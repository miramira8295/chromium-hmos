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

#include "ohos_adapter/ctocpp/ark_video_device_descriptor_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/ctocpp/ark_video_control_support_adapter_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkVideoDeviceDescriptorAdapterGetDisplayNameFunc =
    ArkWebString (*)(struct _ark_video_device_descriptor_adapter_t* self);
static ArkVideoDeviceDescriptorAdapterGetDisplayNameFunc
    ark_video_device_descriptor_adapter_get_display_name =
        reinterpret_cast<ArkVideoDeviceDescriptorAdapterGetDisplayNameFunc>(
            ARK_WEB_INIT_ADDR);

using ArkVideoDeviceDescriptorAdapterGetDeviceIdFunc =
    ArkWebString (*)(struct _ark_video_device_descriptor_adapter_t* self);
static ArkVideoDeviceDescriptorAdapterGetDeviceIdFunc
    ark_video_device_descriptor_adapter_get_device_id =
        reinterpret_cast<ArkVideoDeviceDescriptorAdapterGetDeviceIdFunc>(
            ARK_WEB_INIT_ADDR);

using ArkVideoDeviceDescriptorAdapterGetModelIdFunc =
    ArkWebString (*)(struct _ark_video_device_descriptor_adapter_t* self);
static ArkVideoDeviceDescriptorAdapterGetModelIdFunc
    ark_video_device_descriptor_adapter_get_model_id =
        reinterpret_cast<ArkVideoDeviceDescriptorAdapterGetModelIdFunc>(
            ARK_WEB_INIT_ADDR);

using ArkVideoDeviceDescriptorAdapterGetControlSupportFunc =
    ark_video_control_support_adapter_t* (*)(struct
                                             _ark_video_device_descriptor_adapter_t*
                                                 self);
static ArkVideoDeviceDescriptorAdapterGetControlSupportFunc
    ark_video_device_descriptor_adapter_get_control_support =
        reinterpret_cast<ArkVideoDeviceDescriptorAdapterGetControlSupportFunc>(
            ARK_WEB_INIT_ADDR);

using ArkVideoDeviceDescriptorAdapterGetTransportTypeFunc =
    int32_t (*)(struct _ark_video_device_descriptor_adapter_t* self);
static ArkVideoDeviceDescriptorAdapterGetTransportTypeFunc
    ark_video_device_descriptor_adapter_get_transport_type =
        reinterpret_cast<ArkVideoDeviceDescriptorAdapterGetTransportTypeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkVideoDeviceDescriptorAdapterGetFacingModeFunc =
    int32_t (*)(struct _ark_video_device_descriptor_adapter_t* self);
static ArkVideoDeviceDescriptorAdapterGetFacingModeFunc
    ark_video_device_descriptor_adapter_get_facing_mode =
        reinterpret_cast<ArkVideoDeviceDescriptorAdapterGetFacingModeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkVideoDeviceDescriptorAdapterGetSupportCaptureFormatsFunc =
    ArkFormatAdapterVector (*)(
        struct _ark_video_device_descriptor_adapter_t* self);
static ArkVideoDeviceDescriptorAdapterGetSupportCaptureFormatsFunc
    ark_video_device_descriptor_adapter_get_support_capture_formats =
        reinterpret_cast<
            ArkVideoDeviceDescriptorAdapterGetSupportCaptureFormatsFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
ArkWebString ArkVideoDeviceDescriptorAdapterCToCpp::GetDisplayName() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_video_device_descriptor_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_video_device_descriptor_adapter_get_display_name);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "KTIhFCvFHJEL3YNuZP560w";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_VIDEO_DEVICE_DESCRIPTOR_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_video_device_descriptor_adapter_get_display_name");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_display_name)) {
        ark_video_device_descriptor_adapter_get_display_name = nullptr;
      } else {
        ark_video_device_descriptor_adapter_get_display_name =
            _struct->get_display_name;
      }
    } else {
      ark_video_device_descriptor_adapter_get_display_name =
          reinterpret_cast<ArkVideoDeviceDescriptorAdapterGetDisplayNameFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_video_device_descriptor_adapter_get_display_name,
      ark_web_string_default);

  // Execute
  return ark_video_device_descriptor_adapter_get_display_name(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkVideoDeviceDescriptorAdapterCToCpp::GetDeviceId() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_video_device_descriptor_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_video_device_descriptor_adapter_get_device_id);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "egImIZ3MWPpAJIPWdriPPA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_VIDEO_DEVICE_DESCRIPTOR_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_video_device_descriptor_adapter_get_device_id");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_device_id)) {
        ark_video_device_descriptor_adapter_get_device_id = nullptr;
      } else {
        ark_video_device_descriptor_adapter_get_device_id =
            _struct->get_device_id;
      }
    } else {
      ark_video_device_descriptor_adapter_get_device_id =
          reinterpret_cast<ArkVideoDeviceDescriptorAdapterGetDeviceIdFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_video_device_descriptor_adapter_get_device_id,
      ark_web_string_default);

  // Execute
  return ark_video_device_descriptor_adapter_get_device_id(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkVideoDeviceDescriptorAdapterCToCpp::GetModelId() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_video_device_descriptor_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_video_device_descriptor_adapter_get_model_id);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "yJCaP$q0wufhwhIRRSMghw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_VIDEO_DEVICE_DESCRIPTOR_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_video_device_descriptor_adapter_get_model_id");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_model_id)) {
        ark_video_device_descriptor_adapter_get_model_id = nullptr;
      } else {
        ark_video_device_descriptor_adapter_get_model_id =
            _struct->get_model_id;
      }
    } else {
      ark_video_device_descriptor_adapter_get_model_id =
          reinterpret_cast<ArkVideoDeviceDescriptorAdapterGetModelIdFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_video_device_descriptor_adapter_get_model_id, ark_web_string_default);

  // Execute
  return ark_video_device_descriptor_adapter_get_model_id(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkVideoControlSupportAdapter>
ArkVideoDeviceDescriptorAdapterCToCpp::GetControlSupport() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_video_device_descriptor_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_video_device_descriptor_adapter_get_control_support);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "DT4FvgIHw9pCG38EqWI9Gw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_VIDEO_DEVICE_DESCRIPTOR_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_video_device_descriptor_adapter_get_control_support");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_control_support)) {
        ark_video_device_descriptor_adapter_get_control_support = nullptr;
      } else {
        ark_video_device_descriptor_adapter_get_control_support =
            _struct->get_control_support;
      }
    } else {
      ark_video_device_descriptor_adapter_get_control_support =
          reinterpret_cast<
              ArkVideoDeviceDescriptorAdapterGetControlSupportFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_video_device_descriptor_adapter_get_control_support, nullptr);

  // Execute
  ark_video_control_support_adapter_t* _retval =
      ark_video_device_descriptor_adapter_get_control_support(_struct);

  // Return type: refptr_same
  return ArkVideoControlSupportAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
