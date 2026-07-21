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

#include "ohos_nweb/ctocpp/ark_web_engine_prefetch_args_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebEnginePrefetchArgsGetUrlFunc =
    ArkWebString (*)(struct _ark_web_engine_prefetch_args_t* self);
static ArkWebEnginePrefetchArgsGetUrlFunc ark_web_engine_prefetch_args_get_url =
    reinterpret_cast<ArkWebEnginePrefetchArgsGetUrlFunc>(ARK_WEB_INIT_ADDR);

using ArkWebEnginePrefetchArgsGetMethodFunc =
    ArkWebString (*)(struct _ark_web_engine_prefetch_args_t* self);
static ArkWebEnginePrefetchArgsGetMethodFunc
    ark_web_engine_prefetch_args_get_method =
        reinterpret_cast<ArkWebEnginePrefetchArgsGetMethodFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebEnginePrefetchArgsGetFormDataFunc =
    ArkWebString (*)(struct _ark_web_engine_prefetch_args_t* self);
static ArkWebEnginePrefetchArgsGetFormDataFunc
    ark_web_engine_prefetch_args_get_form_data =
        reinterpret_cast<ArkWebEnginePrefetchArgsGetFormDataFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
ArkWebString ArkWebEnginePrefetchArgsCToCpp::GetUrl() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_engine_prefetch_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_engine_prefetch_args_get_url);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "9lvhtnnEpHdo8DWwAF1piQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ENGINE_PREFETCH_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_engine_prefetch_args_get_url");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_url)) {
        ark_web_engine_prefetch_args_get_url = nullptr;
      } else {
        ark_web_engine_prefetch_args_get_url = _struct->get_url;
      }
    } else {
      ark_web_engine_prefetch_args_get_url =
          reinterpret_cast<ArkWebEnginePrefetchArgsGetUrlFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_engine_prefetch_args_get_url,
                                    ark_web_string_default);

  // Execute
  return ark_web_engine_prefetch_args_get_url(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkWebEnginePrefetchArgsCToCpp::GetMethod() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_engine_prefetch_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_engine_prefetch_args_get_method);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "5584jmN98c_SuljEQ3dAUA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ENGINE_PREFETCH_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_engine_prefetch_args_get_method");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_method)) {
        ark_web_engine_prefetch_args_get_method = nullptr;
      } else {
        ark_web_engine_prefetch_args_get_method = _struct->get_method;
      }
    } else {
      ark_web_engine_prefetch_args_get_method =
          reinterpret_cast<ArkWebEnginePrefetchArgsGetMethodFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_engine_prefetch_args_get_method,
                                    ark_web_string_default);

  // Execute
  return ark_web_engine_prefetch_args_get_method(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkWebEnginePrefetchArgsCToCpp::GetFormData() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_engine_prefetch_args_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_engine_prefetch_args_get_form_data);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "VCdmVDJ6wWTB88kgBROQGg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ENGINE_PREFETCH_ARGS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_engine_prefetch_args_get_form_data");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_form_data)) {
        ark_web_engine_prefetch_args_get_form_data = nullptr;
      } else {
        ark_web_engine_prefetch_args_get_form_data = _struct->get_form_data;
      }
    } else {
      ark_web_engine_prefetch_args_get_form_data =
          reinterpret_cast<ArkWebEnginePrefetchArgsGetFormDataFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_engine_prefetch_args_get_form_data,
                                    ark_web_string_default);

  // Execute
  return ark_web_engine_prefetch_args_get_form_data(_struct);
}

ArkWebEnginePrefetchArgsCToCpp::ArkWebEnginePrefetchArgsCToCpp() {}

ArkWebEnginePrefetchArgsCToCpp::~ArkWebEnginePrefetchArgsCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkWebEnginePrefetchArgsCToCpp,
                           ArkWebEnginePrefetchArgs,
                           ark_web_engine_prefetch_args_t>::kBridgeType =
        ARK_WEB_ENGINE_PREFETCH_ARGS;

}  // namespace OHOS::ArkWeb
