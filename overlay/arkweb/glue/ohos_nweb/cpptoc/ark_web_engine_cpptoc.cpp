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

#include "ohos_nweb/cpptoc/ark_web_engine_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"
#include "ohos_nweb/cpptoc/ark_web_ads_block_manager_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_cookie_manager_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_data_base_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_download_manager_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_nweb_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_web_storage_cpptoc.h"
#include "ohos_nweb/ctocpp/ark_web_engine_init_args_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_engine_prefetch_args_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_nweb_create_info_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_proxy_changed_callback_ctocpp.h"

namespace OHOS::ArkWeb {

ark_web_engine_t* ark_web_engine_get_instance() {
  // Execute
  ArkWebRefPtr<ArkWebEngine> _retval = ArkWebEngine::GetInstance();

  // Return type: refptr_same
  return ArkWebEngineCppToC::Invert(_retval);
}

namespace {

ark_web_nweb_t* ARK_WEB_CALLBACK
ark_web_engine_create_nweb(struct _ark_web_engine_t* self,
                           ark_web_nweb_create_info_t* create_info) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebNWeb> _retval = ArkWebEngineCppToC::Get(self)->CreateNWeb(
      ArkWebNWebCreateInfoCToCpp::Invert(create_info));

  // Return type: refptr_same
  return ArkWebNWebCppToC::Invert(_retval);
}

ark_web_nweb_t* ARK_WEB_CALLBACK
ark_web_engine_get_nweb(struct _ark_web_engine_t* self, int32_t nweb_id) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebNWeb> _retval =
      ArkWebEngineCppToC::Get(self)->GetNWeb(nweb_id);

  // Return type: refptr_same
  return ArkWebNWebCppToC::Invert(_retval);
}

ark_web_data_base_t* ARK_WEB_CALLBACK
ark_web_engine_get_data_base(struct _ark_web_engine_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebDataBase> _retval =
      ArkWebEngineCppToC::Get(self)->GetDataBase();

  // Return type: refptr_same
  return ArkWebDataBaseCppToC::Invert(_retval);
}

ark_web_web_storage_t* ARK_WEB_CALLBACK
ark_web_engine_get_web_storage(struct _ark_web_engine_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebWebStorage> _retval =
      ArkWebEngineCppToC::Get(self)->GetWebStorage();

  // Return type: refptr_same
  return ArkWebWebStorageCppToC::Invert(_retval);
}

ark_web_cookie_manager_t* ARK_WEB_CALLBACK
ark_web_engine_get_cookie_manager(struct _ark_web_engine_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebCookieManager> _retval =
      ArkWebEngineCppToC::Get(self)->GetCookieManager();

  // Return type: refptr_same
  return ArkWebCookieManagerCppToC::Invert(_retval);
}

ark_web_download_manager_t* ARK_WEB_CALLBACK
ark_web_engine_get_download_manager(struct _ark_web_engine_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebDownloadManager> _retval =
      ArkWebEngineCppToC::Get(self)->GetDownloadManager();

  // Return type: refptr_same
  return ArkWebDownloadManagerCppToC::Invert(_retval);
}

void ARK_WEB_CALLBACK ark_web_engine_set_web_tag(struct _ark_web_engine_t* self,
                                                 int32_t nweb_id,
                                                 const char* web_tag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->SetWebTag(nweb_id, web_tag);
}

void ARK_WEB_CALLBACK
ark_web_engine_initialize_web_engine(struct _ark_web_engine_t* self,
                                     ark_web_engine_init_args_t* init_args) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->InitializeWebEngine(
      ArkWebEngineInitArgsCToCpp::Invert(init_args));
}

void ARK_WEB_CALLBACK
ark_web_engine_prepare_for_page_load(struct _ark_web_engine_t* self,
                                     const ArkWebString* url,
                                     bool preconnectable,
                                     int32_t num_sockets) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->PrepareForPageLoad(*url, preconnectable,
                                                    num_sockets);
}

