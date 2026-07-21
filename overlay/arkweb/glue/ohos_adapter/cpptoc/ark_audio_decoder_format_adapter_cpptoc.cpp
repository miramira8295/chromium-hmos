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

#include "ohos_adapter/cpptoc/ark_audio_decoder_format_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

int32_t ARK_WEB_CALLBACK ark_audio_decoder_format_adapter_get_sample_rate(
    struct _ark_audio_decoder_format_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioDecoderFormatAdapterCppToC::Get(self)->GetSampleRate();
}

int32_t ARK_WEB_CALLBACK ark_audio_decoder_format_adapter_get_channel_count(
    struct _ark_audio_decoder_format_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioDecoderFormatAdapterCppToC::Get(self)->GetChannelCount();
}

int64_t ARK_WEB_CALLBACK ark_audio_decoder_format_adapter_get_bit_rate(
    struct _ark_audio_decoder_format_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioDecoderFormatAdapterCppToC::Get(self)->GetBitRate();
}

int32_t ARK_WEB_CALLBACK ark_audio_decoder_format_adapter_get_max_input_size(
    struct _ark_audio_decoder_format_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioDecoderFormatAdapterCppToC::Get(self)->GetMaxInputSize();
}

bool ARK_WEB_CALLBACK ark_audio_decoder_format_adapter_get_aacis_adts(
    struct _ark_audio_decoder_format_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkAudioDecoderFormatAdapterCppToC::Get(self)->GetAACIsAdts();
}

int32_t ARK_WEB_CALLBACK
ark_audio_decoder_format_adapter_get_audio_sample_format(
    struct _ark_audio_decoder_format_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioDecoderFormatAdapterCppToC::Get(self)->GetAudioSampleFormat();
}

int32_t ARK_WEB_CALLBACK
ark_audio_decoder_format_adapter_get_identification_header(
    struct _ark_audio_decoder_format_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioDecoderFormatAdapterCppToC::Get(self)
      ->GetIdentificationHeader();
}

int32_t ARK_WEB_CALLBACK ark_audio_decoder_format_adapter_get_setup_header(
    struct _ark_audio_decoder_format_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioDecoderFormatAdapterCppToC::Get(self)->GetSetupHeader();
}

uint8_t* ARK_WEB_CALLBACK ark_audio_decoder_format_adapter_get_codec_config(
    struct _ark_audio_decoder_format_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  return ArkAudioDecoderFormatAdapterCppToC::Get(self)->GetCodecConfig();
}

uint32_t ARK_WEB_CALLBACK
ark_audio_decoder_format_adapter_get_codec_config_size(
    struct _ark_audio_decoder_format_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioDecoderFormatAdapterCppToC::Get(self)->GetCodecConfigSize();
}

void ARK_WEB_CALLBACK ark_audio_decoder_format_adapter_set_sample_rate(
    struct _ark_audio_decoder_format_adapter_t* self,
    int32_t sampleRate) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioDecoderFormatAdapterCppToC::Get(self)->SetSampleRate(sampleRate);
}

void ARK_WEB_CALLBACK ark_audio_decoder_format_adapter_set_channel_count(
    struct _ark_audio_decoder_format_adapter_t* self,
    int32_t channelCount) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioDecoderFormatAdapterCppToC::Get(self)->SetChannelCount(channelCount);
}

void ARK_WEB_CALLBACK ark_audio_decoder_format_adapter_set_bit_rate(
    struct _ark_audio_decoder_format_adapter_t* self,
    int64_t bitRate) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioDecoderFormatAdapterCppToC::Get(self)->SetBitRate(bitRate);
}

void ARK_WEB_CALLBACK ark_audio_decoder_format_adapter_set_max_input_size(
    struct _ark_audio_decoder_format_adapter_t* self,
    int32_t maxInputSize) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioDecoderFormatAdapterCppToC::Get(self)->SetMaxInputSize(maxInputSize);
}

void ARK_WEB_CALLBACK ark_audio_decoder_format_adapter_set_aacis_adts(
    struct _ark_audio_decoder_format_adapter_t* self,
    bool isAdts) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioDecoderFormatAdapterCppToC::Get(self)->SetAACIsAdts(isAdts);
}

void ARK_WEB_CALLBACK ark_audio_decoder_format_adapter_set_audio_sample_format(
    struct _ark_audio_decoder_format_adapter_t* self,
    int32_t audioSampleFormat) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioDecoderFormatAdapterCppToC::Get(self)->SetAudioSampleFormat(
      audioSampleFormat);
}

void ARK_WEB_CALLBACK
ark_audio_decoder_format_adapter_set_identification_header(
    struct _ark_audio_decoder_format_adapter_t* self,
    int32_t data) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioDecoderFormatAdapterCppToC::Get(self)->SetIdentificationHeader(data);
}

void ARK_WEB_CALLBACK ark_audio_decoder_format_adapter_set_setup_header(
    struct _ark_audio_decoder_format_adapter_t* self,
    int32_t data) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioDecoderFormatAdapterCppToC::Get(self)->SetSetupHeader(data);
}

void ARK_WEB_CALLBACK ark_audio_decoder_format_adapter_set_codec_config(
    struct _ark_audio_decoder_format_adapter_t* self,
    uint8_t* codecConfig) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioDecoderFormatAdapterCppToC::Get(self)->SetCodecConfig(codecConfig);
}

