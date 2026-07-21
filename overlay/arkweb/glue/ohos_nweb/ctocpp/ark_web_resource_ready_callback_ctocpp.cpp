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

#include "ohos_nweb/ctocpp/ark_web_resource_ready_callback_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebResourceReadyCallbackCancelFunc =
    void (*)(struct _ark_web_resource_ready_callback_t* self);
static ArkWebResourceReadyCallbackCancelFunc
    ark_web_resource_ready_callback_cancel =
        reinterpret_cast<ArkWebResourceReadyCallbackCancelFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebResourceReadyCallbackContinueFunc =
    void (*)(struct _ark_web_resource_ready_callback_t* self);
static ArkWebResourceReadyCallbackContinueFunc
    ark_web_resource_ready_callback_continue =
        reinterpret_cast<ArkWebResourceReadyCallbackContinueFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkWebResourceReadyCallbackCToCpp::Cancel() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_resource_ready_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_resource_ready_callback_cancel);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "SZBv_btJSc5gDhvamAV8ww";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_RESOURCE_READY_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_resource_ready_callback_cancel");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, cancel)) {
        ark_web_resource_ready_callback_cancel = nullptr;
      } else {
        ark_web_resource_ready_callback_cancel = _struct->cancel;
      }
    } else {
      ark_web_resource_ready_callback_cancel =
          reinterpret_cast<ArkWebResourceReadyCallbackCancelFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_resource_ready_callback_cancel,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_resource_ready_callback_cancel(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebResourceReadyCallbackCToCpp::Continue() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_resource_ready_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_resource_ready_callback_continue);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "CkylNZ$D7FY4seuPW2OWkg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_RESOURCE_READY_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_resource_ready_callback_continue");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, continue0)) {
        ark_web_resource_ready_callback_continue = nullptr;
      } else {
        ark_web_resource_ready_callback_continue = _struct->continue0;
      }
    } else {
      ark_web_resource_ready_callback_continue =
          reinterpret_cast<ArkWebResourceReadyCallbackContinueFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_resource_ready_callback_continue,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_resource_ready_callback_continue(_struct);
}

ArkWebResourceReadyCallbackCToCpp::ArkWebResourceReadyCallbackCToCpp() {}

ArkWebResourceReadyCallbackCToCpp::~ArkWebResourceReadyCallbackCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkWebResourceReadyCallbackCToCpp,
                           ArkWebResourceReadyCallback,
                           ark_web_resource_ready_callback_t>::kBridgeType =
        ARK_WEB_RESOURCE_READY_CALLBACK;

}  // namespace OHOS::ArkWeb
