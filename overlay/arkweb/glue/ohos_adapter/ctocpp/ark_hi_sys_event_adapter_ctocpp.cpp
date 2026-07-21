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

#include "ohos_adapter/ctocpp/ark_hi_sys_event_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"

namespace OHOS::ArkWeb {

using ArkHiSysEventAdapterWriteFunc1 =
    int (*)(struct _ark_hi_sys_event_adapter_t* self,
            const ArkWebString* eventName,
            uint32_t type,
            const ArkWebString key0,
            const ArkWebString value0);
static ArkHiSysEventAdapterWriteFunc1 ark_hi_sys_event_adapter_write1 =
    reinterpret_cast<ArkHiSysEventAdapterWriteFunc1>(ARK_WEB_INIT_ADDR);

using ArkHiSysEventAdapterWriteFunc2 =
    int (*)(struct _ark_hi_sys_event_adapter_t* self,
            const ArkWebString* eventName,
            uint32_t type,
            const ArkWebString key1,
            const ArkWebString value1,
            const ArkWebString key2,
            const ArkWebString value2);
static ArkHiSysEventAdapterWriteFunc2 ark_hi_sys_event_adapter_write2 =
    reinterpret_cast<ArkHiSysEventAdapterWriteFunc2>(ARK_WEB_INIT_ADDR);

using ArkHiSysEventAdapterWriteFunc3 =
    int (*)(struct _ark_hi_sys_event_adapter_t* self,
            const ArkWebString* eventName,
            uint32_t type,
            const ArkWebString key1,
            const ArkWebString value1,
            const ArkWebString key2,
            const ArkWebString value2,
            const ArkWebString key3,
            const ArkWebString value3);
static ArkHiSysEventAdapterWriteFunc3 ark_hi_sys_event_adapter_write3 =
    reinterpret_cast<ArkHiSysEventAdapterWriteFunc3>(ARK_WEB_INIT_ADDR);

using ArkHiSysEventAdapterWriteFunc4 =
    int (*)(struct _ark_hi_sys_event_adapter_t* self,
            const ArkWebString* eventName,
            uint32_t type,
            const ArkWebString key1,
            const ArkWebString value1,
            const ArkWebString key2,
            const ArkWebString value2,
            const ArkWebString key3,
            const ArkWebString value3,
            const ArkWebString key4,
            const ArkWebString value4);
static ArkHiSysEventAdapterWriteFunc4 ark_hi_sys_event_adapter_write4 =
    reinterpret_cast<ArkHiSysEventAdapterWriteFunc4>(ARK_WEB_INIT_ADDR);

using ArkHiSysEventAdapterWriteFunc5 =
    int (*)(struct _ark_hi_sys_event_adapter_t* self,
            const ArkWebString* eventName,
            uint32_t type,
            const ArkWebString key1,
            const ArkWebString value1,
            const ArkWebString key2,
            const ArkWebString value2,
            const ArkWebString key3,
            const ArkWebString value3,
            const ArkWebString key4,
            const ArkWebString value4,
            const ArkWebString key5,
            const ArkWebString value5);
static ArkHiSysEventAdapterWriteFunc5 ark_hi_sys_event_adapter_write5 =
    reinterpret_cast<ArkHiSysEventAdapterWriteFunc5>(ARK_WEB_INIT_ADDR);

using ArkHiSysEventAdapterWriteFunc6 =
    int (*)(struct _ark_hi_sys_event_adapter_t* self,
            const ArkWebString* eventName,
            uint32_t type,
            const ArkWebString key1,
            const ArkWebString value1,
            const ArkWebString key2,
            const ArkWebString value2,
            const ArkWebString key3,
            const ArkWebString value3,
            const ArkWebString key4,
            const ArkWebString value4,
            const ArkWebString key5,
            const ArkWebString value5,
            const ArkWebString key6,
            const ArkWebString value6);
static ArkHiSysEventAdapterWriteFunc6 ark_hi_sys_event_adapter_write6 =
    reinterpret_cast<ArkHiSysEventAdapterWriteFunc6>(ARK_WEB_INIT_ADDR);

using ArkHiSysEventAdapterWriteFunc7 =
    int (*)(struct _ark_hi_sys_event_adapter_t* self,
            const ArkWebString* eventName,
            uint32_t type,
            const ArkWebString key1,
            const int64_t value1,
            const ArkWebString key2,
            const int value2,
            const ArkWebString key3,
            const ArkWebUint16Vector value3,
            const ArkWebString key4,
            const int value4);
static ArkHiSysEventAdapterWriteFunc7 ark_hi_sys_event_adapter_write7 =
    reinterpret_cast<ArkHiSysEventAdapterWriteFunc7>(ARK_WEB_INIT_ADDR);

using ArkHiSysEventAdapterWriteFunc8 =
    int (*)(struct _ark_hi_sys_event_adapter_t* self,
            const ArkWebString* eventName,
            uint32_t type,
            const ArkWebString key1,
            const int64_t value1,
            const ArkWebString key2,
            const int64_t value2,
            const ArkWebString key3,
            const int value3,
            const ArkWebString key4,
            const int value4,
            const ArkWebString key5,
            const int64_t value5,
            const ArkWebString key6,
            const int value6);
static ArkHiSysEventAdapterWriteFunc8 ark_hi_sys_event_adapter_write8 =
    reinterpret_cast<ArkHiSysEventAdapterWriteFunc8>(ARK_WEB_INIT_ADDR);

using ArkHiSysEventAdapterWriteFunc9 =
    int (*)(struct _ark_hi_sys_event_adapter_t* self,
            const ArkWebString* eventName,
            uint32_t type,
            const ArkWebString key1,
            const int64_t value1,
            const ArkWebString key2,
            const int64_t value2,
            const ArkWebString key3,
            const uint32_t value3,
            const ArkWebString key4,
            const int64_t value4,
            const ArkWebString key5,
            const int64_t value5,
            const ArkWebString key6,
            const int64_t value6,
            const ArkWebString key7,
            const int64_t value7,
            const ArkWebString key8,
            const int64_t value8,
            const ArkWebString key9,
            const int64_t value9,
            const ArkWebString key10,
            const int64_t value10,
            const ArkWebString key11,
            const int64_t value11,
            const ArkWebString key12,
            const int64_t value12,
            const ArkWebString key13,
            const int64_t value13,
            const ArkWebString key14,
            const int64_t value14,
            const ArkWebString key15,
            const int64_t value15,
            const ArkWebString key16,
            const int64_t value16,
            const ArkWebString key17,
            const int64_t value17,
            const ArkWebString key18,
            const int64_t value18,
            const ArkWebString key19,
            const int64_t value19,
            const ArkWebString key20,
            const int64_t value20,
            const ArkWebString key21,
            const int64_t value21,
            const ArkWebString key22,
            const int64_t value22,
            const ArkWebString key23,
            const int64_t value23);
static ArkHiSysEventAdapterWriteFunc9 ark_hi_sys_event_adapter_write9 =
    reinterpret_cast<ArkHiSysEventAdapterWriteFunc9>(ARK_WEB_INIT_ADDR);

using ArkHiSysEventAdapterWriteFunc10 =
    int (*)(struct _ark_hi_sys_event_adapter_t* self,
            const ArkWebString* eventName,
            uint32_t type,
            const ArkWebString key1,
            const ArkWebString value1,
            const ArkWebString key2,
            const ArkWebString value2,
            const ArkWebString key3,
            const ArkWebString value3,
            const ArkWebString key4,
            const ArkWebString value4,
            const ArkWebString key5,
            const ArkWebString value5,
            const ArkWebString key6,
            const ArkWebString value6,
            const ArkWebString key7,
            const ArkWebString value7);
static ArkHiSysEventAdapterWriteFunc10 ark_hi_sys_event_adapter_write10 =
    reinterpret_cast<ArkHiSysEventAdapterWriteFunc10>(ARK_WEB_INIT_ADDR);

using ArkHiSysEventAdapterWriteFunc11 =
    int (*)(struct _ark_hi_sys_event_adapter_t* self,
            const ArkWebString* eventName,
            uint32_t type,
            const ArkWebString key1,
            const ArkWebString value1,
            const ArkWebString key2,
            const ArkWebString value2,
            const ArkWebString key3,
            const ArkWebString value3,
            const ArkWebString key4,
            const ArkWebString value4,
            const ArkWebString key5,
            const ArkWebString value5,
            const ArkWebString key6,
            const ArkWebString value6,
            const ArkWebString key7,
            const ArkWebString value7,
            const ArkWebString key8,
            const ArkWebString value8);
static ArkHiSysEventAdapterWriteFunc11 ark_hi_sys_event_adapter_write11 =
    reinterpret_cast<ArkHiSysEventAdapterWriteFunc11>(ARK_WEB_INIT_ADDR);

using ArkHiSysEventAdapterWriteFunc12 =
    int (*)(struct _ark_hi_sys_event_adapter_t* self,
            const ArkWebString* eventName,
            uint32_t type,
            const ArkWebString key1,
            const uint32_t value1,
            const ArkWebString key2,
            const uint64_t value2);
static ArkHiSysEventAdapterWriteFunc12 ark_hi_sys_event_adapter_write12 =
    reinterpret_cast<ArkHiSysEventAdapterWriteFunc12>(ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
int ArkHiSysEventAdapterCToCpp::Write(const ArkWebString& eventName,
                                      uint32_t type,
                                      const ArkWebString key0,
                                      const ArkWebString value0) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_sys_event_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_hi_sys_event_adapter_write1);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "jNqGuiz9oO8UBy5N3Cyl1Q";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_SYS_EVENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_sys_event_adapter_write1");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, write1)) {
        ark_hi_sys_event_adapter_write1 = nullptr;
      } else {
        ark_hi_sys_event_adapter_write1 = _struct->write1;
      }
    } else {
      ark_hi_sys_event_adapter_write1 =
          reinterpret_cast<ArkHiSysEventAdapterWriteFunc1>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_sys_event_adapter_write1, 0);

  // Execute
  return ark_hi_sys_event_adapter_write1(_struct, &eventName, type, key0,
                                         value0);
}

