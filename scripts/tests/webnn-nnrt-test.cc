// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
// A fault-injecting SDK boundary: this tests host logic/ownership, NOT NPU
// support.
#include <neural_network_runtime/neural_network_core.h>
#include <neural_network_runtime/neural_network_runtime.h>
#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include "services/webnn/ohos/nnrt_add_model.h"

struct NN_TensorDesc {
  size_t bytes = 0;
  std::vector<int32_t> shape;
  OH_NN_DataType dtype = OH_NN_UNKNOWN;
  OH_NN_Format format = OH_NN_FORMAT_NONE;
};
struct OH_NNModel {
  std::vector<NN_TensorDesc> tensors;
  std::vector<OH_NN_TensorType> tensor_types;
  std::vector<std::vector<uint8_t>> tensor_data;
  std::vector<OH_NN_OperationType> ops;
};
struct OH_NNCompilation {};
struct OH_NNExecutor {};
struct NN_Tensor {
  std::vector<float> data;
};
namespace {
int live = 0, calls = 0, fail_at = -1;
bool accelerator = true, supported = true, small_buffer = false;
bool require_4d_nchw = false;
bool multi_accel_mode = false;
size_t chosen = 0;
std::array<bool, 64> op_support_arr{};

bool fail() {
  return ++calls == fail_at;
}
template <class T>
T* create() {
  if (fail())
    return nullptr;
  ++live;
  return new T;
}
template <class T>
void destroy(T** p) {
  assert(p && *p);
  delete *p;
  *p = nullptr;
  --live;
}
OH_NN_ReturnCode status() {
  return fail() ? OH_NN_FAILED : OH_NN_SUCCESS;
}
size_t ByteSize(OH_NN_DataType type) {
  switch (type) {
    case OH_NN_FLOAT32:
    case OH_NN_INT32:
      return 4;
    case OH_NN_FLOAT16:
      return 2;
    case OH_NN_INT64:
      return 8;
    default:
      return 1;
  }
}
}  // namespace
extern "C" {
OH_NN_ReturnCode OH_NNDevice_GetAllDevicesID(const size_t** ids, uint32_t* n) {
  static const size_t values_single[] = {10, 20};
  static const size_t values_multi[] = {10, 20, 30};
  if (multi_accel_mode) {
    *ids = values_multi;
    *n = 3;
  } else {
    *ids = values_single;
    *n = 2;
  }
  return status();
}
OH_NN_ReturnCode OH_NNDevice_GetType(size_t id, OH_NN_DeviceType* type) {
  if ((id == 20 || id == 30) && accelerator) {
    *type = OH_NN_ACCELERATOR;
  } else {
    *type = OH_NN_CPU;
  }
  return status();
}
OH_NN_ReturnCode OH_NNDevice_GetName(size_t id, const char** name) {
  if (id == 10) {
    *name = "fake-cpu";
  } else if (id == 20) {
    *name = "fake-accelerator-0";
  } else if (id == 30) {
    *name = "fake-accelerator-1";
  } else {
    return OH_NN_FAILED;
  }
  return status();
}
NN_TensorDesc* OH_NNTensorDesc_Create() {
  return create<NN_TensorDesc>();
}
OH_NN_ReturnCode OH_NNTensorDesc_Destroy(NN_TensorDesc** p) {
  destroy(p);
  return OH_NN_SUCCESS;
}
OH_NN_ReturnCode OH_NNTensorDesc_SetShape(NN_TensorDesc* d,
                                          const int32_t* shape,
                                          size_t n) {
  d->shape.assign(shape, shape + n);
  d->bytes = ByteSize(d->dtype);
  for (size_t i = 0; i < n; ++i)
    d->bytes *= shape[i];
  return status();
}
OH_NN_ReturnCode OH_NNTensorDesc_SetDataType(NN_TensorDesc* d,
                                             OH_NN_DataType dtype) {
  d->dtype = dtype;
  d->bytes = ByteSize(d->dtype);
  for (int32_t dim : d->shape)
    d->bytes *= dim;
  return status();
}
OH_NN_ReturnCode OH_NNTensorDesc_SetFormat(NN_TensorDesc* d,
                                           OH_NN_Format format) {
  d->format = format;
  return status();
}
OH_NNModel* OH_NNModel_Construct() {
  return create<OH_NNModel>();
}
void OH_NNModel_Destroy(OH_NNModel** p) {
  destroy(p);
}
OH_NN_ReturnCode OH_NNModel_AddTensorToModel(OH_NNModel* m,
                                             const NN_TensorDesc* d) {
  auto r = status();
  if (r == OH_NN_SUCCESS) {
    m->tensors.push_back(*d);
    m->tensor_types.push_back(OH_NN_TENSOR);
    m->tensor_data.emplace_back();
  }
  return r;
}
OH_NN_ReturnCode OH_NNModel_SetTensorType(OH_NNModel* m,
                                          uint32_t index,
                                          OH_NN_TensorType t) {
  assert(index < m->tensor_types.size());
  m->tensor_types[index] = t;
  return status();
}
OH_NN_ReturnCode OH_NNModel_SetTensorData(OH_NNModel* m,
                                          uint32_t index,
                                          const void* data,
                                          size_t len) {
  assert(index < m->tensor_data.size() && data && len > 0);
  const auto* bytes = static_cast<const uint8_t*>(data);
  m->tensor_data[index].assign(bytes, bytes + len);
  return status();
}
OH_NN_ReturnCode OH_NNModel_AddOperation(OH_NNModel* m,
                                         OH_NN_OperationType op,
                                         const OH_NN_UInt32Array*,
                                         const OH_NN_UInt32Array* in,
                                         const OH_NN_UInt32Array* out) {
  assert(in->size >= 1 && out->size >= 1);
  auto r = status();
  if (r == OH_NN_SUCCESS) {
    m->ops.push_back(op);
  }
  return r;
}
OH_NN_ReturnCode OH_NNModel_SpecifyInputsAndOutputs(OH_NNModel*,
                                                    const OH_NN_UInt32Array*,
                                                    const OH_NN_UInt32Array*) {
  return status();
}
OH_NN_ReturnCode OH_NNModel_Finish(OH_NNModel*) {
  return status();
}
OH_NN_ReturnCode OH_NNModel_GetAvailableOperations(OH_NNModel* m,
                                                   size_t id,
                                                   const bool** s,
                                                   uint32_t* n) {
  assert(id == 20 || id == 30);
  bool ok = supported;
  if (multi_accel_mode && id == 20) {
    ok = false;
  }
  if (require_4d_nchw) {
    for (size_t i = 0; i < m->tensors.size(); ++i) {
      if (m->tensor_types[i] == OH_NN_TENSOR) {
        if (m->tensors[i].format != OH_NN_FORMAT_NCHW ||
            m->tensors[i].shape.size() != 4) {
          ok = false;
          break;
        }
      }
    }
  }
  op_support_arr.fill(ok);
  *s = op_support_arr.data();
  *n = static_cast<uint32_t>(m->ops.size());
  return status();
}
OH_NNCompilation* OH_NNCompilation_Construct(const OH_NNModel*) {
  return create<OH_NNCompilation>();
}
void OH_NNCompilation_Destroy(OH_NNCompilation** p) {
  destroy(p);
}
OH_NN_ReturnCode OH_NNCompilation_SetDevice(OH_NNCompilation*, size_t id) {
  chosen = id;
  return status();
}
OH_NN_ReturnCode OH_NNCompilation_EnableFloat16(OH_NNCompilation*,
                                                bool enable) {
  assert(!enable);
  return status();
}
OH_NN_ReturnCode OH_NNCompilation_Build(OH_NNCompilation*) {
  return status();
}
OH_NNExecutor* OH_NNExecutor_Construct(OH_NNCompilation*) {
  return create<OH_NNExecutor>();
}
void OH_NNExecutor_Destroy(OH_NNExecutor** p) {
  destroy(p);
}
NN_Tensor* OH_NNTensor_Create(size_t id, NN_TensorDesc* d) {
  assert(id == 20 || id == 30);
  auto* p = create<NN_Tensor>();
  if (p)
    p->data.resize(d->bytes / 4);
  return p;
}
OH_NN_ReturnCode OH_NNTensor_Destroy(NN_Tensor** p) {
  destroy(p);
  return OH_NN_SUCCESS;
}
void* OH_NNTensor_GetDataBuffer(const NN_Tensor* p) {
  return fail() ? nullptr : const_cast<float*>(p->data.data());
}
OH_NN_ReturnCode OH_NNTensor_GetSize(const NN_Tensor* p, size_t* size) {
  *size = small_buffer ? 1 : p->data.size() * 4;
  return status();
}
OH_NN_ReturnCode OH_NNTensor_GetOffset(const NN_Tensor*, size_t* offset) {
  *offset = 0;
  return status();
}
OH_NN_ReturnCode OH_NNExecutor_RunSync(OH_NNExecutor*,
                                       NN_Tensor* in[],
                                       size_t ni,
                                       NN_Tensor* out[],
                                       size_t no) {
  assert(ni >= 1 && no >= 1);
  auto r = status();
  if (r != OH_NN_SUCCESS)
    return r;
  if (ni == 2) {
    for (size_t i = 0; i < out[0]->data.size(); ++i)
      out[0]->data[i] = in[0]->data[i] + in[1]->data[i];
  } else {
    // Multi-op graph test: y = relu(x * 2 + 1)
    for (size_t i = 0; i < out[0]->data.size(); ++i)
      out[0]->data[i] = std::max(0.0f, in[0]->data[i] * 2.0f + 1.0f);
  }
  return OH_NN_SUCCESS;
}
}

