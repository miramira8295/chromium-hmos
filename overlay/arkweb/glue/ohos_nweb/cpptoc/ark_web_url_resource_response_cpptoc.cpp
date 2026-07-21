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

#include "ohos_nweb/cpptoc/ark_web_url_resource_response_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"
#include "ohos_nweb/ctocpp/ark_web_resource_ready_callback_ctocpp.h"

namespace OHOS::ArkWeb {

namespace {

ArkWebString ARK_WEB_CALLBACK ark_web_url_resource_response_response_data(
    struct _ark_web_url_resource_response_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebUrlResourceResponseCppToC::Get(self)->ResponseData();
}

void ARK_WEB_CALLBACK ark_web_url_resource_response_put_response_data(
    struct _ark_web_url_resource_response_t* self,
    const ArkWebString* input_stream) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(input_stream, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebUrlResourceResponseCppToC::Get(self)->PutResponseData(*input_stream);
}

ArkWebString ARK_WEB_CALLBACK ark_web_url_resource_response_response_status(
    struct _ark_web_url_resource_response_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebUrlResourceResponseCppToC::Get(self)->ResponseStatus();
}

const ArkWebStringMap ARK_WEB_CALLBACK
ark_web_url_resource_response_response_headers(
    struct _ark_web_url_resource_response_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_map_default);

  // Execute
  return ArkWebUrlResourceResponseCppToC::Get(self)->ResponseHeaders();
}

void ARK_WEB_CALLBACK ark_web_url_resource_response_put_response_headers(
    struct _ark_web_url_resource_response_t* self,
    const ArkWebStringMap* response_headers) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(response_headers, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebUrlResourceResponseCppToC::Get(self)->PutResponseHeaders(
      *response_headers);
}

int32_t ARK_WEB_CALLBACK ark_web_url_resource_response_response_data_type(
    struct _ark_web_url_resource_response_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebUrlResourceResponseCppToC::Get(self)->ResponseDataType();
}

ArkWebString ARK_WEB_CALLBACK ark_web_url_resource_response_response_mime_type(
    struct _ark_web_url_resource_response_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebUrlResourceResponseCppToC::Get(self)->ResponseMimeType();
}

void ARK_WEB_CALLBACK ark_web_url_resource_response_put_response_mime_type(
    struct _ark_web_url_resource_response_t* self,
    const ArkWebString* mime_type) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(mime_type, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebUrlResourceResponseCppToC::Get(self)->PutResponseMimeType(*mime_type);
}

ArkWebString ARK_WEB_CALLBACK ark_web_url_resource_response_response_encoding(
    struct _ark_web_url_resource_response_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebUrlResourceResponseCppToC::Get(self)->ResponseEncoding();
}

void ARK_WEB_CALLBACK ark_web_url_resource_response_put_response_encoding(
    struct _ark_web_url_resource_response_t* self,
    const ArkWebString* encoding) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(encoding, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebUrlResourceResponseCppToC::Get(self)->PutResponseEncoding(*encoding);
}

bool ARK_WEB_CALLBACK ark_web_url_resource_response_response_data_status(
    struct _ark_web_url_resource_response_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebUrlResourceResponseCppToC::Get(self)->ResponseDataStatus();
}

void ARK_WEB_CALLBACK ark_web_url_resource_response_put_response_data_status(
    struct _ark_web_url_resource_response_t* self,
    bool is_data_ready) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebUrlResourceResponseCppToC::Get(self)->PutResponseDataStatus(
      is_data_ready);
}

int ARK_WEB_CALLBACK ark_web_url_resource_response_response_status_code(
    struct _ark_web_url_resource_response_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebUrlResourceResponseCppToC::Get(self)->ResponseStatusCode();
}

ArkWebString ARK_WEB_CALLBACK
ark_web_url_resource_response_response_resource_url(
    struct _ark_web_url_resource_response_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebUrlResourceResponseCppToC::Get(self)->ResponseResourceUrl();
}