ARK_WEB_NO_SANITIZE
int ArkHiSysEventAdapterCToCpp::Write(const ArkWebString& eventName,
                                      uint32_t type,
                                      const ArkWebString key1,
                                      const ArkWebString value1,
                                      const ArkWebString key2,
                                      const ArkWebString value2) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_sys_event_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_hi_sys_event_adapter_write2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "SLQFgEGaOm0hmykjyUdctQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_SYS_EVENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_sys_event_adapter_write2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, write2)) {
        ark_hi_sys_event_adapter_write2 = nullptr;
      } else {
        ark_hi_sys_event_adapter_write2 = _struct->write2;
      }
    } else {
      ark_hi_sys_event_adapter_write2 =
          reinterpret_cast<ArkHiSysEventAdapterWriteFunc2>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_sys_event_adapter_write2, 0);

  // Execute
  return ark_hi_sys_event_adapter_write2(_struct, &eventName, type, key1,
                                         value1, key2, value2);
}

ARK_WEB_NO_SANITIZE
int ArkHiSysEventAdapterCToCpp::Write(const ArkWebString& eventName,
                                      uint32_t type,
                                      const ArkWebString key1,
                                      const ArkWebString value1,
                                      const ArkWebString key2,
                                      const ArkWebString value2,
                                      const ArkWebString key3,
                                      const ArkWebString value3) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_sys_event_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_hi_sys_event_adapter_write3);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "SiPWRm2QsZ$By8q$p84TwA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_SYS_EVENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_sys_event_adapter_write3");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, write3)) {
        ark_hi_sys_event_adapter_write3 = nullptr;
      } else {
        ark_hi_sys_event_adapter_write3 = _struct->write3;
      }
    } else {
      ark_hi_sys_event_adapter_write3 =
          reinterpret_cast<ArkHiSysEventAdapterWriteFunc3>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_sys_event_adapter_write3, 0);

  // Execute
  return ark_hi_sys_event_adapter_write3(_struct, &eventName, type, key1,
                                         value1, key2, value2, key3, value3);
}

