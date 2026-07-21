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

#include "ohos_nweb/ctocpp/ark_web_rom_value_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkWebRomValueGetTypeFunc =
    unsigned char (*)(struct _ark_web_rom_value_t* self);
static ArkWebRomValueGetTypeFunc ark_web_rom_value_get_type =
    reinterpret_cast<ArkWebRomValueGetTypeFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueSetTypeFunc = void (*)(struct _ark_web_rom_value_t* self,
                                           unsigned char type);
static ArkWebRomValueSetTypeFunc ark_web_rom_value_set_type =
    reinterpret_cast<ArkWebRomValueSetTypeFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueGetIntFunc = int (*)(struct _ark_web_rom_value_t* self);
static ArkWebRomValueGetIntFunc ark_web_rom_value_get_int =
    reinterpret_cast<ArkWebRomValueGetIntFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueSetIntFunc = void (*)(struct _ark_web_rom_value_t* self,
                                          int value);
static ArkWebRomValueSetIntFunc ark_web_rom_value_set_int =
    reinterpret_cast<ArkWebRomValueSetIntFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueGetBoolFunc = bool (*)(struct _ark_web_rom_value_t* self);
static ArkWebRomValueGetBoolFunc ark_web_rom_value_get_bool =
    reinterpret_cast<ArkWebRomValueGetBoolFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueSetBoolFunc = void (*)(struct _ark_web_rom_value_t* self,
                                           bool value);
static ArkWebRomValueSetBoolFunc ark_web_rom_value_set_bool =
    reinterpret_cast<ArkWebRomValueSetBoolFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueGetDoubleFunc =
    double (*)(struct _ark_web_rom_value_t* self);
static ArkWebRomValueGetDoubleFunc ark_web_rom_value_get_double =
    reinterpret_cast<ArkWebRomValueGetDoubleFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueSetDoubleFunc = void (*)(struct _ark_web_rom_value_t* self,
                                             double value);
static ArkWebRomValueSetDoubleFunc ark_web_rom_value_set_double =
    reinterpret_cast<ArkWebRomValueSetDoubleFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueGetStringFunc =
    ArkWebString (*)(struct _ark_web_rom_value_t* self);
static ArkWebRomValueGetStringFunc ark_web_rom_value_get_string =
    reinterpret_cast<ArkWebRomValueGetStringFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueSetStringFunc = void (*)(struct _ark_web_rom_value_t* self,
                                             const ArkWebString* value);
static ArkWebRomValueSetStringFunc ark_web_rom_value_set_string =
    reinterpret_cast<ArkWebRomValueSetStringFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueGetBinaryFunc1 =
    const char* (*)(struct _ark_web_rom_value_t* self, int* length);
static ArkWebRomValueGetBinaryFunc1 ark_web_rom_value_get_binary1 =
    reinterpret_cast<ArkWebRomValueGetBinaryFunc1>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueSetBinaryFunc1 = void (*)(struct _ark_web_rom_value_t* self,
                                              int length,
                                              const char* value);
static ArkWebRomValueSetBinaryFunc1 ark_web_rom_value_set_binary1 =
    reinterpret_cast<ArkWebRomValueSetBinaryFunc1>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueGetDictValueFunc =
    ArkWebRomValueMap (*)(struct _ark_web_rom_value_t* self);
static ArkWebRomValueGetDictValueFunc ark_web_rom_value_get_dict_value =
    reinterpret_cast<ArkWebRomValueGetDictValueFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueGetListValueFunc =
    ArkWebRomValueVector (*)(struct _ark_web_rom_value_t* self);
static ArkWebRomValueGetListValueFunc ark_web_rom_value_get_list_value =
    reinterpret_cast<ArkWebRomValueGetListValueFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueNewChildValueFunc =
    ark_web_rom_value_t* (*)(struct _ark_web_rom_value_t* self);
static ArkWebRomValueNewChildValueFunc ark_web_rom_value_new_child_value =
    reinterpret_cast<ArkWebRomValueNewChildValueFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueSaveDictChildValueFunc =
    void (*)(struct _ark_web_rom_value_t* self, const ArkWebString* key);
