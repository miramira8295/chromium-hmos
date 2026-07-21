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

#include "ohos_adapter/ctocpp/ark_net_connect_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_net_conn_callback_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_vpn_listener_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkNetConnectAdapterRegisterNetConnCallbackFunc =
    int32_t (*)(struct _ark_net_connect_adapter_t* self,
                ark_net_conn_callback_t* cb);
static ArkNetConnectAdapterRegisterNetConnCallbackFunc
    ark_net_connect_adapter_register_net_conn_callback =
        reinterpret_cast<ArkNetConnectAdapterRegisterNetConnCallbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNetConnectAdapterUnregisterNetConnCallbackFunc =
    int32_t (*)(struct _ark_net_connect_adapter_t* self, int32_t id);
static ArkNetConnectAdapterUnregisterNetConnCallbackFunc
    ark_net_connect_adapter_unregister_net_conn_callback =
        reinterpret_cast<ArkNetConnectAdapterUnregisterNetConnCallbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNetConnectAdapterGetDefaultNetConnectFunc =
    int32_t (*)(struct _ark_net_connect_adapter_t* self,
                uint32_t* type,
                uint32_t* netConnectSubtype);
static ArkNetConnectAdapterGetDefaultNetConnectFunc
    ark_net_connect_adapter_get_default_net_connect =
        reinterpret_cast<ArkNetConnectAdapterGetDefaultNetConnectFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNetConnectAdapterGetDnsServersFunc =
    ArkWebStringVector (*)(struct _ark_net_connect_adapter_t* self);
static ArkNetConnectAdapterGetDnsServersFunc
    ark_net_connect_adapter_get_dns_servers =
        reinterpret_cast<ArkNetConnectAdapterGetDnsServersFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNetConnectAdapterGetDnsServersByNetIdFunc =
    ArkWebStringVector (*)(struct _ark_net_connect_adapter_t* self,
                           int32_t netId);
static ArkNetConnectAdapterGetDnsServersByNetIdFunc
    ark_net_connect_adapter_get_dns_servers_by_net_id =
        reinterpret_cast<ArkNetConnectAdapterGetDnsServersByNetIdFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNetConnectAdapterGetDnsServersForVpnFunc =
    ArkWebStringVector (*)(struct _ark_net_connect_adapter_t* self);
static ArkNetConnectAdapterGetDnsServersForVpnFunc
    ark_net_connect_adapter_get_dns_servers_for_vpn =
        reinterpret_cast<ArkNetConnectAdapterGetDnsServersForVpnFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNetConnectAdapterRegisterVpnListenerFunc =
    void (*)(struct _ark_net_connect_adapter_t* self, ark_vpn_listener_t* cb);
static ArkNetConnectAdapterRegisterVpnListenerFunc
    ark_net_connect_adapter_register_vpn_listener =
        reinterpret_cast<ArkNetConnectAdapterRegisterVpnListenerFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNetConnectAdapterUnRegisterVpnListenerFunc =
    void (*)(struct _ark_net_connect_adapter_t* self);
static ArkNetConnectAdapterUnRegisterVpnListenerFunc
    ark_net_connect_adapter_un_register_vpn_listener =
        reinterpret_cast<ArkNetConnectAdapterUnRegisterVpnListenerFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkNetConnectAdapterCToCpp::RegisterNetConnCallback(
    ArkWebRefPtr<ArkNetConnCallback> cb) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_net_connect_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_net_connect_adapter_register_net_conn_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "F2CIoPtZivdDFfVzEpcJFQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NET_CONNECT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_net_connect_adapter_register_net_conn_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, register_net_conn_callback)) {
        ark_net_connect_adapter_register_net_conn_callback = nullptr;
      } else {
        ark_net_connect_adapter_register_net_conn_callback =
            _struct->register_net_conn_callback;
      }
    } else {
      ark_net_connect_adapter_register_net_conn_callback =
          reinterpret_cast<ArkNetConnectAdapterRegisterNetConnCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_net_connect_adapter_register_net_conn_callback, 0);

  // Execute
  return ark_net_connect_adapter_register_net_conn_callback(
      _struct, ArkNetConnCallbackCppToC::Invert(cb));
}

ARK_WEB_NO_SANITIZE
int32_t ArkNetConnectAdapterCToCpp::UnregisterNetConnCallback(int32_t id) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_net_connect_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_net_connect_adapter_unregister_net_conn_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "n9Ut9aoFDPM8OIF91OooFw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NET_CONNECT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_net_connect_adapter_unregister_net_conn_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, unregister_net_conn_callback)) {
        ark_net_connect_adapter_unregister_net_conn_callback = nullptr;
      } else {
        ark_net_connect_adapter_unregister_net_conn_callback =
            _struct->unregister_net_conn_callback;
      }
    } else {
      ark_net_connect_adapter_unregister_net_conn_callback =
          reinterpret_cast<ArkNetConnectAdapterUnregisterNetConnCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_net_connect_adapter_unregister_net_conn_callback, 0);

  // Execute
  return ark_net_connect_adapter_unregister_net_conn_callback(_struct, id);
}

ARK_WEB_NO_SANITIZE
int32_t ArkNetConnectAdapterCToCpp::GetDefaultNetConnect(
    uint32_t& type,
    uint32_t& netConnectSubtype) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_net_connect_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_net_connect_adapter_get_default_net_connect);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "oj6THZdBoVzIn_WIXVamiQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NET_CONNECT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_net_connect_adapter_get_default_net_connect");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_default_net_connect)) {
        ark_net_connect_adapter_get_default_net_connect = nullptr;
      } else {
        ark_net_connect_adapter_get_default_net_connect =
            _struct->get_default_net_connect;
      }
    } else {
      ark_net_connect_adapter_get_default_net_connect =
          reinterpret_cast<ArkNetConnectAdapterGetDefaultNetConnectFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_net_connect_adapter_get_default_net_connect, 0);

  // Execute
  return ark_net_connect_adapter_get_default_net_connect(_struct, &type,
                                                         &netConnectSubtype);
}

