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

#include "ohos_adapter/cpptoc/ark_imfinput_attribute_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

int32_t ARK_WEB_CALLBACK ark_imfinput_attribute_adapter_get_input_pattern(
    struct _ark_imfinput_attribute_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkIMFInputAttributeAdapterCppToC::Get(self)->GetInputPattern();
}

int32_t ARK_WEB_CALLBACK ark_imfinput_attribute_adapter_get_enter_key_type(
    struct _ark_imfinput_attribute_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkIMFInputAttributeAdapterCppToC::Get(self)->GetEnterKeyType();
}

}  // namespace

ArkIMFInputAttributeAdapterCppToC::ArkIMFInputAttributeAdapterCppToC() {
  GetStruct()->get_input_pattern =
      ark_imfinput_attribute_adapter_get_input_pattern;
  GetStruct()->get_enter_key_type =
      ark_imfinput_attribute_adapter_get_enter_key_type;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["00g7ypmt7125gNAu5ylM5g"] = reinterpret_cast<void*>(
        ark_imfinput_attribute_adapter_get_input_pattern);
    funcMemberMap["w1I$nROkUc8Hi869iOlnVw"] = reinterpret_cast<void*>(
        ark_imfinput_attribute_adapter_get_enter_key_type);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_IMFINPUT_ATTRIBUTE_ADAPTER, funcMemberMap);
  });
}

ArkIMFInputAttributeAdapterCppToC::~ArkIMFInputAttributeAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkIMFInputAttributeAdapterCppToC,
                           ArkIMFInputAttributeAdapter,
                           ark_imfinput_attribute_adapter_t>::kBridgeType =
        ARK_IMFINPUT_ATTRIBUTE_ADAPTER;

}  // namespace OHOS::ArkWeb
