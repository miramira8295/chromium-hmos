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

#include "ohos_nweb/ctocpp/ark_web_screen_capture_config_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebScreenCaptureConfigGetModeFunc =
    int32_t (*)(struct _ark_web_screen_capture_config_t* self);
static ArkWebScreenCaptureConfigGetModeFunc
    ark_web_screen_capture_config_get_mode =
        reinterpret_cast<ArkWebScreenCaptureConfigGetModeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebScreenCaptureConfigGetSourceIdFunc =
    int32_t (*)(struct _ark_web_screen_capture_config_t* self);
static ArkWebScreenCaptureConfigGetSourceIdFunc
    ark_web_screen_capture_config_get_source_id =
        reinterpret_cast<ArkWebScreenCaptureConfigGetSourceIdFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkWebScreenCaptureConfigCToCpp::GetMode() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_screen_capture_config_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_screen_capture_config_get_mode);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "VX$YiBGfoFMZ0VN1pXv8UA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_SCREEN_CAPTURE_CONFIG, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_screen_capture_config_get_mode");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_mode)) {
        ark_web_screen_capture_config_get_mode = nullptr;
      } else {
        ark_web_screen_capture_config_get_mode = _struct->get_mode;
      }
    } else {
      ark_web_screen_capture_config_get_mode =
          reinterpret_cast<ArkWebScreenCaptureConfigGetModeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_screen_capture_config_get_mode, 0);

  // Execute
  return ark_web_screen_capture_config_get_mode(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkWebScreenCaptureConfigCToCpp::GetSourceId() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_screen_capture_config_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_screen_capture_config_get_source_id);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "R667Z9SfWlkTKzKgf_IL_A";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_SCREEN_CAPTURE_CONFIG, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_screen_capture_config_get_source_id");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_source_id)) {
        ark_web_screen_capture_config_get_source_id = nullptr;
      } else {
        ark_web_screen_capture_config_get_source_id = _struct->get_source_id;
      }
    } else {
      ark_web_screen_capture_config_get_source_id =
          reinterpret_cast<ArkWebScreenCaptureConfigGetSourceIdFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_screen_capture_config_get_source_id,
                                    0);

  // Execute
  return ark_web_screen_capture_config_get_source_id(_struct);
}

ArkWebScreenCaptureConfigCToCpp::ArkWebScreenCaptureConfigCToCpp() {}

ArkWebScreenCaptureConfigCToCpp::~ArkWebScreenCaptureConfigCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkWebScreenCaptureConfigCToCpp,
                           ArkWebScreenCaptureConfig,
                           ark_web_screen_capture_config_t>::kBridgeType =
        ARK_WEB_SCREEN_CAPTURE_CONFIG;

}  // namespace OHOS::ArkWeb
