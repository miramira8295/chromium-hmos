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

#include "ohos_adapter/cpptoc/ark_decoder_format_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

int32_t ARK_WEB_CALLBACK ark_decoder_format_adapter_get_width(
    struct _ark_decoder_format_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkDecoderFormatAdapterCppToC::Get(self)->GetWidth();
}

int32_t ARK_WEB_CALLBACK ark_decoder_format_adapter_get_height(
    struct _ark_decoder_format_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkDecoderFormatAdapterCppToC::Get(self)->GetHeight();
}

double ARK_WEB_CALLBACK ark_decoder_format_adapter_get_frame_rate(
    struct _ark_decoder_format_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkDecoderFormatAdapterCppToC::Get(self)->GetFrameRate();
}

void ARK_WEB_CALLBACK
ark_decoder_format_adapter_set_width(struct _ark_decoder_format_adapter_t* self,
                                     int32_t width) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDecoderFormatAdapterCppToC::Get(self)->SetWidth(width);
}

void ARK_WEB_CALLBACK ark_decoder_format_adapter_set_height(
    struct _ark_decoder_format_adapter_t* self,
    int32_t height) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDecoderFormatAdapterCppToC::Get(self)->SetHeight(height);
}

void ARK_WEB_CALLBACK ark_decoder_format_adapter_set_frame_rate(
    struct _ark_decoder_format_adapter_t* self,
    double frameRate) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDecoderFormatAdapterCppToC::Get(self)->SetFrameRate(frameRate);
}

}  // namespace

ArkDecoderFormatAdapterCppToC::ArkDecoderFormatAdapterCppToC() {
  GetStruct()->get_width = ark_decoder_format_adapter_get_width;
  GetStruct()->get_height = ark_decoder_format_adapter_get_height;
  GetStruct()->get_frame_rate = ark_decoder_format_adapter_get_frame_rate;
  GetStruct()->set_width = ark_decoder_format_adapter_set_width;
  GetStruct()->set_height = ark_decoder_format_adapter_set_height;
  GetStruct()->set_frame_rate = ark_decoder_format_adapter_set_frame_rate;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["6u6QKYNHhXSROAii55WrNA"] =
        reinterpret_cast<void*>(ark_decoder_format_adapter_get_width);
    funcMemberMap["D$XP0$mxKAfnWG6UusEokw"] =
        reinterpret_cast<void*>(ark_decoder_format_adapter_get_height);
    funcMemberMap["GwTxVjUg7r5JG3chLnOikQ"] =
        reinterpret_cast<void*>(ark_decoder_format_adapter_get_frame_rate);
    funcMemberMap["lVgLaDVo4CNrQ_uvYflB3Q"] =
        reinterpret_cast<void*>(ark_decoder_format_adapter_set_width);
    funcMemberMap["vGudY8NleE$o30CqRrsDwA"] =
        reinterpret_cast<void*>(ark_decoder_format_adapter_set_height);
    funcMemberMap["dqzRr6Foh2EYYXrvcn1Kfg"] =
        reinterpret_cast<void*>(ark_decoder_format_adapter_set_frame_rate);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_DECODER_FORMAT_ADAPTER, funcMemberMap);
  });
}

ArkDecoderFormatAdapterCppToC::~ArkDecoderFormatAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkDecoderFormatAdapterCppToC,
                           ArkDecoderFormatAdapter,
                           ark_decoder_format_adapter_t>::kBridgeType =
        ARK_DECODER_FORMAT_ADAPTER;

}  // namespace OHOS::ArkWeb
