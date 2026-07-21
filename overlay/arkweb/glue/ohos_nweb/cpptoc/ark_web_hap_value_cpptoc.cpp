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

#include "ohos_nweb/cpptoc/ark_web_hap_value_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

unsigned char ARK_WEB_CALLBACK
ark_web_hap_value_get_type(struct _ark_web_hap_value_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebHapValueCppToC::Get(self)->GetType();
}

void ARK_WEB_CALLBACK
ark_web_hap_value_set_type(struct _ark_web_hap_value_t* self,
                           unsigned char type) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebHapValueCppToC::Get(self)->SetType(type);
}

int ARK_WEB_CALLBACK
ark_web_hap_value_get_int(struct _ark_web_hap_value_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebHapValueCppToC::Get(self)->GetInt();
}

void ARK_WEB_CALLBACK
ark_web_hap_value_set_int(struct _ark_web_hap_value_t* self, int value) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebHapValueCppToC::Get(self)->SetInt(value);
}

bool ARK_WEB_CALLBACK
ark_web_hap_value_get_bool(struct _ark_web_hap_value_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, false);

  // Execute
  return ArkWebHapValueCppToC::Get(self)->GetBool();
}

void ARK_WEB_CALLBACK
ark_web_hap_value_set_bool(struct _ark_web_hap_value_t* self, bool value) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebHapValueCppToC::Get(self)->SetBool(value);
}

double ARK_WEB_CALLBACK
ark_web_hap_value_get_double(struct _ark_web_hap_value_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebHapValueCppToC::Get(self)->GetDouble();
}

void ARK_WEB_CALLBACK
ark_web_hap_value_set_double(struct _ark_web_hap_value_t* self, double value) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebHapValueCppToC::Get(self)->SetDouble(value);
}

ArkWebString ARK_WEB_CALLBACK
ark_web_hap_value_get_string(struct _ark_web_hap_value_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebHapValueCppToC::Get(self)->GetString();
}

void ARK_WEB_CALLBACK
ark_web_hap_value_set_string(struct _ark_web_hap_value_t* self,
                             const ArkWebString* value) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(value, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebHapValueCppToC::Get(self)->SetString(*value);
}

const char* ARK_WEB_CALLBACK
ark_web_hap_value_get_binary1(struct _ark_web_hap_value_t* self, int* length) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);
  ARK_WEB_CPPTOC_CHECK_PARAM(length, NULL);

  // Execute
  return ArkWebHapValueCppToC::Get(self)->GetBinary(*length);
}

void ARK_WEB_CALLBACK
ark_web_hap_value_set_binary1(struct _ark_web_hap_value_t* self,
                              int length,
                              const char* value) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebHapValueCppToC::Get(self)->SetBinary(length, value);
}

ArkWebHapValueMap ARK_WEB_CALLBACK
ark_web_hap_value_get_dict_value(struct _ark_web_hap_value_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_hap_value_map_default);

  // Execute
  return ArkWebHapValueCppToC::Get(self)->GetDictValue();
}

ArkWebHapValueVector ARK_WEB_CALLBACK
ark_web_hap_value_get_list_value(struct _ark_web_hap_value_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_hap_value_vector_default);

  // Execute
  return ArkWebHapValueCppToC::Get(self)->GetListValue();
}

ark_web_hap_value_t* ARK_WEB_CALLBACK
ark_web_hap_value_new_child_value(struct _ark_web_hap_value_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  ArkWebRefPtr<ArkWebHapValue> _retval =
      ArkWebHapValueCppToC::Get(self)->NewChildValue();

  // Return type: refptr_same
  return ArkWebHapValueCppToC::Invert(_retval);
}

void ARK_WEB_CALLBACK
ark_web_hap_value_save_dict_child_value(struct _ark_web_hap_value_t* self,
                                        const ArkWebString* key) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(key, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebHapValueCppToC::Get(self)->SaveDictChildValue(*key);
}

void ARK_WEB_CALLBACK
ark_web_hap_value_save_list_child_value(struct _ark_web_hap_value_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebHapValueCppToC::Get(self)->SaveListChildValue();
}

