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

#include "ohos_adapter/ctocpp/ark_paste_board_client_adapter_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/cpptoc/ark_paste_board_observer_adapter_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkPasteBoardClientAdapterGetPasteDataFunc =
    bool (*)(struct _ark_paste_board_client_adapter_t* self,
             ArkPasteRecordVector* data);
static ArkPasteBoardClientAdapterGetPasteDataFunc
    ark_paste_board_client_adapter_get_paste_data =
        reinterpret_cast<ArkPasteBoardClientAdapterGetPasteDataFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteBoardClientAdapterSetPasteDataFunc =
    void (*)(struct _ark_paste_board_client_adapter_t* self,
             ArkPasteRecordVector* data,
             int32_t copyOption);
static ArkPasteBoardClientAdapterSetPasteDataFunc
    ark_paste_board_client_adapter_set_paste_data =
        reinterpret_cast<ArkPasteBoardClientAdapterSetPasteDataFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteBoardClientAdapterHasPasteDataFunc =
    bool (*)(struct _ark_paste_board_client_adapter_t* self);
static ArkPasteBoardClientAdapterHasPasteDataFunc
    ark_paste_board_client_adapter_has_paste_data =
        reinterpret_cast<ArkPasteBoardClientAdapterHasPasteDataFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteBoardClientAdapterClearFunc =
    void (*)(struct _ark_paste_board_client_adapter_t* self);
static ArkPasteBoardClientAdapterClearFunc
    ark_paste_board_client_adapter_clear =
        reinterpret_cast<ArkPasteBoardClientAdapterClearFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteBoardClientAdapterOpenRemoteUriFunc =
    int32_t (*)(struct _ark_paste_board_client_adapter_t* self,
                const ArkWebString* path);
static ArkPasteBoardClientAdapterOpenRemoteUriFunc
    ark_paste_board_client_adapter_open_remote_uri =
        reinterpret_cast<ArkPasteBoardClientAdapterOpenRemoteUriFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteBoardClientAdapterIsLocalPasteFunc =
    bool (*)(struct _ark_paste_board_client_adapter_t* self);
static ArkPasteBoardClientAdapterIsLocalPasteFunc
    ark_paste_board_client_adapter_is_local_paste =
        reinterpret_cast<ArkPasteBoardClientAdapterIsLocalPasteFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteBoardClientAdapterGetTokenIdFunc =
    uint32_t (*)(struct _ark_paste_board_client_adapter_t* self);
static ArkPasteBoardClientAdapterGetTokenIdFunc
    ark_paste_board_client_adapter_get_token_id =
        reinterpret_cast<ArkPasteBoardClientAdapterGetTokenIdFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteBoardClientAdapterAddPasteboardChangedObserverFunc =
    int32_t (*)(struct _ark_paste_board_client_adapter_t* self,
                ark_paste_board_observer_adapter_t* callback);
static ArkPasteBoardClientAdapterAddPasteboardChangedObserverFunc
    ark_paste_board_client_adapter_add_pasteboard_changed_observer =
        reinterpret_cast<
            ArkPasteBoardClientAdapterAddPasteboardChangedObserverFunc>(
            ARK_WEB_INIT_ADDR);

using ArkPasteBoardClientAdapterRemovePasteboardChangedObserverFunc =
    void (*)(struct _ark_paste_board_client_adapter_t* self,
             int32_t callbackId);
static ArkPasteBoardClientAdapterRemovePasteboardChangedObserverFunc
    ark_paste_board_client_adapter_remove_pasteboard_changed_observer =
        reinterpret_cast<
            ArkPasteBoardClientAdapterRemovePasteboardChangedObserverFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
bool ArkPasteBoardClientAdapterCToCpp::GetPasteData(
    ArkPasteRecordVector& data) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_board_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_board_client_adapter_get_paste_data);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Z3I2l$YTkg72Gf2uyK16Lg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_BOARD_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_board_client_adapter_get_paste_data");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_paste_data)) {
        ark_paste_board_client_adapter_get_paste_data = nullptr;
      } else {
        ark_paste_board_client_adapter_get_paste_data = _struct->get_paste_data;
      }
    } else {
      ark_paste_board_client_adapter_get_paste_data =
          reinterpret_cast<ArkPasteBoardClientAdapterGetPasteDataFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_board_client_adapter_get_paste_data, false);

  // Execute
  return ark_paste_board_client_adapter_get_paste_data(_struct, &data);
}

