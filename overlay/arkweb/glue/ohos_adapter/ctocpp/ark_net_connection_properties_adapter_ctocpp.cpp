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

#include "ohos_adapter/ctocpp/ark_net_connection_properties_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkNetConnectionPropertiesAdapterGetNetIdFunc =
    int32_t (*)(struct _ark_net_connection_properties_adapter_t* self);
static ArkNetConnectionPropertiesAdapterGetNetIdFunc
    ark_net_connection_properties_adapter_get_net_id =
        reinterpret_cast<ArkNetConnectionPropertiesAdapterGetNetIdFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkNetConnectionPropertiesAdapterCToCpp::GetNetId() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_net_connection_properties_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_net_connection_properties_adapter_get_net_id);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "V1IVVAOilrHWqpJ28hDMjA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_NET_CONNECTION_PROPERTIES_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_net_connection_properties_adapter_get_net_id");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_net_id)) {
        ark_net_connection_properties_adapter_get_net_id = nullptr;
      } else {
        ark_net_connection_properties_adapter_get_net_id = _struct->get_net_id;
      }
    } else {
      ark_net_connection_properties_adapter_get_net_id =
          reinterpret_cast<ArkNetConnectionPropertiesAdapterGetNetIdFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_net_connection_properties_adapter_get_net_id, 0);

  // Execute
  return ark_net_connection_properties_adapter_get_net_id(_struct);
}

ArkNetConnectionPropertiesAdapterCToCpp::
    ArkNetConnectionPropertiesAdapterCToCpp() {}

ArkNetConnectionPropertiesAdapterCToCpp::
    ~ArkNetConnectionPropertiesAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<
    ArkNetConnectionPropertiesAdapterCToCpp,
    ArkNetConnectionPropertiesAdapter,
    ark_net_connection_properties_adapter_t>::kBridgeType =
    ARK_NET_CONNECTION_PROPERTIES_ADAPTER;

}  // namespace OHOS::ArkWeb
