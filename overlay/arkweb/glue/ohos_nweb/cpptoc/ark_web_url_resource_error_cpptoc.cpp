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

#include "ohos_nweb/cpptoc/ark_web_url_resource_error_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

int ARK_WEB_CALLBACK ark_web_url_resource_error_error_code(
    struct _ark_web_url_resource_error_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebUrlResourceErrorCppToC::Get(self)->ErrorCode();
}

ArkWebString ARK_WEB_CALLBACK ark_web_url_resource_error_error_info(
    struct _ark_web_url_resource_error_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebUrlResourceErrorCppToC::Get(self)->ErrorInfo();
}

}  // namespace

ArkWebUrlResourceErrorCppToC::ArkWebUrlResourceErrorCppToC() {
  GetStruct()->error_code = ark_web_url_resource_error_error_code;
  GetStruct()->error_info = ark_web_url_resource_error_error_info;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["XZ1ZqR67y1TfqWZavImUOQ"] =
        reinterpret_cast<void*>(ark_web_url_resource_error_error_code);
    funcMemberMap["TUJ5sG2SwvKtoO5zxEco5A"] =
        reinterpret_cast<void*>(ark_web_url_resource_error_error_info);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_URL_RESOURCE_ERROR, funcMemberMap);
  });
}

ArkWebUrlResourceErrorCppToC::~ArkWebUrlResourceErrorCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebUrlResourceErrorCppToC,
                           ArkWebUrlResourceError,
                           ark_web_url_resource_error_t>::kBridgeType =
        ARK_WEB_URL_RESOURCE_ERROR;

}  // namespace OHOS::ArkWeb