static ArkWebRomValueSaveDictChildValueFunc
    ark_web_rom_value_save_dict_child_value =
        reinterpret_cast<ArkWebRomValueSaveDictChildValueFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebRomValueSaveListChildValueFunc =
    void (*)(struct _ark_web_rom_value_t* self);
static ArkWebRomValueSaveListChildValueFunc
    ark_web_rom_value_save_list_child_value =
        reinterpret_cast<ArkWebRomValueSaveListChildValueFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebRomValueGetInt64Func =
    int64_t (*)(struct _ark_web_rom_value_t* self);
static ArkWebRomValueGetInt64Func ark_web_rom_value_get_int64 =
    reinterpret_cast<ArkWebRomValueGetInt64Func>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueSetInt64Func = void (*)(struct _ark_web_rom_value_t* self,
                                            int64_t value);
static ArkWebRomValueSetInt64Func ark_web_rom_value_set_int64 =
    reinterpret_cast<ArkWebRomValueSetInt64Func>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueGetBinaryFunc2 =
    ArkWebUint8Vector (*)(struct _ark_web_rom_value_t* self);
static ArkWebRomValueGetBinaryFunc2 ark_web_rom_value_get_binary2 =
    reinterpret_cast<ArkWebRomValueGetBinaryFunc2>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueSetBinaryFunc2 = void (*)(struct _ark_web_rom_value_t* self,
                                              const ArkWebUint8Vector* value);
static ArkWebRomValueSetBinaryFunc2 ark_web_rom_value_set_binary2 =
    reinterpret_cast<ArkWebRomValueSetBinaryFunc2>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueGetBoolArrayFunc =
    ArkWebBooleanVector (*)(struct _ark_web_rom_value_t* self);
static ArkWebRomValueGetBoolArrayFunc ark_web_rom_value_get_bool_array =
    reinterpret_cast<ArkWebRomValueGetBoolArrayFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueSetBoolArrayFunc =
    void (*)(struct _ark_web_rom_value_t* self,
             const ArkWebBooleanVector* value);
static ArkWebRomValueSetBoolArrayFunc ark_web_rom_value_set_bool_array =
    reinterpret_cast<ArkWebRomValueSetBoolArrayFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueGetInt64ArrayFunc =
    ArkWebInt64Vector (*)(struct _ark_web_rom_value_t* self);
static ArkWebRomValueGetInt64ArrayFunc ark_web_rom_value_get_int64array =
    reinterpret_cast<ArkWebRomValueGetInt64ArrayFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueSetInt64ArrayFunc =
    void (*)(struct _ark_web_rom_value_t* self, const ArkWebInt64Vector* value);
static ArkWebRomValueSetInt64ArrayFunc ark_web_rom_value_set_int64array =
    reinterpret_cast<ArkWebRomValueSetInt64ArrayFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueGetDoubleArrayFunc =
    ArkWebDoubleVector (*)(struct _ark_web_rom_value_t* self);
static ArkWebRomValueGetDoubleArrayFunc ark_web_rom_value_get_double_array =
    reinterpret_cast<ArkWebRomValueGetDoubleArrayFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueSetDoubleArrayFunc =
    void (*)(struct _ark_web_rom_value_t* self,
             const ArkWebDoubleVector* value);
static ArkWebRomValueSetDoubleArrayFunc ark_web_rom_value_set_double_array =
    reinterpret_cast<ArkWebRomValueSetDoubleArrayFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueGetStringArrayFunc =
    ArkWebStringVector (*)(struct _ark_web_rom_value_t* self);
static ArkWebRomValueGetStringArrayFunc ark_web_rom_value_get_string_array =
    reinterpret_cast<ArkWebRomValueGetStringArrayFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueSetStringArrayFunc =
    void (*)(struct _ark_web_rom_value_t* self,
             const ArkWebStringVector* value);
static ArkWebRomValueSetStringArrayFunc ark_web_rom_value_set_string_array =
    reinterpret_cast<ArkWebRomValueSetStringArrayFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueGetErrMsgFunc =
    ArkWebString (*)(struct _ark_web_rom_value_t* self);
