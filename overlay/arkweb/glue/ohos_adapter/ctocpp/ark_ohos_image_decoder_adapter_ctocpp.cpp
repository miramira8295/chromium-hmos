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

#include "ohos_adapter/ctocpp/ark_ohos_image_decoder_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkOhosImageDecoderAdapterParseImageInfoFunc =
    bool (*)(struct _ark_ohos_image_decoder_adapter_t* self,
             const uint8_t* data,
             uint32_t size);
static ArkOhosImageDecoderAdapterParseImageInfoFunc
    ark_ohos_image_decoder_adapter_parse_image_info =
        reinterpret_cast<ArkOhosImageDecoderAdapterParseImageInfoFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosImageDecoderAdapterGetEncodedFormatFunc =
    ArkWebString (*)(struct _ark_ohos_image_decoder_adapter_t* self);
static ArkOhosImageDecoderAdapterGetEncodedFormatFunc
    ark_ohos_image_decoder_adapter_get_encoded_format =
        reinterpret_cast<ArkOhosImageDecoderAdapterGetEncodedFormatFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosImageDecoderAdapterGetImageWidthFunc =
    int32_t (*)(struct _ark_ohos_image_decoder_adapter_t* self);
static ArkOhosImageDecoderAdapterGetImageWidthFunc
    ark_ohos_image_decoder_adapter_get_image_width =
        reinterpret_cast<ArkOhosImageDecoderAdapterGetImageWidthFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosImageDecoderAdapterGetImageHeightFunc =
    int32_t (*)(struct _ark_ohos_image_decoder_adapter_t* self);
static ArkOhosImageDecoderAdapterGetImageHeightFunc
    ark_ohos_image_decoder_adapter_get_image_height =
        reinterpret_cast<ArkOhosImageDecoderAdapterGetImageHeightFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosImageDecoderAdapterDecodeToPixelMapFunc =
    bool (*)(struct _ark_ohos_image_decoder_adapter_t* self,
             const uint8_t* data,
             uint32_t size);
static ArkOhosImageDecoderAdapterDecodeToPixelMapFunc
    ark_ohos_image_decoder_adapter_decode_to_pixel_map =
        reinterpret_cast<ArkOhosImageDecoderAdapterDecodeToPixelMapFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosImageDecoderAdapterGetFdFunc =
    int32_t (*)(struct _ark_ohos_image_decoder_adapter_t* self);
static ArkOhosImageDecoderAdapterGetFdFunc
    ark_ohos_image_decoder_adapter_get_fd =
        reinterpret_cast<ArkOhosImageDecoderAdapterGetFdFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosImageDecoderAdapterGetStrideFunc =
    int32_t (*)(struct _ark_ohos_image_decoder_adapter_t* self);
static ArkOhosImageDecoderAdapterGetStrideFunc
    ark_ohos_image_decoder_adapter_get_stride =
        reinterpret_cast<ArkOhosImageDecoderAdapterGetStrideFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosImageDecoderAdapterGetOffsetFunc =
    int32_t (*)(struct _ark_ohos_image_decoder_adapter_t* self);
static ArkOhosImageDecoderAdapterGetOffsetFunc
    ark_ohos_image_decoder_adapter_get_offset =
        reinterpret_cast<ArkOhosImageDecoderAdapterGetOffsetFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosImageDecoderAdapterGetSizeFunc =
    uint64_t (*)(struct _ark_ohos_image_decoder_adapter_t* self);
static ArkOhosImageDecoderAdapterGetSizeFunc
    ark_ohos_image_decoder_adapter_get_size =
        reinterpret_cast<ArkOhosImageDecoderAdapterGetSizeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosImageDecoderAdapterGetNativeWindowBufferFunc =
    void* (*)(struct _ark_ohos_image_decoder_adapter_t* self);
static ArkOhosImageDecoderAdapterGetNativeWindowBufferFunc
    ark_ohos_image_decoder_adapter_get_native_window_buffer =
        reinterpret_cast<ArkOhosImageDecoderAdapterGetNativeWindowBufferFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosImageDecoderAdapterGetPlanesCountFunc =
    int32_t (*)(struct _ark_ohos_image_decoder_adapter_t* self);
static ArkOhosImageDecoderAdapterGetPlanesCountFunc
    ark_ohos_image_decoder_adapter_get_planes_count =
        reinterpret_cast<ArkOhosImageDecoderAdapterGetPlanesCountFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosImageDecoderAdapterReleasePixelMapFunc =
    void (*)(struct _ark_ohos_image_decoder_adapter_t* self);
