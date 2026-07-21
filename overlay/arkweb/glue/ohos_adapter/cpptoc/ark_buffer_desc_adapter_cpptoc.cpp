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

#include "ohos_adapter/cpptoc/ark_buffer_desc_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

uint8_t* ARK_WEB_CALLBACK
ark_buffer_desc_adapter_get_buffer(struct _ark_buffer_desc_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  return ArkBufferDescAdapterCppToC::Get(self)->GetBuffer();
}

size_t ARK_WEB_CALLBACK ark_buffer_desc_adapter_get_buf_length(
    struct _ark_buffer_desc_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkBufferDescAdapterCppToC::Get(self)->GetBufLength();
}

size_t ARK_WEB_CALLBACK ark_buffer_desc_adapter_get_data_length(
    struct _ark_buffer_desc_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkBufferDescAdapterCppToC::Get(self)->GetDataLength();
}

void ARK_WEB_CALLBACK
ark_buffer_desc_adapter_set_buffer(struct _ark_buffer_desc_adapter_t* self,
                                   uint8_t* buffer) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkBufferDescAdapterCppToC::Get(self)->SetBuffer(buffer);
}

void ARK_WEB_CALLBACK
ark_buffer_desc_adapter_set_buf_length(struct _ark_buffer_desc_adapter_t* self,
                                       size_t bufLength) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkBufferDescAdapterCppToC::Get(self)->SetBufLength(bufLength);
}

void ARK_WEB_CALLBACK
ark_buffer_desc_adapter_set_data_length(struct _ark_buffer_desc_adapter_t* self,
                                        size_t dataLength) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkBufferDescAdapterCppToC::Get(self)->SetDataLength(dataLength);
}

}  // namespace

ArkBufferDescAdapterCppToC::ArkBufferDescAdapterCppToC() {
  GetStruct()->get_buffer = ark_buffer_desc_adapter_get_buffer;
  GetStruct()->get_buf_length = ark_buffer_desc_adapter_get_buf_length;
  GetStruct()->get_data_length = ark_buffer_desc_adapter_get_data_length;
  GetStruct()->set_buffer = ark_buffer_desc_adapter_set_buffer;
  GetStruct()->set_buf_length = ark_buffer_desc_adapter_set_buf_length;
  GetStruct()->set_data_length = ark_buffer_desc_adapter_set_data_length;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["16okenKrIhdinkVYkvUoXg"] =
        reinterpret_cast<void*>(ark_buffer_desc_adapter_get_buffer);
    funcMemberMap["Vwfsnp$mpx7ga6pgFZh0Nw"] =
        reinterpret_cast<void*>(ark_buffer_desc_adapter_get_buf_length);
    funcMemberMap["V4_kt5_HEpYOXo5d$o$v4A"] =
        reinterpret_cast<void*>(ark_buffer_desc_adapter_get_data_length);
    funcMemberMap["0sUmSPspiJWUC7hLCjPptg"] =
        reinterpret_cast<void*>(ark_buffer_desc_adapter_set_buffer);
    funcMemberMap["19j8lxa7UuN1qIFlH4r0UA"] =
        reinterpret_cast<void*>(ark_buffer_desc_adapter_set_buf_length);
    funcMemberMap["HZTwKs2nfVRbMCXxLfjokg"] =
        reinterpret_cast<void*>(ark_buffer_desc_adapter_set_data_length);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_BUFFER_DESC_ADAPTER, funcMemberMap);
  });
}

ArkBufferDescAdapterCppToC::~ArkBufferDescAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkBufferDescAdapterCppToC,
                           ArkBufferDescAdapter,
                           ark_buffer_desc_adapter_t>::kBridgeType =
        ARK_BUFFER_DESC_ADAPTER;

}  // namespace OHOS::ArkWeb
