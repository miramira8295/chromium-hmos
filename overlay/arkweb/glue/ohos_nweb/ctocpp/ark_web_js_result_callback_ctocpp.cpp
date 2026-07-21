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

#include "ohos_nweb/ctocpp/ark_web_js_result_callback_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_nweb/bridge/ark_web_nweb_webcore_bridge_helper.h"
#include "ohos_nweb/cpptoc/ark_web_hap_value_cpptoc.h"

namespace OHOS::ArkWeb {

using ArkWebJsResultCallbackGetJavaScriptResultFunc =
    ArkWebValue (*)(struct _ark_web_js_result_callback_t* self,
                    ArkWebValueVector args,
                    const ArkWebString* method,
                    const ArkWebString* object_name,
                    int32_t routing_id,
                    int32_t object_id);
static ArkWebJsResultCallbackGetJavaScriptResultFunc
    ark_web_js_result_callback_get_java_script_result =
        reinterpret_cast<ArkWebJsResultCallbackGetJavaScriptResultFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebJsResultCallbackHasJavaScriptObjectMethodsFunc =
    bool (*)(struct _ark_web_js_result_callback_t* self,
             int32_t object_id,
             const ArkWebString* method_name);
static ArkWebJsResultCallbackHasJavaScriptObjectMethodsFunc
    ark_web_js_result_callback_has_java_script_object_methods =
        reinterpret_cast<ArkWebJsResultCallbackHasJavaScriptObjectMethodsFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebJsResultCallbackGetJavaScriptObjectMethodsFunc =
    ArkWebValue (*)(struct _ark_web_js_result_callback_t* self,
                    int32_t object_id);
static ArkWebJsResultCallbackGetJavaScriptObjectMethodsFunc
    ark_web_js_result_callback_get_java_script_object_methods =
        reinterpret_cast<ArkWebJsResultCallbackGetJavaScriptObjectMethodsFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebJsResultCallbackRemoveJavaScriptObjectHolderFunc =
    void (*)(struct _ark_web_js_result_callback_t* self,
             int32_t holder,
             int32_t object_id);
static ArkWebJsResultCallbackRemoveJavaScriptObjectHolderFunc
    ark_web_js_result_callback_remove_java_script_object_holder =
        reinterpret_cast<
            ArkWebJsResultCallbackRemoveJavaScriptObjectHolderFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebJsResultCallbackRemoveTransientJavaScriptObjectFunc =
    void (*)(struct _ark_web_js_result_callback_t* self);
static ArkWebJsResultCallbackRemoveTransientJavaScriptObjectFunc
    ark_web_js_result_callback_remove_transient_java_script_object =
        reinterpret_cast<
            ArkWebJsResultCallbackRemoveTransientJavaScriptObjectFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebJsResultCallbackGetJavaScriptResultFlowbufFunc =
    ArkWebValue (*)(struct _ark_web_js_result_callback_t* self,
                    ArkWebValueVector args,
                    const ArkWebString* method,
                    const ArkWebString* object_name,
                    int fd,
                    int32_t routing_id,
                    int32_t object_id);
static ArkWebJsResultCallbackGetJavaScriptResultFlowbufFunc
    ark_web_js_result_callback_get_java_script_result_flowbuf =
        reinterpret_cast<ArkWebJsResultCallbackGetJavaScriptResultFlowbufFunc>(
            ARK_WEB_INIT_ADDR);

using ArkWebJsResultCallbackGetJavaScriptResultV2Func =
    void (*)(struct _ark_web_js_result_callback_t* self,
             const ArkWebHapValueVector* args,
             const ArkWebString* method,
             const ArkWebString* object_name,
             int32_t routing_id,
             int32_t object_id,
             ark_web_hap_value_t* result);
static ArkWebJsResultCallbackGetJavaScriptResultV2Func
    ark_web_js_result_callback_get_java_script_result_v2 =
        reinterpret_cast<ArkWebJsResultCallbackGetJavaScriptResultV2Func>(
            ARK_WEB_INIT_ADDR);

using ArkWebJsResultCallbackGetJavaScriptResultFlowbufV2Func =
    void (*)(struct _ark_web_js_result_callback_t* self,
             const ArkWebHapValueVector* args,
             const ArkWebString* method,
             const ArkWebString* object_name,
             int fd,
             int32_t routing_id,
             int32_t object_id,
             ark_web_hap_value_t* result);
static ArkWebJsResultCallbackGetJavaScriptResultFlowbufV2Func
    ark_web_js_result_callback_get_java_script_result_flowbuf_v2 =
        reinterpret_cast<
            ArkWebJsResultCallbackGetJavaScriptResultFlowbufV2Func>(
            ARK_WEB_INIT_ADDR);

using ArkWebJsResultCallbackGetJavaScriptObjectMethodsV2Func =
    void (*)(struct _ark_web_js_result_callback_t* self,
             int32_t object_id,
             ark_web_hap_value_t* result);
static ArkWebJsResultCallbackGetJavaScriptObjectMethodsV2Func
    ark_web_js_result_callback_get_java_script_object_methods_v2 =
        reinterpret_cast<
            ArkWebJsResultCallbackGetJavaScriptObjectMethodsV2Func>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
ArkWebValue ArkWebJsResultCallbackCToCpp::GetJavaScriptResult(
    ArkWebValueVector args,
    const ArkWebString& method,
    const ArkWebString& object_name,
    int32_t routing_id,
    int32_t object_id) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_js_result_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_value_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_js_result_callback_get_java_script_result);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "aMoUlesdpCd7BfBLBb9tQg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_JS_RESULT_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_js_result_callback_get_java_script_result");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_java_script_result)) {
        ark_web_js_result_callback_get_java_script_result = nullptr;
      } else {
        ark_web_js_result_callback_get_java_script_result =
            _struct->get_java_script_result;
      }
    } else {
      ark_web_js_result_callback_get_java_script_result =
          reinterpret_cast<ArkWebJsResultCallbackGetJavaScriptResultFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_js_result_callback_get_java_script_result, ark_web_value_default);

  // Execute
  return ark_web_js_result_callback_get_java_script_result(
      _struct, args, &method, &object_name, routing_id, object_id);
}

