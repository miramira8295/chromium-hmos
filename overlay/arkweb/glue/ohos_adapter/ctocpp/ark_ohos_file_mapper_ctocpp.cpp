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

#include "ohos_adapter/ctocpp/ark_ohos_file_mapper_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkOhosFileMapperGetFdFunc =
    int32_t (*)(struct _ark_ohos_file_mapper_t* self);
static ArkOhosFileMapperGetFdFunc ark_ohos_file_mapper_get_fd =
    reinterpret_cast<ArkOhosFileMapperGetFdFunc>(ARK_WEB_INIT_ADDR);

using ArkOhosFileMapperGetOffsetFunc =
    int32_t (*)(struct _ark_ohos_file_mapper_t* self);
static ArkOhosFileMapperGetOffsetFunc ark_ohos_file_mapper_get_offset =
    reinterpret_cast<ArkOhosFileMapperGetOffsetFunc>(ARK_WEB_INIT_ADDR);

using ArkOhosFileMapperGetFileNameFunc =
    ArkWebString (*)(struct _ark_ohos_file_mapper_t* self);
static ArkOhosFileMapperGetFileNameFunc ark_ohos_file_mapper_get_file_name =
    reinterpret_cast<ArkOhosFileMapperGetFileNameFunc>(ARK_WEB_INIT_ADDR);

using ArkOhosFileMapperIsCompressedFunc =
    bool (*)(struct _ark_ohos_file_mapper_t* self);
static ArkOhosFileMapperIsCompressedFunc ark_ohos_file_mapper_is_compressed =
    reinterpret_cast<ArkOhosFileMapperIsCompressedFunc>(ARK_WEB_INIT_ADDR);

using ArkOhosFileMapperGetDataPtrFunc =
    void* (*)(struct _ark_ohos_file_mapper_t* self);
static ArkOhosFileMapperGetDataPtrFunc ark_ohos_file_mapper_get_data_ptr =
    reinterpret_cast<ArkOhosFileMapperGetDataPtrFunc>(ARK_WEB_INIT_ADDR);

using ArkOhosFileMapperGetDataLenFunc =
    size_t (*)(struct _ark_ohos_file_mapper_t* self);
static ArkOhosFileMapperGetDataLenFunc ark_ohos_file_mapper_get_data_len =
    reinterpret_cast<ArkOhosFileMapperGetDataLenFunc>(ARK_WEB_INIT_ADDR);

using ArkOhosFileMapperUnzipDataFunc =
    bool (*)(struct _ark_ohos_file_mapper_t* self, uint8_t** dest, size_t* len);
static ArkOhosFileMapperUnzipDataFunc ark_ohos_file_mapper_unzip_data =
    reinterpret_cast<ArkOhosFileMapperUnzipDataFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int32_t ArkOhosFileMapperCToCpp::GetFd() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_file_mapper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_ohos_file_mapper_get_fd);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "A3nhC0rx89qzaXhFk_uyEA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_FILE_MAPPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_file_mapper_get_fd");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_fd)) {
        ark_ohos_file_mapper_get_fd = nullptr;
      } else {
        ark_ohos_file_mapper_get_fd = _struct->get_fd;
      }
    } else {
      ark_ohos_file_mapper_get_fd =
          reinterpret_cast<ArkOhosFileMapperGetFdFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_file_mapper_get_fd, 0);

  // Execute
  return ark_ohos_file_mapper_get_fd(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkOhosFileMapperCToCpp::GetOffset() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_file_mapper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_ohos_file_mapper_get_offset);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "vrfpJ_tDsfLZNjeW$D8xdw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_FILE_MAPPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_file_mapper_get_offset");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_offset)) {
        ark_ohos_file_mapper_get_offset = nullptr;
      } else {
        ark_ohos_file_mapper_get_offset = _struct->get_offset;
      }
    } else {
      ark_ohos_file_mapper_get_offset =
          reinterpret_cast<ArkOhosFileMapperGetOffsetFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_file_mapper_get_offset, 0);

  // Execute
  return ark_ohos_file_mapper_get_offset(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkOhosFileMapperCToCpp::GetFileName() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_file_mapper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_file_mapper_get_file_name);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "$s55TEm0bD9BhVzcrni8iw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_FILE_MAPPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_file_mapper_get_file_name");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_file_name)) {
        ark_ohos_file_mapper_get_file_name = nullptr;
      } else {
        ark_ohos_file_mapper_get_file_name = _struct->get_file_name;
      }
    } else {
      ark_ohos_file_mapper_get_file_name =
          reinterpret_cast<ArkOhosFileMapperGetFileNameFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_file_mapper_get_file_name,
                                    ark_web_string_default);

  // Execute
  return ark_ohos_file_mapper_get_file_name(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkOhosFileMapperCToCpp::IsCompressed() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_file_mapper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_file_mapper_is_compressed);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jbanXlWIq9JQx165GQ2sSQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_FILE_MAPPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_file_mapper_is_compressed");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_compressed)) {
        ark_ohos_file_mapper_is_compressed = nullptr;
      } else {
        ark_ohos_file_mapper_is_compressed = _struct->is_compressed;
      }
    } else {
      ark_ohos_file_mapper_is_compressed =
          reinterpret_cast<ArkOhosFileMapperIsCompressedFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_file_mapper_is_compressed, false);

  // Execute
  return ark_ohos_file_mapper_is_compressed(_struct);
}

