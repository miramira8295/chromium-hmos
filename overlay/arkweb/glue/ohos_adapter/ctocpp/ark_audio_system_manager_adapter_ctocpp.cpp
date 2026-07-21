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

#include "ohos_adapter/ctocpp/ark_audio_system_manager_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_audio_interrupt_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_audio_manager_callback_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_audio_manager_device_change_callback_adapter_cpptoc.h"
#include "ohos_adapter/ctocpp/ark_audio_device_desc_adapter_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkAudioSystemManagerAdapterHasAudioOutputDevicesFunc =
    bool (*)(struct _ark_audio_system_manager_adapter_t* self);
static ArkAudioSystemManagerAdapterHasAudioOutputDevicesFunc
    ark_audio_system_manager_adapter_has_audio_output_devices =
        reinterpret_cast<ArkAudioSystemManagerAdapterHasAudioOutputDevicesFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioSystemManagerAdapterHasAudioInputDevicesFunc =
    bool (*)(struct _ark_audio_system_manager_adapter_t* self);
static ArkAudioSystemManagerAdapterHasAudioInputDevicesFunc
    ark_audio_system_manager_adapter_has_audio_input_devices =
        reinterpret_cast<ArkAudioSystemManagerAdapterHasAudioInputDevicesFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioSystemManagerAdapterRequestAudioFocusFunc =
    int32_t (*)(struct _ark_audio_system_manager_adapter_t* self,
                ark_audio_interrupt_adapter_t* audioInterrupt);
static ArkAudioSystemManagerAdapterRequestAudioFocusFunc
    ark_audio_system_manager_adapter_request_audio_focus =
        reinterpret_cast<ArkAudioSystemManagerAdapterRequestAudioFocusFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioSystemManagerAdapterAbandonAudioFocusFunc =
    int32_t (*)(struct _ark_audio_system_manager_adapter_t* self,
                ark_audio_interrupt_adapter_t* audioInterrupt);
static ArkAudioSystemManagerAdapterAbandonAudioFocusFunc
    ark_audio_system_manager_adapter_abandon_audio_focus =
        reinterpret_cast<ArkAudioSystemManagerAdapterAbandonAudioFocusFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioSystemManagerAdapterSetAudioManagerInterruptCallbackFunc =
    int32_t (*)(struct _ark_audio_system_manager_adapter_t* self,
                ark_audio_manager_callback_adapter_t* callback);
static ArkAudioSystemManagerAdapterSetAudioManagerInterruptCallbackFunc
    ark_audio_system_manager_adapter_set_audio_manager_interrupt_callback =
        reinterpret_cast<
            ArkAudioSystemManagerAdapterSetAudioManagerInterruptCallbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioSystemManagerAdapterUnsetAudioManagerInterruptCallbackFunc =
    int32_t (*)(struct _ark_audio_system_manager_adapter_t* self);
static ArkAudioSystemManagerAdapterUnsetAudioManagerInterruptCallbackFunc
    ark_audio_system_manager_adapter_unset_audio_manager_interrupt_callback =
        reinterpret_cast<
            ArkAudioSystemManagerAdapterUnsetAudioManagerInterruptCallbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioSystemManagerAdapterGetDevicesFunc =
    ArkAudioDeviceDescAdapterVector (*)(
        struct _ark_audio_system_manager_adapter_t* self,
        int32_t flag);
static ArkAudioSystemManagerAdapterGetDevicesFunc
    ark_audio_system_manager_adapter_get_devices =
        reinterpret_cast<ArkAudioSystemManagerAdapterGetDevicesFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioSystemManagerAdapterSelectAudioDeviceByIdFunc =
    int32_t (*)(struct _ark_audio_system_manager_adapter_t* self,
                int32_t deviceId,
                bool isInput);
static ArkAudioSystemManagerAdapterSelectAudioDeviceByIdFunc
    ark_audio_system_manager_adapter_select_audio_device_by_id =
        reinterpret_cast<ArkAudioSystemManagerAdapterSelectAudioDeviceByIdFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioSystemManagerAdapterSetDeviceChangeCallbackFunc =
    int32_t (*)(struct _ark_audio_system_manager_adapter_t* self,
                ark_audio_manager_device_change_callback_adapter_t* callback);
static ArkAudioSystemManagerAdapterSetDeviceChangeCallbackFunc
    ark_audio_system_manager_adapter_set_device_change_callback =
        reinterpret_cast<
            ArkAudioSystemManagerAdapterSetDeviceChangeCallbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioSystemManagerAdapterUnsetDeviceChangeCallbackFunc =
    int32_t (*)(struct _ark_audio_system_manager_adapter_t* self);
