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

#include "ohos_nweb/ctocpp/ark_web_create_native_media_player_callback_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"
#include "ohos_nweb/cpptoc/ark_web_media_info_cpptoc.h"
#include "ohos_nweb/cpptoc/ark_web_native_media_player_handler_cpptoc.h"
#include "ohos_nweb/ctocpp/ark_web_native_media_player_bridge_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkWebCreateNativeMediaPlayerCallbackOnCreateFunc =
    ark_web_native_media_player_bridge_t* (*)(struct
                                              _ark_web_create_native_media_player_callback_t*
                                                  self,
                                              ark_web_native_media_player_handler_t*
                                                  handler,
                                              ark_web_media_info_t* mediaInfo);
static ArkWebCreateNativeMediaPlayerCallbackOnCreateFunc
    ark_web_create_native_media_player_callback_on_create =
        reinterpret_cast<ArkWebCreateNativeMediaPlayerCallbackOnCreateFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkWebNativeMediaPlayerBridge>
ArkWebCreateNativeMediaPlayerCallbackCToCpp::OnCreate(
    ArkWebRefPtr<ArkWebNativeMediaPlayerHandler> handler,
    ArkWebRefPtr<ArkWebMediaInfo> mediaInfo) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_create_native_media_player_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_create_native_media_player_callback_on_create);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "$IWBOoV70XIn0GVPIf$Egg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_CREATE_NATIVE_MEDIA_PLAYER_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_create_native_media_player_callback_on_create");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, on_create)) {
        ark_web_create_native_media_player_callback_on_create = nullptr;
      } else {
        ark_web_create_native_media_player_callback_on_create =
            _struct->on_create;
      }
    } else {
      ark_web_create_native_media_player_callback_on_create =
          reinterpret_cast<ArkWebCreateNativeMediaPlayerCallbackOnCreateFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_create_native_media_player_callback_on_create, nullptr);

  // Execute
  ark_web_native_media_player_bridge_t* _retval =
      ark_web_create_native_media_player_callback_on_create(
          _struct, ArkWebNativeMediaPlayerHandlerCppToC::Invert(handler),
          ArkWebMediaInfoCppToC::Invert(mediaInfo));

  // Return type: refptr_same
  return ArkWebNativeMediaPlayerBridgeCToCpp::Invert(_retval);
}

ArkWebCreateNativeMediaPlayerCallbackCToCpp::
    ArkWebCreateNativeMediaPlayerCallbackCToCpp() {}

ArkWebCreateNativeMediaPlayerCallbackCToCpp::
    ~ArkWebCreateNativeMediaPlayerCallbackCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<
    ArkWebCreateNativeMediaPlayerCallbackCToCpp,
    ArkWebCreateNativeMediaPlayerCallback,
    ark_web_create_native_media_player_callback_t>::kBridgeType =
    ARK_WEB_CREATE_NATIVE_MEDIA_PLAYER_CALLBACK;

}  // namespace OHOS::ArkWeb
