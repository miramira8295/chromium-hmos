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

#include "ohos_nweb/ctocpp/ark_web_stylus_touch_point_info_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebStylusTouchPointInfoGetIdFunc =
    int32_t (*)(struct _ark_web_stylus_touch_point_info_t* self);
static ArkWebStylusTouchPointInfoGetIdFunc
    ark_web_stylus_touch_point_info_get_id =
        reinterpret_cast<ArkWebStylusTouchPointInfoGetIdFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebStylusTouchPointInfoGetXFunc =
    double (*)(struct _ark_web_stylus_touch_point_info_t* self);
static ArkWebStylusTouchPointInfoGetXFunc
    ark_web_stylus_touch_point_info_get_x =
        reinterpret_cast<ArkWebStylusTouchPointInfoGetXFunc>(ARK_WEB_INIT_ADDR);

using ArkWebStylusTouchPointInfoGetYFunc =
    double (*)(struct _ark_web_stylus_touch_point_info_t* self);
static ArkWebStylusTouchPointInfoGetYFunc
    ark_web_stylus_touch_point_info_get_y =
        reinterpret_cast<ArkWebStylusTouchPointInfoGetYFunc>(ARK_WEB_INIT_ADDR);

using ArkWebStylusTouchPointInfoGetSourceToolFunc =
    int32_t (*)(struct _ark_web_stylus_touch_point_info_t* self);
static ArkWebStylusTouchPointInfoGetSourceToolFunc
    ark_web_stylus_touch_point_info_get_source_tool =
        reinterpret_cast<ArkWebStylusTouchPointInfoGetSourceToolFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebStylusTouchPointInfoGetForceFunc =
    float (*)(struct _ark_web_stylus_touch_point_info_t* self);
static ArkWebStylusTouchPointInfoGetForceFunc
    ark_web_stylus_touch_point_info_get_force =
        reinterpret_cast<ArkWebStylusTouchPointInfoGetForceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebStylusTouchPointInfoGetTiltXFunc =
    float (*)(struct _ark_web_stylus_touch_point_info_t* self);
static ArkWebStylusTouchPointInfoGetTiltXFunc
    ark_web_stylus_touch_point_info_get_tilt_x =
        reinterpret_cast<ArkWebStylusTouchPointInfoGetTiltXFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebStylusTouchPointInfoGetTiltYFunc =
    float (*)(struct _ark_web_stylus_touch_point_info_t* self);
static ArkWebStylusTouchPointInfoGetTiltYFunc
    ark_web_stylus_touch_point_info_get_tilt_y =
        reinterpret_cast<ArkWebStylusTouchPointInfoGetTiltYFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebStylusTouchPointInfoGetRollAngleFunc =
    float (*)(struct _ark_web_stylus_touch_point_info_t* self);
static ArkWebStylusTouchPointInfoGetRollAngleFunc
    ark_web_stylus_touch_point_info_get_roll_angle =
        reinterpret_cast<ArkWebStylusTouchPointInfoGetRollAngleFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebStylusTouchPointInfoGetWidthFunc =
    int32_t (*)(struct _ark_web_stylus_touch_point_info_t* self);
static ArkWebStylusTouchPointInfoGetWidthFunc
    ark_web_stylus_touch_point_info_get_width =
        reinterpret_cast<ArkWebStylusTouchPointInfoGetWidthFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebStylusTouchPointInfoGetHeightFunc =
    int32_t (*)(struct _ark_web_stylus_touch_point_info_t* self);
static ArkWebStylusTouchPointInfoGetHeightFunc
    ark_web_stylus_touch_point_info_get_height =
        reinterpret_cast<ArkWebStylusTouchPointInfoGetHeightFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkWebStylusTouchPointInfoCToCpp::GetId() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_stylus_touch_point_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_stylus_touch_point_info_get_id);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "XvGv1dbUKc_dyoNsHkoB1w";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_STYLUS_TOUCH_POINT_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_stylus_touch_point_info_get_id");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_id)) {
        ark_web_stylus_touch_point_info_get_id = nullptr;
      } else {
        ark_web_stylus_touch_point_info_get_id = _struct->get_id;
      }
    } else {
      ark_web_stylus_touch_point_info_get_id =
          reinterpret_cast<ArkWebStylusTouchPointInfoGetIdFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_stylus_touch_point_info_get_id, 0);

  // Execute
  return ark_web_stylus_touch_point_info_get_id(_struct);
}

