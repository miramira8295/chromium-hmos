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

#include "ohos_nweb/ctocpp/ark_web_handler_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"
#include "ohos_nweb/cpptoc/ark_web_access_request_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_app_link_callback_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_console_log_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_context_menu_callback_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_context_menu_params_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_controller_handler_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_cursor_info_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_custom_keyboard_handler_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_data_resubmission_callback_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_date_time_chooser_callback_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_date_time_chooser_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_drag_data_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_file_selector_params_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_first_meaningful_paint_details_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_full_screen_exit_handler_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_geo_location_callback_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_image_options_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_js_all_ssl_error_result_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_js_dialog_result_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_js_http_auth_result_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_js_ssl_error_result_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_js_ssl_select_cert_result_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_key_event_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_largest_contentful_paint_details_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_load_committed_details_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_native_embed_data_info_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_native_embed_mouse_event_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_native_embed_param_data_info_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_native_embed_touch_event_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_native_message_callback_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_nweb_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_quick_menu_callback_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_quick_menu_params_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_runtime_connect_info_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_screen_capture_access_request_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_select_popup_menu_callback_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_select_popup_menu_param_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_string_vector_value_callback_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_touch_handle_hot_zone_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_touch_handle_state_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_url_resource_error_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_url_resource_request_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_url_resource_response_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkWebHandlerSetNWebFunc = void (*)(struct _ark_web_handler_t* self,
                                          ark_web_nweb_t* nweb);
static ArkWebHandlerSetNWebFunc ark_web_handler_set_nweb =
    reinterpret_cast<ArkWebHandlerSetNWebFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnFocusFunc1 = bool (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerOnFocusFunc1 ark_web_handler_on_focus1 =
    reinterpret_cast<ArkWebHandlerOnFocusFunc1>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnMessageFunc = void (*)(struct _ark_web_handler_t* self,
                                            const ArkWebString* param);
static ArkWebHandlerOnMessageFunc ark_web_handler_on_message =
    reinterpret_cast<ArkWebHandlerOnMessageFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnResourceFunc = void (*)(struct _ark_web_handler_t* self,
                                             const ArkWebString* url);
static ArkWebHandlerOnResourceFunc ark_web_handler_on_resource =
    reinterpret_cast<ArkWebHandlerOnResourceFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnPageIconFunc = void (*)(struct _ark_web_handler_t* self,
                                             const void* data,
                                             size_t width,
                                             size_t height,
                                             int color_type,
                                             int alpha_type);
static ArkWebHandlerOnPageIconFunc ark_web_handler_on_page_icon =
    reinterpret_cast<ArkWebHandlerOnPageIconFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnPageTitleFunc = void (*)(struct _ark_web_handler_t* self,
                                              const ArkWebString* title);
static ArkWebHandlerOnPageTitleFunc ark_web_handler_on_page_title =
    reinterpret_cast<ArkWebHandlerOnPageTitleFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnProxyDiedFunc = void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerOnProxyDiedFunc ark_web_handler_on_proxy_died =
    reinterpret_cast<ArkWebHandlerOnProxyDiedFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnHttpErrorFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_url_resource_request_t* request,
             ark_web_url_resource_response_t* error_response);
static ArkWebHandlerOnHttpErrorFunc ark_web_handler_on_http_error =
    reinterpret_cast<ArkWebHandlerOnHttpErrorFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnConsoleLogFunc = bool (*)(struct _ark_web_handler_t* self,
                                               ark_web_console_log_t* message);
static ArkWebHandlerOnConsoleLogFunc ark_web_handler_on_console_log =
    reinterpret_cast<ArkWebHandlerOnConsoleLogFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnRouterPushFunc = void (*)(struct _ark_web_handler_t* self,
                                               const ArkWebString* param);
static ArkWebHandlerOnRouterPushFunc ark_web_handler_on_router_push =
    reinterpret_cast<ArkWebHandlerOnRouterPushFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnPageLoadEndFunc = void (*)(struct _ark_web_handler_t* self,
                                                int http_status_code,
                                                const ArkWebString* url);
static ArkWebHandlerOnPageLoadEndFunc ark_web_handler_on_page_load_end =
    reinterpret_cast<ArkWebHandlerOnPageLoadEndFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnPageLoadBeginFunc =
    void (*)(struct _ark_web_handler_t* self, const ArkWebString* url);
static ArkWebHandlerOnPageLoadBeginFunc ark_web_handler_on_page_load_begin =
    reinterpret_cast<ArkWebHandlerOnPageLoadBeginFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnPageLoadErrorFunc =
    void (*)(struct _ark_web_handler_t* self,
             int error_code,
             const ArkWebString* description,
             const ArkWebString* failing_url);
static ArkWebHandlerOnPageLoadErrorFunc ark_web_handler_on_page_load_error =
    reinterpret_cast<ArkWebHandlerOnPageLoadErrorFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnDesktopIconUrlFunc =
    void (*)(struct _ark_web_handler_t* self,
             const ArkWebString* icon_url,
             bool precomposed);
static ArkWebHandlerOnDesktopIconUrlFunc ark_web_handler_on_desktop_icon_url =
    reinterpret_cast<ArkWebHandlerOnDesktopIconUrlFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnLoadingProgressFunc =
    void (*)(struct _ark_web_handler_t* self, int new_progress);
static ArkWebHandlerOnLoadingProgressFunc ark_web_handler_on_loading_progress =
    reinterpret_cast<ArkWebHandlerOnLoadingProgressFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnGeolocationShowFunc =
    void (*)(struct _ark_web_handler_t* self,
             const ArkWebString* origin,
             ark_web_geo_location_callback_t* callback);
static ArkWebHandlerOnGeolocationShowFunc ark_web_handler_on_geolocation_show =
    reinterpret_cast<ArkWebHandlerOnGeolocationShowFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnGeolocationHideFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerOnGeolocationHideFunc ark_web_handler_on_geolocation_hide =
    reinterpret_cast<ArkWebHandlerOnGeolocationHideFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnFileSelectorShowFunc =
    bool (*)(struct _ark_web_handler_t* self,
             ark_web_string_vector_value_callback_t* callback,
             ark_web_file_selector_params_t* params);
static ArkWebHandlerOnFileSelectorShowFunc
    ark_web_handler_on_file_selector_show =
        reinterpret_cast<ArkWebHandlerOnFileSelectorShowFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnResourceLoadErrorFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_url_resource_request_t* request,
             ark_web_url_resource_error_t* error);
static ArkWebHandlerOnResourceLoadErrorFunc
    ark_web_handler_on_resource_load_error =
        reinterpret_cast<ArkWebHandlerOnResourceLoadErrorFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnPermissionRequestFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_access_request_t* request);
static ArkWebHandlerOnPermissionRequestFunc
    ark_web_handler_on_permission_request =
        reinterpret_cast<ArkWebHandlerOnPermissionRequestFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnQuickMenuDismissedFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerOnQuickMenuDismissedFunc
    ark_web_handler_on_quick_menu_dismissed =
        reinterpret_cast<ArkWebHandlerOnQuickMenuDismissedFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnContextMenuDismissedFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerOnContextMenuDismissedFunc
    ark_web_handler_on_context_menu_dismissed =
        reinterpret_cast<ArkWebHandlerOnContextMenuDismissedFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnTouchSelectionChangedFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_touch_handle_state_t* insert_handle,
             ark_web_touch_handle_state_t* start_selection_handle,
             ark_web_touch_handle_state_t* end_selection_handle);
static ArkWebHandlerOnTouchSelectionChangedFunc
    ark_web_handler_on_touch_selection_changed =
        reinterpret_cast<ArkWebHandlerOnTouchSelectionChangedFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnHandleInterceptRequestFunc =
    bool (*)(struct _ark_web_handler_t* self,
             ark_web_url_resource_request_t* request,
             ark_web_url_resource_response_t* response);
static ArkWebHandlerOnHandleInterceptRequestFunc
    ark_web_handler_on_handle_intercept_request =
        reinterpret_cast<ArkWebHandlerOnHandleInterceptRequestFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnRefreshAccessedHistoryFunc =
    void (*)(struct _ark_web_handler_t* self,
             const ArkWebString* url,
             bool is_reload);
static ArkWebHandlerOnRefreshAccessedHistoryFunc
    ark_web_handler_on_refresh_accessed_history =
        reinterpret_cast<ArkWebHandlerOnRefreshAccessedHistoryFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnPermissionRequestCanceledFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_access_request_t* request);
static ArkWebHandlerOnPermissionRequestCanceledFunc
    ark_web_handler_on_permission_request_canceled =
        reinterpret_cast<ArkWebHandlerOnPermissionRequestCanceledFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnHandleInterceptUrlLoadingFunc =
    bool (*)(struct _ark_web_handler_t* self,
             ark_web_url_resource_request_t* request);
static ArkWebHandlerOnHandleInterceptUrlLoadingFunc
    ark_web_handler_on_handle_intercept_url_loading =
        reinterpret_cast<ArkWebHandlerOnHandleInterceptUrlLoadingFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerRunQuickMenuFunc =
    bool (*)(struct _ark_web_handler_t* self,
             ark_web_quick_menu_params_t* params,
             ark_web_quick_menu_callback_t* callback);
static ArkWebHandlerRunQuickMenuFunc ark_web_handler_run_quick_menu =
    reinterpret_cast<ArkWebHandlerRunQuickMenuFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerRunContextMenuFunc =
    bool (*)(struct _ark_web_handler_t* self,
             ark_web_context_menu_params_t* params,
             ark_web_context_menu_callback_t* callback);
static ArkWebHandlerRunContextMenuFunc ark_web_handler_run_context_menu =
    reinterpret_cast<ArkWebHandlerRunContextMenuFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerUpdateDragCursorFunc =
    void (*)(struct _ark_web_handler_t* self, unsigned char op);
static ArkWebHandlerUpdateDragCursorFunc ark_web_handler_update_drag_cursor =
    reinterpret_cast<ArkWebHandlerUpdateDragCursorFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerFilterScrollEventFunc =
    bool (*)(struct _ark_web_handler_t* self,
             const float x,
             const float y,
             const float x_velocity,
             const float y_velocity);
static ArkWebHandlerFilterScrollEventFunc ark_web_handler_filter_scroll_event =
    reinterpret_cast<ArkWebHandlerFilterScrollEventFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerVisitedUrlHistoryFunc =
    ArkWebStringVector (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerVisitedUrlHistoryFunc ark_web_handler_visited_url_history =
    reinterpret_cast<ArkWebHandlerVisitedUrlHistoryFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnWindowNewByJSFunc =
    void (*)(struct _ark_web_handler_t* self,
             const ArkWebString* target_url,
             bool is_alert,
             bool is_user_trigger,
             ark_web_controller_handler_t* handler);
static ArkWebHandlerOnWindowNewByJSFunc ark_web_handler_on_window_new_by_js =
    reinterpret_cast<ArkWebHandlerOnWindowNewByJSFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnWindowExitByJSFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerOnWindowExitByJSFunc ark_web_handler_on_window_exit_by_js =
    reinterpret_cast<ArkWebHandlerOnWindowExitByJSFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnAlertDialogByJSFunc =
    bool (*)(struct _ark_web_handler_t* self,
             const ArkWebString* url,
             const ArkWebString* message,
             ark_web_js_dialog_result_t* result);
static ArkWebHandlerOnAlertDialogByJSFunc
    ark_web_handler_on_alert_dialog_by_js =
        reinterpret_cast<ArkWebHandlerOnAlertDialogByJSFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnBeforeUnloadByJSFunc =
    bool (*)(struct _ark_web_handler_t* self,
             const ArkWebString* url,
             const ArkWebString* message,
             ark_web_js_dialog_result_t* result);
static ArkWebHandlerOnBeforeUnloadByJSFunc
    ark_web_handler_on_before_unload_by_js =
        reinterpret_cast<ArkWebHandlerOnBeforeUnloadByJSFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnPromptDialogByJSFunc =
    bool (*)(struct _ark_web_handler_t* self,
             const ArkWebString* url,
             const ArkWebString* message,
             const ArkWebString* default_value,
             ark_web_js_dialog_result_t* result);
static ArkWebHandlerOnPromptDialogByJSFunc
    ark_web_handler_on_prompt_dialog_by_js =
        reinterpret_cast<ArkWebHandlerOnPromptDialogByJSFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnConfirmDialogByJSFunc =
    bool (*)(struct _ark_web_handler_t* self,
             const ArkWebString* url,
             const ArkWebString* message,
             ark_web_js_dialog_result_t* result);
static ArkWebHandlerOnConfirmDialogByJSFunc
    ark_web_handler_on_confirm_dialog_by_js =
        reinterpret_cast<ArkWebHandlerOnConfirmDialogByJSFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnHttpAuthRequestByJSFunc =
    bool (*)(struct _ark_web_handler_t* self,
             ark_web_js_http_auth_result_t* result,
             const ArkWebString* host,
             const ArkWebString* realm);
static ArkWebHandlerOnHttpAuthRequestByJSFunc
    ark_web_handler_on_http_auth_request_by_js =
        reinterpret_cast<ArkWebHandlerOnHttpAuthRequestByJSFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnSslErrorRequestByJSFunc =
    bool (*)(struct _ark_web_handler_t* self,
             ark_web_js_ssl_error_result_t* result,
             int error);
static ArkWebHandlerOnSslErrorRequestByJSFunc
    ark_web_handler_on_ssl_error_request_by_js =
        reinterpret_cast<ArkWebHandlerOnSslErrorRequestByJSFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnSslSelectCertRequestByJSFunc =
    bool (*)(struct _ark_web_handler_t* self,
             ark_web_js_ssl_select_cert_result_t* result,
             const ArkWebString* host,
             int port,
             const ArkWebStringVector* key_types,
             const ArkWebStringVector* issuers);
static ArkWebHandlerOnSslSelectCertRequestByJSFunc
    ark_web_handler_on_ssl_select_cert_request_by_js =
        reinterpret_cast<ArkWebHandlerOnSslSelectCertRequestByJSFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnScrollFunc = void (*)(struct _ark_web_handler_t* self,
                                           double x_offset,
                                           double y_offset);
static ArkWebHandlerOnScrollFunc ark_web_handler_on_scroll =
    reinterpret_cast<ArkWebHandlerOnScrollFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnOverScrollFunc1 = void (*)(struct _ark_web_handler_t* self,
                                                float x_offset,
                                                float y_offset);
static ArkWebHandlerOnOverScrollFunc1 ark_web_handler_on_over_scroll1 =
    reinterpret_cast<ArkWebHandlerOnOverScrollFunc1>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnScrollStateFunc = void (*)(struct _ark_web_handler_t* self,
                                                bool scroll_state);
static ArkWebHandlerOnScrollStateFunc ark_web_handler_on_scroll_state =
    reinterpret_cast<ArkWebHandlerOnScrollStateFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnPageVisibleFunc = void (*)(struct _ark_web_handler_t* self,
                                                const ArkWebString* url);
static ArkWebHandlerOnPageVisibleFunc ark_web_handler_on_page_visible =
    reinterpret_cast<ArkWebHandlerOnPageVisibleFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnPreKeyEventFunc = bool (*)(struct _ark_web_handler_t* self,
                                                ark_web_key_event_t* event);
static ArkWebHandlerOnPreKeyEventFunc ark_web_handler_on_pre_key_event =
    reinterpret_cast<ArkWebHandlerOnPreKeyEventFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnScaleChangedFunc =
    void (*)(struct _ark_web_handler_t* self,
             float old_scale_factor,
             float new_scale_factor);
static ArkWebHandlerOnScaleChangedFunc ark_web_handler_on_scale_changed =
    reinterpret_cast<ArkWebHandlerOnScaleChangedFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnCursorChangeFunc =
    bool (*)(struct _ark_web_handler_t* self,
             const int32_t* type,
             ark_web_cursor_info_t* info);
static ArkWebHandlerOnCursorChangeFunc ark_web_handler_on_cursor_change =
    reinterpret_cast<ArkWebHandlerOnCursorChangeFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnRenderExitedFunc =
    void (*)(struct _ark_web_handler_t* self, int reason);
static ArkWebHandlerOnRenderExitedFunc ark_web_handler_on_render_exited =
    reinterpret_cast<ArkWebHandlerOnRenderExitedFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnResizeNotWorkFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerOnResizeNotWorkFunc ark_web_handler_on_resize_not_work =
    reinterpret_cast<ArkWebHandlerOnResizeNotWorkFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnFullScreenExitFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerOnFullScreenExitFunc ark_web_handler_on_full_screen_exit =
    reinterpret_cast<ArkWebHandlerOnFullScreenExitFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnFullScreenEnterFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_full_screen_exit_handler_t* handler);
static ArkWebHandlerOnFullScreenEnterFunc ark_web_handler_on_full_screen_enter =
    reinterpret_cast<ArkWebHandlerOnFullScreenEnterFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnDragAndDropDataFunc =
    bool (*)(struct _ark_web_handler_t* self,
             const void* data,
             size_t len,
             ark_web_image_options_t* opt);
static ArkWebHandlerOnDragAndDropDataFunc
    ark_web_handler_on_drag_and_drop_data =
        reinterpret_cast<ArkWebHandlerOnDragAndDropDataFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnSelectPopupMenuFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_select_popup_menu_param_t* params,
             ark_web_select_popup_menu_callback_t* callback);
static ArkWebHandlerOnSelectPopupMenuFunc ark_web_handler_on_select_popup_menu =
    reinterpret_cast<ArkWebHandlerOnSelectPopupMenuFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnDataResubmissionFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_data_resubmission_callback_t* handler);
