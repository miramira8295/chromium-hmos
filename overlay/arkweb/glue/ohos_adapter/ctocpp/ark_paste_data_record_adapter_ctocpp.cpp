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

#include "ohos_adapter/ctocpp/ark_paste_data_record_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_clip_board_image_data_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkPasteDataRecordAdapterNewRecordFunc1 =
    ark_paste_data_record_adapter_t* (*)(const ArkWebString* mimeType);
static ArkPasteDataRecordAdapterNewRecordFunc1
    ark_paste_data_record_adapter_new_record1 =
        reinterpret_cast<ArkPasteDataRecordAdapterNewRecordFunc1>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterNewRecordFunc2 =
    ark_paste_data_record_adapter_t* (*)(const ArkWebString* mimeType,
                                         void* htmlText,
                                         void* plainText);
static ArkPasteDataRecordAdapterNewRecordFunc2
    ark_paste_data_record_adapter_new_record2 =
        reinterpret_cast<ArkPasteDataRecordAdapterNewRecordFunc2>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterSetHtmlTextFunc =
    bool (*)(struct _ark_paste_data_record_adapter_t* self, void* htmlText);
static ArkPasteDataRecordAdapterSetHtmlTextFunc
    ark_paste_data_record_adapter_set_html_text =
        reinterpret_cast<ArkPasteDataRecordAdapterSetHtmlTextFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterSetPlainTextFunc =
    bool (*)(struct _ark_paste_data_record_adapter_t* self, void* plainText);
static ArkPasteDataRecordAdapterSetPlainTextFunc
    ark_paste_data_record_adapter_set_plain_text =
        reinterpret_cast<ArkPasteDataRecordAdapterSetPlainTextFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterSetImgDataFunc =
    bool (*)(struct _ark_paste_data_record_adapter_t* self,
             ark_clip_board_image_data_adapter_t* imageData);
static ArkPasteDataRecordAdapterSetImgDataFunc
    ark_paste_data_record_adapter_set_img_data =
        reinterpret_cast<ArkPasteDataRecordAdapterSetImgDataFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterGetMimeTypeFunc =
    ArkWebString (*)(struct _ark_paste_data_record_adapter_t* self);
static ArkPasteDataRecordAdapterGetMimeTypeFunc
    ark_paste_data_record_adapter_get_mime_type =
        reinterpret_cast<ArkPasteDataRecordAdapterGetMimeTypeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterGetHtmlTextFunc =
    void (*)(struct _ark_paste_data_record_adapter_t* self, void* data);
static ArkPasteDataRecordAdapterGetHtmlTextFunc
    ark_paste_data_record_adapter_get_html_text =
        reinterpret_cast<ArkPasteDataRecordAdapterGetHtmlTextFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterGetPlainTextFunc =
    void (*)(struct _ark_paste_data_record_adapter_t* self, void* data);
static ArkPasteDataRecordAdapterGetPlainTextFunc
    ark_paste_data_record_adapter_get_plain_text =
        reinterpret_cast<ArkPasteDataRecordAdapterGetPlainTextFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterGetImgDataFunc =
    bool (*)(struct _ark_paste_data_record_adapter_t* self,
             ark_clip_board_image_data_adapter_t* imageData);
static ArkPasteDataRecordAdapterGetImgDataFunc
    ark_paste_data_record_adapter_get_img_data =
        reinterpret_cast<ArkPasteDataRecordAdapterGetImgDataFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterSetUriFunc =
    bool (*)(struct _ark_paste_data_record_adapter_t* self,
             const ArkWebString* uriString);
static ArkPasteDataRecordAdapterSetUriFunc
    ark_paste_data_record_adapter_set_uri =
        reinterpret_cast<ArkPasteDataRecordAdapterSetUriFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterSetCustomDataFunc =
    bool (*)(struct _ark_paste_data_record_adapter_t* self, void* data);
static ArkPasteDataRecordAdapterSetCustomDataFunc
    ark_paste_data_record_adapter_set_custom_data =
        reinterpret_cast<ArkPasteDataRecordAdapterSetCustomDataFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterGetUriFunc =
    void (*)(struct _ark_paste_data_record_adapter_t* self, void* data);
