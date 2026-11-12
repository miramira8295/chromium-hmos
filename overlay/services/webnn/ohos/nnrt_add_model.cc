// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "services/webnn/ohos/nnrt_add_model.h"

#include <algorithm>
#include <array>
#include <cstring>
#include <deque>
#include <limits>
#include <sstream>
#include <utility>

#include <neural_network_runtime/neural_network_core.h>
#include <neural_network_runtime/neural_network_runtime.h>

namespace webnn::ohos {
namespace {

template <class T, auto Destroy>
struct NnrtDeleter {
  void operator()(T* value) const { Destroy(&value); }
};
using Model =
    std::unique_ptr<OH_NNModel, NnrtDeleter<OH_NNModel, OH_NNModel_Destroy>>;
using Compilation =
    std::unique_ptr<OH_NNCompilation,
                    NnrtDeleter<OH_NNCompilation, OH_NNCompilation_Destroy>>;
using Executor =
    std::unique_ptr<OH_NNExecutor,
                    NnrtDeleter<OH_NNExecutor, OH_NNExecutor_Destroy>>;
using Desc =
    std::unique_ptr<NN_TensorDesc,
                    NnrtDeleter<NN_TensorDesc, OH_NNTensorDesc_Destroy>>;
using Tensor =
    std::unique_ptr<NN_Tensor, NnrtDeleter<NN_Tensor, OH_NNTensor_Destroy>>;

bool Check(OH_NN_ReturnCode code, const char* operation, std::string& error) {
  if (code == OH_NN_SUCCESS) {
    return true;
  }
  error = std::string(operation) + " failed: " + std::to_string(code);
  return false;
}

OH_NN_DataType ToOhosDataType(NnrtDataType type) {
  switch (type) {
    case NnrtDataType::kFloat32:
      return OH_NN_FLOAT32;
    case NnrtDataType::kFloat16:
      return OH_NN_FLOAT16;
    case NnrtDataType::kInt32:
      return OH_NN_INT32;
    case NnrtDataType::kInt8:
      return OH_NN_INT8;
    case NnrtDataType::kUint8:
      return OH_NN_UINT8;
    case NnrtDataType::kBool:
      return OH_NN_BOOL;
    case NnrtDataType::kInt64:
      return OH_NN_INT64;
  }
  return OH_NN_UNKNOWN;
}

std::vector<int32_t> BuildDims(const std::vector<uint32_t>& shape,
                               bool pad_to_4d) {
  std::vector<int32_t> dims;
  if (shape.empty()) {
    dims = {1};
  } else {
    dims.assign(shape.begin(), shape.end());
  }
  if (pad_to_4d && dims.size() < 4) {
    dims.insert(dims.begin(), 4 - dims.size(), 1);
  }
  return dims;
}

Desc MakeDescWithFormat(const std::vector<int32_t>& shape,
                        OH_NN_DataType type,
                        OH_NN_Format format,
                        std::string& error) {
  Desc desc(OH_NNTensorDesc_Create());
  if (!desc) {
    error = "OH_NNTensorDesc_Create failed";
    return nullptr;
  }
  if (!Check(OH_NNTensorDesc_SetShape(desc.get(), shape.data(), shape.size()),
             "SetShape", error) ||
      !Check(OH_NNTensorDesc_SetDataType(desc.get(), type), "SetDataType",
             error) ||
      !Check(OH_NNTensorDesc_SetFormat(desc.get(), format), "SetFormat",
             error)) {
    return nullptr;
  }
  return desc;
}

Desc MakeDesc(const std::vector<int32_t>& shape,
              OH_NN_DataType type,
              std::string& error) {
  return MakeDescWithFormat(shape, type, OH_NN_FORMAT_NONE, error);
}

struct FormatCandidate {
  OH_NN_Format format;
  bool pad_to_4d;
  const char* label;
};

constexpr std::array<FormatCandidate, 4> kFormatCandidates = {{
    {OH_NN_FORMAT_NONE, false, "NONE/native"},
    {OH_NN_FORMAT_NCHW, false, "NCHW/native"},
    {OH_NN_FORMAT_NONE, true, "NONE/4D"},
    {OH_NN_FORMAT_NCHW, true, "NCHW/4D"},
}};

bool CanPadGraphTo4D(const NnrtGraphSpec& spec) {
  for (const auto& operand : spec.operands) {
    if (operand.shape.size() > 4) {
      return false;
    }
  }
  for (const auto& op : spec.operations) {
    switch (op.type) {
      case NnrtOpType::kAdd:
      case NnrtOpType::kSub:
      case NnrtOpType::kMul:
      case NnrtOpType::kDiv:
      case NnrtOpType::kMax:
      case NnrtOpType::kMin:
      case NnrtOpType::kPow:
      case NnrtOpType::kEqual:
      case NnrtOpType::kGreater:
      case NnrtOpType::kGreaterEqual:
      case NnrtOpType::kNotEqual:
      case NnrtOpType::kLess:
      case NnrtOpType::kLessEqual:
      case NnrtOpType::kLogicalAnd:
      case NnrtOpType::kLogicalOr:
      case NnrtOpType::kAbs:
      case NnrtOpType::kCeil:
      case NnrtOpType::kCos:
      case NnrtOpType::kExp:
      case NnrtOpType::kFloor:
      case NnrtOpType::kLog:
      case NnrtOpType::kNeg:
      case NnrtOpType::kReciprocal:
      case NnrtOpType::kRound:
      case NnrtOpType::kSin:
      case NnrtOpType::kSqrt:
      case NnrtOpType::kTan:
      case NnrtOpType::kErf:
      case NnrtOpType::kLogicalNot:
      case NnrtOpType::kCast:
      case NnrtOpType::kIdentity:
      case NnrtOpType::kRelu:
      case NnrtOpType::kLeakyRelu:
      case NnrtOpType::kElu:
      case NnrtOpType::kSigmoid:
      case NnrtOpType::kTanh:
      case NnrtOpType::kGelu:
      case NnrtOpType::kHardSwish:
      case NnrtOpType::kHardSigmoid:
      case NnrtOpType::kClamp:
      case NnrtOpType::kLinear:
      case NnrtOpType::kSoftplus:
      case NnrtOpType::kWhere:
        break;
      default:
        return false;
    }
  }
  return true;
}

}  // namespace

struct NnrtAddModel::Impl {
  // Keep constant storage alive for the entire model lifetime.
  const int8_t activation = OH_NN_FUSED_NONE;
  // Reverse destruction keeps the model alive through compilation/execution.
  Model model;
  Compilation compilation;
  std::array<Tensor, 3> tensors;
  Executor executor;
  size_t bytes = 0;
};

struct NnrtCompiledGraph::Impl {
  NnrtDevice device;
  // Stable constant storage that outlives OH_NNModel and OH_NNCompilation.
  std::deque<std::vector<uint8_t>> constant_pool;
  Model model;
  Compilation compilation;
  std::vector<Tensor> input_tensors;
  std::vector<Tensor> output_tensors;
  std::vector<size_t> input_bytes;
  std::vector<size_t> output_bytes;
  Executor executor;
};

bool ListNnrtDevices(std::vector<NnrtDeviceInfo>& devices, std::string& error) {
  devices.clear();
  const size_t* ids = nullptr;
  uint32_t count = 0;
  if (!Check(OH_NNDevice_GetAllDevicesID(&ids, &count), "GetAllDevicesID",
             error)) {
    return false;
  }
  if (count && !ids) {
    error = "NNRt returned an invalid device list";
    return false;
  }
  devices.reserve(count);
  for (uint32_t i = 0; i < count; ++i) {
    OH_NN_DeviceType type = OH_NN_OTHERS;
    if (!Check(OH_NNDevice_GetType(ids[i], &type), "GetType", error)) {
      return false;
    }
    const char* name = nullptr;
    if (!Check(OH_NNDevice_GetName(ids[i], &name), "GetName", error)) {
      return false;
    }
    if (!name) {
      error = "NNRt device has no device name";
      return false;
    }
    devices.push_back({ids[i], static_cast<int32_t>(type), name});
  }
  return true;
}

bool FindNnrtAccelerators(std::vector<NnrtDevice>& devices,
                          std::string& error) {
  devices.clear();
  const size_t* ids = nullptr;
  uint32_t count = 0;
  if (!Check(OH_NNDevice_GetAllDevicesID(&ids, &count), "GetAllDevicesID",
             error)) {
    return false;
  }
  if (count && !ids) {
    error = "NNRt returned an invalid device list";
    return false;
  }
  for (uint32_t i = 0; i < count; ++i) {
    OH_NN_DeviceType type = OH_NN_OTHERS;
    if (OH_NNDevice_GetType(ids[i], &type) != OH_NN_SUCCESS ||
        type != OH_NN_ACCELERATOR) {
      continue;
    }
    const char* name = nullptr;
    if (!Check(OH_NNDevice_GetName(ids[i], &name), "GetName", error)) {
      return false;
    }
    if (!name) {
      error = "NNRt accelerator has no device name";
      return false;
    }
    devices.push_back({ids[i], name});
  }
  if (devices.empty()) {
    error = "No NNRt accelerator; CPU/GPU fallback is disabled";
    return false;
  }
  return true;
}

bool FindNnrtAccelerator(NnrtDevice& device, std::string& error) {
  std::vector<NnrtDevice> devices;
  if (!FindNnrtAccelerators(devices, error)) {
    return false;
  }
  device = std::move(devices.front());
  return true;
}

size_t NnrtCompiledGraph::DataTypeByteSize(NnrtDataType type) {
  switch (type) {
    case NnrtDataType::kFloat32:
    case NnrtDataType::kInt32:
      return 4;
    case NnrtDataType::kFloat16:
      return 2;
    case NnrtDataType::kInt8:
    case NnrtDataType::kUint8:
    case NnrtDataType::kBool:
      return 1;
    case NnrtDataType::kInt64:
      return 8;
  }
  return 0;
}

bool NnrtCompiledGraph::ValidateOperand(const NnrtOperandSpec& spec,
                                        size_t& bytes,
                                        std::string& error) {
  bytes = 0;
  if (spec.shape.size() > kMaxRank) {
    error = "NNRt operand rank exceeds maximum supported rank (8)";
    return false;
  }
  size_t size = DataTypeByteSize(spec.data_type);
  if (!size) {
    error = "Unsupported NNRt operand data type";
    return false;
  }
  for (uint32_t dim : spec.shape) {
    if (!dim ||
        dim > static_cast<uint32_t>(std::numeric_limits<int32_t>::max()) ||
        dim > kMaxTensorBytes / size) {
      error = "Invalid NNRt operand shape or tensor exceeds 64 MiB";
      return false;
    }
    size *= dim;
  }
  if (!spec.constant_data.empty() && spec.constant_data.size() != size) {
    error = "NNRt constant operand byte size mismatch";
    return false;
  }
  bytes = size;
  return true;
}

namespace {

class GraphModelBuilder {
 public:
  GraphModelBuilder(OH_NNModel* model,
                    std::deque<std::vector<uint8_t>>& constant_pool,
                    OH_NN_Format format,
                    bool pad_to_4d)
      : model_(model),
        constant_pool_(constant_pool),
        format_(format),
        pad_to_4d_(pad_to_4d) {}

