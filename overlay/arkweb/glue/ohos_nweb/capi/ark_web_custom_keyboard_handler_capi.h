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

#ifndef ARK_WEB_CUSTOM_KEYBOARD_HANDLER_CAPI_H_
#define ARK_WEB_CUSTOM_KEYBOARD_HANDLER_CAPI_H_
#pragma once

#include "base/capi/ark_web_base_ref_counted_capi.h"
#include "base/include/ark_web_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ark_web_custom_keyboard_handler_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  void(ARK_WEB_CALLBACK* insert_text)(
      struct _ark_web_custom_keyboard_handler_t* self,
      const ArkWebString* text);

  void(ARK_WEB_CALLBACK* delete_forward)(
      struct _ark_web_custom_keyboard_handler_t* self,
      int32_t length);

  void(ARK_WEB_CALLBACK* delete_backward)(
      struct _ark_web_custom_keyboard_handler_t* self,
      int32_t length);

  void(ARK_WEB_CALLBACK* send_function_key)(
      struct _ark_web_custom_keyboard_handler_t* self,
      int32_t key);

  void(ARK_WEB_CALLBACK* close)(
      struct _ark_web_custom_keyboard_handler_t* self);
} ark_web_custom_keyboard_handler_t;

#ifdef __cplusplus
}
#endif

#endif  // ARK_WEB_CUSTOM_KEYBOARD_HANDLER_CAPI_H_
