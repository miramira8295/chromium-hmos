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

#include "ohos_adapter/ctocpp/ark_media_codec_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_codec_callback_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_codec_config_para_adapter_cpptoc.h"
#include "ohos_adapter/ctocpp/ark_producer_surface_adapter_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkMediaCodecAdapterCreateVideoCodecByMimeFunc =
    int32_t (*)(struct _ark_media_codec_adapter_t* self,
                const ArkWebString mimetype);
static ArkMediaCodecAdapterCreateVideoCodecByMimeFunc
    ark_media_codec_adapter_create_video_codec_by_mime =
        reinterpret_cast<ArkMediaCodecAdapterCreateVideoCodecByMimeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecAdapterCreateVideoCodecByNameFunc =
    int32_t (*)(struct _ark_media_codec_adapter_t* self,
                const ArkWebString name);
static ArkMediaCodecAdapterCreateVideoCodecByNameFunc
    ark_media_codec_adapter_create_video_codec_by_name =
        reinterpret_cast<ArkMediaCodecAdapterCreateVideoCodecByNameFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecAdapterSetCodecCallbackFunc =
    int32_t (*)(struct _ark_media_codec_adapter_t* self,
                ark_codec_callback_adapter_t* callback);
static ArkMediaCodecAdapterSetCodecCallbackFunc
    ark_media_codec_adapter_set_codec_callback =
        reinterpret_cast<ArkMediaCodecAdapterSetCodecCallbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecAdapterConfigureFunc =
    int32_t (*)(struct _ark_media_codec_adapter_t* self,
                ark_codec_config_para_adapter_t* config);
static ArkMediaCodecAdapterConfigureFunc ark_media_codec_adapter_configure =
    reinterpret_cast<ArkMediaCodecAdapterConfigureFunc>(ARK_WEB_INIT_ADDR);

using ArkMediaCodecAdapterPrepareFunc =
    int32_t (*)(struct _ark_media_codec_adapter_t* self);
static ArkMediaCodecAdapterPrepareFunc ark_media_codec_adapter_prepare =
    reinterpret_cast<ArkMediaCodecAdapterPrepareFunc>(ARK_WEB_INIT_ADDR);

using ArkMediaCodecAdapterStartFunc =
    int32_t (*)(struct _ark_media_codec_adapter_t* self);
static ArkMediaCodecAdapterStartFunc ark_media_codec_adapter_start =
    reinterpret_cast<ArkMediaCodecAdapterStartFunc>(ARK_WEB_INIT_ADDR);

using ArkMediaCodecAdapterStopFunc =
    int32_t (*)(struct _ark_media_codec_adapter_t* self);
static ArkMediaCodecAdapterStopFunc ark_media_codec_adapter_stop =
    reinterpret_cast<ArkMediaCodecAdapterStopFunc>(ARK_WEB_INIT_ADDR);

using ArkMediaCodecAdapterResetFunc =
    int32_t (*)(struct _ark_media_codec_adapter_t* self);
static ArkMediaCodecAdapterResetFunc ark_media_codec_adapter_reset =
    reinterpret_cast<ArkMediaCodecAdapterResetFunc>(ARK_WEB_INIT_ADDR);

using ArkMediaCodecAdapterReleaseFunc =
    int32_t (*)(struct _ark_media_codec_adapter_t* self);
static ArkMediaCodecAdapterReleaseFunc ark_media_codec_adapter_release =
    reinterpret_cast<ArkMediaCodecAdapterReleaseFunc>(ARK_WEB_INIT_ADDR);

using ArkMediaCodecAdapterCreateInputSurfaceFunc =
    ark_producer_surface_adapter_t* (*)(struct _ark_media_codec_adapter_t*
                                            self);
static ArkMediaCodecAdapterCreateInputSurfaceFunc
    ark_media_codec_adapter_create_input_surface =
        reinterpret_cast<ArkMediaCodecAdapterCreateInputSurfaceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecAdapterReleaseOutputBufferFunc =
    int32_t (*)(struct _ark_media_codec_adapter_t* self,
                uint32_t index,
                bool isRender);
static ArkMediaCodecAdapterReleaseOutputBufferFunc
    ark_media_codec_adapter_release_output_buffer =
        reinterpret_cast<ArkMediaCodecAdapterReleaseOutputBufferFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecAdapterRequestKeyFrameSoonFunc =
    int32_t (*)(struct _ark_media_codec_adapter_t* self);
