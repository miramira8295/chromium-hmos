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

#include "ohos_nweb/cpptoc/ark_web_url_resource_request_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

ArkWebString ARK_WEB_CALLBACK
ark_web_url_resource_request_url(struct _ark_web_url_resource_request_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebUrlResourceRequestCppToC::Get(self)->Url();
}

ArkWebString ARK_WEB_CALLBACK ark_web_url_resource_request_method(
    struct _ark_web_url_resource_request_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebUrlResourceRequestCppToC::Get(self)->Method();
}

bool ARK_WEB_CALLBACK ark_web_url_resource_request_from_gesture(
    struct _ark_web_url_resource_request_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebUrlResourceRequestCppToC::Get(self)->FromGesture();
}

ArkWebStringMap ARK_WEB_CALLBACK ark_web_url_resource_request_request_headers(
    struct _ark_web_url_resource_request_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_map_default);

  // Execute
  return ArkWebUrlResourceRequestCppToC::Get(self)->RequestHeaders();
}

bool ARK_WEB_CALLBACK ark_web_url_resource_request_is_about_main_frame(
    struct _ark_web_url_resource_request_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebUrlResourceRequestCppToC::Get(self)->IsAboutMainFrame();
}

bool ARK_WEB_CALLBACK ark_web_url_resource_request_is_request_redirect(
    struct _ark_web_url_resource_request_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebUrlResourceRequestCppToC::Get(self)->IsRequestRedirect();
}

}  // namespace

ArkWebUrlResourceRequestCppToC::ArkWebUrlResourceRequestCppToC() {
  GetStruct()->url = ark_web_url_resource_request_url;
  GetStruct()->method = ark_web_url_resource_request_method;
  GetStruct()->from_gesture = ark_web_url_resource_request_from_gesture;
  GetStruct()->request_headers = ark_web_url_resource_request_request_headers;
  GetStruct()->is_about_main_frame =
      ark_web_url_resource_request_is_about_main_frame;
  GetStruct()->is_request_redirect =
      ark_web_url_resource_request_is_request_redirect;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["xgZyLlm6ogjyZ$CRpP2Zkw"] =
        reinterpret_cast<void*>(ark_web_url_resource_request_url);
    funcMemberMap["gKXhd5ECMVwvd79$3We53Q"] =
        reinterpret_cast<void*>(ark_web_url_resource_request_method);
    funcMemberMap["VHXi1hlpV8zxgkjlpjUTyw"] =
        reinterpret_cast<void*>(ark_web_url_resource_request_from_gesture);
    funcMemberMap["9f5B1wXWkbfYYiU2bnBCkw"] =
        reinterpret_cast<void*>(ark_web_url_resource_request_request_headers);
    funcMemberMap["TWkU71XKtNY1RkLxUVMgaQ"] = reinterpret_cast<void*>(
        ark_web_url_resource_request_is_about_main_frame);
    funcMemberMap["8596U9TNNsj9u3gx6wBI$w"] = reinterpret_cast<void*>(
        ark_web_url_resource_request_is_request_redirect);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_URL_RESOURCE_REQUEST, funcMemberMap);
  });
}

ArkWebUrlResourceRequestCppToC::~ArkWebUrlResourceRequestCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebUrlResourceRequestCppToC,
                           ArkWebUrlResourceRequest,
                           ark_web_url_resource_request_t>::kBridgeType =
        ARK_WEB_URL_RESOURCE_REQUEST;

}  // namespace OHOS::ArkWeb
