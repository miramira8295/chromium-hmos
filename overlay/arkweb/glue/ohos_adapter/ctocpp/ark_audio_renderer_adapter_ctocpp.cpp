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

#include "ohos_adapter/ctocpp/ark_audio_renderer_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_audio_output_change_callback_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_audio_renderer_callback_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_audio_renderer_options_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkAudioRendererAdapterCreateFunc =
    int32_t (*)(struct _ark_audio_renderer_adapter_t* self,
                ark_audio_renderer_options_adapter_t* options,
                ArkWebString* str);
static ArkAudioRendererAdapterCreateFunc ark_audio_renderer_adapter_create =
    reinterpret_cast<ArkAudioRendererAdapterCreateFunc>(ARK_WEB_INIT_ADDR);

using ArkAudioRendererAdapterStartFunc =
    bool (*)(struct _ark_audio_renderer_adapter_t* self);
static ArkAudioRendererAdapterStartFunc ark_audio_renderer_adapter_start =
    reinterpret_cast<ArkAudioRendererAdapterStartFunc>(ARK_WEB_INIT_ADDR);

using ArkAudioRendererAdapterPauseFunc =
    bool (*)(struct _ark_audio_renderer_adapter_t* self);
static ArkAudioRendererAdapterPauseFunc ark_audio_renderer_adapter_pause =
    reinterpret_cast<ArkAudioRendererAdapterPauseFunc>(ARK_WEB_INIT_ADDR);

using ArkAudioRendererAdapterStopFunc =
    bool (*)(struct _ark_audio_renderer_adapter_t* self);
static ArkAudioRendererAdapterStopFunc ark_audio_renderer_adapter_stop =
    reinterpret_cast<ArkAudioRendererAdapterStopFunc>(ARK_WEB_INIT_ADDR);

using ArkAudioRendererAdapterRelease2Func =
    bool (*)(struct _ark_audio_renderer_adapter_t* self);
static ArkAudioRendererAdapterRelease2Func ark_audio_renderer_adapter_release2 =
    reinterpret_cast<ArkAudioRendererAdapterRelease2Func>(ARK_WEB_INIT_ADDR);

using ArkAudioRendererAdapterWriteFunc =
    int32_t (*)(struct _ark_audio_renderer_adapter_t* self,
                uint8_t* buffer,
                size_t bufferSize);
static ArkAudioRendererAdapterWriteFunc ark_audio_renderer_adapter_write =
    reinterpret_cast<ArkAudioRendererAdapterWriteFunc>(ARK_WEB_INIT_ADDR);

using ArkAudioRendererAdapterGetLatencyFunc =
    int32_t (*)(struct _ark_audio_renderer_adapter_t* self, uint64_t* latency);
static ArkAudioRendererAdapterGetLatencyFunc
    ark_audio_renderer_adapter_get_latency =
        reinterpret_cast<ArkAudioRendererAdapterGetLatencyFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioRendererAdapterSetVolumeFunc =
    int32_t (*)(struct _ark_audio_renderer_adapter_t* self, float volume);
static ArkAudioRendererAdapterSetVolumeFunc
    ark_audio_renderer_adapter_set_volume =
        reinterpret_cast<ArkAudioRendererAdapterSetVolumeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioRendererAdapterGetVolumeFunc =
    float (*)(struct _ark_audio_renderer_adapter_t* self);
static ArkAudioRendererAdapterGetVolumeFunc
    ark_audio_renderer_adapter_get_volume =
        reinterpret_cast<ArkAudioRendererAdapterGetVolumeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioRendererAdapterSetAudioRendererCallbackFunc =
    int32_t (*)(struct _ark_audio_renderer_adapter_t* self,
                ark_audio_renderer_callback_adapter_t* callback);
static ArkAudioRendererAdapterSetAudioRendererCallbackFunc
    ark_audio_renderer_adapter_set_audio_renderer_callback =
        reinterpret_cast<ArkAudioRendererAdapterSetAudioRendererCallbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioRendererAdapterSetInterruptModeFunc =
    void (*)(struct _ark_audio_renderer_adapter_t* self, bool audioExclusive);
static ArkAudioRendererAdapterSetInterruptModeFunc
    ark_audio_renderer_adapter_set_interrupt_mode =
        reinterpret_cast<ArkAudioRendererAdapterSetInterruptModeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioRendererAdapterIsRendererStateRunningFunc =
    bool (*)(struct _ark_audio_renderer_adapter_t* self);
