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

#include "ohos_adapter/ctocpp/ark_camera_manager_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_camera_buffer_listener_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_camera_status_callback_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_video_capture_params_adapter_cpptoc.h"
#include "ohos_adapter/ctocpp/ark_video_capture_range_adapter_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkCameraManagerAdapterCreateFunc =
    int32_t (*)(struct _ark_camera_manager_adapter_t* self,
                ark_camera_status_callback_adapter_t* cameraStatusCallback);
static ArkCameraManagerAdapterCreateFunc ark_camera_manager_adapter_create =
    reinterpret_cast<ArkCameraManagerAdapterCreateFunc>(ARK_WEB_INIT_ADDR);

using ArkCameraManagerAdapterGetDevicesInfoFunc =
    ArkVideoDeviceDescriptorAdapterVector (*)(
        struct _ark_camera_manager_adapter_t* self);
static ArkCameraManagerAdapterGetDevicesInfoFunc
    ark_camera_manager_adapter_get_devices_info =
        reinterpret_cast<ArkCameraManagerAdapterGetDevicesInfoFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraManagerAdapterReleaseCameraMangerFunc =
    int32_t (*)(struct _ark_camera_manager_adapter_t* self);
static ArkCameraManagerAdapterReleaseCameraMangerFunc
    ark_camera_manager_adapter_release_camera_manger =
        reinterpret_cast<ArkCameraManagerAdapterReleaseCameraMangerFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraManagerAdapterGetExposureModesFunc =
    int32_t (*)(struct _ark_camera_manager_adapter_t* self,
                ArkWebInt32Vector* exposureModesAdapter);
static ArkCameraManagerAdapterGetExposureModesFunc
    ark_camera_manager_adapter_get_exposure_modes =
        reinterpret_cast<ArkCameraManagerAdapterGetExposureModesFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraManagerAdapterGetCurrentExposureModeFunc =
    int32_t (*)(struct _ark_camera_manager_adapter_t* self,
                int32_t* exposureModeAdapter);
static ArkCameraManagerAdapterGetCurrentExposureModeFunc
    ark_camera_manager_adapter_get_current_exposure_mode =
        reinterpret_cast<ArkCameraManagerAdapterGetCurrentExposureModeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraManagerAdapterGetCaptionRangeByIdFunc =
    ark_video_capture_range_adapter_t* (*)(struct _ark_camera_manager_adapter_t*
                                               self,
                                           int32_t rangeId);
static ArkCameraManagerAdapterGetCaptionRangeByIdFunc
    ark_camera_manager_adapter_get_caption_range_by_id =
        reinterpret_cast<ArkCameraManagerAdapterGetCaptionRangeByIdFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraManagerAdapterIsFocusModeSupportedFunc =
    bool (*)(struct _ark_camera_manager_adapter_t* self, int32_t focusMode);
static ArkCameraManagerAdapterIsFocusModeSupportedFunc
    ark_camera_manager_adapter_is_focus_mode_supported =
        reinterpret_cast<ArkCameraManagerAdapterIsFocusModeSupportedFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraManagerAdapterGetCurrentFocusModeFunc =
    int32_t (*)(struct _ark_camera_manager_adapter_t* self);
static ArkCameraManagerAdapterGetCurrentFocusModeFunc
    ark_camera_manager_adapter_get_current_focus_mode =
        reinterpret_cast<ArkCameraManagerAdapterGetCurrentFocusModeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraManagerAdapterIsFlashModeSupportedFunc =
    bool (*)(struct _ark_camera_manager_adapter_t* self, int32_t flashMode);
static ArkCameraManagerAdapterIsFlashModeSupportedFunc
    ark_camera_manager_adapter_is_flash_mode_supported =
        reinterpret_cast<ArkCameraManagerAdapterIsFlashModeSupportedFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraManagerAdapterRestartSessionFunc =
    int32_t (*)(struct _ark_camera_manager_adapter_t* self);
static ArkCameraManagerAdapterRestartSessionFunc
    ark_camera_manager_adapter_restart_session =
        reinterpret_cast<ArkCameraManagerAdapterRestartSessionFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraManagerAdapterStopSessionFunc =
    int32_t (*)(struct _ark_camera_manager_adapter_t* self, int32_t stopType);
