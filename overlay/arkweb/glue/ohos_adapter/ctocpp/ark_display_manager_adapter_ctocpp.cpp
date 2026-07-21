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

#include "ohos_adapter/ctocpp/ark_display_manager_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_display_listener_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_fold_status_listener_adapter_cpptoc.h"
#include "ohos_adapter/ctocpp/ark_display_adapter_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkDisplayManagerAdapterGetDefaultDisplayIdFunc =
    uint64_t (*)(struct _ark_display_manager_adapter_t* self);
static ArkDisplayManagerAdapterGetDefaultDisplayIdFunc
    ark_display_manager_adapter_get_default_display_id =
        reinterpret_cast<ArkDisplayManagerAdapterGetDefaultDisplayIdFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDisplayManagerAdapterGetDefaultDisplayFunc =
    ark_display_adapter_t* (*)(struct _ark_display_manager_adapter_t* self);
static ArkDisplayManagerAdapterGetDefaultDisplayFunc
    ark_display_manager_adapter_get_default_display =
        reinterpret_cast<ArkDisplayManagerAdapterGetDefaultDisplayFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDisplayManagerAdapterRegisterDisplayListenerFunc =
    uint32_t (*)(struct _ark_display_manager_adapter_t* self,
                 ark_display_listener_adapter_t* listener);
static ArkDisplayManagerAdapterRegisterDisplayListenerFunc
    ark_display_manager_adapter_register_display_listener =
        reinterpret_cast<ArkDisplayManagerAdapterRegisterDisplayListenerFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDisplayManagerAdapterUnregisterDisplayListenerFunc =
    bool (*)(struct _ark_display_manager_adapter_t* self, uint32_t id);
static ArkDisplayManagerAdapterUnregisterDisplayListenerFunc
    ark_display_manager_adapter_unregister_display_listener =
        reinterpret_cast<ArkDisplayManagerAdapterUnregisterDisplayListenerFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDisplayManagerAdapterIsDefaultPortraitFunc =
    bool (*)(struct _ark_display_manager_adapter_t* self);
static ArkDisplayManagerAdapterIsDefaultPortraitFunc
    ark_display_manager_adapter_is_default_portrait =
        reinterpret_cast<ArkDisplayManagerAdapterIsDefaultPortraitFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDisplayManagerAdapterRegisterFoldStatusListenerFunc =
    uint32_t (*)(struct _ark_display_manager_adapter_t* self,
                 ark_fold_status_listener_adapter_t* listener);
static ArkDisplayManagerAdapterRegisterFoldStatusListenerFunc
    ark_display_manager_adapter_register_fold_status_listener =
        reinterpret_cast<
            ArkDisplayManagerAdapterRegisterFoldStatusListenerFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDisplayManagerAdapterUnregisterFoldStatusListenerFunc =
    bool (*)(struct _ark_display_manager_adapter_t* self, uint32_t id);
static ArkDisplayManagerAdapterUnregisterFoldStatusListenerFunc
    ark_display_manager_adapter_unregister_fold_status_listener =
        reinterpret_cast<
            ArkDisplayManagerAdapterUnregisterFoldStatusListenerFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDisplayManagerAdapterGetPrimaryDisplayFunc =
    ark_display_adapter_t* (*)(struct _ark_display_manager_adapter_t* self);
static ArkDisplayManagerAdapterGetPrimaryDisplayFunc
    ark_display_manager_adapter_get_primary_display =
        reinterpret_cast<ArkDisplayManagerAdapterGetPrimaryDisplayFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDisplayManagerAdapterGetAllDisplaysFunc =
    ArkDisplayAdapterVector (*)(struct _ark_display_manager_adapter_t* self);
static ArkDisplayManagerAdapterGetAllDisplaysFunc
    ark_display_manager_adapter_get_all_displays =
        reinterpret_cast<ArkDisplayManagerAdapterGetAllDisplaysFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
