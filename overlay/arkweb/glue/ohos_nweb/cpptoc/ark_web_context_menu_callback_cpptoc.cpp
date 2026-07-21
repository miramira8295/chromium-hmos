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

#include "ohos_nweb/cpptoc/ark_web_context_menu_callback_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK ark_web_context_menu_callback_cancel(
    struct _ark_web_context_menu_callback_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebContextMenuCallbackCppToC::Get(self)->Cancel();
}

void ARK_WEB_CALLBACK ark_web_context_menu_callback_continue(
    struct _ark_web_context_menu_callback_t* self,
    int32_t command_id,
    int flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebContextMenuCallbackCppToC::Get(self)->Continue(command_id, flag);
}

}  // namespace

ArkWebContextMenuCallbackCppToC::ArkWebContextMenuCallbackCppToC() {
  GetStruct()->cancel = ark_web_context_menu_callback_cancel;
  GetStruct()->continue0 = ark_web_context_menu_callback_continue;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["LWvzoSiQehTnoaTz7g8LIg"] =
        reinterpret_cast<void*>(ark_web_context_menu_callback_cancel);
    funcMemberMap["wDMdKPaKAENbxsg7Tgjk$A"] =
        reinterpret_cast<void*>(ark_web_context_menu_callback_continue);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_CONTEXT_MENU_CALLBACK, funcMemberMap);
  });
}

ArkWebContextMenuCallbackCppToC::~ArkWebContextMenuCallbackCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebContextMenuCallbackCppToC,
                           ArkWebContextMenuCallback,
                           ark_web_context_menu_callback_t>::kBridgeType =
        ARK_WEB_CONTEXT_MENU_CALLBACK;

}  // namespace OHOS::ArkWeb
