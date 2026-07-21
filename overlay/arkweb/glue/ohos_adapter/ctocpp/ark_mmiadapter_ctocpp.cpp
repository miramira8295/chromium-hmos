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

#include "ohos_adapter/ctocpp/ark_mmiadapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_mmidevice_info_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_mmiinput_listener_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_mmilistener_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkMMIAdapterKeyCodeToStringFunc =
    char* (*)(struct _ark_mmiadapter_t* self, int32_t keyCode);
static ArkMMIAdapterKeyCodeToStringFunc ark_mmiadapter_key_code_to_string =
    reinterpret_cast<ArkMMIAdapterKeyCodeToStringFunc>(ARK_WEB_INIT_ADDR);

using ArkMMIAdapterRegisterMMIInputListenerFunc =
    int32_t (*)(struct _ark_mmiadapter_t* self,
                ark_mmiinput_listener_adapter_t* eventCallback);
static ArkMMIAdapterRegisterMMIInputListenerFunc
    ark_mmiadapter_register_mmiinput_listener =
        reinterpret_cast<ArkMMIAdapterRegisterMMIInputListenerFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMMIAdapterUnregisterMMIInputListenerFunc =
    void (*)(struct _ark_mmiadapter_t* self, int32_t monitorId);
static ArkMMIAdapterUnregisterMMIInputListenerFunc
    ark_mmiadapter_unregister_mmiinput_listener =
        reinterpret_cast<ArkMMIAdapterUnregisterMMIInputListenerFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMMIAdapterRegisterDevListenerFunc =
    int32_t (*)(struct _ark_mmiadapter_t* self,
                ArkWebString type,
                ark_mmilistener_adapter_t* listener);
static ArkMMIAdapterRegisterDevListenerFunc
    ark_mmiadapter_register_dev_listener =
        reinterpret_cast<ArkMMIAdapterRegisterDevListenerFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMMIAdapterUnregisterDevListenerFunc =
    int32_t (*)(struct _ark_mmiadapter_t* self, ArkWebString type);
static ArkMMIAdapterUnregisterDevListenerFunc
    ark_mmiadapter_unregister_dev_listener =
        reinterpret_cast<ArkMMIAdapterUnregisterDevListenerFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMMIAdapterGetKeyboardTypeFunc =
    int32_t (*)(struct _ark_mmiadapter_t* self,
                int32_t deviceId,
                int32_t* type);
static ArkMMIAdapterGetKeyboardTypeFunc ark_mmiadapter_get_keyboard_type =
    reinterpret_cast<ArkMMIAdapterGetKeyboardTypeFunc>(ARK_WEB_INIT_ADDR);

using ArkMMIAdapterGetDeviceIdsFunc =
    int32_t (*)(struct _ark_mmiadapter_t* self, ArkWebInt32Vector* ids);
static ArkMMIAdapterGetDeviceIdsFunc ark_mmiadapter_get_device_ids =
    reinterpret_cast<ArkMMIAdapterGetDeviceIdsFunc>(ARK_WEB_INIT_ADDR);

using ArkMMIAdapterGetDeviceInfoFunc =
    int32_t (*)(struct _ark_mmiadapter_t* self,
                int32_t deviceId,
                ark_mmidevice_info_adapter_t* info);
static ArkMMIAdapterGetDeviceInfoFunc ark_mmiadapter_get_device_info =
    reinterpret_cast<ArkMMIAdapterGetDeviceInfoFunc>(ARK_WEB_INIT_ADDR);

using ArkMMIAdapterGetMaxTouchPointsFunc =
    int32_t (*)(struct _ark_mmiadapter_t* self);
static ArkMMIAdapterGetMaxTouchPointsFunc ark_mmiadapter_get_max_touch_points =
    reinterpret_cast<ArkMMIAdapterGetMaxTouchPointsFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
