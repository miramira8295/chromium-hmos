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

#include "ohos_adapter/ctocpp/ark_sensor_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_sensor_callback_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkSensorAdapterIsOhosSensorSupportedFunc =
    int32_t (*)(struct _ark_sensor_adapter_t* self, int32_t sensorTypeId);
static ArkSensorAdapterIsOhosSensorSupportedFunc
    ark_sensor_adapter_is_ohos_sensor_supported =
        reinterpret_cast<ArkSensorAdapterIsOhosSensorSupportedFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSensorAdapterGetOhosSensorReportingModeFunc =
    int32_t (*)(struct _ark_sensor_adapter_t* self, int32_t type);
static ArkSensorAdapterGetOhosSensorReportingModeFunc
    ark_sensor_adapter_get_ohos_sensor_reporting_mode =
        reinterpret_cast<ArkSensorAdapterGetOhosSensorReportingModeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSensorAdapterGetOhosSensorDefaultSupportedFrequencyFunc =
    double (*)(struct _ark_sensor_adapter_t* self, int32_t sensorTypeId);
static ArkSensorAdapterGetOhosSensorDefaultSupportedFrequencyFunc
    ark_sensor_adapter_get_ohos_sensor_default_supported_frequency =
        reinterpret_cast<
            ArkSensorAdapterGetOhosSensorDefaultSupportedFrequencyFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSensorAdapterGetOhosSensorMinSupportedFrequencyFunc =
    double (*)(struct _ark_sensor_adapter_t* self, int32_t sensorTypeId);
static ArkSensorAdapterGetOhosSensorMinSupportedFrequencyFunc
    ark_sensor_adapter_get_ohos_sensor_min_supported_frequency =
        reinterpret_cast<
            ArkSensorAdapterGetOhosSensorMinSupportedFrequencyFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSensorAdapterGetOhosSensorMaxSupportedFrequencyFunc =
    double (*)(struct _ark_sensor_adapter_t* self, int32_t sensorTypeId);
static ArkSensorAdapterGetOhosSensorMaxSupportedFrequencyFunc
    ark_sensor_adapter_get_ohos_sensor_max_supported_frequency =
        reinterpret_cast<
            ArkSensorAdapterGetOhosSensorMaxSupportedFrequencyFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSensorAdapterSubscribeOhosSensorFunc =
    int32_t (*)(struct _ark_sensor_adapter_t* self,
                int32_t sensorTypeId,
                int64_t samplingInterval);
static ArkSensorAdapterSubscribeOhosSensorFunc
    ark_sensor_adapter_subscribe_ohos_sensor =
        reinterpret_cast<ArkSensorAdapterSubscribeOhosSensorFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSensorAdapterRegistOhosSensorCallbackFunc =
    int32_t (*)(struct _ark_sensor_adapter_t* self,
                int32_t sensorTypeId,
                ark_sensor_callback_adapter_t* callbackAdapter);
static ArkSensorAdapterRegistOhosSensorCallbackFunc
    ark_sensor_adapter_regist_ohos_sensor_callback =
        reinterpret_cast<ArkSensorAdapterRegistOhosSensorCallbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSensorAdapterUnsubscribeOhosSensorFunc =
    int32_t (*)(struct _ark_sensor_adapter_t* self, int32_t sensorTypeId);
static ArkSensorAdapterUnsubscribeOhosSensorFunc
    ark_sensor_adapter_unsubscribe_ohos_sensor =
        reinterpret_cast<ArkSensorAdapterUnsubscribeOhosSensorFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkSensorAdapterCToCpp::IsOhosSensorSupported(int32_t sensorTypeId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_sensor_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_sensor_adapter_is_ohos_sensor_supported);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "3w$EAhgqPKt3V0DvrF4wlQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_SENSOR_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_sensor_adapter_is_ohos_sensor_supported");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_ohos_sensor_supported)) {
        ark_sensor_adapter_is_ohos_sensor_supported = nullptr;
      } else {
        ark_sensor_adapter_is_ohos_sensor_supported =
            _struct->is_ohos_sensor_supported;
      }
    } else {
      ark_sensor_adapter_is_ohos_sensor_supported =
          reinterpret_cast<ArkSensorAdapterIsOhosSensorSupportedFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_sensor_adapter_is_ohos_sensor_supported,
                                    0);

  // Execute
  return ark_sensor_adapter_is_ohos_sensor_supported(_struct, sensorTypeId);
}

