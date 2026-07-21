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

#include "ohos_adapter/ctocpp/ark_net_proxy_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_net_proxy_event_callback_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkNetProxyAdapterRegNetProxyEventFunc =
    void (*)(struct _ark_net_proxy_adapter_t* self,
             ark_net_proxy_event_callback_adapter_t* eventCallback);
static ArkNetProxyAdapterRegNetProxyEventFunc
    ark_net_proxy_adapter_reg_net_proxy_event =
        reinterpret_cast<ArkNetProxyAdapterRegNetProxyEventFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNetProxyAdapterStartListenFunc =
    bool (*)(struct _ark_net_proxy_adapter_t* self);
static ArkNetProxyAdapterStartListenFunc ark_net_proxy_adapter_start_listen =
    reinterpret_cast<ArkNetProxyAdapterStartListenFunc>(ARK_WEB_INIT_ADDR);

using ArkNetProxyAdapterStopListenFunc =
    void (*)(struct _ark_net_proxy_adapter_t* self);
static ArkNetProxyAdapterStopListenFunc ark_net_proxy_adapter_stop_listen =
    reinterpret_cast<ArkNetProxyAdapterStopListenFunc>(ARK_WEB_INIT_ADDR);

using ArkNetProxyAdapterGetPropertyFunc =
    void (*)(struct _ark_net_proxy_adapter_t* self,
             ArkWebString* host,
             uint16_t* port,
             ArkWebString* pacUrl,
             ArkWebString* exclusion);
static ArkNetProxyAdapterGetPropertyFunc ark_net_proxy_adapter_get_property =
    reinterpret_cast<ArkNetProxyAdapterGetPropertyFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkNetProxyAdapterCToCpp::RegNetProxyEvent(
    ArkWebRefPtr<ArkNetProxyEventCallbackAdapter> eventCallback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_net_proxy_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_net_proxy_adapter_reg_net_proxy_event);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "0_68TZzRjJ_w5LMUb3K1NA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NET_PROXY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_net_proxy_adapter_reg_net_proxy_event");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, reg_net_proxy_event)) {
        ark_net_proxy_adapter_reg_net_proxy_event = nullptr;
      } else {
        ark_net_proxy_adapter_reg_net_proxy_event =
            _struct->reg_net_proxy_event;
      }
    } else {
      ark_net_proxy_adapter_reg_net_proxy_event =
          reinterpret_cast<ArkNetProxyAdapterRegNetProxyEventFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_net_proxy_adapter_reg_net_proxy_event,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_net_proxy_adapter_reg_net_proxy_event(
      _struct, ArkNetProxyEventCallbackAdapterCppToC::Invert(eventCallback));
}

ARK_WEB_NO_SANITIZE
bool ArkNetProxyAdapterCToCpp::StartListen() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_net_proxy_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_net_proxy_adapter_start_listen);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "uXWpVJZ$oQCF$eFak32LAw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NET_PROXY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_net_proxy_adapter_start_listen");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start_listen)) {
        ark_net_proxy_adapter_start_listen = nullptr;
      } else {
        ark_net_proxy_adapter_start_listen = _struct->start_listen;
      }
    } else {
      ark_net_proxy_adapter_start_listen =
          reinterpret_cast<ArkNetProxyAdapterStartListenFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_net_proxy_adapter_start_listen, false);

  // Execute
  return ark_net_proxy_adapter_start_listen(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkNetProxyAdapterCToCpp::StopListen() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_net_proxy_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_net_proxy_adapter_stop_listen);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Pd1DNuNpENvTA_1GlVnABg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NET_PROXY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_net_proxy_adapter_stop_listen");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, stop_listen)) {
        ark_net_proxy_adapter_stop_listen = nullptr;
      } else {
        ark_net_proxy_adapter_stop_listen = _struct->stop_listen;
      }
    } else {
      ark_net_proxy_adapter_stop_listen =
          reinterpret_cast<ArkNetProxyAdapterStopListenFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_net_proxy_adapter_stop_listen,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_net_proxy_adapter_stop_listen(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkNetProxyAdapterCToCpp::GetProperty(ArkWebString& host,
                                           uint16_t& port,
                                           ArkWebString& pacUrl,
                                           ArkWebString& exclusion) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_net_proxy_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_net_proxy_adapter_get_property);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "XKaKuOSIIUadMn0ga58ysg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NET_PROXY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_net_proxy_adapter_get_property");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_property)) {
        ark_net_proxy_adapter_get_property = nullptr;
      } else {
        ark_net_proxy_adapter_get_property = _struct->get_property;
      }
    } else {
      ark_net_proxy_adapter_get_property =
          reinterpret_cast<ArkNetProxyAdapterGetPropertyFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_net_proxy_adapter_get_property,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_net_proxy_adapter_get_property(_struct, &host, &port, &pacUrl,
                                     &exclusion);
}

ArkNetProxyAdapterCToCpp::ArkNetProxyAdapterCToCpp() {}

ArkNetProxyAdapterCToCpp::~ArkNetProxyAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkNetProxyAdapterCToCpp,
                                        ArkNetProxyAdapter,
                                        ark_net_proxy_adapter_t>::kBridgeType =
    ARK_NET_PROXY_ADAPTER;

}  // namespace OHOS::ArkWeb
