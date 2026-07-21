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

#include "ohos_nweb/ctocpp/ark_web_mouse_event_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebMouseEventGetXFunc =
    int32_t (*)(struct _ark_web_mouse_event_t* self);
static ArkWebMouseEventGetXFunc ark_web_mouse_event_get_x =
    reinterpret_cast<ArkWebMouseEventGetXFunc>(ARK_WEB_INIT_ADDR);

using ArkWebMouseEventGetYFunc =
    int32_t (*)(struct _ark_web_mouse_event_t* self);
static ArkWebMouseEventGetYFunc ark_web_mouse_event_get_y =
    reinterpret_cast<ArkWebMouseEventGetYFunc>(ARK_WEB_INIT_ADDR);

using ArkWebMouseEventGetButtonFunc =
    int32_t (*)(struct _ark_web_mouse_event_t* self);
static ArkWebMouseEventGetButtonFunc ark_web_mouse_event_get_button =
    reinterpret_cast<ArkWebMouseEventGetButtonFunc>(ARK_WEB_INIT_ADDR);

using ArkWebMouseEventGetActionFunc =
    int32_t (*)(struct _ark_web_mouse_event_t* self);
static ArkWebMouseEventGetActionFunc ark_web_mouse_event_get_action =
    reinterpret_cast<ArkWebMouseEventGetActionFunc>(ARK_WEB_INIT_ADDR);

using ArkWebMouseEventGetClickNumFunc =
    int32_t (*)(struct _ark_web_mouse_event_t* self);
static ArkWebMouseEventGetClickNumFunc ark_web_mouse_event_get_click_num =
    reinterpret_cast<ArkWebMouseEventGetClickNumFunc>(ARK_WEB_INIT_ADDR);

using ArkWebMouseEventGetPressKeyCodesFunc =
    ArkWebInt32Vector (*)(struct _ark_web_mouse_event_t* self);
static ArkWebMouseEventGetPressKeyCodesFunc
    ark_web_mouse_event_get_press_key_codes =
        reinterpret_cast<ArkWebMouseEventGetPressKeyCodesFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebMouseEventGetRawXFunc =
    int32_t (*)(struct _ark_web_mouse_event_t* self);
static ArkWebMouseEventGetRawXFunc ark_web_mouse_event_get_raw_x =
    reinterpret_cast<ArkWebMouseEventGetRawXFunc>(ARK_WEB_INIT_ADDR);

using ArkWebMouseEventGetRawYFunc =
    int32_t (*)(struct _ark_web_mouse_event_t* self);
