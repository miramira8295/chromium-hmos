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

#include "ohos_nweb/ctocpp/ark_web_print_write_result_callback_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebPrintWriteResultCallbackAdapterWriteResultCallbackFunc =
    void (*)(struct _ark_web_print_write_result_callback_adapter_t* self,
             const ArkWebString* jobId,
             uint32_t code);
static ArkWebPrintWriteResultCallbackAdapterWriteResultCallbackFunc
    ark_web_print_write_result_callback_adapter_write_result_callback =
        reinterpret_cast<
            ArkWebPrintWriteResultCallbackAdapterWriteResultCallbackFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkWebPrintWriteResultCallbackAdapterCToCpp::WriteResultCallback(
    const ArkWebString& jobId,
    uint32_t code) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_print_write_result_callback_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_print_write_result_callback_adapter_write_result_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "nWd2YppEANjpKSB_YmI21Q";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_PRINT_WRITE_RESULT_CALLBACK_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_print_write_result_callback_adapter_write_result_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, write_result_callback)) {
        ark_web_print_write_result_callback_adapter_write_result_callback =
            nullptr;
      } else {
        ark_web_print_write_result_callback_adapter_write_result_callback =
            _struct->write_result_callback;
      }
    } else {
      ark_web_print_write_result_callback_adapter_write_result_callback =
          reinterpret_cast<
              ArkWebPrintWriteResultCallbackAdapterWriteResultCallbackFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_print_write_result_callback_adapter_write_result_callback,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_print_write_result_callback_adapter_write_result_callback(
      _struct, &jobId, code);
}

ArkWebPrintWriteResultCallbackAdapterCToCpp::
    ArkWebPrintWriteResultCallbackAdapterCToCpp() {}

ArkWebPrintWriteResultCallbackAdapterCToCpp::
    ~ArkWebPrintWriteResultCallbackAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<
    ArkWebPrintWriteResultCallbackAdapterCToCpp,
    ArkWebPrintWriteResultCallbackAdapter,
    ark_web_print_write_result_callback_adapter_t>::kBridgeType =
    ARK_WEB_PRINT_WRITE_RESULT_CALLBACK_ADAPTER;

}  // namespace OHOS::ArkWeb
