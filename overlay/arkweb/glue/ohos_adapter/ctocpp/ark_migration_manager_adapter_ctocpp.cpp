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

#include "ohos_adapter/ctocpp/ark_migration_manager_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_migration_listener_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkMigrationManagerAdapterSetMigrationParamFunc =
    void (*)(struct _ark_migration_manager_adapter_t* self,
             const ArkWebString* bundleName,
             const ArkWebString* abilityName,
             const ArkWebString* token);
static ArkMigrationManagerAdapterSetMigrationParamFunc
    ark_migration_manager_adapter_set_migration_param =
        reinterpret_cast<ArkMigrationManagerAdapterSetMigrationParamFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMigrationManagerAdapterSendMigrationRequestFunc =
    bool (*)(struct _ark_migration_manager_adapter_t* self,
             const char* jsonData);
static ArkMigrationManagerAdapterSendMigrationRequestFunc
    ark_migration_manager_adapter_send_migration_request =
        reinterpret_cast<ArkMigrationManagerAdapterSendMigrationRequestFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMigrationManagerAdapterRegisterMigrationListenerFunc =
    uint32_t (*)(struct _ark_migration_manager_adapter_t* self,
                 ark_migration_listener_adapter_t* listener);
static ArkMigrationManagerAdapterRegisterMigrationListenerFunc
    ark_migration_manager_adapter_register_migration_listener =
        reinterpret_cast<
            ArkMigrationManagerAdapterRegisterMigrationListenerFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkMigrationManagerAdapterCToCpp::SetMigrationParam(
    const ArkWebString& bundleName,
    const ArkWebString& abilityName,
    const ArkWebString& token) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_migration_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_migration_manager_adapter_set_migration_param);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "hn5mTCXq6PKQmpQt9t892g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MIGRATION_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_migration_manager_adapter_set_migration_param");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_migration_param)) {
        ark_migration_manager_adapter_set_migration_param = nullptr;
      } else {
        ark_migration_manager_adapter_set_migration_param =
            _struct->set_migration_param;
      }
    } else {
      ark_migration_manager_adapter_set_migration_param =
          reinterpret_cast<ArkMigrationManagerAdapterSetMigrationParamFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_migration_manager_adapter_set_migration_param, ARK_WEB_RETURN_VOID);

  // Execute
  ark_migration_manager_adapter_set_migration_param(_struct, &bundleName,
                                                    &abilityName, &token);
}

ARK_WEB_NO_SANITIZE
bool ArkMigrationManagerAdapterCToCpp::SendMigrationRequest(
    const char* jsonData) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_migration_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_migration_manager_adapter_send_migration_request);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "qyhY3hW2lnkNaSoR6$4UrQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MIGRATION_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_migration_manager_adapter_send_migration_request");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, send_migration_request)) {
        ark_migration_manager_adapter_send_migration_request = nullptr;
      } else {
        ark_migration_manager_adapter_send_migration_request =
            _struct->send_migration_request;
      }
    } else {
      ark_migration_manager_adapter_send_migration_request =
          reinterpret_cast<ArkMigrationManagerAdapterSendMigrationRequestFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_migration_manager_adapter_send_migration_request, false);

  // Execute
  return ark_migration_manager_adapter_send_migration_request(_struct,
                                                              jsonData);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkMigrationManagerAdapterCToCpp::RegisterMigrationListener(
    ArkWebRefPtr<ArkMigrationListenerAdapter> listener) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_migration_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_migration_manager_adapter_register_migration_listener);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "oyzKCttMI_FwvxC2omLxbQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MIGRATION_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_migration_manager_adapter_register_migration_listener");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, register_migration_listener)) {
        ark_migration_manager_adapter_register_migration_listener = nullptr;
      } else {
        ark_migration_manager_adapter_register_migration_listener =
            _struct->register_migration_listener;
      }
    } else {
      ark_migration_manager_adapter_register_migration_listener =
          reinterpret_cast<
              ArkMigrationManagerAdapterRegisterMigrationListenerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_migration_manager_adapter_register_migration_listener, 0);

  // Execute
  return ark_migration_manager_adapter_register_migration_listener(
      _struct, ArkMigrationListenerAdapterCppToC::Invert(listener));
}

ArkMigrationManagerAdapterCToCpp::ArkMigrationManagerAdapterCToCpp() {}

ArkMigrationManagerAdapterCToCpp::~ArkMigrationManagerAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkMigrationManagerAdapterCToCpp,
                           ArkMigrationManagerAdapter,
                           ark_migration_manager_adapter_t>::kBridgeType =
        ARK_MIGRATION_MANAGER_ADAPTER;

}  // namespace OHOS::ArkWeb
