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

#include "ohos_adapter/ctocpp/ark_drm_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_drm_callback_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkDrmAdapterIsSupportedFunc = bool (*)(struct _ark_drm_adapter_t* self,
                                              const ArkWebString* name);
static ArkDrmAdapterIsSupportedFunc ark_drm_adapter_is_supported =
    reinterpret_cast<ArkDrmAdapterIsSupportedFunc>(ARK_WEB_INIT_ADDR);

using ArkDrmAdapterIsSupported2Func = bool (*)(struct _ark_drm_adapter_t* self,
                                               const ArkWebString* name,
                                               const ArkWebString* mimeType);
static ArkDrmAdapterIsSupported2Func ark_drm_adapter_is_supported2 =
    reinterpret_cast<ArkDrmAdapterIsSupported2Func>(ARK_WEB_INIT_ADDR);

using ArkDrmAdapterIsSupported3Func = bool (*)(struct _ark_drm_adapter_t* self,
                                               const ArkWebString* name,
                                               const ArkWebString* mimeType,
                                               int32_t level);
static ArkDrmAdapterIsSupported3Func ark_drm_adapter_is_supported3 =
    reinterpret_cast<ArkDrmAdapterIsSupported3Func>(ARK_WEB_INIT_ADDR);

using ArkDrmAdapterGetUUIDFunc =
    ArkWebUint8Vector (*)(struct _ark_drm_adapter_t* self,
                          const ArkWebString* name);
static ArkDrmAdapterGetUUIDFunc ark_drm_adapter_get_uuid =
    reinterpret_cast<ArkDrmAdapterGetUUIDFunc>(ARK_WEB_INIT_ADDR);

using ArkDrmAdapterStorageProvisionedResultFunc =
    void (*)(struct _ark_drm_adapter_t* self, bool result);
static ArkDrmAdapterStorageProvisionedResultFunc
    ark_drm_adapter_storage_provisioned_result =
        reinterpret_cast<ArkDrmAdapterStorageProvisionedResultFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDrmAdapterStorageSaveInfoResultFunc =
    void (*)(struct _ark_drm_adapter_t* self, bool result, int32_t type);
static ArkDrmAdapterStorageSaveInfoResultFunc
    ark_drm_adapter_storage_save_info_result =
        reinterpret_cast<ArkDrmAdapterStorageSaveInfoResultFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDrmAdapterStorageLoadInfoResultFunc =
    void (*)(struct _ark_drm_adapter_t* self,
             const ArkWebString* sessionId,
             const ArkWebUint8Vector* keySetId,
             const ArkWebString* mimeType,
             uint32_t keyType);
static ArkDrmAdapterStorageLoadInfoResultFunc
    ark_drm_adapter_storage_load_info_result =
        reinterpret_cast<ArkDrmAdapterStorageLoadInfoResultFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDrmAdapterStorageClearInfoResultFunc =
    void (*)(struct _ark_drm_adapter_t* self, bool result, int32_t type);
static ArkDrmAdapterStorageClearInfoResultFunc
    ark_drm_adapter_storage_clear_info_result =
        reinterpret_cast<ArkDrmAdapterStorageClearInfoResultFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDrmAdapterReleaseMediaKeySystemFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self);
static ArkDrmAdapterReleaseMediaKeySystemFunc
    ark_drm_adapter_release_media_key_system =
        reinterpret_cast<ArkDrmAdapterReleaseMediaKeySystemFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDrmAdapterReleaseMediaKeySessionFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self);
static ArkDrmAdapterReleaseMediaKeySessionFunc
    ark_drm_adapter_release_media_key_session =
        reinterpret_cast<ArkDrmAdapterReleaseMediaKeySessionFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDrmAdapterCreateKeySystemFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self,
                const ArkWebString* name,
                const ArkWebString* origin,
                int32_t securityLevel);
static ArkDrmAdapterCreateKeySystemFunc ark_drm_adapter_create_key_system =
    reinterpret_cast<ArkDrmAdapterCreateKeySystemFunc>(ARK_WEB_INIT_ADDR);

using ArkDrmAdapterSetConfigurationStringFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self,
                const ArkWebString* configName,
                const ArkWebString* value);