static ArkAudioRendererAdapterIsRendererStateRunningFunc
    ark_audio_renderer_adapter_is_renderer_state_running =
        reinterpret_cast<ArkAudioRendererAdapterIsRendererStateRunningFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioRendererAdapterSetAudioOutputChangeCallbackFunc =
    int32_t (*)(struct _ark_audio_renderer_adapter_t* self,
                ark_audio_output_change_callback_adapter_t* callback);
static ArkAudioRendererAdapterSetAudioOutputChangeCallbackFunc
    ark_audio_renderer_adapter_set_audio_output_change_callback =
        reinterpret_cast<
            ArkAudioRendererAdapterSetAudioOutputChangeCallbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioRendererAdapterSetAudioSilentModeFunc =
    void (*)(struct _ark_audio_renderer_adapter_t* self, bool isSilentMode);
static ArkAudioRendererAdapterSetAudioSilentModeFunc
    ark_audio_renderer_adapter_set_audio_silent_mode =
        reinterpret_cast<ArkAudioRendererAdapterSetAudioSilentModeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioRendererAdapterFlushFunc =
    bool (*)(struct _ark_audio_renderer_adapter_t* self);
static ArkAudioRendererAdapterFlushFunc ark_audio_renderer_adapter_flush =
    reinterpret_cast<ArkAudioRendererAdapterFlushFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkAudioRendererAdapterCToCpp::Create(
    const ArkWebRefPtr<ArkAudioRendererOptionsAdapter> options,
    ArkWebString& str) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_renderer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_renderer_adapter_create);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "lF8mfy$XPMmhhFWdlDmQzg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_RENDERER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_audio_renderer_adapter_create");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create)) {
        ark_audio_renderer_adapter_create = nullptr;
      } else {
        ark_audio_renderer_adapter_create = _struct->create;
      }
    } else {
      ark_audio_renderer_adapter_create =
          reinterpret_cast<ArkAudioRendererAdapterCreateFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_renderer_adapter_create, 0);

  // Execute
  return ark_audio_renderer_adapter_create(
      _struct, ArkAudioRendererOptionsAdapterCppToC::Invert(options), &str);
}

ARK_WEB_NO_SANITIZE
bool ArkAudioRendererAdapterCToCpp::Start() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_renderer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_renderer_adapter_start);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Z5KBw05Y0pdR3oNx$Ad_eg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_RENDERER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_audio_renderer_adapter_start");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start)) {
        ark_audio_renderer_adapter_start = nullptr;
      } else {
        ark_audio_renderer_adapter_start = _struct->start;
      }
    } else {
      ark_audio_renderer_adapter_start =
          reinterpret_cast<ArkAudioRendererAdapterStartFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_renderer_adapter_start, false);

  // Execute
  return ark_audio_renderer_adapter_start(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkAudioRendererAdapterCToCpp::Pause() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_renderer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_renderer_adapter_pause);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jMWwJoN_PLHYZxEES_ORWw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_RENDERER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_audio_renderer_adapter_pause");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, pause)) {
        ark_audio_renderer_adapter_pause = nullptr;
      } else {
        ark_audio_renderer_adapter_pause = _struct->pause;
      }
    } else {
      ark_audio_renderer_adapter_pause =
          reinterpret_cast<ArkAudioRendererAdapterPauseFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_renderer_adapter_pause, false);

  // Execute
  return ark_audio_renderer_adapter_pause(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkAudioRendererAdapterCToCpp::Stop() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_renderer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(ark_audio_renderer_adapter_stop);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "pA3bIjyv4bxuol3m$$Iv_Q";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_RENDERER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_audio_renderer_adapter_stop");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, stop)) {
        ark_audio_renderer_adapter_stop = nullptr;
      } else {
        ark_audio_renderer_adapter_stop = _struct->stop;
      }
    } else {
      ark_audio_renderer_adapter_stop =
          reinterpret_cast<ArkAudioRendererAdapterStopFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_renderer_adapter_stop, false);

  // Execute
  return ark_audio_renderer_adapter_stop(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkAudioRendererAdapterCToCpp::Release2() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_renderer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_renderer_adapter_release2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "lQUpOd5jqo4RiKjcu2LN6w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_RENDERER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_audio_renderer_adapter_release2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release2)) {
        ark_audio_renderer_adapter_release2 = nullptr;
      } else {
        ark_audio_renderer_adapter_release2 = _struct->release2;
      }
    } else {
      ark_audio_renderer_adapter_release2 =
          reinterpret_cast<ArkAudioRendererAdapterRelease2Func>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_renderer_adapter_release2, false);

  // Execute
  return ark_audio_renderer_adapter_release2(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioRendererAdapterCToCpp::Write(uint8_t* buffer,
                                             size_t bufferSize) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_renderer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_renderer_adapter_write);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "hhX3JFKduXhTp9Jb3vdGbg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_RENDERER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_audio_renderer_adapter_write");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, write)) {
        ark_audio_renderer_adapter_write = nullptr;
      } else {
        ark_audio_renderer_adapter_write = _struct->write;
      }
    } else {
      ark_audio_renderer_adapter_write =
          reinterpret_cast<ArkAudioRendererAdapterWriteFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_renderer_adapter_write, 0);

  // Execute
  return ark_audio_renderer_adapter_write(_struct, buffer, bufferSize);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioRendererAdapterCToCpp::GetLatency(uint64_t& latency) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_renderer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_renderer_adapter_get_latency);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "uMdxyOY38lVjLzce9CPJkw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_RENDERER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_audio_renderer_adapter_get_latency");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_latency)) {
        ark_audio_renderer_adapter_get_latency = nullptr;
      } else {
        ark_audio_renderer_adapter_get_latency = _struct->get_latency;
      }
    } else {
      ark_audio_renderer_adapter_get_latency =
          reinterpret_cast<ArkAudioRendererAdapterGetLatencyFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_renderer_adapter_get_latency, 0);

  // Execute
  return ark_audio_renderer_adapter_get_latency(_struct, &latency);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioRendererAdapterCToCpp::SetVolume(float volume) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_renderer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_renderer_adapter_set_volume);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "vgKvAl1Lq9I9bY972R1BPA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_RENDERER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_audio_renderer_adapter_set_volume");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_volume)) {
        ark_audio_renderer_adapter_set_volume = nullptr;
      } else {
        ark_audio_renderer_adapter_set_volume = _struct->set_volume;
      }
    } else {
      ark_audio_renderer_adapter_set_volume =
          reinterpret_cast<ArkAudioRendererAdapterSetVolumeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_renderer_adapter_set_volume, 0);

  // Execute
  return ark_audio_renderer_adapter_set_volume(_struct, volume);
}

