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

#ifndef ARK_OHOS_DRAWING_TEXT_ADAPTER_CAPI_H_
#define ARK_OHOS_DRAWING_TEXT_ADAPTER_CAPI_H_
#pragma once

#include "base/capi/ark_web_base_ref_counted_capi.h"
#include "base/include/ark_web_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ark_ohos_drawing_text_font_adapter_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  int(ARK_WEB_CALLBACK* get_system_font_full_names_by_type)(
      struct _ark_ohos_drawing_text_font_adapter_t* self,
      int32_t systemFontType,
      void** drawingArray);

  int(ARK_WEB_CALLBACK* get_font_descriptor_by_full_name)(
      struct _ark_ohos_drawing_text_font_adapter_t* self,
      void* drawingString,
      int32_t systemFontType,
      void** drawingFontDescriptor);

  int(ARK_WEB_CALLBACK* get_system_font_full_name_by_index)(
      struct _ark_ohos_drawing_text_font_adapter_t* self,
      void* drawingArray,
      int32_t indexOfFullName,
      const void** drawingString);

  void(ARK_WEB_CALLBACK* destroy_system_font_full_names)(
      struct _ark_ohos_drawing_text_font_adapter_t* self,
      void* drawingArray);

  void(ARK_WEB_CALLBACK* destroy_font_descriptor)(
      struct _ark_ohos_drawing_text_font_adapter_t* self,
      void* descriptor);
} ark_ohos_drawing_text_font_adapter_t;

typedef struct _ark_ohos_drawing_text_typography_adapter_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  int(ARK_WEB_CALLBACK* get_system_font_config_info)(
      struct _ark_ohos_drawing_text_typography_adapter_t* self,
      void* fontConfigInfoErrorCode,
      void** fontConfigInfo);

  int(ARK_WEB_CALLBACK* get_drawing_array_size)(
      struct _ark_ohos_drawing_text_typography_adapter_t* self,
      void* drawingArray,
      int32_t* sizeOfArray);

  void(ARK_WEB_CALLBACK* destroy_system_font_config_info)(
      struct _ark_ohos_drawing_text_typography_adapter_t* self,
      void* fontConfigInfo);
} ark_ohos_drawing_text_typography_adapter_t;

#ifdef __cplusplus
}
#endif

#endif  // ARK_OHOS_DRAWING_TEXT_ADAPTER_CAPI_H_
