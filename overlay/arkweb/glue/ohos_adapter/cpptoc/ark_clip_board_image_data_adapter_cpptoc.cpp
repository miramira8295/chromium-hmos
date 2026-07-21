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

#include "ohos_adapter/cpptoc/ark_clip_board_image_data_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

int32_t ARK_WEB_CALLBACK ark_clip_board_image_data_adapter_get_color_type(
    struct _ark_clip_board_image_data_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkClipBoardImageDataAdapterCppToC::Get(self)->GetColorType();
}

int32_t ARK_WEB_CALLBACK ark_clip_board_image_data_adapter_get_alpha_type(
    struct _ark_clip_board_image_data_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkClipBoardImageDataAdapterCppToC::Get(self)->GetAlphaType();
}

uint32_t* ARK_WEB_CALLBACK ark_clip_board_image_data_adapter_get_data(
    struct _ark_clip_board_image_data_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  return ArkClipBoardImageDataAdapterCppToC::Get(self)->GetData();
}

size_t ARK_WEB_CALLBACK ark_clip_board_image_data_adapter_get_data_size(
    struct _ark_clip_board_image_data_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkClipBoardImageDataAdapterCppToC::Get(self)->GetDataSize();
}

size_t ARK_WEB_CALLBACK ark_clip_board_image_data_adapter_get_row_bytes(
    struct _ark_clip_board_image_data_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkClipBoardImageDataAdapterCppToC::Get(self)->GetRowBytes();
}

int32_t ARK_WEB_CALLBACK ark_clip_board_image_data_adapter_get_width(
    struct _ark_clip_board_image_data_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkClipBoardImageDataAdapterCppToC::Get(self)->GetWidth();
}

int32_t ARK_WEB_CALLBACK ark_clip_board_image_data_adapter_get_height(
    struct _ark_clip_board_image_data_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkClipBoardImageDataAdapterCppToC::Get(self)->GetHeight();
}

void ARK_WEB_CALLBACK ark_clip_board_image_data_adapter_set_color_type(
    struct _ark_clip_board_image_data_adapter_t* self,
    int32_t color) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkClipBoardImageDataAdapterCppToC::Get(self)->SetColorType(color);
}

void ARK_WEB_CALLBACK ark_clip_board_image_data_adapter_set_alpha_type(
    struct _ark_clip_board_image_data_adapter_t* self,
    int32_t alpha) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkClipBoardImageDataAdapterCppToC::Get(self)->SetAlphaType(alpha);
}

void ARK_WEB_CALLBACK ark_clip_board_image_data_adapter_set_data(
    struct _ark_clip_board_image_data_adapter_t* self,
    uint32_t* data) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkClipBoardImageDataAdapterCppToC::Get(self)->SetData(data);
}

void ARK_WEB_CALLBACK ark_clip_board_image_data_adapter_set_data_size(
    struct _ark_clip_board_image_data_adapter_t* self,
    size_t size) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkClipBoardImageDataAdapterCppToC::Get(self)->SetDataSize(size);
}

void ARK_WEB_CALLBACK ark_clip_board_image_data_adapter_set_row_bytes(
    struct _ark_clip_board_image_data_adapter_t* self,
    size_t rowBytes) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkClipBoardImageDataAdapterCppToC::Get(self)->SetRowBytes(rowBytes);
}

void ARK_WEB_CALLBACK ark_clip_board_image_data_adapter_set_width(
    struct _ark_clip_board_image_data_adapter_t* self,
    int32_t width) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkClipBoardImageDataAdapterCppToC::Get(self)->SetWidth(width);
}

void ARK_WEB_CALLBACK ark_clip_board_image_data_adapter_set_height(
    struct _ark_clip_board_image_data_adapter_t* self,
    int32_t height) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkClipBoardImageDataAdapterCppToC::Get(self)->SetHeight(height);
}

}  // namespace

