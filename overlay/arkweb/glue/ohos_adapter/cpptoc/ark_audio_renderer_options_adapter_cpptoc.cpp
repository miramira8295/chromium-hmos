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

#include "ohos_adapter/cpptoc/ark_audio_renderer_options_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

int32_t ARK_WEB_CALLBACK ark_audio_renderer_options_adapter_get_sampling_rate(
    struct _ark_audio_renderer_options_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioRendererOptionsAdapterCppToC::Get(self)->GetSamplingRate();
}

int32_t ARK_WEB_CALLBACK ark_audio_renderer_options_adapter_get_encoding_type(
    struct _ark_audio_renderer_options_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioRendererOptionsAdapterCppToC::Get(self)->GetEncodingType();
}

int32_t ARK_WEB_CALLBACK ark_audio_renderer_options_adapter_get_sample_format(
    struct _ark_audio_renderer_options_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioRendererOptionsAdapterCppToC::Get(self)->GetSampleFormat();
}

int32_t ARK_WEB_CALLBACK ark_audio_renderer_options_adapter_get_channel(
    struct _ark_audio_renderer_options_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioRendererOptionsAdapterCppToC::Get(self)->GetChannel();
}

int32_t ARK_WEB_CALLBACK ark_audio_renderer_options_adapter_get_content_type(
    struct _ark_audio_renderer_options_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioRendererOptionsAdapterCppToC::Get(self)->GetContentType();
}

int32_t ARK_WEB_CALLBACK ark_audio_renderer_options_adapter_get_stream_usage(
    struct _ark_audio_renderer_options_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioRendererOptionsAdapterCppToC::Get(self)->GetStreamUsage();
}

int32_t ARK_WEB_CALLBACK ark_audio_renderer_options_adapter_get_render_flags(
    struct _ark_audio_renderer_options_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioRendererOptionsAdapterCppToC::Get(self)->GetRenderFlags();
}

int32_t ARK_WEB_CALLBACK
ark_audio_renderer_options_adapter_get_concurrency_mode(
    struct _ark_audio_renderer_options_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioRendererOptionsAdapterCppToC::Get(self)->GetConcurrencyMode();
}

}  // namespace

ArkAudioRendererOptionsAdapterCppToC::ArkAudioRendererOptionsAdapterCppToC() {
  GetStruct()->get_sampling_rate =
      ark_audio_renderer_options_adapter_get_sampling_rate;
  GetStruct()->get_encoding_type =
      ark_audio_renderer_options_adapter_get_encoding_type;
  GetStruct()->get_sample_format =
      ark_audio_renderer_options_adapter_get_sample_format;
  GetStruct()->get_channel = ark_audio_renderer_options_adapter_get_channel;
  GetStruct()->get_content_type =
      ark_audio_renderer_options_adapter_get_content_type;
  GetStruct()->get_stream_usage =
      ark_audio_renderer_options_adapter_get_stream_usage;
  GetStruct()->get_render_flags =
      ark_audio_renderer_options_adapter_get_render_flags;
  GetStruct()->get_concurrency_mode =
      ark_audio_renderer_options_adapter_get_concurrency_mode;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["qrutT0w3YKObzbTKA$uFLQ"] = reinterpret_cast<void*>(
        ark_audio_renderer_options_adapter_get_sampling_rate);
    funcMemberMap["zdF3fzbRKC0mZjzonKhzdA"] = reinterpret_cast<void*>(
        ark_audio_renderer_options_adapter_get_encoding_type);
    funcMemberMap["qFL0jVpjwTqmSYkm7Ek6cw"] = reinterpret_cast<void*>(
        ark_audio_renderer_options_adapter_get_sample_format);
    funcMemberMap["bM12PAOlL2cn2Qx0bYXv5w"] =
        reinterpret_cast<void*>(ark_audio_renderer_options_adapter_get_channel);
    funcMemberMap["TAs0313Np7hO63SncO8qrw"] = reinterpret_cast<void*>(
        ark_audio_renderer_options_adapter_get_content_type);
    funcMemberMap["lk3CXxNmqSUj4cgqvbMwew"] = reinterpret_cast<void*>(
        ark_audio_renderer_options_adapter_get_stream_usage);
    funcMemberMap["TVYvxOfmC_QQfkvzr261Gg"] = reinterpret_cast<void*>(
        ark_audio_renderer_options_adapter_get_render_flags);
    funcMemberMap["rFxV4MJ4sd9kJS4debC0SQ"] = reinterpret_cast<void*>(
        ark_audio_renderer_options_adapter_get_concurrency_mode);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_AUDIO_RENDERER_OPTIONS_ADAPTER, funcMemberMap);
  });
}

ArkAudioRendererOptionsAdapterCppToC::~ArkAudioRendererOptionsAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkAudioRendererOptionsAdapterCppToC,
                           ArkAudioRendererOptionsAdapter,
                           ark_audio_renderer_options_adapter_t>::kBridgeType =
        ARK_AUDIO_RENDERER_OPTIONS_ADAPTER;

}  // namespace OHOS::ArkWeb
