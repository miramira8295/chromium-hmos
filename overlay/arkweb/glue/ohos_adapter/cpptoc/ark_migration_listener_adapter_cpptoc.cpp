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

#include "ohos_adapter/cpptoc/ark_migration_listener_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK ark_migration_listener_adapter_on_migration_reply(
    struct _ark_migration_listener_adapter_t* self,
    int32_t errorCode,
    int32_t succussCount,
    const ArkWebInt32Vector* errorIndex,
    const ArkWebInt32Vector* codeIndex) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(errorIndex, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(codeIndex, ARK_WEB_RETURN_VOID);

  // Execute
  ArkMigrationListenerAdapterCppToC::Get(self)->OnMigrationReply(
      errorCode, succussCount, *errorIndex, *codeIndex);
}

}  // namespace

ArkMigrationListenerAdapterCppToC::ArkMigrationListenerAdapterCppToC() {
  GetStruct()->on_migration_reply =
      ark_migration_listener_adapter_on_migration_reply;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["IvehriaI0xb792qiaqXAMA"] = reinterpret_cast<void*>(
        ark_migration_listener_adapter_on_migration_reply);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_MIGRATION_LISTENER_ADAPTER, funcMemberMap);
  });
}

ArkMigrationListenerAdapterCppToC::~ArkMigrationListenerAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkMigrationListenerAdapterCppToC,
                           ArkMigrationListenerAdapter,
                           ark_migration_listener_adapter_t>::kBridgeType =
        ARK_MIGRATION_LISTENER_ADAPTER;

}  // namespace OHOS::ArkWeb
