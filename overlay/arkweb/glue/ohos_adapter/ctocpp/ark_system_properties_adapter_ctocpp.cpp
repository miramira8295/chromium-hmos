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

#include "ohos_adapter/ctocpp/ark_system_properties_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkSystemPropertiesAdapterGetResourceUseHapPathEnableFunc =
    bool (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetResourceUseHapPathEnableFunc
    ark_system_properties_adapter_get_resource_use_hap_path_enable =
        reinterpret_cast<
            ArkSystemPropertiesAdapterGetResourceUseHapPathEnableFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetDeviceInfoProductModelFunc =
    ArkWebString (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetDeviceInfoProductModelFunc
    ark_system_properties_adapter_get_device_info_product_model =
        reinterpret_cast<
            ArkSystemPropertiesAdapterGetDeviceInfoProductModelFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetDeviceInfoBrandFunc =
    ArkWebString (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetDeviceInfoBrandFunc
    ark_system_properties_adapter_get_device_info_brand =
        reinterpret_cast<ArkSystemPropertiesAdapterGetDeviceInfoBrandFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetDeviceInfoMajorVersionFunc =
    int32_t (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetDeviceInfoMajorVersionFunc
    ark_system_properties_adapter_get_device_info_major_version =
        reinterpret_cast<
            ArkSystemPropertiesAdapterGetDeviceInfoMajorVersionFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetProductDeviceTypeFunc =
    int32_t (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetProductDeviceTypeFunc
    ark_system_properties_adapter_get_product_device_type =
        reinterpret_cast<ArkSystemPropertiesAdapterGetProductDeviceTypeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetWebOptimizationValueFunc =
    bool (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetWebOptimizationValueFunc
    ark_system_properties_adapter_get_web_optimization_value =
        reinterpret_cast<ArkSystemPropertiesAdapterGetWebOptimizationValueFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterIsAdvancedSecurityModeFunc =
    bool (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterIsAdvancedSecurityModeFunc
    ark_system_properties_adapter_is_advanced_security_mode =
        reinterpret_cast<ArkSystemPropertiesAdapterIsAdvancedSecurityModeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetUserAgentOSNameFunc =
    ArkWebString (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetUserAgentOSNameFunc
    ark_system_properties_adapter_get_user_agent_osname =
        reinterpret_cast<ArkSystemPropertiesAdapterGetUserAgentOSNameFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetSoftwareMajorVersionFunc =
    int32_t (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetSoftwareMajorVersionFunc
    ark_system_properties_adapter_get_software_major_version =
        reinterpret_cast<ArkSystemPropertiesAdapterGetSoftwareMajorVersionFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetSoftwareSeniorVersionFunc =
    int32_t (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetSoftwareSeniorVersionFunc
    ark_system_properties_adapter_get_software_senior_version =
        reinterpret_cast<
            ArkSystemPropertiesAdapterGetSoftwareSeniorVersionFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetNetlogModeFunc =
    ArkWebString (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetNetlogModeFunc
    ark_system_properties_adapter_get_netlog_mode =
        reinterpret_cast<ArkSystemPropertiesAdapterGetNetlogModeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetTraceDebugEnableFunc =
    bool (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetTraceDebugEnableFunc
    ark_system_properties_adapter_get_trace_debug_enable =
        reinterpret_cast<ArkSystemPropertiesAdapterGetTraceDebugEnableFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetSiteIsolationModeFunc =
    ArkWebString (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetSiteIsolationModeFunc
    ark_system_properties_adapter_get_site_isolation_mode =
        reinterpret_cast<ArkSystemPropertiesAdapterGetSiteIsolationModeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetFlowBufMaxFdFunc =
    int32_t (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetFlowBufMaxFdFunc
    ark_system_properties_adapter_get_flow_buf_max_fd =
        reinterpret_cast<ArkSystemPropertiesAdapterGetFlowBufMaxFdFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetOOPGPUEnableFunc =
    bool (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetOOPGPUEnableFunc
    ark_system_properties_adapter_get_oopgpuenable =
        reinterpret_cast<ArkSystemPropertiesAdapterGetOOPGPUEnableFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterSetOOPGPUDisableFunc =
    void (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterSetOOPGPUDisableFunc
    ark_system_properties_adapter_set_oopgpudisable =
        reinterpret_cast<ArkSystemPropertiesAdapterSetOOPGPUDisableFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterAttachSysPropObserverFunc =
    void (*)(struct _ark_system_properties_adapter_t* self,
             int32_t key,
             void* observer);
static ArkSystemPropertiesAdapterAttachSysPropObserverFunc
    ark_system_properties_adapter_attach_sys_prop_observer =
        reinterpret_cast<ArkSystemPropertiesAdapterAttachSysPropObserverFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterDetachSysPropObserverFunc =
    void (*)(struct _ark_system_properties_adapter_t* self,
             int32_t key,
             void* observer);
static ArkSystemPropertiesAdapterDetachSysPropObserverFunc
    ark_system_properties_adapter_detach_sys_prop_observer =
        reinterpret_cast<ArkSystemPropertiesAdapterDetachSysPropObserverFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetBoolParameterFunc =
    bool (*)(struct _ark_system_properties_adapter_t* self,
             ArkWebString key,
             bool defaultValue);
static ArkSystemPropertiesAdapterGetBoolParameterFunc
    ark_system_properties_adapter_get_bool_parameter =
        reinterpret_cast<ArkSystemPropertiesAdapterGetBoolParameterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetLTPOConfigFunc =
    ArkFrameRateSettingAdapterVector (*)(
        struct _ark_system_properties_adapter_t* self,
        const ArkWebString* settingName);
static ArkSystemPropertiesAdapterGetLTPOConfigFunc
    ark_system_properties_adapter_get_ltpoconfig =
        reinterpret_cast<ArkSystemPropertiesAdapterGetLTPOConfigFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetOOPGPUStatusFunc =
    ArkWebString (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetOOPGPUStatusFunc
    ark_system_properties_adapter_get_oopgpustatus =
        reinterpret_cast<ArkSystemPropertiesAdapterGetOOPGPUStatusFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterIsLTPODynamicAppFunc =
    bool (*)(struct _ark_system_properties_adapter_t* self,
             ArkWebString bundleName);
static ArkSystemPropertiesAdapterIsLTPODynamicAppFunc
    ark_system_properties_adapter_is_ltpodynamic_app =
        reinterpret_cast<ArkSystemPropertiesAdapterIsLTPODynamicAppFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetLTPOStrategyFunc =
    int32_t (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetLTPOStrategyFunc
    ark_system_properties_adapter_get_ltpostrategy =
        reinterpret_cast<ArkSystemPropertiesAdapterGetLTPOStrategyFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetUserAgentOSVersionFunc =
    ArkWebString (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetUserAgentOSVersionFunc
    ark_system_properties_adapter_get_user_agent_osversion =
        reinterpret_cast<ArkSystemPropertiesAdapterGetUserAgentOSVersionFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetUserAgentBaseOSNameFunc =
    ArkWebString (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetUserAgentBaseOSNameFunc
    ark_system_properties_adapter_get_user_agent_base_osname =
        reinterpret_cast<ArkSystemPropertiesAdapterGetUserAgentBaseOSNameFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetVulkanStatusFunc =
    ArkWebString (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetVulkanStatusFunc
    ark_system_properties_adapter_get_vulkan_status =
        reinterpret_cast<ArkSystemPropertiesAdapterGetVulkanStatusFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetCompatibleDeviceTypeFunc =
    ArkWebString (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetCompatibleDeviceTypeFunc
    ark_system_properties_adapter_get_compatible_device_type =
        reinterpret_cast<ArkSystemPropertiesAdapterGetCompatibleDeviceTypeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetDeviceInfoApiVersionFunc =
    ArkWebString (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetDeviceInfoApiVersionFunc
    ark_system_properties_adapter_get_device_info_api_version =
        reinterpret_cast<ArkSystemPropertiesAdapterGetDeviceInfoApiVersionFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetPRPPreloadModeFunc =
    ArkWebString (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetPRPPreloadModeFunc
    ark_system_properties_adapter_get_prppreload_mode =
        reinterpret_cast<ArkSystemPropertiesAdapterGetPRPPreloadModeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetScrollVelocityScaleFunc =
    ArkWebString (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetScrollVelocityScaleFunc
    ark_system_properties_adapter_get_scroll_velocity_scale =
        reinterpret_cast<ArkSystemPropertiesAdapterGetScrollVelocityScaleFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetScrollFrictionFunc =
    ArkWebString (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetScrollFrictionFunc
    ark_system_properties_adapter_get_scroll_friction =
        reinterpret_cast<ArkSystemPropertiesAdapterGetScrollFrictionFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetBundleNameFunc =
    ArkWebString (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetBundleNameFunc
    ark_system_properties_adapter_get_bundle_name =
        reinterpret_cast<ArkSystemPropertiesAdapterGetBundleNameFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetStringParameterFunc =
    ArkWebString (*)(struct _ark_system_properties_adapter_t* self,
                     const ArkWebString* key,
                     const ArkWebString* defaultValue);
static ArkSystemPropertiesAdapterGetStringParameterFunc
    ark_system_properties_adapter_get_string_parameter =
        reinterpret_cast<ArkSystemPropertiesAdapterGetStringParameterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetInitialCongestionWindowSizeFunc =
    int32_t (*)(struct _ark_system_properties_adapter_t* self);
static ArkSystemPropertiesAdapterGetInitialCongestionWindowSizeFunc
    ark_system_properties_adapter_get_initial_congestion_window_size =
        reinterpret_cast<
            ArkSystemPropertiesAdapterGetInitialCongestionWindowSizeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSystemPropertiesAdapterGetIntParameterFunc =
    int32_t (*)(struct _ark_system_properties_adapter_t* self,
                const ArkWebString* key,
                int32_t defaultValue);
static ArkSystemPropertiesAdapterGetIntParameterFunc
    ark_system_properties_adapter_get_int_parameter =
        reinterpret_cast<ArkSystemPropertiesAdapterGetIntParameterFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
bool ArkSystemPropertiesAdapterCToCpp::GetResourceUseHapPathEnable() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_resource_use_hap_path_enable);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "lWVwZrBYlooXhr0I6PQhzw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_resource_use_hap_path_enable");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_resource_use_hap_path_enable)) {
        ark_system_properties_adapter_get_resource_use_hap_path_enable =
            nullptr;
      } else {
        ark_system_properties_adapter_get_resource_use_hap_path_enable =
            _struct->get_resource_use_hap_path_enable;
      }
    } else {
      ark_system_properties_adapter_get_resource_use_hap_path_enable =
          reinterpret_cast<
              ArkSystemPropertiesAdapterGetResourceUseHapPathEnableFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_resource_use_hap_path_enable, false);

  // Execute
  return ark_system_properties_adapter_get_resource_use_hap_path_enable(
      _struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkSystemPropertiesAdapterCToCpp::GetDeviceInfoProductModel() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_device_info_product_model);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "i_nLrjlBU8UoZ$6ajLuxhg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_device_info_product_model");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_device_info_product_model)) {
        ark_system_properties_adapter_get_device_info_product_model = nullptr;
      } else {
        ark_system_properties_adapter_get_device_info_product_model =
            _struct->get_device_info_product_model;
      }
    } else {
      ark_system_properties_adapter_get_device_info_product_model =
          reinterpret_cast<
              ArkSystemPropertiesAdapterGetDeviceInfoProductModelFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_device_info_product_model,
      ark_web_string_default);

  // Execute
  return ark_system_properties_adapter_get_device_info_product_model(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkSystemPropertiesAdapterCToCpp::GetDeviceInfoBrand() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_device_info_brand);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "WnVWm75WCaKV2Z1Y7ngDbQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_device_info_brand");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_device_info_brand)) {
        ark_system_properties_adapter_get_device_info_brand = nullptr;
      } else {
        ark_system_properties_adapter_get_device_info_brand =
            _struct->get_device_info_brand;
      }
    } else {
      ark_system_properties_adapter_get_device_info_brand =
          reinterpret_cast<ArkSystemPropertiesAdapterGetDeviceInfoBrandFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_device_info_brand,
      ark_web_string_default);

  // Execute
  return ark_system_properties_adapter_get_device_info_brand(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkSystemPropertiesAdapterCToCpp::GetDeviceInfoMajorVersion() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_device_info_major_version);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "xTqVyhultKzFPb7cP9j8Qw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_device_info_major_version");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_device_info_major_version)) {
        ark_system_properties_adapter_get_device_info_major_version = nullptr;
      } else {
        ark_system_properties_adapter_get_device_info_major_version =
            _struct->get_device_info_major_version;
      }
    } else {
      ark_system_properties_adapter_get_device_info_major_version =
          reinterpret_cast<
              ArkSystemPropertiesAdapterGetDeviceInfoMajorVersionFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_device_info_major_version, 0);

  // Execute
  return ark_system_properties_adapter_get_device_info_major_version(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkSystemPropertiesAdapterCToCpp::GetProductDeviceType() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_product_device_type);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "hw4m5q1aD5pK5YRAnwUuVQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_product_device_type");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_product_device_type)) {
        ark_system_properties_adapter_get_product_device_type = nullptr;
      } else {
        ark_system_properties_adapter_get_product_device_type =
            _struct->get_product_device_type;
      }
    } else {
      ark_system_properties_adapter_get_product_device_type =
          reinterpret_cast<ArkSystemPropertiesAdapterGetProductDeviceTypeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_product_device_type, 0);

  // Execute
  return ark_system_properties_adapter_get_product_device_type(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkSystemPropertiesAdapterCToCpp::GetWebOptimizationValue() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_web_optimization_value);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "76V8gUZrNUvfmZjlqiR_aw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_web_optimization_value");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_web_optimization_value)) {
        ark_system_properties_adapter_get_web_optimization_value = nullptr;
      } else {
        ark_system_properties_adapter_get_web_optimization_value =
            _struct->get_web_optimization_value;
      }
    } else {
      ark_system_properties_adapter_get_web_optimization_value =
          reinterpret_cast<
              ArkSystemPropertiesAdapterGetWebOptimizationValueFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_web_optimization_value, false);

  // Execute
  return ark_system_properties_adapter_get_web_optimization_value(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkSystemPropertiesAdapterCToCpp::IsAdvancedSecurityMode() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_is_advanced_security_mode);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "wx74G5k8HkmvLy9$AZ85Qw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_is_advanced_security_mode");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_advanced_security_mode)) {
        ark_system_properties_adapter_is_advanced_security_mode = nullptr;
      } else {
        ark_system_properties_adapter_is_advanced_security_mode =
            _struct->is_advanced_security_mode;
      }
    } else {
      ark_system_properties_adapter_is_advanced_security_mode =
          reinterpret_cast<
              ArkSystemPropertiesAdapterIsAdvancedSecurityModeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_is_advanced_security_mode, false);

  // Execute
  return ark_system_properties_adapter_is_advanced_security_mode(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkSystemPropertiesAdapterCToCpp::GetUserAgentOSName() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_user_agent_osname);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "KK2SlIpkai1Hss9yJqbZ6A";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_user_agent_osname");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_user_agent_osname)) {
        ark_system_properties_adapter_get_user_agent_osname = nullptr;
      } else {
        ark_system_properties_adapter_get_user_agent_osname =
            _struct->get_user_agent_osname;
      }
    } else {
      ark_system_properties_adapter_get_user_agent_osname =
          reinterpret_cast<ArkSystemPropertiesAdapterGetUserAgentOSNameFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_user_agent_osname,
      ark_web_string_default);

  // Execute
  return ark_system_properties_adapter_get_user_agent_osname(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkSystemPropertiesAdapterCToCpp::GetSoftwareMajorVersion() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_software_major_version);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "lEJbBFEnKA0JzDnn93ZbuQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_software_major_version");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_software_major_version)) {
        ark_system_properties_adapter_get_software_major_version = nullptr;
      } else {
        ark_system_properties_adapter_get_software_major_version =
            _struct->get_software_major_version;
      }
    } else {
      ark_system_properties_adapter_get_software_major_version =
          reinterpret_cast<
              ArkSystemPropertiesAdapterGetSoftwareMajorVersionFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_software_major_version, 0);

  // Execute
  return ark_system_properties_adapter_get_software_major_version(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkSystemPropertiesAdapterCToCpp::GetSoftwareSeniorVersion() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_software_senior_version);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "5s8VYdYT3BkYOD4kRneWIQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_software_senior_version");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_software_senior_version)) {
        ark_system_properties_adapter_get_software_senior_version = nullptr;
      } else {
        ark_system_properties_adapter_get_software_senior_version =
            _struct->get_software_senior_version;
      }
    } else {
      ark_system_properties_adapter_get_software_senior_version =
          reinterpret_cast<
              ArkSystemPropertiesAdapterGetSoftwareSeniorVersionFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_software_senior_version, 0);

  // Execute
  return ark_system_properties_adapter_get_software_senior_version(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkSystemPropertiesAdapterCToCpp::GetNetlogMode() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_system_properties_adapter_get_netlog_mode);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "WtY9lobb_f436VIoopDZAg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_netlog_mode");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_netlog_mode)) {
        ark_system_properties_adapter_get_netlog_mode = nullptr;
      } else {
        ark_system_properties_adapter_get_netlog_mode =
            _struct->get_netlog_mode;
      }
    } else {
      ark_system_properties_adapter_get_netlog_mode =
          reinterpret_cast<ArkSystemPropertiesAdapterGetNetlogModeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_netlog_mode, ark_web_string_default);

  // Execute
  return ark_system_properties_adapter_get_netlog_mode(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkSystemPropertiesAdapterCToCpp::GetTraceDebugEnable() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_trace_debug_enable);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "gpODbGaQcP79aBgnOlLQoA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_trace_debug_enable");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_trace_debug_enable)) {
        ark_system_properties_adapter_get_trace_debug_enable = nullptr;
      } else {
        ark_system_properties_adapter_get_trace_debug_enable =
            _struct->get_trace_debug_enable;
      }
    } else {
      ark_system_properties_adapter_get_trace_debug_enable =
          reinterpret_cast<ArkSystemPropertiesAdapterGetTraceDebugEnableFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_trace_debug_enable, false);

  // Execute
  return ark_system_properties_adapter_get_trace_debug_enable(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkSystemPropertiesAdapterCToCpp::GetSiteIsolationMode() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_site_isolation_mode);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "LxtFC9Pthk50XkoXPokegA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_site_isolation_mode");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_site_isolation_mode)) {
        ark_system_properties_adapter_get_site_isolation_mode = nullptr;
      } else {
        ark_system_properties_adapter_get_site_isolation_mode =
            _struct->get_site_isolation_mode;
      }
    } else {
      ark_system_properties_adapter_get_site_isolation_mode =
          reinterpret_cast<ArkSystemPropertiesAdapterGetSiteIsolationModeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_site_isolation_mode,
      ark_web_string_default);

  // Execute
  return ark_system_properties_adapter_get_site_isolation_mode(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkSystemPropertiesAdapterCToCpp::GetFlowBufMaxFd() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_flow_buf_max_fd);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "2wi11uGVaCecgAEu3mkPPg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_flow_buf_max_fd");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_flow_buf_max_fd)) {
        ark_system_properties_adapter_get_flow_buf_max_fd = nullptr;
      } else {
        ark_system_properties_adapter_get_flow_buf_max_fd =
            _struct->get_flow_buf_max_fd;
      }
    } else {
      ark_system_properties_adapter_get_flow_buf_max_fd =
          reinterpret_cast<ArkSystemPropertiesAdapterGetFlowBufMaxFdFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_flow_buf_max_fd, 0);

  // Execute
  return ark_system_properties_adapter_get_flow_buf_max_fd(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkSystemPropertiesAdapterCToCpp::GetOOPGPUEnable() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_system_properties_adapter_get_oopgpuenable);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "26xEZ9pNVQKqOVLSMYScnQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_oopgpuenable");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_oopgpuenable)) {
        ark_system_properties_adapter_get_oopgpuenable = nullptr;
      } else {
        ark_system_properties_adapter_get_oopgpuenable =
            _struct->get_oopgpuenable;
      }
    } else {
      ark_system_properties_adapter_get_oopgpuenable =
          reinterpret_cast<ArkSystemPropertiesAdapterGetOOPGPUEnableFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_oopgpuenable, false);

  // Execute
  return ark_system_properties_adapter_get_oopgpuenable(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkSystemPropertiesAdapterCToCpp::SetOOPGPUDisable() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_system_properties_adapter_set_oopgpudisable);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "D99zB6XX5a0J6xtotdXVzw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_set_oopgpudisable");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_oopgpudisable)) {
        ark_system_properties_adapter_set_oopgpudisable = nullptr;
      } else {
        ark_system_properties_adapter_set_oopgpudisable =
            _struct->set_oopgpudisable;
      }
    } else {
      ark_system_properties_adapter_set_oopgpudisable =
          reinterpret_cast<ArkSystemPropertiesAdapterSetOOPGPUDisableFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_set_oopgpudisable, ARK_WEB_RETURN_VOID);

  // Execute
  ark_system_properties_adapter_set_oopgpudisable(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkSystemPropertiesAdapterCToCpp::AttachSysPropObserver(int32_t key,
                                                             void* observer) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_attach_sys_prop_observer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "mNLEa6tPk0pFUl$J0omMlw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_attach_sys_prop_observer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, attach_sys_prop_observer)) {
        ark_system_properties_adapter_attach_sys_prop_observer = nullptr;
      } else {
        ark_system_properties_adapter_attach_sys_prop_observer =
            _struct->attach_sys_prop_observer;
      }
    } else {
      ark_system_properties_adapter_attach_sys_prop_observer =
          reinterpret_cast<ArkSystemPropertiesAdapterAttachSysPropObserverFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_attach_sys_prop_observer,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_system_properties_adapter_attach_sys_prop_observer(_struct, key,
                                                         observer);
}

