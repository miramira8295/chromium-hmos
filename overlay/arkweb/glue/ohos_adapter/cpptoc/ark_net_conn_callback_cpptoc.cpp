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

#include "ohos_adapter/cpptoc/ark_net_conn_callback_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/ctocpp/ark_net_capabilities_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_net_connection_properties_adapter_ctocpp.h"

namespace OHOS::ArkWeb {

namespace {

int32_t ARK_WEB_CALLBACK
ark_net_conn_callback_net_available(struct _ark_net_conn_callback_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkNetConnCallbackCppToC::Get(self)->NetAvailable();
}

int32_t ARK_WEB_CALLBACK ark_net_conn_callback_net_capabilities_change(
    struct _ark_net_conn_callback_t* self,
    const uint32_t* netConnectType,
    const uint32_t* netConnectSubtype) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(netConnectType, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(netConnectSubtype, 0);

  // Execute
  return ArkNetConnCallbackCppToC::Get(self)->NetCapabilitiesChange(
      *netConnectType, *netConnectSubtype);
}

int32_t ARK_WEB_CALLBACK ark_net_conn_callback_net_connection_properties_change(
    struct _ark_net_conn_callback_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkNetConnCallbackCppToC::Get(self)->NetConnectionPropertiesChange();
}

int32_t ARK_WEB_CALLBACK
ark_net_conn_callback_net_unavailable(struct _ark_net_conn_callback_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkNetConnCallbackCppToC::Get(self)->NetUnavailable();
}

int32_t ARK_WEB_CALLBACK ark_net_conn_callback_on_net_capabilities_changed(
    struct _ark_net_conn_callback_t* self,
    ark_net_capabilities_adapter_t* capabilites) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkNetConnCallbackCppToC::Get(self)->OnNetCapabilitiesChanged(
      ArkNetCapabilitiesAdapterCToCpp::Invert(capabilites));
}

int32_t ARK_WEB_CALLBACK
ark_net_conn_callback_on_net_connection_properties_changed(
    struct _ark_net_conn_callback_t* self,
    ark_net_connection_properties_adapter_t* properties) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkNetConnCallbackCppToC::Get(self)->OnNetConnectionPropertiesChanged(
      ArkNetConnectionPropertiesAdapterCToCpp::Invert(properties));
}

}  // namespace

ArkNetConnCallbackCppToC::ArkNetConnCallbackCppToC() {
  GetStruct()->net_available = ark_net_conn_callback_net_available;
  GetStruct()->net_capabilities_change =
      ark_net_conn_callback_net_capabilities_change;
  GetStruct()->net_connection_properties_change =
      ark_net_conn_callback_net_connection_properties_change;
  GetStruct()->net_unavailable = ark_net_conn_callback_net_unavailable;
  GetStruct()->on_net_capabilities_changed =
      ark_net_conn_callback_on_net_capabilities_changed;
  GetStruct()->on_net_connection_properties_changed =
      ark_net_conn_callback_on_net_connection_properties_changed;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["qYKtTLY3AyHRG9GVVwO7Yg"] =
        reinterpret_cast<void*>(ark_net_conn_callback_net_available);
    funcMemberMap["jZAY1qanK3NWj9mnaRuYAQ"] =
        reinterpret_cast<void*>(ark_net_conn_callback_net_capabilities_change);
    funcMemberMap["raGxdekg8VGZ$ZMkLK$I_Q"] = reinterpret_cast<void*>(
        ark_net_conn_callback_net_connection_properties_change);
    funcMemberMap["EQJjDfp8m1BvAl7wpLyEiA"] =
        reinterpret_cast<void*>(ark_net_conn_callback_net_unavailable);
    funcMemberMap["weFkVFwjeFWKIlJ91G43DA"] = reinterpret_cast<void*>(
        ark_net_conn_callback_on_net_capabilities_changed);
    funcMemberMap["W8xm1DFt6u7HnP_o1ZbVEA"] = reinterpret_cast<void*>(
        ark_net_conn_callback_on_net_connection_properties_changed);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_NET_CONN_CALLBACK, funcMemberMap);
  });
}

ArkNetConnCallbackCppToC::~ArkNetConnCallbackCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<ArkNetConnCallbackCppToC,
                                        ArkNetConnCallback,
                                        ark_net_conn_callback_t>::kBridgeType =
    ARK_NET_CONN_CALLBACK;

}  // namespace OHOS::ArkWeb