static ArkWebMouseEventGetRawYFunc ark_web_mouse_event_get_raw_y =
    reinterpret_cast<ArkWebMouseEventGetRawYFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkWebMouseEventCToCpp::GetX() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_mouse_event_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_web_mouse_event_get_x);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "5cENwt3PRpt8kBmsKByTLA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_MOUSE_EVENT, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_mouse_event_get_x");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_x)) {
        ark_web_mouse_event_get_x = nullptr;
      } else {
        ark_web_mouse_event_get_x = _struct->get_x;
      }
    } else {
      ark_web_mouse_event_get_x =
          reinterpret_cast<ArkWebMouseEventGetXFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_mouse_event_get_x, 0);

  // Execute
  return ark_web_mouse_event_get_x(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkWebMouseEventCToCpp::GetY() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_mouse_event_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_web_mouse_event_get_y);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "UNEQbZLW9FyJFjMBPTsiRg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_MOUSE_EVENT, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_mouse_event_get_y");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_y)) {
        ark_web_mouse_event_get_y = nullptr;
      } else {
        ark_web_mouse_event_get_y = _struct->get_y;
      }
    } else {
      ark_web_mouse_event_get_y =
          reinterpret_cast<ArkWebMouseEventGetYFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_mouse_event_get_y, 0);

  // Execute
  return ark_web_mouse_event_get_y(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkWebMouseEventCToCpp::GetButton() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_mouse_event_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_web_mouse_event_get_button);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "OV9NQJiUaCqXF0wb6DdXRg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_MOUSE_EVENT, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_mouse_event_get_button");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_button)) {
        ark_web_mouse_event_get_button = nullptr;
      } else {
        ark_web_mouse_event_get_button = _struct->get_button;
      }
    } else {
      ark_web_mouse_event_get_button =
          reinterpret_cast<ArkWebMouseEventGetButtonFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_mouse_event_get_button, 0);

  // Execute
  return ark_web_mouse_event_get_button(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkWebMouseEventCToCpp::GetAction() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_mouse_event_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_web_mouse_event_get_action);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "zK_AJAEJjDsy1p47eUcCDw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_MOUSE_EVENT, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_mouse_event_get_action");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_action)) {
        ark_web_mouse_event_get_action = nullptr;
      } else {
        ark_web_mouse_event_get_action = _struct->get_action;
      }
    } else {
      ark_web_mouse_event_get_action =
          reinterpret_cast<ArkWebMouseEventGetActionFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_mouse_event_get_action, 0);

  // Execute
  return ark_web_mouse_event_get_action(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkWebMouseEventCToCpp::GetClickNum() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_mouse_event_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_mouse_event_get_click_num);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "28PzUmrMd_oQx8HMunqBgw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_MOUSE_EVENT, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_mouse_event_get_click_num");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_click_num)) {
        ark_web_mouse_event_get_click_num = nullptr;
      } else {
        ark_web_mouse_event_get_click_num = _struct->get_click_num;
      }
    } else {
      ark_web_mouse_event_get_click_num =
          reinterpret_cast<ArkWebMouseEventGetClickNumFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_mouse_event_get_click_num, 0);

  // Execute
  return ark_web_mouse_event_get_click_num(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebInt32Vector ArkWebMouseEventCToCpp::GetPressKeyCodes() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_mouse_event_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_int32_vector_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_mouse_event_get_press_key_codes);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "3xPgOeifPKTux$Il0yVuxg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_MOUSE_EVENT, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_mouse_event_get_press_key_codes");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_press_key_codes)) {
        ark_web_mouse_event_get_press_key_codes = nullptr;
      } else {
        ark_web_mouse_event_get_press_key_codes = _struct->get_press_key_codes;
      }
    } else {
      ark_web_mouse_event_get_press_key_codes =
          reinterpret_cast<ArkWebMouseEventGetPressKeyCodesFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_mouse_event_get_press_key_codes,
                                    ark_web_int32_vector_default);

  // Execute
  return ark_web_mouse_event_get_press_key_codes(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkWebMouseEventCToCpp::GetRawX() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_mouse_event_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_web_mouse_event_get_raw_x);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "wu8wMNinR0YO_r_po14H8w";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_MOUSE_EVENT, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_mouse_event_get_raw_x");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_raw_x)) {
        ark_web_mouse_event_get_raw_x = nullptr;
      } else {
        ark_web_mouse_event_get_raw_x = _struct->get_raw_x;
      }
    } else {
      ark_web_mouse_event_get_raw_x =
          reinterpret_cast<ArkWebMouseEventGetRawXFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_mouse_event_get_raw_x, 0);

  // Execute
  return ark_web_mouse_event_get_raw_x(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkWebMouseEventCToCpp::GetRawY() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_mouse_event_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_web_mouse_event_get_raw_y);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jhGaRj4LDJzZIhB5f6pOLA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_MOUSE_EVENT, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_mouse_event_get_raw_y");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_raw_y)) {
        ark_web_mouse_event_get_raw_y = nullptr;
      } else {
        ark_web_mouse_event_get_raw_y = _struct->get_raw_y;
      }
    } else {
      ark_web_mouse_event_get_raw_y =
          reinterpret_cast<ArkWebMouseEventGetRawYFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_mouse_event_get_raw_y, 0);

  // Execute
  return ark_web_mouse_event_get_raw_y(_struct);
}

ArkWebMouseEventCToCpp::ArkWebMouseEventCToCpp() {}

ArkWebMouseEventCToCpp::~ArkWebMouseEventCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkWebMouseEventCToCpp,
                                        ArkWebMouseEvent,
                                        ark_web_mouse_event_t>::kBridgeType =
    ARK_WEB_MOUSE_EVENT;

}  // namespace OHOS::ArkWeb