uint64_t ArkDisplayManagerAdapterCToCpp::GetDefaultDisplayId() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_display_manager_adapter_get_default_display_id);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "MLwYilIzbWgM1Lj6chq7Aw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_DISPLAY_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_display_manager_adapter_get_default_display_id");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_default_display_id)) {
        ark_display_manager_adapter_get_default_display_id = nullptr;
      } else {
        ark_display_manager_adapter_get_default_display_id =
            _struct->get_default_display_id;
      }
    } else {
      ark_display_manager_adapter_get_default_display_id =
          reinterpret_cast<ArkDisplayManagerAdapterGetDefaultDisplayIdFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_display_manager_adapter_get_default_display_id, 0);

  // Execute
  return ark_display_manager_adapter_get_default_display_id(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkDisplayAdapter>
ArkDisplayManagerAdapterCToCpp::GetDefaultDisplay() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_display_manager_adapter_get_default_display);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "DkZv8yEpmeJsvvijavjOdQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_DISPLAY_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_display_manager_adapter_get_default_display");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_default_display)) {
        ark_display_manager_adapter_get_default_display = nullptr;
      } else {
        ark_display_manager_adapter_get_default_display =
            _struct->get_default_display;
      }
    } else {
      ark_display_manager_adapter_get_default_display =
          reinterpret_cast<ArkDisplayManagerAdapterGetDefaultDisplayFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_display_manager_adapter_get_default_display, nullptr);

  // Execute
  ark_display_adapter_t* _retval =
      ark_display_manager_adapter_get_default_display(_struct);

  // Return type: refptr_same
  return ArkDisplayAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkDisplayManagerAdapterCToCpp::RegisterDisplayListener(
    ArkWebRefPtr<ArkDisplayListenerAdapter> listener) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_display_manager_adapter_register_display_listener);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "N1JCBxyVU1cCY9urkRxvEQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_DISPLAY_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_display_manager_adapter_register_display_listener");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, register_display_listener)) {
        ark_display_manager_adapter_register_display_listener = nullptr;
      } else {
        ark_display_manager_adapter_register_display_listener =
            _struct->register_display_listener;
      }
    } else {
      ark_display_manager_adapter_register_display_listener =
          reinterpret_cast<ArkDisplayManagerAdapterRegisterDisplayListenerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_display_manager_adapter_register_display_listener, 0);

  // Execute
  return ark_display_manager_adapter_register_display_listener(
      _struct, ArkDisplayListenerAdapterCppToC::Invert(listener));
}

ARK_WEB_NO_SANITIZE
bool ArkDisplayManagerAdapterCToCpp::UnregisterDisplayListener(uint32_t id) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_display_manager_adapter_unregister_display_listener);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "4DL2av4EtUTL7fFTxnmAEQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_DISPLAY_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_display_manager_adapter_unregister_display_listener");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, unregister_display_listener)) {
        ark_display_manager_adapter_unregister_display_listener = nullptr;
      } else {
        ark_display_manager_adapter_unregister_display_listener =
            _struct->unregister_display_listener;
      }
    } else {
      ark_display_manager_adapter_unregister_display_listener =
          reinterpret_cast<
              ArkDisplayManagerAdapterUnregisterDisplayListenerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_display_manager_adapter_unregister_display_listener, false);

  // Execute
  return ark_display_manager_adapter_unregister_display_listener(_struct, id);
}

