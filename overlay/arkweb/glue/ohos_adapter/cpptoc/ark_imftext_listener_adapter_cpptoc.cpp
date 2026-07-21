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

#include "ohos_adapter/cpptoc/ark_imftext_listener_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/ctocpp/ark_imfadapter_function_key_adapter_ctocpp.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK ark_imftext_listener_adapter_insert_text(
    struct _ark_imftext_listener_adapter_t* self,
    const ArkWebU16String* text) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(text, ARK_WEB_RETURN_VOID);

  // Execute
  ArkIMFTextListenerAdapterCppToC::Get(self)->InsertText(*text);
}

void ARK_WEB_CALLBACK ark_imftext_listener_adapter_delete_forward(
    struct _ark_imftext_listener_adapter_t* self,
    int32_t length) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkIMFTextListenerAdapterCppToC::Get(self)->DeleteForward(length);
}

void ARK_WEB_CALLBACK ark_imftext_listener_adapter_delete_backward(
    struct _ark_imftext_listener_adapter_t* self,
    int32_t length) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkIMFTextListenerAdapterCppToC::Get(self)->DeleteBackward(length);
}

void ARK_WEB_CALLBACK
ark_imftext_listener_adapter_send_key_event_from_input_method(
    struct _ark_imftext_listener_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkIMFTextListenerAdapterCppToC::Get(self)->SendKeyEventFromInputMethod();
}

void ARK_WEB_CALLBACK ark_imftext_listener_adapter_send_keyboard_status(
    struct _ark_imftext_listener_adapter_t* self,
    const int32_t* keyboardStatus) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(keyboardStatus, ARK_WEB_RETURN_VOID);

  // Execute
  ArkIMFTextListenerAdapterCppToC::Get(self)->SendKeyboardStatus(
      *keyboardStatus);
}

void ARK_WEB_CALLBACK ark_imftext_listener_adapter_send_function_key(
    struct _ark_imftext_listener_adapter_t* self,
    ark_imfadapter_function_key_adapter_t* functionKey) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkIMFTextListenerAdapterCppToC::Get(self)->SendFunctionKey(
      ArkIMFAdapterFunctionKeyAdapterCToCpp::Invert(functionKey));
}

void ARK_WEB_CALLBACK ark_imftext_listener_adapter_set_keyboard_status(
    struct _ark_imftext_listener_adapter_t* self,
    bool status) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkIMFTextListenerAdapterCppToC::Get(self)->SetKeyboardStatus(status);
}

void ARK_WEB_CALLBACK ark_imftext_listener_adapter_move_cursor(
    struct _ark_imftext_listener_adapter_t* self,
    const uint32_t direction) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkIMFTextListenerAdapterCppToC::Get(self)->MoveCursor(direction);
}

void ARK_WEB_CALLBACK ark_imftext_listener_adapter_handle_set_selection(
    struct _ark_imftext_listener_adapter_t* self,
    int32_t start,
    int32_t end) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkIMFTextListenerAdapterCppToC::Get(self)->HandleSetSelection(start, end);
}

void ARK_WEB_CALLBACK ark_imftext_listener_adapter_handle_extend_action(
    struct _ark_imftext_listener_adapter_t* self,
    int32_t action) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkIMFTextListenerAdapterCppToC::Get(self)->HandleExtendAction(action);
}

void ARK_WEB_CALLBACK ark_imftext_listener_adapter_handle_select(
    struct _ark_imftext_listener_adapter_t* self,
    int32_t keyCode,
    int32_t cursorMoveSkip) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkIMFTextListenerAdapterCppToC::Get(self)->HandleSelect(keyCode,
                                                           cursorMoveSkip);
}

int32_t ARK_WEB_CALLBACK ark_imftext_listener_adapter_get_text_index_at_cursor(
    struct _ark_imftext_listener_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkIMFTextListenerAdapterCppToC::Get(self)->GetTextIndexAtCursor();
}

ArkWebU16String ARK_WEB_CALLBACK
ark_imftext_listener_adapter_get_left_text_of_cursor(
    struct _ark_imftext_listener_adapter_t* self,
    int32_t number) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_u16string_default);

  // Execute
  return ArkIMFTextListenerAdapterCppToC::Get(self)->GetLeftTextOfCursor(
      number);
}

