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

#include "ohos_adapter/ctocpp/ark_media_avsession_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_media_avsession_callback_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_media_avsession_metadata_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_media_avsession_position_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkMediaAVSessionAdapterCreateAVSessionFunc =
    bool (*)(struct _ark_media_avsession_adapter_t* self, int32_t type);
static ArkMediaAVSessionAdapterCreateAVSessionFunc
    ark_media_avsession_adapter_create_avsession =
        reinterpret_cast<ArkMediaAVSessionAdapterCreateAVSessionFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaAVSessionAdapterDestroyAVSessionFunc =
    void (*)(struct _ark_media_avsession_adapter_t* self);
static ArkMediaAVSessionAdapterDestroyAVSessionFunc
    ark_media_avsession_adapter_destroy_avsession =
        reinterpret_cast<ArkMediaAVSessionAdapterDestroyAVSessionFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaAVSessionAdapterRegistCallbackFunc =
    bool (*)(struct _ark_media_avsession_adapter_t* self,
             ark_media_avsession_callback_adapter_t* callbackAdapter);
static ArkMediaAVSessionAdapterRegistCallbackFunc
    ark_media_avsession_adapter_regist_callback =
        reinterpret_cast<ArkMediaAVSessionAdapterRegistCallbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaAVSessionAdapterIsActivatedFunc =
    bool (*)(struct _ark_media_avsession_adapter_t* self);
static ArkMediaAVSessionAdapterIsActivatedFunc
    ark_media_avsession_adapter_is_activated =
        reinterpret_cast<ArkMediaAVSessionAdapterIsActivatedFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaAVSessionAdapterActivateFunc =
    bool (*)(struct _ark_media_avsession_adapter_t* self);
static ArkMediaAVSessionAdapterActivateFunc
    ark_media_avsession_adapter_activate =
        reinterpret_cast<ArkMediaAVSessionAdapterActivateFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaAVSessionAdapterDeActivateFunc =
    void (*)(struct _ark_media_avsession_adapter_t* self);
static ArkMediaAVSessionAdapterDeActivateFunc
    ark_media_avsession_adapter_de_activate =
        reinterpret_cast<ArkMediaAVSessionAdapterDeActivateFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaAVSessionAdapterSetMetadataFunc =
    void (*)(struct _ark_media_avsession_adapter_t* self,
             ark_media_avsession_metadata_adapter_t* metadata);
static ArkMediaAVSessionAdapterSetMetadataFunc
    ark_media_avsession_adapter_set_metadata =
        reinterpret_cast<ArkMediaAVSessionAdapterSetMetadataFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaAVSessionAdapterSetPlaybackStateFunc =
    void (*)(struct _ark_media_avsession_adapter_t* self, int32_t state);
static ArkMediaAVSessionAdapterSetPlaybackStateFunc
    ark_media_avsession_adapter_set_playback_state =
        reinterpret_cast<ArkMediaAVSessionAdapterSetPlaybackStateFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaAVSessionAdapterSetPlaybackPositionFunc =
    void (*)(struct _ark_media_avsession_adapter_t* self,
             ark_media_avsession_position_adapter_t* position);
static ArkMediaAVSessionAdapterSetPlaybackPositionFunc
    ark_media_avsession_adapter_set_playback_position =
        reinterpret_cast<ArkMediaAVSessionAdapterSetPlaybackPositionFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
bool ArkMediaAVSessionAdapterCToCpp::CreateAVSession(int32_t type) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_avsession_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_avsession_adapter_create_avsession);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ngHLh5_XIoWd$mYGFZy3fQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_AVSESSION_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_avsession_adapter_create_avsession");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_avsession)) {
        ark_media_avsession_adapter_create_avsession = nullptr;
      } else {
        ark_media_avsession_adapter_create_avsession =
            _struct->create_avsession;
      }
    } else {
      ark_media_avsession_adapter_create_avsession =
          reinterpret_cast<ArkMediaAVSessionAdapterCreateAVSessionFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_avsession_adapter_create_avsession, false);

  // Execute
  return ark_media_avsession_adapter_create_avsession(_struct, type);
}

ARK_WEB_NO_SANITIZE
void ArkMediaAVSessionAdapterCToCpp::DestroyAVSession() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_avsession_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_avsession_adapter_destroy_avsession);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ug_HLz8ZO$EAqNz3_TJDqQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_AVSESSION_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_avsession_adapter_destroy_avsession");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, destroy_avsession)) {
        ark_media_avsession_adapter_destroy_avsession = nullptr;
      } else {
        ark_media_avsession_adapter_destroy_avsession =
            _struct->destroy_avsession;
      }
    } else {
      ark_media_avsession_adapter_destroy_avsession =
          reinterpret_cast<ArkMediaAVSessionAdapterDestroyAVSessionFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_avsession_adapter_destroy_avsession, ARK_WEB_RETURN_VOID);

  // Execute
  ark_media_avsession_adapter_destroy_avsession(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkMediaAVSessionAdapterCToCpp::RegistCallback(
    ArkWebRefPtr<ArkMediaAVSessionCallbackAdapter> callbackAdapter) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_avsession_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_avsession_adapter_regist_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "SALPEYo59Ta_ec4DNxevEw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_AVSESSION_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_avsession_adapter_regist_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, regist_callback)) {
        ark_media_avsession_adapter_regist_callback = nullptr;
      } else {
        ark_media_avsession_adapter_regist_callback = _struct->regist_callback;
      }
    } else {
      ark_media_avsession_adapter_regist_callback =
          reinterpret_cast<ArkMediaAVSessionAdapterRegistCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_media_avsession_adapter_regist_callback,
                                    false);

  // Execute
  return ark_media_avsession_adapter_regist_callback(
      _struct, ArkMediaAVSessionCallbackAdapterCppToC::Invert(callbackAdapter));
}

