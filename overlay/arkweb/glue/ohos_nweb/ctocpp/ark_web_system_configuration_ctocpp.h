/*
 * Copyright (c) 2026 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ARK_WEB_SYSTEM_CONFIGURATION_CTOCPP_H_
#define ARK_WEB_SYSTEM_CONFIGURATION_CTOCPP_H_
#pragma once

#include "base/ctocpp/ark_web_ctocpp_ref_counted.h"
#include "ohos_nweb/capi/ark_web_system_configuration_capi.h"
#include "ohos_nweb/include/ark_web_system_configuration.h"

namespace OHOS::ArkWeb {

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class ArkWebSystemConfigurationCToCpp
    : public ArkWebCToCppRefCounted<ArkWebSystemConfigurationCToCpp,
                                    ArkWebSystemConfiguration,
                                    ark_web_system_configuration_t> {
 public:
  ArkWebSystemConfigurationCToCpp();
  virtual ~ArkWebSystemConfigurationCToCpp();

  // ArkWebSystemConfiguration methods.
  uint8_t GetThemeFlags() override;
};

}  // namespace OHOS::ArkWeb

#endif  // ARK_WEB_SYSTEM_CONFIGURATION_CTOCPP_H_
