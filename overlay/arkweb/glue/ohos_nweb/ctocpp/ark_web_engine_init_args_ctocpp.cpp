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

#include "ohos_nweb/ctocpp/ark_web_engine_init_args_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebEngineInitArgsGetIsPopupFunc =
    bool (*)(struct _ark_web_engine_init_args_t* self);
static ArkWebEngineInitArgsGetIsPopupFunc
    ark_web_engine_init_args_get_is_popup =
        reinterpret_cast<ArkWebEngineInitArgsGetIsPopupFunc>(ARK_WEB_INIT_ADDR);

using ArkWebEngineInitArgsGetDumpPathFunc =
    ArkWebString (*)(struct _ark_web_engine_init_args_t* self);
static ArkWebEngineInitArgsGetDumpPathFunc
    ark_web_engine_init_args_get_dump_path =
        reinterpret_cast<ArkWebEngineInitArgsGetDumpPathFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebEngineInitArgsGetArgsToAddFunc =
    ArkWebStringList (*)(struct _ark_web_engine_init_args_t* self);
static ArkWebEngineInitArgsGetArgsToAddFunc
    ark_web_engine_init_args_get_args_to_add =
        reinterpret_cast<ArkWebEngineInitArgsGetArgsToAddFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebEngineInitArgsGetArgsToDeleteFunc =
    ArkWebStringList (*)(struct _ark_web_engine_init_args_t* self);
static ArkWebEngineInitArgsGetArgsToDeleteFunc
    ark_web_engine_init_args_get_args_to_delete =
        reinterpret_cast<ArkWebEngineInitArgsGetArgsToDeleteFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebEngineInitArgsGetIsFrameInfoDumpFunc =
    bool (*)(struct _ark_web_engine_init_args_t* self);
static ArkWebEngineInitArgsGetIsFrameInfoDumpFunc
    ark_web_engine_init_args_get_is_frame_info_dump =
        reinterpret_cast<ArkWebEngineInitArgsGetIsFrameInfoDumpFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebEngineInitArgsGetIsEnhanceSurfaceFunc =
    bool (*)(struct _ark_web_engine_init_args_t* self);
static ArkWebEngineInitArgsGetIsEnhanceSurfaceFunc
    ark_web_engine_init_args_get_is_enhance_surface =
        reinterpret_cast<ArkWebEngineInitArgsGetIsEnhanceSurfaceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebEngineInitArgsGetIsMultiRendererProcessFunc =
    bool (*)(struct _ark_web_engine_init_args_t* self);
static ArkWebEngineInitArgsGetIsMultiRendererProcessFunc
    ark_web_engine_init_args_get_is_multi_renderer_process =
        reinterpret_cast<ArkWebEngineInitArgsGetIsMultiRendererProcessFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebEngineInitArgsGetSharedRenderProcessTokenFunc =
    ArkWebString (*)(struct _ark_web_engine_init_args_t* self);
static ArkWebEngineInitArgsGetSharedRenderProcessTokenFunc
    ark_web_engine_init_args_get_shared_render_process_token =
        reinterpret_cast<ArkWebEngineInitArgsGetSharedRenderProcessTokenFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
