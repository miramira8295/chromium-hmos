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

#ifndef ARK_OHOS_NATIVE_BUFFER_ADAPTER_CAPI_H_
#define ARK_OHOS_NATIVE_BUFFER_ADAPTER_CAPI_H_
#pragma once

#include "base/capi/ark_web_base_ref_counted_capi.h"
#include "base/include/ark_web_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ark_native_buffer_config_adapter_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  int(ARK_WEB_CALLBACK* get_buffer_width)(
      struct _ark_native_buffer_config_adapter_t* self);

  int(ARK_WEB_CALLBACK* get_buffer_height)(
      struct _ark_native_buffer_config_adapter_t* self);

  int(ARK_WEB_CALLBACK* get_buffer_format)(
      struct _ark_native_buffer_config_adapter_t* self);

  int(ARK_WEB_CALLBACK* get_buffer_usage)(
      struct _ark_native_buffer_config_adapter_t* self);

  int(ARK_WEB_CALLBACK* get_buffer_stride)(
      struct _ark_native_buffer_config_adapter_t* self);

  void(ARK_WEB_CALLBACK* set_buffer_width)(
      struct _ark_native_buffer_config_adapter_t* self,
      int width);

  void(ARK_WEB_CALLBACK* set_buffer_height)(
      struct _ark_native_buffer_config_adapter_t* self,
      int height);

  void(ARK_WEB_CALLBACK* set_buffer_format)(
      struct _ark_native_buffer_config_adapter_t* self,
      int format);

  void(ARK_WEB_CALLBACK* set_buffer_usage)(
      struct _ark_native_buffer_config_adapter_t* self,
      int usage);

  void(ARK_WEB_CALLBACK* set_buffer_stride)(
      struct _ark_native_buffer_config_adapter_t* self,
      int stride);
} ark_native_buffer_config_adapter_t;

typedef struct _ark_ohos_native_buffer_adapter_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  void(ARK_WEB_CALLBACK* acquire_buffer)(
      struct _ark_ohos_native_buffer_adapter_t* self,
      void* buffer);

  void(ARK_WEB_CALLBACK* release)(
      struct _ark_ohos_native_buffer_adapter_t* self,
      void* buffer);

  int(ARK_WEB_CALLBACK* get_eglbuffer)(
      struct _ark_ohos_native_buffer_adapter_t* self,
      void* buffer,
      void** eglBuffer);

  int(ARK_WEB_CALLBACK* free_eglbuffer)(
      struct _ark_ohos_native_buffer_adapter_t* self,
      void* eglBuffer);

  int(ARK_WEB_CALLBACK* native_buffer_from_native_window_buffer)(
      struct _ark_ohos_native_buffer_adapter_t* self,
      void* nativeWindowBuffer,
      void** nativeBuffer);

  uint32_t(ARK_WEB_CALLBACK* get_seq_num)(
      struct _ark_ohos_native_buffer_adapter_t* self,
      void* nativeBuffer);

  void(ARK_WEB_CALLBACK* allocate)(
      struct _ark_ohos_native_buffer_adapter_t* self,
      ark_native_buffer_config_adapter_t* bufferConfig,
      void** outBuffer);

  void(ARK_WEB_CALLBACK* describe)(
      struct _ark_ohos_native_buffer_adapter_t* self,
      ark_native_buffer_config_adapter_t* bufferConfig,
      void* buffer);

  int(ARK_WEB_CALLBACK* lock)(struct _ark_ohos_native_buffer_adapter_t* self,
                              void* buffer,
                              uint64_t usage,
                              int32_t fence,
                              void** out_virtual_address);

  int(ARK_WEB_CALLBACK* recv_handle_from_unix_socket)(
      struct _ark_ohos_native_buffer_adapter_t* self,
      int socketFd,
      void** outBuffer);

  int(ARK_WEB_CALLBACK* send_handle_to_unix_socket)(
      struct _ark_ohos_native_buffer_adapter_t* self,
      const void* buffer,
      int socketFd);

  int(ARK_WEB_CALLBACK* unlock)(struct _ark_ohos_native_buffer_adapter_t* self,
                                void* buffer,
                                int32_t* fence);

  int(ARK_WEB_CALLBACK* free_native_buffer)(
      struct _ark_ohos_native_buffer_adapter_t* self,
      void* nativeBuffer);
} ark_ohos_native_buffer_adapter_t;

#ifdef __cplusplus
}
#endif

#endif  // ARK_OHOS_NATIVE_BUFFER_ADAPTER_CAPI_H_
