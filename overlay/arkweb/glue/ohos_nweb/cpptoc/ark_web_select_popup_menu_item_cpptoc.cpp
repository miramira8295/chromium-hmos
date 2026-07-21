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

#include "ohos_nweb/cpptoc/ark_web_select_popup_menu_item_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

int ARK_WEB_CALLBACK ark_web_select_popup_menu_item_get_type(
    struct _ark_web_select_popup_menu_item_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebSelectPopupMenuItemCppToC::Get(self)->GetType();
}

ArkWebString ARK_WEB_CALLBACK ark_web_select_popup_menu_item_get_label(
    struct _ark_web_select_popup_menu_item_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebSelectPopupMenuItemCppToC::Get(self)->GetLabel();
}

uint32_t ARK_WEB_CALLBACK ark_web_select_popup_menu_item_get_action(
    struct _ark_web_select_popup_menu_item_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebSelectPopupMenuItemCppToC::Get(self)->GetAction();
}

ArkWebString ARK_WEB_CALLBACK ark_web_select_popup_menu_item_get_tool_tip(
    struct _ark_web_select_popup_menu_item_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebSelectPopupMenuItemCppToC::Get(self)->GetToolTip();
}

bool ARK_WEB_CALLBACK ark_web_select_popup_menu_item_get_is_checked(
    struct _ark_web_select_popup_menu_item_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebSelectPopupMenuItemCppToC::Get(self)->GetIsChecked();
}

bool ARK_WEB_CALLBACK ark_web_select_popup_menu_item_get_is_enabled(
    struct _ark_web_select_popup_menu_item_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebSelectPopupMenuItemCppToC::Get(self)->GetIsEnabled();
}

int ARK_WEB_CALLBACK ark_web_select_popup_menu_item_get_text_direction(
    struct _ark_web_select_popup_menu_item_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebSelectPopupMenuItemCppToC::Get(self)->GetTextDirection();
}

bool ARK_WEB_CALLBACK
ark_web_select_popup_menu_item_get_has_text_direction_override(
    struct _ark_web_select_popup_menu_item_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebSelectPopupMenuItemCppToC::Get(self)
      ->GetHasTextDirectionOverride();
}

}  // namespace

ArkWebSelectPopupMenuItemCppToC::ArkWebSelectPopupMenuItemCppToC() {
  GetStruct()->get_type = ark_web_select_popup_menu_item_get_type;
  GetStruct()->get_label = ark_web_select_popup_menu_item_get_label;
  GetStruct()->get_action = ark_web_select_popup_menu_item_get_action;
  GetStruct()->get_tool_tip = ark_web_select_popup_menu_item_get_tool_tip;
  GetStruct()->get_is_checked = ark_web_select_popup_menu_item_get_is_checked;
  GetStruct()->get_is_enabled = ark_web_select_popup_menu_item_get_is_enabled;
  GetStruct()->get_text_direction =
      ark_web_select_popup_menu_item_get_text_direction;
  GetStruct()->get_has_text_direction_override =
      ark_web_select_popup_menu_item_get_has_text_direction_override;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["t4chKh5cSxi5bDg6zcohfw"] =
        reinterpret_cast<void*>(ark_web_select_popup_menu_item_get_type);
    funcMemberMap["CtCjt39NLnhVaDmNYZZ1cg"] =
        reinterpret_cast<void*>(ark_web_select_popup_menu_item_get_label);
    funcMemberMap["v5tjR8$zaPcUVlwJusJo3g"] =
        reinterpret_cast<void*>(ark_web_select_popup_menu_item_get_action);
    funcMemberMap["5KLyw86L42aMlOhR9ezvtg"] =
        reinterpret_cast<void*>(ark_web_select_popup_menu_item_get_tool_tip);
    funcMemberMap["RSvCkPM6CwaBgPH1PAipdA"] =
        reinterpret_cast<void*>(ark_web_select_popup_menu_item_get_is_checked);
    funcMemberMap["4XQNuDr8fUFHuiZUCqNJOA"] =
        reinterpret_cast<void*>(ark_web_select_popup_menu_item_get_is_enabled);
    funcMemberMap["YbXP_kyMR5NJ3bvYD_2DpA"] = reinterpret_cast<void*>(
        ark_web_select_popup_menu_item_get_text_direction);
    funcMemberMap["gip9WWtiswqO2pad8JxqOw"] = reinterpret_cast<void*>(
        ark_web_select_popup_menu_item_get_has_text_direction_override);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_SELECT_POPUP_MENU_ITEM, funcMemberMap);
  });
}

ArkWebSelectPopupMenuItemCppToC::~ArkWebSelectPopupMenuItemCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebSelectPopupMenuItemCppToC,
                           ArkWebSelectPopupMenuItem,
                           ark_web_select_popup_menu_item_t>::kBridgeType =
        ARK_WEB_SELECT_POPUP_MENU_ITEM;

}  // namespace OHOS::ArkWeb
