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

#include "ohos_adapter/ctocpp/ark_camera_surface_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/ctocpp/ark_camera_surface_buffer_adapter_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkCameraSurfaceAdapterReleaseBufferFunc =
    int32_t (*)(struct _ark_camera_surface_adapter_t* self,
                ark_camera_surface_buffer_adapter_t* buffer,
                int32_t fence);
static ArkCameraSurfaceAdapterReleaseBufferFunc
    ark_camera_surface_adapter_release_buffer =
        reinterpret_cast<ArkCameraSurfaceAdapterReleaseBufferFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkCameraSurfaceAdapterCToCpp::ReleaseBuffer(
    ArkWebRefPtr<ArkCameraSurfaceBufferAdapter> buffer,
    int32_t fence) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_camera_surface_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_camera_surface_adapter_release_buffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "PQKOjHyax7apwoJPVdQZNg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CAMERA_SURFACE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_camera_surface_adapter_release_buffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release_buffer)) {
        ark_camera_surface_adapter_release_buffer = nullptr;
      } else {
        ark_camera_surface_adapter_release_buffer = _struct->release_buffer;
      }
    } else {
      ark_camera_surface_adapter_release_buffer =
          reinterpret_cast<ArkCameraSurfaceAdapterReleaseBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_camera_surface_adapter_release_buffer,
                                    0);

  // Execute
  return ark_camera_surface_adapter_release_buffer(
      _struct, ArkCameraSurfaceBufferAdapterCToCpp::Revert(buffer), fence);
}

ArkCameraSurfaceAdapterCToCpp::ArkCameraSurfaceAdapterCToCpp() {}

ArkCameraSurfaceAdapterCToCpp::~ArkCameraSurfaceAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkCameraSurfaceAdapterCToCpp,
                           ArkCameraSurfaceAdapter,
                           ark_camera_surface_adapter_t>::kBridgeType =
        ARK_CAMERA_SURFACE_ADAPTER;

}  // namespace OHOS::ArkWeb
