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

#include "ohos_adapter/ctocpp/ark_aafwk_app_mgr_client_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_aafwk_browser_host_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_aafwk_render_scheduler_host_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkAafwkAppMgrClientAdapterStartRenderProcessFunc =
    int (*)(struct _ark_aafwk_app_mgr_client_adapter_t* self,
            const ArkWebString* renderParam,
            int32_t ipcFd,
            int32_t sharedFd,
            int32_t crashFd,
            pid_t* renderPid);
static ArkAafwkAppMgrClientAdapterStartRenderProcessFunc
    ark_aafwk_app_mgr_client_adapter_start_render_process =
        reinterpret_cast<ArkAafwkAppMgrClientAdapterStartRenderProcessFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAafwkAppMgrClientAdapterAttachRenderProcessFunc =
    void (*)(struct _ark_aafwk_app_mgr_client_adapter_t* self,
             ark_aafwk_render_scheduler_host_adapter_t* adapter);
static ArkAafwkAppMgrClientAdapterAttachRenderProcessFunc
    ark_aafwk_app_mgr_client_adapter_attach_render_process =
        reinterpret_cast<ArkAafwkAppMgrClientAdapterAttachRenderProcessFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAafwkAppMgrClientAdapterGetRenderProcessTerminationStatusFunc =
    int (*)(struct _ark_aafwk_app_mgr_client_adapter_t* self,
            pid_t renderPid,
            int* status);
static ArkAafwkAppMgrClientAdapterGetRenderProcessTerminationStatusFunc
    ark_aafwk_app_mgr_client_adapter_get_render_process_termination_status =
        reinterpret_cast<
            ArkAafwkAppMgrClientAdapterGetRenderProcessTerminationStatusFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAafwkAppMgrClientAdapterStartChildProcessFunc =
    int (*)(struct _ark_aafwk_app_mgr_client_adapter_t* self,
            const ArkWebString* renderParam,
            int32_t ipcFd,
            int32_t sharedFd,
            int32_t crashFd,
            pid_t* renderPid,
            const ArkWebString* processType);
static ArkAafwkAppMgrClientAdapterStartChildProcessFunc
    ark_aafwk_app_mgr_client_adapter_start_child_process =
        reinterpret_cast<ArkAafwkAppMgrClientAdapterStartChildProcessFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAafwkAppMgrClientAdapterSaveBrowserConnectFunc =
    void (*)(struct _ark_aafwk_app_mgr_client_adapter_t* self,
             ark_aafwk_browser_host_adapter_t* adapter);
static ArkAafwkAppMgrClientAdapterSaveBrowserConnectFunc
    ark_aafwk_app_mgr_client_adapter_save_browser_connect =
        reinterpret_cast<ArkAafwkAppMgrClientAdapterSaveBrowserConnectFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int ArkAafwkAppMgrClientAdapterCToCpp::StartRenderProcess(
    const ArkWebString& renderParam,
    int32_t ipcFd,
    int32_t sharedFd,
    int32_t crashFd,
    pid_t& renderPid) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_aafwk_app_mgr_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_aafwk_app_mgr_client_adapter_start_render_process);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "DswvNLbqhCWHK5JV80tunQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AAFWK_APP_MGR_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_aafwk_app_mgr_client_adapter_start_render_process");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start_render_process)) {
        ark_aafwk_app_mgr_client_adapter_start_render_process = nullptr;
      } else {
        ark_aafwk_app_mgr_client_adapter_start_render_process =
            _struct->start_render_process;
      }
    } else {
      ark_aafwk_app_mgr_client_adapter_start_render_process =
          reinterpret_cast<ArkAafwkAppMgrClientAdapterStartRenderProcessFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_aafwk_app_mgr_client_adapter_start_render_process, 0);

  // Execute
  return ark_aafwk_app_mgr_client_adapter_start_render_process(
      _struct, &renderParam, ipcFd, sharedFd, crashFd, &renderPid);
}

ARK_WEB_NO_SANITIZE
void ArkAafwkAppMgrClientAdapterCToCpp::AttachRenderProcess(
    ArkWebRefPtr<ArkAafwkRenderSchedulerHostAdapter> adapter) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_aafwk_app_mgr_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_aafwk_app_mgr_client_adapter_attach_render_process);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "A8Xt8hwoH4AE3rB4ObmkgA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AAFWK_APP_MGR_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_aafwk_app_mgr_client_adapter_attach_render_process");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, attach_render_process)) {
        ark_aafwk_app_mgr_client_adapter_attach_render_process = nullptr;
      } else {
        ark_aafwk_app_mgr_client_adapter_attach_render_process =
            _struct->attach_render_process;
      }
    } else {
      ark_aafwk_app_mgr_client_adapter_attach_render_process =
          reinterpret_cast<ArkAafwkAppMgrClientAdapterAttachRenderProcessFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_aafwk_app_mgr_client_adapter_attach_render_process,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_aafwk_app_mgr_client_adapter_attach_render_process(
      _struct, ArkAafwkRenderSchedulerHostAdapterCppToC::Invert(adapter));
}