bool ArkWebEngineInitArgsCToCpp::GetIsPopup() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_engine_init_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_engine_init_args_get_is_popup);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ZqKE_0qyPT589Qjju0cxEw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ENGINE_INIT_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_engine_init_args_get_is_popup");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_is_popup)) {
        ark_web_engine_init_args_get_is_popup = nullptr;
      } else {
        ark_web_engine_init_args_get_is_popup = _struct->get_is_popup;
      }
    } else {
      ark_web_engine_init_args_get_is_popup =
          reinterpret_cast<ArkWebEngineInitArgsGetIsPopupFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_engine_init_args_get_is_popup,
                                    false);

  // Execute
  return ark_web_engine_init_args_get_is_popup(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkWebEngineInitArgsCToCpp::GetDumpPath() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_engine_init_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_engine_init_args_get_dump_path);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "SiaBfSvXu9uIK7jnDIazXQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ENGINE_INIT_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_engine_init_args_get_dump_path");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_dump_path)) {
        ark_web_engine_init_args_get_dump_path = nullptr;
      } else {
        ark_web_engine_init_args_get_dump_path = _struct->get_dump_path;
      }
    } else {
      ark_web_engine_init_args_get_dump_path =
          reinterpret_cast<ArkWebEngineInitArgsGetDumpPathFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_engine_init_args_get_dump_path,
                                    ark_web_string_default);

  // Execute
  return ark_web_engine_init_args_get_dump_path(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebStringList ArkWebEngineInitArgsCToCpp::GetArgsToAdd() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_engine_init_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_list_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_engine_init_args_get_args_to_add);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "xLO_tpChYC7t5F_yfcUgHw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ENGINE_INIT_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_engine_init_args_get_args_to_add");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_args_to_add)) {
        ark_web_engine_init_args_get_args_to_add = nullptr;
      } else {
        ark_web_engine_init_args_get_args_to_add = _struct->get_args_to_add;
      }
    } else {
      ark_web_engine_init_args_get_args_to_add =
          reinterpret_cast<ArkWebEngineInitArgsGetArgsToAddFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_engine_init_args_get_args_to_add,
                                    ark_web_string_list_default);

  // Execute
  return ark_web_engine_init_args_get_args_to_add(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebStringList ArkWebEngineInitArgsCToCpp::GetArgsToDelete() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_engine_init_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_list_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_engine_init_args_get_args_to_delete);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "1lPGARun27RuXgxkQyu9hw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ENGINE_INIT_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_engine_init_args_get_args_to_delete");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_args_to_delete)) {
        ark_web_engine_init_args_get_args_to_delete = nullptr;
      } else {
        ark_web_engine_init_args_get_args_to_delete =
            _struct->get_args_to_delete;
      }
    } else {
      ark_web_engine_init_args_get_args_to_delete =
          reinterpret_cast<ArkWebEngineInitArgsGetArgsToDeleteFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_engine_init_args_get_args_to_delete,
                                    ark_web_string_list_default);

  // Execute
  return ark_web_engine_init_args_get_args_to_delete(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkWebEngineInitArgsCToCpp::GetIsFrameInfoDump() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_engine_init_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_engine_init_args_get_is_frame_info_dump);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "6laq6exbklrXQSUN33JtGA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ENGINE_INIT_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_engine_init_args_get_is_frame_info_dump");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_is_frame_info_dump)) {
        ark_web_engine_init_args_get_is_frame_info_dump = nullptr;
      } else {
        ark_web_engine_init_args_get_is_frame_info_dump =
            _struct->get_is_frame_info_dump;
      }
    } else {
      ark_web_engine_init_args_get_is_frame_info_dump =
          reinterpret_cast<ArkWebEngineInitArgsGetIsFrameInfoDumpFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_engine_init_args_get_is_frame_info_dump, false);

  // Execute
  return ark_web_engine_init_args_get_is_frame_info_dump(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkWebEngineInitArgsCToCpp::GetIsEnhanceSurface() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_engine_init_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_engine_init_args_get_is_enhance_surface);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "hHod59nkFtoAqlBctGEztg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ENGINE_INIT_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_engine_init_args_get_is_enhance_surface");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_is_enhance_surface)) {
        ark_web_engine_init_args_get_is_enhance_surface = nullptr;
      } else {
        ark_web_engine_init_args_get_is_enhance_surface =
            _struct->get_is_enhance_surface;
      }
    } else {
      ark_web_engine_init_args_get_is_enhance_surface =
          reinterpret_cast<ArkWebEngineInitArgsGetIsEnhanceSurfaceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_engine_init_args_get_is_enhance_surface, false);

  // Execute
  return ark_web_engine_init_args_get_is_enhance_surface(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkWebEngineInitArgsCToCpp::GetIsMultiRendererProcess() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_engine_init_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_engine_init_args_get_is_multi_renderer_process);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "KUFZkhSZ3aHd7G2dM8zsQg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ENGINE_INIT_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_engine_init_args_get_is_multi_renderer_process");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_is_multi_renderer_process)) {
        ark_web_engine_init_args_get_is_multi_renderer_process = nullptr;
      } else {
        ark_web_engine_init_args_get_is_multi_renderer_process =
            _struct->get_is_multi_renderer_process;
      }
    } else {
      ark_web_engine_init_args_get_is_multi_renderer_process =
          reinterpret_cast<ArkWebEngineInitArgsGetIsMultiRendererProcessFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_engine_init_args_get_is_multi_renderer_process, false);

  // Execute
  return ark_web_engine_init_args_get_is_multi_renderer_process(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkWebEngineInitArgsCToCpp::GetSharedRenderProcessToken() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_engine_init_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_engine_init_args_get_shared_render_process_token);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "nhlcmUAzSLz2ju6iCp_Mxw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ENGINE_INIT_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_engine_init_args_get_shared_render_process_token");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_shared_render_process_token)) {
        ark_web_engine_init_args_get_shared_render_process_token = nullptr;
      } else {
        ark_web_engine_init_args_get_shared_render_process_token =
            _struct->get_shared_render_process_token;
      }
    } else {
      ark_web_engine_init_args_get_shared_render_process_token =
          reinterpret_cast<ArkWebEngineInitArgsGetSharedRenderProcessTokenFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_engine_init_args_get_shared_render_process_token,
      ark_web_string_default);

  // Execute
  return ark_web_engine_init_args_get_shared_render_process_token(_struct);
}

ArkWebEngineInitArgsCToCpp::ArkWebEngineInitArgsCToCpp() {}

ArkWebEngineInitArgsCToCpp::~ArkWebEngineInitArgsCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkWebEngineInitArgsCToCpp,
                           ArkWebEngineInitArgs,
                           ark_web_engine_init_args_t>::kBridgeType =
        ARK_WEB_ENGINE_INIT_ARGS;

}  // namespace OHOS::ArkWeb
