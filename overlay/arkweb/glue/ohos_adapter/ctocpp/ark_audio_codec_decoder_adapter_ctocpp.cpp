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

#include "ohos_adapter/ctocpp/ark_audio_codec_decoder_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_audio_cenc_info_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_audio_decoder_callback_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_audio_decoder_format_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkAudioCodecDecoderAdapterCreateAudioDecoderByMimeFunc =
    int32_t (*)(struct _ark_audio_codec_decoder_adapter_t* self,
                const ArkWebString* mimetype);
static ArkAudioCodecDecoderAdapterCreateAudioDecoderByMimeFunc
    ark_audio_codec_decoder_adapter_create_audio_decoder_by_mime =
        reinterpret_cast<
            ArkAudioCodecDecoderAdapterCreateAudioDecoderByMimeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioCodecDecoderAdapterCreateAudioDecoderByNameFunc =
    int32_t (*)(struct _ark_audio_codec_decoder_adapter_t* self,
                const ArkWebString* name);
static ArkAudioCodecDecoderAdapterCreateAudioDecoderByNameFunc
    ark_audio_codec_decoder_adapter_create_audio_decoder_by_name =
        reinterpret_cast<
            ArkAudioCodecDecoderAdapterCreateAudioDecoderByNameFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioCodecDecoderAdapterConfigureDecoderFunc =
    int32_t (*)(struct _ark_audio_codec_decoder_adapter_t* self,
                ark_audio_decoder_format_adapter_t* format);
static ArkAudioCodecDecoderAdapterConfigureDecoderFunc
    ark_audio_codec_decoder_adapter_configure_decoder =
        reinterpret_cast<ArkAudioCodecDecoderAdapterConfigureDecoderFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioCodecDecoderAdapterSetParameterDecoderFunc =
    int32_t (*)(struct _ark_audio_codec_decoder_adapter_t* self,
                ark_audio_decoder_format_adapter_t* format);
static ArkAudioCodecDecoderAdapterSetParameterDecoderFunc
    ark_audio_codec_decoder_adapter_set_parameter_decoder =
        reinterpret_cast<ArkAudioCodecDecoderAdapterSetParameterDecoderFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioCodecDecoderAdapterPrepareDecoderFunc =
    int32_t (*)(struct _ark_audio_codec_decoder_adapter_t* self);
static ArkAudioCodecDecoderAdapterPrepareDecoderFunc
    ark_audio_codec_decoder_adapter_prepare_decoder =
        reinterpret_cast<ArkAudioCodecDecoderAdapterPrepareDecoderFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioCodecDecoderAdapterStartDecoderFunc =
    int32_t (*)(struct _ark_audio_codec_decoder_adapter_t* self);
static ArkAudioCodecDecoderAdapterStartDecoderFunc
    ark_audio_codec_decoder_adapter_start_decoder =
        reinterpret_cast<ArkAudioCodecDecoderAdapterStartDecoderFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioCodecDecoderAdapterStopDecoderFunc =
    int32_t (*)(struct _ark_audio_codec_decoder_adapter_t* self);
static ArkAudioCodecDecoderAdapterStopDecoderFunc
    ark_audio_codec_decoder_adapter_stop_decoder =
        reinterpret_cast<ArkAudioCodecDecoderAdapterStopDecoderFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioCodecDecoderAdapterFlushDecoderFunc =
    int32_t (*)(struct _ark_audio_codec_decoder_adapter_t* self);
static ArkAudioCodecDecoderAdapterFlushDecoderFunc
    ark_audio_codec_decoder_adapter_flush_decoder =
        reinterpret_cast<ArkAudioCodecDecoderAdapterFlushDecoderFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioCodecDecoderAdapterResetDecoderFunc =
    int32_t (*)(struct _ark_audio_codec_decoder_adapter_t* self);
static ArkAudioCodecDecoderAdapterResetDecoderFunc
    ark_audio_codec_decoder_adapter_reset_decoder =
        reinterpret_cast<ArkAudioCodecDecoderAdapterResetDecoderFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioCodecDecoderAdapterReleaseDecoderFunc =
    int32_t (*)(struct _ark_audio_codec_decoder_adapter_t* self);
