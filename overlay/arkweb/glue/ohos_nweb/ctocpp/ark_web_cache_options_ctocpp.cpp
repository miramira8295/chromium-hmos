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

#include "ohos_nweb/ctocpp/ark_web_cache_options_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebCacheOptionsGetResponseHeadersFunc =
    ArkWebStringMap (*)(struct _ark_web_cache_options_t* self);
static ArkWebCacheOptionsGetResponseHeadersFunc
    ark_web_cache_options_get_response_headers =
        reinterpret_cast<ArkWebCacheOptionsGetResponseHeadersFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
ArkWebStringMap ArkWebCacheOptionsCToCpp::GetResponseHeaders() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_cache_options_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_map_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_cache_options_get_response_headers);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "exBM4W8lRvjKB8QqbtUbtA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_CACHE_OPTIONS, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_cache_options_get_response_headers");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_response_headers)) {
        ark_web_cache_options_get_response_headers = nullptr;
      } else {
        ark_web_cache_options_get_response_headers =
            _struct->get_response_headers;
      }
    } else {
      ark_web_cache_options_get_response_headers =
          reinterpret_cast<ArkWebCacheOptionsGetResponseHeadersFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_cache_options_get_response_headers,
                                    ark_web_string_map_default);

  // Execute
  return ark_web_cache_options_get_response_headers(_struct);
}

ArkWebCacheOptionsCToCpp::ArkWebCacheOptionsCToCpp() {}

ArkWebCacheOptionsCToCpp::~ArkWebCacheOptionsCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkWebCacheOptionsCToCpp,
                                        ArkWebCacheOptions,
                                        ark_web_cache_options_t>::kBridgeType =
    ARK_WEB_CACHE_OPTIONS;

}  // namespace OHOS::ArkWeb
