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

#include "ohos_nweb/cpptoc/ark_web_native_embed_touch_event_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"
#include "ohos_nweb/cpptoc/ark_web_gesture_event_result_cpptoc.h"

namespace OHOS::ArkWeb {

namespace {

float ARK_WEB_CALLBACK ark_web_native_embed_touch_event_get_x(
    struct _ark_web_native_embed_touch_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNativeEmbedTouchEventCppToC::Get(self)->GetX();
}

float ARK_WEB_CALLBACK ark_web_native_embed_touch_event_get_y(
    struct _ark_web_native_embed_touch_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNativeEmbedTouchEventCppToC::Get(self)->GetY();
}

int32_t ARK_WEB_CALLBACK ark_web_native_embed_touch_event_get_id(
    struct _ark_web_native_embed_touch_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNativeEmbedTouchEventCppToC::Get(self)->GetId();
}

size_t ARK_WEB_CALLBACK ark_web_native_embed_touch_event_get_type(
    struct _ark_web_native_embed_touch_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNativeEmbedTouchEventCppToC::Get(self)->GetType();
}

float ARK_WEB_CALLBACK ark_web_native_embed_touch_event_get_offset_x(
    struct _ark_web_native_embed_touch_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNativeEmbedTouchEventCppToC::Get(self)->GetOffsetX();
}

float ARK_WEB_CALLBACK ark_web_native_embed_touch_event_get_offset_y(
    struct _ark_web_native_embed_touch_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNativeEmbedTouchEventCppToC::Get(self)->GetOffsetY();
}

float ARK_WEB_CALLBACK ark_web_native_embed_touch_event_get_screen_x(
    struct _ark_web_native_embed_touch_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNativeEmbedTouchEventCppToC::Get(self)->GetScreenX();
}

float ARK_WEB_CALLBACK ark_web_native_embed_touch_event_get_screen_y(
    struct _ark_web_native_embed_touch_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNativeEmbedTouchEventCppToC::Get(self)->GetScreenY();
}

ArkWebString ARK_WEB_CALLBACK ark_web_native_embed_touch_event_get_embed_id(
    struct _ark_web_native_embed_touch_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebNativeEmbedTouchEventCppToC::Get(self)->GetEmbedId();
}

ark_web_gesture_event_result_t* ARK_WEB_CALLBACK
ark_web_native_embed_touch_event_get_result(
    struct _ark_web_native_embed_touch_event_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebGestureEventResult> _retval =
      ArkWebNativeEmbedTouchEventCppToC::Get(self)->GetResult();

  // Return type: refptr_same
  return ArkWebGestureEventResultCppToC::Invert(_retval);
}

}  // namespace

ArkWebNativeEmbedTouchEventCppToC::ArkWebNativeEmbedTouchEventCppToC() {
  GetStruct()->get_x = ark_web_native_embed_touch_event_get_x;
  GetStruct()->get_y = ark_web_native_embed_touch_event_get_y;
  GetStruct()->get_id = ark_web_native_embed_touch_event_get_id;
  GetStruct()->get_type = ark_web_native_embed_touch_event_get_type;
  GetStruct()->get_offset_x = ark_web_native_embed_touch_event_get_offset_x;
  GetStruct()->get_offset_y = ark_web_native_embed_touch_event_get_offset_y;
  GetStruct()->get_screen_x = ark_web_native_embed_touch_event_get_screen_x;
  GetStruct()->get_screen_y = ark_web_native_embed_touch_event_get_screen_y;
  GetStruct()->get_embed_id = ark_web_native_embed_touch_event_get_embed_id;
  GetStruct()->get_result = ark_web_native_embed_touch_event_get_result;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["yL1vjZwpDRQYO$IuFLb$WQ"] =
        reinterpret_cast<void*>(ark_web_native_embed_touch_event_get_x);
    funcMemberMap["geaGUlVI$m9hicsJGe7bYw"] =
        reinterpret_cast<void*>(ark_web_native_embed_touch_event_get_y);
    funcMemberMap["Gu36OAU_T3$rnTg5giQ_sw"] =
        reinterpret_cast<void*>(ark_web_native_embed_touch_event_get_id);
    funcMemberMap["UgGbfA_ovaoJbYvSti_bbQ"] =
        reinterpret_cast<void*>(ark_web_native_embed_touch_event_get_type);
    funcMemberMap["mlBwEHKq8I6oZlkvATSVDg"] =
        reinterpret_cast<void*>(ark_web_native_embed_touch_event_get_offset_x);
    funcMemberMap["u2SV6QxKFbKkm9AW1lCEbg"] =
        reinterpret_cast<void*>(ark_web_native_embed_touch_event_get_offset_y);
    funcMemberMap["9u9vLfIQvHd72g0_0aYxuw"] =
        reinterpret_cast<void*>(ark_web_native_embed_touch_event_get_screen_x);
    funcMemberMap["pkrEtALsTwY5B6O1HtVpYA"] =
        reinterpret_cast<void*>(ark_web_native_embed_touch_event_get_screen_y);
    funcMemberMap["KhJ2QO3ziUKL94QMCSIl9A"] =
        reinterpret_cast<void*>(ark_web_native_embed_touch_event_get_embed_id);
    funcMemberMap["GYDCzherRf5GuVuqIGm8pQ"] =
        reinterpret_cast<void*>(ark_web_native_embed_touch_event_get_result);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_NATIVE_EMBED_TOUCH_EVENT, funcMemberMap);
  });
}

ArkWebNativeEmbedTouchEventCppToC::~ArkWebNativeEmbedTouchEventCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebNativeEmbedTouchEventCppToC,
                           ArkWebNativeEmbedTouchEvent,
                           ark_web_native_embed_touch_event_t>::kBridgeType =
        ARK_WEB_NATIVE_EMBED_TOUCH_EVENT;

}  // namespace OHOS::ArkWeb
