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

#include "ohos_nweb/cpptoc/ark_web_web_storage_origin_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

long ARK_WEB_CALLBACK ark_web_web_storage_origin_get_quota(
    struct _ark_web_web_storage_origin_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebWebStorageOriginCppToC::Get(self)->GetQuota();
}

void ARK_WEB_CALLBACK
ark_web_web_storage_origin_set_quota(struct _ark_web_web_storage_origin_t* self,
                                     long quota) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebWebStorageOriginCppToC::Get(self)->SetQuota(quota);
}

long ARK_WEB_CALLBACK ark_web_web_storage_origin_get_usage(
    struct _ark_web_web_storage_origin_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebWebStorageOriginCppToC::Get(self)->GetUsage();
}

void ARK_WEB_CALLBACK
ark_web_web_storage_origin_set_usage(struct _ark_web_web_storage_origin_t* self,
                                     long usage) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebWebStorageOriginCppToC::Get(self)->SetUsage(usage);
}

ArkWebString ARK_WEB_CALLBACK ark_web_web_storage_origin_get_origin(
    struct _ark_web_web_storage_origin_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebWebStorageOriginCppToC::Get(self)->GetOrigin();
}

void ARK_WEB_CALLBACK ark_web_web_storage_origin_set_origin(
    struct _ark_web_web_storage_origin_t* self,
    const ArkWebString* origin) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(origin, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebWebStorageOriginCppToC::Get(self)->SetOrigin(*origin);
}

}  // namespace

ArkWebWebStorageOriginCppToC::ArkWebWebStorageOriginCppToC() {
  GetStruct()->get_quota = ark_web_web_storage_origin_get_quota;
  GetStruct()->set_quota = ark_web_web_storage_origin_set_quota;
  GetStruct()->get_usage = ark_web_web_storage_origin_get_usage;
  GetStruct()->set_usage = ark_web_web_storage_origin_set_usage;
  GetStruct()->get_origin = ark_web_web_storage_origin_get_origin;
  GetStruct()->set_origin = ark_web_web_storage_origin_set_origin;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["mGnXKD3N72YcDxI48B1UqQ"] =
        reinterpret_cast<void*>(ark_web_web_storage_origin_get_quota);
    funcMemberMap["JeOh6KRdv45_xyqsFUpWww"] =
        reinterpret_cast<void*>(ark_web_web_storage_origin_set_quota);
    funcMemberMap["TKLgkgqc9CV7CRlOC$jOkA"] =
        reinterpret_cast<void*>(ark_web_web_storage_origin_get_usage);
    funcMemberMap["62oOwP5kqDN_XS2GB9i8cw"] =
        reinterpret_cast<void*>(ark_web_web_storage_origin_set_usage);
    funcMemberMap["zgBFBs_f5ek8Pgo3E6iZaA"] =
        reinterpret_cast<void*>(ark_web_web_storage_origin_get_origin);
    funcMemberMap["uZ$aKma_Ei1IQg_cdTAu8A"] =
        reinterpret_cast<void*>(ark_web_web_storage_origin_set_origin);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_WEB_STORAGE_ORIGIN, funcMemberMap);
  });
}

ArkWebWebStorageOriginCppToC::~ArkWebWebStorageOriginCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebWebStorageOriginCppToC,
                           ArkWebWebStorageOrigin,
                           ark_web_web_storage_origin_t>::kBridgeType =
        ARK_WEB_WEB_STORAGE_ORIGIN;

}  // namespace OHOS::ArkWeb