void ARK_WEB_CALLBACK
ark_web_engine_set_web_debugging_access(struct _ark_web_engine_t* self,
                                        bool isEnableDebug) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->SetWebDebuggingAccess(isEnableDebug);
}

void ARK_WEB_CALLBACK
ark_web_engine_add_intelligent_tracking_prevention_bypassing_list(
    struct _ark_web_engine_t* self,
    const ArkWebStringVector* hosts) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(hosts, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->AddIntelligentTrackingPreventionBypassingList(
      *hosts);
}

void ARK_WEB_CALLBACK
ark_web_engine_remove_intelligent_tracking_prevention_bypassing_list(
    struct _ark_web_engine_t* self,
    const ArkWebStringVector* hosts) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(hosts, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)
      ->RemoveIntelligentTrackingPreventionBypassingList(*hosts);
}

void ARK_WEB_CALLBACK
ark_web_engine_clear_intelligent_tracking_prevention_bypassing_list(
    struct _ark_web_engine_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)
      ->ClearIntelligentTrackingPreventionBypassingList();
}

void ARK_WEB_CALLBACK
ark_web_engine_pause_all_timers(struct _ark_web_engine_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->PauseAllTimers();
}

void ARK_WEB_CALLBACK
ark_web_engine_resume_all_timers(struct _ark_web_engine_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->ResumeAllTimers();
}

void ARK_WEB_CALLBACK
ark_web_engine_prefetch_resource(struct _ark_web_engine_t* self,
                                 ark_web_engine_prefetch_args_t** pre_args,
                                 const ArkWebStringMap* additional_http_headers,
                                 const ArkWebString* cache_key,
                                 const uint32_t* cache_valid_time) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(pre_args, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(additional_http_headers, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(cache_key, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(cache_valid_time, ARK_WEB_RETURN_VOID);
  // Translate param: pre_args; type: refptr_diff_byref
  ArkWebRefPtr<ArkWebEnginePrefetchArgs> pre_argsPtr;
  if (pre_args && *pre_args) {
    pre_argsPtr = ArkWebEnginePrefetchArgsCToCpp::Invert(*pre_args);
  }
  ArkWebEnginePrefetchArgs* pre_argsOrig = pre_argsPtr.get();

  // Execute
  ArkWebEngineCppToC::Get(self)->PrefetchResource(
      pre_argsPtr, *additional_http_headers, *cache_key, *cache_valid_time);

  // Restore param: pre_args; type: refptr_diff_byref
  if (pre_args) {
    if (pre_argsPtr.get()) {
      if (pre_argsPtr.get() != pre_argsOrig) {
        *pre_args = ArkWebEnginePrefetchArgsCToCpp::Revert(pre_argsPtr);
      }
    } else {
      *pre_args = nullptr;
    }
  }
}

void ARK_WEB_CALLBACK
ark_web_engine_set_render_process_mode(struct _ark_web_engine_t* self,
                                       int32_t mode) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->SetRenderProcessMode(mode);
}

int32_t ARK_WEB_CALLBACK
ark_web_engine_get_render_process_mode(struct _ark_web_engine_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebEngineCppToC::Get(self)->GetRenderProcessMode();
}

void ARK_WEB_CALLBACK ark_web_engine_clear_prefetched_resource(
    struct _ark_web_engine_t* self,
    const ArkWebStringVector* cache_key_list) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(cache_key_list, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->ClearPrefetchedResource(*cache_key_list);
}

void ARK_WEB_CALLBACK
ark_web_engine_warmup_service_worker(struct _ark_web_engine_t* self,
                                     const ArkWebString* url) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->WarmupServiceWorker(*url);
}

