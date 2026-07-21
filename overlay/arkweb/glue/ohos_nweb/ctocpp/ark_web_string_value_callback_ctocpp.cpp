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

#include "ohos_nweb/ctocpp/ark_web_string_value_callback_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebStringValueCallbackOnReceiveValueFunc =
    void (*)(struct _ark_web_string_value_callback_t* self,
             const ArkWebString* value);
static ArkWebStringValueCallbackOnReceiveValueFunc
    ark_web_string_value_callback_on_receive_value =
        reinterpret_cast<ArkWebStringValueCallbackOnReceiveValueFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkWebStringValueCallbackCToCpp::OnReceiveValue(
    const ArkWebString& value) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_string_value_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_string_value_callback_on_receive_value);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "B1bTbEsUdc7ULri89T4BJg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_STRING_VALUE_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_string_value_callback_on_receive_value");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_receive_value)) {
        ark_web_string_value_callback_on_receive_value = nullptr;
      } else {
        ark_web_string_value_callback_on_receive_value =
            _struct->on_receive_value;
      }
    } else {
      ark_web_string_value_callback_on_receive_value =
          reinterpret_cast<ArkWebStringValueCallbackOnReceiveValueFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_string_value_callback_on_receive_value, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_string_value_callback_on_receive_value(_struct, &value);
}

ArkWebStringValueCallbackCToCpp::ArkWebStringValueCallbackCToCpp() {}

ArkWebStringValueCallbackCToCpp::~ArkWebStringValueCallbackCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkWebStringValueCallbackCToCpp,
                           ArkWebStringValueCallback,
                           ark_web_string_value_callback_t>::kBridgeType =
        ARK_WEB_STRING_VALUE_CALLBACK;

}  // namespace OHOS::ArkWeb
