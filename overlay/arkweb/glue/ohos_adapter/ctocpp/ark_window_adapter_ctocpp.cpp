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

#include "ohos_adapter/ctocpp/ark_window_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWindowAdapterCreateNativeWindowFromSurfaceFunc =
    void* (*)(struct _ark_window_adapter_t* self, void* pSurface);
static ArkWindowAdapterCreateNativeWindowFromSurfaceFunc
    ark_window_adapter_create_native_window_from_surface =
        reinterpret_cast<ArkWindowAdapterCreateNativeWindowFromSurfaceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWindowAdapterDestroyNativeWindowFunc =
    void (*)(struct _ark_window_adapter_t* self, void* window);
static ArkWindowAdapterDestroyNativeWindowFunc
    ark_window_adapter_destroy_native_window =
        reinterpret_cast<ArkWindowAdapterDestroyNativeWindowFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWindowAdapterNativeWindowSetBufferGeometryFunc =
    int32_t (*)(struct _ark_window_adapter_t* self,
                void* window,
                int32_t width,
                int32_t height);
static ArkWindowAdapterNativeWindowSetBufferGeometryFunc
    ark_window_adapter_native_window_set_buffer_geometry =
        reinterpret_cast<ArkWindowAdapterNativeWindowSetBufferGeometryFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWindowAdapterNativeWindowSurfaceCleanCacheFunc =
    void (*)(struct _ark_window_adapter_t* self, void* window);
static ArkWindowAdapterNativeWindowSurfaceCleanCacheFunc
    ark_window_adapter_native_window_surface_clean_cache =
        reinterpret_cast<ArkWindowAdapterNativeWindowSurfaceCleanCacheFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWindowAdapterNativeWindowSurfaceCleanCacheWithParaFunc =
    void (*)(struct _ark_window_adapter_t* self, void* window, bool cleanAll);
static ArkWindowAdapterNativeWindowSurfaceCleanCacheWithParaFunc
    ark_window_adapter_native_window_surface_clean_cache_with_para =
        reinterpret_cast<
            ArkWindowAdapterNativeWindowSurfaceCleanCacheWithParaFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWindowAdapterSetTransformHintFunc =
    void (*)(struct _ark_window_adapter_t* self,
             uint32_t rotation,
             void* window);
static ArkWindowAdapterSetTransformHintFunc
    ark_window_adapter_set_transform_hint =
        reinterpret_cast<ArkWindowAdapterSetTransformHintFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWindowAdapterAddNativeWindowRefFunc =
    void (*)(struct _ark_window_adapter_t* self, void* window);
static ArkWindowAdapterAddNativeWindowRefFunc
    ark_window_adapter_add_native_window_ref =
        reinterpret_cast<ArkWindowAdapterAddNativeWindowRefFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWindowAdapterNativeWindowUnRefFunc =
    void (*)(struct _ark_window_adapter_t* self, void* window);
static ArkWindowAdapterNativeWindowUnRefFunc
    ark_window_adapter_native_window_un_ref =
        reinterpret_cast<ArkWindowAdapterNativeWindowUnRefFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void* ArkWindowAdapterCToCpp::CreateNativeWindowFromSurface(void* pSurface) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_window_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_window_adapter_create_native_window_from_surface);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "d02Q6OwQItuBetc$ejXkkg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_WINDOW_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_window_adapter_create_native_window_from_surface");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      create_native_window_from_surface)) {
        ark_window_adapter_create_native_window_from_surface = nullptr;
      } else {
        ark_window_adapter_create_native_window_from_surface =
            _struct->create_native_window_from_surface;
      }
    } else {
      ark_window_adapter_create_native_window_from_surface =
          reinterpret_cast<ArkWindowAdapterCreateNativeWindowFromSurfaceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_window_adapter_create_native_window_from_surface, nullptr);

  // Execute
  return ark_window_adapter_create_native_window_from_surface(_struct,
                                                              pSurface);
}

ARK_WEB_NO_SANITIZE
void ArkWindowAdapterCToCpp::DestroyNativeWindow(void* window) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_window_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_window_adapter_destroy_native_window);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "x7W19TzP6Gjo18vewjJMdg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_WINDOW_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_window_adapter_destroy_native_window");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, destroy_native_window)) {
        ark_window_adapter_destroy_native_window = nullptr;
      } else {
        ark_window_adapter_destroy_native_window =
            _struct->destroy_native_window;
      }
    } else {
      ark_window_adapter_destroy_native_window =
          reinterpret_cast<ArkWindowAdapterDestroyNativeWindowFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_window_adapter_destroy_native_window,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_window_adapter_destroy_native_window(_struct, window);
}

