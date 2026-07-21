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

#include "ohos_nweb/ctocpp/ark_web_message_value_callback_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"
#include "ohos_nweb/cpptoc/ark_web_hap_value_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkWebMessageValueCallbackOnReceiveValueFunc =
    void (*)(struct _ark_web_message_value_callback_t* self,
             const ArkWebMessage* value);
static ArkWebMessageValueCallbackOnReceiveValueFunc
    ark_web_message_value_callback_on_receive_value =
        reinterpret_cast<ArkWebMessageValueCallbackOnReceiveValueFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebMessageValueCallbackOnReceiveValueV2Func =
    void (*)(struct _ark_web_message_value_callback_t* self,
             ark_web_hap_value_t* value);
static ArkWebMessageValueCallbackOnReceiveValueV2Func
    ark_web_message_value_callback_on_receive_value_v2 =
        reinterpret_cast<ArkWebMessageValueCallbackOnReceiveValueV2Func>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkWebMessageValueCallbackCToCpp::OnReceiveValue(
    const ArkWebMessage& value) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_message_value_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_message_value_callback_on_receive_value);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "HKzDoBjnpcitlhPmUw8vng";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_MESSAGE_VALUE_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_message_value_callback_on_receive_value");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_receive_value)) {
        ark_web_message_value_callback_on_receive_value = nullptr;
      } else {
        ark_web_message_value_callback_on_receive_value =
            _struct->on_receive_value;
      }
    } else {
      ark_web_message_value_callback_on_receive_value =
          reinterpret_cast<ArkWebMessageValueCallbackOnReceiveValueFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_message_value_callback_on_receive_value, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_message_value_callback_on_receive_value(_struct, &value);
}

ARK_WEB_NO_SANITIZE
void ArkWebMessageValueCallbackCToCpp::OnReceiveValueV2(
    ArkWebRefPtr<ArkWebHapValue> value) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_message_value_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_message_value_callback_on_receive_value_v2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "EHEf76iyb6k3G94qS7R1KA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_MESSAGE_VALUE_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_message_value_callback_on_receive_value_v2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_receive_value_v2)) {
        ark_web_message_value_callback_on_receive_value_v2 = nullptr;
      } else {
        ark_web_message_value_callback_on_receive_value_v2 =
            _struct->on_receive_value_v2;
      }
    } else {
      ark_web_message_value_callback_on_receive_value_v2 =
          reinterpret_cast<ArkWebMessageValueCallbackOnReceiveValueV2Func>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_message_value_callback_on_receive_value_v2, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_message_value_callback_on_receive_value_v2(
      _struct, ArkWebHapValueCppToC::Invert(value));
}

ArkWebMessageValueCallbackCToCpp::ArkWebMessageValueCallbackCToCpp() {}

ArkWebMessageValueCallbackCToCpp::~ArkWebMessageValueCallbackCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkWebMessageValueCallbackCToCpp,
                           ArkWebMessageValueCallback,
                           ark_web_message_value_callback_t>::kBridgeType =
        ARK_WEB_MESSAGE_VALUE_CALLBACK;

}  // namespace OHOS::ArkWeb