ArkClipBoardImageDataAdapterCppToC::ArkClipBoardImageDataAdapterCppToC() {
  GetStruct()->get_color_type =
      ark_clip_board_image_data_adapter_get_color_type;
  GetStruct()->get_alpha_type =
      ark_clip_board_image_data_adapter_get_alpha_type;
  GetStruct()->get_data = ark_clip_board_image_data_adapter_get_data;
  GetStruct()->get_data_size = ark_clip_board_image_data_adapter_get_data_size;
  GetStruct()->get_row_bytes = ark_clip_board_image_data_adapter_get_row_bytes;
  GetStruct()->get_width = ark_clip_board_image_data_adapter_get_width;
  GetStruct()->get_height = ark_clip_board_image_data_adapter_get_height;
  GetStruct()->set_color_type =
      ark_clip_board_image_data_adapter_set_color_type;
  GetStruct()->set_alpha_type =
      ark_clip_board_image_data_adapter_set_alpha_type;
  GetStruct()->set_data = ark_clip_board_image_data_adapter_set_data;
  GetStruct()->set_data_size = ark_clip_board_image_data_adapter_set_data_size;
  GetStruct()->set_row_bytes = ark_clip_board_image_data_adapter_set_row_bytes;
  GetStruct()->set_width = ark_clip_board_image_data_adapter_set_width;
  GetStruct()->set_height = ark_clip_board_image_data_adapter_set_height;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["Yv_980KXEJ9ge0jQgYK5KQ"] = reinterpret_cast<void*>(
        ark_clip_board_image_data_adapter_get_color_type);
    funcMemberMap["kgdOWHVWiditQAPcXuc7HA"] = reinterpret_cast<void*>(
        ark_clip_board_image_data_adapter_get_alpha_type);
    funcMemberMap["0oFkml__dA8RVRILUIke$Q"] =
        reinterpret_cast<void*>(ark_clip_board_image_data_adapter_get_data);
    funcMemberMap["NsY1sMQ23ODRmBPzTxWvog"] = reinterpret_cast<void*>(
        ark_clip_board_image_data_adapter_get_data_size);
    funcMemberMap["O70EEZVmT5w5jXtmz1L4eA"] = reinterpret_cast<void*>(
        ark_clip_board_image_data_adapter_get_row_bytes);
    funcMemberMap["Nujlxb3aNJO6J5E$kGzLkA"] =
        reinterpret_cast<void*>(ark_clip_board_image_data_adapter_get_width);
    funcMemberMap["LujA9m_p99fQZymZIa_Y7g"] =
        reinterpret_cast<void*>(ark_clip_board_image_data_adapter_get_height);
    funcMemberMap["tPy0s7iWy46cE$KLLZ9gUA"] = reinterpret_cast<void*>(
        ark_clip_board_image_data_adapter_set_color_type);
    funcMemberMap["nQPdyElqGd_Ft7zttEgL4Q"] = reinterpret_cast<void*>(
        ark_clip_board_image_data_adapter_set_alpha_type);
    funcMemberMap["bb32RTdV23KooDMmtRKhvQ"] =
        reinterpret_cast<void*>(ark_clip_board_image_data_adapter_set_data);
    funcMemberMap["bKef_kpg$jEa1M0$V1hwQA"] = reinterpret_cast<void*>(
        ark_clip_board_image_data_adapter_set_data_size);
    funcMemberMap["WcgPfywHd3roPh2JgKlplg"] = reinterpret_cast<void*>(
        ark_clip_board_image_data_adapter_set_row_bytes);
    funcMemberMap["bX4lPFSnlQ9s3TKi_CtNMw"] =
        reinterpret_cast<void*>(ark_clip_board_image_data_adapter_set_width);
    funcMemberMap["_Om1NXekqEM72f96j9Y37A"] =
        reinterpret_cast<void*>(ark_clip_board_image_data_adapter_set_height);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_CLIP_BOARD_IMAGE_DATA_ADAPTER, funcMemberMap);
  });
}

ArkClipBoardImageDataAdapterCppToC::~ArkClipBoardImageDataAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkClipBoardImageDataAdapterCppToC,
                           ArkClipBoardImageDataAdapter,
                           ark_clip_board_image_data_adapter_t>::kBridgeType =
        ARK_CLIP_BOARD_IMAGE_DATA_ADAPTER;

}  // namespace OHOS::ArkWeb
