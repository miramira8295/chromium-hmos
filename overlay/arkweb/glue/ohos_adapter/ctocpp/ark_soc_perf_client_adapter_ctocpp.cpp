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

#include "ohos_adapter/ctocpp/ark_soc_perf_client_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkSocPerfClientAdapterApplySocPerfConfigByIdFunc =
    void (*)(struct _ark_soc_perf_client_adapter_t* self, int32_t id);
static ArkSocPerfClientAdapterApplySocPerfConfigByIdFunc
    ark_soc_perf_client_adapter_apply_soc_perf_config_by_id =
        reinterpret_cast<ArkSocPerfClientAdapterApplySocPerfConfigByIdFunc>(
            ARK_WEB_INIT_ADDR);

using ArkSocPerfClientAdapterApplySocPerfConfigByIdExFunc =
    void (*)(struct _ark_soc_perf_client_adapter_t* self,
             int32_t id,
             bool onOffTag);
static ArkSocPerfClientAdapterApplySocPerfConfigByIdExFunc
    ark_soc_perf_client_adapter_apply_soc_perf_config_by_id_ex =
        reinterpret_cast<ArkSocPerfClientAdapterApplySocPerfConfigByIdExFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkSocPerfClientAdapterCToCpp::ApplySocPerfConfigById(int32_t id) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_soc_perf_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_soc_perf_client_adapter_apply_soc_perf_config_by_id);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "aQVpQttxI6zgTN1DnRfNSw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SOC_PERF_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_soc_perf_client_adapter_apply_soc_perf_config_by_id");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, apply_soc_perf_config_by_id)) {
        ark_soc_perf_client_adapter_apply_soc_perf_config_by_id = nullptr;
      } else {
        ark_soc_perf_client_adapter_apply_soc_perf_config_by_id =
            _struct->apply_soc_perf_config_by_id;
      }
    } else {
      ark_soc_perf_client_adapter_apply_soc_perf_config_by_id =
          reinterpret_cast<ArkSocPerfClientAdapterApplySocPerfConfigByIdFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_soc_perf_client_adapter_apply_soc_perf_config_by_id,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_soc_perf_client_adapter_apply_soc_perf_config_by_id(_struct, id);
}

ARK_WEB_NO_SANITIZE
void ArkSocPerfClientAdapterCToCpp::ApplySocPerfConfigByIdEx(int32_t id,
                                                             bool onOffTag) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_soc_perf_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_soc_perf_client_adapter_apply_soc_perf_config_by_id_ex);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "53oeXFWstqmI03IjVlrfDA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_SOC_PERF_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_soc_perf_client_adapter_apply_soc_perf_config_by_id_ex");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      apply_soc_perf_config_by_id_ex)) {
        ark_soc_perf_client_adapter_apply_soc_perf_config_by_id_ex = nullptr;
      } else {
        ark_soc_perf_client_adapter_apply_soc_perf_config_by_id_ex =
            _struct->apply_soc_perf_config_by_id_ex;
      }
    } else {
      ark_soc_perf_client_adapter_apply_soc_perf_config_by_id_ex =
          reinterpret_cast<ArkSocPerfClientAdapterApplySocPerfConfigByIdExFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_soc_perf_client_adapter_apply_soc_perf_config_by_id_ex,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_soc_perf_client_adapter_apply_soc_perf_config_by_id_ex(_struct, id,
                                                             onOffTag);
}

ArkSocPerfClientAdapterCToCpp::ArkSocPerfClientAdapterCToCpp() {}

ArkSocPerfClientAdapterCToCpp::~ArkSocPerfClientAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkSocPerfClientAdapterCToCpp,
                           ArkSocPerfClientAdapter,
                           ark_soc_perf_client_adapter_t>::kBridgeType =
        ARK_SOC_PERF_CLIENT_ADAPTER;

}  // namespace OHOS::ArkWeb