ARK_WEB_NO_SANITIZE
double ArkWebStylusTouchPointInfoCToCpp::GetX() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_stylus_touch_point_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_stylus_touch_point_info_get_x);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "MhhwiUQE4ixvgR0bZAllCA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_STYLUS_TOUCH_POINT_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_stylus_touch_point_info_get_x");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_x)) {
        ark_web_stylus_touch_point_info_get_x = nullptr;
      } else {
        ark_web_stylus_touch_point_info_get_x = _struct->get_x;
      }
    } else {
      ark_web_stylus_touch_point_info_get_x =
          reinterpret_cast<ArkWebStylusTouchPointInfoGetXFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_stylus_touch_point_info_get_x, 0);

  // Execute
  return ark_web_stylus_touch_point_info_get_x(_struct);
}

ARK_WEB_NO_SANITIZE
double ArkWebStylusTouchPointInfoCToCpp::GetY() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_stylus_touch_point_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_stylus_touch_point_info_get_y);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "H3xZvCp3pIY6I$Oh9sOkyQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_STYLUS_TOUCH_POINT_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_stylus_touch_point_info_get_y");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_y)) {
        ark_web_stylus_touch_point_info_get_y = nullptr;
      } else {
        ark_web_stylus_touch_point_info_get_y = _struct->get_y;
      }
    } else {
      ark_web_stylus_touch_point_info_get_y =
          reinterpret_cast<ArkWebStylusTouchPointInfoGetYFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_stylus_touch_point_info_get_y, 0);

  // Execute
  return ark_web_stylus_touch_point_info_get_y(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkWebStylusTouchPointInfoCToCpp::GetSourceTool() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_stylus_touch_point_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_stylus_touch_point_info_get_source_tool);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "1xM0b99vMSvW0XjVCH8VTQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_STYLUS_TOUCH_POINT_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_stylus_touch_point_info_get_source_tool");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_source_tool)) {
        ark_web_stylus_touch_point_info_get_source_tool = nullptr;
      } else {
        ark_web_stylus_touch_point_info_get_source_tool =
            _struct->get_source_tool;
      }
    } else {
      ark_web_stylus_touch_point_info_get_source_tool =
          reinterpret_cast<ArkWebStylusTouchPointInfoGetSourceToolFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_stylus_touch_point_info_get_source_tool, 0);

  // Execute
  return ark_web_stylus_touch_point_info_get_source_tool(_struct);
}

ARK_WEB_NO_SANITIZE
float ArkWebStylusTouchPointInfoCToCpp::GetForce() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_stylus_touch_point_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_stylus_touch_point_info_get_force);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "nhY3L3xCf53iU4mkaaZFew";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_STYLUS_TOUCH_POINT_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_stylus_touch_point_info_get_force");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_force)) {
        ark_web_stylus_touch_point_info_get_force = nullptr;
      } else {
        ark_web_stylus_touch_point_info_get_force = _struct->get_force;
      }
    } else {
      ark_web_stylus_touch_point_info_get_force =
          reinterpret_cast<ArkWebStylusTouchPointInfoGetForceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_stylus_touch_point_info_get_force,
                                    0);

  // Execute
  return ark_web_stylus_touch_point_info_get_force(_struct);
}

ARK_WEB_NO_SANITIZE
float ArkWebStylusTouchPointInfoCToCpp::GetTiltX() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_stylus_touch_point_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_stylus_touch_point_info_get_tilt_x);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "idcdnempWav0sqb5me535A";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_STYLUS_TOUCH_POINT_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_stylus_touch_point_info_get_tilt_x");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_tilt_x)) {
        ark_web_stylus_touch_point_info_get_tilt_x = nullptr;
      } else {
        ark_web_stylus_touch_point_info_get_tilt_x = _struct->get_tilt_x;
      }
    } else {
      ark_web_stylus_touch_point_info_get_tilt_x =
          reinterpret_cast<ArkWebStylusTouchPointInfoGetTiltXFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_stylus_touch_point_info_get_tilt_x,
                                    0);

  // Execute
  return ark_web_stylus_touch_point_info_get_tilt_x(_struct);
}