ARK_WEB_NO_SANITIZE
int ArkHiSysEventAdapterCToCpp::Write(const ArkWebString& eventName,
                                      uint32_t type,
                                      const ArkWebString key1,
                                      const ArkWebString value1,
                                      const ArkWebString key2,
                                      const ArkWebString value2,
                                      const ArkWebString key3,
                                      const ArkWebString value3,
                                      const ArkWebString key4,
                                      const ArkWebString value4) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_sys_event_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_hi_sys_event_adapter_write4);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "bIfYvlLFvGqkOVtEV5s5BQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_SYS_EVENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_sys_event_adapter_write4");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, write4)) {
        ark_hi_sys_event_adapter_write4 = nullptr;
      } else {
        ark_hi_sys_event_adapter_write4 = _struct->write4;
      }
    } else {
      ark_hi_sys_event_adapter_write4 =
          reinterpret_cast<ArkHiSysEventAdapterWriteFunc4>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_sys_event_adapter_write4, 0);

  // Execute
  return ark_hi_sys_event_adapter_write4(_struct, &eventName, type, key1,
                                         value1, key2, value2, key3, value3,
                                         key4, value4);
}

ARK_WEB_NO_SANITIZE
int ArkHiSysEventAdapterCToCpp::Write(const ArkWebString& eventName,
                                      uint32_t type,
                                      const ArkWebString key1,
                                      const ArkWebString value1,
                                      const ArkWebString key2,
                                      const ArkWebString value2,
                                      const ArkWebString key3,
                                      const ArkWebString value3,
                                      const ArkWebString key4,
                                      const ArkWebString value4,
                                      const ArkWebString key5,
                                      const ArkWebString value5) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_sys_event_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_hi_sys_event_adapter_write5);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "NgDGRbDCsEPi64f1SvdHdw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_SYS_EVENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_sys_event_adapter_write5");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, write5)) {
        ark_hi_sys_event_adapter_write5 = nullptr;
      } else {
        ark_hi_sys_event_adapter_write5 = _struct->write5;
      }
    } else {
      ark_hi_sys_event_adapter_write5 =
          reinterpret_cast<ArkHiSysEventAdapterWriteFunc5>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_sys_event_adapter_write5, 0);

  // Execute
  return ark_hi_sys_event_adapter_write5(_struct, &eventName, type, key1,
                                         value1, key2, value2, key3, value3,
                                         key4, value4, key5, value5);
}

