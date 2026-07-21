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

#include "ohos_nweb/ctocpp/ark_web_nweb_create_info_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"
#include "ohos_nweb/ctocpp/ark_web_engine_init_args_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_output_frame_callback_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkWebNWebCreateInfoGetWidthFunc =
    uint32_t (*)(struct _ark_web_nweb_create_info_t* self);
static ArkWebNWebCreateInfoGetWidthFunc ark_web_nweb_create_info_get_width =
    reinterpret_cast<ArkWebNWebCreateInfoGetWidthFunc>(ARK_WEB_INIT_ADDR);

using ArkWebNWebCreateInfoGetHeightFunc =
    uint32_t (*)(struct _ark_web_nweb_create_info_t* self);
static ArkWebNWebCreateInfoGetHeightFunc ark_web_nweb_create_info_get_height =
    reinterpret_cast<ArkWebNWebCreateInfoGetHeightFunc>(ARK_WEB_INIT_ADDR);

using ArkWebNWebCreateInfoGetIsIncognitoModeFunc =
    bool (*)(struct _ark_web_nweb_create_info_t* self);
static ArkWebNWebCreateInfoGetIsIncognitoModeFunc
    ark_web_nweb_create_info_get_is_incognito_mode =
        reinterpret_cast<ArkWebNWebCreateInfoGetIsIncognitoModeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebNWebCreateInfoGetProducerSurfaceFunc =
    void* (*)(struct _ark_web_nweb_create_info_t* self);
static ArkWebNWebCreateInfoGetProducerSurfaceFunc
    ark_web_nweb_create_info_get_producer_surface =
        reinterpret_cast<ArkWebNWebCreateInfoGetProducerSurfaceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebNWebCreateInfoGetEnhanceSurfaceInfoFunc =
    void* (*)(struct _ark_web_nweb_create_info_t* self);
static ArkWebNWebCreateInfoGetEnhanceSurfaceInfoFunc
    ark_web_nweb_create_info_get_enhance_surface_info =
        reinterpret_cast<ArkWebNWebCreateInfoGetEnhanceSurfaceInfoFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebNWebCreateInfoGetEngineInitArgsFunc =
    ark_web_engine_init_args_t* (*)(struct _ark_web_nweb_create_info_t* self);
static ArkWebNWebCreateInfoGetEngineInitArgsFunc
    ark_web_nweb_create_info_get_engine_init_args =
        reinterpret_cast<ArkWebNWebCreateInfoGetEngineInitArgsFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebNWebCreateInfoGetOutputFrameCallbackFunc =
    ark_web_output_frame_callback_t* (*)(struct _ark_web_nweb_create_info_t*
                                             self);
static ArkWebNWebCreateInfoGetOutputFrameCallbackFunc
    ark_web_nweb_create_info_get_output_frame_callback =
        reinterpret_cast<ArkWebNWebCreateInfoGetOutputFrameCallbackFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
uint32_t ArkWebNWebCreateInfoCToCpp::GetWidth() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_nweb_create_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_nweb_create_info_get_width);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "TzkuFfrP6s9K0SwRGzVPfw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NWEB_CREATE_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_nweb_create_info_get_width");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_width)) {
        ark_web_nweb_create_info_get_width = nullptr;
      } else {
        ark_web_nweb_create_info_get_width = _struct->get_width;
      }
    } else {
      ark_web_nweb_create_info_get_width =
          reinterpret_cast<ArkWebNWebCreateInfoGetWidthFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_nweb_create_info_get_width, 0);

  // Execute
  return ark_web_nweb_create_info_get_width(_struct);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkWebNWebCreateInfoCToCpp::GetHeight() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_nweb_create_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_nweb_create_info_get_height);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "gtE9Yw$dTTLXrr40iULadQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NWEB_CREATE_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_nweb_create_info_get_height");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_height)) {
        ark_web_nweb_create_info_get_height = nullptr;
      } else {
        ark_web_nweb_create_info_get_height = _struct->get_height;
      }
    } else {
      ark_web_nweb_create_info_get_height =
          reinterpret_cast<ArkWebNWebCreateInfoGetHeightFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_nweb_create_info_get_height, 0);

  // Execute
  return ark_web_nweb_create_info_get_height(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkWebNWebCreateInfoCToCpp::GetIsIncognitoMode() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_nweb_create_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_nweb_create_info_get_is_incognito_mode);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "w2mHF3EFCGicVY55I4l14A";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NWEB_CREATE_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_nweb_create_info_get_is_incognito_mode");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_is_incognito_mode)) {
        ark_web_nweb_create_info_get_is_incognito_mode = nullptr;
      } else {
        ark_web_nweb_create_info_get_is_incognito_mode =
            _struct->get_is_incognito_mode;
      }
    } else {
      ark_web_nweb_create_info_get_is_incognito_mode =
          reinterpret_cast<ArkWebNWebCreateInfoGetIsIncognitoModeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_nweb_create_info_get_is_incognito_mode, false);

  // Execute
  return ark_web_nweb_create_info_get_is_incognito_mode(_struct);
}

