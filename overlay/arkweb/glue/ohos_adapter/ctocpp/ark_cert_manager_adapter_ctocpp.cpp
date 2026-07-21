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

#include "ohos_adapter/ctocpp/ark_cert_manager_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkCertManagerAdapterGetCertMaxSizeFunc =
    uint32_t (*)(struct _ark_cert_manager_adapter_t* self);
static ArkCertManagerAdapterGetCertMaxSizeFunc
    ark_cert_manager_adapter_get_cert_max_size =
        reinterpret_cast<ArkCertManagerAdapterGetCertMaxSizeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCertManagerAdapterGetAppCertMaxSizeFunc =
    uint32_t (*)(struct _ark_cert_manager_adapter_t* self);
static ArkCertManagerAdapterGetAppCertMaxSizeFunc
    ark_cert_manager_adapter_get_app_cert_max_size =
        reinterpret_cast<ArkCertManagerAdapterGetAppCertMaxSizeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCertManagerAdapterGetSytemRootCertDataFunc =
    int32_t (*)(struct _ark_cert_manager_adapter_t* self,
                uint32_t certCount,
                uint8_t* certData);
static ArkCertManagerAdapterGetSytemRootCertDataFunc
    ark_cert_manager_adapter_get_sytem_root_cert_data =
        reinterpret_cast<ArkCertManagerAdapterGetSytemRootCertDataFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCertManagerAdapterGetSytemRootCertSumFunc =
    uint32_t (*)(struct _ark_cert_manager_adapter_t* self);
static ArkCertManagerAdapterGetSytemRootCertSumFunc
    ark_cert_manager_adapter_get_sytem_root_cert_sum =
        reinterpret_cast<ArkCertManagerAdapterGetSytemRootCertSumFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCertManagerAdapterGetUserRootCertDataFunc =
    int32_t (*)(struct _ark_cert_manager_adapter_t* self,
                uint32_t certCount,
                uint8_t* certData);
static ArkCertManagerAdapterGetUserRootCertDataFunc
    ark_cert_manager_adapter_get_user_root_cert_data =
        reinterpret_cast<ArkCertManagerAdapterGetUserRootCertDataFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCertManagerAdapterGetUserRootCertSumFunc =
    uint32_t (*)(struct _ark_cert_manager_adapter_t* self);
static ArkCertManagerAdapterGetUserRootCertSumFunc
    ark_cert_manager_adapter_get_user_root_cert_sum =
        reinterpret_cast<ArkCertManagerAdapterGetUserRootCertSumFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCertManagerAdapterGetAppCertFunc =
    int32_t (*)(struct _ark_cert_manager_adapter_t* self,
                uint8_t* uriData,
                uint8_t* certData,
                uint32_t* len);
static ArkCertManagerAdapterGetAppCertFunc
    ark_cert_manager_adapter_get_app_cert =
        reinterpret_cast<ArkCertManagerAdapterGetAppCertFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCertManagerAdapterSignFunc =
    int32_t (*)(struct _ark_cert_manager_adapter_t* self,
                const uint8_t* uri,
                const uint8_t* certData,
                uint32_t certDataLen,
                uint8_t* signData,
                uint32_t signDataLen);
static ArkCertManagerAdapterSignFunc ark_cert_manager_adapter_sign =
    reinterpret_cast<ArkCertManagerAdapterSignFunc>(ARK_WEB_INIT_ADDR);

using ArkCertManagerAdapterGetCertDataBySubjectFunc =
    int32_t (*)(struct _ark_cert_manager_adapter_t* self,
                const char* subjectName,
                uint8_t* certData,
                int32_t certType);
static ArkCertManagerAdapterGetCertDataBySubjectFunc
    ark_cert_manager_adapter_get_cert_data_by_subject =
        reinterpret_cast<ArkCertManagerAdapterGetCertDataBySubjectFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCertManagerAdapterVerifyCertFromNetSslFunc =
    int (*)(struct _ark_cert_manager_adapter_t* self,
            uint8_t* certData,
            uint32_t certSize);
static ArkCertManagerAdapterVerifyCertFromNetSslFunc
    ark_cert_manager_adapter_verify_cert_from_net_ssl =
        reinterpret_cast<ArkCertManagerAdapterVerifyCertFromNetSslFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCertManagerAdapterGetTrustAnchorsForHostNameFunc =
    bool (*)(struct _ark_cert_manager_adapter_t* self,
             const ArkWebString* hostname,
             ArkWebStringVector* certs);
