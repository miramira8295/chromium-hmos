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

#ifndef ARK_MIGRATION_MANAGER_ADAPTER_CAPI_H_
#define ARK_MIGRATION_MANAGER_ADAPTER_CAPI_H_
#pragma once

#include "base/capi/ark_web_base_ref_counted_capi.h"
#include "base/include/ark_web_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ark_migration_listener_adapter_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  void(ARK_WEB_CALLBACK* on_migration_reply)(
      struct _ark_migration_listener_adapter_t* self,
      int32_t errorCode,
      int32_t succussCount,
      const ArkWebInt32Vector* errorIndex,
      const ArkWebInt32Vector* codeIndex);
} ark_migration_listener_adapter_t;

typedef struct _ark_migration_manager_adapter_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  void(ARK_WEB_CALLBACK* set_migration_param)(
      struct _ark_migration_manager_adapter_t* self,
      const ArkWebString* bundleName,
      const ArkWebString* abilityName,
      const ArkWebString* token);

  bool(ARK_WEB_CALLBACK* send_migration_request)(
      struct _ark_migration_manager_adapter_t* self,
      const char* jsonData);

  uint32_t(ARK_WEB_CALLBACK* register_migration_listener)(
      struct _ark_migration_manager_adapter_t* self,
      ark_migration_listener_adapter_t* listener);
} ark_migration_manager_adapter_t;

#ifdef __cplusplus
}
#endif

#endif  // ARK_MIGRATION_MANAGER_ADAPTER_CAPI_H_
