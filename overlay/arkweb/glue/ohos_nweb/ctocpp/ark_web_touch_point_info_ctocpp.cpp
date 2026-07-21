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

#include "ohos_nweb/ctocpp/ark_web_touch_point_info_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebTouchPointInfoGetIdFunc =
    int (*)(struct _ark_web_touch_point_info_t* self);
static ArkWebTouchPointInfoGetIdFunc ark_web_touch_point_info_get_id =
    reinterpret_cast<ArkWebTouchPointInfoGetIdFunc>(ARK_WEB_INIT_ADDR);

using ArkWebTouchPointInfoGetXFunc =
    double (*)(struct _ark_web_touch_point_info_t* self);
static ArkWebTouchPointInfoGetXFunc ark_web_touch_point_info_get_x =
    reinterpret_cast<ArkWebTouchPointInfoGetXFunc>(ARK_WEB_INIT_ADDR);

using ArkWebTouchPointInfoGetYFunc =
    double (*)(struct _ark_web_touch_point_info_t* self);
static ArkWebTouchPointInfoGetYFunc ark_web_touch_point_info_get_y =
    reinterpret_cast<ArkWebTouchPointInfoGetYFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int ArkWebTouchPointInfoCToCpp::GetId() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_touch_point_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_web_touch_point_info_get_id);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "PRfLg38qhuyOSzCct4oiwg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_TOUCH_POINT_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_touch_point_info_get_id");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_id)) {
        ark_web_touch_point_info_get_id = nullptr;
      } else {
        ark_web_touch_point_info_get_id = _struct->get_id;
      }
    } else {
      ark_web_touch_point_info_get_id =
          reinterpret_cast<ArkWebTouchPointInfoGetIdFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_touch_point_info_get_id, 0);

  // Execute
  return ark_web_touch_point_info_get_id(_struct);
}

ARK_WEB_NO_SANITIZE
double ArkWebTouchPointInfoCToCpp::GetX() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_touch_point_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_web_touch_point_info_get_x);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "iq7xiK3aHSi1nx16bNG7UA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_TOUCH_POINT_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_touch_point_info_get_x");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_x)) {
        ark_web_touch_point_info_get_x = nullptr;
      } else {
        ark_web_touch_point_info_get_x = _struct->get_x;
      }
    } else {
      ark_web_touch_point_info_get_x =
          reinterpret_cast<ArkWebTouchPointInfoGetXFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_touch_point_info_get_x, 0);

  // Execute
  return ark_web_touch_point_info_get_x(_struct);
}

ARK_WEB_NO_SANITIZE
double ArkWebTouchPointInfoCToCpp::GetY() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_touch_point_info_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_web_touch_point_info_get_y);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "aWgrPq6sli6gn35xcVPNkQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_TOUCH_POINT_INFO, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_touch_point_info_get_y");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_y)) {
        ark_web_touch_point_info_get_y = nullptr;
      } else {
        ark_web_touch_point_info_get_y = _struct->get_y;
      }
    } else {
      ark_web_touch_point_info_get_y =
          reinterpret_cast<ArkWebTouchPointInfoGetYFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_touch_point_info_get_y, 0);

  // Execute
  return ark_web_touch_point_info_get_y(_struct);
}

ArkWebTouchPointInfoCToCpp::ArkWebTouchPointInfoCToCpp() {}

ArkWebTouchPointInfoCToCpp::~ArkWebTouchPointInfoCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkWebTouchPointInfoCToCpp,
                           ArkWebTouchPointInfo,
                           ark_web_touch_point_info_t>::kBridgeType =
        ARK_WEB_TOUCH_POINT_INFO;

}  // namespace OHOS::ArkWeb
