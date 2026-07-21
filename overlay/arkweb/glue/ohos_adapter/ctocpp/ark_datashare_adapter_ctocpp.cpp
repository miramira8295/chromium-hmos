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

#include "ohos_adapter/ctocpp/ark_datashare_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkDatashareAdapterOpenDataShareUriForReadFunc =
    int (*)(struct _ark_datashare_adapter_t* self, const ArkWebString* uriStr);
static ArkDatashareAdapterOpenDataShareUriForReadFunc
    ark_datashare_adapter_open_data_share_uri_for_read =
        reinterpret_cast<ArkDatashareAdapterOpenDataShareUriForReadFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDatashareAdapterGetFileDisplayNameFunc =
    ArkWebString (*)(struct _ark_datashare_adapter_t* self,
                     const ArkWebString* uriStr);
static ArkDatashareAdapterGetFileDisplayNameFunc
    ark_datashare_adapter_get_file_display_name =
        reinterpret_cast<ArkDatashareAdapterGetFileDisplayNameFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDatashareAdapterGetRealPathFunc =
    ArkWebString (*)(struct _ark_datashare_adapter_t* self,
                     const ArkWebString* uriStr);
static ArkDatashareAdapterGetRealPathFunc ark_datashare_adapter_get_real_path =
    reinterpret_cast<ArkDatashareAdapterGetRealPathFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int ArkDatashareAdapterCToCpp::OpenDataShareUriForRead(
    const ArkWebString& uriStr) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_datashare_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_datashare_adapter_open_data_share_uri_for_read);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "A$9v6EHkHWTqrzdkWKxUjg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_DATASHARE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_datashare_adapter_open_data_share_uri_for_read");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, open_data_share_uri_for_read)) {
        ark_datashare_adapter_open_data_share_uri_for_read = nullptr;
      } else {
        ark_datashare_adapter_open_data_share_uri_for_read =
            _struct->open_data_share_uri_for_read;
      }
    } else {
      ark_datashare_adapter_open_data_share_uri_for_read =
          reinterpret_cast<ArkDatashareAdapterOpenDataShareUriForReadFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_datashare_adapter_open_data_share_uri_for_read, 0);

  // Execute
  return ark_datashare_adapter_open_data_share_uri_for_read(_struct, &uriStr);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkDatashareAdapterCToCpp::GetFileDisplayName(
    const ArkWebString& uriStr) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_datashare_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_datashare_adapter_get_file_display_name);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "AZcN7u6nZ0rSqcMu4QzfVw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_DATASHARE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_datashare_adapter_get_file_display_name");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_file_display_name)) {
        ark_datashare_adapter_get_file_display_name = nullptr;
      } else {
        ark_datashare_adapter_get_file_display_name =
            _struct->get_file_display_name;
      }
    } else {
      ark_datashare_adapter_get_file_display_name =
          reinterpret_cast<ArkDatashareAdapterGetFileDisplayNameFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_datashare_adapter_get_file_display_name,
                                    ark_web_string_default);

  // Execute
  return ark_datashare_adapter_get_file_display_name(_struct, &uriStr);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkDatashareAdapterCToCpp::GetRealPath(
    const ArkWebString& uriStr) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_datashare_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_datashare_adapter_get_real_path);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "GxbD8mgtAf6iDuNApkWRJA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_DATASHARE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_datashare_adapter_get_real_path");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_real_path)) {
        ark_datashare_adapter_get_real_path = nullptr;
      } else {
        ark_datashare_adapter_get_real_path = _struct->get_real_path;
      }
    } else {
      ark_datashare_adapter_get_real_path =
          reinterpret_cast<ArkDatashareAdapterGetRealPathFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_datashare_adapter_get_real_path,
                                    ark_web_string_default);

  // Execute
  return ark_datashare_adapter_get_real_path(_struct, &uriStr);
}

ArkDatashareAdapterCToCpp::ArkDatashareAdapterCToCpp() {}

ArkDatashareAdapterCToCpp::~ArkDatashareAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkDatashareAdapterCToCpp,
                                        ArkDatashareAdapter,
                                        ark_datashare_adapter_t>::kBridgeType =
    ARK_DATASHARE_ADAPTER;

}  // namespace OHOS::ArkWeb
