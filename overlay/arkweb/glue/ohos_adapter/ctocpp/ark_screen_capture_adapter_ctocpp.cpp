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

#include "ohos_adapter/ctocpp/ark_screen_capture_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_audio_buffer_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_screen_capture_callback_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_screen_capture_config_adapter_cpptoc.h"
#include "ohos_adapter/ctocpp/ark_surface_buffer_adapter_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkScreenCaptureAdapterInitFunc =
    int32_t (*)(struct _ark_screen_capture_adapter_t* self,
                ark_screen_capture_config_adapter_t* config);
static ArkScreenCaptureAdapterInitFunc ark_screen_capture_adapter_init =
    reinterpret_cast<ArkScreenCaptureAdapterInitFunc>(ARK_WEB_INIT_ADDR);

using ArkScreenCaptureAdapterSetMicrophoneEnableFunc =
    int32_t (*)(struct _ark_screen_capture_adapter_t* self, bool enable);
static ArkScreenCaptureAdapterSetMicrophoneEnableFunc
    ark_screen_capture_adapter_set_microphone_enable =
        reinterpret_cast<ArkScreenCaptureAdapterSetMicrophoneEnableFunc>(
            ARK_WEB_INIT_ADDR);

using ArkScreenCaptureAdapterStartCaptureFunc =
    int32_t (*)(struct _ark_screen_capture_adapter_t* self);
static ArkScreenCaptureAdapterStartCaptureFunc
    ark_screen_capture_adapter_start_capture =
        reinterpret_cast<ArkScreenCaptureAdapterStartCaptureFunc>(
            ARK_WEB_INIT_ADDR);

using ArkScreenCaptureAdapterStopCaptureFunc =
    int32_t (*)(struct _ark_screen_capture_adapter_t* self);
static ArkScreenCaptureAdapterStopCaptureFunc
    ark_screen_capture_adapter_stop_capture =
        reinterpret_cast<ArkScreenCaptureAdapterStopCaptureFunc>(
            ARK_WEB_INIT_ADDR);

using ArkScreenCaptureAdapterSetCaptureCallbackFunc =
    int32_t (*)(struct _ark_screen_capture_adapter_t* self,
                ark_screen_capture_callback_adapter_t* callback);
static ArkScreenCaptureAdapterSetCaptureCallbackFunc
    ark_screen_capture_adapter_set_capture_callback =
        reinterpret_cast<ArkScreenCaptureAdapterSetCaptureCallbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkScreenCaptureAdapterAcquireVideoBufferFunc =
    ark_surface_buffer_adapter_t* (*)(struct _ark_screen_capture_adapter_t*
                                          self);
static ArkScreenCaptureAdapterAcquireVideoBufferFunc
    ark_screen_capture_adapter_acquire_video_buffer =
        reinterpret_cast<ArkScreenCaptureAdapterAcquireVideoBufferFunc>(
            ARK_WEB_INIT_ADDR);

using ArkScreenCaptureAdapterReleaseVideoBufferFunc =
    int32_t (*)(struct _ark_screen_capture_adapter_t* self);
static ArkScreenCaptureAdapterReleaseVideoBufferFunc
    ark_screen_capture_adapter_release_video_buffer =
        reinterpret_cast<ArkScreenCaptureAdapterReleaseVideoBufferFunc>(
            ARK_WEB_INIT_ADDR);

using ArkScreenCaptureAdapterAcquireAudioBufferFunc =
    int32_t (*)(struct _ark_screen_capture_adapter_t* self,
                ark_audio_buffer_adapter_t* audiobuffer,
                int32_t type);
static ArkScreenCaptureAdapterAcquireAudioBufferFunc
    ark_screen_capture_adapter_acquire_audio_buffer =
        reinterpret_cast<ArkScreenCaptureAdapterAcquireAudioBufferFunc>(
            ARK_WEB_INIT_ADDR);

using ArkScreenCaptureAdapterReleaseAudioBufferFunc =
    int32_t (*)(struct _ark_screen_capture_adapter_t* self, int32_t type);