ARK_WEB_NO_SANITIZE
int32_t ArkSensorAdapterCToCpp::GetOhosSensorReportingMode(int32_t type) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_sensor_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_sensor_adapter_get_ohos_sensor_reporting_mode);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "89kM_avPZfHFuowqPpwsWw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_SENSOR_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_sensor_adapter_get_ohos_sensor_reporting_mode");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_ohos_sensor_reporting_mode)) {
        ark_sensor_adapter_get_ohos_sensor_reporting_mode = nullptr;
      } else {
        ark_sensor_adapter_get_ohos_sensor_reporting_mode =
            _struct->get_ohos_sensor_reporting_mode;
      }
    } else {
      ark_sensor_adapter_get_ohos_sensor_reporting_mode =
          reinterpret_cast<ArkSensorAdapterGetOhosSensorReportingModeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_sensor_adapter_get_ohos_sensor_reporting_mode, 0);

  // Execute
  return ark_sensor_adapter_get_ohos_sensor_reporting_mode(_struct, type);
}

ARK_WEB_NO_SANITIZE
double ArkSensorAdapterCToCpp::GetOhosSensorDefaultSupportedFrequency(
    int32_t sensorTypeId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_sensor_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_sensor_adapter_get_ohos_sensor_default_supported_frequency);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "temSqf9Q$vYKbYuVjC7KUw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_SENSOR_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_sensor_adapter_get_ohos_sensor_default_supported_frequency");
      if (ARK_WEB_FUNC_MEMBER_MISSING(
              _struct, get_ohos_sensor_default_supported_frequency)) {
        ark_sensor_adapter_get_ohos_sensor_default_supported_frequency =
            nullptr;
      } else {
        ark_sensor_adapter_get_ohos_sensor_default_supported_frequency =
            _struct->get_ohos_sensor_default_supported_frequency;
      }
    } else {
      ark_sensor_adapter_get_ohos_sensor_default_supported_frequency =
          reinterpret_cast<
              ArkSensorAdapterGetOhosSensorDefaultSupportedFrequencyFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_sensor_adapter_get_ohos_sensor_default_supported_frequency, 0);

  // Execute
  return ark_sensor_adapter_get_ohos_sensor_default_supported_frequency(
      _struct, sensorTypeId);
}

ARK_WEB_NO_SANITIZE
double ArkSensorAdapterCToCpp::GetOhosSensorMinSupportedFrequency(
    int32_t sensorTypeId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_sensor_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_sensor_adapter_get_ohos_sensor_min_supported_frequency);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "_CJcHs3YoO0HLs5bHV0npg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_SENSOR_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_sensor_adapter_get_ohos_sensor_min_supported_frequency");
      if (ARK_WEB_FUNC_MEMBER_MISSING(
              _struct, get_ohos_sensor_min_supported_frequency)) {
        ark_sensor_adapter_get_ohos_sensor_min_supported_frequency = nullptr;
      } else {
        ark_sensor_adapter_get_ohos_sensor_min_supported_frequency =
            _struct->get_ohos_sensor_min_supported_frequency;
      }
    } else {
      ark_sensor_adapter_get_ohos_sensor_min_supported_frequency =
          reinterpret_cast<
              ArkSensorAdapterGetOhosSensorMinSupportedFrequencyFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_sensor_adapter_get_ohos_sensor_min_supported_frequency, 0);

  // Execute
  return ark_sensor_adapter_get_ohos_sensor_min_supported_frequency(
      _struct, sensorTypeId);
}