void ARK_WEB_CALLBACK ark_audio_decoder_format_adapter_set_codec_config_size(
    struct _ark_audio_decoder_format_adapter_t* self,
    uint32_t size) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioDecoderFormatAdapterCppToC::Get(self)->SetCodecConfigSize(size);
}

}  // namespace

ArkAudioDecoderFormatAdapterCppToC::ArkAudioDecoderFormatAdapterCppToC() {
  GetStruct()->get_sample_rate =
      ark_audio_decoder_format_adapter_get_sample_rate;
  GetStruct()->get_channel_count =
      ark_audio_decoder_format_adapter_get_channel_count;
  GetStruct()->get_bit_rate = ark_audio_decoder_format_adapter_get_bit_rate;
  GetStruct()->get_max_input_size =
      ark_audio_decoder_format_adapter_get_max_input_size;
  GetStruct()->get_aacis_adts = ark_audio_decoder_format_adapter_get_aacis_adts;
  GetStruct()->get_audio_sample_format =
      ark_audio_decoder_format_adapter_get_audio_sample_format;
  GetStruct()->get_identification_header =
      ark_audio_decoder_format_adapter_get_identification_header;
  GetStruct()->get_setup_header =
      ark_audio_decoder_format_adapter_get_setup_header;
  GetStruct()->get_codec_config =
      ark_audio_decoder_format_adapter_get_codec_config;
  GetStruct()->get_codec_config_size =
      ark_audio_decoder_format_adapter_get_codec_config_size;
  GetStruct()->set_sample_rate =
      ark_audio_decoder_format_adapter_set_sample_rate;
  GetStruct()->set_channel_count =
      ark_audio_decoder_format_adapter_set_channel_count;
  GetStruct()->set_bit_rate = ark_audio_decoder_format_adapter_set_bit_rate;
  GetStruct()->set_max_input_size =
      ark_audio_decoder_format_adapter_set_max_input_size;
  GetStruct()->set_aacis_adts = ark_audio_decoder_format_adapter_set_aacis_adts;
  GetStruct()->set_audio_sample_format =
      ark_audio_decoder_format_adapter_set_audio_sample_format;
  GetStruct()->set_identification_header =
      ark_audio_decoder_format_adapter_set_identification_header;
  GetStruct()->set_setup_header =
      ark_audio_decoder_format_adapter_set_setup_header;
  GetStruct()->set_codec_config =
      ark_audio_decoder_format_adapter_set_codec_config;
  GetStruct()->set_codec_config_size =
      ark_audio_decoder_format_adapter_set_codec_config_size;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["pGQ3fuVDMMyxrJq58GQBHg"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_get_sample_rate);
    funcMemberMap["D6wxddUS6Hgdr_7QSV4pfQ"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_get_channel_count);
    funcMemberMap["JfQUubM_kfWUJQfiSYYf9w"] =
        reinterpret_cast<void*>(ark_audio_decoder_format_adapter_get_bit_rate);
    funcMemberMap["AS8LfWlLduV3nC_OQKzksg"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_get_max_input_size);
    funcMemberMap["OfWThMHXUj9P9l99rcevWQ"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_get_aacis_adts);
    funcMemberMap["Vxkn_xR_cRhSs4mfMMSfLg"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_get_audio_sample_format);
    funcMemberMap["asA1kaKvZhcNFl4n3JgJ5Q"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_get_identification_header);
    funcMemberMap["_tAZv4St0gABbxjzfUVDww"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_get_setup_header);
    funcMemberMap["qV5x5doCAHg4k8U2vlQo0g"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_get_codec_config);
    funcMemberMap["vYuYQq$LjrRlb0cPmiLvSQ"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_get_codec_config_size);
    funcMemberMap["w7W9x4CoII4ojcyjgAbKmg"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_set_sample_rate);
    funcMemberMap["KIpAJokOSQ4bBosDcxda_A"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_set_channel_count);
    funcMemberMap["W565$X2NXzLqQskqo1SLZg"] =
        reinterpret_cast<void*>(ark_audio_decoder_format_adapter_set_bit_rate);
    funcMemberMap["Kc07tUPKQuvBS9HfN9rpXw"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_set_max_input_size);
    funcMemberMap["NZEkPNjR1ZK5X8LIm7IBgg"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_set_aacis_adts);
    funcMemberMap["gXLHfnnDKYcsJyteJDo0hQ"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_set_audio_sample_format);
    funcMemberMap["X5$Mqi3vA7OrZQjBK5BXHQ"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_set_identification_header);
    funcMemberMap["1yytV9mp1PR0zTs00YXtgA"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_set_setup_header);
    funcMemberMap["3iTfE_xhKlm0p5bScP5j1A"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_set_codec_config);
    funcMemberMap["m3ltslZLL1rQpFmfJx_CeA"] = reinterpret_cast<void*>(
        ark_audio_decoder_format_adapter_set_codec_config_size);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_AUDIO_DECODER_FORMAT_ADAPTER, funcMemberMap);
  });
}

ArkAudioDecoderFormatAdapterCppToC::~ArkAudioDecoderFormatAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkAudioDecoderFormatAdapterCppToC,
                           ArkAudioDecoderFormatAdapter,
                           ark_audio_decoder_format_adapter_t>::kBridgeType =
        ARK_AUDIO_DECODER_FORMAT_ADAPTER;

}  // namespace OHOS::ArkWeb
