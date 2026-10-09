// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/media/key_system_support_ohos.h"

#include <multimedia/drm_framework/native_mediakeysystem.h>
#include <multimedia/player_framework/native_avcapability.h>
#include <multimedia/player_framework/native_avcodec_base.h>

#include <utility>

#include "base/functional/bind.h"
#include "base/logging.h"
#include "base/task/thread_pool.h"
#include "media/base/audio_codecs.h"
#include "media/base/content_decryption_module.h"
#include "media/base/encryption_scheme.h"
#include "media/base/video_codecs.h"

namespace content {

namespace {

// DRM Kit's own key systems that the engine serves; OhosCdm handles exactly
// these.
constexpr char kWisePlayKeySystem[] = "com.wiseplay.drm";

bool HasHardwareDecoder(const char* mime) {
  return OH_AVCodec_GetCapabilityByCategory(mime, /*isEncoder=*/false,
                                            HARDWARE) != nullptr;
}

media::CdmCapabilityOrStatus QueryCapability(const std::string& key_system) {
  if (key_system != kWisePlayKeySystem ||
      !OH_MediaKeySystem_IsSupported(key_system.c_str())) {
    LOG(WARNING) << "OHOS key system " << key_system << ": unsupported";
    return base::unexpected(
        media::CdmCapabilityQueryStatus::kUnsupportedKeySystem);
  }
  // DRM Kit decrypts H.264, HEVC and AAC in MP4 (and TS) only.
  bool video = OH_MediaKeySystem_IsSupported2(key_system.c_str(), "video/mp4");
  bool audio = OH_MediaKeySystem_IsSupported2(key_system.c_str(), "audio/mp4");
  if (!video && !audio) {
    // DRM Kit documents no MIME types for this query; a key system that it
    // serves but answers no to both for is taken at its documented word.
    LOG(WARNING) << "OHOS key system " << key_system
                 << ": no answer for MP4; assuming H.264/HEVC/AAC";
    video = audio = true;
  }
  media::CdmCapability capability;
  if (video) {
    // Empty profile sets mean every profile the decoder takes.
    capability.video_codecs.emplace(media::VideoCodec::kH264,
                                    media::VideoCodecInfo());
    if (HasHardwareDecoder(OH_AVCODEC_MIMETYPE_VIDEO_HEVC)) {
      capability.video_codecs.emplace(media::VideoCodec::kHEVC,
                                      media::VideoCodecInfo());
    }
  }
  if (audio) {
    capability.audio_codecs.insert(media::AudioCodec::kAAC);
  }
  capability.encryption_schemes = {media::EncryptionScheme::kCenc,
                                   media::EncryptionScheme::kCbcs};
  // OhosCdm has no persistent licenses yet.
  capability.session_types = {media::CdmSessionType::kTemporary};
  LOG(WARNING) << "OHOS key system " << key_system << ": video/mp4 "
               << video << ", audio/mp4 " << audio << ", HEVC "
               << capability.video_codecs.contains(media::VideoCodec::kHEVC);
  if (capability.video_codecs.empty()) {
    return base::unexpected(
        media::CdmCapabilityQueryStatus::kNoSupportedVideoCodec);
  }
  return capability;
}

}  // namespace

void GetOhosCdmCapability(const std::string& key_system,
                          CdmInfo::Robustness robustness,
                          media::CdmCapabilityCB cdm_capability_cb) {
  if (robustness == CdmInfo::Robustness::kHardwareSecure) {
    // Hardware security needs DRM Kit's secure video path, which OhosCdm
    // does not do yet.
    std::move(cdm_capability_cb)
        .Run(base::unexpected(
            media::CdmCapabilityQueryStatus::kHardwareSecureCodecNotSupported));
    return;
  }
  // DRM Kit answers over IPC to its service; keep that off the UI thread.
  base::ThreadPool::PostTaskAndReplyWithResult(
      FROM_HERE, {base::MayBlock(), base::TaskPriority::USER_VISIBLE},
      base::BindOnce(&QueryCapability, key_system),
      std::move(cdm_capability_cb));
}

}  // namespace content