static ArkPasteDataRecordAdapterGetUriFunc
    ark_paste_data_record_adapter_get_uri =
        reinterpret_cast<ArkPasteDataRecordAdapterGetUriFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterGetCustomDataFunc =
    void (*)(struct _ark_paste_data_record_adapter_t* self, void* data);
static ArkPasteDataRecordAdapterGetCustomDataFunc
    ark_paste_data_record_adapter_get_custom_data =
        reinterpret_cast<ArkPasteDataRecordAdapterGetCustomDataFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterSetHtmlTextV2Func =
    bool (*)(struct _ark_paste_data_record_adapter_t* self,
             const ArkWebString* htmlText);
static ArkPasteDataRecordAdapterSetHtmlTextV2Func
    ark_paste_data_record_adapter_set_html_text_v2 =
        reinterpret_cast<ArkPasteDataRecordAdapterSetHtmlTextV2Func>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterSetPlainTextV2Func =
    bool (*)(struct _ark_paste_data_record_adapter_t* self,
             const ArkWebString* plainText);
static ArkPasteDataRecordAdapterSetPlainTextV2Func
    ark_paste_data_record_adapter_set_plain_text_v2 =
        reinterpret_cast<ArkPasteDataRecordAdapterSetPlainTextV2Func>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterGetHtmlTextV2Func =
    bool (*)(struct _ark_paste_data_record_adapter_t* self, ArkWebString* data);
static ArkPasteDataRecordAdapterGetHtmlTextV2Func
    ark_paste_data_record_adapter_get_html_text_v2 =
        reinterpret_cast<ArkPasteDataRecordAdapterGetHtmlTextV2Func>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterGetPlainTextV2Func =
    bool (*)(struct _ark_paste_data_record_adapter_t* self, ArkWebString* data);
static ArkPasteDataRecordAdapterGetPlainTextV2Func
    ark_paste_data_record_adapter_get_plain_text_v2 =
        reinterpret_cast<ArkPasteDataRecordAdapterGetPlainTextV2Func>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterSetCustomDataV2Func =
    bool (*)(struct _ark_paste_data_record_adapter_t* self,
             ArkWebUInt8VectorMap* data);
static ArkPasteDataRecordAdapterSetCustomDataV2Func
    ark_paste_data_record_adapter_set_custom_data_v2 =
        reinterpret_cast<ArkPasteDataRecordAdapterSetCustomDataV2Func>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterGetUriV2Func =
    bool (*)(struct _ark_paste_data_record_adapter_t* self, ArkWebString* data);
static ArkPasteDataRecordAdapterGetUriV2Func
    ark_paste_data_record_adapter_get_uri_v2 =
        reinterpret_cast<ArkPasteDataRecordAdapterGetUriV2Func>(
            ARK_WEB_INIT_ADDR);

using ArkPasteDataRecordAdapterGetCustomDataV2Func =
    bool (*)(struct _ark_paste_data_record_adapter_t* self,
             ArkWebUInt8VectorMap* data);
