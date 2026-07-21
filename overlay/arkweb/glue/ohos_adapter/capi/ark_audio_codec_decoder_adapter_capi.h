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

#ifndef ARK_AUDIO_CODEC_DECODER_ADAPTER_CAPI_H_
#define ARK_AUDIO_CODEC_DECODER_ADAPTER_CAPI_H_
#pragma once

#include "base/capi/ark_web_base_ref_counted_capi.h"
#include "base/include/ark_web_types.h"
#include "ohos_adapter/capi/ark_audio_cenc_info_adapter_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ark_audio_decoder_format_adapter_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  int32_t(ARK_WEB_CALLBACK* get_sample_rate)(
      struct _ark_audio_decoder_format_adapter_t* self);

  int32_t(ARK_WEB_CALLBACK* get_channel_count)(
      struct _ark_audio_decoder_format_adapter_t* self);

  int64_t(ARK_WEB_CALLBACK* get_bit_rate)(
      struct _ark_audio_decoder_format_adapter_t* self);

  int32_t(ARK_WEB_CALLBACK* get_max_input_size)(
      struct _ark_audio_decoder_format_adapter_t* self);

  bool(ARK_WEB_CALLBACK* get_aacis_adts)(
      struct _ark_audio_decoder_format_adapter_t* self);

  int32_t(ARK_WEB_CALLBACK* get_audio_sample_format)(
      struct _ark_audio_decoder_format_adapter_t* self);

  int32_t(ARK_WEB_CALLBACK* get_identification_header)(
      struct _ark_audio_decoder_format_adapter_t* self);

  int32_t(ARK_WEB_CALLBACK* get_setup_header)(
      struct _ark_audio_decoder_format_adapter_t* self);

  uint8_t*(ARK_WEB_CALLBACK* get_codec_config)(
      struct _ark_audio_decoder_format_adapter_t* self);

  uint32_t(ARK_WEB_CALLBACK* get_codec_config_size)(
      struct _ark_audio_decoder_format_adapter_t* self);

  void(ARK_WEB_CALLBACK* set_sample_rate)(
      struct _ark_audio_decoder_format_adapter_t* self,
      int32_t sampleRate);

  void(ARK_WEB_CALLBACK* set_channel_count)(
      struct _ark_audio_decoder_format_adapter_t* self,
      int32_t channelCount);

  void(ARK_WEB_CALLBACK* set_bit_rate)(
      struct _ark_audio_decoder_format_adapter_t* self,
      int64_t bitRate);

  void(ARK_WEB_CALLBACK* set_max_input_size)(
      struct _ark_audio_decoder_format_adapter_t* self,
      int32_t maxInputSize);

  void(ARK_WEB_CALLBACK* set_aacis_adts)(
      struct _ark_audio_decoder_format_adapter_t* self,
      bool isAdts);

  void(ARK_WEB_CALLBACK* set_audio_sample_format)(
      struct _ark_audio_decoder_format_adapter_t* self,
      int32_t audioSampleFormat);

  void(ARK_WEB_CALLBACK* set_identification_header)(
      struct _ark_audio_decoder_format_adapter_t* self,
      int32_t data);

  void(ARK_WEB_CALLBACK* set_setup_header)(
      struct _ark_audio_decoder_format_adapter_t* self,
      int32_t data);

  void(ARK_WEB_CALLBACK* set_codec_config)(
      struct _ark_audio_decoder_format_adapter_t* self,
      uint8_t* codecConfig);

  void(ARK_WEB_CALLBACK* set_codec_config_size)(
      struct _ark_audio_decoder_format_adapter_t* self,
      uint32_t size);
} ark_audio_decoder_format_adapter_t;

typedef struct _ark_audio_decoder_callback_adapter_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  void(ARK_WEB_CALLBACK* on_error)(
      struct _ark_audio_decoder_callback_adapter_t* self,
      int32_t errorCode);

  void(ARK_WEB_CALLBACK* on_output_format_changed)(
      struct _ark_audio_decoder_callback_adapter_t* self);

  void(ARK_WEB_CALLBACK* on_input_buffer_available)(
      struct _ark_audio_decoder_callback_adapter_t* self,
      uint32_t index);

  void(ARK_WEB_CALLBACK* on_output_buffer_available)(
      struct _ark_audio_decoder_callback_adapter_t* self,
      uint32_t index,
      uint8_t* bufferData,
      int32_t size,
      int64_t pts,
      int32_t offset,
      uint32_t flags);
} ark_audio_decoder_callback_adapter_t;

typedef struct _ark_audio_codec_decoder_adapter_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  int32_t(ARK_WEB_CALLBACK* create_audio_decoder_by_mime)(
      struct _ark_audio_codec_decoder_adapter_t* self,
      const ArkWebString* mimetype);

  int32_t(ARK_WEB_CALLBACK* create_audio_decoder_by_name)(
      struct _ark_audio_codec_decoder_adapter_t* self,
      const ArkWebString* name);

  int32_t(ARK_WEB_CALLBACK* configure_decoder)(
      struct _ark_audio_codec_decoder_adapter_t* self,
      ark_audio_decoder_format_adapter_t* format);

  int32_t(ARK_WEB_CALLBACK* set_parameter_decoder)(
      struct _ark_audio_codec_decoder_adapter_t* self,
      ark_audio_decoder_format_adapter_t* format);

  int32_t(ARK_WEB_CALLBACK* prepare_decoder)(
      struct _ark_audio_codec_decoder_adapter_t* self);

  int32_t(ARK_WEB_CALLBACK* start_decoder)(
      struct _ark_audio_codec_decoder_adapter_t* self);

  int32_t(ARK_WEB_CALLBACK* stop_decoder)(
      struct _ark_audio_codec_decoder_adapter_t* self);

  int32_t(ARK_WEB_CALLBACK* flush_decoder)(
      struct _ark_audio_codec_decoder_adapter_t* self);

  int32_t(ARK_WEB_CALLBACK* reset_decoder)(
      struct _ark_audio_codec_decoder_adapter_t* self);

  int32_t(ARK_WEB_CALLBACK* release_decoder)(
      struct _ark_audio_codec_decoder_adapter_t* self);

  int32_t(ARK_WEB_CALLBACK* queue_input_buffer_dec)(
      struct _ark_audio_codec_decoder_adapter_t* self,
      uint32_t index,
      int64_t presentationTimeUs,
      uint8_t* bufferData,
      int32_t bufferSize,
      ark_audio_cenc_info_adapter_t* cencInfo,
      bool isEncrypted,
      uint32_t flag);

  int32_t(ARK_WEB_CALLBACK* get_output_format_dec)(
      struct _ark_audio_codec_decoder_adapter_t* self,
      ark_audio_decoder_format_adapter_t* format);

  int32_t(ARK_WEB_CALLBACK* release_output_buffer_dec)(
      struct _ark_audio_codec_decoder_adapter_t* self,
      uint32_t index);

  int32_t(ARK_WEB_CALLBACK* set_callback_dec)(
      struct _ark_audio_codec_decoder_adapter_t* self,
      ark_audio_decoder_callback_adapter_t* callback);

  int32_t(ARK_WEB_CALLBACK* set_decryption_config)(
      struct _ark_audio_codec_decoder_adapter_t* self,
      void* session,
      bool secureAudio);
} ark_audio_codec_decoder_adapter_t;

#ifdef __cplusplus
}
#endif

#endif  // ARK_AUDIO_CODEC_DECODER_ADAPTER_CAPI_H_
