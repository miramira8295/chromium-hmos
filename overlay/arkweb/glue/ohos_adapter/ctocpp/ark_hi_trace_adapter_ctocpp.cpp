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

#include "ohos_adapter/ctocpp/ark_hi_trace_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkHiTraceAdapterStartTraceFunc =
    void (*)(struct _ark_hi_trace_adapter_t* self,
             const ArkWebString* value,
             float limit);
static ArkHiTraceAdapterStartTraceFunc ark_hi_trace_adapter_start_trace =
    reinterpret_cast<ArkHiTraceAdapterStartTraceFunc>(ARK_WEB_INIT_ADDR);

using ArkHiTraceAdapterFinishTraceFunc =
    void (*)(struct _ark_hi_trace_adapter_t* self);
static ArkHiTraceAdapterFinishTraceFunc ark_hi_trace_adapter_finish_trace =
    reinterpret_cast<ArkHiTraceAdapterFinishTraceFunc>(ARK_WEB_INIT_ADDR);

using ArkHiTraceAdapterStartAsyncTraceFunc =
    void (*)(struct _ark_hi_trace_adapter_t* self,
             const ArkWebString* value,
             int32_t taskId,
             float limit);
static ArkHiTraceAdapterStartAsyncTraceFunc
    ark_hi_trace_adapter_start_async_trace =
        reinterpret_cast<ArkHiTraceAdapterStartAsyncTraceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkHiTraceAdapterFinishAsyncTraceFunc =
    void (*)(struct _ark_hi_trace_adapter_t* self,
             const ArkWebString* value,
             int32_t taskId);
static ArkHiTraceAdapterFinishAsyncTraceFunc
    ark_hi_trace_adapter_finish_async_trace =
        reinterpret_cast<ArkHiTraceAdapterFinishAsyncTraceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkHiTraceAdapterCountTraceFunc =
    void (*)(struct _ark_hi_trace_adapter_t* self,
             const ArkWebString* name,
             int64_t count);
static ArkHiTraceAdapterCountTraceFunc ark_hi_trace_adapter_count_trace =
    reinterpret_cast<ArkHiTraceAdapterCountTraceFunc>(ARK_WEB_INIT_ADDR);

using ArkHiTraceAdapterIsHiTraceEnableFunc =
    bool (*)(struct _ark_hi_trace_adapter_t* self);
static ArkHiTraceAdapterIsHiTraceEnableFunc
    ark_hi_trace_adapter_is_hi_trace_enable =
        reinterpret_cast<ArkHiTraceAdapterIsHiTraceEnableFunc>(
            ARK_WEB_INIT_ADDR);

using ArkHiTraceAdapterStartOHOSTraceFunc =
    void (*)(struct _ark_hi_trace_adapter_t* self,
             const ArkWebString* value,
             float limit);
static ArkHiTraceAdapterStartOHOSTraceFunc
    ark_hi_trace_adapter_start_ohostrace =
        reinterpret_cast<ArkHiTraceAdapterStartOHOSTraceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkHiTraceAdapterFinishOHOSTraceFunc =
    void (*)(struct _ark_hi_trace_adapter_t* self);
static ArkHiTraceAdapterFinishOHOSTraceFunc
    ark_hi_trace_adapter_finish_ohostrace =
        reinterpret_cast<ArkHiTraceAdapterFinishOHOSTraceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkHiTraceAdapterCountOHOSTraceFunc =
    void (*)(struct _ark_hi_trace_adapter_t* self,
             const ArkWebString* name,
             int64_t count);
static ArkHiTraceAdapterCountOHOSTraceFunc
    ark_hi_trace_adapter_count_ohostrace =
        reinterpret_cast<ArkHiTraceAdapterCountOHOSTraceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkHiTraceAdapterIsACETraceEnableFunc =
    bool (*)(struct _ark_hi_trace_adapter_t* self);
