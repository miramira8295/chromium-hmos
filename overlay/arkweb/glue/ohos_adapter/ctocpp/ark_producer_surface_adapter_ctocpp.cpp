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

#include "ohos_adapter/ctocpp/ark_producer_surface_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_buffer_flush_config_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_buffer_request_config_adapter_cpptoc.h"
#include "ohos_adapter/ctocpp/ark_surface_buffer_adapter_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkProducerSurfaceAdapterRequestBufferFunc =
    ark_surface_buffer_adapter_t* (*)(struct _ark_producer_surface_adapter_t*
                                          self,
                                      int32_t* fence,
                                      ark_buffer_request_config_adapter_t*
                                          config);
static ArkProducerSurfaceAdapterRequestBufferFunc
    ark_producer_surface_adapter_request_buffer =
        reinterpret_cast<ArkProducerSurfaceAdapterRequestBufferFunc>(
            ARK_WEB_INIT_ADDR);

using ArkProducerSurfaceAdapterFlushBufferFunc =
    int32_t (*)(struct _ark_producer_surface_adapter_t* self,
                ark_surface_buffer_adapter_t* buffer,
                int32_t fence,
                ark_buffer_flush_config_adapter_t* config);
static ArkProducerSurfaceAdapterFlushBufferFunc
    ark_producer_surface_adapter_flush_buffer =
        reinterpret_cast<ArkProducerSurfaceAdapterFlushBufferFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkSurfaceBufferAdapter>
ArkProducerSurfaceAdapterCToCpp::RequestBuffer(
    int32_t& fence,
    ArkWebRefPtr<ArkBufferRequestConfigAdapter> config) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_producer_surface_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_producer_surface_adapter_request_buffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "i3yQoueX_TKLPy4epvG4gQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PRODUCER_SURFACE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_producer_surface_adapter_request_buffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, request_buffer)) {
        ark_producer_surface_adapter_request_buffer = nullptr;
      } else {
        ark_producer_surface_adapter_request_buffer = _struct->request_buffer;
      }
    } else {
      ark_producer_surface_adapter_request_buffer =
          reinterpret_cast<ArkProducerSurfaceAdapterRequestBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_producer_surface_adapter_request_buffer,
                                    nullptr);

  // Execute
  ark_surface_buffer_adapter_t* _retval =
      ark_producer_surface_adapter_request_buffer(
          _struct, &fence, ArkBufferRequestConfigAdapterCppToC::Invert(config));

  // Return type: refptr_same
  return ArkSurfaceBufferAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
int32_t ArkProducerSurfaceAdapterCToCpp::FlushBuffer(
    ArkWebRefPtr<ArkSurfaceBufferAdapter> buffer,
    int32_t fence,
    ArkWebRefPtr<ArkBufferFlushConfigAdapter> config) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_producer_surface_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_producer_surface_adapter_flush_buffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ZefC5LDsFeLAj17wyVirJg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PRODUCER_SURFACE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_producer_surface_adapter_flush_buffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, flush_buffer)) {
        ark_producer_surface_adapter_flush_buffer = nullptr;
      } else {
        ark_producer_surface_adapter_flush_buffer = _struct->flush_buffer;
      }
    } else {
      ark_producer_surface_adapter_flush_buffer =
          reinterpret_cast<ArkProducerSurfaceAdapterFlushBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_producer_surface_adapter_flush_buffer,
                                    0);

  // Execute
  return ark_producer_surface_adapter_flush_buffer(
      _struct, ArkSurfaceBufferAdapterCToCpp::Revert(buffer), fence,
      ArkBufferFlushConfigAdapterCppToC::Invert(config));
}

ArkProducerSurfaceAdapterCToCpp::ArkProducerSurfaceAdapterCToCpp() {}

ArkProducerSurfaceAdapterCToCpp::~ArkProducerSurfaceAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkProducerSurfaceAdapterCToCpp,
                           ArkProducerSurfaceAdapter,
                           ark_producer_surface_adapter_t>::kBridgeType =
        ARK_PRODUCER_SURFACE_ADAPTER;

}  // namespace OHOS::ArkWeb