static ArkWebRomValueGetErrMsgFunc ark_web_rom_value_get_err_msg =
    reinterpret_cast<ArkWebRomValueGetErrMsgFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueSetErrMsgFunc = void (*)(struct _ark_web_rom_value_t* self,
                                             const ArkWebString* msg);
static ArkWebRomValueSetErrMsgFunc ark_web_rom_value_set_err_msg =
    reinterpret_cast<ArkWebRomValueSetErrMsgFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueGetErrNameFunc =
    ArkWebString (*)(struct _ark_web_rom_value_t* self);
static ArkWebRomValueGetErrNameFunc ark_web_rom_value_get_err_name =
    reinterpret_cast<ArkWebRomValueGetErrNameFunc>(ARK_WEB_INIT_ADDR);

using ArkWebRomValueSetErrNameFunc = void (*)(struct _ark_web_rom_value_t* self,
                                              const ArkWebString* name);
static ArkWebRomValueSetErrNameFunc ark_web_rom_value_set_err_name =
    reinterpret_cast<ArkWebRomValueSetErrNameFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
unsigned char ArkWebRomValueCToCpp::GetType() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_get_type);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "TAQXtBkoTOKRMfHLRHwxHQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_get_type");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_type)) {
        ark_web_rom_value_get_type = nullptr;
      } else {
        ark_web_rom_value_get_type = _struct->get_type;
      }
    } else {
      ark_web_rom_value_get_type =
          reinterpret_cast<ArkWebRomValueGetTypeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_get_type, 0);

  // Execute
  return ark_web_rom_value_get_type(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebRomValueCToCpp::SetType(unsigned char type) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_set_type);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ta0CTaExq2k3zHDa8VnyHA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_set_type");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_type)) {
        ark_web_rom_value_set_type = nullptr;
      } else {
        ark_web_rom_value_set_type = _struct->set_type;
      }
    } else {
      ark_web_rom_value_set_type =
          reinterpret_cast<ArkWebRomValueSetTypeFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_set_type,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_rom_value_set_type(_struct, type);
}

ARK_WEB_NO_SANITIZE
int ArkWebRomValueCToCpp::GetInt() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_get_int);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "6aSj1oUvDfM0zqB79tkuHA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_get_int");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_int)) {
        ark_web_rom_value_get_int = nullptr;
      } else {
        ark_web_rom_value_get_int = _struct->get_int;
      }
    } else {
      ark_web_rom_value_get_int =
          reinterpret_cast<ArkWebRomValueGetIntFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_get_int, 0);

  // Execute
  return ark_web_rom_value_get_int(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebRomValueCToCpp::SetInt(int value) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_set_int);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Ad0K23sAXnhZ24tdMr$m7w";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_set_int");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_int)) {
        ark_web_rom_value_set_int = nullptr;
      } else {
        ark_web_rom_value_set_int = _struct->set_int;
      }
    } else {
      ark_web_rom_value_set_int =
          reinterpret_cast<ArkWebRomValueSetIntFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_set_int,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_rom_value_set_int(_struct, value);
}

ARK_WEB_NO_SANITIZE
bool ArkWebRomValueCToCpp::GetBool() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_get_bool);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "0ME1ZGVxPzTANsa9AVm$nA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_get_bool");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_bool)) {
        ark_web_rom_value_get_bool = nullptr;
      } else {
        ark_web_rom_value_get_bool = _struct->get_bool;
      }
    } else {
      ark_web_rom_value_get_bool =
          reinterpret_cast<ArkWebRomValueGetBoolFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_get_bool, false);

  // Execute
  return ark_web_rom_value_get_bool(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebRomValueCToCpp::SetBool(bool value) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_set_bool);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "aGx_ZJ88YmDl72hgMXx_2g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_set_bool");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_bool)) {
        ark_web_rom_value_set_bool = nullptr;
      } else {
        ark_web_rom_value_set_bool = _struct->set_bool;
      }
    } else {
      ark_web_rom_value_set_bool =
          reinterpret_cast<ArkWebRomValueSetBoolFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_set_bool,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_rom_value_set_bool(_struct, value);
}

