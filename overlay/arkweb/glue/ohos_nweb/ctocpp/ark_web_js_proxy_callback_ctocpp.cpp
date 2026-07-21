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

#include "ohos_nweb/ctocpp/ark_web_js_proxy_callback_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebJsProxyCallbackGetMethodNameFunc =
    ArkWebString (*)(struct _ark_web_js_proxy_callback_t* self);
static ArkWebJsProxyCallbackGetMethodNameFunc
    ark_web_js_proxy_callback_get_method_name =
        reinterpret_cast<ArkWebJsProxyCallbackGetMethodNameFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebJsProxyCallbackGetMethodCallbackFunc =
    NativeArkWebOnJavaScriptProxyCallback (*)(
        struct _ark_web_js_proxy_callback_t* self);
static ArkWebJsProxyCallbackGetMethodCallbackFunc
    ark_web_js_proxy_callback_get_method_callback =
        reinterpret_cast<ArkWebJsProxyCallbackGetMethodCallbackFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
ArkWebString ArkWebJsProxyCallbackCToCpp::GetMethodName() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_js_proxy_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_js_proxy_callback_get_method_name);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "4wfACgMzw_7AvIdcGOII$A";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_JS_PROXY_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_js_proxy_callback_get_method_name");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_method_name)) {
        ark_web_js_proxy_callback_get_method_name = nullptr;
      } else {
        ark_web_js_proxy_callback_get_method_name = _struct->get_method_name;
      }
    } else {
      ark_web_js_proxy_callback_get_method_name =
          reinterpret_cast<ArkWebJsProxyCallbackGetMethodNameFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_js_proxy_callback_get_method_name,
                                    ark_web_string_default);

  // Execute
  return ark_web_js_proxy_callback_get_method_name(_struct);
}

ARK_WEB_NO_SANITIZE
NativeArkWebOnJavaScriptProxyCallback
ArkWebJsProxyCallbackCToCpp::GetMethodCallback() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_js_proxy_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, NULL);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_js_proxy_callback_get_method_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ooHULQpwBQ0jKh18_rEWvw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_JS_PROXY_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_js_proxy_callback_get_method_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_method_callback)) {
        ark_web_js_proxy_callback_get_method_callback = nullptr;
      } else {
        ark_web_js_proxy_callback_get_method_callback =
            _struct->get_method_callback;
      }
    } else {
      ark_web_js_proxy_callback_get_method_callback =
          reinterpret_cast<ArkWebJsProxyCallbackGetMethodCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_js_proxy_callback_get_method_callback, NULL);

  // Execute
  return ark_web_js_proxy_callback_get_method_callback(_struct);
}

ArkWebJsProxyCallbackCToCpp::ArkWebJsProxyCallbackCToCpp() {}

ArkWebJsProxyCallbackCToCpp::~ArkWebJsProxyCallbackCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkWebJsProxyCallbackCToCpp,
                           ArkWebJsProxyCallback,
                           ark_web_js_proxy_callback_t>::kBridgeType =
        ARK_WEB_JS_PROXY_CALLBACK;

}  // namespace OHOS::ArkWeb
