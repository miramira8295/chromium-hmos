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

#ifndef ARK_WEB_NATIVE_EMBED_PARAM_DATA_INFO_CAPI_H_
#define ARK_WEB_NATIVE_EMBED_PARAM_DATA_INFO_CAPI_H_
#pragma once

#include "base/capi/ark_web_base_ref_counted_capi.h"
#include "ohos_nweb/capi/ark_web_native_embed_param_item_capi.h"
#include "ohos_nweb/include/ark_web_native_embed_param_item_vector.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ark_web_native_embed_param_data_info_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  ArkWebString(ARK_WEB_CALLBACK* get_embed_id)(
      struct _ark_web_native_embed_param_data_info_t* self);

  ArkWebString(ARK_WEB_CALLBACK* get_object_attribute_id)(
      struct _ark_web_native_embed_param_data_info_t* self);

  ArkWebNativeEmbedParamItemVector(ARK_WEB_CALLBACK* get_param_items)(
      struct _ark_web_native_embed_param_data_info_t* self);
} ark_web_native_embed_param_data_info_t;

#ifdef __cplusplus
}
#endif

#endif  // ARK_WEB_NATIVE_EMBED_PARAM_DATA_INFO_CAPI_H_
