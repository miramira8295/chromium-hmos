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

#include "ohos_adapter/ctocpp/ark_ohos_buffer_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkOhosBufferAdapterGetAddrFunc =
    uint8_t* (*)(struct _ark_ohos_buffer_adapter_t* self);
static ArkOhosBufferAdapterGetAddrFunc ark_ohos_buffer_adapter_get_addr =
    reinterpret_cast<ArkOhosBufferAdapterGetAddrFunc>(ARK_WEB_INIT_ADDR);

using ArkOhosBufferAdapterGetBufferSizeFunc =
    uint32_t (*)(struct _ark_ohos_buffer_adapter_t* self);
static ArkOhosBufferAdapterGetBufferSizeFunc
    ark_ohos_buffer_adapter_get_buffer_size =
        reinterpret_cast<ArkOhosBufferAdapterGetBufferSizeFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
uint8_t* ArkOhosBufferAdapterCToCpp::GetAddr() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_buffer_adapter_get_addr);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jN0HvJZRp2d4nulDQd1mRQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_buffer_adapter_get_addr");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_addr)) {
        ark_ohos_buffer_adapter_get_addr = nullptr;
      } else {
        ark_ohos_buffer_adapter_get_addr = _struct->get_addr;
      }
    } else {
      ark_ohos_buffer_adapter_get_addr =
          reinterpret_cast<ArkOhosBufferAdapterGetAddrFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_buffer_adapter_get_addr, nullptr);

  // Execute
  return ark_ohos_buffer_adapter_get_addr(_struct);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkOhosBufferAdapterCToCpp::GetBufferSize() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_buffer_adapter_get_buffer_size);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "MayFTiREKPjVrv4wC1RtAQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_buffer_adapter_get_buffer_size");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_buffer_size)) {
        ark_ohos_buffer_adapter_get_buffer_size = nullptr;
      } else {
        ark_ohos_buffer_adapter_get_buffer_size = _struct->get_buffer_size;
      }
    } else {
      ark_ohos_buffer_adapter_get_buffer_size =
          reinterpret_cast<ArkOhosBufferAdapterGetBufferSizeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_buffer_adapter_get_buffer_size, 0);

  // Execute
  return ark_ohos_buffer_adapter_get_buffer_size(_struct);
}

ArkOhosBufferAdapterCToCpp::ArkOhosBufferAdapterCToCpp() {}

ArkOhosBufferAdapterCToCpp::~ArkOhosBufferAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkOhosBufferAdapterCToCpp,
                           ArkOhosBufferAdapter,
                           ark_ohos_buffer_adapter_t>::kBridgeType =
        ARK_OHOS_BUFFER_ADAPTER;

}  // namespace OHOS::ArkWeb
