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

#include "ohos_nweb/cpptoc/ark_web_download_manager_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"
#include "ohos_nweb/ctocpp/ark_web_doh_config_ctocpp.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK
ark_web_download_manager_set_http_dns(struct _ark_web_download_manager_t* self,
                                      ark_web_doh_config_t* config) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebDownloadManagerCppToC::Get(self)->SetHttpDns(
      ArkWebDohConfigCToCpp::Invert(config));
}

void ARK_WEB_CALLBACK ark_web_download_manager_set_connection_timeout(
    struct _ark_web_download_manager_t* self,
    const int* timeout) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(timeout, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebDownloadManagerCppToC::Get(self)->SetConnectionTimeout(*timeout);
}

}  // namespace

ArkWebDownloadManagerCppToC::ArkWebDownloadManagerCppToC() {
  GetStruct()->set_http_dns = ark_web_download_manager_set_http_dns;
  GetStruct()->set_connection_timeout =
      ark_web_download_manager_set_connection_timeout;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["BZXv6dJ7um9MDwvZum9q$w"] =
        reinterpret_cast<void*>(ark_web_download_manager_set_http_dns);
    funcMemberMap["HzXyvUt2j_Ms_lExsmBl4Q"] = reinterpret_cast<void*>(
        ark_web_download_manager_set_connection_timeout);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_DOWNLOAD_MANAGER, funcMemberMap);
  });
}

ArkWebDownloadManagerCppToC::~ArkWebDownloadManagerCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebDownloadManagerCppToC,
                           ArkWebDownloadManager,
                           ark_web_download_manager_t>::kBridgeType =
        ARK_WEB_DOWNLOAD_MANAGER;

}  // namespace OHOS::ArkWeb