ARK_WEB_NO_SANITIZE
void ArkSystemPropertiesAdapterCToCpp::DetachSysPropObserver(int32_t key,
                                                             void* observer) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_detach_sys_prop_observer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "POUf$bEO8t$OuIcAhuPFew";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_detach_sys_prop_observer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, detach_sys_prop_observer)) {
        ark_system_properties_adapter_detach_sys_prop_observer = nullptr;
      } else {
        ark_system_properties_adapter_detach_sys_prop_observer =
            _struct->detach_sys_prop_observer;
      }
    } else {
      ark_system_properties_adapter_detach_sys_prop_observer =
          reinterpret_cast<ArkSystemPropertiesAdapterDetachSysPropObserverFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_detach_sys_prop_observer,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_system_properties_adapter_detach_sys_prop_observer(_struct, key,
                                                         observer);
}

ARK_WEB_NO_SANITIZE
bool ArkSystemPropertiesAdapterCToCpp::GetBoolParameter(ArkWebString key,
                                                        bool defaultValue) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_system_properties_adapter_get_bool_parameter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ehgZAKk1K7w8EWigNECC$w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_bool_parameter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_bool_parameter)) {
        ark_system_properties_adapter_get_bool_parameter = nullptr;
      } else {
        ark_system_properties_adapter_get_bool_parameter =
            _struct->get_bool_parameter;
      }
    } else {
      ark_system_properties_adapter_get_bool_parameter =
          reinterpret_cast<ArkSystemPropertiesAdapterGetBoolParameterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_bool_parameter, false);

  // Execute
  return ark_system_properties_adapter_get_bool_parameter(_struct, key,
                                                          defaultValue);
}