ARK_WEB_NO_SANITIZE
int ArkAafwkAppMgrClientAdapterCToCpp::GetRenderProcessTerminationStatus(
    pid_t renderPid,
    int& status) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_aafwk_app_mgr_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_aafwk_app_mgr_client_adapter_get_render_process_termination_status);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Wrc07ImHADMU9IPW9LIjqA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AAFWK_APP_MGR_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_aafwk_app_mgr_client_adapter_get_render_process_termination_"
          "status");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_render_process_termination_status)) {
        ark_aafwk_app_mgr_client_adapter_get_render_process_termination_status =
            nullptr;
      } else {
        ark_aafwk_app_mgr_client_adapter_get_render_process_termination_status =
            _struct->get_render_process_termination_status;
      }
    } else {
      ark_aafwk_app_mgr_client_adapter_get_render_process_termination_status =
          reinterpret_cast<
              ArkAafwkAppMgrClientAdapterGetRenderProcessTerminationStatusFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_aafwk_app_mgr_client_adapter_get_render_process_termination_status,
      0);

  // Execute
  return ark_aafwk_app_mgr_client_adapter_get_render_process_termination_status(
      _struct, renderPid, &status);
}

ARK_WEB_NO_SANITIZE
int ArkAafwkAppMgrClientAdapterCToCpp::StartChildProcess(
    const ArkWebString& renderParam,
    int32_t ipcFd,
    int32_t sharedFd,
    int32_t crashFd,
    pid_t& renderPid,
    const ArkWebString& processType) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_aafwk_app_mgr_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_aafwk_app_mgr_client_adapter_start_child_process);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "WwpwgCHKm8lcKf$EpQLOGg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AAFWK_APP_MGR_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_aafwk_app_mgr_client_adapter_start_child_process");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start_child_process)) {
        ark_aafwk_app_mgr_client_adapter_start_child_process = nullptr;
      } else {
        ark_aafwk_app_mgr_client_adapter_start_child_process =
            _struct->start_child_process;
      }
    } else {
      ark_aafwk_app_mgr_client_adapter_start_child_process =
          reinterpret_cast<ArkAafwkAppMgrClientAdapterStartChildProcessFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_aafwk_app_mgr_client_adapter_start_child_process, 0);

  // Execute
  return ark_aafwk_app_mgr_client_adapter_start_child_process(
      _struct, &renderParam, ipcFd, sharedFd, crashFd, &renderPid,
      &processType);
}

ARK_WEB_NO_SANITIZE
void ArkAafwkAppMgrClientAdapterCToCpp::SaveBrowserConnect(
    ArkWebRefPtr<ArkAafwkBrowserHostAdapter> adapter) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_aafwk_app_mgr_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_aafwk_app_mgr_client_adapter_save_browser_connect);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "0WdidTbyDvA$ntfal9rYkQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AAFWK_APP_MGR_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_aafwk_app_mgr_client_adapter_save_browser_connect");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, save_browser_connect)) {
        ark_aafwk_app_mgr_client_adapter_save_browser_connect = nullptr;
      } else {
        ark_aafwk_app_mgr_client_adapter_save_browser_connect =
            _struct->save_browser_connect;
      }
    } else {
      ark_aafwk_app_mgr_client_adapter_save_browser_connect =
          reinterpret_cast<ArkAafwkAppMgrClientAdapterSaveBrowserConnectFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_aafwk_app_mgr_client_adapter_save_browser_connect,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_aafwk_app_mgr_client_adapter_save_browser_connect(
      _struct, ArkAafwkBrowserHostAdapterCppToC::Invert(adapter));
}

ArkAafwkAppMgrClientAdapterCToCpp::ArkAafwkAppMgrClientAdapterCToCpp() {}

ArkAafwkAppMgrClientAdapterCToCpp::~ArkAafwkAppMgrClientAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkAafwkAppMgrClientAdapterCToCpp,
                           ArkAafwkAppMgrClientAdapter,
                           ark_aafwk_app_mgr_client_adapter_t>::kBridgeType =
        ARK_AAFWK_APP_MGR_CLIENT_ADAPTER;

}  // namespace OHOS::ArkWeb
