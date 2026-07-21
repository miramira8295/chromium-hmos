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

#ifndef ARK_OHOS_NATIVE_BUFFER_ADAPTER_CTOCPP_H_
#define ARK_OHOS_NATIVE_BUFFER_ADAPTER_CTOCPP_H_
#pragma once

#include "base/ctocpp/ark_web_ctocpp_ref_counted.h"
#include "ohos_adapter/capi/ark_ohos_native_buffer_adapter_capi.h"
#include "ohos_adapter/include/ark_ohos_native_buffer_adapter.h"

namespace OHOS::ArkWeb {

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class ArkOhosNativeBufferAdapterCToCpp
    : public ArkWebCToCppRefCounted<ArkOhosNativeBufferAdapterCToCpp,
                                    ArkOhosNativeBufferAdapter,
                                    ark_ohos_native_buffer_adapter_t> {
 public:
  ArkOhosNativeBufferAdapterCToCpp();
  virtual ~ArkOhosNativeBufferAdapterCToCpp();

  // ArkOhosNativeBufferAdapter methods.
  void AcquireBuffer(void* buffer) override;

  void Release(void* buffer) override;

  int GetEGLBuffer(void* buffer, void** eglBuffer) override;

  int FreeEGLBuffer(void* eglBuffer) override;

  int NativeBufferFromNativeWindowBuffer(void* nativeWindowBuffer,
                                         void** nativeBuffer) override;

  uint32_t GetSeqNum(void* nativeBuffer) override;

  void Allocate(const ArkWebRefPtr<ArkNativeBufferConfigAdapter> bufferConfig,
                void** outBuffer) override;

  void Describe(ArkWebRefPtr<ArkNativeBufferConfigAdapter> bufferConfig,
                void* buffer) override;

  int Lock(void* buffer,
           uint64_t usage,
           int32_t fence,
           void** out_virtual_address) override;

  int RecvHandleFromUnixSocket(int socketFd, void** outBuffer) override;

  int SendHandleToUnixSocket(const void* buffer, int socketFd) override;

  int Unlock(void* buffer, int32_t* fence) override;

  int FreeNativeBuffer(void* nativeBuffer) override;
};

}  // namespace OHOS::ArkWeb

#endif  // ARK_OHOS_NATIVE_BUFFER_ADAPTER_CTOCPP_H_