ARK_WEB_NO_SANITIZE
ArkFrameRateSettingAdapterVector
ArkSystemPropertiesAdapterCToCpp::GetLTPOConfig(
    const ArkWebString& settingName) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct,
                             ark_frame_rate_setting_adapter_vector_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_system_properties_adapter_get_ltpoconfig);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "39Kp5woHTMriYvaLQscgtA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_ltpoconfig");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_ltpoconfig)) {
        ark_system_properties_adapter_get_ltpoconfig = nullptr;
      } else {
        ark_system_properties_adapter_get_ltpoconfig = _struct->get_ltpoconfig;
      }
    } else {
      ark_system_properties_adapter_get_ltpoconfig =
          reinterpret_cast<ArkSystemPropertiesAdapterGetLTPOConfigFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_ltpoconfig,
      ark_frame_rate_setting_adapter_vector_default);

  // Execute
  return ark_system_properties_adapter_get_ltpoconfig(_struct, &settingName);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkSystemPropertiesAdapterCToCpp::GetOOPGPUStatus() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_system_properties_adapter_get_oopgpustatus);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "UqM4QJPbI_Lo4DABOOzKbA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_oopgpustatus");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_oopgpustatus)) {
        ark_system_properties_adapter_get_oopgpustatus = nullptr;
      } else {
        ark_system_properties_adapter_get_oopgpustatus =
            _struct->get_oopgpustatus;
      }
    } else {
      ark_system_properties_adapter_get_oopgpustatus =
          reinterpret_cast<ArkSystemPropertiesAdapterGetOOPGPUStatusFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_oopgpustatus, ark_web_string_default);

  // Execute
  return ark_system_properties_adapter_get_oopgpustatus(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkSystemPropertiesAdapterCToCpp::IsLTPODynamicApp(
    ArkWebString bundleName) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_system_properties_adapter_is_ltpodynamic_app);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "fa66srGjO4mgVeBvPIMB$w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_is_ltpodynamic_app");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_ltpodynamic_app)) {
        ark_system_properties_adapter_is_ltpodynamic_app = nullptr;
      } else {
        ark_system_properties_adapter_is_ltpodynamic_app =
            _struct->is_ltpodynamic_app;
      }
    } else {
      ark_system_properties_adapter_is_ltpodynamic_app =
          reinterpret_cast<ArkSystemPropertiesAdapterIsLTPODynamicAppFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_is_ltpodynamic_app, false);

  // Execute
  return ark_system_properties_adapter_is_ltpodynamic_app(_struct, bundleName);
}

