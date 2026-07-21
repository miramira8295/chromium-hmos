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

#include "ohos_nweb/cpptoc/ark_web_native_embed_param_item_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

int ARK_WEB_CALLBACK ark_web_native_embed_param_item_get_status(
    struct _ark_web_native_embed_param_item_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebNativeEmbedParamItemCppToC::Get(self)->GetStatus();
}

ArkWebString ARK_WEB_CALLBACK ark_web_native_embed_param_item_get_id(
    struct _ark_web_native_embed_param_item_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebNativeEmbedParamItemCppToC::Get(self)->GetId();
}

ArkWebString ARK_WEB_CALLBACK ark_web_native_embed_param_item_get_name(
    struct _ark_web_native_embed_param_item_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebNativeEmbedParamItemCppToC::Get(self)->GetName();
}

ArkWebString ARK_WEB_CALLBACK ark_web_native_embed_param_item_get_value(
    struct _ark_web_native_embed_param_item_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebNativeEmbedParamItemCppToC::Get(self)->GetValue();
}

}  // namespace

ArkWebNativeEmbedParamItemCppToC::ArkWebNativeEmbedParamItemCppToC() {
  GetStruct()->get_status = ark_web_native_embed_param_item_get_status;
  GetStruct()->get_id = ark_web_native_embed_param_item_get_id;
  GetStruct()->get_name = ark_web_native_embed_param_item_get_name;
  GetStruct()->get_value = ark_web_native_embed_param_item_get_value;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["BWNk_6JmlCQnaE1Pfz2GSQ"] =
        reinterpret_cast<void*>(ark_web_native_embed_param_item_get_status);
    funcMemberMap["KQ$8Je7D0ajBDf32vMmrNw"] =
        reinterpret_cast<void*>(ark_web_native_embed_param_item_get_id);
    funcMemberMap["lmE3bl6etlSeTcX1EYLuWg"] =
        reinterpret_cast<void*>(ark_web_native_embed_param_item_get_name);
    funcMemberMap["mM2g3b5bE5WqaXTAlrGnXw"] =
        reinterpret_cast<void*>(ark_web_native_embed_param_item_get_value);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_NATIVE_EMBED_PARAM_ITEM, funcMemberMap);
  });
}

ArkWebNativeEmbedParamItemCppToC::~ArkWebNativeEmbedParamItemCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebNativeEmbedParamItemCppToC,
                           ArkWebNativeEmbedParamItem,
                           ark_web_native_embed_param_item_t>::kBridgeType =
        ARK_WEB_NATIVE_EMBED_PARAM_ITEM;

}  // namespace OHOS::ArkWeb
