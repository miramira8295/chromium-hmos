// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <memory>
#include <optional>
#include <utility>

#include "base/task/sequenced_task_runner.h"
#include "media/base/audio_decoder.h"
#include "media/base/media_log.h"
#include "media/base/supported_audio_decoder_config.h"
#include "media/base/supported_video_decoder_config.h"
#include "media/base/video_decoder.h"
#include "media/gpu/ohos/ohos_audio_decoder.h"
#include "media/gpu/ohos/ohos_codec_util.h"
#include "media/gpu/ohos/ohos_video_decoder.h"
#include "media/mojo/services/gpu_mojo_media_client.h"

namespace media {

class GpuMojoMediaClientOhos final : public GpuMojoMediaClient {
 public:
  explicit GpuMojoMediaClientOhos(GpuMojoMediaClientTraits& traits)
      : GpuMojoMediaClient(traits) {}
  ~GpuMojoMediaClientOhos() final = default;

 protected:
  std::unique_ptr<VideoDecoder> CreatePlatformVideoDecoder(
      VideoDecoderTraits& traits) final {
    // The configs are cached by GpuMojoMediaClient, so every decoder checks
    // its config against the same capability snapshot the renderer saw.
    return std::make_unique<OhosVideoDecoder>(
        traits.task_runner, std::move(traits.media_log),
        traits.get_cached_configs_cb.Run(), gpu_task_runner_,
        traits.get_command_buffer_stub_cb, gpu_workarounds_);
  }

  std::optional<SupportedVideoDecoderConfigs>
  GetPlatformSupportedVideoDecoderConfigs() final {
    return GetOhosSupportedDecoderConfigs();
  }

  VideoDecoderType GetPlatformDecoderImplementationType() final {
    // Matches OhosVideoDecoder::GetDecoderType(); see the note there.
    return VideoDecoderType::kUnknown;
  }

  // The renderer asks this once when it starts and answers canPlayType and
  // MSE for AC-3 and DTS from it; it decodes everything else itself.
  std::optional<SupportedAudioDecoderConfigs>
  GetPlatformSupportedAudioDecoderConfigs() final {
    return GetOhosSupportedAudioDecoderConfigs();
  }

  std::unique_ptr<AudioDecoder> CreatePlatformAudioDecoder(
      scoped_refptr<base::SequencedTaskRunner> task_runner,
      std::unique_ptr<MediaLog> media_log) final {
    return std::make_unique<OhosAudioDecoder>(std::move(task_runner),
                                              std::move(media_log));
  }
};

std::unique_ptr<GpuMojoMediaClient> CreateGpuMediaService(
    GpuMojoMediaClientTraits& traits) {
  return std::make_unique<GpuMojoMediaClientOhos>(traits);
}

}  // namespace media
