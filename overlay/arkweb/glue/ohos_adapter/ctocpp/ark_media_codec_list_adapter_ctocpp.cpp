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

#include "ohos_adapter/ctocpp/ark_media_codec_list_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/ctocpp/ark_capability_data_adapter_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkMediaCodecListAdapterGetCodecCapabilityFunc =
    ark_capability_data_adapter_t* (*)(struct _ark_media_codec_list_adapter_t*
                                           self,
                                       const ArkWebString mime,
                                       const bool isCodec);
static ArkMediaCodecListAdapterGetCodecCapabilityFunc
    ark_media_codec_list_adapter_get_codec_capability =
        reinterpret_cast<ArkMediaCodecListAdapterGetCodecCapabilityFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkCapabilityDataAdapter>
ArkMediaCodecListAdapterCToCpp::GetCodecCapability(const ArkWebString mime,
                                                   const bool isCodec) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_list_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_media_codec_list_adapter_get_codec_capability);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "TJU8_hxhI1YOSd4QD2z3fw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_CODEC_LIST_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_list_adapter_get_codec_capability");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_codec_capability)) {
        ark_media_codec_list_adapter_get_codec_capability = nullptr;
      } else {
        ark_media_codec_list_adapter_get_codec_capability =
            _struct->get_codec_capability;
      }
    } else {
      ark_media_codec_list_adapter_get_codec_capability =
          reinterpret_cast<ArkMediaCodecListAdapterGetCodecCapabilityFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_list_adapter_get_codec_capability, nullptr);

  // Execute
  ark_capability_data_adapter_t* _retval =
      ark_media_codec_list_adapter_get_codec_capability(_struct, mime, isCodec);

  // Return type: refptr_same
  return ArkCapabilityDataAdapterCToCpp::Invert(_retval);
}

ArkMediaCodecListAdapterCToCpp::ArkMediaCodecListAdapterCToCpp() {}

ArkMediaCodecListAdapterCToCpp::~ArkMediaCodecListAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkMediaCodecListAdapterCToCpp,
                           ArkMediaCodecListAdapter,
                           ark_media_codec_list_adapter_t>::kBridgeType =
        ARK_MEDIA_CODEC_LIST_ADAPTER;

}  // namespace OHOS::ArkWeb