static ArkPasteDataRecordAdapterGetCustomDataV2Func
    ark_paste_data_record_adapter_get_custom_data_v2 =
        reinterpret_cast<ArkPasteDataRecordAdapterGetCustomDataV2Func>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkPasteDataRecordAdapter> ArkPasteDataRecordAdapter::NewRecord(
    const ArkWebString& mimeType) {
  ARK_WEB_CTOCPP_DV_LOG();

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_new_record1);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const char* funcName =
        "ark_paste_data_record_adapter_new_record1_static";
    ark_paste_data_record_adapter_new_record1 =
        reinterpret_cast<ArkPasteDataRecordAdapterNewRecordFunc1>(
            ArkWebAdapterWebcoreBridgeHelper::GetInstance().LoadFuncSymbol(
                funcName));
  }

  if (!ark_paste_data_record_adapter_new_record1) {
    ARK_WEB_CTOCPP_WARN_LOG(
        "failed to load func ark_paste_data_record_adapter_new_record1_static");
    return nullptr;
  }

  // Execute
  ark_paste_data_record_adapter_t* _retval =
      ark_paste_data_record_adapter_new_record1(&mimeType);

  // Return type: refptr_same
  return ArkPasteDataRecordAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkPasteDataRecordAdapter> ArkPasteDataRecordAdapter::NewRecord(
    const ArkWebString& mimeType,
    void* htmlText,
    void* plainText) {
  ARK_WEB_CTOCPP_DV_LOG();

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_new_record2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const char* funcName =
        "ark_paste_data_record_adapter_new_record2_static";
    ark_paste_data_record_adapter_new_record2 =
        reinterpret_cast<ArkPasteDataRecordAdapterNewRecordFunc2>(
            ArkWebAdapterWebcoreBridgeHelper::GetInstance().LoadFuncSymbol(
                funcName));
  }

  if (!ark_paste_data_record_adapter_new_record2) {
    ARK_WEB_CTOCPP_WARN_LOG(
        "failed to load func ark_paste_data_record_adapter_new_record2_static");
    return nullptr;
  }

  // Execute
  ark_paste_data_record_adapter_t* _retval =
      ark_paste_data_record_adapter_new_record2(&mimeType, htmlText, plainText);

  // Return type: refptr_same
  return ArkPasteDataRecordAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
bool ArkPasteDataRecordAdapterCToCpp::SetHtmlText(void* htmlText) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_set_html_text);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "1aj0BOxfenGfo5OGQtcu9g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_data_record_adapter_set_html_text");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_html_text)) {
        ark_paste_data_record_adapter_set_html_text = nullptr;
      } else {
        ark_paste_data_record_adapter_set_html_text = _struct->set_html_text;
      }
    } else {
      ark_paste_data_record_adapter_set_html_text =
          reinterpret_cast<ArkPasteDataRecordAdapterSetHtmlTextFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_data_record_adapter_set_html_text,
                                    false);

  // Execute
  return ark_paste_data_record_adapter_set_html_text(_struct, htmlText);
}

ARK_WEB_NO_SANITIZE
bool ArkPasteDataRecordAdapterCToCpp::SetPlainText(void* plainText) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_set_plain_text);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "S$3YuDXxkJ0Bc5mdXieMnA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_data_record_adapter_set_plain_text");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_plain_text)) {
        ark_paste_data_record_adapter_set_plain_text = nullptr;
      } else {
        ark_paste_data_record_adapter_set_plain_text = _struct->set_plain_text;
      }
    } else {
      ark_paste_data_record_adapter_set_plain_text =
          reinterpret_cast<ArkPasteDataRecordAdapterSetPlainTextFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_data_record_adapter_set_plain_text, false);

  // Execute
  return ark_paste_data_record_adapter_set_plain_text(_struct, plainText);
}

ARK_WEB_NO_SANITIZE
bool ArkPasteDataRecordAdapterCToCpp::SetImgData(
    ArkWebRefPtr<ArkClipBoardImageDataAdapter> imageData) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_set_img_data);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "uOd2jafCwQgVtHHdFOlxUQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_data_record_adapter_set_img_data");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_img_data)) {
        ark_paste_data_record_adapter_set_img_data = nullptr;
      } else {
        ark_paste_data_record_adapter_set_img_data = _struct->set_img_data;
      }
    } else {
      ark_paste_data_record_adapter_set_img_data =
          reinterpret_cast<ArkPasteDataRecordAdapterSetImgDataFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_data_record_adapter_set_img_data,
                                    false);

  // Execute
  return ark_paste_data_record_adapter_set_img_data(
      _struct, ArkClipBoardImageDataAdapterCppToC::Invert(imageData));
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkPasteDataRecordAdapterCToCpp::GetMimeType() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_get_mime_type);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "dOza6V8MWHPzVBFKgvCfYQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_data_record_adapter_get_mime_type");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_mime_type)) {
        ark_paste_data_record_adapter_get_mime_type = nullptr;
      } else {
        ark_paste_data_record_adapter_get_mime_type = _struct->get_mime_type;
      }
    } else {
      ark_paste_data_record_adapter_get_mime_type =
          reinterpret_cast<ArkPasteDataRecordAdapterGetMimeTypeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_data_record_adapter_get_mime_type,
                                    ark_web_string_default);

  // Execute
  return ark_paste_data_record_adapter_get_mime_type(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkPasteDataRecordAdapterCToCpp::GetHtmlText(void* data) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_get_html_text);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "kT$GKl0XAS$ZHxnRG0UlJw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_data_record_adapter_get_html_text");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_html_text)) {
        ark_paste_data_record_adapter_get_html_text = nullptr;
      } else {
        ark_paste_data_record_adapter_get_html_text = _struct->get_html_text;
      }
    } else {
      ark_paste_data_record_adapter_get_html_text =
          reinterpret_cast<ArkPasteDataRecordAdapterGetHtmlTextFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_data_record_adapter_get_html_text,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_paste_data_record_adapter_get_html_text(_struct, data);
}