ARK_WEB_NO_SANITIZE
void ArkPasteBoardClientAdapterCToCpp::SetPasteData(ArkPasteRecordVector& data,
                                                    int32_t copyOption) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_board_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_board_client_adapter_set_paste_data);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "41BDM6eDpFF8MSi4tSqi4g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_BOARD_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_board_client_adapter_set_paste_data");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, set_paste_data)) {
        ark_paste_board_client_adapter_set_paste_data = nullptr;
      } else {
        ark_paste_board_client_adapter_set_paste_data = _struct->set_paste_data;
      }
    } else {
      ark_paste_board_client_adapter_set_paste_data =
          reinterpret_cast<ArkPasteBoardClientAdapterSetPasteDataFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_board_client_adapter_set_paste_data, ARK_WEB_RETURN_VOID);

  // Execute
  ark_paste_board_client_adapter_set_paste_data(_struct, &data, copyOption);
}

ARK_WEB_NO_SANITIZE
bool ArkPasteBoardClientAdapterCToCpp::HasPasteData() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_board_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_board_client_adapter_has_paste_data);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "9ZlPJKWUZolZgj8Yys2Kjw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_BOARD_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_board_client_adapter_has_paste_data");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, has_paste_data)) {
        ark_paste_board_client_adapter_has_paste_data = nullptr;
      } else {
        ark_paste_board_client_adapter_has_paste_data = _struct->has_paste_data;
      }
    } else {
      ark_paste_board_client_adapter_has_paste_data =
          reinterpret_cast<ArkPasteBoardClientAdapterHasPasteDataFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_board_client_adapter_has_paste_data, false);

  // Execute
  return ark_paste_board_client_adapter_has_paste_data(_struct);
}

ARK_WEB_NO_SANITIZE
void ArkPasteBoardClientAdapterCToCpp::Clear() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_board_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_board_client_adapter_clear);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "pgFsQWTXXTvEbkn6lY4ulw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_BOARD_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_paste_board_client_adapter_clear");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, clear)) {
        ark_paste_board_client_adapter_clear = nullptr;
      } else {
        ark_paste_board_client_adapter_clear = _struct->clear;
      }
    } else {
      ark_paste_board_client_adapter_clear =
          reinterpret_cast<ArkPasteBoardClientAdapterClearFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_board_client_adapter_clear,
                                    ARK_WEB_RETURN_VOID);

  // Execute
  ark_paste_board_client_adapter_clear(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkPasteBoardClientAdapterCToCpp::OpenRemoteUri(
    const ArkWebString& path) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_board_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_board_client_adapter_open_remote_uri);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "pmoco8I39Yqua3v6ODDhLA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_BOARD_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_board_client_adapter_open_remote_uri");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, open_remote_uri)) {
        ark_paste_board_client_adapter_open_remote_uri = nullptr;
      } else {
        ark_paste_board_client_adapter_open_remote_uri =
            _struct->open_remote_uri;
      }
    } else {
      ark_paste_board_client_adapter_open_remote_uri =
          reinterpret_cast<ArkPasteBoardClientAdapterOpenRemoteUriFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_board_client_adapter_open_remote_uri, 0);

  // Execute
  return ark_paste_board_client_adapter_open_remote_uri(_struct, &path);
}

ARK_WEB_NO_SANITIZE
bool ArkPasteBoardClientAdapterCToCpp::IsLocalPaste() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_board_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_board_client_adapter_is_local_paste);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "4rFiL1liwDGqcO6k2JnVUA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_BOARD_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_board_client_adapter_is_local_paste");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, is_local_paste)) {
        ark_paste_board_client_adapter_is_local_paste = nullptr;
      } else {
        ark_paste_board_client_adapter_is_local_paste = _struct->is_local_paste;
      }
    } else {
      ark_paste_board_client_adapter_is_local_paste =
          reinterpret_cast<ArkPasteBoardClientAdapterIsLocalPasteFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_board_client_adapter_is_local_paste, false);

  // Execute
  return ark_paste_board_client_adapter_is_local_paste(_struct);
}

