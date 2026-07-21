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

#include "ohos_nweb/cpptoc/ark_web_console_log_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

ArkWebString ARK_WEB_CALLBACK
ark_web_console_log_log(struct _ark_web_console_log_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebConsoleLogCppToC::Get(self)->Log();
}

ArkWebString ARK_WEB_CALLBACK
ark_web_console_log_source_id(struct _ark_web_console_log_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebConsoleLogCppToC::Get(self)->SourceId();
}

int ARK_WEB_CALLBACK
ark_web_console_log_log_level(struct _ark_web_console_log_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebConsoleLogCppToC::Get(self)->LogLevel();
}

int ARK_WEB_CALLBACK
ark_web_console_log_line_numer(struct _ark_web_console_log_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebConsoleLogCppToC::Get(self)->LineNumer();
}

}  // namespace

ArkWebConsoleLogCppToC::ArkWebConsoleLogCppToC() {
  GetStruct()->log = ark_web_console_log_log;
  GetStruct()->source_id = ark_web_console_log_source_id;
  GetStruct()->log_level = ark_web_console_log_log_level;
  GetStruct()->line_numer = ark_web_console_log_line_numer;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["9ZYITXowvnt3mHgz5y4mYg"] =
        reinterpret_cast<void*>(ark_web_console_log_log);
    funcMemberMap["gUeUdGjTMJjjcK9UrS8Ukg"] =
        reinterpret_cast<void*>(ark_web_console_log_source_id);
    funcMemberMap["kIFiM0Z3hUE9XEJrRcOpLw"] =
        reinterpret_cast<void*>(ark_web_console_log_log_level);
    funcMemberMap["mdfRPrK6npYWjlUODwR6fw"] =
        reinterpret_cast<void*>(ark_web_console_log_line_numer);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_CONSOLE_LOG, funcMemberMap);
  });
}

ArkWebConsoleLogCppToC::~ArkWebConsoleLogCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<ArkWebConsoleLogCppToC,
                                        ArkWebConsoleLog,
                                        ark_web_console_log_t>::kBridgeType =
    ARK_WEB_CONSOLE_LOG;

}  // namespace OHOS::ArkWeb
