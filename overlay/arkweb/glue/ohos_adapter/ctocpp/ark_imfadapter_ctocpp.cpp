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

#include "ohos_adapter/ctocpp/ark_imfadapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_imfcursor_info_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_imftext_config_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_imftext_listener_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkIMFAdapterAttachFunc1 =
    bool (*)(struct _ark_imfadapter_t* self,
             ark_imftext_listener_adapter_t* listener,
             bool isShowKeyboard);
static ArkIMFAdapterAttachFunc1 ark_imfadapter_attach1 =
    reinterpret_cast<ArkIMFAdapterAttachFunc1>(ARK_WEB_INIT_ADDR);

using ArkIMFAdapterAttachFunc2 =
    bool (*)(struct _ark_imfadapter_t* self,
             ark_imftext_listener_adapter_t* listener,
             bool isShowKeyboard,
             ark_imftext_config_adapter_t* config,
             bool isResetListener);
static ArkIMFAdapterAttachFunc2 ark_imfadapter_attach2 =
    reinterpret_cast<ArkIMFAdapterAttachFunc2>(ARK_WEB_INIT_ADDR);

using ArkIMFAdapterAttachWithRequestKeyboardReasonFunc =
    bool (*)(struct _ark_imfadapter_t* self,
             ark_imftext_listener_adapter_t* listener,
             bool isShowKeyboard,
             ark_imftext_config_adapter_t* config,
             bool isResetListener,
             int32_t requestKeyboardReason);
static ArkIMFAdapterAttachWithRequestKeyboardReasonFunc
    ark_imfadapter_attach_with_request_keyboard_reason =
        reinterpret_cast<ArkIMFAdapterAttachWithRequestKeyboardReasonFunc>(
            ARK_WEB_INIT_ADDR);

using ArkIMFAdapterShowCurrentInputFunc =
    void (*)(struct _ark_imfadapter_t* self, const int32_t* inputType);
static ArkIMFAdapterShowCurrentInputFunc ark_imfadapter_show_current_input =
    reinterpret_cast<ArkIMFAdapterShowCurrentInputFunc>(ARK_WEB_INIT_ADDR);

using ArkIMFAdapterHideTextInputFunc = void (*)(struct _ark_imfadapter_t* self);
static ArkIMFAdapterHideTextInputFunc ark_imfadapter_hide_text_input =
    reinterpret_cast<ArkIMFAdapterHideTextInputFunc>(ARK_WEB_INIT_ADDR);

using ArkIMFAdapterCloseFunc = void (*)(struct _ark_imfadapter_t* self);
static ArkIMFAdapterCloseFunc ark_imfadapter_close =
    reinterpret_cast<ArkIMFAdapterCloseFunc>(ARK_WEB_INIT_ADDR);

using ArkIMFAdapterOnCursorUpdateFunc =
    void (*)(struct _ark_imfadapter_t* self,
             ark_imfcursor_info_adapter_t* cursorInfo);
static ArkIMFAdapterOnCursorUpdateFunc ark_imfadapter_on_cursor_update =
    reinterpret_cast<ArkIMFAdapterOnCursorUpdateFunc>(ARK_WEB_INIT_ADDR);

using ArkIMFAdapterOnSelectionChangeFunc =
    void (*)(struct _ark_imfadapter_t* self,
             ArkWebU16String* text,
             int start,
             int end);
static ArkIMFAdapterOnSelectionChangeFunc ark_imfadapter_on_selection_change =
    reinterpret_cast<ArkIMFAdapterOnSelectionChangeFunc>(ARK_WEB_INIT_ADDR);

using ArkIMFAdapterSendPrivateCommandFunc =
    bool (*)(struct _ark_imfadapter_t* self,
             const ArkWebString* commandKey,
             const ArkWebString* commandValue);
static ArkIMFAdapterSendPrivateCommandFunc ark_imfadapter_send_private_command =
    reinterpret_cast<ArkIMFAdapterSendPrivateCommandFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
