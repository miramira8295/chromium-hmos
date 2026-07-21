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

#include "ohos_adapter/ctocpp/ark_capability_data_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkCapabilityDataAdapterGetMaxWidthFunc =
    int32_t (*)(struct _ark_capability_data_adapter_t* self);
static ArkCapabilityDataAdapterGetMaxWidthFunc
    ark_capability_data_adapter_get_max_width =
        reinterpret_cast<ArkCapabilityDataAdapterGetMaxWidthFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCapabilityDataAdapterGetMaxHeightFunc =
    int32_t (*)(struct _ark_capability_data_adapter_t* self);
static ArkCapabilityDataAdapterGetMaxHeightFunc
    ark_capability_data_adapter_get_max_height =
        reinterpret_cast<ArkCapabilityDataAdapterGetMaxHeightFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCapabilityDataAdapterGetMaxframeRateFunc =
    int32_t (*)(struct _ark_capability_data_adapter_t* self);
static ArkCapabilityDataAdapterGetMaxframeRateFunc
    ark_capability_data_adapter_get_maxframe_rate =
        reinterpret_cast<ArkCapabilityDataAdapterGetMaxframeRateFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkCapabilityDataAdapterCToCpp::GetMaxWidth() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_capability_data_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_capability_data_adapter_get_max_width);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "CimK8536O40T2IicM_DcUw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAPABILITY_DATA_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_capability_data_adapter_get_max_width");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_max_width)) {
        ark_capability_data_adapter_get_max_width = nullptr;
      } else {
        ark_capability_data_adapter_get_max_width = _struct->get_max_width;
      }
    } else {
      ark_capability_data_adapter_get_max_width =
          reinterpret_cast<ArkCapabilityDataAdapterGetMaxWidthFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_capability_data_adapter_get_max_width,
                                    0);

  // Execute
  return ark_capability_data_adapter_get_max_width(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCapabilityDataAdapterCToCpp::GetMaxHeight() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_capability_data_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_capability_data_adapter_get_max_height);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "iYSvpXK7sQHaAuLFgThgQg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAPABILITY_DATA_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_capability_data_adapter_get_max_height");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_max_height)) {
        ark_capability_data_adapter_get_max_height = nullptr;
      } else {
        ark_capability_data_adapter_get_max_height = _struct->get_max_height;
      }
    } else {
      ark_capability_data_adapter_get_max_height =
          reinterpret_cast<ArkCapabilityDataAdapterGetMaxHeightFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_capability_data_adapter_get_max_height,
                                    0);

  // Execute
  return ark_capability_data_adapter_get_max_height(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCapabilityDataAdapterCToCpp::GetMaxframeRate() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_capability_data_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_capability_data_adapter_get_maxframe_rate);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "C7iwMOPqz0ngYwXvm8CBFw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAPABILITY_DATA_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_capability_data_adapter_get_maxframe_rate");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_maxframe_rate)) {
        ark_capability_data_adapter_get_maxframe_rate = nullptr;
      } else {
        ark_capability_data_adapter_get_maxframe_rate =
            _struct->get_maxframe_rate;
      }
    } else {
      ark_capability_data_adapter_get_maxframe_rate =
          reinterpret_cast<ArkCapabilityDataAdapterGetMaxframeRateFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_capability_data_adapter_get_maxframe_rate, 0);

  // Execute
  return ark_capability_data_adapter_get_maxframe_rate(_struct);
}

ArkCapabilityDataAdapterCToCpp::ArkCapabilityDataAdapterCToCpp() {}

ArkCapabilityDataAdapterCToCpp::~ArkCapabilityDataAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkCapabilityDataAdapterCToCpp,
                           ArkCapabilityDataAdapter,
                           ark_capability_data_adapter_t>::kBridgeType =
        ARK_CAPABILITY_DATA_ADAPTER;

}  // namespace OHOS::ArkWeb