  bool AddOperandTensor(const NnrtOperandSpec& spec,
                        uint32_t& out_index,
                        std::string& error) {
    const std::vector<int32_t> dims = BuildDims(spec.shape, pad_to_4d_);
    auto desc =
        MakeDescWithFormat(dims, ToOhosDataType(spec.data_type), format_, error);
    if (!desc) {
      return false;
    }
    const uint32_t idx = next_tensor_index_++;
    if (!Check(OH_NNModel_AddTensorToModel(model_, desc.get()),
               "AddTensorToModel", error) ||
        !Check(OH_NNModel_SetTensorType(model_, idx, OH_NN_TENSOR),
               "SetTensorType", error)) {
      return false;
    }
    if (!spec.constant_data.empty()) {
      constant_pool_.push_back(spec.constant_data);
      const auto& buf = constant_pool_.back();
      if (!Check(
              OH_NNModel_SetTensorData(model_, idx, buf.data(), buf.size()),
              "SetTensorData", error)) {
        return false;
      }
    }
    out_index = idx;
    return true;
  }

  template <typename T>
  bool AddScalarParam(OH_NN_DataType dtype,
                      OH_NN_TensorType tensor_type,
                      T value,
                      uint32_t& out_index,
                      std::string& error) {
    return AddArrayParam(dtype, tensor_type, &value, 1, out_index, error);
  }

  template <typename T>
  bool AddArrayParam(OH_NN_DataType dtype,
                     OH_NN_TensorType tensor_type,
                     const T* values,
                     size_t count,
                     uint32_t& out_index,
                     std::string& error) {
    const std::vector<int32_t> dims = {
        static_cast<int32_t>(std::max<size_t>(1, count))};
    auto desc = MakeDesc(dims, dtype, error);
    if (!desc) {
      return false;
    }
    const uint32_t idx = next_tensor_index_++;
    if (!Check(OH_NNModel_AddTensorToModel(model_, desc.get()),
               "AddParamTensor", error) ||
        !Check(OH_NNModel_SetTensorType(model_, idx, tensor_type),
               "SetParamTensorType", error)) {
      return false;
    }
    if (values && count > 0) {
      std::vector<uint8_t> bytes(count * sizeof(T));
      std::memcpy(bytes.data(), values, bytes.size());
      constant_pool_.push_back(std::move(bytes));
      const auto& buf = constant_pool_.back();
      if (!Check(
              OH_NNModel_SetTensorData(model_, idx, buf.data(), buf.size()),
              "SetParamTensorData", error)) {
        return false;
      }
    }
    out_index = idx;
    return true;
  }

  template <typename T>
  bool AddConstantDataTensor(const std::vector<int32_t>& dims,
                             OH_NN_DataType dtype,
                             const T* values,
                             size_t count,
                             uint32_t& out_index,
                             std::string& error) {
    auto desc = MakeDescWithFormat(dims, dtype, OH_NN_FORMAT_NONE, error);
    if (!desc) {
      return false;
    }
    const uint32_t idx = next_tensor_index_++;
    if (!Check(OH_NNModel_AddTensorToModel(model_, desc.get()),
               "AddConstTensor", error) ||
        !Check(OH_NNModel_SetTensorType(model_, idx, OH_NN_TENSOR),
               "SetConstTensorType", error)) {
      return false;
    }
    std::vector<uint8_t> bytes(count * sizeof(T));
    if (values && count > 0) {
      std::memcpy(bytes.data(), values, bytes.size());
    }
    constant_pool_.push_back(std::move(bytes));
    const auto& buf = constant_pool_.back();
    if (!Check(OH_NNModel_SetTensorData(model_, idx, buf.data(), buf.size()),
               "SetConstTensorData", error)) {
      return false;
    }
    out_index = idx;
    return true;
  }

  bool AddIntermediateTensor(const NnrtOperandSpec& like_spec,
                             uint32_t& out_index,
                             std::string& error) {
    NnrtOperandSpec temp;
    temp.data_type = like_spec.data_type;
    temp.shape = like_spec.shape;
    return AddOperandTensor(temp, out_index, error);
  }

  bool EmitOp(OH_NN_OperationType op_type,
              const std::vector<uint32_t>& inputs,
              const std::vector<uint32_t>& params,
              const std::vector<uint32_t>& outputs,
              std::string& error) {
    std::vector<uint32_t> in_copy = inputs;
    std::vector<uint32_t> param_copy = params;
    std::vector<uint32_t> out_copy = outputs;
    const OH_NN_UInt32Array in_arr{
        in_copy.empty() ? nullptr : in_copy.data(),
        static_cast<uint32_t>(in_copy.size())};
    const OH_NN_UInt32Array param_arr{
        param_copy.empty() ? nullptr : param_copy.data(),
        static_cast<uint32_t>(param_copy.size())};
    const OH_NN_UInt32Array out_arr{
        out_copy.empty() ? nullptr : out_copy.data(),
        static_cast<uint32_t>(out_copy.size())};
    if (!Check(
            OH_NNModel_AddOperation(model_, op_type, &param_arr, &in_arr,
                                    &out_arr),
            "AddOperation", error)) {
      return false;
    }
    ++emitted_op_count_;
    return true;
  }

  uint32_t emitted_op_count() const { return emitted_op_count_; }

