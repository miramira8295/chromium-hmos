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

#include "ohos_nweb/cpptoc/ark_web_nweb_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"
#include "ohos_nweb/cpptoc/ark_web_accessibility_node_info_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_drag_data_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_history_list_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_hit_test_result_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_preference_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_print_document_adapter_adapter_cpptoc.h"
#include "ohos_nweb/ctocpp/ark_web_accessibility_event_callback_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_array_buffer_value_callback_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_bool_value_callback_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_cache_options_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_create_native_media_player_callback_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_download_callback_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_drag_event_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_find_callback_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_handler_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_js_proxy_method_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_js_result_callback_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_keyboard_event_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_message_value_callback_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_mouse_event_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_pdfconfig_args_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_release_surface_callback_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_rom_value_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_screen_lock_callback_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_spanstring_convert_html_callback_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_string_value_callback_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_stylus_touch_point_info_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_system_configuration_ctocpp.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK ark_web_nweb_resize(struct _ark_web_nweb_t* self,
                                          uint32_t width,
                                          uint32_t height,
                                          bool is_keyboard) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->Resize(width, height, is_keyboard);
}

void ARK_WEB_CALLBACK ark_web_nweb_on_pause(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnPause();
}

void ARK_WEB_CALLBACK ark_web_nweb_on_continue(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnContinue();
}

void ARK_WEB_CALLBACK ark_web_nweb_on_destroy(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnDestroy();
}

void ARK_WEB_CALLBACK ark_web_nweb_on_focus(struct _ark_web_nweb_t* self,
                                            const int32_t* focus_reason) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(focus_reason, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnFocus(*focus_reason);
}

void ARK_WEB_CALLBACK ark_web_nweb_on_blur(struct _ark_web_nweb_t* self,
                                           const int32_t* blur_reason) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(blur_reason, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnBlur(*blur_reason);
}

void ARK_WEB_CALLBACK ark_web_nweb_on_touch_press(struct _ark_web_nweb_t* self,
                                                  int32_t id,
                                                  double x,
                                                  double y,
                                                  bool from_overlay) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnTouchPress(id, x, y, from_overlay);
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_touch_release(struct _ark_web_nweb_t* self,
                              int32_t id,
                              double x,
                              double y,
                              bool from_overlay) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnTouchRelease(id, x, y, from_overlay);
}

void ARK_WEB_CALLBACK ark_web_nweb_on_touch_move1(struct _ark_web_nweb_t* self,
                                                  int32_t id,
                                                  double x,
                                                  double y,
                                                  bool from_overlay) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnTouchMove(id, x, y, from_overlay);
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_touch_move2(struct _ark_web_nweb_t* self,
                            const ArkWebTouchPointInfoVector* touch_point_infos,
                            bool from_overlay) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(touch_point_infos, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnTouchMove(*touch_point_infos, from_overlay);
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_touch_cancel(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnTouchCancel();
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_navigate_back(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnNavigateBack();
}

bool ARK_WEB_CALLBACK ark_web_nweb_send_key_event(struct _ark_web_nweb_t* self,
                                                  int32_t key_code,
                                                  int32_t key_action) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->SendKeyEvent(key_code, key_action);
}

void ARK_WEB_CALLBACK
ark_web_nweb_send_mouse_wheel_event(struct _ark_web_nweb_t* self,
                                    double x,
                                    double y,
                                    double delta_x,
                                    double delta_y) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SendMouseWheelEvent(x, y, delta_x, delta_y);
}

void ARK_WEB_CALLBACK
ark_web_nweb_send_mouse_event(struct _ark_web_nweb_t* self,
                              int x,
                              int y,
                              int button,
                              int action,
                              int count) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SendMouseEvent(x, y, button, action, count);
}

int ARK_WEB_CALLBACK ark_web_nweb_load1(struct _ark_web_nweb_t* self,
                                        const ArkWebString* url) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->Load(*url);
}

bool ARK_WEB_CALLBACK
ark_web_nweb_is_navigatebackward_allowed(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->IsNavigatebackwardAllowed();
}

bool ARK_WEB_CALLBACK
ark_web_nweb_is_navigate_forward_allowed(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->IsNavigateForwardAllowed();
}

bool ARK_WEB_CALLBACK
ark_web_nweb_can_navigate_back_or_forward(struct _ark_web_nweb_t* self,
                                          int num_steps) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->CanNavigateBackOrForward(num_steps);
}

void ARK_WEB_CALLBACK ark_web_nweb_navigate_back(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->NavigateBack();
}

void ARK_WEB_CALLBACK
ark_web_nweb_navigate_forward(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->NavigateForward();
}

void ARK_WEB_CALLBACK
ark_web_nweb_navigate_back_or_forward(struct _ark_web_nweb_t* self, int step) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->NavigateBackOrForward(step);
}

void ARK_WEB_CALLBACK
ark_web_nweb_delete_navigate_history(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->DeleteNavigateHistory();
}

void ARK_WEB_CALLBACK ark_web_nweb_reload(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->Reload();
}

int ARK_WEB_CALLBACK ark_web_nweb_zoom(struct _ark_web_nweb_t* self,
                                       float zoom_factor) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->Zoom(zoom_factor);
}

int ARK_WEB_CALLBACK ark_web_nweb_zoom_in(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->ZoomIn();
}

int ARK_WEB_CALLBACK ark_web_nweb_zoom_out(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->ZoomOut();
}

void ARK_WEB_CALLBACK ark_web_nweb_stop(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->Stop();
}

void ARK_WEB_CALLBACK
ark_web_nweb_execute_java_script1(struct _ark_web_nweb_t* self,
                                  const ArkWebString* code) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(code, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->ExecuteJavaScript(*code);
}

void ARK_WEB_CALLBACK
ark_web_nweb_execute_java_script2(struct _ark_web_nweb_t* self,
                                  const ArkWebString* code,
                                  ark_web_message_value_callback_t* callback,
                                  bool extention) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(code, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->ExecuteJavaScript(
      *code, ArkWebMessageValueCallbackCToCpp::Invert(callback), extention);
}

ark_web_preference_t* ARK_WEB_CALLBACK
ark_web_nweb_get_preference(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebPreference> _retval =
      ArkWebNWebCppToC::Get(self)->GetPreference();

  // Return type: refptr_same
  return ArkWebPreferenceCppToC::Invert(_retval);
}

unsigned int ARK_WEB_CALLBACK
ark_web_nweb_get_web_id(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetWebId();
}

ark_web_hit_test_result_t* ARK_WEB_CALLBACK
ark_web_nweb_get_hit_test_result(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebHitTestResult> _retval =
      ArkWebNWebCppToC::Get(self)->GetHitTestResult();

  // Return type: refptr_same
  return ArkWebHitTestResultCppToC::Invert(_retval);
}

void ARK_WEB_CALLBACK
ark_web_nweb_put_background_color(struct _ark_web_nweb_t* self, int color) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PutBackgroundColor(color);
}

void ARK_WEB_CALLBACK ark_web_nweb_initial_scale(struct _ark_web_nweb_t* self,
                                                 float scale) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->InitialScale(scale);
}

void ARK_WEB_CALLBACK ark_web_nweb_put_download_callback(
    struct _ark_web_nweb_t* self,
    ark_web_download_callback_t* download_listener) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PutDownloadCallback(
      ArkWebDownloadCallbackCToCpp::Invert(download_listener));
}

void ARK_WEB_CALLBACK ark_web_nweb_put_accessibility_event_callback(
    struct _ark_web_nweb_t* self,
    ark_web_accessibility_event_callback_t* accessibility_event_listener) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PutAccessibilityEventCallback(
      ArkWebAccessibilityEventCallbackCToCpp::Invert(
          accessibility_event_listener));
}

void ARK_WEB_CALLBACK ark_web_nweb_put_accessibility_id_generator(
    struct _ark_web_nweb_t* self,
    const AccessibilityIdGenerateFunc accessibility_id_generator) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PutAccessibilityIdGenerator(
      accessibility_id_generator);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_nweb_handler(struct _ark_web_nweb_t* self,
                              ark_web_handler_t* handler) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetNWebHandler(
      ArkWebHandlerCToCpp::Invert(handler));
}

ArkWebString ARK_WEB_CALLBACK ark_web_nweb_title(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebNWebCppToC::Get(self)->Title();
}

int ARK_WEB_CALLBACK
ark_web_nweb_page_load_progress(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->PageLoadProgress();
}

int ARK_WEB_CALLBACK ark_web_nweb_content_height(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->ContentHeight();
}

float ARK_WEB_CALLBACK ark_web_nweb_scale(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->Scale();
}

int ARK_WEB_CALLBACK
ark_web_nweb_load2(struct _ark_web_nweb_t* self,
                   const ArkWebString* url,
                   const ArkWebStringMap* additional_http_headers) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(additional_http_headers, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->Load(*url, *additional_http_headers);
}

int ARK_WEB_CALLBACK
ark_web_nweb_load_with_data_and_base_url(struct _ark_web_nweb_t* self,
                                         const ArkWebString* base_url,
                                         const ArkWebString* data,
                                         const ArkWebString* mime_type,
                                         const ArkWebString* encoding,
                                         const ArkWebString* history_url) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(base_url, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(data, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(mime_type, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(encoding, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(history_url, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->LoadWithDataAndBaseUrl(
      *base_url, *data, *mime_type, *encoding, *history_url);
}

int ARK_WEB_CALLBACK ark_web_nweb_load_with_data(struct _ark_web_nweb_t* self,
                                                 const ArkWebString* data,
                                                 const ArkWebString* mime_type,
                                                 const ArkWebString* encoding) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(data, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(mime_type, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(encoding, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->LoadWithData(*data, *mime_type,
                                                   *encoding);
}

void ARK_WEB_CALLBACK
ark_web_nweb_register_ark_jsfunction1(struct _ark_web_nweb_t* self,
                                      const ArkWebString* object_name,
                                      const ArkWebStringVector* method_list,
                                      const int32_t object_id) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(object_name, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(method_list, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->RegisterArkJSfunction(*object_name, *method_list,
                                                     object_id);
}

void ARK_WEB_CALLBACK
ark_web_nweb_unregister_ark_jsfunction(struct _ark_web_nweb_t* self,
                                       const ArkWebString* object_name,
                                       const ArkWebStringVector* method_list) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(object_name, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(method_list, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->UnregisterArkJSfunction(*object_name,
                                                       *method_list);
}

void ARK_WEB_CALLBACK ark_web_nweb_set_nweb_java_script_result_call_back(
    struct _ark_web_nweb_t* self,
    ark_web_js_result_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetNWebJavaScriptResultCallBack(
      ArkWebJsResultCallbackCToCpp::Invert(callback));
}

void ARK_WEB_CALLBACK
ark_web_nweb_put_find_callback(struct _ark_web_nweb_t* self,
                               ark_web_find_callback_t* find_listener) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PutFindCallback(
      ArkWebFindCallbackCToCpp::Invert(find_listener));
}

void ARK_WEB_CALLBACK
ark_web_nweb_find_all_async(struct _ark_web_nweb_t* self,
                            const ArkWebString* search_str) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(search_str, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->FindAllAsync(*search_str);
}

void ARK_WEB_CALLBACK ark_web_nweb_clear_matches(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->ClearMatches();
}

void ARK_WEB_CALLBACK ark_web_nweb_find_next(struct _ark_web_nweb_t* self,
                                             const bool forward) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->FindNext(forward);
}

void ARK_WEB_CALLBACK
ark_web_nweb_store_web_archive(struct _ark_web_nweb_t* self,
                               const ArkWebString* base_name,
                               bool auto_name,
                               ark_web_string_value_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(base_name, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->StoreWebArchive(
      *base_name, auto_name, ArkWebStringValueCallbackCToCpp::Invert(callback));
}

ArkWebStringVector ARK_WEB_CALLBACK
ark_web_nweb_create_web_message_ports(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_vector_default);

  // Execute
  return ArkWebNWebCppToC::Get(self)->CreateWebMessagePorts();
}

void ARK_WEB_CALLBACK
ark_web_nweb_post_web_message(struct _ark_web_nweb_t* self,
                              const ArkWebString* message,
                              const ArkWebStringVector* ports,
                              const ArkWebString* target_uri) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(message, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(ports, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(target_uri, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PostWebMessage(*message, *ports, *target_uri);
}

void ARK_WEB_CALLBACK ark_web_nweb_close_port(struct _ark_web_nweb_t* self,
                                              const ArkWebString* port_handle) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(port_handle, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->ClosePort(*port_handle);
}

void ARK_WEB_CALLBACK
ark_web_nweb_post_port_message(struct _ark_web_nweb_t* self,
                               const ArkWebString* port_handle,
                               const ArkWebMessage* data) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(port_handle, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(data, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PostPortMessage(*port_handle, *data);
}

void ARK_WEB_CALLBACK ark_web_nweb_set_port_message_callback(
    struct _ark_web_nweb_t* self,
    const ArkWebString* port_handle,
    ark_web_message_value_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(port_handle, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetPortMessageCallback(
      *port_handle, ArkWebMessageValueCallbackCToCpp::Invert(callback));
}

void ARK_WEB_CALLBACK
ark_web_nweb_send_drag_event(struct _ark_web_nweb_t* self,
                             ark_web_drag_event_t* drag_event) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SendDragEvent(
      ArkWebDragEventCToCpp::Invert(drag_event));
}

void ARK_WEB_CALLBACK
ark_web_nweb_clear_ssl_cache(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->ClearSslCache();
}

ArkWebString ARK_WEB_CALLBACK
ark_web_nweb_get_url(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetUrl();
}

void ARK_WEB_CALLBACK
ark_web_nweb_clear_client_authentication_cache(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->ClearClientAuthenticationCache();
}

void ARK_WEB_CALLBACK ark_web_nweb_update_locale(struct _ark_web_nweb_t* self,
                                                 const ArkWebString* language,
                                                 const ArkWebString* region) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(language, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(region, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->UpdateLocale(*language, *region);
}

const ArkWebString ARK_WEB_CALLBACK
ark_web_nweb_get_original_url(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetOriginalUrl();
}

bool ARK_WEB_CALLBACK ark_web_nweb_get_favicon(struct _ark_web_nweb_t* self,
                                               const void** data,
                                               size_t* width,
                                               size_t* height,
                                               int* color_type,
                                               int* alpha_type) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);
  ARK_WEB_CPPTOC_CHECK_PARAM(width, false);
  ARK_WEB_CPPTOC_CHECK_PARAM(height, false);
  ARK_WEB_CPPTOC_CHECK_PARAM(color_type, false);
  ARK_WEB_CPPTOC_CHECK_PARAM(alpha_type, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetFavicon(data, *width, *height,
                                                 *color_type, *alpha_type);
}

void ARK_WEB_CALLBACK
ark_web_nweb_put_network_available(struct _ark_web_nweb_t* self,
                                   bool available) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PutNetworkAvailable(available);
}

void ARK_WEB_CALLBACK
ark_web_nweb_has_images(struct _ark_web_nweb_t* self,
                        ark_web_bool_value_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->HasImages(
      ArkWebBoolValueCallbackCToCpp::Invert(callback));
}

void ARK_WEB_CALLBACK ark_web_nweb_remove_cache(struct _ark_web_nweb_t* self,
                                                bool include_disk_files) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->RemoveCache(include_disk_files);
}

ark_web_history_list_t* ARK_WEB_CALLBACK
ark_web_nweb_get_history_list(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebHistoryList> _retval =
      ArkWebNWebCppToC::Get(self)->GetHistoryList();

  // Return type: refptr_same
  return ArkWebHistoryListCppToC::Invert(_retval);
}

void ARK_WEB_CALLBACK ark_web_nweb_put_release_surface_callback(
    struct _ark_web_nweb_t* self,
    ark_web_release_surface_callback_t* release_surface_listener) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PutReleaseSurfaceCallback(
      ArkWebReleaseSurfaceCallbackCToCpp::Invert(release_surface_listener));
}

ArkWebUint8Vector ARK_WEB_CALLBACK
ark_web_nweb_serialize_web_state(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_uint8_vector_default);

  // Execute
  return ArkWebNWebCppToC::Get(self)->SerializeWebState();
}

bool ARK_WEB_CALLBACK
ark_web_nweb_restore_web_state(struct _ark_web_nweb_t* self,
                               const ArkWebUint8Vector* state) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);
  ARK_WEB_CPPTOC_CHECK_PARAM(state, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->RestoreWebState(*state);
}

void ARK_WEB_CALLBACK ark_web_nweb_page_up(struct _ark_web_nweb_t* self,
                                           bool top) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PageUp(top);
}

void ARK_WEB_CALLBACK ark_web_nweb_page_down(struct _ark_web_nweb_t* self,
                                             bool bottom) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PageDown(bottom);
}

void ARK_WEB_CALLBACK ark_web_nweb_scroll_to(struct _ark_web_nweb_t* self,
                                             float x,
                                             float y) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->ScrollTo(x, y);
}

void ARK_WEB_CALLBACK ark_web_nweb_scroll_by(struct _ark_web_nweb_t* self,
                                             float delta_x,
                                             float delta_y) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->ScrollBy(delta_x, delta_y);
}

