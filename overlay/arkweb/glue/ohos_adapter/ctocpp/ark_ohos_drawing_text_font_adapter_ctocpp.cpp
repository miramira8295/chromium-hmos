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

#include "ohos_adapter/ctocpp/ark_ohos_drawing_text_font_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkOhosDrawingTextFontAdapterGetSystemFontFullNamesByTypeFunc =
    int (*)(struct _ark_ohos_drawing_text_font_adapter_t* self,
            int32_t systemFontType,
            void** drawingArray);
static ArkOhosDrawingTextFontAdapterGetSystemFontFullNamesByTypeFunc
    ark_ohos_drawing_text_font_adapter_get_system_font_full_names_by_type =
        reinterpret_cast<
            ArkOhosDrawingTextFontAdapterGetSystemFontFullNamesByTypeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosDrawingTextFontAdapterGetFontDescriptorByFullNameFunc =
    int (*)(struct _ark_ohos_drawing_text_font_adapter_t* self,
            void* drawingString,
            int32_t systemFontType,
            void** drawingFontDescriptor);
static ArkOhosDrawingTextFontAdapterGetFontDescriptorByFullNameFunc
    ark_ohos_drawing_text_font_adapter_get_font_descriptor_by_full_name =
        reinterpret_cast<
            ArkOhosDrawingTextFontAdapterGetFontDescriptorByFullNameFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosDrawingTextFontAdapterGetSystemFontFullNameByIndexFunc =
    int (*)(struct _ark_ohos_drawing_text_font_adapter_t* self,
            void* drawingArray,
            int32_t indexOfFullName,
            const void** drawingString);
static ArkOhosDrawingTextFontAdapterGetSystemFontFullNameByIndexFunc
    ark_ohos_drawing_text_font_adapter_get_system_font_full_name_by_index =
        reinterpret_cast<
            ArkOhosDrawingTextFontAdapterGetSystemFontFullNameByIndexFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosDrawingTextFontAdapterDestroySystemFontFullNamesFunc =
    void (*)(struct _ark_ohos_drawing_text_font_adapter_t* self,
             void* drawingArray);
static ArkOhosDrawingTextFontAdapterDestroySystemFontFullNamesFunc
    ark_ohos_drawing_text_font_adapter_destroy_system_font_full_names =
        reinterpret_cast<
            ArkOhosDrawingTextFontAdapterDestroySystemFontFullNamesFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosDrawingTextFontAdapterDestroyFontDescriptorFunc =
    void (*)(struct _ark_ohos_drawing_text_font_adapter_t* self,
             void* descriptor);
static ArkOhosDrawingTextFontAdapterDestroyFontDescriptorFunc
    ark_ohos_drawing_text_font_adapter_destroy_font_descriptor =
        reinterpret_cast<
            ArkOhosDrawingTextFontAdapterDestroyFontDescriptorFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int ArkOhosDrawingTextFontAdapterCToCpp::GetSystemFontFullNamesByType(
    int32_t systemFontType,
    void** drawingArray) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_drawing_text_font_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_drawing_text_font_adapter_get_system_font_full_names_by_type);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "HDBOAjJjk3kSEcuUbb5e_w";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_OHOS_DRAWING_TEXT_FONT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_drawing_text_font_adapter_get_system_font_full_names_by_"
          "type");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_system_font_full_names_by_type)) {
        ark_ohos_drawing_text_font_adapter_get_system_font_full_names_by_type =
            nullptr;
      } else {
        ark_ohos_drawing_text_font_adapter_get_system_font_full_names_by_type =
            _struct->get_system_font_full_names_by_type;
      }
    } else {
      ark_ohos_drawing_text_font_adapter_get_system_font_full_names_by_type =
          reinterpret_cast<
              ArkOhosDrawingTextFontAdapterGetSystemFontFullNamesByTypeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_drawing_text_font_adapter_get_system_font_full_names_by_type, 0);

  // Execute
  return ark_ohos_drawing_text_font_adapter_get_system_font_full_names_by_type(
      _struct, systemFontType, drawingArray);
}

