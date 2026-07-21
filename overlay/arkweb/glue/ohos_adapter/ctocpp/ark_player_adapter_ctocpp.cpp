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

#include "ohos_adapter/ctocpp/ark_player_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_player_callback_adapter_cpptoc.h"
#include "ohos_adapter/ctocpp/ark_iconsumer_surface_adapter_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkPlayerAdapterSetPlayerCallbackFunc =
    int32_t (*)(struct _ark_player_adapter_t* self,
                ark_player_callback_adapter_t* callbackAdapter);
static ArkPlayerAdapterSetPlayerCallbackFunc
    ark_player_adapter_set_player_callback =
        reinterpret_cast<ArkPlayerAdapterSetPlayerCallbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPlayerAdapterSetSourceFunc1 =
    int32_t (*)(struct _ark_player_adapter_t* self, const ArkWebString* url);
static ArkPlayerAdapterSetSourceFunc1 ark_player_adapter_set_source1 =
    reinterpret_cast<ArkPlayerAdapterSetSourceFunc1>(ARK_WEB_INIT_ADDR);

using ArkPlayerAdapterSetSourceFunc2 =
    int32_t (*)(struct _ark_player_adapter_t* self,
                int32_t fd,
                int64_t offset,
                int64_t size);
static ArkPlayerAdapterSetSourceFunc2 ark_player_adapter_set_source2 =
    reinterpret_cast<ArkPlayerAdapterSetSourceFunc2>(ARK_WEB_INIT_ADDR);

using ArkPlayerAdapterSetVideoSurfaceFunc =
    int32_t (*)(struct _ark_player_adapter_t* self,
                ark_iconsumer_surface_adapter_t* cSurfaceAdapter);
static ArkPlayerAdapterSetVideoSurfaceFunc
    ark_player_adapter_set_video_surface =
        reinterpret_cast<ArkPlayerAdapterSetVideoSurfaceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPlayerAdapterSetVolumeFunc =
    int32_t (*)(struct _ark_player_adapter_t* self,
                float leftVolume,
                float rightVolume);
static ArkPlayerAdapterSetVolumeFunc ark_player_adapter_set_volume =
    reinterpret_cast<ArkPlayerAdapterSetVolumeFunc>(ARK_WEB_INIT_ADDR);

using ArkPlayerAdapterSeekFunc = int32_t (*)(struct _ark_player_adapter_t* self,
                                             int32_t mSeconds,
                                             int32_t mode);
static ArkPlayerAdapterSeekFunc ark_player_adapter_seek =
    reinterpret_cast<ArkPlayerAdapterSeekFunc>(ARK_WEB_INIT_ADDR);

using ArkPlayerAdapterPlayFunc =
    int32_t (*)(struct _ark_player_adapter_t* self);
static ArkPlayerAdapterPlayFunc ark_player_adapter_play =
    reinterpret_cast<ArkPlayerAdapterPlayFunc>(ARK_WEB_INIT_ADDR);

using ArkPlayerAdapterPauseFunc =
    int32_t (*)(struct _ark_player_adapter_t* self);
static ArkPlayerAdapterPauseFunc ark_player_adapter_pause =
    reinterpret_cast<ArkPlayerAdapterPauseFunc>(ARK_WEB_INIT_ADDR);

using ArkPlayerAdapterPrepareAsyncFunc =
    int32_t (*)(struct _ark_player_adapter_t* self);
static ArkPlayerAdapterPrepareAsyncFunc ark_player_adapter_prepare_async =
    reinterpret_cast<ArkPlayerAdapterPrepareAsyncFunc>(ARK_WEB_INIT_ADDR);

using ArkPlayerAdapterGetCurrentTimeFunc =
    int32_t (*)(struct _ark_player_adapter_t* self, int32_t* currentTime);
static ArkPlayerAdapterGetCurrentTimeFunc ark_player_adapter_get_current_time =
    reinterpret_cast<ArkPlayerAdapterGetCurrentTimeFunc>(ARK_WEB_INIT_ADDR);

