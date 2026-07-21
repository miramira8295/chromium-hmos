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

#include "ohos_nweb/ctocpp/ark_web_print_attributes_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebPrintAttributesAdapterGetBoolFunc =
    bool (*)(struct _ark_web_print_attributes_adapter_t* self, uint32_t attrId);
static ArkWebPrintAttributesAdapterGetBoolFunc
    ark_web_print_attributes_adapter_get_bool =
        reinterpret_cast<ArkWebPrintAttributesAdapterGetBoolFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebPrintAttributesAdapterGetUInt32Func =
    uint32_t (*)(struct _ark_web_print_attributes_adapter_t* self,
                 uint32_t attrId);
static ArkWebPrintAttributesAdapterGetUInt32Func
    ark_web_print_attributes_adapter_get_uint32 =
        reinterpret_cast<ArkWebPrintAttributesAdapterGetUInt32Func>(
            ARK_WEB_INIT_ADDR);

using ArkWebPrintAttributesAdapterGetStringFunc =
    ArkWebString (*)(struct _ark_web_print_attributes_adapter_t* self,
                     uint32_t attrId);
static ArkWebPrintAttributesAdapterGetStringFunc
    ark_web_print_attributes_adapter_get_string =
        reinterpret_cast<ArkWebPrintAttributesAdapterGetStringFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebPrintAttributesAdapterGetUint32VectorFunc =
    ArkWebUint32Vector (*)(struct _ark_web_print_attributes_adapter_t* self,
                           uint32_t attrId);
static ArkWebPrintAttributesAdapterGetUint32VectorFunc
    ark_web_print_attributes_adapter_get_uint32vector =
        reinterpret_cast<ArkWebPrintAttributesAdapterGetUint32VectorFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
bool ArkWebPrintAttributesAdapterCToCpp::GetBool(uint32_t attrId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_print_attributes_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_print_attributes_adapter_get_bool);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "B2a_lsvXnSXtOQpYaokvMA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_PRINT_ATTRIBUTES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_print_attributes_adapter_get_bool");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_bool)) {
        ark_web_print_attributes_adapter_get_bool = nullptr;
      } else {
        ark_web_print_attributes_adapter_get_bool = _struct->get_bool;
      }
    } else {
      ark_web_print_attributes_adapter_get_bool =
          reinterpret_cast<ArkWebPrintAttributesAdapterGetBoolFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_print_attributes_adapter_get_bool,
                                    false);

  // Execute
  return ark_web_print_attributes_adapter_get_bool(_struct, attrId);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkWebPrintAttributesAdapterCToCpp::GetUInt32(uint32_t attrId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_print_attributes_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_print_attributes_adapter_get_uint32);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jj$trS4I2KYc0CmpXywgrA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_PRINT_ATTRIBUTES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_print_attributes_adapter_get_uint32");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_uint32)) {
        ark_web_print_attributes_adapter_get_uint32 = nullptr;
      } else {
        ark_web_print_attributes_adapter_get_uint32 = _struct->get_uint32;
      }
    } else {
      ark_web_print_attributes_adapter_get_uint32 =
          reinterpret_cast<ArkWebPrintAttributesAdapterGetUInt32Func>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_print_attributes_adapter_get_uint32,
                                    0);

  // Execute
  return ark_web_print_attributes_adapter_get_uint32(_struct, attrId);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkWebPrintAttributesAdapterCToCpp::GetString(uint32_t attrId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_print_attributes_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_print_attributes_adapter_get_string);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "aH1i_WxWq2gmDW3EX82x4g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_PRINT_ATTRIBUTES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_print_attributes_adapter_get_string");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_string)) {
        ark_web_print_attributes_adapter_get_string = nullptr;
      } else {
        ark_web_print_attributes_adapter_get_string = _struct->get_string;
      }
    } else {
      ark_web_print_attributes_adapter_get_string =
          reinterpret_cast<ArkWebPrintAttributesAdapterGetStringFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_print_attributes_adapter_get_string,
                                    ark_web_string_default);

  // Execute
  return ark_web_print_attributes_adapter_get_string(_struct, attrId);
}

ARK_WEB_NO_SANITIZE
ArkWebUint32Vector ArkWebPrintAttributesAdapterCToCpp::GetUint32Vector(
    uint32_t attrId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_print_attributes_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_uint32_vector_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_print_attributes_adapter_get_uint32vector);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "yBbuDHtqNRoRgoxKsYw2yQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_PRINT_ATTRIBUTES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_print_attributes_adapter_get_uint32vector");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_uint32vector)) {
        ark_web_print_attributes_adapter_get_uint32vector = nullptr;
      } else {
        ark_web_print_attributes_adapter_get_uint32vector =
            _struct->get_uint32vector;
      }
    } else {
      ark_web_print_attributes_adapter_get_uint32vector =
          reinterpret_cast<ArkWebPrintAttributesAdapterGetUint32VectorFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_print_attributes_adapter_get_uint32vector,
      ark_web_uint32_vector_default);

  // Execute
  return ark_web_print_attributes_adapter_get_uint32vector(_struct, attrId);
}

ArkWebPrintAttributesAdapterCToCpp::ArkWebPrintAttributesAdapterCToCpp() {}

ArkWebPrintAttributesAdapterCToCpp::~ArkWebPrintAttributesAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkWebPrintAttributesAdapterCToCpp,
                           ArkWebPrintAttributesAdapter,
                           ark_web_print_attributes_adapter_t>::kBridgeType =
        ARK_WEB_PRINT_ATTRIBUTES_ADAPTER;

}  // namespace OHOS::ArkWeb