void ARK_WEB_CALLBACK ark_web_nweb_slide_scroll(struct _ark_web_nweb_t* self,
                                                float vx,
                                                float vy) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SlideScroll(vx, vy);
}

bool ARK_WEB_CALLBACK
ark_web_nweb_get_cert_chain_der_data(struct _ark_web_nweb_t* self,
                                     ArkWebStringVector* cert_chain_data,
                                     bool is_single_cert) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);
  ARK_WEB_CPPTOC_CHECK_PARAM(cert_chain_data, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetCertChainDerData(*cert_chain_data,
                                                          is_single_cert);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_screen_off_set(struct _ark_web_nweb_t* self,
                                double x,
                                double y) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetScreenOffSet(x, y);
}

void ARK_WEB_CALLBACK ark_web_nweb_set_audio_muted(struct _ark_web_nweb_t* self,
                                                   bool muted) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetAudioMuted(muted);
}

void ARK_WEB_CALLBACK ark_web_nweb_set_should_frame_submission_before_draw(
    struct _ark_web_nweb_t* self,
    bool should) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetShouldFrameSubmissionBeforeDraw(should);
}

void ARK_WEB_CALLBACK
ark_web_nweb_notify_popup_window_result(struct _ark_web_nweb_t* self,
                                        bool result) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->NotifyPopupWindowResult(result);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_audio_resume_interval(struct _ark_web_nweb_t* self,
                                       int32_t resume_interval) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetAudioResumeInterval(resume_interval);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_audio_exclusive(struct _ark_web_nweb_t* self,
                                 bool audio_exclusive) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetAudioExclusive(audio_exclusive);
}

void ARK_WEB_CALLBACK ark_web_nweb_register_screen_lock_function(
    struct _ark_web_nweb_t* self,
    int32_t window_id,
    ark_web_screen_lock_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->RegisterScreenLockFunction(
      window_id, ArkWebScreenLockCallbackCToCpp::Invert(callback));
}

void ARK_WEB_CALLBACK
ark_web_nweb_un_register_screen_lock_function(struct _ark_web_nweb_t* self,
                                              int32_t window_id) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->UnRegisterScreenLockFunction(window_id);
}

void ARK_WEB_CALLBACK
ark_web_nweb_notify_memory_level(struct _ark_web_nweb_t* self, int32_t level) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->NotifyMemoryLevel(level);
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_webview_hide(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnWebviewHide();
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_webview_show(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnWebviewShow();
}

ark_web_drag_data_t* ARK_WEB_CALLBACK
ark_web_nweb_get_or_create_drag_data(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebDragData> _retval =
      ArkWebNWebCppToC::Get(self)->GetOrCreateDragData();

  // Return type: refptr_same
  return ArkWebDragDataCppToC::Invert(_retval);
}

void ARK_WEB_CALLBACK
ark_web_nweb_prefetch_page(struct _ark_web_nweb_t* self,
                           const ArkWebString* url,
                           const ArkWebStringMap* additional_http_headers) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(additional_http_headers, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PrefetchPage(*url, *additional_http_headers);
}

void ARK_WEB_CALLBACK ark_web_nweb_set_window_id(struct _ark_web_nweb_t* self,
                                                 uint32_t window_id) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetWindowId(window_id);
}

void ARK_WEB_CALLBACK ark_web_nweb_on_occluded(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnOccluded();
}

void ARK_WEB_CALLBACK ark_web_nweb_on_unoccluded(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnUnoccluded();
}

void ARK_WEB_CALLBACK ark_web_nweb_set_token(struct _ark_web_nweb_t* self,
                                             void* token) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetToken(token);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_nested_scroll_mode(struct _ark_web_nweb_t* self,
                                    const int32_t* nested_scroll_mode) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(nested_scroll_mode, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetNestedScrollMode(*nested_scroll_mode);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_enable_lower_frame_rate(struct _ark_web_nweb_t* self,
                                         bool enabled) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetEnableLowerFrameRate(enabled);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_virtual_key_board_arg(struct _ark_web_nweb_t* self,
                                       int32_t width,
                                       int32_t height,
                                       double keyboard) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetVirtualKeyBoardArg(width, height, keyboard);
}

bool ARK_WEB_CALLBACK
ark_web_nweb_should_virtual_keyboard_overlay(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->ShouldVirtualKeyboardOverlay();
}

void ARK_WEB_CALLBACK ark_web_nweb_set_draw_rect(struct _ark_web_nweb_t* self,
                                                 int32_t x,
                                                 int32_t y,
                                                 int32_t width,
                                                 int32_t height) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetDrawRect(x, y, width, height);
}

void ARK_WEB_CALLBACK ark_web_nweb_set_draw_mode(struct _ark_web_nweb_t* self,
                                                 int32_t mode) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetDrawMode(mode);
}

void* ARK_WEB_CALLBACK
ark_web_nweb_create_web_print_document_adapter(struct _ark_web_nweb_t* self,
                                               const ArkWebString* job_name) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);
  ARK_WEB_CPPTOC_CHECK_PARAM(job_name, NULL);

  // Execute
  return ArkWebNWebCppToC::Get(self)->CreateWebPrintDocumentAdapter(*job_name);
}

int ARK_WEB_CALLBACK ark_web_nweb_post_url(struct _ark_web_nweb_t* self,
                                           const ArkWebString* url,
                                           const ArkWebCharVector* post_data) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(post_data, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->PostUrl(*url, *post_data);
}

void ARK_WEB_CALLBACK ark_web_nweb_java_script_on_document_start(
    struct _ark_web_nweb_t* self,
    const ArkWebStringVectorMap* script_items) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(script_items, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->JavaScriptOnDocumentStart(*script_items);
}

void ARK_WEB_CALLBACK ark_web_nweb_execute_action(struct _ark_web_nweb_t* self,
                                                  int64_t accessibility_id,
                                                  uint32_t action) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->ExecuteAction(accessibility_id, action);
}

ark_web_accessibility_node_info_t* ARK_WEB_CALLBACK
ark_web_nweb_get_focused_accessibility_node_info(struct _ark_web_nweb_t* self,
                                                 int64_t accessibility_id,
                                                 bool is_accessibility_focus) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebAccessibilityNodeInfo> _retval =
      ArkWebNWebCppToC::Get(self)->GetFocusedAccessibilityNodeInfo(
          accessibility_id, is_accessibility_focus);

  // Return type: refptr_same
  return ArkWebAccessibilityNodeInfoCppToC::Invert(_retval);
}

ark_web_accessibility_node_info_t* ARK_WEB_CALLBACK
ark_web_nweb_get_accessibility_node_info_by_id(struct _ark_web_nweb_t* self,
                                               int64_t accessibility_id) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebAccessibilityNodeInfo> _retval =
      ArkWebNWebCppToC::Get(self)->GetAccessibilityNodeInfoById(
          accessibility_id);

  // Return type: refptr_same
  return ArkWebAccessibilityNodeInfoCppToC::Invert(_retval);
}

ark_web_accessibility_node_info_t* ARK_WEB_CALLBACK
ark_web_nweb_get_accessibility_node_info_by_focus_move(
    struct _ark_web_nweb_t* self,
    int64_t accessibility_id,
    int32_t direction) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebAccessibilityNodeInfo> _retval =
      ArkWebNWebCppToC::Get(self)->GetAccessibilityNodeInfoByFocusMove(
          accessibility_id, direction);

  // Return type: refptr_same
  return ArkWebAccessibilityNodeInfoCppToC::Invert(_retval);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_accessibility_state(struct _ark_web_nweb_t* self, bool state) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetAccessibilityState(state);
}

bool ARK_WEB_CALLBACK
ark_web_nweb_need_soft_keyboard(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->NeedSoftKeyboard();
}

bool ARK_WEB_CALLBACK ark_web_nweb_discard(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->Discard();
}

bool ARK_WEB_CALLBACK ark_web_nweb_restore(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->Restore();
}

int ARK_WEB_CALLBACK
ark_web_nweb_get_security_level(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetSecurityLevel();
}

void ARK_WEB_CALLBACK
ark_web_nweb_call_h5function(struct _ark_web_nweb_t* self,
                             int32_t routingId,
                             int32_t h5ObjectId,
                             const ArkWebString* h5MethodName,
                             const ArkWebValueVector* args) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(h5MethodName, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(args, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->CallH5Function(routingId, h5ObjectId,
                                              *h5MethodName, *args);
}

bool ARK_WEB_CALLBACK
ark_web_nweb_is_incognito_mode(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->IsIncognitoMode();
}

void ARK_WEB_CALLBACK ark_web_nweb_register_native_ark_jsfunction(
    struct _ark_web_nweb_t* self,
    const char* objName,
    const ArkWebJsProxyCallbackVector* callbacks) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(callbacks, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->RegisterNativeArkJSFunction(objName, *callbacks);
}

void ARK_WEB_CALLBACK
ark_web_nweb_un_register_native_ark_jsfunction(struct _ark_web_nweb_t* self,
                                               const char* objName) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->UnRegisterNativeArkJSFunction(objName);
}

void ARK_WEB_CALLBACK ark_web_nweb_register_native_valide_callback(
    struct _ark_web_nweb_t* self,
    const char* webName,
    const NativeArkWebOnValidCallback callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->RegisterNativeValideCallback(webName, callback);
}

void ARK_WEB_CALLBACK ark_web_nweb_register_native_destroy_callback(
    struct _ark_web_nweb_t* self,
    const char* webName,
    const NativeArkWebOnValidCallback callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->RegisterNativeDestroyCallback(webName, callback);
}

void ARK_WEB_CALLBACK ark_web_nweb_java_script_on_document_end(
    struct _ark_web_nweb_t* self,
    const ArkWebStringVectorMap* script_items) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(script_items, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->JavaScriptOnDocumentEnd(*script_items);
}

void ARK_WEB_CALLBACK
ark_web_nweb_enable_safe_browsing(struct _ark_web_nweb_t* self, bool enable) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->EnableSafeBrowsing(enable);
}

bool ARK_WEB_CALLBACK
ark_web_nweb_is_safe_browsing_enabled(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->IsSafeBrowsingEnabled();
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_print_background(struct _ark_web_nweb_t* self, bool enable) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetPrintBackground(enable);
}

bool ARK_WEB_CALLBACK
ark_web_nweb_get_print_background(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetPrintBackground();
}

void ARK_WEB_CALLBACK
ark_web_nweb_close_all_media_presentations(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->CloseAllMediaPresentations();
}

void ARK_WEB_CALLBACK
ark_web_nweb_stop_all_media(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->StopAllMedia();
}

void ARK_WEB_CALLBACK
ark_web_nweb_resume_all_media(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->ResumeAllMedia();
}

void ARK_WEB_CALLBACK
ark_web_nweb_pause_all_media(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PauseAllMedia();
}

int ARK_WEB_CALLBACK
ark_web_nweb_get_media_playback_state(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetMediaPlaybackState();
}

void ARK_WEB_CALLBACK ark_web_nweb_enable_intelligent_tracking_prevention(
    struct _ark_web_nweb_t* self,
    bool enable) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->EnableIntelligentTrackingPrevention(enable);
}

bool ARK_WEB_CALLBACK ark_web_nweb_is_intelligent_tracking_prevention_enabled(
    struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->IsIntelligentTrackingPreventionEnabled();
}

void ARK_WEB_CALLBACK ark_web_nweb_start_camera(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->StartCamera();
}

void ARK_WEB_CALLBACK ark_web_nweb_stop_camera(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->StopCamera();
}

void ARK_WEB_CALLBACK ark_web_nweb_close_camera(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->CloseCamera();
}

ArkWebString ARK_WEB_CALLBACK
ark_web_nweb_get_last_javascript_proxy_calling_frame_url(
    struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetLastJavascriptProxyCallingFrameUrl();
}

bool ARK_WEB_CALLBACK
ark_web_nweb_get_pending_size_status(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetPendingSizeStatus();
}

void ARK_WEB_CALLBACK
ark_web_nweb_scroll_by_ref_screen(struct _ark_web_nweb_t* self,
                                  float delta_x,
                                  float delta_y,
                                  float vx,
                                  float vy) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->ScrollByRefScreen(delta_x, delta_y, vx, vy);
}