ARK_WEB_NO_SANITIZE
int32_t ArkSystemPropertiesAdapterCToCpp::GetLTPOStrategy() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_system_properties_adapter_get_ltpostrategy);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "twvUy3zndKdK6CFUNmMbvw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_ltpostrategy");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_ltpostrategy)) {
        ark_system_properties_adapter_get_ltpostrategy = nullptr;
      } else {
        ark_system_properties_adapter_get_ltpostrategy =
            _struct->get_ltpostrategy;
      }
    } else {
      ark_system_properties_adapter_get_ltpostrategy =
          reinterpret_cast<ArkSystemPropertiesAdapterGetLTPOStrategyFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_ltpostrategy, 0);

  // Execute
  return ark_system_properties_adapter_get_ltpostrategy(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkSystemPropertiesAdapterCToCpp::GetUserAgentOSVersion() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_user_agent_osversion);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "FVA7sgoYV_zcY_Oh6jkKxQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_user_agent_osversion");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_user_agent_osversion)) {
        ark_system_properties_adapter_get_user_agent_osversion = nullptr;
      } else {
        ark_system_properties_adapter_get_user_agent_osversion =
            _struct->get_user_agent_osversion;
      }
    } else {
      ark_system_properties_adapter_get_user_agent_osversion =
          reinterpret_cast<ArkSystemPropertiesAdapterGetUserAgentOSVersionFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_user_agent_osversion,
      ark_web_string_default);

  // Execute
  return ark_system_properties_adapter_get_user_agent_osversion(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkSystemPropertiesAdapterCToCpp::GetUserAgentBaseOSName() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_user_agent_base_osname);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "8f2277Fb43lIKAYK4wPBzA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_user_agent_base_osname");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_user_agent_base_osname)) {
        ark_system_properties_adapter_get_user_agent_base_osname = nullptr;
      } else {
        ark_system_properties_adapter_get_user_agent_base_osname =
            _struct->get_user_agent_base_osname;
      }
    } else {
      ark_system_properties_adapter_get_user_agent_base_osname =
          reinterpret_cast<
              ArkSystemPropertiesAdapterGetUserAgentBaseOSNameFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_user_agent_base_osname,
      ark_web_string_default);

  // Execute
  return ark_system_properties_adapter_get_user_agent_base_osname(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkSystemPropertiesAdapterCToCpp::GetVulkanStatus() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_system_properties_adapter_get_vulkan_status);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "GABtVN6RqkuZqteXV9$LrQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_vulkan_status");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_vulkan_status)) {
        ark_system_properties_adapter_get_vulkan_status = nullptr;
      } else {
        ark_system_properties_adapter_get_vulkan_status =
            _struct->get_vulkan_status;
      }
    } else {
      ark_system_properties_adapter_get_vulkan_status =
          reinterpret_cast<ArkSystemPropertiesAdapterGetVulkanStatusFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_vulkan_status, ark_web_string_default);

  // Execute
  return ark_system_properties_adapter_get_vulkan_status(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkSystemPropertiesAdapterCToCpp::GetCompatibleDeviceType() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_compatible_device_type);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "SIY1rlVux4XNQjD63Ldrtw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_compatible_device_type");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_compatible_device_type)) {
        ark_system_properties_adapter_get_compatible_device_type = nullptr;
      } else {
        ark_system_properties_adapter_get_compatible_device_type =
            _struct->get_compatible_device_type;
      }
    } else {
      ark_system_properties_adapter_get_compatible_device_type =
          reinterpret_cast<
              ArkSystemPropertiesAdapterGetCompatibleDeviceTypeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_compatible_device_type,
      ark_web_string_default);

  // Execute
  return ark_system_properties_adapter_get_compatible_device_type(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkSystemPropertiesAdapterCToCpp::GetDeviceInfoApiVersion() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_device_info_api_version);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Uuvj3BHNS0W$DJwbCNEM2w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_device_info_api_version");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_device_info_api_version)) {
        ark_system_properties_adapter_get_device_info_api_version = nullptr;
      } else {
        ark_system_properties_adapter_get_device_info_api_version =
            _struct->get_device_info_api_version;
      }
    } else {
      ark_system_properties_adapter_get_device_info_api_version =
          reinterpret_cast<
              ArkSystemPropertiesAdapterGetDeviceInfoApiVersionFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_device_info_api_version,
      ark_web_string_default);

  // Execute
  return ark_system_properties_adapter_get_device_info_api_version(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkSystemPropertiesAdapterCToCpp::GetPRPPreloadMode() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_prppreload_mode);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Mtcn1svrRao7RCKEtjNPcA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_prppreload_mode");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_prppreload_mode)) {
        ark_system_properties_adapter_get_prppreload_mode = nullptr;
      } else {
        ark_system_properties_adapter_get_prppreload_mode =
            _struct->get_prppreload_mode;
      }
    } else {
      ark_system_properties_adapter_get_prppreload_mode =
          reinterpret_cast<ArkSystemPropertiesAdapterGetPRPPreloadModeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_prppreload_mode,
      ark_web_string_default);

  // Execute
  return ark_system_properties_adapter_get_prppreload_mode(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkSystemPropertiesAdapterCToCpp::GetScrollVelocityScale() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_scroll_velocity_scale);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "EiHp8dbcBoNYCHQaz233_Q";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_scroll_velocity_scale");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_scroll_velocity_scale)) {
        ark_system_properties_adapter_get_scroll_velocity_scale = nullptr;
      } else {
        ark_system_properties_adapter_get_scroll_velocity_scale =
            _struct->get_scroll_velocity_scale;
      }
    } else {
      ark_system_properties_adapter_get_scroll_velocity_scale =
          reinterpret_cast<
              ArkSystemPropertiesAdapterGetScrollVelocityScaleFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_scroll_velocity_scale,
      ark_web_string_default);

  // Execute
  return ark_system_properties_adapter_get_scroll_velocity_scale(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkSystemPropertiesAdapterCToCpp::GetScrollFriction() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_scroll_friction);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "RiJPWtXs_rPEbRB__oY99A";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_scroll_friction");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_scroll_friction)) {
        ark_system_properties_adapter_get_scroll_friction = nullptr;
      } else {
        ark_system_properties_adapter_get_scroll_friction =
            _struct->get_scroll_friction;
      }
    } else {
      ark_system_properties_adapter_get_scroll_friction =
          reinterpret_cast<ArkSystemPropertiesAdapterGetScrollFrictionFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_scroll_friction,
      ark_web_string_default);

  // Execute
  return ark_system_properties_adapter_get_scroll_friction(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkSystemPropertiesAdapterCToCpp::GetBundleName() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_system_properties_adapter_get_bundle_name);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "tRBVUZfJPBBnBsxjq4HiAw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_bundle_name");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_bundle_name)) {
        ark_system_properties_adapter_get_bundle_name = nullptr;
      } else {
        ark_system_properties_adapter_get_bundle_name =
            _struct->get_bundle_name;
      }
    } else {
      ark_system_properties_adapter_get_bundle_name =
          reinterpret_cast<ArkSystemPropertiesAdapterGetBundleNameFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_bundle_name, ark_web_string_default);

  // Execute
  return ark_system_properties_adapter_get_bundle_name(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkSystemPropertiesAdapterCToCpp::GetStringParameter(
    const ArkWebString& key,
    const ArkWebString& defaultValue) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_string_parameter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "qCmlusUAKuACngWbEPaUzg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_string_parameter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_string_parameter)) {
        ark_system_properties_adapter_get_string_parameter = nullptr;
      } else {
        ark_system_properties_adapter_get_string_parameter =
            _struct->get_string_parameter;
      }
    } else {
      ark_system_properties_adapter_get_string_parameter =
          reinterpret_cast<ArkSystemPropertiesAdapterGetStringParameterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_string_parameter,
      ark_web_string_default);

  // Execute
  return ark_system_properties_adapter_get_string_parameter(_struct, &key,
                                                            &defaultValue);
}

