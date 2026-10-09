// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "components/cdm/renderer/ohos_key_system_info.h"

#include <utility>

#include "build/build_config.h"

#if !BUILDFLAG(IS_OHOS)
#error This file should only be built for HarmonyOS.
#endif

using media::EmeConfig;
using media::EmeFeatureSupport;
using media::EmeInitDataType;
using media::EmeMediaType;
using media::EncryptionScheme;
using media::SupportedCodecs;

namespace cdm {

OhosKeySystemInfo::OhosKeySystemInfo(
    const std::string& name,
    SupportedCodecs codecs,
    base::flat_set<EncryptionScheme> encryption_schemes)
    : name_(name),
      codecs_(codecs),
      encryption_schemes_(std::move(encryption_schemes)) {}

OhosKeySystemInfo::~OhosKeySystemInfo() = default;

std::string OhosKeySystemInfo::GetBaseKeySystemName() const {
  return name_;
}

bool OhosKeySystemInfo::IsSupportedInitDataType(
    EmeInitDataType init_data_type) const {
  // OhosCdm passes PSSH boxes to DRM Kit; DRM Kit decrypts MP4 only.
  return init_data_type == EmeInitDataType::CENC &&
         (codecs_ & media::EME_CODEC_MP4_ALL) != 0;
}

EmeConfig::Rule OhosKeySystemInfo::GetEncryptionSchemeConfigRule(
    EncryptionScheme encryption_scheme) const {
  if (!encryption_schemes_.contains(encryption_scheme)) {
    return EmeConfig::UnsupportedRule();
  }
  // Software security only: no hardware secure codecs.
  return EmeConfig{.hw_secure_codecs = media::EmeConfigRuleState::kNotAllowed};
}

SupportedCodecs OhosKeySystemInfo::GetSupportedCodecs() const {
  return codecs_;
}

EmeConfig::Rule OhosKeySystemInfo::GetRobustnessConfigRule(
    const std::string& /*key_system*/,
    EmeMediaType /*media_type*/,
    const std::string& requested_robustness,
    const bool* /*hw_secure_requirement*/) const {
  // DRM Kit's software level. Pages that name a robustness for every key
  // system alike use Widevine's names; the software ones mean the same here.
  if (requested_robustness.empty() ||
      requested_robustness == "SW_SECURE_CRYPTO" ||
      requested_robustness == "SW_SECURE_DECODE") {
    return EmeConfig{.hw_secure_codecs = media::EmeConfigRuleState::kNotAllowed};
  }
  return EmeConfig::UnsupportedRule();
}

EmeConfig::Rule OhosKeySystemInfo::GetPersistentLicenseSessionSupport()
    const {
  return EmeConfig::UnsupportedRule();
}

EmeFeatureSupport OhosKeySystemInfo::GetPersistentStateSupport() const {
  // The device certificate DRM Kit keeps is all that persists, and it is
  // not the page's; licenses are temporary.
  return EmeFeatureSupport::REQUESTABLE;
}

EmeFeatureSupport OhosKeySystemInfo::GetDistinctiveIdentifierSupport() const {
  // Licenses are bound to DRM Kit's device certificate, which every site
  // shares. Exposing that as a distinctive identifier needs the protected
  // media identifier permission, which this build does not have on HarmonyOS
  // (Android, ChromeOS and Windows only); until it does, none is offered, so
  // that pages asking for one 'optional' -- the usual players' default --
  // play without a prompt that could not be shown.
  return EmeFeatureSupport::NOT_SUPPORTED;
}

}  // namespace cdm
