// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_GPU_OHOS_OHOS_VIDEO_FRAME_CONVERTER_H_
#define MEDIA_GPU_OHOS_OHOS_VIDEO_FRAME_CONVERTER_H_

#include "base/functional/callback.h"
#include "base/memory/raw_ptr.h"
#include "base/memory/ref_counted_delete_on_sequence.h"
#include "base/task/sequenced_task_runner.h"
#include "base/time/time.h"
#include "gpu/command_buffer/service/sequence_id.h"
#include "gpu/config/gpu_driver_bug_workarounds.h"
#include "gpu/ipc/service/command_buffer_stub.h"
#include "media/base/video_frame.h"
#include "ui/gfx/gpu_fence_handle.h"
#include "ui/gfx/native_pixmap.h"

namespace gpu {
class ClientSharedImage;
class SharedImageStub;
struct SyncToken;
}  // namespace gpu

namespace media {

// GPU-sequence bridge for decoder-owned buffers. Frame release follows the same
// command-buffer completion protocol as VideoToolboxFrameConverter.
class OhosVideoFrameConverter
    : public gpu::CommandBufferStub::DestructionObserver,
      public base::RefCountedDeleteOnSequence<OhosVideoFrameConverter> {
 public:
  using GetCommandBufferStubCB =
      base::RepeatingCallback<gpu::CommandBufferStub*()>;
  using OutputCB = base::OnceCallback<void(scoped_refptr<VideoFrame>)>;

  OhosVideoFrameConverter(
      scoped_refptr<base::SequencedTaskRunner> gpu_task_runner,
      GetCommandBufferStubCB get_stub_cb,
      const gpu::GpuDriverBugWorkarounds& workarounds);

  // All public methods run on the GPU sequence; construction may run elsewhere.
  void Initialize(base::OnceCallback<void(bool)> done);
  void Convert(scoped_refptr<gfx::NativePixmap> pixmap,
               gfx::GpuFenceHandle acquire_fence,
               const gfx::Rect& visible_rect,
               const gfx::Size& natural_size,
               const gfx::ColorSpace& color_space,
               base::TimeDelta timestamp,
               OutputCB output_cb);

 private:
  friend class base::DeleteHelper<OhosVideoFrameConverter>;
  friend class base::RefCountedDeleteOnSequence<OhosVideoFrameConverter>;
  ~OhosVideoFrameConverter() override;
  void OnWillDestroyStub(bool have_context) override;
  void DestroyStub();
  void OnVideoFrameReleased(scoped_refptr<gpu::ClientSharedImage> shared_image,
                            scoped_refptr<gfx::NativePixmap> pixmap,
                            const gpu::SyncToken& sync_token);

  const scoped_refptr<base::SequencedTaskRunner> gpu_task_runner_;
  GetCommandBufferStubCB get_stub_cb_;
  const gpu::GpuDriverBugWorkarounds workarounds_;
  bool initialized_ = false;
  raw_ptr<gpu::CommandBufferStub> stub_ = nullptr;
  raw_ptr<gpu::SharedImageStub> sis_ = nullptr;
  gpu::SequenceId wait_sequence_id_;
};

}  // namespace media
#endif  // MEDIA_GPU_OHOS_OHOS_VIDEO_FRAME_CONVERTER_H_
