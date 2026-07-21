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

#include "ohos_nweb/ctocpp/ark_web_native_media_player_bridge_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebNativeMediaPlayerBridgeUpdateRectFunc =
    void (*)(struct _ark_web_native_media_player_bridge_t* self,
             double x,
             double y,
             double width,
             double height);
static ArkWebNativeMediaPlayerBridgeUpdateRectFunc
    ark_web_native_media_player_bridge_update_rect =
        reinterpret_cast<ArkWebNativeMediaPlayerBridgeUpdateRectFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebNativeMediaPlayerBridgePlayFunc =
    void (*)(struct _ark_web_native_media_player_bridge_t* self);
static ArkWebNativeMediaPlayerBridgePlayFunc
    ark_web_native_media_player_bridge_play =
        reinterpret_cast<ArkWebNativeMediaPlayerBridgePlayFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebNativeMediaPlayerBridgePauseFunc =
    void (*)(struct _ark_web_native_media_player_bridge_t* self);
static ArkWebNativeMediaPlayerBridgePauseFunc
    ark_web_native_media_player_bridge_pause =
        reinterpret_cast<ArkWebNativeMediaPlayerBridgePauseFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebNativeMediaPlayerBridgeSeekFunc =
    void (*)(struct _ark_web_native_media_player_bridge_t* self, double time);
static ArkWebNativeMediaPlayerBridgeSeekFunc
    ark_web_native_media_player_bridge_seek =
        reinterpret_cast<ArkWebNativeMediaPlayerBridgeSeekFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebNativeMediaPlayerBridgeSetVolumeFunc =
    void (*)(struct _ark_web_native_media_player_bridge_t* self, double volume);
static ArkWebNativeMediaPlayerBridgeSetVolumeFunc
    ark_web_native_media_player_bridge_set_volume =
        reinterpret_cast<ArkWebNativeMediaPlayerBridgeSetVolumeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebNativeMediaPlayerBridgeSetMutedFunc =
    void (*)(struct _ark_web_native_media_player_bridge_t* self, bool isMuted);
static ArkWebNativeMediaPlayerBridgeSetMutedFunc
    ark_web_native_media_player_bridge_set_muted =
        reinterpret_cast<ArkWebNativeMediaPlayerBridgeSetMutedFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebNativeMediaPlayerBridgeSetPlaybackRateFunc =
    void (*)(struct _ark_web_native_media_player_bridge_t* self,
             double playbackRate);
static ArkWebNativeMediaPlayerBridgeSetPlaybackRateFunc
    ark_web_native_media_player_bridge_set_playback_rate =
        reinterpret_cast<ArkWebNativeMediaPlayerBridgeSetPlaybackRateFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebNativeMediaPlayerBridgeReleaseFunc =
    void (*)(struct _ark_web_native_media_player_bridge_t* self);
static ArkWebNativeMediaPlayerBridgeReleaseFunc
    ark_web_native_media_player_bridge_release =
        reinterpret_cast<ArkWebNativeMediaPlayerBridgeReleaseFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebNativeMediaPlayerBridgeEnterFullScreenFunc =
    void (*)(struct _ark_web_native_media_player_bridge_t* self);
static ArkWebNativeMediaPlayerBridgeEnterFullScreenFunc
    ark_web_native_media_player_bridge_enter_full_screen =
        reinterpret_cast<ArkWebNativeMediaPlayerBridgeEnterFullScreenFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebNativeMediaPlayerBridgeExitFullScreenFunc =
    void (*)(struct _ark_web_native_media_player_bridge_t* self);
static ArkWebNativeMediaPlayerBridgeExitFullScreenFunc
    ark_web_native_media_player_bridge_exit_full_screen =
        reinterpret_cast<ArkWebNativeMediaPlayerBridgeExitFullScreenFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebNativeMediaPlayerBridgeResumeMediaPlayerFunc =
    void (*)(struct _ark_web_native_media_player_bridge_t* self);
static ArkWebNativeMediaPlayerBridgeResumeMediaPlayerFunc
    ark_web_native_media_player_bridge_resume_media_player =
        reinterpret_cast<ArkWebNativeMediaPlayerBridgeResumeMediaPlayerFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebNativeMediaPlayerBridgeSuspendMediaPlayerFunc =
    void (*)(struct _ark_web_native_media_player_bridge_t* self, int type);
static ArkWebNativeMediaPlayerBridgeSuspendMediaPlayerFunc
    ark_web_native_media_player_bridge_suspend_media_player =
        reinterpret_cast<ArkWebNativeMediaPlayerBridgeSuspendMediaPlayerFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkWebNativeMediaPlayerBridgeCToCpp::UpdateRect(double x,
                                                     double y,
                                                     double width,
                                                     double height) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_native_media_player_bridge_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_native_media_player_bridge_update_rect);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "REQkwkjG8FF4GBLjgAUUOA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NATIVE_MEDIA_PLAYER_BRIDGE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_native_media_player_bridge_update_rect");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, update_rect)) {
        ark_web_native_media_player_bridge_update_rect = nullptr;
      } else {
        ark_web_native_media_player_bridge_update_rect = _struct->update_rect;
      }
    } else {
      ark_web_native_media_player_bridge_update_rect =
          reinterpret_cast<ArkWebNativeMediaPlayerBridgeUpdateRectFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_native_media_player_bridge_update_rect, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_native_media_player_bridge_update_rect(_struct, x, y, width, height);
}

