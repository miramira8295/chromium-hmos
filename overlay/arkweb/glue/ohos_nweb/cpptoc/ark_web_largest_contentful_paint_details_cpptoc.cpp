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

#include "ohos_nweb/cpptoc/ark_web_largest_contentful_paint_details_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

int64_t ARK_WEB_CALLBACK
ark_web_largest_contentful_paint_details_get_navigation_start_time(
    struct _ark_web_largest_contentful_paint_details_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebLargestContentfulPaintDetailsCppToC::Get(self)
      ->GetNavigationStartTime();
}

int64_t ARK_WEB_CALLBACK
ark_web_largest_contentful_paint_details_get_largest_image_paint_time(
    struct _ark_web_largest_contentful_paint_details_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebLargestContentfulPaintDetailsCppToC::Get(self)
      ->GetLargestImagePaintTime();
}

int64_t ARK_WEB_CALLBACK
ark_web_largest_contentful_paint_details_get_largest_text_paint_time(
    struct _ark_web_largest_contentful_paint_details_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebLargestContentfulPaintDetailsCppToC::Get(self)
      ->GetLargestTextPaintTime();
}

int64_t ARK_WEB_CALLBACK
ark_web_largest_contentful_paint_details_get_largest_image_load_start_time(
    struct _ark_web_largest_contentful_paint_details_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebLargestContentfulPaintDetailsCppToC::Get(self)
      ->GetLargestImageLoadStartTime();
}

int64_t ARK_WEB_CALLBACK
ark_web_largest_contentful_paint_details_get_largest_image_load_end_time(
    struct _ark_web_largest_contentful_paint_details_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebLargestContentfulPaintDetailsCppToC::Get(self)
      ->GetLargestImageLoadEndTime();
}

double_t ARK_WEB_CALLBACK
ark_web_largest_contentful_paint_details_get_image_bpp(
    struct _ark_web_largest_contentful_paint_details_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebLargestContentfulPaintDetailsCppToC::Get(self)->GetImageBPP();
}

}  // namespace

ArkWebLargestContentfulPaintDetailsCppToC::
    ArkWebLargestContentfulPaintDetailsCppToC() {
  GetStruct()->get_navigation_start_time =
      ark_web_largest_contentful_paint_details_get_navigation_start_time;
  GetStruct()->get_largest_image_paint_time =
      ark_web_largest_contentful_paint_details_get_largest_image_paint_time;
  GetStruct()->get_largest_text_paint_time =
      ark_web_largest_contentful_paint_details_get_largest_text_paint_time;
  GetStruct()->get_largest_image_load_start_time =
      ark_web_largest_contentful_paint_details_get_largest_image_load_start_time;
  GetStruct()->get_largest_image_load_end_time =
      ark_web_largest_contentful_paint_details_get_largest_image_load_end_time;
  GetStruct()->get_image_bpp =
      ark_web_largest_contentful_paint_details_get_image_bpp;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["9UEfxm0eEtxtcm4XdNk6bA"] = reinterpret_cast<void*>(
        ark_web_largest_contentful_paint_details_get_navigation_start_time);
    funcMemberMap["rKNwM5a5vldLx_N7SL8bhw"] = reinterpret_cast<void*>(
        ark_web_largest_contentful_paint_details_get_largest_image_paint_time);
    funcMemberMap["uSqHxgwZfnZpn5RUxQLhIw"] = reinterpret_cast<void*>(
        ark_web_largest_contentful_paint_details_get_largest_text_paint_time);
    funcMemberMap["tmvMzR711gqpS9OEic3GMg"] = reinterpret_cast<void*>(
        ark_web_largest_contentful_paint_details_get_largest_image_load_start_time);
    funcMemberMap["5kmBU1vf49xi1sU2gagcrw"] = reinterpret_cast<void*>(
        ark_web_largest_contentful_paint_details_get_largest_image_load_end_time);
    funcMemberMap["HOk32TfOtFfBQSv8lOWGLQ"] = reinterpret_cast<void*>(
        ark_web_largest_contentful_paint_details_get_image_bpp);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_LARGEST_CONTENTFUL_PAINT_DETAILS, funcMemberMap);
  });
}

ArkWebLargestContentfulPaintDetailsCppToC::
    ~ArkWebLargestContentfulPaintDetailsCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<
    ArkWebLargestContentfulPaintDetailsCppToC,
    ArkWebLargestContentfulPaintDetails,
    ark_web_largest_contentful_paint_details_t>::kBridgeType =
    ARK_WEB_LARGEST_CONTENTFUL_PAINT_DETAILS;

}  // namespace OHOS::ArkWeb