 private:
  OH_NNModel* model_;
  std::deque<std::vector<uint8_t>>& constant_pool_;
  OH_NN_Format format_;
  bool pad_to_4d_;
  uint32_t next_tensor_index_ = 0;
  uint32_t emitted_op_count_ = 0;
};

bool BuildOperation(GraphModelBuilder& builder,
                    const NnrtGraphSpec& spec,
                    const NnrtOpSpec& op,
                    bool pad_to_4d,
                    std::string& error) {
  auto check_arity = [&](size_t min_in, size_t max_in,
                         size_t min_out) -> bool {
    if (op.inputs.size() < min_in || op.inputs.size() > max_in ||
        op.outputs.size() < min_out) {
      error = "Invalid NNRt operation input/output count";
      return false;
    }
    for (uint32_t id : op.inputs) {
      if (id >= spec.operands.size()) {
        error = "NNRt operation input operand index out of range";
        return false;
      }
    }
    for (uint32_t id : op.outputs) {
      if (id >= spec.operands.size()) {
        error = "NNRt operation output operand index out of range";
        return false;
      }
    }
    return true;
  };

  switch (op.type) {
    case NnrtOpType::kAdd:
    case NnrtOpType::kSub:
    case NnrtOpType::kMul:
    case NnrtOpType::kDiv: {
      if (!check_arity(2, 2, 1)) {
        return false;
      }
      OH_NN_OperationType nn_op = OH_NN_OPS_ADD;
      OH_NN_TensorType act_type = OH_NN_ADD_ACTIVATIONTYPE;
      if (op.type == NnrtOpType::kSub) {
        nn_op = OH_NN_OPS_SUB;
        act_type = OH_NN_SUB_ACTIVATIONTYPE;
      } else if (op.type == NnrtOpType::kMul) {
        nn_op = OH_NN_OPS_MUL;
        act_type = OH_NN_MUL_ACTIVATION_TYPE;
      } else if (op.type == NnrtOpType::kDiv) {
        nn_op = OH_NN_OPS_DIV;
        act_type = OH_NN_DIV_ACTIVATIONTYPE;
      }
      uint32_t act_param = 0;
      if (!builder.AddScalarParam<int8_t>(OH_NN_INT8, act_type,
                                          OH_NN_FUSED_NONE, act_param, error)) {
        return false;
      }
      return builder.EmitOp(nn_op, op.inputs, {act_param}, op.outputs, error);
    }

    case NnrtOpType::kMax:
    case NnrtOpType::kMin:
    case NnrtOpType::kEqual:
    case NnrtOpType::kGreater:
    case NnrtOpType::kGreaterEqual:
    case NnrtOpType::kNotEqual:
    case NnrtOpType::kLess:
    case NnrtOpType::kLessEqual:
    case NnrtOpType::kLogicalAnd:
    case NnrtOpType::kLogicalOr: {
      if (!check_arity(2, 2, 1)) {
        return false;
      }
      OH_NN_OperationType nn_op = OH_NN_OPS_MAXIMUM;
      if (op.type == NnrtOpType::kMin) {
        nn_op = OH_NN_OPS_MINIMUM;
      } else if (op.type == NnrtOpType::kEqual) {
        nn_op = OH_NN_OPS_EQUAL;
      } else if (op.type == NnrtOpType::kGreater) {
        nn_op = OH_NN_OPS_GREATER;
      } else if (op.type == NnrtOpType::kGreaterEqual) {
        nn_op = OH_NN_OPS_GREATER_EQUAL;
      } else if (op.type == NnrtOpType::kNotEqual) {
        nn_op = OH_NN_OPS_NOT_EQUAL;
      } else if (op.type == NnrtOpType::kLess) {
        nn_op = OH_NN_OPS_LESS;
      } else if (op.type == NnrtOpType::kLessEqual) {
        nn_op = OH_NN_OPS_LESS_EQUAL;
      } else if (op.type == NnrtOpType::kLogicalAnd) {
        nn_op = OH_NN_OPS_LOGICAL_AND;
      } else if (op.type == NnrtOpType::kLogicalOr) {
        nn_op = OH_NN_OPS_LOGICAL_OR;
      }
      return builder.EmitOp(nn_op, op.inputs, {}, op.outputs, error);
    }

    case NnrtOpType::kPow: {
      if (!check_arity(2, 2, 1)) {
        return false;
      }
      uint32_t scale_param = 0;
      uint32_t shift_param = 0;
      if (!builder.AddScalarParam<float>(OH_NN_FLOAT32, OH_NN_POW_SCALE, 1.0f,
                                         scale_param, error) ||
          !builder.AddScalarParam<float>(OH_NN_FLOAT32, OH_NN_POW_SHIFT, 0.0f,
                                         shift_param, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_POW, op.inputs,
                            {scale_param, shift_param}, op.outputs, error);
    }

    case NnrtOpType::kAbs:
    case NnrtOpType::kCeil:
    case NnrtOpType::kCos:
    case NnrtOpType::kFloor:
    case NnrtOpType::kLog:
    case NnrtOpType::kNeg:
    case NnrtOpType::kReciprocal:
    case NnrtOpType::kRound:
    case NnrtOpType::kSin:
    case NnrtOpType::kSqrt:
    case NnrtOpType::kErf:
    case NnrtOpType::kLogicalNot:
    case NnrtOpType::kRelu:
    case NnrtOpType::kSigmoid:
    case NnrtOpType::kTanh:
    case NnrtOpType::kHardSwish:
    case NnrtOpType::kHardSigmoid: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      OH_NN_OperationType nn_op = OH_NN_OPS_RELU;
      switch (op.type) {
        case NnrtOpType::kAbs:
          nn_op = OH_NN_OPS_ABS;
          break;
        case NnrtOpType::kCeil:
          nn_op = OH_NN_OPS_CEIL;
          break;
        case NnrtOpType::kCos:
          nn_op = OH_NN_OPS_COS;
          break;
        case NnrtOpType::kFloor:
          nn_op = OH_NN_OPS_FLOOR;
          break;
        case NnrtOpType::kLog:
          nn_op = OH_NN_OPS_LOG;
          break;
        case NnrtOpType::kNeg:
          nn_op = OH_NN_OPS_NEG;
          break;
        case NnrtOpType::kReciprocal:
          nn_op = OH_NN_OPS_RECIPROCAL;
          break;
        case NnrtOpType::kRound:
          nn_op = OH_NN_OPS_ROUND;
          break;
        case NnrtOpType::kSin:
          nn_op = OH_NN_OPS_SIN;
          break;
        case NnrtOpType::kSqrt:
          nn_op = OH_NN_OPS_SQRT;
          break;
        case NnrtOpType::kErf:
          nn_op = OH_NN_OPS_ERF;
          break;
        case NnrtOpType::kLogicalNot:
          nn_op = OH_NN_OPS_LOGICAL_NOT;
          break;
        case NnrtOpType::kRelu:
          nn_op = OH_NN_OPS_RELU;
          break;
        case NnrtOpType::kSigmoid:
          nn_op = OH_NN_OPS_SIGMOID;
          break;
        case NnrtOpType::kTanh:
          nn_op = OH_NN_OPS_TANH;
          break;
        case NnrtOpType::kHardSwish:
          nn_op = OH_NN_OPS_HSWISH;
          break;
        case NnrtOpType::kHardSigmoid:
          nn_op = OH_NN_OPS_HARD_SIGMOID;
          break;
        default:
          break;
      }
      return builder.EmitOp(nn_op, op.inputs, {}, op.outputs, error);
    }

    case NnrtOpType::kTan: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      // tan(x) = sin(x) / cos(x)
      uint32_t sin_tensor = 0;
      uint32_t cos_tensor = 0;
      uint32_t act_param = 0;
      const auto& out_spec = spec.operands[op.outputs[0]];
      if (!builder.AddIntermediateTensor(out_spec, sin_tensor, error) ||
          !builder.AddIntermediateTensor(out_spec, cos_tensor, error) ||
          !builder.AddScalarParam<int8_t>(OH_NN_INT8, OH_NN_DIV_ACTIVATIONTYPE,
                                          OH_NN_FUSED_NONE, act_param, error) ||
          !builder.EmitOp(OH_NN_OPS_SIN, op.inputs, {}, {sin_tensor}, error) ||
          !builder.EmitOp(OH_NN_OPS_COS, op.inputs, {}, {cos_tensor}, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_DIV, {sin_tensor, cos_tensor},
                            {act_param}, op.outputs, error);
    }

    case NnrtOpType::kExp: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      uint32_t base_param = 0;
      uint32_t scale_param = 0;
      uint32_t shift_param = 0;
      if (!builder.AddScalarParam<float>(OH_NN_FLOAT32, OH_NN_EXP_BASE, -1.0f,
                                         base_param, error) ||
          !builder.AddScalarParam<float>(OH_NN_FLOAT32, OH_NN_EXP_SCALE, 1.0f,
                                         scale_param, error) ||
          !builder.AddScalarParam<float>(OH_NN_FLOAT32, OH_NN_EXP_SHIFT, 0.0f,
                                         shift_param, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_EXP, op.inputs,
                            {base_param, scale_param, shift_param}, op.outputs,
                            error);
    }

    case NnrtOpType::kLeakyRelu: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      uint32_t slope_param = 0;
      if (!builder.AddScalarParam<float>(
              OH_NN_FLOAT32, OH_NN_LEAKY_RELU_NEGATIVE_SLOPE, op.alpha,
              slope_param, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_LEAKY_RELU, op.inputs, {slope_param},
                            op.outputs, error);
    }

    case NnrtOpType::kElu: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      // elu(x) = max(x, 0) + alpha * (exp(min(x, 0)) - 1)
      const auto& out_spec = spec.operands[op.outputs[0]];
      const std::vector<int32_t> scalar_dims = BuildDims({1}, pad_to_4d);
      uint32_t zero_tensor = 0;
      uint32_t one_tensor = 0;
      uint32_t alpha_tensor = 0;
      uint32_t pos_tensor = 0;
      uint32_t neg_tensor = 0;
      uint32_t exp_tensor = 0;
      uint32_t expm1_tensor = 0;
      uint32_t scaled_neg = 0;
      uint32_t base_p = 0, scale_p = 0, shift_p = 0;
      uint32_t sub_act = 0, mul_act = 0, add_act = 0;
      const float zero = 0.0f, one = 1.0f;
      if (!builder.AddConstantDataTensor(scalar_dims, OH_NN_FLOAT32, &zero, 1,
                                         zero_tensor, error) ||
          !builder.AddConstantDataTensor(scalar_dims, OH_NN_FLOAT32, &one, 1,
                                         one_tensor, error) ||
          !builder.AddConstantDataTensor(scalar_dims, OH_NN_FLOAT32, &op.alpha,
                                         1, alpha_tensor, error) ||
          !builder.AddIntermediateTensor(out_spec, pos_tensor, error) ||
          !builder.AddIntermediateTensor(out_spec, neg_tensor, error) ||
          !builder.AddIntermediateTensor(out_spec, exp_tensor, error) ||
          !builder.AddIntermediateTensor(out_spec, expm1_tensor, error) ||
          !builder.AddIntermediateTensor(out_spec, scaled_neg, error) ||
          !builder.AddScalarParam<float>(OH_NN_FLOAT32, OH_NN_EXP_BASE, -1.0f,
                                         base_p, error) ||
          !builder.AddScalarParam<float>(OH_NN_FLOAT32, OH_NN_EXP_SCALE, 1.0f,
                                         scale_p, error) ||
          !builder.AddScalarParam<float>(OH_NN_FLOAT32, OH_NN_EXP_SHIFT, 0.0f,
                                         shift_p, error) ||
          !builder.AddScalarParam<int8_t>(OH_NN_INT8, OH_NN_SUB_ACTIVATIONTYPE,
                                          OH_NN_FUSED_NONE, sub_act, error) ||
          !builder.AddScalarParam<int8_t>(OH_NN_INT8, OH_NN_MUL_ACTIVATION_TYPE,
                                          OH_NN_FUSED_NONE, mul_act, error) ||
          !builder.AddScalarParam<int8_t>(OH_NN_INT8, OH_NN_ADD_ACTIVATIONTYPE,
                                          OH_NN_FUSED_NONE, add_act, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_RELU, op.inputs, {}, {pos_tensor},
                            error) &&
             builder.EmitOp(OH_NN_OPS_MINIMUM, {op.inputs[0], zero_tensor}, {},
                            {neg_tensor}, error) &&
             builder.EmitOp(OH_NN_OPS_EXP, {neg_tensor},
                            {base_p, scale_p, shift_p}, {exp_tensor}, error) &&
             builder.EmitOp(OH_NN_OPS_SUB, {exp_tensor, one_tensor}, {sub_act},
                            {expm1_tensor}, error) &&
             builder.EmitOp(OH_NN_OPS_MUL, {expm1_tensor, alpha_tensor},
                            {mul_act}, {scaled_neg}, error) &&
             builder.EmitOp(OH_NN_OPS_ADD, {pos_tensor, scaled_neg}, {add_act},
                            op.outputs, error);
    }

    case NnrtOpType::kSoftplus: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      // softplus(x) = log(exp(x) + 1)
      const auto& out_spec = spec.operands[op.outputs[0]];
      const std::vector<int32_t> scalar_dims = BuildDims({1}, pad_to_4d);
      uint32_t one_tensor = 0;
      uint32_t exp_tensor = 0;
      uint32_t add_tensor = 0;
      uint32_t base_p = 0, scale_p = 0, shift_p = 0, add_act = 0;
      const float one = 1.0f;
      if (!builder.AddConstantDataTensor(scalar_dims, OH_NN_FLOAT32, &one, 1,
                                         one_tensor, error) ||
          !builder.AddIntermediateTensor(out_spec, exp_tensor, error) ||
          !builder.AddIntermediateTensor(out_spec, add_tensor, error) ||
          !builder.AddScalarParam<float>(OH_NN_FLOAT32, OH_NN_EXP_BASE, -1.0f,
                                         base_p, error) ||
          !builder.AddScalarParam<float>(OH_NN_FLOAT32, OH_NN_EXP_SCALE, 1.0f,
                                         scale_p, error) ||
          !builder.AddScalarParam<float>(OH_NN_FLOAT32, OH_NN_EXP_SHIFT, 0.0f,
                                         shift_p, error) ||
          !builder.AddScalarParam<int8_t>(OH_NN_INT8, OH_NN_ADD_ACTIVATIONTYPE,
                                          OH_NN_FUSED_NONE, add_act, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_EXP, op.inputs,
                            {base_p, scale_p, shift_p}, {exp_tensor}, error) &&
             builder.EmitOp(OH_NN_OPS_ADD, {exp_tensor, one_tensor}, {add_act},
                            {add_tensor}, error) &&
             builder.EmitOp(OH_NN_OPS_LOG, {add_tensor}, {}, op.outputs, error);
    }

    case NnrtOpType::kGelu: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      uint32_t approx_param = 0;
      if (!builder.AddScalarParam<bool>(OH_NN_BOOL, OH_NN_GELU_APPROXIMATE,
                                        false, approx_param, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_GELU, op.inputs, {approx_param},
                            op.outputs, error);
    }

    case NnrtOpType::kClamp: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      if (op.clamp_min == 0.0f && op.clamp_max == 6.0f) {
        return builder.EmitOp(OH_NN_OPS_RELU6, op.inputs, {}, op.outputs,
                              error);
      }
      uint32_t max_param = 0;
      uint32_t min_param = 0;
      if (!builder.AddScalarParam<float>(OH_NN_FLOAT32, OH_NN_CLIP_MAX,
                                         op.clamp_max, max_param, error) ||
          !builder.AddScalarParam<float>(OH_NN_FLOAT32, OH_NN_CLIP_MIN,
                                         op.clamp_min, min_param, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_CLIP, op.inputs, {max_param, min_param},
                            op.outputs, error);
    }

    case NnrtOpType::kLinear: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      const auto& out_spec = spec.operands[op.outputs[0]];
      const std::vector<int32_t> scalar_dims = BuildDims({1}, pad_to_4d);
      uint32_t alpha_tensor = 0;
      uint32_t beta_tensor = 0;
      uint32_t scaled_tensor = 0;
      uint32_t mul_act = 0;
      uint32_t add_act = 0;
      if (!builder.AddConstantDataTensor(scalar_dims, OH_NN_FLOAT32, &op.alpha,
                                         1, alpha_tensor, error) ||
          !builder.AddConstantDataTensor(scalar_dims, OH_NN_FLOAT32, &op.beta,
                                         1, beta_tensor, error) ||
          !builder.AddIntermediateTensor(out_spec, scaled_tensor, error) ||
          !builder.AddScalarParam<int8_t>(OH_NN_INT8, OH_NN_MUL_ACTIVATION_TYPE,
                                          OH_NN_FUSED_NONE, mul_act, error) ||
          !builder.AddScalarParam<int8_t>(OH_NN_INT8, OH_NN_ADD_ACTIVATIONTYPE,
                                          OH_NN_FUSED_NONE, add_act, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_MUL, {op.inputs[0], alpha_tensor},
                            {mul_act}, {scaled_tensor}, error) &&
             builder.EmitOp(OH_NN_OPS_ADD, {scaled_tensor, beta_tensor},
                            {add_act}, op.outputs, error);
    }

    case NnrtOpType::kPrelu: {
      if (!check_arity(2, 2, 1)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_PRELU, op.inputs, {}, op.outputs, error);
    }

    case NnrtOpType::kSoftmax: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      uint32_t axis_param = 0;
      if (!builder.AddScalarParam<int64_t>(OH_NN_INT64, OH_NN_SOFTMAX_AXIS,
                                           op.axis, axis_param, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_SOFTMAX, op.inputs, {axis_param},
                            op.outputs, error);
    }

    case NnrtOpType::kCast: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      const auto dst_type =
          static_cast<int32_t>(ToOhosDataType(spec.operands[op.outputs[0]].data_type));
      uint32_t type_tensor = 0;
      if (!builder.AddConstantDataTensor({1}, OH_NN_INT32, &dst_type, 1,
                                         type_tensor, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_CAST, {op.inputs[0], type_tensor}, {},
                            op.outputs, error);
    }

    case NnrtOpType::kIdentity:
    case NnrtOpType::kReshape: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      const std::vector<int32_t> target_dims =
          BuildDims(spec.operands[op.outputs[0]].shape, pad_to_4d);
      uint32_t shape_tensor = 0;
      if (!builder.AddConstantDataTensor(
              {static_cast<int32_t>(target_dims.size())}, OH_NN_INT32,
              target_dims.data(), target_dims.size(), shape_tensor, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_RESHAPE, {op.inputs[0], shape_tensor}, {},
                            op.outputs, error);
    }

    case NnrtOpType::kTranspose: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      if (op.permutation.empty()) {
        error = "Transpose permutation must not be empty";
        return false;
      }
      uint32_t perm_tensor = 0;
      if (!builder.AddConstantDataTensor(
              {static_cast<int32_t>(op.permutation.size())}, OH_NN_INT32,
              op.permutation.data(), op.permutation.size(), perm_tensor,
              error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_TRANSPOSE, {op.inputs[0], perm_tensor},
                            {}, op.outputs, error);
    }

    case NnrtOpType::kMatmul: {
      if (!check_arity(2, 2, 1)) {
        return false;
      }
      uint32_t ta = 0, tb = 0, act = 0;
      if (!builder.AddScalarParam<bool>(OH_NN_BOOL, OH_NN_MATMUL_TRANSPOSE_A,
                                        op.transpose_a, ta, error) ||
          !builder.AddScalarParam<bool>(OH_NN_BOOL, OH_NN_MATMUL_TRANSPOSE_B,
                                        op.transpose_b, tb, error) ||
          !builder.AddScalarParam<int8_t>(
              OH_NN_INT8, OH_NN_MATMUL_ACTIVATION_TYPE, OH_NN_FUSED_NONE, act,
              error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_MATMUL, op.inputs, {ta, tb, act},
                            op.outputs, error);
    }

    case NnrtOpType::kGemm: {
      if (!check_arity(2, 3, 1)) {
        return false;
      }
      const auto& out_spec = spec.operands[op.outputs[0]];
      uint32_t ta = 0, tb = 0, act = 0;
      if (!builder.AddScalarParam<bool>(OH_NN_BOOL, OH_NN_MATMUL_TRANSPOSE_A,
                                        op.transpose_a, ta, error) ||
          !builder.AddScalarParam<bool>(OH_NN_BOOL, OH_NN_MATMUL_TRANSPOSE_B,
                                        op.transpose_b, tb, error) ||
          !builder.AddScalarParam<int8_t>(
              OH_NN_INT8, OH_NN_MATMUL_ACTIVATION_TYPE, OH_NN_FUSED_NONE, act,
              error)) {
        return false;
      }
      const bool need_alpha = (op.alpha != 1.0f);
      const bool has_c = (op.inputs.size() == 3 && op.beta != 0.0f);
      if (!need_alpha && !has_c) {
        return builder.EmitOp(OH_NN_OPS_MATMUL, {op.inputs[0], op.inputs[1]},
                              {ta, tb, act}, op.outputs, error);
      }
      uint32_t ab_tensor = 0;
      if (!builder.AddIntermediateTensor(out_spec, ab_tensor, error) ||
          !builder.EmitOp(OH_NN_OPS_MATMUL, {op.inputs[0], op.inputs[1]},
                          {ta, tb, act}, {ab_tensor}, error)) {
        return false;
      }
      uint32_t lhs_tensor = ab_tensor;
      if (need_alpha) {
        uint32_t alpha_const = 0, mul_act = 0;
        uint32_t scaled_ab = has_c ? 0 : op.outputs[0];
        if (has_c &&
            !builder.AddIntermediateTensor(out_spec, scaled_ab, error)) {
          return false;
        }
        if (!builder.AddConstantDataTensor({1}, OH_NN_FLOAT32, &op.alpha, 1,
                                           alpha_const, error) ||
            !builder.AddScalarParam<int8_t>(
                OH_NN_INT8, OH_NN_MUL_ACTIVATION_TYPE, OH_NN_FUSED_NONE,
                mul_act, error) ||
            !builder.EmitOp(OH_NN_OPS_MUL, {ab_tensor, alpha_const}, {mul_act},
                            {scaled_ab}, error)) {
          return false;
        }
        lhs_tensor = scaled_ab;
      }
      if (!has_c) {
        return true;
      }
      uint32_t rhs_tensor = op.inputs[2];
      if (op.beta != 1.0f) {
        uint32_t beta_const = 0, mul_act = 0, scaled_c = 0;
        const auto& c_spec = spec.operands[op.inputs[2]];
        if (!builder.AddIntermediateTensor(c_spec, scaled_c, error) ||
            !builder.AddConstantDataTensor({1}, OH_NN_FLOAT32, &op.beta, 1,
                                           beta_const, error) ||
            !builder.AddScalarParam<int8_t>(
                OH_NN_INT8, OH_NN_MUL_ACTIVATION_TYPE, OH_NN_FUSED_NONE,
                mul_act, error) ||
            !builder.EmitOp(OH_NN_OPS_MUL, {op.inputs[2], beta_const},
                            {mul_act}, {scaled_c}, error)) {
          return false;
        }
        rhs_tensor = scaled_c;
      }
      uint32_t add_act = 0;
      if (!builder.AddScalarParam<int8_t>(OH_NN_INT8, OH_NN_ADD_ACTIVATIONTYPE,
                                          OH_NN_FUSED_NONE, add_act, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_ADD, {lhs_tensor, rhs_tensor}, {add_act},
                            op.outputs, error);
    }

    case NnrtOpType::kConcat: {
      if (!check_arity(1, 64, 1)) {
        return false;
      }
      uint32_t axis_param = 0;
      if (!builder.AddScalarParam<int64_t>(OH_NN_INT64, OH_NN_CONCAT_AXIS,
                                           op.axis, axis_param, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_CONCAT, op.inputs, {axis_param},
                            op.outputs, error);
    }

    case NnrtOpType::kSplit: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      std::vector<int32_t> size_splits;
      size_splits.reserve(op.outputs.size());
      for (uint32_t out_id : op.outputs) {
        const auto& out_shape = spec.operands[out_id].shape;
        if (op.axis < 0 || static_cast<size_t>(op.axis) >= out_shape.size()) {
          error = "Split axis out of bounds";
          return false;
        }
        size_splits.push_back(static_cast<int32_t>(out_shape[op.axis]));
      }
      uint32_t out_num_param = 0, splits_param = 0, axis_param = 0;
      if (!builder.AddScalarParam<int64_t>(
              OH_NN_INT64, OH_NN_SPLIT_OUTPUT_NUM,
              static_cast<int64_t>(op.outputs.size()), out_num_param, error) ||
          !builder.AddArrayParam<int32_t>(
              OH_NN_INT32, OH_NN_SPLIT_SIZE_SPLITS, size_splits.data(),
              size_splits.size(), splits_param, error) ||
          !builder.AddScalarParam<int64_t>(OH_NN_INT64, OH_NN_SPLIT_AXIS,
                                           op.axis, axis_param, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_SPLIT, op.inputs,
                            {out_num_param, splits_param, axis_param},
                            op.outputs, error);
    }

    case NnrtOpType::kExpand: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      const std::vector<int32_t> target_dims =
          BuildDims(spec.operands[op.outputs[0]].shape, pad_to_4d);
      uint32_t shape_param = 0;
      if (!builder.AddArrayParam<int32_t>(
              OH_NN_INT32, OH_NN_BROADCAST_TO_SHAPE, target_dims.data(),
              target_dims.size(), shape_param, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_BROADCAST_TO, op.inputs, {shape_param},
                            op.outputs, error);
    }

    case NnrtOpType::kGather: {
      if (!check_arity(2, 2, 1)) {
        return false;
      }
      const int32_t axis_val = static_cast<int32_t>(op.axis);
      uint32_t axis_tensor = 0;
      if (!builder.AddConstantDataTensor({1}, OH_NN_INT32, &axis_val, 1,
                                         axis_tensor, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_GATHER,
                            {op.inputs[0], op.inputs[1], axis_tensor}, {},
                            op.outputs, error);
    }

    case NnrtOpType::kTile: {
      if (!check_arity(1, 1, 1) || op.repeats.empty()) {
        error = "Invalid Tile operation specification";
        return false;
      }
      uint32_t multiples_tensor = 0;
      if (!builder.AddConstantDataTensor(
              {static_cast<int32_t>(op.repeats.size())}, OH_NN_INT32,
              op.repeats.data(), op.repeats.size(), multiples_tensor, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_TILE, {op.inputs[0], multiples_tensor},
                            {}, op.outputs, error);
    }

    case NnrtOpType::kWhere: {
      if (!check_arity(3, 3, 1)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_WHERE, op.inputs, {}, op.outputs, error);
    }

    case NnrtOpType::kPad: {
      if (!check_arity(1, 1, 1) || op.padding.empty() ||
          op.padding.size() % 2 != 0) {
        error = "Invalid Pad operation padding specification";
        return false;
      }
      const int32_t rank = static_cast<int32_t>(op.padding.size() / 2);
      uint32_t pad_tensor = 0, val_param = 0, mode_param = 0;
      if (!builder.AddConstantDataTensor({rank, 2}, OH_NN_INT32,
                                         op.padding.data(), op.padding.size(),
                                         pad_tensor, error) ||
          !builder.AddScalarParam<float>(OH_NN_FLOAT32,
                                         OH_NN_PAD_CONSTANT_VALUE, op.pad_value,
                                         val_param, error) ||
          !builder.AddScalarParam<int32_t>(OH_NN_INT32, OH_NN_PAD_PADDING_MODE,
                                           op.pad_mode, mode_param, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_PAD, {op.inputs[0], pad_tensor},
                            {val_param, mode_param}, op.outputs, error);
    }

    case NnrtOpType::kSlice: {
      if (!check_arity(1, 1, 1) || op.slice_starts.empty() ||
          op.slice_starts.size() != op.slice_sizes.size()) {
        error = "Invalid Slice operation starts/sizes";
        return false;
      }
      std::vector<int32_t> begins(op.slice_starts.begin(),
                                  op.slice_starts.end());
      std::vector<int32_t> sizes(op.slice_sizes.begin(), op.slice_sizes.end());
      std::vector<int32_t> axes(begins.size());
      for (size_t i = 0; i < axes.size(); ++i) {
        axes[i] = static_cast<int32_t>(i);
      }
      uint32_t begin_tensor = 0, size_tensor = 0, axes_param = 0;
      const int32_t n = static_cast<int32_t>(begins.size());
      if (!builder.AddConstantDataTensor({n}, OH_NN_INT32, begins.data(),
                                         begins.size(), begin_tensor, error) ||
          !builder.AddConstantDataTensor({n}, OH_NN_INT32, sizes.data(),
                                         sizes.size(), size_tensor, error) ||
          !builder.AddArrayParam<int32_t>(OH_NN_INT32, OH_NN_SLICE_AXES,
                                          axes.data(), axes.size(), axes_param,
                                          error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_SLICE,
                            {op.inputs[0], begin_tensor, size_tensor},
                            {axes_param}, op.outputs, error);
    }

    case NnrtOpType::kReduceMean:
    case NnrtOpType::kReduceSum:
    case NnrtOpType::kReduceMax:
    case NnrtOpType::kReduceMin:
    case NnrtOpType::kReduceProd:
    case NnrtOpType::kReduceL2: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      std::vector<int32_t> axes32;
      if (op.axes.empty()) {
        const size_t rank = spec.operands[op.inputs[0]].shape.size();
        for (size_t i = 0; i < rank; ++i) {
          axes32.push_back(static_cast<int32_t>(i));
        }
        if (axes32.empty()) {
          axes32.push_back(0);
        }
      } else {
        axes32.assign(op.axes.begin(), op.axes.end());
      }
      uint32_t axis_tensor = 0, keep_dims_param = 0;
      OH_NN_OperationType nn_op = OH_NN_OPS_REDUCE_MEAN;
      OH_NN_TensorType kd_type = OH_NN_REDUCE_MEAN_KEEP_DIMS;
      if (op.type == NnrtOpType::kReduceSum) {
        nn_op = OH_NN_OPS_REDUCE_SUM;
        kd_type = OH_NN_REDUCE_SUM_KEEP_DIMS;
      } else if (op.type == NnrtOpType::kReduceMax) {
        nn_op = OH_NN_OPS_REDUCE_MAX;
        kd_type = OH_NN_REDUCE_MAX_KEEP_DIMS;
      } else if (op.type == NnrtOpType::kReduceMin) {
        nn_op = OH_NN_OPS_REDUCE_MIN;
        kd_type = OH_NN_REDUCE_MIN_KEEP_DIMS;
      } else if (op.type == NnrtOpType::kReduceProd) {
        nn_op = OH_NN_OPS_REDUCE_PROD;
        kd_type = OH_NN_REDUCE_PROD_KEEP_DIMS;
      } else if (op.type == NnrtOpType::kReduceL2) {
        nn_op = OH_NN_OPS_REDUCE_L2;
        kd_type = OH_NN_REDUCE_L2_KEEP_DIMS;
      }
      if (!builder.AddConstantDataTensor(
              {static_cast<int32_t>(axes32.size())}, OH_NN_INT32, axes32.data(),
              axes32.size(), axis_tensor, error) ||
          !builder.AddScalarParam<bool>(OH_NN_BOOL, kd_type, op.keep_dims,
                                        keep_dims_param, error)) {
        return false;
      }
      return builder.EmitOp(nn_op, {op.inputs[0], axis_tensor},
                            {keep_dims_param}, op.outputs, error);
    }

    case NnrtOpType::kArgMax:
    case NnrtOpType::kArgMin: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      uint32_t input_id = op.inputs[0];
      if (op.type == NnrtOpType::kArgMin) {
        const auto& in_spec = spec.operands[op.inputs[0]];
        if (!builder.AddIntermediateTensor(in_spec, input_id, error) ||
            !builder.EmitOp(OH_NN_OPS_NEG, {op.inputs[0]}, {}, {input_id},
                            error)) {
          return false;
        }
      }
      uint32_t axis_param = 0, kd_param = 0;
      if (!builder.AddScalarParam<int32_t>(OH_NN_INT32, OH_NN_ARG_MAX_AXIS,
                                           static_cast<int32_t>(op.axis),
                                           axis_param, error) ||
          !builder.AddScalarParam<bool>(OH_NN_BOOL, OH_NN_ARG_MAX_KEEPDIMS,
                                        op.keep_dims, kd_param, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_ARG_MAX, {input_id},
                            {axis_param, kd_param}, op.outputs, error);
    }

    case NnrtOpType::kConv2d:
    case NnrtOpType::kConvTranspose2d:
    case NnrtOpType::kDepthwiseConv2d: {
      if (!check_arity(2, 3, 1)) {
        return false;
      }
      const std::vector<int64_t> strides =
          op.strides.size() == 2 ? op.strides : std::vector<int64_t>{1, 1};
      const std::vector<int64_t> dilations =
          op.dilations.size() == 2 ? op.dilations : std::vector<int64_t>{1, 1};
      std::vector<int64_t> pads = {0, 0, 0, 0};
      if (op.padding.size() == 4) {
        pads.assign(op.padding.begin(), op.padding.end());
      }
      uint32_t s_param = 0, d_param = 0, p_param = 0, g_param = 0, a_param = 0;
      if (!builder.AddArrayParam<int64_t>(OH_NN_INT64, OH_NN_CONV2D_STRIDES,
                                          strides.data(), 2, s_param, error) ||
          !builder.AddArrayParam<int64_t>(OH_NN_INT64, OH_NN_CONV2D_DILATION,
                                          dilations.data(), 2, d_param,
                                          error) ||
          !builder.AddArrayParam<int64_t>(OH_NN_INT64, OH_NN_CONV2D_PAD,
                                          pads.data(), 4, p_param, error) ||
          !builder.AddScalarParam<int64_t>(OH_NN_INT64, OH_NN_CONV2D_GROUP,
                                           op.groups, g_param, error) ||
          !builder.AddScalarParam<int8_t>(
              OH_NN_INT8, OH_NN_CONV2D_ACTIVATION_TYPE, OH_NN_FUSED_NONE,
              a_param, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_CONV2D, op.inputs,
                            {s_param, d_param, p_param, g_param, a_param},
                            op.outputs, error);
    }

    case NnrtOpType::kAvgPool2d:
    case NnrtOpType::kMaxPool2d: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      const bool is_avg = (op.type == NnrtOpType::kAvgPool2d);
      const std::vector<int64_t> kernel =
          op.kernel_size.size() == 2 ? op.kernel_size
                                     : std::vector<int64_t>{1, 1};
      const std::vector<int64_t> strides =
          op.strides.size() == 2 ? op.strides : std::vector<int64_t>{1, 1};
      std::vector<int64_t> pads = {0, 0, 0, 0};
      if (op.padding.size() == 4) {
        pads.assign(op.padding.begin(), op.padding.end());
      }
      uint32_t k_param = 0, s_param = 0, p_param = 0, a_param = 0;
      if (!builder.AddArrayParam<int64_t>(
              OH_NN_INT64,
              is_avg ? OH_NN_AVG_POOL_KERNEL_SIZE : OH_NN_MAX_POOL_KERNEL_SIZE,
              kernel.data(), 2, k_param, error) ||
          !builder.AddArrayParam<int64_t>(
              OH_NN_INT64,
              is_avg ? OH_NN_AVG_POOL_STRIDE : OH_NN_MAX_POOL_STRIDE,
              strides.data(), 2, s_param, error) ||
          !builder.AddArrayParam<int64_t>(
              OH_NN_INT64, is_avg ? OH_NN_AVG_POOL_PAD : OH_NN_MAX_POOL_PAD,
              pads.data(), 4, p_param, error) ||
          !builder.AddScalarParam<int8_t>(
              OH_NN_INT8,
              is_avg ? OH_NN_AVG_POOL_ACTIVATION_TYPE
                     : OH_NN_MAX_POOL_ACTIVATION_TYPE,
              OH_NN_FUSED_NONE, a_param, error)) {
        return false;
      }
      return builder.EmitOp(is_avg ? OH_NN_OPS_AVG_POOL : OH_NN_OPS_MAX_POOL,
                            op.inputs, {k_param, s_param, p_param, a_param},
                            op.outputs, error);
    }

    case NnrtOpType::kBatchNorm: {
      if (!check_arity(5, 5, 1)) {
        return false;
      }
      uint32_t eps_param = 0;
      if (!builder.AddScalarParam<float>(OH_NN_FLOAT32,
                                         OH_NN_BATCH_NORM_EPSILON, op.epsilon,
                                         eps_param, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_BATCH_NORM, op.inputs, {eps_param},
                            op.outputs, error);
    }

    case NnrtOpType::kLayerNorm: {
      if (!check_arity(3, 3, 1)) {
        return false;
      }
      uint32_t norm_axis = 0, eps_param = 0, param_axis = 0;
      const int32_t axis32 = static_cast<int32_t>(op.axis);
      if (!builder.AddScalarParam<int32_t>(
              OH_NN_INT32, OH_NN_LAYER_NORM_BEGIN_NORM_AXIS, axis32, norm_axis,
              error) ||
          !builder.AddScalarParam<float>(OH_NN_FLOAT32,
                                         OH_NN_LAYER_NORM_EPSILON, op.epsilon,
                                         eps_param, error) ||
          !builder.AddScalarParam<int32_t>(
              OH_NN_INT32, OH_NN_LAYER_NORM_BEGIN_PARAM_AXIS, axis32,
              param_axis, error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_LAYER_NORM, op.inputs,
                            {norm_axis, eps_param, param_axis}, op.outputs,
                            error);
    }

    case NnrtOpType::kInstanceNorm: {
      if (!check_arity(3, 3, 1)) {
        return false;
      }
      uint32_t eps_param = 0;
      if (!builder.AddScalarParam<float>(
              OH_NN_FLOAT32, OH_NN_INSTANCE_NORM_EPSILON, op.epsilon, eps_param,
              error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_INSTANCE_NORM, op.inputs, {eps_param},
                            op.outputs, error);
    }

    case NnrtOpType::kResample2d: {
      if (!check_arity(1, 1, 1)) {
        return false;
      }
      const auto& out_shape = spec.operands[op.outputs[0]].shape;
      if (out_shape.size() != 4) {
        error = "Resample2d requires a 4D output operand";
        return false;
      }
      const int32_t new_h = static_cast<int32_t>(out_shape[1]);
      const int32_t new_w = static_cast<int32_t>(out_shape[2]);
      uint32_t h_p = 0, w_p = 0, ratio_p = 0, mode_p = 0, excl_p = 0;
      if (!builder.AddScalarParam<int32_t>(
              OH_NN_INT32, OH_NN_RESIZE_BILINEAR_NEW_HEIGHT, new_h, h_p,
              error) ||
          !builder.AddScalarParam<int32_t>(
              OH_NN_INT32, OH_NN_RESIZE_BILINEAR_NEW_WIDTH, new_w, w_p,
              error) ||
          !builder.AddScalarParam<bool>(
              OH_NN_BOOL, OH_NN_RESIZE_BILINEAR_PRESERVE_ASPECT_RATIO, false,
              ratio_p, error) ||
          !builder.AddScalarParam<int32_t>(
              OH_NN_INT32, OH_NN_RESIZE_BILINEAR_COORDINATE_TRANSFORM_MODE, 0,
              mode_p, error) ||
          !builder.AddScalarParam<int64_t>(
              OH_NN_INT64, OH_NN_RESIZE_BILINEAR_EXCLUDE_OUTSIDE, 0, excl_p,
              error)) {
        return false;
      }
      return builder.EmitOp(OH_NN_OPS_RESIZE_BILINEAR, op.inputs,
                            {h_p, w_p, ratio_p, mode_p, excl_p}, op.outputs,
                            error);
    }
  }

  error = "Unsupported NNRt operation type";
  return false;
}

}  // namespace

std::unique_ptr<NnrtCompiledGraph> NnrtCompiledGraph::Create(
    const NnrtDevice& device,
    const NnrtGraphSpec& spec,
    std::string& error) {
  return Create(std::vector<NnrtDevice>{device}, spec, error);
}

std::unique_ptr<NnrtCompiledGraph> NnrtCompiledGraph::Create(
    const std::vector<NnrtDevice>& candidate_devices,
    const NnrtGraphSpec& spec,
    std::string& error) {
  if (candidate_devices.empty()) {
    error = "No candidate NNRt accelerator devices provided";
    return nullptr;
  }
  if (spec.operands.empty() || spec.input_operands.empty() ||
      spec.output_operands.empty() || spec.operations.empty()) {
    error = "NNRt graph specification must have operands, inputs, outputs, and operations";
    return nullptr;
  }

  std::vector<size_t> operand_bytes(spec.operands.size(), 0);
  for (size_t i = 0; i < spec.operands.size(); ++i) {
    if (!ValidateOperand(spec.operands[i], operand_bytes[i], error)) {
      return nullptr;
    }
  }
  for (uint32_t id : spec.input_operands) {
    if (id >= spec.operands.size() || !spec.operands[id].constant_data.empty()) {
      error = "Invalid NNRt graph input operand index";
      return nullptr;
    }
  }
  for (uint32_t id : spec.output_operands) {
    if (id >= spec.operands.size() || !spec.operands[id].constant_data.empty()) {
      error = "Invalid NNRt graph output operand index";
      return nullptr;
    }
  }

  const bool can_pad_to_4d = CanPadGraphTo4D(spec);
  std::ostringstream diag;

  for (const auto& device : candidate_devices) {
    OH_NN_DeviceType type = OH_NN_OTHERS;
    if (!Check(OH_NNDevice_GetType(device.id, &type), "GetType", error)) {
      return nullptr;
    }
    if (type != OH_NN_ACCELERATOR) {
      error = "Selected NNRt device is not an accelerator";
      return nullptr;
    }

    for (const auto& candidate : kFormatCandidates) {
      if (candidate.pad_to_4d && !can_pad_to_4d) {
        continue;
      }

      auto impl = std::make_unique<Impl>();
      impl->device = device;
      impl->model.reset(OH_NNModel_Construct());
      if (!impl->model) {
        error = "OH_NNModel_Construct failed";
        return nullptr;
      }

      GraphModelBuilder builder(impl->model.get(), impl->constant_pool,
                                candidate.format, candidate.pad_to_4d);
      for (size_t i = 0; i < spec.operands.size(); ++i) {
        uint32_t idx = 0;
        if (!builder.AddOperandTensor(spec.operands[i], idx, error)) {
          return nullptr;
        }
      }
      for (const auto& op : spec.operations) {
        if (!BuildOperation(builder, spec, op, candidate.pad_to_4d, error)) {
          return nullptr;
        }
      }

      std::vector<uint32_t> inputs = spec.input_operands;
      std::vector<uint32_t> outputs = spec.output_operands;
      const OH_NN_UInt32Array input_ids{
          inputs.data(), static_cast<uint32_t>(inputs.size())};
      const OH_NN_UInt32Array output_ids{
          outputs.data(), static_cast<uint32_t>(outputs.size())};
      if (!Check(OH_NNModel_SpecifyInputsAndOutputs(impl->model.get(),
                                                    &input_ids, &output_ids),
                 "SpecifyInputsAndOutputs", error) ||
          !Check(OH_NNModel_Finish(impl->model.get()), "Finish", error)) {
        return nullptr;
      }

      const bool* supported = nullptr;
      uint32_t op_count = 0;
      if (!Check(OH_NNModel_GetAvailableOperations(impl->model.get(), device.id,
                                                   &supported, &op_count),
                 "GetAvailableOperations", error)) {
        return nullptr;
      }
      bool all_supported =
          (supported != nullptr && op_count == builder.emitted_op_count() &&
           op_count > 0);
      if (all_supported) {
        for (uint32_t i = 0; i < op_count; ++i) {
          if (!supported[i]) {
            all_supported = false;
            break;
          }
        }
      }
      if (!all_supported) {
        diag << "[" << device.name << "#" << device.id << " "
             << candidate.label << ": op_count=" << op_count << "/"
             << builder.emitted_op_count() << " unsupported]";
        continue;
      }

      impl->compilation.reset(OH_NNCompilation_Construct(impl->model.get()));
      if (!impl->compilation) {
        error = "OH_NNCompilation_Construct failed";
        return nullptr;
      }
      if (!Check(OH_NNCompilation_SetDevice(impl->compilation.get(), device.id),
                 "SetDevice", error) ||
          !Check(OH_NNCompilation_EnableFloat16(impl->compilation.get(),
                                                spec.allow_fp16),
                 "EnableFloat16", error) ||
          !Check(OH_NNCompilation_Build(impl->compilation.get()), "Build",
                 error)) {
        return nullptr;
      }

      impl->executor.reset(OH_NNExecutor_Construct(impl->compilation.get()));
      if (!impl->executor) {
        error = "OH_NNExecutor_Construct failed";
        return nullptr;
      }

      impl->input_tensors.resize(spec.input_operands.size());
      impl->input_bytes.resize(spec.input_operands.size());
      for (size_t i = 0; i < spec.input_operands.size(); ++i) {
        const uint32_t op_id = spec.input_operands[i];
        const auto& op_spec = spec.operands[op_id];
        auto desc = MakeDescWithFormat(
            BuildDims(op_spec.shape, candidate.pad_to_4d),
            ToOhosDataType(op_spec.data_type), candidate.format, error);
        if (!desc) {
          return nullptr;
        }
        impl->input_tensors[i].reset(OH_NNTensor_Create(device.id, desc.get()));
        if (!impl->input_tensors[i]) {
          error = "OH_NNTensor_Create failed";
          return nullptr;
        }
        impl->input_bytes[i] = operand_bytes[op_id];
      }

      impl->output_tensors.resize(spec.output_operands.size());
      impl->output_bytes.resize(spec.output_operands.size());
      for (size_t i = 0; i < spec.output_operands.size(); ++i) {
        const uint32_t op_id = spec.output_operands[i];
        const auto& op_spec = spec.operands[op_id];
        auto desc = MakeDescWithFormat(
            BuildDims(op_spec.shape, candidate.pad_to_4d),
            ToOhosDataType(op_spec.data_type), candidate.format, error);
        if (!desc) {
          return nullptr;
        }
        impl->output_tensors[i].reset(
            OH_NNTensor_Create(device.id, desc.get()));
        if (!impl->output_tensors[i]) {
          error = "OH_NNTensor_Create failed";
          return nullptr;
        }
        impl->output_bytes[i] = operand_bytes[op_id];
      }

      return std::unique_ptr<NnrtCompiledGraph>(
          new NnrtCompiledGraph(std::move(impl)));
    }
  }

  error = "Selected accelerator does not support this WebNN graph " +
          diag.str();
  return nullptr;
}

NnrtCompiledGraph::NnrtCompiledGraph(std::unique_ptr<Impl> impl)
    : impl_(std::move(impl)) {}
NnrtCompiledGraph::~NnrtCompiledGraph() = default;

const NnrtDevice& NnrtCompiledGraph::device() const {
  return impl_->device;
}
size_t NnrtCompiledGraph::input_count() const {
  return impl_->input_tensors.size();
}
size_t NnrtCompiledGraph::output_count() const {
  return impl_->output_tensors.size();
}
size_t NnrtCompiledGraph::input_byte_length(size_t index) const {
  return index < impl_->input_bytes.size() ? impl_->input_bytes[index] : 0;
}
size_t NnrtCompiledGraph::output_byte_length(size_t index) const {
  return index < impl_->output_bytes.size() ? impl_->output_bytes[index] : 0;
}

bool NnrtCompiledGraph::Run(const std::vector<NnrtConstBufferView>& inputs,
                            const std::vector<NnrtBufferView>& outputs,
                            std::string& error) {
  if (inputs.size() != impl_->input_tensors.size() ||
      outputs.size() != impl_->output_tensors.size()) {
    error = "NNRt graph input/output count mismatch";
    return false;
  }
  for (size_t i = 0; i < inputs.size(); ++i) {
    if (!inputs[i].data || inputs[i].byte_length != impl_->input_bytes[i]) {
      error = "NNRt graph input buffer size mismatch";
      return false;
    }
  }
  for (size_t i = 0; i < outputs.size(); ++i) {
    if (!outputs[i].data || outputs[i].byte_length != impl_->output_bytes[i]) {
      error = "NNRt graph output buffer size mismatch";
      return false;
    }
  }

  std::vector<void*> in_buffers(inputs.size(), nullptr);
  std::vector<NN_Tensor*> in_ptrs(inputs.size(), nullptr);
  for (size_t i = 0; i < inputs.size(); ++i) {
    NN_Tensor* tensor = impl_->input_tensors[i].get();
    in_buffers[i] = OH_NNTensor_GetDataBuffer(tensor);
    size_t capacity = 0;
    size_t offset = 0;
    if (!in_buffers[i] ||
        !Check(OH_NNTensor_GetSize(tensor, &capacity), "GetSize", error) ||
        !Check(OH_NNTensor_GetOffset(tensor, &offset), "GetOffset", error) ||
        offset > capacity || impl_->input_bytes[i] > capacity - offset) {
      error = "Invalid NNRt input tensor buffer or capacity";
      return false;
    }
    in_ptrs[i] = tensor;
  }

  std::vector<void*> out_buffers(outputs.size(), nullptr);
  std::vector<NN_Tensor*> out_ptrs(outputs.size(), nullptr);
  for (size_t i = 0; i < outputs.size(); ++i) {
    NN_Tensor* tensor = impl_->output_tensors[i].get();
    out_buffers[i] = OH_NNTensor_GetDataBuffer(tensor);
    size_t capacity = 0;
    size_t offset = 0;
    if (!out_buffers[i] ||
        !Check(OH_NNTensor_GetSize(tensor, &capacity), "GetSize", error) ||
        !Check(OH_NNTensor_GetOffset(tensor, &offset), "GetOffset", error) ||
        offset > capacity || impl_->output_bytes[i] > capacity - offset) {
      error = "Invalid NNRt output tensor buffer or capacity";
      return false;
    }
    out_ptrs[i] = tensor;
  }

  for (size_t i = 0; i < inputs.size(); ++i) {
    std::memcpy(in_buffers[i], inputs[i].data, impl_->input_bytes[i]);
  }
  if (!Check(OH_NNExecutor_RunSync(
                 impl_->executor.get(), in_ptrs.data(),
                 static_cast<uint32_t>(in_ptrs.size()), out_ptrs.data(),
                 static_cast<uint32_t>(out_ptrs.size())),
             "RunSync", error)) {
    return false;
  }
  for (size_t i = 0; i < outputs.size(); ++i) {
    std::memcpy(outputs[i].data, out_buffers[i], impl_->output_bytes[i]);
  }
  return true;
}

bool NnrtAddModel::ValidateShape(const std::vector<uint32_t>& shape,
                                 size_t& bytes,
                                 std::string& error) {
  bytes = 0;
  if (shape.empty() || shape.size() > 4) {
    error = "NNRt Add prototype supports ranks 1 through 4";
    return false;
  }
  size_t size = sizeof(float);
  for (uint32_t dim : shape) {
    if (!dim ||
        dim > static_cast<uint32_t>(std::numeric_limits<int32_t>::max()) ||
        dim > kMaxTensorBytes / size) {
      error = "Invalid shape or tensor exceeds 4 MiB";
      return false;
    }
    size *= dim;
  }
  bytes = size;
  return true;
}

std::unique_ptr<NnrtAddModel> NnrtAddModel::Create(
    const NnrtDevice& device,
    const std::vector<uint32_t>& shape,
    std::string& error) {
  size_t bytes = 0;
  if (!ValidateShape(shape, bytes, error)) {
    return nullptr;
  }
  // Recheck the selected device, including callers of the standalone probe.
  OH_NN_DeviceType type = OH_NN_OTHERS;
  if (!Check(OH_NNDevice_GetType(device.id, &type), "GetType", error)) {
    return nullptr;
  }
  if (type != OH_NN_ACCELERATOR) {
    error = "Selected NNRt device is not an accelerator";
    return nullptr;
  }

  for (const auto& candidate : kFormatCandidates) {
    auto impl = std::make_unique<Impl>();
    impl->bytes = bytes;
    impl->model.reset(OH_NNModel_Construct());
    if (!impl->model) {
      error = "OH_NNModel_Construct failed";
      return nullptr;
    }
    const std::vector<int32_t> dims = BuildDims(shape, candidate.pad_to_4d);
    auto desc =
        MakeDescWithFormat(dims, OH_NN_FLOAT32, candidate.format, error);
    if (!desc) {
      return nullptr;
    }
    // Add input0 (0) and input1 (1), then activation parameter (2), then
    // output (3), matching the NNRt developer guide (inputs -> params ->
    // outputs).
    for (uint32_t i = 0; i < 2; ++i) {
      if (!Check(OH_NNModel_AddTensorToModel(impl->model.get(), desc.get()),
                 "AddTensorToModel", error) ||
          !Check(OH_NNModel_SetTensorType(impl->model.get(), i, OH_NN_TENSOR),
                 "SetTensorType", error)) {
        return nullptr;
      }
    }
    auto activation_desc = MakeDesc({1}, OH_NN_INT8, error);
    if (!activation_desc ||
        !Check(OH_NNModel_AddTensorToModel(impl->model.get(),
                                           activation_desc.get()),
               "Add activation tensor", error) ||
        !Check(OH_NNModel_SetTensorType(impl->model.get(), 2,
                                        OH_NN_ADD_ACTIVATIONTYPE),
               "Set activation type", error) ||
        !Check(OH_NNModel_SetTensorData(impl->model.get(), 2, &impl->activation,
                                        sizeof(impl->activation)),
               "Set activation value", error)) {
      return nullptr;
    }
    if (!Check(OH_NNModel_AddTensorToModel(impl->model.get(), desc.get()),
               "AddTensorToModel", error) ||
        !Check(OH_NNModel_SetTensorType(impl->model.get(), 3, OH_NN_TENSOR),
               "SetTensorType", error)) {
      return nullptr;
    }
    uint32_t inputs[] = {0, 1};
    uint32_t activation = 2;
    uint32_t output = 3;
    const OH_NN_UInt32Array input_ids{inputs, 2};
    const OH_NN_UInt32Array params{&activation, 1};
    const OH_NN_UInt32Array output_ids{&output, 1};
    if (!Check(OH_NNModel_AddOperation(impl->model.get(), OH_NN_OPS_ADD,
                                       &params, &input_ids, &output_ids),
               "AddOperation", error) ||
        !Check(OH_NNModel_SpecifyInputsAndOutputs(impl->model.get(), &input_ids,
                                                  &output_ids),
               "SpecifyInputsAndOutputs", error) ||
        !Check(OH_NNModel_Finish(impl->model.get()), "Finish", error)) {
      return nullptr;
    }
    const bool* supported = nullptr;
    uint32_t op_count = 0;
    if (!Check(OH_NNModel_GetAvailableOperations(impl->model.get(), device.id,
                                                 &supported, &op_count),
               "GetAvailableOperations", error)) {
      return nullptr;
    }
    if (!supported || op_count != 1 || !supported[0]) {
      continue;
    }
    impl->compilation.reset(OH_NNCompilation_Construct(impl->model.get()));
    if (!impl->compilation) {
      error = "OH_NNCompilation_Construct failed";
      return nullptr;
    }
    if (!Check(OH_NNCompilation_SetDevice(impl->compilation.get(), device.id),
               "SetDevice", error) ||
        !Check(OH_NNCompilation_EnableFloat16(impl->compilation.get(), false),
               "DisableFloat16", error) ||
        !Check(OH_NNCompilation_Build(impl->compilation.get()), "Build",
               error)) {
      return nullptr;
    }
    impl->executor.reset(OH_NNExecutor_Construct(impl->compilation.get()));
    if (!impl->executor) {
      error = "OH_NNExecutor_Construct failed";
      return nullptr;
    }
    for (auto& tensor : impl->tensors) {
      tensor.reset(OH_NNTensor_Create(device.id, desc.get()));
      if (!tensor) {
        error = "OH_NNTensor_Create failed";
        return nullptr;
      }
    }
    return std::unique_ptr<NnrtAddModel>(new NnrtAddModel(std::move(impl)));
  }

  error = "Selected accelerator does not support this float32 Add graph";
  return nullptr;
}

NnrtAddModel::NnrtAddModel(std::unique_ptr<Impl> impl)
    : impl_(std::move(impl)) {}
NnrtAddModel::~NnrtAddModel() = default;
size_t NnrtAddModel::byte_length() const {
  return impl_->bytes;
}

bool NnrtAddModel::Run(const void* lhs,
                       size_t lhs_size,
                       const void* rhs,
                       size_t rhs_size,
                       void* output,
                       size_t output_size,
                       std::string& error) {
  if (!lhs || !rhs || !output || lhs_size != impl_->bytes ||
      rhs_size != impl_->bytes || output_size != impl_->bytes) {
    error = "NNRt Add buffer size mismatch";
    return false;
  }
  std::array<void*, 3> buffers{};
  for (size_t i = 0; i < buffers.size(); ++i) {
    buffers[i] = OH_NNTensor_GetDataBuffer(impl_->tensors[i].get());
    size_t capacity = 0;
    size_t offset = 0;
    if (!buffers[i] ||
        !Check(OH_NNTensor_GetSize(impl_->tensors[i].get(), &capacity),
               "GetSize", error) ||
        !Check(OH_NNTensor_GetOffset(impl_->tensors[i].get(), &offset),
               "GetOffset", error) ||
        offset > capacity || impl_->bytes > capacity - offset) {
      error = "Invalid NNRt tensor buffer or capacity";
      return false;
    }
  }
  std::memcpy(buffers[0], lhs, impl_->bytes);
  std::memcpy(buffers[1], rhs, impl_->bytes);
  NN_Tensor* inputs[] = {impl_->tensors[0].get(), impl_->tensors[1].get()};
  NN_Tensor* outputs[] = {impl_->tensors[2].get()};
  if (!Check(
          OH_NNExecutor_RunSync(impl_->executor.get(), inputs, 2, outputs, 1),
          "RunSync", error)) {
    return false;
  }
  std::memcpy(output, buffers[2], impl_->bytes);
  return true;
}

}  // namespace webnn::ohos