static ArkScreenCaptureAdapterReleaseAudioBufferFunc
    ark_screen_capture_adapter_release_audio_buffer =
        reinterpret_cast<ArkScreenCaptureAdapterReleaseAudioBufferFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkScreenCaptureAdapterCToCpp::Init(
    const ArkWebRefPtr<ArkScreenCaptureConfigAdapter> config) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_screen_capture_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_screen_capture_adapter_init);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "llw5qnbD7KFCiVlRgxtpJg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SCREEN_CAPTURE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_screen_capture_adapter_init");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, init)) {
        ark_screen_capture_adapter_init = nullptr;
      } else {
        ark_screen_capture_adapter_init = _struct->init;
      }
    } else {
      ark_screen_capture_adapter_init =
          reinterpret_cast<ArkScreenCaptureAdapterInitFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_screen_capture_adapter_init, 0);

  // Execute
  return ark_screen_capture_adapter_init(
      _struct, ArkScreenCaptureConfigAdapterCppToC::Invert(config));
}

ARK_WEB_NO_SANITIZE
int32_t ArkScreenCaptureAdapterCToCpp::SetMicrophoneEnable(bool enable) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_screen_capture_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_screen_capture_adapter_set_microphone_enable);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "kDMrBfUQw02gpvTmZ9zzfA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SCREEN_CAPTURE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_screen_capture_adapter_set_microphone_enable");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_microphone_enable)) {
        ark_screen_capture_adapter_set_microphone_enable = nullptr;
      } else {
        ark_screen_capture_adapter_set_microphone_enable =
            _struct->set_microphone_enable;
      }
    } else {
      ark_screen_capture_adapter_set_microphone_enable =
          reinterpret_cast<ArkScreenCaptureAdapterSetMicrophoneEnableFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_screen_capture_adapter_set_microphone_enable, 0);

  // Execute
  return ark_screen_capture_adapter_set_microphone_enable(_struct, enable);
}

ARK_WEB_NO_SANITIZE
int32_t ArkScreenCaptureAdapterCToCpp::StartCapture() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_screen_capture_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_screen_capture_adapter_start_capture);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "IDkUwHOYQHbJv_Ac3DAt_g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SCREEN_CAPTURE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_screen_capture_adapter_start_capture");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start_capture)) {
        ark_screen_capture_adapter_start_capture = nullptr;
      } else {
        ark_screen_capture_adapter_start_capture = _struct->start_capture;
      }
    } else {
      ark_screen_capture_adapter_start_capture =
          reinterpret_cast<ArkScreenCaptureAdapterStartCaptureFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_screen_capture_adapter_start_capture,
                                    0);

  // Execute
  return ark_screen_capture_adapter_start_capture(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkScreenCaptureAdapterCToCpp::StopCapture() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_screen_capture_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_screen_capture_adapter_stop_capture);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "MZk8IsCDQV8bFTzjbODQMA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SCREEN_CAPTURE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_screen_capture_adapter_stop_capture");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, stop_capture)) {
        ark_screen_capture_adapter_stop_capture = nullptr;
      } else {
        ark_screen_capture_adapter_stop_capture = _struct->stop_capture;
      }
    } else {
      ark_screen_capture_adapter_stop_capture =
          reinterpret_cast<ArkScreenCaptureAdapterStopCaptureFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_screen_capture_adapter_stop_capture, 0);

  // Execute
  return ark_screen_capture_adapter_stop_capture(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkScreenCaptureAdapterCToCpp::SetCaptureCallback(
    const ArkWebRefPtr<ArkScreenCaptureCallbackAdapter> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_screen_capture_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_screen_capture_adapter_set_capture_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "rnigynNvEGeDMz4t0PCs3w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SCREEN_CAPTURE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_screen_capture_adapter_set_capture_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_capture_callback)) {
        ark_screen_capture_adapter_set_capture_callback = nullptr;
      } else {
        ark_screen_capture_adapter_set_capture_callback =
            _struct->set_capture_callback;
      }
    } else {
      ark_screen_capture_adapter_set_capture_callback =
          reinterpret_cast<ArkScreenCaptureAdapterSetCaptureCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_screen_capture_adapter_set_capture_callback, 0);

  // Execute
  return ark_screen_capture_adapter_set_capture_callback(
      _struct, ArkScreenCaptureCallbackAdapterCppToC::Invert(callback));
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkSurfaceBufferAdapter>
ArkScreenCaptureAdapterCToCpp::AcquireVideoBuffer() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_screen_capture_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_screen_capture_adapter_acquire_video_buffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "MkjOM6nFXyZlOpQugCc6Sg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SCREEN_CAPTURE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_screen_capture_adapter_acquire_video_buffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, acquire_video_buffer)) {
        ark_screen_capture_adapter_acquire_video_buffer = nullptr;
      } else {
        ark_screen_capture_adapter_acquire_video_buffer =
            _struct->acquire_video_buffer;
      }
    } else {
      ark_screen_capture_adapter_acquire_video_buffer =
          reinterpret_cast<ArkScreenCaptureAdapterAcquireVideoBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_screen_capture_adapter_acquire_video_buffer, nullptr);

  // Execute
  ark_surface_buffer_adapter_t* _retval =
      ark_screen_capture_adapter_acquire_video_buffer(_struct);

  // Return type: refptr_same
  return ArkSurfaceBufferAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