using ArkPlayerAdapterGetDurationFunc =
    int32_t (*)(struct _ark_player_adapter_t* self, int32_t* duration);
static ArkPlayerAdapterGetDurationFunc ark_player_adapter_get_duration =
    reinterpret_cast<ArkPlayerAdapterGetDurationFunc>(ARK_WEB_INIT_ADDR);

using ArkPlayerAdapterSetPlaybackSpeedFunc =
    int32_t (*)(struct _ark_player_adapter_t* self, int32_t mode);
static ArkPlayerAdapterSetPlaybackSpeedFunc
    ark_player_adapter_set_playback_speed =
        reinterpret_cast<ArkPlayerAdapterSetPlaybackSpeedFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPlayerAdapterSetVideoSurfaceNewFunc =
    int32_t (*)(struct _ark_player_adapter_t* self, void* native_window);
static ArkPlayerAdapterSetVideoSurfaceNewFunc
    ark_player_adapter_set_video_surface_new =
        reinterpret_cast<ArkPlayerAdapterSetVideoSurfaceNewFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPlayerAdapterSetMediaSourceHeaderFunc =
    int32_t (*)(struct _ark_player_adapter_t* self,
                const ArkWebString* url,
                const ArkWebStringMap* header);
static ArkPlayerAdapterSetMediaSourceHeaderFunc
    ark_player_adapter_set_media_source_header =
        reinterpret_cast<ArkPlayerAdapterSetMediaSourceHeaderFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkPlayerAdapterCToCpp::SetPlayerCallback(
    ArkWebRefPtr<ArkPlayerCallbackAdapter> callbackAdapter) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_player_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_player_adapter_set_player_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "RDiB7srGS5HP7vR2LgMiCQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_PLAYER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_player_adapter_set_player_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_player_callback)) {
        ark_player_adapter_set_player_callback = nullptr;
      } else {
        ark_player_adapter_set_player_callback = _struct->set_player_callback;
      }
    } else {
      ark_player_adapter_set_player_callback =
          reinterpret_cast<ArkPlayerAdapterSetPlayerCallbackFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_player_adapter_set_player_callback, 0);

  // Execute
  return ark_player_adapter_set_player_callback(
      _struct, ArkPlayerCallbackAdapterCppToC::Invert(callbackAdapter));
}

ARK_WEB_NO_SANITIZE
int32_t ArkPlayerAdapterCToCpp::SetSource(const ArkWebString& url) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_player_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_player_adapter_set_source1);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "7svRKOekw29NFiqCTaQxhQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_PLAYER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_player_adapter_set_source1");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_source1)) {
        ark_player_adapter_set_source1 = nullptr;
      } else {
        ark_player_adapter_set_source1 = _struct->set_source1;
      }
    } else {
      ark_player_adapter_set_source1 =
          reinterpret_cast<ArkPlayerAdapterSetSourceFunc1>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_player_adapter_set_source1, 0);

  // Execute
  return ark_player_adapter_set_source1(_struct, &url);
}

ARK_WEB_NO_SANITIZE
int32_t ArkPlayerAdapterCToCpp::SetSource(int32_t fd,
                                          int64_t offset,
                                          int64_t size) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_player_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_player_adapter_set_source2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "kNtAgsq3yyursqZ8CZTioA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_PLAYER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_player_adapter_set_source2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_source2)) {
        ark_player_adapter_set_source2 = nullptr;
      } else {
        ark_player_adapter_set_source2 = _struct->set_source2;
      }
    } else {
      ark_player_adapter_set_source2 =
          reinterpret_cast<ArkPlayerAdapterSetSourceFunc2>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_player_adapter_set_source2, 0);

  // Execute
  return ark_player_adapter_set_source2(_struct, fd, offset, size);
}

