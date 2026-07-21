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

#ifndef ARK_OHOS_IMAGE_DECODER_ADAPTER_CTOCPP_H_
#define ARK_OHOS_IMAGE_DECODER_ADAPTER_CTOCPP_H_
#pragma once

#include "base/ctocpp/ark_web_ctocpp_ref_counted.h"
#include "ohos_adapter/capi/ark_ohos_image_decoder_adapter_capi.h"
#include "ohos_adapter/include/ark_ohos_image_decoder_adapter.h"

namespace OHOS::ArkWeb {

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class ArkOhosImageDecoderAdapterCToCpp
    : public ArkWebCToCppRefCounted<ArkOhosImageDecoderAdapterCToCpp,
                                    ArkOhosImageDecoderAdapter,
                                    ark_ohos_image_decoder_adapter_t> {
 public:
  ArkOhosImageDecoderAdapterCToCpp();
  virtual ~ArkOhosImageDecoderAdapterCToCpp();

  // ArkOhosImageDecoderAdapter methods.
  bool ParseImageInfo(const uint8_t* data, uint32_t size) override;

  ArkWebString GetEncodedFormat() override;

  int32_t GetImageWidth() override;

  int32_t GetImageHeight() override;

  bool DecodeToPixelMap(const uint8_t* data, uint32_t size) override;

  int32_t GetFd() override;

  int32_t GetStride() override;

  int32_t GetOffset() override;

  uint64_t GetSize() override;

  void* GetNativeWindowBuffer() override;

  int32_t GetPlanesCount() override;

  void ReleasePixelMap() override;

  bool Decode(const uint8_t* data,
              uint32_t size,
              uint32_t type,
              bool useYuv) override;

  void* GetDecodeData() override;
};

}  // namespace OHOS::ArkWeb

#endif  // ARK_OHOS_IMAGE_DECODER_ADAPTER_CTOCPP_H_
