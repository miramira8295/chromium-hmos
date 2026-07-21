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

#include "ohos_nweb/cpptoc/ark_web_js_ssl_select_cert_result_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK ark_web_js_ssl_select_cert_result_cancel(
    struct _ark_web_js_ssl_select_cert_result_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebJsSslSelectCertResultCppToC::Get(self)->Cancel();
}

void ARK_WEB_CALLBACK ark_web_js_ssl_select_cert_result_ignore(
    struct _ark_web_js_ssl_select_cert_result_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebJsSslSelectCertResultCppToC::Get(self)->Ignore();
}

void ARK_WEB_CALLBACK ark_web_js_ssl_select_cert_result_confirm(
    struct _ark_web_js_ssl_select_cert_result_t* self,
    const ArkWebString* private_key_file,
    const ArkWebString* cert_chain_file) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(private_key_file, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(cert_chain_file, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebJsSslSelectCertResultCppToC::Get(self)->Confirm(*private_key_file,
                                                        *cert_chain_file);
}

}  // namespace

ArkWebJsSslSelectCertResultCppToC::ArkWebJsSslSelectCertResultCppToC() {
  GetStruct()->cancel = ark_web_js_ssl_select_cert_result_cancel;
  GetStruct()->ignore = ark_web_js_ssl_select_cert_result_ignore;
  GetStruct()->confirm = ark_web_js_ssl_select_cert_result_confirm;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["uUKgoLSdBC1EfUBOD4iLbw"] =
        reinterpret_cast<void*>(ark_web_js_ssl_select_cert_result_cancel);
    funcMemberMap["qmNmthoSuiKHyd8dRXuaZg"] =
        reinterpret_cast<void*>(ark_web_js_ssl_select_cert_result_ignore);
    funcMemberMap["G1KcZDOdoY3N9SL10kHJMQ"] =
        reinterpret_cast<void*>(ark_web_js_ssl_select_cert_result_confirm);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_JS_SSL_SELECT_CERT_RESULT, funcMemberMap);
  });
}

ArkWebJsSslSelectCertResultCppToC::~ArkWebJsSslSelectCertResultCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebJsSslSelectCertResultCppToC,
                           ArkWebJsSslSelectCertResult,
                           ark_web_js_ssl_select_cert_result_t>::kBridgeType =
        ARK_WEB_JS_SSL_SELECT_CERT_RESULT;

}  // namespace OHOS::ArkWeb