static ArkWebHandlerOnDataResubmissionFunc
    ark_web_handler_on_data_resubmission =
        reinterpret_cast<ArkWebHandlerOnDataResubmissionFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnRootLayerChangedFunc =
    void (*)(struct _ark_web_handler_t* self, int width, int height);
static ArkWebHandlerOnRootLayerChangedFunc
    ark_web_handler_on_root_layer_changed =
        reinterpret_cast<ArkWebHandlerOnRootLayerChangedFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnAudioStateChangedFunc =
    void (*)(struct _ark_web_handler_t* self, bool playing);
static ArkWebHandlerOnAudioStateChangedFunc
    ark_web_handler_on_audio_state_changed =
        reinterpret_cast<ArkWebHandlerOnAudioStateChangedFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnOverScrollFlingEndFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerOnOverScrollFlingEndFunc
    ark_web_handler_on_over_scroll_fling_end =
        reinterpret_cast<ArkWebHandlerOnOverScrollFlingEndFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnUnProcessedKeyEventFunc =
    bool (*)(struct _ark_web_handler_t* self, ark_web_key_event_t* event);
static ArkWebHandlerOnUnProcessedKeyEventFunc
    ark_web_handler_on_un_processed_key_event =
        reinterpret_cast<ArkWebHandlerOnUnProcessedKeyEventFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnDragAndDropDataUdmfFunc =
    bool (*)(struct _ark_web_handler_t* self, ark_web_drag_data_t* drag_data);
static ArkWebHandlerOnDragAndDropDataUdmfFunc
    ark_web_handler_on_drag_and_drop_data_udmf =
        reinterpret_cast<ArkWebHandlerOnDragAndDropDataUdmfFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnFirstContentfulPaintFunc =
    void (*)(struct _ark_web_handler_t* self,
             int64_t navigation_start_tick,
             int64_t first_contentful_paint_ms);
static ArkWebHandlerOnFirstContentfulPaintFunc
    ark_web_handler_on_first_contentful_paint =
        reinterpret_cast<ArkWebHandlerOnFirstContentfulPaintFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnDateTimeChooserPopupFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_date_time_chooser_t* chooser,
             const ArkWebDateTimeSuggestionVector* suggestions,
             ark_web_date_time_chooser_callback_t* callback);
static ArkWebHandlerOnDateTimeChooserPopupFunc
    ark_web_handler_on_date_time_chooser_popup =
        reinterpret_cast<ArkWebHandlerOnDateTimeChooserPopupFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnDateTimeChooserCloseFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerOnDateTimeChooserCloseFunc
    ark_web_handler_on_date_time_chooser_close =
        reinterpret_cast<ArkWebHandlerOnDateTimeChooserCloseFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnScreenCaptureRequestFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_screen_capture_access_request_t* request);
static ArkWebHandlerOnScreenCaptureRequestFunc
    ark_web_handler_on_screen_capture_request =
        reinterpret_cast<ArkWebHandlerOnScreenCaptureRequestFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnActivityStateChangedFunc =
    void (*)(struct _ark_web_handler_t* self, int state, int type);
static ArkWebHandlerOnActivityStateChangedFunc
    ark_web_handler_on_activity_state_changed =
        reinterpret_cast<ArkWebHandlerOnActivityStateChangedFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnGetTouchHandleHotZoneFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_touch_handle_hot_zone_t* hot_zone);
static ArkWebHandlerOnGetTouchHandleHotZoneFunc
    ark_web_handler_on_get_touch_handle_hot_zone =
        reinterpret_cast<ArkWebHandlerOnGetTouchHandleHotZoneFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnCompleteSwapWithNewSizeFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerOnCompleteSwapWithNewSizeFunc
    ark_web_handler_on_complete_swap_with_new_size =
        reinterpret_cast<ArkWebHandlerOnCompleteSwapWithNewSizeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnOverScrollFlingVelocityFunc =
    void (*)(struct _ark_web_handler_t* self,
             float x_velocity,
             float y_velocity,
             bool is_fling);
static ArkWebHandlerOnOverScrollFlingVelocityFunc
    ark_web_handler_on_over_scroll_fling_velocity =
        reinterpret_cast<ArkWebHandlerOnOverScrollFlingVelocityFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnNavigationEntryCommittedFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_load_committed_details_t* details);
static ArkWebHandlerOnNavigationEntryCommittedFunc
    ark_web_handler_on_navigation_entry_committed =
        reinterpret_cast<ArkWebHandlerOnNavigationEntryCommittedFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnNativeEmbedLifecycleChangeFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_native_embed_data_info_t* data_info);
static ArkWebHandlerOnNativeEmbedLifecycleChangeFunc
    ark_web_handler_on_native_embed_lifecycle_change =
        reinterpret_cast<ArkWebHandlerOnNativeEmbedLifecycleChangeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnNativeEmbedGestureEventFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_native_embed_touch_event_t* touch_event);
static ArkWebHandlerOnNativeEmbedGestureEventFunc
    ark_web_handler_on_native_embed_gesture_event =
        reinterpret_cast<ArkWebHandlerOnNativeEmbedGestureEventFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnSafeBrowsingCheckResultFunc =
    void (*)(struct _ark_web_handler_t* self, int threat_type);
static ArkWebHandlerOnSafeBrowsingCheckResultFunc
    ark_web_handler_on_safe_browsing_check_result =
        reinterpret_cast<ArkWebHandlerOnSafeBrowsingCheckResultFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnIntelligentTrackingPreventionResultFunc =
    void (*)(struct _ark_web_handler_t* self,
             const ArkWebString* website_host,
             const ArkWebString* tracker_host);
static ArkWebHandlerOnIntelligentTrackingPreventionResultFunc
    ark_web_handler_on_intelligent_tracking_prevention_result =
        reinterpret_cast<
            ArkWebHandlerOnIntelligentTrackingPreventionResultFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnFullScreenEnterWithVideoSizeFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_full_screen_exit_handler_t* handler,
             int video_natural_width,
             int video_natural_height);
static ArkWebHandlerOnFullScreenEnterWithVideoSizeFunc
    ark_web_handler_on_full_screen_enter_with_video_size =
        reinterpret_cast<ArkWebHandlerOnFullScreenEnterWithVideoSizeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnHandleOverrideUrlLoadingFunc =
    bool (*)(struct _ark_web_handler_t* self,
             ark_web_url_resource_request_t* request);
static ArkWebHandlerOnHandleOverrideUrlLoadingFunc
    ark_web_handler_on_handle_override_url_loading =
        reinterpret_cast<ArkWebHandlerOnHandleOverrideUrlLoadingFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnFirstMeaningfulPaintFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_first_meaningful_paint_details_t* details);
static ArkWebHandlerOnFirstMeaningfulPaintFunc
    ark_web_handler_on_first_meaningful_paint =
        reinterpret_cast<ArkWebHandlerOnFirstMeaningfulPaintFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnLargestContentfulPaintFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_largest_contentful_paint_details_t* details);
static ArkWebHandlerOnLargestContentfulPaintFunc
    ark_web_handler_on_largest_contentful_paint =
        reinterpret_cast<ArkWebHandlerOnLargestContentfulPaintFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnAllSslErrorRequestByJSFunc =
    bool (*)(struct _ark_web_handler_t* self,
             ark_web_js_all_ssl_error_result_t* result,
             int error,
             const ArkWebString* url,
             const ArkWebString* originalUrl,
             const ArkWebString* referrer,
             bool isFatalError,
             bool isMainFrame);
static ArkWebHandlerOnAllSslErrorRequestByJSFunc
    ark_web_handler_on_all_ssl_error_request_by_js =
        reinterpret_cast<ArkWebHandlerOnAllSslErrorRequestByJSFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnTooltipFunc = void (*)(struct _ark_web_handler_t* self,
                                            const ArkWebString* tooltip);
static ArkWebHandlerOnTooltipFunc ark_web_handler_on_tooltip =
    reinterpret_cast<ArkWebHandlerOnTooltipFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerReleaseResizeHoldFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerReleaseResizeHoldFunc ark_web_handler_release_resize_hold =
    reinterpret_cast<ArkWebHandlerReleaseResizeHoldFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnShowAutofillPopupFunc =
    void (*)(struct _ark_web_handler_t* self,
             const float offsetX,
             const float offsetY,
             const ArkWebStringVector* menu_items);
static ArkWebHandlerOnShowAutofillPopupFunc
    ark_web_handler_on_show_autofill_popup =
        reinterpret_cast<ArkWebHandlerOnShowAutofillPopupFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnHideAutofillPopupFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerOnHideAutofillPopupFunc
    ark_web_handler_on_hide_autofill_popup =
        reinterpret_cast<ArkWebHandlerOnHideAutofillPopupFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerGetWordSelectionFunc =
    ArkWebCharVector (*)(struct _ark_web_handler_t* self,
                         const ArkWebString* text,
                         int8_t offset);
static ArkWebHandlerGetWordSelectionFunc ark_web_handler_get_word_selection =
    reinterpret_cast<ArkWebHandlerGetWordSelectionFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerUpdateClippedSelectionBoundsFunc =
    void (*)(struct _ark_web_handler_t* self, int x, int y, int w, int h);
static ArkWebHandlerUpdateClippedSelectionBoundsFunc
    ark_web_handler_update_clipped_selection_bounds =
        reinterpret_cast<ArkWebHandlerUpdateClippedSelectionBoundsFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnOpenAppLinkFunc =
    bool (*)(struct _ark_web_handler_t* self,
             const ArkWebString* url,
             ark_web_app_link_callback_t* callback);
static ArkWebHandlerOnOpenAppLinkFunc ark_web_handler_on_open_app_link =
    reinterpret_cast<ArkWebHandlerOnOpenAppLinkFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnRenderProcessNotRespondingFunc =
    void (*)(struct _ark_web_handler_t* self,
             const ArkWebString* js_stack,
             int pid,
             int reason);
static ArkWebHandlerOnRenderProcessNotRespondingFunc
    ark_web_handler_on_render_process_not_responding =
        reinterpret_cast<ArkWebHandlerOnRenderProcessNotRespondingFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnRenderProcessRespondingFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerOnRenderProcessRespondingFunc
    ark_web_handler_on_render_process_responding =
        reinterpret_cast<ArkWebHandlerOnRenderProcessRespondingFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnViewportFitChangeFunc =
    void (*)(struct _ark_web_handler_t* self, int viewportFit);
static ArkWebHandlerOnViewportFitChangeFunc
    ark_web_handler_on_viewport_fit_change =
        reinterpret_cast<ArkWebHandlerOnViewportFitChangeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerCreateOverlayFunc = void (*)(struct _ark_web_handler_t* self,
                                                void* data,
                                                size_t len,
                                                int width,
                                                int height,
                                                int offset_x,
                                                int offset_y,
                                                int rect_width,
                                                int rect_height,
                                                int point_x,
                                                int point_y);
static ArkWebHandlerCreateOverlayFunc ark_web_handler_create_overlay =
    reinterpret_cast<ArkWebHandlerCreateOverlayFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnOverlayStateChangedFunc =
    void (*)(struct _ark_web_handler_t* self,
             int offset_x,
             int offset_y,
             int rect_width,
             int rect_height);
static ArkWebHandlerOnOverlayStateChangedFunc
    ark_web_handler_on_overlay_state_changed =
        reinterpret_cast<ArkWebHandlerOnOverlayStateChangedFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnFocusFunc2 = bool (*)(struct _ark_web_handler_t* self,
                                           int source);
static ArkWebHandlerOnFocusFunc2 ark_web_handler_on_focus2 =
    reinterpret_cast<ArkWebHandlerOnFocusFunc2>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnOverScrollFunc2 = bool (*)(struct _ark_web_handler_t* self,
                                                float xOffset,
                                                float yOffset,
                                                float xVelocity,
                                                float yVelocity);
static ArkWebHandlerOnOverScrollFunc2 ark_web_handler_on_over_scroll2 =
    reinterpret_cast<ArkWebHandlerOnOverScrollFunc2>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerKeyboardReDispatchFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_key_event_t* event,
             bool isUsed);
static ArkWebHandlerKeyboardReDispatchFunc
    ark_web_handler_keyboard_re_dispatch =
        reinterpret_cast<ArkWebHandlerKeyboardReDispatchFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnInterceptKeyboardAttachFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_custom_keyboard_handler_t* keyboardHandler,
             const ArkWebStringMap* attributes,
             bool* useSystemKeyboard,
             int32_t* enterKeyType);
static ArkWebHandlerOnInterceptKeyboardAttachFunc
    ark_web_handler_on_intercept_keyboard_attach =
        reinterpret_cast<ArkWebHandlerOnInterceptKeyboardAttachFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnCustomKeyboardAttachFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerOnCustomKeyboardAttachFunc
    ark_web_handler_on_custom_keyboard_attach =
        reinterpret_cast<ArkWebHandlerOnCustomKeyboardAttachFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnCustomKeyboardCloseFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerOnCustomKeyboardCloseFunc
    ark_web_handler_on_custom_keyboard_close =
        reinterpret_cast<ArkWebHandlerOnCustomKeyboardCloseFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnAdsBlockedFunc =
    void (*)(struct _ark_web_handler_t* self,
             const ArkWebString* url,
             const ArkWebStringVector* adsBlocked);
static ArkWebHandlerOnAdsBlockedFunc ark_web_handler_on_ads_blocked =
    reinterpret_cast<ArkWebHandlerOnAdsBlockedFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnCursorUpdateFunc =
    void (*)(struct _ark_web_handler_t* self,
             double x,
             double y,
             double width,
             double height);
static ArkWebHandlerOnCursorUpdateFunc ark_web_handler_on_cursor_update =
    reinterpret_cast<ArkWebHandlerOnCursorUpdateFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerReportDynamicFrameLossEventFunc =
    void (*)(struct _ark_web_handler_t* self,
             const ArkWebString* sceneId,
             bool isStart);
static ArkWebHandlerReportDynamicFrameLossEventFunc
    ark_web_handler_report_dynamic_frame_loss_event =
        reinterpret_cast<ArkWebHandlerReportDynamicFrameLossEventFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerHideHandleAndQuickMenuIfNecessaryFunc =
    void (*)(struct _ark_web_handler_t* self, bool hide);
static ArkWebHandlerHideHandleAndQuickMenuIfNecessaryFunc
    ark_web_handler_hide_handle_and_quick_menu_if_necessary =
        reinterpret_cast<ArkWebHandlerHideHandleAndQuickMenuIfNecessaryFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerChangeVisibilityOfQuickMenuFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerChangeVisibilityOfQuickMenuFunc
    ark_web_handler_change_visibility_of_quick_menu =
        reinterpret_cast<ArkWebHandlerChangeVisibilityOfQuickMenuFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerStartVibraFeedbackFunc =
    void (*)(struct _ark_web_handler_t* self, const ArkWebString* vibratorType);
static ArkWebHandlerStartVibraFeedbackFunc
    ark_web_handler_start_vibra_feedback =
        reinterpret_cast<ArkWebHandlerStartVibraFeedbackFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnPopupSizeFunc = void (*)(struct _ark_web_handler_t* self,
                                              int x,
                                              int y,
                                              int width,
                                              int height);
static ArkWebHandlerOnPopupSizeFunc ark_web_handler_on_popup_size =
    reinterpret_cast<ArkWebHandlerOnPopupSizeFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnPopupShowFunc = void (*)(struct _ark_web_handler_t* self,
                                              bool show);
static ArkWebHandlerOnPopupShowFunc ark_web_handler_on_popup_show =
    reinterpret_cast<ArkWebHandlerOnPopupShowFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnNativeEmbedVisibilityChangeFunc =
    void (*)(struct _ark_web_handler_t* self,
             const ArkWebString* embed_id,
             bool visibility);
