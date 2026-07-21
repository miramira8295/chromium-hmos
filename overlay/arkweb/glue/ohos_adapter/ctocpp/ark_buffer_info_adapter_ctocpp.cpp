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

#include "ohos_adapter/ctocpp/ark_buffer_info_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkBufferInfoAdapterGetPresentationTimeUsFunc =
    int64_t (*)(struct _ark_buffer_info_adapter_t* self);
static ArkBufferInfoAdapterGetPresentationTimeUsFunc
    ark_buffer_info_adapter_get_presentation_time_us =
        reinterpret_cast<ArkBufferInfoAdapterGetPresentationTimeUsFunc>(
            ARK_WEB_INIT_ADDR);

using ArkBufferInfoAdapterGetSizeFunc =
    int32_t (*)(struct _ark_buffer_info_adapter_t* self);
static ArkBufferInfoAdapterGetSizeFunc ark_buffer_info_adapter_get_size =
    reinterpret_cast<ArkBufferInfoAdapterGetSizeFunc>(ARK_WEB_INIT_ADDR);

using ArkBufferInfoAdapterGetOffsetFunc =
    int32_t (*)(struct _ark_buffer_info_adapter_t* self);
static ArkBufferInfoAdapterGetOffsetFunc ark_buffer_info_adapter_get_offset =
    reinterpret_cast<ArkBufferInfoAdapterGetOffsetFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int64_t ArkBufferInfoAdapterCToCpp::GetPresentationTimeUs() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_buffer_info_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_buffer_info_adapter_get_presentation_time_us);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Bn_H509GbJu4xyfzyz_X$g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_BUFFER_INFO_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_buffer_info_adapter_get_presentation_time_us");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_presentation_time_us)) {
        ark_buffer_info_adapter_get_presentation_time_us = nullptr;
      } else {
        ark_buffer_info_adapter_get_presentation_time_us =
            _struct->get_presentation_time_us;
      }
    } else {
      ark_buffer_info_adapter_get_presentation_time_us =
          reinterpret_cast<ArkBufferInfoAdapterGetPresentationTimeUsFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_buffer_info_adapter_get_presentation_time_us, 0);

  // Execute
  return ark_buffer_info_adapter_get_presentation_time_us(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkBufferInfoAdapterCToCpp::GetSize() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_buffer_info_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_buffer_info_adapter_get_size);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "f$X6wTULvAVWeWfVII_p5A";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_BUFFER_INFO_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_buffer_info_adapter_get_size");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_size)) {
        ark_buffer_info_adapter_get_size = nullptr;
      } else {
        ark_buffer_info_adapter_get_size = _struct->get_size;
      }
    } else {
      ark_buffer_info_adapter_get_size =
          reinterpret_cast<ArkBufferInfoAdapterGetSizeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_buffer_info_adapter_get_size, 0);

  // Execute
  return ark_buffer_info_adapter_get_size(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkBufferInfoAdapterCToCpp::GetOffset() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_buffer_info_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_buffer_info_adapter_get_offset);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "1LWJ9DZhoj9hP9uzbVs6uQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_BUFFER_INFO_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_buffer_info_adapter_get_offset");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_offset)) {
        ark_buffer_info_adapter_get_offset = nullptr;
      } else {
        ark_buffer_info_adapter_get_offset = _struct->get_offset;
      }
    } else {
      ark_buffer_info_adapter_get_offset =
          reinterpret_cast<ArkBufferInfoAdapterGetOffsetFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_buffer_info_adapter_get_offset, 0);

  // Execute
  return ark_buffer_info_adapter_get_offset(_struct);
}

ArkBufferInfoAdapterCToCpp::ArkBufferInfoAdapterCToCpp() {}

ArkBufferInfoAdapterCToCpp::~ArkBufferInfoAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkBufferInfoAdapterCToCpp,
                           ArkBufferInfoAdapter,
                           ark_buffer_info_adapter_t>::kBridgeType =
        ARK_BUFFER_INFO_ADAPTER;

}  // namespace OHOS::ArkWeb
