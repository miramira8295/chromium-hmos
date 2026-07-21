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

#include "ohos_adapter/ctocpp/ark_location_info_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkLocationInfoGetLatitudeFunc =
    double (*)(struct _ark_location_info_t* self);
static ArkLocationInfoGetLatitudeFunc ark_location_info_get_latitude =
    reinterpret_cast<ArkLocationInfoGetLatitudeFunc>(ARK_WEB_INIT_ADDR);

using ArkLocationInfoGetLongitudeFunc =
    double (*)(struct _ark_location_info_t* self);
static ArkLocationInfoGetLongitudeFunc ark_location_info_get_longitude =
    reinterpret_cast<ArkLocationInfoGetLongitudeFunc>(ARK_WEB_INIT_ADDR);

using ArkLocationInfoGetAltitudeFunc =
    double (*)(struct _ark_location_info_t* self);
static ArkLocationInfoGetAltitudeFunc ark_location_info_get_altitude =
    reinterpret_cast<ArkLocationInfoGetAltitudeFunc>(ARK_WEB_INIT_ADDR);

using ArkLocationInfoGetAccuracyFunc =
    float (*)(struct _ark_location_info_t* self);
static ArkLocationInfoGetAccuracyFunc ark_location_info_get_accuracy =
    reinterpret_cast<ArkLocationInfoGetAccuracyFunc>(ARK_WEB_INIT_ADDR);

using ArkLocationInfoGetSpeedFunc =
    float (*)(struct _ark_location_info_t* self);
static ArkLocationInfoGetSpeedFunc ark_location_info_get_speed =
    reinterpret_cast<ArkLocationInfoGetSpeedFunc>(ARK_WEB_INIT_ADDR);

using ArkLocationInfoGetDirectionFunc =
    double (*)(struct _ark_location_info_t* self);
static ArkLocationInfoGetDirectionFunc ark_location_info_get_direction =
    reinterpret_cast<ArkLocationInfoGetDirectionFunc>(ARK_WEB_INIT_ADDR);

using ArkLocationInfoGetTimeStampFunc =
    int64_t (*)(struct _ark_location_info_t* self);
static ArkLocationInfoGetTimeStampFunc ark_location_info_get_time_stamp =
    reinterpret_cast<ArkLocationInfoGetTimeStampFunc>(ARK_WEB_INIT_ADDR);

using ArkLocationInfoGetTimeSinceBootFunc =
    int64_t (*)(struct _ark_location_info_t* self);
static ArkLocationInfoGetTimeSinceBootFunc
    ark_location_info_get_time_since_boot =
        reinterpret_cast<ArkLocationInfoGetTimeSinceBootFunc>(
            ARK_WEB_INIT_ADDR);

using ArkLocationInfoGetAdditionsFunc =
    ArkWebStringVector (*)(struct _ark_location_info_t* self);
static ArkLocationInfoGetAdditionsFunc ark_location_info_get_additions =
    reinterpret_cast<ArkLocationInfoGetAdditionsFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
double ArkLocationInfoCToCpp::GetLatitude() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_location_info_get_latitude);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "H4XG_D8F5XR1mlsIVHrFtA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_LOCATION_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_location_info_get_latitude");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_latitude)) {
        ark_location_info_get_latitude = nullptr;
      } else {
        ark_location_info_get_latitude = _struct->get_latitude;
      }
    } else {
      ark_location_info_get_latitude =
          reinterpret_cast<ArkLocationInfoGetLatitudeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_location_info_get_latitude, 0);

  // Execute
  return ark_location_info_get_latitude(_struct);
}

ARK_WEB_NO_SANITIZE
double ArkLocationInfoCToCpp::GetLongitude() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_location_info_get_longitude);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "mFOL2WKC52CDqPhBkde87A";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_LOCATION_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_location_info_get_longitude");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_longitude)) {
        ark_location_info_get_longitude = nullptr;
      } else {
        ark_location_info_get_longitude = _struct->get_longitude;
      }
    } else {
      ark_location_info_get_longitude =
          reinterpret_cast<ArkLocationInfoGetLongitudeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_location_info_get_longitude, 0);

  // Execute
  return ark_location_info_get_longitude(_struct);
}

ARK_WEB_NO_SANITIZE
double ArkLocationInfoCToCpp::GetAltitude() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_location_info_get_altitude);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "zhMJxktVLnEvdCrq2dDtZg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_LOCATION_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_location_info_get_altitude");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_altitude)) {
        ark_location_info_get_altitude = nullptr;
      } else {
        ark_location_info_get_altitude = _struct->get_altitude;
      }
    } else {
      ark_location_info_get_altitude =
          reinterpret_cast<ArkLocationInfoGetAltitudeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_location_info_get_altitude, 0);

  // Execute
  return ark_location_info_get_altitude(_struct);
}

