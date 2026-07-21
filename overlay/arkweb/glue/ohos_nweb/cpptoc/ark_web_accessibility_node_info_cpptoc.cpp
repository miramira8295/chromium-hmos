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

#include "ohos_nweb/cpptoc/ark_web_accessibility_node_info_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

ArkWebString ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_hint(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetHint();
}

ArkWebString ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_error(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetError();
}

int32_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_rect_x(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetRectX();
}

int32_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_rect_y(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetRectY();
}

void ARK_WEB_CALLBACK ark_web_accessibility_node_info_set_page_id(
    struct _ark_web_accessibility_node_info_t* self,
    int32_t page_id) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebAccessibilityNodeInfoCppToC::Get(self)->SetPageId(page_id);
}

int32_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_page_id(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetPageId();
}

ArkWebUint32Vector ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_actions(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_uint32_vector_default);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetActions();
}

ArkWebString ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_content(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetContent();
}

ArkWebInt64Vector ARK_WEB_CALLBACK
ark_web_accessibility_node_info_get_child_ids(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_int64_vector_default);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetChildIds();
}

void ARK_WEB_CALLBACK ark_web_accessibility_node_info_set_parent_id(
    struct _ark_web_accessibility_node_info_t* self,
    int64_t parentId_id) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebAccessibilityNodeInfoCppToC::Get(self)->SetParentId(parentId_id);
}

int64_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_parent_id(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetParentId();
}

bool ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_is_heading(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetIsHeading();
}

bool ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_is_checked(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetIsChecked();
}

bool ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_is_enabled(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetIsEnabled();
}

bool ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_is_focused(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetIsFocused();
}

int32_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_rect_width(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetRectWidth();
}

int32_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_rect_height(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetRectHeight();
}

bool ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_is_visible(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetIsVisible();
}

bool ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_is_hinting(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetIsHinting();
}

bool ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_is_editable(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetIsEditable();
}

bool ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_is_selected(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetIsSelected();
}

size_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_item_counts(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetItemCounts();
}

int32_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_live_region(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetLiveRegion();
}

bool ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_is_password(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetIsPassword();
}

bool ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_is_checkable(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetIsCheckable();
}

bool ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_is_clickable(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetIsClickable();
}

bool ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_is_focusable(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetIsFocusable();
}

bool ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_is_scrollable(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetIsScrollable();
}

bool ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_is_deletable(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetIsDeletable();
}

int64_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_accessibility_id(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetAccessibilityId();
}

bool ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_is_popup_supported(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetIsPopupSupported();
}

bool ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_is_content_invalid(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetIsContentInvalid();
}

int32_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_selection_end(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetSelectionEnd();
}

int32_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_selection_start(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetSelectionStart();
}

float ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_range_info_min(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetRangeInfoMin();
}

float ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_range_info_max(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetRangeInfoMax();
}

float ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_range_info_current(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetRangeInfoCurrent();
}

int32_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_input_type(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetInputType();
}

ArkWebString ARK_WEB_CALLBACK
ark_web_accessibility_node_info_get_component_type(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetComponentType();
}

ArkWebString ARK_WEB_CALLBACK
ark_web_accessibility_node_info_get_description_info(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetDescriptionInfo();
}

int32_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_grid_rows(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetGridRows();
}

int32_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_grid_item_row(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetGridItemRow();
}

int32_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_grid_columns(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetGridColumns();
}

int32_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_grid_item_column(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetGridItemColumn();
}

int32_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_grid_item_row_span(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetGridItemRowSpan();
}

int32_t ARK_WEB_CALLBACK ark_web_accessibility_node_info_get_grid_selected_mode(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetGridSelectedMode();
}

int32_t ARK_WEB_CALLBACK
ark_web_accessibility_node_info_get_grid_item_column_span(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetGridItemColumnSpan();
}

bool ARK_WEB_CALLBACK
ark_web_accessibility_node_info_get_is_accessibility_focus(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)
      ->GetIsAccessibilityFocus();
}

bool ARK_WEB_CALLBACK
ark_web_accessibility_node_info_get_is_plural_line_supported(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)
      ->GetIsPluralLineSupported();
}

bool ARK_WEB_CALLBACK
ark_web_accessibility_node_info_get_is_accessibility_group(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)
      ->GetIsAccessibilityGroup();
}

ArkWebString ARK_WEB_CALLBACK
ark_web_accessibility_node_info_get_accessibility_level(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetAccessibilityLevel();
}

