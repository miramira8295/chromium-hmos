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

#include "ohos_nweb/ctocpp/ark_web_proxy_changed_callback_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebProxyChangedCallbackOnChangedFunc =
    void (*)(struct _ark_web_proxy_changed_callback_t* self);
static ArkWebProxyChangedCallbackOnChangedFunc
    ark_web_proxy_changed_callback_on_changed =
        reinterpret_cast<ArkWebProxyChangedCallbackOnChangedFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkWebProxyChangedCallbackCToCpp::OnChanged() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_proxy_changed_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_proxy_changed_callback_on_changed);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "XXLMdVPnbKobnjIJ8VxN_g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_PROXY_CHANGED_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_proxy_changed_callback_on_changed");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_changed)) {
        ark_web_proxy_changed_callback_on_changed = nullptr;
      } else {
        ark_web_proxy_changed_callback_on_changed = _struct->on_changed;
      }
    } else {
      ark_web_proxy_changed_callback_on_changed =
          reinterpret_cast<ArkWebProxyChangedCallbackOnChangedFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_proxy_changed_callback_on_changed,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_proxy_changed_callback_on_changed(_struct);
}

ArkWebProxyChangedCallbackCToCpp::ArkWebProxyChangedCallbackCToCpp() {}

ArkWebProxyChangedCallbackCToCpp::~ArkWebProxyChangedCallbackCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkWebProxyChangedCallbackCToCpp,
                           ArkWebProxyChangedCallback,
                           ark_web_proxy_changed_callback_t>::kBridgeType =
        ARK_WEB_PROXY_CHANGED_CALLBACK;

}  // namespace OHOS::ArkWeb
