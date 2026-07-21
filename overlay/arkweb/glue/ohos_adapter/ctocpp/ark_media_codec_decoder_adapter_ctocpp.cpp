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

#include "ohos_adapter/ctocpp/ark_media_codec_decoder_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_audio_cenc_info_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_decoder_callback_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_decoder_format_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkMediaCodecDecoderAdapterCreateVideoDecoderByMimeFunc =
    int32_t (*)(struct _ark_media_codec_decoder_adapter_t* self,
                const ArkWebString* mimetype);
static ArkMediaCodecDecoderAdapterCreateVideoDecoderByMimeFunc
    ark_media_codec_decoder_adapter_create_video_decoder_by_mime =
        reinterpret_cast<
            ArkMediaCodecDecoderAdapterCreateVideoDecoderByMimeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecDecoderAdapterCreateVideoDecoderByNameFunc =
    int32_t (*)(struct _ark_media_codec_decoder_adapter_t* self,
                const ArkWebString* name);
static ArkMediaCodecDecoderAdapterCreateVideoDecoderByNameFunc
    ark_media_codec_decoder_adapter_create_video_decoder_by_name =
        reinterpret_cast<
            ArkMediaCodecDecoderAdapterCreateVideoDecoderByNameFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecDecoderAdapterConfigureDecoderFunc =
    int32_t (*)(struct _ark_media_codec_decoder_adapter_t* self,
                ark_decoder_format_adapter_t* format);
static ArkMediaCodecDecoderAdapterConfigureDecoderFunc
    ark_media_codec_decoder_adapter_configure_decoder =
        reinterpret_cast<ArkMediaCodecDecoderAdapterConfigureDecoderFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecDecoderAdapterSetParameterDecoderFunc =
    int32_t (*)(struct _ark_media_codec_decoder_adapter_t* self,
                ark_decoder_format_adapter_t* format);
static ArkMediaCodecDecoderAdapterSetParameterDecoderFunc
    ark_media_codec_decoder_adapter_set_parameter_decoder =
        reinterpret_cast<ArkMediaCodecDecoderAdapterSetParameterDecoderFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecDecoderAdapterSetOutputSurfaceFunc =
    int32_t (*)(struct _ark_media_codec_decoder_adapter_t* self, void* window);
static ArkMediaCodecDecoderAdapterSetOutputSurfaceFunc
    ark_media_codec_decoder_adapter_set_output_surface =
        reinterpret_cast<ArkMediaCodecDecoderAdapterSetOutputSurfaceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecDecoderAdapterPrepareDecoderFunc =
    int32_t (*)(struct _ark_media_codec_decoder_adapter_t* self);
static ArkMediaCodecDecoderAdapterPrepareDecoderFunc
    ark_media_codec_decoder_adapter_prepare_decoder =
        reinterpret_cast<ArkMediaCodecDecoderAdapterPrepareDecoderFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecDecoderAdapterStartDecoderFunc =
    int32_t (*)(struct _ark_media_codec_decoder_adapter_t* self);
static ArkMediaCodecDecoderAdapterStartDecoderFunc
    ark_media_codec_decoder_adapter_start_decoder =
        reinterpret_cast<ArkMediaCodecDecoderAdapterStartDecoderFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecDecoderAdapterStopDecoderFunc =
    int32_t (*)(struct _ark_media_codec_decoder_adapter_t* self);
static ArkMediaCodecDecoderAdapterStopDecoderFunc
    ark_media_codec_decoder_adapter_stop_decoder =
        reinterpret_cast<ArkMediaCodecDecoderAdapterStopDecoderFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecDecoderAdapterFlushDecoderFunc =
    int32_t (*)(struct _ark_media_codec_decoder_adapter_t* self);
static ArkMediaCodecDecoderAdapterFlushDecoderFunc
    ark_media_codec_decoder_adapter_flush_decoder =
        reinterpret_cast<ArkMediaCodecDecoderAdapterFlushDecoderFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecDecoderAdapterResetDecoderFunc =
    int32_t (*)(struct _ark_media_codec_decoder_adapter_t* self);
static ArkMediaCodecDecoderAdapterResetDecoderFunc
    ark_media_codec_decoder_adapter_reset_decoder =
        reinterpret_cast<ArkMediaCodecDecoderAdapterResetDecoderFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecDecoderAdapterReleaseDecoderFunc =
    int32_t (*)(struct _ark_media_codec_decoder_adapter_t* self);
