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

#include "ohos_adapter/ctocpp/ark_vsync_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkVSyncAdapterRequestVsyncFunc =
    uint32_t (*)(struct _ark_vsync_adapter_t* self, void* data, void* cb);
static ArkVSyncAdapterRequestVsyncFunc ark_vsync_adapter_request_vsync =
    reinterpret_cast<ArkVSyncAdapterRequestVsyncFunc>(ARK_WEB_INIT_ADDR);

using ArkVSyncAdapterGetVSyncPeriodFunc =
    int64_t (*)(struct _ark_vsync_adapter_t* self);
static ArkVSyncAdapterGetVSyncPeriodFunc ark_vsync_adapter_get_vsync_period =
    reinterpret_cast<ArkVSyncAdapterGetVSyncPeriodFunc>(ARK_WEB_INIT_ADDR);

using ArkVSyncAdapterSetFrameRateLinkerEnableFunc =
    void (*)(struct _ark_vsync_adapter_t* self, bool enabled);
static ArkVSyncAdapterSetFrameRateLinkerEnableFunc
    ark_vsync_adapter_set_frame_rate_linker_enable =
        reinterpret_cast<ArkVSyncAdapterSetFrameRateLinkerEnableFunc>(
            ARK_WEB_INIT_ADDR);

using ArkVSyncAdapterSetFramePreferredRateFunc =
    void (*)(struct _ark_vsync_adapter_t* self, int32_t preferredRate);
static ArkVSyncAdapterSetFramePreferredRateFunc
    ark_vsync_adapter_set_frame_preferred_rate =
        reinterpret_cast<ArkVSyncAdapterSetFramePreferredRateFunc>(
            ARK_WEB_INIT_ADDR);

using ArkVSyncAdapterSetOnVsyncCallbackFunc =
    void (*)(struct _ark_vsync_adapter_t* self, OnVsyncCallback callback);
static ArkVSyncAdapterSetOnVsyncCallbackFunc
    ark_vsync_adapter_set_on_vsync_callback =
        reinterpret_cast<ArkVSyncAdapterSetOnVsyncCallbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkVSyncAdapterSetOnVsyncEndCallbackFunc =
    void (*)(struct _ark_vsync_adapter_t* self,
             OnVsyncCallback onVsyncEndCallback);
static ArkVSyncAdapterSetOnVsyncEndCallbackFunc
    ark_vsync_adapter_set_on_vsync_end_callback =
        reinterpret_cast<ArkVSyncAdapterSetOnVsyncEndCallbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkVSyncAdapterSetSceneFunc = void (*)(struct _ark_vsync_adapter_t* self,
                                             const ArkWebString* sceneName,
                                             uint32_t state);
static ArkVSyncAdapterSetSceneFunc ark_vsync_adapter_set_scene =
    reinterpret_cast<ArkVSyncAdapterSetSceneFunc>(ARK_WEB_INIT_ADDR);

using ArkVSyncAdapterSetDVSyncSwitchFunc =
    void (*)(struct _ark_vsync_adapter_t* self, bool dvsyncSwitch);
static ArkVSyncAdapterSetDVSyncSwitchFunc ark_vsync_adapter_set_dvsync_switch =
    reinterpret_cast<ArkVSyncAdapterSetDVSyncSwitchFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
uint32_t ArkVSyncAdapterCToCpp::RequestVsync(void* data, void* cb) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_vsync_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_vsync_adapter_request_vsync);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "AQct45RYfCzmK6y6bsW5YA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_VSYNC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_vsync_adapter_request_vsync");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, request_vsync)) {
        ark_vsync_adapter_request_vsync = nullptr;
      } else {
        ark_vsync_adapter_request_vsync = _struct->request_vsync;
      }
    } else {
      ark_vsync_adapter_request_vsync =
          reinterpret_cast<ArkVSyncAdapterRequestVsyncFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_vsync_adapter_request_vsync, 0);

  // Execute
  return ark_vsync_adapter_request_vsync(_struct, data, cb);
}

ARK_WEB_NO_SANITIZE
int64_t ArkVSyncAdapterCToCpp::GetVSyncPeriod() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_vsync_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_vsync_adapter_get_vsync_period);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "metX_hAfykjO2vZ4FX6rTw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_VSYNC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_vsync_adapter_get_vsync_period");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_vsync_period)) {
        ark_vsync_adapter_get_vsync_period = nullptr;
      } else {
        ark_vsync_adapter_get_vsync_period = _struct->get_vsync_period;
      }
    } else {
      ark_vsync_adapter_get_vsync_period =
          reinterpret_cast<ArkVSyncAdapterGetVSyncPeriodFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_vsync_adapter_get_vsync_period, 0);

  // Execute
  return ark_vsync_adapter_get_vsync_period(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkVSyncAdapterCToCpp::SetFrameRateLinkerEnable(bool enabled) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_vsync_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_vsync_adapter_set_frame_rate_linker_enable);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "fatUC2fkuQ_w2RLgoKL4Ew";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_VSYNC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_vsync_adapter_set_frame_rate_linker_enable");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_frame_rate_linker_enable)) {
        ark_vsync_adapter_set_frame_rate_linker_enable = nullptr;
      } else {
        ark_vsync_adapter_set_frame_rate_linker_enable =
            _struct->set_frame_rate_linker_enable;
      }
    } else {
      ark_vsync_adapter_set_frame_rate_linker_enable =
          reinterpret_cast<ArkVSyncAdapterSetFrameRateLinkerEnableFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_vsync_adapter_set_frame_rate_linker_enable, ARK_WEB_RETURN_VOID);

  // Execute
  ark_vsync_adapter_set_frame_rate_linker_enable(_struct, enabled);
}

