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

#include "ohos_nweb/cpptoc/ark_web_native_media_player_handler_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK ark_web_native_media_player_handler_handle_status_changed(
    struct _ark_web_native_media_player_handler_t* self,
    int status) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMediaPlayerHandlerCppToC::Get(self)->HandleStatusChanged(status);
}

void ARK_WEB_CALLBACK ark_web_native_media_player_handler_handle_volume_changed(
    struct _ark_web_native_media_player_handler_t* self,
    double volume) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMediaPlayerHandlerCppToC::Get(self)->HandleVolumeChanged(volume);
}

void ARK_WEB_CALLBACK ark_web_native_media_player_handler_handle_muted_changed(
    struct _ark_web_native_media_player_handler_t* self,
    bool isMuted) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMediaPlayerHandlerCppToC::Get(self)->HandleMutedChanged(isMuted);
}

void ARK_WEB_CALLBACK
ark_web_native_media_player_handler_handle_playback_rate_changed(
    struct _ark_web_native_media_player_handler_t* self,
    double playbackRate) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMediaPlayerHandlerCppToC::Get(self)->HandlePlaybackRateChanged(
      playbackRate);
}

void ARK_WEB_CALLBACK
ark_web_native_media_player_handler_handle_duration_changed(
    struct _ark_web_native_media_player_handler_t* self,
    double duration) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMediaPlayerHandlerCppToC::Get(self)->HandleDurationChanged(
      duration);
}

void ARK_WEB_CALLBACK ark_web_native_media_player_handler_handle_time_update(
    struct _ark_web_native_media_player_handler_t* self,
    double playTime) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMediaPlayerHandlerCppToC::Get(self)->HandleTimeUpdate(playTime);
}

void ARK_WEB_CALLBACK
ark_web_native_media_player_handler_handle_buffered_end_time_changed(
    struct _ark_web_native_media_player_handler_t* self,
    double bufferedEndTime) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMediaPlayerHandlerCppToC::Get(self)->HandleBufferedEndTimeChanged(
      bufferedEndTime);
}

void ARK_WEB_CALLBACK ark_web_native_media_player_handler_handle_ended(
    struct _ark_web_native_media_player_handler_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMediaPlayerHandlerCppToC::Get(self)->HandleEnded();
}

void ARK_WEB_CALLBACK
ark_web_native_media_player_handler_handle_network_state_changed(
    struct _ark_web_native_media_player_handler_t* self,
    int state) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMediaPlayerHandlerCppToC::Get(self)->HandleNetworkStateChanged(
      state);
}

void ARK_WEB_CALLBACK
ark_web_native_media_player_handler_handle_ready_state_changed(
    struct _ark_web_native_media_player_handler_t* self,
    int state) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMediaPlayerHandlerCppToC::Get(self)->HandleReadyStateChanged(
      state);
}

void ARK_WEB_CALLBACK
ark_web_native_media_player_handler_handle_full_screen_changed(
    struct _ark_web_native_media_player_handler_t* self,
    bool isFullScreen) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMediaPlayerHandlerCppToC::Get(self)->HandleFullScreenChanged(
      isFullScreen);
}

void ARK_WEB_CALLBACK ark_web_native_media_player_handler_handle_seeking(
    struct _ark_web_native_media_player_handler_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMediaPlayerHandlerCppToC::Get(self)->HandleSeeking();
}

void ARK_WEB_CALLBACK ark_web_native_media_player_handler_handle_seek_finished(
    struct _ark_web_native_media_player_handler_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMediaPlayerHandlerCppToC::Get(self)->HandleSeekFinished();
}

void ARK_WEB_CALLBACK ark_web_native_media_player_handler_handle_error(
    struct _ark_web_native_media_player_handler_t* self,
    int error,
    const ArkWebString* message) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(message, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMediaPlayerHandlerCppToC::Get(self)->HandleError(error, *message);
}

void ARK_WEB_CALLBACK
ark_web_native_media_player_handler_handle_video_size_changed(
    struct _ark_web_native_media_player_handler_t* self,
    double width,
    double height) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNativeMediaPlayerHandlerCppToC::Get(self)->HandleVideoSizeChanged(
      width, height);
}

}  // namespace

