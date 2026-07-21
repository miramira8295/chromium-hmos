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

#include "ohos_adapter/ctocpp/ark_paste_data_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/ctocpp/ark_paste_data_record_adapter_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkPasteDataAdapterAddHtmlRecordFunc =
    void (*)(struct _ark_paste_data_adapter_t* self, const ArkWebString* html);
static ArkPasteDataAdapterAddHtmlRecordFunc
    ark_paste_data_adapter_add_html_record =
        reinterpret_cast<ArkPasteDataAdapterAddHtmlRecordFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataAdapterAddTextRecordFunc =
    void (*)(struct _ark_paste_data_adapter_t* self, const ArkWebString* text);
static ArkPasteDataAdapterAddTextRecordFunc
    ark_paste_data_adapter_add_text_record =
        reinterpret_cast<ArkPasteDataAdapterAddTextRecordFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataAdapterGetMimeTypesFunc =
    ArkWebStringVector (*)(struct _ark_paste_data_adapter_t* self);
static ArkPasteDataAdapterGetMimeTypesFunc
    ark_paste_data_adapter_get_mime_types =
        reinterpret_cast<ArkPasteDataAdapterGetMimeTypesFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataAdapterGetPrimaryHtmlFunc =
    void (*)(struct _ark_paste_data_adapter_t* self, void* data);
static ArkPasteDataAdapterGetPrimaryHtmlFunc
    ark_paste_data_adapter_get_primary_html =
        reinterpret_cast<ArkPasteDataAdapterGetPrimaryHtmlFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataAdapterGetPrimaryTextFunc =
    void (*)(struct _ark_paste_data_adapter_t* self, void* data);
static ArkPasteDataAdapterGetPrimaryTextFunc
    ark_paste_data_adapter_get_primary_text =
        reinterpret_cast<ArkPasteDataAdapterGetPrimaryTextFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataAdapterGetPrimaryMimeTypeFunc =
    void (*)(struct _ark_paste_data_adapter_t* self, void* data);
static ArkPasteDataAdapterGetPrimaryMimeTypeFunc
    ark_paste_data_adapter_get_primary_mime_type =
        reinterpret_cast<ArkPasteDataAdapterGetPrimaryMimeTypeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataAdapterGetRecordAtFunc =
    ark_paste_data_record_adapter_t* (*)(struct _ark_paste_data_adapter_t* self,
                                         size_t index);
static ArkPasteDataAdapterGetRecordAtFunc ark_paste_data_adapter_get_record_at =
    reinterpret_cast<ArkPasteDataAdapterGetRecordAtFunc>(ARK_WEB_INIT_ADDR);

using ArkPasteDataAdapterGetRecordCountFunc =
    size_t (*)(struct _ark_paste_data_adapter_t* self);
static ArkPasteDataAdapterGetRecordCountFunc
    ark_paste_data_adapter_get_record_count =
        reinterpret_cast<ArkPasteDataAdapterGetRecordCountFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataAdapterAllRecordsFunc =
    ArkPasteRecordVector (*)(struct _ark_paste_data_adapter_t* self);
static ArkPasteDataAdapterAllRecordsFunc ark_paste_data_adapter_all_records =
    reinterpret_cast<ArkPasteDataAdapterAllRecordsFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkPasteDataAdapterCToCpp::AddHtmlRecord(const ArkWebString& html) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_adapter_add_html_record);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "NhFzxeZeAbXSOAc7mDo6zQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_paste_data_adapter_add_html_record");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, add_html_record)) {
        ark_paste_data_adapter_add_html_record = nullptr;
      } else {
        ark_paste_data_adapter_add_html_record = _struct->add_html_record;
      }
    } else {
      ark_paste_data_adapter_add_html_record =
          reinterpret_cast<ArkPasteDataAdapterAddHtmlRecordFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_data_adapter_add_html_record,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_paste_data_adapter_add_html_record(_struct, &html);
}

ARK_WEB_NO_SANITIZE
void ArkPasteDataAdapterCToCpp::AddTextRecord(const ArkWebString& text) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_adapter_add_text_record);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "VID9MDt3FCrTxSaL4XCtJg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_paste_data_adapter_add_text_record");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, add_text_record)) {
        ark_paste_data_adapter_add_text_record = nullptr;
      } else {
        ark_paste_data_adapter_add_text_record = _struct->add_text_record;
      }
    } else {
      ark_paste_data_adapter_add_text_record =
          reinterpret_cast<ArkPasteDataAdapterAddTextRecordFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_data_adapter_add_text_record,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_paste_data_adapter_add_text_record(_struct, &text);
}