ARK_WEB_NO_SANITIZE
double ArkWebRomValueCToCpp::GetDouble() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_get_double);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ElQt9pqVFtl5KLOhne$hGA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_get_double");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_double)) {
        ark_web_rom_value_get_double = nullptr;
      } else {
        ark_web_rom_value_get_double = _struct->get_double;
      }
    } else {
      ark_web_rom_value_get_double =
          reinterpret_cast<ArkWebRomValueGetDoubleFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_get_double, 0);

  // Execute
  return ark_web_rom_value_get_double(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebRomValueCToCpp::SetDouble(double value) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_set_double);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "_tgOSsL3j6PzJu3AcV6M4g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_set_double");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_double)) {
        ark_web_rom_value_set_double = nullptr;
      } else {
        ark_web_rom_value_set_double = _struct->set_double;
      }
    } else {
      ark_web_rom_value_set_double =
          reinterpret_cast<ArkWebRomValueSetDoubleFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_set_double,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_rom_value_set_double(_struct, value);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkWebRomValueCToCpp::GetString() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_get_string);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "C1Q7yHq23iAaD068L$6Asg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_get_string");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_string)) {
        ark_web_rom_value_get_string = nullptr;
      } else {
        ark_web_rom_value_get_string = _struct->get_string;
      }
    } else {
      ark_web_rom_value_get_string =
          reinterpret_cast<ArkWebRomValueGetStringFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_get_string,
                                    ark_web_string_default);

  // Execute
  return ark_web_rom_value_get_string(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebRomValueCToCpp::SetString(const ArkWebString& value) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_set_string);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "RzfTmoEDw$E7uegGyk4v2g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_set_string");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_string)) {
        ark_web_rom_value_set_string = nullptr;
      } else {
        ark_web_rom_value_set_string = _struct->set_string;
      }
    } else {
      ark_web_rom_value_set_string =
          reinterpret_cast<ArkWebRomValueSetStringFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_set_string,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_rom_value_set_string(_struct, &value);
}

ARK_WEB_NO_SANITIZE
const char* ArkWebRomValueCToCpp::GetBinary(int& length) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_get_binary1);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "raIrUdhY8neNEvLf0PEx0w";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_get_binary1");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_binary1)) {
        ark_web_rom_value_get_binary1 = nullptr;
      } else {
        ark_web_rom_value_get_binary1 = _struct->get_binary1;
      }
    } else {
      ark_web_rom_value_get_binary1 =
          reinterpret_cast<ArkWebRomValueGetBinaryFunc1>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_get_binary1, nullptr);

  // Execute
  return ark_web_rom_value_get_binary1(_struct, &length);
}

ARK_WEB_NO_SANITIZE
void ArkWebRomValueCToCpp::SetBinary(int length, const char* value) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_set_binary1);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "bFw7tglgYlHF2jUgKq9qVw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_set_binary1");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_binary1)) {
        ark_web_rom_value_set_binary1 = nullptr;
      } else {
        ark_web_rom_value_set_binary1 = _struct->set_binary1;
      }
    } else {
      ark_web_rom_value_set_binary1 =
          reinterpret_cast<ArkWebRomValueSetBinaryFunc1>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_set_binary1,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_rom_value_set_binary1(_struct, length, value);
}

ARK_WEB_NO_SANITIZE
ArkWebRomValueMap ArkWebRomValueCToCpp::GetDictValue() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_rom_value_map_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_rom_value_get_dict_value);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "vL0BGE8aiFS2aKNYGwHuRQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_get_dict_value");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_dict_value)) {
        ark_web_rom_value_get_dict_value = nullptr;
      } else {
        ark_web_rom_value_get_dict_value = _struct->get_dict_value;
      }
    } else {
      ark_web_rom_value_get_dict_value =
          reinterpret_cast<ArkWebRomValueGetDictValueFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_get_dict_value,
                                    ark_web_rom_value_map_default);

  // Execute
  return ark_web_rom_value_get_dict_value(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebRomValueVector ArkWebRomValueCToCpp::GetListValue() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_rom_value_vector_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_rom_value_get_list_value);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "cUuq5G5UOx$IiZBUOxkXiA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_get_list_value");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_list_value)) {
        ark_web_rom_value_get_list_value = nullptr;
      } else {
        ark_web_rom_value_get_list_value = _struct->get_list_value;
      }
    } else {
      ark_web_rom_value_get_list_value =
          reinterpret_cast<ArkWebRomValueGetListValueFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_get_list_value,
                                    ark_web_rom_value_vector_default);

  // Execute
  return ark_web_rom_value_get_list_value(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkWebRomValue> ArkWebRomValueCToCpp::NewChildValue() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_rom_value_new_child_value);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "YTFB9Wl0c0D9mKYzNpXDhA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_new_child_value");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, new_child_value)) {
        ark_web_rom_value_new_child_value = nullptr;
      } else {
        ark_web_rom_value_new_child_value = _struct->new_child_value;
      }
    } else {
      ark_web_rom_value_new_child_value =
          reinterpret_cast<ArkWebRomValueNewChildValueFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_new_child_value, nullptr);

  // Execute
  ark_web_rom_value_t* _retval = ark_web_rom_value_new_child_value(_struct);

  // Return type: refptr_same
  return ArkWebRomValueCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
