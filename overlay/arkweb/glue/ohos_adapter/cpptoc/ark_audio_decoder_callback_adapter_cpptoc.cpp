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

#include "ohos_adapter/cpptoc/ark_audio_decoder_callback_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK ark_audio_decoder_callback_adapter_on_error(
    struct _ark_audio_decoder_callback_adapter_t* self,
    int32_t errorCode) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioDecoderCallbackAdapterCppToC::Get(self)->OnError(errorCode);
}

void ARK_WEB_CALLBACK
ark_audio_decoder_callback_adapter_on_output_format_changed(
    struct _ark_audio_decoder_callback_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioDecoderCallbackAdapterCppToC::Get(self)->OnOutputFormatChanged();
}

void ARK_WEB_CALLBACK
ark_audio_decoder_callback_adapter_on_input_buffer_available(
    struct _ark_audio_decoder_callback_adapter_t* self,
    uint32_t index) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioDecoderCallbackAdapterCppToC::Get(self)->OnInputBufferAvailable(
      index);
}

void ARK_WEB_CALLBACK
ark_audio_decoder_callback_adapter_on_output_buffer_available(
    struct _ark_audio_decoder_callback_adapter_t* self,
    uint32_t index,
    uint8_t* bufferData,
    int32_t size,
    int64_t pts,
    int32_t offset,
    uint32_t flags) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioDecoderCallbackAdapterCppToC::Get(self)->OnOutputBufferAvailable(
      index, bufferData, size, pts, offset, flags);
}

}  // namespace

ArkAudioDecoderCallbackAdapterCppToC::ArkAudioDecoderCallbackAdapterCppToC() {
  GetStruct()->on_error = ark_audio_decoder_callback_adapter_on_error;
  GetStruct()->on_output_format_changed =
      ark_audio_decoder_callback_adapter_on_output_format_changed;
  GetStruct()->on_input_buffer_available =
      ark_audio_decoder_callback_adapter_on_input_buffer_available;
  GetStruct()->on_output_buffer_available =
      ark_audio_decoder_callback_adapter_on_output_buffer_available;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["4oEY_6A4uAbpDjcNdHXNEg"] =
        reinterpret_cast<void*>(ark_audio_decoder_callback_adapter_on_error);
    funcMemberMap["yx0HDlTxf8t9EP$EMkPG_Q"] = reinterpret_cast<void*>(
        ark_audio_decoder_callback_adapter_on_output_format_changed);
    funcMemberMap["t8JOW5OZFuK4GOU1hnkGJQ"] = reinterpret_cast<void*>(
        ark_audio_decoder_callback_adapter_on_input_buffer_available);
    funcMemberMap["bG1vWHAYkMWDMy5OL9cUUg"] = reinterpret_cast<void*>(
        ark_audio_decoder_callback_adapter_on_output_buffer_available);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_AUDIO_DECODER_CALLBACK_ADAPTER, funcMemberMap);
  });
}

ArkAudioDecoderCallbackAdapterCppToC::~ArkAudioDecoderCallbackAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkAudioDecoderCallbackAdapterCppToC,
                           ArkAudioDecoderCallbackAdapter,
                           ark_audio_decoder_callback_adapter_t>::kBridgeType =
        ARK_AUDIO_DECODER_CALLBACK_ADAPTER;

}  // namespace OHOS::ArkWeb
