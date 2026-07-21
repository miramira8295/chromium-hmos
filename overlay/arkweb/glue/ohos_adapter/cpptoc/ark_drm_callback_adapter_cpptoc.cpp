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

#include "ohos_adapter/cpptoc/ark_drm_callback_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

void ARK_WEB_CALLBACK ark_drm_callback_adapter_on_session_message(
    struct _ark_drm_callback_adapter_t* self,
    const ArkWebString* sessionId,
    int32_t* type,
    const ArkWebUint8Vector* message) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(sessionId, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(type, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(message, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDrmCallbackAdapterCppToC::Get(self)->OnSessionMessage(*sessionId, *type,
                                                           *message);
}

void ARK_WEB_CALLBACK ark_drm_callback_adapter_on_provision_request(
    struct _ark_drm_callback_adapter_t* self,
    const ArkWebString* defaultUrl,
    const ArkWebString* requestData) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(defaultUrl, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(requestData, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDrmCallbackAdapterCppToC::Get(self)->OnProvisionRequest(*defaultUrl,
                                                             *requestData);
}

void ARK_WEB_CALLBACK ark_drm_callback_adapter_on_provisioning_complete(
    struct _ark_drm_callback_adapter_t* self,
    bool success) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDrmCallbackAdapterCppToC::Get(self)->OnProvisioningComplete(success);
}

void ARK_WEB_CALLBACK ark_drm_callback_adapter_on_media_key_session_ready(
    struct _ark_drm_callback_adapter_t* self,
    void* session) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDrmCallbackAdapterCppToC::Get(self)->OnMediaKeySessionReady(session);
}

void ARK_WEB_CALLBACK ark_drm_callback_adapter_on_promise_rejected(
    struct _ark_drm_callback_adapter_t* self,
    uint32_t promiseId,
    const ArkWebString* errorMessage) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(errorMessage, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDrmCallbackAdapterCppToC::Get(self)->OnPromiseRejected(promiseId,
                                                            *errorMessage);
}

void ARK_WEB_CALLBACK ark_drm_callback_adapter_on_promise_resolved(
    struct _ark_drm_callback_adapter_t* self,
    uint32_t promiseId) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDrmCallbackAdapterCppToC::Get(self)->OnPromiseResolved(promiseId);
}

void ARK_WEB_CALLBACK ark_drm_callback_adapter_on_promise_resolved_with_session(
    struct _ark_drm_callback_adapter_t* self,
    uint32_t promiseId,
    const ArkWebString* sessionId) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(sessionId, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDrmCallbackAdapterCppToC::Get(self)->OnPromiseResolvedWithSession(
      promiseId, *sessionId);
}

void ARK_WEB_CALLBACK ark_drm_callback_adapter_on_session_closed(
    struct _ark_drm_callback_adapter_t* self,
    const ArkWebString* sessionId) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(sessionId, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDrmCallbackAdapterCppToC::Get(self)->OnSessionClosed(*sessionId);
}