ARK_WEB_NO_SANITIZE
bool ArkWebJsResultCallbackCToCpp::HasJavaScriptObjectMethods(
    int32_t object_id,
    const ArkWebString& method_name) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_js_result_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, false);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_js_result_callback_has_java_script_object_methods);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "m1OtCBz447UWQ73XYSzlzA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_JS_RESULT_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_js_result_callback_has_java_script_object_methods");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      has_java_script_object_methods)) {
        ark_web_js_result_callback_has_java_script_object_methods = nullptr;
      } else {
        ark_web_js_result_callback_has_java_script_object_methods =
            _struct->has_java_script_object_methods;
      }
    } else {
      ark_web_js_result_callback_has_java_script_object_methods =
          reinterpret_cast<
              ArkWebJsResultCallbackHasJavaScriptObjectMethodsFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_js_result_callback_has_java_script_object_methods, false);

  // Execute
  return ark_web_js_result_callback_has_java_script_object_methods(
      _struct, object_id, &method_name);
}

ARK_WEB_NO_SANITIZE
ArkWebValue ArkWebJsResultCallbackCToCpp::GetJavaScriptObjectMethods(
    int32_t object_id) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_js_result_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_value_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_js_result_callback_get_java_script_object_methods);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "0OY2sSLpZ9DDe83vN4cPxw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_JS_RESULT_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_js_result_callback_get_java_script_object_methods");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_java_script_object_methods)) {
        ark_web_js_result_callback_get_java_script_object_methods = nullptr;
      } else {
        ark_web_js_result_callback_get_java_script_object_methods =
            _struct->get_java_script_object_methods;
      }
    } else {
      ark_web_js_result_callback_get_java_script_object_methods =
          reinterpret_cast<
              ArkWebJsResultCallbackGetJavaScriptObjectMethodsFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_js_result_callback_get_java_script_object_methods,
      ark_web_value_default);

  // Execute
  return ark_web_js_result_callback_get_java_script_object_methods(_struct,
                                                                   object_id);
}