static ArkAudioCodecDecoderAdapterReleaseDecoderFunc
    ark_audio_codec_decoder_adapter_release_decoder =
        reinterpret_cast<ArkAudioCodecDecoderAdapterReleaseDecoderFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioCodecDecoderAdapterQueueInputBufferDecFunc =
    int32_t (*)(struct _ark_audio_codec_decoder_adapter_t* self,
                uint32_t index,
                int64_t presentationTimeUs,
                uint8_t* bufferData,
                int32_t bufferSize,
                ark_audio_cenc_info_adapter_t* cencInfo,
                bool isEncrypted,
                uint32_t flag);
static ArkAudioCodecDecoderAdapterQueueInputBufferDecFunc
    ark_audio_codec_decoder_adapter_queue_input_buffer_dec =
        reinterpret_cast<ArkAudioCodecDecoderAdapterQueueInputBufferDecFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioCodecDecoderAdapterGetOutputFormatDecFunc =
    int32_t (*)(struct _ark_audio_codec_decoder_adapter_t* self,
                ark_audio_decoder_format_adapter_t* format);
static ArkAudioCodecDecoderAdapterGetOutputFormatDecFunc
    ark_audio_codec_decoder_adapter_get_output_format_dec =
        reinterpret_cast<ArkAudioCodecDecoderAdapterGetOutputFormatDecFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioCodecDecoderAdapterReleaseOutputBufferDecFunc =
    int32_t (*)(struct _ark_audio_codec_decoder_adapter_t* self,
                uint32_t index);
static ArkAudioCodecDecoderAdapterReleaseOutputBufferDecFunc
    ark_audio_codec_decoder_adapter_release_output_buffer_dec =
        reinterpret_cast<ArkAudioCodecDecoderAdapterReleaseOutputBufferDecFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioCodecDecoderAdapterSetCallbackDecFunc =
    int32_t (*)(struct _ark_audio_codec_decoder_adapter_t* self,
                ark_audio_decoder_callback_adapter_t* callback);
static ArkAudioCodecDecoderAdapterSetCallbackDecFunc
    ark_audio_codec_decoder_adapter_set_callback_dec =
        reinterpret_cast<ArkAudioCodecDecoderAdapterSetCallbackDecFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAudioCodecDecoderAdapterSetDecryptionConfigFunc =
    int32_t (*)(struct _ark_audio_codec_decoder_adapter_t* self,
                void* session,
                bool secureAudio);
