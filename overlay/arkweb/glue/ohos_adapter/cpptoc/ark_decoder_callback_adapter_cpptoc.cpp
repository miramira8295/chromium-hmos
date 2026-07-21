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

#include "ohos_adapter/cpptoc/ark_decoder_callback_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/ctocpp/ark_buffer_info_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_ohos_buffer_adapter_ctocpp.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK ark_decoder_callback_adapter_on_error(
    struct _ark_decoder_callback_adapter_t* self,
    int32_t errorType,
    int32_t errorCode) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDecoderCallbackAdapterCppToC::Get(self)->OnError(errorType, errorCode);
}

void ARK_WEB_CALLBACK ark_decoder_callback_adapter_on_stream_changed(
    struct _ark_decoder_callback_adapter_t* self,
    int32_t width,
    int32_t height,
    double frameRate) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDecoderCallbackAdapterCppToC::Get(self)->OnStreamChanged(width, height,
                                                              frameRate);
}

void ARK_WEB_CALLBACK ark_decoder_callback_adapter_on_need_input_data(
    struct _ark_decoder_callback_adapter_t* self,
    uint32_t index,
    ark_ohos_buffer_adapter_t* buffer) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDecoderCallbackAdapterCppToC::Get(self)->OnNeedInputData(
      index, ArkOhosBufferAdapterCToCpp::Invert(buffer));
}

void ARK_WEB_CALLBACK ark_decoder_callback_adapter_on_need_output_data(
    struct _ark_decoder_callback_adapter_t* self,
    uint32_t index,
    ark_buffer_info_adapter_t* info,
    uint32_t flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDecoderCallbackAdapterCppToC::Get(self)->OnNeedOutputData(
      index, ArkBufferInfoAdapterCToCpp::Invert(info), flag);
}

}  // namespace

ArkDecoderCallbackAdapterCppToC::ArkDecoderCallbackAdapterCppToC() {
  GetStruct()->on_error = ark_decoder_callback_adapter_on_error;
  GetStruct()->on_stream_changed =
      ark_decoder_callback_adapter_on_stream_changed;
  GetStruct()->on_need_input_data =
      ark_decoder_callback_adapter_on_need_input_data;
  GetStruct()->on_need_output_data =
      ark_decoder_callback_adapter_on_need_output_data;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["6B9UNGSTvqN3HehV9Nol5g"] =
        reinterpret_cast<void*>(ark_decoder_callback_adapter_on_error);
    funcMemberMap["5yOXTa9u0P$j9xWfKv4YAg"] =
        reinterpret_cast<void*>(ark_decoder_callback_adapter_on_stream_changed);
    funcMemberMap["y3HYqy57Fdc1Esfhdie6Sw"] = reinterpret_cast<void*>(
        ark_decoder_callback_adapter_on_need_input_data);
    funcMemberMap["q0JRea7p4r3PkAAgfeZiYg"] = reinterpret_cast<void*>(
        ark_decoder_callback_adapter_on_need_output_data);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_DECODER_CALLBACK_ADAPTER, funcMemberMap);
  });
}

ArkDecoderCallbackAdapterCppToC::~ArkDecoderCallbackAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkDecoderCallbackAdapterCppToC,
                           ArkDecoderCallbackAdapter,
                           ark_decoder_callback_adapter_t>::kBridgeType =
        ARK_DECODER_CALLBACK_ADAPTER;

}  // namespace OHOS::ArkWeb
