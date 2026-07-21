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

#include "ohos_adapter/cpptoc/ark_audio_cenc_info_adapter_cpptoc.h"

#include "base/cpptoc/ark_web_cpptoc_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

namespace {

uint8_t* ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_get_key_id(
    struct _ark_audio_cenc_info_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  return ArkAudioCencInfoAdapterCppToC::Get(self)->GetKeyId();
}

uint32_t ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_get_key_id_len(
    struct _ark_audio_cenc_info_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioCencInfoAdapterCppToC::Get(self)->GetKeyIdLen();
}

uint8_t* ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_get_iv(
    struct _ark_audio_cenc_info_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, NULL);

  // Execute
  return ArkAudioCencInfoAdapterCppToC::Get(self)->GetIv();
}

uint32_t ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_get_iv_len(
    struct _ark_audio_cenc_info_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioCencInfoAdapterCppToC::Get(self)->GetIvLen();
}

uint32_t ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_get_algo(
    struct _ark_audio_cenc_info_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioCencInfoAdapterCppToC::Get(self)->GetAlgo();
}

uint32_t ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_get_encrypted_block_count(
    struct _ark_audio_cenc_info_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioCencInfoAdapterCppToC::Get(self)->GetEncryptedBlockCount();
}

uint32_t ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_get_skipped_block_count(
    struct _ark_audio_cenc_info_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioCencInfoAdapterCppToC::Get(self)->GetSkippedBlockCount();
}

uint32_t ARK_WEB_CALLBACK
ark_audio_cenc_info_adapter_get_first_encrypted_offset(
    struct _ark_audio_cenc_info_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioCencInfoAdapterCppToC::Get(self)->GetFirstEncryptedOffset();
}

ArkWebUint32Vector ARK_WEB_CALLBACK
ark_audio_cenc_info_adapter_get_clear_header_lens(
    struct _ark_audio_cenc_info_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_uint32_vector_default);

  // Execute
  return ArkAudioCencInfoAdapterCppToC::Get(self)->GetClearHeaderLens();
}

ArkWebUint32Vector ARK_WEB_CALLBACK
ark_audio_cenc_info_adapter_get_pay_load_lens(
    struct _ark_audio_cenc_info_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ark_web_uint32_vector_default);

  // Execute
  return ArkAudioCencInfoAdapterCppToC::Get(self)->GetPayLoadLens();
}

uint32_t ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_get_mode(
    struct _ark_audio_cenc_info_adapter_t* self) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, 0);

  // Execute
  return ArkAudioCencInfoAdapterCppToC::Get(self)->GetMode();
}

void ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_set_key_id(
    struct _ark_audio_cenc_info_adapter_t* self,
    uint8_t* keyId) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioCencInfoAdapterCppToC::Get(self)->SetKeyId(keyId);
}

void ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_set_key_id_len(
    struct _ark_audio_cenc_info_adapter_t* self,
    uint32_t keyIdLen) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioCencInfoAdapterCppToC::Get(self)->SetKeyIdLen(keyIdLen);
}

void ARK_WEB_CALLBACK
ark_audio_cenc_info_adapter_set_iv(struct _ark_audio_cenc_info_adapter_t* self,
                                   uint8_t* iv) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioCencInfoAdapterCppToC::Get(self)->SetIv(iv);
}

void ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_set_iv_len(
    struct _ark_audio_cenc_info_adapter_t* self,
    uint32_t ivLen) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioCencInfoAdapterCppToC::Get(self)->SetIvLen(ivLen);
}

void ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_set_algo(
    struct _ark_audio_cenc_info_adapter_t* self,
    uint32_t algo) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioCencInfoAdapterCppToC::Get(self)->SetAlgo(algo);
}

void ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_set_encrypted_block_count(
    struct _ark_audio_cenc_info_adapter_t* self,
    uint32_t blockCount) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioCencInfoAdapterCppToC::Get(self)->SetEncryptedBlockCount(blockCount);
}

void ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_set_skipped_block_count(
    struct _ark_audio_cenc_info_adapter_t* self,
    uint32_t blockCount) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioCencInfoAdapterCppToC::Get(self)->SetSkippedBlockCount(blockCount);
}

void ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_set_first_encrypted_offset(
    struct _ark_audio_cenc_info_adapter_t* self,
    uint32_t offset) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioCencInfoAdapterCppToC::Get(self)->SetFirstEncryptedOffset(offset);
}

void ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_set_clear_header_lens(
    struct _ark_audio_cenc_info_adapter_t* self,
    const ArkWebUint32Vector* lens) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(lens, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioCencInfoAdapterCppToC::Get(self)->SetClearHeaderLens(*lens);
}

void ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_set_pay_load_lens(
    struct _ark_audio_cenc_info_adapter_t* self,
    const ArkWebUint32Vector* lens) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);
  ARK_WEB_CPPTOC_CHECK_PARAM(lens, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioCencInfoAdapterCppToC::Get(self)->SetPayLoadLens(*lens);
}

void ARK_WEB_CALLBACK ark_audio_cenc_info_adapter_set_mode(
    struct _ark_audio_cenc_info_adapter_t* self,
    uint32_t mode) {
  ARK_WEB_CPPTOC_DV_LOG("capi struct is %{public}ld", (long)self);

  ARK_WEB_CPPTOC_CHECK_PARAM(self, ARK_WEB_RETURN_VOID);

  // Execute
  ArkAudioCencInfoAdapterCppToC::Get(self)->SetMode(mode);
}

}  // namespace

