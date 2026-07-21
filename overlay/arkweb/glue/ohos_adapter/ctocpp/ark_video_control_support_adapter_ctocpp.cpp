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

#include "ohos_adapter/ctocpp/ark_video_control_support_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkVideoControlSupportAdapterGetPanFunc =
    bool (*)(struct _ark_video_control_support_adapter_t* self);
static ArkVideoControlSupportAdapterGetPanFunc
    ark_video_control_support_adapter_get_pan =
        reinterpret_cast<ArkVideoControlSupportAdapterGetPanFunc>(
            ARK_WEB_INIT_ADDR);

using ArkVideoControlSupportAdapterGetTiltFunc =
    bool (*)(struct _ark_video_control_support_adapter_t* self);
static ArkVideoControlSupportAdapterGetTiltFunc
    ark_video_control_support_adapter_get_tilt =
        reinterpret_cast<ArkVideoControlSupportAdapterGetTiltFunc>(
            ARK_WEB_INIT_ADDR);

using ArkVideoControlSupportAdapterGetZoomFunc =
    bool (*)(struct _ark_video_control_support_adapter_t* self);
static ArkVideoControlSupportAdapterGetZoomFunc
    ark_video_control_support_adapter_get_zoom =
        reinterpret_cast<ArkVideoControlSupportAdapterGetZoomFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
bool ArkVideoControlSupportAdapterCToCpp::GetPan() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_video_control_support_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_video_control_support_adapter_get_pan);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "MkIptWbi7CwX0vRZY6uEkw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_VIDEO_CONTROL_SUPPORT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_video_control_support_adapter_get_pan");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_pan)) {
        ark_video_control_support_adapter_get_pan = nullptr;
      } else {
        ark_video_control_support_adapter_get_pan = _struct->get_pan;
      }
    } else {
      ark_video_control_support_adapter_get_pan =
          reinterpret_cast<ArkVideoControlSupportAdapterGetPanFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_video_control_support_adapter_get_pan,
                                    false);

  // Execute
  return ark_video_control_support_adapter_get_pan(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkVideoControlSupportAdapterCToCpp::GetTilt() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_video_control_support_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_video_control_support_adapter_get_tilt);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Cy4D0R0lrkti_w_Id2OCHQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_VIDEO_CONTROL_SUPPORT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_video_control_support_adapter_get_tilt");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_tilt)) {
        ark_video_control_support_adapter_get_tilt = nullptr;
      } else {
        ark_video_control_support_adapter_get_tilt = _struct->get_tilt;
      }
    } else {
      ark_video_control_support_adapter_get_tilt =
          reinterpret_cast<ArkVideoControlSupportAdapterGetTiltFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_video_control_support_adapter_get_tilt,
                                    false);

  // Execute
  return ark_video_control_support_adapter_get_tilt(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkVideoControlSupportAdapterCToCpp::GetZoom() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_video_control_support_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_video_control_support_adapter_get_zoom);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Mw11lOCiPsVa1zpHx8JGGA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_VIDEO_CONTROL_SUPPORT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_video_control_support_adapter_get_zoom");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_zoom)) {
        ark_video_control_support_adapter_get_zoom = nullptr;
      } else {
        ark_video_control_support_adapter_get_zoom = _struct->get_zoom;
      }
    } else {
      ark_video_control_support_adapter_get_zoom =
          reinterpret_cast<ArkVideoControlSupportAdapterGetZoomFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_video_control_support_adapter_get_zoom,
                                    false);

  // Execute
  return ark_video_control_support_adapter_get_zoom(_struct);
}

ArkVideoControlSupportAdapterCToCpp::ArkVideoControlSupportAdapterCToCpp() {}

ArkVideoControlSupportAdapterCToCpp::~ArkVideoControlSupportAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkVideoControlSupportAdapterCToCpp,
                           ArkVideoControlSupportAdapter,
                           ark_video_control_support_adapter_t>::kBridgeType =
        ARK_VIDEO_CONTROL_SUPPORT_ADAPTER;

}  // namespace OHOS::ArkWeb