bool ArkIMFAdapterCToCpp::Attach(
    ArkWebRefPtr<ArkIMFTextListenerAdapter> listener,
    bool isShowKeyboard) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_imfadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(ark_imfadapter_attach1);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "r4_qRiOJDQ40q1nXgAOicQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_IMFADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_imfadapter_attach1");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, attach1)) {
        ark_imfadapter_attach1 = nullptr;
      } else {
        ark_imfadapter_attach1 = _struct->attach1;
      }
    } else {
      ark_imfadapter_attach1 =
          reinterpret_cast<ArkIMFAdapterAttachFunc1>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_imfadapter_attach1, false);

  // Execute
  return ark_imfadapter_attach1(
      _struct, ArkIMFTextListenerAdapterCppToC::Invert(listener),
      isShowKeyboard);
}

ARK_WEB_NO_SANITIZE
bool ArkIMFAdapterCToCpp::Attach(
    ArkWebRefPtr<ArkIMFTextListenerAdapter> listener,
    bool isShowKeyboard,
    ArkWebRefPtr<ArkIMFTextConfigAdapter> config,
    bool isResetListener) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_imfadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(ark_imfadapter_attach2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "NmjnE$YJNi8N4XUFUQm67w";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_IMFADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_imfadapter_attach2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, attach2)) {
        ark_imfadapter_attach2 = nullptr;
      } else {
        ark_imfadapter_attach2 = _struct->attach2;
      }
    } else {
      ark_imfadapter_attach2 =
          reinterpret_cast<ArkIMFAdapterAttachFunc2>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_imfadapter_attach2, false);

  // Execute
  return ark_imfadapter_attach2(
      _struct, ArkIMFTextListenerAdapterCppToC::Invert(listener),
      isShowKeyboard, ArkIMFTextConfigAdapterCppToC::Invert(config),
      isResetListener);
}

ARK_WEB_NO_SANITIZE
bool ArkIMFAdapterCToCpp::AttachWithRequestKeyboardReason(
    ArkWebRefPtr<ArkIMFTextListenerAdapter> listener,
    bool isShowKeyboard,
    ArkWebRefPtr<ArkIMFTextConfigAdapter> config,
    bool isResetListener,
    int32_t requestKeyboardReason) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_imfadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_imfadapter_attach_with_request_keyboard_reason);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "vcqx4e1MP1rVx2EHot_WjA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_IMFADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_imfadapter_attach_with_request_keyboard_reason");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      attach_with_request_keyboard_reason)) {
        ark_imfadapter_attach_with_request_keyboard_reason = nullptr;
      } else {
        ark_imfadapter_attach_with_request_keyboard_reason =
            _struct->attach_with_request_keyboard_reason;
      }
    } else {
      ark_imfadapter_attach_with_request_keyboard_reason =
          reinterpret_cast<ArkIMFAdapterAttachWithRequestKeyboardReasonFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_imfadapter_attach_with_request_keyboard_reason, false);

  // Execute
  return ark_imfadapter_attach_with_request_keyboard_reason(
      _struct, ArkIMFTextListenerAdapterCppToC::Invert(listener),
      isShowKeyboard, ArkIMFTextConfigAdapterCppToC::Invert(config),
      isResetListener, requestKeyboardReason);
}

ARK_WEB_NO_SANITIZE
void ArkIMFAdapterCToCpp::ShowCurrentInput(const int32_t& inputType) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_imfadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_imfadapter_show_current_input);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "oVbwvxGjdsn6fY5zRBQzCA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_IMFADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_imfadapter_show_current_input");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, show_current_input)) {
        ark_imfadapter_show_current_input = nullptr;
      } else {
        ark_imfadapter_show_current_input = _struct->show_current_input;
      }
    } else {
      ark_imfadapter_show_current_input =
          reinterpret_cast<ArkIMFAdapterShowCurrentInputFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_imfadapter_show_current_input,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_imfadapter_show_current_input(_struct, &inputType);
}