static ArkCertManagerAdapterGetTrustAnchorsForHostNameFunc
    ark_cert_manager_adapter_get_trust_anchors_for_host_name =
        reinterpret_cast<ArkCertManagerAdapterGetTrustAnchorsForHostNameFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCertManagerAdapterGetPinSetForHostNameFunc =
    bool (*)(struct _ark_cert_manager_adapter_t* self,
             const ArkWebString* hostname,
             ArkWebStringVector* pins);
static ArkCertManagerAdapterGetPinSetForHostNameFunc
    ark_cert_manager_adapter_get_pin_set_for_host_name =
        reinterpret_cast<ArkCertManagerAdapterGetPinSetForHostNameFunc>(
            ARK_WEB_INIT_ADDR);

using ArkCertManagerAdapterSignV2Func =
    int32_t (*)(struct _ark_cert_manager_adapter_t* self,
                const uint8_t* uri,
                const uint8_t* certData,
                uint32_t certDataLen,
                uint8_t* signData,
                uint32_t* signDataLen,
                uint16_t algorithm);
static ArkCertManagerAdapterSignV2Func ark_cert_manager_adapter_sign_v2 =
    reinterpret_cast<ArkCertManagerAdapterSignV2Func>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
uint32_t ArkCertManagerAdapterCToCpp::GetCertMaxSize() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_cert_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_cert_manager_adapter_get_cert_max_size);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "uwW$aXKJg8Q$bh$Cjv6TTA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CERT_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_cert_manager_adapter_get_cert_max_size");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_cert_max_size)) {
        ark_cert_manager_adapter_get_cert_max_size = nullptr;
      } else {
        ark_cert_manager_adapter_get_cert_max_size = _struct->get_cert_max_size;
      }
    } else {
      ark_cert_manager_adapter_get_cert_max_size =
          reinterpret_cast<ArkCertManagerAdapterGetCertMaxSizeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_cert_manager_adapter_get_cert_max_size,
                                    0);

  // Execute
  return ark_cert_manager_adapter_get_cert_max_size(_struct);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkCertManagerAdapterCToCpp::GetAppCertMaxSize() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_cert_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_cert_manager_adapter_get_app_cert_max_size);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "kENUPqkxhjai8FDv1eRiwQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CERT_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_cert_manager_adapter_get_app_cert_max_size");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_app_cert_max_size)) {
        ark_cert_manager_adapter_get_app_cert_max_size = nullptr;
      } else {
        ark_cert_manager_adapter_get_app_cert_max_size =
            _struct->get_app_cert_max_size;
      }
    } else {
      ark_cert_manager_adapter_get_app_cert_max_size =
          reinterpret_cast<ArkCertManagerAdapterGetAppCertMaxSizeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_cert_manager_adapter_get_app_cert_max_size, 0);

  // Execute
  return ark_cert_manager_adapter_get_app_cert_max_size(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCertManagerAdapterCToCpp::GetSytemRootCertData(uint32_t certCount,
                                                          uint8_t* certData) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_cert_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_cert_manager_adapter_get_sytem_root_cert_data);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "yfW0mQGrdu6XjjvuGcUsBw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CERT_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_cert_manager_adapter_get_sytem_root_cert_data");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_sytem_root_cert_data)) {
        ark_cert_manager_adapter_get_sytem_root_cert_data = nullptr;
      } else {
        ark_cert_manager_adapter_get_sytem_root_cert_data =
            _struct->get_sytem_root_cert_data;
      }
    } else {
      ark_cert_manager_adapter_get_sytem_root_cert_data =
          reinterpret_cast<ArkCertManagerAdapterGetSytemRootCertDataFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_cert_manager_adapter_get_sytem_root_cert_data, 0);

  // Execute
  return ark_cert_manager_adapter_get_sytem_root_cert_data(_struct, certCount,
                                                           certData);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkCertManagerAdapterCToCpp::GetSytemRootCertSum() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_cert_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_cert_manager_adapter_get_sytem_root_cert_sum);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "zhvWa55yBdY_mUsa1MWq5A";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CERT_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_cert_manager_adapter_get_sytem_root_cert_sum");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_sytem_root_cert_sum)) {
        ark_cert_manager_adapter_get_sytem_root_cert_sum = nullptr;
      } else {
        ark_cert_manager_adapter_get_sytem_root_cert_sum =
            _struct->get_sytem_root_cert_sum;
      }
    } else {
      ark_cert_manager_adapter_get_sytem_root_cert_sum =
          reinterpret_cast<ArkCertManagerAdapterGetSytemRootCertSumFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_cert_manager_adapter_get_sytem_root_cert_sum, 0);

  // Execute
  return ark_cert_manager_adapter_get_sytem_root_cert_sum(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCertManagerAdapterCToCpp::GetUserRootCertData(uint32_t certCount,
                                                         uint8_t* certData) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_cert_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_cert_manager_adapter_get_user_root_cert_data);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "_owb6CWp9oOrFMNueNQOcg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CERT_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_cert_manager_adapter_get_user_root_cert_data");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_user_root_cert_data)) {
        ark_cert_manager_adapter_get_user_root_cert_data = nullptr;
      } else {
        ark_cert_manager_adapter_get_user_root_cert_data =
            _struct->get_user_root_cert_data;
      }
    } else {
      ark_cert_manager_adapter_get_user_root_cert_data =
          reinterpret_cast<ArkCertManagerAdapterGetUserRootCertDataFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_cert_manager_adapter_get_user_root_cert_data, 0);

  // Execute
  return ark_cert_manager_adapter_get_user_root_cert_data(_struct, certCount,
                                                          certData);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkCertManagerAdapterCToCpp::GetUserRootCertSum() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_cert_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_cert_manager_adapter_get_user_root_cert_sum);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jZc4sB53SLN6I0sqfxogWg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CERT_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_cert_manager_adapter_get_user_root_cert_sum");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_user_root_cert_sum)) {
        ark_cert_manager_adapter_get_user_root_cert_sum = nullptr;
      } else {
        ark_cert_manager_adapter_get_user_root_cert_sum =
            _struct->get_user_root_cert_sum;
      }
    } else {
      ark_cert_manager_adapter_get_user_root_cert_sum =
          reinterpret_cast<ArkCertManagerAdapterGetUserRootCertSumFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_cert_manager_adapter_get_user_root_cert_sum, 0);

  // Execute
  return ark_cert_manager_adapter_get_user_root_cert_sum(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCertManagerAdapterCToCpp::GetAppCert(uint8_t* uriData,
                                                uint8_t* certData,
                                                uint32_t* len) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_cert_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_cert_manager_adapter_get_app_cert);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "uM9uosNL5vOwY_zepb3oUw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CERT_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_cert_manager_adapter_get_app_cert");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_app_cert)) {
        ark_cert_manager_adapter_get_app_cert = nullptr;
      } else {
        ark_cert_manager_adapter_get_app_cert = _struct->get_app_cert;
      }
    } else {
      ark_cert_manager_adapter_get_app_cert =
          reinterpret_cast<ArkCertManagerAdapterGetAppCertFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_cert_manager_adapter_get_app_cert, 0);

  // Execute
  return ark_cert_manager_adapter_get_app_cert(_struct, uriData, certData, len);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCertManagerAdapterCToCpp::Sign(const uint8_t* uri,
                                          const uint8_t* certData,
                                          uint32_t certDataLen,
                                          uint8_t* signData,
                                          uint32_t signDataLen) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_cert_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_cert_manager_adapter_sign);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "RhNyGIoDO5BNp0otN$w5cg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CERT_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_cert_manager_adapter_sign");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, sign)) {
        ark_cert_manager_adapter_sign = nullptr;
      } else {
        ark_cert_manager_adapter_sign = _struct->sign;
      }
    } else {
      ark_cert_manager_adapter_sign =
          reinterpret_cast<ArkCertManagerAdapterSignFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_cert_manager_adapter_sign, 0);

  // Execute
  return ark_cert_manager_adapter_sign(_struct, uri, certData, certDataLen,
                                       signData, signDataLen);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCertManagerAdapterCToCpp::GetCertDataBySubject(
    const char* subjectName,
    uint8_t* certData,
    int32_t certType) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_cert_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_cert_manager_adapter_get_cert_data_by_subject);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "BH5YVGiUA1hJdmI6cowfTg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CERT_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_cert_manager_adapter_get_cert_data_by_subject");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_cert_data_by_subject)) {
        ark_cert_manager_adapter_get_cert_data_by_subject = nullptr;
      } else {
        ark_cert_manager_adapter_get_cert_data_by_subject =
            _struct->get_cert_data_by_subject;
      }
    } else {
      ark_cert_manager_adapter_get_cert_data_by_subject =
          reinterpret_cast<ArkCertManagerAdapterGetCertDataBySubjectFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_cert_manager_adapter_get_cert_data_by_subject, 0);

  // Execute
  return ark_cert_manager_adapter_get_cert_data_by_subject(_struct, subjectName,
                                                           certData, certType);
}

