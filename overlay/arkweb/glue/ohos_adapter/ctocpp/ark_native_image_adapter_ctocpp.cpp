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

#include "ohos_adapter/ctocpp/ark_native_image_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_frame_available_listener_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkNativeImageAdapterCreateNativeImageFunc =
    void (*)(struct _ark_native_image_adapter_t* self,
             uint32_t textureId,
             uint32_t textureTarget);
static ArkNativeImageAdapterCreateNativeImageFunc
    ark_native_image_adapter_create_native_image =
        reinterpret_cast<ArkNativeImageAdapterCreateNativeImageFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNativeImageAdapterAquireNativeWindowFromNativeImageFunc =
    void* (*)(struct _ark_native_image_adapter_t* self);
static ArkNativeImageAdapterAquireNativeWindowFromNativeImageFunc
    ark_native_image_adapter_aquire_native_window_from_native_image =
        reinterpret_cast<
            ArkNativeImageAdapterAquireNativeWindowFromNativeImageFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNativeImageAdapterAttachContextFunc =
    int32_t (*)(struct _ark_native_image_adapter_t* self, uint32_t textureId);
static ArkNativeImageAdapterAttachContextFunc
    ark_native_image_adapter_attach_context =
        reinterpret_cast<ArkNativeImageAdapterAttachContextFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNativeImageAdapterDetachContextFunc =
    int32_t (*)(struct _ark_native_image_adapter_t* self);
static ArkNativeImageAdapterDetachContextFunc
    ark_native_image_adapter_detach_context =
        reinterpret_cast<ArkNativeImageAdapterDetachContextFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNativeImageAdapterUpdateSurfaceImageFunc =
    int32_t (*)(struct _ark_native_image_adapter_t* self);
static ArkNativeImageAdapterUpdateSurfaceImageFunc
    ark_native_image_adapter_update_surface_image =
        reinterpret_cast<ArkNativeImageAdapterUpdateSurfaceImageFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNativeImageAdapterGetTimestampFunc =
    int64_t (*)(struct _ark_native_image_adapter_t* self);
static ArkNativeImageAdapterGetTimestampFunc
    ark_native_image_adapter_get_timestamp =
        reinterpret_cast<ArkNativeImageAdapterGetTimestampFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNativeImageAdapterGetTransformMatrixFunc =
    int32_t (*)(struct _ark_native_image_adapter_t* self, float matrix[16]);
static ArkNativeImageAdapterGetTransformMatrixFunc
    ark_native_image_adapter_get_transform_matrix =
        reinterpret_cast<ArkNativeImageAdapterGetTransformMatrixFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNativeImageAdapterGetSurfaceIdFunc =
    int32_t (*)(struct _ark_native_image_adapter_t* self, uint64_t* surfaceId);
static ArkNativeImageAdapterGetSurfaceIdFunc
    ark_native_image_adapter_get_surface_id =
        reinterpret_cast<ArkNativeImageAdapterGetSurfaceIdFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNativeImageAdapterSetOnFrameAvailableListenerFunc =
    int32_t (*)(struct _ark_native_image_adapter_t* self,
                ark_frame_available_listener_t* listener);
static ArkNativeImageAdapterSetOnFrameAvailableListenerFunc
    ark_native_image_adapter_set_on_frame_available_listener =
        reinterpret_cast<ArkNativeImageAdapterSetOnFrameAvailableListenerFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNativeImageAdapterUnsetOnFrameAvailableListenerFunc =
    int32_t (*)(struct _ark_native_image_adapter_t* self);
static ArkNativeImageAdapterUnsetOnFrameAvailableListenerFunc
    ark_native_image_adapter_unset_on_frame_available_listener =
        reinterpret_cast<
            ArkNativeImageAdapterUnsetOnFrameAvailableListenerFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNativeImageAdapterDestroyNativeImageFunc =
    void (*)(struct _ark_native_image_adapter_t* self);
