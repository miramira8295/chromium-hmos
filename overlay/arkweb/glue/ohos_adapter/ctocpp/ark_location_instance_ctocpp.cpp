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

#include "ohos_adapter/ctocpp/ark_location_instance_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/ctocpp/ark_location_proxy_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_location_request_config_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkLocationInstanceGetInstanceFunc = ark_location_instance_t* (*)(void);
static ArkLocationInstanceGetInstanceFunc ark_location_instance_get_instance =
    reinterpret_cast<ArkLocationInstanceGetInstanceFunc>(ARK_WEB_INIT_ADDR);

using ArkLocationInstanceCreateLocationProxyAdapterFunc =
    ark_location_proxy_adapter_t* (*)(struct _ark_location_instance_t* self);
static ArkLocationInstanceCreateLocationProxyAdapterFunc
    ark_location_instance_create_location_proxy_adapter =
        reinterpret_cast<ArkLocationInstanceCreateLocationProxyAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkLocationInstanceCreateLocationRequestConfigFunc =
    ark_location_request_config_t* (*)(struct _ark_location_instance_t* self);
static ArkLocationInstanceCreateLocationRequestConfigFunc
    ark_location_instance_create_location_request_config =
        reinterpret_cast<ArkLocationInstanceCreateLocationRequestConfigFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkLocationInstance> ArkLocationInstance::GetInstance() {
  ARK_WEB_CTOCPP_DV_LOG();

  void* func_pointer =
      reinterpret_cast<void*>(ark_location_instance_get_instance);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const char* funcName = "ark_location_instance_get_instance_static";
    ark_location_instance_get_instance =
        reinterpret_cast<ArkLocationInstanceGetInstanceFunc>(
            ArkWebAdapterWebcoreBridgeHelper::GetInstance().LoadFuncSymbol(
                funcName));
  }

  if (!ark_location_instance_get_instance) {
    ARK_WEB_CTOCPP_WARN_LOG(
        "failed to load func ark_location_instance_get_instance_static");
    return nullptr;
  }

  // Execute
  ark_location_instance_t* _retval = ark_location_instance_get_instance();

  // Return type: refptr_same
  return ArkLocationInstanceCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkLocationProxyAdapter>
ArkLocationInstanceCToCpp::CreateLocationProxyAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_instance_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_location_instance_create_location_proxy_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "6RtNwi$0yZDyovkw9iPBqw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_LOCATION_INSTANCE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_location_instance_create_location_proxy_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_location_proxy_adapter)) {
        ark_location_instance_create_location_proxy_adapter = nullptr;
      } else {
        ark_location_instance_create_location_proxy_adapter =
            _struct->create_location_proxy_adapter;
      }
    } else {
      ark_location_instance_create_location_proxy_adapter =
          reinterpret_cast<ArkLocationInstanceCreateLocationProxyAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_location_instance_create_location_proxy_adapter, nullptr);

  // Execute
  ark_location_proxy_adapter_t* _retval =
      ark_location_instance_create_location_proxy_adapter(_struct);

  // Return type: refptr_same
  return ArkLocationProxyAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkLocationRequestConfig>
ArkLocationInstanceCToCpp::CreateLocationRequestConfig() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_location_instance_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_location_instance_create_location_request_config);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "FXZvOHIomnrd3nx94H4cGA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_LOCATION_INSTANCE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_location_instance_create_location_request_config");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      create_location_request_config)) {
        ark_location_instance_create_location_request_config = nullptr;
      } else {
        ark_location_instance_create_location_request_config =
            _struct->create_location_request_config;
      }
    } else {
      ark_location_instance_create_location_request_config =
          reinterpret_cast<ArkLocationInstanceCreateLocationRequestConfigFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_location_instance_create_location_request_config, nullptr);

  // Execute
  ark_location_request_config_t* _retval =
      ark_location_instance_create_location_request_config(_struct);

  // Return type: refptr_same
  return ArkLocationRequestConfigCToCpp::Invert(_retval);
}

ArkLocationInstanceCToCpp::ArkLocationInstanceCToCpp() {}

ArkLocationInstanceCToCpp::~ArkLocationInstanceCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkLocationInstanceCToCpp,
                                        ArkLocationInstance,
                                        ark_location_instance_t>::kBridgeType =
    ARK_LOCATION_INSTANCE;

}  // namespace OHOS::ArkWeb