ARK_WEB_NO_SANITIZE
void ArkPasteDataRecordAdapterCToCpp::GetPlainText(void* data) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_get_plain_text);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "9wPW5S8cLSeMyuZJLqoNNQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_data_record_adapter_get_plain_text");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_plain_text)) {
        ark_paste_data_record_adapter_get_plain_text = nullptr;
      } else {
        ark_paste_data_record_adapter_get_plain_text = _struct->get_plain_text;
      }
    } else {
      ark_paste_data_record_adapter_get_plain_text =
          reinterpret_cast<ArkPasteDataRecordAdapterGetPlainTextFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_data_record_adapter_get_plain_text, ARK_WEB_RETURN_VOID);

  // Execute
  ark_paste_data_record_adapter_get_plain_text(_struct, data);
}

ARK_WEB_NO_SANITIZE
bool ArkPasteDataRecordAdapterCToCpp::GetImgData(
    ArkWebRefPtr<ArkClipBoardImageDataAdapter> imageData) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_get_img_data);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "FaWkjBexIpuDDMeRSnIoGg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_data_record_adapter_get_img_data");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_img_data)) {
        ark_paste_data_record_adapter_get_img_data = nullptr;
      } else {
        ark_paste_data_record_adapter_get_img_data = _struct->get_img_data;
      }
    } else {
      ark_paste_data_record_adapter_get_img_data =
          reinterpret_cast<ArkPasteDataRecordAdapterGetImgDataFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_data_record_adapter_get_img_data,
                                    false);

  // Execute
  return ark_paste_data_record_adapter_get_img_data(
      _struct, ArkClipBoardImageDataAdapterCppToC::Invert(imageData));
}

ARK_WEB_NO_SANITIZE
bool ArkPasteDataRecordAdapterCToCpp::SetUri(const ArkWebString& uriString) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_set_uri);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "RzjR1sw__rN$$sS3GTPA8g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_paste_data_record_adapter_set_uri");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_uri)) {
        ark_paste_data_record_adapter_set_uri = nullptr;
      } else {
        ark_paste_data_record_adapter_set_uri = _struct->set_uri;
      }
    } else {
      ark_paste_data_record_adapter_set_uri =
          reinterpret_cast<ArkPasteDataRecordAdapterSetUriFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_data_record_adapter_set_uri,
                                    false);

  // Execute
  return ark_paste_data_record_adapter_set_uri(_struct, &uriString);
}

ARK_WEB_NO_SANITIZE
bool ArkPasteDataRecordAdapterCToCpp::SetCustomData(void* data) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_set_custom_data);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "WNzHdDiTemenoAMqaBzCHA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_data_record_adapter_set_custom_data");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_custom_data)) {
        ark_paste_data_record_adapter_set_custom_data = nullptr;
      } else {
        ark_paste_data_record_adapter_set_custom_data =
            _struct->set_custom_data;
      }
    } else {
      ark_paste_data_record_adapter_set_custom_data =
          reinterpret_cast<ArkPasteDataRecordAdapterSetCustomDataFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_data_record_adapter_set_custom_data, false);

  // Execute
  return ark_paste_data_record_adapter_set_custom_data(_struct, data);
}

