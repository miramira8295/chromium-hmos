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

#include "ohos_adapter/ctocpp/ark_location_request_config_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkLocationRequestConfigSetScenarioFunc =
    void (*)(struct _ark_location_request_config_t* self, int32_t scenario);
static ArkLocationRequestConfigSetScenarioFunc
    ark_location_request_config_set_scenario =
        reinterpret_cast<ArkLocationRequestConfigSetScenarioFunc>(
            ARK_WEB_INIT_ADDR);

using ArkLocationRequestConfigSetFixNumberFunc =
    void (*)(struct _ark_location_request_config_t* self, int32_t number);
static ArkLocationRequestConfigSetFixNumberFunc
    ark_location_request_config_set_fix_number =
        reinterpret_cast<ArkLocationRequestConfigSetFixNumberFunc>(
            ARK_WEB_INIT_ADDR);

using ArkLocationRequestConfigSetMaxAccuracyFunc =
    void (*)(struct _ark_location_request_config_t* self, int32_t maxAccuary);
static ArkLocationRequestConfigSetMaxAccuracyFunc
    ark_location_request_config_set_max_accuracy =
        reinterpret_cast<ArkLocationRequestConfigSetMaxAccuracyFunc>(
            ARK_WEB_INIT_ADDR);

using ArkLocationRequestConfigSetDistanceIntervalFunc =
    void (*)(struct _ark_location_request_config_t* self, int32_t disInterval);
static ArkLocationRequestConfigSetDistanceIntervalFunc
    ark_location_request_config_set_distance_interval =
        reinterpret_cast<ArkLocationRequestConfigSetDistanceIntervalFunc>(
            ARK_WEB_INIT_ADDR);

using ArkLocationRequestConfigSetTimeIntervalFunc =
    void (*)(struct _ark_location_request_config_t* self, int32_t timeInterval);
static ArkLocationRequestConfigSetTimeIntervalFunc
    ark_location_request_config_set_time_interval =
        reinterpret_cast<ArkLocationRequestConfigSetTimeIntervalFunc>(
            ARK_WEB_INIT_ADDR);

using ArkLocationRequestConfigSetPriorityFunc =
    void (*)(struct _ark_location_request_config_t* self, int32_t priority);
static ArkLocationRequestConfigSetPriorityFunc
    ark_location_request_config_set_priority =
        reinterpret_cast<ArkLocationRequestConfigSetPriorityFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkLocationRequestConfigCToCpp::SetScenario(int32_t scenario) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_request_config_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_location_request_config_set_scenario);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "4KIJ4BL8nLf11m$i11AitA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_LOCATION_REQUEST_CONFIG, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_location_request_config_set_scenario");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_scenario)) {
        ark_location_request_config_set_scenario = nullptr;
      } else {
        ark_location_request_config_set_scenario = _struct->set_scenario;
      }
    } else {
      ark_location_request_config_set_scenario =
          reinterpret_cast<ArkLocationRequestConfigSetScenarioFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_location_request_config_set_scenario,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_location_request_config_set_scenario(_struct, scenario);
}

ARK_WEB_NO_SANITIZE
void ArkLocationRequestConfigCToCpp::SetFixNumber(int32_t number) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_request_config_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_location_request_config_set_fix_number);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "WykGOqb_wNdgAQTHyuHVIw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_LOCATION_REQUEST_CONFIG, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_location_request_config_set_fix_number");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_fix_number)) {
        ark_location_request_config_set_fix_number = nullptr;
      } else {
        ark_location_request_config_set_fix_number = _struct->set_fix_number;
      }
    } else {
      ark_location_request_config_set_fix_number =
          reinterpret_cast<ArkLocationRequestConfigSetFixNumberFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_location_request_config_set_fix_number,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_location_request_config_set_fix_number(_struct, number);
}

ARK_WEB_NO_SANITIZE
void ArkLocationRequestConfigCToCpp::SetMaxAccuracy(int32_t maxAccuary) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_request_config_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_location_request_config_set_max_accuracy);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "hDJaTdHYwQy_Aps_VYrw3w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_LOCATION_REQUEST_CONFIG, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_location_request_config_set_max_accuracy");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_max_accuracy)) {
        ark_location_request_config_set_max_accuracy = nullptr;
      } else {
        ark_location_request_config_set_max_accuracy =
            _struct->set_max_accuracy;
      }
    } else {
      ark_location_request_config_set_max_accuracy =
          reinterpret_cast<ArkLocationRequestConfigSetMaxAccuracyFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_location_request_config_set_max_accuracy, ARK_WEB_RETURN_VOID);

  // Execute
  ark_location_request_config_set_max_accuracy(_struct, maxAccuary);
}

ARK_WEB_NO_SANITIZE
void ArkLocationRequestConfigCToCpp::SetDistanceInterval(int32_t disInterval) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_request_config_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_location_request_config_set_distance_interval);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "mLx6jG9x5DOtRuDFG5RZ7A";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_LOCATION_REQUEST_CONFIG, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_location_request_config_set_distance_interval");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_distance_interval)) {
        ark_location_request_config_set_distance_interval = nullptr;
      } else {
        ark_location_request_config_set_distance_interval =
            _struct->set_distance_interval;
      }
    } else {
      ark_location_request_config_set_distance_interval =
          reinterpret_cast<ArkLocationRequestConfigSetDistanceIntervalFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_location_request_config_set_distance_interval, ARK_WEB_RETURN_VOID);

  // Execute
  ark_location_request_config_set_distance_interval(_struct, disInterval);
}

ARK_WEB_NO_SANITIZE
void ArkLocationRequestConfigCToCpp::SetTimeInterval(int32_t timeInterval) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_request_config_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_location_request_config_set_time_interval);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "0YmkfoaM115ZwZ0dT4Lr2w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_LOCATION_REQUEST_CONFIG, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_location_request_config_set_time_interval");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_time_interval)) {
        ark_location_request_config_set_time_interval = nullptr;
      } else {
        ark_location_request_config_set_time_interval =
            _struct->set_time_interval;
      }
    } else {
      ark_location_request_config_set_time_interval =
          reinterpret_cast<ArkLocationRequestConfigSetTimeIntervalFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_location_request_config_set_time_interval, ARK_WEB_RETURN_VOID);

  // Execute
  ark_location_request_config_set_time_interval(_struct, timeInterval);
}

ARK_WEB_NO_SANITIZE
void ArkLocationRequestConfigCToCpp::SetPriority(int32_t priority) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_request_config_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_location_request_config_set_priority);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "7tUz9bgoEoNkVAcRQvKJEA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_LOCATION_REQUEST_CONFIG, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_location_request_config_set_priority");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_priority)) {
        ark_location_request_config_set_priority = nullptr;
      } else {
        ark_location_request_config_set_priority = _struct->set_priority;
      }
    } else {
      ark_location_request_config_set_priority =
          reinterpret_cast<ArkLocationRequestConfigSetPriorityFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_location_request_config_set_priority,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_location_request_config_set_priority(_struct, priority);
}

ArkLocationRequestConfigCToCpp::ArkLocationRequestConfigCToCpp() {}

ArkLocationRequestConfigCToCpp::~ArkLocationRequestConfigCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkLocationRequestConfigCToCpp,
                           ArkLocationRequestConfig,
                           ark_location_request_config_t>::kBridgeType =
        ARK_LOCATION_REQUEST_CONFIG;

}  // namespace OHOS::ArkWeb