ARK_WEB_NO_SANITIZE
int ArkCertManagerAdapterCToCpp::VerifyCertFromNetSsl(uint8_t* certData,
                                                      uint32_t certSize) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_cert_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_cert_manager_adapter_verify_cert_from_net_ssl);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "UKT6I_q$pxkSwfbfhJst$Q";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CERT_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_cert_manager_adapter_verify_cert_from_net_ssl");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, verify_cert_from_net_ssl)) {
        ark_cert_manager_adapter_verify_cert_from_net_ssl = nullptr;
      } else {
        ark_cert_manager_adapter_verify_cert_from_net_ssl =
            _struct->verify_cert_from_net_ssl;
      }
    } else {
      ark_cert_manager_adapter_verify_cert_from_net_ssl =
          reinterpret_cast<ArkCertManagerAdapterVerifyCertFromNetSslFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_cert_manager_adapter_verify_cert_from_net_ssl, 0);

  // Execute
  return ark_cert_manager_adapter_verify_cert_from_net_ssl(_struct, certData,
                                                           certSize);
}

ARK_WEB_NO_SANITIZE
bool ArkCertManagerAdapterCToCpp::GetTrustAnchorsForHostName(
    const ArkWebString& hostname,
    ArkWebStringVector& certs) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_cert_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_cert_manager_adapter_get_trust_anchors_for_host_name);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "q2ohmPAuwyYeXfg5p617$Q";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CERT_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_cert_manager_adapter_get_trust_anchors_for_host_name");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_trust_anchors_for_host_name)) {
        ark_cert_manager_adapter_get_trust_anchors_for_host_name = nullptr;
      } else {
        ark_cert_manager_adapter_get_trust_anchors_for_host_name =
            _struct->get_trust_anchors_for_host_name;
      }
    } else {
      ark_cert_manager_adapter_get_trust_anchors_for_host_name =
          reinterpret_cast<ArkCertManagerAdapterGetTrustAnchorsForHostNameFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_cert_manager_adapter_get_trust_anchors_for_host_name, false);

  // Execute
  return ark_cert_manager_adapter_get_trust_anchors_for_host_name(
      _struct, &hostname, &certs);
}