void ARK_WEB_CALLBACK ark_web_engine_set_host_ip(struct _ark_web_engine_t* self,
                                                 const ArkWebString* hostName,
                                                 const ArkWebString* address,
                                                 int32_t aliveTime) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(hostName, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(address, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->SetHostIP(*hostName, *address, aliveTime);
}

void ARK_WEB_CALLBACK
ark_web_engine_clear_host_ip(struct _ark_web_engine_t* self,
                             const ArkWebString* hostName) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(hostName, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->ClearHostIP(*hostName);
}

void ARK_WEB_CALLBACK
ark_web_engine_enable_whole_web_page_drawing(struct _ark_web_engine_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->EnableWholeWebPageDrawing();
}

ark_web_ads_block_manager_t* ARK_WEB_CALLBACK
ark_web_engine_get_ads_block_manager(struct _ark_web_engine_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebAdsBlockManager> _retval =
      ArkWebEngineCppToC::Get(self)->GetAdsBlockManager();

  // Return type: refptr_same
  return ArkWebAdsBlockManagerCppToC::Invert(_retval);
}

void ARK_WEB_CALLBACK
ark_web_engine_trim_memory_by_pressure_level(struct _ark_web_engine_t* self,
                                             int32_t memoryLevel) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->TrimMemoryByPressureLevel(memoryLevel);
}

void ARK_WEB_CALLBACK
ark_web_engine_set_ark_web_rom_api_level(struct _ark_web_engine_t* self,
                                         int apiLevel) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->SetArkWebRomApiLevel(apiLevel);
}

int ARK_WEB_CALLBACK
ark_web_engine_get_ark_web_core_api_level(struct _ark_web_engine_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebEngineCppToC::Get(self)->GetArkWebCoreApiLevel();
}

ArkWebString ARK_WEB_CALLBACK
ark_web_engine_get_default_user_agent(struct _ark_web_engine_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebEngineCppToC::Get(self)->GetDefaultUserAgent();
}

void ARK_WEB_CALLBACK
ark_web_engine_remove_all_cache(struct _ark_web_engine_t* self,
                                bool include_disk_files) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->RemoveAllCache(include_disk_files);
}

void ARK_WEB_CALLBACK ark_web_engine_set_proxy_override(
    struct _ark_web_engine_t* self,
    const ArkWebStringVector* proxy_urls,
    const ArkWebStringVector* proxy_scheme_filters,
    const ArkWebStringVector* proxy_bypass_rules,
    const bool* reverse_bypass,
    ark_web_proxy_changed_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(proxy_urls, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(proxy_scheme_filters, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(proxy_bypass_rules, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(reverse_bypass, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->SetProxyOverride(
      *proxy_urls, *proxy_scheme_filters, *proxy_bypass_rules, *reverse_bypass,
      ArkWebProxyChangedCallbackCToCpp::Invert(callback));
}

void ARK_WEB_CALLBACK ark_web_engine_remove_proxy_override(
    struct _ark_web_engine_t* self,
    ark_web_proxy_changed_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->RemoveProxyOverride(
      ArkWebProxyChangedCallbackCToCpp::Invert(callback));
}

void ARK_WEB_CALLBACK
ark_web_engine_set_app_custom_user_agent(struct _ark_web_engine_t* self,
                                         const ArkWebString* userAgent) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(userAgent, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->SetAppCustomUserAgent(*userAgent);
}

void ARK_WEB_CALLBACK
ark_web_engine_set_user_agent_for_hosts(struct _ark_web_engine_t* self,
                                        const ArkWebString* userAgent,
                                        const ArkWebStringVector* hosts) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(userAgent, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(hosts, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->SetUserAgentForHosts(*userAgent, *hosts);
}

void ARK_WEB_CALLBACK
ark_web_engine_set_web_debugging_access_and_port(struct _ark_web_engine_t* self,
                                                 bool isEnableDebug,
                                                 int32_t port) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->SetWebDebuggingAccessAndPort(isEnableDebug,
                                                              port);
}

uint32_t ARK_WEB_CALLBACK
ark_web_engine_add_blankless_loading_urls(struct _ark_web_engine_t* self,
                                          const ArkWebStringVector* urls) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(urls, 0);

  // Execute
  return ArkWebEngineCppToC::Get(self)->AddBlanklessLoadingUrls(*urls);
}

void ARK_WEB_CALLBACK
ark_web_engine_remove_blankless_loading_urls(struct _ark_web_engine_t* self,
                                             const ArkWebStringVector* urls) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(urls, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->RemoveBlanklessLoadingUrls(*urls);
}

void ARK_WEB_CALLBACK
ark_web_engine_clear_blankless_loading_cache(struct _ark_web_engine_t* self,
                                             const ArkWebStringVector* urls) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(urls, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->ClearBlanklessLoadingCache(*urls);
}

ArkWebString ARK_WEB_CALLBACK
ark_web_engine_check_blank_opt_enable(struct _ark_web_engine_t* self,
                                      const ArkWebString* url,
                                      int32_t nweb_id) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, ark_web_string_default);

  // Execute
  return ArkWebEngineCppToC::Get(self)->CheckBlankOptEnable(*url, nweb_id);
}

void ARK_WEB_CALLBACK ark_web_engine_set_blankless_loading_cache_capacity(
    struct _ark_web_engine_t* self,
    int32_t capacity) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->SetBlanklessLoadingCacheCapacity(capacity);
}

