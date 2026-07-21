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

#include "ohos_adapter/cpptoc/ark_video_info_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_video_capture_info_adapter_cpptoc.h"
#include "ohos_adapter/cpptoc/ark_video_enc_info_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

namespace {

ark_video_capture_info_adapter_t* ARK_WEB_CALLBACK
ark_video_info_adapter_get_video_cap_info(
    struct _ark_video_info_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkVideoCaptureInfoAdapter> _retval =
      ArkVideoInfoAdapterCppToC::Get(self)->GetVideoCapInfo();

  // Return type: refptr_same
  return ArkVideoCaptureInfoAdapterCppToC::Invert(_retval);
}

ark_video_enc_info_adapter_t* ARK_WEB_CALLBACK
ark_video_info_adapter_get_video_enc_info(
    struct _ark_video_info_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkVideoEncInfoAdapter> _retval =
      ArkVideoInfoAdapterCppToC::Get(self)->GetVideoEncInfo();

  // Return type: refptr_same
  return ArkVideoEncInfoAdapterCppToC::Invert(_retval);
}

}  // namespace

ArkVideoInfoAdapterCppToC::ArkVideoInfoAdapterCppToC() {
  GetStruct()->get_video_cap_info = ark_video_info_adapter_get_video_cap_info;
  GetStruct()->get_video_enc_info = ark_video_info_adapter_get_video_enc_info;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["Hj8mSdhIMOGNe1rmIevR1Q"] =
        reinterpret_cast<void*>(ark_video_info_adapter_get_video_cap_info);
    funcMemberMap["WHmWaSt9wAcerR7Wh3$R4Q"] =
        reinterpret_cast<void*>(ark_video_info_adapter_get_video_enc_info);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_VIDEO_INFO_ADAPTER, funcMemberMap);
  });
}

ArkVideoInfoAdapterCppToC::~ArkVideoInfoAdapterCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<ArkVideoInfoAdapterCppToC,
                                        ArkVideoInfoAdapter,
                                        ark_video_info_adapter_t>::kBridgeType =
    ARK_VIDEO_INFO_ADAPTER;

}  // namespace OHOS::ArkWeb