ARK_WEB_NO_SANITIZE
void ArkPasteDataRecordAdapterCToCpp::GetUri(void* data) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_get_uri);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "4mbBscX27j4uVVZOKljBuQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_paste_data_record_adapter_get_uri");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_uri)) {
        ark_paste_data_record_adapter_get_uri = nullptr;
      } else {
        ark_paste_data_record_adapter_get_uri = _struct->get_uri;
      }
    } else {
      ark_paste_data_record_adapter_get_uri =
          reinterpret_cast<ArkPasteDataRecordAdapterGetUriFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_data_record_adapter_get_uri,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_paste_data_record_adapter_get_uri(_struct, data);
}

ARK_WEB_NO_SANITIZE
void ArkPasteDataRecordAdapterCToCpp::GetCustomData(void* data) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_get_custom_data);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "T3PfNUCDMm1VXPhtZT08Jw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_data_record_adapter_get_custom_data");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_custom_data)) {
        ark_paste_data_record_adapter_get_custom_data = nullptr;
      } else {
        ark_paste_data_record_adapter_get_custom_data =
            _struct->get_custom_data;
      }
    } else {
      ark_paste_data_record_adapter_get_custom_data =
          reinterpret_cast<ArkPasteDataRecordAdapterGetCustomDataFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_data_record_adapter_get_custom_data, ARK_WEB_RETURN_VOID);

  // Execute
  ark_paste_data_record_adapter_get_custom_data(_struct, data);
}

ARK_WEB_NO_SANITIZE
bool ArkPasteDataRecordAdapterCToCpp::SetHtmlTextV2(
    const ArkWebString& htmlText) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_set_html_text_v2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "DaX$b5GGeidO_5G_m8vLOw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_data_record_adapter_set_html_text_v2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_html_text_v2)) {
        ark_paste_data_record_adapter_set_html_text_v2 = nullptr;
      } else {
        ark_paste_data_record_adapter_set_html_text_v2 =
            _struct->set_html_text_v2;
      }
    } else {
      ark_paste_data_record_adapter_set_html_text_v2 =
          reinterpret_cast<ArkPasteDataRecordAdapterSetHtmlTextV2Func>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_data_record_adapter_set_html_text_v2, false);

  // Execute
  return ark_paste_data_record_adapter_set_html_text_v2(_struct, &htmlText);
}

ARK_WEB_NO_SANITIZE
bool ArkPasteDataRecordAdapterCToCpp::SetPlainTextV2(
    const ArkWebString& plainText) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_set_plain_text_v2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "be335ITU28tWwVUDRxc3qA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_data_record_adapter_set_plain_text_v2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_plain_text_v2)) {
        ark_paste_data_record_adapter_set_plain_text_v2 = nullptr;
      } else {
        ark_paste_data_record_adapter_set_plain_text_v2 =
            _struct->set_plain_text_v2;
      }
    } else {
      ark_paste_data_record_adapter_set_plain_text_v2 =
          reinterpret_cast<ArkPasteDataRecordAdapterSetPlainTextV2Func>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_data_record_adapter_set_plain_text_v2, false);

  // Execute
  return ark_paste_data_record_adapter_set_plain_text_v2(_struct, &plainText);
}

ARK_WEB_NO_SANITIZE
bool ArkPasteDataRecordAdapterCToCpp::GetHtmlTextV2(ArkWebString& data) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_get_html_text_v2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "SpzO5rlc6T7BtgrcZqKyRw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_data_record_adapter_get_html_text_v2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_html_text_v2)) {
        ark_paste_data_record_adapter_get_html_text_v2 = nullptr;
      } else {
        ark_paste_data_record_adapter_get_html_text_v2 =
            _struct->get_html_text_v2;
      }
    } else {
      ark_paste_data_record_adapter_get_html_text_v2 =
          reinterpret_cast<ArkPasteDataRecordAdapterGetHtmlTextV2Func>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_data_record_adapter_get_html_text_v2, false);

  // Execute
  return ark_paste_data_record_adapter_get_html_text_v2(_struct, &data);
}

