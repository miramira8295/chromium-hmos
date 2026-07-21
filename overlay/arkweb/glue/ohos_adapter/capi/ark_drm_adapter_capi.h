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

#ifndef ARK_DRM_ADAPTER_CAPI_H_
#define ARK_DRM_ADAPTER_CAPI_H_
#pragma once

#include "base/capi/ark_web_base_ref_counted_capi.h"
#include "base/include/ark_web_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ark_drm_callback_adapter_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  void(ARK_WEB_CALLBACK* on_session_message)(
      struct _ark_drm_callback_adapter_t* self,
      const ArkWebString* sessionId,
      int32_t* type,
      const ArkWebUint8Vector* message);

  void(ARK_WEB_CALLBACK* on_provision_request)(
      struct _ark_drm_callback_adapter_t* self,
      const ArkWebString* defaultUrl,
      const ArkWebString* requestData);

  void(ARK_WEB_CALLBACK* on_provisioning_complete)(
      struct _ark_drm_callback_adapter_t* self,
      bool success);

  void(ARK_WEB_CALLBACK* on_media_key_session_ready)(
      struct _ark_drm_callback_adapter_t* self,
      void* session);

  void(ARK_WEB_CALLBACK* on_promise_rejected)(
      struct _ark_drm_callback_adapter_t* self,
      uint32_t promiseId,
      const ArkWebString* errorMessage);

  void(ARK_WEB_CALLBACK* on_promise_resolved)(
      struct _ark_drm_callback_adapter_t* self,
      uint32_t promiseId);

  void(ARK_WEB_CALLBACK* on_promise_resolved_with_session)(
      struct _ark_drm_callback_adapter_t* self,
      uint32_t promiseId,
      const ArkWebString* sessionId);

  void(ARK_WEB_CALLBACK* on_session_closed)(
      struct _ark_drm_callback_adapter_t* self,
      const ArkWebString* sessionId);

  void(ARK_WEB_CALLBACK* on_session_keys_change)(
      struct _ark_drm_callback_adapter_t* self,
      const ArkWebString* sessionId,
      const ArkWebStringVector* keyIdArray,
      const ArkWebUint32Vector* statusArray,
      bool hasAdditionalUsableKey,
      bool isKeyRelease);

  void(ARK_WEB_CALLBACK* on_session_expiration_update)(
      struct _ark_drm_callback_adapter_t* self,
      const ArkWebString* sessionId,
      uint64_t expirationTime);

  void(ARK_WEB_CALLBACK* on_storage_provisioned)(
      struct _ark_drm_callback_adapter_t* self);

  void(ARK_WEB_CALLBACK* on_storage_save_info)(
      struct _ark_drm_callback_adapter_t* self,
      const ArkWebUint8Vector* ketSetId,
      const ArkWebString* mimeType,
      const ArkWebString* sessionId,
      int32_t keyType);

  void(ARK_WEB_CALLBACK* on_storage_load_info)(
      struct _ark_drm_callback_adapter_t* self,
      const ArkWebString* sessionId);

  void(ARK_WEB_CALLBACK* on_storage_clear_info_for_key_release)(
      struct _ark_drm_callback_adapter_t* self,
      const ArkWebString* sessionId);

  void(ARK_WEB_CALLBACK* on_storage_clear_info_for_load_fail)(
      struct _ark_drm_callback_adapter_t* self,
      const ArkWebString* sessionId);

  void(ARK_WEB_CALLBACK* on_media_license_ready)(
      struct _ark_drm_callback_adapter_t* self,
      bool success);
} ark_drm_callback_adapter_t;