ARK_WEB_NO_SANITIZE
void ArkWebJsResultCallbackCToCpp::RemoveJavaScriptObjectHolder(
    int32_t holder,
    int32_t object_id) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_js_result_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_js_result_callback_remove_java_script_object_holder);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "qSc4SPDtkKAQ4ZhTy0jZmw";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_JS_RESULT_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_js_result_callback_remove_java_script_object_holder");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      remove_java_script_object_holder)) {
        ark_web_js_result_callback_remove_java_script_object_holder = nullptr;
      } else {
        ark_web_js_result_callback_remove_java_script_object_holder =
            _struct->remove_java_script_object_holder;
      }
    } else {
      ark_web_js_result_callback_remove_java_script_object_holder =
          reinterpret_cast<
              ArkWebJsResultCallbackRemoveJavaScriptObjectHolderFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_js_result_callback_remove_java_script_object_holder,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_js_result_callback_remove_java_script_object_holder(_struct, holder,
                                                              object_id);
}

ARK_WEB_NO_SANITIZE
void ArkWebJsResultCallbackCToCpp::RemoveTransientJavaScriptObject() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_js_result_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_js_result_callback_remove_transient_java_script_object);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "4C88sJLPbJZI2sHWj6L7TQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_JS_RESULT_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_js_result_callback_remove_transient_java_script_object");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      remove_transient_java_script_object)) {
        ark_web_js_result_callback_remove_transient_java_script_object =
            nullptr;
      } else {
        ark_web_js_result_callback_remove_transient_java_script_object =
            _struct->remove_transient_java_script_object;
      }
    } else {
      ark_web_js_result_callback_remove_transient_java_script_object =
          reinterpret_cast<
              ArkWebJsResultCallbackRemoveTransientJavaScriptObjectFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_js_result_callback_remove_transient_java_script_object,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_js_result_callback_remove_transient_java_script_object(_struct);
}

ARK_WEB_NO_SANITIZE
ArkWebValue ArkWebJsResultCallbackCToCpp::GetJavaScriptResultFlowbuf(
    ArkWebValueVector args,
    const ArkWebString& method,
    const ArkWebString& object_name,
    int fd,
    int32_t routing_id,
    int32_t object_id) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_js_result_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ark_web_value_default);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_js_result_callback_get_java_script_result_flowbuf);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Vg_qzA9_RbnLu63YNPGVVQ";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_JS_RESULT_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_js_result_callback_get_java_script_result_flowbuf");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_java_script_result_flowbuf)) {
        ark_web_js_result_callback_get_java_script_result_flowbuf = nullptr;
      } else {
        ark_web_js_result_callback_get_java_script_result_flowbuf =
            _struct->get_java_script_result_flowbuf;
      }
    } else {
      ark_web_js_result_callback_get_java_script_result_flowbuf =
          reinterpret_cast<
              ArkWebJsResultCallbackGetJavaScriptResultFlowbufFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_js_result_callback_get_java_script_result_flowbuf,
      ark_web_value_default);

  // Execute
  return ark_web_js_result_callback_get_java_script_result_flowbuf(
      _struct, args, &method, &object_name, fd, routing_id, object_id);
}