ARK_WEB_NO_SANITIZE
void ArkWebNativeMediaPlayerBridgeCToCpp::Play() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_native_media_player_bridge_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_native_media_player_bridge_play);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "DABtQKwSCrODNwjCBbt7Ig";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NATIVE_MEDIA_PLAYER_BRIDGE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_native_media_player_bridge_play");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, play)) {
        ark_web_native_media_player_bridge_play = nullptr;
      } else {
        ark_web_native_media_player_bridge_play = _struct->play;
      }
    } else {
      ark_web_native_media_player_bridge_play =
          reinterpret_cast<ArkWebNativeMediaPlayerBridgePlayFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_native_media_player_bridge_play,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_native_media_player_bridge_play(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebNativeMediaPlayerBridgeCToCpp::Pause() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_native_media_player_bridge_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_native_media_player_bridge_pause);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "eB1qY9_3$yzoCQwaxi7OFg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NATIVE_MEDIA_PLAYER_BRIDGE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_native_media_player_bridge_pause");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, pause)) {
        ark_web_native_media_player_bridge_pause = nullptr;
      } else {
        ark_web_native_media_player_bridge_pause = _struct->pause;
      }
    } else {
      ark_web_native_media_player_bridge_pause =
          reinterpret_cast<ArkWebNativeMediaPlayerBridgePauseFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_native_media_player_bridge_pause,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_native_media_player_bridge_pause(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebNativeMediaPlayerBridgeCToCpp::Seek(double time) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_native_media_player_bridge_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_native_media_player_bridge_seek);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "oOKrZZ5UQlMdHefICF0wyQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NATIVE_MEDIA_PLAYER_BRIDGE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_native_media_player_bridge_seek");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, seek)) {
        ark_web_native_media_player_bridge_seek = nullptr;
      } else {
        ark_web_native_media_player_bridge_seek = _struct->seek;
      }
    } else {
      ark_web_native_media_player_bridge_seek =
          reinterpret_cast<ArkWebNativeMediaPlayerBridgeSeekFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_native_media_player_bridge_seek,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_native_media_player_bridge_seek(_struct, time);
}

ARK_WEB_NO_SANITIZE
void ArkWebNativeMediaPlayerBridgeCToCpp::SetVolume(double volume) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_native_media_player_bridge_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_native_media_player_bridge_set_volume);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "uRBUbJ_xfEuSkqYvTvhE5w";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NATIVE_MEDIA_PLAYER_BRIDGE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_native_media_player_bridge_set_volume");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_volume)) {
        ark_web_native_media_player_bridge_set_volume = nullptr;
      } else {
        ark_web_native_media_player_bridge_set_volume = _struct->set_volume;
      }
    } else {
      ark_web_native_media_player_bridge_set_volume =
          reinterpret_cast<ArkWebNativeMediaPlayerBridgeSetVolumeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_native_media_player_bridge_set_volume, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_native_media_player_bridge_set_volume(_struct, volume);
}

ARK_WEB_NO_SANITIZE
void ArkWebNativeMediaPlayerBridgeCToCpp::SetMuted(bool isMuted) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_native_media_player_bridge_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_native_media_player_bridge_set_muted);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "PHezBPyTTIN4eRt3AtmWJg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NATIVE_MEDIA_PLAYER_BRIDGE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_native_media_player_bridge_set_muted");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_muted)) {
        ark_web_native_media_player_bridge_set_muted = nullptr;
      } else {
        ark_web_native_media_player_bridge_set_muted = _struct->set_muted;
      }
    } else {
      ark_web_native_media_player_bridge_set_muted =
          reinterpret_cast<ArkWebNativeMediaPlayerBridgeSetMutedFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_native_media_player_bridge_set_muted, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_native_media_player_bridge_set_muted(_struct, isMuted);
}

ARK_WEB_NO_SANITIZE
void ArkWebNativeMediaPlayerBridgeCToCpp::SetPlaybackRate(double playbackRate) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_native_media_player_bridge_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_native_media_player_bridge_set_playback_rate);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "hQwiOnZz4ETB6io$jv5QYw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NATIVE_MEDIA_PLAYER_BRIDGE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_native_media_player_bridge_set_playback_rate");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_playback_rate)) {
        ark_web_native_media_player_bridge_set_playback_rate = nullptr;
      } else {
        ark_web_native_media_player_bridge_set_playback_rate =
            _struct->set_playback_rate;
      }
    } else {
      ark_web_native_media_player_bridge_set_playback_rate =
          reinterpret_cast<ArkWebNativeMediaPlayerBridgeSetPlaybackRateFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_native_media_player_bridge_set_playback_rate,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_native_media_player_bridge_set_playback_rate(_struct, playbackRate);
}

