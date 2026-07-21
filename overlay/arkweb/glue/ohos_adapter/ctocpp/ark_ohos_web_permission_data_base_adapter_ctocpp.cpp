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

#include "ohos_adapter/ctocpp/ark_ohos_web_permission_data_base_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkOhosWebPermissionDataBaseAdapterExistPermissionByOriginFunc =
    bool (*)(struct _ark_ohos_web_permission_data_base_adapter_t* self,
             const ArkWebString* origin,
             const int32_t* key);
static ArkOhosWebPermissionDataBaseAdapterExistPermissionByOriginFunc
    ark_ohos_web_permission_data_base_adapter_exist_permission_by_origin =
        reinterpret_cast<
            ArkOhosWebPermissionDataBaseAdapterExistPermissionByOriginFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosWebPermissionDataBaseAdapterGetPermissionResultByOriginFunc =
    bool (*)(struct _ark_ohos_web_permission_data_base_adapter_t* self,
             const ArkWebString* origin,
             const int32_t* key,
             bool* result);
static ArkOhosWebPermissionDataBaseAdapterGetPermissionResultByOriginFunc
    ark_ohos_web_permission_data_base_adapter_get_permission_result_by_origin =
        reinterpret_cast<
            ArkOhosWebPermissionDataBaseAdapterGetPermissionResultByOriginFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosWebPermissionDataBaseAdapterSetPermissionByOriginFunc =
    void (*)(struct _ark_ohos_web_permission_data_base_adapter_t* self,
             const ArkWebString* origin,
             const int32_t* key,
             bool result);
static ArkOhosWebPermissionDataBaseAdapterSetPermissionByOriginFunc
    ark_ohos_web_permission_data_base_adapter_set_permission_by_origin =
        reinterpret_cast<
            ArkOhosWebPermissionDataBaseAdapterSetPermissionByOriginFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosWebPermissionDataBaseAdapterClearPermissionByOriginFunc =
    void (*)(struct _ark_ohos_web_permission_data_base_adapter_t* self,
             const ArkWebString* origin,
             const int32_t* key);
static ArkOhosWebPermissionDataBaseAdapterClearPermissionByOriginFunc
    ark_ohos_web_permission_data_base_adapter_clear_permission_by_origin =
        reinterpret_cast<
            ArkOhosWebPermissionDataBaseAdapterClearPermissionByOriginFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosWebPermissionDataBaseAdapterClearAllPermissionFunc =
    void (*)(struct _ark_ohos_web_permission_data_base_adapter_t* self,
             const int32_t* key);
static ArkOhosWebPermissionDataBaseAdapterClearAllPermissionFunc
    ark_ohos_web_permission_data_base_adapter_clear_all_permission =
        reinterpret_cast<
            ArkOhosWebPermissionDataBaseAdapterClearAllPermissionFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosWebPermissionDataBaseAdapterGetOriginsByPermissionFunc =
    void (*)(struct _ark_ohos_web_permission_data_base_adapter_t* self,
             const int32_t* key,
             ArkWebStringVector* origins);
static ArkOhosWebPermissionDataBaseAdapterGetOriginsByPermissionFunc
    ark_ohos_web_permission_data_base_adapter_get_origins_by_permission =
        reinterpret_cast<
            ArkOhosWebPermissionDataBaseAdapterGetOriginsByPermissionFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
bool ArkOhosWebPermissionDataBaseAdapterCToCpp::ExistPermissionByOrigin(
    const ArkWebString& origin,
    const int32_t& key) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_web_permission_data_base_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_web_permission_data_base_adapter_exist_permission_by_origin);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Nq1Hn2AlxrKJ0rAMbyIGDQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_OHOS_WEB_PERMISSION_DATA_BASE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_web_permission_data_base_adapter_exist_permission_by_"
          "origin");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, exist_permission_by_origin)) {
        ark_ohos_web_permission_data_base_adapter_exist_permission_by_origin =
            nullptr;
      } else {
        ark_ohos_web_permission_data_base_adapter_exist_permission_by_origin =
            _struct->exist_permission_by_origin;
      }
    } else {
      ark_ohos_web_permission_data_base_adapter_exist_permission_by_origin =
          reinterpret_cast<
              ArkOhosWebPermissionDataBaseAdapterExistPermissionByOriginFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_web_permission_data_base_adapter_exist_permission_by_origin,
      false);

  // Execute
  return ark_ohos_web_permission_data_base_adapter_exist_permission_by_origin(
      _struct, &origin, &key);
}

ARK_WEB_NO_SANITIZE
bool ArkOhosWebPermissionDataBaseAdapterCToCpp::GetPermissionResultByOrigin(
    const ArkWebString& origin,
    const int32_t& key,
    bool& result) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_web_permission_data_base_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_web_permission_data_base_adapter_get_permission_result_by_origin);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "sbofCSABO8glY0hqDgC3sA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_OHOS_WEB_PERMISSION_DATA_BASE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_web_permission_data_base_adapter_get_permission_result_by_"
          "origin");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_permission_result_by_origin)) {
        ark_ohos_web_permission_data_base_adapter_get_permission_result_by_origin =
            nullptr;
      } else {
        ark_ohos_web_permission_data_base_adapter_get_permission_result_by_origin =
            _struct->get_permission_result_by_origin;
      }
    } else {
      ark_ohos_web_permission_data_base_adapter_get_permission_result_by_origin =
          reinterpret_cast<
              ArkOhosWebPermissionDataBaseAdapterGetPermissionResultByOriginFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_web_permission_data_base_adapter_get_permission_result_by_origin,
      false);

  // Execute
  return ark_ohos_web_permission_data_base_adapter_get_permission_result_by_origin(
      _struct, &origin, &key, &result);
}

