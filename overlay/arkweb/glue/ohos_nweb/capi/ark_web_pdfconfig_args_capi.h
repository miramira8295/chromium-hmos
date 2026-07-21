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

#ifndef ARK_WEB_PDFCONFIG_ARGS_CAPI_H_
#define ARK_WEB_PDFCONFIG_ARGS_CAPI_H_
#pragma once

#include "base/capi/ark_web_base_ref_counted_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ark_web_pdfconfig_args_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  double(ARK_WEB_CALLBACK* get_width)(struct _ark_web_pdfconfig_args_t* self);

  double(ARK_WEB_CALLBACK* get_height)(struct _ark_web_pdfconfig_args_t* self);

  double(ARK_WEB_CALLBACK* get_scale)(struct _ark_web_pdfconfig_args_t* self);

  double(ARK_WEB_CALLBACK* get_margin_top)(
      struct _ark_web_pdfconfig_args_t* self);

  double(ARK_WEB_CALLBACK* get_margin_bottom)(
      struct _ark_web_pdfconfig_args_t* self);

  double(ARK_WEB_CALLBACK* get_margin_right)(
      struct _ark_web_pdfconfig_args_t* self);

  double(ARK_WEB_CALLBACK* get_margin_left)(
      struct _ark_web_pdfconfig_args_t* self);

  bool(ARK_WEB_CALLBACK* get_should_print_background)(
      struct _ark_web_pdfconfig_args_t* self);
} ark_web_pdfconfig_args_t;

#ifdef __cplusplus
}
#endif

#endif  // ARK_WEB_PDFCONFIG_ARGS_CAPI_H_
