// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/gpu/ohos/ohos_cenc_info.h"

#include <multimedia/player_framework/native_averrors.h>
#include <multimedia/player_framework/native_cencinfo.h>
#include <stdint.h>

#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "media/base/decrypt_config.h"
#include "media/base/encryption_scheme.h"

namespace media {

namespace {

struct CencInfoDeleter {
  void operator()(OH_AVCencInfo* info) const { OH_AVCencInfo_Destroy(info); }
};

}  // namespace

bool AttachOhosCencInfo(const DecryptConfig* config,
                        size_t sample_size,
                        OH_AVBuffer* buffer) {
  std::unique_ptr<OH_AVCencInfo, CencInfoDeleter> info(OH_AVCencInfo_Create());
  if (!info) {
    return false;
  }
  if (!config) {
    // Input buffers are reused; say so explicitly so that a clear sample
    // never inherits the previous sample's encryption.
    return OH_AVCencInfo_SetAlgorithm(info.get(), DRM_ALG_CENC_UNENCRYPTED) ==
               AV_ERR_OK &&
           OH_AVCencInfo_SetMode(info.get(),
                                 DRM_CENC_INFO_KEY_IV_SUBSAMPLES_NOT_SET) ==
               AV_ERR_OK &&
           OH_AVCencInfo_SetAVBuffer(info.get(), buffer) == AV_ERR_OK;
  }

  DrmCencAlgorithm algorithm;
  switch (config->encryption_scheme()) {
    case EncryptionScheme::kCenc:
      algorithm = DRM_ALG_CENC_AES_CTR;
      break;
    case EncryptionScheme::kCbcs:
      algorithm = DRM_ALG_CENC_AES_CBC;
      break;
    case EncryptionScheme::kUnencrypted:
      return AttachOhosCencInfo(nullptr, sample_size, buffer);
  }

  std::string key_id = config->key_id();
  std::string iv = config->iv();
  if (key_id.size() != DRM_KEY_ID_SIZE || iv.size() != DRM_KEY_IV_SIZE) {
    LOG(ERROR) << "OHOS CENC: key ID or IV of unexpected size";
    return false;
  }

  // A sample without subsamples is encrypted from end to end.
  std::vector<DrmSubsample> subsamples;
  if (config->subsamples().empty()) {
    subsamples.push_back({0, static_cast<uint32_t>(sample_size)});
  } else {
    for (const SubsampleEntry& entry : config->subsamples()) {
      subsamples.push_back({entry.clear_bytes, entry.cypher_bytes});
    }
  }
  if (subsamples.size() > DRM_KEY_MAX_SUB_SAMPLE_NUM) {
    LOG(ERROR) << "OHOS CENC: " << subsamples.size()
               << " subsamples; DRM Kit takes " << DRM_KEY_MAX_SUB_SAMPLE_NUM;
    return false;
  }
  // 'cbcs' encrypts a pattern of 16-byte blocks; without one, every block.
  uint32_t crypt_blocks = 0;
  uint32_t skip_blocks = 0;
  if (config->encryption_pattern()) {
    crypt_blocks = config->encryption_pattern()->crypt_byte_block();
    skip_blocks = config->encryption_pattern()->skip_byte_block();
  }

  return OH_AVCencInfo_SetAlgorithm(info.get(), algorithm) == AV_ERR_OK &&
         OH_AVCencInfo_SetKeyIdAndIv(
             info.get(), reinterpret_cast<uint8_t*>(key_id.data()),
             DRM_KEY_ID_SIZE, reinterpret_cast<uint8_t*>(iv.data()),
             DRM_KEY_IV_SIZE) == AV_ERR_OK &&
         OH_AVCencInfo_SetSubsampleInfo(
             info.get(), crypt_blocks, skip_blocks,
             /*firstEncryptedOffset=*/0,
             static_cast<uint32_t>(subsamples.size()),
             subsamples.data()) == AV_ERR_OK &&
         OH_AVCencInfo_SetMode(info.get(),
                               DRM_CENC_INFO_KEY_IV_SUBSAMPLES_SET) ==
             AV_ERR_OK &&
         OH_AVCencInfo_SetAVBuffer(info.get(), buffer) == AV_ERR_OK;
}

}  // namespace media