void ArkWebRomValueCToCpp::SaveDictChildValue(const ArkWebString& key) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_rom_value_save_dict_child_value);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "aB0nKrPiHWNu98w1Tvszng";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_save_dict_child_value");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, save_dict_child_value)) {
        ark_web_rom_value_save_dict_child_value = nullptr;
      } else {
        ark_web_rom_value_save_dict_child_value =
            _struct->save_dict_child_value;
      }
    } else {
      ark_web_rom_value_save_dict_child_value =
          reinterpret_cast<ArkWebRomValueSaveDictChildValueFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_save_dict_child_value,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_rom_value_save_dict_child_value(_struct, &key);
}

ARK_WEB_NO_SANITIZE
void ArkWebRomValueCToCpp::SaveListChildValue() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_rom_value_save_list_child_value);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ybXIke664RTP0MCpwW1cag";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_save_list_child_value");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, save_list_child_value)) {
        ark_web_rom_value_save_list_child_value = nullptr;
      } else {
        ark_web_rom_value_save_list_child_value =
            _struct->save_list_child_value;
      }
    } else {
      ark_web_rom_value_save_list_child_value =
          reinterpret_cast<ArkWebRomValueSaveListChildValueFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_save_list_child_value,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_rom_value_save_list_child_value(_struct);
}

ARK_WEB_NO_SANITIZE
int64_t ArkWebRomValueCToCpp::GetInt64() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_get_int64);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "9HfBV5fReKQ3hAv0M9C57g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_get_int64");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_int64)) {
        ark_web_rom_value_get_int64 = nullptr;
      } else {
        ark_web_rom_value_get_int64 = _struct->get_int64;
      }
    } else {
      ark_web_rom_value_get_int64 =
          reinterpret_cast<ArkWebRomValueGetInt64Func>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_get_int64, 0);

  // Execute
  return ark_web_rom_value_get_int64(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebRomValueCToCpp::SetInt64(int64_t value) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_set_int64);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "$v27W5dpplsGhQxrxZuc8g";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_set_int64");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_int64)) {
        ark_web_rom_value_set_int64 = nullptr;
      } else {
        ark_web_rom_value_set_int64 = _struct->set_int64;
      }
    } else {
      ark_web_rom_value_set_int64 =
          reinterpret_cast<ArkWebRomValueSetInt64Func>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_set_int64,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_rom_value_set_int64(_struct, value);
}

ARK_WEB_NO_SANITIZE
ArkWebUint8Vector ArkWebRomValueCToCpp::GetBinary() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_uint8_vector_default);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_get_binary2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "KGHYrBWXMKqHLnfEEfeTLA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_get_binary2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_binary2)) {
        ark_web_rom_value_get_binary2 = nullptr;
      } else {
        ark_web_rom_value_get_binary2 = _struct->get_binary2;
      }
    } else {
      ark_web_rom_value_get_binary2 =
          reinterpret_cast<ArkWebRomValueGetBinaryFunc2>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_get_binary2,
                                    ark_web_uint8_vector_default);

  // Execute
  return ark_web_rom_value_get_binary2(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebRomValueCToCpp::SetBinary(const ArkWebUint8Vector& value) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_set_binary2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ToTV8hV6tiJuJAjFI$Jmqw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_set_binary2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_binary2)) {
        ark_web_rom_value_set_binary2 = nullptr;
      } else {
        ark_web_rom_value_set_binary2 = _struct->set_binary2;
      }
    } else {
      ark_web_rom_value_set_binary2 =
          reinterpret_cast<ArkWebRomValueSetBinaryFunc2>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_set_binary2,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_rom_value_set_binary2(_struct, &value);
}