ARK_WEB_NO_SANITIZE
void* ArkOhosFileMapperCToCpp::GetDataPtr() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_file_mapper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_file_mapper_get_data_ptr);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "CPDSa_S6pvMobXSV2qqCCA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_FILE_MAPPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_file_mapper_get_data_ptr");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_data_ptr)) {
        ark_ohos_file_mapper_get_data_ptr = nullptr;
      } else {
        ark_ohos_file_mapper_get_data_ptr = _struct->get_data_ptr;
      }
    } else {
      ark_ohos_file_mapper_get_data_ptr =
          reinterpret_cast<ArkOhosFileMapperGetDataPtrFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_file_mapper_get_data_ptr, nullptr);

  // Execute
  return ark_ohos_file_mapper_get_data_ptr(_struct);
}

ARK_WEB_NO_SANITIZE
size_t ArkOhosFileMapperCToCpp::GetDataLen() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_file_mapper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_file_mapper_get_data_len);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "N9oosRR7svJdXfrP8dDr1g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_FILE_MAPPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_file_mapper_get_data_len");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_data_len)) {
        ark_ohos_file_mapper_get_data_len = nullptr;
      } else {
        ark_ohos_file_mapper_get_data_len = _struct->get_data_len;
      }
    } else {
      ark_ohos_file_mapper_get_data_len =
          reinterpret_cast<ArkOhosFileMapperGetDataLenFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_file_mapper_get_data_len, 0);

  // Execute
  return ark_ohos_file_mapper_get_data_len(_struct);
}

ARK_WEB_NO_SANITIZE
bool ArkOhosFileMapperCToCpp::UnzipData(uint8_t** dest, size_t& len) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_file_mapper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(ark_ohos_file_mapper_unzip_data);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "EKAMIEyhQJtzzo1a0mn2HQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_FILE_MAPPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_file_mapper_unzip_data");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, unzip_data)) {
        ark_ohos_file_mapper_unzip_data = nullptr;
      } else {
        ark_ohos_file_mapper_unzip_data = _struct->unzip_data;
      }
    } else {
      ark_ohos_file_mapper_unzip_data =
          reinterpret_cast<ArkOhosFileMapperUnzipDataFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_file_mapper_unzip_data, false);

  // Execute
  return ark_ohos_file_mapper_unzip_data(_struct, dest, &len);
}

ArkOhosFileMapperCToCpp::ArkOhosFileMapperCToCpp() {}

ArkOhosFileMapperCToCpp::~ArkOhosFileMapperCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkOhosFileMapperCToCpp,
                                        ArkOhosFileMapper,
                                        ark_ohos_file_mapper_t>::kBridgeType =
    ARK_OHOS_FILE_MAPPER;

}  // namespace OHOS::ArkWeb
