// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/gpu/ohos/ohos_video_frame_converter.h"

#include <string>
#include <utility>
#include <vector>

#include "base/functional/bind.h"
#include "base/functional/callback_helpers.h"
#include "base/logging.h"
#include "base/task/bind_post_task.h"
#include "gpu/command_buffer/client/client_shared_image.h"
#include "gpu/command_buffer/common/shared_image_info.h"
#include "gpu/command_buffer/common/shared_image_usage.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "gpu/command_buffer/service/scheduler.h"
#include "gpu/command_buffer/service/shared_context_state.h"
#include "gpu/ipc/service/gpu_channel.h"
#include "gpu/ipc/service/gpu_channel_shared_image_interface.h"
#include "gpu/ipc/service/shared_image_stub.h"
#include "media/base/format_utils.h"
#include "media/base/video_types.h"
#include "ui/gl/gl_bindings.h"
#include "ui/gl/gl_fence.h"
#include "ui/gl/gl_surface_egl.h"
#include "ui/ozone/platform/ohos/ohos_native_pixmap.h"

namespace media {

OhosVideoFrameConverter::OhosVideoFrameConverter(
    scoped_refptr<base::SequencedTaskRunner> gpu_task_runner,
    GetCommandBufferStubCB get_stub_cb,
    const gpu::GpuDriverBugWorkarounds& workarounds)
    : base::RefCountedDeleteOnSequence<OhosVideoFrameConverter>(
          gpu_task_runner),
      gpu_task_runner_(std::move(gpu_task_runner)),
      get_stub_cb_(std::move(get_stub_cb)),
      workarounds_(workarounds) {}

OhosVideoFrameConverter::~OhosVideoFrameConverter() {
  DCHECK(gpu_task_runner_->RunsTasksInCurrentSequence());
  DestroyStub();
}

void OhosVideoFrameConverter::Initialize(viz::SharedImageFormat format,
                                         base::OnceCallback<void(bool)> done) {
  DCHECK(gpu_task_runner_->RunsTasksInCurrentSequence());
  if (!initialized_) {
    initialized_ = true;
    stub_ = get_stub_cb_ ? get_stub_cb_.Run() : nullptr;
    get_stub_cb_.Reset();
    if (stub_) {
      stub_->AddDestructionObserver(this);
      wait_sequence_id_ = stub_->channel()->scheduler()->CreateSequence(
          gpu::SchedulingPriority::kHigh, stub_->channel()->task_runner());
      sis_ = stub_->channel()->shared_image_stub();
    }
  }
  // Native Skia Vulkan and Graphite import need a separate implementation.
  // ANGLE Vulkan is allowed when its EGL NativeBuffer and fence support exist.
  bool supported = sis_ && sis_->MakeContextCurrent(/*needs_gl=*/true) &&
                   !sis_->shared_context_state()->context_lost() &&
                   sis_->shared_context_state()->gr_context_type() ==
                       gpu::GrContextType::kGL &&
                   gl::GLFence::IsGpuFenceSupported() &&
                   ui::IsOhosNativePixmapFormat(format);
  if (supported) {
    auto* display = gl::GLSurfaceEGL::GetGLDisplayEGL();
    const char* extensions =
        display ? eglQueryString(display->GetDisplay(), EGL_EXTENSIONS)
                : nullptr;
    supported = extensions &&
                std::string(extensions).find("EGL_OHOS_image_native_buffer") !=
                    std::string::npos;
  }
  std::move(done).Run(supported);
}

void OhosVideoFrameConverter::OnWillDestroyStub(bool have_context) {
  DestroyStub();
}

void OhosVideoFrameConverter::DestroyStub() {
  DCHECK(gpu_task_runner_->RunsTasksInCurrentSequence());
  sis_ = nullptr;
  if (stub_) {
    stub_->channel()->scheduler()->DestroySequence(wait_sequence_id_);
    stub_->RemoveDestructionObserver(this);
    stub_ = nullptr;
  }
}

void OhosVideoFrameConverter::Convert(scoped_refptr<gfx::NativePixmap> pixmap,
                                      gfx::GpuFenceHandle acquire_fence,
                                      const gfx::Rect& visible_rect,
                                      const gfx::Size& natural_size,
                                      const gfx::ColorSpace& color_space,
                                      const gfx::HDRMetadata& hdr_metadata,
                                      base::TimeDelta timestamp,
                                      OutputCB output_cb) {
  DCHECK(gpu_task_runner_->RunsTasksInCurrentSequence());
  if (!sis_ || !gfx::Rect(pixmap->GetBufferSize()).Contains(visible_rect)) {
    std::move(output_cb).Run(nullptr);
    return;
  }
  // External sampling is a SharedImage detail. Select the VideoFrame format
  // from the actual native allocation, not the codec profile or a fixed NV12.
  auto format = pixmap->GetSharedImageFormat();
  format.ClearPrefersExternalSampler();
  auto pixel_format = SharedImageFormatToVideoPixelFormat(format);
  if (!pixel_format || (*pixel_format != PIXEL_FORMAT_NV12 &&
                        *pixel_format != PIXEL_FORMAT_P010LE)) {
    std::move(output_cb).Run(nullptr);
    return;
  }
  // Read-only GPU uses. No scanout, CPU mapping, or direct WebGPU import.
  const gpu::SharedImageInfo info(pixmap->GetSharedImageFormat(),
                                  pixmap->GetBufferSize(), color_space,
                                  kTopLeft_GrSurfaceOrigin, kOpaque_SkAlphaType,
                                  gpu::SHARED_IMAGE_USAGE_DISPLAY_READ |
                                      gpu::SHARED_IMAGE_USAGE_RASTER_READ |
                                      gpu::SHARED_IMAGE_USAGE_GLES2_READ,
                                  "OhosVideoDecoder");
  auto shared_image =
      sis_->shared_image_interface()->CreateSharedImageForOhosVideo(
          info, pixmap, std::move(acquire_fence), workarounds_);
  if (!shared_image) {
    LOG(ERROR) << "OHOS video zero-copy: SharedImage creation failed";
    std::move(output_cb).Run(nullptr);
    return;
  }
  auto release_cb = base::BindPostTask(
      gpu_task_runner_,
      base::BindOnce(&OhosVideoFrameConverter::OnVideoFrameReleased,
                     base::WrapRefCounted(this), shared_image,
                     std::move(pixmap)));
  auto frame = VideoFrame::WrapSharedImage(
      *pixel_format, shared_image, shared_image->creation_sync_token(),
      std::move(release_cb), visible_rect, natural_size, timestamp);
  if (frame) {
    frame->set_color_space(color_space);
    if (color_space.IsHDR()) {
      frame->set_hdr_metadata(hdr_metadata);
    }
    frame->metadata().read_lock_fences_enabled = true;
    frame->metadata().power_efficient = true;
  }
  std::move(output_cb).Run(std::move(frame));
}

void OhosVideoFrameConverter::OnVideoFrameReleased(
    scoped_refptr<gpu::ClientSharedImage> shared_image,
    scoped_refptr<gfx::NativePixmap> pixmap,
    const gpu::SyncToken& sync_token) {
  DCHECK(gpu_task_runner_->RunsTasksInCurrentSequence());
  shared_image->UpdateDestructionSyncToken(sync_token);
  if (!stub_) {
    return;
  }
  // A mailbox release means submitted work, not necessarily completed work.
  // Hold the native buffer until Chromium's read-lock completion token passes.
  stub_->channel()->scheduler()->ScheduleTask(gpu::Scheduler::Task(
      wait_sequence_id_, base::DoNothingWithBoundArgs(std::move(pixmap)),
      std::vector<gpu::SyncToken>{sync_token}));
}

}  // namespace media