ARK_WEB_NO_SANITIZE
ArkWebBooleanVector ArkWebRomValueCToCpp::GetBoolArray() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_boolean_vector_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_rom_value_get_bool_array);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "RF5ZAkQTGzRzlnwoo_4asg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_get_bool_array");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_bool_array)) {
        ark_web_rom_value_get_bool_array = nullptr;
      } else {
        ark_web_rom_value_get_bool_array = _struct->get_bool_array;
      }
    } else {
      ark_web_rom_value_get_bool_array =
          reinterpret_cast<ArkWebRomValueGetBoolArrayFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_get_bool_array,
                                    ark_web_boolean_vector_default);

  // Execute
  return ark_web_rom_value_get_bool_array(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebRomValueCToCpp::SetBoolArray(const ArkWebBooleanVector& value) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_rom_value_set_bool_array);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ACbOMduQNmmXkn8Litl9PQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_set_bool_array");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_bool_array)) {
        ark_web_rom_value_set_bool_array = nullptr;
      } else {
        ark_web_rom_value_set_bool_array = _struct->set_bool_array;
      }
    } else {
      ark_web_rom_value_set_bool_array =
          reinterpret_cast<ArkWebRomValueSetBoolArrayFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_set_bool_array,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_rom_value_set_bool_array(_struct, &value);
}

ARK_WEB_NO_SANITIZE
ArkWebInt64Vector ArkWebRomValueCToCpp::GetInt64Array() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_int64_vector_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_rom_value_get_int64array);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "zx3BlqQ7TmAxWLYqrz1VUA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_get_int64array");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_int64array)) {
        ark_web_rom_value_get_int64array = nullptr;
      } else {
        ark_web_rom_value_get_int64array = _struct->get_int64array;
      }
    } else {
      ark_web_rom_value_get_int64array =
          reinterpret_cast<ArkWebRomValueGetInt64ArrayFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_get_int64array,
                                    ark_web_int64_vector_default);

  // Execute
  return ark_web_rom_value_get_int64array(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebRomValueCToCpp::SetInt64Array(const ArkWebInt64Vector& value) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_rom_value_set_int64array);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "1UcJjapnUXr7i5RSr7BYXw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_set_int64array");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_int64array)) {
        ark_web_rom_value_set_int64array = nullptr;
      } else {
        ark_web_rom_value_set_int64array = _struct->set_int64array;
      }
    } else {
      ark_web_rom_value_set_int64array =
          reinterpret_cast<ArkWebRomValueSetInt64ArrayFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_set_int64array,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_rom_value_set_int64array(_struct, &value);
}

ARK_WEB_NO_SANITIZE
ArkWebDoubleVector ArkWebRomValueCToCpp::GetDoubleArray() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_double_vector_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_rom_value_get_double_array);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jnsVweye0MfFJaxzv$tflA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_get_double_array");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_double_array)) {
        ark_web_rom_value_get_double_array = nullptr;
      } else {
        ark_web_rom_value_get_double_array = _struct->get_double_array;
      }
    } else {
      ark_web_rom_value_get_double_array =
          reinterpret_cast<ArkWebRomValueGetDoubleArrayFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_get_double_array,
                                    ark_web_double_vector_default);

  // Execute
  return ark_web_rom_value_get_double_array(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebRomValueCToCpp::SetDoubleArray(const ArkWebDoubleVector& value) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_rom_value_set_double_array);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "3$VCNECu_7ikvv2W$zi3Gw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_set_double_array");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_double_array)) {
        ark_web_rom_value_set_double_array = nullptr;
      } else {
        ark_web_rom_value_set_double_array = _struct->set_double_array;
      }
    } else {
      ark_web_rom_value_set_double_array =
          reinterpret_cast<ArkWebRomValueSetDoubleArrayFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_set_double_array,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_rom_value_set_double_array(_struct, &value);
}

