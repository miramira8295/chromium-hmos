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

#include "ohos_nweb/cpptoc/ark_web_mouse_event_result_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK ark_web_mouse_event_result_set_mouse_event_result(
    struct _ark_web_mouse_event_result_t* self,
    bool result,
    bool stopPropagation) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebMouseEventResultCppToC::Get(self)->SetMouseEventResult(result,
                                                               stopPropagation);
}

}  // namespace

ArkWebMouseEventResultCppToC::ArkWebMouseEventResultCppToC() {
  GetStruct()->set_mouse_event_result =
      ark_web_mouse_event_result_set_mouse_event_result;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["9xIXWPBwb3ZB09xG9hUBrw"] = reinterpret_cast<void*>(
        ark_web_mouse_event_result_set_mouse_event_result);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_MOUSE_EVENT_RESULT, funcMemberMap);
  });
}

ArkWebMouseEventResultCppToC::~ArkWebMouseEventResultCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebMouseEventResultCppToC,
                           ArkWebMouseEventResult,
                           ark_web_mouse_event_result_t>::kBridgeType =
        ARK_WEB_MOUSE_EVENT_RESULT;

}  // namespace OHOS::ArkWeb