ARK_WEB_NO_SANITIZE
void* ArkWebNWebCreateInfoCToCpp::GetProducerSurface() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_nweb_create_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_nweb_create_info_get_producer_surface);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "yPvFatiC2UtAp9EtUjREnA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NWEB_CREATE_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_nweb_create_info_get_producer_surface");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_producer_surface)) {
        ark_web_nweb_create_info_get_producer_surface = nullptr;
      } else {
        ark_web_nweb_create_info_get_producer_surface =
            _struct->get_producer_surface;
      }
    } else {
      ark_web_nweb_create_info_get_producer_surface =
          reinterpret_cast<ArkWebNWebCreateInfoGetProducerSurfaceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_nweb_create_info_get_producer_surface, nullptr);

  // Execute
  return ark_web_nweb_create_info_get_producer_surface(_struct);
}

ARK_WEB_NO_SANITIZE
void* ArkWebNWebCreateInfoCToCpp::GetEnhanceSurfaceInfo() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_nweb_create_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_nweb_create_info_get_enhance_surface_info);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "lmM0WmXzMLb5KQEv37y5Tg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NWEB_CREATE_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_nweb_create_info_get_enhance_surface_info");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_enhance_surface_info)) {
        ark_web_nweb_create_info_get_enhance_surface_info = nullptr;
      } else {
        ark_web_nweb_create_info_get_enhance_surface_info =
            _struct->get_enhance_surface_info;
      }
    } else {
      ark_web_nweb_create_info_get_enhance_surface_info =
          reinterpret_cast<ArkWebNWebCreateInfoGetEnhanceSurfaceInfoFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_nweb_create_info_get_enhance_surface_info, nullptr);

  // Execute
  return ark_web_nweb_create_info_get_enhance_surface_info(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkWebEngineInitArgs>
ArkWebNWebCreateInfoCToCpp::GetEngineInitArgs() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_nweb_create_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_nweb_create_info_get_engine_init_args);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "xGXWGf41WZATAfFd20qGGg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NWEB_CREATE_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_nweb_create_info_get_engine_init_args");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_engine_init_args)) {
        ark_web_nweb_create_info_get_engine_init_args = nullptr;
      } else {
        ark_web_nweb_create_info_get_engine_init_args =
            _struct->get_engine_init_args;
      }
    } else {
      ark_web_nweb_create_info_get_engine_init_args =
          reinterpret_cast<ArkWebNWebCreateInfoGetEngineInitArgsFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_nweb_create_info_get_engine_init_args, nullptr);

  // Execute
  ark_web_engine_init_args_t* _retval =
      ark_web_nweb_create_info_get_engine_init_args(_struct);

  // Return type: refptr_same
  return ArkWebEngineInitArgsCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkWebOutputFrameCallback>
ArkWebNWebCreateInfoCToCpp::GetOutputFrameCallback() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_nweb_create_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_nweb_create_info_get_output_frame_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "IIKgNZJ_HseXKVUhjzA2sA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_NWEB_CREATE_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_nweb_create_info_get_output_frame_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_output_frame_callback)) {
        ark_web_nweb_create_info_get_output_frame_callback = nullptr;
      } else {
        ark_web_nweb_create_info_get_output_frame_callback =
            _struct->get_output_frame_callback;
      }
    } else {
      ark_web_nweb_create_info_get_output_frame_callback =
          reinterpret_cast<ArkWebNWebCreateInfoGetOutputFrameCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_nweb_create_info_get_output_frame_callback, nullptr);

  // Execute
  ark_web_output_frame_callback_t* _retval =
      ark_web_nweb_create_info_get_output_frame_callback(_struct);

  // Return type: refptr_same
  return ArkWebOutputFrameCallbackCToCpp::Invert(_retval);
}

ArkWebNWebCreateInfoCToCpp::ArkWebNWebCreateInfoCToCpp() {}

ArkWebNWebCreateInfoCToCpp::~ArkWebNWebCreateInfoCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkWebNWebCreateInfoCToCpp,
                           ArkWebNWebCreateInfo,
                           ark_web_nweb_create_info_t>::kBridgeType =
        ARK_WEB_NWEB_CREATE_INFO;

}  // namespace OHOS::ArkWeb
