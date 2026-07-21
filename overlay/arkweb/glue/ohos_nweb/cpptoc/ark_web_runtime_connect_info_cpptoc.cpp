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

#include "ohos_nweb/cpptoc/ark_web_runtime_connect_info_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

ArkWebString ARK_WEB_CALLBACK ark_web_runtime_connect_info_get_bundle_name(
    struct _ark_web_runtime_connect_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebRuntimeConnectInfoCppToC::Get(self)->GetBundleName();
}

ArkWebString ARK_WEB_CALLBACK ark_web_runtime_connect_info_get_extension_origin(
    struct _ark_web_runtime_connect_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebRuntimeConnectInfoCppToC::Get(self)->GetExtensionOrigin();
}

int ARK_WEB_CALLBACK ark_web_runtime_connect_info_get_message_read_pipe(
    struct _ark_web_runtime_connect_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebRuntimeConnectInfoCppToC::Get(self)->GetMessageReadPipe();
}

int ARK_WEB_CALLBACK ark_web_runtime_connect_info_get_message_write_pipe(
    struct _ark_web_runtime_connect_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebRuntimeConnectInfoCppToC::Get(self)->GetMessageWritePipe();
}

}  // namespace

ArkWebRuntimeConnectInfoCppToC::ArkWebRuntimeConnectInfoCppToC() {
  GetStruct()->get_bundle_name = ark_web_runtime_connect_info_get_bundle_name;
  GetStruct()->get_extension_origin =
      ark_web_runtime_connect_info_get_extension_origin;
  GetStruct()->get_message_read_pipe =
      ark_web_runtime_connect_info_get_message_read_pipe;
  GetStruct()->get_message_write_pipe =
      ark_web_runtime_connect_info_get_message_write_pipe;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["$ncvUw851R75vINbdzW7CA"] =
        reinterpret_cast<void*>(ark_web_runtime_connect_info_get_bundle_name);
    funcMemberMap["noIMpXx53mVeNihWmGEDKQ"] = reinterpret_cast<void*>(
        ark_web_runtime_connect_info_get_extension_origin);
    funcMemberMap["r$lBSADuSOz5lMECxX7EdQ"] = reinterpret_cast<void*>(
        ark_web_runtime_connect_info_get_message_read_pipe);
    funcMemberMap["Y2Zuz8v3bK4IY$cIKaogtQ"] = reinterpret_cast<void*>(
        ark_web_runtime_connect_info_get_message_write_pipe);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_RUNTIME_CONNECT_INFO, funcMemberMap);
  });
}

ArkWebRuntimeConnectInfoCppToC::~ArkWebRuntimeConnectInfoCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebRuntimeConnectInfoCppToC,
                           ArkWebRuntimeConnectInfo,
                           ark_web_runtime_connect_info_t>::kBridgeType =
        ARK_WEB_RUNTIME_CONNECT_INFO;

}  // namespace OHOS::ArkWeb