static ArkAudioCodecDecoderAdapterSetDecryptionConfigFunc
    ark_audio_codec_decoder_adapter_set_decryption_config =
        reinterpret_cast<ArkAudioCodecDecoderAdapterSetDecryptionConfigFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCodecDecoderAdapterCToCpp::CreateAudioDecoderByMime(
    const ArkWebString& mimetype) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_codec_decoder_adapter_create_audio_decoder_by_mime);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "xmAmCCGk1HNu8jrpt_RZ3Q";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_codec_decoder_adapter_create_audio_decoder_by_mime");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_audio_decoder_by_mime)) {
        ark_audio_codec_decoder_adapter_create_audio_decoder_by_mime = nullptr;
      } else {
        ark_audio_codec_decoder_adapter_create_audio_decoder_by_mime =
            _struct->create_audio_decoder_by_mime;
      }
    } else {
      ark_audio_codec_decoder_adapter_create_audio_decoder_by_mime =
          reinterpret_cast<
              ArkAudioCodecDecoderAdapterCreateAudioDecoderByMimeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_codec_decoder_adapter_create_audio_decoder_by_mime, 0);

  // Execute
  return ark_audio_codec_decoder_adapter_create_audio_decoder_by_mime(
      _struct, &mimetype);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCodecDecoderAdapterCToCpp::CreateAudioDecoderByName(
    const ArkWebString& name) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_codec_decoder_adapter_create_audio_decoder_by_name);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "G$wtTIm1KYGZxP66RBpUDA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_codec_decoder_adapter_create_audio_decoder_by_name");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_audio_decoder_by_name)) {
        ark_audio_codec_decoder_adapter_create_audio_decoder_by_name = nullptr;
      } else {
        ark_audio_codec_decoder_adapter_create_audio_decoder_by_name =
            _struct->create_audio_decoder_by_name;
      }
    } else {
      ark_audio_codec_decoder_adapter_create_audio_decoder_by_name =
          reinterpret_cast<
              ArkAudioCodecDecoderAdapterCreateAudioDecoderByNameFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_codec_decoder_adapter_create_audio_decoder_by_name, 0);

  // Execute
  return ark_audio_codec_decoder_adapter_create_audio_decoder_by_name(_struct,
                                                                      &name);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCodecDecoderAdapterCToCpp::ConfigureDecoder(
    const ArkWebRefPtr<ArkAudioDecoderFormatAdapter> format) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_codec_decoder_adapter_configure_decoder);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "kH72y1htVzDbG$hOiaz_tg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_codec_decoder_adapter_configure_decoder");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, configure_decoder)) {
        ark_audio_codec_decoder_adapter_configure_decoder = nullptr;
      } else {
        ark_audio_codec_decoder_adapter_configure_decoder =
            _struct->configure_decoder;
      }
    } else {
      ark_audio_codec_decoder_adapter_configure_decoder =
          reinterpret_cast<ArkAudioCodecDecoderAdapterConfigureDecoderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_codec_decoder_adapter_configure_decoder, 0);

  // Execute
  return ark_audio_codec_decoder_adapter_configure_decoder(
      _struct, ArkAudioDecoderFormatAdapterCppToC::Invert(format));
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCodecDecoderAdapterCToCpp::SetParameterDecoder(
    const ArkWebRefPtr<ArkAudioDecoderFormatAdapter> format) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_codec_decoder_adapter_set_parameter_decoder);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "GFsV9GiHAY1oVQ7_uoxBgg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_codec_decoder_adapter_set_parameter_decoder");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_parameter_decoder)) {
        ark_audio_codec_decoder_adapter_set_parameter_decoder = nullptr;
      } else {
        ark_audio_codec_decoder_adapter_set_parameter_decoder =
            _struct->set_parameter_decoder;
      }
    } else {
      ark_audio_codec_decoder_adapter_set_parameter_decoder =
          reinterpret_cast<ArkAudioCodecDecoderAdapterSetParameterDecoderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_codec_decoder_adapter_set_parameter_decoder, 0);

  // Execute
  return ark_audio_codec_decoder_adapter_set_parameter_decoder(
      _struct, ArkAudioDecoderFormatAdapterCppToC::Invert(format));
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCodecDecoderAdapterCToCpp::PrepareDecoder() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_codec_decoder_adapter_prepare_decoder);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "vWBvz$AlytDCmpotd2lKEg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_codec_decoder_adapter_prepare_decoder");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, prepare_decoder)) {
        ark_audio_codec_decoder_adapter_prepare_decoder = nullptr;
      } else {
        ark_audio_codec_decoder_adapter_prepare_decoder =
            _struct->prepare_decoder;
      }
    } else {
      ark_audio_codec_decoder_adapter_prepare_decoder =
          reinterpret_cast<ArkAudioCodecDecoderAdapterPrepareDecoderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_codec_decoder_adapter_prepare_decoder, 0);

  // Execute
  return ark_audio_codec_decoder_adapter_prepare_decoder(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCodecDecoderAdapterCToCpp::StartDecoder() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_codec_decoder_adapter_start_decoder);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jCm6dvq8iHBJeAPC4ovxKA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_codec_decoder_adapter_start_decoder");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start_decoder)) {
        ark_audio_codec_decoder_adapter_start_decoder = nullptr;
      } else {
        ark_audio_codec_decoder_adapter_start_decoder = _struct->start_decoder;
      }
    } else {
      ark_audio_codec_decoder_adapter_start_decoder =
          reinterpret_cast<ArkAudioCodecDecoderAdapterStartDecoderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_codec_decoder_adapter_start_decoder, 0);

  // Execute
  return ark_audio_codec_decoder_adapter_start_decoder(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCodecDecoderAdapterCToCpp::StopDecoder() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_codec_decoder_adapter_stop_decoder);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "i8s1ouAyEz6Hg2YTS_8fng";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_codec_decoder_adapter_stop_decoder");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, stop_decoder)) {
        ark_audio_codec_decoder_adapter_stop_decoder = nullptr;
      } else {
        ark_audio_codec_decoder_adapter_stop_decoder = _struct->stop_decoder;
      }
    } else {
      ark_audio_codec_decoder_adapter_stop_decoder =
          reinterpret_cast<ArkAudioCodecDecoderAdapterStopDecoderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_codec_decoder_adapter_stop_decoder, 0);

  // Execute
  return ark_audio_codec_decoder_adapter_stop_decoder(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCodecDecoderAdapterCToCpp::FlushDecoder() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_codec_decoder_adapter_flush_decoder);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "vF1glWmhXz16gbrDiIxXtQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_codec_decoder_adapter_flush_decoder");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, flush_decoder)) {
        ark_audio_codec_decoder_adapter_flush_decoder = nullptr;
      } else {
        ark_audio_codec_decoder_adapter_flush_decoder = _struct->flush_decoder;
      }
    } else {
      ark_audio_codec_decoder_adapter_flush_decoder =
          reinterpret_cast<ArkAudioCodecDecoderAdapterFlushDecoderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_codec_decoder_adapter_flush_decoder, 0);

  // Execute
  return ark_audio_codec_decoder_adapter_flush_decoder(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCodecDecoderAdapterCToCpp::ResetDecoder() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_codec_decoder_adapter_reset_decoder);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "qt0$E6j8WIrZniKnfJdrHA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_codec_decoder_adapter_reset_decoder");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, reset_decoder)) {
        ark_audio_codec_decoder_adapter_reset_decoder = nullptr;
      } else {
        ark_audio_codec_decoder_adapter_reset_decoder = _struct->reset_decoder;
      }
    } else {
      ark_audio_codec_decoder_adapter_reset_decoder =
          reinterpret_cast<ArkAudioCodecDecoderAdapterResetDecoderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_codec_decoder_adapter_reset_decoder, 0);

  // Execute
  return ark_audio_codec_decoder_adapter_reset_decoder(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCodecDecoderAdapterCToCpp::ReleaseDecoder() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_codec_decoder_adapter_release_decoder);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "y2Bb9x_r48CjtlFeHcMfww";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_codec_decoder_adapter_release_decoder");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release_decoder)) {
        ark_audio_codec_decoder_adapter_release_decoder = nullptr;
      } else {
        ark_audio_codec_decoder_adapter_release_decoder =
            _struct->release_decoder;
      }
    } else {
      ark_audio_codec_decoder_adapter_release_decoder =
          reinterpret_cast<ArkAudioCodecDecoderAdapterReleaseDecoderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_codec_decoder_adapter_release_decoder, 0);

  // Execute
  return ark_audio_codec_decoder_adapter_release_decoder(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCodecDecoderAdapterCToCpp::QueueInputBufferDec(
    uint32_t index,
    int64_t presentationTimeUs,
    uint8_t* bufferData,
    int32_t bufferSize,
    const ArkWebRefPtr<ArkAudioCencInfoAdapter> cencInfo,
    bool isEncrypted,
    uint32_t flag) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_codec_decoder_adapter_queue_input_buffer_dec);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "dL_sllJdUxMdsql0anfc6A";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_codec_decoder_adapter_queue_input_buffer_dec");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, queue_input_buffer_dec)) {
        ark_audio_codec_decoder_adapter_queue_input_buffer_dec = nullptr;
      } else {
        ark_audio_codec_decoder_adapter_queue_input_buffer_dec =
            _struct->queue_input_buffer_dec;
      }
    } else {
      ark_audio_codec_decoder_adapter_queue_input_buffer_dec =
          reinterpret_cast<ArkAudioCodecDecoderAdapterQueueInputBufferDecFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_codec_decoder_adapter_queue_input_buffer_dec, 0);

  // Execute
  return ark_audio_codec_decoder_adapter_queue_input_buffer_dec(
      _struct, index, presentationTimeUs, bufferData, bufferSize,
      ArkAudioCencInfoAdapterCppToC::Invert(cencInfo), isEncrypted, flag);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCodecDecoderAdapterCToCpp::GetOutputFormatDec(
    ArkWebRefPtr<ArkAudioDecoderFormatAdapter> format) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_codec_decoder_adapter_get_output_format_dec);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "AFasWjaByiU2S2rJ4fyyHg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_codec_decoder_adapter_get_output_format_dec");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_output_format_dec)) {
        ark_audio_codec_decoder_adapter_get_output_format_dec = nullptr;
      } else {
        ark_audio_codec_decoder_adapter_get_output_format_dec =
            _struct->get_output_format_dec;
      }
    } else {
      ark_audio_codec_decoder_adapter_get_output_format_dec =
          reinterpret_cast<ArkAudioCodecDecoderAdapterGetOutputFormatDecFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_codec_decoder_adapter_get_output_format_dec, 0);

  // Execute
  return ark_audio_codec_decoder_adapter_get_output_format_dec(
      _struct, ArkAudioDecoderFormatAdapterCppToC::Invert(format));
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCodecDecoderAdapterCToCpp::ReleaseOutputBufferDec(
    uint32_t index) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_codec_decoder_adapter_release_output_buffer_dec);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "$xdZK2KqGy_ud8rsgKZF_Q";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_codec_decoder_adapter_release_output_buffer_dec");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release_output_buffer_dec)) {
        ark_audio_codec_decoder_adapter_release_output_buffer_dec = nullptr;
      } else {
        ark_audio_codec_decoder_adapter_release_output_buffer_dec =
            _struct->release_output_buffer_dec;
      }
    } else {
      ark_audio_codec_decoder_adapter_release_output_buffer_dec =
          reinterpret_cast<
              ArkAudioCodecDecoderAdapterReleaseOutputBufferDecFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_codec_decoder_adapter_release_output_buffer_dec, 0);

  // Execute
  return ark_audio_codec_decoder_adapter_release_output_buffer_dec(_struct,
                                                                   index);
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCodecDecoderAdapterCToCpp::SetCallbackDec(
    const ArkWebRefPtr<ArkAudioDecoderCallbackAdapter> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_audio_codec_decoder_adapter_set_callback_dec);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "xPqgiuENZudJMDlC933jBQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_codec_decoder_adapter_set_callback_dec");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_callback_dec)) {
        ark_audio_codec_decoder_adapter_set_callback_dec = nullptr;
      } else {
        ark_audio_codec_decoder_adapter_set_callback_dec =
            _struct->set_callback_dec;
      }
    } else {
      ark_audio_codec_decoder_adapter_set_callback_dec =
          reinterpret_cast<ArkAudioCodecDecoderAdapterSetCallbackDecFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_codec_decoder_adapter_set_callback_dec, 0);

  // Execute
  return ark_audio_codec_decoder_adapter_set_callback_dec(
      _struct, ArkAudioDecoderCallbackAdapterCppToC::Invert(callback));
}

