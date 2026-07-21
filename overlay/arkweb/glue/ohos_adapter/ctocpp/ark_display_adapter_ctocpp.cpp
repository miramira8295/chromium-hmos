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

#include "ohos_adapter/ctocpp/ark_display_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkDisplayAdapterGetIdFunc =
    uint64_t (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetIdFunc ark_display_adapter_get_id =
    reinterpret_cast<ArkDisplayAdapterGetIdFunc>(ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetWidthFunc =
    int32_t (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetWidthFunc ark_display_adapter_get_width =
    reinterpret_cast<ArkDisplayAdapterGetWidthFunc>(ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetHeightFunc =
    int32_t (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetHeightFunc ark_display_adapter_get_height =
    reinterpret_cast<ArkDisplayAdapterGetHeightFunc>(ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetVirtualPixelRatioFunc =
    float (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetVirtualPixelRatioFunc
    ark_display_adapter_get_virtual_pixel_ratio =
        reinterpret_cast<ArkDisplayAdapterGetVirtualPixelRatioFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetRotationFunc =
    uint32_t (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetRotationFunc ark_display_adapter_get_rotation =
    reinterpret_cast<ArkDisplayAdapterGetRotationFunc>(ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetOrientationFunc =
    uint32_t (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetOrientationFunc ark_display_adapter_get_orientation =
    reinterpret_cast<ArkDisplayAdapterGetOrientationFunc>(ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetDpiFunc =
    int32_t (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetDpiFunc ark_display_adapter_get_dpi =
    reinterpret_cast<ArkDisplayAdapterGetDpiFunc>(ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetDisplayOrientationFunc =
    uint32_t (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetDisplayOrientationFunc
    ark_display_adapter_get_display_orientation =
        reinterpret_cast<ArkDisplayAdapterGetDisplayOrientationFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetFoldStatusFunc =
    uint32_t (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetFoldStatusFunc ark_display_adapter_get_fold_status =
    reinterpret_cast<ArkDisplayAdapterGetFoldStatusFunc>(ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterIsFoldableFunc =
    bool (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterIsFoldableFunc ark_display_adapter_is_foldable =
    reinterpret_cast<ArkDisplayAdapterIsFoldableFunc>(ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetNameFunc =
    ArkWebString (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetNameFunc ark_display_adapter_get_name =
    reinterpret_cast<ArkDisplayAdapterGetNameFunc>(ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetAvailableWidthFunc =
    int32_t (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetAvailableWidthFunc
    ark_display_adapter_get_available_width =
        reinterpret_cast<ArkDisplayAdapterGetAvailableWidthFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetAvailableHeightFunc =
    int32_t (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetAvailableHeightFunc
    ark_display_adapter_get_available_height =
        reinterpret_cast<ArkDisplayAdapterGetAvailableHeightFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetAliveStatusFunc =
    bool (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetAliveStatusFunc
    ark_display_adapter_get_alive_status =
        reinterpret_cast<ArkDisplayAdapterGetAliveStatusFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetDisplayStateFunc =
    uint32_t (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetDisplayStateFunc
    ark_display_adapter_get_display_state =
        reinterpret_cast<ArkDisplayAdapterGetDisplayStateFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetDensityDpiFunc =
    int32_t (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetDensityDpiFunc ark_display_adapter_get_density_dpi =
    reinterpret_cast<ArkDisplayAdapterGetDensityDpiFunc>(ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetXFunc =
    int32_t (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetXFunc ark_display_adapter_get_x =
    reinterpret_cast<ArkDisplayAdapterGetXFunc>(ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetYFunc =
    int32_t (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetYFunc ark_display_adapter_get_y =
    reinterpret_cast<ArkDisplayAdapterGetYFunc>(ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetDisplaySourceModeFunc =
    uint32_t (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetDisplaySourceModeFunc
    ark_display_adapter_get_display_source_mode =
        reinterpret_cast<ArkDisplayAdapterGetDisplaySourceModeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetPhysicalWidthFunc =
    int32_t (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetPhysicalWidthFunc
    ark_display_adapter_get_physical_width =
        reinterpret_cast<ArkDisplayAdapterGetPhysicalWidthFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetPhysicalHeightFunc =
    int32_t (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetPhysicalHeightFunc
    ark_display_adapter_get_physical_height =
        reinterpret_cast<ArkDisplayAdapterGetPhysicalHeightFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDisplayAdapterGetDefaultVirtualPixelRatioFunc =
    float (*)(struct _ark_display_adapter_t* self);
static ArkDisplayAdapterGetDefaultVirtualPixelRatioFunc
    ark_display_adapter_get_default_virtual_pixel_ratio =
        reinterpret_cast<ArkDisplayAdapterGetDefaultVirtualPixelRatioFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
uint64_t ArkDisplayAdapterCToCpp::GetId() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_display_adapter_get_id);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "M7dL09wqLYit$ytZQuX30A";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_display_adapter_get_id");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_id)) {
        ark_display_adapter_get_id = nullptr;
      } else {
        ark_display_adapter_get_id = _struct->get_id;
      }
    } else {
      ark_display_adapter_get_id =
          reinterpret_cast<ArkDisplayAdapterGetIdFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_id, 0);

  // Execute
  return ark_display_adapter_get_id(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDisplayAdapterCToCpp::GetWidth() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_display_adapter_get_width);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Eiozj4DRgd2oBzvOgjkktA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_display_adapter_get_width");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_width)) {
        ark_display_adapter_get_width = nullptr;
      } else {
        ark_display_adapter_get_width = _struct->get_width;
      }
    } else {
      ark_display_adapter_get_width =
          reinterpret_cast<ArkDisplayAdapterGetWidthFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_width, 0);

  // Execute
  return ark_display_adapter_get_width(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDisplayAdapterCToCpp::GetHeight() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_display_adapter_get_height);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "bHY$w5rmexKEDLdjQDDLsQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_display_adapter_get_height");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_height)) {
        ark_display_adapter_get_height = nullptr;
      } else {
        ark_display_adapter_get_height = _struct->get_height;
      }
    } else {
      ark_display_adapter_get_height =
          reinterpret_cast<ArkDisplayAdapterGetHeightFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_height, 0);

  // Execute
  return ark_display_adapter_get_height(_struct);
}

ARK_WEB_NO_SANITIZE
float ArkDisplayAdapterCToCpp::GetVirtualPixelRatio() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_display_adapter_get_virtual_pixel_ratio);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "vhAq_w$i1AzeqgTBpzrMHw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_display_adapter_get_virtual_pixel_ratio");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_virtual_pixel_ratio)) {
        ark_display_adapter_get_virtual_pixel_ratio = nullptr;
      } else {
        ark_display_adapter_get_virtual_pixel_ratio =
            _struct->get_virtual_pixel_ratio;
      }
    } else {
      ark_display_adapter_get_virtual_pixel_ratio =
          reinterpret_cast<ArkDisplayAdapterGetVirtualPixelRatioFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_virtual_pixel_ratio,
                                    0);

  // Execute
  return ark_display_adapter_get_virtual_pixel_ratio(_struct);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkDisplayAdapterCToCpp::GetRotation() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_display_adapter_get_rotation);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "gr18wV7V5ghMuw31Eib7Bg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_display_adapter_get_rotation");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_rotation)) {
        ark_display_adapter_get_rotation = nullptr;
      } else {
        ark_display_adapter_get_rotation = _struct->get_rotation;
      }
    } else {
      ark_display_adapter_get_rotation =
          reinterpret_cast<ArkDisplayAdapterGetRotationFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_rotation, 0);

  // Execute
  return ark_display_adapter_get_rotation(_struct);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkDisplayAdapterCToCpp::GetOrientation() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_display_adapter_get_orientation);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "393wq7x4f$az_1PiEEM13w";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_display_adapter_get_orientation");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_orientation)) {
        ark_display_adapter_get_orientation = nullptr;
      } else {
        ark_display_adapter_get_orientation = _struct->get_orientation;
      }
    } else {
      ark_display_adapter_get_orientation =
          reinterpret_cast<ArkDisplayAdapterGetOrientationFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_orientation, 0);

  // Execute
  return ark_display_adapter_get_orientation(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDisplayAdapterCToCpp::GetDpi() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_display_adapter_get_dpi);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "OGwuGkp7_vKWTz8EuqPDuQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_display_adapter_get_dpi");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_dpi)) {
        ark_display_adapter_get_dpi = nullptr;
      } else {
        ark_display_adapter_get_dpi = _struct->get_dpi;
      }
    } else {
      ark_display_adapter_get_dpi =
          reinterpret_cast<ArkDisplayAdapterGetDpiFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_dpi, 0);

  // Execute
  return ark_display_adapter_get_dpi(_struct);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkDisplayAdapterCToCpp::GetDisplayOrientation() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_display_adapter_get_display_orientation);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Tl_jNCrJhSmjDFlkGFDWow";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_display_adapter_get_display_orientation");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_display_orientation)) {
        ark_display_adapter_get_display_orientation = nullptr;
      } else {
        ark_display_adapter_get_display_orientation =
            _struct->get_display_orientation;
      }
    } else {
      ark_display_adapter_get_display_orientation =
          reinterpret_cast<ArkDisplayAdapterGetDisplayOrientationFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_display_orientation,
                                    0);

  // Execute
  return ark_display_adapter_get_display_orientation(_struct);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkDisplayAdapterCToCpp::GetFoldStatus() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_display_adapter_get_fold_status);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "1caXfTZ2mWPAh_$fKaMYHw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_display_adapter_get_fold_status");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_fold_status)) {
        ark_display_adapter_get_fold_status = nullptr;
      } else {
        ark_display_adapter_get_fold_status = _struct->get_fold_status;
      }
    } else {
      ark_display_adapter_get_fold_status =
          reinterpret_cast<ArkDisplayAdapterGetFoldStatusFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_fold_status, 0);

  // Execute
  return ark_display_adapter_get_fold_status(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkDisplayAdapterCToCpp::IsFoldable() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(ark_display_adapter_is_foldable);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "PnVtn6zJ1BUNgIMlrnfudQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_display_adapter_is_foldable");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_foldable)) {
        ark_display_adapter_is_foldable = nullptr;
      } else {
        ark_display_adapter_is_foldable = _struct->is_foldable;
      }
    } else {
      ark_display_adapter_is_foldable =
          reinterpret_cast<ArkDisplayAdapterIsFoldableFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_is_foldable, false);

  // Execute
  return ark_display_adapter_is_foldable(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkDisplayAdapterCToCpp::GetName() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(ark_display_adapter_get_name);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "mXNdvCK42Y_0gXe_kOXNwg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_display_adapter_get_name");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_name)) {
        ark_display_adapter_get_name = nullptr;
      } else {
        ark_display_adapter_get_name = _struct->get_name;
      }
    } else {
      ark_display_adapter_get_name =
          reinterpret_cast<ArkDisplayAdapterGetNameFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_name,
                                    ark_web_string_default);

  // Execute
  return ark_display_adapter_get_name(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDisplayAdapterCToCpp::GetAvailableWidth() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_display_adapter_get_available_width);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Ge23k6nRxe0n_5KVc78kGQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_display_adapter_get_available_width");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_available_width)) {
        ark_display_adapter_get_available_width = nullptr;
      } else {
        ark_display_adapter_get_available_width = _struct->get_available_width;
      }
    } else {
      ark_display_adapter_get_available_width =
          reinterpret_cast<ArkDisplayAdapterGetAvailableWidthFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_available_width, 0);

  // Execute
  return ark_display_adapter_get_available_width(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDisplayAdapterCToCpp::GetAvailableHeight() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_display_adapter_get_available_height);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "W_BJuTaoR51EG$JDy$_oyQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_display_adapter_get_available_height");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_available_height)) {
        ark_display_adapter_get_available_height = nullptr;
      } else {
        ark_display_adapter_get_available_height =
            _struct->get_available_height;
      }
    } else {
      ark_display_adapter_get_available_height =
          reinterpret_cast<ArkDisplayAdapterGetAvailableHeightFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_available_height,
                                    0);

  // Execute
  return ark_display_adapter_get_available_height(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkDisplayAdapterCToCpp::GetAliveStatus() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_display_adapter_get_alive_status);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "yIS7NBtF8EOxNFQLsicvpA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_display_adapter_get_alive_status");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_alive_status)) {
        ark_display_adapter_get_alive_status = nullptr;
      } else {
        ark_display_adapter_get_alive_status = _struct->get_alive_status;
      }
    } else {
      ark_display_adapter_get_alive_status =
          reinterpret_cast<ArkDisplayAdapterGetAliveStatusFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_alive_status,
                                    false);

  // Execute
  return ark_display_adapter_get_alive_status(_struct);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkDisplayAdapterCToCpp::GetDisplayState() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_display_adapter_get_display_state);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "rF2QNU1UHCNUSBE6DOGv4A";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_display_adapter_get_display_state");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_display_state)) {
        ark_display_adapter_get_display_state = nullptr;
      } else {
        ark_display_adapter_get_display_state = _struct->get_display_state;
      }
    } else {
      ark_display_adapter_get_display_state =
          reinterpret_cast<ArkDisplayAdapterGetDisplayStateFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_display_state, 0);

  // Execute
  return ark_display_adapter_get_display_state(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDisplayAdapterCToCpp::GetDensityDpi() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_display_adapter_get_density_dpi);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "f820aFEIYgZ7N2jN6vQ4rg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_display_adapter_get_density_dpi");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_density_dpi)) {
        ark_display_adapter_get_density_dpi = nullptr;
      } else {
        ark_display_adapter_get_density_dpi = _struct->get_density_dpi;
      }
    } else {
      ark_display_adapter_get_density_dpi =
          reinterpret_cast<ArkDisplayAdapterGetDensityDpiFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_density_dpi, 0);

  // Execute
  return ark_display_adapter_get_density_dpi(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDisplayAdapterCToCpp::GetX() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_display_adapter_get_x);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "SkkFl0jCjE$5Fh4hjEb0ug";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_display_adapter_get_x");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_x)) {
        ark_display_adapter_get_x = nullptr;
      } else {
        ark_display_adapter_get_x = _struct->get_x;
      }
    } else {
      ark_display_adapter_get_x =
          reinterpret_cast<ArkDisplayAdapterGetXFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_x, 0);

  // Execute
  return ark_display_adapter_get_x(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDisplayAdapterCToCpp::GetY() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_display_adapter_get_y);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "DsYtpCULLyITc4eOb1sHLQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_display_adapter_get_y");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_y)) {
        ark_display_adapter_get_y = nullptr;
      } else {
        ark_display_adapter_get_y = _struct->get_y;
      }
    } else {
      ark_display_adapter_get_y =
          reinterpret_cast<ArkDisplayAdapterGetYFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_y, 0);

  // Execute
  return ark_display_adapter_get_y(_struct);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkDisplayAdapterCToCpp::GetDisplaySourceMode() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_display_adapter_get_display_source_mode);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "TQYAWsBrlOuyVkfH0UvKNA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_display_adapter_get_display_source_mode");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_display_source_mode)) {
        ark_display_adapter_get_display_source_mode = nullptr;
      } else {
        ark_display_adapter_get_display_source_mode =
            _struct->get_display_source_mode;
      }
    } else {
      ark_display_adapter_get_display_source_mode =
          reinterpret_cast<ArkDisplayAdapterGetDisplaySourceModeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_display_source_mode,
                                    0);

  // Execute
  return ark_display_adapter_get_display_source_mode(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDisplayAdapterCToCpp::GetPhysicalWidth() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_display_adapter_get_physical_width);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "dUwsKzVxrVmBhEDfZSYP9A";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_display_adapter_get_physical_width");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_physical_width)) {
        ark_display_adapter_get_physical_width = nullptr;
      } else {
        ark_display_adapter_get_physical_width = _struct->get_physical_width;
      }
    } else {
      ark_display_adapter_get_physical_width =
          reinterpret_cast<ArkDisplayAdapterGetPhysicalWidthFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_physical_width, 0);

  // Execute
  return ark_display_adapter_get_physical_width(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDisplayAdapterCToCpp::GetPhysicalHeight() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_display_adapter_get_physical_height);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "moLSBwX9hl4Z52x0YRq5lw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_display_adapter_get_physical_height");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_physical_height)) {
        ark_display_adapter_get_physical_height = nullptr;
      } else {
        ark_display_adapter_get_physical_height = _struct->get_physical_height;
      }
    } else {
      ark_display_adapter_get_physical_height =
          reinterpret_cast<ArkDisplayAdapterGetPhysicalHeightFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_display_adapter_get_physical_height, 0);

  // Execute
  return ark_display_adapter_get_physical_height(_struct);
}