void ARK_WEB_CALLBACK
ark_web_nweb_execute_java_script_ext(struct _ark_web_nweb_t* self,
                                     const int fd,
                                     const size_t scriptLength,
                                     ark_web_message_value_callback_t* callback,
                                     bool extention) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->ExecuteJavaScriptExt(
      fd, scriptLength, ArkWebMessageValueCallbackCToCpp::Invert(callback),
      extention);
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_render_to_background(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnRenderToBackground();
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_render_to_foreground(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnRenderToForeground();
}

void ARK_WEB_CALLBACK ark_web_nweb_precompile_java_script(
    struct _ark_web_nweb_t* self,
    const ArkWebString* url,
    const ArkWebString* script,
    ark_web_cache_options_t** cacheOptions,
    ark_web_message_value_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(script, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(cacheOptions, ARK_WEB_RETURN_VOID);
  // Translate param: cacheOptions; type: refptr_diff_byref
  ArkWebRefPtr<ArkWebCacheOptions> cacheOptionsPtr;
  if (cacheOptions && *cacheOptions) {
    cacheOptionsPtr = ArkWebCacheOptionsCToCpp::Invert(*cacheOptions);
  }
  ArkWebCacheOptions* cacheOptionsOrig = cacheOptionsPtr.get();

  // Execute
  ArkWebNWebCppToC::Get(self)->PrecompileJavaScript(
      *url, *script, cacheOptionsPtr,
      ArkWebMessageValueCallbackCToCpp::Invert(callback));

  // Restore param: cacheOptions; type: refptr_diff_byref
  if (cacheOptions) {
    if (cacheOptionsPtr.get()) {
      if (cacheOptionsPtr.get() != cacheOptionsOrig) {
        *cacheOptions = ArkWebCacheOptionsCToCpp::Revert(cacheOptionsPtr);
      }
    } else {
      *cacheOptions = nullptr;
    }
  }
}

void ARK_WEB_CALLBACK ark_web_nweb_on_create_native_media_player(
    struct _ark_web_nweb_t* self,
    ark_web_create_native_media_player_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnCreateNativeMediaPlayer(
      ArkWebCreateNativeMediaPlayerCallbackCToCpp::Invert(callback));
}

void ARK_WEB_CALLBACK ark_web_nweb_drag_resize(struct _ark_web_nweb_t* self,
                                               uint32_t width,
                                               uint32_t height,
                                               uint32_t pre_height,
                                               uint32_t pre_width) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->DragResize(width, height, pre_height, pre_width);
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_touch_cancel_by_id(struct _ark_web_nweb_t* self,
                                   int32_t id,
                                   double x,
                                   double y,
                                   bool from_overlay) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnTouchCancelById(id, x, y, from_overlay);
}

int ARK_WEB_CALLBACK
ark_web_nweb_scale_gesture_change(struct _ark_web_nweb_t* self,
                                  double scale,
                                  double centerX,
                                  double centerY) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->ScaleGestureChange(scale, centerX,
                                                         centerY);
}

void ARK_WEB_CALLBACK
ark_web_nweb_inject_offline_resource(struct _ark_web_nweb_t* self,
                                     const ArkWebString* url,
                                     const ArkWebString* origin,
                                     const ArkWebUint8Vector* resource,
                                     const ArkWebStringMap* responseHeaders,
                                     const int type) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(origin, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(resource, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(responseHeaders, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->InjectOfflineResource(*url, *origin, *resource,
                                                     *responseHeaders, type);
}

bool ARK_WEB_CALLBACK
ark_web_nweb_terminate_render_process(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->TerminateRenderProcess();
}

void ARK_WEB_CALLBACK
ark_web_nweb_suggestion_selected(struct _ark_web_nweb_t* self, int32_t index) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SuggestionSelected(index);
}

void ARK_WEB_CALLBACK ark_web_nweb_register_ark_jsfunction2(
    struct _ark_web_nweb_t* self,
    const ArkWebString* object_name,
    const ArkWebStringVector* method_list,
    const ArkWebStringVector* async_method_list,
    const int32_t object_id) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(object_name, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(method_list, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(async_method_list, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->RegisterArkJSfunction(
      *object_name, *method_list, *async_method_list, object_id);
}

void ARK_WEB_CALLBACK
ark_web_nweb_send_touchpad_fling_event(struct _ark_web_nweb_t* self,
                                       double x,
                                       double y,
                                       double vx,
                                       double vy) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SendTouchpadFlingEvent(x, y, vx, vy);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_fit_content_mode(struct _ark_web_nweb_t* self, int32_t mode) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetFitContentMode(mode);
}

ArkWebString ARK_WEB_CALLBACK
ark_web_nweb_get_select_info(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetSelectInfo();
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_online_render_to_foreground(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnOnlineRenderToForeground();
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_safe_insets_change(struct _ark_web_nweb_t* self,
                                   int left,
                                   int top,
                                   int right,
                                   int bottom) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnSafeInsetsChange(left, top, right, bottom);
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_text_selected(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnTextSelected();
}

bool ARK_WEB_CALLBACK
ark_web_nweb_web_send_key_event(struct _ark_web_nweb_t* self,
                                int32_t keyCode,
                                int32_t keyAction,
                                const ArkWebInt32Vector* pressedCodes) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);
  ARK_WEB_CPPTOC_CHECK_PARAM(pressedCodes, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->WebSendKeyEvent(keyCode, keyAction,
                                                      *pressedCodes);
}

void ARK_WEB_CALLBACK ark_web_nweb_on_configuration_updated(
    struct _ark_web_nweb_t* self,
    ark_web_system_configuration_t* configuration) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnConfigurationUpdated(
      ArkWebSystemConfigurationCToCpp::Invert(configuration));
}

void ARK_WEB_CALLBACK
ark_web_nweb_enable_ads_block(struct _ark_web_nweb_t* self, bool enable) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->EnableAdsBlock(enable);
}

bool ARK_WEB_CALLBACK
ark_web_nweb_is_ads_block_enabled(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->IsAdsBlockEnabled();
}

bool ARK_WEB_CALLBACK
ark_web_nweb_is_ads_block_enabled_for_cur_page(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->IsAdsBlockEnabledForCurPage();
}

void ARK_WEB_CALLBACK
ark_web_nweb_notify_for_next_touch_event(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->NotifyForNextTouchEvent();
}

int ARK_WEB_CALLBACK
ark_web_nweb_set_url_trust_list(struct _ark_web_nweb_t* self,
                                const ArkWebString* urlTrustList) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(urlTrustList, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->SetUrlTrustList(*urlTrustList);
}

void ARK_WEB_CALLBACK ark_web_nweb_put_spanstring_convert_html_callback(
    struct _ark_web_nweb_t* self,
    ark_web_spanstring_convert_html_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PutSpanstringConvertHtmlCallback(
      ArkWebSpanstringConvertHtmlCallbackCToCpp::Invert(callback));
}

bool ARK_WEB_CALLBACK
ark_web_nweb_web_page_snapshot(struct _ark_web_nweb_t* self,
                               const char* id,
                               int type,
                               int width,
                               int height,
                               const WebSnapshotCallback callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->WebPageSnapshot(id, type, width, height,
                                                      callback);
}

void ARK_WEB_CALLBACK ark_web_nweb_set_path_allowing_universal_access(
    struct _ark_web_nweb_t* self,
    const ArkWebStringVector* dirs,
    const ArkWebStringVector* moduleName,
    ArkWebString* errorPath) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(dirs, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(moduleName, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(errorPath, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetPathAllowingUniversalAccess(
      *dirs, *moduleName, *errorPath);
}

void ARK_WEB_CALLBACK
ark_web_nweb_perform_action(struct _ark_web_nweb_t* self,
                            int64_t accessibilityId,
                            uint32_t action,
                            const ArkWebStringMap* actionArguments) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(actionArguments, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PerformAction(accessibilityId, action,
                                             *actionArguments);
}

void ARK_WEB_CALLBACK
ark_web_nweb_scroll_to_with_anime(struct _ark_web_nweb_t* self,
                                  float x,
                                  float y,
                                  int32_t duration) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->ScrollToWithAnime(x, y, duration);
}

void ARK_WEB_CALLBACK
ark_web_nweb_scroll_by_with_anime(struct _ark_web_nweb_t* self,
                                  float delta_x,
                                  float delta_y,
                                  int32_t duration) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->ScrollByWithAnime(delta_x, delta_y, duration);
}

void ARK_WEB_CALLBACK
ark_web_nweb_web_send_mouse_wheel_event(struct _ark_web_nweb_t* self,
                                        double x,
                                        double y,
                                        double delta_x,
                                        double delta_y,
                                        const ArkWebInt32Vector* pressedCodes) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(pressedCodes, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->WebSendMouseWheelEvent(x, y, delta_x, delta_y,
                                                      *pressedCodes);
}

void ARK_WEB_CALLBACK ark_web_nweb_web_send_touchpad_fling_event(
    struct _ark_web_nweb_t* self,
    double x,
    double y,
    double vx,
    double vy,
    const ArkWebInt32Vector* pressedCodes) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(pressedCodes, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->WebSendTouchpadFlingEvent(x, y, vx, vy,
                                                         *pressedCodes);
}

int ARK_WEB_CALLBACK
ark_web_nweb_set_url_trust_list_with_err_msg(struct _ark_web_nweb_t* self,
                                             const ArkWebString* urlTrustList,
                                             ArkWebString* detailErrMsg) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(urlTrustList, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(detailErrMsg, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->SetUrlTrustListWithErrMsg(*urlTrustList,
                                                                *detailErrMsg);
}

void ARK_WEB_CALLBACK
ark_web_nweb_send_accessibility_hover_event(struct _ark_web_nweb_t* self,
                                            int32_t x,
                                            int32_t y) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SendAccessibilityHoverEvent(x, y);
}

void ARK_WEB_CALLBACK ark_web_nweb_register_ark_jsfunction3(
    struct _ark_web_nweb_t* self,
    const ArkWebString* object_name,
    const ArkWebStringVector* method_list,
    const ArkWebStringVector* async_method_list,
    const int32_t object_id,
    const ArkWebString* permission) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(object_name, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(method_list, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(async_method_list, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(permission, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->RegisterArkJSfunction(
      *object_name, *method_list, *async_method_list, object_id, *permission);
}

void ARK_WEB_CALLBACK
ark_web_nweb_resize_visible_viewport(struct _ark_web_nweb_t* self,
                                     uint32_t width,
                                     uint32_t height,
                                     bool isKeyboard) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->ResizeVisibleViewport(width, height, isKeyboard);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_back_forward_cache_options(struct _ark_web_nweb_t* self,
                                            int32_t size,
                                            int32_t timeToLive) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetBackForwardCacheOptions(size, timeToLive);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_autofill_callback(struct _ark_web_nweb_t* self,
                                   ark_web_message_value_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetAutofillCallback(
      ArkWebMessageValueCallbackCToCpp::Invert(callback));
}

void ARK_WEB_CALLBACK
ark_web_nweb_fill_autofill_data(struct _ark_web_nweb_t* self,
                                const ArkWebMessage* data) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(data, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->FillAutofillData(*data);
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_autofill_cancel(struct _ark_web_nweb_t* self,
                                const ArkWebString* fillContent) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(fillContent, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnAutofillCancel(*fillContent);
}

void ARK_WEB_CALLBACK
ark_web_nweb_get_scroll_offset(struct _ark_web_nweb_t* self,
                               float* offset_x,
                               float* offset_y) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->GetScrollOffset(offset_x, offset_y);
}

void ARK_WEB_CALLBACK ark_web_nweb_execute_create_pdfext(
    struct _ark_web_nweb_t* self,
    ark_web_pdfconfig_args_t* pdfConfig,
    ark_web_array_buffer_value_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->ExecuteCreatePDFExt(
      ArkWebPDFConfigArgsCToCpp::Invert(pdfConfig),
      ArkWebArrayBufferValueCallbackCToCpp::Invert(callback));
}

bool ARK_WEB_CALLBACK
ark_web_nweb_scroll_by_with_result(struct _ark_web_nweb_t* self,
                                   float delta_x,
                                   float delta_y) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->ScrollByWithResult(delta_x, delta_y);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_popup_surface(struct _ark_web_nweb_t* self,
                               void* popupSurface) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetPopupSurface(popupSurface);
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_destroy_image_analyzer_overlay(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnDestroyImageAnalyzerOverlay();
}

void ARK_WEB_CALLBACK
ark_web_nweb_web_send_mouse_event(struct _ark_web_nweb_t* self,
                                  ark_web_mouse_event_t* mouseEvent) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->WebSendMouseEvent(
      ArkWebMouseEventCToCpp::Invert(mouseEvent));
}

bool ARK_WEB_CALLBACK
ark_web_nweb_get_accessibility_visible(struct _ark_web_nweb_t* self,
                                       int64_t accessibility_id) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetAccessibilityVisible(accessibility_id);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_transform_hint(struct _ark_web_nweb_t* self,
                                uint32_t rotation) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetTransformHint(rotation);
}

void ARK_WEB_CALLBACK
ark_web_nweb_web_components_blur(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->WebComponentsBlur();
}

float ARK_WEB_CALLBACK
ark_web_nweb_dump_gpu_info(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->DumpGpuInfo();
}

int ARK_WEB_CALLBACK
ark_web_nweb_scale_gesture_change_v2(struct _ark_web_nweb_t* self,
                                     int type,
                                     double scale,
                                     double originScale,
                                     double centerX,
                                     double centerY) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->ScaleGestureChangeV2(
      type, scale, originScale, centerX, centerY);
}

bool ARK_WEB_CALLBACK
ark_web_nweb_send_keyboard_event(struct _ark_web_nweb_t* self,
                                 ark_web_keyboard_event_t* keyboardEvent) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->SendKeyboardEvent(
      ArkWebKeyboardEventCToCpp::Invert(keyboardEvent));
}

bool ARK_WEB_CALLBACK
ark_web_nweb_perform_action_v2(struct _ark_web_nweb_t* self,
                               int64_t accessibilityId,
                               uint32_t action,
                               const ArkWebStringMap* actionArguments) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);
  ARK_WEB_CPPTOC_CHECK_PARAM(actionArguments, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->PerformActionV2(accessibilityId, action,
                                                      *actionArguments);
}

void ARK_WEB_CALLBACK ark_web_nweb_java_script_on_document_start_by_order(
    struct _ark_web_nweb_t* self,
    const ArkWebStringVectorMap* script_items,
    const ArkWebStringVector* script_items_by_order) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(script_items, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(script_items_by_order, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->JavaScriptOnDocumentStartByOrder(
      *script_items, *script_items_by_order);
}

void ARK_WEB_CALLBACK ark_web_nweb_java_script_on_document_end_by_order(
    struct _ark_web_nweb_t* self,
    const ArkWebStringVectorMap* script_items,
    const ArkWebStringVector* script_items_by_order) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(script_items, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(script_items_by_order, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->JavaScriptOnDocumentEndByOrder(
      *script_items, *script_items_by_order);
}

bool ARK_WEB_CALLBACK
ark_web_nweb_is_active_policy_disable(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->IsActivePolicyDisable();
}

void ARK_WEB_CALLBACK ark_web_nweb_java_script_on_head_ready_by_order(
    struct _ark_web_nweb_t* self,
    const ArkWebStringVectorMap* script_items,
    const ArkWebStringVector* script_items_by_order) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(script_items, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(script_items_by_order, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->JavaScriptOnHeadReadyByOrder(
      *script_items, *script_items_by_order);
}

void ARK_WEB_CALLBACK
ark_web_nweb_put_optimize_parser_budget_enabled(struct _ark_web_nweb_t* self,
                                                bool enable) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PutOptimizeParserBudgetEnabled(enable);
}

bool ARK_WEB_CALLBACK
ark_web_nweb_get_accessibility_node_rect_by_id(struct _ark_web_nweb_t* self,
                                               int64_t accessibilityId,
                                               int32_t* width,
                                               int32_t* height,
                                               int32_t* offsetX,
                                               int32_t* offsetY) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetAccessibilityNodeRectById(
      accessibilityId, width, height, offsetX, offsetY);
}

ark_web_hit_test_result_t* ARK_WEB_CALLBACK
ark_web_nweb_get_last_hit_test_result(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebHitTestResult> _retval =
      ArkWebNWebCppToC::Get(self)->GetLastHitTestResult();

  // Return type: refptr_same
  return ArkWebHitTestResultCppToC::Invert(_retval);
}

ArkWebString ARK_WEB_CALLBACK
ark_web_nweb_get_current_language(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetCurrentLanguage();
}

bool ARK_WEB_CALLBACK ark_web_nweb_web_send_mouse_wheel_event_v2(
    struct _ark_web_nweb_t* self,
    double x,
    double y,
    double delta_x,
    double delta_y,
    const ArkWebInt32Vector* pressedCodes,
    int32_t source) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);
  ARK_WEB_CPPTOC_CHECK_PARAM(pressedCodes, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->WebSendMouseWheelEventV2(
      x, y, delta_x, delta_y, *pressedCodes, source);
}