static ArkOhosImageDecoderAdapterReleasePixelMapFunc
    ark_ohos_image_decoder_adapter_release_pixel_map =
        reinterpret_cast<ArkOhosImageDecoderAdapterReleasePixelMapFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosImageDecoderAdapterDecodeFunc =
    bool (*)(struct _ark_ohos_image_decoder_adapter_t* self,
             const uint8_t* data,
             uint32_t size,
             uint32_t type,
             bool useYuv);
static ArkOhosImageDecoderAdapterDecodeFunc
    ark_ohos_image_decoder_adapter_decode =
        reinterpret_cast<ArkOhosImageDecoderAdapterDecodeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosImageDecoderAdapterGetDecodeDataFunc =
    void* (*)(struct _ark_ohos_image_decoder_adapter_t* self);
static ArkOhosImageDecoderAdapterGetDecodeDataFunc
    ark_ohos_image_decoder_adapter_get_decode_data =
        reinterpret_cast<ArkOhosImageDecoderAdapterGetDecodeDataFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
bool ArkOhosImageDecoderAdapterCToCpp::ParseImageInfo(const uint8_t* data,
                                                      uint32_t size) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_image_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_image_decoder_adapter_parse_image_info);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ewGlQ4a6y12tVA6DKhOL5w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_IMAGE_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_image_decoder_adapter_parse_image_info");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, parse_image_info)) {
        ark_ohos_image_decoder_adapter_parse_image_info = nullptr;
      } else {
        ark_ohos_image_decoder_adapter_parse_image_info =
            _struct->parse_image_info;
      }
    } else {
      ark_ohos_image_decoder_adapter_parse_image_info =
          reinterpret_cast<ArkOhosImageDecoderAdapterParseImageInfoFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_image_decoder_adapter_parse_image_info, false);

  // Execute
  return ark_ohos_image_decoder_adapter_parse_image_info(_struct, data, size);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkOhosImageDecoderAdapterCToCpp::GetEncodedFormat() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_image_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_image_decoder_adapter_get_encoded_format);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "n5fRDW7CRGvYCxZAu1OtAw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_IMAGE_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_image_decoder_adapter_get_encoded_format");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_encoded_format)) {
        ark_ohos_image_decoder_adapter_get_encoded_format = nullptr;
      } else {
        ark_ohos_image_decoder_adapter_get_encoded_format =
            _struct->get_encoded_format;
      }
    } else {
      ark_ohos_image_decoder_adapter_get_encoded_format =
          reinterpret_cast<ArkOhosImageDecoderAdapterGetEncodedFormatFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_image_decoder_adapter_get_encoded_format,
      ark_web_string_default);

  // Execute
  return ark_ohos_image_decoder_adapter_get_encoded_format(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkOhosImageDecoderAdapterCToCpp::GetImageWidth() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_image_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_image_decoder_adapter_get_image_width);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "EBtMn5wDDU2kz9WaBORSlA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_IMAGE_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_image_decoder_adapter_get_image_width");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_image_width)) {
        ark_ohos_image_decoder_adapter_get_image_width = nullptr;
      } else {
        ark_ohos_image_decoder_adapter_get_image_width =
            _struct->get_image_width;
      }
    } else {
      ark_ohos_image_decoder_adapter_get_image_width =
          reinterpret_cast<ArkOhosImageDecoderAdapterGetImageWidthFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_image_decoder_adapter_get_image_width, 0);

  // Execute
  return ark_ohos_image_decoder_adapter_get_image_width(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkOhosImageDecoderAdapterCToCpp::GetImageHeight() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_image_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_image_decoder_adapter_get_image_height);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "tvbch4ibs6M6_fONOqe0JQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_IMAGE_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_image_decoder_adapter_get_image_height");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_image_height)) {
        ark_ohos_image_decoder_adapter_get_image_height = nullptr;
      } else {
        ark_ohos_image_decoder_adapter_get_image_height =
            _struct->get_image_height;
      }
    } else {
      ark_ohos_image_decoder_adapter_get_image_height =
          reinterpret_cast<ArkOhosImageDecoderAdapterGetImageHeightFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_image_decoder_adapter_get_image_height, 0);

  // Execute
  return ark_ohos_image_decoder_adapter_get_image_height(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkOhosImageDecoderAdapterCToCpp::DecodeToPixelMap(const uint8_t* data,
                                                        uint32_t size) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_image_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_image_decoder_adapter_decode_to_pixel_map);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "havzobxneAtVsYO9rKGh1w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_IMAGE_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_image_decoder_adapter_decode_to_pixel_map");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, decode_to_pixel_map)) {
        ark_ohos_image_decoder_adapter_decode_to_pixel_map = nullptr;
      } else {
        ark_ohos_image_decoder_adapter_decode_to_pixel_map =
            _struct->decode_to_pixel_map;
      }
    } else {
      ark_ohos_image_decoder_adapter_decode_to_pixel_map =
          reinterpret_cast<ArkOhosImageDecoderAdapterDecodeToPixelMapFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_image_decoder_adapter_decode_to_pixel_map, false);

  // Execute
  return ark_ohos_image_decoder_adapter_decode_to_pixel_map(_struct, data,
                                                            size);
}