static ArkNativeImageAdapterDestroyNativeImageFunc
    ark_native_image_adapter_destroy_native_image =
        reinterpret_cast<ArkNativeImageAdapterDestroyNativeImageFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNativeImageAdapterNewNativeImageFunc =
    void (*)(struct _ark_native_image_adapter_t* self);
static ArkNativeImageAdapterNewNativeImageFunc
    ark_native_image_adapter_new_native_image =
        reinterpret_cast<ArkNativeImageAdapterNewNativeImageFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNativeImageAdapterAcquireNativeWindowBufferFunc =
    int32_t (*)(struct _ark_native_image_adapter_t* self,
                void** windowBuffer,
                int* acquireFenceFd);
static ArkNativeImageAdapterAcquireNativeWindowBufferFunc
    ark_native_image_adapter_acquire_native_window_buffer =
        reinterpret_cast<ArkNativeImageAdapterAcquireNativeWindowBufferFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNativeImageAdapterGetNativeBufferFunc =
    int32_t (*)(struct _ark_native_image_adapter_t* self,
                void* windowBuffer,
                void** nativeBuffer);
static ArkNativeImageAdapterGetNativeBufferFunc
    ark_native_image_adapter_get_native_buffer =
        reinterpret_cast<ArkNativeImageAdapterGetNativeBufferFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNativeImageAdapterReleaseNativeWindowBufferFunc =
    int32_t (*)(struct _ark_native_image_adapter_t* self,
                void* windowBuffer,
                int fenceFd);
static ArkNativeImageAdapterReleaseNativeWindowBufferFunc
    ark_native_image_adapter_release_native_window_buffer =
        reinterpret_cast<ArkNativeImageAdapterReleaseNativeWindowBufferFunc>(
            ARK_WEB_INIT_ADDR);

using ArkNativeImageAdapterGetNativeWindowBufferSizeFunc =
    void (*)(struct _ark_native_image_adapter_t* self,
             void* windowBuffer,
             uint32_t* width,
             uint32_t* height);
static ArkNativeImageAdapterGetNativeWindowBufferSizeFunc
    ark_native_image_adapter_get_native_window_buffer_size =
        reinterpret_cast<ArkNativeImageAdapterGetNativeWindowBufferSizeFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkNativeImageAdapterCToCpp::CreateNativeImage(uint32_t textureId,
                                                    uint32_t textureTarget) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_native_image_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_native_image_adapter_create_native_image);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Te53PfNccewC9mDLDkxBOA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NATIVE_IMAGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_native_image_adapter_create_native_image");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_native_image)) {
        ark_native_image_adapter_create_native_image = nullptr;
      } else {
        ark_native_image_adapter_create_native_image =
            _struct->create_native_image;
      }
    } else {
      ark_native_image_adapter_create_native_image =
          reinterpret_cast<ArkNativeImageAdapterCreateNativeImageFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_native_image_adapter_create_native_image, ARK_WEB_RETURN_VOID);

  // Execute
  ark_native_image_adapter_create_native_image(_struct, textureId,
                                               textureTarget);
}

ARK_WEB_NO_SANITIZE
void* ArkNativeImageAdapterCToCpp::AquireNativeWindowFromNativeImage() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_native_image_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_native_image_adapter_aquire_native_window_from_native_image);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "LC2jEH78zPtREyGeM4$$7A";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NATIVE_IMAGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_native_image_adapter_aquire_native_window_from_native_image");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      aquire_native_window_from_native_image)) {
        ark_native_image_adapter_aquire_native_window_from_native_image =
            nullptr;
      } else {
        ark_native_image_adapter_aquire_native_window_from_native_image =
            _struct->aquire_native_window_from_native_image;
      }
    } else {
      ark_native_image_adapter_aquire_native_window_from_native_image =
          reinterpret_cast<
              ArkNativeImageAdapterAquireNativeWindowFromNativeImageFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_native_image_adapter_aquire_native_window_from_native_image, nullptr);

  // Execute
  return ark_native_image_adapter_aquire_native_window_from_native_image(
      _struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkNativeImageAdapterCToCpp::AttachContext(uint32_t textureId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_native_image_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_native_image_adapter_attach_context);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "cJPOyGP02fAYnQ5bcwbIFw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NATIVE_IMAGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_native_image_adapter_attach_context");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, attach_context)) {
        ark_native_image_adapter_attach_context = nullptr;
      } else {
        ark_native_image_adapter_attach_context = _struct->attach_context;
      }
    } else {
      ark_native_image_adapter_attach_context =
          reinterpret_cast<ArkNativeImageAdapterAttachContextFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_native_image_adapter_attach_context, 0);

  // Execute
  return ark_native_image_adapter_attach_context(_struct, textureId);
}