ARK_WEB_NO_SANITIZE
void ArkWebJsResultCallbackCToCpp::GetJavaScriptResultV2(
    const ArkWebHapValueVector& args,
    const ArkWebString& method,
    const ArkWebString& object_name,
    int32_t routing_id,
    int32_t object_id,
    ArkWebRefPtr<ArkWebHapValue> result) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_js_result_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_js_result_callback_get_java_script_result_v2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "7KVkXLZiaIkf$bjD9obgWA";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_JS_RESULT_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_js_result_callback_get_java_script_result_v2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_java_script_result_v2)) {
        ark_web_js_result_callback_get_java_script_result_v2 = nullptr;
      } else {
        ark_web_js_result_callback_get_java_script_result_v2 =
            _struct->get_java_script_result_v2;
      }
    } else {
      ark_web_js_result_callback_get_java_script_result_v2 =
          reinterpret_cast<ArkWebJsResultCallbackGetJavaScriptResultV2Func>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_js_result_callback_get_java_script_result_v2,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_js_result_callback_get_java_script_result_v2(
      _struct, &args, &method, &object_name, routing_id, object_id,
      ArkWebHapValueCppToC::Invert(result));
}

ARK_WEB_NO_SANITIZE
void ArkWebJsResultCallbackCToCpp::GetJavaScriptResultFlowbufV2(
    const ArkWebHapValueVector& args,
    const ArkWebString& method,
    const ArkWebString& object_name,
    int fd,
    int32_t routing_id,
    int32_t object_id,
    ArkWebRefPtr<ArkWebHapValue> result) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_js_result_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_js_result_callback_get_java_script_result_flowbuf_v2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "2O4u1hRpw4DGczZNriQO7A";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_JS_RESULT_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_js_result_callback_get_java_script_result_flowbuf_v2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_java_script_result_flowbuf_v2)) {
        ark_web_js_result_callback_get_java_script_result_flowbuf_v2 = nullptr;
      } else {
        ark_web_js_result_callback_get_java_script_result_flowbuf_v2 =
            _struct->get_java_script_result_flowbuf_v2;
      }
    } else {
      ark_web_js_result_callback_get_java_script_result_flowbuf_v2 =
          reinterpret_cast<
              ArkWebJsResultCallbackGetJavaScriptResultFlowbufV2Func>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_js_result_callback_get_java_script_result_flowbuf_v2,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_js_result_callback_get_java_script_result_flowbuf_v2(
      _struct, &args, &method, &object_name, fd, routing_id, object_id,
      ArkWebHapValueCppToC::Invert(result));
}

ARK_WEB_NO_SANITIZE
void ArkWebJsResultCallbackCToCpp::GetJavaScriptObjectMethodsV2(
    int32_t object_id,
    ArkWebRefPtr<ArkWebHapValue> result) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_web_js_result_callback_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_web_js_result_callback_get_java_script_object_methods_v2);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "KqsP2riMqUHZqxAqgBmeOg";
    func_pointer =
        ArkWebNWebWebcoreBridgeHelper::GetInstance().CheckFuncMemberForCaller(
            ARK_WEB_JS_RESULT_CALLBACK, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_web_js_result_callback_get_java_script_object_methods_v2");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_java_script_object_methods_v2)) {
        ark_web_js_result_callback_get_java_script_object_methods_v2 = nullptr;
      } else {
        ark_web_js_result_callback_get_java_script_object_methods_v2 =
            _struct->get_java_script_object_methods_v2;
      }
    } else {
      ark_web_js_result_callback_get_java_script_object_methods_v2 =
          reinterpret_cast<
              ArkWebJsResultCallbackGetJavaScriptObjectMethodsV2Func>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_web_js_result_callback_get_java_script_object_methods_v2,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_web_js_result_callback_get_java_script_object_methods_v2(
      _struct, object_id, ArkWebHapValueCppToC::Invert(result));
}

ArkWebJsResultCallbackCToCpp::ArkWebJsResultCallbackCToCpp() {}

ArkWebJsResultCallbackCToCpp::~ArkWebJsResultCallbackCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkWebJsResultCallbackCToCpp,
                           ArkWebJsResultCallback,
                           ark_web_js_result_callback_t>::kBridgeType =
        ARK_WEB_JS_RESULT_CALLBACK;

}  // namespace OHOS::ArkWeb