ARK_WEB_NO_SANITIZE
int32_t ArkOhosImageDecoderAdapterCToCpp::GetFd() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_image_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_image_decoder_adapter_get_fd);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "APoQ70fwb3mynBtmAOd80A";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_IMAGE_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_image_decoder_adapter_get_fd");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_fd)) {
        ark_ohos_image_decoder_adapter_get_fd = nullptr;
      } else {
        ark_ohos_image_decoder_adapter_get_fd = _struct->get_fd;
      }
    } else {
      ark_ohos_image_decoder_adapter_get_fd =
          reinterpret_cast<ArkOhosImageDecoderAdapterGetFdFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_image_decoder_adapter_get_fd, 0);

  // Execute
  return ark_ohos_image_decoder_adapter_get_fd(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkOhosImageDecoderAdapterCToCpp::GetStride() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_image_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_image_decoder_adapter_get_stride);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "P42zDuWcjFGFZeFOgovWBg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_IMAGE_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_image_decoder_adapter_get_stride");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_stride)) {
        ark_ohos_image_decoder_adapter_get_stride = nullptr;
      } else {
        ark_ohos_image_decoder_adapter_get_stride = _struct->get_stride;
      }
    } else {
      ark_ohos_image_decoder_adapter_get_stride =
          reinterpret_cast<ArkOhosImageDecoderAdapterGetStrideFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_image_decoder_adapter_get_stride,
                                    0);

  // Execute
  return ark_ohos_image_decoder_adapter_get_stride(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkOhosImageDecoderAdapterCToCpp::GetOffset() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_image_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_image_decoder_adapter_get_offset);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "M8AeaIIHFjCsFZ2Vf8nvUw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_IMAGE_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_image_decoder_adapter_get_offset");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_offset)) {
        ark_ohos_image_decoder_adapter_get_offset = nullptr;
      } else {
        ark_ohos_image_decoder_adapter_get_offset = _struct->get_offset;
      }
    } else {
      ark_ohos_image_decoder_adapter_get_offset =
          reinterpret_cast<ArkOhosImageDecoderAdapterGetOffsetFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_image_decoder_adapter_get_offset,
                                    0);

  // Execute
  return ark_ohos_image_decoder_adapter_get_offset(_struct);
}

ARK_WEB_NO_SANITIZE
uint64_t ArkOhosImageDecoderAdapterCToCpp::GetSize() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_image_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_image_decoder_adapter_get_size);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "aKtZFe$wfNctiWDEsbV28w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_IMAGE_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_image_decoder_adapter_get_size");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_size)) {
        ark_ohos_image_decoder_adapter_get_size = nullptr;
      } else {
        ark_ohos_image_decoder_adapter_get_size = _struct->get_size;
      }
    } else {
      ark_ohos_image_decoder_adapter_get_size =
          reinterpret_cast<ArkOhosImageDecoderAdapterGetSizeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_image_decoder_adapter_get_size, 0);

  // Execute
  return ark_ohos_image_decoder_adapter_get_size(_struct);
}