ARK_WEB_NO_SANITIZE
bool ArkPasteDataRecordAdapterCToCpp::GetPlainTextV2(ArkWebString& data) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_get_plain_text_v2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "FRcX1FblIqPkaWeyTTHqrQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_data_record_adapter_get_plain_text_v2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_plain_text_v2)) {
        ark_paste_data_record_adapter_get_plain_text_v2 = nullptr;
      } else {
        ark_paste_data_record_adapter_get_plain_text_v2 =
            _struct->get_plain_text_v2;
      }
    } else {
      ark_paste_data_record_adapter_get_plain_text_v2 =
          reinterpret_cast<ArkPasteDataRecordAdapterGetPlainTextV2Func>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_data_record_adapter_get_plain_text_v2, false);

  // Execute
  return ark_paste_data_record_adapter_get_plain_text_v2(_struct, &data);
}

ARK_WEB_NO_SANITIZE
bool ArkPasteDataRecordAdapterCToCpp::SetCustomDataV2(
    ArkWebUInt8VectorMap& data) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_set_custom_data_v2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "o8quLyZXsBKdCSidV$TjJg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_data_record_adapter_set_custom_data_v2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_custom_data_v2)) {
        ark_paste_data_record_adapter_set_custom_data_v2 = nullptr;
      } else {
        ark_paste_data_record_adapter_set_custom_data_v2 =
            _struct->set_custom_data_v2;
      }
    } else {
      ark_paste_data_record_adapter_set_custom_data_v2 =
          reinterpret_cast<ArkPasteDataRecordAdapterSetCustomDataV2Func>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_data_record_adapter_set_custom_data_v2, false);

  // Execute
  return ark_paste_data_record_adapter_set_custom_data_v2(_struct, &data);
}

ARK_WEB_NO_SANITIZE
bool ArkPasteDataRecordAdapterCToCpp::GetUriV2(ArkWebString& data) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_get_uri_v2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "b09oRj25o_wYTmBR$_eecw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_data_record_adapter_get_uri_v2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_uri_v2)) {
        ark_paste_data_record_adapter_get_uri_v2 = nullptr;
      } else {
        ark_paste_data_record_adapter_get_uri_v2 = _struct->get_uri_v2;
      }
    } else {
      ark_paste_data_record_adapter_get_uri_v2 =
          reinterpret_cast<ArkPasteDataRecordAdapterGetUriV2Func>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_data_record_adapter_get_uri_v2,
                                    false);

  // Execute
  return ark_paste_data_record_adapter_get_uri_v2(_struct, &data);
}

ARK_WEB_NO_SANITIZE
bool ArkPasteDataRecordAdapterCToCpp::GetCustomDataV2(
    ArkWebUInt8VectorMap& data) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_data_record_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_data_record_adapter_get_custom_data_v2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "4$kVfyyX4zPbTEA0zQo$7w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_DATA_RECORD_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_data_record_adapter_get_custom_data_v2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_custom_data_v2)) {
        ark_paste_data_record_adapter_get_custom_data_v2 = nullptr;
      } else {
        ark_paste_data_record_adapter_get_custom_data_v2 =
            _struct->get_custom_data_v2;
      }
    } else {
      ark_paste_data_record_adapter_get_custom_data_v2 =
          reinterpret_cast<ArkPasteDataRecordAdapterGetCustomDataV2Func>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_data_record_adapter_get_custom_data_v2, false);

  // Execute
  return ark_paste_data_record_adapter_get_custom_data_v2(_struct, &data);
}

ArkPasteDataRecordAdapterCToCpp::ArkPasteDataRecordAdapterCToCpp() {}

ArkPasteDataRecordAdapterCToCpp::~ArkPasteDataRecordAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkPasteDataRecordAdapterCToCpp,
                           ArkPasteDataRecordAdapter,
                           ark_paste_data_record_adapter_t>::kBridgeType =
        ARK_PASTE_DATA_RECORD_ADAPTER;

}  // namespace OHOS::ArkWeb