static ArkCameraManagerAdapterStopSessionFunc
    ark_camera_manager_adapter_stop_session =
        reinterpret_cast<ArkCameraManagerAdapterStopSessionFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraManagerAdapterGetCameraStatusFunc =
    int32_t (*)(struct _ark_camera_manager_adapter_t* self);
static ArkCameraManagerAdapterGetCameraStatusFunc
    ark_camera_manager_adapter_get_camera_status =
        reinterpret_cast<ArkCameraManagerAdapterGetCameraStatusFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraManagerAdapterIsExistCaptureTaskFunc =
    bool (*)(struct _ark_camera_manager_adapter_t* self);
static ArkCameraManagerAdapterIsExistCaptureTaskFunc
    ark_camera_manager_adapter_is_exist_capture_task =
        reinterpret_cast<ArkCameraManagerAdapterIsExistCaptureTaskFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraManagerAdapterStartStreamFunc =
    int32_t (*)(struct _ark_camera_manager_adapter_t* self,
                const ArkWebString* deviceId,
                ark_video_capture_params_adapter_t* captureParams,
                ark_camera_buffer_listener_adapter_t* listener);
static ArkCameraManagerAdapterStartStreamFunc
    ark_camera_manager_adapter_start_stream =
        reinterpret_cast<ArkCameraManagerAdapterStartStreamFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraManagerAdapterSetForegroundFlagFunc =
    void (*)(struct _ark_camera_manager_adapter_t* self, bool isForeground);
static ArkCameraManagerAdapterSetForegroundFlagFunc
    ark_camera_manager_adapter_set_foreground_flag =
        reinterpret_cast<ArkCameraManagerAdapterSetForegroundFlagFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraManagerAdapterSetCameraStatusFunc =
    void (*)(struct _ark_camera_manager_adapter_t* self, int32_t status);
static ArkCameraManagerAdapterSetCameraStatusFunc
    ark_camera_manager_adapter_set_camera_status =
        reinterpret_cast<ArkCameraManagerAdapterSetCameraStatusFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraManagerAdapterGetCurrentDeviceIdFunc =
    ArkWebString (*)(struct _ark_camera_manager_adapter_t* self);
static ArkCameraManagerAdapterGetCurrentDeviceIdFunc
    ark_camera_manager_adapter_get_current_device_id =
        reinterpret_cast<ArkCameraManagerAdapterGetCurrentDeviceIdFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkCameraManagerAdapterCToCpp::Create(
    ArkWebRefPtr<ArkCameraStatusCallbackAdapter> cameraStatusCallback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_manager_adapter_create);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "zZ1TJRu9EUvWBI7K7hhvag";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_camera_manager_adapter_create");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create)) {
        ark_camera_manager_adapter_create = nullptr;
      } else {
        ark_camera_manager_adapter_create = _struct->create;
      }
    } else {
      ark_camera_manager_adapter_create =
          reinterpret_cast<ArkCameraManagerAdapterCreateFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_camera_manager_adapter_create, 0);

  // Execute
  return ark_camera_manager_adapter_create(
      _struct,
      ArkCameraStatusCallbackAdapterCppToC::Invert(cameraStatusCallback));
}