ARK_WEB_NO_SANITIZE
float ArkDisplayAdapterCToCpp::GetDefaultVirtualPixelRatio() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_display_adapter_get_default_virtual_pixel_ratio);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "DvLOUwq_73Q9JJwGvppRHA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DISPLAY_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_display_adapter_get_default_virtual_pixel_ratio");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_default_virtual_pixel_ratio)) {
        ark_display_adapter_get_default_virtual_pixel_ratio = nullptr;
      } else {
        ark_display_adapter_get_default_virtual_pixel_ratio =
            _struct->get_default_virtual_pixel_ratio;
      }
    } else {
      ark_display_adapter_get_default_virtual_pixel_ratio =
          reinterpret_cast<ArkDisplayAdapterGetDefaultVirtualPixelRatioFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_display_adapter_get_default_virtual_pixel_ratio, 0);

  // Execute
  return ark_display_adapter_get_default_virtual_pixel_ratio(_struct);
}

ArkDisplayAdapterCToCpp::ArkDisplayAdapterCToCpp() {}

ArkDisplayAdapterCToCpp::~ArkDisplayAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkDisplayAdapterCToCpp,
                                        ArkDisplayAdapter,
                                        ark_display_adapter_t>::kBridgeType =
    ARK_DISPLAY_ADAPTER;

}  // namespace OHOS::ArkWeb
