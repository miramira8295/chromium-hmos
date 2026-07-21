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

#include "ohos_nweb/cpptoc/ark_web_print_document_adapter_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"
#include "ohos_nweb/ctocpp/ark_web_print_attributes_adapter_ctocpp.h"
#include "ohos_nweb/ctocpp/ark_web_print_write_result_callback_adapter_ctocpp.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK
ark_web_print_document_adapter_adapter_on_start_layout_write(
    struct _ark_web_print_document_adapter_adapter_t* self,
    const ArkWebString* jobId,
    ark_web_print_attributes_adapter_t* oldAttrs,
    ark_web_print_attributes_adapter_t* newAttrs,
    uint32_t fd,
    ark_web_print_write_result_callback_adapter_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(jobId, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPrintDocumentAdapterAdapterCppToC::Get(self)->OnStartLayoutWrite(
      *jobId, ArkWebPrintAttributesAdapterCToCpp::Invert(oldAttrs),
      ArkWebPrintAttributesAdapterCToCpp::Invert(newAttrs), fd,
      ArkWebPrintWriteResultCallbackAdapterCToCpp::Invert(callback));
}

void ARK_WEB_CALLBACK
ark_web_print_document_adapter_adapter_on_job_state_changed(
    struct _ark_web_print_document_adapter_adapter_t* self,
    const ArkWebString* jobId,
    uint32_t state) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(jobId, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebPrintDocumentAdapterAdapterCppToC::Get(self)->OnJobStateChanged(*jobId,
                                                                        state);
}

}  // namespace

ArkWebPrintDocumentAdapterAdapterCppToC::
    ArkWebPrintDocumentAdapterAdapterCppToC() {
  GetStruct()->on_start_layout_write =
      ark_web_print_document_adapter_adapter_on_start_layout_write;
  GetStruct()->on_job_state_changed =
      ark_web_print_document_adapter_adapter_on_job_state_changed;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["WC5gLDqmfNBoXlZr62rzUA"] = reinterpret_cast<void*>(
        ark_web_print_document_adapter_adapter_on_start_layout_write);
    funcMemberMap["0gw5_r_nE6IgZUr7uMu7jQ"] = reinterpret_cast<void*>(
        ark_web_print_document_adapter_adapter_on_job_state_changed);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_PRINT_DOCUMENT_ADAPTER_ADAPTER, funcMemberMap);
  });
}

ArkWebPrintDocumentAdapterAdapterCppToC::
    ~ArkWebPrintDocumentAdapterAdapterCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<
    ArkWebPrintDocumentAdapterAdapterCppToC,
    ArkWebPrintDocumentAdapterAdapter,
    ark_web_print_document_adapter_adapter_t>::kBridgeType =
    ARK_WEB_PRINT_DOCUMENT_ADAPTER_ADAPTER;

}  // namespace OHOS::ArkWeb
