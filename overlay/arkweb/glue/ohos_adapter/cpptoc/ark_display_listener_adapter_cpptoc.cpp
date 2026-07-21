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

#include "ohos_adapter/cpptoc/ark_display_listener_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK ark_display_listener_adapter_on_create(
    struct _ark_display_listener_adapter_t* self,
    uint64_t displayId) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDisplayListenerAdapterCppToC::Get(self)->OnCreate(displayId);
}

void ARK_WEB_CALLBACK ark_display_listener_adapter_on_destroy(
    struct _ark_display_listener_adapter_t* self,
    uint64_t displayId) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDisplayListenerAdapterCppToC::Get(self)->OnDestroy(displayId);
}

void ARK_WEB_CALLBACK ark_display_listener_adapter_on_change(
    struct _ark_display_listener_adapter_t* self,
    uint64_t displayId) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDisplayListenerAdapterCppToC::Get(self)->OnChange(displayId);
}

}  // namespace

ArkDisplayListenerAdapterCppToC::ArkDisplayListenerAdapterCppToC() {
  GetStruct()->on_create = ark_display_listener_adapter_on_create;
  GetStruct()->on_destroy = ark_display_listener_adapter_on_destroy;
  GetStruct()->on_change = ark_display_listener_adapter_on_change;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["mL_D14OaIqzX4rDagEfUEQ"] =
        reinterpret_cast<void*>(ark_display_listener_adapter_on_create);
    funcMemberMap["$IenrgvsvmyGOEblu_s18A"] =
        reinterpret_cast<void*>(ark_display_listener_adapter_on_destroy);
    funcMemberMap["e2ySNwhbuE6_db9qt_03oA"] =
        reinterpret_cast<void*>(ark_display_listener_adapter_on_change);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_DISPLAY_LISTENER_ADAPTER, funcMemberMap);
  });
}

ArkDisplayListenerAdapterCppToC::~ArkDisplayListenerAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkDisplayListenerAdapterCppToC,
                           ArkDisplayListenerAdapter,
                           ark_display_listener_adapter_t>::kBridgeType =
        ARK_DISPLAY_LISTENER_ADAPTER;

}  // namespace OHOS::ArkWeb
