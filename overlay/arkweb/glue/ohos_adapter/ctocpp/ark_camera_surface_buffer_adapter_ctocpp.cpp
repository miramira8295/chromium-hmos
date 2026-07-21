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

#include "ohos_adapter/ctocpp/ark_camera_surface_buffer_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkCameraSurfaceBufferAdapterGetFileDescriptorFunc =
    int32_t (*)(struct _ark_camera_surface_buffer_adapter_t* self);
static ArkCameraSurfaceBufferAdapterGetFileDescriptorFunc
    ark_camera_surface_buffer_adapter_get_file_descriptor =
        reinterpret_cast<ArkCameraSurfaceBufferAdapterGetFileDescriptorFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraSurfaceBufferAdapterGetWidthFunc =
    int32_t (*)(struct _ark_camera_surface_buffer_adapter_t* self);
static ArkCameraSurfaceBufferAdapterGetWidthFunc
    ark_camera_surface_buffer_adapter_get_width =
        reinterpret_cast<ArkCameraSurfaceBufferAdapterGetWidthFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraSurfaceBufferAdapterGetHeightFunc =
    int32_t (*)(struct _ark_camera_surface_buffer_adapter_t* self);
static ArkCameraSurfaceBufferAdapterGetHeightFunc
    ark_camera_surface_buffer_adapter_get_height =
        reinterpret_cast<ArkCameraSurfaceBufferAdapterGetHeightFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraSurfaceBufferAdapterGetStrideFunc =
    int32_t (*)(struct _ark_camera_surface_buffer_adapter_t* self);
static ArkCameraSurfaceBufferAdapterGetStrideFunc
    ark_camera_surface_buffer_adapter_get_stride =
        reinterpret_cast<ArkCameraSurfaceBufferAdapterGetStrideFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraSurfaceBufferAdapterGetFormatFunc =
    int32_t (*)(struct _ark_camera_surface_buffer_adapter_t* self);
static ArkCameraSurfaceBufferAdapterGetFormatFunc
    ark_camera_surface_buffer_adapter_get_format =
        reinterpret_cast<ArkCameraSurfaceBufferAdapterGetFormatFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraSurfaceBufferAdapterGetSizeFunc =
    uint32_t (*)(struct _ark_camera_surface_buffer_adapter_t* self);
static ArkCameraSurfaceBufferAdapterGetSizeFunc
    ark_camera_surface_buffer_adapter_get_size =
        reinterpret_cast<ArkCameraSurfaceBufferAdapterGetSizeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCameraSurfaceBufferAdapterGetBufferAddrFunc =
    uint8_t* (*)(struct _ark_camera_surface_buffer_adapter_t* self);
