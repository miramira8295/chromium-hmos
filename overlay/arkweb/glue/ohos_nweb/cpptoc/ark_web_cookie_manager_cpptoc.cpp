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

#include "ohos_nweb/cpptoc/ark_web_cookie_manager_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"
#include "ohos_nweb/ctocpp/ark_web_bool_value_callback_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_long_value_callback_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_string_value_callback_ctocpp.h"

namespace OHOS::ArkWeb {

namespace {

bool ARK_WEB_CALLBACK
ark_web_cookie_manager_store1(struct _ark_web_cookie_manager_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebCookieManagerCppToC::Get(self)->Store();
}

void ARK_WEB_CALLBACK
ark_web_cookie_manager_store2(struct _ark_web_cookie_manager_t* self,
                              ark_web_bool_value_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebCookieManagerCppToC::Get(self)->Store(
      ArkWebBoolValueCallbackCToCpp::Invert(callback));
}

int ARK_WEB_CALLBACK
ark_web_cookie_manager_set_cookie1(struct _ark_web_cookie_manager_t* self,
                                   const ArkWebString* url,
                                   const ArkWebString* value,
                                   bool incognito_mode) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(value, 0);

  // Execute
  return ArkWebCookieManagerCppToC::Get(self)->SetCookie(*url, *value,
                                                         incognito_mode);
}

void ARK_WEB_CALLBACK
ark_web_cookie_manager_set_cookie2(struct _ark_web_cookie_manager_t* self,
                                   const ArkWebString* url,
                                   const ArkWebString* value,
                                   ark_web_bool_value_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(value, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebCookieManagerCppToC::Get(self)->SetCookie(
      *url, *value, ArkWebBoolValueCallbackCToCpp::Invert(callback));
}

bool ARK_WEB_CALLBACK
ark_web_cookie_manager_exist_cookies1(struct _ark_web_cookie_manager_t* self,
                                      bool incognito_mode) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebCookieManagerCppToC::Get(self)->ExistCookies(incognito_mode);
}

void ARK_WEB_CALLBACK
ark_web_cookie_manager_exist_cookies2(struct _ark_web_cookie_manager_t* self,
                                      ark_web_bool_value_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebCookieManagerCppToC::Get(self)->ExistCookies(
      ArkWebBoolValueCallbackCToCpp::Invert(callback));
}

ArkWebString ARK_WEB_CALLBACK
ark_web_cookie_manager_return_cookie1(struct _ark_web_cookie_manager_t* self,
                                      const ArkWebString* url,
                                      bool* is_valid,
                                      bool incognito_mode) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, ark_web_string_default);
  ARK_WEB_CPPTOC_CHECK_PARAM(is_valid, ark_web_string_default);

  // Execute
  return ArkWebCookieManagerCppToC::Get(self)->ReturnCookie(*url, *is_valid,
                                                            incognito_mode);
}

void ARK_WEB_CALLBACK ark_web_cookie_manager_return_cookie2(
    struct _ark_web_cookie_manager_t* self,
    const ArkWebString* url,
    ark_web_string_value_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebCookieManagerCppToC::Get(self)->ReturnCookie(
      *url, ArkWebStringValueCallbackCToCpp::Invert(callback));
}

void ARK_WEB_CALLBACK
ark_web_cookie_manager_config_cookie(struct _ark_web_cookie_manager_t* self,
                                     const ArkWebString* url,
                                     const ArkWebString* value,
                                     ark_web_long_value_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(value, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebCookieManagerCppToC::Get(self)->ConfigCookie(
      *url, *value, ArkWebLongValueCallbackCToCpp::Invert(callback));
}

void ARK_WEB_CALLBACK ark_web_cookie_manager_delete_session_cookies(
    struct _ark_web_cookie_manager_t* self,
    ark_web_bool_value_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebCookieManagerCppToC::Get(self)->DeleteSessionCookies(
      ArkWebBoolValueCallbackCToCpp::Invert(callback));
}

void ARK_WEB_CALLBACK ark_web_cookie_manager_delete_cookie_entirely(
    struct _ark_web_cookie_manager_t* self,
    ark_web_bool_value_callback_t* callback,
    bool incognito_mode) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebCookieManagerCppToC::Get(self)->DeleteCookieEntirely(
      ArkWebBoolValueCallbackCToCpp::Invert(callback), incognito_mode);
}

bool ARK_WEB_CALLBACK ark_web_cookie_manager_is_accept_cookie_allowed(
    struct _ark_web_cookie_manager_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebCookieManagerCppToC::Get(self)->IsAcceptCookieAllowed();
}

