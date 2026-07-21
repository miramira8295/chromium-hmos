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

#include "ohos_nweb/cpptoc/ark_web_cursor_info_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

int32_t ARK_WEB_CALLBACK
ark_web_cursor_info_get_x(struct _ark_web_cursor_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebCursorInfoCppToC::Get(self)->GetX();
}

int32_t ARK_WEB_CALLBACK
ark_web_cursor_info_get_y(struct _ark_web_cursor_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebCursorInfoCppToC::Get(self)->GetY();
}

uint8_t* ARK_WEB_CALLBACK
ark_web_cursor_info_get_buff(struct _ark_web_cursor_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  return ArkWebCursorInfoCppToC::Get(self)->GetBuff();
}

float ARK_WEB_CALLBACK
ark_web_cursor_info_get_scale(struct _ark_web_cursor_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebCursorInfoCppToC::Get(self)->GetScale();
}

int32_t ARK_WEB_CALLBACK
ark_web_cursor_info_get_width(struct _ark_web_cursor_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebCursorInfoCppToC::Get(self)->GetWidth();
}

int32_t ARK_WEB_CALLBACK
ark_web_cursor_info_get_height(struct _ark_web_cursor_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebCursorInfoCppToC::Get(self)->GetHeight();
}

}  // namespace

ArkWebCursorInfoCppToC::ArkWebCursorInfoCppToC() {
  GetStruct()->get_x = ark_web_cursor_info_get_x;
  GetStruct()->get_y = ark_web_cursor_info_get_y;
  GetStruct()->get_buff = ark_web_cursor_info_get_buff;
  GetStruct()->get_scale = ark_web_cursor_info_get_scale;
  GetStruct()->get_width = ark_web_cursor_info_get_width;
  GetStruct()->get_height = ark_web_cursor_info_get_height;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["jO$a$LsiOY9P5de5zx2pcg"] =
        reinterpret_cast<void*>(ark_web_cursor_info_get_x);
    funcMemberMap["lX$082EYJfeU6rv_wT3jKw"] =
        reinterpret_cast<void*>(ark_web_cursor_info_get_y);
    funcMemberMap["toI4vnewy4zEIjopqXiWiw"] =
        reinterpret_cast<void*>(ark_web_cursor_info_get_buff);
    funcMemberMap["dX$rB8GW1Tiq2SbrPMAEOA"] =
        reinterpret_cast<void*>(ark_web_cursor_info_get_scale);
    funcMemberMap["ubEUHz0EHNrlIHFVh78zaQ"] =
        reinterpret_cast<void*>(ark_web_cursor_info_get_width);
    funcMemberMap["0Jw$MPBxQn9JWjlb_lb0hQ"] =
        reinterpret_cast<void*>(ark_web_cursor_info_get_height);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_CURSOR_INFO, funcMemberMap);
  });
}

ArkWebCursorInfoCppToC::~ArkWebCursorInfoCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<ArkWebCursorInfoCppToC,
                                        ArkWebCursorInfo,
                                        ark_web_cursor_info_t>::kBridgeType =
    ARK_WEB_CURSOR_INFO;

}  // namespace OHOS::ArkWeb