ArkAudioCencInfoAdapterCppToC::ArkAudioCencInfoAdapterCppToC() {
  GetStruct()->get_key_id = ark_audio_cenc_info_adapter_get_key_id;
  GetStruct()->get_key_id_len = ark_audio_cenc_info_adapter_get_key_id_len;
  GetStruct()->get_iv = ark_audio_cenc_info_adapter_get_iv;
  GetStruct()->get_iv_len = ark_audio_cenc_info_adapter_get_iv_len;
  GetStruct()->get_algo = ark_audio_cenc_info_adapter_get_algo;
  GetStruct()->get_encrypted_block_count =
      ark_audio_cenc_info_adapter_get_encrypted_block_count;
  GetStruct()->get_skipped_block_count =
      ark_audio_cenc_info_adapter_get_skipped_block_count;
  GetStruct()->get_first_encrypted_offset =
      ark_audio_cenc_info_adapter_get_first_encrypted_offset;
  GetStruct()->get_clear_header_lens =
      ark_audio_cenc_info_adapter_get_clear_header_lens;
  GetStruct()->get_pay_load_lens =
      ark_audio_cenc_info_adapter_get_pay_load_lens;
  GetStruct()->get_mode = ark_audio_cenc_info_adapter_get_mode;
  GetStruct()->set_key_id = ark_audio_cenc_info_adapter_set_key_id;
  GetStruct()->set_key_id_len = ark_audio_cenc_info_adapter_set_key_id_len;
  GetStruct()->set_iv = ark_audio_cenc_info_adapter_set_iv;
  GetStruct()->set_iv_len = ark_audio_cenc_info_adapter_set_iv_len;
  GetStruct()->set_algo = ark_audio_cenc_info_adapter_set_algo;
  GetStruct()->set_encrypted_block_count =
      ark_audio_cenc_info_adapter_set_encrypted_block_count;
  GetStruct()->set_skipped_block_count =
      ark_audio_cenc_info_adapter_set_skipped_block_count;
  GetStruct()->set_first_encrypted_offset =
      ark_audio_cenc_info_adapter_set_first_encrypted_offset;
  GetStruct()->set_clear_header_lens =
      ark_audio_cenc_info_adapter_set_clear_header_lens;
  GetStruct()->set_pay_load_lens =
      ark_audio_cenc_info_adapter_set_pay_load_lens;
  GetStruct()->set_mode = ark_audio_cenc_info_adapter_set_mode;

  static std::once_flag flag;
  std::call_once(flag, [] {
    std::map<std::string, void*> funcMemberMap;
    funcMemberMap["eigQyLI8JQbgbYnU5mHPrw"] =
        reinterpret_cast<void*>(ark_audio_cenc_info_adapter_get_key_id);
    funcMemberMap["FjLjpevLgmlLD5yTuln8Pw"] =
        reinterpret_cast<void*>(ark_audio_cenc_info_adapter_get_key_id_len);
    funcMemberMap["QEcPpDsg56Iz9G2SMWpHrg"] =
        reinterpret_cast<void*>(ark_audio_cenc_info_adapter_get_iv);
    funcMemberMap["qm09GT3iTWhjqDfhb6Z6bQ"] =
        reinterpret_cast<void*>(ark_audio_cenc_info_adapter_get_iv_len);
    funcMemberMap["ije_K3zaY4pVluUwzEYWag"] =
        reinterpret_cast<void*>(ark_audio_cenc_info_adapter_get_algo);
    funcMemberMap["Wvy_drGC4$toI1TiNf94pA"] = reinterpret_cast<void*>(
        ark_audio_cenc_info_adapter_get_encrypted_block_count);
    funcMemberMap["nkvJmjIvdXCiu95NJcQRKA"] = reinterpret_cast<void*>(
        ark_audio_cenc_info_adapter_get_skipped_block_count);
    funcMemberMap["TXheeY00MB98ojoiSZI5yw"] = reinterpret_cast<void*>(
        ark_audio_cenc_info_adapter_get_first_encrypted_offset);
    funcMemberMap["sfkXBEl9XgGG1oKrgIe5pg"] = reinterpret_cast<void*>(
        ark_audio_cenc_info_adapter_get_clear_header_lens);
    funcMemberMap["QNvip52674EE0k_jyB6Q2Q"] =
        reinterpret_cast<void*>(ark_audio_cenc_info_adapter_get_pay_load_lens);
    funcMemberMap["TpwC29QSIPyPMiF6I998Zg"] =
        reinterpret_cast<void*>(ark_audio_cenc_info_adapter_get_mode);
    funcMemberMap["u42fedpOmi_ULpgNlDaGkw"] =
        reinterpret_cast<void*>(ark_audio_cenc_info_adapter_set_key_id);
    funcMemberMap["orddmp42eVQS20Q2Ip0SUg"] =
        reinterpret_cast<void*>(ark_audio_cenc_info_adapter_set_key_id_len);
    funcMemberMap["No0icCV_$kSaAwNKnKyeQA"] =
        reinterpret_cast<void*>(ark_audio_cenc_info_adapter_set_iv);
    funcMemberMap["xFGj$SlPl3kVMq3w_CaIXw"] =
        reinterpret_cast<void*>(ark_audio_cenc_info_adapter_set_iv_len);
    funcMemberMap["OzPgzwvg2plJfWk5UsdksA"] =
        reinterpret_cast<void*>(ark_audio_cenc_info_adapter_set_algo);
    funcMemberMap["RApyXCWyAZnSYNFJ6b3Fwg"] = reinterpret_cast<void*>(
        ark_audio_cenc_info_adapter_set_encrypted_block_count);
    funcMemberMap["HNA$vZC_5EdKa83B_FDjCg"] = reinterpret_cast<void*>(
        ark_audio_cenc_info_adapter_set_skipped_block_count);
    funcMemberMap["XIRCjUxYy399fFEaE9I2eA"] = reinterpret_cast<void*>(
        ark_audio_cenc_info_adapter_set_first_encrypted_offset);
    funcMemberMap["T_eE8vRfVZBbxLHhnNP_2w"] = reinterpret_cast<void*>(
        ark_audio_cenc_info_adapter_set_clear_header_lens);
    funcMemberMap["EWmNliPtd62RodGMONjQtA"] =
        reinterpret_cast<void*>(ark_audio_cenc_info_adapter_set_pay_load_lens);
    funcMemberMap["hsi1wkMXE367Q1Yx1i63Mw"] =
        reinterpret_cast<void*>(ark_audio_cenc_info_adapter_set_mode);
    ArkWebAdapterWebcoreBridgeHelper::GetInstance().RegisterFuncMember(
        ARK_AUDIO_CENC_INFO_ADAPTER, funcMemberMap);
  });
}

ArkAudioCencInfoAdapterCppToC::~ArkAudioCencInfoAdapterCppToC() {}

template <>
ArkWebBridgeType
    ArkWebCppToCRefCounted<ArkAudioCencInfoAdapterCppToC,
                           ArkAudioCencInfoAdapter,
                           ark_audio_cenc_info_adapter_t>::kBridgeType =
        ARK_AUDIO_CENC_INFO_ADAPTER;

}  // namespace OHOS::ArkWeb