void ARK_WEB_CALLBACK ark_web_cookie_manager_put_accept_cookie_enabled(
    struct _ark_web_cookie_manager_t* self,
    bool accept) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebCookieManagerCppToC::Get(self)->PutAcceptCookieEnabled(accept);
}

bool ARK_WEB_CALLBACK ark_web_cookie_manager_is_third_party_cookie_allowed(
    struct _ark_web_cookie_manager_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebCookieManagerCppToC::Get(self)->IsThirdPartyCookieAllowed();
}

bool ARK_WEB_CALLBACK ark_web_cookie_manager_is_file_urlscheme_cookies_allowed(
    struct _ark_web_cookie_manager_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebCookieManagerCppToC::Get(self)->IsFileURLSchemeCookiesAllowed();
}

void ARK_WEB_CALLBACK
ark_web_cookie_manager_put_accept_third_party_cookie_enabled(
    struct _ark_web_cookie_manager_t* self,
    bool accept) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebCookieManagerCppToC::Get(self)->PutAcceptThirdPartyCookieEnabled(
      accept);
}

void ARK_WEB_CALLBACK
ark_web_cookie_manager_put_accept_file_urlscheme_cookies_enabled(
    struct _ark_web_cookie_manager_t* self,
    bool allow) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebCookieManagerCppToC::Get(self)->PutAcceptFileURLSchemeCookiesEnabled(
      allow);
}

void ARK_WEB_CALLBACK ark_web_cookie_manager_get_cookie_async(
    struct _ark_web_cookie_manager_t* self,
    const ArkWebString* url,
    bool incognitoMode,
    ark_web_string_value_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebCookieManagerCppToC::Get(self)->GetCookieAsync(
      *url, incognitoMode, ArkWebStringValueCallbackCToCpp::Invert(callback));
}

int ARK_WEB_CALLBACK
ark_web_cookie_manager_set_cookie_sync(struct _ark_web_cookie_manager_t* self,
                                       const ArkWebString* url,
                                       const ArkWebString* value,
                                       bool incognitoMode,
                                       bool includeHttpOnly) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(value, 0);

  // Execute
  return ArkWebCookieManagerCppToC::Get(self)->SetCookieSync(
      *url, *value, incognitoMode, includeHttpOnly);
}

void ARK_WEB_CALLBACK ark_web_cookie_manager_set_cookie_async(
    struct _ark_web_cookie_manager_t* self,
    const ArkWebString* url,
    const ArkWebString* value,
    bool incognitoMode,
    bool includeHttpOnly,
    ark_web_long_value_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(value, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebCookieManagerCppToC::Get(self)->SetCookieAsync(
      *url, *value, incognitoMode, includeHttpOnly,
      ArkWebLongValueCallbackCToCpp::Invert(callback));
}

}  // namespace

