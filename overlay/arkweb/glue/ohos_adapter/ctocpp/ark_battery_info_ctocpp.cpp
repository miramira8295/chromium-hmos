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

#include "ohos_adapter/ctocpp/ark_battery_info_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkBatteryInfoGetLevelFunc = double (*)(struct _ark_battery_info_t* self);
static ArkBatteryInfoGetLevelFunc ark_battery_info_get_level =
    reinterpret_cast<ArkBatteryInfoGetLevelFunc>(ARK_WEB_INIT_ADDR);

using ArkBatteryInfoIsChargingFunc = bool (*)(struct _ark_battery_info_t* self);
static ArkBatteryInfoIsChargingFunc ark_battery_info_is_charging =
    reinterpret_cast<ArkBatteryInfoIsChargingFunc>(ARK_WEB_INIT_ADDR);

using ArkBatteryInfoDisChargingTimeFunc =
    int (*)(struct _ark_battery_info_t* self);
static ArkBatteryInfoDisChargingTimeFunc ark_battery_info_dis_charging_time =
    reinterpret_cast<ArkBatteryInfoDisChargingTimeFunc>(ARK_WEB_INIT_ADDR);

using ArkBatteryInfoChargingTimeFunc =
    int (*)(struct _ark_battery_info_t* self);
static ArkBatteryInfoChargingTimeFunc ark_battery_info_charging_time =
    reinterpret_cast<ArkBatteryInfoChargingTimeFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
double ArkBatteryInfoCToCpp::GetLevel() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_battery_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_battery_info_get_level);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "lA5DJGsrxrEeR8piWAQkog";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_BATTERY_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_battery_info_get_level");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_level)) {
        ark_battery_info_get_level = nullptr;
      } else {
        ark_battery_info_get_level = _struct->get_level;
      }
    } else {
      ark_battery_info_get_level =
          reinterpret_cast<ArkBatteryInfoGetLevelFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_battery_info_get_level, 0);

  // Execute
  return ark_battery_info_get_level(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkBatteryInfoCToCpp::IsCharging() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_battery_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(ark_battery_info_is_charging);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "I9B8u7$EVAT6AxRWZTNnbg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_BATTERY_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_battery_info_is_charging");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_charging)) {
        ark_battery_info_is_charging = nullptr;
      } else {
        ark_battery_info_is_charging = _struct->is_charging;
      }
    } else {
      ark_battery_info_is_charging =
          reinterpret_cast<ArkBatteryInfoIsChargingFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_battery_info_is_charging, false);

  // Execute
  return ark_battery_info_is_charging(_struct);
}

ARK_WEB_NO_SANITIZE
int ArkBatteryInfoCToCpp::DisChargingTime() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_battery_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_battery_info_dis_charging_time);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "YwG9uCaIdB356Ws9eVkeSw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_BATTERY_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_battery_info_dis_charging_time");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, dis_charging_time)) {
        ark_battery_info_dis_charging_time = nullptr;
      } else {
        ark_battery_info_dis_charging_time = _struct->dis_charging_time;
      }
    } else {
      ark_battery_info_dis_charging_time =
          reinterpret_cast<ArkBatteryInfoDisChargingTimeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_battery_info_dis_charging_time, 0);

  // Execute
  return ark_battery_info_dis_charging_time(_struct);
}

ARK_WEB_NO_SANITIZE
int ArkBatteryInfoCToCpp::ChargingTime() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_battery_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_battery_info_charging_time);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "mdhHmfEKuGld9El0bbwsGw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_BATTERY_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_battery_info_charging_time");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, charging_time)) {
        ark_battery_info_charging_time = nullptr;
      } else {
        ark_battery_info_charging_time = _struct->charging_time;
      }
    } else {
      ark_battery_info_charging_time =
          reinterpret_cast<ArkBatteryInfoChargingTimeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_battery_info_charging_time, 0);

  // Execute
  return ark_battery_info_charging_time(_struct);
}

ArkBatteryInfoCToCpp::ArkBatteryInfoCToCpp() {}

ArkBatteryInfoCToCpp::~ArkBatteryInfoCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkBatteryInfoCToCpp,
                                        ArkBatteryInfo,
                                        ark_battery_info_t>::kBridgeType =
    ARK_BATTERY_INFO;

}  // namespace OHOS::ArkWeb
