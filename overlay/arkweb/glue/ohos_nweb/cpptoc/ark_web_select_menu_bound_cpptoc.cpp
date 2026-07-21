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

#include "ohos_nweb/cpptoc/ark_web_select_menu_bound_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

int ARK_WEB_CALLBACK
ark_web_select_menu_bound_get_x(struct _ark_web_select_menu_bound_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebSelectMenuBoundCppToC::Get(self)->GetX();
}

int ARK_WEB_CALLBACK
ark_web_select_menu_bound_get_y(struct _ark_web_select_menu_bound_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebSelectMenuBoundCppToC::Get(self)->GetY();
}

int ARK_WEB_CALLBACK
ark_web_select_menu_bound_get_width(struct _ark_web_select_menu_bound_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebSelectMenuBoundCppToC::Get(self)->GetWidth();
}

int ARK_WEB_CALLBACK ark_web_select_menu_bound_get_height(
    struct _ark_web_select_menu_bound_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebSelectMenuBoundCppToC::Get(self)->GetHeight();
}

}  // namespace

ArkWebSelectMenuBoundCppToC::ArkWebSelectMenuBoundCppToC() {
  GetStruct()->get_x = ark_web_select_menu_bound_get_x;
  GetStruct()->get_y = ark_web_select_menu_bound_get_y;
  GetStruct()->get_width = ark_web_select_menu_bound_get_width;
  GetStruct()->get_height = ark_web_select_menu_bound_get_height;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["AtUi_hX9SZvif6ea9vspkA"] =
        reinterpret_cast<void*>(ark_web_select_menu_bound_get_x);
    funcMemberMap["1eRZGZLq82Xht_HjwBGXiQ"] =
        reinterpret_cast<void*>(ark_web_select_menu_bound_get_y);
    funcMemberMap["4mSXauhiE5fDoSuc6h$wUw"] =
        reinterpret_cast<void*>(ark_web_select_menu_bound_get_width);
    funcMemberMap["qjXo$37OK8lHnpZKVmeKLg"] =
        reinterpret_cast<void*>(ark_web_select_menu_bound_get_height);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_SELECT_MENU_BOUND, funcMemberMap);
  });
}

ArkWebSelectMenuBoundCppToC::~ArkWebSelectMenuBoundCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebSelectMenuBoundCppToC,
                           ArkWebSelectMenuBound,
                           ark_web_select_menu_bound_t>::kBridgeType =
        ARK_WEB_SELECT_MENU_BOUND;

}  // namespace OHOS::ArkWeb
