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

#ifndef ARK_SENSOR_ADAPTER_CAPI_H_
#define ARK_SENSOR_ADAPTER_CAPI_H_
#pragma once

#include "base/capi/ark_web_base_ref_counted_capi.h"
#include "base/include/ark_web_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ark_sensor_callback_adapter_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  void(ARK_WEB_CALLBACK* update_ohos_sensor_data)(
      struct _ark_sensor_callback_adapter_t* self,
      double timestamp,
      double value1,
      double value2,
      double value3,
      double value4);
} ark_sensor_callback_adapter_t;

typedef struct _ark_sensor_adapter_t {
  /**
   * @brief Base structure.
   */
  ark_web_base_ref_counted_t base;

  int32_t(ARK_WEB_CALLBACK* is_ohos_sensor_supported)(
      struct _ark_sensor_adapter_t* self,
      int32_t sensorTypeId);

  int32_t(ARK_WEB_CALLBACK* get_ohos_sensor_reporting_mode)(
      struct _ark_sensor_adapter_t* self,
      int32_t type);

  double(ARK_WEB_CALLBACK* get_ohos_sensor_default_supported_frequency)(
      struct _ark_sensor_adapter_t* self,
      int32_t sensorTypeId);

  double(ARK_WEB_CALLBACK* get_ohos_sensor_min_supported_frequency)(
      struct _ark_sensor_adapter_t* self,
      int32_t sensorTypeId);

  double(ARK_WEB_CALLBACK* get_ohos_sensor_max_supported_frequency)(
      struct _ark_sensor_adapter_t* self,
      int32_t sensorTypeId);

  int32_t(ARK_WEB_CALLBACK* subscribe_ohos_sensor)(
      struct _ark_sensor_adapter_t* self,
      int32_t sensorTypeId,
      int64_t samplingInterval);

  int32_t(ARK_WEB_CALLBACK* regist_ohos_sensor_callback)(
      struct _ark_sensor_adapter_t* self,
      int32_t sensorTypeId,
      ark_sensor_callback_adapter_t* callbackAdapter);

  int32_t(ARK_WEB_CALLBACK* unsubscribe_ohos_sensor)(
      struct _ark_sensor_adapter_t* self,
      int32_t sensorTypeId);
} ark_sensor_adapter_t;

#ifdef __cplusplus
}
#endif

#endif  // ARK_SENSOR_ADAPTER_CAPI_H_
