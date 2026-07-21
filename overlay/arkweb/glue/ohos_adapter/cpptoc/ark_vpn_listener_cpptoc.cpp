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

#include "ohos_adapter/cpptoc/ark_vpn_listener_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK
ark_vpn_listener_on_available(struct _ark_vpn_listener_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkVpnListenerCppToC::Get(self)->OnAvailable();
}

void ARK_WEB_CALLBACK
ark_vpn_listener_on_lost(struct _ark_vpn_listener_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkVpnListenerCppToC::Get(self)->OnLost();
}

}  // namespace

ArkVpnListenerCppToC::ArkVpnListenerCppToC() {
  GetStruct()->on_available = ark_vpn_listener_on_available;
  GetStruct()->on_lost = ark_vpn_listener_on_lost;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["EbKyN2PoryV1uOyoCy8Q2g"] =
        reinterpret_cast<void*>(ark_vpn_listener_on_available);
    funcMemberMap["82ToFdBXlKxZIMR29EtPNw"] =
        reinterpret_cast<void*>(ark_vpn_listener_on_lost);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_VPN_LISTENER, funcMemberMap);
  });
}

ArkVpnListenerCppToC::~ArkVpnListenerCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<ArkVpnListenerCppToC,
                                        ArkVpnListener,
                                        ark_vpn_listener_t>::kBridgeType =
    ARK_VPN_LISTENER;

}  // namespace OHOS::ArkWeb
