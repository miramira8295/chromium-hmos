// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_CDM_RENDERER_OHOS_KEY_SYSTEM_INFO_H_
#define COMPONENTS_CDM_RENDERER_OHOS_KEY_SYSTEM_INFO_H_

#include <string>

#include "base/containers/flat_set.h"
#include "media/base/eme_constants.h"
#include "media/base/encryption_scheme.h"
#include "media/base/key_system_info.h"

namespace cdm {

// A key system served by HarmonyOS DRM Kit (WisePlay), as the GPU process's
// OhosCdm and AVCodecKit decoders implement it: software security, temporary
// sessions, 'cenc' init data.
class OhosKeySystemInfo : public media::KeySystemInfo {
 public:
  OhosKeySystemInfo(const std::string& name,
                    media::SupportedCodecs codecs,
                    base::flat_set<media::EncryptionScheme> encryption_schemes);
  ~OhosKeySystemInfo() override;

  std::string GetBaseKeySystemName() const override;
  bool IsSupportedInitDataType(
      media::EmeInitDataType init_data_type) const override;
  media::EmeConfig::Rule GetEncryptionSchemeConfigRule(
      media::EncryptionScheme encryption_scheme) const override;
  media::SupportedCodecs GetSupportedCodecs() const override;
  media::EmeConfig::Rule GetRobustnessConfigRule(
      const std::string& key_system,
      media::EmeMediaType media_type,
      const std::string& requested_robustness,
      const bool* hw_secure_requirement) const override;
  media::EmeConfig::Rule GetPersistentLicenseSessionSupport() const override;
  media::EmeFeatureSupport GetPersistentStateSupport() const override;
  media::EmeFeatureSupport GetDistinctiveIdentifierSupport() const override;

 private:
  const std::string name_;
  const media::SupportedCodecs codecs_;
  const base::flat_set<media::EncryptionScheme> encryption_schemes_;
};

}  // namespace cdm

#endif  // COMPONENTS_CDM_RENDERER_OHOS_KEY_SYSTEM_INFO_H_
