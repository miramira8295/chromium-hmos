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

#include "ohos_nweb/ctocpp/ark_web_accessibility_event_callback_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebAccessibilityEventCallbackOnAccessibilityEventFunc =
    void (*)(struct _ark_web_accessibility_event_callback_t* self,
             int64_t accessibility_id,
             uint32_t event_type);
static ArkWebAccessibilityEventCallbackOnAccessibilityEventFunc
    ark_web_accessibility_event_callback_on_accessibility_event =
        reinterpret_cast<
            ArkWebAccessibilityEventCallbackOnAccessibilityEventFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkWebAccessibilityEventCallbackCToCpp::OnAccessibilityEvent(
    int64_t accessibility_id,
    uint32_t event_type) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_accessibility_event_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_accessibility_event_callback_on_accessibility_event);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "TOpZM0GQ41l2ZZFIXeGNug";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ACCESSIBILITY_EVENT_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_accessibility_event_callback_on_accessibility_event");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_accessibility_event)) {
        ark_web_accessibility_event_callback_on_accessibility_event = nullptr;
      } else {
        ark_web_accessibility_event_callback_on_accessibility_event =
            _struct->on_accessibility_event;
      }
    } else {
      ark_web_accessibility_event_callback_on_accessibility_event =
          reinterpret_cast<
              ArkWebAccessibilityEventCallbackOnAccessibilityEventFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_accessibility_event_callback_on_accessibility_event,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_accessibility_event_callback_on_accessibility_event(
      _struct, accessibility_id, event_type);
}

ArkWebAccessibilityEventCallbackCToCpp::
    ArkWebAccessibilityEventCallbackCToCpp() {}

ArkWebAccessibilityEventCallbackCToCpp::
    ~ArkWebAccessibilityEventCallbackCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<
    ArkWebAccessibilityEventCallbackCToCpp,
    ArkWebAccessibilityEventCallback,
    ark_web_accessibility_event_callback_t>::kBridgeType =
    ARK_WEB_ACCESSIBILITY_EVENT_CALLBACK;

}  // namespace OHOS::ArkWeb