static ArkDrmAdapterSetConfigurationStringFunc
    ark_drm_adapter_set_configuration_string =
        reinterpret_cast<ArkDrmAdapterSetConfigurationStringFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDrmAdapterGetConfigurationStringFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self,
                const ArkWebString* configName,
                char* value,
                int32_t valueLen);
static ArkDrmAdapterGetConfigurationStringFunc
    ark_drm_adapter_get_configuration_string =
        reinterpret_cast<ArkDrmAdapterGetConfigurationStringFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDrmAdapterSetConfigurationByteArrayFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self,
                const ArkWebString* configName,
                const uint8_t* value,
                int32_t valueLen);
static ArkDrmAdapterSetConfigurationByteArrayFunc
    ark_drm_adapter_set_configuration_byte_array =
        reinterpret_cast<ArkDrmAdapterSetConfigurationByteArrayFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDrmAdapterGetConfigurationByteArrayFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self,
                const ArkWebString* configName,
                uint8_t* value,
                int32_t* valueLen);
static ArkDrmAdapterGetConfigurationByteArrayFunc
    ark_drm_adapter_get_configuration_byte_array =
        reinterpret_cast<ArkDrmAdapterGetConfigurationByteArrayFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDrmAdapterGetMaxContentProtectionLevelFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self, int32_t* level);
static ArkDrmAdapterGetMaxContentProtectionLevelFunc
    ark_drm_adapter_get_max_content_protection_level =
        reinterpret_cast<ArkDrmAdapterGetMaxContentProtectionLevelFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDrmAdapterProcessKeySystemResponseFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self,
                const ArkWebString* response,
                bool isResponseReceived);
static ArkDrmAdapterProcessKeySystemResponseFunc
    ark_drm_adapter_process_key_system_response =
        reinterpret_cast<ArkDrmAdapterProcessKeySystemResponseFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDrmAdapterGetCertificateStatusFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self, int32_t* certStatus);
static ArkDrmAdapterGetCertificateStatusFunc
    ark_drm_adapter_get_certificate_status =
        reinterpret_cast<ArkDrmAdapterGetCertificateStatusFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDrmAdapterRegistDrmCallbackFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self,
                ark_drm_callback_adapter_t* callbackAdapter);
static ArkDrmAdapterRegistDrmCallbackFunc ark_drm_adapter_regist_drm_callback =
    reinterpret_cast<ArkDrmAdapterRegistDrmCallbackFunc>(ARK_WEB_INIT_ADDR);

using ArkDrmAdapterUpdateSessionFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self,
                uint32_t promiseId,
                const ArkWebString* sessionId,
                ArkWebUint8Vector response);
static ArkDrmAdapterUpdateSessionFunc ark_drm_adapter_update_session =
    reinterpret_cast<ArkDrmAdapterUpdateSessionFunc>(ARK_WEB_INIT_ADDR);

using ArkDrmAdapterCloseSessionFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self,
                uint32_t promiseId,
                const ArkWebString* sessionId);
static ArkDrmAdapterCloseSessionFunc ark_drm_adapter_close_session =
    reinterpret_cast<ArkDrmAdapterCloseSessionFunc>(ARK_WEB_INIT_ADDR);

using ArkDrmAdapterRemoveSessionFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self,
                uint32_t promiseId,
                const ArkWebString* sessionId);
static ArkDrmAdapterRemoveSessionFunc ark_drm_adapter_remove_session =
    reinterpret_cast<ArkDrmAdapterRemoveSessionFunc>(ARK_WEB_INIT_ADDR);

using ArkDrmAdapterLoadSessionFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self,
                uint32_t promiseId,
                const ArkWebString* sessionId);
static ArkDrmAdapterLoadSessionFunc ark_drm_adapter_load_session =
    reinterpret_cast<ArkDrmAdapterLoadSessionFunc>(ARK_WEB_INIT_ADDR);

using ArkDrmAdapterClearMediaKeysFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self);
static ArkDrmAdapterClearMediaKeysFunc ark_drm_adapter_clear_media_keys =
    reinterpret_cast<ArkDrmAdapterClearMediaKeysFunc>(ARK_WEB_INIT_ADDR);

using ArkDrmAdapterGetSecurityLevelFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self);
static ArkDrmAdapterGetSecurityLevelFunc ark_drm_adapter_get_security_level =
    reinterpret_cast<ArkDrmAdapterGetSecurityLevelFunc>(ARK_WEB_INIT_ADDR);

using ArkDrmAdapterRequireSecureDecoderModuleFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self,
                const ArkWebString* mimeType,
                bool* status);
static ArkDrmAdapterRequireSecureDecoderModuleFunc
    ark_drm_adapter_require_secure_decoder_module =
        reinterpret_cast<ArkDrmAdapterRequireSecureDecoderModuleFunc>(
            ARK_WEB_INIT_ADDR);

using ArkDrmAdapterGenerateMediaKeyRequestFunc =
    int32_t (*)(struct _ark_drm_adapter_t* self,
                const ArkWebString* sessionId,
                int32_t type,
                int32_t initDataLen,
                const ArkWebUint8Vector* initData,
                const ArkWebString* mimeType,
                uint32_t promiseId);
static ArkDrmAdapterGenerateMediaKeyRequestFunc
    ark_drm_adapter_generate_media_key_request =
        reinterpret_cast<ArkDrmAdapterGenerateMediaKeyRequestFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
bool ArkDrmAdapterCToCpp::IsSupported(const ArkWebString& name) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(ark_drm_adapter_is_supported);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "74fNsoqv3rHcBXFNCzqeZA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_drm_adapter_is_supported");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_supported)) {
        ark_drm_adapter_is_supported = nullptr;
      } else {
        ark_drm_adapter_is_supported = _struct->is_supported;
      }
    } else {
      ark_drm_adapter_is_supported =
          reinterpret_cast<ArkDrmAdapterIsSupportedFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_is_supported, false);

  // Execute
  return ark_drm_adapter_is_supported(_struct, &name);
}

ARK_WEB_NO_SANITIZE
bool ArkDrmAdapterCToCpp::IsSupported2(const ArkWebString& name,
                                       const ArkWebString& mimeType) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(ark_drm_adapter_is_supported2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "6iJy5Q6eu2n3AyjWQ6xYmw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_drm_adapter_is_supported2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_supported2)) {
        ark_drm_adapter_is_supported2 = nullptr;
      } else {
        ark_drm_adapter_is_supported2 = _struct->is_supported2;
      }
    } else {
      ark_drm_adapter_is_supported2 =
          reinterpret_cast<ArkDrmAdapterIsSupported2Func>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_is_supported2, false);

  // Execute
  return ark_drm_adapter_is_supported2(_struct, &name, &mimeType);
}

ARK_WEB_NO_SANITIZE
bool ArkDrmAdapterCToCpp::IsSupported3(const ArkWebString& name,
                                       const ArkWebString& mimeType,
                                       int32_t level) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(ark_drm_adapter_is_supported3);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "U9qg3w5I85$aZyFAdvrnwQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_drm_adapter_is_supported3");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_supported3)) {
        ark_drm_adapter_is_supported3 = nullptr;
      } else {
        ark_drm_adapter_is_supported3 = _struct->is_supported3;
      }
    } else {
      ark_drm_adapter_is_supported3 =
          reinterpret_cast<ArkDrmAdapterIsSupported3Func>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_is_supported3, false);

  // Execute
  return ark_drm_adapter_is_supported3(_struct, &name, &mimeType, level);
}

ARK_WEB_NO_SANITIZE
ArkWebUint8Vector ArkDrmAdapterCToCpp::GetUUID(const ArkWebString& name) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_uint8_vector_default);

  void* func_pointer = reinterpret_cast<void*>(ark_drm_adapter_get_uuid);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "UTNH5TZhC7ZUrW9pIkwt2w";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_drm_adapter_get_uuid");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_uuid)) {
        ark_drm_adapter_get_uuid = nullptr;
      } else {
        ark_drm_adapter_get_uuid = _struct->get_uuid;
      }
    } else {
      ark_drm_adapter_get_uuid =
          reinterpret_cast<ArkDrmAdapterGetUUIDFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_get_uuid,
                                    ark_web_uint8_vector_default);

  // Execute
  return ark_drm_adapter_get_uuid(_struct, &name);
}

