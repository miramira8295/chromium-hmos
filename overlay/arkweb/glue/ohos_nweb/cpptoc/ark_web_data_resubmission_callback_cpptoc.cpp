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

#include "ohos_nweb/cpptoc/ark_web_data_resubmission_callback_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK ark_web_data_resubmission_callback_cancel(
    struct _ark_web_data_resubmission_callback_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebDataResubmissionCallbackCppToC::Get(self)->Cancel();
}

void ARK_WEB_CALLBACK ark_web_data_resubmission_callback_resend(
    struct _ark_web_data_resubmission_callback_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebDataResubmissionCallbackCppToC::Get(self)->Resend();
}

}  // namespace

ArkWebDataResubmissionCallbackCppToC::ArkWebDataResubmissionCallbackCppToC() {
  GetStruct()->cancel = ark_web_data_resubmission_callback_cancel;
  GetStruct()->resend = ark_web_data_resubmission_callback_resend;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["FMpDkPcsVYESvKbTrMl$3Q"] =
        reinterpret_cast<void*>(ark_web_data_resubmission_callback_cancel);
    funcMemberMap["a9d5VlLdZPVZJEJwrr3gCQ"] =
        reinterpret_cast<void*>(ark_web_data_resubmission_callback_resend);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_DATA_RESUBMISSION_CALLBACK, funcMemberMap);
  });
}

ArkWebDataResubmissionCallbackCppToC::~ArkWebDataResubmissionCallbackCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebDataResubmissionCallbackCppToC,
                           ArkWebDataResubmissionCallback,
                           ark_web_data_resubmission_callback_t>::kBridgeType =
        ARK_WEB_DATA_RESUBMISSION_CALLBACK;

}  // namespace OHOS::ArkWeb
