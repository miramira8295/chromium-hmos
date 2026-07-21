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

#include "ohos_adapter/ctocpp/ark_location_proxy_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_location_callback_adapter_cpptoc.h"
#include "ohos_adapter/ctocpp/ark_location_request_config_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkLocationProxyAdapterStartLocatingFunc =
    int32_t (*)(struct _ark_location_proxy_adapter_t* self,
                ark_location_request_config_t* requestConfig,
                ark_location_callback_adapter_t* callback);
static ArkLocationProxyAdapterStartLocatingFunc
    ark_location_proxy_adapter_start_locating =
        reinterpret_cast<ArkLocationProxyAdapterStartLocatingFunc>(
            ARK_WEB_INIT_ADDR);

using ArkLocationProxyAdapterStopLocatingFunc =
    bool (*)(struct _ark_location_proxy_adapter_t* self, int32_t callbackId);
static ArkLocationProxyAdapterStopLocatingFunc
    ark_location_proxy_adapter_stop_locating =
        reinterpret_cast<ArkLocationProxyAdapterStopLocatingFunc>(
            ARK_WEB_INIT_ADDR);

using ArkLocationProxyAdapterEnableAbilityFunc =
    bool (*)(struct _ark_location_proxy_adapter_t* self, bool isEnabled);
static ArkLocationProxyAdapterEnableAbilityFunc
    ark_location_proxy_adapter_enable_ability =
        reinterpret_cast<ArkLocationProxyAdapterEnableAbilityFunc>(
            ARK_WEB_INIT_ADDR);

using ArkLocationProxyAdapterIsLocationEnabledFunc =
    bool (*)(struct _ark_location_proxy_adapter_t* self);
static ArkLocationProxyAdapterIsLocationEnabledFunc
    ark_location_proxy_adapter_is_location_enabled =
        reinterpret_cast<ArkLocationProxyAdapterIsLocationEnabledFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkLocationProxyAdapterCToCpp::StartLocating(
    ArkWebRefPtr<ArkLocationRequestConfig> requestConfig,
    ArkWebRefPtr<ArkLocationCallbackAdapter> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_proxy_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_location_proxy_adapter_start_locating);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "h8wfOVNVtayJ9PqCdYsvfQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_LOCATION_PROXY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_location_proxy_adapter_start_locating");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start_locating)) {
        ark_location_proxy_adapter_start_locating = nullptr;
      } else {
        ark_location_proxy_adapter_start_locating = _struct->start_locating;
      }
    } else {
      ark_location_proxy_adapter_start_locating =
          reinterpret_cast<ArkLocationProxyAdapterStartLocatingFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_location_proxy_adapter_start_locating,
                                    0);

  // Execute
  return ark_location_proxy_adapter_start_locating(
      _struct, ArkLocationRequestConfigCToCpp::Revert(requestConfig),
      ArkLocationCallbackAdapterCppToC::Invert(callback));
}

ARK_WEB_NO_SANITIZE
bool ArkLocationProxyAdapterCToCpp::StopLocating(int32_t callbackId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_proxy_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_location_proxy_adapter_stop_locating);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "58QVUViiO3ct3cglfoKtDw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_LOCATION_PROXY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_location_proxy_adapter_stop_locating");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, stop_locating)) {
        ark_location_proxy_adapter_stop_locating = nullptr;
      } else {
        ark_location_proxy_adapter_stop_locating = _struct->stop_locating;
      }
    } else {
      ark_location_proxy_adapter_stop_locating =
          reinterpret_cast<ArkLocationProxyAdapterStopLocatingFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_location_proxy_adapter_stop_locating,
                                    false);

  // Execute
  return ark_location_proxy_adapter_stop_locating(_struct, callbackId);
}

ARK_WEB_NO_SANITIZE
bool ArkLocationProxyAdapterCToCpp::EnableAbility(bool isEnabled) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_proxy_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_location_proxy_adapter_enable_ability);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "rPPbv4pj40Uy1Ve6yoCJyQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_LOCATION_PROXY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_location_proxy_adapter_enable_ability");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, enable_ability)) {
        ark_location_proxy_adapter_enable_ability = nullptr;
      } else {
        ark_location_proxy_adapter_enable_ability = _struct->enable_ability;
      }
    } else {
      ark_location_proxy_adapter_enable_ability =
          reinterpret_cast<ArkLocationProxyAdapterEnableAbilityFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_location_proxy_adapter_enable_ability,
                                    false);

  // Execute
  return ark_location_proxy_adapter_enable_ability(_struct, isEnabled);
}

ARK_WEB_NO_SANITIZE
bool ArkLocationProxyAdapterCToCpp::IsLocationEnabled() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_proxy_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_location_proxy_adapter_is_location_enabled);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "hcvRdyCw$4I0nJkXtKleIA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_LOCATION_PROXY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_location_proxy_adapter_is_location_enabled");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_location_enabled)) {
        ark_location_proxy_adapter_is_location_enabled = nullptr;
      } else {
        ark_location_proxy_adapter_is_location_enabled =
            _struct->is_location_enabled;
      }
    } else {
      ark_location_proxy_adapter_is_location_enabled =
          reinterpret_cast<ArkLocationProxyAdapterIsLocationEnabledFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_location_proxy_adapter_is_location_enabled, false);

  // Execute
  return ark_location_proxy_adapter_is_location_enabled(_struct);
}

ArkLocationProxyAdapterCToCpp::ArkLocationProxyAdapterCToCpp() {}

ArkLocationProxyAdapterCToCpp::~ArkLocationProxyAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkLocationProxyAdapterCToCpp,
                           ArkLocationProxyAdapter,
                           ark_location_proxy_adapter_t>::kBridgeType =
        ARK_LOCATION_PROXY_ADAPTER;

}  // namespace OHOS::ArkWeb