ARK_WEB_NO_SANITIZE
bool ArkDisplayManagerAdapterCToCpp::IsDefaultPortrait() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_display_manager_adapter_is_default_portrait);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "gTD2gHOdRL_aCQ_BEygAEQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_DISPLAY_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_display_manager_adapter_is_default_portrait");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_default_portrait)) {
        ark_display_manager_adapter_is_default_portrait = nullptr;
      } else {
        ark_display_manager_adapter_is_default_portrait =
            _struct->is_default_portrait;
      }
    } else {
      ark_display_manager_adapter_is_default_portrait =
          reinterpret_cast<ArkDisplayManagerAdapterIsDefaultPortraitFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_display_manager_adapter_is_default_portrait, false);

  // Execute
  return ark_display_manager_adapter_is_default_portrait(_struct);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkDisplayManagerAdapterCToCpp::RegisterFoldStatusListener(
    ArkWebRefPtr<ArkFoldStatusListenerAdapter> listener) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_display_manager_adapter_register_fold_status_listener);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "xLvfUuVqOW$PvyWSXEA14g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_DISPLAY_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_display_manager_adapter_register_fold_status_listener");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, register_fold_status_listener)) {
        ark_display_manager_adapter_register_fold_status_listener = nullptr;
      } else {
        ark_display_manager_adapter_register_fold_status_listener =
            _struct->register_fold_status_listener;
      }
    } else {
      ark_display_manager_adapter_register_fold_status_listener =
          reinterpret_cast<
              ArkDisplayManagerAdapterRegisterFoldStatusListenerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_display_manager_adapter_register_fold_status_listener, 0);

  // Execute
  return ark_display_manager_adapter_register_fold_status_listener(
      _struct, ArkFoldStatusListenerAdapterCppToC::Invert(listener));
}

ARK_WEB_NO_SANITIZE
bool ArkDisplayManagerAdapterCToCpp::UnregisterFoldStatusListener(uint32_t id) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_display_manager_adapter_unregister_fold_status_listener);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "M5nC8yI3F8F2Grd9GlZAeg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_DISPLAY_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_display_manager_adapter_unregister_fold_status_listener");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      unregister_fold_status_listener)) {
        ark_display_manager_adapter_unregister_fold_status_listener = nullptr;
      } else {
        ark_display_manager_adapter_unregister_fold_status_listener =
            _struct->unregister_fold_status_listener;
      }
    } else {
      ark_display_manager_adapter_unregister_fold_status_listener =
          reinterpret_cast<
              ArkDisplayManagerAdapterUnregisterFoldStatusListenerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_display_manager_adapter_unregister_fold_status_listener, false);

  // Execute
  return ark_display_manager_adapter_unregister_fold_status_listener(_struct,
                                                                     id);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkDisplayAdapter>
ArkDisplayManagerAdapterCToCpp::GetPrimaryDisplay() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_display_manager_adapter_get_primary_display);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "JCRshORBwDLKt9L$YHbGFw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_DISPLAY_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_display_manager_adapter_get_primary_display");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_primary_display)) {
        ark_display_manager_adapter_get_primary_display = nullptr;
      } else {
        ark_display_manager_adapter_get_primary_display =
            _struct->get_primary_display;
      }
    } else {
      ark_display_manager_adapter_get_primary_display =
          reinterpret_cast<ArkDisplayManagerAdapterGetPrimaryDisplayFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_display_manager_adapter_get_primary_display, nullptr);

  // Execute
  ark_display_adapter_t* _retval =
      ark_display_manager_adapter_get_primary_display(_struct);

  // Return type: refptr_same
  return ArkDisplayAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkDisplayAdapterVector ArkDisplayManagerAdapterCToCpp::GetAllDisplays() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_display_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, {0});

  void* func_pointer =
      reinterpret_cast<void*>(ark_display_manager_adapter_get_all_displays);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "fUMhgbXLbfv7trvXTyA7OQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_DISPLAY_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_display_manager_adapter_get_all_displays");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_all_displays)) {
        ark_display_manager_adapter_get_all_displays = nullptr;
      } else {
        ark_display_manager_adapter_get_all_displays =
            _struct->get_all_displays;
      }
    } else {
      ark_display_manager_adapter_get_all_displays =
          reinterpret_cast<ArkDisplayManagerAdapterGetAllDisplaysFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_display_manager_adapter_get_all_displays, {0});

  // Execute
  return ark_display_manager_adapter_get_all_displays(_struct);
}

ArkDisplayManagerAdapterCToCpp::ArkDisplayManagerAdapterCToCpp() {}

ArkDisplayManagerAdapterCToCpp::~ArkDisplayManagerAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkDisplayManagerAdapterCToCpp,
                           ArkDisplayManagerAdapter,
                           ark_display_manager_adapter_t>::kBridgeType =
        ARK_DISPLAY_MANAGER_ADAPTER;

}  // namespace OHOS::ArkWeb