static ArkHiTraceAdapterIsACETraceEnableFunc
    ark_hi_trace_adapter_is_acetrace_enable =
        reinterpret_cast<ArkHiTraceAdapterIsACETraceEnableFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkHiTraceAdapterCToCpp::StartTrace(const ArkWebString& value,
                                         float limit) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_trace_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_hi_trace_adapter_start_trace);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "sdb6pJW_WiAeNO9dXXzcrA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_TRACE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_trace_adapter_start_trace");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start_trace)) {
        ark_hi_trace_adapter_start_trace = nullptr;
      } else {
        ark_hi_trace_adapter_start_trace = _struct->start_trace;
      }
    } else {
      ark_hi_trace_adapter_start_trace =
          reinterpret_cast<ArkHiTraceAdapterStartTraceFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_trace_adapter_start_trace,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_hi_trace_adapter_start_trace(_struct, &value, limit);
}

ARK_WEB_NO_SANITIZE
void ArkHiTraceAdapterCToCpp::FinishTrace() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_trace_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_hi_trace_adapter_finish_trace);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "As850vnmg_C1J0BAJwA1Jw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_TRACE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_trace_adapter_finish_trace");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, finish_trace)) {
        ark_hi_trace_adapter_finish_trace = nullptr;
      } else {
        ark_hi_trace_adapter_finish_trace = _struct->finish_trace;
      }
    } else {
      ark_hi_trace_adapter_finish_trace =
          reinterpret_cast<ArkHiTraceAdapterFinishTraceFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_trace_adapter_finish_trace,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_hi_trace_adapter_finish_trace(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkHiTraceAdapterCToCpp::StartAsyncTrace(const ArkWebString& value,
                                              int32_t taskId,
                                              float limit) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_trace_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_hi_trace_adapter_start_async_trace);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "LNFrT7Oxq7C6JjtzzEXM8w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_TRACE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_trace_adapter_start_async_trace");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start_async_trace)) {
        ark_hi_trace_adapter_start_async_trace = nullptr;
      } else {
        ark_hi_trace_adapter_start_async_trace = _struct->start_async_trace;
      }
    } else {
      ark_hi_trace_adapter_start_async_trace =
          reinterpret_cast<ArkHiTraceAdapterStartAsyncTraceFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_trace_adapter_start_async_trace,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_hi_trace_adapter_start_async_trace(_struct, &value, taskId, limit);
}

ARK_WEB_NO_SANITIZE
void ArkHiTraceAdapterCToCpp::FinishAsyncTrace(const ArkWebString& value,
                                               int32_t taskId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_trace_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_hi_trace_adapter_finish_async_trace);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "wJWVPimCUTEYyBdGfMYC9Q";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_TRACE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_trace_adapter_finish_async_trace");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, finish_async_trace)) {
        ark_hi_trace_adapter_finish_async_trace = nullptr;
      } else {
        ark_hi_trace_adapter_finish_async_trace = _struct->finish_async_trace;
      }
    } else {
      ark_hi_trace_adapter_finish_async_trace =
          reinterpret_cast<ArkHiTraceAdapterFinishAsyncTraceFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_trace_adapter_finish_async_trace,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_hi_trace_adapter_finish_async_trace(_struct, &value, taskId);
}

ARK_WEB_NO_SANITIZE
void ArkHiTraceAdapterCToCpp::CountTrace(const ArkWebString& name,
                                         int64_t count) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_trace_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_hi_trace_adapter_count_trace);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "TUMkvN6IfCfX7sBeOwRvQA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_TRACE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_trace_adapter_count_trace");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, count_trace)) {
        ark_hi_trace_adapter_count_trace = nullptr;
      } else {
        ark_hi_trace_adapter_count_trace = _struct->count_trace;
      }
    } else {
      ark_hi_trace_adapter_count_trace =
          reinterpret_cast<ArkHiTraceAdapterCountTraceFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_trace_adapter_count_trace,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_hi_trace_adapter_count_trace(_struct, &name, count);
}