ARK_WEB_NO_SANITIZE
void ArkDrmAdapterCToCpp::StorageProvisionedResult(bool result) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_storage_provisioned_result);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "iptC_N2xYEXYOqIsftoSUw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_drm_adapter_storage_provisioned_result");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, storage_provisioned_result)) {
        ark_drm_adapter_storage_provisioned_result = nullptr;
      } else {
        ark_drm_adapter_storage_provisioned_result =
            _struct->storage_provisioned_result;
      }
    } else {
      ark_drm_adapter_storage_provisioned_result =
          reinterpret_cast<ArkDrmAdapterStorageProvisionedResultFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_storage_provisioned_result,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_drm_adapter_storage_provisioned_result(_struct, result);
}

ARK_WEB_NO_SANITIZE
void ArkDrmAdapterCToCpp::StorageSaveInfoResult(bool result, int32_t type) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_storage_save_info_result);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "oKrTFn2OWVHpSQETanWcbg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_drm_adapter_storage_save_info_result");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, storage_save_info_result)) {
        ark_drm_adapter_storage_save_info_result = nullptr;
      } else {
        ark_drm_adapter_storage_save_info_result =
            _struct->storage_save_info_result;
      }
    } else {
      ark_drm_adapter_storage_save_info_result =
          reinterpret_cast<ArkDrmAdapterStorageSaveInfoResultFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_storage_save_info_result,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_drm_adapter_storage_save_info_result(_struct, result, type);
}

ARK_WEB_NO_SANITIZE
void ArkDrmAdapterCToCpp::StorageLoadInfoResult(
    const ArkWebString& sessionId,
    const ArkWebUint8Vector& keySetId,
    const ArkWebString& mimeType,
    uint32_t keyType) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_storage_load_info_result);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "7VhiFHtP3FpyqJnLV29giA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_drm_adapter_storage_load_info_result");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, storage_load_info_result)) {
        ark_drm_adapter_storage_load_info_result = nullptr;
      } else {
        ark_drm_adapter_storage_load_info_result =
            _struct->storage_load_info_result;
      }
    } else {
      ark_drm_adapter_storage_load_info_result =
          reinterpret_cast<ArkDrmAdapterStorageLoadInfoResultFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_storage_load_info_result,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_drm_adapter_storage_load_info_result(_struct, &sessionId, &keySetId,
                                           &mimeType, keyType);
}

