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

#include "ohos_nweb/ctocpp/ark_web_pdfconfig_args_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebPDFConfigArgsGetWidthFunc =
    double (*)(struct _ark_web_pdfconfig_args_t* self);
static ArkWebPDFConfigArgsGetWidthFunc ark_web_pdfconfig_args_get_width =
    reinterpret_cast<ArkWebPDFConfigArgsGetWidthFunc>(ARK_WEB_INIT_ADDR);

using ArkWebPDFConfigArgsGetHeightFunc =
    double (*)(struct _ark_web_pdfconfig_args_t* self);
static ArkWebPDFConfigArgsGetHeightFunc ark_web_pdfconfig_args_get_height =
    reinterpret_cast<ArkWebPDFConfigArgsGetHeightFunc>(ARK_WEB_INIT_ADDR);

using ArkWebPDFConfigArgsGetScaleFunc =
    double (*)(struct _ark_web_pdfconfig_args_t* self);
static ArkWebPDFConfigArgsGetScaleFunc ark_web_pdfconfig_args_get_scale =
    reinterpret_cast<ArkWebPDFConfigArgsGetScaleFunc>(ARK_WEB_INIT_ADDR);

using ArkWebPDFConfigArgsGetMarginTopFunc =
    double (*)(struct _ark_web_pdfconfig_args_t* self);
static ArkWebPDFConfigArgsGetMarginTopFunc
    ark_web_pdfconfig_args_get_margin_top =
        reinterpret_cast<ArkWebPDFConfigArgsGetMarginTopFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebPDFConfigArgsGetMarginBottomFunc =
    double (*)(struct _ark_web_pdfconfig_args_t* self);
static ArkWebPDFConfigArgsGetMarginBottomFunc
    ark_web_pdfconfig_args_get_margin_bottom =
        reinterpret_cast<ArkWebPDFConfigArgsGetMarginBottomFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebPDFConfigArgsGetMarginRightFunc =
    double (*)(struct _ark_web_pdfconfig_args_t* self);
static ArkWebPDFConfigArgsGetMarginRightFunc
    ark_web_pdfconfig_args_get_margin_right =
        reinterpret_cast<ArkWebPDFConfigArgsGetMarginRightFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebPDFConfigArgsGetMarginLeftFunc =
    double (*)(struct _ark_web_pdfconfig_args_t* self);
static ArkWebPDFConfigArgsGetMarginLeftFunc
    ark_web_pdfconfig_args_get_margin_left =
        reinterpret_cast<ArkWebPDFConfigArgsGetMarginLeftFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebPDFConfigArgsGetShouldPrintBackgroundFunc =
    bool (*)(struct _ark_web_pdfconfig_args_t* self);
static ArkWebPDFConfigArgsGetShouldPrintBackgroundFunc
    ark_web_pdfconfig_args_get_should_print_background =
        reinterpret_cast<ArkWebPDFConfigArgsGetShouldPrintBackgroundFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
double ArkWebPDFConfigArgsCToCpp::GetWidth() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_pdfconfig_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_pdfconfig_args_get_width);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "rePOTlSsm$97ZqzXPWDJkg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_PDFCONFIG_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_pdfconfig_args_get_width");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_width)) {
        ark_web_pdfconfig_args_get_width = nullptr;
      } else {
        ark_web_pdfconfig_args_get_width = _struct->get_width;
      }
    } else {
      ark_web_pdfconfig_args_get_width =
          reinterpret_cast<ArkWebPDFConfigArgsGetWidthFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_pdfconfig_args_get_width, 0);

  // Execute
  return ark_web_pdfconfig_args_get_width(_struct);
}

ARK_WEB_NO_SANITIZE
double ArkWebPDFConfigArgsCToCpp::GetHeight() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_pdfconfig_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_pdfconfig_args_get_height);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "NZnXEW71HwmSANJz5_EZGw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_PDFCONFIG_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_pdfconfig_args_get_height");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_height)) {
        ark_web_pdfconfig_args_get_height = nullptr;
      } else {
        ark_web_pdfconfig_args_get_height = _struct->get_height;
      }
    } else {
      ark_web_pdfconfig_args_get_height =
          reinterpret_cast<ArkWebPDFConfigArgsGetHeightFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_pdfconfig_args_get_height, 0);

  // Execute
  return ark_web_pdfconfig_args_get_height(_struct);
}

ARK_WEB_NO_SANITIZE
double ArkWebPDFConfigArgsCToCpp::GetScale() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_pdfconfig_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_pdfconfig_args_get_scale);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "9nx9yNrzQ0M3J1cEArCRJQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_PDFCONFIG_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_pdfconfig_args_get_scale");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_scale)) {
        ark_web_pdfconfig_args_get_scale = nullptr;
      } else {
        ark_web_pdfconfig_args_get_scale = _struct->get_scale;
      }
    } else {
      ark_web_pdfconfig_args_get_scale =
          reinterpret_cast<ArkWebPDFConfigArgsGetScaleFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_pdfconfig_args_get_scale, 0);

  // Execute
  return ark_web_pdfconfig_args_get_scale(_struct);
}

