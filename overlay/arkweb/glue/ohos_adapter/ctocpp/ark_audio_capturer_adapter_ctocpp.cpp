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

#include "ohos_adapter/ctocpp/ark_audio_capturer_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_audio_capturer_options_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_audio_capturer_read_callback_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_buffer_desc_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkAudioCapturerAdapterCreateFunc =
    int32_t (*)(struct _ark_audio_capturer_adapter_t* self,
                ark_audio_capturer_options_adapter_t* capturerOptions,
                ArkWebString* cachePath);
static ArkAudioCapturerAdapterCreateFunc ark_audio_capturer_adapter_create =
    reinterpret_cast<ArkAudioCapturerAdapterCreateFunc>(ARK_WEB_INIT_ADDR);

using ArkAudioCapturerAdapterStartFunc =
    bool (*)(struct _ark_audio_capturer_adapter_t* self);
static ArkAudioCapturerAdapterStartFunc ark_audio_capturer_adapter_start =
    reinterpret_cast<ArkAudioCapturerAdapterStartFunc>(ARK_WEB_INIT_ADDR);

using ArkAudioCapturerAdapterStopFunc =
    bool (*)(struct _ark_audio_capturer_adapter_t* self);
static ArkAudioCapturerAdapterStopFunc ark_audio_capturer_adapter_stop =
    reinterpret_cast<ArkAudioCapturerAdapterStopFunc>(ARK_WEB_INIT_ADDR);

using ArkAudioCapturerAdapterRelease2Func =
    bool (*)(struct _ark_audio_capturer_adapter_t* self);
static ArkAudioCapturerAdapterRelease2Func ark_audio_capturer_adapter_release2 =
    reinterpret_cast<ArkAudioCapturerAdapterRelease2Func>(ARK_WEB_INIT_ADDR);

using ArkAudioCapturerAdapterSetCapturerReadCallbackFunc =
    int32_t (*)(struct _ark_audio_capturer_adapter_t* self,
                ark_audio_capturer_read_callback_adapter_t* callbck);
static ArkAudioCapturerAdapterSetCapturerReadCallbackFunc
    ark_audio_capturer_adapter_set_capturer_read_callback =
        reinterpret_cast<ArkAudioCapturerAdapterSetCapturerReadCallbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioCapturerAdapterGetBufferDescFunc =
    int32_t (*)(struct _ark_audio_capturer_adapter_t* self,
                ark_buffer_desc_adapter_t* buffferDesc);
static ArkAudioCapturerAdapterGetBufferDescFunc
    ark_audio_capturer_adapter_get_buffer_desc =
        reinterpret_cast<ArkAudioCapturerAdapterGetBufferDescFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioCapturerAdapterEnqueueFunc =
    int32_t (*)(struct _ark_audio_capturer_adapter_t* self,
                ark_buffer_desc_adapter_t* bufferDesc);
static ArkAudioCapturerAdapterEnqueueFunc ark_audio_capturer_adapter_enqueue =
    reinterpret_cast<ArkAudioCapturerAdapterEnqueueFunc>(ARK_WEB_INIT_ADDR);

using ArkAudioCapturerAdapterGetFrameCountFunc =
    int32_t (*)(struct _ark_audio_capturer_adapter_t* self,
                uint32_t* frameCount);
static ArkAudioCapturerAdapterGetFrameCountFunc
    ark_audio_capturer_adapter_get_frame_count =
        reinterpret_cast<ArkAudioCapturerAdapterGetFrameCountFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioCapturerAdapterGetAudioTimeFunc =
    int64_t (*)(struct _ark_audio_capturer_adapter_t* self);
static ArkAudioCapturerAdapterGetAudioTimeFunc
    ark_audio_capturer_adapter_get_audio_time =
        reinterpret_cast<ArkAudioCapturerAdapterGetAudioTimeFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCapturerAdapterCToCpp::Create(
    const ArkWebRefPtr<ArkAudioCapturerOptionsAdapter> capturerOptions,
    ArkWebString& cachePath) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_capturer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_capturer_adapter_create);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "$dHRnhwjO_sq90BPbq1MQA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_CAPTURER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_audio_capturer_adapter_create");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create)) {
        ark_audio_capturer_adapter_create = nullptr;
      } else {
        ark_audio_capturer_adapter_create = _struct->create;
      }
    } else {
      ark_audio_capturer_adapter_create =
          reinterpret_cast<ArkAudioCapturerAdapterCreateFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_capturer_adapter_create, 0);

  // Execute
  return ark_audio_capturer_adapter_create(
      _struct, ArkAudioCapturerOptionsAdapterCppToC::Invert(capturerOptions),
      &cachePath);
}