static ArkAudioSystemManagerAdapterUnsetDeviceChangeCallbackFunc
    ark_audio_system_manager_adapter_unset_device_change_callback =
        reinterpret_cast<
            ArkAudioSystemManagerAdapterUnsetDeviceChangeCallbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioSystemManagerAdapterGetDefaultOutputDeviceFunc =
    ark_audio_device_desc_adapter_t* (*)(struct
                                         _ark_audio_system_manager_adapter_t*
                                             self);
static ArkAudioSystemManagerAdapterGetDefaultOutputDeviceFunc
    ark_audio_system_manager_adapter_get_default_output_device =
        reinterpret_cast<
            ArkAudioSystemManagerAdapterGetDefaultOutputDeviceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioSystemManagerAdapterGetDefaultInputDeviceFunc =
    ark_audio_device_desc_adapter_t* (*)(struct
                                         _ark_audio_system_manager_adapter_t*
                                             self);
static ArkAudioSystemManagerAdapterGetDefaultInputDeviceFunc
    ark_audio_system_manager_adapter_get_default_input_device =
        reinterpret_cast<ArkAudioSystemManagerAdapterGetDefaultInputDeviceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioSystemManagerAdapterSetLanguageFunc =
    bool (*)(struct _ark_audio_system_manager_adapter_t* self,
             const ArkWebString* language);
static ArkAudioSystemManagerAdapterSetLanguageFunc
    ark_audio_system_manager_adapter_set_language =
        reinterpret_cast<ArkAudioSystemManagerAdapterSetLanguageFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
bool ArkAudioSystemManagerAdapterCToCpp::HasAudioOutputDevices() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_system_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_system_manager_adapter_has_audio_output_devices);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "E48uH7Cp5t5bUIffLurusA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_SYSTEM_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_system_manager_adapter_has_audio_output_devices");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, has_audio_output_devices)) {
        ark_audio_system_manager_adapter_has_audio_output_devices = nullptr;
      } else {
        ark_audio_system_manager_adapter_has_audio_output_devices =
            _struct->has_audio_output_devices;
      }
    } else {
      ark_audio_system_manager_adapter_has_audio_output_devices =
          reinterpret_cast<
              ArkAudioSystemManagerAdapterHasAudioOutputDevicesFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_system_manager_adapter_has_audio_output_devices, false);

  // Execute
  return ark_audio_system_manager_adapter_has_audio_output_devices(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkAudioSystemManagerAdapterCToCpp::HasAudioInputDevices() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_system_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_system_manager_adapter_has_audio_input_devices);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "7p2_y21x0AI5ZVDzikPRYA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_SYSTEM_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_system_manager_adapter_has_audio_input_devices");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, has_audio_input_devices)) {
        ark_audio_system_manager_adapter_has_audio_input_devices = nullptr;
      } else {
        ark_audio_system_manager_adapter_has_audio_input_devices =
            _struct->has_audio_input_devices;
      }
    } else {
      ark_audio_system_manager_adapter_has_audio_input_devices =
          reinterpret_cast<
              ArkAudioSystemManagerAdapterHasAudioInputDevicesFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_system_manager_adapter_has_audio_input_devices, false);

  // Execute
  return ark_audio_system_manager_adapter_has_audio_input_devices(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioSystemManagerAdapterCToCpp::RequestAudioFocus(
    const ArkWebRefPtr<ArkAudioInterruptAdapter> audioInterrupt) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_system_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_system_manager_adapter_request_audio_focus);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "RhPs50kDTuj11ouA7vN_Ow";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_SYSTEM_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_system_manager_adapter_request_audio_focus");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, request_audio_focus)) {
        ark_audio_system_manager_adapter_request_audio_focus = nullptr;
      } else {
        ark_audio_system_manager_adapter_request_audio_focus =
            _struct->request_audio_focus;
      }
    } else {
      ark_audio_system_manager_adapter_request_audio_focus =
          reinterpret_cast<ArkAudioSystemManagerAdapterRequestAudioFocusFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_system_manager_adapter_request_audio_focus, 0);

  // Execute
  return ark_audio_system_manager_adapter_request_audio_focus(
      _struct, ArkAudioInterruptAdapterCppToC::Invert(audioInterrupt));
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioSystemManagerAdapterCToCpp::AbandonAudioFocus(
    const ArkWebRefPtr<ArkAudioInterruptAdapter> audioInterrupt) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_system_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_system_manager_adapter_abandon_audio_focus);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "E0F5RyrE_QpjFp2w5LyTKg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_SYSTEM_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_system_manager_adapter_abandon_audio_focus");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, abandon_audio_focus)) {
        ark_audio_system_manager_adapter_abandon_audio_focus = nullptr;
      } else {
        ark_audio_system_manager_adapter_abandon_audio_focus =
            _struct->abandon_audio_focus;
      }
    } else {
      ark_audio_system_manager_adapter_abandon_audio_focus =
          reinterpret_cast<ArkAudioSystemManagerAdapterAbandonAudioFocusFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_system_manager_adapter_abandon_audio_focus, 0);

  // Execute
  return ark_audio_system_manager_adapter_abandon_audio_focus(
      _struct, ArkAudioInterruptAdapterCppToC::Invert(audioInterrupt));
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioSystemManagerAdapterCToCpp::SetAudioManagerInterruptCallback(
    ArkWebRefPtr<ArkAudioManagerCallbackAdapter> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_system_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_system_manager_adapter_set_audio_manager_interrupt_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "PY0UVHGmdj8fO4EpeZbazA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_SYSTEM_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_system_manager_adapter_set_audio_manager_interrupt_"
          "callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      set_audio_manager_interrupt_callback)) {
        ark_audio_system_manager_adapter_set_audio_manager_interrupt_callback =
            nullptr;
      } else {
        ark_audio_system_manager_adapter_set_audio_manager_interrupt_callback =
            _struct->set_audio_manager_interrupt_callback;
      }
    } else {
      ark_audio_system_manager_adapter_set_audio_manager_interrupt_callback =
          reinterpret_cast<
              ArkAudioSystemManagerAdapterSetAudioManagerInterruptCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_system_manager_adapter_set_audio_manager_interrupt_callback, 0);

  // Execute
  return ark_audio_system_manager_adapter_set_audio_manager_interrupt_callback(
      _struct, ArkAudioManagerCallbackAdapterCppToC::Invert(callback));
}