ARK_WEB_NO_SANITIZE
int32_t ArkPlayerAdapterCToCpp::SetVideoSurface(
    ArkWebRefPtr<ArkIConsumerSurfaceAdapter> cSurfaceAdapter) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_player_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_player_adapter_set_video_surface);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "iu9$YoapOLaSMnliyQGQyg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_PLAYER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_player_adapter_set_video_surface");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_video_surface)) {
        ark_player_adapter_set_video_surface = nullptr;
      } else {
        ark_player_adapter_set_video_surface = _struct->set_video_surface;
      }
    } else {
      ark_player_adapter_set_video_surface =
          reinterpret_cast<ArkPlayerAdapterSetVideoSurfaceFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_player_adapter_set_video_surface, 0);

  // Execute
  return ark_player_adapter_set_video_surface(
      _struct, ArkIConsumerSurfaceAdapterCToCpp::Revert(cSurfaceAdapter));
}

ARK_WEB_NO_SANITIZE
int32_t ArkPlayerAdapterCToCpp::SetVolume(float leftVolume, float rightVolume) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_player_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_player_adapter_set_volume);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "dvMYwU06MIh9dIpTZt9L3Q";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_PLAYER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_player_adapter_set_volume");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_volume)) {
        ark_player_adapter_set_volume = nullptr;
      } else {
        ark_player_adapter_set_volume = _struct->set_volume;
      }
    } else {
      ark_player_adapter_set_volume =
          reinterpret_cast<ArkPlayerAdapterSetVolumeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_player_adapter_set_volume, 0);

  // Execute
  return ark_player_adapter_set_volume(_struct, leftVolume, rightVolume);
}

ARK_WEB_NO_SANITIZE
int32_t ArkPlayerAdapterCToCpp::Seek(int32_t mSeconds, int32_t mode) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_player_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_player_adapter_seek);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "pvb0I$tyH$EPow4u2Kk2bA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_PLAYER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_player_adapter_seek");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, seek)) {
        ark_player_adapter_seek = nullptr;
      } else {
        ark_player_adapter_seek = _struct->seek;
      }
    } else {
      ark_player_adapter_seek =
          reinterpret_cast<ArkPlayerAdapterSeekFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_player_adapter_seek, 0);

  // Execute
  return ark_player_adapter_seek(_struct, mSeconds, mode);
}

ARK_WEB_NO_SANITIZE
int32_t ArkPlayerAdapterCToCpp::Play() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_player_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_player_adapter_play);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "d89NnCTYsrjyj72PRdpJ1g";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_PLAYER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_player_adapter_play");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, play)) {
        ark_player_adapter_play = nullptr;
      } else {
        ark_player_adapter_play = _struct->play;
      }
    } else {
      ark_player_adapter_play =
          reinterpret_cast<ArkPlayerAdapterPlayFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_player_adapter_play, 0);

  // Execute
  return ark_player_adapter_play(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkPlayerAdapterCToCpp::Pause() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_player_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_player_adapter_pause);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "9ufWU6e34mMYlDJ6I9QPHw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_PLAYER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_player_adapter_pause");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, pause)) {
        ark_player_adapter_pause = nullptr;
      } else {
        ark_player_adapter_pause = _struct->pause;
      }
    } else {
      ark_player_adapter_pause =
          reinterpret_cast<ArkPlayerAdapterPauseFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_player_adapter_pause, 0);

  // Execute
  return ark_player_adapter_pause(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkPlayerAdapterCToCpp::PrepareAsync() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_player_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_player_adapter_prepare_async);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "d$WlPCQFimJ0cqYjsB35Aw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_PLAYER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_player_adapter_prepare_async");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, prepare_async)) {
        ark_player_adapter_prepare_async = nullptr;
      } else {
        ark_player_adapter_prepare_async = _struct->prepare_async;
      }
    } else {
      ark_player_adapter_prepare_async =
          reinterpret_cast<ArkPlayerAdapterPrepareAsyncFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_player_adapter_prepare_async, 0);

  // Execute
  return ark_player_adapter_prepare_async(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkPlayerAdapterCToCpp::GetCurrentTime(int32_t& currentTime) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_player_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_player_adapter_get_current_time);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "TD7K3bASh0O4he7c3seLMA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_PLAYER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_player_adapter_get_current_time");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_current_time)) {
        ark_player_adapter_get_current_time = nullptr;
      } else {
        ark_player_adapter_get_current_time = _struct->get_current_time;
      }
    } else {
      ark_player_adapter_get_current_time =
          reinterpret_cast<ArkPlayerAdapterGetCurrentTimeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_player_adapter_get_current_time, 0);

  // Execute
  return ark_player_adapter_get_current_time(_struct, &currentTime);
}