void ARK_WEB_CALLBACK
ark_web_engine_enable_private_network_access(struct _ark_web_engine_t* self,
                                             bool enable) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->EnablePrivateNetworkAccess(enable);
}

bool ARK_WEB_CALLBACK ark_web_engine_is_private_network_access_enabled(
    struct _ark_web_engine_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebEngineCppToC::Get(self)->IsPrivateNetworkAccessEnabled();
}

void ARK_WEB_CALLBACK
ark_web_engine_set_web_destroy_mode(struct _ark_web_engine_t* self,
                                    int32_t mode) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->SetWebDestroyMode(mode);
}

int32_t ARK_WEB_CALLBACK
ark_web_engine_set_site_isolation_mode(struct _ark_web_engine_t* self,
                                       int32_t mode) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebEngineCppToC::Get(self)->SetSiteIsolationMode(mode);
}

int32_t ARK_WEB_CALLBACK
ark_web_engine_get_site_isolation_mode(struct _ark_web_engine_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebEngineCppToC::Get(self)->GetSiteIsolationMode();
}

void ARK_WEB_CALLBACK
ark_web_engine_set_socket_idle_timeout(struct _ark_web_engine_t* self,
                                       int32_t timeout) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebEngineCppToC::Get(self)->SetSocketIdleTimeout(timeout);
}

}  // namespace