static ArkMediaCodecDecoderAdapterReleaseDecoderFunc
    ark_media_codec_decoder_adapter_release_decoder =
        reinterpret_cast<ArkMediaCodecDecoderAdapterReleaseDecoderFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecDecoderAdapterQueueInputBufferDecFunc =
    int32_t (*)(struct _ark_media_codec_decoder_adapter_t* self,
                uint32_t index,
                int64_t presentationTimeUs,
                int32_t size,
                int32_t offset,
                uint32_t flag);
static ArkMediaCodecDecoderAdapterQueueInputBufferDecFunc
    ark_media_codec_decoder_adapter_queue_input_buffer_dec =
        reinterpret_cast<ArkMediaCodecDecoderAdapterQueueInputBufferDecFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecDecoderAdapterGetOutputFormatDecFunc =
    int32_t (*)(struct _ark_media_codec_decoder_adapter_t* self,
                ark_decoder_format_adapter_t* format);
static ArkMediaCodecDecoderAdapterGetOutputFormatDecFunc
    ark_media_codec_decoder_adapter_get_output_format_dec =
        reinterpret_cast<ArkMediaCodecDecoderAdapterGetOutputFormatDecFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecDecoderAdapterReleaseOutputBufferDecFunc =
    int32_t (*)(struct _ark_media_codec_decoder_adapter_t* self,
                uint32_t index,
                bool isRender);
static ArkMediaCodecDecoderAdapterReleaseOutputBufferDecFunc
    ark_media_codec_decoder_adapter_release_output_buffer_dec =
        reinterpret_cast<ArkMediaCodecDecoderAdapterReleaseOutputBufferDecFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecDecoderAdapterSetCallbackDecFunc =
    int32_t (*)(struct _ark_media_codec_decoder_adapter_t* self,
                ark_decoder_callback_adapter_t* callback);
static ArkMediaCodecDecoderAdapterSetCallbackDecFunc
    ark_media_codec_decoder_adapter_set_callback_dec =
        reinterpret_cast<ArkMediaCodecDecoderAdapterSetCallbackDecFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecDecoderAdapterSetDecryptionConfigFunc =
    int32_t (*)(struct _ark_media_codec_decoder_adapter_t* self,
                void* session,
                bool isSecure);
static ArkMediaCodecDecoderAdapterSetDecryptionConfigFunc
    ark_media_codec_decoder_adapter_set_decryption_config =
        reinterpret_cast<ArkMediaCodecDecoderAdapterSetDecryptionConfigFunc>(
            ARK_WEB_INIT_ADDR);

using ArkMediaCodecDecoderAdapterSetAVCencInfoFunc =
    int32_t (*)(struct _ark_media_codec_decoder_adapter_t* self,
                uint32_t index,
                ark_audio_cenc_info_adapter_t* cencInfo);