void ARK_WEB_CALLBACK ark_web_url_resource_response_put_response_resource_url(
    struct _ark_web_url_resource_response_t* self,
    const ArkWebString* url) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(url, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebUrlResourceResponseCppToC::Get(self)->PutResponseResourceUrl(*url);
}

int ARK_WEB_CALLBACK ark_web_url_resource_response_response_file_handle(
    struct _ark_web_url_resource_response_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebUrlResourceResponseCppToC::Get(self)->ResponseFileHandle();
}

void ARK_WEB_CALLBACK ark_web_url_resource_response_put_response_file_handle(
    struct _ark_web_url_resource_response_t* self,
    int fd) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebUrlResourceResponseCppToC::Get(self)->PutResponseFileHandle(fd);
}

bool ARK_WEB_CALLBACK ark_web_url_resource_response_response_is_file_handle(
    struct _ark_web_url_resource_response_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebUrlResourceResponseCppToC::Get(self)->ResponseIsFileHandle();
}

void ARK_WEB_CALLBACK
ark_web_url_resource_response_put_response_state_and_statuscode(
    struct _ark_web_url_resource_response_t* self,
    int status_code,
    const ArkWebString* reason_phrase) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(reason_phrase, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebUrlResourceResponseCppToC::Get(self)->PutResponseStateAndStatuscode(
      status_code, *reason_phrase);
}

void ARK_WEB_CALLBACK ark_web_url_resource_response_put_response_ready_callback(
    struct _ark_web_url_resource_response_t* self,
    ark_web_resource_ready_callback_t* callback) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebUrlResourceResponseCppToC::Get(self)->PutResponseReadyCallback(
      ArkWebResourceReadyCallbackCToCpp::Invert(callback));
}

void ARK_WEB_CALLBACK ark_web_url_resource_response_put_response_data_buffer(
    struct _ark_web_url_resource_response_t* self,
    char* buffer,
    size_t bufferSize) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebUrlResourceResponseCppToC::Get(self)->PutResponseDataBuffer(buffer,
                                                                    bufferSize);
}

char* ARK_WEB_CALLBACK ark_web_url_resource_response_get_response_data_buffer(
    struct _ark_web_url_resource_response_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  return ArkWebUrlResourceResponseCppToC::Get(self)->GetResponseDataBuffer();
}

size_t ARK_WEB_CALLBACK
ark_web_url_resource_response_get_response_data_buffer_size(
    struct _ark_web_url_resource_response_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebUrlResourceResponseCppToC::Get(self)
      ->GetResponseDataBufferSize();
}

}  // namespace