int main() {
  using webnn::ohos::NnrtAddModel;
  using webnn::ohos::NnrtCompiledGraph;
  using webnn::ohos::NnrtDataType;
  using webnn::ohos::NnrtGraphSpec;
  using webnn::ohos::NnrtOpType;
  webnn::ohos::NnrtDevice device;
  std::string error;
  size_t bytes;

  // 1. Validate NnrtAddModel shape bounds and device selection.
  for (const auto& shape : std::vector<std::vector<uint32_t>>{
           {}, {0}, {1, 1, 1, 1, 1}, {0xffffffff}, {1024, 1025}}) {
    assert(!NnrtAddModel::ValidateShape(shape, bytes, error));
  }
  assert(NnrtAddModel::ValidateShape({1024, 1024}, bytes, error) &&
         bytes == 4 * 1024 * 1024);

  std::vector<webnn::ohos::NnrtDeviceInfo> all_devices;
  assert(webnn::ohos::ListNnrtDevices(all_devices, error) &&
         all_devices.size() == 2);
  assert(webnn::ohos::FindNnrtAccelerator(device, error) && device.id == 20);

  accelerator = false;
  assert(!webnn::ohos::FindNnrtAccelerator(device, error));
  assert(!NnrtAddModel::Create(device, {4}, error));
  accelerator = true;

  // 2. NnrtAddModel creation, execution, and fault injection.
  calls = 0;
  auto model = NnrtAddModel::Create(device, {4}, error);
  assert(model && chosen == 20);
  const int creation_calls = calls;
  const std::array<float, 4> lhs{1, -2, 0.25f, 1024},
      rhs{3, 0.5f, -0.125f, -512};
  std::array<float, 4> out{};
  calls = 0;
  assert(model->Run(lhs.data(), sizeof(lhs), rhs.data(), sizeof(rhs),
                    out.data(), sizeof(out), error));
  assert((out == std::array<float, 4>{4, -1.5f, 0.125f, 512}));
  const int run_calls = calls;
  for (int i = 1; i <= run_calls; ++i) {
    calls = 0;
    fail_at = i;
    out.fill(123);
    assert(!model->Run(lhs.data(), sizeof(lhs), rhs.data(), sizeof(rhs),
                       out.data(), sizeof(out), error));
    for (float value : out)
      assert(value == 123);
  }
  fail_at = -1;
  calls = 0;
  assert(!model->Run(lhs.data(), 4, rhs.data(), sizeof(rhs), out.data(),
                     sizeof(out), error) &&
         calls == 0);
  small_buffer = true;
  assert(!model->Run(lhs.data(), sizeof(lhs), rhs.data(), sizeof(rhs),
                     out.data(), sizeof(out), error));
  small_buffer = false;
  model.reset();
  assert(live == 0);
  for (int i = 1; i <= creation_calls; ++i) {
    calls = 0;
    fail_at = i;
    assert(!NnrtAddModel::Create(device, {4}, error));
    assert(live == 0);
  }
  fail_at = -1;
  supported = false;
  assert(!NnrtAddModel::Create(device, {4}, error) && live == 0);
  supported = true;

  // 3. Test automatic format + 4D shape promotion when NNRt driver requires
  // NCHW 4D tensors (Mate 70 Pro+ GetAvailableOperations fix).
  require_4d_nchw = true;
  auto promoted_add = NnrtAddModel::Create(device, {1, 4}, error);
  assert(promoted_add);
  assert(promoted_add->Run(lhs.data(), sizeof(lhs), rhs.data(), sizeof(rhs),
                           out.data(), sizeof(out), error));
  assert((out == std::array<float, 4>{4, -1.5f, 0.125f, 512}));
  promoted_add.reset();
  assert(live == 0);
  require_4d_nchw = false;

  // 4. Test general multi-op DAG NnrtCompiledGraph (Mul + Add + Relu with
  // constant weights) and multi-accelerator fallback.
  NnrtGraphSpec spec;
  spec.operands.resize(6);
  // 0: input x [1, 4]
  spec.operands[0] = {NnrtDataType::kFloat32, {1, 4}, {}};
  // 1: constant weight [1, 4] = {2, 2, 2, 2}
  const std::array<float, 4> w_vals{2.0f, 2.0f, 2.0f, 2.0f};
  spec.operands[1].data_type = NnrtDataType::kFloat32;
  spec.operands[1].shape = {1, 4};
  spec.operands[1].constant_data.resize(sizeof(w_vals));
  std::memcpy(spec.operands[1].constant_data.data(), w_vals.data(),
              sizeof(w_vals));
  // 2: constant bias [1, 4] = {1, 1, 1, 1}
  const std::array<float, 4> b_vals{1.0f, 1.0f, 1.0f, 1.0f};
  spec.operands[2].data_type = NnrtDataType::kFloat32;
  spec.operands[2].shape = {1, 4};
  spec.operands[2].constant_data.resize(sizeof(b_vals));
  std::memcpy(spec.operands[2].constant_data.data(), b_vals.data(),
              sizeof(b_vals));
  // 3: intermediate mul_out [1, 4]
  spec.operands[3] = {NnrtDataType::kFloat32, {1, 4}, {}};
  // 4: intermediate add_out [1, 4]
  spec.operands[4] = {NnrtDataType::kFloat32, {1, 4}, {}};
  // 5: output relu_out [1, 4]
  spec.operands[5] = {NnrtDataType::kFloat32, {1, 4}, {}};

  spec.input_operands = {0};
  spec.output_operands = {5};
  spec.operations.resize(3);
  spec.operations[0].type = NnrtOpType::kMul;
  spec.operations[0].inputs = {0, 1};
  spec.operations[0].outputs = {3};
  spec.operations[1].type = NnrtOpType::kAdd;
  spec.operations[1].inputs = {3, 2};
  spec.operations[1].outputs = {4};
  spec.operations[2].type = NnrtOpType::kRelu;
  spec.operations[2].inputs = {4};
  spec.operations[2].outputs = {5};

  multi_accel_mode = true;
  require_4d_nchw = true;
  std::vector<webnn::ohos::NnrtDevice> accelerators;
  assert(webnn::ohos::FindNnrtAccelerators(accelerators, error) &&
         accelerators.size() == 2);
  auto dag = NnrtCompiledGraph::Create(accelerators, spec, error);
  assert(dag && dag->device().id == 30 && chosen == 30);
  std::array<float, 4> dag_out{};
  assert(dag->Run({{lhs.data(), sizeof(lhs)}},
                  {{dag_out.data(), sizeof(dag_out)}}, error));
  assert((dag_out == std::array<float, 4>{3.0f, 0.0f, 1.5f, 2049.0f}));
  dag.reset();
  assert(live == 0);
  multi_accel_mode = false;
  require_4d_nchw = false;

  // Fault injection on NnrtCompiledGraph::Create
  calls = 0;
  auto dag_single = NnrtCompiledGraph::Create(device, spec, error);
  assert(dag_single);
  const int dag_create_calls = calls;
  dag_single.reset();
  assert(live == 0);
  for (int i = 1; i <= dag_create_calls; ++i) {
    calls = 0;
    fail_at = i;
    assert(!NnrtCompiledGraph::Create(device, spec, error));
    assert(live == 0);
  }
  fail_at = -1;

  std::cout << "PASS: selection, shape bounds, 4D/NCHW promotion, multi-op "
               "DAG, multi-device fallback, "
            << creation_calls << "+" << dag_create_calls << " creation + "
            << run_calls << " execution failure points; all handles released\n";
}