ARK_WEB_NO_SANITIZE
void* ArkOhosImageDecoderAdapterCToCpp::GetNativeWindowBuffer() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_image_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_image_decoder_adapter_get_native_window_buffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "or7MPbFx63zpHg1sU6yJ_w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_IMAGE_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_image_decoder_adapter_get_native_window_buffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_native_window_buffer)) {
        ark_ohos_image_decoder_adapter_get_native_window_buffer = nullptr;
      } else {
        ark_ohos_image_decoder_adapter_get_native_window_buffer =
            _struct->get_native_window_buffer;
      }
    } else {
      ark_ohos_image_decoder_adapter_get_native_window_buffer =
          reinterpret_cast<ArkOhosImageDecoderAdapterGetNativeWindowBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_image_decoder_adapter_get_native_window_buffer, nullptr);

  // Execute
  return ark_ohos_image_decoder_adapter_get_native_window_buffer(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkOhosImageDecoderAdapterCToCpp::GetPlanesCount() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_image_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_image_decoder_adapter_get_planes_count);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "w10Ouv4Ykp5rQatO0b4K2Q";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_IMAGE_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_image_decoder_adapter_get_planes_count");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_planes_count)) {
        ark_ohos_image_decoder_adapter_get_planes_count = nullptr;
      } else {
        ark_ohos_image_decoder_adapter_get_planes_count =
            _struct->get_planes_count;
      }
    } else {
      ark_ohos_image_decoder_adapter_get_planes_count =
          reinterpret_cast<ArkOhosImageDecoderAdapterGetPlanesCountFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_image_decoder_adapter_get_planes_count, 0);

  // Execute
  return ark_ohos_image_decoder_adapter_get_planes_count(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkOhosImageDecoderAdapterCToCpp::ReleasePixelMap() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_image_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_image_decoder_adapter_release_pixel_map);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "1WgfIUhoG1ppBxu9svw1RQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_IMAGE_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_image_decoder_adapter_release_pixel_map");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release_pixel_map)) {
        ark_ohos_image_decoder_adapter_release_pixel_map = nullptr;
      } else {
        ark_ohos_image_decoder_adapter_release_pixel_map =
            _struct->release_pixel_map;
      }
    } else {
      ark_ohos_image_decoder_adapter_release_pixel_map =
          reinterpret_cast<ArkOhosImageDecoderAdapterReleasePixelMapFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_image_decoder_adapter_release_pixel_map, ARK_WEB_RETURN_VOID);

  // Execute
  ark_ohos_image_decoder_adapter_release_pixel_map(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkOhosImageDecoderAdapterCToCpp::Decode(const uint8_t* data,
                                              uint32_t size,
                                              uint32_t type,
                                              bool useYuv) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_image_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_image_decoder_adapter_decode);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Ai007cZ1QJpx8S7ocNkCvA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_IMAGE_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_image_decoder_adapter_decode");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, decode)) {
        ark_ohos_image_decoder_adapter_decode = nullptr;
      } else {
        ark_ohos_image_decoder_adapter_decode = _struct->decode;
      }
    } else {
      ark_ohos_image_decoder_adapter_decode =
          reinterpret_cast<ArkOhosImageDecoderAdapterDecodeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_image_decoder_adapter_decode,
                                    false);

  // Execute
  return ark_ohos_image_decoder_adapter_decode(_struct, data, size, type,
                                               useYuv);
}

ARK_WEB_NO_SANITIZE
void* ArkOhosImageDecoderAdapterCToCpp::GetDecodeData() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_image_decoder_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_image_decoder_adapter_get_decode_data);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "rfX4deh_l9s5FdZuuoa$pg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_IMAGE_DECODER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_image_decoder_adapter_get_decode_data");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_decode_data)) {
        ark_ohos_image_decoder_adapter_get_decode_data = nullptr;
      } else {
        ark_ohos_image_decoder_adapter_get_decode_data =
            _struct->get_decode_data;
      }
    } else {
      ark_ohos_image_decoder_adapter_get_decode_data =
          reinterpret_cast<ArkOhosImageDecoderAdapterGetDecodeDataFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_image_decoder_adapter_get_decode_data, nullptr);

  // Execute
  return ark_ohos_image_decoder_adapter_get_decode_data(_struct);
}

ArkOhosImageDecoderAdapterCToCpp::ArkOhosImageDecoderAdapterCToCpp() {}

ArkOhosImageDecoderAdapterCToCpp::~ArkOhosImageDecoderAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkOhosImageDecoderAdapterCToCpp,
                           ArkOhosImageDecoderAdapter,
                           ark_ohos_image_decoder_adapter_t>::kBridgeType =
        ARK_OHOS_IMAGE_DECODER_ADAPTER;

}  // namespace OHOS::ArkWeb
