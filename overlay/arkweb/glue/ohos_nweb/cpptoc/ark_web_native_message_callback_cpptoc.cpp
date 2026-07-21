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

#include "ohos_nweb/cpptoc/ark_web_native_message_callback_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK ark_web_native_message_callback_on_connect(
    struct _ark_web_native_message_callback_t* self,
    int nativeInfo) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMessageCallbackCppToC::Get(self)->OnConnect(nativeInfo);
}

void ARK_WEB_CALLBACK ark_web_native_message_callback_on_disconnect(
    struct _ark_web_native_message_callback_t* self,
    int nativeInfo) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMessageCallbackCppToC::Get(self)->OnDisconnect(nativeInfo);
}

void ARK_WEB_CALLBACK ark_web_native_message_callback_on_failed(
    struct _ark_web_native_message_callback_t* self,
    int code) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMessageCallbackCppToC::Get(self)->OnFailed(code);
}

}  // namespace

ArkWebNativeMessageCallbackCppToC::ArkWebNativeMessageCallbackCppToC() {
  GetStruct()->on_connect = ark_web_native_message_callback_on_connect;
  GetStruct()->on_disconnect = ark_web_native_message_callback_on_disconnect;
  GetStruct()->on_failed = ark_web_native_message_callback_on_failed;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["ThZEBYNSiIErr3iI1gT_ZA"] =
        reinterpret_cast<void*>(ark_web_native_message_callback_on_connect);
    funcMemberMap["DyYqCFoOiziwaTFz9Hm8LA"] =
        reinterpret_cast<void*>(ark_web_native_message_callback_on_disconnect);
    funcMemberMap["ApSmXguTl7hOZP_E9$etiA"] =
        reinterpret_cast<void*>(ark_web_native_message_callback_on_failed);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_NATIVE_MESSAGE_CALLBACK, funcMemberMap);
  });
}

ArkWebNativeMessageCallbackCppToC::~ArkWebNativeMessageCallbackCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebNativeMessageCallbackCppToC,
                           ArkWebNativeMessageCallback,
                           ark_web_native_message_callback_t>::kBridgeType =
        ARK_WEB_NATIVE_MESSAGE_CALLBACK;

}  // namespace OHOS::ArkWeb