ARK_WEB_NO_SANITIZE
int ArkHiSysEventAdapterCToCpp::Write(const ArkWebString& eventName,
                                      uint32_t type,
                                      const ArkWebString key1,
                                      const ArkWebString value1,
                                      const ArkWebString key2,
                                      const ArkWebString value2,
                                      const ArkWebString key3,
                                      const ArkWebString value3,
                                      const ArkWebString key4,
                                      const ArkWebString value4,
                                      const ArkWebString key5,
                                      const ArkWebString value5,
                                      const ArkWebString key6,
                                      const ArkWebString value6) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_sys_event_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_hi_sys_event_adapter_write6);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "eOKXX7eFqWZJeY3nMh8uqw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_SYS_EVENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_sys_event_adapter_write6");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, write6)) {
        ark_hi_sys_event_adapter_write6 = nullptr;
      } else {
        ark_hi_sys_event_adapter_write6 = _struct->write6;
      }
    } else {
      ark_hi_sys_event_adapter_write6 =
          reinterpret_cast<ArkHiSysEventAdapterWriteFunc6>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_sys_event_adapter_write6, 0);

  // Execute
  return ark_hi_sys_event_adapter_write6(
      _struct, &eventName, type, key1, value1, key2, value2, key3, value3, key4,
      value4, key5, value5, key6, value6);
}

ARK_WEB_NO_SANITIZE
int ArkHiSysEventAdapterCToCpp::Write(const ArkWebString& eventName,
                                      uint32_t type,
                                      const ArkWebString key1,
                                      const int64_t value1,
                                      const ArkWebString key2,
                                      const int value2,
                                      const ArkWebString key3,
                                      const ArkWebUint16Vector value3,
                                      const ArkWebString key4,
                                      const int value4) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_sys_event_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_hi_sys_event_adapter_write7);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "3BWO4VxoJ58v9pOHftt9WA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_SYS_EVENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_sys_event_adapter_write7");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, write7)) {
        ark_hi_sys_event_adapter_write7 = nullptr;
      } else {
        ark_hi_sys_event_adapter_write7 = _struct->write7;
      }
    } else {
      ark_hi_sys_event_adapter_write7 =
          reinterpret_cast<ArkHiSysEventAdapterWriteFunc7>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_sys_event_adapter_write7, 0);

  // Execute
  return ark_hi_sys_event_adapter_write7(_struct, &eventName, type, key1,
                                         value1, key2, value2, key3, value3,
                                         key4, value4);
}