ARK_WEB_NO_SANITIZE
ArkWebStringVector ArkNetConnectAdapterCToCpp::GetDnsServers() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_net_connect_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_vector_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_net_connect_adapter_get_dns_servers);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Gl6AwE9TXEVloAB2MGbhuQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NET_CONNECT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_net_connect_adapter_get_dns_servers");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_dns_servers)) {
        ark_net_connect_adapter_get_dns_servers = nullptr;
      } else {
        ark_net_connect_adapter_get_dns_servers = _struct->get_dns_servers;
      }
    } else {
      ark_net_connect_adapter_get_dns_servers =
          reinterpret_cast<ArkNetConnectAdapterGetDnsServersFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_net_connect_adapter_get_dns_servers,
                                    ark_web_string_vector_default);

  // Execute
  return ark_net_connect_adapter_get_dns_servers(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebStringVector ArkNetConnectAdapterCToCpp::GetDnsServersByNetId(
    int32_t netId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_net_connect_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_vector_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_net_connect_adapter_get_dns_servers_by_net_id);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "i$xhEUuusZ7_Fo3WJyLmmg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NET_CONNECT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_net_connect_adapter_get_dns_servers_by_net_id");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_dns_servers_by_net_id)) {
        ark_net_connect_adapter_get_dns_servers_by_net_id = nullptr;
      } else {
        ark_net_connect_adapter_get_dns_servers_by_net_id =
            _struct->get_dns_servers_by_net_id;
      }
    } else {
      ark_net_connect_adapter_get_dns_servers_by_net_id =
          reinterpret_cast<ArkNetConnectAdapterGetDnsServersByNetIdFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_net_connect_adapter_get_dns_servers_by_net_id,
      ark_web_string_vector_default);

  // Execute
  return ark_net_connect_adapter_get_dns_servers_by_net_id(_struct, netId);
}

ARK_WEB_NO_SANITIZE
ArkWebStringVector ArkNetConnectAdapterCToCpp::GetDnsServersForVpn() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_net_connect_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_vector_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_net_connect_adapter_get_dns_servers_for_vpn);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "D0FtJ_fDEvLq$6LAmtO0eA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NET_CONNECT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_net_connect_adapter_get_dns_servers_for_vpn");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_dns_servers_for_vpn)) {
        ark_net_connect_adapter_get_dns_servers_for_vpn = nullptr;
      } else {
        ark_net_connect_adapter_get_dns_servers_for_vpn =
            _struct->get_dns_servers_for_vpn;
      }
    } else {
      ark_net_connect_adapter_get_dns_servers_for_vpn =
          reinterpret_cast<ArkNetConnectAdapterGetDnsServersForVpnFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_net_connect_adapter_get_dns_servers_for_vpn,
      ark_web_string_vector_default);

  // Execute
  return ark_net_connect_adapter_get_dns_servers_for_vpn(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkNetConnectAdapterCToCpp::RegisterVpnListener(
    ArkWebRefPtr<ArkVpnListener> cb) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_net_connect_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_net_connect_adapter_register_vpn_listener);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "VkDAvQCFJH3XHWGlilPcsA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NET_CONNECT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_net_connect_adapter_register_vpn_listener");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, register_vpn_listener)) {
        ark_net_connect_adapter_register_vpn_listener = nullptr;
      } else {
        ark_net_connect_adapter_register_vpn_listener =
            _struct->register_vpn_listener;
      }
    } else {
      ark_net_connect_adapter_register_vpn_listener =
          reinterpret_cast<ArkNetConnectAdapterRegisterVpnListenerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_net_connect_adapter_register_vpn_listener, ARK_WEB_RETURN_VOID);

  // Execute
  ark_net_connect_adapter_register_vpn_listener(
      _struct, ArkVpnListenerCppToC::Invert(cb));
}

ARK_WEB_NO_SANITIZE
void ArkNetConnectAdapterCToCpp::UnRegisterVpnListener() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_net_connect_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_net_connect_adapter_un_register_vpn_listener);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "QnVnlJaCJ4Eye3ygbibR2w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NET_CONNECT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_net_connect_adapter_un_register_vpn_listener");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, un_register_vpn_listener)) {
        ark_net_connect_adapter_un_register_vpn_listener = nullptr;
      } else {
        ark_net_connect_adapter_un_register_vpn_listener =
            _struct->un_register_vpn_listener;
      }
    } else {
      ark_net_connect_adapter_un_register_vpn_listener =
          reinterpret_cast<ArkNetConnectAdapterUnRegisterVpnListenerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_net_connect_adapter_un_register_vpn_listener, ARK_WEB_RETURN_VOID);

  // Execute
  ark_net_connect_adapter_un_register_vpn_listener(_struct);
}

ArkNetConnectAdapterCToCpp::ArkNetConnectAdapterCToCpp() {}

ArkNetConnectAdapterCToCpp::~ArkNetConnectAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkNetConnectAdapterCToCpp,
                           ArkNetConnectAdapter,
                           ark_net_connect_adapter_t>::kBridgeType =
        ARK_NET_CONNECT_ADAPTER;

}  // namespace OHOS::ArkWeb