ARK_WEB_NO_SANITIZE
bool ArkMediaAVSessionAdapterCToCpp::IsActivated() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_avsession_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_avsession_adapter_is_activated);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "GQDEH116Ec_cioXTpMYEYg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_AVSESSION_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_avsession_adapter_is_activated");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_activated)) {
        ark_media_avsession_adapter_is_activated = nullptr;
      } else {
        ark_media_avsession_adapter_is_activated = _struct->is_activated;
      }
    } else {
      ark_media_avsession_adapter_is_activated =
          reinterpret_cast<ArkMediaAVSessionAdapterIsActivatedFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_media_avsession_adapter_is_activated,
                                    false);

  // Execute
  return ark_media_avsession_adapter_is_activated(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkMediaAVSessionAdapterCToCpp::Activate() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_avsession_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_avsession_adapter_activate);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "2UHeyhU3w1748aASOpdvbA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_AVSESSION_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_media_avsession_adapter_activate");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, activate)) {
        ark_media_avsession_adapter_activate = nullptr;
      } else {
        ark_media_avsession_adapter_activate = _struct->activate;
      }
    } else {
      ark_media_avsession_adapter_activate =
          reinterpret_cast<ArkMediaAVSessionAdapterActivateFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_media_avsession_adapter_activate,
                                    false);

  // Execute
  return ark_media_avsession_adapter_activate(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkMediaAVSessionAdapterCToCpp::DeActivate() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_avsession_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_avsession_adapter_de_activate);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "UPFhyiuIt3_NOmSrUsQ8Xw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_AVSESSION_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_media_avsession_adapter_de_activate");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, de_activate)) {
        ark_media_avsession_adapter_de_activate = nullptr;
      } else {
        ark_media_avsession_adapter_de_activate = _struct->de_activate;
      }
    } else {
      ark_media_avsession_adapter_de_activate =
          reinterpret_cast<ArkMediaAVSessionAdapterDeActivateFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_media_avsession_adapter_de_activate,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_media_avsession_adapter_de_activate(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkMediaAVSessionAdapterCToCpp::SetMetadata(
    const ArkWebRefPtr<ArkMediaAVSessionMetadataAdapter> metadata) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_avsession_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_avsession_adapter_set_metadata);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "qIQzxvfGPXVOePy2SIZJRA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_AVSESSION_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_avsession_adapter_set_metadata");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_metadata)) {
        ark_media_avsession_adapter_set_metadata = nullptr;
      } else {
        ark_media_avsession_adapter_set_metadata = _struct->set_metadata;
      }
    } else {
      ark_media_avsession_adapter_set_metadata =
          reinterpret_cast<ArkMediaAVSessionAdapterSetMetadataFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_media_avsession_adapter_set_metadata,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_media_avsession_adapter_set_metadata(
      _struct, ArkMediaAVSessionMetadataAdapterCppToC::Invert(metadata));
}

ARK_WEB_NO_SANITIZE
void ArkMediaAVSessionAdapterCToCpp::SetPlaybackState(int32_t state) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_avsession_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_avsession_adapter_set_playback_state);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "vkTmcHg$M5h9c7qZ5VI1Zg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_AVSESSION_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_avsession_adapter_set_playback_state");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_playback_state)) {
        ark_media_avsession_adapter_set_playback_state = nullptr;
      } else {
        ark_media_avsession_adapter_set_playback_state =
            _struct->set_playback_state;
      }
    } else {
      ark_media_avsession_adapter_set_playback_state =
          reinterpret_cast<ArkMediaAVSessionAdapterSetPlaybackStateFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_avsession_adapter_set_playback_state, ARK_WEB_RETURN_VOID);

  // Execute
  ark_media_avsession_adapter_set_playback_state(_struct, state);
}

ARK_WEB_NO_SANITIZE
void ArkMediaAVSessionAdapterCToCpp::SetPlaybackPosition(
    const ArkWebRefPtr<ArkMediaAVSessionPositionAdapter> position) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_avsession_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_media_avsession_adapter_set_playback_position);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "P_OhklfjG0lCCag208TUNQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_AVSESSION_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_avsession_adapter_set_playback_position");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_playback_position)) {
        ark_media_avsession_adapter_set_playback_position = nullptr;
      } else {
        ark_media_avsession_adapter_set_playback_position =
            _struct->set_playback_position;
      }
    } else {
      ark_media_avsession_adapter_set_playback_position =
          reinterpret_cast<ArkMediaAVSessionAdapterSetPlaybackPositionFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_avsession_adapter_set_playback_position, ARK_WEB_RETURN_VOID);

  // Execute
  ark_media_avsession_adapter_set_playback_position(
      _struct, ArkMediaAVSessionPositionAdapterCppToC::Invert(position));
}

ArkMediaAVSessionAdapterCToCpp::ArkMediaAVSessionAdapterCToCpp() {}

ArkMediaAVSessionAdapterCToCpp::~ArkMediaAVSessionAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkMediaAVSessionAdapterCToCpp,
                           ArkMediaAVSessionAdapter,
                           ark_media_avsession_adapter_t>::kBridgeType =
        ARK_MEDIA_AVSESSION_ADAPTER;

}  // namespace OHOS::ArkWeb
