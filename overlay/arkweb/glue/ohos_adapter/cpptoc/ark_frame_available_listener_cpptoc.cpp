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

#include "ohos_adapter/cpptoc/ark_frame_available_listener_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void* ARK_WEB_CALLBACK ark_frame_available_listener_get_context(
    struct _ark_frame_available_listener_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  return ArkFrameAvailableListenerCppToC::Get(self)->GetContext();
}

void* ARK_WEB_CALLBACK ark_frame_available_listener_get_on_frame_available_cb(
    struct _ark_frame_available_listener_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  return ArkFrameAvailableListenerCppToC::Get(self)->GetOnFrameAvailableCb();
}

}  // namespace

ArkFrameAvailableListenerCppToC::ArkFrameAvailableListenerCppToC() {
  GetStruct()->get_context = ark_frame_available_listener_get_context;
  GetStruct()->get_on_frame_available_cb =
      ark_frame_available_listener_get_on_frame_available_cb;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["WB8DbE$RVanJcf1A9nS8Gw"] =
        reinterpret_cast<void*>(ark_frame_available_listener_get_context);
    funcMemberMap["SGE8uoJHTiDsGsG4KKZm$Q"] = reinterpret_cast<void*>(
        ark_frame_available_listener_get_on_frame_available_cb);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_FRAME_AVAILABLE_LISTENER, funcMemberMap);
  });
}

ArkFrameAvailableListenerCppToC::~ArkFrameAvailableListenerCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkFrameAvailableListenerCppToC,
                           ArkFrameAvailableListener,
                           ark_frame_available_listener_t>::kBridgeType =
        ARK_FRAME_AVAILABLE_LISTENER;

}  // namespace OHOS::ArkWeb