static ArkMediaCodecDecoderAdapterSetAVCencInfoFunc
    ark_media_codec_decoder_adapter_set_avcenc_info =
        reinterpret_cast<ArkMediaCodecDecoderAdapterSetAVCencInfoFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecDecoderAdapterCToCpp::CreateVideoDecoderByMime(
    const ArkWebString& mimetype) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_media_codec_decoder_adapter_create_video_decoder_by_mime);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "yoBDbrSBgw5qOyCnYjcNGg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_MEDIA_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_decoder_adapter_create_video_decoder_by_mime");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_video_decoder_by_mime)) {
        ark_media_codec_decoder_adapter_create_video_decoder_by_mime = nullptr;
      } else {
        ark_media_codec_decoder_adapter_create_video_decoder_by_mime =
            _struct->create_video_decoder_by_mime;
      }
    } else {
      ark_media_codec_decoder_adapter_create_video_decoder_by_mime =
          reinterpret_cast<
              ArkMediaCodecDecoderAdapterCreateVideoDecoderByMimeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_decoder_adapter_create_video_decoder_by_mime, 0);

  // Execute
  return ark_media_codec_decoder_adapter_create_video_decoder_by_mime(
      _struct, &mimetype);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecDecoderAdapterCToCpp::CreateVideoDecoderByName(
    const ArkWebString& name) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_media_codec_decoder_adapter_create_video_decoder_by_name);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "v9Z5Ldsi2$k4LrDazUf3XQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_MEDIA_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_decoder_adapter_create_video_decoder_by_name");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_video_decoder_by_name)) {
        ark_media_codec_decoder_adapter_create_video_decoder_by_name = nullptr;
      } else {
        ark_media_codec_decoder_adapter_create_video_decoder_by_name =
            _struct->create_video_decoder_by_name;
      }
    } else {
      ark_media_codec_decoder_adapter_create_video_decoder_by_name =
          reinterpret_cast<
              ArkMediaCodecDecoderAdapterCreateVideoDecoderByNameFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_decoder_adapter_create_video_decoder_by_name, 0);

  // Execute
  return ark_media_codec_decoder_adapter_create_video_decoder_by_name(_struct,
                                                                      &name);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecDecoderAdapterCToCpp::ConfigureDecoder(
    const ArkWebRefPtr<ArkDecoderFormatAdapter> format) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_media_codec_decoder_adapter_configure_decoder);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "4_v3LWyo8LYchyNr5NbmIQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_MEDIA_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_decoder_adapter_configure_decoder");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, configure_decoder)) {
        ark_media_codec_decoder_adapter_configure_decoder = nullptr;
      } else {
        ark_media_codec_decoder_adapter_configure_decoder =
            _struct->configure_decoder;
      }
    } else {
      ark_media_codec_decoder_adapter_configure_decoder =
          reinterpret_cast<ArkMediaCodecDecoderAdapterConfigureDecoderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_decoder_adapter_configure_decoder, 0);

  // Execute
  return ark_media_codec_decoder_adapter_configure_decoder(
      _struct, ArkDecoderFormatAdapterCppToC::Invert(format));
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecDecoderAdapterCToCpp::SetParameterDecoder(
    const ArkWebRefPtr<ArkDecoderFormatAdapter> format) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_media_codec_decoder_adapter_set_parameter_decoder);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "RRX4LkgrkygwVSPZNngHCw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_MEDIA_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_decoder_adapter_set_parameter_decoder");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_parameter_decoder)) {
        ark_media_codec_decoder_adapter_set_parameter_decoder = nullptr;
      } else {
        ark_media_codec_decoder_adapter_set_parameter_decoder =
            _struct->set_parameter_decoder;
      }
    } else {
      ark_media_codec_decoder_adapter_set_parameter_decoder =
          reinterpret_cast<ArkMediaCodecDecoderAdapterSetParameterDecoderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_decoder_adapter_set_parameter_decoder, 0);

  // Execute
  return ark_media_codec_decoder_adapter_set_parameter_decoder(
      _struct, ArkDecoderFormatAdapterCppToC::Invert(format));
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecDecoderAdapterCToCpp::SetOutputSurface(void* window) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_media_codec_decoder_adapter_set_output_surface);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "$sEoRExhV52gBlcXbRHWfA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_MEDIA_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_decoder_adapter_set_output_surface");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_output_surface)) {
        ark_media_codec_decoder_adapter_set_output_surface = nullptr;
      } else {
        ark_media_codec_decoder_adapter_set_output_surface =
            _struct->set_output_surface;
      }
    } else {
      ark_media_codec_decoder_adapter_set_output_surface =
          reinterpret_cast<ArkMediaCodecDecoderAdapterSetOutputSurfaceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_decoder_adapter_set_output_surface, 0);

  // Execute
  return ark_media_codec_decoder_adapter_set_output_surface(_struct, window);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecDecoderAdapterCToCpp::PrepareDecoder() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_codec_decoder_adapter_prepare_decoder);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "t931S3yS2UHwv0IS7tuK6g";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_MEDIA_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_decoder_adapter_prepare_decoder");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, prepare_decoder)) {
        ark_media_codec_decoder_adapter_prepare_decoder = nullptr;
      } else {
        ark_media_codec_decoder_adapter_prepare_decoder =
            _struct->prepare_decoder;
      }
    } else {
      ark_media_codec_decoder_adapter_prepare_decoder =
          reinterpret_cast<ArkMediaCodecDecoderAdapterPrepareDecoderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_decoder_adapter_prepare_decoder, 0);

  // Execute
  return ark_media_codec_decoder_adapter_prepare_decoder(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecDecoderAdapterCToCpp::StartDecoder() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_codec_decoder_adapter_start_decoder);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "tBRbD_0aLuzZcgqTwNl1zQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_MEDIA_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_decoder_adapter_start_decoder");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start_decoder)) {
        ark_media_codec_decoder_adapter_start_decoder = nullptr;
      } else {
        ark_media_codec_decoder_adapter_start_decoder = _struct->start_decoder;
      }
    } else {
      ark_media_codec_decoder_adapter_start_decoder =
          reinterpret_cast<ArkMediaCodecDecoderAdapterStartDecoderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_decoder_adapter_start_decoder, 0);

  // Execute
  return ark_media_codec_decoder_adapter_start_decoder(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecDecoderAdapterCToCpp::StopDecoder() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_codec_decoder_adapter_stop_decoder);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "t_3OffSUNQroXvCuNxT4rQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_MEDIA_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_decoder_adapter_stop_decoder");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, stop_decoder)) {
        ark_media_codec_decoder_adapter_stop_decoder = nullptr;
      } else {
        ark_media_codec_decoder_adapter_stop_decoder = _struct->stop_decoder;
      }
    } else {
      ark_media_codec_decoder_adapter_stop_decoder =
          reinterpret_cast<ArkMediaCodecDecoderAdapterStopDecoderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_decoder_adapter_stop_decoder, 0);

  // Execute
  return ark_media_codec_decoder_adapter_stop_decoder(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecDecoderAdapterCToCpp::FlushDecoder() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_codec_decoder_adapter_flush_decoder);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "5FjN8VAXP3tuA7edeXVOGQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_MEDIA_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_decoder_adapter_flush_decoder");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, flush_decoder)) {
        ark_media_codec_decoder_adapter_flush_decoder = nullptr;
      } else {
        ark_media_codec_decoder_adapter_flush_decoder = _struct->flush_decoder;
      }
    } else {
      ark_media_codec_decoder_adapter_flush_decoder =
          reinterpret_cast<ArkMediaCodecDecoderAdapterFlushDecoderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_decoder_adapter_flush_decoder, 0);

  // Execute
  return ark_media_codec_decoder_adapter_flush_decoder(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecDecoderAdapterCToCpp::ResetDecoder() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_codec_decoder_adapter_reset_decoder);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "dFn1yjM_Zp9T3i0cu1wJog";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_MEDIA_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_decoder_adapter_reset_decoder");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, reset_decoder)) {
        ark_media_codec_decoder_adapter_reset_decoder = nullptr;
      } else {
        ark_media_codec_decoder_adapter_reset_decoder = _struct->reset_decoder;
      }
    } else {
      ark_media_codec_decoder_adapter_reset_decoder =
          reinterpret_cast<ArkMediaCodecDecoderAdapterResetDecoderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_decoder_adapter_reset_decoder, 0);

  // Execute
  return ark_media_codec_decoder_adapter_reset_decoder(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecDecoderAdapterCToCpp::ReleaseDecoder() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_codec_decoder_adapter_release_decoder);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "8IuTz84V79_07SmgpqlCww";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_MEDIA_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_decoder_adapter_release_decoder");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release_decoder)) {
        ark_media_codec_decoder_adapter_release_decoder = nullptr;
      } else {
        ark_media_codec_decoder_adapter_release_decoder =
            _struct->release_decoder;
      }
    } else {
      ark_media_codec_decoder_adapter_release_decoder =
          reinterpret_cast<ArkMediaCodecDecoderAdapterReleaseDecoderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_decoder_adapter_release_decoder, 0);

  // Execute
  return ark_media_codec_decoder_adapter_release_decoder(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecDecoderAdapterCToCpp::QueueInputBufferDec(
    uint32_t index,
    int64_t presentationTimeUs,
    int32_t size,
    int32_t offset,
    uint32_t flag) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_media_codec_decoder_adapter_queue_input_buffer_dec);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "kEqcu3rPXOxCgRBh3WdL2w";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_MEDIA_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_decoder_adapter_queue_input_buffer_dec");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, queue_input_buffer_dec)) {
        ark_media_codec_decoder_adapter_queue_input_buffer_dec = nullptr;
      } else {
        ark_media_codec_decoder_adapter_queue_input_buffer_dec =
            _struct->queue_input_buffer_dec;
      }
    } else {
      ark_media_codec_decoder_adapter_queue_input_buffer_dec =
          reinterpret_cast<ArkMediaCodecDecoderAdapterQueueInputBufferDecFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_decoder_adapter_queue_input_buffer_dec, 0);

  // Execute
  return ark_media_codec_decoder_adapter_queue_input_buffer_dec(
      _struct, index, presentationTimeUs, size, offset, flag);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecDecoderAdapterCToCpp::GetOutputFormatDec(
    ArkWebRefPtr<ArkDecoderFormatAdapter> format) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_media_codec_decoder_adapter_get_output_format_dec);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "BfBmxzDLF8U6FODwgGmIyQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_MEDIA_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_decoder_adapter_get_output_format_dec");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_output_format_dec)) {
        ark_media_codec_decoder_adapter_get_output_format_dec = nullptr;
      } else {
        ark_media_codec_decoder_adapter_get_output_format_dec =
            _struct->get_output_format_dec;
      }
    } else {
      ark_media_codec_decoder_adapter_get_output_format_dec =
          reinterpret_cast<ArkMediaCodecDecoderAdapterGetOutputFormatDecFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_decoder_adapter_get_output_format_dec, 0);

  // Execute
  return ark_media_codec_decoder_adapter_get_output_format_dec(
      _struct, ArkDecoderFormatAdapterCppToC::Invert(format));
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecDecoderAdapterCToCpp::ReleaseOutputBufferDec(
    uint32_t index,
    bool isRender) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_media_codec_decoder_adapter_release_output_buffer_dec);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jk6_wHL6Nd1Ql2s5WL$iEg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_MEDIA_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_decoder_adapter_release_output_buffer_dec");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release_output_buffer_dec)) {
        ark_media_codec_decoder_adapter_release_output_buffer_dec = nullptr;
      } else {
        ark_media_codec_decoder_adapter_release_output_buffer_dec =
            _struct->release_output_buffer_dec;
      }
    } else {
      ark_media_codec_decoder_adapter_release_output_buffer_dec =
          reinterpret_cast<
              ArkMediaCodecDecoderAdapterReleaseOutputBufferDecFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_decoder_adapter_release_output_buffer_dec, 0);

  // Execute
  return ark_media_codec_decoder_adapter_release_output_buffer_dec(
      _struct, index, isRender);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecDecoderAdapterCToCpp::SetCallbackDec(
    const ArkWebRefPtr<ArkDecoderCallbackAdapter> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_codec_decoder_adapter_set_callback_dec);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "bBVtGZm1Bffa30LmfpFNVQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_MEDIA_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_decoder_adapter_set_callback_dec");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_callback_dec)) {
        ark_media_codec_decoder_adapter_set_callback_dec = nullptr;
      } else {
        ark_media_codec_decoder_adapter_set_callback_dec =
            _struct->set_callback_dec;
      }
    } else {
      ark_media_codec_decoder_adapter_set_callback_dec =
          reinterpret_cast<ArkMediaCodecDecoderAdapterSetCallbackDecFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_decoder_adapter_set_callback_dec, 0);

  // Execute
  return ark_media_codec_decoder_adapter_set_callback_dec(
      _struct, ArkDecoderCallbackAdapterCppToC::Invert(callback));
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecDecoderAdapterCToCpp::SetDecryptionConfig(void* session,
                                                               bool isSecure) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_media_codec_decoder_adapter_set_decryption_config);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "4Gr3OpkzktjVoVej6LuajQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_MEDIA_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_decoder_adapter_set_decryption_config");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_decryption_config)) {
        ark_media_codec_decoder_adapter_set_decryption_config = nullptr;
      } else {
        ark_media_codec_decoder_adapter_set_decryption_config =
            _struct->set_decryption_config;
      }
    } else {
      ark_media_codec_decoder_adapter_set_decryption_config =
          reinterpret_cast<ArkMediaCodecDecoderAdapterSetDecryptionConfigFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_decoder_adapter_set_decryption_config, 0);

  // Execute
  return ark_media_codec_decoder_adapter_set_decryption_config(_struct, session,
                                                               isSecure);
}