char* ArkMMIAdapterCToCpp::KeyCodeToString(int32_t keyCode) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_mmiadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_mmiadapter_key_code_to_string);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "MWqrZEfrusHgUGEF$ff5hQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_MMIADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_mmiadapter_key_code_to_string");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, key_code_to_string)) {
        ark_mmiadapter_key_code_to_string = nullptr;
      } else {
        ark_mmiadapter_key_code_to_string = _struct->key_code_to_string;
      }
    } else {
      ark_mmiadapter_key_code_to_string =
          reinterpret_cast<ArkMMIAdapterKeyCodeToStringFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_mmiadapter_key_code_to_string, nullptr);

  // Execute
  return ark_mmiadapter_key_code_to_string(_struct, keyCode);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMMIAdapterCToCpp::RegisterMMIInputListener(
    ArkWebRefPtr<ArkMMIInputListenerAdapter> eventCallback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_mmiadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_mmiadapter_register_mmiinput_listener);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "UE3PgpsoNFqY0MVEwPcAIw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_MMIADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_mmiadapter_register_mmiinput_listener");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, register_mmiinput_listener)) {
        ark_mmiadapter_register_mmiinput_listener = nullptr;
      } else {
        ark_mmiadapter_register_mmiinput_listener =
            _struct->register_mmiinput_listener;
      }
    } else {
      ark_mmiadapter_register_mmiinput_listener =
          reinterpret_cast<ArkMMIAdapterRegisterMMIInputListenerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_mmiadapter_register_mmiinput_listener,
                                    0);

  // Execute
  return ark_mmiadapter_register_mmiinput_listener(
      _struct, ArkMMIInputListenerAdapterCppToC::Invert(eventCallback));
}

ARK_WEB_NO_SANITIZE
void ArkMMIAdapterCToCpp::UnregisterMMIInputListener(int32_t monitorId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_mmiadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_mmiadapter_unregister_mmiinput_listener);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "W9Vr_NvqJEow9wgG$wiERQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_MMIADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_mmiadapter_unregister_mmiinput_listener");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, unregister_mmiinput_listener)) {
        ark_mmiadapter_unregister_mmiinput_listener = nullptr;
      } else {
        ark_mmiadapter_unregister_mmiinput_listener =
            _struct->unregister_mmiinput_listener;
      }
    } else {
      ark_mmiadapter_unregister_mmiinput_listener =
          reinterpret_cast<ArkMMIAdapterUnregisterMMIInputListenerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_mmiadapter_unregister_mmiinput_listener,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_mmiadapter_unregister_mmiinput_listener(_struct, monitorId);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMMIAdapterCToCpp::RegisterDevListener(
    ArkWebString type,
    ArkWebRefPtr<ArkMMIListenerAdapter> listener) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_mmiadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_mmiadapter_register_dev_listener);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "7ntY_mIQPKUaS3At3yOWXw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_MMIADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_mmiadapter_register_dev_listener");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, register_dev_listener)) {
        ark_mmiadapter_register_dev_listener = nullptr;
      } else {
        ark_mmiadapter_register_dev_listener = _struct->register_dev_listener;
      }
    } else {
      ark_mmiadapter_register_dev_listener =
          reinterpret_cast<ArkMMIAdapterRegisterDevListenerFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_mmiadapter_register_dev_listener, 0);

  // Execute
  return ark_mmiadapter_register_dev_listener(
      _struct, type, ArkMMIListenerAdapterCppToC::Invert(listener));
}

