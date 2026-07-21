// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <deviceinfo.h>

#include <optional>
#include <string>
#include <vector>

#include "base/files/file_path.h"
#include "components/device_signals/core/common/common_types.h"
#include "components/device_signals/core/common/platform_utils.h"

namespace device_signals {

std::string GetDeviceModel() {
  const char* product_model = OH_GetProductModel();
  return product_model ? product_model : "";
}

std::string GetSerialNumber() {
  return {};
}

SettingValue GetScreenlockSecured() {
  return SettingValue::UNKNOWN;
}

SettingValue GetDiskEncrypted() {
  return SettingValue::UNKNOWN;
}

std::vector<std::string> internal::GetMacAddressesImpl() {
  return {};
}

base::FilePath GetCrowdStrikeZtaFilePath() {
  return {};
}

std::optional<CrowdStrikeSignals> GetCrowdStrikeSignals() {
  return std::nullopt;
}

}  // namespace device_signals