ARK_WEB_NO_SANITIZE
int32_t ArkMediaCodecDecoderAdapterCToCpp::SetAVCencInfo(
    uint32_t index,
    const ArkWebRefPtr<ArkAudioCencInfoAdapter> cencInfo) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_media_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_media_codec_decoder_adapter_set_avcenc_info);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "vFnr8JD$HkaOYvwQ14M7Vw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_MEDIA_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_media_codec_decoder_adapter_set_avcenc_info");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_avcenc_info)) {
        ark_media_codec_decoder_adapter_set_avcenc_info = nullptr;
      } else {
        ark_media_codec_decoder_adapter_set_avcenc_info =
            _struct->set_avcenc_info;
      }
    } else {
      ark_media_codec_decoder_adapter_set_avcenc_info =
          reinterpret_cast<ArkMediaCodecDecoderAdapterSetAVCencInfoFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_media_codec_decoder_adapter_set_avcenc_info, 0);

  // Execute
  return ark_media_codec_decoder_adapter_set_avcenc_info(
      _struct, index, ArkAudioCencInfoAdapterCppToC::Invert(cencInfo));
}

ArkMediaCodecDecoderAdapterCToCpp::ArkMediaCodecDecoderAdapterCToCpp() {}

ArkMediaCodecDecoderAdapterCToCpp::~ArkMediaCodecDecoderAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkMediaCodecDecoderAdapterCToCpp,
                           ArkMediaCodecDecoderAdapter,
                           ark_media_codec_decoder_adapter_t>::kBridgeType =
        ARK_MEDIA_CODEC_DECODER_ADAPTER;

}  // namespace OHOS::ArkWeb