ARK_WEB_NO_SANITIZE
int32_t ArkNativeImageAdapterCToCpp::DetachContext() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_native_image_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_native_image_adapter_detach_context);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "K5VuxsQE_fYrfLlGh5L08g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NATIVE_IMAGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_native_image_adapter_detach_context");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, detach_context)) {
        ark_native_image_adapter_detach_context = nullptr;
      } else {
        ark_native_image_adapter_detach_context = _struct->detach_context;
      }
    } else {
      ark_native_image_adapter_detach_context =
          reinterpret_cast<ArkNativeImageAdapterDetachContextFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_native_image_adapter_detach_context, 0);

  // Execute
  return ark_native_image_adapter_detach_context(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkNativeImageAdapterCToCpp::UpdateSurfaceImage() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_native_image_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_native_image_adapter_update_surface_image);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "XxH8Oc8YfjzZ1U9e8jh8gw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NATIVE_IMAGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_native_image_adapter_update_surface_image");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, update_surface_image)) {
        ark_native_image_adapter_update_surface_image = nullptr;
      } else {
        ark_native_image_adapter_update_surface_image =
            _struct->update_surface_image;
      }
    } else {
      ark_native_image_adapter_update_surface_image =
          reinterpret_cast<ArkNativeImageAdapterUpdateSurfaceImageFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_native_image_adapter_update_surface_image, 0);

  // Execute
  return ark_native_image_adapter_update_surface_image(_struct);
}

ARK_WEB_NO_SANITIZE
int64_t ArkNativeImageAdapterCToCpp::GetTimestamp() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_native_image_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_native_image_adapter_get_timestamp);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "0YFi6_p5aUzianb8wE$ZDQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NATIVE_IMAGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_native_image_adapter_get_timestamp");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_timestamp)) {
        ark_native_image_adapter_get_timestamp = nullptr;
      } else {
        ark_native_image_adapter_get_timestamp = _struct->get_timestamp;
      }
    } else {
      ark_native_image_adapter_get_timestamp =
          reinterpret_cast<ArkNativeImageAdapterGetTimestampFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_native_image_adapter_get_timestamp, 0);

  // Execute
  return ark_native_image_adapter_get_timestamp(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkNativeImageAdapterCToCpp::GetTransformMatrix(float matrix[16]) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_native_image_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_native_image_adapter_get_transform_matrix);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "uGqJjYSPflismCCu03a9XQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NATIVE_IMAGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_native_image_adapter_get_transform_matrix");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_transform_matrix)) {
        ark_native_image_adapter_get_transform_matrix = nullptr;
      } else {
        ark_native_image_adapter_get_transform_matrix =
            _struct->get_transform_matrix;
      }
    } else {
      ark_native_image_adapter_get_transform_matrix =
          reinterpret_cast<ArkNativeImageAdapterGetTransformMatrixFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_native_image_adapter_get_transform_matrix, 0);

  // Execute
  return ark_native_image_adapter_get_transform_matrix(_struct, matrix);
}

ARK_WEB_NO_SANITIZE
int32_t ArkNativeImageAdapterCToCpp::GetSurfaceId(uint64_t* surfaceId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_native_image_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_native_image_adapter_get_surface_id);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "YZonSbuTIhdM5oHlUuTLgg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NATIVE_IMAGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_native_image_adapter_get_surface_id");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_surface_id)) {
        ark_native_image_adapter_get_surface_id = nullptr;
      } else {
        ark_native_image_adapter_get_surface_id = _struct->get_surface_id;
      }
    } else {
      ark_native_image_adapter_get_surface_id =
          reinterpret_cast<ArkNativeImageAdapterGetSurfaceIdFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_native_image_adapter_get_surface_id, 0);

  // Execute
  return ark_native_image_adapter_get_surface_id(_struct, surfaceId);
}

