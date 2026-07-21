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

#include "ohos_nweb/ctocpp/ark_web_spanstring_convert_html_callback_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebSpanstringConvertHtmlCallbackSpanstringConvertHtmlFunc =
    ArkWebString (*)(struct _ark_web_spanstring_convert_html_callback_t* self,
                     const ArkWebUint8Vector* content);
static ArkWebSpanstringConvertHtmlCallbackSpanstringConvertHtmlFunc
    ark_web_spanstring_convert_html_callback_spanstring_convert_html =
        reinterpret_cast<
            ArkWebSpanstringConvertHtmlCallbackSpanstringConvertHtmlFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
ArkWebString ArkWebSpanstringConvertHtmlCallbackCToCpp::SpanstringConvertHtml(
    const ArkWebUint8Vector& content) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_spanstring_convert_html_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_spanstring_convert_html_callback_spanstring_convert_html);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Dmn$7SH0rP_BAOw0zho_vw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_SPANSTRING_CONVERT_HTML_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_spanstring_convert_html_callback_spanstring_convert_html");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, spanstring_convert_html)) {
        ark_web_spanstring_convert_html_callback_spanstring_convert_html =
            nullptr;
      } else {
        ark_web_spanstring_convert_html_callback_spanstring_convert_html =
            _struct->spanstring_convert_html;
      }
    } else {
      ark_web_spanstring_convert_html_callback_spanstring_convert_html =
          reinterpret_cast<
              ArkWebSpanstringConvertHtmlCallbackSpanstringConvertHtmlFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_spanstring_convert_html_callback_spanstring_convert_html,
      ark_web_string_default);

  // Execute
  return ark_web_spanstring_convert_html_callback_spanstring_convert_html(
      _struct, &content);
}

ArkWebSpanstringConvertHtmlCallbackCToCpp::
    ArkWebSpanstringConvertHtmlCallbackCToCpp() {}

ArkWebSpanstringConvertHtmlCallbackCToCpp::
    ~ArkWebSpanstringConvertHtmlCallbackCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<
    ArkWebSpanstringConvertHtmlCallbackCToCpp,
    ArkWebSpanstringConvertHtmlCallback,
    ark_web_spanstring_convert_html_callback_t>::kBridgeType =
    ARK_WEB_SPANSTRING_CONVERT_HTML_CALLBACK;

}  // namespace OHOS::ArkWeb
