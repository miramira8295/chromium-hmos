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

#include "ohos_adapter/ctocpp/ark_web_timezone_info_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebTimezoneInfoGetTzIdFunc =
    ArkWebString (*)(struct _ark_web_timezone_info_t* self);
static ArkWebTimezoneInfoGetTzIdFunc ark_web_timezone_info_get_tz_id =
    reinterpret_cast<ArkWebTimezoneInfoGetTzIdFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
ArkWebString ArkWebTimezoneInfoCToCpp::GetTzId() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_timezone_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(ark_web_timezone_info_get_tz_id);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "VDWwchDWbaK3zqq1mJ0jHQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_WEB_TIMEZONE_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_timezone_info_get_tz_id");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_tz_id)) {
        ark_web_timezone_info_get_tz_id = nullptr;
      } else {
        ark_web_timezone_info_get_tz_id = _struct->get_tz_id;
      }
    } else {
      ark_web_timezone_info_get_tz_id =
          reinterpret_cast<ArkWebTimezoneInfoGetTzIdFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_timezone_info_get_tz_id,
                                    ark_web_string_default);

  // Execute
  return ark_web_timezone_info_get_tz_id(_struct);
}

ArkWebTimezoneInfoCToCpp::ArkWebTimezoneInfoCToCpp() {}

ArkWebTimezoneInfoCToCpp::~ArkWebTimezoneInfoCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkWebTimezoneInfoCToCpp,
                                        ArkWebTimezoneInfo,
                                        ark_web_timezone_info_t>::kBridgeType =
    ARK_WEB_TIMEZONE_INFO;

}  // namespace OHOS::ArkWeb