ARK_WEB_NO_SANITIZE
int32_t ArkAudioCodecDecoderAdapterCToCpp::SetDecryptionConfig(
    void* session,
    bool secureAudio) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_audio_codec_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_audio_codec_decoder_adapter_set_decryption_config);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "IacsIgkIj7SbJCVziGzLzQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AUDIO_CODEC_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_audio_codec_decoder_adapter_set_decryption_config");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_decryption_config)) {
        ark_audio_codec_decoder_adapter_set_decryption_config = nullptr;
      } else {
        ark_audio_codec_decoder_adapter_set_decryption_config =
            _struct->set_decryption_config;
      }
    } else {
      ark_audio_codec_decoder_adapter_set_decryption_config =
          reinterpret_cast<ArkAudioCodecDecoderAdapterSetDecryptionConfigFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_audio_codec_decoder_adapter_set_decryption_config, 0);

  // Execute
  return ark_audio_codec_decoder_adapter_set_decryption_config(_struct, session,
                                                               secureAudio);
}

ArkAudioCodecDecoderAdapterCToCpp::ArkAudioCodecDecoderAdapterCToCpp() {}

ArkAudioCodecDecoderAdapterCToCpp::~ArkAudioCodecDecoderAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkAudioCodecDecoderAdapterCToCpp,
                           ArkAudioCodecDecoderAdapter,
                           ark_audio_codec_decoder_adapter_t>::kBridgeType =
        ARK_AUDIO_CODEC_DECODER_ADAPTER;

}  // namespace OHOS::ArkWeb
