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

#include "ohos_nweb/cpptoc/ark_web_history_list_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"
#include "ohos_nweb/cpptoc/ark_web_history_item_cpptoc.h"

namespace OHOS::ArkWeb {

namespace {

ark_web_history_item_t* ARK_WEB_CALLBACK
ark_web_history_list_get_item(struct _ark_web_history_list_t* self,
                              int32_t index) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebHistoryItem> _retval =
      ArkWebHistoryListCppToC::Get(self)->GetItem(index);

  // Return type: refptr_same
  return ArkWebHistoryItemCppToC::Invert(_retval);
}

int32_t ARK_WEB_CALLBACK
ark_web_history_list_get_list_size(struct _ark_web_history_list_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebHistoryListCppToC::Get(self)->GetListSize();
}

int32_t ARK_WEB_CALLBACK
ark_web_history_list_get_current_index(struct _ark_web_history_list_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebHistoryListCppToC::Get(self)->GetCurrentIndex();
}

}  // namespace

ArkWebHistoryListCppToC::ArkWebHistoryListCppToC() {
  GetStruct()->get_item = ark_web_history_list_get_item;
  GetStruct()->get_list_size = ark_web_history_list_get_list_size;
  GetStruct()->get_current_index = ark_web_history_list_get_current_index;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["tmcEpibVuNYC3E6HxX4ytg"] =
        reinterpret_cast<void*>(ark_web_history_list_get_item);
    funcMemberMap["Q1Tsc6utNzbVnLWx3HM41Q"] =
        reinterpret_cast<void*>(ark_web_history_list_get_list_size);
    funcMemberMap["xD0JIcjxYKzRnBm_iTvloQ"] =
        reinterpret_cast<void*>(ark_web_history_list_get_current_index);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_HISTORY_LIST, funcMemberMap);
  });
}

ArkWebHistoryListCppToC::~ArkWebHistoryListCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<ArkWebHistoryListCppToC,
                                        ArkWebHistoryList,
                                        ark_web_history_list_t>::kBridgeType =
    ARK_WEB_HISTORY_LIST;

}  // namespace OHOS::ArkWeb
