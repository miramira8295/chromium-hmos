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

#include "ohos_nweb/ctocpp/ark_web_screen_lock_callback_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebScreenLockCallbackHandleFunc =
    void (*)(struct _ark_web_screen_lock_callback_t* self, bool key);
static ArkWebScreenLockCallbackHandleFunc ark_web_screen_lock_callback_handle =
    reinterpret_cast<ArkWebScreenLockCallbackHandleFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkWebScreenLockCallbackCToCpp::Handle(bool key) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_screen_lock_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_screen_lock_callback_handle);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "DbIQYLxDaL8Z6$l3h4zQ0w";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_SCREEN_LOCK_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_screen_lock_callback_handle");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, handle)) {
        ark_web_screen_lock_callback_handle = nullptr;
      } else {
        ark_web_screen_lock_callback_handle = _struct->handle;
      }
    } else {
      ark_web_screen_lock_callback_handle =
          reinterpret_cast<ArkWebScreenLockCallbackHandleFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_screen_lock_callback_handle,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_screen_lock_callback_handle(_struct, key);
}

ArkWebScreenLockCallbackCToCpp::ArkWebScreenLockCallbackCToCpp() {}

ArkWebScreenLockCallbackCToCpp::~ArkWebScreenLockCallbackCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkWebScreenLockCallbackCToCpp,
                           ArkWebScreenLockCallback,
                           ark_web_screen_lock_callback_t>::kBridgeType =
        ARK_WEB_SCREEN_LOCK_CALLBACK;

}  // namespace OHOS::ArkWeb
