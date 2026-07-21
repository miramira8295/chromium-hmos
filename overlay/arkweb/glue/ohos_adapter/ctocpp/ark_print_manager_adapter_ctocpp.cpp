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

#include "ohos_adapter/ctocpp/ark_print_manager_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_print_document_adapter_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkPrintManagerAdapterStartPrintFunc =
    int32_t (*)(struct _ark_print_manager_adapter_t* self,
                const ArkWebStringVector* fileList,
                const ArkWebUint32Vector* fdList,
                ArkWebString* taskId);
static ArkPrintManagerAdapterStartPrintFunc
    ark_print_manager_adapter_start_print =
        reinterpret_cast<ArkPrintManagerAdapterStartPrintFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPrintManagerAdapterPrintFunc1 =
    int32_t (*)(struct _ark_print_manager_adapter_t* self,
                const ArkWebString* printJobName,
                ark_print_document_adapter_adapter_t* listener,
                const ArkPrintAttributesAdapter* printAttributes);
static ArkPrintManagerAdapterPrintFunc1 ark_print_manager_adapter_print1 =
    reinterpret_cast<ArkPrintManagerAdapterPrintFunc1>(ARK_WEB_INIT_ADDR);

using ArkPrintManagerAdapterPrintFunc2 =
    int32_t (*)(struct _ark_print_manager_adapter_t* self,
                const ArkWebString* printJobName,
                ark_print_document_adapter_adapter_t* listener,
                const ArkPrintAttributesAdapter* printAttributes,
                void* contextToken);
static ArkPrintManagerAdapterPrintFunc2 ark_print_manager_adapter_print2 =
    reinterpret_cast<ArkPrintManagerAdapterPrintFunc2>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkPrintManagerAdapterCToCpp::StartPrint(
    const ArkWebStringVector& fileList,
    const ArkWebUint32Vector& fdList,
    ArkWebString& taskId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_print_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_print_manager_adapter_start_print);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "3H3i6ISGAdiXYCLDNETmUQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PRINT_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_print_manager_adapter_start_print");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, start_print)) {
        ark_print_manager_adapter_start_print = nullptr;
      } else {
        ark_print_manager_adapter_start_print = _struct->start_print;
      }
    } else {
      ark_print_manager_adapter_start_print =
          reinterpret_cast<ArkPrintManagerAdapterStartPrintFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_print_manager_adapter_start_print, 0);

  // Execute
  return ark_print_manager_adapter_start_print(_struct, &fileList, &fdList,
                                               &taskId);
}

ARK_WEB_NO_SANITIZE
int32_t ArkPrintManagerAdapterCToCpp::Print(
    const ArkWebString& printJobName,
    const ArkWebRefPtr<ArkPrintDocumentAdapterAdapter> listener,
    const ArkPrintAttributesAdapter& printAttributes) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_print_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_print_manager_adapter_print1);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "dFNSSPCjrIsL2FG4$xbK8g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PRINT_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_print_manager_adapter_print1");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, print1)) {
        ark_print_manager_adapter_print1 = nullptr;
      } else {
        ark_print_manager_adapter_print1 = _struct->print1;
      }
    } else {
      ark_print_manager_adapter_print1 =
          reinterpret_cast<ArkPrintManagerAdapterPrintFunc1>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_print_manager_adapter_print1, 0);

  // Execute
  return ark_print_manager_adapter_print1(
      _struct, &printJobName,
      ArkPrintDocumentAdapterAdapterCppToC::Invert(listener), &printAttributes);
}

ARK_WEB_NO_SANITIZE
int32_t ArkPrintManagerAdapterCToCpp::Print(
    const ArkWebString& printJobName,
    const ArkWebRefPtr<ArkPrintDocumentAdapterAdapter> listener,
    const ArkPrintAttributesAdapter& printAttributes,
    void* contextToken) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_print_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_print_manager_adapter_print2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "z_uwv0qKvmnRMd84$LilRw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PRINT_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_print_manager_adapter_print2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, print2)) {
        ark_print_manager_adapter_print2 = nullptr;
      } else {
        ark_print_manager_adapter_print2 = _struct->print2;
      }
    } else {
      ark_print_manager_adapter_print2 =
          reinterpret_cast<ArkPrintManagerAdapterPrintFunc2>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_print_manager_adapter_print2, 0);

  // Execute
  return ark_print_manager_adapter_print2(
      _struct, &printJobName,
      ArkPrintDocumentAdapterAdapterCppToC::Invert(listener), &printAttributes,
      contextToken);
}

ArkPrintManagerAdapterCToCpp::ArkPrintManagerAdapterCToCpp() {}

ArkPrintManagerAdapterCToCpp::~ArkPrintManagerAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkPrintManagerAdapterCToCpp,
                           ArkPrintManagerAdapter,
                           ark_print_manager_adapter_t>::kBridgeType =
        ARK_PRINT_MANAGER_ADAPTER;

}  // namespace OHOS::ArkWeb