ARK_WEB_NO_SANITIZE
double ArkSensorAdapterCToCpp::GetOhosSensorMaxSupportedFrequency(
    int32_t sensorTypeId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_sensor_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_sensor_adapter_get_ohos_sensor_max_supported_frequency);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Zggku3_dHCoQNndLG58iQA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_SENSOR_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_sensor_adapter_get_ohos_sensor_max_supported_frequency");
      if (ARK_WEB_FUNC_MEMBER_MISSING(
              _struct, get_ohos_sensor_max_supported_frequency)) {
        ark_sensor_adapter_get_ohos_sensor_max_supported_frequency = nullptr;
      } else {
        ark_sensor_adapter_get_ohos_sensor_max_supported_frequency =
            _struct->get_ohos_sensor_max_supported_frequency;
      }
    } else {
      ark_sensor_adapter_get_ohos_sensor_max_supported_frequency =
          reinterpret_cast<
              ArkSensorAdapterGetOhosSensorMaxSupportedFrequencyFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_sensor_adapter_get_ohos_sensor_max_supported_frequency, 0);

  // Execute
  return ark_sensor_adapter_get_ohos_sensor_max_supported_frequency(
      _struct, sensorTypeId);
}

ARK_WEB_NO_SANITIZE
int32_t ArkSensorAdapterCToCpp::SubscribeOhosSensor(int32_t sensorTypeId,
                                                    int64_t samplingInterval) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_sensor_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_sensor_adapter_subscribe_ohos_sensor);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "DHdCL1rCGDCPh4NwC6TE6Q";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_SENSOR_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_sensor_adapter_subscribe_ohos_sensor");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, subscribe_ohos_sensor)) {
        ark_sensor_adapter_subscribe_ohos_sensor = nullptr;
      } else {
        ark_sensor_adapter_subscribe_ohos_sensor =
            _struct->subscribe_ohos_sensor;
      }
    } else {
      ark_sensor_adapter_subscribe_ohos_sensor =
          reinterpret_cast<ArkSensorAdapterSubscribeOhosSensorFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_sensor_adapter_subscribe_ohos_sensor,
                                    0);

  // Execute
  return ark_sensor_adapter_subscribe_ohos_sensor(_struct, sensorTypeId,
                                                  samplingInterval);
}

ARK_WEB_NO_SANITIZE
int32_t ArkSensorAdapterCToCpp::RegistOhosSensorCallback(
    int32_t sensorTypeId,
    ArkWebRefPtr<ArkSensorCallbackAdapter> callbackAdapter) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_sensor_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_sensor_adapter_regist_ohos_sensor_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "P3oC_mfvhCaFHjqIhxWv7Q";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_SENSOR_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_sensor_adapter_regist_ohos_sensor_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, regist_ohos_sensor_callback)) {
        ark_sensor_adapter_regist_ohos_sensor_callback = nullptr;
      } else {
        ark_sensor_adapter_regist_ohos_sensor_callback =
            _struct->regist_ohos_sensor_callback;
      }
    } else {
      ark_sensor_adapter_regist_ohos_sensor_callback =
          reinterpret_cast<ArkSensorAdapterRegistOhosSensorCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_sensor_adapter_regist_ohos_sensor_callback, 0);

  // Execute
  return ark_sensor_adapter_regist_ohos_sensor_callback(
      _struct, sensorTypeId,
      ArkSensorCallbackAdapterCppToC::Invert(callbackAdapter));
}

ARK_WEB_NO_SANITIZE
int32_t ArkSensorAdapterCToCpp::UnsubscribeOhosSensor(int32_t sensorTypeId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_sensor_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_sensor_adapter_unsubscribe_ohos_sensor);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ey2FvPTeN4H59wH9Vje1eg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_SENSOR_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_sensor_adapter_unsubscribe_ohos_sensor");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, unsubscribe_ohos_sensor)) {
        ark_sensor_adapter_unsubscribe_ohos_sensor = nullptr;
      } else {
        ark_sensor_adapter_unsubscribe_ohos_sensor =
            _struct->unsubscribe_ohos_sensor;
      }
    } else {
      ark_sensor_adapter_unsubscribe_ohos_sensor =
          reinterpret_cast<ArkSensorAdapterUnsubscribeOhosSensorFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_sensor_adapter_unsubscribe_ohos_sensor,
                                    0);

  // Execute
  return ark_sensor_adapter_unsubscribe_ohos_sensor(_struct, sensorTypeId);
}

ArkSensorAdapterCToCpp::ArkSensorAdapterCToCpp() {}

ArkSensorAdapterCToCpp::~ArkSensorAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkSensorAdapterCToCpp,
                                        ArkSensorAdapter,
                                        ark_sensor_adapter_t>::kBridgeType =
    ARK_SENSOR_ADAPTER;

}  // namespace OHOS::ArkWeb