bool ARK_WEB_CALLBACK ark_web_nweb_is_nweb_ex(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->IsNWebEx();
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_enable_half_frame_rate(struct _ark_web_nweb_t* self,
                                        bool enabled) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetEnableHalfFrameRate(enabled);
}

void ARK_WEB_CALLBACK
ark_web_nweb_maximize_resize(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->MaximizeResize();
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_drag_attach(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnDragAttach();
}

bool ARK_WEB_CALLBACK
ark_web_nweb_set_focus_by_position(struct _ark_web_nweb_t* self,
                                   float x,
                                   float y) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->SetFocusByPosition(x, y);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_surface_density(struct _ark_web_nweb_t* self,
                                 const double* density) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(density, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetSurfaceDensity(*density);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_border_radius_from_web(struct _ark_web_nweb_t* self,
                                        double borderRadiusTopLeft,
                                        double borderRadiusTopRight,
                                        double borderRadiusBottomLeft,
                                        double borderRadiusBottomRight) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetBorderRadiusFromWeb(
      borderRadiusTopLeft, borderRadiusTopRight, borderRadiusBottomLeft,
      borderRadiusBottomRight);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_native_inner_web(struct _ark_web_nweb_t* self,
                                  bool isInnerWeb) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetNativeInnerWeb(isInnerWeb);
}

void ARK_WEB_CALLBACK
ark_web_nweb_send_accessibility_hover_event_v2(struct _ark_web_nweb_t* self,
                                               int32_t x,
                                               int32_t y,
                                               bool isHoverEnter) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SendAccessibilityHoverEventV2(x, y,
                                                             isHoverEnter);
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_browser_foreground(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnBrowserForeground();
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_browser_background(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnBrowserBackground();
}

void ARK_WEB_CALLBACK ark_web_nweb_register_native_java_script_proxy(
    struct _ark_web_nweb_t* self,
    const ArkWebString* objName,
    const ArkWebStringVector* methodName,
    ark_web_js_proxy_method_t* data,
    bool isAsync,
    const ArkWebString* permission) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(objName, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(methodName, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(permission, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->RegisterNativeJavaScriptProxy(
      *objName, *methodName, ArkWebJsProxyMethodCToCpp::Invert(data), isAsync,
      *permission);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_focus_window_id(struct _ark_web_nweb_t* self,
                                 uint32_t focus_window_id) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetFocusWindowId(focus_window_id);
}

void ARK_WEB_CALLBACK
ark_web_nweb_run_data_detector_js(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->RunDataDetectorJS();
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_data_detector_enable(struct _ark_web_nweb_t* self,
                                      bool enable) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetDataDetectorEnable(enable);
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_data_detector_select_text(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnDataDetectorSelectText();
}

void ARK_WEB_CALLBACK
ark_web_nweb_on_data_detector_copy(struct _ark_web_nweb_t* self,
                                   const ArkWebStringVector* recordMix) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(recordMix, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnDataDetectorCopy(*recordMix);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_pip_native_window(struct _ark_web_nweb_t* self,
                                   int delegate_id,
                                   int child_id,
                                   int frame_routing_id,
                                   void* window) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetPipNativeWindow(delegate_id, child_id,
                                                  frame_routing_id, window);
}

void ARK_WEB_CALLBACK ark_web_nweb_send_pip_event(struct _ark_web_nweb_t* self,
                                                  int delegate_id,
                                                  int child_id,
                                                  int frame_routing_id,
                                                  int event) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SendPipEvent(delegate_id, child_id,
                                            frame_routing_id, event);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_blankless_loading_key(struct _ark_web_nweb_t* self,
                                       const ArkWebString* key) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(key, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetBlanklessLoadingKey(*key);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_privacy_status(struct _ark_web_nweb_t* self, bool isPrivate) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetPrivacyStatus(isPrivate);
}

int ARK_WEB_CALLBACK
ark_web_nweb_get_select_start_index(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetSelectStartIndex();
}

int ARK_WEB_CALLBACK
ark_web_nweb_get_select_end_index(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetSelectEndIndex();
}

ArkWebString ARK_WEB_CALLBACK
ark_web_nweb_get_all_text_info(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetAllTextInfo();
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_audio_session_type(struct _ark_web_nweb_t* self,
                                    int32_t audio_session_type) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetAudioSessionType(audio_session_type);
}

int64_t ARK_WEB_CALLBACK
ark_web_nweb_get_web_accessibility_id_by_html_element_id(
    struct _ark_web_nweb_t* self,
    const ArkWebString* htmlElementId) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(htmlElementId, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetWebAccessibilityIdByHtmlElementId(
      *htmlElementId);
}

int32_t ARK_WEB_CALLBACK
ark_web_nweb_get_blankless_info_with_key(struct _ark_web_nweb_t* self,
                                         const ArkWebString* key,
                                         double* similarity,
                                         int32_t* loadingTime) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(key, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetBlanklessInfoWithKey(*key, similarity,
                                                              loadingTime);
}

int32_t ARK_WEB_CALLBACK
ark_web_nweb_set_blankless_loading_with_key(struct _ark_web_nweb_t* self,
                                            const ArkWebString* key,
                                            bool isStart) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);
  ARK_WEB_CPPTOC_CHECK_PARAM(key, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->SetBlanklessLoadingWithKey(*key, isStart);
}

void ARK_WEB_CALLBACK
ark_web_nweb_update_single_handle_visible(struct _ark_web_nweb_t* self,
                                          bool isVisible) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->UpdateSingleHandleVisible(isVisible);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_touch_handle_exist_state(struct _ark_web_nweb_t* self,
                                          bool touchHandleExist) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetTouchHandleExistState(touchHandleExist);
}

void ARK_WEB_CALLBACK
ark_web_nweb_avoid_visible_viewport_bottom(struct _ark_web_nweb_t* self,
                                           int32_t avoidHeight) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->AvoidVisibleViewportBottom(avoidHeight);
}

int32_t ARK_WEB_CALLBACK
ark_web_nweb_get_visible_viewport_avoid_height(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetVisibleViewportAvoidHeight();
}

bool ARK_WEB_CALLBACK
ark_web_nweb_trigger_blankless_for_url(struct _ark_web_nweb_t* self,
                                       const ArkWebString* url) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->TriggerBlanklessForUrl(*url);
}

void ARK_WEB_CALLBACK ark_web_nweb_set_visibility(struct _ark_web_nweb_t* self,
                                                  bool isVisible) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetVisibility(isVisible);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_viewport_scale_state(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetViewportScaleState();
}

void ARK_WEB_CALLBACK ark_web_nweb_get_page_offset(struct _ark_web_nweb_t* self,
                                                   float* offset_x,
                                                   float* offset_y) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->GetPageOffset(offset_x, offset_y);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_error_page_enabled(struct _ark_web_nweb_t* self, bool enable) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetErrorPageEnabled(enable);
}

bool ARK_WEB_CALLBACK
ark_web_nweb_get_error_page_enabled(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetErrorPageEnabled();
}

int32_t ARK_WEB_CALLBACK
ark_web_nweb_get_web_destroy_mode(struct _ark_web_nweb_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNWebCppToC::Get(self)->GetWebDestroyMode();
}

void ARK_WEB_CALLBACK
ark_web_nweb_call_h5function_v2(struct _ark_web_nweb_t* self,
                                int32_t routing_id,
                                int32_t h5_object_id,
                                const ArkWebString* h5_method_name,
                                const ArkWebRomValueVector* args) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(h5_method_name, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(args, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->CallH5FunctionV2(routing_id, h5_object_id,
                                                *h5_method_name, *args);
}

void ARK_WEB_CALLBACK
ark_web_nweb_post_port_message_v2(struct _ark_web_nweb_t* self,
                                  const ArkWebString* portHandle,
                                  ark_web_rom_value_t* data) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(portHandle, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PostPortMessageV2(
      *portHandle, ArkWebRomValueCToCpp::Invert(data));
}

void ARK_WEB_CALLBACK
ark_web_nweb_fill_autofill_data_v2(struct _ark_web_nweb_t* self,
                                   ark_web_rom_value_t* data) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->FillAutofillDataV2(
      ArkWebRomValueCToCpp::Invert(data));
}

ark_web_print_document_adapter_adapter_t* ARK_WEB_CALLBACK
ark_web_nweb_create_web_print_document_adapter_v2(
    struct _ark_web_nweb_t* self,
    const ArkWebString* job_name) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);
  ARK_WEB_CPPTOC_CHECK_PARAM(job_name, NULL);

  // Execute
  ArkWebRefPtr<ArkWebPrintDocumentAdapterAdapter> _retval =
      ArkWebNWebCppToC::Get(self)->CreateWebPrintDocumentAdapterV2(*job_name);

  // Return type: refptr_same
  return ArkWebPrintDocumentAdapterAdapterCppToC::Invert(_retval);
}

void ARK_WEB_CALLBACK ark_web_nweb_on_stylus_touch_press(
    struct _ark_web_nweb_t* self,
    ark_web_stylus_touch_point_info_t* stylus_touch_point_info,
    bool from_overlay) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnStylusTouchPress(
      ArkWebStylusTouchPointInfoCToCpp::Invert(stylus_touch_point_info),
      from_overlay);
}

void ARK_WEB_CALLBACK ark_web_nweb_on_stylus_touch_release(
    struct _ark_web_nweb_t* self,
    ark_web_stylus_touch_point_info_t* stylus_touch_point_info,
    bool from_overlay) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnStylusTouchRelease(
      ArkWebStylusTouchPointInfoCToCpp::Invert(stylus_touch_point_info),
      from_overlay);
}

void ARK_WEB_CALLBACK ark_web_nweb_on_stylus_touch_move(
    struct _ark_web_nweb_t* self,
    const ArkWebStylusTouchPointInfoVector* stylus_touch_point_infos,
    bool from_overlay) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(stylus_touch_point_infos, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->OnStylusTouchMove(*stylus_touch_point_infos,
                                                 from_overlay);
}

void ARK_WEB_CALLBACK
ark_web_nweb_record_blankless_frame_size(struct _ark_web_nweb_t* self,
                                         uint32_t width,
                                         uint32_t height) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->RecordBlanklessFrameSize(width, height);
}

void ARK_WEB_CALLBACK
ark_web_nweb_prefetch_page_v2(struct _ark_web_nweb_t* self,
                              const ArkWebString* url,
                              const ArkWebStringMap* additional_http_headers,
                              int32_t minTimeBetweenPrefetchesMs,
                              bool ignoreCacheControlNoStore) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(additional_http_headers, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->PrefetchPageV2(*url, *additional_http_headers,
                                              minTimeBetweenPrefetchesMs,
                                              ignoreCacheControlNoStore);
}

void ARK_WEB_CALLBACK
ark_web_nweb_set_force_enable_zoom(struct _ark_web_nweb_t* self,
                                   bool forceEnableZoom) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebNWebCppToC::Get(self)->SetForceEnableZoom(forceEnableZoom);
}

}  // namespace