ARK_WEB_NO_SANITIZE
int32_t ArkWindowAdapterCToCpp::NativeWindowSetBufferGeometry(void* window,
                                                              int32_t width,
                                                              int32_t height) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_window_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_window_adapter_native_window_set_buffer_geometry);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "XKURV3nUhLITuPQnNPzFQQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_WINDOW_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_window_adapter_native_window_set_buffer_geometry");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      native_window_set_buffer_geometry)) {
        ark_window_adapter_native_window_set_buffer_geometry = nullptr;
      } else {
        ark_window_adapter_native_window_set_buffer_geometry =
            _struct->native_window_set_buffer_geometry;
      }
    } else {
      ark_window_adapter_native_window_set_buffer_geometry =
          reinterpret_cast<ArkWindowAdapterNativeWindowSetBufferGeometryFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_window_adapter_native_window_set_buffer_geometry, 0);

  // Execute
  return ark_window_adapter_native_window_set_buffer_geometry(_struct, window,
                                                              width, height);
}

ARK_WEB_NO_SANITIZE
void ArkWindowAdapterCToCpp::NativeWindowSurfaceCleanCache(void* window) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_window_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_window_adapter_native_window_surface_clean_cache);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "THXx32CCIh1UhoQlgWNUOQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_WINDOW_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_window_adapter_native_window_surface_clean_cache");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      native_window_surface_clean_cache)) {
        ark_window_adapter_native_window_surface_clean_cache = nullptr;
      } else {
        ark_window_adapter_native_window_surface_clean_cache =
            _struct->native_window_surface_clean_cache;
      }
    } else {
      ark_window_adapter_native_window_surface_clean_cache =
          reinterpret_cast<ArkWindowAdapterNativeWindowSurfaceCleanCacheFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_window_adapter_native_window_surface_clean_cache,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_window_adapter_native_window_surface_clean_cache(_struct, window);
}

ARK_WEB_NO_SANITIZE
void ArkWindowAdapterCToCpp::NativeWindowSurfaceCleanCacheWithPara(
    void* window,
    bool cleanAll) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_window_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_window_adapter_native_window_surface_clean_cache_with_para);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ZZ3x$F9pPsEEn4z5vddmgQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_WINDOW_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_window_adapter_native_window_surface_clean_cache_with_para");
      if (ARK_WEB_FUNC_MEMBER_MISSING(
              _struct, native_window_surface_clean_cache_with_para)) {
        ark_window_adapter_native_window_surface_clean_cache_with_para =
            nullptr;
      } else {
        ark_window_adapter_native_window_surface_clean_cache_with_para =
            _struct->native_window_surface_clean_cache_with_para;
      }
    } else {
      ark_window_adapter_native_window_surface_clean_cache_with_para =
          reinterpret_cast<
              ArkWindowAdapterNativeWindowSurfaceCleanCacheWithParaFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_window_adapter_native_window_surface_clean_cache_with_para,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_window_adapter_native_window_surface_clean_cache_with_para(
      _struct, window, cleanAll);
}

ARK_WEB_NO_SANITIZE
void ArkWindowAdapterCToCpp::SetTransformHint(uint32_t rotation, void* window) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_window_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_window_adapter_set_transform_hint);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ilFV31vbSsO25HvAgg9kpA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_WINDOW_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_window_adapter_set_transform_hint");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_transform_hint)) {
        ark_window_adapter_set_transform_hint = nullptr;
      } else {
        ark_window_adapter_set_transform_hint = _struct->set_transform_hint;
      }
    } else {
      ark_window_adapter_set_transform_hint =
          reinterpret_cast<ArkWindowAdapterSetTransformHintFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_window_adapter_set_transform_hint,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_window_adapter_set_transform_hint(_struct, rotation, window);
}

ARK_WEB_NO_SANITIZE
void ArkWindowAdapterCToCpp::AddNativeWindowRef(void* window) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_window_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_window_adapter_add_native_window_ref);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "yMxdXZfPSDJdQDmRr4hmIQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_WINDOW_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_window_adapter_add_native_window_ref");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, add_native_window_ref)) {
        ark_window_adapter_add_native_window_ref = nullptr;
      } else {
        ark_window_adapter_add_native_window_ref =
            _struct->add_native_window_ref;
      }
    } else {
      ark_window_adapter_add_native_window_ref =
          reinterpret_cast<ArkWindowAdapterAddNativeWindowRefFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_window_adapter_add_native_window_ref,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_window_adapter_add_native_window_ref(_struct, window);
}

ARK_WEB_NO_SANITIZE
void ArkWindowAdapterCToCpp::NativeWindowUnRef(void* window) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_window_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_window_adapter_native_window_un_ref);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "varkL1tkjiD64Ws6qttv5g";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_WINDOW_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_window_adapter_native_window_un_ref");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, native_window_un_ref)) {
        ark_window_adapter_native_window_un_ref = nullptr;
      } else {
        ark_window_adapter_native_window_un_ref = _struct->native_window_un_ref;
      }
    } else {
      ark_window_adapter_native_window_un_ref =
          reinterpret_cast<ArkWindowAdapterNativeWindowUnRefFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_window_adapter_native_window_un_ref,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_window_adapter_native_window_un_ref(_struct, window);
}

ArkWindowAdapterCToCpp::ArkWindowAdapterCToCpp() {}

ArkWindowAdapterCToCpp::~ArkWindowAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkWindowAdapterCToCpp,
                                        ArkWindowAdapter,
                                        ark_window_adapter_t>::kBridgeType =
    ARK_WINDOW_ADAPTER;

}  // namespace OHOS::ArkWeb