typedef struct _ark_drm_adapter_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  bool(ARK_WEB_CALLBACK* is_supported)(struct _ark_drm_adapter_t* self,
                                       const ArkWebString* name);

  bool(ARK_WEB_CALLBACK* is_supported2)(struct _ark_drm_adapter_t* self,
                                        const ArkWebString* name,
                                        const ArkWebString* mimeType);

  bool(ARK_WEB_CALLBACK* is_supported3)(struct _ark_drm_adapter_t* self,
                                        const ArkWebString* name,
                                        const ArkWebString* mimeType,
                                        int32_t level);

  ArkWebUint8Vector(ARK_WEB_CALLBACK* get_uuid)(struct _ark_drm_adapter_t* self,
                                                const ArkWebString* name);

  void(ARK_WEB_CALLBACK* storage_provisioned_result)(
      struct _ark_drm_adapter_t* self,
      bool result);

  void(ARK_WEB_CALLBACK* storage_save_info_result)(
      struct _ark_drm_adapter_t* self,
      bool result,
      int32_t type);

  void(ARK_WEB_CALLBACK* storage_load_info_result)(
      struct _ark_drm_adapter_t* self,
      const ArkWebString* sessionId,
      const ArkWebUint8Vector* keySetId,
      const ArkWebString* mimeType,
      uint32_t keyType);

  void(ARK_WEB_CALLBACK* storage_clear_info_result)(
      struct _ark_drm_adapter_t* self,
      bool result,
      int32_t type);

  int32_t(ARK_WEB_CALLBACK* release_media_key_system)(
      struct _ark_drm_adapter_t* self);

  int32_t(ARK_WEB_CALLBACK* release_media_key_session)(
      struct _ark_drm_adapter_t* self);

  int32_t(ARK_WEB_CALLBACK* create_key_system)(struct _ark_drm_adapter_t* self,
                                               const ArkWebString* name,
                                               const ArkWebString* origin,
                                               int32_t securityLevel);

  int32_t(ARK_WEB_CALLBACK* set_configuration_string)(
      struct _ark_drm_adapter_t* self,
      const ArkWebString* configName,
      const ArkWebString* value);

  int32_t(ARK_WEB_CALLBACK* get_configuration_string)(
      struct _ark_drm_adapter_t* self,
      const ArkWebString* configName,
      char* value,
      int32_t valueLen);

  int32_t(ARK_WEB_CALLBACK* set_configuration_byte_array)(
      struct _ark_drm_adapter_t* self,
      const ArkWebString* configName,
      const uint8_t* value,
      int32_t valueLen);

  int32_t(ARK_WEB_CALLBACK* get_configuration_byte_array)(
      struct _ark_drm_adapter_t* self,
      const ArkWebString* configName,
      uint8_t* value,
      int32_t* valueLen);

  int32_t(ARK_WEB_CALLBACK* get_max_content_protection_level)(
      struct _ark_drm_adapter_t* self,
      int32_t* level);

  int32_t(ARK_WEB_CALLBACK* process_key_system_response)(
      struct _ark_drm_adapter_t* self,
      const ArkWebString* response,
      bool isResponseReceived);

  int32_t(ARK_WEB_CALLBACK* get_certificate_status)(
      struct _ark_drm_adapter_t* self,
      int32_t* certStatus);

  int32_t(ARK_WEB_CALLBACK* regist_drm_callback)(
      struct _ark_drm_adapter_t* self,
      ark_drm_callback_adapter_t* callbackAdapter);

  int32_t(ARK_WEB_CALLBACK* update_session)(struct _ark_drm_adapter_t* self,
                                            uint32_t promiseId,
                                            const ArkWebString* sessionId,
                                            ArkWebUint8Vector response);

  int32_t(ARK_WEB_CALLBACK* close_session)(struct _ark_drm_adapter_t* self,
                                           uint32_t promiseId,
                                           const ArkWebString* sessionId);

  int32_t(ARK_WEB_CALLBACK* remove_session)(struct _ark_drm_adapter_t* self,
                                            uint32_t promiseId,
                                            const ArkWebString* sessionId);

  int32_t(ARK_WEB_CALLBACK* load_session)(struct _ark_drm_adapter_t* self,
                                          uint32_t promiseId,
                                          const ArkWebString* sessionId);

  int32_t(ARK_WEB_CALLBACK* clear_media_keys)(struct _ark_drm_adapter_t* self);

  int32_t(ARK_WEB_CALLBACK* get_security_level)(
      struct _ark_drm_adapter_t* self);

  int32_t(ARK_WEB_CALLBACK* require_secure_decoder_module)(
      struct _ark_drm_adapter_t* self,
      const ArkWebString* mimeType,
      bool* status);

  int32_t(ARK_WEB_CALLBACK* generate_media_key_request)(
      struct _ark_drm_adapter_t* self,
      const ArkWebString* sessionId,
      int32_t type,
      int32_t initDataLen,
      const ArkWebUint8Vector* initData,
      const ArkWebString* mimeType,
      uint32_t promiseId);
} ark_drm_adapter_t;

#ifdef __cplusplus
}
#endif

#endif  // ARK_DRM_ADAPTER_CAPI_H_
