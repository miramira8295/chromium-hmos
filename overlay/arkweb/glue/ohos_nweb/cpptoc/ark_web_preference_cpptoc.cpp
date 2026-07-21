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

#include "ohos_nweb/cpptoc/ark_web_preference_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

ArkWebString ARK_WEB_CALLBACK
ark_web_preference_user_agent(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->UserAgent();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_user_agent(struct _ark_web_preference_t* self,
                                  const ArkWebString* ua) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(ua, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutUserAgent(*ua);
}

ArkWebString ARK_WEB_CALLBACK
ark_web_preference_default_user_agent(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->DefaultUserAgent();
}

int ARK_WEB_CALLBACK
ark_web_preference_cache_mode(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->CacheMode();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_cache_mode(struct _ark_web_preference_t* self,
                                  int flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutCacheMode(flag);
}

bool ARK_WEB_CALLBACK
ark_web_preference_is_network_blocked(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->IsNetworkBlocked();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_block_network(struct _ark_web_preference_t* self,
                                     bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutBlockNetwork(flag);
}

uint32_t ARK_WEB_CALLBACK
ark_web_preference_get_scroll_bar_color(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->GetScrollBarColor();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_scroll_bar_color(struct _ark_web_preference_t* self,
                                        uint32_t color_value) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutScrollBarColor(color_value);
}

int ARK_WEB_CALLBACK
ark_web_preference_get_overscroll_mode(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->GetOverscrollMode();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_overscroll_mode(struct _ark_web_preference_t* self,
                                       int over_scroll_mode) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutOverscrollMode(over_scroll_mode);
}

int ARK_WEB_CALLBACK
ark_web_preference_default_font_size(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->DefaultFontSize();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_default_font_size(struct _ark_web_preference_t* self,
                                         int size) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutDefaultFontSize(size);
}

bool ARK_WEB_CALLBACK
ark_web_preference_get_pinch_smooth_mode(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->GetPinchSmoothMode();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_pinch_smooth_mode(struct _ark_web_preference_t* self,
                                         bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutPinchSmoothMode(flag);
}

bool ARK_WEB_CALLBACK
ark_web_preference_is_data_base_enabled(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->IsDataBaseEnabled();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_database_allowed(struct _ark_web_preference_t* self,
                                        bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutDatabaseAllowed(flag);
}

bool ARK_WEB_CALLBACK
ark_web_preference_is_multi_window_access(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->IsMultiWindowAccess();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_multi_window_access(struct _ark_web_preference_t* self,
                                           bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutMultiWindowAccess(flag);
}

bool ARK_WEB_CALLBACK
ark_web_preference_is_java_script_allowed(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->IsJavaScriptAllowed();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_java_script_enabled(struct _ark_web_preference_t* self,
                                           bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutJavaScriptEnabled(flag);
}

int ARK_WEB_CALLBACK
ark_web_preference_dark_scheme_enabled(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->DarkSchemeEnabled();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_dark_scheme_enabled(struct _ark_web_preference_t* self,
                                           int dark_scheme) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutDarkSchemeEnabled(dark_scheme);
}

bool ARK_WEB_CALLBACK
ark_web_preference_is_dom_storage_enabled(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->IsDomStorageEnabled();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_dom_storage_enabled(struct _ark_web_preference_t* self,
                                           bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutDomStorageEnabled(flag);
}

int ARK_WEB_CALLBACK
ark_web_preference_font_size_lower_limit(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->FontSizeLowerLimit();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_font_size_lower_limit(struct _ark_web_preference_t* self,
                                             int size) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutFontSizeLowerLimit(size);
}

bool ARK_WEB_CALLBACK
ark_web_preference_geo_location_allowed(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->GeoLocationAllowed();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_geo_location_allowed(struct _ark_web_preference_t* self,
                                            bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutGeoLocationAllowed(flag);
}

bool ARK_WEB_CALLBACK
ark_web_preference_is_web_debugging_access(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->IsWebDebuggingAccess();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_web_debugging_access(struct _ark_web_preference_t* self,
                                            bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutWebDebuggingAccess(flag);
}

bool ARK_WEB_CALLBACK
ark_web_preference_enable_content_access(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->EnableContentAccess();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_enable_content_access(struct _ark_web_preference_t* self,
                                             bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutEnableContentAccess(flag);
}

bool ARK_WEB_CALLBACK
ark_web_preference_enable_raw_file_access(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->EnableRawFileAccess();
}

void ARK_WEB_CALLBACK ark_web_preference_put_enable_raw_file_access(
    struct _ark_web_preference_t* self,
    bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutEnableRawFileAccess(flag);
}

bool ARK_WEB_CALLBACK ark_web_preference_is_image_loading_allowed(
    struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->IsImageLoadingAllowed();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_image_loading_allowed(struct _ark_web_preference_t* self,
                                             bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutImageLoadingAllowed(flag);
}

ArkWebString ARK_WEB_CALLBACK
ark_web_preference_fixed_font_family_name(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->FixedFontFamilyName();
}

void ARK_WEB_CALLBACK ark_web_preference_put_fixed_font_family_name(
    struct _ark_web_preference_t* self,
    const ArkWebString* font) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(font, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutFixedFontFamilyName(*font);
}

ArkWebString ARK_WEB_CALLBACK
ark_web_preference_serif_font_family_name(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->SerifFontFamilyName();
}

void ARK_WEB_CALLBACK ark_web_preference_put_serif_font_family_name(
    struct _ark_web_preference_t* self,
    const ArkWebString* font) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(font, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutSerifFontFamilyName(*font);
}

int ARK_WEB_CALLBACK
ark_web_preference_zooming_for_text_factor(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->ZoomingForTextFactor();
}

void ARK_WEB_CALLBACK ark_web_preference_put_zooming_for_text_factor(
    struct _ark_web_preference_t* self,
    int text_zoom) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutZoomingForTextFactor(text_zoom);
}

int ARK_WEB_CALLBACK
ark_web_preference_force_dark_mode_enabled(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->ForceDarkModeEnabled();
}

void ARK_WEB_CALLBACK ark_web_preference_put_force_dark_mode_enabled(
    struct _ark_web_preference_t* self,
    int force_dark) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutForceDarkModeEnabled(force_dark);
}

bool ARK_WEB_CALLBACK ark_web_preference_is_load_with_overview_mode(
    struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->IsLoadWithOverviewMode();
}

void ARK_WEB_CALLBACK ark_web_preference_put_load_with_overview_mode(
    struct _ark_web_preference_t* self,
    bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutLoadWithOverviewMode(flag);
}

int ARK_WEB_CALLBACK
ark_web_preference_default_fixed_font_size(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->DefaultFixedFontSize();
}

void ARK_WEB_CALLBACK ark_web_preference_put_default_fixed_font_size(
    struct _ark_web_preference_t* self,
    int size) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutDefaultFixedFontSize(size);
}

ArkWebString ARK_WEB_CALLBACK ark_web_preference_cursive_font_family_name(
    struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->CursiveFontFamilyName();
}

void ARK_WEB_CALLBACK ark_web_preference_put_cursive_font_family_name(
    struct _ark_web_preference_t* self,
    const ArkWebString* font) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(font, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutCursiveFontFamilyName(*font);
}

ArkWebString ARK_WEB_CALLBACK ark_web_preference_fantasy_font_family_name(
    struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->FantasyFontFamilyName();
}

void ARK_WEB_CALLBACK ark_web_preference_put_fantasy_font_family_name(
    struct _ark_web_preference_t* self,
    const ArkWebString* font) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(font, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutFantasyFontFamilyName(*font);
}

bool ARK_WEB_CALLBACK
ark_web_preference_zoomingfunction_enabled(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->ZoomingfunctionEnabled();
}

void ARK_WEB_CALLBACK ark_web_preference_put_zooming_function_enabled(
    struct _ark_web_preference_t* self,
    bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutZoomingFunctionEnabled(flag);
}

bool ARK_WEB_CALLBACK ark_web_preference_get_media_play_gesture_access(
    struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->GetMediaPlayGestureAccess();
}

void ARK_WEB_CALLBACK ark_web_preference_put_media_play_gesture_access(
    struct _ark_web_preference_t* self,
    bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutMediaPlayGestureAccess(flag);
}

ArkWebString ARK_WEB_CALLBACK ark_web_preference_standard_font_family_name(
    struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->StandardFontFamilyName();
}

void ARK_WEB_CALLBACK ark_web_preference_put_standard_font_family_name(
    struct _ark_web_preference_t* self,
    const ArkWebString* font) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(font, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutStandardFontFamilyName(*font);
}

ArkWebString ARK_WEB_CALLBACK ark_web_preference_sans_serif_font_family_name(
    struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->SansSerifFontFamilyName();
}

void ARK_WEB_CALLBACK ark_web_preference_put_sans_serif_font_family_name(
    struct _ark_web_preference_t* self,
    const ArkWebString* font) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(font, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutSansSerifFontFamilyName(*font);
}

bool ARK_WEB_CALLBACK ark_web_preference_is_vertical_scroll_bar_access(
    struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->IsVerticalScrollBarAccess();
}

void ARK_WEB_CALLBACK ark_web_preference_put_vertical_scroll_bar_access(
    struct _ark_web_preference_t* self,
    bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutVerticalScrollBarAccess(flag);
}

bool ARK_WEB_CALLBACK ark_web_preference_is_horizontal_scroll_bar_access(
    struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->IsHorizontalScrollBarAccess();
}

void ARK_WEB_CALLBACK ark_web_preference_put_horizontal_scroll_bar_access(
    struct _ark_web_preference_t* self,
    bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutHorizontalScrollBarAccess(flag);
}

int ARK_WEB_CALLBACK ark_web_preference_logical_font_size_lower_limit(
    struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->LogicalFontSizeLowerLimit();
}

void ARK_WEB_CALLBACK ark_web_preference_put_logical_font_size_lower_limit(
    struct _ark_web_preference_t* self,
    int size) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutLogicalFontSizeLowerLimit(size);
}

ArkWebString ARK_WEB_CALLBACK ark_web_preference_default_text_encoding_format(
    struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->DefaultTextEncodingFormat();
}

void ARK_WEB_CALLBACK ark_web_preference_put_default_text_encoding_format(
    struct _ark_web_preference_t* self,
    const ArkWebString* encoding) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(encoding, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutDefaultTextEncodingFormat(*encoding);
}

bool ARK_WEB_CALLBACK ark_web_preference_is_load_image_from_network_disabled(
    struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->IsLoadImageFromNetworkDisabled();
}

void ARK_WEB_CALLBACK ark_web_preference_put_load_image_from_network_disabled(
    struct _ark_web_preference_t* self,
    bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutLoadImageFromNetworkDisabled(flag);
}

bool ARK_WEB_CALLBACK ark_web_preference_enable_raw_file_access_from_file_urls(
    struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->EnableRawFileAccessFromFileURLs();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_enable_raw_file_access_from_file_urls(
    struct _ark_web_preference_t* self,
    bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutEnableRawFileAccessFromFileURLs(flag);
}

bool ARK_WEB_CALLBACK ark_web_preference_enable_universal_access_from_file_urls(
    struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->EnableUniversalAccessFromFileURLs();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_enable_universal_access_from_file_urls(
    struct _ark_web_preference_t* self,
    bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutEnableUniversalAccessFromFileURLs(flag);
}

bool ARK_WEB_CALLBACK
ark_web_preference_is_create_windows_by_java_script_allowed(
    struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)
      ->IsCreateWindowsByJavaScriptAllowed();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_is_create_windows_by_java_script_allowed(
    struct _ark_web_preference_t* self,
    bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutIsCreateWindowsByJavaScriptAllowed(
      flag);
}

int ARK_WEB_CALLBACK
ark_web_preference_access_mode_for_secure_origin_load_from_insecure(
    struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)
      ->AccessModeForSecureOriginLoadFromInsecure();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_access_mode_for_secure_origin_load_from_insecure(
    struct _ark_web_preference_t* self,
    int mode) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)
      ->PutAccessModeForSecureOriginLoadFromInsecure(mode);
}

int ARK_WEB_CALLBACK
ark_web_preference_get_copy_option_mode(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->GetCopyOptionMode();
}

void ARK_WEB_CALLBACK
ark_web_preference_put_copy_option_mode(struct _ark_web_preference_t* self,
                                        int copyOption) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutCopyOptionMode(copyOption);
}

void ARK_WEB_CALLBACK
ark_web_preference_set_native_embed_mode(struct _ark_web_preference_t* self,
                                         bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->SetNativeEmbedMode(flag);
}

bool ARK_WEB_CALLBACK
ark_web_preference_get_native_embed_mode(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->GetNativeEmbedMode();
}

void ARK_WEB_CALLBACK ark_web_preference_register_native_embed_rule(
    struct _ark_web_preference_t* self,
    const ArkWebString* tag,
    const ArkWebString* type) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(tag, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(type, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->RegisterNativeEmbedRule(*tag, *type);
}

void ARK_WEB_CALLBACK
ark_web_preference_set_scrollable1(struct _ark_web_preference_t* self,
                                   bool enable) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->SetScrollable(enable);
}

bool ARK_WEB_CALLBACK
ark_web_preference_get_scrollable(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->GetScrollable();
}

void ARK_WEB_CALLBACK ark_web_preference_put_text_autosizing_enabled(
    struct _ark_web_preference_t* self,
    bool flag) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutTextAutosizingEnabled(flag);
}

void ARK_WEB_CALLBACK
ark_web_preference_set_viewport_enable(struct _ark_web_preference_t* self,
                                       bool enable) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->SetViewportEnable(enable);
}

void ARK_WEB_CALLBACK ark_web_preference_set_native_video_player_config(
    struct _ark_web_preference_t* self,
    bool enable,
    bool shouldOverlay) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->SetNativeVideoPlayerConfig(enable,
                                                                shouldOverlay);
}

ArkWebString ARK_WEB_CALLBACK
ark_web_preference_get_surface_id(struct _ark_web_preference_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebPreferenceCppToC::Get(self)->GetSurfaceId();
}

void ARK_WEB_CALLBACK
ark_web_preference_set_surface_id(struct _ark_web_preference_t* self,
                                  const ArkWebString* surfaceId) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(surfaceId, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->SetSurfaceId(*surfaceId);
}

void ARK_WEB_CALLBACK ark_web_preference_put_overlay_scrollbar_enabled(
    struct _ark_web_preference_t* self,
    bool enable) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutOverlayScrollbarEnabled(enable);
}

void ARK_WEB_CALLBACK
ark_web_preference_set_scrollable2(struct _ark_web_preference_t* self,
                                   bool enable,
                                   int32_t scrollType) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->SetScrollable(enable, scrollType);
}

void ARK_WEB_CALLBACK ark_web_preference_set_blur_on_keyboard_hide_mode(
    struct _ark_web_preference_t* self,
    int enable) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->SetBlurOnKeyboardHideMode(enable);
}

void ARK_WEB_CALLBACK ark_web_preference_put_web_media_avsession_enabled(
    struct _ark_web_preference_t* self,
    bool enable) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->PutWebMediaAVSessionEnabled(enable);
}

