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

#include "ohos_adapter/ctocpp/ark_aafwk_browser_client_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkAafwkBrowserClientAdapterQueryRenderSurfaceFunc =
    void* (*)(struct _ark_aafwk_browser_client_adapter_t* self,
              int32_t surface_id);
static ArkAafwkBrowserClientAdapterQueryRenderSurfaceFunc
    ark_aafwk_browser_client_adapter_query_render_surface =
        reinterpret_cast<ArkAafwkBrowserClientAdapterQueryRenderSurfaceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAafwkBrowserClientAdapterReportThreadFunc =
    void (*)(struct _ark_aafwk_browser_client_adapter_t* self,
             int32_t status,
             int32_t process_id,
             int32_t thread_id,
             int32_t role);
static ArkAafwkBrowserClientAdapterReportThreadFunc
    ark_aafwk_browser_client_adapter_report_thread =
        reinterpret_cast<ArkAafwkBrowserClientAdapterReportThreadFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAafwkBrowserClientAdapterPassSurfaceFunc =
    void (*)(struct _ark_aafwk_browser_client_adapter_t* self,
             int64_t surface_id);
static ArkAafwkBrowserClientAdapterPassSurfaceFunc
    ark_aafwk_browser_client_adapter_pass_surface =
        reinterpret_cast<ArkAafwkBrowserClientAdapterPassSurfaceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkAafwkBrowserClientAdapterDestroyRenderSurfaceFunc =
    void (*)(struct _ark_aafwk_browser_client_adapter_t* self,
             int32_t surface_id);
static ArkAafwkBrowserClientAdapterDestroyRenderSurfaceFunc
    ark_aafwk_browser_client_adapter_destroy_render_surface =
        reinterpret_cast<ArkAafwkBrowserClientAdapterDestroyRenderSurfaceFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void* ArkAafwkBrowserClientAdapterCToCpp::QueryRenderSurface(
    int32_t surface_id) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_aafwk_browser_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_aafwk_browser_client_adapter_query_render_surface);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "frbTN1X7gJJyaIrlP0FZqA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AAFWK_BROWSER_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_aafwk_browser_client_adapter_query_render_surface");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, query_render_surface)) {
        ark_aafwk_browser_client_adapter_query_render_surface = nullptr;
      } else {
        ark_aafwk_browser_client_adapter_query_render_surface =
            _struct->query_render_surface;
      }
    } else {
      ark_aafwk_browser_client_adapter_query_render_surface =
          reinterpret_cast<ArkAafwkBrowserClientAdapterQueryRenderSurfaceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_aafwk_browser_client_adapter_query_render_surface, nullptr);

  // Execute
  return ark_aafwk_browser_client_adapter_query_render_surface(_struct,
                                                               surface_id);
}

ARK_WEB_NO_SANITIZE
void ArkAafwkBrowserClientAdapterCToCpp::ReportThread(int32_t status,
                                                      int32_t process_id,
                                                      int32_t thread_id,
                                                      int32_t role) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_aafwk_browser_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_aafwk_browser_client_adapter_report_thread);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "SP_3H2dz0FW7QD65_Z5OxA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AAFWK_BROWSER_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_aafwk_browser_client_adapter_report_thread");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, report_thread)) {
        ark_aafwk_browser_client_adapter_report_thread = nullptr;
      } else {
        ark_aafwk_browser_client_adapter_report_thread = _struct->report_thread;
      }
    } else {
      ark_aafwk_browser_client_adapter_report_thread =
          reinterpret_cast<ArkAafwkBrowserClientAdapterReportThreadFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_aafwk_browser_client_adapter_report_thread, ARK_WEB_RETURN_VOID);

  // Execute
  ark_aafwk_browser_client_adapter_report_thread(_struct, status, process_id,
                                                 thread_id, role);
}

ARK_WEB_NO_SANITIZE
void ArkAafwkBrowserClientAdapterCToCpp::PassSurface(int64_t surface_id) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_aafwk_browser_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_aafwk_browser_client_adapter_pass_surface);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Yx_3O8fjp$qMaTA9aDEx1g";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AAFWK_BROWSER_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_aafwk_browser_client_adapter_pass_surface");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, pass_surface)) {
        ark_aafwk_browser_client_adapter_pass_surface = nullptr;
      } else {
        ark_aafwk_browser_client_adapter_pass_surface = _struct->pass_surface;
      }
    } else {
      ark_aafwk_browser_client_adapter_pass_surface =
          reinterpret_cast<ArkAafwkBrowserClientAdapterPassSurfaceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_aafwk_browser_client_adapter_pass_surface, ARK_WEB_RETURN_VOID);

  // Execute
  ark_aafwk_browser_client_adapter_pass_surface(_struct, surface_id);
}

ARK_WEB_NO_SANITIZE
void ArkAafwkBrowserClientAdapterCToCpp::DestroyRenderSurface(
    int32_t surface_id) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_aafwk_browser_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_aafwk_browser_client_adapter_destroy_render_surface);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "OXMukKDY_GJIcKbfSFIrTQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_AAFWK_BROWSER_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_aafwk_browser_client_adapter_destroy_render_surface");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, destroy_render_surface)) {
        ark_aafwk_browser_client_adapter_destroy_render_surface = nullptr;
      } else {
        ark_aafwk_browser_client_adapter_destroy_render_surface =
            _struct->destroy_render_surface;
      }
    } else {
      ark_aafwk_browser_client_adapter_destroy_render_surface =
          reinterpret_cast<
              ArkAafwkBrowserClientAdapterDestroyRenderSurfaceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_aafwk_browser_client_adapter_destroy_render_surface,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_aafwk_browser_client_adapter_destroy_render_surface(_struct, surface_id);
}

ArkAafwkBrowserClientAdapterCToCpp::ArkAafwkBrowserClientAdapterCToCpp() {}

ArkAafwkBrowserClientAdapterCToCpp::~ArkAafwkBrowserClientAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkAafwkBrowserClientAdapterCToCpp,
                           ArkAafwkBrowserClientAdapter,
                           ark_aafwk_browser_client_adapter_t>::kBridgeType =
        ARK_AAFWK_BROWSER_CLIENT_ADAPTER;

}  // namespace OHOS::ArkWeb