static ArkCameraSurfaceBufferAdapterGetBufferAddrFunc
    ark_camera_surface_buffer_adapter_get_buffer_addr =
        reinterpret_cast<ArkCameraSurfaceBufferAdapterGetBufferAddrFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkCameraSurfaceBufferAdapterCToCpp::GetFileDescriptor() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_surface_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_camera_surface_buffer_adapter_get_file_descriptor);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "QnnwFzdUDoDJmGD4xjXEpw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_CAMERA_SURFACE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_surface_buffer_adapter_get_file_descriptor");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_file_descriptor)) {
        ark_camera_surface_buffer_adapter_get_file_descriptor = nullptr;
      } else {
        ark_camera_surface_buffer_adapter_get_file_descriptor =
            _struct->get_file_descriptor;
      }
    } else {
      ark_camera_surface_buffer_adapter_get_file_descriptor =
          reinterpret_cast<ArkCameraSurfaceBufferAdapterGetFileDescriptorFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_camera_surface_buffer_adapter_get_file_descriptor, 0);

  // Execute
  return ark_camera_surface_buffer_adapter_get_file_descriptor(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCameraSurfaceBufferAdapterCToCpp::GetWidth() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_surface_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_surface_buffer_adapter_get_width);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "1hFO6HhomhlxqLi20iZvQg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_CAMERA_SURFACE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_surface_buffer_adapter_get_width");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_width)) {
        ark_camera_surface_buffer_adapter_get_width = nullptr;
      } else {
        ark_camera_surface_buffer_adapter_get_width = _struct->get_width;
      }
    } else {
      ark_camera_surface_buffer_adapter_get_width =
          reinterpret_cast<ArkCameraSurfaceBufferAdapterGetWidthFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_camera_surface_buffer_adapter_get_width,
                                    0);

  // Execute
  return ark_camera_surface_buffer_adapter_get_width(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCameraSurfaceBufferAdapterCToCpp::GetHeight() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_surface_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_surface_buffer_adapter_get_height);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "0gbH_Bkb6mktOJ5U8rz25g";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_CAMERA_SURFACE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_surface_buffer_adapter_get_height");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_height)) {
        ark_camera_surface_buffer_adapter_get_height = nullptr;
      } else {
        ark_camera_surface_buffer_adapter_get_height = _struct->get_height;
      }
    } else {
      ark_camera_surface_buffer_adapter_get_height =
          reinterpret_cast<ArkCameraSurfaceBufferAdapterGetHeightFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_camera_surface_buffer_adapter_get_height, 0);

  // Execute
  return ark_camera_surface_buffer_adapter_get_height(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCameraSurfaceBufferAdapterCToCpp::GetStride() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_surface_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_surface_buffer_adapter_get_stride);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "hE2fdPEiGFh8X9xP3bcGkg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_CAMERA_SURFACE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_surface_buffer_adapter_get_stride");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_stride)) {
        ark_camera_surface_buffer_adapter_get_stride = nullptr;
      } else {
        ark_camera_surface_buffer_adapter_get_stride = _struct->get_stride;
      }
    } else {
      ark_camera_surface_buffer_adapter_get_stride =
          reinterpret_cast<ArkCameraSurfaceBufferAdapterGetStrideFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_camera_surface_buffer_adapter_get_stride, 0);

  // Execute
  return ark_camera_surface_buffer_adapter_get_stride(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCameraSurfaceBufferAdapterCToCpp::GetFormat() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_surface_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_surface_buffer_adapter_get_format);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Dn12j3Fcbx4My53PbCZhtQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_CAMERA_SURFACE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_surface_buffer_adapter_get_format");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_format)) {
        ark_camera_surface_buffer_adapter_get_format = nullptr;
      } else {
        ark_camera_surface_buffer_adapter_get_format = _struct->get_format;
      }
    } else {
      ark_camera_surface_buffer_adapter_get_format =
          reinterpret_cast<ArkCameraSurfaceBufferAdapterGetFormatFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_camera_surface_buffer_adapter_get_format, 0);

  // Execute
  return ark_camera_surface_buffer_adapter_get_format(_struct);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkCameraSurfaceBufferAdapterCToCpp::GetSize() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_surface_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_surface_buffer_adapter_get_size);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Ts$Cyo_NH6zsl2DSBteX6g";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_CAMERA_SURFACE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_surface_buffer_adapter_get_size");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_size)) {
        ark_camera_surface_buffer_adapter_get_size = nullptr;
      } else {
        ark_camera_surface_buffer_adapter_get_size = _struct->get_size;
      }
    } else {
      ark_camera_surface_buffer_adapter_get_size =
          reinterpret_cast<ArkCameraSurfaceBufferAdapterGetSizeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_camera_surface_buffer_adapter_get_size,
                                    0);

  // Execute
  return ark_camera_surface_buffer_adapter_get_size(_struct);
}

ARK_WEB_NO_SANITIZE
uint8_t* ArkCameraSurfaceBufferAdapterCToCpp::GetBufferAddr() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_surface_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_camera_surface_buffer_adapter_get_buffer_addr);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "yATWMQ_7u3vXjJvi5OgGcA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_CAMERA_SURFACE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_surface_buffer_adapter_get_buffer_addr");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_buffer_addr)) {
        ark_camera_surface_buffer_adapter_get_buffer_addr = nullptr;
      } else {
        ark_camera_surface_buffer_adapter_get_buffer_addr =
            _struct->get_buffer_addr;
      }
    } else {
      ark_camera_surface_buffer_adapter_get_buffer_addr =
          reinterpret_cast<ArkCameraSurfaceBufferAdapterGetBufferAddrFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_camera_surface_buffer_adapter_get_buffer_addr, nullptr);

  // Execute
  return ark_camera_surface_buffer_adapter_get_buffer_addr(_struct);
}

ArkCameraSurfaceBufferAdapterCToCpp::ArkCameraSurfaceBufferAdapterCToCpp() {}

ArkCameraSurfaceBufferAdapterCToCpp::~ArkCameraSurfaceBufferAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkCameraSurfaceBufferAdapterCToCpp,
                           ArkCameraSurfaceBufferAdapter,
                           ark_camera_surface_buffer_adapter_t>::kBridgeType =
        ARK_CAMERA_SURFACE_BUFFER_ADAPTER;

}  // namespace OHOS::ArkWeb