ARK_WEB_NO_SANITIZE
void ArkIMFAdapterCToCpp::HideTextInput() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_imfadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_imfadapter_hide_text_input);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "10A_l1Hvugv7KTs6XdyYEA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_IMFADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_imfadapter_hide_text_input");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, hide_text_input)) {
        ark_imfadapter_hide_text_input = nullptr;
      } else {
        ark_imfadapter_hide_text_input = _struct->hide_text_input;
      }
    } else {
      ark_imfadapter_hide_text_input =
          reinterpret_cast<ArkIMFAdapterHideTextInputFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_imfadapter_hide_text_input,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_imfadapter_hide_text_input(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkIMFAdapterCToCpp::Close() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_imfadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_imfadapter_close);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "FYjcPJjrLv34kj7T2ECbTQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_IMFADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG("failed to find func member ark_imfadapter_close");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, close)) {
        ark_imfadapter_close = nullptr;
      } else {
        ark_imfadapter_close = _struct->close;
      }
    } else {
      ark_imfadapter_close =
          reinterpret_cast<ArkIMFAdapterCloseFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_imfadapter_close, ARK_WEB_RETURN_VOID);

  // Execute
  ark_imfadapter_close(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkIMFAdapterCToCpp::OnCursorUpdate(
    ArkWebRefPtr<ArkIMFCursorInfoAdapter> cursorInfo) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_imfadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_imfadapter_on_cursor_update);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Y3aefETG5oIO5u0iNaQJpg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_IMFADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_imfadapter_on_cursor_update");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_cursor_update)) {
        ark_imfadapter_on_cursor_update = nullptr;
      } else {
        ark_imfadapter_on_cursor_update = _struct->on_cursor_update;
      }
    } else {
      ark_imfadapter_on_cursor_update =
          reinterpret_cast<ArkIMFAdapterOnCursorUpdateFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_imfadapter_on_cursor_update,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_imfadapter_on_cursor_update(
      _struct, ArkIMFCursorInfoAdapterCppToC::Invert(cursorInfo));
}

ARK_WEB_NO_SANITIZE
void ArkIMFAdapterCToCpp::OnSelectionChange(ArkWebU16String& text,
                                            int start,
                                            int end) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_imfadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_imfadapter_on_selection_change);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "tXnrJuQpql07vMSiuki4fQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_IMFADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_imfadapter_on_selection_change");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_selection_change)) {
        ark_imfadapter_on_selection_change = nullptr;
      } else {
        ark_imfadapter_on_selection_change = _struct->on_selection_change;
      }
    } else {
      ark_imfadapter_on_selection_change =
          reinterpret_cast<ArkIMFAdapterOnSelectionChangeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_imfadapter_on_selection_change,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_imfadapter_on_selection_change(_struct, &text, start, end);
}

ARK_WEB_NO_SANITIZE
bool ArkIMFAdapterCToCpp::SendPrivateCommand(const ArkWebString& commandKey,
                                             const ArkWebString& commandValue) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_imfadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_imfadapter_send_private_command);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "gd98ggbnN3x3BPU9F1bQhA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_IMFADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_imfadapter_send_private_command");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, send_private_command)) {
        ark_imfadapter_send_private_command = nullptr;
      } else {
        ark_imfadapter_send_private_command = _struct->send_private_command;
      }
    } else {
      ark_imfadapter_send_private_command =
          reinterpret_cast<ArkIMFAdapterSendPrivateCommandFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_imfadapter_send_private_command, false);

  // Execute
  return ark_imfadapter_send_private_command(_struct, &commandKey,
                                             &commandValue);
}

ArkIMFAdapterCToCpp::ArkIMFAdapterCToCpp() {}

ArkIMFAdapterCToCpp::~ArkIMFAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkIMFAdapterCToCpp,
                                        ArkIMFAdapter,
                                        ark_imfadapter_t>::kBridgeType =
    ARK_IMFADAPTER;

}  // namespace OHOS::ArkWeb
