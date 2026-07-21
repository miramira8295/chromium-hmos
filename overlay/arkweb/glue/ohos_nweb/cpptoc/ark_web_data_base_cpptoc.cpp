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

#include "ohos_nweb/cpptoc/ark_web_data_base_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK
ark_web_data_base_clear_all_permission(struct _ark_web_data_base_t* self,
                                       int type,
                                       bool incognito) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebDataBaseCppToC::Get(self)->ClearAllPermission(type, incognito);
}

void ARK_WEB_CALLBACK
ark_web_data_base_get_http_auth_credentials(struct _ark_web_data_base_t* self,
                                            const ArkWebString* host,
                                            const ArkWebString* realm,
                                            ArkWebString* user_name,
                                            char* password,
                                            uint32_t password_size) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(host, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(realm, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(user_name, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebDataBaseCppToC::Get(self)->GetHttpAuthCredentials(
      *host, *realm, *user_name, password, password_size);
}

void ARK_WEB_CALLBACK
ark_web_data_base_save_http_auth_credentials(struct _ark_web_data_base_t* self,
                                             const ArkWebString* host,
                                             const ArkWebString* realm,
                                             const ArkWebString* user_name,
                                             const char* password) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(host, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(realm, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(user_name, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebDataBaseCppToC::Get(self)->SaveHttpAuthCredentials(
      *host, *realm, *user_name, password);
}

bool ARK_WEB_CALLBACK ark_web_data_base_exist_http_auth_credentials(
    struct _ark_web_data_base_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebDataBaseCppToC::Get(self)->ExistHttpAuthCredentials();
}

void ARK_WEB_CALLBACK ark_web_data_base_delete_http_auth_credentials(
    struct _ark_web_data_base_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebDataBaseCppToC::Get(self)->DeleteHttpAuthCredentials();
}

ArkWebStringVector ARK_WEB_CALLBACK
ark_web_data_base_get_origins_by_permission(struct _ark_web_data_base_t* self,
                                            int type,
                                            bool incognito) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_vector_default);

  // Execute
  return ArkWebDataBaseCppToC::Get(self)->GetOriginsByPermission(type,
                                                                 incognito);
}

bool ARK_WEB_CALLBACK
ark_web_data_base_get_permission_by_origin(struct _ark_web_data_base_t* self,
                                           const ArkWebString* origin,
                                           int type,
                                           bool* result,
                                           bool incognito) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);
  ARK_WEB_CPPTOC_CHECK_PARAM(origin, false);
  ARK_WEB_CPPTOC_CHECK_PARAM(result, false);

  // Execute
  return ArkWebDataBaseCppToC::Get(self)->GetPermissionByOrigin(
      *origin, type, *result, incognito);
}

int ARK_WEB_CALLBACK
ark_web_data_base_set_permission_by_origin(struct _ark_web_data_base_t* self,
                                           const ArkWebString* origin,
                                           int type,
                                           bool result,
                                           bool incognito) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(origin, 0);

  // Execute
  return ArkWebDataBaseCppToC::Get(self)->SetPermissionByOrigin(
      *origin, type, result, incognito);
}

bool ARK_WEB_CALLBACK
ark_web_data_base_exist_permission_by_origin(struct _ark_web_data_base_t* self,
                                             const ArkWebString* origin,
                                             int type,
                                             bool incognito) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);
  ARK_WEB_CPPTOC_CHECK_PARAM(origin, false);

  // Execute
  return ArkWebDataBaseCppToC::Get(self)->ExistPermissionByOrigin(*origin, type,
                                                                  incognito);
}

int ARK_WEB_CALLBACK
ark_web_data_base_clear_permission_by_origin(struct _ark_web_data_base_t* self,
                                             const ArkWebString* origin,
                                             int type,
                                             bool incognito) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(origin, 0);

  // Execute
  return ArkWebDataBaseCppToC::Get(self)->ClearPermissionByOrigin(*origin, type,
                                                                  incognito);
}

}  // namespace

ArkWebDataBaseCppToC::ArkWebDataBaseCppToC() {
  GetStruct()->clear_all_permission = ark_web_data_base_clear_all_permission;
  GetStruct()->get_http_auth_credentials =
      ark_web_data_base_get_http_auth_credentials;
  GetStruct()->save_http_auth_credentials =
      ark_web_data_base_save_http_auth_credentials;
  GetStruct()->exist_http_auth_credentials =
      ark_web_data_base_exist_http_auth_credentials;
  GetStruct()->delete_http_auth_credentials =
      ark_web_data_base_delete_http_auth_credentials;
  GetStruct()->get_origins_by_permission =
      ark_web_data_base_get_origins_by_permission;
  GetStruct()->get_permission_by_origin =
      ark_web_data_base_get_permission_by_origin;
  GetStruct()->set_permission_by_origin =
      ark_web_data_base_set_permission_by_origin;
  GetStruct()->exist_permission_by_origin =
      ark_web_data_base_exist_permission_by_origin;
  GetStruct()->clear_permission_by_origin =
      ark_web_data_base_clear_permission_by_origin;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["NTGE8nmHo92AwGn2QnV26g"] =
        reinterpret_cast<void*>(ark_web_data_base_clear_all_permission);
    funcMemberMap["1Loa9_TlWhp_sAMhJP2sHg"] =
        reinterpret_cast<void*>(ark_web_data_base_get_http_auth_credentials);
    funcMemberMap["rWcrDp$C5kJAPFfF_pj21w"] =
        reinterpret_cast<void*>(ark_web_data_base_save_http_auth_credentials);
    funcMemberMap["R8lfqnc3Gk5YiXMGZO8gDA"] =
        reinterpret_cast<void*>(ark_web_data_base_exist_http_auth_credentials);
    funcMemberMap["4vwlXAlWI15g6zw_VZQgVQ"] =
        reinterpret_cast<void*>(ark_web_data_base_delete_http_auth_credentials);
    funcMemberMap["Hezx4M3vOtVLfo0yCuiIBQ"] =
        reinterpret_cast<void*>(ark_web_data_base_get_origins_by_permission);
    funcMemberMap["6TRyQJ32FA9ulf_PWpR22g"] =
        reinterpret_cast<void*>(ark_web_data_base_get_permission_by_origin);
    funcMemberMap["oXDsb00IAQ9LeQGI7KXFYA"] =
        reinterpret_cast<void*>(ark_web_data_base_set_permission_by_origin);
    funcMemberMap["urHy2YCFf9ruModq2lt8RQ"] =
        reinterpret_cast<void*>(ark_web_data_base_exist_permission_by_origin);
    funcMemberMap["rz$R81Ja9jZg_8$m2xcvbQ"] =
        reinterpret_cast<void*>(ark_web_data_base_clear_permission_by_origin);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_DATA_BASE, funcMemberMap);
  });
}

ArkWebDataBaseCppToC::~ArkWebDataBaseCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<ArkWebDataBaseCppToC,
                                        ArkWebDataBase,
                                        ark_web_data_base_t>::kBridgeType =
    ARK_WEB_DATA_BASE;

}  // namespace OHOS::ArkWeb