ARK_WEB_NO_SANITIZE
int ArkHiSysEventAdapterCToCpp::Write(const ArkWebString& eventName,
                                      uint32_t type,
                                      const ArkWebString key1,
                                      const int64_t value1,
                                      const ArkWebString key2,
                                      const int64_t value2,
                                      const ArkWebString key3,
                                      const int value3,
                                      const ArkWebString key4,
                                      const int value4,
                                      const ArkWebString key5,
                                      const int64_t value5,
                                      const ArkWebString key6,
                                      const int value6) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_sys_event_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_hi_sys_event_adapter_write8);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "7_Mfnog63uVbS_E2aYG$YQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_SYS_EVENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_sys_event_adapter_write8");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, write8)) {
        ark_hi_sys_event_adapter_write8 = nullptr;
      } else {
        ark_hi_sys_event_adapter_write8 = _struct->write8;
      }
    } else {
      ark_hi_sys_event_adapter_write8 =
          reinterpret_cast<ArkHiSysEventAdapterWriteFunc8>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_sys_event_adapter_write8, 0);

  // Execute
  return ark_hi_sys_event_adapter_write8(
      _struct, &eventName, type, key1, value1, key2, value2, key3, value3, key4,
      value4, key5, value5, key6, value6);
}

ARK_WEB_NO_SANITIZE
int ArkHiSysEventAdapterCToCpp::Write(const ArkWebString& eventName,
                                      uint32_t type,
                                      const ArkWebString key1,
                                      const int64_t value1,
                                      const ArkWebString key2,
                                      const int64_t value2,
                                      const ArkWebString key3,
                                      const uint32_t value3,
                                      const ArkWebString key4,
                                      const int64_t value4,
                                      const ArkWebString key5,
                                      const int64_t value5,
                                      const ArkWebString key6,
                                      const int64_t value6,
                                      const ArkWebString key7,
                                      const int64_t value7,
                                      const ArkWebString key8,
                                      const int64_t value8,
                                      const ArkWebString key9,
                                      const int64_t value9,
                                      const ArkWebString key10,
                                      const int64_t value10,
                                      const ArkWebString key11,
                                      const int64_t value11,
                                      const ArkWebString key12,
                                      const int64_t value12,
                                      const ArkWebString key13,
                                      const int64_t value13,
                                      const ArkWebString key14,
                                      const int64_t value14,
                                      const ArkWebString key15,
                                      const int64_t value15,
                                      const ArkWebString key16,
                                      const int64_t value16,
                                      const ArkWebString key17,
                                      const int64_t value17,
                                      const ArkWebString key18,
                                      const int64_t value18,
                                      const ArkWebString key19,
                                      const int64_t value19,
                                      const ArkWebString key20,
                                      const int64_t value20,
                                      const ArkWebString key21,
                                      const int64_t value21,
                                      const ArkWebString key22,
                                      const int64_t value22,
                                      const ArkWebString key23,
                                      const int64_t value23) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_sys_event_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(ark_hi_sys_event_adapter_write9);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "HqVOyc9jmWLd2ZgTCF06IQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_SYS_EVENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_sys_event_adapter_write9");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, write9)) {
        ark_hi_sys_event_adapter_write9 = nullptr;
      } else {
        ark_hi_sys_event_adapter_write9 = _struct->write9;
      }
    } else {
      ark_hi_sys_event_adapter_write9 =
          reinterpret_cast<ArkHiSysEventAdapterWriteFunc9>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_sys_event_adapter_write9, 0);

  // Execute
  return ark_hi_sys_event_adapter_write9(
      _struct, &eventName, type, key1, value1, key2, value2, key3, value3, key4,
      value4, key5, value5, key6, value6, key7, value7, key8, value8, key9,
      value9, key10, value10, key11, value11, key12, value12, key13, value13,
      key14, value14, key15, value15, key16, value16, key17, value17, key18,
      value18, key19, value19, key20, value20, key21, value21, key22, value22,
      key23, value23);
}

