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

#include "ohos_adapter/ctocpp/ark_codec_format_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkCodecFormatAdapterGetWidthFunc =
    int32_t (*)(struct _ark_codec_format_adapter_t* self);
static ArkCodecFormatAdapterGetWidthFunc ark_codec_format_adapter_get_width =
    reinterpret_cast<ArkCodecFormatAdapterGetWidthFunc>(ARK_WEB_INIT_ADDR);

using ArkCodecFormatAdapterGetHeightFunc =
    int32_t (*)(struct _ark_codec_format_adapter_t* self);
static ArkCodecFormatAdapterGetHeightFunc ark_codec_format_adapter_get_height =
    reinterpret_cast<ArkCodecFormatAdapterGetHeightFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkCodecFormatAdapterCToCpp::GetWidth() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_codec_format_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_codec_format_adapter_get_width);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "bvslVQaba8WCvDjEevymKA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CODEC_FORMAT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_codec_format_adapter_get_width");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_width)) {
        ark_codec_format_adapter_get_width = nullptr;
      } else {
        ark_codec_format_adapter_get_width = _struct->get_width;
      }
    } else {
      ark_codec_format_adapter_get_width =
          reinterpret_cast<ArkCodecFormatAdapterGetWidthFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_codec_format_adapter_get_width, 0);

  // Execute
  return ark_codec_format_adapter_get_width(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCodecFormatAdapterCToCpp::GetHeight() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_codec_format_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_codec_format_adapter_get_height);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "85DYaYvki1P84ssmNpcjzw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CODEC_FORMAT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_codec_format_adapter_get_height");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_height)) {
        ark_codec_format_adapter_get_height = nullptr;
      } else {
        ark_codec_format_adapter_get_height = _struct->get_height;
      }
    } else {
      ark_codec_format_adapter_get_height =
          reinterpret_cast<ArkCodecFormatAdapterGetHeightFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_codec_format_adapter_get_height, 0);

  // Execute
  return ark_codec_format_adapter_get_height(_struct);
}

ArkCodecFormatAdapterCToCpp::ArkCodecFormatAdapterCToCpp() {}

ArkCodecFormatAdapterCToCpp::~ArkCodecFormatAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkCodecFormatAdapterCToCpp,
                           ArkCodecFormatAdapter,
                           ark_codec_format_adapter_t>::kBridgeType =
        ARK_CODEC_FORMAT_ADAPTER;

}  // namespace OHOS::ArkWeb