void ARK_WEB_CALLBACK ark_drm_callback_adapter_on_session_keys_change(
    struct _ark_drm_callback_adapter_t* self,
    const ArkWebString* sessionId,
    const ArkWebStringVector* keyIdArray,
    const ArkWebUint32Vector* statusArray,
    bool hasAdditionalUsableKey,
    bool isKeyRelease) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(sessionId, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(keyIdArray, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(statusArray, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDrmCallbackAdapterCppToC::Get(self)->OnSessionKeysChange(
      *sessionId, *keyIdArray, *statusArray, hasAdditionalUsableKey,
      isKeyRelease);
}

void ARK_WEB_CALLBACK ark_drm_callback_adapter_on_session_expiration_update(
    struct _ark_drm_callback_adapter_t* self,
    const ArkWebString* sessionId,
    uint64_t expirationTime) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(sessionId, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDrmCallbackAdapterCppToC::Get(self)->OnSessionExpirationUpdate(
      *sessionId, expirationTime);
}

void ARK_WEB_CALLBACK ark_drm_callback_adapter_on_storage_provisioned(
    struct _ark_drm_callback_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDrmCallbackAdapterCppToC::Get(self)->OnStorageProvisioned();
}

void ARK_WEB_CALLBACK ark_drm_callback_adapter_on_storage_save_info(
    struct _ark_drm_callback_adapter_t* self,
    const ArkWebUint8Vector* ketSetId,
    const ArkWebString* mimeType,
    const ArkWebString* sessionId,
    int32_t keyType) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(ketSetId, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(mimeType, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(sessionId, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDrmCallbackAdapterCppToC::Get(self)->OnStorageSaveInfo(
      *ketSetId, *mimeType, *sessionId, keyType);
}

void ARK_WEB_CALLBACK ark_drm_callback_adapter_on_storage_load_info(
    struct _ark_drm_callback_adapter_t* self,
    const ArkWebString* sessionId) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(sessionId, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDrmCallbackAdapterCppToC::Get(self)->OnStorageLoadInfo(*sessionId);
}

void ARK_WEB_CALLBACK
ark_drm_callback_adapter_on_storage_clear_info_for_key_release(
    struct _ark_drm_callback_adapter_t* self,
    const ArkWebString* sessionId) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(sessionId, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDrmCallbackAdapterCppToC::Get(self)->OnStorageClearInfoForKeyRelease(
      *sessionId);
}

void ARK_WEB_CALLBACK
ark_drm_callback_adapter_on_storage_clear_info_for_load_fail(
    struct _ark_drm_callback_adapter_t* self,
    const ArkWebString* sessionId) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(sessionId, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDrmCallbackAdapterCppToC::Get(self)->OnStorageClearInfoForLoadFail(
      *sessionId);
}

void ARK_WEB_CALLBACK ark_drm_callback_adapter_on_media_license_ready(
    struct _ark_drm_callback_adapter_t* self,
    bool success) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkDrmCallbackAdapterCppToC::Get(self)->OnMediaLicenseReady(success);
}

}  // namespace

ArkDrmCallbackAdapterCppToC::ArkDrmCallbackAdapterCppToC() {
  GetStruct()->on_session_message = ark_drm_callback_adapter_on_session_message;
  GetStruct()->on_provision_request =
      ark_drm_callback_adapter_on_provision_request;
  GetStruct()->on_provisioning_complete =
      ark_drm_callback_adapter_on_provisioning_complete;
  GetStruct()->on_media_key_session_ready =
      ark_drm_callback_adapter_on_media_key_session_ready;
  GetStruct()->on_promise_rejected =
      ark_drm_callback_adapter_on_promise_rejected;
  GetStruct()->on_promise_resolved =
      ark_drm_callback_adapter_on_promise_resolved;
  GetStruct()->on_promise_resolved_with_session =
      ark_drm_callback_adapter_on_promise_resolved_with_session;
  GetStruct()->on_session_closed = ark_drm_callback_adapter_on_session_closed;
  GetStruct()->on_session_keys_change =
      ark_drm_callback_adapter_on_session_keys_change;
  GetStruct()->on_session_expiration_update =
      ark_drm_callback_adapter_on_session_expiration_update;
  GetStruct()->on_storage_provisioned =
      ark_drm_callback_adapter_on_storage_provisioned;
  GetStruct()->on_storage_save_info =
      ark_drm_callback_adapter_on_storage_save_info;
  GetStruct()->on_storage_load_info =
      ark_drm_callback_adapter_on_storage_load_info;
  GetStruct()->on_storage_clear_info_for_key_release =
      ark_drm_callback_adapter_on_storage_clear_info_for_key_release;
  GetStruct()->on_storage_clear_info_for_load_fail =
      ark_drm_callback_adapter_on_storage_clear_info_for_load_fail;
  GetStruct()->on_media_license_ready =
      ark_drm_callback_adapter_on_media_license_ready;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["jTuSKoABjZxiz2UNbm3t5w"] =
        reinterpret_cast<void*>(ark_drm_callback_adapter_on_session_message);
    funcMemberMap["0W6QL9mC0munisVRBcCJGA"] =
        reinterpret_cast<void*>(ark_drm_callback_adapter_on_provision_request);
    funcMemberMap["Cch9oSTZ6OB3YSnk43qS4w"] = reinterpret_cast<void*>(
        ark_drm_callback_adapter_on_provisioning_complete);
    funcMemberMap["YAm2dEkEeolkfl9kYlzF1Q"] = reinterpret_cast<void*>(
        ark_drm_callback_adapter_on_media_key_session_ready);
    funcMemberMap["que4BCaL$MrNgPx2AmyJhg"] =
        reinterpret_cast<void*>(ark_drm_callback_adapter_on_promise_rejected);
    funcMemberMap["O_2$Yz61jkhHPdtQwk6INA"] =
        reinterpret_cast<void*>(ark_drm_callback_adapter_on_promise_resolved);
    funcMemberMap["pgmLab4mG27OaHozzDho4w"] = reinterpret_cast<void*>(
        ark_drm_callback_adapter_on_promise_resolved_with_session);
    funcMemberMap["cPNIhllEtIePCNVftS$0pg"] =
        reinterpret_cast<void*>(ark_drm_callback_adapter_on_session_closed);
    funcMemberMap["5RnJ_p48H5uorbDHWPJc0A"] = reinterpret_cast<void*>(
        ark_drm_callback_adapter_on_session_keys_change);
    funcMemberMap["b6KXT_DWOdAUZvfDGyZ0NA"] = reinterpret_cast<void*>(
        ark_drm_callback_adapter_on_session_expiration_update);
    funcMemberMap["l4W4PTVPa6Qkt91XqglIZg"] = reinterpret_cast<void*>(
        ark_drm_callback_adapter_on_storage_provisioned);
    funcMemberMap["fweeSMdeOceRcQAYfyIQDw"] =
        reinterpret_cast<void*>(ark_drm_callback_adapter_on_storage_save_info);
    funcMemberMap["ZxHkMIAo5o6g6J4_hIOxrA"] =
        reinterpret_cast<void*>(ark_drm_callback_adapter_on_storage_load_info);
    funcMemberMap["AZk_1mcT3ke4G8H9Dk6FYw"] = reinterpret_cast<void*>(
        ark_drm_callback_adapter_on_storage_clear_info_for_key_release);
    funcMemberMap["LMALP4zs5LAL7p5YuzPOOQ"] = reinterpret_cast<void*>(
        ark_drm_callback_adapter_on_storage_clear_info_for_load_fail);
    funcMemberMap["Nh1k7YfY_YZFeMSCUk1UDA"] = reinterpret_cast<void*>(
        ark_drm_callback_adapter_on_media_license_ready);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_DRM_CALLBACK_ADAPTER, funcMemberMap);
  });
}

ArkDrmCallbackAdapterCppToC::~ArkDrmCallbackAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkDrmCallbackAdapterCppToC,
                           ArkDrmCallbackAdapter,
                           ark_drm_callback_adapter_t>::kBridgeType =
        ARK_DRM_CALLBACK_ADAPTER;

}  // namespace OHOS::ArkWeb