ARK_WEB_NO_SANITIZE
int32_t
ArkAudioSystemManagerAdapterCToCpp::UnsetAudioManagerInterruptCallback() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_system_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_system_manager_adapter_unset_audio_manager_interrupt_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Ngw1jCwJp4wrSrWubWMptw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_SYSTEM_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_system_manager_adapter_unset_audio_manager_interrupt_"
          "callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      unset_audio_manager_interrupt_callback)) {
        ark_audio_system_manager_adapter_unset_audio_manager_interrupt_callback =
            nullptr;
      } else {
        ark_audio_system_manager_adapter_unset_audio_manager_interrupt_callback =
            _struct->unset_audio_manager_interrupt_callback;
      }
    } else {
      ark_audio_system_manager_adapter_unset_audio_manager_interrupt_callback =
          reinterpret_cast<
              ArkAudioSystemManagerAdapterUnsetAudioManagerInterruptCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_system_manager_adapter_unset_audio_manager_interrupt_callback,
      0);

  // Execute
  return ark_audio_system_manager_adapter_unset_audio_manager_interrupt_callback(
      _struct);
}

ARK_WEB_NO_SANITIZE
ArkAudioDeviceDescAdapterVector ArkAudioSystemManagerAdapterCToCpp::GetDevices(
    int32_t flag) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_system_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, {0});

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_system_manager_adapter_get_devices);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "wj6iH0szy2K6sup3kyFsFQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_SYSTEM_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_system_manager_adapter_get_devices");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_devices)) {
        ark_audio_system_manager_adapter_get_devices = nullptr;
      } else {
        ark_audio_system_manager_adapter_get_devices = _struct->get_devices;
      }
    } else {
      ark_audio_system_manager_adapter_get_devices =
          reinterpret_cast<ArkAudioSystemManagerAdapterGetDevicesFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_system_manager_adapter_get_devices, {0});

  // Execute
  return ark_audio_system_manager_adapter_get_devices(_struct, flag);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioSystemManagerAdapterCToCpp::SelectAudioDeviceById(
    int32_t deviceId,
    bool isInput) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_system_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_system_manager_adapter_select_audio_device_by_id);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ZQhSX$XfNzS3v_olOYWbkA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_SYSTEM_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_system_manager_adapter_select_audio_device_by_id");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, select_audio_device_by_id)) {
        ark_audio_system_manager_adapter_select_audio_device_by_id = nullptr;
      } else {
        ark_audio_system_manager_adapter_select_audio_device_by_id =
            _struct->select_audio_device_by_id;
      }
    } else {
      ark_audio_system_manager_adapter_select_audio_device_by_id =
          reinterpret_cast<
              ArkAudioSystemManagerAdapterSelectAudioDeviceByIdFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_system_manager_adapter_select_audio_device_by_id, 0);

  // Execute
  return ark_audio_system_manager_adapter_select_audio_device_by_id(
      _struct, deviceId, isInput);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioSystemManagerAdapterCToCpp::SetDeviceChangeCallback(
    ArkWebRefPtr<ArkAudioManagerDeviceChangeCallbackAdapter> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_system_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_system_manager_adapter_set_device_change_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "OEAtmSog$iP5OTmHjqyYFA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_SYSTEM_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_system_manager_adapter_set_device_change_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_device_change_callback)) {
        ark_audio_system_manager_adapter_set_device_change_callback = nullptr;
      } else {
        ark_audio_system_manager_adapter_set_device_change_callback =
            _struct->set_device_change_callback;
      }
    } else {
      ark_audio_system_manager_adapter_set_device_change_callback =
          reinterpret_cast<
              ArkAudioSystemManagerAdapterSetDeviceChangeCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_system_manager_adapter_set_device_change_callback, 0);

  // Execute
  return ark_audio_system_manager_adapter_set_device_change_callback(
      _struct,
      ArkAudioManagerDeviceChangeCallbackAdapterCppToC::Invert(callback));
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioSystemManagerAdapterCToCpp::UnsetDeviceChangeCallback() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_system_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_system_manager_adapter_unset_device_change_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "apPcgGmq5RuRguFT$a1z0A";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_SYSTEM_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_system_manager_adapter_unset_device_change_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, unset_device_change_callback)) {
        ark_audio_system_manager_adapter_unset_device_change_callback = nullptr;
      } else {
        ark_audio_system_manager_adapter_unset_device_change_callback =
            _struct->unset_device_change_callback;
      }
    } else {
      ark_audio_system_manager_adapter_unset_device_change_callback =
          reinterpret_cast<
              ArkAudioSystemManagerAdapterUnsetDeviceChangeCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_system_manager_adapter_unset_device_change_callback, 0);

  // Execute
  return ark_audio_system_manager_adapter_unset_device_change_callback(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkAudioDeviceDescAdapter>
ArkAudioSystemManagerAdapterCToCpp::GetDefaultOutputDevice() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_system_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_system_manager_adapter_get_default_output_device);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "9BlmjRNDXKKVKCrs5criIA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_SYSTEM_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_system_manager_adapter_get_default_output_device");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_default_output_device)) {
        ark_audio_system_manager_adapter_get_default_output_device = nullptr;
      } else {
        ark_audio_system_manager_adapter_get_default_output_device =
            _struct->get_default_output_device;
      }
    } else {
      ark_audio_system_manager_adapter_get_default_output_device =
          reinterpret_cast<
              ArkAudioSystemManagerAdapterGetDefaultOutputDeviceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_system_manager_adapter_get_default_output_device, nullptr);

  // Execute
  ark_audio_device_desc_adapter_t* _retval =
      ark_audio_system_manager_adapter_get_default_output_device(_struct);

  // Return type: refptr_same
  return ArkAudioDeviceDescAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkAudioDeviceDescAdapter>
