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

#include "ohos_adapter/cpptoc/ark_sensor_callback_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK ark_sensor_callback_adapter_update_ohos_sensor_data(
    struct _ark_sensor_callback_adapter_t* self,
    double timestamp,
    double value1,
    double value2,
    double value3,
    double value4) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkSensorCallbackAdapterCppToC::Get(self)->UpdateOhosSensorData(
      timestamp, value1, value2, value3, value4);
}

}  // namespace

ArkSensorCallbackAdapterCppToC::ArkSensorCallbackAdapterCppToC() {
  GetStruct()->update_ohos_sensor_data =
      ark_sensor_callback_adapter_update_ohos_sensor_data;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["eHr3ZyqgixUv33KdWMdq7w"] = reinterpret_cast<void*>(
        ark_sensor_callback_adapter_update_ohos_sensor_data);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_SENSOR_CALLBACK_ADAPTER, funcMemberMap);
  });
}

ArkSensorCallbackAdapterCppToC::~ArkSensorCallbackAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkSensorCallbackAdapterCppToC,
                           ArkSensorCallbackAdapter,
                           ark_sensor_callback_adapter_t>::kBridgeType =
        ARK_SENSOR_CALLBACK_ADAPTER;

}  // namespace OHOS::ArkWeb
