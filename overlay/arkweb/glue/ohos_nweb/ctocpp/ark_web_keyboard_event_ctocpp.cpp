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

#include "ohos_nweb/ctocpp/ark_web_keyboard_event_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebKeyboardEventGetKeyCodeFunc =
    int32_t (*)(struct _ark_web_keyboard_event_t* self);
static ArkWebKeyboardEventGetKeyCodeFunc ark_web_keyboard_event_get_key_code =
    reinterpret_cast<ArkWebKeyboardEventGetKeyCodeFunc>(ARK_WEB_INIT_ADDR);

using ArkWebKeyboardEventGetActionFunc =
    int32_t (*)(struct _ark_web_keyboard_event_t* self);
static ArkWebKeyboardEventGetActionFunc ark_web_keyboard_event_get_action =
    reinterpret_cast<ArkWebKeyboardEventGetActionFunc>(ARK_WEB_INIT_ADDR);

using ArkWebKeyboardEventGetUnicodeFunc =
    int32_t (*)(struct _ark_web_keyboard_event_t* self);
static ArkWebKeyboardEventGetUnicodeFunc ark_web_keyboard_event_get_unicode =
    reinterpret_cast<ArkWebKeyboardEventGetUnicodeFunc>(ARK_WEB_INIT_ADDR);

using ArkWebKeyboardEventIsEnableCapsLockFunc =
    bool (*)(struct _ark_web_keyboard_event_t* self);
static ArkWebKeyboardEventIsEnableCapsLockFunc
    ark_web_keyboard_event_is_enable_caps_lock =
        reinterpret_cast<ArkWebKeyboardEventIsEnableCapsLockFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebKeyboardEventGetPressKeyCodesFunc =
    ArkWebInt32Vector (*)(struct _ark_web_keyboard_event_t* self);
static ArkWebKeyboardEventGetPressKeyCodesFunc
    ark_web_keyboard_event_get_press_key_codes =
        reinterpret_cast<ArkWebKeyboardEventGetPressKeyCodesFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkWebKeyboardEventCToCpp::GetKeyCode() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_keyboard_event_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_keyboard_event_get_key_code);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "5M5elXmTOVrH7RATWkTkug";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_KEYBOARD_EVENT, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_keyboard_event_get_key_code");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_key_code)) {
        ark_web_keyboard_event_get_key_code = nullptr;
      } else {
        ark_web_keyboard_event_get_key_code = _struct->get_key_code;
      }
    } else {
      ark_web_keyboard_event_get_key_code =
          reinterpret_cast<ArkWebKeyboardEventGetKeyCodeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_keyboard_event_get_key_code, 0);

  // Execute
  return ark_web_keyboard_event_get_key_code(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkWebKeyboardEventCToCpp::GetAction() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_keyboard_event_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_keyboard_event_get_action);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "c7dMzoh3r388eydew0KcZA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_KEYBOARD_EVENT, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_keyboard_event_get_action");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_action)) {
        ark_web_keyboard_event_get_action = nullptr;
      } else {
        ark_web_keyboard_event_get_action = _struct->get_action;
      }
    } else {
      ark_web_keyboard_event_get_action =
          reinterpret_cast<ArkWebKeyboardEventGetActionFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_keyboard_event_get_action, 0);

  // Execute
  return ark_web_keyboard_event_get_action(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkWebKeyboardEventCToCpp::GetUnicode() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_keyboard_event_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_keyboard_event_get_unicode);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "FOxWvFHh2hoQTeccToHGhA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_KEYBOARD_EVENT, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_keyboard_event_get_unicode");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_unicode)) {
        ark_web_keyboard_event_get_unicode = nullptr;
      } else {
        ark_web_keyboard_event_get_unicode = _struct->get_unicode;
      }
    } else {
      ark_web_keyboard_event_get_unicode =
          reinterpret_cast<ArkWebKeyboardEventGetUnicodeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_keyboard_event_get_unicode, 0);

  // Execute
  return ark_web_keyboard_event_get_unicode(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkWebKeyboardEventCToCpp::IsEnableCapsLock() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_keyboard_event_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_keyboard_event_is_enable_caps_lock);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "x3CmlfqZAKPvhVQJ8zQG0w";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_KEYBOARD_EVENT, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_keyboard_event_is_enable_caps_lock");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_enable_caps_lock)) {
        ark_web_keyboard_event_is_enable_caps_lock = nullptr;
      } else {
        ark_web_keyboard_event_is_enable_caps_lock =
            _struct->is_enable_caps_lock;
      }
    } else {
      ark_web_keyboard_event_is_enable_caps_lock =
          reinterpret_cast<ArkWebKeyboardEventIsEnableCapsLockFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_keyboard_event_is_enable_caps_lock,
                                    false);

  // Execute
  return ark_web_keyboard_event_is_enable_caps_lock(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebInt32Vector ArkWebKeyboardEventCToCpp::GetPressKeyCodes() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_keyboard_event_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_int32_vector_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_keyboard_event_get_press_key_codes);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "sGxdyhMWe2BlgipBC8FDVw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_KEYBOARD_EVENT, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_keyboard_event_get_press_key_codes");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_press_key_codes)) {
        ark_web_keyboard_event_get_press_key_codes = nullptr;
      } else {
        ark_web_keyboard_event_get_press_key_codes =
            _struct->get_press_key_codes;
      }
    } else {
      ark_web_keyboard_event_get_press_key_codes =
          reinterpret_cast<ArkWebKeyboardEventGetPressKeyCodesFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_keyboard_event_get_press_key_codes,
                                    ark_web_int32_vector_default);

  // Execute
  return ark_web_keyboard_event_get_press_key_codes(_struct);
}

ArkWebKeyboardEventCToCpp::ArkWebKeyboardEventCToCpp() {}

ArkWebKeyboardEventCToCpp::~ArkWebKeyboardEventCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkWebKeyboardEventCToCpp,
                                        ArkWebKeyboardEvent,
                                        ark_web_keyboard_event_t>::kBridgeType =
    ARK_WEB_KEYBOARD_EVENT;

}  // namespace OHOS::ArkWeb