ARK_WEB_NO_SANITIZE
ArkVideoDeviceDescriptorAdapterVector
ArkCameraManagerAdapterCToCpp::GetDevicesInfo() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, {0});

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_manager_adapter_get_devices_info);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "B0haa91Sp8$8OBY9ZNs$bQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_manager_adapter_get_devices_info");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_devices_info)) {
        ark_camera_manager_adapter_get_devices_info = nullptr;
      } else {
        ark_camera_manager_adapter_get_devices_info = _struct->get_devices_info;
      }
    } else {
      ark_camera_manager_adapter_get_devices_info =
          reinterpret_cast<ArkCameraManagerAdapterGetDevicesInfoFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_camera_manager_adapter_get_devices_info,
                                    {0});

  // Execute
  return ark_camera_manager_adapter_get_devices_info(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCameraManagerAdapterCToCpp::ReleaseCameraManger() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_manager_adapter_release_camera_manger);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "M5NDJfs$rLTjMX1rDLm69w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_manager_adapter_release_camera_manger");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release_camera_manger)) {
        ark_camera_manager_adapter_release_camera_manger = nullptr;
      } else {
        ark_camera_manager_adapter_release_camera_manger =
            _struct->release_camera_manger;
      }
    } else {
      ark_camera_manager_adapter_release_camera_manger =
          reinterpret_cast<ArkCameraManagerAdapterReleaseCameraMangerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_camera_manager_adapter_release_camera_manger, 0);

  // Execute
  return ark_camera_manager_adapter_release_camera_manger(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCameraManagerAdapterCToCpp::GetExposureModes(
    ArkWebInt32Vector& exposureModesAdapter) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_manager_adapter_get_exposure_modes);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "yk35J3Fx$1SZGtFIOVpehQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_manager_adapter_get_exposure_modes");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_exposure_modes)) {
        ark_camera_manager_adapter_get_exposure_modes = nullptr;
      } else {
        ark_camera_manager_adapter_get_exposure_modes =
            _struct->get_exposure_modes;
      }
    } else {
      ark_camera_manager_adapter_get_exposure_modes =
          reinterpret_cast<ArkCameraManagerAdapterGetExposureModesFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_camera_manager_adapter_get_exposure_modes, 0);

  // Execute
  return ark_camera_manager_adapter_get_exposure_modes(_struct,
                                                       &exposureModesAdapter);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCameraManagerAdapterCToCpp::GetCurrentExposureMode(
    int32_t& exposureModeAdapter) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_camera_manager_adapter_get_current_exposure_mode);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "FBi0naE46kOVJZijX$pBZA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_manager_adapter_get_current_exposure_mode");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_current_exposure_mode)) {
        ark_camera_manager_adapter_get_current_exposure_mode = nullptr;
      } else {
        ark_camera_manager_adapter_get_current_exposure_mode =
            _struct->get_current_exposure_mode;
      }
    } else {
      ark_camera_manager_adapter_get_current_exposure_mode =
          reinterpret_cast<ArkCameraManagerAdapterGetCurrentExposureModeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_camera_manager_adapter_get_current_exposure_mode, 0);

  // Execute
  return ark_camera_manager_adapter_get_current_exposure_mode(
      _struct, &exposureModeAdapter);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkVideoCaptureRangeAdapter>
ArkCameraManagerAdapterCToCpp::GetCaptionRangeById(int32_t rangeId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_camera_manager_adapter_get_caption_range_by_id);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "lNePZiGNHR_oSvhXd3zh3Q";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_manager_adapter_get_caption_range_by_id");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_caption_range_by_id)) {
        ark_camera_manager_adapter_get_caption_range_by_id = nullptr;
      } else {
        ark_camera_manager_adapter_get_caption_range_by_id =
            _struct->get_caption_range_by_id;
      }
    } else {
      ark_camera_manager_adapter_get_caption_range_by_id =
          reinterpret_cast<ArkCameraManagerAdapterGetCaptionRangeByIdFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_camera_manager_adapter_get_caption_range_by_id, nullptr);

  // Execute
  ark_video_capture_range_adapter_t* _retval =
      ark_camera_manager_adapter_get_caption_range_by_id(_struct, rangeId);

  // Return type: refptr_same
  return ArkVideoCaptureRangeAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