ARK_WEB_NO_SANITIZE
void ArkWebNativeMediaPlayerBridgeCToCpp::Release() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_native_media_player_bridge_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_native_media_player_bridge_release);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "kC2TI04QNJOWAMzGm0I25g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NATIVE_MEDIA_PLAYER_BRIDGE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_native_media_player_bridge_release");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release)) {
        ark_web_native_media_player_bridge_release = nullptr;
      } else {
        ark_web_native_media_player_bridge_release = _struct->release;
      }
    } else {
      ark_web_native_media_player_bridge_release =
          reinterpret_cast<ArkWebNativeMediaPlayerBridgeReleaseFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_native_media_player_bridge_release,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_native_media_player_bridge_release(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebNativeMediaPlayerBridgeCToCpp::EnterFullScreen() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_native_media_player_bridge_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_native_media_player_bridge_enter_full_screen);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "0ZCsRgTANeIw2zun6UgYMQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NATIVE_MEDIA_PLAYER_BRIDGE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_native_media_player_bridge_enter_full_screen");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, enter_full_screen)) {
        ark_web_native_media_player_bridge_enter_full_screen = nullptr;
      } else {
        ark_web_native_media_player_bridge_enter_full_screen =
            _struct->enter_full_screen;
      }
    } else {
      ark_web_native_media_player_bridge_enter_full_screen =
          reinterpret_cast<ArkWebNativeMediaPlayerBridgeEnterFullScreenFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_native_media_player_bridge_enter_full_screen,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_native_media_player_bridge_enter_full_screen(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebNativeMediaPlayerBridgeCToCpp::ExitFullScreen() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_native_media_player_bridge_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_native_media_player_bridge_exit_full_screen);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "XQErAM6J2sOh1qP2UeziKg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NATIVE_MEDIA_PLAYER_BRIDGE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_native_media_player_bridge_exit_full_screen");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, exit_full_screen)) {
        ark_web_native_media_player_bridge_exit_full_screen = nullptr;
      } else {
        ark_web_native_media_player_bridge_exit_full_screen =
            _struct->exit_full_screen;
      }
    } else {
      ark_web_native_media_player_bridge_exit_full_screen =
          reinterpret_cast<ArkWebNativeMediaPlayerBridgeExitFullScreenFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_native_media_player_bridge_exit_full_screen, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_native_media_player_bridge_exit_full_screen(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebNativeMediaPlayerBridgeCToCpp::ResumeMediaPlayer() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_native_media_player_bridge_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_native_media_player_bridge_resume_media_player);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "8mINch2rVHhzXfZqMiQhpg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NATIVE_MEDIA_PLAYER_BRIDGE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_native_media_player_bridge_resume_media_player");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, resume_media_player)) {
        ark_web_native_media_player_bridge_resume_media_player = nullptr;
      } else {
        ark_web_native_media_player_bridge_resume_media_player =
            _struct->resume_media_player;
      }
    } else {
      ark_web_native_media_player_bridge_resume_media_player =
          reinterpret_cast<ArkWebNativeMediaPlayerBridgeResumeMediaPlayerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_native_media_player_bridge_resume_media_player,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_native_media_player_bridge_resume_media_player(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebNativeMediaPlayerBridgeCToCpp::SuspendMediaPlayer(int type) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_native_media_player_bridge_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_native_media_player_bridge_suspend_media_player);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "uOlobuH3W$pnx_4DfE3Png";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NATIVE_MEDIA_PLAYER_BRIDGE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_native_media_player_bridge_suspend_media_player");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, suspend_media_player)) {
        ark_web_native_media_player_bridge_suspend_media_player = nullptr;
      } else {
        ark_web_native_media_player_bridge_suspend_media_player =
            _struct->suspend_media_player;
      }
    } else {
      ark_web_native_media_player_bridge_suspend_media_player =
          reinterpret_cast<ArkWebNativeMediaPlayerBridgeSuspendMediaPlayerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_native_media_player_bridge_suspend_media_player,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_native_media_player_bridge_suspend_media_player(_struct, type);
}

ArkWebNativeMediaPlayerBridgeCToCpp::ArkWebNativeMediaPlayerBridgeCToCpp() {}

ArkWebNativeMediaPlayerBridgeCToCpp::~ArkWebNativeMediaPlayerBridgeCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkWebNativeMediaPlayerBridgeCToCpp,
                           ArkWebNativeMediaPlayerBridge,
                           ark_web_native_media_player_bridge_t>::kBridgeType =
        ARK_WEB_NATIVE_MEDIA_PLAYER_BRIDGE;

}  // namespace OHOS::ArkWeb
