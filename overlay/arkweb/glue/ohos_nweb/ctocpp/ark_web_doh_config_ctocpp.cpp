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

#include "ohos_nweb/ctocpp/ark_web_doh_config_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebDohConfigGetModeFunc =
    int32_t (*)(struct _ark_web_doh_config_t* self);
static ArkWebDohConfigGetModeFunc ark_web_doh_config_get_mode =
    reinterpret_cast<ArkWebDohConfigGetModeFunc>(ARK_WEB_INIT_ADDR);

using ArkWebDohConfigGetConfigFunc =
    ArkWebString (*)(struct _ark_web_doh_config_t* self);
static ArkWebDohConfigGetConfigFunc ark_web_doh_config_get_config =
    reinterpret_cast<ArkWebDohConfigGetConfigFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkWebDohConfigCToCpp::GetMode() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_doh_config_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_web_doh_config_get_mode);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Q__csMPla307tUOA0sXZEA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_DOH_CONFIG, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_doh_config_get_mode");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_mode)) {
        ark_web_doh_config_get_mode = nullptr;
      } else {
        ark_web_doh_config_get_mode = _struct->get_mode;
      }
    } else {
      ark_web_doh_config_get_mode =
          reinterpret_cast<ArkWebDohConfigGetModeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_doh_config_get_mode, 0);

  // Execute
  return ark_web_doh_config_get_mode(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkWebDohConfigCToCpp::GetConfig() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_doh_config_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(ark_web_doh_config_get_config);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "8Y56HheAQPW7jOIgByQQSw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_DOH_CONFIG, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_doh_config_get_config");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_config)) {
        ark_web_doh_config_get_config = nullptr;
      } else {
        ark_web_doh_config_get_config = _struct->get_config;
      }
    } else {
      ark_web_doh_config_get_config =
          reinterpret_cast<ArkWebDohConfigGetConfigFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_doh_config_get_config,
                                    ark_web_string_default);

  // Execute
  return ark_web_doh_config_get_config(_struct);
}

ArkWebDohConfigCToCpp::ArkWebDohConfigCToCpp() {}

ArkWebDohConfigCToCpp::~ArkWebDohConfigCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkWebDohConfigCToCpp,
                                        ArkWebDohConfig,
                                        ark_web_doh_config_t>::kBridgeType =
    ARK_WEB_DOH_CONFIG;

}  // namespace OHOS::ArkWeb