ArkWebEngineCppToC::ArkWebEngineCppToC() {
  GetStruct()->create_nweb = ark_web_engine_create_nweb;
  GetStruct()->get_nweb = ark_web_engine_get_nweb;
  GetStruct()->get_data_base = ark_web_engine_get_data_base;
  GetStruct()->get_web_storage = ark_web_engine_get_web_storage;
  GetStruct()->get_cookie_manager = ark_web_engine_get_cookie_manager;
  GetStruct()->get_download_manager = ark_web_engine_get_download_manager;
  GetStruct()->set_web_tag = ark_web_engine_set_web_tag;
  GetStruct()->initialize_web_engine = ark_web_engine_initialize_web_engine;
  GetStruct()->prepare_for_page_load = ark_web_engine_prepare_for_page_load;
  GetStruct()->set_web_debugging_access =
      ark_web_engine_set_web_debugging_access;
  GetStruct()->add_intelligent_tracking_prevention_bypassing_list =
      ark_web_engine_add_intelligent_tracking_prevention_bypassing_list;
  GetStruct()->remove_intelligent_tracking_prevention_bypassing_list =
      ark_web_engine_remove_intelligent_tracking_prevention_bypassing_list;
  GetStruct()->clear_intelligent_tracking_prevention_bypassing_list =
      ark_web_engine_clear_intelligent_tracking_prevention_bypassing_list;
  GetStruct()->pause_all_timers = ark_web_engine_pause_all_timers;
  GetStruct()->resume_all_timers = ark_web_engine_resume_all_timers;
  GetStruct()->prefetch_resource = ark_web_engine_prefetch_resource;
  GetStruct()->set_render_process_mode = ark_web_engine_set_render_process_mode;
  GetStruct()->get_render_process_mode = ark_web_engine_get_render_process_mode;
  GetStruct()->clear_prefetched_resource =
      ark_web_engine_clear_prefetched_resource;
  GetStruct()->warmup_service_worker = ark_web_engine_warmup_service_worker;
  GetStruct()->set_host_ip = ark_web_engine_set_host_ip;
  GetStruct()->clear_host_ip = ark_web_engine_clear_host_ip;
  GetStruct()->enable_whole_web_page_drawing =
      ark_web_engine_enable_whole_web_page_drawing;
  GetStruct()->get_ads_block_manager = ark_web_engine_get_ads_block_manager;
  GetStruct()->trim_memory_by_pressure_level =
      ark_web_engine_trim_memory_by_pressure_level;
  GetStruct()->set_ark_web_rom_api_level =
      ark_web_engine_set_ark_web_rom_api_level;
  GetStruct()->get_ark_web_core_api_level =
      ark_web_engine_get_ark_web_core_api_level;
  GetStruct()->get_default_user_agent = ark_web_engine_get_default_user_agent;
  GetStruct()->remove_all_cache = ark_web_engine_remove_all_cache;
  GetStruct()->set_proxy_override = ark_web_engine_set_proxy_override;
  GetStruct()->remove_proxy_override = ark_web_engine_remove_proxy_override;
  GetStruct()->set_app_custom_user_agent =
      ark_web_engine_set_app_custom_user_agent;
  GetStruct()->set_user_agent_for_hosts =
      ark_web_engine_set_user_agent_for_hosts;
  GetStruct()->set_web_debugging_access_and_port =
      ark_web_engine_set_web_debugging_access_and_port;
  GetStruct()->add_blankless_loading_urls =
      ark_web_engine_add_blankless_loading_urls;
  GetStruct()->remove_blankless_loading_urls =
      ark_web_engine_remove_blankless_loading_urls;
  GetStruct()->clear_blankless_loading_cache =
      ark_web_engine_clear_blankless_loading_cache;
  GetStruct()->check_blank_opt_enable = ark_web_engine_check_blank_opt_enable;
  GetStruct()->set_blankless_loading_cache_capacity =
      ark_web_engine_set_blankless_loading_cache_capacity;
  GetStruct()->enable_private_network_access =
      ark_web_engine_enable_private_network_access;
  GetStruct()->is_private_network_access_enabled =
      ark_web_engine_is_private_network_access_enabled;
  GetStruct()->set_web_destroy_mode = ark_web_engine_set_web_destroy_mode;
  GetStruct()->set_site_isolation_mode = ark_web_engine_set_site_isolation_mode;
  GetStruct()->get_site_isolation_mode = ark_web_engine_get_site_isolation_mode;
  GetStruct()->set_socket_idle_timeout = ark_web_engine_set_socket_idle_timeout;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["H0t$3QYTwSQYoDm29NvgfA"] =
        reinterpret_cast<void*>(ark_web_engine_create_nweb);
    funcMemberMap["YcWb4UGpG0pRNhre4B73ZA"] =
        reinterpret_cast<void*>(ark_web_engine_get_nweb);
    funcMemberMap["3Tww8XgjdZkqfQF43BQvjA"] =
        reinterpret_cast<void*>(ark_web_engine_get_data_base);
    funcMemberMap["_cekhA9_rsNn4500i6uy_g"] =
        reinterpret_cast<void*>(ark_web_engine_get_web_storage);
    funcMemberMap["RXNQWVULMiYRCExFuDXvkg"] =
        reinterpret_cast<void*>(ark_web_engine_get_cookie_manager);
    funcMemberMap["AtFH7teUuv6DODZ_SBIAXg"] =
        reinterpret_cast<void*>(ark_web_engine_get_download_manager);
    funcMemberMap["lH$Fr5GEgUy7p4Bl6OSeaA"] =
        reinterpret_cast<void*>(ark_web_engine_set_web_tag);
    funcMemberMap["2YGSGB3PDCTZi$oARhzg3A"] =
        reinterpret_cast<void*>(ark_web_engine_initialize_web_engine);
    funcMemberMap["qOob8TqhrimKuI7rhWEg7A"] =
        reinterpret_cast<void*>(ark_web_engine_prepare_for_page_load);
    funcMemberMap["x$W96jmZKiaBpcF0IiE2Mw"] =
        reinterpret_cast<void*>(ark_web_engine_set_web_debugging_access);
    funcMemberMap["7NkJDAObJlcKTTPMqotykQ"] = reinterpret_cast<void*>(
        ark_web_engine_add_intelligent_tracking_prevention_bypassing_list);
    funcMemberMap["BSEWpj7ofDztnwVuP91q1Q"] = reinterpret_cast<void*>(
        ark_web_engine_remove_intelligent_tracking_prevention_bypassing_list);
    funcMemberMap["Ifgc_GRboagNZ25UKDqbiw"] = reinterpret_cast<void*>(
        ark_web_engine_clear_intelligent_tracking_prevention_bypassing_list);
    funcMemberMap["pA$nUzizCfEr2gbyU6YadQ"] =
        reinterpret_cast<void*>(ark_web_engine_pause_all_timers);
    funcMemberMap["YKTr1KsWqMKraWRvBg0cUg"] =
        reinterpret_cast<void*>(ark_web_engine_resume_all_timers);
    funcMemberMap["tzWzbj8JubWfP7mwUDdANw"] =
        reinterpret_cast<void*>(ark_web_engine_prefetch_resource);
    funcMemberMap["A4dHVDGrXxu8Z0BgOANJ4g"] =
        reinterpret_cast<void*>(ark_web_engine_set_render_process_mode);
    funcMemberMap["YN7_EgSDirIDdnXneVoPJQ"] =
        reinterpret_cast<void*>(ark_web_engine_get_render_process_mode);
    funcMemberMap["U2mIDii9NDxDjch515VDEg"] =
        reinterpret_cast<void*>(ark_web_engine_clear_prefetched_resource);
    funcMemberMap["1HKVV7dMm7hKQta4SWbbIg"] =
        reinterpret_cast<void*>(ark_web_engine_warmup_service_worker);
    funcMemberMap["MxKBZMoezO1LjOVsHMwiuA"] =
        reinterpret_cast<void*>(ark_web_engine_set_host_ip);
    funcMemberMap["NzsciGI2MX4M0dfsc8kJgw"] =
        reinterpret_cast<void*>(ark_web_engine_clear_host_ip);
    funcMemberMap["7BHTDbi137bWZFIeVX$Hmw"] =
        reinterpret_cast<void*>(ark_web_engine_enable_whole_web_page_drawing);
    funcMemberMap["bxemwWcze5TxvQqejrqmYg"] =
        reinterpret_cast<void*>(ark_web_engine_get_ads_block_manager);
    funcMemberMap["$SXHVV3QULRBuHbJMKRTGw"] =
        reinterpret_cast<void*>(ark_web_engine_trim_memory_by_pressure_level);
    funcMemberMap["H3BoqYcWNg61K0Uc0nzTEQ"] =
        reinterpret_cast<void*>(ark_web_engine_set_ark_web_rom_api_level);
    funcMemberMap["S_kQ91PnECNrA5zw$7sJjw"] =
        reinterpret_cast<void*>(ark_web_engine_get_ark_web_core_api_level);
    funcMemberMap["6_$8obigXiEPVJe7BJfV1w"] =
        reinterpret_cast<void*>(ark_web_engine_get_default_user_agent);
    funcMemberMap["8KiHLowhnIM_35FoGMkbVg"] =
        reinterpret_cast<void*>(ark_web_engine_remove_all_cache);
    funcMemberMap["zvVp2ZtxYcd8X$5YGg9Jkw"] =
        reinterpret_cast<void*>(ark_web_engine_set_proxy_override);
    funcMemberMap["n$9s1bzuIdGrF6$zhLm9Og"] =
        reinterpret_cast<void*>(ark_web_engine_remove_proxy_override);
    funcMemberMap["mdhQvpfjsVDjb2_T_h8KPw"] =
        reinterpret_cast<void*>(ark_web_engine_set_app_custom_user_agent);
    funcMemberMap["_gYUc9rVqQwaZunYZ79AmA"] =
        reinterpret_cast<void*>(ark_web_engine_set_user_agent_for_hosts);
    funcMemberMap["jw0NehoDRGFAxHwXCKxeqw"] = reinterpret_cast<void*>(
        ark_web_engine_set_web_debugging_access_and_port);
    funcMemberMap["l89xjzYzhzokufKvSSBhGg"] =
        reinterpret_cast<void*>(ark_web_engine_add_blankless_loading_urls);
    funcMemberMap["KCAAJ9QPj9fXfYSUgG2yAw"] =
        reinterpret_cast<void*>(ark_web_engine_remove_blankless_loading_urls);
    funcMemberMap["cDLXr_Hpl_LSB0knuSoWyg"] =
        reinterpret_cast<void*>(ark_web_engine_clear_blankless_loading_cache);
    funcMemberMap["zOJsuojl8iY81BXTTavF4A"] =
        reinterpret_cast<void*>(ark_web_engine_check_blank_opt_enable);
    funcMemberMap["jcRWgVC_VOKPTZ6djlwqbQ"] = reinterpret_cast<void*>(
        ark_web_engine_set_blankless_loading_cache_capacity);
    funcMemberMap["iNszQYt7giz9zZwEGtijdQ"] =
        reinterpret_cast<void*>(ark_web_engine_enable_private_network_access);
    funcMemberMap["YAXIhLTwL3NQMyxjqpFPwg"] = reinterpret_cast<void*>(
        ark_web_engine_is_private_network_access_enabled);
    funcMemberMap["7OldmonzthUSqW2dFiznEg"] =
        reinterpret_cast<void*>(ark_web_engine_set_web_destroy_mode);
    funcMemberMap["1$aT85n8AnSVM2WtAfblRQ"] =
        reinterpret_cast<void*>(ark_web_engine_set_site_isolation_mode);
    funcMemberMap["IIM7XthMc9r1DG3IV7ugrQ"] =
        reinterpret_cast<void*>(ark_web_engine_get_site_isolation_mode);
    funcMemberMap["Wt7xNBLGfie2Z7$9LPeLyA"] =
        reinterpret_cast<void*>(ark_web_engine_set_socket_idle_timeout);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_ENGINE, funcMemberMap);
  });
}

ArkWebEngineCppToC::~ArkWebEngineCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<ArkWebEngineCppToC,
                                        ArkWebEngine,
                                        ark_web_engine_t>::kBridgeType =
    ARK_WEB_ENGINE;

}  // namespace OHOS::ArkWeb

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

ARK_WEB_EXPORT ark_web_engine_t* ark_web_engine_get_instance_static() {
  ARK_WEB_CPPTOC_DV_LOG();

  return OHOS::ArkWeb::ark_web_engine_get_instance();
}

#ifdef __cplusplus
}
#endif  // __cplusplus
