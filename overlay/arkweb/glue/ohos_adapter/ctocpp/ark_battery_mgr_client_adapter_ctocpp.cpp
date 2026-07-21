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

#include "ohos_adapter/ctocpp/ark_battery_mgr_client_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_battery_event_callback_cpptoc.h"
#include "ohos_adapter/ctocpp/ark_battery_info_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkBatteryMgrClientAdapterRegBatteryEventFunc =
    void (*)(struct _ark_battery_mgr_client_adapter_t* self,
             ark_battery_event_callback_t* eventCallback);
static ArkBatteryMgrClientAdapterRegBatteryEventFunc
    ark_battery_mgr_client_adapter_reg_battery_event =
        reinterpret_cast<ArkBatteryMgrClientAdapterRegBatteryEventFunc>(
            ARK_WEB_INIT_ADDR);

using ArkBatteryMgrClientAdapterStartListenFunc =
    bool (*)(struct _ark_battery_mgr_client_adapter_t* self);
static ArkBatteryMgrClientAdapterStartListenFunc
    ark_battery_mgr_client_adapter_start_listen =
        reinterpret_cast<ArkBatteryMgrClientAdapterStartListenFunc>(
            ARK_WEB_INIT_ADDR);

using ArkBatteryMgrClientAdapterStopListenFunc =
    void (*)(struct _ark_battery_mgr_client_adapter_t* self);
static ArkBatteryMgrClientAdapterStopListenFunc
    ark_battery_mgr_client_adapter_stop_listen =
        reinterpret_cast<ArkBatteryMgrClientAdapterStopListenFunc>(
            ARK_WEB_INIT_ADDR);

using ArkBatteryMgrClientAdapterRequestBatteryInfoFunc =
    ark_battery_info_t* (*)(struct _ark_battery_mgr_client_adapter_t* self);
static ArkBatteryMgrClientAdapterRequestBatteryInfoFunc
    ark_battery_mgr_client_adapter_request_battery_info =
        reinterpret_cast<ArkBatteryMgrClientAdapterRequestBatteryInfoFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkBatteryMgrClientAdapterCToCpp::RegBatteryEvent(
    ArkWebRefPtr<ArkBatteryEventCallback> eventCallback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_battery_mgr_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_battery_mgr_client_adapter_reg_battery_event);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "CEvDlWpMjogw3Xpwnp9MJA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_BATTERY_MGR_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_battery_mgr_client_adapter_reg_battery_event");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, reg_battery_event)) {
        ark_battery_mgr_client_adapter_reg_battery_event = nullptr;
      } else {
        ark_battery_mgr_client_adapter_reg_battery_event =
            _struct->reg_battery_event;
      }
    } else {
      ark_battery_mgr_client_adapter_reg_battery_event =
          reinterpret_cast<ArkBatteryMgrClientAdapterRegBatteryEventFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_battery_mgr_client_adapter_reg_battery_event, ARK_WEB_RETURN_VOID);

  // Execute
  ark_battery_mgr_client_adapter_reg_battery_event(
      _struct, ArkBatteryEventCallbackCppToC::Invert(eventCallback));
}

ARK_WEB_NO_SANITIZE
bool ArkBatteryMgrClientAdapterCToCpp::StartListen() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_battery_mgr_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_battery_mgr_client_adapter_start_listen);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "KjjHMr9iloUU6TjxTwpnLQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_BATTERY_MGR_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_battery_mgr_client_adapter_start_listen");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start_listen)) {
        ark_battery_mgr_client_adapter_start_listen = nullptr;
      } else {
        ark_battery_mgr_client_adapter_start_listen = _struct->start_listen;
      }
    } else {
      ark_battery_mgr_client_adapter_start_listen =
          reinterpret_cast<ArkBatteryMgrClientAdapterStartListenFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_battery_mgr_client_adapter_start_listen,
                                    false);

  // Execute
  return ark_battery_mgr_client_adapter_start_listen(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkBatteryMgrClientAdapterCToCpp::StopListen() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_battery_mgr_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_battery_mgr_client_adapter_stop_listen);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "_ijRPQhkkaSsuKDX_l$CVw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_BATTERY_MGR_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_battery_mgr_client_adapter_stop_listen");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, stop_listen)) {
        ark_battery_mgr_client_adapter_stop_listen = nullptr;
      } else {
        ark_battery_mgr_client_adapter_stop_listen = _struct->stop_listen;
      }
    } else {
      ark_battery_mgr_client_adapter_stop_listen =
          reinterpret_cast<ArkBatteryMgrClientAdapterStopListenFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_battery_mgr_client_adapter_stop_listen,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_battery_mgr_client_adapter_stop_listen(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkBatteryInfo>
ArkBatteryMgrClientAdapterCToCpp::RequestBatteryInfo() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_battery_mgr_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_battery_mgr_client_adapter_request_battery_info);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Xr9doyO3AwQKi00aUGS_Ew";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_BATTERY_MGR_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_battery_mgr_client_adapter_request_battery_info");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, request_battery_info)) {
        ark_battery_mgr_client_adapter_request_battery_info = nullptr;
      } else {
        ark_battery_mgr_client_adapter_request_battery_info =
            _struct->request_battery_info;
      }
    } else {
      ark_battery_mgr_client_adapter_request_battery_info =
          reinterpret_cast<ArkBatteryMgrClientAdapterRequestBatteryInfoFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_battery_mgr_client_adapter_request_battery_info, nullptr);

  // Execute
  ark_battery_info_t* _retval =
      ark_battery_mgr_client_adapter_request_battery_info(_struct);

  // Return type: refptr_same
  return ArkBatteryInfoCToCpp::Invert(_retval);
}

ArkBatteryMgrClientAdapterCToCpp::ArkBatteryMgrClientAdapterCToCpp() {}

ArkBatteryMgrClientAdapterCToCpp::~ArkBatteryMgrClientAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkBatteryMgrClientAdapterCToCpp,
                           ArkBatteryMgrClientAdapter,
                           ark_battery_mgr_client_adapter_t>::kBridgeType =
        ARK_BATTERY_MGR_CLIENT_ADAPTER;

}  // namespace OHOS::ArkWeb
