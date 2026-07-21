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

#include "ohos_adapter/ctocpp/ark_iconsumer_surface_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_ibuffer_consumer_listener_adapter_cpptoc.h"
#include "ohos_adapter/ctocpp/ark_surface_buffer_adapter_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkIConsumerSurfaceAdapterRegisterConsumerListenerFunc =
    int32_t (*)(struct _ark_iconsumer_surface_adapter_t* self,
                ark_ibuffer_consumer_listener_adapter_t* listener);
static ArkIConsumerSurfaceAdapterRegisterConsumerListenerFunc
    ark_iconsumer_surface_adapter_register_consumer_listener = reinterpret_cast<
        ArkIConsumerSurfaceAdapterRegisterConsumerListenerFunc>(
        ARK_WEB_INIT_ADDR);

using ArkIConsumerSurfaceAdapterReleaseBufferFunc =
    int32_t (*)(struct _ark_iconsumer_surface_adapter_t* self,
                ark_surface_buffer_adapter_t* buffer,
                int32_t fence);
static ArkIConsumerSurfaceAdapterReleaseBufferFunc
    ark_iconsumer_surface_adapter_release_buffer =
        reinterpret_cast<ArkIConsumerSurfaceAdapterReleaseBufferFunc>(
            ARK_WEB_INIT_ADDR);

using ArkIConsumerSurfaceAdapterSetUserDataFunc =
    int32_t (*)(struct _ark_iconsumer_surface_adapter_t* self,
                const ArkWebString* key,
                const ArkWebString* val);
static ArkIConsumerSurfaceAdapterSetUserDataFunc
    ark_iconsumer_surface_adapter_set_user_data =
        reinterpret_cast<ArkIConsumerSurfaceAdapterSetUserDataFunc>(
            ARK_WEB_INIT_ADDR);

using ArkIConsumerSurfaceAdapterSetQueueSizeFunc =
    int32_t (*)(struct _ark_iconsumer_surface_adapter_t* self,
                uint32_t queueSize);
static ArkIConsumerSurfaceAdapterSetQueueSizeFunc
    ark_iconsumer_surface_adapter_set_queue_size =
        reinterpret_cast<ArkIConsumerSurfaceAdapterSetQueueSizeFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkIConsumerSurfaceAdapterCToCpp::RegisterConsumerListener(
    ArkWebRefPtr<ArkIBufferConsumerListenerAdapter> listener) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_iconsumer_surface_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_iconsumer_surface_adapter_register_consumer_listener);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "zchYKuxg2hTAjskHvTEUBQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_ICONSUMER_SURFACE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_iconsumer_surface_adapter_register_consumer_listener");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, register_consumer_listener)) {
        ark_iconsumer_surface_adapter_register_consumer_listener = nullptr;
      } else {
        ark_iconsumer_surface_adapter_register_consumer_listener =
            _struct->register_consumer_listener;
      }
    } else {
      ark_iconsumer_surface_adapter_register_consumer_listener =
          reinterpret_cast<
              ArkIConsumerSurfaceAdapterRegisterConsumerListenerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_iconsumer_surface_adapter_register_consumer_listener, 0);

  // Execute
  return ark_iconsumer_surface_adapter_register_consumer_listener(
      _struct, ArkIBufferConsumerListenerAdapterCppToC::Invert(listener));
}

ARK_WEB_NO_SANITIZE
int32_t ArkIConsumerSurfaceAdapterCToCpp::ReleaseBuffer(
    ArkWebRefPtr<ArkSurfaceBufferAdapter> buffer,
    int32_t fence) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_iconsumer_surface_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_iconsumer_surface_adapter_release_buffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "G8dIrNvg$zgbCcYEiHzusw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_ICONSUMER_SURFACE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_iconsumer_surface_adapter_release_buffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release_buffer)) {
        ark_iconsumer_surface_adapter_release_buffer = nullptr;
      } else {
        ark_iconsumer_surface_adapter_release_buffer = _struct->release_buffer;
      }
    } else {
      ark_iconsumer_surface_adapter_release_buffer =
          reinterpret_cast<ArkIConsumerSurfaceAdapterReleaseBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_iconsumer_surface_adapter_release_buffer, 0);

  // Execute
  return ark_iconsumer_surface_adapter_release_buffer(
      _struct, ArkSurfaceBufferAdapterCToCpp::Revert(buffer), fence);
}

ARK_WEB_NO_SANITIZE
int32_t ArkIConsumerSurfaceAdapterCToCpp::SetUserData(const ArkWebString& key,
                                                      const ArkWebString& val) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_iconsumer_surface_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_iconsumer_surface_adapter_set_user_data);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "SqGybSSgjyO3h2d$aJ5VLw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_ICONSUMER_SURFACE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_iconsumer_surface_adapter_set_user_data");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_user_data)) {
        ark_iconsumer_surface_adapter_set_user_data = nullptr;
      } else {
        ark_iconsumer_surface_adapter_set_user_data = _struct->set_user_data;
      }
    } else {
      ark_iconsumer_surface_adapter_set_user_data =
          reinterpret_cast<ArkIConsumerSurfaceAdapterSetUserDataFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_iconsumer_surface_adapter_set_user_data,
                                    0);

  // Execute
  return ark_iconsumer_surface_adapter_set_user_data(_struct, &key, &val);
}

ARK_WEB_NO_SANITIZE
int32_t ArkIConsumerSurfaceAdapterCToCpp::SetQueueSize(uint32_t queueSize) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_iconsumer_surface_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_iconsumer_surface_adapter_set_queue_size);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "aILSmndpWHY9AMBmGio4oQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_ICONSUMER_SURFACE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_iconsumer_surface_adapter_set_queue_size");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_queue_size)) {
        ark_iconsumer_surface_adapter_set_queue_size = nullptr;
      } else {
        ark_iconsumer_surface_adapter_set_queue_size = _struct->set_queue_size;
      }
    } else {
      ark_iconsumer_surface_adapter_set_queue_size =
          reinterpret_cast<ArkIConsumerSurfaceAdapterSetQueueSizeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_iconsumer_surface_adapter_set_queue_size, 0);

  // Execute
  return ark_iconsumer_surface_adapter_set_queue_size(_struct, queueSize);
}

ArkIConsumerSurfaceAdapterCToCpp::ArkIConsumerSurfaceAdapterCToCpp() {}

ArkIConsumerSurfaceAdapterCToCpp::~ArkIConsumerSurfaceAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkIConsumerSurfaceAdapterCToCpp,
                           ArkIConsumerSurfaceAdapter,
                           ark_iconsumer_surface_adapter_t>::kBridgeType =
        ARK_ICONSUMER_SURFACE_ADAPTER;

}  // namespace OHOS::ArkWeb