ARK_WEB_NO_SANITIZE
float ArkLocationInfoCToCpp::GetAccuracy() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_location_info_get_accuracy);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "MA0D6lKok0xudr0rvhjY_A";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_LOCATION_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_location_info_get_accuracy");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_accuracy)) {
        ark_location_info_get_accuracy = nullptr;
      } else {
        ark_location_info_get_accuracy = _struct->get_accuracy;
      }
    } else {
      ark_location_info_get_accuracy =
          reinterpret_cast<ArkLocationInfoGetAccuracyFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_location_info_get_accuracy, 0);

  // Execute
  return ark_location_info_get_accuracy(_struct);
}

ARK_WEB_NO_SANITIZE
float ArkLocationInfoCToCpp::GetSpeed() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_location_info_get_speed);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jfb65jt7c6BrEeG885GxLQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_LOCATION_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_location_info_get_speed");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_speed)) {
        ark_location_info_get_speed = nullptr;
      } else {
        ark_location_info_get_speed = _struct->get_speed;
      }
    } else {
      ark_location_info_get_speed =
          reinterpret_cast<ArkLocationInfoGetSpeedFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_location_info_get_speed, 0);

  // Execute
  return ark_location_info_get_speed(_struct);
}

ARK_WEB_NO_SANITIZE
double ArkLocationInfoCToCpp::GetDirection() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_location_info_get_direction);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "P6VLGrx9G3Wx0gyNGUQg9g";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_LOCATION_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_location_info_get_direction");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_direction)) {
        ark_location_info_get_direction = nullptr;
      } else {
        ark_location_info_get_direction = _struct->get_direction;
      }
    } else {
      ark_location_info_get_direction =
          reinterpret_cast<ArkLocationInfoGetDirectionFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_location_info_get_direction, 0);

  // Execute
  return ark_location_info_get_direction(_struct);
}

ARK_WEB_NO_SANITIZE
int64_t ArkLocationInfoCToCpp::GetTimeStamp() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_location_info_get_time_stamp);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "CO5yApEdORfAy$2XXX$ncw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_LOCATION_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_location_info_get_time_stamp");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_time_stamp)) {
        ark_location_info_get_time_stamp = nullptr;
      } else {
        ark_location_info_get_time_stamp = _struct->get_time_stamp;
      }
    } else {
      ark_location_info_get_time_stamp =
          reinterpret_cast<ArkLocationInfoGetTimeStampFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_location_info_get_time_stamp, 0);

  // Execute
  return ark_location_info_get_time_stamp(_struct);
}

ARK_WEB_NO_SANITIZE
int64_t ArkLocationInfoCToCpp::GetTimeSinceBoot() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_location_info_get_time_since_boot);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ypZq$7RHOP2kC$jVf8v5Hw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_LOCATION_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_location_info_get_time_since_boot");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_time_since_boot)) {
        ark_location_info_get_time_since_boot = nullptr;
      } else {
        ark_location_info_get_time_since_boot = _struct->get_time_since_boot;
      }
    } else {
      ark_location_info_get_time_since_boot =
          reinterpret_cast<ArkLocationInfoGetTimeSinceBootFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_location_info_get_time_since_boot, 0);

  // Execute
  return ark_location_info_get_time_since_boot(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebStringVector ArkLocationInfoCToCpp::GetAdditions() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_vector_default);

  void* func_pointer = reinterpret_cast<void*>(ark_location_info_get_additions);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "e5WsPVN2Kn5aaPmDY$6Nrg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_LOCATION_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_location_info_get_additions");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_additions)) {
        ark_location_info_get_additions = nullptr;
      } else {
        ark_location_info_get_additions = _struct->get_additions;
      }
    } else {
      ark_location_info_get_additions =
          reinterpret_cast<ArkLocationInfoGetAdditionsFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_location_info_get_additions,
                                    ark_web_string_vector_default);

  // Execute
  return ark_location_info_get_additions(_struct);
}

ArkLocationInfoCToCpp::ArkLocationInfoCToCpp() {}

ArkLocationInfoCToCpp::~ArkLocationInfoCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkLocationInfoCToCpp,
                                        ArkLocationInfo,
                                        ark_location_info_t>::kBridgeType =
    ARK_LOCATION_INFO;

}  // namespace OHOS::ArkWeb
