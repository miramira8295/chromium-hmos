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

#include "ohos_adapter/cpptoc/ark_buffer_request_config_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

int32_t ARK_WEB_CALLBACK ark_buffer_request_config_adapter_get_width(
    struct _ark_buffer_request_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkBufferRequestConfigAdapterCppToC::Get(self)->GetWidth();
}

int32_t ARK_WEB_CALLBACK ark_buffer_request_config_adapter_get_height(
    struct _ark_buffer_request_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkBufferRequestConfigAdapterCppToC::Get(self)->GetHeight();
}

int32_t ARK_WEB_CALLBACK ark_buffer_request_config_adapter_get_stride_alignment(
    struct _ark_buffer_request_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkBufferRequestConfigAdapterCppToC::Get(self)->GetStrideAlignment();
}

int32_t ARK_WEB_CALLBACK ark_buffer_request_config_adapter_get_format(
    struct _ark_buffer_request_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkBufferRequestConfigAdapterCppToC::Get(self)->GetFormat();
}

uint64_t ARK_WEB_CALLBACK ark_buffer_request_config_adapter_get_usage(
    struct _ark_buffer_request_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkBufferRequestConfigAdapterCppToC::Get(self)->GetUsage();
}

int32_t ARK_WEB_CALLBACK ark_buffer_request_config_adapter_get_timeout(
    struct _ark_buffer_request_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkBufferRequestConfigAdapterCppToC::Get(self)->GetTimeout();
}

int32_t ARK_WEB_CALLBACK ark_buffer_request_config_adapter_get_color_gamut(
    struct _ark_buffer_request_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkBufferRequestConfigAdapterCppToC::Get(self)->GetColorGamut();
}

int32_t ARK_WEB_CALLBACK ark_buffer_request_config_adapter_get_transform_type(
    struct _ark_buffer_request_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkBufferRequestConfigAdapterCppToC::Get(self)->GetTransformType();
}

}  // namespace

ArkBufferRequestConfigAdapterCppToC::ArkBufferRequestConfigAdapterCppToC() {
  GetStruct()->get_width = ark_buffer_request_config_adapter_get_width;
  GetStruct()->get_height = ark_buffer_request_config_adapter_get_height;
  GetStruct()->get_stride_alignment =
      ark_buffer_request_config_adapter_get_stride_alignment;
  GetStruct()->get_format = ark_buffer_request_config_adapter_get_format;
  GetStruct()->get_usage = ark_buffer_request_config_adapter_get_usage;
  GetStruct()->get_timeout = ark_buffer_request_config_adapter_get_timeout;
  GetStruct()->get_color_gamut =
      ark_buffer_request_config_adapter_get_color_gamut;
  GetStruct()->get_transform_type =
      ark_buffer_request_config_adapter_get_transform_type;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["rpnyzUsqa5yEaKNZbeQ_Wg"] =
        reinterpret_cast<void*>(ark_buffer_request_config_adapter_get_width);
    funcMemberMap["8U48cXXM3AVJEeia9Uyxkw"] =
        reinterpret_cast<void*>(ark_buffer_request_config_adapter_get_height);
    funcMemberMap["JAZvUFcyYKeAhY3dQXpz6g"] = reinterpret_cast<void*>(
        ark_buffer_request_config_adapter_get_stride_alignment);
    funcMemberMap["HX4pCC58w0E8E0viTj2A5Q"] =
        reinterpret_cast<void*>(ark_buffer_request_config_adapter_get_format);
    funcMemberMap["46sTal5JGs9h1B1So59l_w"] =
        reinterpret_cast<void*>(ark_buffer_request_config_adapter_get_usage);
    funcMemberMap["94jtmq4MQKEnFtJOJ$SwjQ"] =
        reinterpret_cast<void*>(ark_buffer_request_config_adapter_get_timeout);
    funcMemberMap["i_Jqr0sxjF5RobReW$mIDw"] = reinterpret_cast<void*>(
        ark_buffer_request_config_adapter_get_color_gamut);
    funcMemberMap["Ufa1fM0OR8YsmFUG2Wp9xA"] = reinterpret_cast<void*>(
        ark_buffer_request_config_adapter_get_transform_type);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_BUFFER_REQUEST_CONFIG_ADAPTER, funcMemberMap);
  });
}

ArkBufferRequestConfigAdapterCppToC::~ArkBufferRequestConfigAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkBufferRequestConfigAdapterCppToC,
                           ArkBufferRequestConfigAdapter,
                           ark_buffer_request_config_adapter_t>::kBridgeType =
        ARK_BUFFER_REQUEST_CONFIG_ADAPTER;

}  // namespace OHOS::ArkWeb