static ArkWebHandlerOnNativeEmbedVisibilityChangeFunc
    ark_web_handler_on_native_embed_visibility_change =
        reinterpret_cast<ArkWebHandlerOnNativeEmbedVisibilityChangeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerCloseImageOverlaySelectionFunc =
    bool (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerCloseImageOverlaySelectionFunc
    ark_web_handler_close_image_overlay_selection =
        reinterpret_cast<ArkWebHandlerCloseImageOverlaySelectionFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnSslErrorRequestByJSV2Func =
    bool (*)(struct _ark_web_handler_t* self,
             ark_web_js_ssl_error_result_t* result,
             int error,
             const ArkWebStringVector* certChainData);
static ArkWebHandlerOnSslErrorRequestByJSV2Func
    ark_web_handler_on_ssl_error_request_by_jsv2 =
        reinterpret_cast<ArkWebHandlerOnSslErrorRequestByJSV2Func>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnAccessibilityEventFunc =
    void (*)(struct _ark_web_handler_t* self,
             int64_t accessibilityId,
             int32_t eventType);
static ArkWebHandlerOnAccessibilityEventFunc
    ark_web_handler_on_accessibility_event =
        reinterpret_cast<ArkWebHandlerOnAccessibilityEventFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerIsCurrentFocusFunc =
    bool (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerIsCurrentFocusFunc ark_web_handler_is_current_focus =
    reinterpret_cast<ArkWebHandlerIsCurrentFocusFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerGetVisibleRectToWebFunc =
    void (*)(struct _ark_web_handler_t* self,
             int* visibleX,
             int* visibleY,
             int* visibleWidth,
             int* visibleHeight);
static ArkWebHandlerGetVisibleRectToWebFunc
    ark_web_handler_get_visible_rect_to_web =
        reinterpret_cast<ArkWebHandlerGetVisibleRectToWebFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnScrollStartFunc = void (*)(struct _ark_web_handler_t* self,
                                                const float x,
                                                const float y);
static ArkWebHandlerOnScrollStartFunc ark_web_handler_on_scroll_start =
    reinterpret_cast<ArkWebHandlerOnScrollStartFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnShowAutofillPopupV2Func =
    void (*)(struct _ark_web_handler_t* self,
             const float offsetX,
             const float offsetY,
             const float height,
             const float width,
             const ArkWebStringVector* menu_items);
static ArkWebHandlerOnShowAutofillPopupV2Func
    ark_web_handler_on_show_autofill_popup_v2 =
        reinterpret_cast<ArkWebHandlerOnShowAutofillPopupV2Func>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerRestoreRenderFitFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerRestoreRenderFitFunc ark_web_handler_restore_render_fit =
    reinterpret_cast<ArkWebHandlerRestoreRenderFitFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnAccessibilityEventV2Func =
    void (*)(struct _ark_web_handler_t* self,
             int64_t accessibilityId,
             int32_t eventType,
             const ArkWebString* argument);
static ArkWebHandlerOnAccessibilityEventV2Func
    ark_web_handler_on_accessibility_event_v2 =
        reinterpret_cast<ArkWebHandlerOnAccessibilityEventV2Func>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnNestedScrollFunc =
    bool (*)(struct _ark_web_handler_t* self,
             float* x,
             float* y,
             float* xVelocity,
             float* yVelocity,
             bool* isAvailable);
static ArkWebHandlerOnNestedScrollFunc ark_web_handler_on_nested_scroll =
    reinterpret_cast<ArkWebHandlerOnNestedScrollFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerEnableSecurityLayerFunc =
    void (*)(struct _ark_web_handler_t* self, bool isNeedSecurityLayer);
static ArkWebHandlerEnableSecurityLayerFunc
    ark_web_handler_enable_security_layer =
        reinterpret_cast<ArkWebHandlerEnableSecurityLayerFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerChangeVisibilityOfQuickMenuV2Func =
    bool (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerChangeVisibilityOfQuickMenuV2Func
    ark_web_handler_change_visibility_of_quick_menu_v2 =
        reinterpret_cast<ArkWebHandlerChangeVisibilityOfQuickMenuV2Func>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnPipFunc = void (*)(struct _ark_web_handler_t* self,
                                        int status,
                                        int delegate_id,
                                        int child_id,
                                        int frame_routing_id,
                                        int width,
                                        int height);
static ArkWebHandlerOnPipFunc ark_web_handler_on_pip =
    reinterpret_cast<ArkWebHandlerOnPipFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnBeforeUnloadByJSV2Func =
    bool (*)(struct _ark_web_handler_t* self,
             const ArkWebString* url,
             const ArkWebString* message,
             bool isReload,
             ark_web_js_dialog_result_t* result);
static ArkWebHandlerOnBeforeUnloadByJSV2Func
    ark_web_handler_on_before_unload_by_jsv2 =
        reinterpret_cast<ArkWebHandlerOnBeforeUnloadByJSV2Func>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnNativeEmbedMouseEventFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_native_embed_mouse_event_t* mouse_event);
static ArkWebHandlerOnNativeEmbedMouseEventFunc
    ark_web_handler_on_native_embed_mouse_event =
        reinterpret_cast<ArkWebHandlerOnNativeEmbedMouseEventFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnActivateContentByJSFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerOnActivateContentByJSFunc
    ark_web_handler_on_activate_content_by_js =
        reinterpret_cast<ArkWebHandlerOnActivateContentByJSFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnLoadStartedFunc = void (*)(struct _ark_web_handler_t* self,
                                                const ArkWebString* url);
static ArkWebHandlerOnLoadStartedFunc ark_web_handler_on_load_started =
    reinterpret_cast<ArkWebHandlerOnLoadStartedFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnLoadFinishedFunc =
    void (*)(struct _ark_web_handler_t* self, const ArkWebString* url);
static ArkWebHandlerOnLoadFinishedFunc ark_web_handler_on_load_finished =
    reinterpret_cast<ArkWebHandlerOnLoadFinishedFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnAllSslErrorRequestByJSV2Func =
    bool (*)(struct _ark_web_handler_t* self,
             ark_web_js_all_ssl_error_result_t* result,
             int error,
             const ArkWebString* url,
             const ArkWebString* originalUrl,
             const ArkWebString* referrer,
             bool isFatalError,
             bool isMainFrame,
             const ArkWebStringVector* certChainData);
static ArkWebHandlerOnAllSslErrorRequestByJSV2Func
    ark_web_handler_on_all_ssl_error_request_by_jsv2 =
        reinterpret_cast<ArkWebHandlerOnAllSslErrorRequestByJSV2Func>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerShowMagnifierFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerShowMagnifierFunc ark_web_handler_show_magnifier =
    reinterpret_cast<ArkWebHandlerShowMagnifierFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerHideMagnifierFunc =
    void (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerHideMagnifierFunc ark_web_handler_hide_magnifier =
    reinterpret_cast<ArkWebHandlerHideMagnifierFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnPageTitleV2Func = void (*)(struct _ark_web_handler_t* self,
                                                const ArkWebString* title,
                                                bool isRealTitle);
static ArkWebHandlerOnPageTitleV2Func ark_web_handler_on_page_title_v2 =
    reinterpret_cast<ArkWebHandlerOnPageTitleV2Func>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnInsertBlanklessFrameFunc =
    void (*)(struct _ark_web_handler_t* self, const ArkWebString* pathToFrame);
static ArkWebHandlerOnInsertBlanklessFrameFunc
    ark_web_handler_on_insert_blankless_frame =
        reinterpret_cast<ArkWebHandlerOnInsertBlanklessFrameFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnRemoveBlanklessFrameFunc =
    void (*)(struct _ark_web_handler_t* self, int delayTime);
static ArkWebHandlerOnRemoveBlanklessFrameFunc
    ark_web_handler_on_remove_blankless_frame =
        reinterpret_cast<ArkWebHandlerOnRemoveBlanklessFrameFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnHandleOverrideErrorPageFunc =
    ArkWebString (*)(struct _ark_web_handler_t* self,
                     ark_web_url_resource_request_t* request,
                     ark_web_url_resource_error_t* error);
static ArkWebHandlerOnHandleOverrideErrorPageFunc
    ark_web_handler_on_handle_override_error_page =
        reinterpret_cast<ArkWebHandlerOnHandleOverrideErrorPageFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnPdfScrollAtBottomFunc =
    void (*)(struct _ark_web_handler_t* self, const ArkWebString* url);
static ArkWebHandlerOnPdfScrollAtBottomFunc
    ark_web_handler_on_pdf_scroll_at_bottom =
        reinterpret_cast<ArkWebHandlerOnPdfScrollAtBottomFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnPdfLoadEventFunc =
    void (*)(struct _ark_web_handler_t* self,
             int32_t result,
             const ArkWebString* url);
static ArkWebHandlerOnPdfLoadEventFunc ark_web_handler_on_pdf_load_event =
    reinterpret_cast<ArkWebHandlerOnPdfLoadEventFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnTakeFocusFunc = void (*)(struct _ark_web_handler_t* self,
                                              ark_web_key_event_t* event);
static ArkWebHandlerOnTakeFocusFunc ark_web_handler_on_take_focus =
    reinterpret_cast<ArkWebHandlerOnTakeFocusFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnInsertBlanklessFrameWithSizeFunc =
    void (*)(struct _ark_web_handler_t* self,
             const ArkWebString* pathToFrame,
             uint32_t width,
             uint32_t height);
static ArkWebHandlerOnInsertBlanklessFrameWithSizeFunc
    ark_web_handler_on_insert_blankless_frame_with_size =
        reinterpret_cast<ArkWebHandlerOnInsertBlanklessFrameWithSizeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerSetImeShowFunc = void (*)(struct _ark_web_handler_t* self,
                                             bool visible);
static ArkWebHandlerSetImeShowFunc ark_web_handler_set_ime_show =
    reinterpret_cast<ArkWebHandlerSetImeShowFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerIsShowHandleFunc = bool (*)(struct _ark_web_handler_t* self);
static ArkWebHandlerIsShowHandleFunc ark_web_handler_is_show_handle =
    reinterpret_cast<ArkWebHandlerIsShowHandleFunc>(ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnNativeEmbedObjectParamChangeFunc =
    void (*)(struct _ark_web_handler_t* self,
             ark_web_native_embed_param_data_info_t* data_info);
static ArkWebHandlerOnNativeEmbedObjectParamChangeFunc
    ark_web_handler_on_native_embed_object_param_change =
        reinterpret_cast<ArkWebHandlerOnNativeEmbedObjectParamChangeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnSafeBrowsingCheckFinishFunc =
    void (*)(struct _ark_web_handler_t* self, int threat_type);
static ArkWebHandlerOnSafeBrowsingCheckFinishFunc
    ark_web_handler_on_safe_browsing_check_finish =
        reinterpret_cast<ArkWebHandlerOnSafeBrowsingCheckFinishFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnExtensionDisconnectFunc =
    void (*)(struct _ark_web_handler_t* self, int32_t connectId);
static ArkWebHandlerOnExtensionDisconnectFunc
    ark_web_handler_on_extension_disconnect =
        reinterpret_cast<ArkWebHandlerOnExtensionDisconnectFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnWebNativeMessageFunc =
    ArkWebString (*)(struct _ark_web_handler_t* self,
                     ark_web_runtime_connect_info_t* info,
                     ark_web_native_message_callback_t* callback);
static ArkWebHandlerOnWebNativeMessageFunc
    ark_web_handler_on_web_native_message =
        reinterpret_cast<ArkWebHandlerOnWebNativeMessageFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebHandlerOnRefreshAccessedHistoryV2Func =
    void (*)(struct _ark_web_handler_t* self,
             const ArkWebString* url,
             bool isReload,
             bool isMainFrame);
static ArkWebHandlerOnRefreshAccessedHistoryV2Func
    ark_web_handler_on_refresh_accessed_history_v2 =
        reinterpret_cast<ArkWebHandlerOnRefreshAccessedHistoryV2Func>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::SetNWeb(ArkWebRefPtr<ArkWebNWeb> nweb) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_set_nweb);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "CTn8xRguxNREfBNsZCy0kg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_set_nweb");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_nweb)) {
        ark_web_handler_set_nweb = nullptr;
      } else {
        ark_web_handler_set_nweb = _struct->set_nweb;
      }
    } else {
      ark_web_handler_set_nweb =
          reinterpret_cast<ArkWebHandlerSetNWebFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_set_nweb,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_set_nweb(_struct, ArkWebNWebCppToC::Invert(nweb));
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnFocus() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_focus1);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "PHxDGiIo8jTZcDwFBGm$hA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_focus1");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_focus1)) {
        ark_web_handler_on_focus1 = nullptr;
      } else {
        ark_web_handler_on_focus1 = _struct->on_focus1;
      }
    } else {
      ark_web_handler_on_focus1 =
          reinterpret_cast<ArkWebHandlerOnFocusFunc1>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_focus1, false);

  // Execute
  return ark_web_handler_on_focus1(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnMessage(const ArkWebString& param) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_message);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "wpuVZZR5nyUTdyGzRZTJ1Q";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_message");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_message)) {
        ark_web_handler_on_message = nullptr;
      } else {
        ark_web_handler_on_message = _struct->on_message;
      }
    } else {
      ark_web_handler_on_message =
          reinterpret_cast<ArkWebHandlerOnMessageFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_message,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_message(_struct, &param);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnResource(const ArkWebString& url) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_resource);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "tXYqorcx7uZod91MqLrWkw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_resource");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_resource)) {
        ark_web_handler_on_resource = nullptr;
      } else {
        ark_web_handler_on_resource = _struct->on_resource;
      }
    } else {
      ark_web_handler_on_resource =
          reinterpret_cast<ArkWebHandlerOnResourceFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_resource,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_resource(_struct, &url);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnPageIcon(const void* data,
                                     size_t width,
                                     size_t height,
                                     int color_type,
                                     int alpha_type) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_page_icon);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "eMZ096fcd6y1H1EBB$BquQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_page_icon");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_page_icon)) {
        ark_web_handler_on_page_icon = nullptr;
      } else {
        ark_web_handler_on_page_icon = _struct->on_page_icon;
      }
    } else {
      ark_web_handler_on_page_icon =
          reinterpret_cast<ArkWebHandlerOnPageIconFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_page_icon,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_page_icon(_struct, data, width, height, color_type,
                               alpha_type);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnPageTitle(const ArkWebString& title) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_page_title);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jN6JkzVLIha$Bl9sH20XVA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_page_title");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_page_title)) {
        ark_web_handler_on_page_title = nullptr;
      } else {
        ark_web_handler_on_page_title = _struct->on_page_title;
      }
    } else {
      ark_web_handler_on_page_title =
          reinterpret_cast<ArkWebHandlerOnPageTitleFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_page_title,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_page_title(_struct, &title);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnProxyDied() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_proxy_died);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "8UZJuWoCR4hZBKPza6O2dQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_proxy_died");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_proxy_died)) {
        ark_web_handler_on_proxy_died = nullptr;
      } else {
        ark_web_handler_on_proxy_died = _struct->on_proxy_died;
      }
    } else {
      ark_web_handler_on_proxy_died =
          reinterpret_cast<ArkWebHandlerOnProxyDiedFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_proxy_died,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_proxy_died(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnHttpError(
    ArkWebRefPtr<ArkWebUrlResourceRequest> request,
    ArkWebRefPtr<ArkWebUrlResourceResponse> error_response) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_http_error);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "W6$IY_neMLzpSdmhdgvZtg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_http_error");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_http_error)) {
        ark_web_handler_on_http_error = nullptr;
      } else {
        ark_web_handler_on_http_error = _struct->on_http_error;
      }
    } else {
      ark_web_handler_on_http_error =
          reinterpret_cast<ArkWebHandlerOnHttpErrorFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_http_error,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_http_error(
      _struct, ArkWebUrlResourceRequestCppToC::Invert(request),
      ArkWebUrlResourceResponseCppToC::Invert(error_response));
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnConsoleLog(ArkWebRefPtr<ArkWebConsoleLog> message) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_console_log);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "FcdybrQP14FQs9zBKuoxcg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_console_log");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_console_log)) {
        ark_web_handler_on_console_log = nullptr;
      } else {
        ark_web_handler_on_console_log = _struct->on_console_log;
      }
    } else {
      ark_web_handler_on_console_log =
          reinterpret_cast<ArkWebHandlerOnConsoleLogFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_console_log, false);

  // Execute
  return ark_web_handler_on_console_log(
      _struct, ArkWebConsoleLogCppToC::Invert(message));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnRouterPush(const ArkWebString& param) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_router_push);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "7bYoF4UZ2nZX6GLECo27ew";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_router_push");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_router_push)) {
        ark_web_handler_on_router_push = nullptr;
      } else {
        ark_web_handler_on_router_push = _struct->on_router_push;
      }
    } else {
      ark_web_handler_on_router_push =
          reinterpret_cast<ArkWebHandlerOnRouterPushFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_router_push,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_router_push(_struct, &param);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnPageLoadEnd(int http_status_code,
                                        const ArkWebString& url) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_page_load_end);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "b9bq_K7EK2crFwhEM7Aiww";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_page_load_end");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_page_load_end)) {
        ark_web_handler_on_page_load_end = nullptr;
      } else {
        ark_web_handler_on_page_load_end = _struct->on_page_load_end;
      }
    } else {
      ark_web_handler_on_page_load_end =
          reinterpret_cast<ArkWebHandlerOnPageLoadEndFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_page_load_end,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_page_load_end(_struct, http_status_code, &url);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnPageLoadBegin(const ArkWebString& url) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_page_load_begin);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jLW2TuGykiLzEoeyFor6lw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_page_load_begin");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_page_load_begin)) {
        ark_web_handler_on_page_load_begin = nullptr;
      } else {
        ark_web_handler_on_page_load_begin = _struct->on_page_load_begin;
      }
    } else {
      ark_web_handler_on_page_load_begin =
          reinterpret_cast<ArkWebHandlerOnPageLoadBeginFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_page_load_begin,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_page_load_begin(_struct, &url);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnPageLoadError(int error_code,
                                          const ArkWebString& description,
                                          const ArkWebString& failing_url) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_page_load_error);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ArBazlrNb8_TLjbiLvbG2A";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_page_load_error");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_page_load_error)) {
        ark_web_handler_on_page_load_error = nullptr;
      } else {
        ark_web_handler_on_page_load_error = _struct->on_page_load_error;
      }
    } else {
      ark_web_handler_on_page_load_error =
          reinterpret_cast<ArkWebHandlerOnPageLoadErrorFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_page_load_error,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_page_load_error(_struct, error_code, &description,
                                     &failing_url);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnDesktopIconUrl(const ArkWebString& icon_url,
                                           bool precomposed) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_desktop_icon_url);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ticHWmTrFVhEDDY_IsSbrQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_desktop_icon_url");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_desktop_icon_url)) {
        ark_web_handler_on_desktop_icon_url = nullptr;
      } else {
        ark_web_handler_on_desktop_icon_url = _struct->on_desktop_icon_url;
      }
    } else {
      ark_web_handler_on_desktop_icon_url =
          reinterpret_cast<ArkWebHandlerOnDesktopIconUrlFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_desktop_icon_url,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_desktop_icon_url(_struct, &icon_url, precomposed);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnLoadingProgress(int new_progress) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_loading_progress);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "nZZ8zOQWDTu1crdiR2ZWJQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_loading_progress");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_loading_progress)) {
        ark_web_handler_on_loading_progress = nullptr;
      } else {
        ark_web_handler_on_loading_progress = _struct->on_loading_progress;
      }
    } else {
      ark_web_handler_on_loading_progress =
          reinterpret_cast<ArkWebHandlerOnLoadingProgressFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_loading_progress,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_loading_progress(_struct, new_progress);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnGeolocationShow(
    const ArkWebString& origin,
    ArkWebRefPtr<ArkWebGeoLocationCallback> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_geolocation_show);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Zy8G2$spHnMMlvG4Ae1OUg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_geolocation_show");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_geolocation_show)) {
        ark_web_handler_on_geolocation_show = nullptr;
      } else {
        ark_web_handler_on_geolocation_show = _struct->on_geolocation_show;
      }
    } else {
      ark_web_handler_on_geolocation_show =
          reinterpret_cast<ArkWebHandlerOnGeolocationShowFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_geolocation_show,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_geolocation_show(
      _struct, &origin, ArkWebGeoLocationCallbackCppToC::Invert(callback));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnGeolocationHide() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_geolocation_hide);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "gl3k4Fig9chNIiqjoo_s2g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_geolocation_hide");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_geolocation_hide)) {
        ark_web_handler_on_geolocation_hide = nullptr;
      } else {
        ark_web_handler_on_geolocation_hide = _struct->on_geolocation_hide;
      }
    } else {
      ark_web_handler_on_geolocation_hide =
          reinterpret_cast<ArkWebHandlerOnGeolocationHideFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_geolocation_hide,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_geolocation_hide(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnFileSelectorShow(
    ArkWebRefPtr<ArkWebStringVectorValueCallback> callback,
    ArkWebRefPtr<ArkWebFileSelectorParams> params) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_file_selector_show);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "U2cuqbqmIatB3YHJTkMEIQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_file_selector_show");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_file_selector_show)) {
        ark_web_handler_on_file_selector_show = nullptr;
      } else {
        ark_web_handler_on_file_selector_show = _struct->on_file_selector_show;
      }
    } else {
      ark_web_handler_on_file_selector_show =
          reinterpret_cast<ArkWebHandlerOnFileSelectorShowFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_file_selector_show,
                                    false);

  // Execute
  return ark_web_handler_on_file_selector_show(
      _struct, ArkWebStringVectorValueCallbackCppToC::Invert(callback),
      ArkWebFileSelectorParamsCppToC::Invert(params));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnResourceLoadError(
    ArkWebRefPtr<ArkWebUrlResourceRequest> request,
    ArkWebRefPtr<ArkWebUrlResourceError> error) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_resource_load_error);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "O9$7kqrz1phnNki1BbHToQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_resource_load_error");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_resource_load_error)) {
        ark_web_handler_on_resource_load_error = nullptr;
      } else {
        ark_web_handler_on_resource_load_error =
            _struct->on_resource_load_error;
      }
    } else {
      ark_web_handler_on_resource_load_error =
          reinterpret_cast<ArkWebHandlerOnResourceLoadErrorFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_resource_load_error,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_resource_load_error(
      _struct, ArkWebUrlResourceRequestCppToC::Invert(request),
      ArkWebUrlResourceErrorCppToC::Invert(error));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnPermissionRequest(
    ArkWebRefPtr<ArkWebAccessRequest> request) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_permission_request);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "w$W6rXbasIcX2W9mrKvaaQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_permission_request");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_permission_request)) {
        ark_web_handler_on_permission_request = nullptr;
      } else {
        ark_web_handler_on_permission_request = _struct->on_permission_request;
      }
    } else {
      ark_web_handler_on_permission_request =
          reinterpret_cast<ArkWebHandlerOnPermissionRequestFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_permission_request,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_permission_request(
      _struct, ArkWebAccessRequestCppToC::Invert(request));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnQuickMenuDismissed() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_quick_menu_dismissed);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "5bDEYOfhyQFwKOBOd1PtbQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_quick_menu_dismissed");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_quick_menu_dismissed)) {
        ark_web_handler_on_quick_menu_dismissed = nullptr;
      } else {
        ark_web_handler_on_quick_menu_dismissed =
            _struct->on_quick_menu_dismissed;
      }
    } else {
      ark_web_handler_on_quick_menu_dismissed =
          reinterpret_cast<ArkWebHandlerOnQuickMenuDismissedFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_quick_menu_dismissed,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_quick_menu_dismissed(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnContextMenuDismissed() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_context_menu_dismissed);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "RImgwWhE6yekI6dqUIoA9w";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_context_menu_dismissed");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_context_menu_dismissed)) {
        ark_web_handler_on_context_menu_dismissed = nullptr;
      } else {
        ark_web_handler_on_context_menu_dismissed =
            _struct->on_context_menu_dismissed;
      }
    } else {
      ark_web_handler_on_context_menu_dismissed =
          reinterpret_cast<ArkWebHandlerOnContextMenuDismissedFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_context_menu_dismissed,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_context_menu_dismissed(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnTouchSelectionChanged(
    ArkWebRefPtr<ArkWebTouchHandleState> insert_handle,
    ArkWebRefPtr<ArkWebTouchHandleState> start_selection_handle,
    ArkWebRefPtr<ArkWebTouchHandleState> end_selection_handle) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_touch_selection_changed);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "r1Ng00SXRqGdnGw0uplLfw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_touch_selection_changed");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_touch_selection_changed)) {
        ark_web_handler_on_touch_selection_changed = nullptr;
      } else {
        ark_web_handler_on_touch_selection_changed =
            _struct->on_touch_selection_changed;
      }
    } else {
      ark_web_handler_on_touch_selection_changed =
          reinterpret_cast<ArkWebHandlerOnTouchSelectionChangedFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_touch_selection_changed,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_touch_selection_changed(
      _struct, ArkWebTouchHandleStateCppToC::Invert(insert_handle),
      ArkWebTouchHandleStateCppToC::Invert(start_selection_handle),
      ArkWebTouchHandleStateCppToC::Invert(end_selection_handle));
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnHandleInterceptRequest(
    ArkWebRefPtr<ArkWebUrlResourceRequest> request,
    ArkWebRefPtr<ArkWebUrlResourceResponse> response) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_handle_intercept_request);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Fqm6MEWscTIzCSWsL8gOmg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_handle_intercept_request");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_handle_intercept_request)) {
        ark_web_handler_on_handle_intercept_request = nullptr;
      } else {
        ark_web_handler_on_handle_intercept_request =
            _struct->on_handle_intercept_request;
      }
    } else {
      ark_web_handler_on_handle_intercept_request =
          reinterpret_cast<ArkWebHandlerOnHandleInterceptRequestFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_handle_intercept_request,
                                    false);

  // Execute
  return ark_web_handler_on_handle_intercept_request(
      _struct, ArkWebUrlResourceRequestCppToC::Invert(request),
      ArkWebUrlResourceResponseCppToC::Invert(response));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnRefreshAccessedHistory(const ArkWebString& url,
                                                   bool is_reload) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_refresh_accessed_history);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "LH3mAKecuVcWU3TIVYhUvQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_refresh_accessed_history");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_refresh_accessed_history)) {
        ark_web_handler_on_refresh_accessed_history = nullptr;
      } else {
        ark_web_handler_on_refresh_accessed_history =
            _struct->on_refresh_accessed_history;
      }
    } else {
      ark_web_handler_on_refresh_accessed_history =
          reinterpret_cast<ArkWebHandlerOnRefreshAccessedHistoryFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_refresh_accessed_history,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_refresh_accessed_history(_struct, &url, is_reload);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnPermissionRequestCanceled(
    ArkWebRefPtr<ArkWebAccessRequest> request) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_permission_request_canceled);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ndyqMfiL1EI3$55IwcmeCA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_permission_request_canceled");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      on_permission_request_canceled)) {
        ark_web_handler_on_permission_request_canceled = nullptr;
      } else {
        ark_web_handler_on_permission_request_canceled =
            _struct->on_permission_request_canceled;
      }
    } else {
      ark_web_handler_on_permission_request_canceled =
          reinterpret_cast<ArkWebHandlerOnPermissionRequestCanceledFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_permission_request_canceled, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_permission_request_canceled(
      _struct, ArkWebAccessRequestCppToC::Invert(request));
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnHandleInterceptUrlLoading(
    ArkWebRefPtr<ArkWebUrlResourceRequest> request) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_handle_intercept_url_loading);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "B7j1RgpQEAFXu$KPStoNGw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_handle_intercept_url_loading");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      on_handle_intercept_url_loading)) {
        ark_web_handler_on_handle_intercept_url_loading = nullptr;
      } else {
        ark_web_handler_on_handle_intercept_url_loading =
            _struct->on_handle_intercept_url_loading;
      }
    } else {
      ark_web_handler_on_handle_intercept_url_loading =
          reinterpret_cast<ArkWebHandlerOnHandleInterceptUrlLoadingFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_handle_intercept_url_loading, false);

  // Execute
  return ark_web_handler_on_handle_intercept_url_loading(
      _struct, ArkWebUrlResourceRequestCppToC::Invert(request));
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::RunQuickMenu(
    ArkWebRefPtr<ArkWebQuickMenuParams> params,
    ArkWebRefPtr<ArkWebQuickMenuCallback> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_run_quick_menu);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "xM3RbgXrwJGJbWeY983Eaw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_run_quick_menu");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, run_quick_menu)) {
        ark_web_handler_run_quick_menu = nullptr;
      } else {
        ark_web_handler_run_quick_menu = _struct->run_quick_menu;
      }
    } else {
      ark_web_handler_run_quick_menu =
          reinterpret_cast<ArkWebHandlerRunQuickMenuFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_run_quick_menu, false);

  // Execute
  return ark_web_handler_run_quick_menu(
      _struct, ArkWebQuickMenuParamsCppToC::Invert(params),
      ArkWebQuickMenuCallbackCppToC::Invert(callback));
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::RunContextMenu(
    ArkWebRefPtr<ArkWebContextMenuParams> params,
    ArkWebRefPtr<ArkWebContextMenuCallback> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_run_context_menu);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "F9NBmnH_slKGq2aAK4H_LA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_run_context_menu");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, run_context_menu)) {
        ark_web_handler_run_context_menu = nullptr;
      } else {
        ark_web_handler_run_context_menu = _struct->run_context_menu;
      }
    } else {
      ark_web_handler_run_context_menu =
          reinterpret_cast<ArkWebHandlerRunContextMenuFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_run_context_menu, false);

  // Execute
  return ark_web_handler_run_context_menu(
      _struct, ArkWebContextMenuParamsCppToC::Invert(params),
      ArkWebContextMenuCallbackCppToC::Invert(callback));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::UpdateDragCursor(unsigned char op) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_update_drag_cursor);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "i5PY1$mPcm2fWOXjVNCR0A";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_update_drag_cursor");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, update_drag_cursor)) {
        ark_web_handler_update_drag_cursor = nullptr;
      } else {
        ark_web_handler_update_drag_cursor = _struct->update_drag_cursor;
      }
    } else {
      ark_web_handler_update_drag_cursor =
          reinterpret_cast<ArkWebHandlerUpdateDragCursorFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_update_drag_cursor,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_update_drag_cursor(_struct, op);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::FilterScrollEvent(const float x,
                                            const float y,
                                            const float x_velocity,
                                            const float y_velocity) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_filter_scroll_event);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "A$jgFlI2z4tkvTjh9axzqA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_filter_scroll_event");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, filter_scroll_event)) {
        ark_web_handler_filter_scroll_event = nullptr;
      } else {
        ark_web_handler_filter_scroll_event = _struct->filter_scroll_event;
      }
    } else {
      ark_web_handler_filter_scroll_event =
          reinterpret_cast<ArkWebHandlerFilterScrollEventFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_filter_scroll_event, false);

  // Execute
  return ark_web_handler_filter_scroll_event(_struct, x, y, x_velocity,
                                             y_velocity);
}