int64_t ARK_WEB_CALLBACK
ark_web_hap_value_get_int64(struct _ark_web_hap_value_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkWebHapValueCppToC::Get(self)->GetInt64();
}

void ARK_WEB_CALLBACK
ark_web_hap_value_set_int64(struct _ark_web_hap_value_t* self, int64_t value) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebHapValueCppToC::Get(self)->SetInt64(value);
}

ArkWebUint8Vector ARK_WEB_CALLBACK
ark_web_hap_value_get_binary2(struct _ark_web_hap_value_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_uint8_vector_default);

  // Execute
  return ArkWebHapValueCppToC::Get(self)->GetBinary();
}

void ARK_WEB_CALLBACK
ark_web_hap_value_set_binary2(struct _ark_web_hap_value_t* self,
                              const ArkWebUint8Vector* value) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(value, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebHapValueCppToC::Get(self)->SetBinary(*value);
}

ArkWebBooleanVector ARK_WEB_CALLBACK
ark_web_hap_value_get_bool_array(struct _ark_web_hap_value_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_boolean_vector_default);

  // Execute
  return ArkWebHapValueCppToC::Get(self)->GetBoolArray();
}

void ARK_WEB_CALLBACK
ark_web_hap_value_set_bool_array(struct _ark_web_hap_value_t* self,
                                 const ArkWebBooleanVector* value) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(value, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebHapValueCppToC::Get(self)->SetBoolArray(*value);
}

ArkWebInt64Vector ARK_WEB_CALLBACK
ark_web_hap_value_get_int64array(struct _ark_web_hap_value_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_int64_vector_default);

  // Execute
  return ArkWebHapValueCppToC::Get(self)->GetInt64Array();
}

void ARK_WEB_CALLBACK
ark_web_hap_value_set_int64array(struct _ark_web_hap_value_t* self,
                                 const ArkWebInt64Vector* value) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(value, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebHapValueCppToC::Get(self)->SetInt64Array(*value);
}

ArkWebDoubleVector ARK_WEB_CALLBACK
ark_web_hap_value_get_double_array(struct _ark_web_hap_value_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_double_vector_default);

  // Execute
  return ArkWebHapValueCppToC::Get(self)->GetDoubleArray();
}

void ARK_WEB_CALLBACK
ark_web_hap_value_set_double_array(struct _ark_web_hap_value_t* self,
                                   const ArkWebDoubleVector* value) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(value, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebHapValueCppToC::Get(self)->SetDoubleArray(*value);
}

ArkWebStringVector ARK_WEB_CALLBACK
ark_web_hap_value_get_string_array(struct _ark_web_hap_value_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_vector_default);

  // Execute
  return ArkWebHapValueCppToC::Get(self)->GetStringArray();
}

void ARK_WEB_CALLBACK
ark_web_hap_value_set_string_array(struct _ark_web_hap_value_t* self,
                                   const ArkWebStringVector* value) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(value, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebHapValueCppToC::Get(self)->SetStringArray(*value);
}

ArkWebString ARK_WEB_CALLBACK
ark_web_hap_value_get_err_msg(struct _ark_web_hap_value_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebHapValueCppToC::Get(self)->GetErrMsg();
}

void ARK_WEB_CALLBACK
ark_web_hap_value_set_err_msg(struct _ark_web_hap_value_t* self,
                              const ArkWebString* msg) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(msg, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebHapValueCppToC::Get(self)->SetErrMsg(*msg);
}

ArkWebString ARK_WEB_CALLBACK
ark_web_hap_value_get_err_name(struct _ark_web_hap_value_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_string_default);

  // Execute
  return ArkWebHapValueCppToC::Get(self)->GetErrName();
}

void ARK_WEB_CALLBACK
ark_web_hap_value_set_err_name(struct _ark_web_hap_value_t* self,
                               const ArkWebString* name) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(name, ARK_WEB_RETURN_VOID);

  // Execute
  ArkWebHapValueCppToC::Get(self)->SetErrName(*name);
}

}  // namespace