ArkWebString ARK_WEB_CALLBACK
ark_web_accessibility_node_info_get_accessibility_description(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)
      ->GetAccessibilityDescription();
}

ArkWebString ARK_WEB_CALLBACK
ark_web_accessibility_node_info_get_accessibility_text(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetAccessibilityText();
}

ArkWebString ARK_WEB_CALLBACK
ark_web_accessibility_node_info_get_html_element_id(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetHtmlElementId();
}

ArkWebString ARK_WEB_CALLBACK
ark_web_accessibility_node_info_get_component_type_description(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)
      ->GetComponentTypeDescription();
}

int32_t ARK_WEB_CALLBACK
ark_web_accessibility_node_info_get_checkbox_group_selected_status(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)
      ->GetCheckboxGroupSelectedStatus();
}

ArkWebString ARK_WEB_CALLBACK
ark_web_accessibility_node_info_get_expanded_state(
    struct _ark_web_accessibility_node_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebAccessibilityNodeInfoCppToC::Get(self)->GetExpandedState();
}

}  // namespace

ArkWebAccessibilityNodeInfoCppToC::ArkWebAccessibilityNodeInfoCppToC() {
  GetStruct()->get_hint = ark_web_accessibility_node_info_get_hint;
  GetStruct()->get_error = ark_web_accessibility_node_info_get_error;
  GetStruct()->get_rect_x = ark_web_accessibility_node_info_get_rect_x;
  GetStruct()->get_rect_y = ark_web_accessibility_node_info_get_rect_y;
  GetStruct()->set_page_id = ark_web_accessibility_node_info_set_page_id;
  GetStruct()->get_page_id = ark_web_accessibility_node_info_get_page_id;
  GetStruct()->get_actions = ark_web_accessibility_node_info_get_actions;
  GetStruct()->get_content = ark_web_accessibility_node_info_get_content;
  GetStruct()->get_child_ids = ark_web_accessibility_node_info_get_child_ids;
  GetStruct()->set_parent_id = ark_web_accessibility_node_info_set_parent_id;
  GetStruct()->get_parent_id = ark_web_accessibility_node_info_get_parent_id;
  GetStruct()->get_is_heading = ark_web_accessibility_node_info_get_is_heading;
  GetStruct()->get_is_checked = ark_web_accessibility_node_info_get_is_checked;
  GetStruct()->get_is_enabled = ark_web_accessibility_node_info_get_is_enabled;
  GetStruct()->get_is_focused = ark_web_accessibility_node_info_get_is_focused;
  GetStruct()->get_rect_width = ark_web_accessibility_node_info_get_rect_width;
  GetStruct()->get_rect_height =
      ark_web_accessibility_node_info_get_rect_height;
  GetStruct()->get_is_visible = ark_web_accessibility_node_info_get_is_visible;
  GetStruct()->get_is_hinting = ark_web_accessibility_node_info_get_is_hinting;
  GetStruct()->get_is_editable =
      ark_web_accessibility_node_info_get_is_editable;
  GetStruct()->get_is_selected =
      ark_web_accessibility_node_info_get_is_selected;
  GetStruct()->get_item_counts =
      ark_web_accessibility_node_info_get_item_counts;
  GetStruct()->get_live_region =
      ark_web_accessibility_node_info_get_live_region;
  GetStruct()->get_is_password =
      ark_web_accessibility_node_info_get_is_password;
  GetStruct()->get_is_checkable =
      ark_web_accessibility_node_info_get_is_checkable;
  GetStruct()->get_is_clickable =
      ark_web_accessibility_node_info_get_is_clickable;
  GetStruct()->get_is_focusable =
      ark_web_accessibility_node_info_get_is_focusable;
  GetStruct()->get_is_scrollable =
      ark_web_accessibility_node_info_get_is_scrollable;
  GetStruct()->get_is_deletable =
      ark_web_accessibility_node_info_get_is_deletable;
  GetStruct()->get_accessibility_id =
      ark_web_accessibility_node_info_get_accessibility_id;
  GetStruct()->get_is_popup_supported =
      ark_web_accessibility_node_info_get_is_popup_supported;
  GetStruct()->get_is_content_invalid =
      ark_web_accessibility_node_info_get_is_content_invalid;
  GetStruct()->get_selection_end =
      ark_web_accessibility_node_info_get_selection_end;
  GetStruct()->get_selection_start =
      ark_web_accessibility_node_info_get_selection_start;
  GetStruct()->get_range_info_min =
      ark_web_accessibility_node_info_get_range_info_min;
  GetStruct()->get_range_info_max =
      ark_web_accessibility_node_info_get_range_info_max;
  GetStruct()->get_range_info_current =
      ark_web_accessibility_node_info_get_range_info_current;
  GetStruct()->get_input_type = ark_web_accessibility_node_info_get_input_type;
  GetStruct()->get_component_type =
      ark_web_accessibility_node_info_get_component_type;
  GetStruct()->get_description_info =
      ark_web_accessibility_node_info_get_description_info;
  GetStruct()->get_grid_rows = ark_web_accessibility_node_info_get_grid_rows;
  GetStruct()->get_grid_item_row =
      ark_web_accessibility_node_info_get_grid_item_row;
  GetStruct()->get_grid_columns =
      ark_web_accessibility_node_info_get_grid_columns;
  GetStruct()->get_grid_item_column =
      ark_web_accessibility_node_info_get_grid_item_column;
  GetStruct()->get_grid_item_row_span =
      ark_web_accessibility_node_info_get_grid_item_row_span;
  GetStruct()->get_grid_selected_mode =
      ark_web_accessibility_node_info_get_grid_selected_mode;
  GetStruct()->get_grid_item_column_span =
      ark_web_accessibility_node_info_get_grid_item_column_span;
  GetStruct()->get_is_accessibility_focus =
      ark_web_accessibility_node_info_get_is_accessibility_focus;
  GetStruct()->get_is_plural_line_supported =
      ark_web_accessibility_node_info_get_is_plural_line_supported;
  GetStruct()->get_is_accessibility_group =
      ark_web_accessibility_node_info_get_is_accessibility_group;
  GetStruct()->get_accessibility_level =
      ark_web_accessibility_node_info_get_accessibility_level;
  GetStruct()->get_accessibility_description =
      ark_web_accessibility_node_info_get_accessibility_description;
  GetStruct()->get_accessibility_text =
      ark_web_accessibility_node_info_get_accessibility_text;
  GetStruct()->get_html_element_id =
      ark_web_accessibility_node_info_get_html_element_id;
  GetStruct()->get_component_type_description =
      ark_web_accessibility_node_info_get_component_type_description;
  GetStruct()->get_checkbox_group_selected_status =
      ark_web_accessibility_node_info_get_checkbox_group_selected_status;
  GetStruct()->get_expanded_state =
      ark_web_accessibility_node_info_get_expanded_state;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["EtAlWzy8qVUS_u3YeaBxAw"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_hint);
    funcMemberMap["NvKod6_AkCm2Wo67hf1Ypw"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_error);
    funcMemberMap["dhmpxeE_dQ342PCeofKkow"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_rect_x);
    funcMemberMap["by4p6_gu3$eSC$NMzUrh_Q"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_rect_y);
    funcMemberMap["TcVn2AxiKQ5NHcTEq5JEvg"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_set_page_id);
    funcMemberMap["aYEJ_3OzxZTBdm9bohWOFw"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_page_id);
    funcMemberMap["qOirvM3Ob_n2mOhRmj9Rrw"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_actions);
    funcMemberMap["3kvu0IDMVZ0VE7zE_MMfWw"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_content);
    funcMemberMap["$njRYfn2YTB_AoJtB06tbA"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_child_ids);
    funcMemberMap["OY226qQ8qqzYmZuMndFqHw"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_set_parent_id);
    funcMemberMap["Ab5ljRkdHNhRtLQSWrdWHw"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_parent_id);
    funcMemberMap["m0o4vNRgZC6S5roWCmP44w"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_is_heading);
    funcMemberMap["WIMdNuQIHrHVGHS6n6Knkg"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_is_checked);
    funcMemberMap["m3e_z0cki$efPmX$iLFJaA"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_is_enabled);
    funcMemberMap["IVL2nfFe$GJT0BHTwDuu$g"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_is_focused);
    funcMemberMap["VfJidjban_CpU1AZV1fJ9A"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_rect_width);
    funcMemberMap["fdOUL6B0nQENufP9ZlnPLw"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_rect_height);
    funcMemberMap["JnpYR_uR7R6zn0Y5Ge_dmQ"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_is_visible);
    funcMemberMap["OGnV$yrBG4YTu2OUcGs7cg"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_is_hinting);
    funcMemberMap["dI_yoHeWxdjGnsouqdl9wg"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_is_editable);
    funcMemberMap["$v1uZdgFkS7DRkXTEVvrsQ"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_is_selected);
    funcMemberMap["MOGqC3Wx2JkOnnRKYFuV5g"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_item_counts);
    funcMemberMap["chT0CWMeK3$E6BQeQmvL0Q"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_live_region);
    funcMemberMap["uLK2wInDdYyCGKd82wd5Vw"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_is_password);
    funcMemberMap["snsd9SgyFQyG4pOfrf0_cA"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_is_checkable);
    funcMemberMap["KVnywcVJUH7dGRKJJRq$Bw"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_is_clickable);
    funcMemberMap["EfQGWsgOmbfWVyXl9d$R4w"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_is_focusable);
    funcMemberMap["9MUQkx6ihL91nHONSa9$AQ"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_is_scrollable);
    funcMemberMap["rpSJWhPMfL6IyxtMSMxAQw"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_is_deletable);
    funcMemberMap["R2_wb1e0S9GNPfX1A$oSZg"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_accessibility_id);
    funcMemberMap["ZOMaSBFPevZa0E4PoXZTnA"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_is_popup_supported);
    funcMemberMap["YNe1WKLtdZ_wa5JViiG4dw"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_is_content_invalid);
    funcMemberMap["zPZz2KeYw4YUsacHhG9ojg"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_selection_end);
    funcMemberMap["ZcTW$InfRLvDYCCju5Izgg"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_selection_start);
    funcMemberMap["zdwBJ8EJJEQnqlpk6xDrOA"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_range_info_min);
    funcMemberMap["9He4WTkOqSpgF3v$h6sbbA"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_range_info_max);
    funcMemberMap["OJPlMfs9WL1USKeyMGDIqA"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_range_info_current);
    funcMemberMap["FG4mm1Hpoqs0lorCExiN6A"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_input_type);
    funcMemberMap["HQPjKx3IRmOQ7UmMpXZOJw"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_component_type);
    funcMemberMap["OgVkoa5vCEkGJgz6lyB9oA"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_description_info);
    funcMemberMap["XMjIcP97qDd_O32_ofHzXg"] =
        reinterpret_cast<void*>(ark_web_accessibility_node_info_get_grid_rows);
    funcMemberMap["p$ZlAQdn7_xqp9j35Zbo6A"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_grid_item_row);
    funcMemberMap["0oJxDHmtgzGu8LwPRbumHg"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_grid_columns);
    funcMemberMap["edZ7pcPZ1hZsUfzNEBJ3_A"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_grid_item_column);
    funcMemberMap["DBXjpBnt0aDEpbzXF3Abig"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_grid_item_row_span);
    funcMemberMap["SCdWOHyI8GO3jrxQGZw8pA"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_grid_selected_mode);
    funcMemberMap["$P8nF1KpjfudgNlh4g7QsQ"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_grid_item_column_span);
    funcMemberMap["Y8sOSIEU7W3HB$ZbFC4guw"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_is_accessibility_focus);
    funcMemberMap["StDoixUFHdbG_TZe_McA7Q"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_is_plural_line_supported);
    funcMemberMap["qks1IFQQNlWa8l9T5eVMtw"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_is_accessibility_group);
    funcMemberMap["PMWmYpeGz$fqR2KDnpHLVA"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_accessibility_level);
    funcMemberMap["ETOwG9ArEXmhTaO6w27DQQ"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_accessibility_description);
    funcMemberMap["cSymo7x$H2FYqtZrgj1Q5g"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_accessibility_text);
    funcMemberMap["tr3$oIfwSjjB9GmCdKO8bQ"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_html_element_id);
    funcMemberMap["Tp_4ojBppB5ZpLkx5o45iw"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_component_type_description);
    funcMemberMap["tScx8IIQM2AqM_mAERxOgg"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_checkbox_group_selected_status);
    funcMemberMap["KuPazYPDEXbAtwsuDbwxXg"] = reinterpret_cast<void*>(
        ark_web_accessibility_node_info_get_expanded_state);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_ACCESSIBILITY_NODE_INFO, funcMemberMap);
  });
}

ArkWebAccessibilityNodeInfoCppToC::~ArkWebAccessibilityNodeInfoCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebAccessibilityNodeInfoCppToC,
                           ArkWebAccessibilityNodeInfo,
                           ark_web_accessibility_node_info_t>::kBridgeType =
        ARK_WEB_ACCESSIBILITY_NODE_INFO;

}  // namespace OHOS::ArkWeb
