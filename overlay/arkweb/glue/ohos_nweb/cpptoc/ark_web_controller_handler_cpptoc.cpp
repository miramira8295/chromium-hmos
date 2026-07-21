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

#include "ohos_nweb/cpptoc/ark_web_controller_handler_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

int32_t ARK_WEB_CALLBACK
ark_web_controller_handler_get_id(struct _ark_web_controller_handler_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebControllerHandlerCppToC::Get(self)->GetId();
}

bool ARK_WEB_CALLBACK ark_web_controller_handler_is_frist(
    struct _ark_web_controller_handler_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebControllerHandlerCppToC::Get(self)->IsFrist();
}

int32_t ARK_WEB_CALLBACK ark_web_controller_handler_get_nweb_handler_id(
    struct _ark_web_controller_handler_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebControllerHandlerCppToC::Get(self)->GetNWebHandlerId();
}

void ARK_WEB_CALLBACK ark_web_controller_handler_set_nweb_handler_by_id(
    struct _ark_web_controller_handler_t* self,
    int32_t nweb_id) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebControllerHandlerCppToC::Get(self)->SetNWebHandlerById(nweb_id);
}

}  // namespace

ArkWebControllerHandlerCppToC::ArkWebControllerHandlerCppToC() {
  GetStruct()->get_id = ark_web_controller_handler_get_id;
  GetStruct()->is_frist = ark_web_controller_handler_is_frist;
  GetStruct()->get_nweb_handler_id =
      ark_web_controller_handler_get_nweb_handler_id;
  GetStruct()->set_nweb_handler_by_id =
      ark_web_controller_handler_set_nweb_handler_by_id;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["oJCsLHH0g8XlcpemmxsUrg"] =
        reinterpret_cast<void*>(ark_web_controller_handler_get_id);
    funcMemberMap["__jAQMbae7SHzMJvn3diKg"] =
        reinterpret_cast<void*>(ark_web_controller_handler_is_frist);
    funcMemberMap["J_twAd13i8_t5gKSMKNbWw"] =
        reinterpret_cast<void*>(ark_web_controller_handler_get_nweb_handler_id);
    funcMemberMap["_AfWwljULGddemhtUHPeiw"] = reinterpret_cast<void*>(
        ark_web_controller_handler_set_nweb_handler_by_id);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_CONTROLLER_HANDLER, funcMemberMap);
  });
}

ArkWebControllerHandlerCppToC::~ArkWebControllerHandlerCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebControllerHandlerCppToC,
                           ArkWebControllerHandler,
                           ark_web_controller_handler_t>::kBridgeType =
        ARK_WEB_CONTROLLER_HANDLER;

}  // namespace OHOS::ArkWeb
