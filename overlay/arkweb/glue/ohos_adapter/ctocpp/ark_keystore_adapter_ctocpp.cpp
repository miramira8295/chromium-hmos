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

#include "ohos_adapter/ctocpp/ark_keystore_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkKeystoreAdapterEncryptKeyFunc =
    ArkWebString (*)(struct _ark_keystore_adapter_t* self,
                     const ArkWebString* alias,
                     const ArkWebString* plainData);
static ArkKeystoreAdapterEncryptKeyFunc ark_keystore_adapter_encrypt_key =
    reinterpret_cast<ArkKeystoreAdapterEncryptKeyFunc>(ARK_WEB_INIT_ADDR);

using ArkKeystoreAdapterDecryptKeyFunc =
    ArkWebString (*)(struct _ark_keystore_adapter_t* self,
                     const ArkWebString* alis,
                     const ArkWebString* encryptedData);
static ArkKeystoreAdapterDecryptKeyFunc ark_keystore_adapter_decrypt_key =
    reinterpret_cast<ArkKeystoreAdapterDecryptKeyFunc>(ARK_WEB_INIT_ADDR);

using ArkKeystoreAdapterAssetQueryFunc =
    ArkWebString (*)(struct _ark_keystore_adapter_t* self,
                     const ArkWebString* assetHandle);
static ArkKeystoreAdapterAssetQueryFunc ark_keystore_adapter_asset_query =
    reinterpret_cast<ArkKeystoreAdapterAssetQueryFunc>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
ArkWebString ArkKeystoreAdapterCToCpp::EncryptKey(
    const ArkWebString& alias,
    const ArkWebString& plainData) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_keystore_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_keystore_adapter_encrypt_key);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "4_O2yQDqMjfkybFpPrtd0w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_KEYSTORE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_keystore_adapter_encrypt_key");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, encrypt_key)) {
        ark_keystore_adapter_encrypt_key = nullptr;
      } else {
        ark_keystore_adapter_encrypt_key = _struct->encrypt_key;
      }
    } else {
      ark_keystore_adapter_encrypt_key =
          reinterpret_cast<ArkKeystoreAdapterEncryptKeyFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_keystore_adapter_encrypt_key,
                                    ark_web_string_default);

  // Execute
  return ark_keystore_adapter_encrypt_key(_struct, &alias, &plainData);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkKeystoreAdapterCToCpp::DecryptKey(
    const ArkWebString& alis,
    const ArkWebString& encryptedData) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_keystore_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_keystore_adapter_decrypt_key);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Hd8lziMIeQ6pvcJos9vb2A";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_KEYSTORE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_keystore_adapter_decrypt_key");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, decrypt_key)) {
        ark_keystore_adapter_decrypt_key = nullptr;
      } else {
        ark_keystore_adapter_decrypt_key = _struct->decrypt_key;
      }
    } else {
      ark_keystore_adapter_decrypt_key =
          reinterpret_cast<ArkKeystoreAdapterDecryptKeyFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_keystore_adapter_decrypt_key,
                                    ark_web_string_default);

  // Execute
  return ark_keystore_adapter_decrypt_key(_struct, &alis, &encryptedData);
}

ARK_WEB_NO_SANITIZE
ArkWebString ArkKeystoreAdapterCToCpp::AssetQuery(
    const ArkWebString& assetHandle) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_keystore_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_string_default);

  void* func_pointer =
      reinterpret_cast<void*>(ark_keystore_adapter_asset_query);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "nDpfyW5hO_GgUOiqPrAW2Q";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_KEYSTORE_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_keystore_adapter_asset_query");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, asset_query)) {
        ark_keystore_adapter_asset_query = nullptr;
      } else {
        ark_keystore_adapter_asset_query = _struct->asset_query;
      }
    } else {
      ark_keystore_adapter_asset_query =
          reinterpret_cast<ArkKeystoreAdapterAssetQueryFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_keystore_adapter_asset_query,
                                    ark_web_string_default);

  // Execute
  return ark_keystore_adapter_asset_query(_struct, &assetHandle);
}

ArkKeystoreAdapterCToCpp::ArkKeystoreAdapterCToCpp() {}

ArkKeystoreAdapterCToCpp::~ArkKeystoreAdapterCToCpp() {}

template <>
ArkWebBridgeType ArkWebCToCppRefCounted<ArkKeystoreAdapterCToCpp,
                                        ArkKeystoreAdapter,
                                        ark_keystore_adapter_t>::kBridgeType =
    ARK_KEYSTORE_ADAPTER;

}  // namespace OHOS::ArkWeb