ARK_WEB_NO_SANITIZE
double ArkWebPDFConfigArgsCToCpp::GetMarginTop() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_pdfconfig_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_pdfconfig_args_get_margin_top);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "FoMDHxO6CFgiy1T9x1Cctg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_PDFCONFIG_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_pdfconfig_args_get_margin_top");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_margin_top)) {
        ark_web_pdfconfig_args_get_margin_top = nullptr;
      } else {
        ark_web_pdfconfig_args_get_margin_top = _struct->get_margin_top;
      }
    } else {
      ark_web_pdfconfig_args_get_margin_top =
          reinterpret_cast<ArkWebPDFConfigArgsGetMarginTopFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_pdfconfig_args_get_margin_top, 0);

  // Execute
  return ark_web_pdfconfig_args_get_margin_top(_struct);
}

ARK_WEB_NO_SANITIZE
double ArkWebPDFConfigArgsCToCpp::GetMarginBottom() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_pdfconfig_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_pdfconfig_args_get_margin_bottom);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ePmIJeCCF4RRmzn_9PL0Rw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_PDFCONFIG_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_pdfconfig_args_get_margin_bottom");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_margin_bottom)) {
        ark_web_pdfconfig_args_get_margin_bottom = nullptr;
      } else {
        ark_web_pdfconfig_args_get_margin_bottom = _struct->get_margin_bottom;
      }
    } else {
      ark_web_pdfconfig_args_get_margin_bottom =
          reinterpret_cast<ArkWebPDFConfigArgsGetMarginBottomFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_pdfconfig_args_get_margin_bottom,
                                    0);

  // Execute
  return ark_web_pdfconfig_args_get_margin_bottom(_struct);
}

ARK_WEB_NO_SANITIZE
double ArkWebPDFConfigArgsCToCpp::GetMarginRight() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_pdfconfig_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_pdfconfig_args_get_margin_right);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "hnN5DPnJl7FdMyuy44JJqA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_PDFCONFIG_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_pdfconfig_args_get_margin_right");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_margin_right)) {
        ark_web_pdfconfig_args_get_margin_right = nullptr;
      } else {
        ark_web_pdfconfig_args_get_margin_right = _struct->get_margin_right;
      }
    } else {
      ark_web_pdfconfig_args_get_margin_right =
          reinterpret_cast<ArkWebPDFConfigArgsGetMarginRightFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_pdfconfig_args_get_margin_right, 0);

  // Execute
  return ark_web_pdfconfig_args_get_margin_right(_struct);
}

ARK_WEB_NO_SANITIZE
double ArkWebPDFConfigArgsCToCpp::GetMarginLeft() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_pdfconfig_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_pdfconfig_args_get_margin_left);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "E7Sf0MW7VBxyhMDVzVzolA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_PDFCONFIG_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_pdfconfig_args_get_margin_left");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_margin_left)) {
        ark_web_pdfconfig_args_get_margin_left = nullptr;
      } else {
        ark_web_pdfconfig_args_get_margin_left = _struct->get_margin_left;
      }
    } else {
      ark_web_pdfconfig_args_get_margin_left =
          reinterpret_cast<ArkWebPDFConfigArgsGetMarginLeftFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_pdfconfig_args_get_margin_left, 0);

  // Execute
  return ark_web_pdfconfig_args_get_margin_left(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkWebPDFConfigArgsCToCpp::GetShouldPrintBackground() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_pdfconfig_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_pdfconfig_args_get_should_print_background);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "uem9HtrpFQqHewScO7muHg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_PDFCONFIG_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_pdfconfig_args_get_should_print_background");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_should_print_background)) {
        ark_web_pdfconfig_args_get_should_print_background = nullptr;
      } else {
        ark_web_pdfconfig_args_get_should_print_background =
            _struct->get_should_print_background;
      }
    } else {
      ark_web_pdfconfig_args_get_should_print_background =
          reinterpret_cast<ArkWebPDFConfigArgsGetShouldPrintBackgroundFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_pdfconfig_args_get_should_print_background, false);

  // Execute
  return ark_web_pdfconfig_args_get_should_print_background(_struct);
}

ArkWebPDFConfigArgsCToCpp::ArkWebPDFConfigArgsCToCpp() {}

ArkWebPDFConfigArgsCToCpp::~ArkWebPDFConfigArgsCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkWebPDFConfigArgsCToCpp,
                                        ArkWebPDFConfigArgs,
                                        ark_web_pdfconfig_args_t>::kBridgeType =
    ARK_WEB_PDFCONFIG_ARGS;

}  // namespace OHOS::ArkWeb