ARK_WEB_NO_SANITIZE
float ArkWebStylusTouchPointInfoCToCpp::GetTiltY() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_stylus_touch_point_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_stylus_touch_point_info_get_tilt_y);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "6s8idjSR4QR_mfjdeh_v9g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_STYLUS_TOUCH_POINT_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_stylus_touch_point_info_get_tilt_y");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_tilt_y)) {
        ark_web_stylus_touch_point_info_get_tilt_y = nullptr;
      } else {
        ark_web_stylus_touch_point_info_get_tilt_y = _struct->get_tilt_y;
      }
    } else {
      ark_web_stylus_touch_point_info_get_tilt_y =
          reinterpret_cast<ArkWebStylusTouchPointInfoGetTiltYFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_stylus_touch_point_info_get_tilt_y,
                                    0);

  // Execute
  return ark_web_stylus_touch_point_info_get_tilt_y(_struct);
}

ARK_WEB_NO_SANITIZE
float ArkWebStylusTouchPointInfoCToCpp::GetRollAngle() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_stylus_touch_point_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_stylus_touch_point_info_get_roll_angle);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "bgcO$leSPW5G379p3$W7ZA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_STYLUS_TOUCH_POINT_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_stylus_touch_point_info_get_roll_angle");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_roll_angle)) {
        ark_web_stylus_touch_point_info_get_roll_angle = nullptr;
      } else {
        ark_web_stylus_touch_point_info_get_roll_angle =
            _struct->get_roll_angle;
      }
    } else {
      ark_web_stylus_touch_point_info_get_roll_angle =
          reinterpret_cast<ArkWebStylusTouchPointInfoGetRollAngleFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_stylus_touch_point_info_get_roll_angle, 0);

  // Execute
  return ark_web_stylus_touch_point_info_get_roll_angle(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkWebStylusTouchPointInfoCToCpp::GetWidth() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_stylus_touch_point_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_stylus_touch_point_info_get_width);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "vuMKcpuAom$S4V29926stw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_STYLUS_TOUCH_POINT_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_stylus_touch_point_info_get_width");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_width)) {
        ark_web_stylus_touch_point_info_get_width = nullptr;
      } else {
        ark_web_stylus_touch_point_info_get_width = _struct->get_width;
      }
    } else {
      ark_web_stylus_touch_point_info_get_width =
          reinterpret_cast<ArkWebStylusTouchPointInfoGetWidthFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_stylus_touch_point_info_get_width,
                                    0);

  // Execute
  return ark_web_stylus_touch_point_info_get_width(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkWebStylusTouchPointInfoCToCpp::GetHeight() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_stylus_touch_point_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_stylus_touch_point_info_get_height);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "VYAfkR_ro9pIFfm0qLq1hA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_STYLUS_TOUCH_POINT_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_stylus_touch_point_info_get_height");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_height)) {
        ark_web_stylus_touch_point_info_get_height = nullptr;
      } else {
        ark_web_stylus_touch_point_info_get_height = _struct->get_height;
      }
    } else {
      ark_web_stylus_touch_point_info_get_height =
          reinterpret_cast<ArkWebStylusTouchPointInfoGetHeightFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_stylus_touch_point_info_get_height,
                                    0);

  // Execute
  return ark_web_stylus_touch_point_info_get_height(_struct);
}

ArkWebStylusTouchPointInfoCToCpp::ArkWebStylusTouchPointInfoCToCpp() {}

ArkWebStylusTouchPointInfoCToCpp::~ArkWebStylusTouchPointInfoCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkWebStylusTouchPointInfoCToCpp,
                           ArkWebStylusTouchPointInfo,
                           ark_web_stylus_touch_point_info_t>::kBridgeType =
        ARK_WEB_STYLUS_TOUCH_POINT_INFO;

}  // namespace OHOS::ArkWeb
