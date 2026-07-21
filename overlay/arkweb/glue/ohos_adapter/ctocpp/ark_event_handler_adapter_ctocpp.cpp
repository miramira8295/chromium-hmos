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

#include "ohos_adapter/ctocpp/ark_event_handler_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_event_handler_fdlistener_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_once_callback_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkEventHandlerAdapterAddFileDescriptorListenerFunc =
    bool (*)(struct _ark_event_handler_adapter_t* self,
             int32_t fileDescriptor,
             uint32_t events,
             ark_event_handler_fdlistener_adapter_t* listener);
static ArkEventHandlerAdapterAddFileDescriptorListenerFunc
    ark_event_handler_adapter_add_file_descriptor_listener =
        reinterpret_cast<ArkEventHandlerAdapterAddFileDescriptorListenerFunc>(
            ARK_WEB_INIT_ADDR);

using ArkEventHandlerAdapterRemoveFileDescriptorListenerFunc =
    void (*)(struct _ark_event_handler_adapter_t* self, int32_t fileDescriptor);
static ArkEventHandlerAdapterRemoveFileDescriptorListenerFunc
    ark_event_handler_adapter_remove_file_descriptor_listener =
        reinterpret_cast<
            ArkEventHandlerAdapterRemoveFileDescriptorListenerFunc>(
            ARK_WEB_INIT_ADDR);

using ArkEventHandlerAdapterPostTaskFunc =
    void (*)(struct _ark_event_handler_adapter_t* self,
             ark_once_callback_adapter_t* callback);
static ArkEventHandlerAdapterPostTaskFunc ark_event_handler_adapter_post_task =
    reinterpret_cast<ArkEventHandlerAdapterPostTaskFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
bool ArkEventHandlerAdapterCToCpp::AddFileDescriptorListener(
    int32_t fileDescriptor,
    uint32_t events,
    const ArkWebRefPtr<ArkEventHandlerFDListenerAdapter> listener) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_event_handler_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_event_handler_adapter_add_file_descriptor_listener);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "WTBOkM_seIv27ToZztvXOg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_EVENT_HANDLER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_event_handler_adapter_add_file_descriptor_listener");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, add_file_descriptor_listener)) {
        ark_event_handler_adapter_add_file_descriptor_listener = nullptr;
      } else {
        ark_event_handler_adapter_add_file_descriptor_listener =
            _struct->add_file_descriptor_listener;
      }
    } else {
      ark_event_handler_adapter_add_file_descriptor_listener =
          reinterpret_cast<ArkEventHandlerAdapterAddFileDescriptorListenerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_event_handler_adapter_add_file_descriptor_listener, false);

  // Execute
  return ark_event_handler_adapter_add_file_descriptor_listener(
      _struct, fileDescriptor, events,
      ArkEventHandlerFDListenerAdapterCppToC::Invert(listener));
}

ARK_WEB_NO_SANITIZE
void ArkEventHandlerAdapterCToCpp::RemoveFileDescriptorListener(
    int32_t fileDescriptor) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_event_handler_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_event_handler_adapter_remove_file_descriptor_listener);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "yAqsZJLeZjXwiTm38fUXAg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_EVENT_HANDLER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_event_handler_adapter_remove_file_descriptor_listener");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      remove_file_descriptor_listener)) {
        ark_event_handler_adapter_remove_file_descriptor_listener = nullptr;
      } else {
        ark_event_handler_adapter_remove_file_descriptor_listener =
            _struct->remove_file_descriptor_listener;
      }
    } else {
      ark_event_handler_adapter_remove_file_descriptor_listener =
          reinterpret_cast<
              ArkEventHandlerAdapterRemoveFileDescriptorListenerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_event_handler_adapter_remove_file_descriptor_listener,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_event_handler_adapter_remove_file_descriptor_listener(_struct,
                                                            fileDescriptor);
}

ARK_WEB_NO_SANITIZE
void ArkEventHandlerAdapterCToCpp::PostTask(
    ArkWebRefPtr<ArkOnceCallbackAdapter> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_event_handler_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_event_handler_adapter_post_task);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "i5$UPZSJUMMa4ErfEmMKIw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_EVENT_HANDLER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_event_handler_adapter_post_task");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, post_task)) {
        ark_event_handler_adapter_post_task = nullptr;
      } else {
        ark_event_handler_adapter_post_task = _struct->post_task;
      }
    } else {
      ark_event_handler_adapter_post_task =
          reinterpret_cast<ArkEventHandlerAdapterPostTaskFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_event_handler_adapter_post_task,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_event_handler_adapter_post_task(
      _struct, ArkOnceCallbackAdapterCppToC::Invert(callback));
}

ArkEventHandlerAdapterCToCpp::ArkEventHandlerAdapterCToCpp() {}

ArkEventHandlerAdapterCToCpp::~ArkEventHandlerAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkEventHandlerAdapterCToCpp,
                           ArkEventHandlerAdapter,
                           ark_event_handler_adapter_t>::kBridgeType =
        ARK_EVENT_HANDLER_ADAPTER;

}  // namespace OHOS::ArkWeb
