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

#include "ohos_adapter/cpptoc/ark_audio_buffer_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

uint8_t* ARK_WEB_CALLBACK
ark_audio_buffer_adapter_get_buffer(struct _ark_audio_buffer_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  return ArkAudioBufferAdapterCppToC::Get(self)->GetBuffer();
}

int32_t ARK_WEB_CALLBACK
ark_audio_buffer_adapter_get_length(struct _ark_audio_buffer_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioBufferAdapterCppToC::Get(self)->GetLength();
}

int64_t ARK_WEB_CALLBACK ark_audio_buffer_adapter_get_timestamp(
    struct _ark_audio_buffer_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioBufferAdapterCppToC::Get(self)->GetTimestamp();
}

int32_t ARK_WEB_CALLBACK ark_audio_buffer_adapter_get_sourcetype(
    struct _ark_audio_buffer_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioBufferAdapterCppToC::Get(self)->GetSourcetype();
}

void ARK_WEB_CALLBACK
ark_audio_buffer_adapter_set_buffer(struct _ark_audio_buffer_adapter_t* self,
                                    uint8_t* buffer) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioBufferAdapterCppToC::Get(self)->SetBuffer(buffer);
}

void ARK_WEB_CALLBACK
ark_audio_buffer_adapter_set_length(struct _ark_audio_buffer_adapter_t* self,
                                    int32_t length) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioBufferAdapterCppToC::Get(self)->SetLength(length);
}

void ARK_WEB_CALLBACK
ark_audio_buffer_adapter_set_timestamp(struct _ark_audio_buffer_adapter_t* self,
                                       int64_t timestamp) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioBufferAdapterCppToC::Get(self)->SetTimestamp(timestamp);
}

void ARK_WEB_CALLBACK ark_audio_buffer_adapter_set_sourcetype(
    struct _ark_audio_buffer_adapter_t* self,
    int32_t sourcetype) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioBufferAdapterCppToC::Get(self)->SetSourcetype(sourcetype);
}

}  // namespace

ArkAudioBufferAdapterCppToC::ArkAudioBufferAdapterCppToC() {
  GetStruct()->get_buffer = ark_audio_buffer_adapter_get_buffer;
  GetStruct()->get_length = ark_audio_buffer_adapter_get_length;
  GetStruct()->get_timestamp = ark_audio_buffer_adapter_get_timestamp;
  GetStruct()->get_sourcetype = ark_audio_buffer_adapter_get_sourcetype;
  GetStruct()->set_buffer = ark_audio_buffer_adapter_set_buffer;
  GetStruct()->set_length = ark_audio_buffer_adapter_set_length;
  GetStruct()->set_timestamp = ark_audio_buffer_adapter_set_timestamp;
  GetStruct()->set_sourcetype = ark_audio_buffer_adapter_set_sourcetype;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["dWlswkXOGPjA2oVlmgOoUA"] =
        reinterpret_cast<void*>(ark_audio_buffer_adapter_get_buffer);
    funcMemberMap["aTUhVEVPfESm7a8tRnayqw"] =
        reinterpret_cast<void*>(ark_audio_buffer_adapter_get_length);
    funcMemberMap["ZRdWnrqOZxccM0f5tqHbYQ"] =
        reinterpret_cast<void*>(ark_audio_buffer_adapter_get_timestamp);
    funcMemberMap["YejHPHkULFM4J9g0pJm4aA"] =
        reinterpret_cast<void*>(ark_audio_buffer_adapter_get_sourcetype);
    funcMemberMap["jrsMJS8QrjLY4rpUGWTyag"] =
        reinterpret_cast<void*>(ark_audio_buffer_adapter_set_buffer);
    funcMemberMap["_cn1HlBYcFuafZSRWRNgLw"] =
        reinterpret_cast<void*>(ark_audio_buffer_adapter_set_length);
    funcMemberMap["AsDBvcUhDdZBstfGPcZzyg"] =
        reinterpret_cast<void*>(ark_audio_buffer_adapter_set_timestamp);
    funcMemberMap["uM4N0_iWN9pZQsFQX9nK7g"] =
        reinterpret_cast<void*>(ark_audio_buffer_adapter_set_sourcetype);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_AUDIO_BUFFER_ADAPTER, funcMemberMap);
  });
}

ArkAudioBufferAdapterCppToC::~ArkAudioBufferAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkAudioBufferAdapterCppToC,
                           ArkAudioBufferAdapter,
                           ark_audio_buffer_adapter_t>::kBridgeType =
        ARK_AUDIO_BUFFER_ADAPTER;

}  // namespace OHOS::ArkWeb
