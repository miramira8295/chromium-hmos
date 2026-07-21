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

#include "ohos_adapter/ctocpp/ark_ohos_resource_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/ctocpp/ark_ohos_file_mapper_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkOhosResourceAdapterGetRawFileDataFunc =
    bool (*)(struct _ark_ohos_resource_adapter_t* self,
             const ArkWebString* rawFile,
             size_t* len,
             uint8_t** dest,
             bool isSys);
static ArkOhosResourceAdapterGetRawFileDataFunc
    ark_ohos_resource_adapter_get_raw_file_data =
        reinterpret_cast<ArkOhosResourceAdapterGetRawFileDataFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosResourceAdapterGetRawFileMapperFunc =
    ark_ohos_file_mapper_t* (*)(struct _ark_ohos_resource_adapter_t* self,
                                const ArkWebString* rawFile,
                                bool isSys);
static ArkOhosResourceAdapterGetRawFileMapperFunc
    ark_ohos_resource_adapter_get_raw_file_mapper =
        reinterpret_cast<ArkOhosResourceAdapterGetRawFileMapperFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosResourceAdapterIsRawFileExistFunc =
    bool (*)(struct _ark_ohos_resource_adapter_t* self,
             const ArkWebString* rawFile,
             bool isSys);
static ArkOhosResourceAdapterIsRawFileExistFunc
    ark_ohos_resource_adapter_is_raw_file_exist =
        reinterpret_cast<ArkOhosResourceAdapterIsRawFileExistFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosResourceAdapterGetRawFileLastModTimeFunc1 =
    bool (*)(struct _ark_ohos_resource_adapter_t* self,
             const ArkWebString* rawFile,
             uint16_t* date,
             uint16_t* time,
             bool isSys);
static ArkOhosResourceAdapterGetRawFileLastModTimeFunc1
    ark_ohos_resource_adapter_get_raw_file_last_mod_time1 =
        reinterpret_cast<ArkOhosResourceAdapterGetRawFileLastModTimeFunc1>(
            ARK_WEB_INIT_ADDR);

using ArkOhosResourceAdapterGetRawFileLastModTimeFunc2 =
    bool (*)(struct _ark_ohos_resource_adapter_t* self,
             const ArkWebString* rawFile,
             time_t* time,
             bool isSys);
static ArkOhosResourceAdapterGetRawFileLastModTimeFunc2
    ark_ohos_resource_adapter_get_raw_file_last_mod_time2 =
        reinterpret_cast<ArkOhosResourceAdapterGetRawFileLastModTimeFunc2>(
            ARK_WEB_INIT_ADDR);

using ArkOhosResourceAdapterGetSystemLanguageFunc =
    ArkWebString (*)(struct _ark_ohos_resource_adapter_t* self);
static ArkOhosResourceAdapterGetSystemLanguageFunc
    ark_ohos_resource_adapter_get_system_language =
        reinterpret_cast<ArkOhosResourceAdapterGetSystemLanguageFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
bool ArkOhosResourceAdapterCToCpp::GetRawFileData(const ArkWebString& rawFile,
                                                  size_t& len,
                                                  uint8_t** dest,
                                                  bool isSys) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_resource_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_resource_adapter_get_raw_file_data);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "s9ZvgFEGmruJwZR7DOVaLA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_RESOURCE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_resource_adapter_get_raw_file_data");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_raw_file_data)) {
        ark_ohos_resource_adapter_get_raw_file_data = nullptr;
      } else {
        ark_ohos_resource_adapter_get_raw_file_data =
            _struct->get_raw_file_data;
      }
    } else {
      ark_ohos_resource_adapter_get_raw_file_data =
          reinterpret_cast<ArkOhosResourceAdapterGetRawFileDataFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_resource_adapter_get_raw_file_data,
                                    false);

  // Execute
  return ark_ohos_resource_adapter_get_raw_file_data(_struct, &rawFile, &len,
                                                     dest, isSys);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkOhosFileMapper> ArkOhosResourceAdapterCToCpp::GetRawFileMapper(
    const ArkWebString& rawFile,
    bool isSys) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_resource_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_resource_adapter_get_raw_file_mapper);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ATB9KVpi6MEvJoKnI38I0g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_RESOURCE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_resource_adapter_get_raw_file_mapper");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_raw_file_mapper)) {
        ark_ohos_resource_adapter_get_raw_file_mapper = nullptr;
      } else {
        ark_ohos_resource_adapter_get_raw_file_mapper =
            _struct->get_raw_file_mapper;
      }
    } else {
      ark_ohos_resource_adapter_get_raw_file_mapper =
          reinterpret_cast<ArkOhosResourceAdapterGetRawFileMapperFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_resource_adapter_get_raw_file_mapper, nullptr);

  // Execute
  ark_ohos_file_mapper_t* _retval =
      ark_ohos_resource_adapter_get_raw_file_mapper(_struct, &rawFile, isSys);

  // Return type: refptr_same
  return ArkOhosFileMapperCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