ARK_WEB_NO_SANITIZE
void ArkDrmAdapterCToCpp::StorageClearInfoResult(bool result, int32_t type) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_storage_clear_info_result);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "gMpp1Olj6QvkpP8SR_dhTg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_drm_adapter_storage_clear_info_result");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, storage_clear_info_result)) {
        ark_drm_adapter_storage_clear_info_result = nullptr;
      } else {
        ark_drm_adapter_storage_clear_info_result =
            _struct->storage_clear_info_result;
      }
    } else {
      ark_drm_adapter_storage_clear_info_result =
          reinterpret_cast<ArkDrmAdapterStorageClearInfoResultFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_storage_clear_info_result,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_drm_adapter_storage_clear_info_result(_struct, result, type);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::ReleaseMediaKeySystem() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_release_media_key_system);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "CIDNacMb2trtCqa4WDVYPA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_drm_adapter_release_media_key_system");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release_media_key_system)) {
        ark_drm_adapter_release_media_key_system = nullptr;
      } else {
        ark_drm_adapter_release_media_key_system =
            _struct->release_media_key_system;
      }
    } else {
      ark_drm_adapter_release_media_key_system =
          reinterpret_cast<ArkDrmAdapterReleaseMediaKeySystemFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_release_media_key_system,
                                    0);

  // Execute
  return ark_drm_adapter_release_media_key_system(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::ReleaseMediaKeySession() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_release_media_key_session);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "2cAU1s4vfFY56a8kKhEMDA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_drm_adapter_release_media_key_session");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release_media_key_session)) {
        ark_drm_adapter_release_media_key_session = nullptr;
      } else {
        ark_drm_adapter_release_media_key_session =
            _struct->release_media_key_session;
      }
    } else {
      ark_drm_adapter_release_media_key_session =
          reinterpret_cast<ArkDrmAdapterReleaseMediaKeySessionFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_release_media_key_session,
                                    0);

  // Execute
  return ark_drm_adapter_release_media_key_session(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::CreateKeySystem(const ArkWebString& name,
                                             const ArkWebString& origin,
                                             int32_t securityLevel) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_create_key_system);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "hCYGk2aocvO7YZgRx14Bqg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_drm_adapter_create_key_system");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_key_system)) {
        ark_drm_adapter_create_key_system = nullptr;
      } else {
        ark_drm_adapter_create_key_system = _struct->create_key_system;
      }
    } else {
      ark_drm_adapter_create_key_system =
          reinterpret_cast<ArkDrmAdapterCreateKeySystemFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_create_key_system, 0);

  // Execute
  return ark_drm_adapter_create_key_system(_struct, &name, &origin,
                                           securityLevel);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::SetConfigurationString(
    const ArkWebString& configName,
    const ArkWebString& value) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_set_configuration_string);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "_97xhyAkXLlyw2vjsNnVMQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_drm_adapter_set_configuration_string");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_configuration_string)) {
        ark_drm_adapter_set_configuration_string = nullptr;
      } else {
        ark_drm_adapter_set_configuration_string =
            _struct->set_configuration_string;
      }
    } else {
      ark_drm_adapter_set_configuration_string =
          reinterpret_cast<ArkDrmAdapterSetConfigurationStringFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_set_configuration_string,
                                    0);

  // Execute
  return ark_drm_adapter_set_configuration_string(_struct, &configName, &value);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::GetConfigurationString(
    const ArkWebString& configName,
    char* value,
    int32_t valueLen) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_get_configuration_string);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "zIcqhVMjIuuZkLiNFJkH3A";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_drm_adapter_get_configuration_string");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_configuration_string)) {
        ark_drm_adapter_get_configuration_string = nullptr;
      } else {
        ark_drm_adapter_get_configuration_string =
            _struct->get_configuration_string;
      }
    } else {
      ark_drm_adapter_get_configuration_string =
          reinterpret_cast<ArkDrmAdapterGetConfigurationStringFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_get_configuration_string,
                                    0);

  // Execute
  return ark_drm_adapter_get_configuration_string(_struct, &configName, value,
                                                  valueLen);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::SetConfigurationByteArray(
    const ArkWebString& configName,
    const uint8_t* value,
    int32_t valueLen) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_set_configuration_byte_array);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "KsxfNh6gq9$1MYFSH37sQw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_drm_adapter_set_configuration_byte_array");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_configuration_byte_array)) {
        ark_drm_adapter_set_configuration_byte_array = nullptr;
      } else {
        ark_drm_adapter_set_configuration_byte_array =
            _struct->set_configuration_byte_array;
      }
    } else {
      ark_drm_adapter_set_configuration_byte_array =
          reinterpret_cast<ArkDrmAdapterSetConfigurationByteArrayFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_drm_adapter_set_configuration_byte_array, 0);

  // Execute
  return ark_drm_adapter_set_configuration_byte_array(_struct, &configName,
                                                      value, valueLen);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::GetConfigurationByteArray(
    const ArkWebString& configName,
    uint8_t* value,
    int32_t* valueLen) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_get_configuration_byte_array);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "AcQNBOfgbg6USOp8dz7nBQ";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_drm_adapter_get_configuration_byte_array");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_configuration_byte_array)) {
        ark_drm_adapter_get_configuration_byte_array = nullptr;
      } else {
        ark_drm_adapter_get_configuration_byte_array =
            _struct->get_configuration_byte_array;
      }
    } else {
      ark_drm_adapter_get_configuration_byte_array =
          reinterpret_cast<ArkDrmAdapterGetConfigurationByteArrayFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_drm_adapter_get_configuration_byte_array, 0);

  // Execute
  return ark_drm_adapter_get_configuration_byte_array(_struct, &configName,
                                                      value, valueLen);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::GetMaxContentProtectionLevel(int32_t& level) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_get_max_content_protection_level);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jP5Qipk7xnIbhf7Lh3GRKw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_drm_adapter_get_max_content_protection_level");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_max_content_protection_level)) {
        ark_drm_adapter_get_max_content_protection_level = nullptr;
      } else {
        ark_drm_adapter_get_max_content_protection_level =
            _struct->get_max_content_protection_level;
      }
    } else {
      ark_drm_adapter_get_max_content_protection_level =
          reinterpret_cast<ArkDrmAdapterGetMaxContentProtectionLevelFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_drm_adapter_get_max_content_protection_level, 0);

  // Execute
  return ark_drm_adapter_get_max_content_protection_level(_struct, &level);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::ProcessKeySystemResponse(
    const ArkWebString& response,
    bool isResponseReceived) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_process_key_system_response);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "WH9EzD23zc8KdAe8qUbOcw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_drm_adapter_process_key_system_response");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, process_key_system_response)) {
        ark_drm_adapter_process_key_system_response = nullptr;
      } else {
        ark_drm_adapter_process_key_system_response =
            _struct->process_key_system_response;
      }
    } else {
      ark_drm_adapter_process_key_system_response =
          reinterpret_cast<ArkDrmAdapterProcessKeySystemResponseFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_process_key_system_response,
                                    0);

  // Execute
  return ark_drm_adapter_process_key_system_response(_struct, &response,
                                                     isResponseReceived);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::GetCertificateStatus(int32_t& certStatus) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_get_certificate_status);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "NWo8pVH5D1y4IdYlbvNVWA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_drm_adapter_get_certificate_status");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_certificate_status)) {
        ark_drm_adapter_get_certificate_status = nullptr;
      } else {
        ark_drm_adapter_get_certificate_status =
            _struct->get_certificate_status;
      }
    } else {
      ark_drm_adapter_get_certificate_status =
          reinterpret_cast<ArkDrmAdapterGetCertificateStatusFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_get_certificate_status, 0);

  // Execute
  return ark_drm_adapter_get_certificate_status(_struct, &certStatus);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::RegistDrmCallback(
    ArkWebRefPtr<ArkDrmCallbackAdapter> callbackAdapter) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_regist_drm_callback);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "fUAMBsA82HcP2O4YK7SfCA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_drm_adapter_regist_drm_callback");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, regist_drm_callback)) {
        ark_drm_adapter_regist_drm_callback = nullptr;
      } else {
        ark_drm_adapter_regist_drm_callback = _struct->regist_drm_callback;
      }
    } else {
      ark_drm_adapter_regist_drm_callback =
          reinterpret_cast<ArkDrmAdapterRegistDrmCallbackFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_regist_drm_callback, 0);

  // Execute
  return ark_drm_adapter_regist_drm_callback(
      _struct, ArkDrmCallbackAdapterCppToC::Invert(callbackAdapter));
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::UpdateSession(uint32_t promiseId,
                                           const ArkWebString& sessionId,
                                           ArkWebUint8Vector response) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_drm_adapter_update_session);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "q01ZQQiJRIqDVKq6vTBgHg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_drm_adapter_update_session");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, update_session)) {
        ark_drm_adapter_update_session = nullptr;
      } else {
        ark_drm_adapter_update_session = _struct->update_session;
      }
    } else {
      ark_drm_adapter_update_session =
          reinterpret_cast<ArkDrmAdapterUpdateSessionFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_update_session, 0);

  // Execute
  return ark_drm_adapter_update_session(_struct, promiseId, &sessionId,
                                        response);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::CloseSession(uint32_t promiseId,
                                          const ArkWebString& sessionId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_drm_adapter_close_session);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Smmj4TdiTyc5E$lw7EMXUA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_drm_adapter_close_session");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, close_session)) {
        ark_drm_adapter_close_session = nullptr;
      } else {
        ark_drm_adapter_close_session = _struct->close_session;
      }
    } else {
      ark_drm_adapter_close_session =
          reinterpret_cast<ArkDrmAdapterCloseSessionFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_close_session, 0);

  // Execute
  return ark_drm_adapter_close_session(_struct, promiseId, &sessionId);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::RemoveSession(uint32_t promiseId,
                                           const ArkWebString& sessionId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_drm_adapter_remove_session);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "rc95kWBnq46Vzos1UnCPjw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_drm_adapter_remove_session");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, remove_session)) {
        ark_drm_adapter_remove_session = nullptr;
      } else {
        ark_drm_adapter_remove_session = _struct->remove_session;
      }
    } else {
      ark_drm_adapter_remove_session =
          reinterpret_cast<ArkDrmAdapterRemoveSessionFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_remove_session, 0);

  // Execute
  return ark_drm_adapter_remove_session(_struct, promiseId, &sessionId);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::LoadSession(uint32_t promiseId,
                                         const ArkWebString& sessionId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_drm_adapter_load_session);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "P1$j4LaJCHDmcWOmRh8nmg";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_drm_adapter_load_session");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, load_session)) {
        ark_drm_adapter_load_session = nullptr;
      } else {
        ark_drm_adapter_load_session = _struct->load_session;
      }
    } else {
      ark_drm_adapter_load_session =
          reinterpret_cast<ArkDrmAdapterLoadSessionFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_load_session, 0);

  // Execute
  return ark_drm_adapter_load_session(_struct, promiseId, &sessionId);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::ClearMediaKeys() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_clear_media_keys);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "yKmuIjJxU2hr4ilCmWAZ0w";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_drm_adapter_clear_media_keys");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, clear_media_keys)) {
        ark_drm_adapter_clear_media_keys = nullptr;
      } else {
        ark_drm_adapter_clear_media_keys = _struct->clear_media_keys;
      }
    } else {
      ark_drm_adapter_clear_media_keys =
          reinterpret_cast<ArkDrmAdapterClearMediaKeysFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_clear_media_keys, 0);

  // Execute
  return ark_drm_adapter_clear_media_keys(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::GetSecurityLevel() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_get_security_level);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "kjANhO_xEUlEF5FEqwXIGw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_drm_adapter_get_security_level");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_security_level)) {
        ark_drm_adapter_get_security_level = nullptr;
      } else {
        ark_drm_adapter_get_security_level = _struct->get_security_level;
      }
    } else {
      ark_drm_adapter_get_security_level =
          reinterpret_cast<ArkDrmAdapterGetSecurityLevelFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_get_security_level, 0);

  // Execute
  return ark_drm_adapter_get_security_level(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::RequireSecureDecoderModule(
    const ArkWebString& mimeType,
    bool& status) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_require_secure_decoder_module);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "X4tqRJ_bdFF54mPxIn4Xbw";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_drm_adapter_require_secure_decoder_module");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, require_secure_decoder_module)) {
        ark_drm_adapter_require_secure_decoder_module = nullptr;
      } else {
        ark_drm_adapter_require_secure_decoder_module =
            _struct->require_secure_decoder_module;
      }
    } else {
      ark_drm_adapter_require_secure_decoder_module =
          reinterpret_cast<ArkDrmAdapterRequireSecureDecoderModuleFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_drm_adapter_require_secure_decoder_module, 0);

  // Execute
  return ark_drm_adapter_require_secure_decoder_module(_struct, &mimeType,
                                                       &status);
}

