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

#include "ohos_nweb/cpptoc/ark_web_native_embed_param_data_info_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

ArkWebString ARK_WEB_CALLBACK ark_web_native_embed_param_data_info_get_embed_id(
    struct _ark_web_native_embed_param_data_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebNativeEmbedParamDataInfoCppToC::Get(self)->GetEmbedId();
}

ArkWebString ARK_WEB_CALLBACK
ark_web_native_embed_param_data_info_get_object_attribute_id(
    struct _ark_web_native_embed_param_data_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebNativeEmbedParamDataInfoCppToC::Get(self)
      ->GetObjectAttributeId();
}

ArkWebNativeEmbedParamItemVector ARK_WEB_CALLBACK
ark_web_native_embed_param_data_info_get_param_items(
    struct _ark_web_native_embed_param_data_info_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self,
                             ark_web_native_embed_param_item_vector_default);

  // Execute
  return ArkWebNativeEmbedParamDataInfoCppToC::Get(self)->GetParamItems();
}

}  // namespace

ArkWebNativeEmbedParamDataInfoCppToC::ArkWebNativeEmbedParamDataInfoCppToC() {
  GetStruct()->get_embed_id = ark_web_native_embed_param_data_info_get_embed_id;
  GetStruct()->get_object_attribute_id =
      ark_web_native_embed_param_data_info_get_object_attribute_id;
  GetStruct()->get_param_items =
      ark_web_native_embed_param_data_info_get_param_items;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["sftJb7auVU8$nL3eQ9IGPA"] = reinterpret_cast<void*>(
        ark_web_native_embed_param_data_info_get_embed_id);
    funcMemberMap["QugJ7CODz9w2iMRulA_UOQ"] = reinterpret_cast<void*>(
        ark_web_native_embed_param_data_info_get_object_attribute_id);
    funcMemberMap["YCQzmOSYTtUIpN43Fq3V4A"] = reinterpret_cast<void*>(
        ark_web_native_embed_param_data_info_get_param_items);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_NATIVE_EMBED_PARAM_DATA_INFO, funcMemberMap);
  });
}

ArkWebNativeEmbedParamDataInfoCppToC::~ArkWebNativeEmbedParamDataInfoCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<
    ArkWebNativeEmbedParamDataInfoCppToC,
    ArkWebNativeEmbedParamDataInfo,
    ark_web_native_embed_param_data_info_t>::kBridgeType =
    ARK_WEB_NATIVE_EMBED_PARAM_DATA_INFO;

}  // namespace OHOS::ArkWeb
