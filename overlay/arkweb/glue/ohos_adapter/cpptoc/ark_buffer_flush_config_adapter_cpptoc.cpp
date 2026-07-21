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

#include "ohos_adapter/cpptoc/ark_buffer_flush_config_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

int32_t ARK_WEB_CALLBACK ark_buffer_flush_config_adapter_get_x(
    struct _ark_buffer_flush_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkBufferFlushConfigAdapterCppToC::Get(self)->GetX();
}

int32_t ARK_WEB_CALLBACK ark_buffer_flush_config_adapter_get_y(
    struct _ark_buffer_flush_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkBufferFlushConfigAdapterCppToC::Get(self)->GetY();
}

int32_t ARK_WEB_CALLBACK ark_buffer_flush_config_adapter_get_w(
    struct _ark_buffer_flush_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkBufferFlushConfigAdapterCppToC::Get(self)->GetW();
}

int32_t ARK_WEB_CALLBACK ark_buffer_flush_config_adapter_get_h(
    struct _ark_buffer_flush_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkBufferFlushConfigAdapterCppToC::Get(self)->GetH();
}

int64_t ARK_WEB_CALLBACK ark_buffer_flush_config_adapter_get_timestamp(
    struct _ark_buffer_flush_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkBufferFlushConfigAdapterCppToC::Get(self)->GetTimestamp();
}

}  // namespace

ArkBufferFlushConfigAdapterCppToC::ArkBufferFlushConfigAdapterCppToC() {
  GetStruct()->get_x = ark_buffer_flush_config_adapter_get_x;
  GetStruct()->get_y = ark_buffer_flush_config_adapter_get_y;
  GetStruct()->get_w = ark_buffer_flush_config_adapter_get_w;
  GetStruct()->get_h = ark_buffer_flush_config_adapter_get_h;
  GetStruct()->get_timestamp = ark_buffer_flush_config_adapter_get_timestamp;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["E_VGMP2h4Tc3nyucoWfkqQ"] =
        reinterpret_cast<void*>(ark_buffer_flush_config_adapter_get_x);
    funcMemberMap["as5aGaVfi$qF5FU5zg2hNg"] =
        reinterpret_cast<void*>(ark_buffer_flush_config_adapter_get_y);
    funcMemberMap["7ziyCzOm$dawGE4ynOLyiA"] =
        reinterpret_cast<void*>(ark_buffer_flush_config_adapter_get_w);
    funcMemberMap["e0yly9r8s$$a8jqRkv4I9A"] =
        reinterpret_cast<void*>(ark_buffer_flush_config_adapter_get_h);
    funcMemberMap["_gxjV5b3Al8wh_RebZf5NA"] =
        reinterpret_cast<void*>(ark_buffer_flush_config_adapter_get_timestamp);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_BUFFER_FLUSH_CONFIG_ADAPTER, funcMemberMap);
  });
}

ArkBufferFlushConfigAdapterCppToC::~ArkBufferFlushConfigAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkBufferFlushConfigAdapterCppToC,
                           ArkBufferFlushConfigAdapter,
                           ark_buffer_flush_config_adapter_t>::kBridgeType =
        ARK_BUFFER_FLUSH_CONFIG_ADAPTER;

}  // namespace OHOS::ArkWeb