ARK_WEB_NO_SANITIZE
int ArkHiSysEventAdapterCToCpp::Write(const ArkWebString& eventName,
                                      uint32_t type,
                                      const ArkWebString key1,
                                      const ArkWebString value1,
                                      const ArkWebString key2,
                                      const ArkWebString value2,
                                      const ArkWebString key3,
                                      const ArkWebString value3,
                                      const ArkWebString key4,
                                      const ArkWebString value4,
                                      const ArkWebString key5,
                                      const ArkWebString value5,
                                      const ArkWebString key6,
                                      const ArkWebString value6,
                                      const ArkWebString key7,
                                      const ArkWebString value7) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_sys_event_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_hi_sys_event_adapter_write10);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "MG2iP26l1xxm1_CduITx3A";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_SYS_EVENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_sys_event_adapter_write10");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, write10)) {
        ark_hi_sys_event_adapter_write10 = nullptr;
      } else {
        ark_hi_sys_event_adapter_write10 = _struct->write10;
      }
    } else {
      ark_hi_sys_event_adapter_write10 =
          reinterpret_cast<ArkHiSysEventAdapterWriteFunc10>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_sys_event_adapter_write10, 0);

  // Execute
  return ark_hi_sys_event_adapter_write10(
      _struct, &eventName, type, key1, value1, key2, value2, key3, value3, key4,
      value4, key5, value5, key6, value6, key7, value7);
}

ARK_WEB_NO_SANITIZE
int ArkHiSysEventAdapterCToCpp::Write(const ArkWebString& eventName,
                                      uint32_t type,
                                      const ArkWebString key1,
                                      const ArkWebString value1,
                                      const ArkWebString key2,
                                      const ArkWebString value2,
                                      const ArkWebString key3,
                                      const ArkWebString value3,
                                      const ArkWebString key4,
                                      const ArkWebString value4,
                                      const ArkWebString key5,
                                      const ArkWebString value5,
                                      const ArkWebString key6,
                                      const ArkWebString value6,
                                      const ArkWebString key7,
                                      const ArkWebString value7,
                                      const ArkWebString key8,
                                      const ArkWebString value8) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_sys_event_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_hi_sys_event_adapter_write11);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "0dOAtenERtmzZLtPnWHyHg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_SYS_EVENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_sys_event_adapter_write11");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, write11)) {
        ark_hi_sys_event_adapter_write11 = nullptr;
      } else {
        ark_hi_sys_event_adapter_write11 = _struct->write11;
      }
    } else {
      ark_hi_sys_event_adapter_write11 =
          reinterpret_cast<ArkHiSysEventAdapterWriteFunc11>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_sys_event_adapter_write11, 0);

  // Execute
  return ark_hi_sys_event_adapter_write11(
      _struct, &eventName, type, key1, value1, key2, value2, key3, value3, key4,
      value4, key5, value5, key6, value6, key7, value7, key8, value8);
}

ARK_WEB_NO_SANITIZE
int ArkHiSysEventAdapterCToCpp::Write(const ArkWebString& eventName,
                                      uint32_t type,
                                      const ArkWebString key1,
                                      const uint32_t value1,
                                      const ArkWebString key2,
                                      const uint64_t value2) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_hi_sys_event_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_hi_sys_event_adapter_write12);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "XcKsDaTYXnVxtMoBIcjBXA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_HI_SYS_EVENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_hi_sys_event_adapter_write12");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, write12)) {
        ark_hi_sys_event_adapter_write12 = nullptr;
      } else {
        ark_hi_sys_event_adapter_write12 = _struct->write12;
      }
    } else {
      ark_hi_sys_event_adapter_write12 =
          reinterpret_cast<ArkHiSysEventAdapterWriteFunc12>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_hi_sys_event_adapter_write12, 0);

  // Execute
  return ark_hi_sys_event_adapter_write12(_struct, &eventName, type, key1,
                                          value1, key2, value2);
}

ArkHiSysEventAdapterCToCpp::ArkHiSysEventAdapterCToCpp() {}

ArkHiSysEventAdapterCToCpp::~ArkHiSysEventAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkHiSysEventAdapterCToCpp,
                           ArkHiSysEventAdapter,
                           ark_hi_sys_event_adapter_t>::kBridgeType =
        ARK_HI_SYS_EVENT_ADAPTER;

}  // namespace OHOS::ArkWeb