bool ArkCameraManagerAdapterCToCpp::IsFocusModeSupported(int32_t focusMode) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_camera_manager_adapter_is_focus_mode_supported);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "hi49pO3btkF8N7PvReMDbw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_manager_adapter_is_focus_mode_supported");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_focus_mode_supported)) {
        ark_camera_manager_adapter_is_focus_mode_supported = nullptr;
      } else {
        ark_camera_manager_adapter_is_focus_mode_supported =
            _struct->is_focus_mode_supported;
      }
    } else {
      ark_camera_manager_adapter_is_focus_mode_supported =
          reinterpret_cast<ArkCameraManagerAdapterIsFocusModeSupportedFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_camera_manager_adapter_is_focus_mode_supported, false);

  // Execute
  return ark_camera_manager_adapter_is_focus_mode_supported(_struct, focusMode);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCameraManagerAdapterCToCpp::GetCurrentFocusMode() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_camera_manager_adapter_get_current_focus_mode);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "nPmC0OVtp_W2oufNwm4NbQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_manager_adapter_get_current_focus_mode");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_current_focus_mode)) {
        ark_camera_manager_adapter_get_current_focus_mode = nullptr;
      } else {
        ark_camera_manager_adapter_get_current_focus_mode =
            _struct->get_current_focus_mode;
      }
    } else {
      ark_camera_manager_adapter_get_current_focus_mode =
          reinterpret_cast<ArkCameraManagerAdapterGetCurrentFocusModeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_camera_manager_adapter_get_current_focus_mode, 0);

  // Execute
  return ark_camera_manager_adapter_get_current_focus_mode(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkCameraManagerAdapterCToCpp::IsFlashModeSupported(int32_t flashMode) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_camera_manager_adapter_is_flash_mode_supported);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "0JxzXCpuUAEnpoqWiaya5w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_manager_adapter_is_flash_mode_supported");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_flash_mode_supported)) {
        ark_camera_manager_adapter_is_flash_mode_supported = nullptr;
      } else {
        ark_camera_manager_adapter_is_flash_mode_supported =
            _struct->is_flash_mode_supported;
      }
    } else {
      ark_camera_manager_adapter_is_flash_mode_supported =
          reinterpret_cast<ArkCameraManagerAdapterIsFlashModeSupportedFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_camera_manager_adapter_is_flash_mode_supported, false);

  // Execute
  return ark_camera_manager_adapter_is_flash_mode_supported(_struct, flashMode);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCameraManagerAdapterCToCpp::RestartSession() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_manager_adapter_restart_session);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "tEfDujY_xISrb_6fwUY0GA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_manager_adapter_restart_session");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, restart_session)) {
        ark_camera_manager_adapter_restart_session = nullptr;
      } else {
        ark_camera_manager_adapter_restart_session = _struct->restart_session;
      }
    } else {
      ark_camera_manager_adapter_restart_session =
          reinterpret_cast<ArkCameraManagerAdapterRestartSessionFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_camera_manager_adapter_restart_session,
                                    0);

  // Execute
  return ark_camera_manager_adapter_restart_session(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCameraManagerAdapterCToCpp::StopSession(int32_t stopType) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_manager_adapter_stop_session);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "2jWOxkzeBzt0NY5$0Pz0FA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_camera_manager_adapter_stop_session");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, stop_session)) {
        ark_camera_manager_adapter_stop_session = nullptr;
      } else {
        ark_camera_manager_adapter_stop_session = _struct->stop_session;
      }
    } else {
      ark_camera_manager_adapter_stop_session =
          reinterpret_cast<ArkCameraManagerAdapterStopSessionFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_camera_manager_adapter_stop_session, 0);

  // Execute
  return ark_camera_manager_adapter_stop_session(_struct, stopType);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCameraManagerAdapterCToCpp::GetCameraStatus() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_manager_adapter_get_camera_status);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "kC0u8_UQtODWD0wy5avw1g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_manager_adapter_get_camera_status");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_camera_status)) {
        ark_camera_manager_adapter_get_camera_status = nullptr;
      } else {
        ark_camera_manager_adapter_get_camera_status =
            _struct->get_camera_status;
      }
    } else {
      ark_camera_manager_adapter_get_camera_status =
          reinterpret_cast<ArkCameraManagerAdapterGetCameraStatusFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_camera_manager_adapter_get_camera_status, 0);

  // Execute
  return ark_camera_manager_adapter_get_camera_status(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkCameraManagerAdapterCToCpp::IsExistCaptureTask() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_manager_adapter_is_exist_capture_task);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "G3GYOLGaHr0lykr91lTB4w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_manager_adapter_is_exist_capture_task");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_exist_capture_task)) {
        ark_camera_manager_adapter_is_exist_capture_task = nullptr;
      } else {
        ark_camera_manager_adapter_is_exist_capture_task =
            _struct->is_exist_capture_task;
      }
    } else {
      ark_camera_manager_adapter_is_exist_capture_task =
          reinterpret_cast<ArkCameraManagerAdapterIsExistCaptureTaskFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_camera_manager_adapter_is_exist_capture_task, false);

  // Execute
  return ark_camera_manager_adapter_is_exist_capture_task(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCameraManagerAdapterCToCpp::StartStream(
    const ArkWebString& deviceId,
    const ArkWebRefPtr<ArkVideoCaptureParamsAdapter> captureParams,
    ArkWebRefPtr<ArkCameraBufferListenerAdapter> listener) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_manager_adapter_start_stream);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "yaG8cwtn6hhRMiRCHxhycw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_camera_manager_adapter_start_stream");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start_stream)) {
        ark_camera_manager_adapter_start_stream = nullptr;
      } else {
        ark_camera_manager_adapter_start_stream = _struct->start_stream;
      }
    } else {
      ark_camera_manager_adapter_start_stream =
          reinterpret_cast<ArkCameraManagerAdapterStartStreamFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_camera_manager_adapter_start_stream, 0);

  // Execute
  return ark_camera_manager_adapter_start_stream(
      _struct, &deviceId,
      ArkVideoCaptureParamsAdapterCppToC::Invert(captureParams),
      ArkCameraBufferListenerAdapterCppToC::Invert(listener));
}

