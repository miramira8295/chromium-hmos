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

#include "ohos_adapter/ctocpp/ark_surface_buffer_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkSurfaceBufferAdapterGetFileDescriptorFunc =
    int32_t (*)(struct _ark_surface_buffer_adapter_t* self);
static ArkSurfaceBufferAdapterGetFileDescriptorFunc
    ark_surface_buffer_adapter_get_file_descriptor =
        reinterpret_cast<ArkSurfaceBufferAdapterGetFileDescriptorFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSurfaceBufferAdapterGetWidthFunc =
    int32_t (*)(struct _ark_surface_buffer_adapter_t* self);
static ArkSurfaceBufferAdapterGetWidthFunc
    ark_surface_buffer_adapter_get_width =
        reinterpret_cast<ArkSurfaceBufferAdapterGetWidthFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSurfaceBufferAdapterGetHeightFunc =
    int32_t (*)(struct _ark_surface_buffer_adapter_t* self);
static ArkSurfaceBufferAdapterGetHeightFunc
    ark_surface_buffer_adapter_get_height =
        reinterpret_cast<ArkSurfaceBufferAdapterGetHeightFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSurfaceBufferAdapterGetStrideFunc =
    int32_t (*)(struct _ark_surface_buffer_adapter_t* self);
static ArkSurfaceBufferAdapterGetStrideFunc
    ark_surface_buffer_adapter_get_stride =
        reinterpret_cast<ArkSurfaceBufferAdapterGetStrideFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSurfaceBufferAdapterGetFormatFunc =
    int32_t (*)(struct _ark_surface_buffer_adapter_t* self);
static ArkSurfaceBufferAdapterGetFormatFunc
    ark_surface_buffer_adapter_get_format =
        reinterpret_cast<ArkSurfaceBufferAdapterGetFormatFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSurfaceBufferAdapterGetSizeFunc =
    uint32_t (*)(struct _ark_surface_buffer_adapter_t* self);
static ArkSurfaceBufferAdapterGetSizeFunc ark_surface_buffer_adapter_get_size =
    reinterpret_cast<ArkSurfaceBufferAdapterGetSizeFunc>(ARK_WEB_INIT_ADDR);

using ArkSurfaceBufferAdapterGetVirAddrFunc =
    void* (*)(struct _ark_surface_buffer_adapter_t* self);
