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

#include "ohos_adapter/ctocpp/ark_video_capture_range_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkVideoCaptureRangeAdapterGetMinFunc =
    double (*)(struct _ark_video_capture_range_adapter_t* self);
static ArkVideoCaptureRangeAdapterGetMinFunc
    ark_video_capture_range_adapter_get_min =
        reinterpret_cast<ArkVideoCaptureRangeAdapterGetMinFunc>(
            ARK_WEB_INIT_ADDR);

using ArkVideoCaptureRangeAdapterGetMaxFunc =
    double (*)(struct _ark_video_capture_range_adapter_t* self);
static ArkVideoCaptureRangeAdapterGetMaxFunc
    ark_video_capture_range_adapter_get_max =
        reinterpret_cast<ArkVideoCaptureRangeAdapterGetMaxFunc>(
            ARK_WEB_INIT_ADDR);

using ArkVideoCaptureRangeAdapterGetStepFunc =
    double (*)(struct _ark_video_capture_range_adapter_t* self);
static ArkVideoCaptureRangeAdapterGetStepFunc
    ark_video_capture_range_adapter_get_step =
        reinterpret_cast<ArkVideoCaptureRangeAdapterGetStepFunc>(
            ARK_WEB_INIT_ADDR);

using ArkVideoCaptureRangeAdapterGetCurrentFunc =
    double (*)(struct _ark_video_capture_range_adapter_t* self);
static ArkVideoCaptureRangeAdapterGetCurrentFunc
    ark_video_capture_range_adapter_get_current =
        reinterpret_cast<ArkVideoCaptureRangeAdapterGetCurrentFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
double ArkVideoCaptureRangeAdapterCToCpp::GetMin() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_video_capture_range_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_video_capture_range_adapter_get_min);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "$SULYRC6qbxp_ImIGN6xYw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_VIDEO_CAPTURE_RANGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_video_capture_range_adapter_get_min");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_min)) {
        ark_video_capture_range_adapter_get_min = nullptr;
      } else {
        ark_video_capture_range_adapter_get_min = _struct->get_min;
      }
    } else {
      ark_video_capture_range_adapter_get_min =
          reinterpret_cast<ArkVideoCaptureRangeAdapterGetMinFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_video_capture_range_adapter_get_min, 0);

  // Execute
  return ark_video_capture_range_adapter_get_min(_struct);
}

ARK_WEB_NO_SANITIZE
double ArkVideoCaptureRangeAdapterCToCpp::GetMax() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_video_capture_range_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_video_capture_range_adapter_get_max);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "1MOY7cxCpY8VFqAWez21bg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_VIDEO_CAPTURE_RANGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_video_capture_range_adapter_get_max");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_max)) {
        ark_video_capture_range_adapter_get_max = nullptr;
      } else {
        ark_video_capture_range_adapter_get_max = _struct->get_max;
      }
    } else {
      ark_video_capture_range_adapter_get_max =
          reinterpret_cast<ArkVideoCaptureRangeAdapterGetMaxFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_video_capture_range_adapter_get_max, 0);

  // Execute
  return ark_video_capture_range_adapter_get_max(_struct);
}

ARK_WEB_NO_SANITIZE
double ArkVideoCaptureRangeAdapterCToCpp::GetStep() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_video_capture_range_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_video_capture_range_adapter_get_step);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "yE_WxmKsbi2arzKMsY4zZw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_VIDEO_CAPTURE_RANGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_video_capture_range_adapter_get_step");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_step)) {
        ark_video_capture_range_adapter_get_step = nullptr;
      } else {
        ark_video_capture_range_adapter_get_step = _struct->get_step;
      }
    } else {
      ark_video_capture_range_adapter_get_step =
          reinterpret_cast<ArkVideoCaptureRangeAdapterGetStepFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_video_capture_range_adapter_get_step,
                                    0);

  // Execute
  return ark_video_capture_range_adapter_get_step(_struct);
}

ARK_WEB_NO_SANITIZE
double ArkVideoCaptureRangeAdapterCToCpp::GetCurrent() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_video_capture_range_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_video_capture_range_adapter_get_current);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "GY2thLWBXtV_aVBEIz4KBQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_VIDEO_CAPTURE_RANGE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_video_capture_range_adapter_get_current");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_current)) {
        ark_video_capture_range_adapter_get_current = nullptr;
      } else {
        ark_video_capture_range_adapter_get_current = _struct->get_current;
      }
    } else {
      ark_video_capture_range_adapter_get_current =
          reinterpret_cast<ArkVideoCaptureRangeAdapterGetCurrentFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_video_capture_range_adapter_get_current,
                                    0);

  // Execute
  return ark_video_capture_range_adapter_get_current(_struct);
}

ArkVideoCaptureRangeAdapterCToCpp::ArkVideoCaptureRangeAdapterCToCpp() {}

ArkVideoCaptureRangeAdapterCToCpp::~ArkVideoCaptureRangeAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkVideoCaptureRangeAdapterCToCpp,
                           ArkVideoCaptureRangeAdapter,
                           ark_video_capture_range_adapter_t>::kBridgeType =
        ARK_VIDEO_CAPTURE_RANGE_ADAPTER;

}  // namespace OHOS::ArkWeb