ARK_WEB_NO_SANITIZE
uint32_t ArkPasteBoardClientAdapterCToCpp::GetTokenId() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_board_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer =
      reinterpret_cast<void*>(ark_paste_board_client_adapter_get_token_id);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "G3osdyF1gBJx4z8muRVa6w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_BOARD_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_board_client_adapter_get_token_id");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_token_id)) {
        ark_paste_board_client_adapter_get_token_id = nullptr;
      } else {
        ark_paste_board_client_adapter_get_token_id = _struct->get_token_id;
      }
    } else {
      ark_paste_board_client_adapter_get_token_id =
          reinterpret_cast<ArkPasteBoardClientAdapterGetTokenIdFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_paste_board_client_adapter_get_token_id,
                                    0);

  // Execute
  return ark_paste_board_client_adapter_get_token_id(_struct);
}

ARK_WEB_NO_SANITIZE
int32_t ArkPasteBoardClientAdapterCToCpp::AddPasteboardChangedObserver(
    ArkWebRefPtr<ArkPasteBoardObserverAdapter> callback) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_board_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, 0);

  void* func_pointer = reinterpret_cast<void*>(
      ark_paste_board_client_adapter_add_pasteboard_changed_observer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "P4gJ1j_7svWSfmbbr96xSA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_BOARD_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_board_client_adapter_add_pasteboard_changed_observer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      add_pasteboard_changed_observer)) {
        ark_paste_board_client_adapter_add_pasteboard_changed_observer =
            nullptr;
      } else {
        ark_paste_board_client_adapter_add_pasteboard_changed_observer =
            _struct->add_pasteboard_changed_observer;
      }
    } else {
      ark_paste_board_client_adapter_add_pasteboard_changed_observer =
          reinterpret_cast<
              ArkPasteBoardClientAdapterAddPasteboardChangedObserverFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_board_client_adapter_add_pasteboard_changed_observer, 0);

  // Execute
  return ark_paste_board_client_adapter_add_pasteboard_changed_observer(
      _struct, ArkPasteBoardObserverAdapterCppToC::Invert(callback));
}

ARK_WEB_NO_SANITIZE
void ArkPasteBoardClientAdapterCToCpp::RemovePasteboardChangedObserver(
    int32_t callbackId) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_paste_board_client_adapter_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_paste_board_client_adapter_remove_pasteboard_changed_observer);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "F2bx9Nmtaico_qaa09Icdw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_PASTE_BOARD_CLIENT_ADAPTER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_paste_board_client_adapter_remove_pasteboard_changed_observer");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      remove_pasteboard_changed_observer)) {
        ark_paste_board_client_adapter_remove_pasteboard_changed_observer =
            nullptr;
      } else {
        ark_paste_board_client_adapter_remove_pasteboard_changed_observer =
            _struct->remove_pasteboard_changed_observer;
      }
    } else {
      ark_paste_board_client_adapter_remove_pasteboard_changed_observer =
          reinterpret_cast<
              ArkPasteBoardClientAdapterRemovePasteboardChangedObserverFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_paste_board_client_adapter_remove_pasteboard_changed_observer,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_paste_board_client_adapter_remove_pasteboard_changed_observer(_struct,
                                                                    callbackId);
}

ArkPasteBoardClientAdapterCToCpp::ArkPasteBoardClientAdapterCToCpp() {}

ArkPasteBoardClientAdapterCToCpp::~ArkPasteBoardClientAdapterCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkPasteBoardClientAdapterCToCpp,
                           ArkPasteBoardClientAdapter,
                           ark_paste_board_client_adapter_t>::kBridgeType =
        ARK_PASTE_BOARD_CLIENT_ADAPTER;

}  // namespace OHOS::ArkWeb