static ArkSurfaceBufferAdapterGetVirAddrFunc
    ark_surface_buffer_adapter_get_vir_addr =
        reinterpret_cast<ArkSurfaceBufferAdapterGetVirAddrFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkSurfaceBufferAdapterCToCpp::GetFileDescriptor() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_surface_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_surface_buffer_adapter_get_file_descriptor);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "_XabS_5lVV5WkP3y9bBOvw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SURFACE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_surface_buffer_adapter_get_file_descriptor");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_file_descriptor)) {
        ark_surface_buffer_adapter_get_file_descriptor = nullptr;
      } else {
        ark_surface_buffer_adapter_get_file_descriptor =
            _struct->get_file_descriptor;
      }
    } else {
      ark_surface_buffer_adapter_get_file_descriptor =
          reinterpret_cast<ArkSurfaceBufferAdapterGetFileDescriptorFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_surface_buffer_adapter_get_file_descriptor, 0);

  // Execute
  return ark_surface_buffer_adapter_get_file_descriptor(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkSurfaceBufferAdapterCToCpp::GetWidth() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_surface_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_surface_buffer_adapter_get_width);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "E2frXVaLwsmbQ85WgIcpew";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SURFACE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_surface_buffer_adapter_get_width");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_width)) {
        ark_surface_buffer_adapter_get_width = nullptr;
      } else {
        ark_surface_buffer_adapter_get_width = _struct->get_width;
      }
    } else {
      ark_surface_buffer_adapter_get_width =
          reinterpret_cast<ArkSurfaceBufferAdapterGetWidthFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_surface_buffer_adapter_get_width, 0);

  // Execute
  return ark_surface_buffer_adapter_get_width(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkSurfaceBufferAdapterCToCpp::GetHeight() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_surface_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_surface_buffer_adapter_get_height);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "9YI2fjECXUauD4hxNiVhKQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SURFACE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_surface_buffer_adapter_get_height");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_height)) {
        ark_surface_buffer_adapter_get_height = nullptr;
      } else {
        ark_surface_buffer_adapter_get_height = _struct->get_height;
      }
    } else {
      ark_surface_buffer_adapter_get_height =
          reinterpret_cast<ArkSurfaceBufferAdapterGetHeightFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_surface_buffer_adapter_get_height, 0);

  // Execute
  return ark_surface_buffer_adapter_get_height(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkSurfaceBufferAdapterCToCpp::GetStride() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_surface_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_surface_buffer_adapter_get_stride);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Izk8LS3Wr5SCbtSrCLAvOA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SURFACE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_surface_buffer_adapter_get_stride");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_stride)) {
        ark_surface_buffer_adapter_get_stride = nullptr;
      } else {
        ark_surface_buffer_adapter_get_stride = _struct->get_stride;
      }
    } else {
      ark_surface_buffer_adapter_get_stride =
          reinterpret_cast<ArkSurfaceBufferAdapterGetStrideFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_surface_buffer_adapter_get_stride, 0);

  // Execute
  return ark_surface_buffer_adapter_get_stride(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkSurfaceBufferAdapterCToCpp::GetFormat() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_surface_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_surface_buffer_adapter_get_format);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "yvPRGJF9Sq1pXdEDHs86vg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SURFACE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_surface_buffer_adapter_get_format");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_format)) {
        ark_surface_buffer_adapter_get_format = nullptr;
      } else {
        ark_surface_buffer_adapter_get_format = _struct->get_format;
      }
    } else {
      ark_surface_buffer_adapter_get_format =
          reinterpret_cast<ArkSurfaceBufferAdapterGetFormatFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_surface_buffer_adapter_get_format, 0);

  // Execute
  return ark_surface_buffer_adapter_get_format(_struct);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkSurfaceBufferAdapterCToCpp::GetSize() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_surface_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_surface_buffer_adapter_get_size);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "BMhAvhbQ80tOiDoCclSF0g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SURFACE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_surface_buffer_adapter_get_size");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_size)) {
        ark_surface_buffer_adapter_get_size = nullptr;
      } else {
        ark_surface_buffer_adapter_get_size = _struct->get_size;
      }
    } else {
      ark_surface_buffer_adapter_get_size =
          reinterpret_cast<ArkSurfaceBufferAdapterGetSizeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_surface_buffer_adapter_get_size, 0);

  // Execute
  return ark_surface_buffer_adapter_get_size(_struct);
}

ARK_WEB_NO_SANITIZE
void* ArkSurfaceBufferAdapterCToCpp::GetVirAddr() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_surface_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_surface_buffer_adapter_get_vir_addr);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "O9OlBKS4QjB09Wc$8yA5$w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SURFACE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_surface_buffer_adapter_get_vir_addr");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_vir_addr)) {
        ark_surface_buffer_adapter_get_vir_addr = nullptr;
      } else {
        ark_surface_buffer_adapter_get_vir_addr = _struct->get_vir_addr;
      }
    } else {
      ark_surface_buffer_adapter_get_vir_addr =
          reinterpret_cast<ArkSurfaceBufferAdapterGetVirAddrFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_surface_buffer_adapter_get_vir_addr,
                                    nullptr);

  // Execute
  return ark_surface_buffer_adapter_get_vir_addr(_struct);
}

ArkSurfaceBufferAdapterCToCpp::ArkSurfaceBufferAdapterCToCpp() {}

ArkSurfaceBufferAdapterCToCpp::~ArkSurfaceBufferAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkSurfaceBufferAdapterCToCpp,
                           ArkSurfaceBufferAdapter,
                           ark_surface_buffer_adapter_t>::kBridgeType =
        ARK_SURFACE_BUFFER_ADAPTER;

}  // namespace OHOS::ArkWeb