ARK_WEB_NO_SANITIZE
ArkWebStringVector ArkWebHandlerCToCpp::VisitedUrlHistory() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_vector_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_visited_url_history);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "qko$IYleoA363F_p_AhYew";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_visited_url_history");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, visited_url_history)) {
        ark_web_handler_visited_url_history = nullptr;
      } else {
        ark_web_handler_visited_url_history = _struct->visited_url_history;
      }
    } else {
      ark_web_handler_visited_url_history =
          reinterpret_cast<ArkWebHandlerVisitedUrlHistoryFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_visited_url_history,
                                    ark_web_string_vector_default);

  // Execute
  return ark_web_handler_visited_url_history(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnWindowNewByJS(
    const ArkWebString& target_url,
    bool is_alert,
    bool is_user_trigger,
    ArkWebRefPtr<ArkWebControllerHandler> handler) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_window_new_by_js);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "9LoldjDctauz62vo2ZFXFA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_window_new_by_js");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_window_new_by_js)) {
        ark_web_handler_on_window_new_by_js = nullptr;
      } else {
        ark_web_handler_on_window_new_by_js = _struct->on_window_new_by_js;
      }
    } else {
      ark_web_handler_on_window_new_by_js =
          reinterpret_cast<ArkWebHandlerOnWindowNewByJSFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_window_new_by_js,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_window_new_by_js(
      _struct, &target_url, is_alert, is_user_trigger,
      ArkWebControllerHandlerCppToC::Invert(handler));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnWindowExitByJS() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_window_exit_by_js);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "5SNN1eQ7NW_j_P554q2SAQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_window_exit_by_js");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_window_exit_by_js)) {
        ark_web_handler_on_window_exit_by_js = nullptr;
      } else {
        ark_web_handler_on_window_exit_by_js = _struct->on_window_exit_by_js;
      }
    } else {
      ark_web_handler_on_window_exit_by_js =
          reinterpret_cast<ArkWebHandlerOnWindowExitByJSFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_window_exit_by_js,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_window_exit_by_js(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnAlertDialogByJS(
    const ArkWebString& url,
    const ArkWebString& message,
    ArkWebRefPtr<ArkWebJsDialogResult> result) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_alert_dialog_by_js);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "rz4nR7GEwFuef3JHZ1VOYA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_alert_dialog_by_js");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_alert_dialog_by_js)) {
        ark_web_handler_on_alert_dialog_by_js = nullptr;
      } else {
        ark_web_handler_on_alert_dialog_by_js = _struct->on_alert_dialog_by_js;
      }
    } else {
      ark_web_handler_on_alert_dialog_by_js =
          reinterpret_cast<ArkWebHandlerOnAlertDialogByJSFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_alert_dialog_by_js,
                                    false);

  // Execute
  return ark_web_handler_on_alert_dialog_by_js(
      _struct, &url, &message, ArkWebJsDialogResultCppToC::Invert(result));
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnBeforeUnloadByJS(
    const ArkWebString& url,
    const ArkWebString& message,
    ArkWebRefPtr<ArkWebJsDialogResult> result) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_before_unload_by_js);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "8YkeoALv14OPBGL50PNxlw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_before_unload_by_js");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_before_unload_by_js)) {
        ark_web_handler_on_before_unload_by_js = nullptr;
      } else {
        ark_web_handler_on_before_unload_by_js =
            _struct->on_before_unload_by_js;
      }
    } else {
      ark_web_handler_on_before_unload_by_js =
          reinterpret_cast<ArkWebHandlerOnBeforeUnloadByJSFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_before_unload_by_js,
                                    false);

  // Execute
  return ark_web_handler_on_before_unload_by_js(
      _struct, &url, &message, ArkWebJsDialogResultCppToC::Invert(result));
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnPromptDialogByJS(
    const ArkWebString& url,
    const ArkWebString& message,
    const ArkWebString& default_value,
    ArkWebRefPtr<ArkWebJsDialogResult> result) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_prompt_dialog_by_js);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Geq2HRSrt7MFajp00yFC1g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_prompt_dialog_by_js");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_prompt_dialog_by_js)) {
        ark_web_handler_on_prompt_dialog_by_js = nullptr;
      } else {
        ark_web_handler_on_prompt_dialog_by_js =
            _struct->on_prompt_dialog_by_js;
      }
    } else {
      ark_web_handler_on_prompt_dialog_by_js =
          reinterpret_cast<ArkWebHandlerOnPromptDialogByJSFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_prompt_dialog_by_js,
                                    false);

  // Execute
  return ark_web_handler_on_prompt_dialog_by_js(
      _struct, &url, &message, &default_value,
      ArkWebJsDialogResultCppToC::Invert(result));
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnConfirmDialogByJS(
    const ArkWebString& url,
    const ArkWebString& message,
    ArkWebRefPtr<ArkWebJsDialogResult> result) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_confirm_dialog_by_js);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "8i$EQ1DgsvSO5ZhkdN8uog";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_confirm_dialog_by_js");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_confirm_dialog_by_js)) {
        ark_web_handler_on_confirm_dialog_by_js = nullptr;
      } else {
        ark_web_handler_on_confirm_dialog_by_js =
            _struct->on_confirm_dialog_by_js;
      }
    } else {
      ark_web_handler_on_confirm_dialog_by_js =
          reinterpret_cast<ArkWebHandlerOnConfirmDialogByJSFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_confirm_dialog_by_js,
                                    false);

  // Execute
  return ark_web_handler_on_confirm_dialog_by_js(
      _struct, &url, &message, ArkWebJsDialogResultCppToC::Invert(result));
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnHttpAuthRequestByJS(
    ArkWebRefPtr<ArkWebJsHttpAuthResult> result,
    const ArkWebString& host,
    const ArkWebString& realm) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_http_auth_request_by_js);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "H2tlPgWfe_G5nUNmZKbRFA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_http_auth_request_by_js");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_http_auth_request_by_js)) {
        ark_web_handler_on_http_auth_request_by_js = nullptr;
      } else {
        ark_web_handler_on_http_auth_request_by_js =
            _struct->on_http_auth_request_by_js;
      }
    } else {
      ark_web_handler_on_http_auth_request_by_js =
          reinterpret_cast<ArkWebHandlerOnHttpAuthRequestByJSFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_http_auth_request_by_js,
                                    false);

  // Execute
  return ark_web_handler_on_http_auth_request_by_js(
      _struct, ArkWebJsHttpAuthResultCppToC::Invert(result), &host, &realm);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnSslErrorRequestByJS(
    ArkWebRefPtr<ArkWebJsSslErrorResult> result,
    int error) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_ssl_error_request_by_js);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "oz6$JPeVFCbWZdTT3IRJUQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_ssl_error_request_by_js");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_ssl_error_request_by_js)) {
        ark_web_handler_on_ssl_error_request_by_js = nullptr;
      } else {
        ark_web_handler_on_ssl_error_request_by_js =
            _struct->on_ssl_error_request_by_js;
      }
    } else {
      ark_web_handler_on_ssl_error_request_by_js =
          reinterpret_cast<ArkWebHandlerOnSslErrorRequestByJSFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_ssl_error_request_by_js,
                                    false);

  // Execute
  return ark_web_handler_on_ssl_error_request_by_js(
      _struct, ArkWebJsSslErrorResultCppToC::Invert(result), error);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnSslSelectCertRequestByJS(
    ArkWebRefPtr<ArkWebJsSslSelectCertResult> result,
    const ArkWebString& host,
    int port,
    const ArkWebStringVector& key_types,
    const ArkWebStringVector& issuers) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_ssl_select_cert_request_by_js);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "B16VB103qdJZqfrl_oDI6g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_ssl_select_cert_request_by_js");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      on_ssl_select_cert_request_by_js)) {
        ark_web_handler_on_ssl_select_cert_request_by_js = nullptr;
      } else {
        ark_web_handler_on_ssl_select_cert_request_by_js =
            _struct->on_ssl_select_cert_request_by_js;
      }
    } else {
      ark_web_handler_on_ssl_select_cert_request_by_js =
          reinterpret_cast<ArkWebHandlerOnSslSelectCertRequestByJSFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_ssl_select_cert_request_by_js, false);

  // Execute
  return ark_web_handler_on_ssl_select_cert_request_by_js(
      _struct, ArkWebJsSslSelectCertResultCppToC::Invert(result), &host, port,
      &key_types, &issuers);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnScroll(double x_offset, double y_offset) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_scroll);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "nr9knkqB0pmGSbPgKwtTWg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_scroll");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_scroll)) {
        ark_web_handler_on_scroll = nullptr;
      } else {
        ark_web_handler_on_scroll = _struct->on_scroll;
      }
    } else {
      ark_web_handler_on_scroll =
          reinterpret_cast<ArkWebHandlerOnScrollFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_scroll,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_scroll(_struct, x_offset, y_offset);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnOverScroll(float x_offset, float y_offset) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_over_scroll1);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "VnE9d_voai2MlNrSF5SAdA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_over_scroll1");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_over_scroll1)) {
        ark_web_handler_on_over_scroll1 = nullptr;
      } else {
        ark_web_handler_on_over_scroll1 = _struct->on_over_scroll1;
      }
    } else {
      ark_web_handler_on_over_scroll1 =
          reinterpret_cast<ArkWebHandlerOnOverScrollFunc1>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_over_scroll1,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_over_scroll1(_struct, x_offset, y_offset);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnScrollState(bool scroll_state) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_scroll_state);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "uzAqIYFKwbQroD5owJydAg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_scroll_state");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_scroll_state)) {
        ark_web_handler_on_scroll_state = nullptr;
      } else {
        ark_web_handler_on_scroll_state = _struct->on_scroll_state;
      }
    } else {
      ark_web_handler_on_scroll_state =
          reinterpret_cast<ArkWebHandlerOnScrollStateFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_scroll_state,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_scroll_state(_struct, scroll_state);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnPageVisible(const ArkWebString& url) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_page_visible);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "EkpAvqcAVOKLejifa8BG5w";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_page_visible");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_page_visible)) {
        ark_web_handler_on_page_visible = nullptr;
      } else {
        ark_web_handler_on_page_visible = _struct->on_page_visible;
      }
    } else {
      ark_web_handler_on_page_visible =
          reinterpret_cast<ArkWebHandlerOnPageVisibleFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_page_visible,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_page_visible(_struct, &url);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnPreKeyEvent(ArkWebRefPtr<ArkWebKeyEvent> event) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_pre_key_event);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ntpis34P$27J5pNT2eFDmA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_pre_key_event");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_pre_key_event)) {
        ark_web_handler_on_pre_key_event = nullptr;
      } else {
        ark_web_handler_on_pre_key_event = _struct->on_pre_key_event;
      }
    } else {
      ark_web_handler_on_pre_key_event =
          reinterpret_cast<ArkWebHandlerOnPreKeyEventFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_pre_key_event, false);

  // Execute
  return ark_web_handler_on_pre_key_event(_struct,
                                          ArkWebKeyEventCppToC::Invert(event));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnScaleChanged(float old_scale_factor,
                                         float new_scale_factor) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_scale_changed);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "5Q6YoTkYLzsiZrQjDE$OdQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_scale_changed");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_scale_changed)) {
        ark_web_handler_on_scale_changed = nullptr;
      } else {
        ark_web_handler_on_scale_changed = _struct->on_scale_changed;
      }
    } else {
      ark_web_handler_on_scale_changed =
          reinterpret_cast<ArkWebHandlerOnScaleChangedFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_scale_changed,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_scale_changed(_struct, old_scale_factor, new_scale_factor);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnCursorChange(const int32_t& type,
                                         ArkWebRefPtr<ArkWebCursorInfo> info) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_cursor_change);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "tR8WYcPXGGue6fOnYkNYXw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_cursor_change");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_cursor_change)) {
        ark_web_handler_on_cursor_change = nullptr;
      } else {
        ark_web_handler_on_cursor_change = _struct->on_cursor_change;
      }
    } else {
      ark_web_handler_on_cursor_change =
          reinterpret_cast<ArkWebHandlerOnCursorChangeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_cursor_change, false);

  // Execute
  return ark_web_handler_on_cursor_change(_struct, &type,
                                          ArkWebCursorInfoCppToC::Invert(info));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnRenderExited(int reason) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_render_exited);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "qZrA$XaO8wSMO4NvW1ve4g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_render_exited");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_render_exited)) {
        ark_web_handler_on_render_exited = nullptr;
      } else {
        ark_web_handler_on_render_exited = _struct->on_render_exited;
      }
    } else {
      ark_web_handler_on_render_exited =
          reinterpret_cast<ArkWebHandlerOnRenderExitedFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_render_exited,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_render_exited(_struct, reason);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnResizeNotWork() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_resize_not_work);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "pp5wn3hx2snmP5fOg_zcpQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_resize_not_work");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_resize_not_work)) {
        ark_web_handler_on_resize_not_work = nullptr;
      } else {
        ark_web_handler_on_resize_not_work = _struct->on_resize_not_work;
      }
    } else {
      ark_web_handler_on_resize_not_work =
          reinterpret_cast<ArkWebHandlerOnResizeNotWorkFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_resize_not_work,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_resize_not_work(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnFullScreenExit() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_full_screen_exit);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "7S0aOEFIKodAK7PRjo08dw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_full_screen_exit");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_full_screen_exit)) {
        ark_web_handler_on_full_screen_exit = nullptr;
      } else {
        ark_web_handler_on_full_screen_exit = _struct->on_full_screen_exit;
      }
    } else {
      ark_web_handler_on_full_screen_exit =
          reinterpret_cast<ArkWebHandlerOnFullScreenExitFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_full_screen_exit,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_full_screen_exit(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnFullScreenEnter(
    ArkWebRefPtr<ArkWebFullScreenExitHandler> handler) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_full_screen_enter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "RBBJrG$jsmUoaZW36Gr7Xg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_full_screen_enter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_full_screen_enter)) {
        ark_web_handler_on_full_screen_enter = nullptr;
      } else {
        ark_web_handler_on_full_screen_enter = _struct->on_full_screen_enter;
      }
    } else {
      ark_web_handler_on_full_screen_enter =
          reinterpret_cast<ArkWebHandlerOnFullScreenEnterFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_full_screen_enter,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_full_screen_enter(
      _struct, ArkWebFullScreenExitHandlerCppToC::Invert(handler));
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnDragAndDropData(
    const void* data,
    size_t len,
    ArkWebRefPtr<ArkWebImageOptions> opt) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_drag_and_drop_data);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "_4A5qmTdSMjjUNguCan8$A";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_drag_and_drop_data");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_drag_and_drop_data)) {
        ark_web_handler_on_drag_and_drop_data = nullptr;
      } else {
        ark_web_handler_on_drag_and_drop_data = _struct->on_drag_and_drop_data;
      }
    } else {
      ark_web_handler_on_drag_and_drop_data =
          reinterpret_cast<ArkWebHandlerOnDragAndDropDataFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_drag_and_drop_data,
                                    false);

  // Execute
  return ark_web_handler_on_drag_and_drop_data(
      _struct, data, len, ArkWebImageOptionsCppToC::Invert(opt));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnSelectPopupMenu(
    ArkWebRefPtr<ArkWebSelectPopupMenuParam> params,
    ArkWebRefPtr<ArkWebSelectPopupMenuCallback> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_select_popup_menu);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "6W$4dKJW_q4eGmz0$OzOGA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_select_popup_menu");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_select_popup_menu)) {
        ark_web_handler_on_select_popup_menu = nullptr;
      } else {
        ark_web_handler_on_select_popup_menu = _struct->on_select_popup_menu;
      }
    } else {
      ark_web_handler_on_select_popup_menu =
          reinterpret_cast<ArkWebHandlerOnSelectPopupMenuFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_select_popup_menu,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_select_popup_menu(
      _struct, ArkWebSelectPopupMenuParamCppToC::Invert(params),
      ArkWebSelectPopupMenuCallbackCppToC::Invert(callback));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnDataResubmission(
    ArkWebRefPtr<ArkWebDataResubmissionCallback> handler) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_data_resubmission);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "1KAD7OCpi2KkmVoWAMHcYA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_data_resubmission");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_data_resubmission)) {
        ark_web_handler_on_data_resubmission = nullptr;
      } else {
        ark_web_handler_on_data_resubmission = _struct->on_data_resubmission;
      }
    } else {
      ark_web_handler_on_data_resubmission =
          reinterpret_cast<ArkWebHandlerOnDataResubmissionFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_data_resubmission,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_data_resubmission(
      _struct, ArkWebDataResubmissionCallbackCppToC::Invert(handler));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnRootLayerChanged(int width, int height) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_root_layer_changed);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "pBPzW4AsAYVJ6_xz0Pq2qw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_root_layer_changed");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_root_layer_changed)) {
        ark_web_handler_on_root_layer_changed = nullptr;
      } else {
        ark_web_handler_on_root_layer_changed = _struct->on_root_layer_changed;
      }
    } else {
      ark_web_handler_on_root_layer_changed =
          reinterpret_cast<ArkWebHandlerOnRootLayerChangedFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_root_layer_changed,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_root_layer_changed(_struct, width, height);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnAudioStateChanged(bool playing) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_audio_state_changed);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "8u$xNivgBXeDSPkovQps5w";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_audio_state_changed");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_audio_state_changed)) {
        ark_web_handler_on_audio_state_changed = nullptr;
      } else {
        ark_web_handler_on_audio_state_changed =
            _struct->on_audio_state_changed;
      }
    } else {
      ark_web_handler_on_audio_state_changed =
          reinterpret_cast<ArkWebHandlerOnAudioStateChangedFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_audio_state_changed,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_audio_state_changed(_struct, playing);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnOverScrollFlingEnd() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_over_scroll_fling_end);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "rAJnej1Ube91cJmLkmt01w";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_over_scroll_fling_end");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_over_scroll_fling_end)) {
        ark_web_handler_on_over_scroll_fling_end = nullptr;
      } else {
        ark_web_handler_on_over_scroll_fling_end =
            _struct->on_over_scroll_fling_end;
      }
    } else {
      ark_web_handler_on_over_scroll_fling_end =
          reinterpret_cast<ArkWebHandlerOnOverScrollFlingEndFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_over_scroll_fling_end,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_over_scroll_fling_end(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnUnProcessedKeyEvent(
    ArkWebRefPtr<ArkWebKeyEvent> event) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_un_processed_key_event);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "7RAkYoTmtiZZc9jivD1jBQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_un_processed_key_event");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_un_processed_key_event)) {
        ark_web_handler_on_un_processed_key_event = nullptr;
      } else {
        ark_web_handler_on_un_processed_key_event =
            _struct->on_un_processed_key_event;
      }
    } else {
      ark_web_handler_on_un_processed_key_event =
          reinterpret_cast<ArkWebHandlerOnUnProcessedKeyEventFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_un_processed_key_event,
                                    false);

  // Execute
  return ark_web_handler_on_un_processed_key_event(
      _struct, ArkWebKeyEventCppToC::Invert(event));
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnDragAndDropDataUdmf(
    ArkWebRefPtr<ArkWebDragData> drag_data) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_drag_and_drop_data_udmf);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "RvAS661w7OSwpT_LeuUKfA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_drag_and_drop_data_udmf");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_drag_and_drop_data_udmf)) {
        ark_web_handler_on_drag_and_drop_data_udmf = nullptr;
      } else {
        ark_web_handler_on_drag_and_drop_data_udmf =
            _struct->on_drag_and_drop_data_udmf;
      }
    } else {
      ark_web_handler_on_drag_and_drop_data_udmf =
          reinterpret_cast<ArkWebHandlerOnDragAndDropDataUdmfFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_drag_and_drop_data_udmf,
                                    false);

  // Execute
  return ark_web_handler_on_drag_and_drop_data_udmf(
      _struct, ArkWebDragDataCppToC::Invert(drag_data));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnFirstContentfulPaint(
    int64_t navigation_start_tick,
    int64_t first_contentful_paint_ms) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_first_contentful_paint);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "bsC9xULwHys1zGohQyAudA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_first_contentful_paint");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_first_contentful_paint)) {
        ark_web_handler_on_first_contentful_paint = nullptr;
      } else {
        ark_web_handler_on_first_contentful_paint =
            _struct->on_first_contentful_paint;
      }
    } else {
      ark_web_handler_on_first_contentful_paint =
          reinterpret_cast<ArkWebHandlerOnFirstContentfulPaintFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_first_contentful_paint,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_first_contentful_paint(_struct, navigation_start_tick,
                                            first_contentful_paint_ms);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnDateTimeChooserPopup(
    ArkWebRefPtr<ArkWebDateTimeChooser> chooser,
    const ArkWebDateTimeSuggestionVector& suggestions,
    ArkWebRefPtr<ArkWebDateTimeChooserCallback> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_date_time_chooser_popup);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "PPlsfIgSZ2p4Yy05B82lZQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_date_time_chooser_popup");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_date_time_chooser_popup)) {
        ark_web_handler_on_date_time_chooser_popup = nullptr;
      } else {
        ark_web_handler_on_date_time_chooser_popup =
            _struct->on_date_time_chooser_popup;
      }
    } else {
      ark_web_handler_on_date_time_chooser_popup =
          reinterpret_cast<ArkWebHandlerOnDateTimeChooserPopupFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_date_time_chooser_popup,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_date_time_chooser_popup(
      _struct, ArkWebDateTimeChooserCppToC::Invert(chooser), &suggestions,
      ArkWebDateTimeChooserCallbackCppToC::Invert(callback));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnDateTimeChooserClose() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_date_time_chooser_close);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "9orVQ39F_hctLtWyMBnEbA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_date_time_chooser_close");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_date_time_chooser_close)) {
        ark_web_handler_on_date_time_chooser_close = nullptr;
      } else {
        ark_web_handler_on_date_time_chooser_close =
            _struct->on_date_time_chooser_close;
      }
    } else {
      ark_web_handler_on_date_time_chooser_close =
          reinterpret_cast<ArkWebHandlerOnDateTimeChooserCloseFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_date_time_chooser_close,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_date_time_chooser_close(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnScreenCaptureRequest(
    ArkWebRefPtr<ArkWebScreenCaptureAccessRequest> request) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_screen_capture_request);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "HgfR$iUs_80h2WMTgsFNuw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_screen_capture_request");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_screen_capture_request)) {
        ark_web_handler_on_screen_capture_request = nullptr;
      } else {
        ark_web_handler_on_screen_capture_request =
            _struct->on_screen_capture_request;
      }
    } else {
      ark_web_handler_on_screen_capture_request =
          reinterpret_cast<ArkWebHandlerOnScreenCaptureRequestFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_screen_capture_request,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_screen_capture_request(
      _struct, ArkWebScreenCaptureAccessRequestCppToC::Invert(request));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnActivityStateChanged(int state, int type) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_activity_state_changed);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "T7z52cM6VJHfq9QPyleM9A";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_activity_state_changed");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_activity_state_changed)) {
        ark_web_handler_on_activity_state_changed = nullptr;
      } else {
        ark_web_handler_on_activity_state_changed =
            _struct->on_activity_state_changed;
      }
    } else {
      ark_web_handler_on_activity_state_changed =
          reinterpret_cast<ArkWebHandlerOnActivityStateChangedFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_activity_state_changed,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_activity_state_changed(_struct, state, type);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnGetTouchHandleHotZone(
    ArkWebRefPtr<ArkWebTouchHandleHotZone> hot_zone) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_get_touch_handle_hot_zone);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Jg$5Q_m$2AvQOxEeijABuw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_get_touch_handle_hot_zone");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_get_touch_handle_hot_zone)) {
        ark_web_handler_on_get_touch_handle_hot_zone = nullptr;
      } else {
        ark_web_handler_on_get_touch_handle_hot_zone =
            _struct->on_get_touch_handle_hot_zone;
      }
    } else {
      ark_web_handler_on_get_touch_handle_hot_zone =
          reinterpret_cast<ArkWebHandlerOnGetTouchHandleHotZoneFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_get_touch_handle_hot_zone, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_get_touch_handle_hot_zone(
      _struct, ArkWebTouchHandleHotZoneCppToC::Invert(hot_zone));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnCompleteSwapWithNewSize() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_complete_swap_with_new_size);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Wrm9wezVuqbzrAZ$Mwj2UA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_complete_swap_with_new_size");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      on_complete_swap_with_new_size)) {
        ark_web_handler_on_complete_swap_with_new_size = nullptr;
      } else {
        ark_web_handler_on_complete_swap_with_new_size =
            _struct->on_complete_swap_with_new_size;
      }
    } else {
      ark_web_handler_on_complete_swap_with_new_size =
          reinterpret_cast<ArkWebHandlerOnCompleteSwapWithNewSizeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_complete_swap_with_new_size, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_complete_swap_with_new_size(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnOverScrollFlingVelocity(float x_velocity,
                                                    float y_velocity,
                                                    bool is_fling) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_over_scroll_fling_velocity);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "0ciLcf$ffJr04TIXItFTnQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_over_scroll_fling_velocity");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_over_scroll_fling_velocity)) {
        ark_web_handler_on_over_scroll_fling_velocity = nullptr;
      } else {
        ark_web_handler_on_over_scroll_fling_velocity =
            _struct->on_over_scroll_fling_velocity;
      }
    } else {
      ark_web_handler_on_over_scroll_fling_velocity =
          reinterpret_cast<ArkWebHandlerOnOverScrollFlingVelocityFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_over_scroll_fling_velocity, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_over_scroll_fling_velocity(_struct, x_velocity, y_velocity,
                                                is_fling);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnNavigationEntryCommitted(
    ArkWebRefPtr<ArkWebLoadCommittedDetails> details) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_navigation_entry_committed);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "XjEOiUlrc_8UW1ghmhsiPQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_navigation_entry_committed");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_navigation_entry_committed)) {
        ark_web_handler_on_navigation_entry_committed = nullptr;
      } else {
        ark_web_handler_on_navigation_entry_committed =
            _struct->on_navigation_entry_committed;
      }
    } else {
      ark_web_handler_on_navigation_entry_committed =
          reinterpret_cast<ArkWebHandlerOnNavigationEntryCommittedFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_navigation_entry_committed, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_navigation_entry_committed(
      _struct, ArkWebLoadCommittedDetailsCppToC::Invert(details));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnNativeEmbedLifecycleChange(
    ArkWebRefPtr<ArkWebNativeEmbedDataInfo> data_info) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_native_embed_lifecycle_change);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "kWKI5p7VNTpsmfhAq8hUlw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_native_embed_lifecycle_change");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      on_native_embed_lifecycle_change)) {
        ark_web_handler_on_native_embed_lifecycle_change = nullptr;
      } else {
        ark_web_handler_on_native_embed_lifecycle_change =
            _struct->on_native_embed_lifecycle_change;
      }
    } else {
      ark_web_handler_on_native_embed_lifecycle_change =
          reinterpret_cast<ArkWebHandlerOnNativeEmbedLifecycleChangeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_native_embed_lifecycle_change, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_native_embed_lifecycle_change(
      _struct, ArkWebNativeEmbedDataInfoCppToC::Invert(data_info));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnNativeEmbedGestureEvent(
    ArkWebRefPtr<ArkWebNativeEmbedTouchEvent> touch_event) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_native_embed_gesture_event);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "AsuppTheoY4d6139Gqv8aQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_native_embed_gesture_event");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_native_embed_gesture_event)) {
        ark_web_handler_on_native_embed_gesture_event = nullptr;
      } else {
        ark_web_handler_on_native_embed_gesture_event =
            _struct->on_native_embed_gesture_event;
      }
    } else {
      ark_web_handler_on_native_embed_gesture_event =
          reinterpret_cast<ArkWebHandlerOnNativeEmbedGestureEventFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_native_embed_gesture_event, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_native_embed_gesture_event(
      _struct, ArkWebNativeEmbedTouchEventCppToC::Invert(touch_event));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnSafeBrowsingCheckResult(int threat_type) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_safe_browsing_check_result);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "nSDG9EotIBkex7F9zNYjLA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_safe_browsing_check_result");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_safe_browsing_check_result)) {
        ark_web_handler_on_safe_browsing_check_result = nullptr;
      } else {
        ark_web_handler_on_safe_browsing_check_result =
            _struct->on_safe_browsing_check_result;
      }
    } else {
      ark_web_handler_on_safe_browsing_check_result =
          reinterpret_cast<ArkWebHandlerOnSafeBrowsingCheckResultFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_safe_browsing_check_result, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_safe_browsing_check_result(_struct, threat_type);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnIntelligentTrackingPreventionResult(
    const ArkWebString& website_host,
    const ArkWebString& tracker_host) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_handler_on_intelligent_tracking_prevention_result);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "KXqcB_gtBLyA_kriD4Msbw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_intelligent_tracking_prevention_result");
      if (ARK_WEB_FUNC_MEMBER_MISSING(
              _struct, on_intelligent_tracking_prevention_result)) {
        ark_web_handler_on_intelligent_tracking_prevention_result = nullptr;
      } else {
        ark_web_handler_on_intelligent_tracking_prevention_result =
            _struct->on_intelligent_tracking_prevention_result;
      }
    } else {
      ark_web_handler_on_intelligent_tracking_prevention_result =
          reinterpret_cast<
              ArkWebHandlerOnIntelligentTrackingPreventionResultFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_intelligent_tracking_prevention_result,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_intelligent_tracking_prevention_result(
      _struct, &website_host, &tracker_host);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnFullScreenEnterWithVideoSize(
    ArkWebRefPtr<ArkWebFullScreenExitHandler> handler,
    int video_natural_width,
    int video_natural_height) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_handler_on_full_screen_enter_with_video_size);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "a7iTZMjKVlGGAjuU_n28Mw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_full_screen_enter_with_video_size");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      on_full_screen_enter_with_video_size)) {
        ark_web_handler_on_full_screen_enter_with_video_size = nullptr;
      } else {
        ark_web_handler_on_full_screen_enter_with_video_size =
            _struct->on_full_screen_enter_with_video_size;
      }
    } else {
      ark_web_handler_on_full_screen_enter_with_video_size =
          reinterpret_cast<ArkWebHandlerOnFullScreenEnterWithVideoSizeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_full_screen_enter_with_video_size,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_full_screen_enter_with_video_size(
      _struct, ArkWebFullScreenExitHandlerCppToC::Invert(handler),
      video_natural_width, video_natural_height);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnHandleOverrideUrlLoading(
    ArkWebRefPtr<ArkWebUrlResourceRequest> request) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_handle_override_url_loading);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "7RYci924KJYPD6nqFBOWFg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_handle_override_url_loading");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      on_handle_override_url_loading)) {
        ark_web_handler_on_handle_override_url_loading = nullptr;
      } else {
        ark_web_handler_on_handle_override_url_loading =
            _struct->on_handle_override_url_loading;
      }
    } else {
      ark_web_handler_on_handle_override_url_loading =
          reinterpret_cast<ArkWebHandlerOnHandleOverrideUrlLoadingFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_handle_override_url_loading, false);

  // Execute
  return ark_web_handler_on_handle_override_url_loading(
      _struct, ArkWebUrlResourceRequestCppToC::Invert(request));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnFirstMeaningfulPaint(
    ArkWebRefPtr<ArkWebFirstMeaningfulPaintDetails> details) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_first_meaningful_paint);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "3GdCvnOLX66v7A2okrrtOA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_first_meaningful_paint");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_first_meaningful_paint)) {
        ark_web_handler_on_first_meaningful_paint = nullptr;
      } else {
        ark_web_handler_on_first_meaningful_paint =
            _struct->on_first_meaningful_paint;
      }
    } else {
      ark_web_handler_on_first_meaningful_paint =
          reinterpret_cast<ArkWebHandlerOnFirstMeaningfulPaintFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_first_meaningful_paint,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_first_meaningful_paint(
      _struct, ArkWebFirstMeaningfulPaintDetailsCppToC::Invert(details));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnLargestContentfulPaint(
    ArkWebRefPtr<ArkWebLargestContentfulPaintDetails> details) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_largest_contentful_paint);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "_M9c9bHzdmGg3m2RxSmnyw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_largest_contentful_paint");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_largest_contentful_paint)) {
        ark_web_handler_on_largest_contentful_paint = nullptr;
      } else {
        ark_web_handler_on_largest_contentful_paint =
            _struct->on_largest_contentful_paint;
      }
    } else {
      ark_web_handler_on_largest_contentful_paint =
          reinterpret_cast<ArkWebHandlerOnLargestContentfulPaintFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_largest_contentful_paint,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_largest_contentful_paint(
      _struct, ArkWebLargestContentfulPaintDetailsCppToC::Invert(details));
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnAllSslErrorRequestByJS(
    ArkWebRefPtr<ArkWebJsAllSslErrorResult> result,
    int error,
    const ArkWebString& url,
    const ArkWebString& originalUrl,
    const ArkWebString& referrer,
    bool isFatalError,
    bool isMainFrame) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_all_ssl_error_request_by_js);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "q0gGxYXnM88$mT2nhrZFzQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_all_ssl_error_request_by_js");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      on_all_ssl_error_request_by_js)) {
        ark_web_handler_on_all_ssl_error_request_by_js = nullptr;
      } else {
        ark_web_handler_on_all_ssl_error_request_by_js =
            _struct->on_all_ssl_error_request_by_js;
      }
    } else {
      ark_web_handler_on_all_ssl_error_request_by_js =
          reinterpret_cast<ArkWebHandlerOnAllSslErrorRequestByJSFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_all_ssl_error_request_by_js, false);

  // Execute
  return ark_web_handler_on_all_ssl_error_request_by_js(
      _struct, ArkWebJsAllSslErrorResultCppToC::Invert(result), error, &url,
      &originalUrl, &referrer, isFatalError, isMainFrame);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnTooltip(const ArkWebString& tooltip) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_tooltip);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "r_lOMPuYYv$ixsP6NFasJg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_tooltip");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_tooltip)) {
        ark_web_handler_on_tooltip = nullptr;
      } else {
        ark_web_handler_on_tooltip = _struct->on_tooltip;
      }
    } else {
      ark_web_handler_on_tooltip =
          reinterpret_cast<ArkWebHandlerOnTooltipFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_tooltip,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_tooltip(_struct, &tooltip);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::ReleaseResizeHold() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_release_resize_hold);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "bpsCOe_6I5lv0v3cl2uO7w";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_release_resize_hold");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release_resize_hold)) {
        ark_web_handler_release_resize_hold = nullptr;
      } else {
        ark_web_handler_release_resize_hold = _struct->release_resize_hold;
      }
    } else {
      ark_web_handler_release_resize_hold =
          reinterpret_cast<ArkWebHandlerReleaseResizeHoldFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_release_resize_hold,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_release_resize_hold(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnShowAutofillPopup(
    const float offsetX,
    const float offsetY,
    const ArkWebStringVector& menu_items) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_show_autofill_popup);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "BMpEpZkNd5O8Seeupy8PrQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_show_autofill_popup");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_show_autofill_popup)) {
        ark_web_handler_on_show_autofill_popup = nullptr;
      } else {
        ark_web_handler_on_show_autofill_popup =
            _struct->on_show_autofill_popup;
      }
    } else {
      ark_web_handler_on_show_autofill_popup =
          reinterpret_cast<ArkWebHandlerOnShowAutofillPopupFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_show_autofill_popup,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_show_autofill_popup(_struct, offsetX, offsetY,
                                         &menu_items);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnHideAutofillPopup() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_hide_autofill_popup);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "TFVAornJ8nz8VC2IUHEXUw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_hide_autofill_popup");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_hide_autofill_popup)) {
        ark_web_handler_on_hide_autofill_popup = nullptr;
      } else {
        ark_web_handler_on_hide_autofill_popup =
            _struct->on_hide_autofill_popup;
      }
    } else {
      ark_web_handler_on_hide_autofill_popup =
          reinterpret_cast<ArkWebHandlerOnHideAutofillPopupFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_hide_autofill_popup,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_hide_autofill_popup(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebCharVector ArkWebHandlerCToCpp::GetWordSelection(const ArkWebString& text,
                                                       int8_t offset) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_char_vector_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_get_word_selection);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "GEFYoHGKE4QAeUViY4rjKA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_get_word_selection");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_word_selection)) {
        ark_web_handler_get_word_selection = nullptr;
      } else {
        ark_web_handler_get_word_selection = _struct->get_word_selection;
      }
    } else {
      ark_web_handler_get_word_selection =
          reinterpret_cast<ArkWebHandlerGetWordSelectionFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_get_word_selection,
                                    ark_web_char_vector_default);

  // Execute
  return ark_web_handler_get_word_selection(_struct, &text, offset);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::UpdateClippedSelectionBounds(int x,
                                                       int y,
                                                       int w,
                                                       int h) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_update_clipped_selection_bounds);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Eumjlxi6Qz5PNWyAFGkT1w";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_update_clipped_selection_bounds");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      update_clipped_selection_bounds)) {
        ark_web_handler_update_clipped_selection_bounds = nullptr;
      } else {
        ark_web_handler_update_clipped_selection_bounds =
            _struct->update_clipped_selection_bounds;
      }
    } else {
      ark_web_handler_update_clipped_selection_bounds =
          reinterpret_cast<ArkWebHandlerUpdateClippedSelectionBoundsFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_update_clipped_selection_bounds, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_update_clipped_selection_bounds(_struct, x, y, w, h);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnOpenAppLink(
    const ArkWebString& url,
    ArkWebRefPtr<ArkWebAppLinkCallback> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_open_app_link);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "FDqQCTxEZJvirOfgvWXNTg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_open_app_link");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_open_app_link)) {
        ark_web_handler_on_open_app_link = nullptr;
      } else {
        ark_web_handler_on_open_app_link = _struct->on_open_app_link;
      }
    } else {
      ark_web_handler_on_open_app_link =
          reinterpret_cast<ArkWebHandlerOnOpenAppLinkFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_open_app_link, false);

  // Execute
  return ark_web_handler_on_open_app_link(
      _struct, &url, ArkWebAppLinkCallbackCppToC::Invert(callback));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnRenderProcessNotResponding(
    const ArkWebString& js_stack,
    int pid,
    int reason) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_render_process_not_responding);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "gyqGb5CD5aQ5OEpUk_du5g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_render_process_not_responding");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      on_render_process_not_responding)) {
        ark_web_handler_on_render_process_not_responding = nullptr;
      } else {
        ark_web_handler_on_render_process_not_responding =
            _struct->on_render_process_not_responding;
      }
    } else {
      ark_web_handler_on_render_process_not_responding =
          reinterpret_cast<ArkWebHandlerOnRenderProcessNotRespondingFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_render_process_not_responding, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_render_process_not_responding(_struct, &js_stack, pid,
                                                   reason);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnRenderProcessResponding() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_render_process_responding);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "f$yq9OCRxkopqMF5ZyUYQw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_render_process_responding");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_render_process_responding)) {
        ark_web_handler_on_render_process_responding = nullptr;
      } else {
        ark_web_handler_on_render_process_responding =
            _struct->on_render_process_responding;
      }
    } else {
      ark_web_handler_on_render_process_responding =
          reinterpret_cast<ArkWebHandlerOnRenderProcessRespondingFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_render_process_responding, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_render_process_responding(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnViewportFitChange(int viewportFit) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_viewport_fit_change);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "j41qFTZoIlCE9tNj1_hMPA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_viewport_fit_change");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_viewport_fit_change)) {
        ark_web_handler_on_viewport_fit_change = nullptr;
      } else {
        ark_web_handler_on_viewport_fit_change =
            _struct->on_viewport_fit_change;
      }
    } else {
      ark_web_handler_on_viewport_fit_change =
          reinterpret_cast<ArkWebHandlerOnViewportFitChangeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_viewport_fit_change,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_viewport_fit_change(_struct, viewportFit);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::CreateOverlay(void* data,
                                        size_t len,
                                        int width,
                                        int height,
                                        int offset_x,
                                        int offset_y,
                                        int rect_width,
                                        int rect_height,
                                        int point_x,
                                        int point_y) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_create_overlay);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Ja304zfkxCftLU96N$AvEQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_create_overlay");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_overlay)) {
        ark_web_handler_create_overlay = nullptr;
      } else {
        ark_web_handler_create_overlay = _struct->create_overlay;
      }
    } else {
      ark_web_handler_create_overlay =
          reinterpret_cast<ArkWebHandlerCreateOverlayFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_create_overlay,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_create_overlay(_struct, data, len, width, height, offset_x,
                                 offset_y, rect_width, rect_height, point_x,
                                 point_y);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnOverlayStateChanged(int offset_x,
                                                int offset_y,
                                                int rect_width,
                                                int rect_height) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_overlay_state_changed);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "6x7vkgyxlpV5aZvsD2ITRw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_overlay_state_changed");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_overlay_state_changed)) {
        ark_web_handler_on_overlay_state_changed = nullptr;
      } else {
        ark_web_handler_on_overlay_state_changed =
            _struct->on_overlay_state_changed;
      }
    } else {
      ark_web_handler_on_overlay_state_changed =
          reinterpret_cast<ArkWebHandlerOnOverlayStateChangedFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_overlay_state_changed,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_overlay_state_changed(_struct, offset_x, offset_y,
                                           rect_width, rect_height);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnFocus(int source) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_focus2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "HGmn9TMFMK$DzmW6W_nmBg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_focus2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_focus2)) {
        ark_web_handler_on_focus2 = nullptr;
      } else {
        ark_web_handler_on_focus2 = _struct->on_focus2;
      }
    } else {
      ark_web_handler_on_focus2 =
          reinterpret_cast<ArkWebHandlerOnFocusFunc2>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_focus2, false);

  // Execute
  return ark_web_handler_on_focus2(_struct, source);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnOverScroll(float xOffset,
                                       float yOffset,
                                       float xVelocity,
                                       float yVelocity) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_over_scroll2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "6BtACvmydfAWfybyF6tHKA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_over_scroll2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_over_scroll2)) {
        ark_web_handler_on_over_scroll2 = nullptr;
      } else {
        ark_web_handler_on_over_scroll2 = _struct->on_over_scroll2;
      }
    } else {
      ark_web_handler_on_over_scroll2 =
          reinterpret_cast<ArkWebHandlerOnOverScrollFunc2>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_over_scroll2, false);

  // Execute
  return ark_web_handler_on_over_scroll2(_struct, xOffset, yOffset, xVelocity,
                                         yVelocity);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::KeyboardReDispatch(ArkWebRefPtr<ArkWebKeyEvent> event,
                                             bool isUsed) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_keyboard_re_dispatch);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "cCx$fdZdhdqlKMS8HN5mtg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_keyboard_re_dispatch");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, keyboard_re_dispatch)) {
        ark_web_handler_keyboard_re_dispatch = nullptr;
      } else {
        ark_web_handler_keyboard_re_dispatch = _struct->keyboard_re_dispatch;
      }
    } else {
      ark_web_handler_keyboard_re_dispatch =
          reinterpret_cast<ArkWebHandlerKeyboardReDispatchFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_keyboard_re_dispatch,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_keyboard_re_dispatch(
      _struct, ArkWebKeyEventCppToC::Invert(event), isUsed);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnInterceptKeyboardAttach(
    ArkWebRefPtr<ArkWebCustomKeyboardHandler> keyboardHandler,
    const ArkWebStringMap& attributes,
    bool& useSystemKeyboard,
    int32_t& enterKeyType) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_intercept_keyboard_attach);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "zsNoJr_8YANMQtHvwZDOmg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_intercept_keyboard_attach");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_intercept_keyboard_attach)) {
        ark_web_handler_on_intercept_keyboard_attach = nullptr;
      } else {
        ark_web_handler_on_intercept_keyboard_attach =
            _struct->on_intercept_keyboard_attach;
      }
    } else {
      ark_web_handler_on_intercept_keyboard_attach =
          reinterpret_cast<ArkWebHandlerOnInterceptKeyboardAttachFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_intercept_keyboard_attach, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_intercept_keyboard_attach(
      _struct, ArkWebCustomKeyboardHandlerCppToC::Invert(keyboardHandler),
      &attributes, &useSystemKeyboard, &enterKeyType);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnCustomKeyboardAttach() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_custom_keyboard_attach);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "CZNVycKIDPSSZsk879gSTg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_custom_keyboard_attach");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_custom_keyboard_attach)) {
        ark_web_handler_on_custom_keyboard_attach = nullptr;
      } else {
        ark_web_handler_on_custom_keyboard_attach =
            _struct->on_custom_keyboard_attach;
      }
    } else {
      ark_web_handler_on_custom_keyboard_attach =
          reinterpret_cast<ArkWebHandlerOnCustomKeyboardAttachFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_custom_keyboard_attach,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_custom_keyboard_attach(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnCustomKeyboardClose() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_custom_keyboard_close);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "eV0mHrbwgxMtjiJ63$$6MA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_custom_keyboard_close");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_custom_keyboard_close)) {
        ark_web_handler_on_custom_keyboard_close = nullptr;
      } else {
        ark_web_handler_on_custom_keyboard_close =
            _struct->on_custom_keyboard_close;
      }
    } else {
      ark_web_handler_on_custom_keyboard_close =
          reinterpret_cast<ArkWebHandlerOnCustomKeyboardCloseFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_custom_keyboard_close,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_custom_keyboard_close(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnAdsBlocked(const ArkWebString& url,
                                       const ArkWebStringVector& adsBlocked) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_ads_blocked);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "3gbH8SrTn0_kRG_9bYAJLg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_ads_blocked");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_ads_blocked)) {
        ark_web_handler_on_ads_blocked = nullptr;
      } else {
        ark_web_handler_on_ads_blocked = _struct->on_ads_blocked;
      }
    } else {
      ark_web_handler_on_ads_blocked =
          reinterpret_cast<ArkWebHandlerOnAdsBlockedFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_ads_blocked,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_ads_blocked(_struct, &url, &adsBlocked);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnCursorUpdate(double x,
                                         double y,
                                         double width,
                                         double height) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_cursor_update);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "iGV_9h8DGylnYziUyTzJrA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_cursor_update");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_cursor_update)) {
        ark_web_handler_on_cursor_update = nullptr;
      } else {
        ark_web_handler_on_cursor_update = _struct->on_cursor_update;
      }
    } else {
      ark_web_handler_on_cursor_update =
          reinterpret_cast<ArkWebHandlerOnCursorUpdateFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_cursor_update,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_cursor_update(_struct, x, y, width, height);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::ReportDynamicFrameLossEvent(
    const ArkWebString& sceneId,
    bool isStart) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_report_dynamic_frame_loss_event);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "0PVARgVtNfHgGAB5IyQtpg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_report_dynamic_frame_loss_event");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      report_dynamic_frame_loss_event)) {
        ark_web_handler_report_dynamic_frame_loss_event = nullptr;
      } else {
        ark_web_handler_report_dynamic_frame_loss_event =
            _struct->report_dynamic_frame_loss_event;
      }
    } else {
      ark_web_handler_report_dynamic_frame_loss_event =
          reinterpret_cast<ArkWebHandlerReportDynamicFrameLossEventFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_report_dynamic_frame_loss_event, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_report_dynamic_frame_loss_event(_struct, &sceneId, isStart);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::HideHandleAndQuickMenuIfNecessary(bool hide) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_handler_hide_handle_and_quick_menu_if_necessary);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "6O7SU3gCjREf$rBG$qimBQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_hide_handle_and_quick_menu_if_necessary");
      if (ARK_WEB_FUNC_MEMBER_MISSING(
              _struct, hide_handle_and_quick_menu_if_necessary)) {
        ark_web_handler_hide_handle_and_quick_menu_if_necessary = nullptr;
      } else {
        ark_web_handler_hide_handle_and_quick_menu_if_necessary =
            _struct->hide_handle_and_quick_menu_if_necessary;
      }
    } else {
      ark_web_handler_hide_handle_and_quick_menu_if_necessary =
          reinterpret_cast<ArkWebHandlerHideHandleAndQuickMenuIfNecessaryFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_hide_handle_and_quick_menu_if_necessary,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_hide_handle_and_quick_menu_if_necessary(_struct, hide);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::ChangeVisibilityOfQuickMenu() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_change_visibility_of_quick_menu);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "5oArTQ90HjtCgtSMJEL9FQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_change_visibility_of_quick_menu");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      change_visibility_of_quick_menu)) {
        ark_web_handler_change_visibility_of_quick_menu = nullptr;
      } else {
        ark_web_handler_change_visibility_of_quick_menu =
            _struct->change_visibility_of_quick_menu;
      }
    } else {
      ark_web_handler_change_visibility_of_quick_menu =
          reinterpret_cast<ArkWebHandlerChangeVisibilityOfQuickMenuFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_change_visibility_of_quick_menu, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_change_visibility_of_quick_menu(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::StartVibraFeedback(const ArkWebString& vibratorType) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_start_vibra_feedback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "YaPkQKlrtSjoZzpUZHAiOQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_start_vibra_feedback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start_vibra_feedback)) {
        ark_web_handler_start_vibra_feedback = nullptr;
      } else {
        ark_web_handler_start_vibra_feedback = _struct->start_vibra_feedback;
      }
    } else {
      ark_web_handler_start_vibra_feedback =
          reinterpret_cast<ArkWebHandlerStartVibraFeedbackFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_start_vibra_feedback,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_start_vibra_feedback(_struct, &vibratorType);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnPopupSize(int x, int y, int width, int height) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_popup_size);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "96VGGyOyfN95T1c0bJ24iQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_popup_size");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_popup_size)) {
        ark_web_handler_on_popup_size = nullptr;
      } else {
        ark_web_handler_on_popup_size = _struct->on_popup_size;
      }
    } else {
      ark_web_handler_on_popup_size =
          reinterpret_cast<ArkWebHandlerOnPopupSizeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_popup_size,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_popup_size(_struct, x, y, width, height);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnPopupShow(bool show) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_popup_show);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Y4VLrraf06wdCyPCVWgOPQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_popup_show");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_popup_show)) {
        ark_web_handler_on_popup_show = nullptr;
      } else {
        ark_web_handler_on_popup_show = _struct->on_popup_show;
      }
    } else {
      ark_web_handler_on_popup_show =
          reinterpret_cast<ArkWebHandlerOnPopupShowFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_popup_show,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_popup_show(_struct, show);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnNativeEmbedVisibilityChange(
    const ArkWebString& embed_id,
    bool visibility) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_handler_on_native_embed_visibility_change);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "EVgIS8pE0cSZweHVTIcROQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_native_embed_visibility_change");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      on_native_embed_visibility_change)) {
        ark_web_handler_on_native_embed_visibility_change = nullptr;
      } else {
        ark_web_handler_on_native_embed_visibility_change =
            _struct->on_native_embed_visibility_change;
      }
    } else {
      ark_web_handler_on_native_embed_visibility_change =
          reinterpret_cast<ArkWebHandlerOnNativeEmbedVisibilityChangeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_native_embed_visibility_change, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_native_embed_visibility_change(_struct, &embed_id,
                                                    visibility);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::CloseImageOverlaySelection() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_close_image_overlay_selection);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "SM26v4h6ZWuSUc59gboQNg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_close_image_overlay_selection");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, close_image_overlay_selection)) {
        ark_web_handler_close_image_overlay_selection = nullptr;
      } else {
        ark_web_handler_close_image_overlay_selection =
            _struct->close_image_overlay_selection;
      }
    } else {
      ark_web_handler_close_image_overlay_selection =
          reinterpret_cast<ArkWebHandlerCloseImageOverlaySelectionFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_close_image_overlay_selection, false);

  // Execute
  return ark_web_handler_close_image_overlay_selection(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnSslErrorRequestByJSV2(
    ArkWebRefPtr<ArkWebJsSslErrorResult> result,
    int error,
    const ArkWebStringVector& certChainData) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_ssl_error_request_by_jsv2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "_r1j86H6uno0OcU30vTF7g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_ssl_error_request_by_jsv2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_ssl_error_request_by_jsv2)) {
        ark_web_handler_on_ssl_error_request_by_jsv2 = nullptr;
      } else {
        ark_web_handler_on_ssl_error_request_by_jsv2 =
            _struct->on_ssl_error_request_by_jsv2;
      }
    } else {
      ark_web_handler_on_ssl_error_request_by_jsv2 =
          reinterpret_cast<ArkWebHandlerOnSslErrorRequestByJSV2Func>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_ssl_error_request_by_jsv2, false);

  // Execute
  return ark_web_handler_on_ssl_error_request_by_jsv2(
      _struct, ArkWebJsSslErrorResultCppToC::Invert(result), error,
      &certChainData);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnAccessibilityEvent(int64_t accessibilityId,
                                               int32_t eventType) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_accessibility_event);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "JpgRU$s_VX40pwEHNBhxJA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_accessibility_event");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_accessibility_event)) {
        ark_web_handler_on_accessibility_event = nullptr;
      } else {
        ark_web_handler_on_accessibility_event =
            _struct->on_accessibility_event;
      }
    } else {
      ark_web_handler_on_accessibility_event =
          reinterpret_cast<ArkWebHandlerOnAccessibilityEventFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_accessibility_event,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_accessibility_event(_struct, accessibilityId, eventType);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::IsCurrentFocus() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_is_current_focus);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Nlk5f3t17LYwb5k8s52TIQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_is_current_focus");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_current_focus)) {
        ark_web_handler_is_current_focus = nullptr;
      } else {
        ark_web_handler_is_current_focus = _struct->is_current_focus;
      }
    } else {
      ark_web_handler_is_current_focus =
          reinterpret_cast<ArkWebHandlerIsCurrentFocusFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_is_current_focus, false);

  // Execute
  return ark_web_handler_is_current_focus(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::GetVisibleRectToWeb(int& visibleX,
                                              int& visibleY,
                                              int& visibleWidth,
                                              int& visibleHeight) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_get_visible_rect_to_web);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "O_I7x0CpwglFqblSx3vvkQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_get_visible_rect_to_web");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_visible_rect_to_web)) {
        ark_web_handler_get_visible_rect_to_web = nullptr;
      } else {
        ark_web_handler_get_visible_rect_to_web =
            _struct->get_visible_rect_to_web;
      }
    } else {
      ark_web_handler_get_visible_rect_to_web =
          reinterpret_cast<ArkWebHandlerGetVisibleRectToWebFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_get_visible_rect_to_web,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_get_visible_rect_to_web(_struct, &visibleX, &visibleY,
                                          &visibleWidth, &visibleHeight);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnScrollStart(const float x, const float y) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_scroll_start);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "sShxP0679156$Kn_rtbMOA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_scroll_start");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_scroll_start)) {
        ark_web_handler_on_scroll_start = nullptr;
      } else {
        ark_web_handler_on_scroll_start = _struct->on_scroll_start;
      }
    } else {
      ark_web_handler_on_scroll_start =
          reinterpret_cast<ArkWebHandlerOnScrollStartFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_scroll_start,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_scroll_start(_struct, x, y);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnShowAutofillPopupV2(
    const float offsetX,
    const float offsetY,
    const float height,
    const float width,
    const ArkWebStringVector& menu_items) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_show_autofill_popup_v2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Tp917m81ZqbNJUqm8PaUDQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_show_autofill_popup_v2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_show_autofill_popup_v2)) {
        ark_web_handler_on_show_autofill_popup_v2 = nullptr;
      } else {
        ark_web_handler_on_show_autofill_popup_v2 =
            _struct->on_show_autofill_popup_v2;
      }
    } else {
      ark_web_handler_on_show_autofill_popup_v2 =
          reinterpret_cast<ArkWebHandlerOnShowAutofillPopupV2Func>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_show_autofill_popup_v2,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_show_autofill_popup_v2(_struct, offsetX, offsetY, height,
                                            width, &menu_items);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::RestoreRenderFit() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_restore_render_fit);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "DNRuhotpSHOHCyhM3ZPDdA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_restore_render_fit");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, restore_render_fit)) {
        ark_web_handler_restore_render_fit = nullptr;
      } else {
        ark_web_handler_restore_render_fit = _struct->restore_render_fit;
      }
    } else {
      ark_web_handler_restore_render_fit =
          reinterpret_cast<ArkWebHandlerRestoreRenderFitFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_restore_render_fit,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_restore_render_fit(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnAccessibilityEventV2(int64_t accessibilityId,
                                                 int32_t eventType,
                                                 const ArkWebString& argument) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_accessibility_event_v2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "H$X59DRpFGnNOriOI5_RbA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_accessibility_event_v2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_accessibility_event_v2)) {
        ark_web_handler_on_accessibility_event_v2 = nullptr;
      } else {
        ark_web_handler_on_accessibility_event_v2 =
            _struct->on_accessibility_event_v2;
      }
    } else {
      ark_web_handler_on_accessibility_event_v2 =
          reinterpret_cast<ArkWebHandlerOnAccessibilityEventV2Func>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_accessibility_event_v2,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_accessibility_event_v2(_struct, accessibilityId, eventType,
                                            &argument);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnNestedScroll(float& x,
                                         float& y,
                                         float& xVelocity,
                                         float& yVelocity,
                                         bool& isAvailable) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_nested_scroll);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "FLht6dRRIRhOh33ws6zl2Q";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_nested_scroll");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_nested_scroll)) {
        ark_web_handler_on_nested_scroll = nullptr;
      } else {
        ark_web_handler_on_nested_scroll = _struct->on_nested_scroll;
      }
    } else {
      ark_web_handler_on_nested_scroll =
          reinterpret_cast<ArkWebHandlerOnNestedScrollFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_nested_scroll, false);

  // Execute
  return ark_web_handler_on_nested_scroll(_struct, &x, &y, &xVelocity,
                                          &yVelocity, &isAvailable);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::EnableSecurityLayer(bool isNeedSecurityLayer) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_enable_security_layer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "aCFtUvwzbrYRcGynvR_2cw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_enable_security_layer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, enable_security_layer)) {
        ark_web_handler_enable_security_layer = nullptr;
      } else {
        ark_web_handler_enable_security_layer = _struct->enable_security_layer;
      }
    } else {
      ark_web_handler_enable_security_layer =
          reinterpret_cast<ArkWebHandlerEnableSecurityLayerFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_enable_security_layer,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_enable_security_layer(_struct, isNeedSecurityLayer);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::ChangeVisibilityOfQuickMenuV2() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_handler_change_visibility_of_quick_menu_v2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "_v6Wzxq$fHAwNztgdaWGyA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_change_visibility_of_quick_menu_v2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      change_visibility_of_quick_menu_v2)) {
        ark_web_handler_change_visibility_of_quick_menu_v2 = nullptr;
      } else {
        ark_web_handler_change_visibility_of_quick_menu_v2 =
            _struct->change_visibility_of_quick_menu_v2;
      }
    } else {
      ark_web_handler_change_visibility_of_quick_menu_v2 =
          reinterpret_cast<ArkWebHandlerChangeVisibilityOfQuickMenuV2Func>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_change_visibility_of_quick_menu_v2, false);

  // Execute
  return ark_web_handler_change_visibility_of_quick_menu_v2(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnPip(int status,
                                int delegate_id,
                                int child_id,
                                int frame_routing_id,
                                int width,
                                int height) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_pip);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "FEu35T2tifK5fOsinrHROQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_pip");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_pip)) {
        ark_web_handler_on_pip = nullptr;
      } else {
        ark_web_handler_on_pip = _struct->on_pip;
      }
    } else {
      ark_web_handler_on_pip =
          reinterpret_cast<ArkWebHandlerOnPipFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_pip,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_pip(_struct, status, delegate_id, child_id,
                         frame_routing_id, width, height);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnBeforeUnloadByJSV2(
    const ArkWebString& url,
    const ArkWebString& message,
    bool isReload,
    ArkWebRefPtr<ArkWebJsDialogResult> result) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_before_unload_by_jsv2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "uzY4vU3O2J9XghgSg5Fw7A";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_before_unload_by_jsv2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_before_unload_by_jsv2)) {
        ark_web_handler_on_before_unload_by_jsv2 = nullptr;
      } else {
        ark_web_handler_on_before_unload_by_jsv2 =
            _struct->on_before_unload_by_jsv2;
      }
    } else {
      ark_web_handler_on_before_unload_by_jsv2 =
          reinterpret_cast<ArkWebHandlerOnBeforeUnloadByJSV2Func>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_before_unload_by_jsv2,
                                    false);

  // Execute
  return ark_web_handler_on_before_unload_by_jsv2(
      _struct, &url, &message, isReload,
      ArkWebJsDialogResultCppToC::Invert(result));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnNativeEmbedMouseEvent(
    ArkWebRefPtr<ArkWebNativeEmbedMouseEvent> mouse_event) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_native_embed_mouse_event);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "oGE1N4J$0x6YxZbpBqy$Nw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_native_embed_mouse_event");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_native_embed_mouse_event)) {
        ark_web_handler_on_native_embed_mouse_event = nullptr;
      } else {
        ark_web_handler_on_native_embed_mouse_event =
            _struct->on_native_embed_mouse_event;
      }
    } else {
      ark_web_handler_on_native_embed_mouse_event =
          reinterpret_cast<ArkWebHandlerOnNativeEmbedMouseEventFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_native_embed_mouse_event,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_native_embed_mouse_event(
      _struct, ArkWebNativeEmbedMouseEventCppToC::Invert(mouse_event));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnActivateContentByJS() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_activate_content_by_js);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "g8pSB1iCxQRdS_ZHKpvrDQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_activate_content_by_js");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_activate_content_by_js)) {
        ark_web_handler_on_activate_content_by_js = nullptr;
      } else {
        ark_web_handler_on_activate_content_by_js =
            _struct->on_activate_content_by_js;
      }
    } else {
      ark_web_handler_on_activate_content_by_js =
          reinterpret_cast<ArkWebHandlerOnActivateContentByJSFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_activate_content_by_js,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_activate_content_by_js(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnLoadStarted(const ArkWebString& url) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_load_started);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "SRDJiQtG876dIKNTux$iNQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_load_started");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_load_started)) {
        ark_web_handler_on_load_started = nullptr;
      } else {
        ark_web_handler_on_load_started = _struct->on_load_started;
      }
    } else {
      ark_web_handler_on_load_started =
          reinterpret_cast<ArkWebHandlerOnLoadStartedFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_load_started,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_load_started(_struct, &url);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnLoadFinished(const ArkWebString& url) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_load_finished);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "NoabUJFd_C3pjn_Wxk9kIQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_load_finished");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_load_finished)) {
        ark_web_handler_on_load_finished = nullptr;
      } else {
        ark_web_handler_on_load_finished = _struct->on_load_finished;
      }
    } else {
      ark_web_handler_on_load_finished =
          reinterpret_cast<ArkWebHandlerOnLoadFinishedFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_load_finished,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_load_finished(_struct, &url);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::OnAllSslErrorRequestByJSV2(
    ArkWebRefPtr<ArkWebJsAllSslErrorResult> result,
    int error,
    const ArkWebString& url,
    const ArkWebString& originalUrl,
    const ArkWebString& referrer,
    bool isFatalError,
    bool isMainFrame,
    const ArkWebStringVector& certChainData) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_all_ssl_error_request_by_jsv2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "myteyHEwLUEkDThmrbserw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_all_ssl_error_request_by_jsv2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      on_all_ssl_error_request_by_jsv2)) {
        ark_web_handler_on_all_ssl_error_request_by_jsv2 = nullptr;
      } else {
        ark_web_handler_on_all_ssl_error_request_by_jsv2 =
            _struct->on_all_ssl_error_request_by_jsv2;
      }
    } else {
      ark_web_handler_on_all_ssl_error_request_by_jsv2 =
          reinterpret_cast<ArkWebHandlerOnAllSslErrorRequestByJSV2Func>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_all_ssl_error_request_by_jsv2, false);

  // Execute
  return ark_web_handler_on_all_ssl_error_request_by_jsv2(
      _struct, ArkWebJsAllSslErrorResultCppToC::Invert(result), error, &url,
      &originalUrl, &referrer, isFatalError, isMainFrame, &certChainData);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::ShowMagnifier() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_show_magnifier);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ehgb8$lhKB1ufq18PFFgkA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_show_magnifier");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, show_magnifier)) {
        ark_web_handler_show_magnifier = nullptr;
      } else {
        ark_web_handler_show_magnifier = _struct->show_magnifier;
      }
    } else {
      ark_web_handler_show_magnifier =
          reinterpret_cast<ArkWebHandlerShowMagnifierFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_show_magnifier,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_show_magnifier(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::HideMagnifier() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_hide_magnifier);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "oCnrLlZ4KcB_6_GIS2kB9g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_hide_magnifier");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, hide_magnifier)) {
        ark_web_handler_hide_magnifier = nullptr;
      } else {
        ark_web_handler_hide_magnifier = _struct->hide_magnifier;
      }
    } else {
      ark_web_handler_hide_magnifier =
          reinterpret_cast<ArkWebHandlerHideMagnifierFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_hide_magnifier,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_hide_magnifier(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnPageTitleV2(const ArkWebString& title,
                                        bool isRealTitle) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_page_title_v2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "k90iq9QZRFG6kmrOOO1UZA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_page_title_v2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_page_title_v2)) {
        ark_web_handler_on_page_title_v2 = nullptr;
      } else {
        ark_web_handler_on_page_title_v2 = _struct->on_page_title_v2;
      }
    } else {
      ark_web_handler_on_page_title_v2 =
          reinterpret_cast<ArkWebHandlerOnPageTitleV2Func>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_page_title_v2,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_page_title_v2(_struct, &title, isRealTitle);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnInsertBlanklessFrame(
    const ArkWebString& pathToFrame) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_insert_blankless_frame);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "48agZ$$rrWJGnBKrCNQGgw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_insert_blankless_frame");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_insert_blankless_frame)) {
        ark_web_handler_on_insert_blankless_frame = nullptr;
      } else {
        ark_web_handler_on_insert_blankless_frame =
            _struct->on_insert_blankless_frame;
      }
    } else {
      ark_web_handler_on_insert_blankless_frame =
          reinterpret_cast<ArkWebHandlerOnInsertBlanklessFrameFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_insert_blankless_frame,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_insert_blankless_frame(_struct, &pathToFrame);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnRemoveBlanklessFrame(int delayTime) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_remove_blankless_frame);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "IkZrHMXFnNK9lF_x8IpLEA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_remove_blankless_frame");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_remove_blankless_frame)) {
        ark_web_handler_on_remove_blankless_frame = nullptr;
      } else {
        ark_web_handler_on_remove_blankless_frame =
            _struct->on_remove_blankless_frame;
      }
    } else {
      ark_web_handler_on_remove_blankless_frame =
          reinterpret_cast<ArkWebHandlerOnRemoveBlanklessFrameFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_remove_blankless_frame,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_remove_blankless_frame(_struct, delayTime);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkWebHandlerCToCpp::OnHandleOverrideErrorPage(
    ArkWebRefPtr<ArkWebUrlResourceRequest> request,
    ArkWebRefPtr<ArkWebUrlResourceError> error) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_handle_override_error_page);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "BBgyXd2WYX6edVGjvdXs$Q";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_handle_override_error_page");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_handle_override_error_page)) {
        ark_web_handler_on_handle_override_error_page = nullptr;
      } else {
        ark_web_handler_on_handle_override_error_page =
            _struct->on_handle_override_error_page;
      }
    } else {
      ark_web_handler_on_handle_override_error_page =
          reinterpret_cast<ArkWebHandlerOnHandleOverrideErrorPageFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_handle_override_error_page, ark_web_string_default);

  // Execute
  return ark_web_handler_on_handle_override_error_page(
      _struct, ArkWebUrlResourceRequestCppToC::Invert(request),
      ArkWebUrlResourceErrorCppToC::Invert(error));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnPdfScrollAtBottom(const ArkWebString& url) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_pdf_scroll_at_bottom);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "S3NymGhKUU0E7kmrLaoLfg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_pdf_scroll_at_bottom");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_pdf_scroll_at_bottom)) {
        ark_web_handler_on_pdf_scroll_at_bottom = nullptr;
      } else {
        ark_web_handler_on_pdf_scroll_at_bottom =
            _struct->on_pdf_scroll_at_bottom;
      }
    } else {
      ark_web_handler_on_pdf_scroll_at_bottom =
          reinterpret_cast<ArkWebHandlerOnPdfScrollAtBottomFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_pdf_scroll_at_bottom,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_pdf_scroll_at_bottom(_struct, &url);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnPdfLoadEvent(int32_t result,
                                         const ArkWebString& url) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_pdf_load_event);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "CdTlj2_dldQ0ZVBczhxD4A";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_pdf_load_event");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_pdf_load_event)) {
        ark_web_handler_on_pdf_load_event = nullptr;
      } else {
        ark_web_handler_on_pdf_load_event = _struct->on_pdf_load_event;
      }
    } else {
      ark_web_handler_on_pdf_load_event =
          reinterpret_cast<ArkWebHandlerOnPdfLoadEventFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_pdf_load_event,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_pdf_load_event(_struct, result, &url);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnTakeFocus(ArkWebRefPtr<ArkWebKeyEvent> event) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_on_take_focus);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "liBOAOWd6aakUDc7rSBa8g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_take_focus");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_take_focus)) {
        ark_web_handler_on_take_focus = nullptr;
      } else {
        ark_web_handler_on_take_focus = _struct->on_take_focus;
      }
    } else {
      ark_web_handler_on_take_focus =
          reinterpret_cast<ArkWebHandlerOnTakeFocusFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_take_focus,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_take_focus(_struct, ArkWebKeyEventCppToC::Invert(event));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnInsertBlanklessFrameWithSize(
    const ArkWebString& pathToFrame,
    uint32_t width,
    uint32_t height) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_handler_on_insert_blankless_frame_with_size);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "V8EebGeQ5C_ZLeGB4oFTwg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_insert_blankless_frame_with_size");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      on_insert_blankless_frame_with_size)) {
        ark_web_handler_on_insert_blankless_frame_with_size = nullptr;
      } else {
        ark_web_handler_on_insert_blankless_frame_with_size =
            _struct->on_insert_blankless_frame_with_size;
      }
    } else {
      ark_web_handler_on_insert_blankless_frame_with_size =
          reinterpret_cast<ArkWebHandlerOnInsertBlanklessFrameWithSizeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_insert_blankless_frame_with_size, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_insert_blankless_frame_with_size(_struct, &pathToFrame,
                                                      width, height);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::SetImeShow(bool visible) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_set_ime_show);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Jn57kxsUahRNqQAzlo2$IA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_set_ime_show");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_ime_show)) {
        ark_web_handler_set_ime_show = nullptr;
      } else {
        ark_web_handler_set_ime_show = _struct->set_ime_show;
      }
    } else {
      ark_web_handler_set_ime_show =
          reinterpret_cast<ArkWebHandlerSetImeShowFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_set_ime_show,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_set_ime_show(_struct, visible);
}

