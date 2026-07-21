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

#include "ohos_nweb/cpptoc/ark_web_native_embed_mouse_event_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"
#include "ohos_nweb/cpptoc/ark_web_mouse_event_result_cpptoc.h"

namespace OHOS::ArkWeb {

namespace {

float ARK_WEB_CALLBACK ark_web_native_embed_mouse_event_get_x(
    struct _ark_web_native_embed_mouse_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNativeEmbedMouseEventCppToC::Get(self)->GetX();
}

float ARK_WEB_CALLBACK ark_web_native_embed_mouse_event_get_y(
    struct _ark_web_native_embed_mouse_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNativeEmbedMouseEventCppToC::Get(self)->GetY();
}

bool ARK_WEB_CALLBACK ark_web_native_embed_mouse_event_is_hit_native_area(
    struct _ark_web_native_embed_mouse_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebNativeEmbedMouseEventCppToC::Get(self)->IsHitNativeArea();
}

size_t ARK_WEB_CALLBACK ark_web_native_embed_mouse_event_get_type(
    struct _ark_web_native_embed_mouse_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNativeEmbedMouseEventCppToC::Get(self)->GetType();
}

size_t ARK_WEB_CALLBACK ark_web_native_embed_mouse_event_get_button(
    struct _ark_web_native_embed_mouse_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNativeEmbedMouseEventCppToC::Get(self)->GetButton();
}

float ARK_WEB_CALLBACK ark_web_native_embed_mouse_event_get_offset_x(
    struct _ark_web_native_embed_mouse_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNativeEmbedMouseEventCppToC::Get(self)->GetOffsetX();
}

float ARK_WEB_CALLBACK ark_web_native_embed_mouse_event_get_offset_y(
    struct _ark_web_native_embed_mouse_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNativeEmbedMouseEventCppToC::Get(self)->GetOffsetY();
}

float ARK_WEB_CALLBACK ark_web_native_embed_mouse_event_get_screen_x(
    struct _ark_web_native_embed_mouse_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNativeEmbedMouseEventCppToC::Get(self)->GetScreenX();
}

float ARK_WEB_CALLBACK ark_web_native_embed_mouse_event_get_screen_y(
    struct _ark_web_native_embed_mouse_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNativeEmbedMouseEventCppToC::Get(self)->GetScreenY();
}

ArkWebString ARK_WEB_CALLBACK ark_web_native_embed_mouse_event_get_embed_id(
    struct _ark_web_native_embed_mouse_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebNativeEmbedMouseEventCppToC::Get(self)->GetEmbedId();
}

ark_web_mouse_event_result_t* ARK_WEB_CALLBACK
ark_web_native_embed_mouse_event_get_result(
    struct _ark_web_native_embed_mouse_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebMouseEventResult> _retval =
      ArkWebNativeEmbedMouseEventCppToC::Get(self)->GetResult();

  // Return type: refptr_same
  return ArkWebMouseEventResultCppToC::Invert(_retval);
}

}  // namespace

ArkWebNativeEmbedMouseEventCppToC::ArkWebNativeEmbedMouseEventCppToC() {
  GetStruct()->get_x = ark_web_native_embed_mouse_event_get_x;
  GetStruct()->get_y = ark_web_native_embed_mouse_event_get_y;
  GetStruct()->is_hit_native_area =
      ark_web_native_embed_mouse_event_is_hit_native_area;
  GetStruct()->get_type = ark_web_native_embed_mouse_event_get_type;
  GetStruct()->get_button = ark_web_native_embed_mouse_event_get_button;
  GetStruct()->get_offset_x = ark_web_native_embed_mouse_event_get_offset_x;
  GetStruct()->get_offset_y = ark_web_native_embed_mouse_event_get_offset_y;
  GetStruct()->get_screen_x = ark_web_native_embed_mouse_event_get_screen_x;
  GetStruct()->get_screen_y = ark_web_native_embed_mouse_event_get_screen_y;
  GetStruct()->get_embed_id = ark_web_native_embed_mouse_event_get_embed_id;
  GetStruct()->get_result = ark_web_native_embed_mouse_event_get_result;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["Suok9mjH5UuDdhrqBGuZNA"] =
        reinterpret_cast<void*>(ark_web_native_embed_mouse_event_get_x);
    funcMemberMap["$5RKN96XmfdHckvjhSkwQg"] =
        reinterpret_cast<void*>(ark_web_native_embed_mouse_event_get_y);
    funcMemberMap["dor01dTMcbXJ_qcXI$571A"] = reinterpret_cast<void*>(
        ark_web_native_embed_mouse_event_is_hit_native_area);
    funcMemberMap["GVQFJXUgM35PFdwkkCGzew"] =
        reinterpret_cast<void*>(ark_web_native_embed_mouse_event_get_type);
    funcMemberMap["h7xU32yu$lAwZvXCat5UfQ"] =
        reinterpret_cast<void*>(ark_web_native_embed_mouse_event_get_button);
    funcMemberMap["mSdVSkHxvkWCouPooHzcEQ"] =
        reinterpret_cast<void*>(ark_web_native_embed_mouse_event_get_offset_x);
    funcMemberMap["NS1lP8MiTk9BUpuEaRwP_A"] =
        reinterpret_cast<void*>(ark_web_native_embed_mouse_event_get_offset_y);
    funcMemberMap["Xy8vMLNAlXEbLBY0PfAiSw"] =
        reinterpret_cast<void*>(ark_web_native_embed_mouse_event_get_screen_x);
    funcMemberMap["jjBJ7$D3Ij6wvb$MXJHteQ"] =
        reinterpret_cast<void*>(ark_web_native_embed_mouse_event_get_screen_y);
    funcMemberMap["0HDEr8wLL2R793oxJFVtZA"] =
        reinterpret_cast<void*>(ark_web_native_embed_mouse_event_get_embed_id);
    funcMemberMap["eWQTVMecGBSdg2X7gPVDKg"] =
        reinterpret_cast<void*>(ark_web_native_embed_mouse_event_get_result);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_NATIVE_EMBED_MOUSE_EVENT, funcMemberMap);
  });
}

ArkWebNativeEmbedMouseEventCppToC::~ArkWebNativeEmbedMouseEventCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebNativeEmbedMouseEventCppToC,
                           ArkWebNativeEmbedMouseEvent,
                           ark_web_native_embed_mouse_event_t>::kBridgeType =
        ARK_WEB_NATIVE_EMBED_MOUSE_EVENT;

}  // namespace OHOS::ArkWeb