ARK_WEB_NO_SANITIZE
int ArkOhosDrawingTextFontAdapterCToCpp::GetFontDescriptorByFullName(
    void* drawingString,
    int32_t systemFontType,
    void** drawingFontDescriptor) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_drawing_text_font_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_drawing_text_font_adapter_get_font_descriptor_by_full_name);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "3SXuXN3iUP3lq0rms$mhpA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_OHOS_DRAWING_TEXT_FONT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_drawing_text_font_adapter_get_font_descriptor_by_full_"
          "name");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_font_descriptor_by_full_name)) {
        ark_ohos_drawing_text_font_adapter_get_font_descriptor_by_full_name =
            nullptr;
      } else {
        ark_ohos_drawing_text_font_adapter_get_font_descriptor_by_full_name =
            _struct->get_font_descriptor_by_full_name;
      }
    } else {
      ark_ohos_drawing_text_font_adapter_get_font_descriptor_by_full_name =
          reinterpret_cast<
              ArkOhosDrawingTextFontAdapterGetFontDescriptorByFullNameFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_drawing_text_font_adapter_get_font_descriptor_by_full_name, 0);

  // Execute
  return ark_ohos_drawing_text_font_adapter_get_font_descriptor_by_full_name(
      _struct, drawingString, systemFontType, drawingFontDescriptor);
}

ARK_WEB_NO_SANITIZE
int ArkOhosDrawingTextFontAdapterCToCpp::GetSystemFontFullNameByIndex(
    void* drawingArray,
    int32_t indexOfFullName,
    const void** drawingString) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_drawing_text_font_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_drawing_text_font_adapter_get_system_font_full_name_by_index);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "F3r0er9rDsaY$v27cCQQJQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_OHOS_DRAWING_TEXT_FONT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_drawing_text_font_adapter_get_system_font_full_name_by_"
          "index");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_system_font_full_name_by_index)) {
        ark_ohos_drawing_text_font_adapter_get_system_font_full_name_by_index =
            nullptr;
      } else {
        ark_ohos_drawing_text_font_adapter_get_system_font_full_name_by_index =
            _struct->get_system_font_full_name_by_index;
      }
    } else {
      ark_ohos_drawing_text_font_adapter_get_system_font_full_name_by_index =
          reinterpret_cast<
              ArkOhosDrawingTextFontAdapterGetSystemFontFullNameByIndexFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_drawing_text_font_adapter_get_system_font_full_name_by_index, 0);

  // Execute
  return ark_ohos_drawing_text_font_adapter_get_system_font_full_name_by_index(
      _struct, drawingArray, indexOfFullName, drawingString);
}

ARK_WEB_NO_SANITIZE
void ArkOhosDrawingTextFontAdapterCToCpp::DestroySystemFontFullNames(
    void* drawingArray) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_drawing_text_font_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_drawing_text_font_adapter_destroy_system_font_full_names);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "zOtsYDLepQFLj5Z1N84sYg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_OHOS_DRAWING_TEXT_FONT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_drawing_text_font_adapter_destroy_system_font_full_names");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      destroy_system_font_full_names)) {
        ark_ohos_drawing_text_font_adapter_destroy_system_font_full_names =
            nullptr;
      } else {
        ark_ohos_drawing_text_font_adapter_destroy_system_font_full_names =
            _struct->destroy_system_font_full_names;
      }
    } else {
      ark_ohos_drawing_text_font_adapter_destroy_system_font_full_names =
          reinterpret_cast<
              ArkOhosDrawingTextFontAdapterDestroySystemFontFullNamesFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_drawing_text_font_adapter_destroy_system_font_full_names,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_ohos_drawing_text_font_adapter_destroy_system_font_full_names(
      _struct, drawingArray);
}

ARK_WEB_NO_SANITIZE
void ArkOhosDrawingTextFontAdapterCToCpp::DestroyFontDescriptor(
    void* descriptor) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_drawing_text_font_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_drawing_text_font_adapter_destroy_font_descriptor);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jMm5UD9aU9n3KaqvMS_nkw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_OHOS_DRAWING_TEXT_FONT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_drawing_text_font_adapter_destroy_font_descriptor");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, destroy_font_descriptor)) {
        ark_ohos_drawing_text_font_adapter_destroy_font_descriptor = nullptr;
      } else {
        ark_ohos_drawing_text_font_adapter_destroy_font_descriptor =
            _struct->destroy_font_descriptor;
      }
    } else {
      ark_ohos_drawing_text_font_adapter_destroy_font_descriptor =
          reinterpret_cast<
              ArkOhosDrawingTextFontAdapterDestroyFontDescriptorFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_drawing_text_font_adapter_destroy_font_descriptor,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_ohos_drawing_text_font_adapter_destroy_font_descriptor(_struct,
                                                             descriptor);
}

ArkOhosDrawingTextFontAdapterCToCpp::ArkOhosDrawingTextFontAdapterCToCpp() {}

ArkOhosDrawingTextFontAdapterCToCpp::~ArkOhosDrawingTextFontAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkOhosDrawingTextFontAdapterCToCpp,
                           ArkOhosDrawingTextFontAdapter,
                           ark_ohos_drawing_text_font_adapter_t>::kBridgeType =
        ARK_OHOS_DRAWING_TEXT_FONT_ADAPTER;

}  // namespace OHOS::ArkWeb
