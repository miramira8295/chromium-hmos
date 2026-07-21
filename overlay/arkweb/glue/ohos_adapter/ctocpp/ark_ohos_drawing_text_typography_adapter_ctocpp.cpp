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

#include "ohos_adapter/ctocpp/ark_ohos_drawing_text_typography_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkOhosDrawingTextTypographyAdapterGetSystemFontConfigInfoFunc =
    int (*)(struct _ark_ohos_drawing_text_typography_adapter_t* self,
            void* fontConfigInfoErrorCode,
            void** fontConfigInfo);
static ArkOhosDrawingTextTypographyAdapterGetSystemFontConfigInfoFunc
    ark_ohos_drawing_text_typography_adapter_get_system_font_config_info =
        reinterpret_cast<
            ArkOhosDrawingTextTypographyAdapterGetSystemFontConfigInfoFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosDrawingTextTypographyAdapterGetDrawingArraySizeFunc =
    int (*)(struct _ark_ohos_drawing_text_typography_adapter_t* self,
            void* drawingArray,
            int32_t* sizeOfArray);
static ArkOhosDrawingTextTypographyAdapterGetDrawingArraySizeFunc
    ark_ohos_drawing_text_typography_adapter_get_drawing_array_size =
        reinterpret_cast<
            ArkOhosDrawingTextTypographyAdapterGetDrawingArraySizeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosDrawingTextTypographyAdapterDestroySystemFontConfigInfoFunc =
    void (*)(struct _ark_ohos_drawing_text_typography_adapter_t* self,
             void* fontConfigInfo);
static ArkOhosDrawingTextTypographyAdapterDestroySystemFontConfigInfoFunc
    ark_ohos_drawing_text_typography_adapter_destroy_system_font_config_info =
        reinterpret_cast<
            ArkOhosDrawingTextTypographyAdapterDestroySystemFontConfigInfoFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int ArkOhosDrawingTextTypographyAdapterCToCpp::GetSystemFontConfigInfo(
    void* fontConfigInfoErrorCode,
    void** fontConfigInfo) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_drawing_text_typography_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_drawing_text_typography_adapter_get_system_font_config_info);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Lv0Vc5Zvf44DjxKU5K2yeA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_OHOS_DRAWING_TEXT_TYPOGRAPHY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_drawing_text_typography_adapter_get_system_font_config_"
          "info");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_system_font_config_info)) {
        ark_ohos_drawing_text_typography_adapter_get_system_font_config_info =
            nullptr;
      } else {
        ark_ohos_drawing_text_typography_adapter_get_system_font_config_info =
            _struct->get_system_font_config_info;
      }
    } else {
      ark_ohos_drawing_text_typography_adapter_get_system_font_config_info =
          reinterpret_cast<
              ArkOhosDrawingTextTypographyAdapterGetSystemFontConfigInfoFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_drawing_text_typography_adapter_get_system_font_config_info, 0);

  // Execute
  return ark_ohos_drawing_text_typography_adapter_get_system_font_config_info(
      _struct, fontConfigInfoErrorCode, fontConfigInfo);
}

ARK_WEB_NO_SANITIZE
int ArkOhosDrawingTextTypographyAdapterCToCpp::GetDrawingArraySize(
    void* drawingArray,
    int32_t& sizeOfArray) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_drawing_text_typography_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_drawing_text_typography_adapter_get_drawing_array_size);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Ob5oIuGglujOBo9fPp1eyg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_OHOS_DRAWING_TEXT_TYPOGRAPHY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_drawing_text_typography_adapter_get_drawing_array_size");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_drawing_array_size)) {
        ark_ohos_drawing_text_typography_adapter_get_drawing_array_size =
            nullptr;
      } else {
        ark_ohos_drawing_text_typography_adapter_get_drawing_array_size =
            _struct->get_drawing_array_size;
      }
    } else {
      ark_ohos_drawing_text_typography_adapter_get_drawing_array_size =
          reinterpret_cast<
              ArkOhosDrawingTextTypographyAdapterGetDrawingArraySizeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_drawing_text_typography_adapter_get_drawing_array_size, 0);

  // Execute
  return ark_ohos_drawing_text_typography_adapter_get_drawing_array_size(
      _struct, drawingArray, &sizeOfArray);
}

ARK_WEB_NO_SANITIZE
void ArkOhosDrawingTextTypographyAdapterCToCpp::DestroySystemFontConfigInfo(
    void* fontConfigInfo) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_drawing_text_typography_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_drawing_text_typography_adapter_destroy_system_font_config_info);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "HnAY$qfOqi1TkFaUqmxpZA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_OHOS_DRAWING_TEXT_TYPOGRAPHY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_drawing_text_typography_adapter_destroy_system_font_config_"
          "info");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      destroy_system_font_config_info)) {
        ark_ohos_drawing_text_typography_adapter_destroy_system_font_config_info =
            nullptr;
      } else {
        ark_ohos_drawing_text_typography_adapter_destroy_system_font_config_info =
            _struct->destroy_system_font_config_info;
      }
    } else {
      ark_ohos_drawing_text_typography_adapter_destroy_system_font_config_info =
          reinterpret_cast<
              ArkOhosDrawingTextTypographyAdapterDestroySystemFontConfigInfoFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_drawing_text_typography_adapter_destroy_system_font_config_info,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_ohos_drawing_text_typography_adapter_destroy_system_font_config_info(
      _struct, fontConfigInfo);
}

ArkOhosDrawingTextTypographyAdapterCToCpp::
    ArkOhosDrawingTextTypographyAdapterCToCpp() {}

ArkOhosDrawingTextTypographyAdapterCToCpp::
    ~ArkOhosDrawingTextTypographyAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<
    ArkOhosDrawingTextTypographyAdapterCToCpp,
    ArkOhosDrawingTextTypographyAdapter,
    ark_ohos_drawing_text_typography_adapter_t>::kBridgeType =
    ARK_OHOS_DRAWING_TEXT_TYPOGRAPHY_ADAPTER;

}  // namespace OHOS::ArkWeb