static ArkMediaCodecAdapterRequestKeyFrameSoonFunc
    ark_media_codec_adapter_request_key_frame_soon =
        reinterpret_cast<ArkMediaCodecAdapterRequestKeyFrameSoonFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecAdapterCToCpp::CreateVideoCodecByMime(
    const ArkWebString mimetype) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_media_codec_adapter_create_video_codec_by_mime);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "CDA3Y0dlPotWqJuCMrbIpw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_CODEC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_adapter_create_video_codec_by_mime");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_video_codec_by_mime)) {
        ark_media_codec_adapter_create_video_codec_by_mime = nullptr;
      } else {
        ark_media_codec_adapter_create_video_codec_by_mime =
            _struct->create_video_codec_by_mime;
      }
    } else {
      ark_media_codec_adapter_create_video_codec_by_mime =
          reinterpret_cast<ArkMediaCodecAdapterCreateVideoCodecByMimeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_adapter_create_video_codec_by_mime, 0);

  // Execute
  return ark_media_codec_adapter_create_video_codec_by_mime(_struct, mimetype);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecAdapterCToCpp::CreateVideoCodecByName(
    const ArkWebString name) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_media_codec_adapter_create_video_codec_by_name);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "S4LIfkceTMG8eRdTjyC9$g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_CODEC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_adapter_create_video_codec_by_name");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_video_codec_by_name)) {
        ark_media_codec_adapter_create_video_codec_by_name = nullptr;
      } else {
        ark_media_codec_adapter_create_video_codec_by_name =
            _struct->create_video_codec_by_name;
      }
    } else {
      ark_media_codec_adapter_create_video_codec_by_name =
          reinterpret_cast<ArkMediaCodecAdapterCreateVideoCodecByNameFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_adapter_create_video_codec_by_name, 0);

  // Execute
  return ark_media_codec_adapter_create_video_codec_by_name(_struct, name);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecAdapterCToCpp::SetCodecCallback(
    const ArkWebRefPtr<ArkCodecCallbackAdapter> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_codec_adapter_set_codec_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "iAA2usZ2_AsbC$2GS4waZQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_CODEC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_adapter_set_codec_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_codec_callback)) {
        ark_media_codec_adapter_set_codec_callback = nullptr;
      } else {
        ark_media_codec_adapter_set_codec_callback =
            _struct->set_codec_callback;
      }
    } else {
      ark_media_codec_adapter_set_codec_callback =
          reinterpret_cast<ArkMediaCodecAdapterSetCodecCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_media_codec_adapter_set_codec_callback,
                                    0);

  // Execute
  return ark_media_codec_adapter_set_codec_callback(
      _struct, ArkCodecCallbackAdapterCppToC::Invert(callback));
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecAdapterCToCpp::Configure(
    const ArkWebRefPtr<ArkCodecConfigParaAdapter> config) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_codec_adapter_configure);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "VOE2T8nPteO_4QIVC_rVyA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_CODEC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_media_codec_adapter_configure");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, configure)) {
        ark_media_codec_adapter_configure = nullptr;
      } else {
        ark_media_codec_adapter_configure = _struct->configure;
      }
    } else {
      ark_media_codec_adapter_configure =
          reinterpret_cast<ArkMediaCodecAdapterConfigureFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_media_codec_adapter_configure, 0);

  // Execute
  return ark_media_codec_adapter_configure(
      _struct, ArkCodecConfigParaAdapterCppToC::Invert(config));
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecAdapterCToCpp::Prepare() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_media_codec_adapter_prepare);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "obaBEcG2xdxEghkYF0qidA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_CODEC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_media_codec_adapter_prepare");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, prepare)) {
        ark_media_codec_adapter_prepare = nullptr;
      } else {
        ark_media_codec_adapter_prepare = _struct->prepare;
      }
    } else {
      ark_media_codec_adapter_prepare =
          reinterpret_cast<ArkMediaCodecAdapterPrepareFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_media_codec_adapter_prepare, 0);

  // Execute
  return ark_media_codec_adapter_prepare(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecAdapterCToCpp::Start() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_media_codec_adapter_start);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "OdezvQIGEeywipiaMPh2OA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_CODEC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_media_codec_adapter_start");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start)) {
        ark_media_codec_adapter_start = nullptr;
      } else {
        ark_media_codec_adapter_start = _struct->start;
      }
    } else {
      ark_media_codec_adapter_start =
          reinterpret_cast<ArkMediaCodecAdapterStartFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_media_codec_adapter_start, 0);

  // Execute
  return ark_media_codec_adapter_start(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecAdapterCToCpp::Stop() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_media_codec_adapter_stop);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "4p1YuPsiY9A0UptNgW_40A";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_CODEC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_media_codec_adapter_stop");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, stop)) {
        ark_media_codec_adapter_stop = nullptr;
      } else {
        ark_media_codec_adapter_stop = _struct->stop;
      }
    } else {
      ark_media_codec_adapter_stop =
          reinterpret_cast<ArkMediaCodecAdapterStopFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_media_codec_adapter_stop, 0);

  // Execute
  return ark_media_codec_adapter_stop(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecAdapterCToCpp::Reset() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_media_codec_adapter_reset);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "8OGapGAvk6NeEARhYPS6bg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_CODEC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_media_codec_adapter_reset");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, reset)) {
        ark_media_codec_adapter_reset = nullptr;
      } else {
        ark_media_codec_adapter_reset = _struct->reset;
      }
    } else {
      ark_media_codec_adapter_reset =
          reinterpret_cast<ArkMediaCodecAdapterResetFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_media_codec_adapter_reset, 0);

  // Execute
  return ark_media_codec_adapter_reset(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecAdapterCToCpp::Release() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_media_codec_adapter_release);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "fk_5CthBqAh1AA1ysNF9Mw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_CODEC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_media_codec_adapter_release");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release)) {
        ark_media_codec_adapter_release = nullptr;
      } else {
        ark_media_codec_adapter_release = _struct->release;
      }
    } else {
      ark_media_codec_adapter_release =
          reinterpret_cast<ArkMediaCodecAdapterReleaseFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_media_codec_adapter_release, 0);

  // Execute
  return ark_media_codec_adapter_release(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkProducerSurfaceAdapter>
ArkMediaCodecAdapterCToCpp::CreateInputSurface() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_codec_adapter_create_input_surface);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "2Ht9Knwjqi$jRDBXcKUHIQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_CODEC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_adapter_create_input_surface");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_input_surface)) {
        ark_media_codec_adapter_create_input_surface = nullptr;
      } else {
        ark_media_codec_adapter_create_input_surface =
            _struct->create_input_surface;
      }
    } else {
      ark_media_codec_adapter_create_input_surface =
          reinterpret_cast<ArkMediaCodecAdapterCreateInputSurfaceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_adapter_create_input_surface, nullptr);

  // Execute
  ark_producer_surface_adapter_t* _retval =
      ark_media_codec_adapter_create_input_surface(_struct);

  // Return type: refptr_same
  return ArkProducerSurfaceAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecAdapterCToCpp::ReleaseOutputBuffer(uint32_t index,
                                                        bool isRender) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_codec_adapter_release_output_buffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "YfLeKkw64O2Id4LEuEsh8A";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_CODEC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_adapter_release_output_buffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release_output_buffer)) {
        ark_media_codec_adapter_release_output_buffer = nullptr;
      } else {
        ark_media_codec_adapter_release_output_buffer =
            _struct->release_output_buffer;
      }
    } else {
      ark_media_codec_adapter_release_output_buffer =
          reinterpret_cast<ArkMediaCodecAdapterReleaseOutputBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_adapter_release_output_buffer, 0);

  // Execute
  return ark_media_codec_adapter_release_output_buffer(_struct, index,
                                                       isRender);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecAdapterCToCpp::RequestKeyFrameSoon() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_codec_adapter_request_key_frame_soon);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ozocBRXhClBszEVudIIa4g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_MEDIA_CODEC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_adapter_request_key_frame_soon");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, request_key_frame_soon)) {
        ark_media_codec_adapter_request_key_frame_soon = nullptr;
      } else {
        ark_media_codec_adapter_request_key_frame_soon =
            _struct->request_key_frame_soon;
      }
    } else {
      ark_media_codec_adapter_request_key_frame_soon =
          reinterpret_cast<ArkMediaCodecAdapterRequestKeyFrameSoonFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_adapter_request_key_frame_soon, 0);

  // Execute
  return ark_media_codec_adapter_request_key_frame_soon(_struct);
}

ArkMediaCodecAdapterCToCpp::ArkMediaCodecAdapterCToCpp() {}

ArkMediaCodecAdapterCToCpp::~ArkMediaCodecAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkMediaCodecAdapterCToCpp,
                           ArkMediaCodecAdapter,
                           ark_media_codec_adapter_t>::kBridgeType =
        ARK_MEDIA_CODEC_ADAPTER;

}  // namespace OHOS::ArkWeb
