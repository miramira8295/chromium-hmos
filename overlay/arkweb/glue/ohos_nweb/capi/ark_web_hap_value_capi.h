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

#ifndef ARK_WEB_HAP_VALUE_CAPI_H_
#define ARK_WEB_HAP_VALUE_CAPI_H_
#pragma once

#include "base/capi/ark_web_base_ref_counted_capi.h"
#include "ohos_nweb/include/ark_web_hap_value_vector.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ark_web_hap_value_t ark_web_hap_value_t;

typedef struct _ark_web_hap_value_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  unsigned char(ARK_WEB_CALLBACK* get_type)(struct _ark_web_hap_value_t* self);

  void(ARK_WEB_CALLBACK* set_type)(struct _ark_web_hap_value_t* self,
                                   unsigned char type);

  int(ARK_WEB_CALLBACK* get_int)(struct _ark_web_hap_value_t* self);

  void(ARK_WEB_CALLBACK* set_int)(struct _ark_web_hap_value_t* self, int value);

  bool(ARK_WEB_CALLBACK* get_bool)(struct _ark_web_hap_value_t* self);

  void(ARK_WEB_CALLBACK* set_bool)(struct _ark_web_hap_value_t* self,
                                   bool value);

  double(ARK_WEB_CALLBACK* get_double)(struct _ark_web_hap_value_t* self);

  void(ARK_WEB_CALLBACK* set_double)(struct _ark_web_hap_value_t* self,
                                     double value);

  ArkWebString(ARK_WEB_CALLBACK* get_string)(struct _ark_web_hap_value_t* self);

  void(ARK_WEB_CALLBACK* set_string)(struct _ark_web_hap_value_t* self,
                                     const ArkWebString* value);

  const char*(ARK_WEB_CALLBACK* get_binary1)(struct _ark_web_hap_value_t* self,
                                             int* length);

  void(ARK_WEB_CALLBACK* set_binary1)(struct _ark_web_hap_value_t* self,
                                      int length,
                                      const char* value);

  ArkWebHapValueMap(ARK_WEB_CALLBACK* get_dict_value)(
      struct _ark_web_hap_value_t* self);

  ArkWebHapValueVector(ARK_WEB_CALLBACK* get_list_value)(
      struct _ark_web_hap_value_t* self);

  ark_web_hap_value_t*(ARK_WEB_CALLBACK* new_child_value)(
      struct _ark_web_hap_value_t* self);

  void(ARK_WEB_CALLBACK* save_dict_child_value)(
      struct _ark_web_hap_value_t* self,
      const ArkWebString* key);

  void(ARK_WEB_CALLBACK* save_list_child_value)(
      struct _ark_web_hap_value_t* self);

  int64_t(ARK_WEB_CALLBACK* get_int64)(struct _ark_web_hap_value_t* self);

  void(ARK_WEB_CALLBACK* set_int64)(struct _ark_web_hap_value_t* self,
                                    int64_t value);

  ArkWebUint8Vector(ARK_WEB_CALLBACK* get_binary2)(
      struct _ark_web_hap_value_t* self);

  void(ARK_WEB_CALLBACK* set_binary2)(struct _ark_web_hap_value_t* self,
                                      const ArkWebUint8Vector* value);

  ArkWebBooleanVector(ARK_WEB_CALLBACK* get_bool_array)(
      struct _ark_web_hap_value_t* self);

  void(ARK_WEB_CALLBACK* set_bool_array)(struct _ark_web_hap_value_t* self,
                                         const ArkWebBooleanVector* value);

  ArkWebInt64Vector(ARK_WEB_CALLBACK* get_int64array)(
      struct _ark_web_hap_value_t* self);

  void(ARK_WEB_CALLBACK* set_int64array)(struct _ark_web_hap_value_t* self,
                                         const ArkWebInt64Vector* value);

  ArkWebDoubleVector(ARK_WEB_CALLBACK* get_double_array)(
      struct _ark_web_hap_value_t* self);

  void(ARK_WEB_CALLBACK* set_double_array)(struct _ark_web_hap_value_t* self,
                                           const ArkWebDoubleVector* value);

  ArkWebStringVector(ARK_WEB_CALLBACK* get_string_array)(
      struct _ark_web_hap_value_t* self);

  void(ARK_WEB_CALLBACK* set_string_array)(struct _ark_web_hap_value_t* self,
                                           const ArkWebStringVector* value);

  ArkWebString(ARK_WEB_CALLBACK* get_err_msg)(
      struct _ark_web_hap_value_t* self);

  void(ARK_WEB_CALLBACK* set_err_msg)(struct _ark_web_hap_value_t* self,
                                      const ArkWebString* msg);

  ArkWebString(ARK_WEB_CALLBACK* get_err_name)(
      struct _ark_web_hap_value_t* self);

  void(ARK_WEB_CALLBACK* set_err_name)(struct _ark_web_hap_value_t* self,
                                       const ArkWebString* name);
} ark_web_hap_value_t;

#ifdef __cplusplus
}
#endif

#endif  // ARK_WEB_HAP_VALUE_CAPI_H_
