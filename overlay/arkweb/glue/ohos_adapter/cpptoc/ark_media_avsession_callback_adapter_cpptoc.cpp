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

#include "ohos_adapter/cpptoc/ark_media_avsession_callback_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK ark_media_avsession_callback_adapter_play(
    struct _ark_media_avsession_callback_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkMediaAVSessionCallbackAdapterCppToC::Get(self)->Play();
}

void ARK_WEB_CALLBACK ark_media_avsession_callback_adapter_pause(
    struct _ark_media_avsession_callback_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkMediaAVSessionCallbackAdapterCppToC::Get(self)->Pause();
}

void ARK_WEB_CALLBACK ark_media_avsession_callback_adapter_stop(
    struct _ark_media_avsession_callback_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkMediaAVSessionCallbackAdapterCppToC::Get(self)->Stop();
}

void ARK_WEB_CALLBACK ark_media_avsession_callback_adapter_seek_to(
    struct _ark_media_avsession_callback_adapter_t* self,
    int64_t millisTime) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkMediaAVSessionCallbackAdapterCppToC::Get(self)->SeekTo(millisTime);
}

}  // namespace

ArkMediaAVSessionCallbackAdapterCppToC::
    ArkMediaAVSessionCallbackAdapterCppToC() {
  GetStruct()->play = ark_media_avsession_callback_adapter_play;
  GetStruct()->pause = ark_media_avsession_callback_adapter_pause;
  GetStruct()->stop = ark_media_avsession_callback_adapter_stop;
  GetStruct()->seek_to = ark_media_avsession_callback_adapter_seek_to;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["bP3T3dsk4T$Z9qBp1oLywA"] =
        reinterpret_cast<void*>(ark_media_avsession_callback_adapter_play);
    funcMemberMap["uJG$f3L$XENIwYLQoZI7UA"] =
        reinterpret_cast<void*>(ark_media_avsession_callback_adapter_pause);
    funcMemberMap["CGCQRzlzTsLk8BkSR6_SZQ"] =
        reinterpret_cast<void*>(ark_media_avsession_callback_adapter_stop);
    funcMemberMap["jyfULqih2QdZk7qNMpoU3w"] =
        reinterpret_cast<void*>(ark_media_avsession_callback_adapter_seek_to);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_MEDIA_AVSESSION_CALLBACK_ADAPTER, funcMemberMap);
  });
}

ArkMediaAVSessionCallbackAdapterCppToC::
    ~ArkMediaAVSessionCallbackAdapterCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<
    ArkMediaAVSessionCallbackAdapterCppToC,
    ArkMediaAVSessionCallbackAdapter,
    ark_media_avsession_callback_adapter_t>::kBridgeType =
    ARK_MEDIA_AVSESSION_CALLBACK_ADAPTER;

}  // namespace OHOS::ArkWeb