ARK_WEB_NO_SANITIZE
bool ArkCertManagerAdapterCToCpp::GetPinSetForHostName(
    const ArkWebString& hostname,
    ArkWebStringVector& pins) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_cert_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_cert_manager_adapter_get_pin_set_for_host_name);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "BTRu$qQmdEZuag4GdOUZzw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CERT_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_cert_manager_adapter_get_pin_set_for_host_name");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_pin_set_for_host_name)) {
        ark_cert_manager_adapter_get_pin_set_for_host_name = nullptr;
      } else {
        ark_cert_manager_adapter_get_pin_set_for_host_name =
            _struct->get_pin_set_for_host_name;
      }
    } else {
      ark_cert_manager_adapter_get_pin_set_for_host_name =
          reinterpret_cast<ArkCertManagerAdapterGetPinSetForHostNameFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_cert_manager_adapter_get_pin_set_for_host_name, false);

  // Execute
  return ark_cert_manager_adapter_get_pin_set_for_host_name(_struct, &hostname,
                                                            &pins);
}

ARK_WEB_NO_SANITIZE
int32_t ArkCertManagerAdapterCToCpp::SignV2(const uint8_t* uri,
                                            const uint8_t* certData,
                                            uint32_t certDataLen,
                                            uint8_t* signData,
                                            uint32_t* signDataLen,
                                            uint16_t algorithm) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_cert_manager_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_cert_manager_adapter_sign_v2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "37OZunhQ2OhdzUzNYx5KXw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_CERT_MANAGER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_cert_manager_adapter_sign_v2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, sign_v2)) {
        ark_cert_manager_adapter_sign_v2 = nullptr;
      } else {
        ark_cert_manager_adapter_sign_v2 = _struct->sign_v2;
      }
    } else {
      ark_cert_manager_adapter_sign_v2 =
          reinterpret_cast<ArkCertManagerAdapterSignV2Func>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_cert_manager_adapter_sign_v2, 0);

  // Execute
  return ark_cert_manager_adapter_sign_v2(_struct, uri, certData, certDataLen,
                                          signData, signDataLen, algorithm);
}

ArkCertManagerAdapterCToCpp::ArkCertManagerAdapterCToCpp() {}

ArkCertManagerAdapterCToCpp::~ArkCertManagerAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkCertManagerAdapterCToCpp,
                           ArkCertManagerAdapter,
                           ark_cert_manager_adapter_t>::kBridgeType =
        ARK_CERT_MANAGER_ADAPTER;

}  // namespace OHOS::ArkWeb
