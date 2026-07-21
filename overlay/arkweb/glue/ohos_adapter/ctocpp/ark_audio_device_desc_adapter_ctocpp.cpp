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

#include "ohos_adapter/ctocpp/ark_audio_device_desc_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkAudioDeviceDescAdapterGetDeviceIdFunc =
    int32_t (*)(struct _ark_audio_device_desc_adapter_t* self);
static ArkAudioDeviceDescAdapterGetDeviceIdFunc
    ark_audio_device_desc_adapter_get_device_id =
        reinterpret_cast<ArkAudioDeviceDescAdapterGetDeviceIdFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioDeviceDescAdapterGetDeviceNameFunc =
    ArkWebString (*)(struct _ark_audio_device_desc_adapter_t* self);
static ArkAudioDeviceDescAdapterGetDeviceNameFunc
    ark_audio_device_desc_adapter_get_device_name =
        reinterpret_cast<ArkAudioDeviceDescAdapterGetDeviceNameFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkAudioDeviceDescAdapterCToCpp::GetDeviceId() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_device_desc_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_device_desc_adapter_get_device_id);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "1cXeYITtG0Chp9_PU6r$sg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_DEVICE_DESC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_device_desc_adapter_get_device_id");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_device_id)) {
        ark_audio_device_desc_adapter_get_device_id = nullptr;
      } else {
        ark_audio_device_desc_adapter_get_device_id = _struct->get_device_id;
      }
    } else {
      ark_audio_device_desc_adapter_get_device_id =
          reinterpret_cast<ArkAudioDeviceDescAdapterGetDeviceIdFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_device_desc_adapter_get_device_id,
                                    0);

  // Execute
  return ark_audio_device_desc_adapter_get_device_id(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkAudioDeviceDescAdapterCToCpp::GetDeviceName() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_device_desc_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_device_desc_adapter_get_device_name);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "5q$YRogBQ$dQpjQLTM3mBg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_DEVICE_DESC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_device_desc_adapter_get_device_name");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_device_name)) {
        ark_audio_device_desc_adapter_get_device_name = nullptr;
      } else {
        ark_audio_device_desc_adapter_get_device_name =
            _struct->get_device_name;
      }
    } else {
      ark_audio_device_desc_adapter_get_device_name =
          reinterpret_cast<ArkAudioDeviceDescAdapterGetDeviceNameFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_device_desc_adapter_get_device_name, ark_web_string_default);

  // Execute
  return ark_audio_device_desc_adapter_get_device_name(_struct);
}

ArkAudioDeviceDescAdapterCToCpp::ArkAudioDeviceDescAdapterCToCpp() {}

ArkAudioDeviceDescAdapterCToCpp::~ArkAudioDeviceDescAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkAudioDeviceDescAdapterCToCpp,
                           ArkAudioDeviceDescAdapter,
                           ark_audio_device_desc_adapter_t>::kBridgeType =
        ARK_AUDIO_DEVICE_DESC_ADAPTER;

}  // namespace OHOS::ArkWeb