ARK_WEB_NO_SANITIZE
int32_t ArkPlayerAdapterCToCpp::GetDuration(int32_t& duration) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_player_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_player_adapter_get_duration);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "K1gPWaILdGK0nfi0xJBbew";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_PLAYER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_player_adapter_get_duration");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_duration)) {
        ark_player_adapter_get_duration = nullptr;
      } else {
        ark_player_adapter_get_duration = _struct->get_duration;
      }
    } else {
      ark_player_adapter_get_duration =
          reinterpret_cast<ArkPlayerAdapterGetDurationFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_player_adapter_get_duration, 0);

  // Execute
  return ark_player_adapter_get_duration(_struct, &duration);
}

ARK_WEB_NO_SANITIZE
int32_t ArkPlayerAdapterCToCpp::SetPlaybackSpeed(int32_t mode) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_player_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_player_adapter_set_playback_speed);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "uOKY0mKhmYvHkf6ihscIaA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_PLAYER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_player_adapter_set_playback_speed");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_playback_speed)) {
        ark_player_adapter_set_playback_speed = nullptr;
      } else {
        ark_player_adapter_set_playback_speed = _struct->set_playback_speed;
      }
    } else {
      ark_player_adapter_set_playback_speed =
          reinterpret_cast<ArkPlayerAdapterSetPlaybackSpeedFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_player_adapter_set_playback_speed, 0);

  // Execute
  return ark_player_adapter_set_playback_speed(_struct, mode);
}

ARK_WEB_NO_SANITIZE
int32_t ArkPlayerAdapterCToCpp::SetVideoSurfaceNew(void* native_window) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_player_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_player_adapter_set_video_surface_new);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "C4bMunV_h2gWV2KDV7cdag";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_PLAYER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_player_adapter_set_video_surface_new");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_video_surface_new)) {
        ark_player_adapter_set_video_surface_new = nullptr;
      } else {
        ark_player_adapter_set_video_surface_new =
            _struct->set_video_surface_new;
      }
    } else {
      ark_player_adapter_set_video_surface_new =
          reinterpret_cast<ArkPlayerAdapterSetVideoSurfaceNewFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_player_adapter_set_video_surface_new,
                                    0);

  // Execute
  return ark_player_adapter_set_video_surface_new(_struct, native_window);
}

ARK_WEB_NO_SANITIZE
int32_t ArkPlayerAdapterCToCpp::SetMediaSourceHeader(
    const ArkWebString& url,
    const ArkWebStringMap& header) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_player_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_player_adapter_set_media_source_header);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "xbE_4M_dZB4mKKruDnXQoQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_PLAYER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_player_adapter_set_media_source_header");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_media_source_header)) {
        ark_player_adapter_set_media_source_header = nullptr;
      } else {
        ark_player_adapter_set_media_source_header =
            _struct->set_media_source_header;
      }
    } else {
      ark_player_adapter_set_media_source_header =
          reinterpret_cast<ArkPlayerAdapterSetMediaSourceHeaderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_player_adapter_set_media_source_header,
                                    0);

  // Execute
  return ark_player_adapter_set_media_source_header(_struct, &url, &header);
}

ArkPlayerAdapterCToCpp::ArkPlayerAdapterCToCpp() {}

ArkPlayerAdapterCToCpp::~ArkPlayerAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkPlayerAdapterCToCpp,
                                        ArkPlayerAdapter,
                                        ark_player_adapter_t>::kBridgeType =
    ARK_PLAYER_ADAPTER;

}  // namespace OHOS::ArkWeb