ArkWebCookieManagerCppToC::ArkWebCookieManagerCppToC() {
  GetStruct()->store1 = ark_web_cookie_manager_store1;
  GetStruct()->store2 = ark_web_cookie_manager_store2;
  GetStruct()->set_cookie1 = ark_web_cookie_manager_set_cookie1;
  GetStruct()->set_cookie2 = ark_web_cookie_manager_set_cookie2;
  GetStruct()->exist_cookies1 = ark_web_cookie_manager_exist_cookies1;
  GetStruct()->exist_cookies2 = ark_web_cookie_manager_exist_cookies2;
  GetStruct()->return_cookie1 = ark_web_cookie_manager_return_cookie1;
  GetStruct()->return_cookie2 = ark_web_cookie_manager_return_cookie2;
  GetStruct()->config_cookie = ark_web_cookie_manager_config_cookie;
  GetStruct()->delete_session_cookies =
      ark_web_cookie_manager_delete_session_cookies;
  GetStruct()->delete_cookie_entirely =
      ark_web_cookie_manager_delete_cookie_entirely;
  GetStruct()->is_accept_cookie_allowed =
      ark_web_cookie_manager_is_accept_cookie_allowed;
  GetStruct()->put_accept_cookie_enabled =
      ark_web_cookie_manager_put_accept_cookie_enabled;
  GetStruct()->is_third_party_cookie_allowed =
      ark_web_cookie_manager_is_third_party_cookie_allowed;
  GetStruct()->is_file_urlscheme_cookies_allowed =
      ark_web_cookie_manager_is_file_urlscheme_cookies_allowed;
  GetStruct()->put_accept_third_party_cookie_enabled =
      ark_web_cookie_manager_put_accept_third_party_cookie_enabled;
  GetStruct()->put_accept_file_urlscheme_cookies_enabled =
      ark_web_cookie_manager_put_accept_file_urlscheme_cookies_enabled;
  GetStruct()->get_cookie_async = ark_web_cookie_manager_get_cookie_async;
  GetStruct()->set_cookie_sync = ark_web_cookie_manager_set_cookie_sync;
  GetStruct()->set_cookie_async = ark_web_cookie_manager_set_cookie_async;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["oyTR3fZ_p7YGmiMEpavdOQ"] =
        reinterpret_cast<void*>(ark_web_cookie_manager_store1);
    funcMemberMap["XqXaWLduGZF_8QdV3Vl1Rw"] =
        reinterpret_cast<void*>(ark_web_cookie_manager_store2);
    funcMemberMap["uyyeZfZeuAtwx1FdKctXYQ"] =
        reinterpret_cast<void*>(ark_web_cookie_manager_set_cookie1);
    funcMemberMap["BCJ2APEOZWCEeJHFGM9ZMA"] =
        reinterpret_cast<void*>(ark_web_cookie_manager_set_cookie2);
    funcMemberMap["A94k_3ZR84_VBgtupTl0TQ"] =
        reinterpret_cast<void*>(ark_web_cookie_manager_exist_cookies1);
    funcMemberMap["xkmiOfxxn7RiD_oZ0qbNiA"] =
        reinterpret_cast<void*>(ark_web_cookie_manager_exist_cookies2);
    funcMemberMap["sntk71jSJfXeWVYxpJo9Iw"] =
        reinterpret_cast<void*>(ark_web_cookie_manager_return_cookie1);
    funcMemberMap["h1CHYUEtig0LGo_sdf95MQ"] =
        reinterpret_cast<void*>(ark_web_cookie_manager_return_cookie2);
    funcMemberMap["8LwVXum4d0vAwl9$zXnRFg"] =
        reinterpret_cast<void*>(ark_web_cookie_manager_config_cookie);
    funcMemberMap["OdnsoB2e7G0G9yg3GKGLhA"] =
        reinterpret_cast<void*>(ark_web_cookie_manager_delete_session_cookies);
    funcMemberMap["szxH$ywta8g4Br7Mtsw2UQ"] =
        reinterpret_cast<void*>(ark_web_cookie_manager_delete_cookie_entirely);
    funcMemberMap["a4PkOxkB_c476PMC$X4t5A"] = reinterpret_cast<void*>(
        ark_web_cookie_manager_is_accept_cookie_allowed);
    funcMemberMap["p148Tvvd$Sc0HACWPYHakg"] = reinterpret_cast<void*>(
        ark_web_cookie_manager_put_accept_cookie_enabled);
    funcMemberMap["QR3kB6WfuGZSv4$03TyvUg"] = reinterpret_cast<void*>(
        ark_web_cookie_manager_is_third_party_cookie_allowed);
    funcMemberMap["mpnGCOtSVozV6R63gPjLbA"] = reinterpret_cast<void*>(
        ark_web_cookie_manager_is_file_urlscheme_cookies_allowed);
    funcMemberMap["34h32a3Fki$InJkYtYkpHA"] = reinterpret_cast<void*>(
        ark_web_cookie_manager_put_accept_third_party_cookie_enabled);
    funcMemberMap["MqGhvtCfb3DyBaWi05ag_g"] = reinterpret_cast<void*>(
        ark_web_cookie_manager_put_accept_file_urlscheme_cookies_enabled);
    funcMemberMap["YTu8P92BTyJkly3rICU$gw"] =
        reinterpret_cast<void*>(ark_web_cookie_manager_get_cookie_async);
    funcMemberMap["UaDbEZ3H42T4On3Dt4rZxA"] =
        reinterpret_cast<void*>(ark_web_cookie_manager_set_cookie_sync);
    funcMemberMap["GqFL38UfWhsESRsAbW9BKw"] =
        reinterpret_cast<void*>(ark_web_cookie_manager_set_cookie_async);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_COOKIE_MANAGER, funcMemberMap);
  });
}

ArkWebCookieManagerCppToC::~ArkWebCookieManagerCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<ArkWebCookieManagerCppToC,
                                        ArkWebCookieManager,
                                        ark_web_cookie_manager_t>::kBridgeType =
    ARK_WEB_COOKIE_MANAGER;

}  // namespace OHOS::ArkWeb
