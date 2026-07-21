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

#include "ohos_adapter/cpptoc/ark_native_buffer_config_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

int ARK_WEB_CALLBACK ark_native_buffer_config_adapter_get_buffer_width(
    struct _ark_native_buffer_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkNativeBufferConfigAdapterCppToC::Get(self)->GetBufferWidth();
}

int ARK_WEB_CALLBACK ark_native_buffer_config_adapter_get_buffer_height(
    struct _ark_native_buffer_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkNativeBufferConfigAdapterCppToC::Get(self)->GetBufferHeight();
}

int ARK_WEB_CALLBACK ark_native_buffer_config_adapter_get_buffer_format(
    struct _ark_native_buffer_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkNativeBufferConfigAdapterCppToC::Get(self)->GetBufferFormat();
}

int ARK_WEB_CALLBACK ark_native_buffer_config_adapter_get_buffer_usage(
    struct _ark_native_buffer_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkNativeBufferConfigAdapterCppToC::Get(self)->GetBufferUsage();
}

int ARK_WEB_CALLBACK ark_native_buffer_config_adapter_get_buffer_stride(
    struct _ark_native_buffer_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkNativeBufferConfigAdapterCppToC::Get(self)->GetBufferStride();
}

void ARK_WEB_CALLBACK ark_native_buffer_config_adapter_set_buffer_width(
    struct _ark_native_buffer_config_adapter_t* self,
    int width) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkNativeBufferConfigAdapterCppToC::Get(self)->SetBufferWidth(width);
}

void ARK_WEB_CALLBACK ark_native_buffer_config_adapter_set_buffer_height(
    struct _ark_native_buffer_config_adapter_t* self,
    int height) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkNativeBufferConfigAdapterCppToC::Get(self)->SetBufferHeight(height);
}

void ARK_WEB_CALLBACK ark_native_buffer_config_adapter_set_buffer_format(
    struct _ark_native_buffer_config_adapter_t* self,
    int format) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkNativeBufferConfigAdapterCppToC::Get(self)->SetBufferFormat(format);
}

void ARK_WEB_CALLBACK ark_native_buffer_config_adapter_set_buffer_usage(
    struct _ark_native_buffer_config_adapter_t* self,
    int usage) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkNativeBufferConfigAdapterCppToC::Get(self)->SetBufferUsage(usage);
}

void ARK_WEB_CALLBACK ark_native_buffer_config_adapter_set_buffer_stride(
    struct _ark_native_buffer_config_adapter_t* self,
    int stride) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkNativeBufferConfigAdapterCppToC::Get(self)->SetBufferStride(stride);
}

}  // namespace

ArkNativeBufferConfigAdapterCppToC::ArkNativeBufferConfigAdapterCppToC() {
  GetStruct()->get_buffer_width =
      ark_native_buffer_config_adapter_get_buffer_width;
  GetStruct()->get_buffer_height =
      ark_native_buffer_config_adapter_get_buffer_height;
  GetStruct()->get_buffer_format =
      ark_native_buffer_config_adapter_get_buffer_format;
  GetStruct()->get_buffer_usage =
      ark_native_buffer_config_adapter_get_buffer_usage;
  GetStruct()->get_buffer_stride =
      ark_native_buffer_config_adapter_get_buffer_stride;
  GetStruct()->set_buffer_width =
      ark_native_buffer_config_adapter_set_buffer_width;
  GetStruct()->set_buffer_height =
      ark_native_buffer_config_adapter_set_buffer_height;
  GetStruct()->set_buffer_format =
      ark_native_buffer_config_adapter_set_buffer_format;
  GetStruct()->set_buffer_usage =
      ark_native_buffer_config_adapter_set_buffer_usage;
  GetStruct()->set_buffer_stride =
      ark_native_buffer_config_adapter_set_buffer_stride;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["GENhsBAzvegXx2UTD6PkZQ"] = reinterpret_cast<void*>(
        ark_native_buffer_config_adapter_get_buffer_width);
    funcMemberMap["s$$9GQWJhxsV5ISruLIXSQ"] = reinterpret_cast<void*>(
        ark_native_buffer_config_adapter_get_buffer_height);
    funcMemberMap["BGkTDuY1D51NcM5biAHrzA"] = reinterpret_cast<void*>(
        ark_native_buffer_config_adapter_get_buffer_format);
    funcMemberMap["CK3tWsbb2txQrmUFwCfVbQ"] = reinterpret_cast<void*>(
        ark_native_buffer_config_adapter_get_buffer_usage);
    funcMemberMap["QJBgF4Pm4D1jdKVVY8LdLw"] = reinterpret_cast<void*>(
        ark_native_buffer_config_adapter_get_buffer_stride);
    funcMemberMap["n3Vcwjdj9IDTL6U4yYnwsQ"] = reinterpret_cast<void*>(
        ark_native_buffer_config_adapter_set_buffer_width);
    funcMemberMap["kzpc6v5GEBTk3GXF3QfG0Q"] = reinterpret_cast<void*>(
        ark_native_buffer_config_adapter_set_buffer_height);
    funcMemberMap["SpdSyekgvCJwDlh8_vWvCQ"] = reinterpret_cast<void*>(
        ark_native_buffer_config_adapter_set_buffer_format);
    funcMemberMap["nvlYK6XbxvAaCu2kCdaY1w"] = reinterpret_cast<void*>(
        ark_native_buffer_config_adapter_set_buffer_usage);
    funcMemberMap["dCpaIqRYCn3vLkT0$XZgAg"] = reinterpret_cast<void*>(
        ark_native_buffer_config_adapter_set_buffer_stride);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_NATIVE_BUFFER_CONFIG_ADAPTER, funcMemberMap);
  });
}

ArkNativeBufferConfigAdapterCppToC::~ArkNativeBufferConfigAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkNativeBufferConfigAdapterCppToC,
                           ArkNativeBufferConfigAdapter,
                           ark_native_buffer_config_adapter_t>::kBridgeType =
        ARK_NATIVE_BUFFER_CONFIG_ADAPTER;

}  // namespace OHOS::ArkWeb