ARK_WEB_NO_SANITIZE
bool ArkHiTraceAdapterCToCpp::IsHiTraceEnable() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_trace_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_hi_trace_adapter_is_hi_trace_enable);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "dKyEzRzQ$2h6qMxduX3AGw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_TRACE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_trace_adapter_is_hi_trace_enable");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_hi_trace_enable)) {
        ark_hi_trace_adapter_is_hi_trace_enable = nullptr;
      } else {
        ark_hi_trace_adapter_is_hi_trace_enable = _struct->is_hi_trace_enable;
      }
    } else {
      ark_hi_trace_adapter_is_hi_trace_enable =
          reinterpret_cast<ArkHiTraceAdapterIsHiTraceEnableFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_trace_adapter_is_hi_trace_enable,
                                    false);

  // Execute
  return ark_hi_trace_adapter_is_hi_trace_enable(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkHiTraceAdapterCToCpp::StartOHOSTrace(const ArkWebString& value,
                                             float limit) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_trace_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_hi_trace_adapter_start_ohostrace);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "$ZT$_rwDMceap9O4J3MT2A";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_TRACE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_trace_adapter_start_ohostrace");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start_ohostrace)) {
        ark_hi_trace_adapter_start_ohostrace = nullptr;
      } else {
        ark_hi_trace_adapter_start_ohostrace = _struct->start_ohostrace;
      }
    } else {
      ark_hi_trace_adapter_start_ohostrace =
          reinterpret_cast<ArkHiTraceAdapterStartOHOSTraceFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_trace_adapter_start_ohostrace,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_hi_trace_adapter_start_ohostrace(_struct, &value, limit);
}

ARK_WEB_NO_SANITIZE
void ArkHiTraceAdapterCToCpp::FinishOHOSTrace() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_trace_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_hi_trace_adapter_finish_ohostrace);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "8bYEwDH2CGBNSkba5HbJQg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_TRACE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_trace_adapter_finish_ohostrace");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, finish_ohostrace)) {
        ark_hi_trace_adapter_finish_ohostrace = nullptr;
      } else {
        ark_hi_trace_adapter_finish_ohostrace = _struct->finish_ohostrace;
      }
    } else {
      ark_hi_trace_adapter_finish_ohostrace =
          reinterpret_cast<ArkHiTraceAdapterFinishOHOSTraceFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_trace_adapter_finish_ohostrace,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_hi_trace_adapter_finish_ohostrace(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkHiTraceAdapterCToCpp::CountOHOSTrace(const ArkWebString& name,
                                             int64_t count) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_trace_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_hi_trace_adapter_count_ohostrace);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "VoHV5Uu9YxWV6wrpEslJcw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_TRACE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_trace_adapter_count_ohostrace");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, count_ohostrace)) {
        ark_hi_trace_adapter_count_ohostrace = nullptr;
      } else {
        ark_hi_trace_adapter_count_ohostrace = _struct->count_ohostrace;
      }
    } else {
      ark_hi_trace_adapter_count_ohostrace =
          reinterpret_cast<ArkHiTraceAdapterCountOHOSTraceFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_trace_adapter_count_ohostrace,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_hi_trace_adapter_count_ohostrace(_struct, &name, count);
}

ARK_WEB_NO_SANITIZE
bool ArkHiTraceAdapterCToCpp::IsACETraceEnable() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_trace_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_hi_trace_adapter_is_acetrace_enable);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "kyLKFSBhiuBkVWt5LMFDDg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_TRACE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_trace_adapter_is_acetrace_enable");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_acetrace_enable)) {
        ark_hi_trace_adapter_is_acetrace_enable = nullptr;
      } else {
        ark_hi_trace_adapter_is_acetrace_enable = _struct->is_acetrace_enable;
      }
    } else {
      ark_hi_trace_adapter_is_acetrace_enable =
          reinterpret_cast<ArkHiTraceAdapterIsACETraceEnableFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_trace_adapter_is_acetrace_enable,
                                    false);

  // Execute
  return ark_hi_trace_adapter_is_acetrace_enable(_struct);
}

ArkHiTraceAdapterCToCpp::ArkHiTraceAdapterCToCpp() {}

ArkHiTraceAdapterCToCpp::~ArkHiTraceAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkHiTraceAdapterCToCpp,
                                        ArkHiTraceAdapter,
                                        ark_hi_trace_adapter_t>::kBridgeType =
    ARK_HI_TRACE_ADAPTER;

}  // namespace OHOS::ArkWeb