ArkWebUrlResourceResponseCppToC::ArkWebUrlResourceResponseCppToC() {
  GetStruct()->response_data = ark_web_url_resource_response_response_data;
  GetStruct()->put_response_data =
      ark_web_url_resource_response_put_response_data;
  GetStruct()->response_status = ark_web_url_resource_response_response_status;
  GetStruct()->response_headers =
      ark_web_url_resource_response_response_headers;
  GetStruct()->put_response_headers =
      ark_web_url_resource_response_put_response_headers;
  GetStruct()->response_data_type =
      ark_web_url_resource_response_response_data_type;
  GetStruct()->response_mime_type =
      ark_web_url_resource_response_response_mime_type;
  GetStruct()->put_response_mime_type =
      ark_web_url_resource_response_put_response_mime_type;
  GetStruct()->response_encoding =
      ark_web_url_resource_response_response_encoding;
  GetStruct()->put_response_encoding =
      ark_web_url_resource_response_put_response_encoding;
  GetStruct()->response_data_status =
      ark_web_url_resource_response_response_data_status;
  GetStruct()->put_response_data_status =
      ark_web_url_resource_response_put_response_data_status;
  GetStruct()->response_status_code =
      ark_web_url_resource_response_response_status_code;
  GetStruct()->response_resource_url =
      ark_web_url_resource_response_response_resource_url;
  GetStruct()->put_response_resource_url =
      ark_web_url_resource_response_put_response_resource_url;
  GetStruct()->response_file_handle =
      ark_web_url_resource_response_response_file_handle;
  GetStruct()->put_response_file_handle =
      ark_web_url_resource_response_put_response_file_handle;
  GetStruct()->response_is_file_handle =
      ark_web_url_resource_response_response_is_file_handle;
  GetStruct()->put_response_state_and_statuscode =
      ark_web_url_resource_response_put_response_state_and_statuscode;
  GetStruct()->put_response_ready_callback =
      ark_web_url_resource_response_put_response_ready_callback;
  GetStruct()->put_response_data_buffer =
      ark_web_url_resource_response_put_response_data_buffer;
  GetStruct()->get_response_data_buffer =
      ark_web_url_resource_response_get_response_data_buffer;
  GetStruct()->get_response_data_buffer_size =
      ark_web_url_resource_response_get_response_data_buffer_size;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["qocxZKkkoagd7QrEnqHrJA"] =
        reinterpret_cast<void*>(ark_web_url_resource_response_response_data);
    funcMemberMap["JmyuCRLbvSVbRMv9t_a63Q"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_put_response_data);
    funcMemberMap["giJXNbeXExhzbLW$VU0uJg"] =
        reinterpret_cast<void*>(ark_web_url_resource_response_response_status);
    funcMemberMap["2pUwuBMoFkJT16E8Hx6MuA"] =
        reinterpret_cast<void*>(ark_web_url_resource_response_response_headers);
    funcMemberMap["FQ0ptx2pEXPEytFzOyqnlg"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_put_response_headers);
    funcMemberMap["w8o6JnDYugGAacTX4Tm_qA"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_response_data_type);
    funcMemberMap["VrwPEQKVJ3laLC6PCwk5gQ"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_response_mime_type);
    funcMemberMap["MLrN$D9Z$gPHF8gy6T_eYA"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_put_response_mime_type);
    funcMemberMap["pKNEVraYaNBbYIvXjlSqrg"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_response_encoding);
    funcMemberMap["fapYJHJS1K_xCcKRgQiUBQ"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_put_response_encoding);
    funcMemberMap["4vllS0SEkt6lU1EPdQwhkQ"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_response_data_status);
    funcMemberMap["mN680TomGzojml$jjErQpA"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_put_response_data_status);
    funcMemberMap["15QAzXr2TnjCS0cIu0gJbg"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_response_status_code);
    funcMemberMap["AIDdtM5rJ4ajRHW78kILGQ"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_response_resource_url);
    funcMemberMap["pc4z2s6ov_mrqjFC9ijApw"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_put_response_resource_url);
    funcMemberMap["hTdQtV_$qlRcMK6TWCwGqA"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_response_file_handle);
    funcMemberMap["WgPjxIh0B1qvBqydBYqcHQ"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_put_response_file_handle);
    funcMemberMap["vvB21oG37S2pEAqmmRHPng"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_response_is_file_handle);
    funcMemberMap["EMBonoqSO$PLcPNIGpTBLQ"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_put_response_state_and_statuscode);
    funcMemberMap["14BFhAkV9YVGOJmkNc5FfQ"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_put_response_ready_callback);
    funcMemberMap["0hEDJ83pwjkQikSCYJYyCQ"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_put_response_data_buffer);
    funcMemberMap["6Oid_xJ6lCn4VhTSjhP5jA"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_get_response_data_buffer);
    funcMemberMap["JWdCKuKDbaWR8me7iLyhXw"] = reinterpret_cast<void*>(
        ark_web_url_resource_response_get_response_data_buffer_size);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_URL_RESOURCE_RESPONSE, funcMemberMap);
  });
}

ArkWebUrlResourceResponseCppToC::~ArkWebUrlResourceResponseCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkWebUrlResourceResponseCppToC,
                           ArkWebUrlResourceResponse,
                           ark_web_url_resource_response_t>::kBridgeType =
        ARK_WEB_URL_RESOURCE_RESPONSE;

}  // namespace OHOS::ArkWeb