ARK_WEB_NO_SANITIZE
ArkWebStringVector ArkPasteDataAdapterCToCpp::GetMimeTypes() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_vector_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_adapter_get_mime_types);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Medj8ieUVNe5lYKQqMhN4w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_paste_data_adapter_get_mime_types");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_mime_types)) {
        ark_paste_data_adapter_get_mime_types = nullptr;
      } else {
        ark_paste_data_adapter_get_mime_types = _struct->get_mime_types;
      }
    } else {
      ark_paste_data_adapter_get_mime_types =
          reinterpret_cast<ArkPasteDataAdapterGetMimeTypesFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_data_adapter_get_mime_types,
                                    ark_web_string_vector_default);

  // Execute
  return ark_paste_data_adapter_get_mime_types(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkPasteDataAdapterCToCpp::GetPrimaryHtml(void* data) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_adapter_get_primary_html);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "YZDu4alXbqmhwLElBAngHA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_paste_data_adapter_get_primary_html");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_primary_html)) {
        ark_paste_data_adapter_get_primary_html = nullptr;
      } else {
        ark_paste_data_adapter_get_primary_html = _struct->get_primary_html;
      }
    } else {
      ark_paste_data_adapter_get_primary_html =
          reinterpret_cast<ArkPasteDataAdapterGetPrimaryHtmlFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_data_adapter_get_primary_html,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_paste_data_adapter_get_primary_html(_struct, data);
}

ARK_WEB_NO_SANITIZE
void ArkPasteDataAdapterCToCpp::GetPrimaryText(void* data) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_adapter_get_primary_text);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "RDwqNh6IHA1Dpa$rRw9otQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_paste_data_adapter_get_primary_text");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_primary_text)) {
        ark_paste_data_adapter_get_primary_text = nullptr;
      } else {
        ark_paste_data_adapter_get_primary_text = _struct->get_primary_text;
      }
    } else {
      ark_paste_data_adapter_get_primary_text =
          reinterpret_cast<ArkPasteDataAdapterGetPrimaryTextFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_data_adapter_get_primary_text,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_paste_data_adapter_get_primary_text(_struct, data);
}

ARK_WEB_NO_SANITIZE
void ArkPasteDataAdapterCToCpp::GetPrimaryMimeType(void* data) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_adapter_get_primary_mime_type);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "FH1SoXhFawq0rf0GKFCBfQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_data_adapter_get_primary_mime_type");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_primary_mime_type)) {
        ark_paste_data_adapter_get_primary_mime_type = nullptr;
      } else {
        ark_paste_data_adapter_get_primary_mime_type =
            _struct->get_primary_mime_type;
      }
    } else {
      ark_paste_data_adapter_get_primary_mime_type =
          reinterpret_cast<ArkPasteDataAdapterGetPrimaryMimeTypeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_data_adapter_get_primary_mime_type, ARK_WEB_RETURN_VOID);

  // Execute
  ark_paste_data_adapter_get_primary_mime_type(_struct, data);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkPasteDataRecordAdapter> ArkPasteDataAdapterCToCpp::GetRecordAt(
    size_t index) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_adapter_get_record_at);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ma7uKvh2eSRYhpebF6NQfw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_paste_data_adapter_get_record_at");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_record_at)) {
        ark_paste_data_adapter_get_record_at = nullptr;
      } else {
        ark_paste_data_adapter_get_record_at = _struct->get_record_at;
      }
    } else {
      ark_paste_data_adapter_get_record_at =
          reinterpret_cast<ArkPasteDataAdapterGetRecordAtFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_data_adapter_get_record_at,
                                    nullptr);

  // Execute
  ark_paste_data_record_adapter_t* _retval =
      ark_paste_data_adapter_get_record_at(_struct, index);

  // Return type: refptr_same
  return ArkPasteDataRecordAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
size_t ArkPasteDataAdapterCToCpp::GetRecordCount() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_adapter_get_record_count);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "O24LS__j_snGwuYIB6DyMw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_paste_data_adapter_get_record_count");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_record_count)) {
        ark_paste_data_adapter_get_record_count = nullptr;
      } else {
        ark_paste_data_adapter_get_record_count = _struct->get_record_count;
      }
    } else {
      ark_paste_data_adapter_get_record_count =
          reinterpret_cast<ArkPasteDataAdapterGetRecordCountFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_data_adapter_get_record_count, 0);

  // Execute
  return ark_paste_data_adapter_get_record_count(_struct);
}

ARK_WEB_NO_SANITIZE
ArkPasteRecordVector ArkPasteDataAdapterCToCpp::AllRecords() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, {0});

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_adapter_all_records);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "TuFd5ktDvv8SRNmBM1RduQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_paste_data_adapter_all_records");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, all_records)) {
        ark_paste_data_adapter_all_records = nullptr;
      } else {
        ark_paste_data_adapter_all_records = _struct->all_records;
      }
    } else {
      ark_paste_data_adapter_all_records =
          reinterpret_cast<ArkPasteDataAdapterAllRecordsFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_data_adapter_all_records, {0});

  // Execute
  return ark_paste_data_adapter_all_records(_struct);
}

ArkPasteDataAdapterCToCpp::ArkPasteDataAdapterCToCpp() {}

ArkPasteDataAdapterCToCpp::~ArkPasteDataAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkPasteDataAdapterCToCpp,
                                        ArkPasteDataAdapter,
                                        ark_paste_data_adapter_t>::kBridgeType =
    ARK_PASTE_DATA_ADAPTER;

}  // namespace OHOS::ArkWeb
