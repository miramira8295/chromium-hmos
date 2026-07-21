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

#include "ohos_adapter/ctocpp/ark_ohos_native_buffer_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_native_buffer_config_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkOhosNativeBufferAdapterAcquireBufferFunc =
    void (*)(struct _ark_ohos_native_buffer_adapter_t* self, void* buffer);
static ArkOhosNativeBufferAdapterAcquireBufferFunc
    ark_ohos_native_buffer_adapter_acquire_buffer =
        reinterpret_cast<ArkOhosNativeBufferAdapterAcquireBufferFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosNativeBufferAdapterReleaseFunc =
    void (*)(struct _ark_ohos_native_buffer_adapter_t* self, void* buffer);
static ArkOhosNativeBufferAdapterReleaseFunc
    ark_ohos_native_buffer_adapter_release =
        reinterpret_cast<ArkOhosNativeBufferAdapterReleaseFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosNativeBufferAdapterGetEGLBufferFunc =
    int (*)(struct _ark_ohos_native_buffer_adapter_t* self,
            void* buffer,
            void** eglBuffer);
static ArkOhosNativeBufferAdapterGetEGLBufferFunc
    ark_ohos_native_buffer_adapter_get_eglbuffer =
        reinterpret_cast<ArkOhosNativeBufferAdapterGetEGLBufferFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosNativeBufferAdapterFreeEGLBufferFunc =
    int (*)(struct _ark_ohos_native_buffer_adapter_t* self, void* eglBuffer);
static ArkOhosNativeBufferAdapterFreeEGLBufferFunc
    ark_ohos_native_buffer_adapter_free_eglbuffer =
        reinterpret_cast<ArkOhosNativeBufferAdapterFreeEGLBufferFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosNativeBufferAdapterNativeBufferFromNativeWindowBufferFunc =
    int (*)(struct _ark_ohos_native_buffer_adapter_t* self,
            void* nativeWindowBuffer,
            void** nativeBuffer);
static ArkOhosNativeBufferAdapterNativeBufferFromNativeWindowBufferFunc
    ark_ohos_native_buffer_adapter_native_buffer_from_native_window_buffer =
        reinterpret_cast<
            ArkOhosNativeBufferAdapterNativeBufferFromNativeWindowBufferFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosNativeBufferAdapterGetSeqNumFunc =
    uint32_t (*)(struct _ark_ohos_native_buffer_adapter_t* self,
                 void* nativeBuffer);
static ArkOhosNativeBufferAdapterGetSeqNumFunc
    ark_ohos_native_buffer_adapter_get_seq_num =
        reinterpret_cast<ArkOhosNativeBufferAdapterGetSeqNumFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosNativeBufferAdapterAllocateFunc =
    void (*)(struct _ark_ohos_native_buffer_adapter_t* self,
             ark_native_buffer_config_adapter_t* bufferConfig,
             void** outBuffer);
static ArkOhosNativeBufferAdapterAllocateFunc
    ark_ohos_native_buffer_adapter_allocate =
        reinterpret_cast<ArkOhosNativeBufferAdapterAllocateFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosNativeBufferAdapterDescribeFunc =
    void (*)(struct _ark_ohos_native_buffer_adapter_t* self,
             ark_native_buffer_config_adapter_t* bufferConfig,
             void* buffer);
static ArkOhosNativeBufferAdapterDescribeFunc
    ark_ohos_native_buffer_adapter_describe =
        reinterpret_cast<ArkOhosNativeBufferAdapterDescribeFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosNativeBufferAdapterLockFunc =
    int (*)(struct _ark_ohos_native_buffer_adapter_t* self,
            void* buffer,
            uint64_t usage,
            int32_t fence,
            void** out_virtual_address);
static ArkOhosNativeBufferAdapterLockFunc ark_ohos_native_buffer_adapter_lock =
    reinterpret_cast<ArkOhosNativeBufferAdapterLockFunc>(ARK_WEB_INIT_ADDR);

using ArkOhosNativeBufferAdapterRecvHandleFromUnixSocketFunc =
    int (*)(struct _ark_ohos_native_buffer_adapter_t* self,
            int socketFd,
            void** outBuffer);
static ArkOhosNativeBufferAdapterRecvHandleFromUnixSocketFunc
    ark_ohos_native_buffer_adapter_recv_handle_from_unix_socket =
        reinterpret_cast<
            ArkOhosNativeBufferAdapterRecvHandleFromUnixSocketFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosNativeBufferAdapterSendHandleToUnixSocketFunc =
    int (*)(struct _ark_ohos_native_buffer_adapter_t* self,
            const void* buffer,
            int socketFd);