bool ArkOhosResourceAdapterCToCpp::IsRawFileExist(const ArkWebString& rawFile,
                                                  bool isSys) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_resource_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_resource_adapter_is_raw_file_exist);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "4Q4y89UE_54QuQBgL6viTg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_RESOURCE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_resource_adapter_is_raw_file_exist");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_raw_file_exist)) {
        ark_ohos_resource_adapter_is_raw_file_exist = nullptr;
      } else {
        ark_ohos_resource_adapter_is_raw_file_exist =
            _struct->is_raw_file_exist;
      }
    } else {
      ark_ohos_resource_adapter_is_raw_file_exist =
          reinterpret_cast<ArkOhosResourceAdapterIsRawFileExistFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_resource_adapter_is_raw_file_exist,
                                    false);

  // Execute
  return ark_ohos_resource_adapter_is_raw_file_exist(_struct, &rawFile, isSys);
}

ARK_WEB_NO_SANITIZE
bool ArkOhosResourceAdapterCToCpp::GetRawFileLastModTime(
    const ArkWebString& rawFile,
    uint16_t& date,
    uint16_t& time,
    bool isSys) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_resource_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_resource_adapter_get_raw_file_last_mod_time1);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "4z2956PlUolfCCjVgXp2cQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_RESOURCE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_resource_adapter_get_raw_file_last_mod_time1");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_raw_file_last_mod_time1)) {
        ark_ohos_resource_adapter_get_raw_file_last_mod_time1 = nullptr;
      } else {
        ark_ohos_resource_adapter_get_raw_file_last_mod_time1 =
            _struct->get_raw_file_last_mod_time1;
      }
    } else {
      ark_ohos_resource_adapter_get_raw_file_last_mod_time1 =
          reinterpret_cast<ArkOhosResourceAdapterGetRawFileLastModTimeFunc1>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_resource_adapter_get_raw_file_last_mod_time1, false);

  // Execute
  return ark_ohos_resource_adapter_get_raw_file_last_mod_time1(
      _struct, &rawFile, &date, &time, isSys);
}

ARK_WEB_NO_SANITIZE
bool ArkOhosResourceAdapterCToCpp::GetRawFileLastModTime(
    const ArkWebString& rawFile,
    time_t& time,
    bool isSys) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_resource_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_resource_adapter_get_raw_file_last_mod_time2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "8TzixHmHe2VhtX6ljME2wA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_RESOURCE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_resource_adapter_get_raw_file_last_mod_time2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_raw_file_last_mod_time2)) {
        ark_ohos_resource_adapter_get_raw_file_last_mod_time2 = nullptr;
      } else {
        ark_ohos_resource_adapter_get_raw_file_last_mod_time2 =
            _struct->get_raw_file_last_mod_time2;
      }
    } else {
      ark_ohos_resource_adapter_get_raw_file_last_mod_time2 =
          reinterpret_cast<ArkOhosResourceAdapterGetRawFileLastModTimeFunc2>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_resource_adapter_get_raw_file_last_mod_time2, false);

  // Execute
  return ark_ohos_resource_adapter_get_raw_file_last_mod_time2(
      _struct, &rawFile, &time, isSys);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkOhosResourceAdapterCToCpp::GetSystemLanguage() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_resource_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_resource_adapter_get_system_language);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "nAoTS3_Fd1mDEdGtbfQdzQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_RESOURCE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_resource_adapter_get_system_language");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_system_language)) {
        ark_ohos_resource_adapter_get_system_language = nullptr;
      } else {
        ark_ohos_resource_adapter_get_system_language =
            _struct->get_system_language;
      }
    } else {
      ark_ohos_resource_adapter_get_system_language =
          reinterpret_cast<ArkOhosResourceAdapterGetSystemLanguageFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_resource_adapter_get_system_language, ark_web_string_default);

  // Execute
  return ark_ohos_resource_adapter_get_system_language(_struct);
}

ArkOhosResourceAdapterCToCpp::ArkOhosResourceAdapterCToCpp() {}

ArkOhosResourceAdapterCToCpp::~ArkOhosResourceAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkOhosResourceAdapterCToCpp,
                           ArkOhosResourceAdapter,
                           ark_ohos_resource_adapter_t>::kBridgeType =
        ARK_OHOS_RESOURCE_ADAPTER;

}  // namespace OHOS::ArkWeb