ArkWebNWebCppToC::ArkWebNWebCppToC() {
  GetStruct()->resize = ark_web_nweb_resize;
  GetStruct()->on_pause = ark_web_nweb_on_pause;
  GetStruct()->on_continue = ark_web_nweb_on_continue;
  GetStruct()->on_destroy = ark_web_nweb_on_destroy;
  GetStruct()->on_focus = ark_web_nweb_on_focus;
  GetStruct()->on_blur = ark_web_nweb_on_blur;
  GetStruct()->on_touch_press = ark_web_nweb_on_touch_press;
  GetStruct()->on_touch_release = ark_web_nweb_on_touch_release;
  GetStruct()->on_touch_move1 = ark_web_nweb_on_touch_move1;
  GetStruct()->on_touch_move2 = ark_web_nweb_on_touch_move2;
  GetStruct()->on_touch_cancel = ark_web_nweb_on_touch_cancel;
  GetStruct()->on_navigate_back = ark_web_nweb_on_navigate_back;
  GetStruct()->send_key_event = ark_web_nweb_send_key_event;
  GetStruct()->send_mouse_wheel_event = ark_web_nweb_send_mouse_wheel_event;
  GetStruct()->send_mouse_event = ark_web_nweb_send_mouse_event;
  GetStruct()->load1 = ark_web_nweb_load1;
  GetStruct()->is_navigatebackward_allowed =
      ark_web_nweb_is_navigatebackward_allowed;
  GetStruct()->is_navigate_forward_allowed =
      ark_web_nweb_is_navigate_forward_allowed;
  GetStruct()->can_navigate_back_or_forward =
      ark_web_nweb_can_navigate_back_or_forward;
  GetStruct()->navigate_back = ark_web_nweb_navigate_back;
  GetStruct()->navigate_forward = ark_web_nweb_navigate_forward;
  GetStruct()->navigate_back_or_forward = ark_web_nweb_navigate_back_or_forward;
  GetStruct()->delete_navigate_history = ark_web_nweb_delete_navigate_history;
  GetStruct()->reload = ark_web_nweb_reload;
  GetStruct()->zoom = ark_web_nweb_zoom;
  GetStruct()->zoom_in = ark_web_nweb_zoom_in;
  GetStruct()->zoom_out = ark_web_nweb_zoom_out;
  GetStruct()->stop = ark_web_nweb_stop;
  GetStruct()->execute_java_script1 = ark_web_nweb_execute_java_script1;
  GetStruct()->execute_java_script2 = ark_web_nweb_execute_java_script2;
  GetStruct()->get_preference = ark_web_nweb_get_preference;
  GetStruct()->get_web_id = ark_web_nweb_get_web_id;
  GetStruct()->get_hit_test_result = ark_web_nweb_get_hit_test_result;
  GetStruct()->put_background_color = ark_web_nweb_put_background_color;
  GetStruct()->initial_scale = ark_web_nweb_initial_scale;
  GetStruct()->put_download_callback = ark_web_nweb_put_download_callback;
  GetStruct()->put_accessibility_event_callback =
      ark_web_nweb_put_accessibility_event_callback;
  GetStruct()->put_accessibility_id_generator =
      ark_web_nweb_put_accessibility_id_generator;
  GetStruct()->set_nweb_handler = ark_web_nweb_set_nweb_handler;
  GetStruct()->title = ark_web_nweb_title;
  GetStruct()->page_load_progress = ark_web_nweb_page_load_progress;
  GetStruct()->content_height = ark_web_nweb_content_height;
  GetStruct()->scale = ark_web_nweb_scale;
  GetStruct()->load2 = ark_web_nweb_load2;
  GetStruct()->load_with_data_and_base_url =
      ark_web_nweb_load_with_data_and_base_url;
  GetStruct()->load_with_data = ark_web_nweb_load_with_data;
  GetStruct()->register_ark_jsfunction1 = ark_web_nweb_register_ark_jsfunction1;
  GetStruct()->unregister_ark_jsfunction =
      ark_web_nweb_unregister_ark_jsfunction;
  GetStruct()->set_nweb_java_script_result_call_back =
      ark_web_nweb_set_nweb_java_script_result_call_back;
  GetStruct()->put_find_callback = ark_web_nweb_put_find_callback;
  GetStruct()->find_all_async = ark_web_nweb_find_all_async;
  GetStruct()->clear_matches = ark_web_nweb_clear_matches;
  GetStruct()->find_next = ark_web_nweb_find_next;
  GetStruct()->store_web_archive = ark_web_nweb_store_web_archive;
  GetStruct()->create_web_message_ports = ark_web_nweb_create_web_message_ports;
  GetStruct()->post_web_message = ark_web_nweb_post_web_message;
  GetStruct()->close_port = ark_web_nweb_close_port;
  GetStruct()->post_port_message = ark_web_nweb_post_port_message;
  GetStruct()->set_port_message_callback =
      ark_web_nweb_set_port_message_callback;
  GetStruct()->send_drag_event = ark_web_nweb_send_drag_event;
  GetStruct()->clear_ssl_cache = ark_web_nweb_clear_ssl_cache;
  GetStruct()->get_url = ark_web_nweb_get_url;
  GetStruct()->clear_client_authentication_cache =
      ark_web_nweb_clear_client_authentication_cache;
  GetStruct()->update_locale = ark_web_nweb_update_locale;
  GetStruct()->get_original_url = ark_web_nweb_get_original_url;
  GetStruct()->get_favicon = ark_web_nweb_get_favicon;
  GetStruct()->put_network_available = ark_web_nweb_put_network_available;
  GetStruct()->has_images = ark_web_nweb_has_images;
  GetStruct()->remove_cache = ark_web_nweb_remove_cache;
  GetStruct()->get_history_list = ark_web_nweb_get_history_list;
  GetStruct()->put_release_surface_callback =
      ark_web_nweb_put_release_surface_callback;
  GetStruct()->serialize_web_state = ark_web_nweb_serialize_web_state;
  GetStruct()->restore_web_state = ark_web_nweb_restore_web_state;
  GetStruct()->page_up = ark_web_nweb_page_up;
  GetStruct()->page_down = ark_web_nweb_page_down;
  GetStruct()->scroll_to = ark_web_nweb_scroll_to;
  GetStruct()->scroll_by = ark_web_nweb_scroll_by;
  GetStruct()->slide_scroll = ark_web_nweb_slide_scroll;
  GetStruct()->get_cert_chain_der_data = ark_web_nweb_get_cert_chain_der_data;
  GetStruct()->set_screen_off_set = ark_web_nweb_set_screen_off_set;
  GetStruct()->set_audio_muted = ark_web_nweb_set_audio_muted;
  GetStruct()->set_should_frame_submission_before_draw =
      ark_web_nweb_set_should_frame_submission_before_draw;
  GetStruct()->notify_popup_window_result =
      ark_web_nweb_notify_popup_window_result;
  GetStruct()->set_audio_resume_interval =
      ark_web_nweb_set_audio_resume_interval;
  GetStruct()->set_audio_exclusive = ark_web_nweb_set_audio_exclusive;
  GetStruct()->register_screen_lock_function =
      ark_web_nweb_register_screen_lock_function;
  GetStruct()->un_register_screen_lock_function =
      ark_web_nweb_un_register_screen_lock_function;
  GetStruct()->notify_memory_level = ark_web_nweb_notify_memory_level;
  GetStruct()->on_webview_hide = ark_web_nweb_on_webview_hide;
  GetStruct()->on_webview_show = ark_web_nweb_on_webview_show;
  GetStruct()->get_or_create_drag_data = ark_web_nweb_get_or_create_drag_data;
  GetStruct()->prefetch_page = ark_web_nweb_prefetch_page;
  GetStruct()->set_window_id = ark_web_nweb_set_window_id;
  GetStruct()->on_occluded = ark_web_nweb_on_occluded;
  GetStruct()->on_unoccluded = ark_web_nweb_on_unoccluded;
  GetStruct()->set_token = ark_web_nweb_set_token;
  GetStruct()->set_nested_scroll_mode = ark_web_nweb_set_nested_scroll_mode;
  GetStruct()->set_enable_lower_frame_rate =
      ark_web_nweb_set_enable_lower_frame_rate;
  GetStruct()->set_virtual_key_board_arg =
      ark_web_nweb_set_virtual_key_board_arg;
  GetStruct()->should_virtual_keyboard_overlay =
      ark_web_nweb_should_virtual_keyboard_overlay;
  GetStruct()->set_draw_rect = ark_web_nweb_set_draw_rect;
  GetStruct()->set_draw_mode = ark_web_nweb_set_draw_mode;
  GetStruct()->create_web_print_document_adapter =
      ark_web_nweb_create_web_print_document_adapter;
  GetStruct()->post_url = ark_web_nweb_post_url;
  GetStruct()->java_script_on_document_start =
      ark_web_nweb_java_script_on_document_start;
  GetStruct()->execute_action = ark_web_nweb_execute_action;
  GetStruct()->get_focused_accessibility_node_info =
      ark_web_nweb_get_focused_accessibility_node_info;
  GetStruct()->get_accessibility_node_info_by_id =
      ark_web_nweb_get_accessibility_node_info_by_id;
  GetStruct()->get_accessibility_node_info_by_focus_move =
      ark_web_nweb_get_accessibility_node_info_by_focus_move;
  GetStruct()->set_accessibility_state = ark_web_nweb_set_accessibility_state;
  GetStruct()->need_soft_keyboard = ark_web_nweb_need_soft_keyboard;
  GetStruct()->discard = ark_web_nweb_discard;
  GetStruct()->restore = ark_web_nweb_restore;
  GetStruct()->get_security_level = ark_web_nweb_get_security_level;
  GetStruct()->call_h5function = ark_web_nweb_call_h5function;
  GetStruct()->is_incognito_mode = ark_web_nweb_is_incognito_mode;
  GetStruct()->register_native_ark_jsfunction =
      ark_web_nweb_register_native_ark_jsfunction;
  GetStruct()->un_register_native_ark_jsfunction =
      ark_web_nweb_un_register_native_ark_jsfunction;
  GetStruct()->register_native_valide_callback =
      ark_web_nweb_register_native_valide_callback;
  GetStruct()->register_native_destroy_callback =
      ark_web_nweb_register_native_destroy_callback;
  GetStruct()->java_script_on_document_end =
      ark_web_nweb_java_script_on_document_end;
  GetStruct()->enable_safe_browsing = ark_web_nweb_enable_safe_browsing;
  GetStruct()->is_safe_browsing_enabled = ark_web_nweb_is_safe_browsing_enabled;
  GetStruct()->set_print_background = ark_web_nweb_set_print_background;
  GetStruct()->get_print_background = ark_web_nweb_get_print_background;
  GetStruct()->close_all_media_presentations =
      ark_web_nweb_close_all_media_presentations;
  GetStruct()->stop_all_media = ark_web_nweb_stop_all_media;
  GetStruct()->resume_all_media = ark_web_nweb_resume_all_media;
  GetStruct()->pause_all_media = ark_web_nweb_pause_all_media;
  GetStruct()->get_media_playback_state = ark_web_nweb_get_media_playback_state;
  GetStruct()->enable_intelligent_tracking_prevention =
      ark_web_nweb_enable_intelligent_tracking_prevention;
  GetStruct()->is_intelligent_tracking_prevention_enabled =
      ark_web_nweb_is_intelligent_tracking_prevention_enabled;
  GetStruct()->start_camera = ark_web_nweb_start_camera;
  GetStruct()->stop_camera = ark_web_nweb_stop_camera;
  GetStruct()->close_camera = ark_web_nweb_close_camera;
  GetStruct()->get_last_javascript_proxy_calling_frame_url =
      ark_web_nweb_get_last_javascript_proxy_calling_frame_url;
  GetStruct()->get_pending_size_status = ark_web_nweb_get_pending_size_status;
  GetStruct()->scroll_by_ref_screen = ark_web_nweb_scroll_by_ref_screen;
  GetStruct()->execute_java_script_ext = ark_web_nweb_execute_java_script_ext;
  GetStruct()->on_render_to_background = ark_web_nweb_on_render_to_background;
  GetStruct()->on_render_to_foreground = ark_web_nweb_on_render_to_foreground;
  GetStruct()->precompile_java_script = ark_web_nweb_precompile_java_script;
  GetStruct()->on_create_native_media_player =
      ark_web_nweb_on_create_native_media_player;
  GetStruct()->drag_resize = ark_web_nweb_drag_resize;
  GetStruct()->on_touch_cancel_by_id = ark_web_nweb_on_touch_cancel_by_id;
  GetStruct()->scale_gesture_change = ark_web_nweb_scale_gesture_change;
  GetStruct()->inject_offline_resource = ark_web_nweb_inject_offline_resource;
  GetStruct()->terminate_render_process = ark_web_nweb_terminate_render_process;
  GetStruct()->suggestion_selected = ark_web_nweb_suggestion_selected;
  GetStruct()->register_ark_jsfunction2 = ark_web_nweb_register_ark_jsfunction2;
  GetStruct()->send_touchpad_fling_event =
      ark_web_nweb_send_touchpad_fling_event;
  GetStruct()->set_fit_content_mode = ark_web_nweb_set_fit_content_mode;
  GetStruct()->get_select_info = ark_web_nweb_get_select_info;
  GetStruct()->on_online_render_to_foreground =
      ark_web_nweb_on_online_render_to_foreground;
  GetStruct()->on_safe_insets_change = ark_web_nweb_on_safe_insets_change;
  GetStruct()->on_text_selected = ark_web_nweb_on_text_selected;
  GetStruct()->web_send_key_event = ark_web_nweb_web_send_key_event;
  GetStruct()->on_configuration_updated = ark_web_nweb_on_configuration_updated;
  GetStruct()->enable_ads_block = ark_web_nweb_enable_ads_block;
  GetStruct()->is_ads_block_enabled = ark_web_nweb_is_ads_block_enabled;
  GetStruct()->is_ads_block_enabled_for_cur_page =
      ark_web_nweb_is_ads_block_enabled_for_cur_page;
  GetStruct()->notify_for_next_touch_event =
      ark_web_nweb_notify_for_next_touch_event;
  GetStruct()->set_url_trust_list = ark_web_nweb_set_url_trust_list;
  GetStruct()->put_spanstring_convert_html_callback =
      ark_web_nweb_put_spanstring_convert_html_callback;
  GetStruct()->web_page_snapshot = ark_web_nweb_web_page_snapshot;
  GetStruct()->set_path_allowing_universal_access =
      ark_web_nweb_set_path_allowing_universal_access;
  GetStruct()->perform_action = ark_web_nweb_perform_action;
  GetStruct()->scroll_to_with_anime = ark_web_nweb_scroll_to_with_anime;
  GetStruct()->scroll_by_with_anime = ark_web_nweb_scroll_by_with_anime;
  GetStruct()->web_send_mouse_wheel_event =
      ark_web_nweb_web_send_mouse_wheel_event;
  GetStruct()->web_send_touchpad_fling_event =
      ark_web_nweb_web_send_touchpad_fling_event;
  GetStruct()->set_url_trust_list_with_err_msg =
      ark_web_nweb_set_url_trust_list_with_err_msg;
  GetStruct()->send_accessibility_hover_event =
      ark_web_nweb_send_accessibility_hover_event;
  GetStruct()->register_ark_jsfunction3 = ark_web_nweb_register_ark_jsfunction3;
  GetStruct()->resize_visible_viewport = ark_web_nweb_resize_visible_viewport;
  GetStruct()->set_back_forward_cache_options =
      ark_web_nweb_set_back_forward_cache_options;
  GetStruct()->set_autofill_callback = ark_web_nweb_set_autofill_callback;
  GetStruct()->fill_autofill_data = ark_web_nweb_fill_autofill_data;
  GetStruct()->on_autofill_cancel = ark_web_nweb_on_autofill_cancel;
  GetStruct()->get_scroll_offset = ark_web_nweb_get_scroll_offset;
  GetStruct()->execute_create_pdfext = ark_web_nweb_execute_create_pdfext;
  GetStruct()->scroll_by_with_result = ark_web_nweb_scroll_by_with_result;
  GetStruct()->set_popup_surface = ark_web_nweb_set_popup_surface;
  GetStruct()->on_destroy_image_analyzer_overlay =
      ark_web_nweb_on_destroy_image_analyzer_overlay;
  GetStruct()->web_send_mouse_event = ark_web_nweb_web_send_mouse_event;
  GetStruct()->get_accessibility_visible =
      ark_web_nweb_get_accessibility_visible;
  GetStruct()->set_transform_hint = ark_web_nweb_set_transform_hint;
  GetStruct()->web_components_blur = ark_web_nweb_web_components_blur;
  GetStruct()->dump_gpu_info = ark_web_nweb_dump_gpu_info;
  GetStruct()->scale_gesture_change_v2 = ark_web_nweb_scale_gesture_change_v2;
  GetStruct()->send_keyboard_event = ark_web_nweb_send_keyboard_event;
  GetStruct()->perform_action_v2 = ark_web_nweb_perform_action_v2;
  GetStruct()->java_script_on_document_start_by_order =
      ark_web_nweb_java_script_on_document_start_by_order;
  GetStruct()->java_script_on_document_end_by_order =
      ark_web_nweb_java_script_on_document_end_by_order;
  GetStruct()->is_active_policy_disable = ark_web_nweb_is_active_policy_disable;
  GetStruct()->java_script_on_head_ready_by_order =
      ark_web_nweb_java_script_on_head_ready_by_order;
  GetStruct()->put_optimize_parser_budget_enabled =
      ark_web_nweb_put_optimize_parser_budget_enabled;
  GetStruct()->get_accessibility_node_rect_by_id =
      ark_web_nweb_get_accessibility_node_rect_by_id;
  GetStruct()->get_last_hit_test_result = ark_web_nweb_get_last_hit_test_result;
  GetStruct()->get_current_language = ark_web_nweb_get_current_language;
  GetStruct()->web_send_mouse_wheel_event_v2 =
      ark_web_nweb_web_send_mouse_wheel_event_v2;
  GetStruct()->is_nweb_ex = ark_web_nweb_is_nweb_ex;
  GetStruct()->set_enable_half_frame_rate =
      ark_web_nweb_set_enable_half_frame_rate;
  GetStruct()->maximize_resize = ark_web_nweb_maximize_resize;
  GetStruct()->on_drag_attach = ark_web_nweb_on_drag_attach;
  GetStruct()->set_focus_by_position = ark_web_nweb_set_focus_by_position;
  GetStruct()->set_surface_density = ark_web_nweb_set_surface_density;
  GetStruct()->set_border_radius_from_web =
      ark_web_nweb_set_border_radius_from_web;
  GetStruct()->set_native_inner_web = ark_web_nweb_set_native_inner_web;
  GetStruct()->send_accessibility_hover_event_v2 =
      ark_web_nweb_send_accessibility_hover_event_v2;
  GetStruct()->on_browser_foreground = ark_web_nweb_on_browser_foreground;
  GetStruct()->on_browser_background = ark_web_nweb_on_browser_background;
  GetStruct()->register_native_java_script_proxy =
      ark_web_nweb_register_native_java_script_proxy;
  GetStruct()->set_focus_window_id = ark_web_nweb_set_focus_window_id;
  GetStruct()->run_data_detector_js = ark_web_nweb_run_data_detector_js;
  GetStruct()->set_data_detector_enable = ark_web_nweb_set_data_detector_enable;
  GetStruct()->on_data_detector_select_text =
      ark_web_nweb_on_data_detector_select_text;
  GetStruct()->on_data_detector_copy = ark_web_nweb_on_data_detector_copy;
  GetStruct()->set_pip_native_window = ark_web_nweb_set_pip_native_window;
  GetStruct()->send_pip_event = ark_web_nweb_send_pip_event;
  GetStruct()->set_blankless_loading_key =
      ark_web_nweb_set_blankless_loading_key;
  GetStruct()->set_privacy_status = ark_web_nweb_set_privacy_status;
  GetStruct()->get_select_start_index = ark_web_nweb_get_select_start_index;
  GetStruct()->get_select_end_index = ark_web_nweb_get_select_end_index;
  GetStruct()->get_all_text_info = ark_web_nweb_get_all_text_info;
  GetStruct()->set_audio_session_type = ark_web_nweb_set_audio_session_type;
  GetStruct()->get_web_accessibility_id_by_html_element_id =
      ark_web_nweb_get_web_accessibility_id_by_html_element_id;
  GetStruct()->get_blankless_info_with_key =
      ark_web_nweb_get_blankless_info_with_key;
  GetStruct()->set_blankless_loading_with_key =
      ark_web_nweb_set_blankless_loading_with_key;
  GetStruct()->update_single_handle_visible =
      ark_web_nweb_update_single_handle_visible;
  GetStruct()->set_touch_handle_exist_state =
      ark_web_nweb_set_touch_handle_exist_state;
  GetStruct()->avoid_visible_viewport_bottom =
      ark_web_nweb_avoid_visible_viewport_bottom;
  GetStruct()->get_visible_viewport_avoid_height =
      ark_web_nweb_get_visible_viewport_avoid_height;
  GetStruct()->trigger_blankless_for_url =
      ark_web_nweb_trigger_blankless_for_url;
  GetStruct()->set_visibility = ark_web_nweb_set_visibility;
  GetStruct()->set_viewport_scale_state = ark_web_nweb_set_viewport_scale_state;
  GetStruct()->get_page_offset = ark_web_nweb_get_page_offset;
  GetStruct()->set_error_page_enabled = ark_web_nweb_set_error_page_enabled;
  GetStruct()->get_error_page_enabled = ark_web_nweb_get_error_page_enabled;
  GetStruct()->get_web_destroy_mode = ark_web_nweb_get_web_destroy_mode;
  GetStruct()->call_h5function_v2 = ark_web_nweb_call_h5function_v2;
  GetStruct()->post_port_message_v2 = ark_web_nweb_post_port_message_v2;
  GetStruct()->fill_autofill_data_v2 = ark_web_nweb_fill_autofill_data_v2;
  GetStruct()->create_web_print_document_adapter_v2 =
      ark_web_nweb_create_web_print_document_adapter_v2;
  GetStruct()->on_stylus_touch_press = ark_web_nweb_on_stylus_touch_press;
  GetStruct()->on_stylus_touch_release = ark_web_nweb_on_stylus_touch_release;
  GetStruct()->on_stylus_touch_move = ark_web_nweb_on_stylus_touch_move;
  GetStruct()->record_blankless_frame_size =
      ark_web_nweb_record_blankless_frame_size;
  GetStruct()->prefetch_page_v2 = ark_web_nweb_prefetch_page_v2;
  GetStruct()->set_force_enable_zoom = ark_web_nweb_set_force_enable_zoom;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["qhmoBJk_wRX7_kQGQh376A"] =
        reinterpret_cast<void*>(ark_web_nweb_resize);
    funcMemberMap["P1tztPgrOrNY_hUEBJcdhg"] =
        reinterpret_cast<void*>(ark_web_nweb_on_pause);
    funcMemberMap["zhg5QpT7GGrWokma$LGDNQ"] =
        reinterpret_cast<void*>(ark_web_nweb_on_continue);
    funcMemberMap["drSFTopGBdmFjWJUAMO1FQ"] =
        reinterpret_cast<void*>(ark_web_nweb_on_destroy);
    funcMemberMap["NwI8p$afPwcbCnIZMy37gA"] =
        reinterpret_cast<void*>(ark_web_nweb_on_focus);
    funcMemberMap["2v6EqhkjwM60Q2VlS5hmNg"] =
        reinterpret_cast<void*>(ark_web_nweb_on_blur);
    funcMemberMap["ol9FGk_K2DpS9nBKK0uoVg"] =
        reinterpret_cast<void*>(ark_web_nweb_on_touch_press);
    funcMemberMap["Iihdaz5qlDSqmoYrLufDAQ"] =
        reinterpret_cast<void*>(ark_web_nweb_on_touch_release);
    funcMemberMap["PbHkZ$O6pRs3crq$fxhZeg"] =
        reinterpret_cast<void*>(ark_web_nweb_on_touch_move1);
    funcMemberMap["MuTLs6nGyKzwnTWza17Sag"] =
        reinterpret_cast<void*>(ark_web_nweb_on_touch_move2);
    funcMemberMap["J$04n4F$QWHtyLJsBy8vlQ"] =
        reinterpret_cast<void*>(ark_web_nweb_on_touch_cancel);
    funcMemberMap["iDM0$viWfz7C9SWZ2ETRXQ"] =
        reinterpret_cast<void*>(ark_web_nweb_on_navigate_back);
    funcMemberMap["pCM8RaDSwB$4w7Wt02fnXQ"] =
        reinterpret_cast<void*>(ark_web_nweb_send_key_event);
    funcMemberMap["T7Z2kDo1haFw6TCSYp0f5w"] =
        reinterpret_cast<void*>(ark_web_nweb_send_mouse_wheel_event);
    funcMemberMap["Qc845yXvWp07kgkrX7BBVA"] =
        reinterpret_cast<void*>(ark_web_nweb_send_mouse_event);
    funcMemberMap["owJVVt8u$gTgGLaoXiZZhQ"] =
        reinterpret_cast<void*>(ark_web_nweb_load1);
    funcMemberMap["LhoNVvJZAD_zqUA2kiK8$A"] =
        reinterpret_cast<void*>(ark_web_nweb_is_navigatebackward_allowed);
    funcMemberMap["Pp1QC5qLWdzpHcEJ62Hp4Q"] =
        reinterpret_cast<void*>(ark_web_nweb_is_navigate_forward_allowed);
    funcMemberMap["U_qENE$pvIAP1wgekAFozQ"] =
        reinterpret_cast<void*>(ark_web_nweb_can_navigate_back_or_forward);
    funcMemberMap["jT66n8tOlfgZRIWJD8uEXA"] =
        reinterpret_cast<void*>(ark_web_nweb_navigate_back);
    funcMemberMap["aVMIBMZ8pTjseaRVd7nP0A"] =
        reinterpret_cast<void*>(ark_web_nweb_navigate_forward);
    funcMemberMap["Cy6lST7BB0TfD1G7ztuPlg"] =
        reinterpret_cast<void*>(ark_web_nweb_navigate_back_or_forward);
    funcMemberMap["jnGOgwPEAUNZWdqk7V8VjA"] =
        reinterpret_cast<void*>(ark_web_nweb_delete_navigate_history);
    funcMemberMap["dhnQDdCQd_z6qRVbFpKQSQ"] =
        reinterpret_cast<void*>(ark_web_nweb_reload);
    funcMemberMap["eoBM9vnxFw7mtrC6TkgMIw"] =
        reinterpret_cast<void*>(ark_web_nweb_zoom);
    funcMemberMap["G2WlBsGgQN3Ko989A5Ffew"] =
        reinterpret_cast<void*>(ark_web_nweb_zoom_in);
    funcMemberMap["WsvJu8y24YSJ1nWGA1YShg"] =
        reinterpret_cast<void*>(ark_web_nweb_zoom_out);
    funcMemberMap["fI4H3Irg_J9d3Axe9tyBRw"] =
        reinterpret_cast<void*>(ark_web_nweb_stop);
    funcMemberMap["FlZSiTK_CQ$r6UGl9kIZ5w"] =
        reinterpret_cast<void*>(ark_web_nweb_execute_java_script1);
    funcMemberMap["NYPYGBtiJRZFteIXPwyIIg"] =
        reinterpret_cast<void*>(ark_web_nweb_execute_java_script2);
    funcMemberMap["QbD7eDoEFxQNVGjzkAnU1Q"] =
        reinterpret_cast<void*>(ark_web_nweb_get_preference);
    funcMemberMap["5l3QKryQarykJTWf3ieFew"] =
        reinterpret_cast<void*>(ark_web_nweb_get_web_id);
    funcMemberMap["1AOnmvLA57BxHx4lIJvhEA"] =
        reinterpret_cast<void*>(ark_web_nweb_get_hit_test_result);
    funcMemberMap["IvNclv_h6uAznUQWIUNS1A"] =
        reinterpret_cast<void*>(ark_web_nweb_put_background_color);
    funcMemberMap["vz2OPrvVU5rfTjWJ4mWWhQ"] =
        reinterpret_cast<void*>(ark_web_nweb_initial_scale);
    funcMemberMap["NhxfCgRDd3TvwUqt1TIxnA"] =
        reinterpret_cast<void*>(ark_web_nweb_put_download_callback);
    funcMemberMap["hl_EhWdUsZU5a61htwTMkQ"] =
        reinterpret_cast<void*>(ark_web_nweb_put_accessibility_event_callback);
    funcMemberMap["0ZRvPXqHIT6HbI$A6fCDqg"] =
        reinterpret_cast<void*>(ark_web_nweb_put_accessibility_id_generator);
    funcMemberMap["l5ZpvXCeHFPMF6w6sTEo4A"] =
        reinterpret_cast<void*>(ark_web_nweb_set_nweb_handler);
    funcMemberMap["YaAIbgOHQLSw9hGFgZ0_hQ"] =
        reinterpret_cast<void*>(ark_web_nweb_title);
    funcMemberMap["AlAnjCWKV0lwSqs04v7roQ"] =
        reinterpret_cast<void*>(ark_web_nweb_page_load_progress);
    funcMemberMap["9Fh7GJWlkbrdIwf$FykY0g"] =
        reinterpret_cast<void*>(ark_web_nweb_content_height);
    funcMemberMap["dexLWmUid7YD_47oiMx_Dw"] =
        reinterpret_cast<void*>(ark_web_nweb_scale);
    funcMemberMap["emacuN$HbDEAxjpag1q3zg"] =
        reinterpret_cast<void*>(ark_web_nweb_load2);
    funcMemberMap["CpfdC6a4K6i8y7KMvw7zUw"] =
        reinterpret_cast<void*>(ark_web_nweb_load_with_data_and_base_url);
    funcMemberMap["Simh9rKzYyyajm_ZHkqHfA"] =
        reinterpret_cast<void*>(ark_web_nweb_load_with_data);
    funcMemberMap["pt7Kq2GxVxQdlW7FPfDfwQ"] =
        reinterpret_cast<void*>(ark_web_nweb_register_ark_jsfunction1);
    funcMemberMap["3pI5ZKFF3u2TjFA_eecC2w"] =
        reinterpret_cast<void*>(ark_web_nweb_unregister_ark_jsfunction);
    funcMemberMap["kKqQZLtSCmbMuN4aEdmB4w"] = reinterpret_cast<void*>(
        ark_web_nweb_set_nweb_java_script_result_call_back);
    funcMemberMap["OFqxegIIKQcr852EWzx72Q"] =
        reinterpret_cast<void*>(ark_web_nweb_put_find_callback);
    funcMemberMap["w0Olmp7p$y$_lymRuWECIQ"] =
        reinterpret_cast<void*>(ark_web_nweb_find_all_async);
    funcMemberMap["BdEb5hz4DIi1y31VpZFDyg"] =
        reinterpret_cast<void*>(ark_web_nweb_clear_matches);
    funcMemberMap["BXTMjLRZicERivh85WQMVg"] =
        reinterpret_cast<void*>(ark_web_nweb_find_next);
    funcMemberMap["OTacRYBreNKEX4ruhgliqw"] =
        reinterpret_cast<void*>(ark_web_nweb_store_web_archive);
    funcMemberMap["j_w87YqknbOBj77PCqJ1Ow"] =
        reinterpret_cast<void*>(ark_web_nweb_create_web_message_ports);
    funcMemberMap["LkRPHz0e8hKyFl0bCl7PXQ"] =
        reinterpret_cast<void*>(ark_web_nweb_post_web_message);
    funcMemberMap["9U1Ag6Ali9u7Zef$TXrN9w"] =
        reinterpret_cast<void*>(ark_web_nweb_close_port);
    funcMemberMap["WcRCQkKugPmgBYUyp8k8gQ"] =
        reinterpret_cast<void*>(ark_web_nweb_post_port_message);
    funcMemberMap["DgJ4iTnfvZvOvQdJKCLcPw"] =
        reinterpret_cast<void*>(ark_web_nweb_set_port_message_callback);
    funcMemberMap["yXow0CcFGmrYa1gsQwlGug"] =
        reinterpret_cast<void*>(ark_web_nweb_send_drag_event);
    funcMemberMap["uwP5y8DK5ChvibUHSEuZow"] =
        reinterpret_cast<void*>(ark_web_nweb_clear_ssl_cache);
    funcMemberMap["6pIZmJRnBkSCZZTZy7Ts3Q"] =
        reinterpret_cast<void*>(ark_web_nweb_get_url);
    funcMemberMap["$b8wTkhcjYOwgyp4IxP2DA"] =
        reinterpret_cast<void*>(ark_web_nweb_clear_client_authentication_cache);
    funcMemberMap["_dQ6smwn4ENO6i0B6JBRKA"] =
        reinterpret_cast<void*>(ark_web_nweb_update_locale);
    funcMemberMap["dvXv0QZhovv0GUiPjmrJLQ"] =
        reinterpret_cast<void*>(ark_web_nweb_get_original_url);
    funcMemberMap["UY_7BsveLLoLA$imJGQBlw"] =
        reinterpret_cast<void*>(ark_web_nweb_get_favicon);
    funcMemberMap["IbmbscCt_hcq7RHivYfCCQ"] =
        reinterpret_cast<void*>(ark_web_nweb_put_network_available);
    funcMemberMap["uLCpzBGiyC8H9f3Pyu_62Q"] =
        reinterpret_cast<void*>(ark_web_nweb_has_images);
    funcMemberMap["D_jQu72cEzzGogSsRgqM7w"] =
        reinterpret_cast<void*>(ark_web_nweb_remove_cache);
    funcMemberMap["XlMhmVoPzF8_FYq1Wei8Cw"] =
        reinterpret_cast<void*>(ark_web_nweb_get_history_list);
    funcMemberMap["MJuN9$XRvoEiIlgDIBIJNg"] =
        reinterpret_cast<void*>(ark_web_nweb_put_release_surface_callback);
    funcMemberMap["CZ0eYgJzYtN0fkucvuEWfg"] =
        reinterpret_cast<void*>(ark_web_nweb_serialize_web_state);
    funcMemberMap["G_EH7O0Uqc3rgz2G4G7zJQ"] =
        reinterpret_cast<void*>(ark_web_nweb_restore_web_state);
    funcMemberMap["c8E4ntaM49aDJmG95ecaog"] =
        reinterpret_cast<void*>(ark_web_nweb_page_up);
    funcMemberMap["BgSwlA_lXoMngZX9S9t2KQ"] =
        reinterpret_cast<void*>(ark_web_nweb_page_down);
    funcMemberMap["ruX8_FD8O76BV6puJd7PoA"] =
        reinterpret_cast<void*>(ark_web_nweb_scroll_to);
    funcMemberMap["zN7jIHbTM1arZ2bxy$d5Pg"] =
        reinterpret_cast<void*>(ark_web_nweb_scroll_by);
    funcMemberMap["fiPincJ61ypXLLEoCkdxQg"] =
        reinterpret_cast<void*>(ark_web_nweb_slide_scroll);
    funcMemberMap["kvCaSbBZNWT$hRBWUyCKNg"] =
        reinterpret_cast<void*>(ark_web_nweb_get_cert_chain_der_data);
    funcMemberMap["eV8n_cgQG3kBDlmAaqkTvw"] =
        reinterpret_cast<void*>(ark_web_nweb_set_screen_off_set);
    funcMemberMap["p4l$cfSBd5JICXPmhpGVJg"] =
        reinterpret_cast<void*>(ark_web_nweb_set_audio_muted);
    funcMemberMap["hF_ONJYngnkYxBbvR55l4A"] = reinterpret_cast<void*>(
        ark_web_nweb_set_should_frame_submission_before_draw);
    funcMemberMap["YycmTDERAsFtcLiCU7CNnQ"] =
        reinterpret_cast<void*>(ark_web_nweb_notify_popup_window_result);
    funcMemberMap["CRe_vA6EgMjutHfLUsygow"] =
        reinterpret_cast<void*>(ark_web_nweb_set_audio_resume_interval);
    funcMemberMap["sbAOYRVTQTC9CdmP39zyjA"] =
        reinterpret_cast<void*>(ark_web_nweb_set_audio_exclusive);
    funcMemberMap["aHjUYR42zxhqwp3JCize$g"] =
        reinterpret_cast<void*>(ark_web_nweb_register_screen_lock_function);
    funcMemberMap["OO4ZrWbLELx_rR1pDs_VVg"] =
        reinterpret_cast<void*>(ark_web_nweb_un_register_screen_lock_function);
    funcMemberMap["TmVG4K6hn6cnIzRBZkDaUQ"] =
        reinterpret_cast<void*>(ark_web_nweb_notify_memory_level);
    funcMemberMap["otWnTADRs6o_f2Z4P3QVug"] =
        reinterpret_cast<void*>(ark_web_nweb_on_webview_hide);
    funcMemberMap["g4gFxx9Xu9gh_e5KTvhg9w"] =
        reinterpret_cast<void*>(ark_web_nweb_on_webview_show);
    funcMemberMap["lh2VU0pQ0mutOSI8UIVc5w"] =
        reinterpret_cast<void*>(ark_web_nweb_get_or_create_drag_data);
    funcMemberMap["NOo7LrGTOnvFPCaMwxz5Tw"] =
        reinterpret_cast<void*>(ark_web_nweb_prefetch_page);
    funcMemberMap["emAB1_1CMzflBOC3PnWzgw"] =
        reinterpret_cast<void*>(ark_web_nweb_set_window_id);
    funcMemberMap["oGxVg0gSjL$xsi6CJdeO$w"] =
        reinterpret_cast<void*>(ark_web_nweb_on_occluded);
    funcMemberMap["28I6B86uLWrJ9YaMGgJ89g"] =
        reinterpret_cast<void*>(ark_web_nweb_on_unoccluded);
    funcMemberMap["jz0b9WaC5y26Z1c3Y_bKkw"] =
        reinterpret_cast<void*>(ark_web_nweb_set_token);
    funcMemberMap["4oMV7NZCs_HV5Ph9vLTIVw"] =
        reinterpret_cast<void*>(ark_web_nweb_set_nested_scroll_mode);
    funcMemberMap["QIIhVY0jUhLTfH$Zy$lTdw"] =
        reinterpret_cast<void*>(ark_web_nweb_set_enable_lower_frame_rate);
    funcMemberMap["H2TOBeIdf8lqBGZutGQrGQ"] =
        reinterpret_cast<void*>(ark_web_nweb_set_virtual_key_board_arg);
    funcMemberMap["4dhh_qjQuNI9gtEEPjSj1A"] =
        reinterpret_cast<void*>(ark_web_nweb_should_virtual_keyboard_overlay);
    funcMemberMap["RK15ocV1uxtD3fkZbpNH7A"] =
        reinterpret_cast<void*>(ark_web_nweb_set_draw_rect);
    funcMemberMap["4ba5Wzzlm53U5K$RQiyXIQ"] =
        reinterpret_cast<void*>(ark_web_nweb_set_draw_mode);
    funcMemberMap["EyaOA2eP4O1ZQoFoQDtS0g"] =
        reinterpret_cast<void*>(ark_web_nweb_create_web_print_document_adapter);
    funcMemberMap["cXGgGc0TTNPxYkEAzYioqQ"] =
        reinterpret_cast<void*>(ark_web_nweb_post_url);
    funcMemberMap["Ox1HdrNgdWIZuiDnOZ80nQ"] =
        reinterpret_cast<void*>(ark_web_nweb_java_script_on_document_start);
    funcMemberMap["YFlX3TpgrfUO5TQitqeEog"] =
        reinterpret_cast<void*>(ark_web_nweb_execute_action);
    funcMemberMap["7AKrE6mvFHvlAQZ0uJWxKg"] = reinterpret_cast<void*>(
        ark_web_nweb_get_focused_accessibility_node_info);
    funcMemberMap["mxmnAvpqrZIonzp1fUgaHA"] =
        reinterpret_cast<void*>(ark_web_nweb_get_accessibility_node_info_by_id);
    funcMemberMap["fcq4Hy_ulgnWPKZ4rM4UBg"] = reinterpret_cast<void*>(
        ark_web_nweb_get_accessibility_node_info_by_focus_move);
    funcMemberMap["xrt5hl4sOUkI13TrWPZ$PA"] =
        reinterpret_cast<void*>(ark_web_nweb_set_accessibility_state);
    funcMemberMap["lI6_Nmbvjhcmq3p6xrBquQ"] =
        reinterpret_cast<void*>(ark_web_nweb_need_soft_keyboard);
    funcMemberMap["4Gt0KJ0ZSjfnAwspA3PJew"] =
        reinterpret_cast<void*>(ark_web_nweb_discard);
    funcMemberMap["mHgoTJfSj6VpSf0k0SZvrQ"] =
        reinterpret_cast<void*>(ark_web_nweb_restore);
    funcMemberMap["CG5C8I0qCrKRutQir_YRvg"] =
        reinterpret_cast<void*>(ark_web_nweb_get_security_level);
    funcMemberMap["uRx16Zw5k0EWF1o0N_mX9g"] =
        reinterpret_cast<void*>(ark_web_nweb_call_h5function);
    funcMemberMap["FrRJ0_NcE38obGFCNCZI7Q"] =
        reinterpret_cast<void*>(ark_web_nweb_is_incognito_mode);
    funcMemberMap["mmr3rzqDxFn7qDGa3OfPqA"] =
        reinterpret_cast<void*>(ark_web_nweb_register_native_ark_jsfunction);
    funcMemberMap["plzXUu44RmNG4X4REC6XsA"] =
        reinterpret_cast<void*>(ark_web_nweb_un_register_native_ark_jsfunction);
    funcMemberMap["263P581pKLiBdl1KIbK8eA"] =
        reinterpret_cast<void*>(ark_web_nweb_register_native_valide_callback);
    funcMemberMap["T3HGfF66LcXPmOeCN1bcMg"] =
        reinterpret_cast<void*>(ark_web_nweb_register_native_destroy_callback);
    funcMemberMap["Oi2iAyaoyX6S0r$l0RlfLQ"] =
        reinterpret_cast<void*>(ark_web_nweb_java_script_on_document_end);
    funcMemberMap["q1$W6FV4B4kElNCh40gY7w"] =
        reinterpret_cast<void*>(ark_web_nweb_enable_safe_browsing);
    funcMemberMap["4wfHpaKTi6U6xzh0SpCffw"] =
        reinterpret_cast<void*>(ark_web_nweb_is_safe_browsing_enabled);
    funcMemberMap["A4f67G6nwJemaohe1pbByQ"] =
        reinterpret_cast<void*>(ark_web_nweb_set_print_background);
    funcMemberMap["LoGTboapq_0lqHMcBwBGfg"] =
        reinterpret_cast<void*>(ark_web_nweb_get_print_background);
    funcMemberMap["gPpuAXJyAztOq7$XFMdZcQ"] =
        reinterpret_cast<void*>(ark_web_nweb_close_all_media_presentations);
    funcMemberMap["wNJqwhHyUaOJ$JCHCyAIXw"] =
        reinterpret_cast<void*>(ark_web_nweb_stop_all_media);
    funcMemberMap["9PgSKThHZKaoU1Cf0Cuuew"] =
        reinterpret_cast<void*>(ark_web_nweb_resume_all_media);
    funcMemberMap["on6kTS9M8TDohbotNq8WQg"] =
        reinterpret_cast<void*>(ark_web_nweb_pause_all_media);
    funcMemberMap["Z7Eq0K$ultTZVPR9DXEQ1Q"] =
        reinterpret_cast<void*>(ark_web_nweb_get_media_playback_state);
    funcMemberMap["AeJgDYeoZjrZKRJatEzDcA"] = reinterpret_cast<void*>(
        ark_web_nweb_enable_intelligent_tracking_prevention);
    funcMemberMap["i4VUe$iwsC7SyT1tp6105A"] = reinterpret_cast<void*>(
        ark_web_nweb_is_intelligent_tracking_prevention_enabled);
    funcMemberMap["PtImDZ0NoKOBFfLaDNs28g"] =
        reinterpret_cast<void*>(ark_web_nweb_start_camera);
    funcMemberMap["_mLJiw8YNCg2y9GNsOUutA"] =
        reinterpret_cast<void*>(ark_web_nweb_stop_camera);
    funcMemberMap["bYdhoNcnj6xWvG0RBqGhbA"] =
        reinterpret_cast<void*>(ark_web_nweb_close_camera);
    funcMemberMap["c1JrdNkG1gfFGn7SAyHSdA"] = reinterpret_cast<void*>(
        ark_web_nweb_get_last_javascript_proxy_calling_frame_url);
    funcMemberMap["X_Pbqfv5YyDAQZbHR4Hg_w"] =
        reinterpret_cast<void*>(ark_web_nweb_get_pending_size_status);
    funcMemberMap["knvv9rp8DCGK6ndfMvg_fA"] =
        reinterpret_cast<void*>(ark_web_nweb_scroll_by_ref_screen);
    funcMemberMap["eOMARrDMcCJZSX1ubAKR4Q"] =
        reinterpret_cast<void*>(ark_web_nweb_execute_java_script_ext);
    funcMemberMap["m218oaZDIFLEvLXGIUjXhA"] =
        reinterpret_cast<void*>(ark_web_nweb_on_render_to_background);
    funcMemberMap["0AeyuOVeh_Xdb90txSISyQ"] =
        reinterpret_cast<void*>(ark_web_nweb_on_render_to_foreground);
    funcMemberMap["eKJ$p5kJsFYMhTmi3m2$8A"] =
        reinterpret_cast<void*>(ark_web_nweb_precompile_java_script);
    funcMemberMap["qzHpmZYUsWS4JO31w3uyaw"] =
        reinterpret_cast<void*>(ark_web_nweb_on_create_native_media_player);
    funcMemberMap["IziZmOZtOrVdp2bZiYo7dg"] =
        reinterpret_cast<void*>(ark_web_nweb_drag_resize);
    funcMemberMap["oag7OYcSG_T5RSx$PVyC5w"] =
        reinterpret_cast<void*>(ark_web_nweb_on_touch_cancel_by_id);
    funcMemberMap["PQ_G2V8trCBHyRsz0yFisQ"] =
        reinterpret_cast<void*>(ark_web_nweb_scale_gesture_change);
    funcMemberMap["K5AUtf86S3eOmwvNJV6M7Q"] =
        reinterpret_cast<void*>(ark_web_nweb_inject_offline_resource);
    funcMemberMap["kmi3eSNAn_lCqDBBeIuUFA"] =
        reinterpret_cast<void*>(ark_web_nweb_terminate_render_process);
    funcMemberMap["lvbF6b_WBvzJ33OUNhdZSg"] =
        reinterpret_cast<void*>(ark_web_nweb_suggestion_selected);
    funcMemberMap["m4tUebVLa33OZan62jS2EQ"] =
        reinterpret_cast<void*>(ark_web_nweb_register_ark_jsfunction2);
    funcMemberMap["vQjLxhlce8Nk9G5dRXNdlQ"] =
        reinterpret_cast<void*>(ark_web_nweb_send_touchpad_fling_event);
    funcMemberMap["FISOPch_xAqCJ1r1K5papQ"] =
        reinterpret_cast<void*>(ark_web_nweb_set_fit_content_mode);
    funcMemberMap["z6tCI0$Ug4L_TQpRS2LmQQ"] =
        reinterpret_cast<void*>(ark_web_nweb_get_select_info);
    funcMemberMap["Sigh10GO4jZbFSmYQ54QtQ"] =
        reinterpret_cast<void*>(ark_web_nweb_on_online_render_to_foreground);
    funcMemberMap["MF599qF44hnneEIjq1dngg"] =
        reinterpret_cast<void*>(ark_web_nweb_on_safe_insets_change);
    funcMemberMap["TcxdKxzW8z$safhEc7_38A"] =
        reinterpret_cast<void*>(ark_web_nweb_on_text_selected);
    funcMemberMap["2yG4JQ9lTIKx4NCDMshjJA"] =
        reinterpret_cast<void*>(ark_web_nweb_web_send_key_event);
    funcMemberMap["bZLhXGmEtaMfPMxP07cm1A"] =
        reinterpret_cast<void*>(ark_web_nweb_on_configuration_updated);
    funcMemberMap["dzH0OhFdJJCKmc8oOCwBgg"] =
        reinterpret_cast<void*>(ark_web_nweb_enable_ads_block);
    funcMemberMap["ipjjj28HoSnOylMGBJqKmw"] =
        reinterpret_cast<void*>(ark_web_nweb_is_ads_block_enabled);
    funcMemberMap["4OD3qftqztA8n_n_u4QWGA"] =
        reinterpret_cast<void*>(ark_web_nweb_is_ads_block_enabled_for_cur_page);
    funcMemberMap["vjbTSW8i90LQ8ArzBzUAYQ"] =
        reinterpret_cast<void*>(ark_web_nweb_notify_for_next_touch_event);
    funcMemberMap["5Su$xJej24q3QjKQEBISvw"] =
        reinterpret_cast<void*>(ark_web_nweb_set_url_trust_list);
    funcMemberMap["yz14P1LjzkWfkuy65ZBStA"] = reinterpret_cast<void*>(
        ark_web_nweb_put_spanstring_convert_html_callback);
    funcMemberMap["A$UU8DDyiJj5dZZQhwfypw"] =
        reinterpret_cast<void*>(ark_web_nweb_web_page_snapshot);
    funcMemberMap["dSAspRgIzpe64xpIcc5bGQ"] = reinterpret_cast<void*>(
        ark_web_nweb_set_path_allowing_universal_access);
    funcMemberMap["m8B1spqqUnFWT_B35e1V6w"] =
        reinterpret_cast<void*>(ark_web_nweb_perform_action);
    funcMemberMap["EvEMne4ckTSATM_CbNjudQ"] =
        reinterpret_cast<void*>(ark_web_nweb_scroll_to_with_anime);
    funcMemberMap["OJ3J8Exn0JcjXZSqPk6KLw"] =
        reinterpret_cast<void*>(ark_web_nweb_scroll_by_with_anime);
    funcMemberMap["zL5bs40c7qV5t5C$UOb_bw"] =
        reinterpret_cast<void*>(ark_web_nweb_web_send_mouse_wheel_event);
    funcMemberMap["1ZSYI2W_ZSNyBL9pknBU9A"] =
        reinterpret_cast<void*>(ark_web_nweb_web_send_touchpad_fling_event);
    funcMemberMap["q2I32djVAUutTrCywRwsLw"] =
        reinterpret_cast<void*>(ark_web_nweb_set_url_trust_list_with_err_msg);
    funcMemberMap["bbSTiWTw2Qsnn9Ur3BnAOw"] =
        reinterpret_cast<void*>(ark_web_nweb_send_accessibility_hover_event);
    funcMemberMap["w2s6meNdwO0PepKCW7_BMw"] =
        reinterpret_cast<void*>(ark_web_nweb_register_ark_jsfunction3);
    funcMemberMap["UP3JpGLAWf6QX$uC1LLiGw"] =
        reinterpret_cast<void*>(ark_web_nweb_resize_visible_viewport);
    funcMemberMap["V6J0kDqABtGFO3Mi9u7fFQ"] =
        reinterpret_cast<void*>(ark_web_nweb_set_back_forward_cache_options);
    funcMemberMap["95Xg0lc0KKSIZ9jkTonUzw"] =
        reinterpret_cast<void*>(ark_web_nweb_set_autofill_callback);
    funcMemberMap["Cvmsq9T1VFYncM_nRlIQgA"] =
        reinterpret_cast<void*>(ark_web_nweb_fill_autofill_data);
    funcMemberMap["y0KfkN0r8TjNPDncFe0Rcw"] =
        reinterpret_cast<void*>(ark_web_nweb_on_autofill_cancel);
    funcMemberMap["CUWcTP1Bdn35Pfb_pujnTA"] =
        reinterpret_cast<void*>(ark_web_nweb_get_scroll_offset);
    funcMemberMap["jjLj6SBCyh75QPoAfNu7oA"] =
        reinterpret_cast<void*>(ark_web_nweb_execute_create_pdfext);
    funcMemberMap["CgspHvdwq5EZpsx6IyZQVw"] =
        reinterpret_cast<void*>(ark_web_nweb_scroll_by_with_result);
    funcMemberMap["H97v25aIM4OSAUAgVkO_gQ"] =
        reinterpret_cast<void*>(ark_web_nweb_set_popup_surface);
    funcMemberMap["KjoLU3$e6RWTYi24_cK8Gw"] =
        reinterpret_cast<void*>(ark_web_nweb_on_destroy_image_analyzer_overlay);
    funcMemberMap["eHDTloVjkPl2cGsoC0dMZw"] =
        reinterpret_cast<void*>(ark_web_nweb_web_send_mouse_event);
    funcMemberMap["6JjzZ0t9iffimSDLeBQ1FQ"] =
        reinterpret_cast<void*>(ark_web_nweb_get_accessibility_visible);
    funcMemberMap["oGPEj_NAmSuPuXt8lpVu2g"] =
        reinterpret_cast<void*>(ark_web_nweb_set_transform_hint);
    funcMemberMap["8hC_zDJQoenOPeCiDU_jPQ"] =
        reinterpret_cast<void*>(ark_web_nweb_web_components_blur);
    funcMemberMap["Leg6rEyFbnXFveh1sAiC0A"] =
        reinterpret_cast<void*>(ark_web_nweb_dump_gpu_info);
    funcMemberMap["l9N1O3stsEElJHMHKnkzKA"] =
        reinterpret_cast<void*>(ark_web_nweb_scale_gesture_change_v2);
    funcMemberMap["H3jgv1laTuvF3eHpbNy4mg"] =
        reinterpret_cast<void*>(ark_web_nweb_send_keyboard_event);
    funcMemberMap["ZVoyiqnu5TTuZ_SE0qzQeg"] =
        reinterpret_cast<void*>(ark_web_nweb_perform_action_v2);
    funcMemberMap["tglxZM3J1e3DwNXlgnENAw"] = reinterpret_cast<void*>(
        ark_web_nweb_java_script_on_document_start_by_order);
    funcMemberMap["k_v44fBh2Sp4VpG9N81kCA"] = reinterpret_cast<void*>(
        ark_web_nweb_java_script_on_document_end_by_order);
    funcMemberMap["mtR$$5qp8EAIMIev_0h59g"] =
        reinterpret_cast<void*>(ark_web_nweb_is_active_policy_disable);
    funcMemberMap["uppRvWCYdI4ZCq8otEFMTw"] = reinterpret_cast<void*>(
        ark_web_nweb_java_script_on_head_ready_by_order);
    funcMemberMap["EHtmni2MEfHgJ5aNofBvLQ"] = reinterpret_cast<void*>(
        ark_web_nweb_put_optimize_parser_budget_enabled);
    funcMemberMap["zfKEMLt1gExFmkSFjc3gKA"] =
        reinterpret_cast<void*>(ark_web_nweb_get_accessibility_node_rect_by_id);
    funcMemberMap["a8COwlmxCvjYO2VOchfV6w"] =
        reinterpret_cast<void*>(ark_web_nweb_get_last_hit_test_result);
    funcMemberMap["X6r5eDuJ3dyR9Tcoi5F8gw"] =
        reinterpret_cast<void*>(ark_web_nweb_get_current_language);
    funcMemberMap["TqDfE2FfWDO$FR7BqEZHsw"] =
        reinterpret_cast<void*>(ark_web_nweb_web_send_mouse_wheel_event_v2);
    funcMemberMap["0yiGApxRtx7jDQ0vpDQJlw"] =
        reinterpret_cast<void*>(ark_web_nweb_is_nweb_ex);
    funcMemberMap["fCb0MgRQ1VBaspVXBWrvAw"] =
        reinterpret_cast<void*>(ark_web_nweb_set_enable_half_frame_rate);
    funcMemberMap["s7kb5fxLxxckZcs_f6dhmg"] =
        reinterpret_cast<void*>(ark_web_nweb_maximize_resize);
    funcMemberMap["qfnXs16OCOm7mxFhmXO7ww"] =
        reinterpret_cast<void*>(ark_web_nweb_on_drag_attach);
    funcMemberMap["LpYyasJ91ih02oB_eTdtzg"] =
        reinterpret_cast<void*>(ark_web_nweb_set_focus_by_position);
    funcMemberMap["6QCgOJMr0QtjzGFl2tnAQQ"] =
        reinterpret_cast<void*>(ark_web_nweb_set_surface_density);
    funcMemberMap["wHylVEMwoVuf18EabHXSWw"] =
        reinterpret_cast<void*>(ark_web_nweb_set_border_radius_from_web);
    funcMemberMap["8gGvSXShXHTgQX6fgkSqUQ"] =
        reinterpret_cast<void*>(ark_web_nweb_set_native_inner_web);
    funcMemberMap["Hz5A8H7wkoJgNB91lgMuNw"] =
        reinterpret_cast<void*>(ark_web_nweb_send_accessibility_hover_event_v2);
    funcMemberMap["EzLSUtwxxiXSgct3xybQTw"] =
        reinterpret_cast<void*>(ark_web_nweb_on_browser_foreground);
    funcMemberMap["Q1Jl65OIZTzh_jEqH4eevQ"] =
        reinterpret_cast<void*>(ark_web_nweb_on_browser_background);
    funcMemberMap["RcLZK34yL7PeOvU$Os0sLA"] =
        reinterpret_cast<void*>(ark_web_nweb_register_native_java_script_proxy);
    funcMemberMap["UQvsfUi0Z6UoY6GSqty5lA"] =
        reinterpret_cast<void*>(ark_web_nweb_set_focus_window_id);
    funcMemberMap["iVDaW0Tn5Zg9LZnPZU1wSw"] =
        reinterpret_cast<void*>(ark_web_nweb_run_data_detector_js);
    funcMemberMap["TKLPC8MHqUBYYgPQjl4pvw"] =
        reinterpret_cast<void*>(ark_web_nweb_set_data_detector_enable);
    funcMemberMap["itEclsvPhGzieY1j$kyjWg"] =
        reinterpret_cast<void*>(ark_web_nweb_on_data_detector_select_text);
    funcMemberMap["uDDAVnmUWMtIXOsC3tBjAA"] =
        reinterpret_cast<void*>(ark_web_nweb_on_data_detector_copy);
    funcMemberMap["yOJHG1pFuzAFnWKwRxhCjw"] =
        reinterpret_cast<void*>(ark_web_nweb_set_pip_native_window);
    funcMemberMap["wZBMYFAmwaAg8sfIkHe9cw"] =
        reinterpret_cast<void*>(ark_web_nweb_send_pip_event);
    funcMemberMap["O0gTQCjd9CRomyZR0K_CpA"] =
        reinterpret_cast<void*>(ark_web_nweb_set_blankless_loading_key);
    funcMemberMap["k2sSloaV5qagPFcTdYsn_w"] =
        reinterpret_cast<void*>(ark_web_nweb_set_privacy_status);
    funcMemberMap["VUk4nYXXkJk_5fBioqXB2A"] =
        reinterpret_cast<void*>(ark_web_nweb_get_select_start_index);
    funcMemberMap["BxrZHeEhiTRZoYp_Ca8sLg"] =
        reinterpret_cast<void*>(ark_web_nweb_get_select_end_index);
    funcMemberMap["Q37J82qjnWXiDHbhKZqYKQ"] =
        reinterpret_cast<void*>(ark_web_nweb_get_all_text_info);
    funcMemberMap["DLEjwTTCCgoAY2bY76V8GA"] =
        reinterpret_cast<void*>(ark_web_nweb_set_audio_session_type);
    funcMemberMap["FVoJYiGfShBnHM6_p8ctXQ"] = reinterpret_cast<void*>(
        ark_web_nweb_get_web_accessibility_id_by_html_element_id);
    funcMemberMap["TEYdpPV6mdhT80cRG8kD8g"] =
        reinterpret_cast<void*>(ark_web_nweb_get_blankless_info_with_key);
    funcMemberMap["dLwBaeqNbYWirE$dD55FEw"] =
        reinterpret_cast<void*>(ark_web_nweb_set_blankless_loading_with_key);
    funcMemberMap["GmmGVBb2KNDSc$u7SZ7NxA"] =
        reinterpret_cast<void*>(ark_web_nweb_update_single_handle_visible);
    funcMemberMap["haByw0wsbRo7nuWFezB7Yg"] =
        reinterpret_cast<void*>(ark_web_nweb_set_touch_handle_exist_state);
    funcMemberMap["fqYVSjWeMEcDFyEXuf9otg"] =
        reinterpret_cast<void*>(ark_web_nweb_avoid_visible_viewport_bottom);
    funcMemberMap["nxe8cptrzdpOIWV5UmEQeg"] =
        reinterpret_cast<void*>(ark_web_nweb_get_visible_viewport_avoid_height);
    funcMemberMap["tJ$W3qSt3duTu95YoUaVgg"] =
        reinterpret_cast<void*>(ark_web_nweb_trigger_blankless_for_url);
    funcMemberMap["J$oZm5vbdaWNLgF8zWLp7g"] =
        reinterpret_cast<void*>(ark_web_nweb_set_visibility);
    funcMemberMap["Xf8MqxHt8hLIvSpXpjJcdA"] =
        reinterpret_cast<void*>(ark_web_nweb_set_viewport_scale_state);
    funcMemberMap["wTKQLaWIRDAhbz93IrXSKQ"] =
        reinterpret_cast<void*>(ark_web_nweb_get_page_offset);
    funcMemberMap["P83XRA0o_dsBClCgdnJ2tQ"] =
        reinterpret_cast<void*>(ark_web_nweb_set_error_page_enabled);
    funcMemberMap["KIrbd4BarEnBmut5q333LQ"] =
        reinterpret_cast<void*>(ark_web_nweb_get_error_page_enabled);
    funcMemberMap["eJ4lmpoHl_fSIGKBwwyvaQ"] =
        reinterpret_cast<void*>(ark_web_nweb_get_web_destroy_mode);
    funcMemberMap["nvNLVpY1bjQGRyaojFlOWQ"] =
        reinterpret_cast<void*>(ark_web_nweb_call_h5function_v2);
    funcMemberMap["n8AgKi9zvbzAhU8cm76ycA"] =
        reinterpret_cast<void*>(ark_web_nweb_post_port_message_v2);
    funcMemberMap["rCfnxUlOyLHWJbuGMXgrSw"] =
        reinterpret_cast<void*>(ark_web_nweb_fill_autofill_data_v2);
    funcMemberMap["gfes619S4OfnLWmaaWwx5Q"] = reinterpret_cast<void*>(
        ark_web_nweb_create_web_print_document_adapter_v2);
    funcMemberMap["J9oauDmRK1QR96BN_sjlig"] =
        reinterpret_cast<void*>(ark_web_nweb_on_stylus_touch_press);
    funcMemberMap["spmhQaeUL05gRu$Cm5EPLg"] =
        reinterpret_cast<void*>(ark_web_nweb_on_stylus_touch_release);
    funcMemberMap["jPb8ux85EXE5xNeb3zRKFA"] =
        reinterpret_cast<void*>(ark_web_nweb_on_stylus_touch_move);
    funcMemberMap["wr573En3xnHagahRIfSqqw"] =
        reinterpret_cast<void*>(ark_web_nweb_record_blankless_frame_size);
    funcMemberMap["7AylSM0jd2n6_n2Ig86b8Q"] =
        reinterpret_cast<void*>(ark_web_nweb_prefetch_page_v2);
    funcMemberMap["CRZh6pjFyL3Cq78tq2EudA"] =
        reinterpret_cast<void*>(ark_web_nweb_set_force_enable_zoom);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_NWEB, funcMemberMap);
  });
}

ArkWebNWebCppToC::~ArkWebNWebCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<ArkWebNWebCppToC,
                                        ArkWebNWeb,
                                        ark_web_nweb_t>::kBridgeType =
    ARK_WEB_NWEB;

}  // namespace OHOS::ArkWeb