ARK_WEB_NO_SANITIZE
void ArkOhosWebPermissionDataBaseAdapterCToCpp::SetPermissionByOrigin(
    const ArkWebString& origin,
    const int32_t& key,
    bool result) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_web_permission_data_base_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_web_permission_data_base_adapter_set_permission_by_origin);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "GqkIYyvwco5_bkLrW5RIyw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_OHOS_WEB_PERMISSION_DATA_BASE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_web_permission_data_base_adapter_set_permission_by_origin");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_permission_by_origin)) {
        ark_ohos_web_permission_data_base_adapter_set_permission_by_origin =
            nullptr;
      } else {
        ark_ohos_web_permission_data_base_adapter_set_permission_by_origin =
            _struct->set_permission_by_origin;
      }
    } else {
      ark_ohos_web_permission_data_base_adapter_set_permission_by_origin =
          reinterpret_cast<
              ArkOhosWebPermissionDataBaseAdapterSetPermissionByOriginFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_web_permission_data_base_adapter_set_permission_by_origin,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_ohos_web_permission_data_base_adapter_set_permission_by_origin(
      _struct, &origin, &key, result);
}

ARK_WEB_NO_SANITIZE
void ArkOhosWebPermissionDataBaseAdapterCToCpp::ClearPermissionByOrigin(
    const ArkWebString& origin,
    const int32_t& key) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_web_permission_data_base_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_web_permission_data_base_adapter_clear_permission_by_origin);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "21GWyaJMdyGDIpviZWt0pg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_OHOS_WEB_PERMISSION_DATA_BASE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_web_permission_data_base_adapter_clear_permission_by_"
          "origin");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, clear_permission_by_origin)) {
        ark_ohos_web_permission_data_base_adapter_clear_permission_by_origin =
            nullptr;
      } else {
        ark_ohos_web_permission_data_base_adapter_clear_permission_by_origin =
            _struct->clear_permission_by_origin;
      }
    } else {
      ark_ohos_web_permission_data_base_adapter_clear_permission_by_origin =
          reinterpret_cast<
              ArkOhosWebPermissionDataBaseAdapterClearPermissionByOriginFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_web_permission_data_base_adapter_clear_permission_by_origin,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_ohos_web_permission_data_base_adapter_clear_permission_by_origin(
      _struct, &origin, &key);
}

ARK_WEB_NO_SANITIZE
void ArkOhosWebPermissionDataBaseAdapterCToCpp::ClearAllPermission(
    const int32_t& key) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_web_permission_data_base_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_web_permission_data_base_adapter_clear_all_permission);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "IDQGnGNBHf9yoM5$X8gSmw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_OHOS_WEB_PERMISSION_DATA_BASE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_web_permission_data_base_adapter_clear_all_permission");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, clear_all_permission)) {
        ark_ohos_web_permission_data_base_adapter_clear_all_permission =
            nullptr;
      } else {
        ark_ohos_web_permission_data_base_adapter_clear_all_permission =
            _struct->clear_all_permission;
      }
    } else {
      ark_ohos_web_permission_data_base_adapter_clear_all_permission =
          reinterpret_cast<
              ArkOhosWebPermissionDataBaseAdapterClearAllPermissionFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_web_permission_data_base_adapter_clear_all_permission,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_ohos_web_permission_data_base_adapter_clear_all_permission(_struct, &key);
}

ARK_WEB_NO_SANITIZE
void ArkOhosWebPermissionDataBaseAdapterCToCpp::GetOriginsByPermission(
    const int32_t& key,
    ArkWebStringVector& origins) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_web_permission_data_base_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_web_permission_data_base_adapter_get_origins_by_permission);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "mgPBYxqk$mcpM9HWMze3Og";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_OHOS_WEB_PERMISSION_DATA_BASE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_web_permission_data_base_adapter_get_origins_by_"
          "permission");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_origins_by_permission)) {
        ark_ohos_web_permission_data_base_adapter_get_origins_by_permission =
            nullptr;
      } else {
        ark_ohos_web_permission_data_base_adapter_get_origins_by_permission =
            _struct->get_origins_by_permission;
      }
    } else {
      ark_ohos_web_permission_data_base_adapter_get_origins_by_permission =
          reinterpret_cast<
              ArkOhosWebPermissionDataBaseAdapterGetOriginsByPermissionFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_web_permission_data_base_adapter_get_origins_by_permission,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_ohos_web_permission_data_base_adapter_get_origins_by_permission(
      _struct, &key, &origins);
}

ArkOhosWebPermissionDataBaseAdapterCToCpp::
    ArkOhosWebPermissionDataBaseAdapterCToCpp() {}

ArkOhosWebPermissionDataBaseAdapterCToCpp::
    ~ArkOhosWebPermissionDataBaseAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<
    ArkOhosWebPermissionDataBaseAdapterCToCpp,
    ArkOhosWebPermissionDataBaseAdapter,
    ark_ohos_web_permission_data_base_adapter_t>::kBridgeType =
    ARK_OHOS_WEB_PERMISSION_DATA_BASE_ADAPTER;

}  // namespace OHOS::ArkWeb
