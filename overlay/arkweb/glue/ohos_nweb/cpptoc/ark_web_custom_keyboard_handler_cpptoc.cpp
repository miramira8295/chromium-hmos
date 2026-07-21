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

#include "ohos_nweb/cpptoc/ark_web_custom_keyboard_handler_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK ark_web_custom_keyboard_handler_insert_text(
    struct _ark_web_custom_keyboard_handler_t* self,
    const ArkWebString* text) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(text, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebCustomKeyboardHandlerCppToC::Get(self)->InsertText(*text);
}

void ARK_WEB_CALLBACK ark_web_custom_keyboard_handler_delete_forward(
    struct _ark_web_custom_keyboard_handler_t* self,
    int32_t length) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebCustomKeyboardHandlerCppToC::Get(self)->DeleteForward(length);
}

void ARK_WEB_CALLBACK ark_web_custom_keyboard_handler_delete_backward(
    struct _ark_web_custom_keyboard_handler_t* self,
    int32_t length) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebCustomKeyboardHandlerCppToC::Get(self)->DeleteBackward(length);
}

void ARK_WEB_CALLBACK ark_web_custom_keyboard_handler_send_function_key(
    struct _ark_web_custom_keyboard_handler_t* self,
    int32_t key) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebCustomKeyboardHandlerCppToC::Get(self)->SendFunctionKey(key);
}

void ARK_WEB_CALLBACK ark_web_custom_keyboard_handler_close(
    struct _ark_web_custom_keyboard_handler_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebCustomKeyboardHandlerCppToC::Get(self)->Close();
}

}  // namespace

ArkWebCustomKeyboardHandlerCppToC::ArkWebCustomKeyboardHandlerCppToC() {
  GetStruct()->insert_text = ark_web_custom_keyboard_handler_insert_text;
  GetStruct()->delete_forward = ark_web_custom_keyboard_handler_delete_forward;
  GetStruct()->delete_backward =
      ark_web_custom_keyboard_handler_delete_backward;
  GetStruct()->send_function_key =
      ark_web_custom_keyboard_handler_send_function_key;
  GetStruct()->close = ark_web_custom_keyboard_handler_close;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["7dYYrb3NHfDj5fFQYrSOTw"] =
        reinterpret_cast<void*>(ark_web_custom_keyboard_handler_insert_text);
    funcMemberMap["M_tMC91iubwOWahW2hDOYw"] =
        reinterpret_cast<void*>(ark_web_custom_keyboard_handler_delete_forward);
    funcMemberMap["X3l3tI09m8$HBHBYYUiqSw"] = reinterpret_cast<void*>(
        ark_web_custom_keyboard_handler_delete_backward);
    funcMemberMap["yLr_7PfjmbOm2hMFpj4PnA"] = reinterpret_cast<void*>(
        ark_web_custom_keyboard_handler_send_function_key);
    funcMemberMap["LFipLjgiiaDaAna45O13ew"] =
        reinterpret_cast<void*>(ark_web_custom_keyboard_handler_close);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_CUSTOM_KEYBOARD_HANDLER, funcMemberMap);
  });
}

ArkWebCustomKeyboardHandlerCppToC::~ArkWebCustomKeyboardHandlerCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebCustomKeyboardHandlerCppToC,
                           ArkWebCustomKeyboardHandler,
                           ark_web_custom_keyboard_handler_t>::kBridgeType =
        ARK_WEB_CUSTOM_KEYBOARD_HANDLER;

}  // namespace OHOS::ArkWeb