ArkWebHapValueCppToC::ArkWebHapValueCppToC() {
  GetStruct()->get_type = ark_web_hap_value_get_type;
  GetStruct()->set_type = ark_web_hap_value_set_type;
  GetStruct()->get_int = ark_web_hap_value_get_int;
  GetStruct()->set_int = ark_web_hap_value_set_int;
  GetStruct()->get_bool = ark_web_hap_value_get_bool;
  GetStruct()->set_bool = ark_web_hap_value_set_bool;
  GetStruct()->get_double = ark_web_hap_value_get_double;
  GetStruct()->set_double = ark_web_hap_value_set_double;
  GetStruct()->get_string = ark_web_hap_value_get_string;
  GetStruct()->set_string = ark_web_hap_value_set_string;
  GetStruct()->get_binary1 = ark_web_hap_value_get_binary1;
  GetStruct()->set_binary1 = ark_web_hap_value_set_binary1;
  GetStruct()->get_dict_value = ark_web_hap_value_get_dict_value;
  GetStruct()->get_list_value = ark_web_hap_value_get_list_value;
  GetStruct()->new_child_value = ark_web_hap_value_new_child_value;
  GetStruct()->save_dict_child_value = ark_web_hap_value_save_dict_child_value;
  GetStruct()->save_list_child_value = ark_web_hap_value_save_list_child_value;
  GetStruct()->get_int64 = ark_web_hap_value_get_int64;
  GetStruct()->set_int64 = ark_web_hap_value_set_int64;
  GetStruct()->get_binary2 = ark_web_hap_value_get_binary2;
  GetStruct()->set_binary2 = ark_web_hap_value_set_binary2;
  GetStruct()->get_bool_array = ark_web_hap_value_get_bool_array;
  GetStruct()->set_bool_array = ark_web_hap_value_set_bool_array;
  GetStruct()->get_int64array = ark_web_hap_value_get_int64array;
  GetStruct()->set_int64array = ark_web_hap_value_set_int64array;
  GetStruct()->get_double_array = ark_web_hap_value_get_double_array;
  GetStruct()->set_double_array = ark_web_hap_value_set_double_array;
  GetStruct()->get_string_array = ark_web_hap_value_get_string_array;
  GetStruct()->set_string_array = ark_web_hap_value_set_string_array;
  GetStruct()->get_err_msg = ark_web_hap_value_get_err_msg;
  GetStruct()->set_err_msg = ark_web_hap_value_set_err_msg;
  GetStruct()->get_err_name = ark_web_hap_value_get_err_name;
  GetStruct()->set_err_name = ark_web_hap_value_set_err_name;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["6satjtHTZH2hSlwa_xCeSg"] =
        reinterpret_cast<void*>(ark_web_hap_value_get_type);
    funcMemberMap["Gx6xmNtzNSZq6aUFum0UNw"] =
        reinterpret_cast<void*>(ark_web_hap_value_set_type);
    funcMemberMap["gT2VoUA5ATQCEQXzRO196A"] =
        reinterpret_cast<void*>(ark_web_hap_value_get_int);
    funcMemberMap["EFh$_IM4o3e5XWD5ZcQlkA"] =
        reinterpret_cast<void*>(ark_web_hap_value_set_int);
    funcMemberMap["dd7qaEWIIJtafg7kvKyBMA"] =
        reinterpret_cast<void*>(ark_web_hap_value_get_bool);
    funcMemberMap["AUZdJeYWfamsAM2h4E0FeA"] =
        reinterpret_cast<void*>(ark_web_hap_value_set_bool);
    funcMemberMap["qcmuIIj6O0rhDykufcRvig"] =
        reinterpret_cast<void*>(ark_web_hap_value_get_double);
    funcMemberMap["3rc6BVoxQx8qpTc0tiQrew"] =
        reinterpret_cast<void*>(ark_web_hap_value_set_double);
    funcMemberMap["bmM4zYh$vTo4wCh6WxuknA"] =
        reinterpret_cast<void*>(ark_web_hap_value_get_string);
    funcMemberMap["_1_SNeXolqZgSXCnNRLGSw"] =
        reinterpret_cast<void*>(ark_web_hap_value_set_string);
    funcMemberMap["4JODxl1PxARsCacqE2OAPQ"] =
        reinterpret_cast<void*>(ark_web_hap_value_get_binary1);
    funcMemberMap["yDlpNgt_BZIbHrQQRqvOvg"] =
        reinterpret_cast<void*>(ark_web_hap_value_set_binary1);
    funcMemberMap["CeA3KKGLgXijvWTQ0OoEhA"] =
        reinterpret_cast<void*>(ark_web_hap_value_get_dict_value);
    funcMemberMap["s0TvhNBl4X9RBFF5FMtY0g"] =
        reinterpret_cast<void*>(ark_web_hap_value_get_list_value);
    funcMemberMap["2pTKDplfYPhQ3lrHziC19A"] =
        reinterpret_cast<void*>(ark_web_hap_value_new_child_value);
    funcMemberMap["vnxhVjzFTXwXb4egO4Yyew"] =
        reinterpret_cast<void*>(ark_web_hap_value_save_dict_child_value);
    funcMemberMap["Y5VOdXkWvMsBF_zOAZIPkA"] =
        reinterpret_cast<void*>(ark_web_hap_value_save_list_child_value);
    funcMemberMap["jP5ySTUqyrNNL5fnuW5dhQ"] =
        reinterpret_cast<void*>(ark_web_hap_value_get_int64);
    funcMemberMap["umPq3WU756QjE$_v81Gbdg"] =
        reinterpret_cast<void*>(ark_web_hap_value_set_int64);
    funcMemberMap["40O8eIrn2JHpjYL$T9ovEw"] =
        reinterpret_cast<void*>(ark_web_hap_value_get_binary2);
    funcMemberMap["NywV$bYccdgQ76hXhYIlKQ"] =
        reinterpret_cast<void*>(ark_web_hap_value_set_binary2);
    funcMemberMap["Vb$g2b56Yzn2dIQHNKBEzQ"] =
        reinterpret_cast<void*>(ark_web_hap_value_get_bool_array);
    funcMemberMap["6NTJRhXCHMo7ajNCsim_fg"] =
        reinterpret_cast<void*>(ark_web_hap_value_set_bool_array);
    funcMemberMap["dcejz8qbObRE7mc3AcNGvg"] =
        reinterpret_cast<void*>(ark_web_hap_value_get_int64array);
    funcMemberMap["9UjG1nheRe__JWA5agzfTQ"] =
        reinterpret_cast<void*>(ark_web_hap_value_set_int64array);
    funcMemberMap["8zLebCUGfdB6f0ChHdT7VQ"] =
        reinterpret_cast<void*>(ark_web_hap_value_get_double_array);
    funcMemberMap["5Snhmi2AhvUChspK19QicA"] =
        reinterpret_cast<void*>(ark_web_hap_value_set_double_array);
    funcMemberMap["RvSNTsYcxFeKFWgHTuYUwg"] =
        reinterpret_cast<void*>(ark_web_hap_value_get_string_array);
    funcMemberMap["0FnT5P_xkue4DkNRZ3Zbuw"] =
        reinterpret_cast<void*>(ark_web_hap_value_set_string_array);
    funcMemberMap["0qYUUf0_rSLV2kBV2s2k_A"] =
        reinterpret_cast<void*>(ark_web_hap_value_get_err_msg);
    funcMemberMap["liX9Y90NbLrMees$cg1uUw"] =
        reinterpret_cast<void*>(ark_web_hap_value_set_err_msg);
    funcMemberMap["$fpa59IpdmmMmBcLeL5GwQ"] =
        reinterpret_cast<void*>(ark_web_hap_value_get_err_name);
    funcMemberMap["3_mMpltNkUVO372AAs56WA"] =
        reinterpret_cast<void*>(ark_web_hap_value_set_err_name);
    ArkWebNWebWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_WEB_HAP_VALUE, funcMemberMap);
  });
}

ArkWebHapValueCppToC::~ArkWebHapValueCppToC() {}

template <>
ArkWebBridgeType ArkWebCppToCRefCounted<ArkWebHapValueCppToC,
                                        ArkWebHapValue,
                                        ark_web_hap_value_t>::kBridgeType =
    ARK_WEB_HAP_VALUE;

}  // namespace OHOS::ArkWeb