ARK_WEB_NO_SANITIZE
int32_t ArkNativeImageAdapterCToCpp::SetOnFrameAvailableListener(
    ArkWebRefPtr<ArkFrameAvailableListener> listener) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_native_image_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_native_image_adapter_set_on_frame_available_listener);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "DJ8wLQUn8O4FtfohcnSOsg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NATIVE_IMAGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_native_image_adapter_set_on_frame_available_listener");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      set_on_frame_available_listener)) {
        ark_native_image_adapter_set_on_frame_available_listener = nullptr;
      } else {
        ark_native_image_adapter_set_on_frame_available_listener =
            _struct->set_on_frame_available_listener;
      }
    } else {
      ark_native_image_adapter_set_on_frame_available_listener =
          reinterpret_cast<
              ArkNativeImageAdapterSetOnFrameAvailableListenerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_native_image_adapter_set_on_frame_available_listener, 0);

  // Execute
  return ark_native_image_adapter_set_on_frame_available_listener(
      _struct, ArkFrameAvailableListenerCppToC::Invert(listener));
}

ARK_WEB_NO_SANITIZE
int32_t ArkNativeImageAdapterCToCpp::UnsetOnFrameAvailableListener() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_native_image_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_native_image_adapter_unset_on_frame_available_listener);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "F3jm84nUQKJgouomtuxk_Q";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NATIVE_IMAGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_native_image_adapter_unset_on_frame_available_listener");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      unset_on_frame_available_listener)) {
        ark_native_image_adapter_unset_on_frame_available_listener = nullptr;
      } else {
        ark_native_image_adapter_unset_on_frame_available_listener =
            _struct->unset_on_frame_available_listener;
      }
    } else {
      ark_native_image_adapter_unset_on_frame_available_listener =
          reinterpret_cast<
              ArkNativeImageAdapterUnsetOnFrameAvailableListenerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_native_image_adapter_unset_on_frame_available_listener, 0);

  // Execute
  return ark_native_image_adapter_unset_on_frame_available_listener(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkNativeImageAdapterCToCpp::DestroyNativeImage() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_native_image_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_native_image_adapter_destroy_native_image);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "hiimLevJfnUn2s_8k$piNQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NATIVE_IMAGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_native_image_adapter_destroy_native_image");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, destroy_native_image)) {
        ark_native_image_adapter_destroy_native_image = nullptr;
      } else {
        ark_native_image_adapter_destroy_native_image =
            _struct->destroy_native_image;
      }
    } else {
      ark_native_image_adapter_destroy_native_image =
          reinterpret_cast<ArkNativeImageAdapterDestroyNativeImageFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_native_image_adapter_destroy_native_image, ARK_WEB_RETURN_VOID);

  // Execute
  ark_native_image_adapter_destroy_native_image(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkNativeImageAdapterCToCpp::NewNativeImage() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_native_image_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_native_image_adapter_new_native_image);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "gzBidPYxVVpt9PWP0caBqw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NATIVE_IMAGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_native_image_adapter_new_native_image");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, new_native_image)) {
        ark_native_image_adapter_new_native_image = nullptr;
      } else {
        ark_native_image_adapter_new_native_image = _struct->new_native_image;
      }
    } else {
      ark_native_image_adapter_new_native_image =
          reinterpret_cast<ArkNativeImageAdapterNewNativeImageFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_native_image_adapter_new_native_image,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_native_image_adapter_new_native_image(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkNativeImageAdapterCToCpp::AcquireNativeWindowBuffer(
    void** windowBuffer,
    int* acquireFenceFd) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_native_image_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_native_image_adapter_acquire_native_window_buffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "xX8Z9Y62m65eogZLQ7AiJQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NATIVE_IMAGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_native_image_adapter_acquire_native_window_buffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, acquire_native_window_buffer)) {
        ark_native_image_adapter_acquire_native_window_buffer = nullptr;
      } else {
        ark_native_image_adapter_acquire_native_window_buffer =
            _struct->acquire_native_window_buffer;
      }
    } else {
      ark_native_image_adapter_acquire_native_window_buffer =
          reinterpret_cast<ArkNativeImageAdapterAcquireNativeWindowBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_native_image_adapter_acquire_native_window_buffer, 0);

  // Execute
  return ark_native_image_adapter_acquire_native_window_buffer(
      _struct, windowBuffer, acquireFenceFd);
}

