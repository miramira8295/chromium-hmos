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

#include "ohos_nweb/ctocpp/ark_web_drag_event_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebDragEventGetXFunc = double (*)(struct _ark_web_drag_event_t* self);
static ArkWebDragEventGetXFunc ark_web_drag_event_get_x =
    reinterpret_cast<ArkWebDragEventGetXFunc>(ARK_WEB_INIT_ADDR);

using ArkWebDragEventGetYFunc = double (*)(struct _ark_web_drag_event_t* self);
static ArkWebDragEventGetYFunc ark_web_drag_event_get_y =
    reinterpret_cast<ArkWebDragEventGetYFunc>(ARK_WEB_INIT_ADDR);

using ArkWebDragEventGetActionFunc =
    int (*)(struct _ark_web_drag_event_t* self);
static ArkWebDragEventGetActionFunc ark_web_drag_event_get_action =
    reinterpret_cast<ArkWebDragEventGetActionFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
double ArkWebDragEventCToCpp::GetX() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_drag_event_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_web_drag_event_get_x);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "5qReZnkQItSFYfrpynKA5A";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_DRAG_EVENT, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_drag_event_get_x");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_x)) {
        ark_web_drag_event_get_x = nullptr;
      } else {
        ark_web_drag_event_get_x = _struct->get_x;
      }
    } else {
      ark_web_drag_event_get_x =
          reinterpret_cast<ArkWebDragEventGetXFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_drag_event_get_x, 0);

  // Execute
  return ark_web_drag_event_get_x(_struct);
}

ARK_WEB_NO_SANITIZE
double ArkWebDragEventCToCpp::GetY() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_drag_event_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_web_drag_event_get_y);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Yx5PVD9cHK1575d_m9XnAQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_DRAG_EVENT, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_drag_event_get_y");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_y)) {
        ark_web_drag_event_get_y = nullptr;
      } else {
        ark_web_drag_event_get_y = _struct->get_y;
      }
    } else {
      ark_web_drag_event_get_y =
          reinterpret_cast<ArkWebDragEventGetYFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_drag_event_get_y, 0);

  // Execute
  return ark_web_drag_event_get_y(_struct);
}

ARK_WEB_NO_SANITIZE
int ArkWebDragEventCToCpp::GetAction() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_drag_event_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_web_drag_event_get_action);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "p$SIuHXhk2TGi9tRMUZWXA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_DRAG_EVENT, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_drag_event_get_action");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_action)) {
        ark_web_drag_event_get_action = nullptr;
      } else {
        ark_web_drag_event_get_action = _struct->get_action;
      }
    } else {
      ark_web_drag_event_get_action =
          reinterpret_cast<ArkWebDragEventGetActionFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_drag_event_get_action, 0);

  // Execute
  return ark_web_drag_event_get_action(_struct);
}

ArkWebDragEventCToCpp::ArkWebDragEventCToCpp() {}

ArkWebDragEventCToCpp::~ArkWebDragEventCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkWebDragEventCToCpp,
                                        ArkWebDragEvent,
                                        ark_web_drag_event_t>::kBridgeType =
    ARK_WEB_DRAG_EVENT;

}  // namespace OHOS::ArkWeb
