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

#include "ohos_nweb/ctocpp/ark_web_js_proxy_method_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebJsProxyMethodGetSizeFunc =
    int32_t (*)(struct _ark_web_js_proxy_method_t* self);
static ArkWebJsProxyMethodGetSizeFunc ark_web_js_proxy_method_get_size =
    reinterpret_cast<ArkWebJsProxyMethodGetSizeFunc>(ARK_WEB_INIT_ADDR);

using ArkWebJsProxyMethodOnHandleFunc =
    void (*)(struct _ark_web_js_proxy_method_t* self,
             int32_t number,
             const ArkWebStringVector* param);
static ArkWebJsProxyMethodOnHandleFunc ark_web_js_proxy_method_on_handle =
    reinterpret_cast<ArkWebJsProxyMethodOnHandleFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkWebJsProxyMethodCToCpp::GetSize() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_js_proxy_method_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_js_proxy_method_get_size);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "EOkZ6nWAuIBguQ$7880bkg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_JS_PROXY_METHOD, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_js_proxy_method_get_size");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_size)) {
        ark_web_js_proxy_method_get_size = nullptr;
      } else {
        ark_web_js_proxy_method_get_size = _struct->get_size;
      }
    } else {
      ark_web_js_proxy_method_get_size =
          reinterpret_cast<ArkWebJsProxyMethodGetSizeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_js_proxy_method_get_size, 0);

  // Execute
  return ark_web_js_proxy_method_get_size(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebJsProxyMethodCToCpp::OnHandle(int32_t number,
                                         const ArkWebStringVector& param) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_js_proxy_method_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_js_proxy_method_on_handle);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "xV5YxUFjYkpVIervfAOl2A";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_JS_PROXY_METHOD, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_js_proxy_method_on_handle");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_handle)) {
        ark_web_js_proxy_method_on_handle = nullptr;
      } else {
        ark_web_js_proxy_method_on_handle = _struct->on_handle;
      }
    } else {
      ark_web_js_proxy_method_on_handle =
          reinterpret_cast<ArkWebJsProxyMethodOnHandleFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_js_proxy_method_on_handle,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_js_proxy_method_on_handle(_struct, number, &param);
}

ArkWebJsProxyMethodCToCpp::ArkWebJsProxyMethodCToCpp() {}

ArkWebJsProxyMethodCToCpp::~ArkWebJsProxyMethodCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkWebJsProxyMethodCToCpp,
                           ArkWebJsProxyMethod,
                           ark_web_js_proxy_method_t>::kBridgeType =
        ARK_WEB_JS_PROXY_METHOD;

}  // namespace OHOS::ArkWeb