ARK_WEB_NO_SANITIZE
bool ArkWebHandlerCToCpp::IsShowHandle() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(ark_web_handler_is_show_handle);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "FajmmX3Uuv_BtUqyXOTnNQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_is_show_handle");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_show_handle)) {
        ark_web_handler_is_show_handle = nullptr;
      } else {
        ark_web_handler_is_show_handle = _struct->is_show_handle;
      }
    } else {
      ark_web_handler_is_show_handle =
          reinterpret_cast<ArkWebHandlerIsShowHandleFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_is_show_handle, false);

  // Execute
  return ark_web_handler_is_show_handle(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnNativeEmbedObjectParamChange(
    ArkWebRefPtr<ArkWebNativeEmbedParamDataInfo> data_info) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_handler_on_native_embed_object_param_change);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "cbKATLrIHCpwcw4TWznxRw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_native_embed_object_param_change");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      on_native_embed_object_param_change)) {
        ark_web_handler_on_native_embed_object_param_change = nullptr;
      } else {
        ark_web_handler_on_native_embed_object_param_change =
            _struct->on_native_embed_object_param_change;
      }
    } else {
      ark_web_handler_on_native_embed_object_param_change =
          reinterpret_cast<ArkWebHandlerOnNativeEmbedObjectParamChangeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_native_embed_object_param_change, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_native_embed_object_param_change(
      _struct, ArkWebNativeEmbedParamDataInfoCppToC::Invert(data_info));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnSafeBrowsingCheckFinish(int threat_type) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_safe_browsing_check_finish);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "mFlhWmlBXGwCFatW1oF8MA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_safe_browsing_check_finish");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_safe_browsing_check_finish)) {
        ark_web_handler_on_safe_browsing_check_finish = nullptr;
      } else {
        ark_web_handler_on_safe_browsing_check_finish =
            _struct->on_safe_browsing_check_finish;
      }
    } else {
      ark_web_handler_on_safe_browsing_check_finish =
          reinterpret_cast<ArkWebHandlerOnSafeBrowsingCheckFinishFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_safe_browsing_check_finish, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_safe_browsing_check_finish(_struct, threat_type);
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnExtensionDisconnect(int32_t connectId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_extension_disconnect);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "0khDzy0rMpb0aOOScTI2_A";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_extension_disconnect");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_extension_disconnect)) {
        ark_web_handler_on_extension_disconnect = nullptr;
      } else {
        ark_web_handler_on_extension_disconnect =
            _struct->on_extension_disconnect;
      }
    } else {
      ark_web_handler_on_extension_disconnect =
          reinterpret_cast<ArkWebHandlerOnExtensionDisconnectFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_extension_disconnect,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_extension_disconnect(_struct, connectId);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkWebHandlerCToCpp::OnWebNativeMessage(
    ArkWebRefPtr<ArkWebRuntimeConnectInfo> info,
    ArkWebRefPtr<ArkWebNativeMessageCallback> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_web_native_message);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "mpWVnlw$zHx0Ktzydi7w_w";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_handler_on_web_native_message");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_web_native_message)) {
        ark_web_handler_on_web_native_message = nullptr;
      } else {
        ark_web_handler_on_web_native_message = _struct->on_web_native_message;
      }
    } else {
      ark_web_handler_on_web_native_message =
          reinterpret_cast<ArkWebHandlerOnWebNativeMessageFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_handler_on_web_native_message,
                                    ark_web_string_default);

  // Execute
  return ark_web_handler_on_web_native_message(
      _struct, ArkWebRuntimeConnectInfoCppToC::Invert(info),
      ArkWebNativeMessageCallbackCppToC::Invert(callback));
}