ArkWebU16String ARK_WEB_CALLBACK
ark_imftext_listener_adapter_get_right_text_of_cursor(
    struct _ark_imftext_listener_adapter_t* self,
    int32_t number) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_u16string_default);

  // Execute
  return ArkIMFTextListenerAdapterCppToC::Get(self)->GetRightTextOfCursor(
      number);
}

int32_t ARK_WEB_CALLBACK ark_imftext_listener_adapter_set_preview_text(
    struct _ark_imftext_listener_adapter_t* self,
    const ArkWebU16String* text,
    int32_t start,
    int32_t end) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(text, 0);

  // Execute
  return ArkIMFTextListenerAdapterCppToC::Get(self)->SetPreviewText(*text,
                                                                    start, end);
}

void ARK_WEB_CALLBACK ark_imftext_listener_adapter_finish_text_preview(
    struct _ark_imftext_listener_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkIMFTextListenerAdapterCppToC::Get(self)->FinishTextPreview();
}

void ARK_WEB_CALLBACK ark_imftext_listener_adapter_set_need_under_line(
    struct _ark_imftext_listener_adapter_t* self,
    bool isNeedUnderline) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkIMFTextListenerAdapterCppToC::Get(self)->SetNeedUnderLine(isNeedUnderline);
}

void ARK_WEB_CALLBACK ark_imftext_listener_adapter_auto_fill_with_imfevent(
    struct _ark_imftext_listener_adapter_t* self,
    bool isUsername,
    bool isOtherAccount,
    bool isNewPassword,
    const ArkWebString* content) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(content, ARK_WEB_RETURN_VOID);

  // Execute
  ArkIMFTextListenerAdapterCppToC::Get(self)->AutoFillWithIMFEvent(
      isUsername, isOtherAccount, isNewPassword, *content);
}

void ARK_WEB_CALLBACK
ark_imftext_listener_adapter_keyboard_upper_right_corner_hide(
    struct _ark_imftext_listener_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkIMFTextListenerAdapterCppToC::Get(self)->KeyboardUpperRightCornerHide();
}

void ARK_WEB_CALLBACK ark_imftext_listener_adapter_web_set_ime_show(
    struct _ark_imftext_listener_adapter_t* self,
    bool visible) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkIMFTextListenerAdapterCppToC::Get(self)->WebSetImeShow(visible);
}

}  // namespace

