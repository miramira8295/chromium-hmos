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

#include "ohos_nweb/ctocpp/ark_web_system_configuration_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebSystemConfigurationGetThemeFlagsFunc =
    uint8_t (*)(struct _ark_web_system_configuration_t* self);
static ArkWebSystemConfigurationGetThemeFlagsFunc
    ark_web_system_configuration_get_theme_flags =
        reinterpret_cast<ArkWebSystemConfigurationGetThemeFlagsFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
uint8_t ArkWebSystemConfigurationCToCpp::GetThemeFlags() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_system_configuration_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_system_configuration_get_theme_flags);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "1j11qlFok8lngCUqdrP88g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_SYSTEM_CONFIGURATION, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_system_configuration_get_theme_flags");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_theme_flags)) {
        ark_web_system_configuration_get_theme_flags = nullptr;
      } else {
        ark_web_system_configuration_get_theme_flags = _struct->get_theme_flags;
      }
    } else {
      ark_web_system_configuration_get_theme_flags =
          reinterpret_cast<ArkWebSystemConfigurationGetThemeFlagsFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_system_configuration_get_theme_flags, 0);

  // Execute
  return ark_web_system_configuration_get_theme_flags(_struct);
}

ArkWebSystemConfigurationCToCpp::ArkWebSystemConfigurationCToCpp() {}

ArkWebSystemConfigurationCToCpp::~ArkWebSystemConfigurationCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkWebSystemConfigurationCToCpp,
                           ArkWebSystemConfiguration,
                           ark_web_system_configuration_t>::kBridgeType =
        ARK_WEB_SYSTEM_CONFIGURATION;

}  // namespace OHOS::ArkWeb