ARK_WEB_NO_SANITIZE
void ArkWebHandlerCToCpp::OnRefreshAccessedHistoryV2(const ArkWebString& url,
                                                     bool isReload,
                                                     bool isMainFrame) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_handler_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_handler_on_refresh_accessed_history_v2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "MKUV8FUu0q8YmdPpEV8OuA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_HANDLER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_handler_on_refresh_accessed_history_v2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      on_refresh_accessed_history_v2)) {
        ark_web_handler_on_refresh_accessed_history_v2 = nullptr;
      } else {
        ark_web_handler_on_refresh_accessed_history_v2 =
            _struct->on_refresh_accessed_history_v2;
      }
    } else {
      ark_web_handler_on_refresh_accessed_history_v2 =
          reinterpret_cast<ArkWebHandlerOnRefreshAccessedHistoryV2Func>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_handler_on_refresh_accessed_history_v2, ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_handler_on_refresh_accessed_history_v2(_struct, &url, isReload,
                                                 isMainFrame);
}

ArkWebHandlerCToCpp::ArkWebHandlerCToCpp() {}

ArkWebHandlerCToCpp::~ArkWebHandlerCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkWebHandlerCToCpp,
                                        ArkWebHandler,
                                        ark_web_handler_t>::kBridgeType =
    ARK_WEB_HANDLER;

}  // namespace OHOS::ArkWeb