ArkIMFTextListenerAdapterCppToC::ArkIMFTextListenerAdapterCppToC() {
  GetStruct()->insert_text = ark_imftext_listener_adapter_insert_text;
  GetStruct()->delete_forward = ark_imftext_listener_adapter_delete_forward;
  GetStruct()->delete_backward = ark_imftext_listener_adapter_delete_backward;
  GetStruct()->send_key_event_from_input_method =
      ark_imftext_listener_adapter_send_key_event_from_input_method;
  GetStruct()->send_keyboard_status =
      ark_imftext_listener_adapter_send_keyboard_status;
  GetStruct()->send_function_key =
      ark_imftext_listener_adapter_send_function_key;
  GetStruct()->set_keyboard_status =
      ark_imftext_listener_adapter_set_keyboard_status;
  GetStruct()->move_cursor = ark_imftext_listener_adapter_move_cursor;
  GetStruct()->handle_set_selection =
      ark_imftext_listener_adapter_handle_set_selection;
  GetStruct()->handle_extend_action =
      ark_imftext_listener_adapter_handle_extend_action;
  GetStruct()->handle_select = ark_imftext_listener_adapter_handle_select;
  GetStruct()->get_text_index_at_cursor =
      ark_imftext_listener_adapter_get_text_index_at_cursor;
  GetStruct()->get_left_text_of_cursor =
      ark_imftext_listener_adapter_get_left_text_of_cursor;
  GetStruct()->get_right_text_of_cursor =
      ark_imftext_listener_adapter_get_right_text_of_cursor;
  GetStruct()->set_preview_text = ark_imftext_listener_adapter_set_preview_text;
  GetStruct()->finish_text_preview =
      ark_imftext_listener_adapter_finish_text_preview;
  GetStruct()->set_need_under_line =
      ark_imftext_listener_adapter_set_need_under_line;
  GetStruct()->auto_fill_with_imfevent =
      ark_imftext_listener_adapter_auto_fill_with_imfevent;
  GetStruct()->keyboard_upper_right_corner_hide =
      ark_imftext_listener_adapter_keyboard_upper_right_corner_hide;
  GetStruct()->web_set_ime_show = ark_imftext_listener_adapter_web_set_ime_show;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["UfQY1rSQfnC1IELsKNsaOA"] =
        reinterpret_cast<void*>(ark_imftext_listener_adapter_insert_text);
    funcMemberMap["5m_bp1EgKK1tmuKo_Wtk1A"] =
        reinterpret_cast<void*>(ark_imftext_listener_adapter_delete_forward);
    funcMemberMap["cOPsKIHPJazbaD$HrGN1jA"] =
        reinterpret_cast<void*>(ark_imftext_listener_adapter_delete_backward);
    funcMemberMap["giJdKhJqx3H60407Vb3HFg"] = reinterpret_cast<void*>(
        ark_imftext_listener_adapter_send_key_event_from_input_method);
    funcMemberMap["kdmHplvKvIwZ7WUo4jdoRw"] = reinterpret_cast<void*>(
        ark_imftext_listener_adapter_send_keyboard_status);
    funcMemberMap["BocfN5F3wkWbSYDmuU4i4g"] =
        reinterpret_cast<void*>(ark_imftext_listener_adapter_send_function_key);
    funcMemberMap["COnrpitM1GGlFWQlDLqAfw"] = reinterpret_cast<void*>(
        ark_imftext_listener_adapter_set_keyboard_status);
    funcMemberMap["WNuMdQe9VE4YiKjFXwt0hw"] =
        reinterpret_cast<void*>(ark_imftext_listener_adapter_move_cursor);
    funcMemberMap["ICd0JiVdplQJGRwGTcSKLA"] = reinterpret_cast<void*>(
        ark_imftext_listener_adapter_handle_set_selection);
    funcMemberMap["bHHghNcdWt5BJrLh$X6trA"] = reinterpret_cast<void*>(
        ark_imftext_listener_adapter_handle_extend_action);
    funcMemberMap["nwvZRRoWg9d9TGi8QuH4Sg"] =
        reinterpret_cast<void*>(ark_imftext_listener_adapter_handle_select);
    funcMemberMap["8xZuKgv2vNS6XCy87WJGww"] = reinterpret_cast<void*>(
        ark_imftext_listener_adapter_get_text_index_at_cursor);
    funcMemberMap["LJvskArXayoLw$OH0jsYIw"] = reinterpret_cast<void*>(
        ark_imftext_listener_adapter_get_left_text_of_cursor);
    funcMemberMap["OdCTpczJxhN5iWsFdViiAA"] = reinterpret_cast<void*>(
        ark_imftext_listener_adapter_get_right_text_of_cursor);
    funcMemberMap["mMf4GIUSGok_4m1bT7j3OA"] =
        reinterpret_cast<void*>(ark_imftext_listener_adapter_set_preview_text);
    funcMemberMap["13lds_P4E64qe$Pp9W0_$w"] = reinterpret_cast<void*>(
        ark_imftext_listener_adapter_finish_text_preview);
    funcMemberMap["bF0MD47FcUQbYsLNa2mlYQ"] = reinterpret_cast<void*>(
        ark_imftext_listener_adapter_set_need_under_line);
    funcMemberMap["CV$9hbkgUyQa3$SrvMOqLA"] = reinterpret_cast<void*>(
        ark_imftext_listener_adapter_auto_fill_with_imfevent);
    funcMemberMap["bml5T6F6qh075jiZhe31bw"] = reinterpret_cast<void*>(
        ark_imftext_listener_adapter_keyboard_upper_right_corner_hide);
    funcMemberMap["vbG4CDM4xalWvqEMO1MTxg"] =
        reinterpret_cast<void*>(ark_imftext_listener_adapter_web_set_ime_show);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_IMFTEXT_LISTENER_ADAPTER, funcMemberMap);
  });
}

ArkIMFTextListenerAdapterCppToC::~ArkIMFTextListenerAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkIMFTextListenerAdapterCppToC,
                           ArkIMFTextListenerAdapter,
                           ark_imftext_listener_adapter_t>::kBridgeType =
        ARK_IMFTEXT_LISTENER_ADAPTER;

}  // namespace OHOS::ArkWeb