ARK_WEB_NO_SANITIZE
bool ArkAudioCapturerAdapterCToCpp::Start() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_capturer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_capturer_adapter_start);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "vEeAgdol4qV7t8GsaGKMHw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_CAPTURER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_audio_capturer_adapter_start");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start)) {
        ark_audio_capturer_adapter_start = nullptr;
      } else {
        ark_audio_capturer_adapter_start = _struct->start;
      }
    } else {
      ark_audio_capturer_adapter_start =
          reinterpret_cast<ArkAudioCapturerAdapterStartFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_capturer_adapter_start, false);

  // Execute
  return ark_audio_capturer_adapter_start(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkAudioCapturerAdapterCToCpp::Stop() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_capturer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(ark_audio_capturer_adapter_stop);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "IUpJy32960X67GoTcH1TKA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_CAPTURER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_audio_capturer_adapter_stop");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, stop)) {
        ark_audio_capturer_adapter_stop = nullptr;
      } else {
        ark_audio_capturer_adapter_stop = _struct->stop;
      }
    } else {
      ark_audio_capturer_adapter_stop =
          reinterpret_cast<ArkAudioCapturerAdapterStopFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_capturer_adapter_stop, false);

  // Execute
  return ark_audio_capturer_adapter_stop(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkAudioCapturerAdapterCToCpp::Release2() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_capturer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_capturer_adapter_release2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "XwF_xQasuiXtaoUwwsNEzA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_CAPTURER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_audio_capturer_adapter_release2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release2)) {
        ark_audio_capturer_adapter_release2 = nullptr;
      } else {
        ark_audio_capturer_adapter_release2 = _struct->release2;
      }
    } else {
      ark_audio_capturer_adapter_release2 =
          reinterpret_cast<ArkAudioCapturerAdapterRelease2Func>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_capturer_adapter_release2, false);

  // Execute
  return ark_audio_capturer_adapter_release2(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCapturerAdapterCToCpp::SetCapturerReadCallback(
    ArkWebRefPtr<ArkAudioCapturerReadCallbackAdapter> callbck) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_capturer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_capturer_adapter_set_capturer_read_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "9$wNPbOcYECYmW$0XuK2Mg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_CAPTURER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_capturer_adapter_set_capturer_read_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_capturer_read_callback)) {
        ark_audio_capturer_adapter_set_capturer_read_callback = nullptr;
      } else {
        ark_audio_capturer_adapter_set_capturer_read_callback =
            _struct->set_capturer_read_callback;
      }
    } else {
      ark_audio_capturer_adapter_set_capturer_read_callback =
          reinterpret_cast<ArkAudioCapturerAdapterSetCapturerReadCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_capturer_adapter_set_capturer_read_callback, 0);

  // Execute
  return ark_audio_capturer_adapter_set_capturer_read_callback(
      _struct, ArkAudioCapturerReadCallbackAdapterCppToC::Invert(callbck));
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCapturerAdapterCToCpp::GetBufferDesc(
    ArkWebRefPtr<ArkBufferDescAdapter> buffferDesc) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_capturer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_capturer_adapter_get_buffer_desc);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "UMoRIyHJXMv5bX8N3ZwlZQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_CAPTURER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_capturer_adapter_get_buffer_desc");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_buffer_desc)) {
        ark_audio_capturer_adapter_get_buffer_desc = nullptr;
      } else {
        ark_audio_capturer_adapter_get_buffer_desc = _struct->get_buffer_desc;
      }
    } else {
      ark_audio_capturer_adapter_get_buffer_desc =
          reinterpret_cast<ArkAudioCapturerAdapterGetBufferDescFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_capturer_adapter_get_buffer_desc,
                                    0);

  // Execute
  return ark_audio_capturer_adapter_get_buffer_desc(
      _struct, ArkBufferDescAdapterCppToC::Invert(buffferDesc));
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCapturerAdapterCToCpp::Enqueue(
    const ArkWebRefPtr<ArkBufferDescAdapter> bufferDesc) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_capturer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_capturer_adapter_enqueue);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "J8Alpn7AcLRVdY5GhZTohw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_CAPTURER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_audio_capturer_adapter_enqueue");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, enqueue)) {
        ark_audio_capturer_adapter_enqueue = nullptr;
      } else {
        ark_audio_capturer_adapter_enqueue = _struct->enqueue;
      }
    } else {
      ark_audio_capturer_adapter_enqueue =
          reinterpret_cast<ArkAudioCapturerAdapterEnqueueFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_capturer_adapter_enqueue, 0);

  // Execute
  return ark_audio_capturer_adapter_enqueue(
      _struct, ArkBufferDescAdapterCppToC::Invert(bufferDesc));
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCapturerAdapterCToCpp::GetFrameCount(uint32_t& frameCount) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_capturer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_capturer_adapter_get_frame_count);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "8ckTp3n0k1t9P_uEJfWWbQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_CAPTURER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_capturer_adapter_get_frame_count");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_frame_count)) {
        ark_audio_capturer_adapter_get_frame_count = nullptr;
      } else {
        ark_audio_capturer_adapter_get_frame_count = _struct->get_frame_count;
      }
    } else {
      ark_audio_capturer_adapter_get_frame_count =
          reinterpret_cast<ArkAudioCapturerAdapterGetFrameCountFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_capturer_adapter_get_frame_count,
                                    0);

  // Execute
  return ark_audio_capturer_adapter_get_frame_count(_struct, &frameCount);
}

ARK_WEB_NO_SANITIZE
int64_t ArkAudioCapturerAdapterCToCpp::GetAudioTime() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_capturer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_capturer_adapter_get_audio_time);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "7Aydee71QDkOZZgdomg1nw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_AUDIO_CAPTURER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_capturer_adapter_get_audio_time");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_audio_time)) {
        ark_audio_capturer_adapter_get_audio_time = nullptr;
      } else {
        ark_audio_capturer_adapter_get_audio_time = _struct->get_audio_time;
      }
    } else {
      ark_audio_capturer_adapter_get_audio_time =
          reinterpret_cast<ArkAudioCapturerAdapterGetAudioTimeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_audio_capturer_adapter_get_audio_time,
                                    0);

  // Execute
  return ark_audio_capturer_adapter_get_audio_time(_struct);
}

ArkAudioCapturerAdapterCToCpp::ArkAudioCapturerAdapterCToCpp() {}

ArkAudioCapturerAdapterCToCpp::~ArkAudioCapturerAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkAudioCapturerAdapterCToCpp,
                           ArkAudioCapturerAdapter,
                           ark_audio_capturer_adapter_t>::kBridgeType =
        ARK_AUDIO_CAPTURER_ADAPTER;

}  // namespace OHOS::ArkWeb