ARK_WEB_NO_SANITIZE
float ArkAudioRendererAdapterCToCpp::GetVolume() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_renderer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_renderer_adapter_get_volume);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "e1iWN_D0gAkNaTCypNC59w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_RENDERER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_audio_renderer_adapter_get_volume");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_volume)) {
        ark_audio_renderer_adapter_get_volume = nullptr;
      } else {
        ark_audio_renderer_adapter_get_volume = _struct->get_volume;
      }
    } else {
      ark_audio_renderer_adapter_get_volume =
          reinterpret_cast<ArkAudioRendererAdapterGetVolumeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_renderer_adapter_get_volume, 0);

  // Execute
  return ark_audio_renderer_adapter_get_volume(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioRendererAdapterCToCpp::SetAudioRendererCallback(
    const ArkWebRefPtr<ArkAudioRendererCallbackAdapter> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_renderer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_renderer_adapter_set_audio_renderer_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "KZLL$6r1WyD_gihE180XSw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_RENDERER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_renderer_adapter_set_audio_renderer_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_audio_renderer_callback)) {
        ark_audio_renderer_adapter_set_audio_renderer_callback = nullptr;
      } else {
        ark_audio_renderer_adapter_set_audio_renderer_callback =
            _struct->set_audio_renderer_callback;
      }
    } else {
      ark_audio_renderer_adapter_set_audio_renderer_callback =
          reinterpret_cast<ArkAudioRendererAdapterSetAudioRendererCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_renderer_adapter_set_audio_renderer_callback, 0);

  // Execute
  return ark_audio_renderer_adapter_set_audio_renderer_callback(
      _struct, ArkAudioRendererCallbackAdapterCppToC::Invert(callback));
}

