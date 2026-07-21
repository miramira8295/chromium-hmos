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

#include "ohos_adapter/ctocpp/ark_enterprise_device_management_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_edm_policy_changed_event_callback_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkEnterpriseDeviceManagementAdapterGetPoliciesFunc =
    int32_t (*)(struct _ark_enterprise_device_management_adapter_t* self,
                ArkWebString* policies);
static ArkEnterpriseDeviceManagementAdapterGetPoliciesFunc
    ark_enterprise_device_management_adapter_get_policies =
        reinterpret_cast<ArkEnterpriseDeviceManagementAdapterGetPoliciesFunc>(
            ARK_WEB_INIT_ADDR);

using ArkEnterpriseDeviceManagementAdapterRegistPolicyChangeEventCallbackFunc =
    void (*)(struct _ark_enterprise_device_management_adapter_t* self,
             ark_edm_policy_changed_event_callback_adapter_t* eventCallback);
static ArkEnterpriseDeviceManagementAdapterRegistPolicyChangeEventCallbackFunc
    ark_enterprise_device_management_adapter_regist_policy_change_event_callback =
        reinterpret_cast<
            ArkEnterpriseDeviceManagementAdapterRegistPolicyChangeEventCallbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkEnterpriseDeviceManagementAdapterStartObservePolicyChangeFunc =
    bool (*)(struct _ark_enterprise_device_management_adapter_t* self);
static ArkEnterpriseDeviceManagementAdapterStartObservePolicyChangeFunc
    ark_enterprise_device_management_adapter_start_observe_policy_change =
        reinterpret_cast<
            ArkEnterpriseDeviceManagementAdapterStartObservePolicyChangeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkEnterpriseDeviceManagementAdapterStopObservePolicyChangeFunc =
    bool (*)(struct _ark_enterprise_device_management_adapter_t* self);
static ArkEnterpriseDeviceManagementAdapterStopObservePolicyChangeFunc
    ark_enterprise_device_management_adapter_stop_observe_policy_change =
        reinterpret_cast<
            ArkEnterpriseDeviceManagementAdapterStopObservePolicyChangeFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkEnterpriseDeviceManagementAdapterCToCpp::GetPolicies(
    ArkWebString& policies) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_enterprise_device_management_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_enterprise_device_management_adapter_get_policies);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "EbXRgD3LDadROtqnXVXFQA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_ENTERPRISE_DEVICE_MANAGEMENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_enterprise_device_management_adapter_get_policies");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_policies)) {
        ark_enterprise_device_management_adapter_get_policies = nullptr;
      } else {
        ark_enterprise_device_management_adapter_get_policies =
            _struct->get_policies;
      }
    } else {
      ark_enterprise_device_management_adapter_get_policies =
          reinterpret_cast<ArkEnterpriseDeviceManagementAdapterGetPoliciesFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_enterprise_device_management_adapter_get_policies, 0);

  // Execute
  return ark_enterprise_device_management_adapter_get_policies(_struct,
                                                               &policies);
}

ARK_WEB_NO_SANITIZE
void ArkEnterpriseDeviceManagementAdapterCToCpp::
    RegistPolicyChangeEventCallback(
        ArkWebRefPtr<ArkEdmPolicyChangedEventCallbackAdapter> eventCallback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_enterprise_device_management_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_enterprise_device_management_adapter_regist_policy_change_event_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "gaOqOoxNkv$4fcwPeFuPzA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_ENTERPRISE_DEVICE_MANAGEMENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_enterprise_device_management_adapter_regist_policy_change_event_"
          "callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      regist_policy_change_event_callback)) {
        ark_enterprise_device_management_adapter_regist_policy_change_event_callback =
            nullptr;
      } else {
        ark_enterprise_device_management_adapter_regist_policy_change_event_callback =
            _struct->regist_policy_change_event_callback;
      }
    } else {
      ark_enterprise_device_management_adapter_regist_policy_change_event_callback =
          reinterpret_cast<
              ArkEnterpriseDeviceManagementAdapterRegistPolicyChangeEventCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_enterprise_device_management_adapter_regist_policy_change_event_callback,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_enterprise_device_management_adapter_regist_policy_change_event_callback(
      _struct,
      ArkEdmPolicyChangedEventCallbackAdapterCppToC::Invert(eventCallback));
}

ARK_WEB_NO_SANITIZE
bool ArkEnterpriseDeviceManagementAdapterCToCpp::StartObservePolicyChange() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_enterprise_device_management_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_enterprise_device_management_adapter_start_observe_policy_change);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "_mIk07aPqNijt13VDi$sDw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_ENTERPRISE_DEVICE_MANAGEMENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_enterprise_device_management_adapter_start_observe_policy_"
          "change");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start_observe_policy_change)) {
        ark_enterprise_device_management_adapter_start_observe_policy_change =
            nullptr;
      } else {
        ark_enterprise_device_management_adapter_start_observe_policy_change =
            _struct->start_observe_policy_change;
      }
    } else {
      ark_enterprise_device_management_adapter_start_observe_policy_change =
          reinterpret_cast<
              ArkEnterpriseDeviceManagementAdapterStartObservePolicyChangeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_enterprise_device_management_adapter_start_observe_policy_change,
      false);

  // Execute
  return ark_enterprise_device_management_adapter_start_observe_policy_change(
      _struct);
}

ARK_WEB_NO_SANITIZE
bool ArkEnterpriseDeviceManagementAdapterCToCpp::StopObservePolicyChange() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_enterprise_device_management_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_enterprise_device_management_adapter_stop_observe_policy_change);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "7el0E23o_vudpwLr5qsC3w";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_ENTERPRISE_DEVICE_MANAGEMENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_enterprise_device_management_adapter_stop_observe_policy_"
          "change");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, stop_observe_policy_change)) {
        ark_enterprise_device_management_adapter_stop_observe_policy_change =
            nullptr;
      } else {
        ark_enterprise_device_management_adapter_stop_observe_policy_change =
            _struct->stop_observe_policy_change;
      }
    } else {
      ark_enterprise_device_management_adapter_stop_observe_policy_change =
          reinterpret_cast<
              ArkEnterpriseDeviceManagementAdapterStopObservePolicyChangeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_enterprise_device_management_adapter_stop_observe_policy_change,
      false);

  // Execute
  return ark_enterprise_device_management_adapter_stop_observe_policy_change(
      _struct);
}

ArkEnterpriseDeviceManagementAdapterCToCpp::
    ArkEnterpriseDeviceManagementAdapterCToCpp() {}

ArkEnterpriseDeviceManagementAdapterCToCpp::
    ~ArkEnterpriseDeviceManagementAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<
    ArkEnterpriseDeviceManagementAdapterCToCpp,
    ArkEnterpriseDeviceManagementAdapter,
    ark_enterprise_device_management_adapter_t>::kBridgeType =
    ARK_ENTERPRISE_DEVICE_MANAGEMENT_ADAPTER;

}  // namespace OHOS::ArkWeb
