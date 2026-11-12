// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_WEBNN_OHOS_NNRT_ADD_MODEL_H_
#define SERVICES_WEBNN_OHOS_NNRT_ADD_MODEL_H_

#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace webnn::ohos {

// All NNRt calls, including model/executor destruction, must run on the same
// NNRt sequence. No silent CPU fallback is permitted for NPU contexts.
struct NnrtDevice {
  size_t id = 0;
  std::string name;
};

struct NnrtDeviceInfo {
  size_t id = 0;
  int32_t type = 0;
  std::string name;
};

// Enumerates all NNRt devices reported by the OS runtime (for diagnostics).
bool ListNnrtDevices(std::vector<NnrtDeviceInfo>& devices, std::string& error);

// Enumerates all dedicated hardware accelerators (OH_NN_ACCELERATOR).
bool FindNnrtAccelerators(std::vector<NnrtDevice>& devices, std::string& error);

// Selects the primary dedicated hardware accelerator (OH_NN_ACCELERATOR).
bool FindNnrtAccelerator(NnrtDevice& device, std::string& error);

enum class NnrtDataType {
  kFloat32,
  kFloat16,
  kInt32,
  kInt8,
  kUint8,
  kBool,
  kInt64,
};

struct NnrtOperandSpec {
  NnrtDataType data_type = NnrtDataType::kFloat32;
  // Empty shape represents a 0D scalar, which is mapped to {1} in NNRt.
  std::vector<uint32_t> shape;
  // Non-empty for constant operands (weights/biases).
  std::vector<uint8_t> constant_data;
};

enum class NnrtOpType {
  // Element-wise binary operations
  kAdd,
  kSub,
  kMul,
  kDiv,
  kMax,
  kMin,
  kPow,
  kEqual,
  kGreater,
  kGreaterEqual,
  kNotEqual,
  kLess,
  kLessEqual,
  kLogicalAnd,
  kLogicalOr,
  // Element-wise unary & cast operations
  kAbs,
  kCeil,
  kCos,
  kExp,
  kFloor,
  kLog,
  kNeg,
  kReciprocal,
  kRound,
  kSin,
  kSqrt,
  kTan,
  kErf,
  kLogicalNot,
  kCast,
  kIdentity,
  // Activations & parameterized element-wise operations
  kRelu,
  kLeakyRelu,
  kElu,
  kSigmoid,
  kTanh,
  kGelu,
  kHardSwish,
  kHardSigmoid,
  kSoftmax,
  kClamp,
  kLinear,
  kPrelu,
  kSoftplus,
  // Matrix & linear operations
  kMatmul,
  kGemm,
  // Convolution & 2D pooling operations
  kConv2d,
  kConvTranspose2d,
  kDepthwiseConv2d,
  kAvgPool2d,
  kMaxPool2d,
  // Tensor manipulation operations
  kReshape,
  kTranspose,
  kConcat,
  kSplit,
  kPad,
  kSlice,
  kExpand,
  kGather,
  kTile,
  kWhere,
  // Reduction & argMin/argMax operations
  kReduceMean,
  kReduceSum,
  kReduceMax,
  kReduceMin,
  kReduceProd,
  kReduceL2,
  kArgMax,
  kArgMin,
  // Normalization & resampling operations
  kLayerNorm,
  kBatchNorm,
  kInstanceNorm,
  kResample2d,
};

struct NnrtOpSpec {
  NnrtOpType type = NnrtOpType::kAdd;
  std::vector<uint32_t> inputs;
  std::vector<uint32_t> outputs;

  // Optional operator attributes
  float alpha = 1.0f;
  float beta = 0.0f;
  float clamp_min = 0.0f;
  float clamp_max = 0.0f;
  float epsilon = 1e-5f;
  float pad_value = 0.0f;
  int32_t pad_mode = 0;
  int64_t axis = 0;
  int64_t groups = 1;
  bool transpose_a = false;
  bool transpose_b = false;
  bool keep_dims = false;
  std::vector<int64_t> axes;
  std::vector<int32_t> permutation;
  std::vector<int32_t> padding;
  std::vector<int64_t> strides;
  std::vector<int64_t> dilations;
  std::vector<int64_t> kernel_size;
  std::vector<int64_t> slice_starts;
  std::vector<int64_t> slice_sizes;
  std::vector<int32_t> repeats;
};

struct NnrtGraphSpec {
  std::vector<NnrtOperandSpec> operands;
  std::vector<uint32_t> input_operands;
  std::vector<uint32_t> output_operands;
  std::vector<NnrtOpSpec> operations;
  bool allow_fp16 = false;
};

struct NnrtConstBufferView {
  const void* data = nullptr;
  size_t byte_length = 0;
};

struct NnrtBufferView {
  void* data = nullptr;
  size_t byte_length = 0;
};

class NnrtCompiledGraph {
 public:
  static constexpr size_t kMaxTensorBytes = 64 * 1024 * 1024;
  static constexpr size_t kMaxRank = 8;

  static size_t DataTypeByteSize(NnrtDataType type);
  static bool ValidateOperand(const NnrtOperandSpec& spec,
                              size_t& bytes,
                              std::string& error);

  // Compiles `spec` against the first accelerator in `candidate_devices` that
  // supports all operations in the graph (trying native format first, then
  // NCHW / 4D shape promotion when compatible).
  static std::unique_ptr<NnrtCompiledGraph> Create(
      const std::vector<NnrtDevice>& candidate_devices,
      const NnrtGraphSpec& spec,
      std::string& error);

  static std::unique_ptr<NnrtCompiledGraph> Create(
      const NnrtDevice& device,
      const NnrtGraphSpec& spec,
      std::string& error);

  ~NnrtCompiledGraph();
  NnrtCompiledGraph(const NnrtCompiledGraph&) = delete;
  NnrtCompiledGraph& operator=(const NnrtCompiledGraph&) = delete;

  const NnrtDevice& device() const;
  size_t input_count() const;
  size_t output_count() const;
  size_t input_byte_length(size_t index) const;
  size_t output_byte_length(size_t index) const;

  bool Run(const std::vector<NnrtConstBufferView>& inputs,
           const std::vector<NnrtBufferView>& outputs,
           std::string& error);

 private:
  struct Impl;
  explicit NnrtCompiledGraph(std::unique_ptr<Impl> impl);
  std::unique_ptr<Impl> impl_;
};

class NnrtAddModel {
 public:
  static constexpr size_t kMaxTensorBytes = 4 * 1024 * 1024;
  static bool ValidateShape(const std::vector<uint32_t>& shape,
                            size_t& bytes,
                            std::string& error);
  static std::unique_ptr<NnrtAddModel> Create(
      const NnrtDevice& device,
      const std::vector<uint32_t>& shape,
      std::string& error);
  ~NnrtAddModel();
  NnrtAddModel(const NnrtAddModel&) = delete;
  NnrtAddModel& operator=(const NnrtAddModel&) = delete;

  size_t byte_length() const;
  // Copies into/out of device tensors. Success is reported only after RunSync
  // succeeds. The output is untouched on failure. Buffers may alias.
  bool Run(const void* lhs,
           size_t lhs_size,
           const void* rhs,
           size_t rhs_size,
           void* output,
           size_t output_size,
           std::string& error);

 private:
  struct Impl;
  explicit NnrtAddModel(std::unique_ptr<Impl> impl);
  std::unique_ptr<Impl> impl_;
};

}  // namespace webnn::ohos
#endif  // SERVICES_WEBNN_OHOS_NNRT_ADD_MODEL_H_
