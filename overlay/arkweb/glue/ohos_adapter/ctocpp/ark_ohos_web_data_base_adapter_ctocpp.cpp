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

#include "ohos_adapter/ctocpp/ark_ohos_web_data_base_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkOhosWebDataBaseAdapterExistHttpAuthCredentialsFunc =
    bool (*)(struct _ark_ohos_web_data_base_adapter_t* self);
static ArkOhosWebDataBaseAdapterExistHttpAuthCredentialsFunc
    ark_ohos_web_data_base_adapter_exist_http_auth_credentials =
        reinterpret_cast<ArkOhosWebDataBaseAdapterExistHttpAuthCredentialsFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosWebDataBaseAdapterDeleteHttpAuthCredentialsFunc =
    void (*)(struct _ark_ohos_web_data_base_adapter_t* self);
static ArkOhosWebDataBaseAdapterDeleteHttpAuthCredentialsFunc
    ark_ohos_web_data_base_adapter_delete_http_auth_credentials =
        reinterpret_cast<
            ArkOhosWebDataBaseAdapterDeleteHttpAuthCredentialsFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosWebDataBaseAdapterSaveHttpAuthCredentialsFunc =
    void (*)(struct _ark_ohos_web_data_base_adapter_t* self,
             const ArkWebString* host,
             const ArkWebString* realm,
             const ArkWebString* username,
             const char* password);
static ArkOhosWebDataBaseAdapterSaveHttpAuthCredentialsFunc
    ark_ohos_web_data_base_adapter_save_http_auth_credentials =
        reinterpret_cast<ArkOhosWebDataBaseAdapterSaveHttpAuthCredentialsFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosWebDataBaseAdapterGetHttpAuthCredentialsFunc =
    void (*)(struct _ark_ohos_web_data_base_adapter_t* self,
             const ArkWebString* host,
             const ArkWebString* realm,
             ArkWebString* username,
             char* password,
             uint32_t passwordSize);
static ArkOhosWebDataBaseAdapterGetHttpAuthCredentialsFunc
    ark_ohos_web_data_base_adapter_get_http_auth_credentials =
        reinterpret_cast<ArkOhosWebDataBaseAdapterGetHttpAuthCredentialsFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
bool ArkOhosWebDataBaseAdapterCToCpp::ExistHttpAuthCredentials() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_web_data_base_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_web_data_base_adapter_exist_http_auth_credentials);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jZR2uwuBAB87021qcL_NOQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_WEB_DATA_BASE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_web_data_base_adapter_exist_http_auth_credentials");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, exist_http_auth_credentials)) {
        ark_ohos_web_data_base_adapter_exist_http_auth_credentials = nullptr;
      } else {
        ark_ohos_web_data_base_adapter_exist_http_auth_credentials =
            _struct->exist_http_auth_credentials;
      }
    } else {
      ark_ohos_web_data_base_adapter_exist_http_auth_credentials =
          reinterpret_cast<
              ArkOhosWebDataBaseAdapterExistHttpAuthCredentialsFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_web_data_base_adapter_exist_http_auth_credentials, false);

  // Execute
  return ark_ohos_web_data_base_adapter_exist_http_auth_credentials(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkOhosWebDataBaseAdapterCToCpp::DeleteHttpAuthCredentials() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_web_data_base_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_web_data_base_adapter_delete_http_auth_credentials);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "YDRhpLKN5u_Qz5CJZ99ZEQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_WEB_DATA_BASE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_web_data_base_adapter_delete_http_auth_credentials");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, delete_http_auth_credentials)) {
        ark_ohos_web_data_base_adapter_delete_http_auth_credentials = nullptr;
      } else {
        ark_ohos_web_data_base_adapter_delete_http_auth_credentials =
            _struct->delete_http_auth_credentials;
      }
    } else {
      ark_ohos_web_data_base_adapter_delete_http_auth_credentials =
          reinterpret_cast<
              ArkOhosWebDataBaseAdapterDeleteHttpAuthCredentialsFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_web_data_base_adapter_delete_http_auth_credentials,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_ohos_web_data_base_adapter_delete_http_auth_credentials(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkOhosWebDataBaseAdapterCToCpp::SaveHttpAuthCredentials(
    const ArkWebString& host,
    const ArkWebString& realm,
    const ArkWebString& username,
    const char* password) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_web_data_base_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_web_data_base_adapter_save_http_auth_credentials);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "x8Kbe17dDX7n$hpUNNJvDA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_WEB_DATA_BASE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_web_data_base_adapter_save_http_auth_credentials");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, save_http_auth_credentials)) {
        ark_ohos_web_data_base_adapter_save_http_auth_credentials = nullptr;
      } else {
        ark_ohos_web_data_base_adapter_save_http_auth_credentials =
            _struct->save_http_auth_credentials;
      }
    } else {
      ark_ohos_web_data_base_adapter_save_http_auth_credentials =
          reinterpret_cast<
              ArkOhosWebDataBaseAdapterSaveHttpAuthCredentialsFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_web_data_base_adapter_save_http_auth_credentials,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_ohos_web_data_base_adapter_save_http_auth_credentials(
      _struct, &host, &realm, &username, password);
}

ARK_WEB_NO_SANITIZE
void ArkOhosWebDataBaseAdapterCToCpp::GetHttpAuthCredentials(
    const ArkWebString& host,
    const ArkWebString& realm,
    ArkWebString& username,
    char* password,
    uint32_t passwordSize) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_web_data_base_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_web_data_base_adapter_get_http_auth_credentials);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "zQXCgi8eyhVBBL8OQKug7Q";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_WEB_DATA_BASE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_web_data_base_adapter_get_http_auth_credentials");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_http_auth_credentials)) {
        ark_ohos_web_data_base_adapter_get_http_auth_credentials = nullptr;
      } else {
        ark_ohos_web_data_base_adapter_get_http_auth_credentials =
            _struct->get_http_auth_credentials;
      }
    } else {
      ark_ohos_web_data_base_adapter_get_http_auth_credentials =
          reinterpret_cast<ArkOhosWebDataBaseAdapterGetHttpAuthCredentialsFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_web_data_base_adapter_get_http_auth_credentials,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_ohos_web_data_base_adapter_get_http_auth_credentials(
      _struct, &host, &realm, &username, password, passwordSize);
}

ArkOhosWebDataBaseAdapterCToCpp::ArkOhosWebDataBaseAdapterCToCpp() {}

ArkOhosWebDataBaseAdapterCToCpp::~ArkOhosWebDataBaseAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkOhosWebDataBaseAdapterCToCpp,
                           ArkOhosWebDataBaseAdapter,
                           ark_ohos_web_data_base_adapter_t>::kBridgeType =
        ARK_OHOS_WEB_DATA_BASE_ADAPTER;

}  // namespace OHOS::ArkWeb