ArkWebNativeMediaPlayerHandlerCppToC::ArkWebNativeMediaPlayerHandlerCppToC() {
  GetStruct()->handle_status_changed =
      ark_web_native_media_player_handler_handle_status_changed;
  GetStruct()->handle_volume_changed =
      ark_web_native_media_player_handler_handle_volume_changed;
  GetStruct()->handle_muted_changed =
      ark_web_native_media_player_handler_handle_muted_changed;
  GetStruct()->handle_playback_rate_changed =
      ark_web_native_media_player_handler_handle_playback_rate_changed;
  GetStruct()->handle_duration_changed =
      ark_web_native_media_player_handler_handle_duration_changed;
  GetStruct()->handle_time_update =
      ark_web_native_media_player_handler_handle_time_update;
  GetStruct()->handle_buffered_end_time_changed =
      ark_web_native_media_player_handler_handle_buffered_end_time_changed;
  GetStruct()->handle_ended = ark_web_native_media_player_handler_handle_ended;
  GetStruct()->handle_network_state_changed =
      ark_web_native_media_player_handler_handle_network_state_changed;
  GetStruct()->handle_ready_state_changed =
      ark_web_native_media_player_handler_handle_ready_state_changed;
  GetStruct()->handle_full_screen_changed =
      ark_web_native_media_player_handler_handle_full_screen_changed;
  GetStruct()->handle_seeking =
      ark_web_native_media_player_handler_handle_seeking;
  GetStruct()->handle_seek_finished =
      ark_web_native_media_player_handler_handle_seek_finished;
  GetStruct()->handle_error = ark_web_native_media_player_handler_handle_error;
  GetStruct()->handle_video_size_changed =
      ark_web_native_media_player_handler_handle_video_size_changed;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["Z58LRC$H7DqvkkKQplPiYw"] = reinterpret_cast<void*>(
        ark_web_native_media_player_handler_handle_status_changed);
    funcMemberMap["TQAzLPPW1voXgLGzC01lHA"] = reinterpret_cast<void*>(
        ark_web_native_media_player_handler_handle_volume_changed);
    funcMemberMap["UtS7G_6FrkJcGwXFbcwHrg"] = reinterpret_cast<void*>(
        ark_web_native_media_player_handler_handle_muted_changed);
    funcMemberMap["gTBm7gEZNLKSFvEIR7NT2A"] = reinterpret_cast<void*>(
        ark_web_native_media_player_handler_handle_playback_rate_changed);
    funcMemberMap["9vqqiLPv3U_b8pHj_pKgaA"] = reinterpret_cast<void*>(
        ark_web_native_media_player_handler_handle_duration_changed);
    funcMemberMap["_UQWrnA$sMrIkkz5lq6CgA"] = reinterpret_cast<void*>(
        ark_web_native_media_player_handler_handle_time_update);
    funcMemberMap["dcR23ix28VXkEo7wopyLcw"] = reinterpret_cast<void*>(
        ark_web_native_media_player_handler_handle_buffered_end_time_changed);
    funcMemberMap["F9dhWDxQttv4_varEv585Q"] = reinterpret_cast<void*>(
        ark_web_native_media_player_handler_handle_ended);
    funcMemberMap["TV9IzpU8TDH3ynHg6_HTpA"] = reinterpret_cast<void*>(
        ark_web_native_media_player_handler_handle_network_state_changed);
    funcMemberMap["J_mkg7IrLlMF3aT6_8d2FQ"] = reinterpret_cast<void*>(
        ark_web_native_media_player_handler_handle_ready_state_changed);
    funcMemberMap["J9Diovh$KxGno5bCW3rNtA"] = reinterpret_cast<void*>(
        ark_web_native_media_player_handler_handle_full_screen_changed);
    funcMemberMap["Y9q$z7S4xEkAdnfCRqO__A"] = reinterpret_cast<void*>(
        ark_web_native_media_player_handler_handle_seeking);
    funcMemberMap["aaclVc541tRKok69hAw87A"] = reinterpret_cast<void*>(
        ark_web_native_media_player_handler_handle_seek_finished);
    funcMemberMap["qh7jNTjvJWHNHmECFrWgmQ"] = reinterpret_cast<void*>(
        ark_web_native_media_player_handler_handle_error);
    funcMemberMap["H9skH81MGREnbjJcDBO0nA"] = reinterpret_cast<void*>(
        ark_web_native_media_player_handler_handle_video_size_changed);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_NATIVE_MEDIA_PLAYER_HANDLER, funcMemberMap);
  });
}

ArkWebNativeMediaPlayerHandlerCppToC::~ArkWebNativeMediaPlayerHandlerCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebNativeMediaPlayerHandlerCppToC,
                           ArkWebNativeMediaPlayerHandler,
                           ark_web_native_media_player_handler_t>::kBridgeType =
        ARK_WEB_NATIVE_MEDIA_PLAYER_HANDLER;

}  // namespace OHOS::ArkWeb