static ArkOhosNativeBufferAdapterSendHandleToUnixSocketFunc
    ark_ohos_native_buffer_adapter_send_handle_to_unix_socket =
        reinterpret_cast<ArkOhosNativeBufferAdapterSendHandleToUnixSocketFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosNativeBufferAdapterUnlockFunc =
    int (*)(struct _ark_ohos_native_buffer_adapter_t* self,
            void* buffer,
            int32_t* fence);
static ArkOhosNativeBufferAdapterUnlockFunc
    ark_ohos_native_buffer_adapter_unlock =
        reinterpret_cast<ArkOhosNativeBufferAdapterUnlockFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosNativeBufferAdapterFreeNativeBufferFunc =
    int (*)(struct _ark_ohos_native_buffer_adapter_t* self, void* nativeBuffer);
static ArkOhosNativeBufferAdapterFreeNativeBufferFunc
    ark_ohos_native_buffer_adapter_free_native_buffer =
        reinterpret_cast<ArkOhosNativeBufferAdapterFreeNativeBufferFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
void ArkOhosNativeBufferAdapterCToCpp::AcquireBuffer(void* buffer) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_native_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_native_buffer_adapter_acquire_buffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "kTfo_gepSrNwcbWB_Smrbw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_NATIVE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_native_buffer_adapter_acquire_buffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, acquire_buffer)) {
        ark_ohos_native_buffer_adapter_acquire_buffer = nullptr;
      } else {
        ark_ohos_native_buffer_adapter_acquire_buffer = _struct->acquire_buffer;
      }
    } else {
      ark_ohos_native_buffer_adapter_acquire_buffer =
          reinterpret_cast<ArkOhosNativeBufferAdapterAcquireBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_native_buffer_adapter_acquire_buffer, ARK_WEB_RETURN_VOID);

  // Execute
  ark_ohos_native_buffer_adapter_acquire_buffer(_struct, buffer);
}

ARK_WEB_NO_SANITIZE
void ArkOhosNativeBufferAdapterCToCpp::Release(void* buffer) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_native_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_native_buffer_adapter_release);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "KxqE9RjGkxFjjLUU_6H3xg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_NATIVE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_native_buffer_adapter_release");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, release)) {
        ark_ohos_native_buffer_adapter_release = nullptr;
      } else {
        ark_ohos_native_buffer_adapter_release = _struct->release;
      }
    } else {
      ark_ohos_native_buffer_adapter_release =
          reinterpret_cast<ArkOhosNativeBufferAdapterReleaseFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_native_buffer_adapter_release,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_ohos_native_buffer_adapter_release(_struct, buffer);
}

ARK_WEB_NO_SANITIZE
int ArkOhosNativeBufferAdapterCToCpp::GetEGLBuffer(void* buffer,
                                                   void** eglBuffer) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_native_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_native_buffer_adapter_get_eglbuffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "v4NoSmhNlpkdWsL7zVWi2g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_NATIVE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_native_buffer_adapter_get_eglbuffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_eglbuffer)) {
        ark_ohos_native_buffer_adapter_get_eglbuffer = nullptr;
      } else {
        ark_ohos_native_buffer_adapter_get_eglbuffer = _struct->get_eglbuffer;
      }
    } else {
      ark_ohos_native_buffer_adapter_get_eglbuffer =
          reinterpret_cast<ArkOhosNativeBufferAdapterGetEGLBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_native_buffer_adapter_get_eglbuffer, 0);

  // Execute
  return ark_ohos_native_buffer_adapter_get_eglbuffer(_struct, buffer,
                                                      eglBuffer);
}

ARK_WEB_NO_SANITIZE
int ArkOhosNativeBufferAdapterCToCpp::FreeEGLBuffer(void* eglBuffer) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_native_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_native_buffer_adapter_free_eglbuffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "XpjyVuks28EHpMQk1ekiHw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_NATIVE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_native_buffer_adapter_free_eglbuffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, free_eglbuffer)) {
        ark_ohos_native_buffer_adapter_free_eglbuffer = nullptr;
      } else {
        ark_ohos_native_buffer_adapter_free_eglbuffer = _struct->free_eglbuffer;
      }
    } else {
      ark_ohos_native_buffer_adapter_free_eglbuffer =
          reinterpret_cast<ArkOhosNativeBufferAdapterFreeEGLBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_native_buffer_adapter_free_eglbuffer, 0);

  // Execute
  return ark_ohos_native_buffer_adapter_free_eglbuffer(_struct, eglBuffer);
}

