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

#include "ohos_adapter/ctocpp/ark_format_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkFormatAdapterGetWidthFunc =
    uint32_t (*)(struct _ark_format_adapter_t* self);
static ArkFormatAdapterGetWidthFunc ark_format_adapter_get_width =
    reinterpret_cast<ArkFormatAdapterGetWidthFunc>(ARK_WEB_INIT_ADDR);

using ArkFormatAdapterGetHeightFunc =
    uint32_t (*)(struct _ark_format_adapter_t* self);
static ArkFormatAdapterGetHeightFunc ark_format_adapter_get_height =
    reinterpret_cast<ArkFormatAdapterGetHeightFunc>(ARK_WEB_INIT_ADDR);

using ArkFormatAdapterGetFrameRateFunc =
    float (*)(struct _ark_format_adapter_t* self);
static ArkFormatAdapterGetFrameRateFunc ark_format_adapter_get_frame_rate =
    reinterpret_cast<ArkFormatAdapterGetFrameRateFunc>(ARK_WEB_INIT_ADDR);

using ArkFormatAdapterGetPixelFormatFunc =
    int32_t (*)(struct _ark_format_adapter_t* self);
static ArkFormatAdapterGetPixelFormatFunc ark_format_adapter_get_pixel_format =
    reinterpret_cast<ArkFormatAdapterGetPixelFormatFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
uint32_t ArkFormatAdapterCToCpp::GetWidth() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_format_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_format_adapter_get_width);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "EwK0nULuclxKLsF_isY2Pw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_FORMAT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_format_adapter_get_width");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_width)) {
        ark_format_adapter_get_width = nullptr;
      } else {
        ark_format_adapter_get_width = _struct->get_width;
      }
    } else {
      ark_format_adapter_get_width =
          reinterpret_cast<ArkFormatAdapterGetWidthFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_format_adapter_get_width, 0);

  // Execute
  return ark_format_adapter_get_width(_struct);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkFormatAdapterCToCpp::GetHeight() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_format_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_format_adapter_get_height);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "w2Z6SYdDkCjDGD66KWdm9w";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_FORMAT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_format_adapter_get_height");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_height)) {
        ark_format_adapter_get_height = nullptr;
      } else {
        ark_format_adapter_get_height = _struct->get_height;
      }
    } else {
      ark_format_adapter_get_height =
          reinterpret_cast<ArkFormatAdapterGetHeightFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_format_adapter_get_height, 0);

  // Execute
  return ark_format_adapter_get_height(_struct);
}

ARK_WEB_NO_SANITIZE
float ArkFormatAdapterCToCpp::GetFrameRate() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_format_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_format_adapter_get_frame_rate);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "VT9cOiKQmYd0mUo3tw26RQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_FORMAT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_format_adapter_get_frame_rate");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_frame_rate)) {
        ark_format_adapter_get_frame_rate = nullptr;
      } else {
        ark_format_adapter_get_frame_rate = _struct->get_frame_rate;
      }
    } else {
      ark_format_adapter_get_frame_rate =
          reinterpret_cast<ArkFormatAdapterGetFrameRateFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_format_adapter_get_frame_rate, 0);

  // Execute
  return ark_format_adapter_get_frame_rate(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkFormatAdapterCToCpp::GetPixelFormat() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_format_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_format_adapter_get_pixel_format);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ABAgH3qbO7B81LGHV77v6A";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_FORMAT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_format_adapter_get_pixel_format");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_pixel_format)) {
        ark_format_adapter_get_pixel_format = nullptr;
      } else {
        ark_format_adapter_get_pixel_format = _struct->get_pixel_format;
      }
    } else {
      ark_format_adapter_get_pixel_format =
          reinterpret_cast<ArkFormatAdapterGetPixelFormatFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_format_adapter_get_pixel_format, 0);

  // Execute
  return ark_format_adapter_get_pixel_format(_struct);
}

ArkFormatAdapterCToCpp::ArkFormatAdapterCToCpp() {}

ArkFormatAdapterCToCpp::~ArkFormatAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkFormatAdapterCToCpp,
                                        ArkFormatAdapter,
                                        ark_format_adapter_t>::kBridgeType =
    ARK_FORMAT_ADAPTER;

}  // namespace OHOS::ArkWeb