ARK_WEB_NO_SANITIZE
ArkWebStringVector ArkWebRomValueCToCpp::GetStringArray() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_vector_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_rom_value_get_string_array);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "RaQSbnaOZIyYEs2a1CCkQg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_get_string_array");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_string_array)) {
        ark_web_rom_value_get_string_array = nullptr;
      } else {
        ark_web_rom_value_get_string_array = _struct->get_string_array;
      }
    } else {
      ark_web_rom_value_get_string_array =
          reinterpret_cast<ArkWebRomValueGetStringArrayFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_get_string_array,
                                    ark_web_string_vector_default);

  // Execute
  return ark_web_rom_value_get_string_array(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebRomValueCToCpp::SetStringArray(const ArkWebStringVector& value) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_web_rom_value_set_string_array);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "BdAPJM11BuWD4uSeCC6kQQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_set_string_array");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_string_array)) {
        ark_web_rom_value_set_string_array = nullptr;
      } else {
        ark_web_rom_value_set_string_array = _struct->set_string_array;
      }
    } else {
      ark_web_rom_value_set_string_array =
          reinterpret_cast<ArkWebRomValueSetStringArrayFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_set_string_array,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_rom_value_set_string_array(_struct, &value);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkWebRomValueCToCpp::GetErrMsg() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_get_err_msg);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "amqx$je9VEuyGnahSYFADg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_get_err_msg");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_err_msg)) {
        ark_web_rom_value_get_err_msg = nullptr;
      } else {
        ark_web_rom_value_get_err_msg = _struct->get_err_msg;
      }
    } else {
      ark_web_rom_value_get_err_msg =
          reinterpret_cast<ArkWebRomValueGetErrMsgFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_get_err_msg,
                                    ark_web_string_default);

  // Execute
  return ark_web_rom_value_get_err_msg(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebRomValueCToCpp::SetErrMsg(const ArkWebString& msg) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_set_err_msg);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "vtVAkgGqz3dAHo_JY8EbQw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_set_err_msg");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_err_msg)) {
        ark_web_rom_value_set_err_msg = nullptr;
      } else {
        ark_web_rom_value_set_err_msg = _struct->set_err_msg;
      }
    } else {
      ark_web_rom_value_set_err_msg =
          reinterpret_cast<ArkWebRomValueSetErrMsgFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_set_err_msg,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_rom_value_set_err_msg(_struct, &msg);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkWebRomValueCToCpp::GetErrName() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_get_err_name);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "yIauEEXop1EkjldMNFmLSQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_get_err_name");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_err_name)) {
        ark_web_rom_value_get_err_name = nullptr;
      } else {
        ark_web_rom_value_get_err_name = _struct->get_err_name;
      }
    } else {
      ark_web_rom_value_get_err_name =
          reinterpret_cast<ArkWebRomValueGetErrNameFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_get_err_name,
                                    ark_web_string_default);

  // Execute
  return ark_web_rom_value_get_err_name(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkWebRomValueCToCpp::SetErrName(const ArkWebString& name) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_rom_value_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(ark_web_rom_value_set_err_name);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "SoQ6zJVv2HTRkqlfUE8SJg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_ROM_VALUE, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_web_rom_value_set_err_name");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_err_name)) {
        ark_web_rom_value_set_err_name = nullptr;
      } else {
        ark_web_rom_value_set_err_name = _struct->set_err_name;
      }
    } else {
      ark_web_rom_value_set_err_name =
          reinterpret_cast<ArkWebRomValueSetErrNameFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_web_rom_value_set_err_name,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_rom_value_set_err_name(_struct, &name);
}

ArkWebRomValueCToCpp::ArkWebRomValueCToCpp() {}

ArkWebRomValueCToCpp::~ArkWebRomValueCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkWebRomValueCToCpp,
                                        ArkWebRomValue,
                                        ark_web_rom_value_t>::kBridgeType =
    ARK_WEB_ROM_VALUE;

}  // namespace OHOS::ArkWeb