ARK_WEB_NO_SANITIZE
int ArkOhosNativeBufferAdapterCToCpp::NativeBufferFromNativeWindowBuffer(
    void* nativeWindowBuffer,
    void** nativeBuffer) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_native_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_native_buffer_adapter_native_buffer_from_native_window_buffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Tx0Bj8t2bicque2GkSyfuA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_NATIVE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_native_buffer_adapter_native_buffer_from_native_window_"
          "buffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(
              _struct, native_buffer_from_native_window_buffer)) {
        ark_ohos_native_buffer_adapter_native_buffer_from_native_window_buffer =
            nullptr;
      } else {
        ark_ohos_native_buffer_adapter_native_buffer_from_native_window_buffer =
            _struct->native_buffer_from_native_window_buffer;
      }
    } else {
      ark_ohos_native_buffer_adapter_native_buffer_from_native_window_buffer =
          reinterpret_cast<
              ArkOhosNativeBufferAdapterNativeBufferFromNativeWindowBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_native_buffer_adapter_native_buffer_from_native_window_buffer,
      0);

  // Execute
  return ark_ohos_native_buffer_adapter_native_buffer_from_native_window_buffer(
      _struct, nativeWindowBuffer, nativeBuffer);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkOhosNativeBufferAdapterCToCpp::GetSeqNum(void* nativeBuffer) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_native_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_native_buffer_adapter_get_seq_num);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "cY$fHfzC73YCacbVLOYjLg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_NATIVE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_native_buffer_adapter_get_seq_num");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_seq_num)) {
        ark_ohos_native_buffer_adapter_get_seq_num = nullptr;
      } else {
        ark_ohos_native_buffer_adapter_get_seq_num = _struct->get_seq_num;
      }
    } else {
      ark_ohos_native_buffer_adapter_get_seq_num =
          reinterpret_cast<ArkOhosNativeBufferAdapterGetSeqNumFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_native_buffer_adapter_get_seq_num,
                                    0);

  // Execute
  return ark_ohos_native_buffer_adapter_get_seq_num(_struct, nativeBuffer);
}

ARK_WEB_NO_SANITIZE
void ArkOhosNativeBufferAdapterCToCpp::Allocate(
    const ArkWebRefPtr<ArkNativeBufferConfigAdapter> bufferConfig,
    void** outBuffer) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_native_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_native_buffer_adapter_allocate);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "AEMlssieN_5xmW4kVK8ljA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_NATIVE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_native_buffer_adapter_allocate");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, allocate)) {
        ark_ohos_native_buffer_adapter_allocate = nullptr;
      } else {
        ark_ohos_native_buffer_adapter_allocate = _struct->allocate;
      }
    } else {
      ark_ohos_native_buffer_adapter_allocate =
          reinterpret_cast<ArkOhosNativeBufferAdapterAllocateFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_native_buffer_adapter_allocate,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_ohos_native_buffer_adapter_allocate(
      _struct, ArkNativeBufferConfigAdapterCppToC::Invert(bufferConfig),
      outBuffer);
}

ARK_WEB_NO_SANITIZE
void ArkOhosNativeBufferAdapterCToCpp::Describe(
    ArkWebRefPtr<ArkNativeBufferConfigAdapter> bufferConfig,
    void* buffer) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_native_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_native_buffer_adapter_describe);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "$8rsV18CbfFuPnLRxZNdKQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_NATIVE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_native_buffer_adapter_describe");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, describe)) {
        ark_ohos_native_buffer_adapter_describe = nullptr;
      } else {
        ark_ohos_native_buffer_adapter_describe = _struct->describe;
      }
    } else {
      ark_ohos_native_buffer_adapter_describe =
          reinterpret_cast<ArkOhosNativeBufferAdapterDescribeFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_native_buffer_adapter_describe,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_ohos_native_buffer_adapter_describe(
      _struct, ArkNativeBufferConfigAdapterCppToC::Invert(bufferConfig),
      buffer);
}

ARK_WEB_NO_SANITIZE
int ArkOhosNativeBufferAdapterCToCpp::Lock(void* buffer,
                                           uint64_t usage,
                                           int32_t fence,
                                           void** out_virtual_address) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_native_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_native_buffer_adapter_lock);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "cHxEkuRjEIECGHsQkz4NFQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_NATIVE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_native_buffer_adapter_lock");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, lock)) {
        ark_ohos_native_buffer_adapter_lock = nullptr;
      } else {
        ark_ohos_native_buffer_adapter_lock = _struct->lock;
      }
    } else {
      ark_ohos_native_buffer_adapter_lock =
          reinterpret_cast<ArkOhosNativeBufferAdapterLockFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_native_buffer_adapter_lock, 0);

  // Execute
  return ark_ohos_native_buffer_adapter_lock(_struct, buffer, usage, fence,
                                             out_virtual_address);
}

