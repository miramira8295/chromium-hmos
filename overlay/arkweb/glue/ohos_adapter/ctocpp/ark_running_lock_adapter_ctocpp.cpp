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

#include "ohos_adapter/ctocpp/ark_running_lock_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkRunningLockAdapterIsUsedFunc =
    bool (*)(struct _ark_running_lock_adapter_t* self);
static ArkRunningLockAdapterIsUsedFunc ark_running_lock_adapter_is_used =
    reinterpret_cast<ArkRunningLockAdapterIsUsedFunc>(ARK_WEB_INIT_ADDR);

using ArkRunningLockAdapterLockFunc =
    int32_t (*)(struct _ark_running_lock_adapter_t* self, uint32_t timeOutMs);
static ArkRunningLockAdapterLockFunc ark_running_lock_adapter_lock =
    reinterpret_cast<ArkRunningLockAdapterLockFunc>(ARK_WEB_INIT_ADDR);

using ArkRunningLockAdapterUnLockFunc =
    int32_t (*)(struct _ark_running_lock_adapter_t* self);
static ArkRunningLockAdapterUnLockFunc ark_running_lock_adapter_un_lock =
    reinterpret_cast<ArkRunningLockAdapterUnLockFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
bool ArkRunningLockAdapterCToCpp::IsUsed() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_running_lock_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_running_lock_adapter_is_used);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "nF8PSBwwZ0OjPnvKV3dCkw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_RUNNING_LOCK_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_running_lock_adapter_is_used");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_used)) {
        ark_running_lock_adapter_is_used = nullptr;
      } else {
        ark_running_lock_adapter_is_used = _struct->is_used;
      }
    } else {
      ark_running_lock_adapter_is_used =
          reinterpret_cast<ArkRunningLockAdapterIsUsedFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_running_lock_adapter_is_used, false);

  // Execute
  return ark_running_lock_adapter_is_used(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkRunningLockAdapterCToCpp::Lock(uint32_t timeOutMs) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_running_lock_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_running_lock_adapter_lock);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "t5Z$peWyeEoyapAeGFf9Jg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_RUNNING_LOCK_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_running_lock_adapter_lock");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, lock)) {
        ark_running_lock_adapter_lock = nullptr;
      } else {
        ark_running_lock_adapter_lock = _struct->lock;
      }
    } else {
      ark_running_lock_adapter_lock =
          reinterpret_cast<ArkRunningLockAdapterLockFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_running_lock_adapter_lock, 0);

  // Execute
  return ark_running_lock_adapter_lock(_struct, timeOutMs);
}

ARK_WEB_NO_SANITIZE
int32_t ArkRunningLockAdapterCToCpp::UnLock() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_running_lock_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_running_lock_adapter_un_lock);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "GpzjQU2UE8HRj5vFWwE7cA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_RUNNING_LOCK_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_running_lock_adapter_un_lock");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, un_lock)) {
        ark_running_lock_adapter_un_lock = nullptr;
      } else {
        ark_running_lock_adapter_un_lock = _struct->un_lock;
      }
    } else {
      ark_running_lock_adapter_un_lock =
          reinterpret_cast<ArkRunningLockAdapterUnLockFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_running_lock_adapter_un_lock, 0);

  // Execute
  return ark_running_lock_adapter_un_lock(_struct);
}

ArkRunningLockAdapterCToCpp::ArkRunningLockAdapterCToCpp() {}

ArkRunningLockAdapterCToCpp::~ArkRunningLockAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkRunningLockAdapterCToCpp,
                           ArkRunningLockAdapter,
                           ark_running_lock_adapter_t>::kBridgeType =
        ARK_RUNNING_LOCK_ADAPTER;

}  // namespace OHOS::ArkWeb