ARK_WEB_NO_SANITIZE
int32_t ArkNativeImageAdapterCToCpp::GetNativeBuffer(void* windowBuffer,
                                                     void** nativeBuffer) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_native_image_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_native_image_adapter_get_native_buffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Fipw1sI3ZRxAJSnrN_cFTA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NATIVE_IMAGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_native_image_adapter_get_native_buffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_native_buffer)) {
        ark_native_image_adapter_get_native_buffer = nullptr;
      } else {
        ark_native_image_adapter_get_native_buffer = _struct->get_native_buffer;
      }
    } else {
      ark_native_image_adapter_get_native_buffer =
          reinterpret_cast<ArkNativeImageAdapterGetNativeBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_native_image_adapter_get_native_buffer,
                                    0);

  // Execute
  return ark_native_image_adapter_get_native_buffer(_struct, windowBuffer,
                                                    nativeBuffer);
}

ARK_WEB_NO_SANITIZE
int32_t ArkNativeImageAdapterCToCpp::ReleaseNativeWindowBuffer(
    void* windowBuffer,
    int fenceFd) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_native_image_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_native_image_adapter_release_native_window_buffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "5EDG6koXZUbvFlHEIpVKNg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NATIVE_IMAGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_native_image_adapter_release_native_window_buffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release_native_window_buffer)) {
        ark_native_image_adapter_release_native_window_buffer = nullptr;
      } else {
        ark_native_image_adapter_release_native_window_buffer =
            _struct->release_native_window_buffer;
      }
    } else {
      ark_native_image_adapter_release_native_window_buffer =
          reinterpret_cast<ArkNativeImageAdapterReleaseNativeWindowBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_native_image_adapter_release_native_window_buffer, 0);

  // Execute
  return ark_native_image_adapter_release_native_window_buffer(
      _struct, windowBuffer, fenceFd);
}

ARK_WEB_NO_SANITIZE
void ArkNativeImageAdapterCToCpp::GetNativeWindowBufferSize(void* windowBuffer,
                                                            uint32_t* width,
                                                            uint32_t* height) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_native_image_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_native_image_adapter_get_native_window_buffer_size);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "rf7v4s_aIuQMUzOGn9k6KQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_NATIVE_IMAGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_native_image_adapter_get_native_window_buffer_size");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_native_window_buffer_size)) {
        ark_native_image_adapter_get_native_window_buffer_size = nullptr;
      } else {
        ark_native_image_adapter_get_native_window_buffer_size =
            _struct->get_native_window_buffer_size;
      }
    } else {
      ark_native_image_adapter_get_native_window_buffer_size =
          reinterpret_cast<ArkNativeImageAdapterGetNativeWindowBufferSizeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_native_image_adapter_get_native_window_buffer_size,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_native_image_adapter_get_native_window_buffer_size(_struct, windowBuffer,
                                                         width, height);
}

ArkNativeImageAdapterCToCpp::ArkNativeImageAdapterCToCpp() {}

ArkNativeImageAdapterCToCpp::~ArkNativeImageAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkNativeImageAdapterCToCpp,
                           ArkNativeImageAdapter,
                           ark_native_image_adapter_t>::kBridgeType =
        ARK_NATIVE_IMAGE_ADAPTER;

}  // namespace OHOS::ArkWeb