ARK_WEB_NO_SANITIZE
int ArkOhosNativeBufferAdapterCToCpp::RecvHandleFromUnixSocket(
    int socketFd,
    void** outBuffer) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_native_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_native_buffer_adapter_recv_handle_from_unix_socket);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "sxf6SOcBdiY3g_yIyJMT4w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_NATIVE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_native_buffer_adapter_recv_handle_from_unix_socket");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, recv_handle_from_unix_socket)) {
        ark_ohos_native_buffer_adapter_recv_handle_from_unix_socket = nullptr;
      } else {
        ark_ohos_native_buffer_adapter_recv_handle_from_unix_socket =
            _struct->recv_handle_from_unix_socket;
      }
    } else {
      ark_ohos_native_buffer_adapter_recv_handle_from_unix_socket =
          reinterpret_cast<
              ArkOhosNativeBufferAdapterRecvHandleFromUnixSocketFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_native_buffer_adapter_recv_handle_from_unix_socket, 0);

  // Execute
  return ark_ohos_native_buffer_adapter_recv_handle_from_unix_socket(
      _struct, socketFd, outBuffer);
}

ARK_WEB_NO_SANITIZE
int ArkOhosNativeBufferAdapterCToCpp::SendHandleToUnixSocket(const void* buffer,
                                                             int socketFd) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_native_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_native_buffer_adapter_send_handle_to_unix_socket);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "vQt6JEioiKDs1PmFARCVPQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_NATIVE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_native_buffer_adapter_send_handle_to_unix_socket");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, send_handle_to_unix_socket)) {
        ark_ohos_native_buffer_adapter_send_handle_to_unix_socket = nullptr;
      } else {
        ark_ohos_native_buffer_adapter_send_handle_to_unix_socket =
            _struct->send_handle_to_unix_socket;
      }
    } else {
      ark_ohos_native_buffer_adapter_send_handle_to_unix_socket =
          reinterpret_cast<
              ArkOhosNativeBufferAdapterSendHandleToUnixSocketFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_native_buffer_adapter_send_handle_to_unix_socket, 0);

  // Execute
  return ark_ohos_native_buffer_adapter_send_handle_to_unix_socket(
      _struct, buffer, socketFd);
}

ARK_WEB_NO_SANITIZE
int ArkOhosNativeBufferAdapterCToCpp::Unlock(void* buffer, int32_t* fence) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_native_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_native_buffer_adapter_unlock);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "tM3$g4S_4c_R1I2hnYfWuA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_NATIVE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_native_buffer_adapter_unlock");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, unlock)) {
        ark_ohos_native_buffer_adapter_unlock = nullptr;
      } else {
        ark_ohos_native_buffer_adapter_unlock = _struct->unlock;
      }
    } else {
      ark_ohos_native_buffer_adapter_unlock =
          reinterpret_cast<ArkOhosNativeBufferAdapterUnlockFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_native_buffer_adapter_unlock, 0);

  // Execute
  return ark_ohos_native_buffer_adapter_unlock(_struct, buffer, fence);
}

ARK_WEB_NO_SANITIZE
int ArkOhosNativeBufferAdapterCToCpp::FreeNativeBuffer(void* nativeBuffer) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_native_buffer_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_native_buffer_adapter_free_native_buffer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "UPMK$_8MPLipPFwmGbUzRQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_NATIVE_BUFFER_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_native_buffer_adapter_free_native_buffer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, free_native_buffer)) {
        ark_ohos_native_buffer_adapter_free_native_buffer = nullptr;
      } else {
        ark_ohos_native_buffer_adapter_free_native_buffer =
            _struct->free_native_buffer;
      }
    } else {
      ark_ohos_native_buffer_adapter_free_native_buffer =
          reinterpret_cast<ArkOhosNativeBufferAdapterFreeNativeBufferFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_native_buffer_adapter_free_native_buffer, 0);

  // Execute
  return ark_ohos_native_buffer_adapter_free_native_buffer(_struct,
                                                           nativeBuffer);
}

ArkOhosNativeBufferAdapterCToCpp::ArkOhosNativeBufferAdapterCToCpp() {}

ArkOhosNativeBufferAdapterCToCpp::~ArkOhosNativeBufferAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkOhosNativeBufferAdapterCToCpp,
                           ArkOhosNativeBufferAdapter,
                           ark_ohos_native_buffer_adapter_t>::kBridgeType =
        ARK_OHOS_NATIVE_BUFFER_ADAPTER;

}  // namespace OHOS::ArkWeb