int32_t ArkScreenCaptureAdapterCToCpp::ReleaseVideoBuffer() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_screen_capture_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_screen_capture_adapter_release_video_buffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "DgamY6WWX0KywK0NdhwZDw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SCREEN_CAPTURE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_screen_capture_adapter_release_video_buffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release_video_buffer)) {
        ark_screen_capture_adapter_release_video_buffer = nullptr;
      } else {
        ark_screen_capture_adapter_release_video_buffer =
            _struct->release_video_buffer;
      }
    } else {
      ark_screen_capture_adapter_release_video_buffer =
          reinterpret_cast<ArkScreenCaptureAdapterReleaseVideoBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_screen_capture_adapter_release_video_buffer, 0);

  // Execute
  return ark_screen_capture_adapter_release_video_buffer(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkScreenCaptureAdapterCToCpp::AcquireAudioBuffer(
    ArkWebRefPtr<ArkAudioBufferAdapter> audiobuffer,
    int32_t type) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_screen_capture_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_screen_capture_adapter_acquire_audio_buffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "u_UyA9uO40wvI7u5O2s4EA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SCREEN_CAPTURE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_screen_capture_adapter_acquire_audio_buffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, acquire_audio_buffer)) {
        ark_screen_capture_adapter_acquire_audio_buffer = nullptr;
      } else {
        ark_screen_capture_adapter_acquire_audio_buffer =
            _struct->acquire_audio_buffer;
      }
    } else {
      ark_screen_capture_adapter_acquire_audio_buffer =
          reinterpret_cast<ArkScreenCaptureAdapterAcquireAudioBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_screen_capture_adapter_acquire_audio_buffer, 0);

  // Execute
  return ark_screen_capture_adapter_acquire_audio_buffer(
      _struct, ArkAudioBufferAdapterCppToC::Invert(audiobuffer), type);
}

ARK_WEB_NO_SANITIZE
int32_t ArkScreenCaptureAdapterCToCpp::ReleaseAudioBuffer(int32_t type) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_screen_capture_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_screen_capture_adapter_release_audio_buffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "yt$zWCgTIKeKb3zeLIUisg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SCREEN_CAPTURE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_screen_capture_adapter_release_audio_buffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release_audio_buffer)) {
        ark_screen_capture_adapter_release_audio_buffer = nullptr;
      } else {
        ark_screen_capture_adapter_release_audio_buffer =
            _struct->release_audio_buffer;
      }
    } else {
      ark_screen_capture_adapter_release_audio_buffer =
          reinterpret_cast<ArkScreenCaptureAdapterReleaseAudioBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_screen_capture_adapter_release_audio_buffer, 0);

  // Execute
  return ark_screen_capture_adapter_release_audio_buffer(_struct, type);
}

ArkScreenCaptureAdapterCToCpp::ArkScreenCaptureAdapterCToCpp() {}

ArkScreenCaptureAdapterCToCpp::~ArkScreenCaptureAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkScreenCaptureAdapterCToCpp,
                           ArkScreenCaptureAdapter,
                           ark_screen_capture_adapter_t>::kBridgeType =
        ARK_SCREEN_CAPTURE_ADAPTER;

}  // namespace OHOS::ArkWeb