int32_t ArkVideoDeviceDescriptorAdapterCToCpp::GetTransportType() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_video_device_descriptor_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_video_device_descriptor_adapter_get_transport_type);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "sgKGdftU5ryp9_V67HniZw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_VIDEO_DEVICE_DESCRIPTOR_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_video_device_descriptor_adapter_get_transport_type");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_transport_type)) {
        ark_video_device_descriptor_adapter_get_transport_type = nullptr;
      } else {
        ark_video_device_descriptor_adapter_get_transport_type =
            _struct->get_transport_type;
      }
    } else {
      ark_video_device_descriptor_adapter_get_transport_type =
          reinterpret_cast<ArkVideoDeviceDescriptorAdapterGetTransportTypeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_video_device_descriptor_adapter_get_transport_type, 0);

  // Execute
  return ark_video_device_descriptor_adapter_get_transport_type(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkVideoDeviceDescriptorAdapterCToCpp::GetFacingMode() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_video_device_descriptor_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_video_device_descriptor_adapter_get_facing_mode);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "QcLyemzFfz9KlkUdZyVy7A";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_VIDEO_DEVICE_DESCRIPTOR_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_video_device_descriptor_adapter_get_facing_mode");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_facing_mode)) {
        ark_video_device_descriptor_adapter_get_facing_mode = nullptr;
      } else {
        ark_video_device_descriptor_adapter_get_facing_mode =
            _struct->get_facing_mode;
      }
    } else {
      ark_video_device_descriptor_adapter_get_facing_mode =
          reinterpret_cast<ArkVideoDeviceDescriptorAdapterGetFacingModeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_video_device_descriptor_adapter_get_facing_mode, 0);

  // Execute
  return ark_video_device_descriptor_adapter_get_facing_mode(_struct);
}

ARK_WEB_NO_SANITIZE
ArkFormatAdapterVector
ArkVideoDeviceDescriptorAdapterCToCpp::GetSupportCaptureFormats() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_video_device_descriptor_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, {0});

  void* func_pointer = reinterpret_cast<void*>(
      ark_video_device_descriptor_adapter_get_support_capture_formats);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "$HnlUchsePuiav1goXtTxg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(
                           ARK_VIDEO_DEVICE_DESCRIPTOR_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_video_device_descriptor_adapter_get_support_capture_formats");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_support_capture_formats)) {
        ark_video_device_descriptor_adapter_get_support_capture_formats =
            nullptr;
      } else {
        ark_video_device_descriptor_adapter_get_support_capture_formats =
            _struct->get_support_capture_formats;
      }
    } else {
      ark_video_device_descriptor_adapter_get_support_capture_formats =
          reinterpret_cast<
              ArkVideoDeviceDescriptorAdapterGetSupportCaptureFormatsFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_video_device_descriptor_adapter_get_support_capture_formats, {0});

  // Execute
  return ark_video_device_descriptor_adapter_get_support_capture_formats(
      _struct);
}

ArkVideoDeviceDescriptorAdapterCToCpp::ArkVideoDeviceDescriptorAdapterCToCpp() {
}

ArkVideoDeviceDescriptorAdapterCToCpp::
    ~ArkVideoDeviceDescriptorAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkVideoDeviceDescriptorAdapterCToCpp,
                           ArkVideoDeviceDescriptorAdapter,
                           ark_video_device_descriptor_adapter_t>::kBridgeType =
        ARK_VIDEO_DEVICE_DESCRIPTOR_ADAPTER;

}  // namespace OHOS::ArkWeb