ARK_WEB_NO_SANITIZE
void ArkCameraManagerAdapterCToCpp::SetForegroundFlag(bool isForeground) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_manager_adapter_set_foreground_flag);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "NtRUKeJ792r27dE3UT$RWA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_manager_adapter_set_foreground_flag");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_foreground_flag)) {
        ark_camera_manager_adapter_set_foreground_flag = nullptr;
      } else {
        ark_camera_manager_adapter_set_foreground_flag =
            _struct->set_foreground_flag;
      }
    } else {
      ark_camera_manager_adapter_set_foreground_flag =
          reinterpret_cast<ArkCameraManagerAdapterSetForegroundFlagFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_camera_manager_adapter_set_foreground_flag, ARK_WEB_RETURN_VOID);

  // Execute
  ark_camera_manager_adapter_set_foreground_flag(_struct, isForeground);
}

ARK_WEB_NO_SANITIZE
void ArkCameraManagerAdapterCToCpp::SetCameraStatus(int32_t status) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_manager_adapter_set_camera_status);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "QVMDreE5Rt4PDgMGpagqTw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_manager_adapter_set_camera_status");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_camera_status)) {
        ark_camera_manager_adapter_set_camera_status = nullptr;
      } else {
        ark_camera_manager_adapter_set_camera_status =
            _struct->set_camera_status;
      }
    } else {
      ark_camera_manager_adapter_set_camera_status =
          reinterpret_cast<ArkCameraManagerAdapterSetCameraStatusFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_camera_manager_adapter_set_camera_status, ARK_WEB_RETURN_VOID);

  // Execute
  ark_camera_manager_adapter_set_camera_status(_struct, status);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkCameraManagerAdapterCToCpp::GetCurrentDeviceId() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_manager_adapter_get_current_device_id);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "0eqZ2jEPiY$IzV1e8nHL5Q";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_manager_adapter_get_current_device_id");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_current_device_id)) {
        ark_camera_manager_adapter_get_current_device_id = nullptr;
      } else {
        ark_camera_manager_adapter_get_current_device_id =
            _struct->get_current_device_id;
      }
    } else {
      ark_camera_manager_adapter_get_current_device_id =
          reinterpret_cast<ArkCameraManagerAdapterGetCurrentDeviceIdFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_camera_manager_adapter_get_current_device_id, ark_web_string_default);

  // Execute
  return ark_camera_manager_adapter_get_current_device_id(_struct);
}

ArkCameraManagerAdapterCToCpp::ArkCameraManagerAdapterCToCpp() {}

ArkCameraManagerAdapterCToCpp::~ArkCameraManagerAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkCameraManagerAdapterCToCpp,
                           ArkCameraManagerAdapter,
                           ark_camera_manager_adapter_t>::kBridgeType =
        ARK_CAMERA_MANAGER_ADAPTER;

}  // namespace OHOS::ArkWeb
