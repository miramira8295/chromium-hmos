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

#include "ohos_adapter/ctocpp/ark_screenlock_manager_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkScreenlockManagerAdapterIsLockedFunc =
    bool (*)(struct _ark_screenlock_manager_adapter_t* self);
static ArkScreenlockManagerAdapterIsLockedFunc
    ark_screenlock_manager_adapter_is_locked =
        reinterpret_cast<ArkScreenlockManagerAdapterIsLockedFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
bool ArkScreenlockManagerAdapterCToCpp::IsLocked() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_screenlock_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_screenlock_manager_adapter_is_locked);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Hgk3Yxlix3KLs7JEwa3RtA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SCREENLOCK_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_screenlock_manager_adapter_is_locked");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_locked)) {
        ark_screenlock_manager_adapter_is_locked = nullptr;
      } else {
        ark_screenlock_manager_adapter_is_locked = _struct->is_locked;
      }
    } else {
      ark_screenlock_manager_adapter_is_locked =
          reinterpret_cast<ArkScreenlockManagerAdapterIsLockedFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_screenlock_manager_adapter_is_locked,
                                    false);

  // Execute
  return ark_screenlock_manager_adapter_is_locked(_struct);
}

ArkScreenlockManagerAdapterCToCpp::ArkScreenlockManagerAdapterCToCpp() {}

ArkScreenlockManagerAdapterCToCpp::~ArkScreenlockManagerAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkScreenlockManagerAdapterCToCpp,
                           ArkScreenlockManagerAdapter,
                           ark_screenlock_manager_adapter_t>::kBridgeType =
        ARK_SCREENLOCK_MANAGER_ADAPTER;

}  // namespace OHOS::ArkWeb