ARK_WEB_NO_SANITIZE
int32_t ArkMMIAdapterCToCpp::UnregisterDevListener(ArkWebString type) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_mmiadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_mmiadapter_unregister_dev_listener);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "9VFEwUqYbiDc3yfLF9AFtw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_MMIADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_mmiadapter_unregister_dev_listener");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, unregister_dev_listener)) {
        ark_mmiadapter_unregister_dev_listener = nullptr;
      } else {
        ark_mmiadapter_unregister_dev_listener =
            _struct->unregister_dev_listener;
      }
    } else {
      ark_mmiadapter_unregister_dev_listener =
          reinterpret_cast<ArkMMIAdapterUnregisterDevListenerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_mmiadapter_unregister_dev_listener, 0);

  // Execute
  return ark_mmiadapter_unregister_dev_listener(_struct, type);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMMIAdapterCToCpp::GetKeyboardType(int32_t deviceId, int32_t& type) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_mmiadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_mmiadapter_get_keyboard_type);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "KDoHTLdCipI3S95g9nSkSg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_MMIADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_mmiadapter_get_keyboard_type");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_keyboard_type)) {
        ark_mmiadapter_get_keyboard_type = nullptr;
      } else {
        ark_mmiadapter_get_keyboard_type = _struct->get_keyboard_type;
      }
    } else {
      ark_mmiadapter_get_keyboard_type =
          reinterpret_cast<ArkMMIAdapterGetKeyboardTypeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_mmiadapter_get_keyboard_type, 0);

  // Execute
  return ark_mmiadapter_get_keyboard_type(_struct, deviceId, &type);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMMIAdapterCToCpp::GetDeviceIds(ArkWebInt32Vector& ids) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_mmiadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_mmiadapter_get_device_ids);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "fgQnn6JFE0hxncqhGnISxw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_MMIADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_mmiadapter_get_device_ids");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_device_ids)) {
        ark_mmiadapter_get_device_ids = nullptr;
      } else {
        ark_mmiadapter_get_device_ids = _struct->get_device_ids;
      }
    } else {
      ark_mmiadapter_get_device_ids =
          reinterpret_cast<ArkMMIAdapterGetDeviceIdsFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_mmiadapter_get_device_ids, 0);

  // Execute
  return ark_mmiadapter_get_device_ids(_struct, &ids);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMMIAdapterCToCpp::GetDeviceInfo(
    int32_t deviceId,
    ArkWebRefPtr<ArkMMIDeviceInfoAdapter> info) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_mmiadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_mmiadapter_get_device_info);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "cpwErCLX3zbOBxGUiBl61g";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_MMIADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_mmiadapter_get_device_info");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_device_info)) {
        ark_mmiadapter_get_device_info = nullptr;
      } else {
        ark_mmiadapter_get_device_info = _struct->get_device_info;
      }
    } else {
      ark_mmiadapter_get_device_info =
          reinterpret_cast<ArkMMIAdapterGetDeviceInfoFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_mmiadapter_get_device_info, 0);

  // Execute
  return ark_mmiadapter_get_device_info(
      _struct, deviceId, ArkMMIDeviceInfoAdapterCppToC::Invert(info));
}

ARK_WEB_NO_SANITIZE
int32_t ArkMMIAdapterCToCpp::GetMaxTouchPoints() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_mmiadapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_mmiadapter_get_max_touch_points);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "CGy1VoHBPWOVEzxsLRaHmA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_MMIADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_mmiadapter_get_max_touch_points");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_max_touch_points)) {
        ark_mmiadapter_get_max_touch_points = nullptr;
      } else {
        ark_mmiadapter_get_max_touch_points = _struct->get_max_touch_points;
      }
    } else {
      ark_mmiadapter_get_max_touch_points =
          reinterpret_cast<ArkMMIAdapterGetMaxTouchPointsFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_mmiadapter_get_max_touch_points, 0);

  // Execute
  return ark_mmiadapter_get_max_touch_points(_struct);
}

ArkMMIAdapterCToCpp::ArkMMIAdapterCToCpp() {}

ArkMMIAdapterCToCpp::~ArkMMIAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkMMIAdapterCToCpp,
                                        ArkMMIAdapter,
                                        ark_mmiadapter_t>::kBridgeType =
    ARK_MMIADAPTER;

}  // namespace OHOS::ArkWeb
