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

#include "ohos_adapter/cpptoc/ark_audio_output_change_callback_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK
ark_audio_output_change_callback_adapter_on_output_device_change(
    struct _ark_audio_output_change_callback_adapter_t* self,
    int32_t reason) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioOutputChangeCallbackAdapterCppToC::Get(self)->OnOutputDeviceChange(
      reason);
}

}  // namespace

ArkAudioOutputChangeCallbackAdapterCppToC::
    ArkAudioOutputChangeCallbackAdapterCppToC() {
  GetStruct()->on_output_device_change =
      ark_audio_output_change_callback_adapter_on_output_device_change;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["j7kG0PK6cN56Be2RTzhMhg"] = reinterpret_cast<void*>(
        ark_audio_output_change_callback_adapter_on_output_device_change);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_AUDIO_OUTPUT_CHANGE_CALLBACK_ADAPTER, funcMemberMap);
  });
}

ArkAudioOutputChangeCallbackAdapterCppToC::
    ~ArkAudioOutputChangeCallbackAdapterCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<
    ArkAudioOutputChangeCallbackAdapterCppToC,
    ArkAudioOutputChangeCallbackAdapter,
    ark_audio_output_change_callback_adapter_t>::kBridgeType =
    ARK_AUDIO_OUTPUT_CHANGE_CALLBACK_ADAPTER;

}  // namespace OHOS::ArkWeb