ARK_WEB_NO_SANITIZE
int32_t ArkDrmAdapterCToCpp::GenerateMediaKeyRequest(
    const ArkWebString& sessionId,
    int32_t type,
    int32_t initDataLen,
    const ArkWebUint8Vector& initData,
    const ArkWebString& mimeType,
    uint32_t promiseId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_drm_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_drm_adapter_generate_media_key_request);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "JgEbXo_W9zF7e$_TdioWEA";
    func_pointer = ArkWebAdapterWebcoreBridgeHelper::GetInstance()
                       .CheckFuncMemberForCaller(ARK_DRM_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_drm_adapter_generate_media_key_request");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, generate_media_key_request)) {
        ark_drm_adapter_generate_media_key_request = nullptr;
      } else {
        ark_drm_adapter_generate_media_key_request =
            _struct->generate_media_key_request;
      }
    } else {
      ark_drm_adapter_generate_media_key_request =
          reinterpret_cast<ArkDrmAdapterGenerateMediaKeyRequestFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_drm_adapter_generate_media_key_request,
                                    0);

  // Execute
  return ark_drm_adapter_generate_media_key_request(
      _struct, &sessionId, type, initDataLen, &initData, &mimeType, promiseId);
}

ArkDrmAdapterCToCpp::ArkDrmAdapterCToCpp() {}

ArkDrmAdapterCToCpp::~ArkDrmAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkDrmAdapterCToCpp,
                                        ArkDrmAdapter,
                                        ark_drm_adapter_t>::kBridgeType =
    ARK_DRM_ADAPTER;

}  // namespace OHOS::ArkWeb
