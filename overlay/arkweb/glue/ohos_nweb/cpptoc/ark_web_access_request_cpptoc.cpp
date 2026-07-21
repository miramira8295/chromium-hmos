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

#include "ohos_nweb/cpptoc/ark_web_access_request_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK
ark_web_access_request_agree(struct _ark_web_access_request_t* self,
                             int resource_id) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebAccessRequestCppToC::Get(self)->Agree(resource_id);
}

ArkWebString ARK_WEB_CALLBACK
ark_web_access_request_origin(struct _ark_web_access_request_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebAccessRequestCppToC::Get(self)->Origin();
}

void ARK_WEB_CALLBACK
ark_web_access_request_refuse(struct _ark_web_access_request_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebAccessRequestCppToC::Get(self)->Refuse();
}

int ARK_WEB_CALLBACK ark_web_access_request_resource_access_id(
    struct _ark_web_access_request_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessRequestCppToC::Get(self)->ResourceAccessId();
}

}  // namespace

ArkWebAccessRequestCppToC::ArkWebAccessRequestCppToC() {
  GetStruct()->agree = ark_web_access_request_agree;
  GetStruct()->origin = ark_web_access_request_origin;
  GetStruct()->refuse = ark_web_access_request_refuse;
  GetStruct()->resource_access_id = ark_web_access_request_resource_access_id;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["$iR7IusnTm33WQCYgGJfqA"] =
        reinterpret_cast<void*>(ark_web_access_request_agree);
    funcMemberMap["e7WH_jslV1f_VQ1IHs2h2A"] =
        reinterpret_cast<void*>(ark_web_access_request_origin);
    funcMemberMap["N2fijcBhdktNIumZGRk02w"] =
        reinterpret_cast<void*>(ark_web_access_request_refuse);
    funcMemberMap["lM_lRlHzcwDqsB5sDDyGIg"] =
        reinterpret_cast<void*>(ark_web_access_request_resource_access_id);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_ACCESS_REQUEST, funcMemberMap);
  });
}

ArkWebAccessRequestCppToC::~ArkWebAccessRequestCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<ArkWebAccessRequestCppToC,
                                        ArkWebAccessRequest,
                                        ark_web_access_request_t>::kBridgeType =
    ARK_WEB_ACCESS_REQUEST;

}  // namespace OHOS::ArkWeb