ArkAudioSystemManagerAdapterCToCpp::GetDefaultInputDevice() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_system_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_system_manager_adapter_get_default_input_device);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "W2wc2A0Vdg4L25PMrE1Kmg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_SYSTEM_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_system_manager_adapter_get_default_input_device");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_default_input_device)) {
        ark_audio_system_manager_adapter_get_default_input_device = nullptr;
      } else {
        ark_audio_system_manager_adapter_get_default_input_device =
            _struct->get_default_input_device;
      }
    } else {
      ark_audio_system_manager_adapter_get_default_input_device =
          reinterpret_cast<
              ArkAudioSystemManagerAdapterGetDefaultInputDeviceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_system_manager_adapter_get_default_input_device, nullptr);

  // Execute
  ark_audio_device_desc_adapter_t* _retval =
      ark_audio_system_manager_adapter_get_default_input_device(_struct);

  // Return type: refptr_same
  return ArkAudioDeviceDescAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
bool ArkAudioSystemManagerAdapterCToCpp::SetLanguage(
    const ArkWebString& language) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_system_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_system_manager_adapter_set_language);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "kAnSjKmRUaQswfel0UCWkA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_SYSTEM_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_system_manager_adapter_set_language");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_language)) {
        ark_audio_system_manager_adapter_set_language = nullptr;
      } else {
        ark_audio_system_manager_adapter_set_language = _struct->set_language;
      }
    } else {
      ark_audio_system_manager_adapter_set_language =
          reinterpret_cast<ArkAudioSystemManagerAdapterSetLanguageFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_system_manager_adapter_set_language, false);

  // Execute
  return ark_audio_system_manager_adapter_set_language(_struct, &language);
}

ArkAudioSystemManagerAdapterCToCpp::ArkAudioSystemManagerAdapterCToCpp() {}

ArkAudioSystemManagerAdapterCToCpp::~ArkAudioSystemManagerAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkAudioSystemManagerAdapterCToCpp,
                           ArkAudioSystemManagerAdapter,
                           ark_audio_system_manager_adapter_t>::kBridgeType =
        ARK_AUDIO_SYSTEM_MANAGER_ADAPTER;

}  // namespace OHOS::ArkWeb
