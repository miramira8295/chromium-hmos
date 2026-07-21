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

#include "ohos_nweb/cpptoc/ark_web_ads_block_manager_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK ark_web_ads_block_manager_set_ads_block_rules(
    struct _ark_web_ads_block_manager_t* self,
    const ArkWebString* url,
    bool replace) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebAdsBlockManagerCppToC::Get(self)->SetAdsBlockRules(*url, replace);
}

void ARK_WEB_CALLBACK ark_web_ads_block_manager_add_ads_block_disallowed_list(
    struct _ark_web_ads_block_manager_t* self,
    const ArkWebStringVector* domainSuffixes) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(domainSuffixes, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebAdsBlockManagerCppToC::Get(self)->AddAdsBlockDisallowedList(
      *domainSuffixes);
}

void ARK_WEB_CALLBACK
ark_web_ads_block_manager_remove_ads_block_disallowed_list(
    struct _ark_web_ads_block_manager_t* self,
    const ArkWebStringVector* domainSuffixes) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(domainSuffixes, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebAdsBlockManagerCppToC::Get(self)->RemoveAdsBlockDisallowedList(
      *domainSuffixes);
}

void ARK_WEB_CALLBACK ark_web_ads_block_manager_clear_ads_block_disallowed_list(
    struct _ark_web_ads_block_manager_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebAdsBlockManagerCppToC::Get(self)->ClearAdsBlockDisallowedList();
}

void ARK_WEB_CALLBACK ark_web_ads_block_manager_add_ads_block_allowed_list(
    struct _ark_web_ads_block_manager_t* self,
    const ArkWebStringVector* domainSuffixes) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(domainSuffixes, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebAdsBlockManagerCppToC::Get(self)->AddAdsBlockAllowedList(
      *domainSuffixes);
}

void ARK_WEB_CALLBACK ark_web_ads_block_manager_remove_ads_block_allowed_list(
    struct _ark_web_ads_block_manager_t* self,
    const ArkWebStringVector* domainSuffixes) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(domainSuffixes, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebAdsBlockManagerCppToC::Get(self)->RemoveAdsBlockAllowedList(
      *domainSuffixes);
}

void ARK_WEB_CALLBACK ark_web_ads_block_manager_clear_ads_block_allowed_list(
    struct _ark_web_ads_block_manager_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebAdsBlockManagerCppToC::Get(self)->ClearAdsBlockAllowedList();
}

}  // namespace

ArkWebAdsBlockManagerCppToC::ArkWebAdsBlockManagerCppToC() {
  GetStruct()->set_ads_block_rules =
      ark_web_ads_block_manager_set_ads_block_rules;
  GetStruct()->add_ads_block_disallowed_list =
      ark_web_ads_block_manager_add_ads_block_disallowed_list;
  GetStruct()->remove_ads_block_disallowed_list =
      ark_web_ads_block_manager_remove_ads_block_disallowed_list;
  GetStruct()->clear_ads_block_disallowed_list =
      ark_web_ads_block_manager_clear_ads_block_disallowed_list;
  GetStruct()->add_ads_block_allowed_list =
      ark_web_ads_block_manager_add_ads_block_allowed_list;
  GetStruct()->remove_ads_block_allowed_list =
      ark_web_ads_block_manager_remove_ads_block_allowed_list;
  GetStruct()->clear_ads_block_allowed_list =
      ark_web_ads_block_manager_clear_ads_block_allowed_list;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["R1tcAGsMi47nfiQtLMWRGA"] =
        reinterpret_cast<void*>(ark_web_ads_block_manager_set_ads_block_rules);
    funcMemberMap["dp7kDg9N4CgQheuE4LqlCw"] = reinterpret_cast<void*>(
        ark_web_ads_block_manager_add_ads_block_disallowed_list);
    funcMemberMap["BENKkEjru3lLpAD213hw8Q"] = reinterpret_cast<void*>(
        ark_web_ads_block_manager_remove_ads_block_disallowed_list);
    funcMemberMap["6qNHqaved27_YZPR6Muz8Q"] = reinterpret_cast<void*>(
        ark_web_ads_block_manager_clear_ads_block_disallowed_list);
    funcMemberMap["hJMAn$FPrMcpoxhmPEG8Yg"] = reinterpret_cast<void*>(
        ark_web_ads_block_manager_add_ads_block_allowed_list);
    funcMemberMap["caCamHlrOtm0oMG1djMI_A"] = reinterpret_cast<void*>(
        ark_web_ads_block_manager_remove_ads_block_allowed_list);
    funcMemberMap["oOJzy78C6IFK7_sNSOZkrg"] = reinterpret_cast<void*>(
        ark_web_ads_block_manager_clear_ads_block_allowed_list);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_ADS_BLOCK_MANAGER, funcMemberMap);
  });
}

ArkWebAdsBlockManagerCppToC::~ArkWebAdsBlockManagerCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebAdsBlockManagerCppToC,
                           ArkWebAdsBlockManager,
                           ark_web_ads_block_manager_t>::kBridgeType =
        ARK_WEB_ADS_BLOCK_MANAGER;

}  // namespace OHOS::ArkWeb
