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

#ifndef ARK_AUDIO_CENC_INFO_ADAPTER_CAPI_H_
#define ARK_AUDIO_CENC_INFO_ADAPTER_CAPI_H_
#pragma once

#include "base/capi/ark_web_base_ref_counted_capi.h"
#include "base/include/ark_web_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ark_audio_cenc_info_adapter_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  uint8_t*(ARK_WEB_CALLBACK* get_key_id)(
      struct _ark_audio_cenc_info_adapter_t* self);

  uint32_t(ARK_WEB_CALLBACK* get_key_id_len)(
      struct _ark_audio_cenc_info_adapter_t* self);

  uint8_t*(ARK_WEB_CALLBACK* get_iv)(
      struct _ark_audio_cenc_info_adapter_t* self);

  uint32_t(ARK_WEB_CALLBACK* get_iv_len)(
      struct _ark_audio_cenc_info_adapter_t* self);

  uint32_t(ARK_WEB_CALLBACK* get_algo)(
      struct _ark_audio_cenc_info_adapter_t* self);

  uint32_t(ARK_WEB_CALLBACK* get_encrypted_block_count)(
      struct _ark_audio_cenc_info_adapter_t* self);

  uint32_t(ARK_WEB_CALLBACK* get_skipped_block_count)(
      struct _ark_audio_cenc_info_adapter_t* self);

  uint32_t(ARK_WEB_CALLBACK* get_first_encrypted_offset)(
      struct _ark_audio_cenc_info_adapter_t* self);

  ArkWebUint32Vector(ARK_WEB_CALLBACK* get_clear_header_lens)(
      struct _ark_audio_cenc_info_adapter_t* self);

  ArkWebUint32Vector(ARK_WEB_CALLBACK* get_pay_load_lens)(
      struct _ark_audio_cenc_info_adapter_t* self);

  uint32_t(ARK_WEB_CALLBACK* get_mode)(
      struct _ark_audio_cenc_info_adapter_t* self);

  void(ARK_WEB_CALLBACK* set_key_id)(
      struct _ark_audio_cenc_info_adapter_t* self,
      uint8_t* keyId);

  void(ARK_WEB_CALLBACK* set_key_id_len)(
      struct _ark_audio_cenc_info_adapter_t* self,
      uint32_t keyIdLen);

  void(ARK_WEB_CALLBACK* set_iv)(struct _ark_audio_cenc_info_adapter_t* self,
                                 uint8_t* iv);

  void(ARK_WEB_CALLBACK* set_iv_len)(
      struct _ark_audio_cenc_info_adapter_t* self,
      uint32_t ivLen);

  void(ARK_WEB_CALLBACK* set_algo)(struct _ark_audio_cenc_info_adapter_t* self,
                                   uint32_t algo);

  void(ARK_WEB_CALLBACK* set_encrypted_block_count)(
      struct _ark_audio_cenc_info_adapter_t* self,
      uint32_t blockCount);

  void(ARK_WEB_CALLBACK* set_skipped_block_count)(
      struct _ark_audio_cenc_info_adapter_t* self,
      uint32_t blockCount);

  void(ARK_WEB_CALLBACK* set_first_encrypted_offset)(
      struct _ark_audio_cenc_info_adapter_t* self,
      uint32_t offset);

  void(ARK_WEB_CALLBACK* set_clear_header_lens)(
      struct _ark_audio_cenc_info_adapter_t* self,
      const ArkWebUint32Vector* lens);

  void(ARK_WEB_CALLBACK* set_pay_load_lens)(
      struct _ark_audio_cenc_info_adapter_t* self,
      const ArkWebUint32Vector* lens);

  void(ARK_WEB_CALLBACK* set_mode)(struct _ark_audio_cenc_info_adapter_t* self,
                                   uint32_t mode);
} ark_audio_cenc_info_adapter_t;

#ifdef __cplusplus
}
#endif

#endif  // ARK_AUDIO_CENC_INFO_ADAPTER_CAPI_H_
