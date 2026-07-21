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

#include "ohos_adapter/ctocpp/ark_date_time_format_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_timezone_event_callback_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkDateTimeFormatAdapterRegTimezoneEventFunc =
    void (*)(struct _ark_date_time_format_adapter_t* self,
             ark_timezone_event_callback_adapter_t* eventCallback);
static ArkDateTimeFormatAdapterRegTimezoneEventFunc
    ark_date_time_format_adapter_reg_timezone_event =
        reinterpret_cast<ArkDateTimeFormatAdapterRegTimezoneEventFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDateTimeFormatAdapterStartListenFunc =
    bool (*)(struct _ark_date_time_format_adapter_t* self);
static ArkDateTimeFormatAdapterStartListenFunc
    ark_date_time_format_adapter_start_listen =
        reinterpret_cast<ArkDateTimeFormatAdapterStartListenFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDateTimeFormatAdapterStopListenFunc =
    void (*)(struct _ark_date_time_format_adapter_t* self);
static ArkDateTimeFormatAdapterStopListenFunc
    ark_date_time_format_adapter_stop_listen =
        reinterpret_cast<ArkDateTimeFormatAdapterStopListenFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDateTimeFormatAdapterGetTimezoneFunc =
    ArkWebString (*)(struct _ark_date_time_format_adapter_t* self);
static ArkDateTimeFormatAdapterGetTimezoneFunc
    ark_date_time_format_adapter_get_timezone =
        reinterpret_cast<ArkDateTimeFormatAdapterGetTimezoneFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkDateTimeFormatAdapterCToCpp::RegTimezoneEvent(
    ArkWebRefPtr<ArkTimezoneEventCallbackAdapter> eventCallback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_date_time_format_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_date_time_format_adapter_reg_timezone_event);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "DmCYDNa2gz1NH4g2eaPMoQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_DATE_TIME_FORMAT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_date_time_format_adapter_reg_timezone_event");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, reg_timezone_event)) {
        ark_date_time_format_adapter_reg_timezone_event = nullptr;
      } else {
        ark_date_time_format_adapter_reg_timezone_event =
            _struct->reg_timezone_event;
      }
    } else {
      ark_date_time_format_adapter_reg_timezone_event =
          reinterpret_cast<ArkDateTimeFormatAdapterRegTimezoneEventFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_date_time_format_adapter_reg_timezone_event, ARK_WEB_RETURN_VOID);

  // Execute
  ark_date_time_format_adapter_reg_timezone_event(
      _struct, ArkTimezoneEventCallbackAdapterCppToC::Invert(eventCallback));
}

ARK_WEB_NO_SANITIZE
bool ArkDateTimeFormatAdapterCToCpp::StartListen() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_date_time_format_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_date_time_format_adapter_start_listen);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "bQ_7Tfd1ZlbLtlIPq4jW4g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_DATE_TIME_FORMAT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_date_time_format_adapter_start_listen");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start_listen)) {
        ark_date_time_format_adapter_start_listen = nullptr;
      } else {
        ark_date_time_format_adapter_start_listen = _struct->start_listen;
      }
    } else {
      ark_date_time_format_adapter_start_listen =
          reinterpret_cast<ArkDateTimeFormatAdapterStartListenFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_date_time_format_adapter_start_listen,
                                    false);

  // Execute
  return ark_date_time_format_adapter_start_listen(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkDateTimeFormatAdapterCToCpp::StopListen() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_date_time_format_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_date_time_format_adapter_stop_listen);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Yox5NLqqfJ$VQez8xV34RA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_DATE_TIME_FORMAT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_date_time_format_adapter_stop_listen");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, stop_listen)) {
        ark_date_time_format_adapter_stop_listen = nullptr;
      } else {
        ark_date_time_format_adapter_stop_listen = _struct->stop_listen;
      }
    } else {
      ark_date_time_format_adapter_stop_listen =
          reinterpret_cast<ArkDateTimeFormatAdapterStopListenFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_date_time_format_adapter_stop_listen,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_date_time_format_adapter_stop_listen(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkDateTimeFormatAdapterCToCpp::GetTimezone() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_date_time_format_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_date_time_format_adapter_get_timezone);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "NQuLOL4UE764ylDix$VtrA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_DATE_TIME_FORMAT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_date_time_format_adapter_get_timezone");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_timezone)) {
        ark_date_time_format_adapter_get_timezone = nullptr;
      } else {
        ark_date_time_format_adapter_get_timezone = _struct->get_timezone;
      }
    } else {
      ark_date_time_format_adapter_get_timezone =
          reinterpret_cast<ArkDateTimeFormatAdapterGetTimezoneFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_date_time_format_adapter_get_timezone,
                                    ark_web_string_default);

  // Execute
  return ark_date_time_format_adapter_get_timezone(_struct);
}

ArkDateTimeFormatAdapterCToCpp::ArkDateTimeFormatAdapterCToCpp() {}

ArkDateTimeFormatAdapterCToCpp::~ArkDateTimeFormatAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkDateTimeFormatAdapterCToCpp,
                           ArkDateTimeFormatAdapter,
                           ark_date_time_format_adapter_t>::kBridgeType =
        ARK_DATE_TIME_FORMAT_ADAPTER;

}  // namespace OHOS::ArkWeb