ARK_WEB_NO_SANITIZE
int32_t ArkSystemPropertiesAdapterCToCpp::GetInitialCongestionWindowSize() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_system_properties_adapter_get_initial_congestion_window_size);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Hs11frdydpOixZVzAiEkLQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_initial_congestion_window_size");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_initial_congestion_window_size)) {
        ark_system_properties_adapter_get_initial_congestion_window_size =
            nullptr;
      } else {
        ark_system_properties_adapter_get_initial_congestion_window_size =
            _struct->get_initial_congestion_window_size;
      }
    } else {
      ark_system_properties_adapter_get_initial_congestion_window_size =
          reinterpret_cast<
              ArkSystemPropertiesAdapterGetInitialCongestionWindowSizeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_initial_congestion_window_size, 0);

  // Execute
  return ark_system_properties_adapter_get_initial_congestion_window_size(
      _struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkSystemPropertiesAdapterCToCpp::GetIntParameter(
    const ArkWebString& key,
    int32_t defaultValue) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_system_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_system_properties_adapter_get_int_parameter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "zSZTu$HNOduaupQBMwCfJw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SYSTEM_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_system_properties_adapter_get_int_parameter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_int_parameter)) {
        ark_system_properties_adapter_get_int_parameter = nullptr;
      } else {
        ark_system_properties_adapter_get_int_parameter =
            _struct->get_int_parameter;
      }
    } else {
      ark_system_properties_adapter_get_int_parameter =
          reinterpret_cast<ArkSystemPropertiesAdapterGetIntParameterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_system_properties_adapter_get_int_parameter, 0);

  // Execute
  return ark_system_properties_adapter_get_int_parameter(_struct, &key,
                                                         defaultValue);
}

ArkSystemPropertiesAdapterCToCpp::ArkSystemPropertiesAdapterCToCpp() {}

ArkSystemPropertiesAdapterCToCpp::~ArkSystemPropertiesAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkSystemPropertiesAdapterCToCpp,
                           ArkSystemPropertiesAdapter,
                           ark_system_properties_adapter_t>::kBridgeType =
        ARK_SYSTEM_PROPERTIES_ADAPTER;

}  // namespace OHOS::ArkWeb