ARK_WEB_NO_SANITIZE
void ArkAudioRendererAdapterCToCpp::SetInterruptMode(bool audioExclusive) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_renderer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_renderer_adapter_set_interrupt_mode);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "4ocfR7Hhn4JPhJXMDWiAbg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_RENDERER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_renderer_adapter_set_interrupt_mode");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_interrupt_mode)) {
        ark_audio_renderer_adapter_set_interrupt_mode = nullptr;
      } else {
        ark_audio_renderer_adapter_set_interrupt_mode =
            _struct->set_interrupt_mode;
      }
    } else {
      ark_audio_renderer_adapter_set_interrupt_mode =
          reinterpret_cast<ArkAudioRendererAdapterSetInterruptModeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_renderer_adapter_set_interrupt_mode, ARK_WEB_RETURN_VOID);

  // Execute
  ark_audio_renderer_adapter_set_interrupt_mode(_struct, audioExclusive);
}

ARK_WEB_NO_SANITIZE
bool ArkAudioRendererAdapterCToCpp::IsRendererStateRunning() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_renderer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_renderer_adapter_is_renderer_state_running);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "JE2IG0aygPV1uFiY$rL8Mw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_RENDERER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_renderer_adapter_is_renderer_state_running");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_renderer_state_running)) {
        ark_audio_renderer_adapter_is_renderer_state_running = nullptr;
      } else {
        ark_audio_renderer_adapter_is_renderer_state_running =
            _struct->is_renderer_state_running;
      }
    } else {
      ark_audio_renderer_adapter_is_renderer_state_running =
          reinterpret_cast<ArkAudioRendererAdapterIsRendererStateRunningFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_renderer_adapter_is_renderer_state_running, false);

  // Execute
  return ark_audio_renderer_adapter_is_renderer_state_running(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioRendererAdapterCToCpp::SetAudioOutputChangeCallback(
    const ArkWebRefPtr<ArkAudioOutputChangeCallbackAdapter> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_renderer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_renderer_adapter_set_audio_output_change_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "vqRpS2LXGFwy24aVOoWcyw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_RENDERER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_renderer_adapter_set_audio_output_change_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      set_audio_output_change_callback)) {
        ark_audio_renderer_adapter_set_audio_output_change_callback = nullptr;
      } else {
        ark_audio_renderer_adapter_set_audio_output_change_callback =
            _struct->set_audio_output_change_callback;
      }
    } else {
      ark_audio_renderer_adapter_set_audio_output_change_callback =
          reinterpret_cast<
              ArkAudioRendererAdapterSetAudioOutputChangeCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_renderer_adapter_set_audio_output_change_callback, 0);

  // Execute
  return ark_audio_renderer_adapter_set_audio_output_change_callback(
      _struct, ArkAudioOutputChangeCallbackAdapterCppToC::Invert(callback));
}

ARK_WEB_NO_SANITIZE
void ArkAudioRendererAdapterCToCpp::SetAudioSilentMode(bool isSilentMode) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_renderer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_renderer_adapter_set_audio_silent_mode);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jcegY14UAxvjI4zDukgB9Q";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_RENDERER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_renderer_adapter_set_audio_silent_mode");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_audio_silent_mode)) {
        ark_audio_renderer_adapter_set_audio_silent_mode = nullptr;
      } else {
        ark_audio_renderer_adapter_set_audio_silent_mode =
            _struct->set_audio_silent_mode;
      }
    } else {
      ark_audio_renderer_adapter_set_audio_silent_mode =
          reinterpret_cast<ArkAudioRendererAdapterSetAudioSilentModeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_renderer_adapter_set_audio_silent_mode, ARK_WEB_RETURN_VOID);

  // Execute
  ark_audio_renderer_adapter_set_audio_silent_mode(_struct, isSilentMode);
}

ARK_WEB_NO_SANITIZE
bool ArkAudioRendererAdapterCToCpp::Flush() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_renderer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_renderer_adapter_flush);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jkorPrQ_aY8UhFnvm_IP7g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_RENDERER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_audio_renderer_adapter_flush");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, flush)) {
        ark_audio_renderer_adapter_flush = nullptr;
      } else {
        ark_audio_renderer_adapter_flush = _struct->flush;
      }
    } else {
      ark_audio_renderer_adapter_flush =
          reinterpret_cast<ArkAudioRendererAdapterFlushFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_renderer_adapter_flush, false);

  // Execute
  return ark_audio_renderer_adapter_flush(_struct);
}

ArkAudioRendererAdapterCToCpp::ArkAudioRendererAdapterCToCpp() {}

ArkAudioRendererAdapterCToCpp::~ArkAudioRendererAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkAudioRendererAdapterCToCpp,
                           ArkAudioRendererAdapter,
                           ark_audio_renderer_adapter_t>::kBridgeType =
        ARK_AUDIO_RENDERER_ADAPTER;

}  // namespace OHOS::ArkWeb