ARK_WEB_NO_SANITIZE
void ArkVSyncAdapterCToCpp::SetFramePreferredRate(int32_t preferredRate) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_vsync_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_vsync_adapter_set_frame_preferred_rate);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "RuWCpI$XyEKiEj0JMLJtVg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_VSYNC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_vsync_adapter_set_frame_preferred_rate");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_frame_preferred_rate)) {
        ark_vsync_adapter_set_frame_preferred_rate = nullptr;
      } else {
        ark_vsync_adapter_set_frame_preferred_rate =
            _struct->set_frame_preferred_rate;
      }
    } else {
      ark_vsync_adapter_set_frame_preferred_rate =
          reinterpret_cast<ArkVSyncAdapterSetFramePreferredRateFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_vsync_adapter_set_frame_preferred_rate,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_vsync_adapter_set_frame_preferred_rate(_struct, preferredRate);
}

ARK_WEB_NO_SANITIZE
void ArkVSyncAdapterCToCpp::SetOnVsyncCallback(OnVsyncCallback callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_vsync_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_vsync_adapter_set_on_vsync_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "6lrICN8Xy3t09i36kspCXA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_VSYNC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_vsync_adapter_set_on_vsync_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_on_vsync_callback)) {
        ark_vsync_adapter_set_on_vsync_callback = nullptr;
      } else {
        ark_vsync_adapter_set_on_vsync_callback =
            _struct->set_on_vsync_callback;
      }
    } else {
      ark_vsync_adapter_set_on_vsync_callback =
          reinterpret_cast<ArkVSyncAdapterSetOnVsyncCallbackFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_vsync_adapter_set_on_vsync_callback,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_vsync_adapter_set_on_vsync_callback(_struct, callback);
}

ARK_WEB_NO_SANITIZE
void ArkVSyncAdapterCToCpp::SetOnVsyncEndCallback(
    OnVsyncCallback onVsyncEndCallback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_vsync_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_vsync_adapter_set_on_vsync_end_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "7PITqrr_tsCznA_Z7_wyaQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_VSYNC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_vsync_adapter_set_on_vsync_end_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_on_vsync_end_callback)) {
        ark_vsync_adapter_set_on_vsync_end_callback = nullptr;
      } else {
        ark_vsync_adapter_set_on_vsync_end_callback =
            _struct->set_on_vsync_end_callback;
      }
    } else {
      ark_vsync_adapter_set_on_vsync_end_callback =
          reinterpret_cast<ArkVSyncAdapterSetOnVsyncEndCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_vsync_adapter_set_on_vsync_end_callback,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_vsync_adapter_set_on_vsync_end_callback(_struct, onVsyncEndCallback);
}

ARK_WEB_NO_SANITIZE
void ArkVSyncAdapterCToCpp::SetScene(const ArkWebString& sceneName,
                                     uint32_t state) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_vsync_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_vsync_adapter_set_scene);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "9wLTtTtBKPFhNJpg_kbxtw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_VSYNC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_vsync_adapter_set_scene");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_scene)) {
        ark_vsync_adapter_set_scene = nullptr;
      } else {
        ark_vsync_adapter_set_scene = _struct->set_scene;
      }
    } else {
      ark_vsync_adapter_set_scene =
          reinterpret_cast<ArkVSyncAdapterSetSceneFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_vsync_adapter_set_scene,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_vsync_adapter_set_scene(_struct, &sceneName, state);
}

ARK_WEB_NO_SANITIZE
void ArkVSyncAdapterCToCpp::SetDVSyncSwitch(bool dvsyncSwitch) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_vsync_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_vsync_adapter_set_dvsync_switch);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "7Ucu_XDSq$2iKoyrizikWA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_VSYNC_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_vsync_adapter_set_dvsync_switch");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_dvsync_switch)) {
        ark_vsync_adapter_set_dvsync_switch = nullptr;
      } else {
        ark_vsync_adapter_set_dvsync_switch = _struct->set_dvsync_switch;
      }
    } else {
      ark_vsync_adapter_set_dvsync_switch =
          reinterpret_cast<ArkVSyncAdapterSetDVSyncSwitchFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_vsync_adapter_set_dvsync_switch,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_vsync_adapter_set_dvsync_switch(_struct, dvsyncSwitch);
}

ArkVSyncAdapterCToCpp::ArkVSyncAdapterCToCpp() {}

ArkVSyncAdapterCToCpp::~ArkVSyncAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkVSyncAdapterCToCpp,
                                        ArkVSyncAdapter,
                                        ark_vsync_adapter_t>::kBridgeType =
    ARK_VSYNC_ADAPTER;

}  // namespace OHOS::ArkWeb
