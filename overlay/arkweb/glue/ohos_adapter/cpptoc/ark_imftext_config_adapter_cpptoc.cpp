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

#include "ohos_adapter/cpptoc/ark_imftext_config_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_imfcursor_info_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_imfinput_attribute_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_imfselection_range_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

namespace {

ark_imfinput_attribute_adapter_t* ARK_WEB_CALLBACK
ark_imftext_config_adapter_get_input_attribute(
    struct _ark_imftext_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkIMFInputAttributeAdapter> _retval =
      ArkIMFTextConfigAdapterCppToC::Get(self)->GetInputAttribute();

  // Return type: refptr_same
  return ArkIMFInputAttributeAdapterCppToC::Invert(_retval);
}

ark_imfcursor_info_adapter_t* ARK_WEB_CALLBACK
ark_imftext_config_adapter_get_cursor_info(
    struct _ark_imftext_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkIMFCursorInfoAdapter> _retval =
      ArkIMFTextConfigAdapterCppToC::Get(self)->GetCursorInfo();

  // Return type: refptr_same
  return ArkIMFCursorInfoAdapterCppToC::Invert(_retval);
}

ark_imfselection_range_adapter_t* ARK_WEB_CALLBACK
ark_imftext_config_adapter_get_selection_range(
    struct _ark_imftext_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkIMFSelectionRangeAdapter> _retval =
      ArkIMFTextConfigAdapterCppToC::Get(self)->GetSelectionRange();

  // Return type: refptr_same
  return ArkIMFSelectionRangeAdapterCppToC::Invert(_retval);
}

uint32_t ARK_WEB_CALLBACK ark_imftext_config_adapter_get_window_id(
    struct _ark_imftext_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkIMFTextConfigAdapterCppToC::Get(self)->GetWindowId();
}

double ARK_WEB_CALLBACK ark_imftext_config_adapter_get_position_y(
    struct _ark_imftext_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkIMFTextConfigAdapterCppToC::Get(self)->GetPositionY();
}

double ARK_WEB_CALLBACK ark_imftext_config_adapter_get_height(
    struct _ark_imftext_config_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkIMFTextConfigAdapterCppToC::Get(self)->GetHeight();
}

}  // namespace

ArkIMFTextConfigAdapterCppToC::ArkIMFTextConfigAdapterCppToC() {
  GetStruct()->get_input_attribute =
      ark_imftext_config_adapter_get_input_attribute;
  GetStruct()->get_cursor_info = ark_imftext_config_adapter_get_cursor_info;
  GetStruct()->get_selection_range =
      ark_imftext_config_adapter_get_selection_range;
  GetStruct()->get_window_id = ark_imftext_config_adapter_get_window_id;
  GetStruct()->get_position_y = ark_imftext_config_adapter_get_position_y;
  GetStruct()->get_height = ark_imftext_config_adapter_get_height;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["dhhLQJP1qSvPv8wVy_QTfg"] =
        reinterpret_cast<void*>(ark_imftext_config_adapter_get_input_attribute);
    funcMemberMap["xYgOAT1_gT5_XuscLIWYdg"] =
        reinterpret_cast<void*>(ark_imftext_config_adapter_get_cursor_info);
    funcMemberMap["CzqCMoRG37yU81vvAIQz4w"] =
        reinterpret_cast<void*>(ark_imftext_config_adapter_get_selection_range);
    funcMemberMap["ZREhAqqgHHubIS0PCDenuw"] =
        reinterpret_cast<void*>(ark_imftext_config_adapter_get_window_id);
    funcMemberMap["KmK505QQKYBb7geZELxRMg"] =
        reinterpret_cast<void*>(ark_imftext_config_adapter_get_position_y);
    funcMemberMap["kawmvbVHyWF6tMmxiFyluQ"] =
        reinterpret_cast<void*>(ark_imftext_config_adapter_get_height);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_IMFTEXT_CONFIG_ADAPTER, funcMemberMap);
  });
}

ArkIMFTextConfigAdapterCppToC::~ArkIMFTextConfigAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkIMFTextConfigAdapterCppToC,
                           ArkIMFTextConfigAdapter,
                           ark_imftext_config_adapter_t>::kBridgeType =
        ARK_IMFTEXT_CONFIG_ADAPTER;

}  // namespace OHOS::ArkWeb