void ARK_WEB_CALLBACK
ark_web_preference_set_font_weight_scale(struct _ark_web_preference_t* self,
                                         float scale) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->SetFontWeightScale(scale);
}

void ARK_WEB_CALLBACK
ark_web_preference_set_intrinsic_size_enable(struct _ark_web_preference_t* self,
                                             bool enable) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->SetIntrinsicSizeEnable(enable);
}

void ARK_WEB_CALLBACK ark_web_preference_set_css_display_change_enabled(
    struct _ark_web_preference_t* self,
    bool enable) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->SetCssDisplayChangeEnabled(enable);
}

void ARK_WEB_CALLBACK ark_web_preference_set_bypass_vsync_condition(
    struct _ark_web_preference_t* self,
    int32_t condition) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->SetBypassVsyncCondition(condition);
}

void ARK_WEB_CALLBACK
ark_web_preference_set_gesture_focus_mode(struct _ark_web_preference_t* self,
                                          int32_t mode) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPreferenceCppToC::Get(self)->SetGestureFocusMode(mode);
}

}  // namespace

ArkWebPreferenceCppToC::ArkWebPreferenceCppToC() {
  GetStruct()->user_agent = ark_web_preference_user_agent;
  GetStruct()->put_user_agent = ark_web_preference_put_user_agent;
  GetStruct()->default_user_agent = ark_web_preference_default_user_agent;
  GetStruct()->cache_mode = ark_web_preference_cache_mode;
  GetStruct()->put_cache_mode = ark_web_preference_put_cache_mode;
  GetStruct()->is_network_blocked = ark_web_preference_is_network_blocked;
  GetStruct()->put_block_network = ark_web_preference_put_block_network;
  GetStruct()->get_scroll_bar_color = ark_web_preference_get_scroll_bar_color;
  GetStruct()->put_scroll_bar_color = ark_web_preference_put_scroll_bar_color;
  GetStruct()->get_overscroll_mode = ark_web_preference_get_overscroll_mode;
  GetStruct()->put_overscroll_mode = ark_web_preference_put_overscroll_mode;
  GetStruct()->default_font_size = ark_web_preference_default_font_size;
  GetStruct()->put_default_font_size = ark_web_preference_put_default_font_size;
  GetStruct()->get_pinch_smooth_mode = ark_web_preference_get_pinch_smooth_mode;
  GetStruct()->put_pinch_smooth_mode = ark_web_preference_put_pinch_smooth_mode;
  GetStruct()->is_data_base_enabled = ark_web_preference_is_data_base_enabled;
  GetStruct()->put_database_allowed = ark_web_preference_put_database_allowed;
  GetStruct()->is_multi_window_access =
      ark_web_preference_is_multi_window_access;
  GetStruct()->put_multi_window_access =
      ark_web_preference_put_multi_window_access;
  GetStruct()->is_java_script_allowed =
      ark_web_preference_is_java_script_allowed;
  GetStruct()->put_java_script_enabled =
      ark_web_preference_put_java_script_enabled;
  GetStruct()->dark_scheme_enabled = ark_web_preference_dark_scheme_enabled;
  GetStruct()->put_dark_scheme_enabled =
      ark_web_preference_put_dark_scheme_enabled;
  GetStruct()->is_dom_storage_enabled =
      ark_web_preference_is_dom_storage_enabled;
  GetStruct()->put_dom_storage_enabled =
      ark_web_preference_put_dom_storage_enabled;
  GetStruct()->font_size_lower_limit = ark_web_preference_font_size_lower_limit;
  GetStruct()->put_font_size_lower_limit =
      ark_web_preference_put_font_size_lower_limit;
  GetStruct()->geo_location_allowed = ark_web_preference_geo_location_allowed;
  GetStruct()->put_geo_location_allowed =
      ark_web_preference_put_geo_location_allowed;
  GetStruct()->is_web_debugging_access =
      ark_web_preference_is_web_debugging_access;
  GetStruct()->put_web_debugging_access =
      ark_web_preference_put_web_debugging_access;
  GetStruct()->enable_content_access = ark_web_preference_enable_content_access;
  GetStruct()->put_enable_content_access =
      ark_web_preference_put_enable_content_access;
  GetStruct()->enable_raw_file_access =
      ark_web_preference_enable_raw_file_access;
  GetStruct()->put_enable_raw_file_access =
      ark_web_preference_put_enable_raw_file_access;
  GetStruct()->is_image_loading_allowed =
      ark_web_preference_is_image_loading_allowed;
  GetStruct()->put_image_loading_allowed =
      ark_web_preference_put_image_loading_allowed;
  GetStruct()->fixed_font_family_name =
      ark_web_preference_fixed_font_family_name;
  GetStruct()->put_fixed_font_family_name =
      ark_web_preference_put_fixed_font_family_name;
  GetStruct()->serif_font_family_name =
      ark_web_preference_serif_font_family_name;
  GetStruct()->put_serif_font_family_name =
      ark_web_preference_put_serif_font_family_name;
  GetStruct()->zooming_for_text_factor =
      ark_web_preference_zooming_for_text_factor;
  GetStruct()->put_zooming_for_text_factor =
      ark_web_preference_put_zooming_for_text_factor;
  GetStruct()->force_dark_mode_enabled =
      ark_web_preference_force_dark_mode_enabled;
  GetStruct()->put_force_dark_mode_enabled =
      ark_web_preference_put_force_dark_mode_enabled;
  GetStruct()->is_load_with_overview_mode =
      ark_web_preference_is_load_with_overview_mode;
  GetStruct()->put_load_with_overview_mode =
      ark_web_preference_put_load_with_overview_mode;
  GetStruct()->default_fixed_font_size =
      ark_web_preference_default_fixed_font_size;
  GetStruct()->put_default_fixed_font_size =
      ark_web_preference_put_default_fixed_font_size;
  GetStruct()->cursive_font_family_name =
      ark_web_preference_cursive_font_family_name;
  GetStruct()->put_cursive_font_family_name =
      ark_web_preference_put_cursive_font_family_name;
  GetStruct()->fantasy_font_family_name =
      ark_web_preference_fantasy_font_family_name;
  GetStruct()->put_fantasy_font_family_name =
      ark_web_preference_put_fantasy_font_family_name;
  GetStruct()->zoomingfunction_enabled =
      ark_web_preference_zoomingfunction_enabled;
  GetStruct()->put_zooming_function_enabled =
      ark_web_preference_put_zooming_function_enabled;
  GetStruct()->get_media_play_gesture_access =
      ark_web_preference_get_media_play_gesture_access;
  GetStruct()->put_media_play_gesture_access =
      ark_web_preference_put_media_play_gesture_access;
  GetStruct()->standard_font_family_name =
      ark_web_preference_standard_font_family_name;
  GetStruct()->put_standard_font_family_name =
      ark_web_preference_put_standard_font_family_name;
  GetStruct()->sans_serif_font_family_name =
      ark_web_preference_sans_serif_font_family_name;
  GetStruct()->put_sans_serif_font_family_name =
      ark_web_preference_put_sans_serif_font_family_name;
  GetStruct()->is_vertical_scroll_bar_access =
      ark_web_preference_is_vertical_scroll_bar_access;
  GetStruct()->put_vertical_scroll_bar_access =
      ark_web_preference_put_vertical_scroll_bar_access;
  GetStruct()->is_horizontal_scroll_bar_access =
      ark_web_preference_is_horizontal_scroll_bar_access;
  GetStruct()->put_horizontal_scroll_bar_access =
      ark_web_preference_put_horizontal_scroll_bar_access;
  GetStruct()->logical_font_size_lower_limit =
      ark_web_preference_logical_font_size_lower_limit;
  GetStruct()->put_logical_font_size_lower_limit =
      ark_web_preference_put_logical_font_size_lower_limit;
  GetStruct()->default_text_encoding_format =
      ark_web_preference_default_text_encoding_format;
  GetStruct()->put_default_text_encoding_format =
      ark_web_preference_put_default_text_encoding_format;
  GetStruct()->is_load_image_from_network_disabled =
      ark_web_preference_is_load_image_from_network_disabled;
  GetStruct()->put_load_image_from_network_disabled =
      ark_web_preference_put_load_image_from_network_disabled;
  GetStruct()->enable_raw_file_access_from_file_urls =
      ark_web_preference_enable_raw_file_access_from_file_urls;
  GetStruct()->put_enable_raw_file_access_from_file_urls =
      ark_web_preference_put_enable_raw_file_access_from_file_urls;
  GetStruct()->enable_universal_access_from_file_urls =
      ark_web_preference_enable_universal_access_from_file_urls;
  GetStruct()->put_enable_universal_access_from_file_urls =
      ark_web_preference_put_enable_universal_access_from_file_urls;
  GetStruct()->is_create_windows_by_java_script_allowed =
      ark_web_preference_is_create_windows_by_java_script_allowed;
  GetStruct()->put_is_create_windows_by_java_script_allowed =
      ark_web_preference_put_is_create_windows_by_java_script_allowed;
  GetStruct()->access_mode_for_secure_origin_load_from_insecure =
      ark_web_preference_access_mode_for_secure_origin_load_from_insecure;
  GetStruct()->put_access_mode_for_secure_origin_load_from_insecure =
      ark_web_preference_put_access_mode_for_secure_origin_load_from_insecure;
  GetStruct()->get_copy_option_mode = ark_web_preference_get_copy_option_mode;
  GetStruct()->put_copy_option_mode = ark_web_preference_put_copy_option_mode;
  GetStruct()->set_native_embed_mode = ark_web_preference_set_native_embed_mode;
  GetStruct()->get_native_embed_mode = ark_web_preference_get_native_embed_mode;
  GetStruct()->register_native_embed_rule =
      ark_web_preference_register_native_embed_rule;
  GetStruct()->set_scrollable1 = ark_web_preference_set_scrollable1;
  GetStruct()->get_scrollable = ark_web_preference_get_scrollable;
  GetStruct()->put_text_autosizing_enabled =
      ark_web_preference_put_text_autosizing_enabled;
  GetStruct()->set_viewport_enable = ark_web_preference_set_viewport_enable;
  GetStruct()->set_native_video_player_config =
      ark_web_preference_set_native_video_player_config;
  GetStruct()->get_surface_id = ark_web_preference_get_surface_id;
  GetStruct()->set_surface_id = ark_web_preference_set_surface_id;
  GetStruct()->put_overlay_scrollbar_enabled =
      ark_web_preference_put_overlay_scrollbar_enabled;
  GetStruct()->set_scrollable2 = ark_web_preference_set_scrollable2;
  GetStruct()->set_blur_on_keyboard_hide_mode =
      ark_web_preference_set_blur_on_keyboard_hide_mode;
  GetStruct()->put_web_media_avsession_enabled =
      ark_web_preference_put_web_media_avsession_enabled;
  GetStruct()->set_font_weight_scale = ark_web_preference_set_font_weight_scale;
  GetStruct()->set_intrinsic_size_enable =
      ark_web_preference_set_intrinsic_size_enable;
  GetStruct()->set_css_display_change_enabled =
      ark_web_preference_set_css_display_change_enabled;
  GetStruct()->set_bypass_vsync_condition =
      ark_web_preference_set_bypass_vsync_condition;
  GetStruct()->set_gesture_focus_mode =
      ark_web_preference_set_gesture_focus_mode;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["rXi51bodseETHiACe7sKeA"] =
        reinterpret_cast<void*>(ark_web_preference_user_agent);
    funcMemberMap["m7ljdevdvg9SqvPs20qNiw"] =
        reinterpret_cast<void*>(ark_web_preference_put_user_agent);
    funcMemberMap["yWe1RfGewZGK9mFKvFtVDQ"] =
        reinterpret_cast<void*>(ark_web_preference_default_user_agent);
    funcMemberMap["IE3ulU7v9E5eSL_42Derwg"] =
        reinterpret_cast<void*>(ark_web_preference_cache_mode);
    funcMemberMap["z$RRF_RhHnVeoZux1nqgAw"] =
        reinterpret_cast<void*>(ark_web_preference_put_cache_mode);
    funcMemberMap["MQuFtT0oOwQ0PNhC65581w"] =
        reinterpret_cast<void*>(ark_web_preference_is_network_blocked);
    funcMemberMap["cRBGl3zl9_ljVS12DB4mBA"] =
        reinterpret_cast<void*>(ark_web_preference_put_block_network);
    funcMemberMap["_MOFW6C2N_eHGaF8vGGeBQ"] =
        reinterpret_cast<void*>(ark_web_preference_get_scroll_bar_color);
    funcMemberMap["Y46$qErU_nVWF1IZznQbPA"] =
        reinterpret_cast<void*>(ark_web_preference_put_scroll_bar_color);
    funcMemberMap["sC3bnqPyGmQ2SS9jokchTg"] =
        reinterpret_cast<void*>(ark_web_preference_get_overscroll_mode);
    funcMemberMap["bnuN7VaB9PNV0p3uBZ_$YQ"] =
        reinterpret_cast<void*>(ark_web_preference_put_overscroll_mode);
    funcMemberMap["Dsdr0XZpUx7UlY91XGTGfg"] =
        reinterpret_cast<void*>(ark_web_preference_default_font_size);
    funcMemberMap["IdJG8eaQr4PN4leCYrUKng"] =
        reinterpret_cast<void*>(ark_web_preference_put_default_font_size);
    funcMemberMap["ZFQ7fD9e7aP9$FfiRMIm7A"] =
        reinterpret_cast<void*>(ark_web_preference_get_pinch_smooth_mode);
    funcMemberMap["zEJJJv5cuQw3mRYlqsp64A"] =
        reinterpret_cast<void*>(ark_web_preference_put_pinch_smooth_mode);
    funcMemberMap["JlbQ88dzps80vv37ni2uWQ"] =
        reinterpret_cast<void*>(ark_web_preference_is_data_base_enabled);
    funcMemberMap["vS99FtTbPgTvD2$EV4S1qw"] =
        reinterpret_cast<void*>(ark_web_preference_put_database_allowed);
    funcMemberMap["tdM1Q060_nhCIj8diXY94w"] =
        reinterpret_cast<void*>(ark_web_preference_is_multi_window_access);
    funcMemberMap["Cykk6$zrLqKQxoTRIj8eMA"] =
        reinterpret_cast<void*>(ark_web_preference_put_multi_window_access);
    funcMemberMap["k7yaKOLe_Jlq_sQBWK2gAw"] =
        reinterpret_cast<void*>(ark_web_preference_is_java_script_allowed);
    funcMemberMap["lHEQk7H3pC48kWixoc4SyA"] =
        reinterpret_cast<void*>(ark_web_preference_put_java_script_enabled);
    funcMemberMap["jFSKHvF9_EdYpIuuF5xQXA"] =
        reinterpret_cast<void*>(ark_web_preference_dark_scheme_enabled);
    funcMemberMap["_8$GqJd__y4LVY6$T7OFGw"] =
        reinterpret_cast<void*>(ark_web_preference_put_dark_scheme_enabled);
    funcMemberMap["4k9P73g5F4sppxToAitBfw"] =
        reinterpret_cast<void*>(ark_web_preference_is_dom_storage_enabled);
    funcMemberMap["9LgV$dfEa0f7Pl99NdvQ0A"] =
        reinterpret_cast<void*>(ark_web_preference_put_dom_storage_enabled);
    funcMemberMap["99J2b9XTdkdrKhVGh2zwfw"] =
        reinterpret_cast<void*>(ark_web_preference_font_size_lower_limit);
    funcMemberMap["9rYAFV7GF8JaCREEOEZzUg"] =
        reinterpret_cast<void*>(ark_web_preference_put_font_size_lower_limit);
    funcMemberMap["zPeEbnaR8a5uUw_LIWYDOQ"] =
        reinterpret_cast<void*>(ark_web_preference_geo_location_allowed);
    funcMemberMap["bryMLYYMwZnc2QEvzevyxg"] =
        reinterpret_cast<void*>(ark_web_preference_put_geo_location_allowed);
    funcMemberMap["Zw$wRXBqhMgnZK$1JwSTIA"] =
        reinterpret_cast<void*>(ark_web_preference_is_web_debugging_access);
    funcMemberMap["noH5OgEpfcnw$VDVb8pufA"] =
        reinterpret_cast<void*>(ark_web_preference_put_web_debugging_access);
    funcMemberMap["GDbF1LKY2Ofv9u3aDqDY9g"] =
        reinterpret_cast<void*>(ark_web_preference_enable_content_access);
    funcMemberMap["JBFH9VAxMTQFPMvKnUAB3A"] =
        reinterpret_cast<void*>(ark_web_preference_put_enable_content_access);
    funcMemberMap["VEZGmZHIVa7pbsOlpI5DgQ"] =
        reinterpret_cast<void*>(ark_web_preference_enable_raw_file_access);
    funcMemberMap["sI6wGw8VBVYzMixx2F1jAg"] =
        reinterpret_cast<void*>(ark_web_preference_put_enable_raw_file_access);
    funcMemberMap["347maZQcIUowzmNOZWG47w"] =
        reinterpret_cast<void*>(ark_web_preference_is_image_loading_allowed);
    funcMemberMap["CWQDcjettsVDPlHd5_GLmQ"] =
        reinterpret_cast<void*>(ark_web_preference_put_image_loading_allowed);
    funcMemberMap["s2ACFVsH9vfNWHSMX1NaQQ"] =
        reinterpret_cast<void*>(ark_web_preference_fixed_font_family_name);
    funcMemberMap["q2jimt31oQENnrTfnBTt$Q"] =
        reinterpret_cast<void*>(ark_web_preference_put_fixed_font_family_name);
    funcMemberMap["jFCOEVzbI7YQ2Oj9_MvpQA"] =
        reinterpret_cast<void*>(ark_web_preference_serif_font_family_name);
    funcMemberMap["bM$7IslVJVyfjmE22YC4Xw"] =
        reinterpret_cast<void*>(ark_web_preference_put_serif_font_family_name);
    funcMemberMap["avCEZpmbeqlaw7IVVB0khg"] =
        reinterpret_cast<void*>(ark_web_preference_zooming_for_text_factor);
    funcMemberMap["A4erwzXJFpQfEz6OXCNbMA"] =
        reinterpret_cast<void*>(ark_web_preference_put_zooming_for_text_factor);
    funcMemberMap["NGP9ahkgvuYUxY_4i9kF2Q"] =
        reinterpret_cast<void*>(ark_web_preference_force_dark_mode_enabled);
    funcMemberMap["rPkt1TVleeDSackgdjgS0g"] =
        reinterpret_cast<void*>(ark_web_preference_put_force_dark_mode_enabled);
    funcMemberMap["zmSACv71uhcKPqoEnZD7YA"] =
        reinterpret_cast<void*>(ark_web_preference_is_load_with_overview_mode);
    funcMemberMap["3wQKJtp$sCf7Zcm0DtQcEQ"] =
        reinterpret_cast<void*>(ark_web_preference_put_load_with_overview_mode);
    funcMemberMap["Q88wOciyg38o7OHrkVLkng"] =
        reinterpret_cast<void*>(ark_web_preference_default_fixed_font_size);
    funcMemberMap["uc2Qe3$kpMt3hzCiHCmdrw"] =
        reinterpret_cast<void*>(ark_web_preference_put_default_fixed_font_size);
    funcMemberMap["nI4ZIJ$KKC1xVvDyNTjyVA"] =
        reinterpret_cast<void*>(ark_web_preference_cursive_font_family_name);
    funcMemberMap["Qpjuu1IobSaI1AeP2t542g"] = reinterpret_cast<void*>(
        ark_web_preference_put_cursive_font_family_name);
    funcMemberMap["KIKER0cJOYLTZYW7MacTWA"] =
        reinterpret_cast<void*>(ark_web_preference_fantasy_font_family_name);
    funcMemberMap["G$iBh8Se479p0palXPnHRg"] = reinterpret_cast<void*>(
        ark_web_preference_put_fantasy_font_family_name);
    funcMemberMap["eZUsdm6L9JuQbaz9orhRpA"] =
        reinterpret_cast<void*>(ark_web_preference_zoomingfunction_enabled);
    funcMemberMap["CnmpAcB_iW5uG45kvsmOrg"] = reinterpret_cast<void*>(
        ark_web_preference_put_zooming_function_enabled);
    funcMemberMap["hLkffq_zA46IsT5ow45igw"] = reinterpret_cast<void*>(
        ark_web_preference_get_media_play_gesture_access);
    funcMemberMap["enXmueZFPtimsS_kpjfh2w"] = reinterpret_cast<void*>(
        ark_web_preference_put_media_play_gesture_access);
    funcMemberMap["EjyBexXVDSwN2dOY64uKpQ"] =
        reinterpret_cast<void*>(ark_web_preference_standard_font_family_name);
    funcMemberMap["k0xgPAOTatFmKX51wN08VA"] = reinterpret_cast<void*>(
        ark_web_preference_put_standard_font_family_name);
    funcMemberMap["QVA5WFoYKfZkGBsIkyFtPg"] =
        reinterpret_cast<void*>(ark_web_preference_sans_serif_font_family_name);
    funcMemberMap["LGHHsLvnreiRuQ3TmpwCWw"] = reinterpret_cast<void*>(
        ark_web_preference_put_sans_serif_font_family_name);
    funcMemberMap["7qIyh212W7RNQrAnyYZ3QQ"] = reinterpret_cast<void*>(
        ark_web_preference_is_vertical_scroll_bar_access);
    funcMemberMap["JkZaG5bUvRq$eIVyXAdI4g"] = reinterpret_cast<void*>(
        ark_web_preference_put_vertical_scroll_bar_access);
    funcMemberMap["ETo_tKLnECMR5p1T9xpwGg"] = reinterpret_cast<void*>(
        ark_web_preference_is_horizontal_scroll_bar_access);
    funcMemberMap["aS1isSOxLdQR3Sc4AVVmYg"] = reinterpret_cast<void*>(
        ark_web_preference_put_horizontal_scroll_bar_access);
    funcMemberMap["b7znmYlnDxQKFUJJvC4uZA"] = reinterpret_cast<void*>(
        ark_web_preference_logical_font_size_lower_limit);
    funcMemberMap["3tEQyViTLUjC6AYCzsZRRg"] = reinterpret_cast<void*>(
        ark_web_preference_put_logical_font_size_lower_limit);
    funcMemberMap["T3rAR6rzPzahEmfdZnzROA"] = reinterpret_cast<void*>(
        ark_web_preference_default_text_encoding_format);
    funcMemberMap["XZ5yCx3FNkLXLZxZawMiqA"] = reinterpret_cast<void*>(
        ark_web_preference_put_default_text_encoding_format);
    funcMemberMap["c3Xr3wIMJU4$AV$j3lOa_A"] = reinterpret_cast<void*>(
        ark_web_preference_is_load_image_from_network_disabled);
    funcMemberMap["pLbfSzXTvsc0G5aF9uNIHg"] = reinterpret_cast<void*>(
        ark_web_preference_put_load_image_from_network_disabled);
    funcMemberMap["ox2U1wux9vK5_DcGXR3Ezw"] = reinterpret_cast<void*>(
        ark_web_preference_enable_raw_file_access_from_file_urls);
    funcMemberMap["gvRXqlSFQa86nLmXT5a1Iw"] = reinterpret_cast<void*>(
        ark_web_preference_put_enable_raw_file_access_from_file_urls);
    funcMemberMap["hqV5P27cjNfQneYQ_xwTYw"] = reinterpret_cast<void*>(
        ark_web_preference_enable_universal_access_from_file_urls);
    funcMemberMap["xKBaIDhszSGwrRTB1Ttgyg"] = reinterpret_cast<void*>(
        ark_web_preference_put_enable_universal_access_from_file_urls);
    funcMemberMap["WL1YsvfZoNci093D_biaiA"] = reinterpret_cast<void*>(
        ark_web_preference_is_create_windows_by_java_script_allowed);
    funcMemberMap["ltbD4dAQIRLQD0S27$cNCA"] = reinterpret_cast<void*>(
        ark_web_preference_put_is_create_windows_by_java_script_allowed);
    funcMemberMap["7T45zFCG__QqArzQB0UBKQ"] = reinterpret_cast<void*>(
        ark_web_preference_access_mode_for_secure_origin_load_from_insecure);
    funcMemberMap["QEBlds3i6C$Lyxn8gf8uMA"] = reinterpret_cast<void*>(
        ark_web_preference_put_access_mode_for_secure_origin_load_from_insecure);
    funcMemberMap["0YidsoUkee4$3j0qt8el9g"] =
        reinterpret_cast<void*>(ark_web_preference_get_copy_option_mode);
    funcMemberMap["V5I81PyCft3O9PuWEk2J4w"] =
        reinterpret_cast<void*>(ark_web_preference_put_copy_option_mode);
    funcMemberMap["kiT$cpXeY44E$EExfXY$mA"] =
        reinterpret_cast<void*>(ark_web_preference_set_native_embed_mode);
    funcMemberMap["2UYp0QTytbfqoPdiIGZ7mA"] =
        reinterpret_cast<void*>(ark_web_preference_get_native_embed_mode);
    funcMemberMap["66KIS8lkDDFVBW4XIS9GBA"] =
        reinterpret_cast<void*>(ark_web_preference_register_native_embed_rule);
    funcMemberMap["ouqRmf05ojQZncKa6jIgdQ"] =
        reinterpret_cast<void*>(ark_web_preference_set_scrollable1);
    funcMemberMap["MEnPmAv8bsPZGhE2OGY$EA"] =
        reinterpret_cast<void*>(ark_web_preference_get_scrollable);
    funcMemberMap["c3RZY5qWYFBBBdhz9AUbRQ"] =
        reinterpret_cast<void*>(ark_web_preference_put_text_autosizing_enabled);
    funcMemberMap["NFhQFVL6mhu2L6Bcb2LeCA"] =
        reinterpret_cast<void*>(ark_web_preference_set_viewport_enable);
    funcMemberMap["44fvEkOjRLHWlvmURbaFQg"] = reinterpret_cast<void*>(
        ark_web_preference_set_native_video_player_config);
    funcMemberMap["RJu92RFPvi4pO64IbX6KVQ"] =
        reinterpret_cast<void*>(ark_web_preference_get_surface_id);
    funcMemberMap["ZKt_GHyKLjdDUW3lO9eAFg"] =
        reinterpret_cast<void*>(ark_web_preference_set_surface_id);
    funcMemberMap["VbzEBXwlbirdXNe6L6we3A"] = reinterpret_cast<void*>(
        ark_web_preference_put_overlay_scrollbar_enabled);
    funcMemberMap["F3PnT7n1RA2IpBUI2irq$w"] =
        reinterpret_cast<void*>(ark_web_preference_set_scrollable2);
    funcMemberMap["w7PjvdmNeoCDTp66XAgcyQ"] = reinterpret_cast<void*>(
        ark_web_preference_set_blur_on_keyboard_hide_mode);
    funcMemberMap["vjmVwRWDdhrfj94qghVsLA"] = reinterpret_cast<void*>(
        ark_web_preference_put_web_media_avsession_enabled);
    funcMemberMap["psu8YK9gCa4UkGfaGBIGzA"] =
        reinterpret_cast<void*>(ark_web_preference_set_font_weight_scale);
    funcMemberMap["3tcYlxsahoTeAg6KfeRPuQ"] =
        reinterpret_cast<void*>(ark_web_preference_set_intrinsic_size_enable);
    funcMemberMap["EPwpgh39o_89s3KrbEVHoQ"] = reinterpret_cast<void*>(
        ark_web_preference_set_css_display_change_enabled);
    funcMemberMap["IvGKtJmpU4zju148T879CA"] =
        reinterpret_cast<void*>(ark_web_preference_set_bypass_vsync_condition);
    funcMemberMap["sUljeQn3vhodTnyIjlLF6g"] =
        reinterpret_cast<void*>(ark_web_preference_set_gesture_focus_mode);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_PREFERENCE, funcMemberMap);
  });
}

ArkWebPreferenceCppToC::~ArkWebPreferenceCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<ArkWebPreferenceCppToC,
                                        ArkWebPreference,
                                        ark_web_preference_t>::kBridgeType =
    ARK_WEB_PREFERENCE;

}  // namespace OHOS::ArkWeb
