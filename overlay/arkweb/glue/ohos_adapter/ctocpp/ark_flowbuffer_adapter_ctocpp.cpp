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

#include "ohos_adapter/ctocpp/ark_flowbuffer_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkFlowbufferAdapterStartPerformanceBoostFunc =
    void (*)(struct _ark_flowbuffer_adapter_t* self);
static ArkFlowbufferAdapterStartPerformanceBoostFunc
    ark_flowbuffer_adapter_start_performance_boost =
        reinterpret_cast<ArkFlowbufferAdapterStartPerformanceBoostFunc>(
            ARK_WEB_INIT_ADDR);

using ArkFlowbufferAdapterCreateAshmemFunc =
    void* (*)(struct _ark_flowbuffer_adapter_t* self,
              size_t size,
              int mapType,
              int* fd);
static ArkFlowbufferAdapterCreateAshmemFunc
    ark_flowbuffer_adapter_create_ashmem =
        reinterpret_cast<ArkFlowbufferAdapterCreateAshmemFunc>(
            ARK_WEB_INIT_ADDR);

using ArkFlowbufferAdapterCreateAshmemWithFdFunc =
    void* (*)(struct _ark_flowbuffer_adapter_t* self,
              const int fd,
              size_t size,
              int mapType);
static ArkFlowbufferAdapterCreateAshmemWithFdFunc
    ark_flowbuffer_adapter_create_ashmem_with_fd =
        reinterpret_cast<ArkFlowbufferAdapterCreateAshmemWithFdFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkFlowbufferAdapterCToCpp::StartPerformanceBoost() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_flowbuffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_flowbuffer_adapter_start_performance_boost);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "mvKzvSsqGVsLjO9JiPwx$w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_FLOWBUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_flowbuffer_adapter_start_performance_boost");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start_performance_boost)) {
        ark_flowbuffer_adapter_start_performance_boost = nullptr;
      } else {
        ark_flowbuffer_adapter_start_performance_boost =
            _struct->start_performance_boost;
      }
    } else {
      ark_flowbuffer_adapter_start_performance_boost =
          reinterpret_cast<ArkFlowbufferAdapterStartPerformanceBoostFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_flowbuffer_adapter_start_performance_boost, ARK_WEB_RETURN_VOID);

  // Execute
  ark_flowbuffer_adapter_start_performance_boost(_struct);
}

ARK_WEB_NO_SANITIZE
void* ArkFlowbufferAdapterCToCpp::CreateAshmem(size_t size,
                                               int mapType,
                                               int& fd) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_flowbuffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_flowbuffer_adapter_create_ashmem);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "l19q3X11tJk$2bmkWJHEAg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_FLOWBUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_flowbuffer_adapter_create_ashmem");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_ashmem)) {
        ark_flowbuffer_adapter_create_ashmem = nullptr;
      } else {
        ark_flowbuffer_adapter_create_ashmem = _struct->create_ashmem;
      }
    } else {
      ark_flowbuffer_adapter_create_ashmem =
          reinterpret_cast<ArkFlowbufferAdapterCreateAshmemFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_flowbuffer_adapter_create_ashmem,
                                    nullptr);

  // Execute
  return ark_flowbuffer_adapter_create_ashmem(_struct, size, mapType, &fd);
}

ARK_WEB_NO_SANITIZE
void* ArkFlowbufferAdapterCToCpp::CreateAshmemWithFd(const int fd,
                                                     size_t size,
                                                     int mapType) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_flowbuffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_flowbuffer_adapter_create_ashmem_with_fd);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "0dAGcKnNa9zRpAGjR6NJBQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_FLOWBUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_flowbuffer_adapter_create_ashmem_with_fd");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_ashmem_with_fd)) {
        ark_flowbuffer_adapter_create_ashmem_with_fd = nullptr;
      } else {
        ark_flowbuffer_adapter_create_ashmem_with_fd =
            _struct->create_ashmem_with_fd;
      }
    } else {
      ark_flowbuffer_adapter_create_ashmem_with_fd =
          reinterpret_cast<ArkFlowbufferAdapterCreateAshmemWithFdFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_flowbuffer_adapter_create_ashmem_with_fd, nullptr);

  // Execute
  return ark_flowbuffer_adapter_create_ashmem_with_fd(_struct, fd, size,
                                                      mapType);
}

ArkFlowbufferAdapterCToCpp::ArkFlowbufferAdapterCToCpp() {}

ArkFlowbufferAdapterCToCpp::~ArkFlowbufferAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkFlowbufferAdapterCToCpp,
                                        ArkFlowbufferAdapter,
                                        ark_flowbuffer_adapter_t>::kBridgeType =
    ARK_FLOWBUFFER_ADAPTER;

}  // namespace OHOS::ArkWeb
