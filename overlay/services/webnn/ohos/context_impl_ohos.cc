// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "services/webnn/ohos/context_impl_ohos.h"

#include <sstream>
#include <utility>

#include "base/containers/heap_array.h"
#include "base/logging.h"
#include "base/no_destructor.h"
#include "base/notreached.h"
#include "base/task/thread_pool.h"
#include "base/trace_event/trace_event.h"
#include "services/webnn/gpu_task_scheduler.h"
#include "services/webnn/public/mojom/webnn_error.mojom.h"
#include "services/webnn/public/mojom/webnn_graph.mojom.h"
#include "services/webnn/public/mojom/webnn_service_introspection.mojom.h"
#include "services/webnn/webnn_constant_operand.h"

namespace webnn::ohos {

BASE_FEATURE(kOhosWebNN, base::FEATURE_DISABLED_BY_DEFAULT);

namespace {

ContextProperties GetProperties() {
  constexpr SupportedDataTypes kFloatTypes{OperandDataType::kFloat32,
                                           OperandDataType::kFloat16};
  constexpr SupportedDataTypes kFloatAndIntTypes{
      OperandDataType::kFloat32, OperandDataType::kFloat16,
      OperandDataType::kInt32, OperandDataType::kInt8,
      OperandDataType::kUint8};
  constexpr SupportedDataTypes kSignedTypes{OperandDataType::kFloat32,
                                            OperandDataType::kFloat16,
                                            OperandDataType::kInt32,
                                            OperandDataType::kInt8};
  constexpr SupportedDataTypes kIndicesTypes{OperandDataType::kInt32,
                                             OperandDataType::kInt64};
  constexpr SupportedDataTypes kUint8Only{OperandDataType::kUint8};

  constexpr SupportedRanks kUpTo8 = SupportedRanks::UpTo(8);
  constexpr SupportedRanks kNonScalarUpTo8 = SupportedRanks::NonScalarUpTo(8);
  constexpr SupportedRanks kAtLeast2D{2, 8};
  constexpr SupportedRanks kRank4 = SupportedRanks::Exactly(4);
  constexpr SupportedRanks kRank2 = SupportedRanks::Exactly(2);
  constexpr SupportedRanks kRank1 = SupportedRanks::Exactly(1);
  constexpr SupportedRanks kUpTo2 = SupportedRanks::UpTo(2);

  const SupportedTensors float_up_to_8{kFloatTypes, kUpTo8};
  const SupportedTensors float_non_scalar{kFloatTypes, kNonScalarUpTo8};
  const SupportedTensors all_up_to_8{kFloatAndIntTypes, kUpTo8};
  const SupportedTensors all_non_scalar{kFloatAndIntTypes, kNonScalarUpTo8};
  const SupportedTensors signed_up_to_8{kSignedTypes, kUpTo8};

  // Construct every limit explicitly: unsupported operations have empty sets.
  // Mojo's deserialization-only constructor must not be used here.
  DataTypeLimits limits(
      /*input=*/all_up_to_8,
      /*constant=*/all_up_to_8,
      /*arg_min_max_input=*/all_non_scalar,
      /*arg_min_max_output=*/{kIndicesTypes, kUpTo8},
      /*batch_normalization_input=*/float_non_scalar,
      /*batch_normalization_mean=*/{kFloatTypes, kRank1},
      /*cast_input=*/all_up_to_8,
      /*clamp_input=*/all_up_to_8,
      /*concat_inputs=*/all_non_scalar,
      /*conv2d_input=*/{kFloatTypes, kRank4},
      /*conv2d_bias=*/{kFloatTypes, kRank1},
      /*conv_transpose2d_input=*/{kFloatTypes, kRank4},
      /*conv_transpose2d_bias=*/{kFloatTypes, kRank1},
      /*cumulative_sum_input=*/{},
      /*dequantize_linear_input=*/{},
      /*dequantize_linear_scale=*/{},
      /*add_input=*/all_up_to_8,
      /*sub_input=*/all_up_to_8,
      /*mul_input=*/all_up_to_8,
      /*div_input=*/all_up_to_8,
      /*max_input=*/all_up_to_8,
      /*min_input=*/all_up_to_8,
      /*pow_input=*/float_up_to_8,
      /*equal_input=*/all_up_to_8,
      /*greater_input=*/all_up_to_8,
      /*greater_or_equal_input=*/all_up_to_8,
      /*lesser_input=*/all_up_to_8,
      /*lesser_or_equal_input=*/all_up_to_8,
      /*not_equal_input=*/all_up_to_8,
      /*logical_and_input=*/{kUint8Only, kUpTo8},
      /*logical_or_input=*/{kUint8Only, kUpTo8},
      /*logical_xor_input=*/{},
      /*logical_not_input=*/{kUint8Only, kUpTo8},
      /*is_nan_input=*/{},
      /*is_infinite_input=*/{},
      /*logical_output=*/kUint8Only,
      /*abs_input=*/signed_up_to_8,
      /*ceil_input=*/float_up_to_8,
      /*cos_input=*/float_up_to_8,
      /*erf_input=*/float_up_to_8,
      /*exp_input=*/float_up_to_8,
      /*floor_input=*/float_up_to_8,
      /*identity_input=*/all_up_to_8,
      /*log_input=*/float_up_to_8,
      /*neg_input=*/signed_up_to_8,
      /*reciprocal_input=*/float_up_to_8,
      /*round_even_input=*/float_up_to_8,
      /*sign_input=*/{},
      /*sin_input=*/float_up_to_8,
      /*sqrt_input=*/float_up_to_8,
      /*tan_input=*/float_up_to_8,
      /*elu_input=*/float_up_to_8,
      /*expand_input=*/all_up_to_8,
      /*gather_input=*/all_non_scalar,
      /*gather_indices=*/{kIndicesTypes, kUpTo8},
      /*gather_elements_input=*/{},
      /*gather_elements_indices=*/{},
      /*gather_nd_input=*/{},
      /*gather_nd_indices=*/{},
      /*gelu_input=*/float_up_to_8,
      /*gemm_a=*/{kFloatTypes, kRank2},
      /*gemm_c=*/{kFloatTypes, kUpTo2},
      /*gru_input=*/{},
      /*gru_bias=*/{},
      /*gru_output_sequence=*/{},
      /*gru_cell_input=*/{},
      /*gru_cell_bias=*/{},
      /*hard_sigmoid_input=*/float_up_to_8,
      /*hard_swish_input=*/float_up_to_8,
      /*instance_normalization_input=*/{kFloatTypes, kRank4},
      /*instance_normalization_scale=*/{kFloatTypes, kRank1},
      /*layer_normalization_input=*/float_up_to_8,
      /*leaky_relu_input=*/float_up_to_8,
      /*linear_input=*/float_up_to_8,
      /*lstm_input=*/{},
      /*lstm_bias=*/{},
      /*lstm_output_sequence=*/{},
      /*lstm_cell_input=*/{},
      /*lstm_cell_bias=*/{},
      /*matmul_input=*/{kFloatTypes, kAtLeast2D},
      /*pad_input=*/float_non_scalar,
      /*average_pool2d_input=*/{kFloatTypes, kRank4},
      /*l2_pool2d_input=*/{},
      /*max_pool2d_input=*/{kFloatAndIntTypes, kRank4},
      /*prelu_input=*/signed_up_to_8,
      /*quantize_linear_input=*/{},
      /*quantize_linear_zero_point=*/{},
      /*reduce_l1_input=*/{},
      /*reduce_l2_input=*/float_up_to_8,
      /*reduce_log_sum_input=*/{},
      /*reduce_log_sum_exp_input=*/{},
      /*reduce_max_input=*/all_up_to_8,
      /*reduce_mean_input=*/float_up_to_8,
      /*reduce_min_input=*/all_up_to_8,
      /*reduce_product_input=*/signed_up_to_8,
      /*reduce_sum_input=*/signed_up_to_8,
      /*reduce_sum_square_input=*/{},
      /*relu_input=*/signed_up_to_8,
      /*resample2d_input=*/{kFloatTypes, kRank4},
      /*reshape_input=*/all_up_to_8,
      /*reverse_input=*/{},
      /*scatter_elements_input=*/{},
      /*scatter_elements_indices=*/{},
      /*scatter_nd_input=*/{},
      /*scatter_nd_indices=*/{},
      /*scatter_nd_updates=*/{},
      /*sigmoid_input=*/float_up_to_8,
      /*slice_input=*/all_non_scalar,
      /*softmax_input=*/float_non_scalar,
      /*softplus_input=*/float_up_to_8,
      /*softsign_input=*/{},
      /*split_input=*/all_non_scalar,
      /*tanh_input=*/float_up_to_8,
      /*tile_input=*/all_non_scalar,
      /*transpose_input=*/all_non_scalar,
      /*triangular_input=*/{},
      /*where_condition=*/{kUint8Only, kUpTo8},
      /*where_value=*/all_up_to_8);
  return ContextProperties(InputOperandLayout::kNchw, Resample2DAxes::kAny,
                           BatchNormalizationAxis::kAny,
                           NnrtCompiledGraph::kMaxTensorBytes,
                           std::move(limits));
}

mojom::ErrorPtr NotSupported(const std::string& message) {
  return mojom::Error::New(mojom::Error::Code::kNotSupportedError, message);
}

bool ConvertDataType(OperandDataType in,
                     NnrtDataType& out,
                     std::string& error) {
  switch (in) {
    case OperandDataType::kFloat32:
      out = NnrtDataType::kFloat32;
      return true;
    case OperandDataType::kFloat16:
      out = NnrtDataType::kFloat16;
      return true;
    case OperandDataType::kInt32:
      out = NnrtDataType::kInt32;
      return true;
    case OperandDataType::kInt8:
      out = NnrtDataType::kInt8;
      return true;
    case OperandDataType::kUint8:
      out = NnrtDataType::kUint8;
      return true;
    case OperandDataType::kInt64:
      out = NnrtDataType::kInt64;
      return true;
    default:
      error = "Unsupported WebNN operand data type for OHOS NNRt";
      return false;
  }
}

float NumberToFloat(const mojom::Number& num) {
  if (num.is_floating_point()) {
    return static_cast<float>(num.get_floating_point());
  }
  if (num.is_signed_integer()) {
    return static_cast<float>(num.get_signed_integer());
  }
  if (num.is_unsigned_integer()) {
    return static_cast<float>(num.get_unsigned_integer());
  }
  return 0.0f;
}

bool TranslateOperation(const mojom::Operation& mojom_op,
                        NnrtOpSpec& out_op,
                        std::string& error) {
  using Tag = mojom::Operation::Tag;
  switch (mojom_op.which()) {
    case Tag::kElementWiseBinary: {
      const auto& bin = *mojom_op.get_element_wise_binary();
      out_op.inputs = {bin.lhs_operand_id.value(), bin.rhs_operand_id.value()};
      out_op.outputs = {bin.output_operand_id.value()};
      switch (bin.kind) {
        case mojom::ElementWiseBinary::Kind::kAdd:
          out_op.type = NnrtOpType::kAdd;
          return true;
        case mojom::ElementWiseBinary::Kind::kSub:
          out_op.type = NnrtOpType::kSub;
          return true;
        case mojom::ElementWiseBinary::Kind::kMul:
          out_op.type = NnrtOpType::kMul;
          return true;
        case mojom::ElementWiseBinary::Kind::kDiv:
          out_op.type = NnrtOpType::kDiv;
          return true;
        case mojom::ElementWiseBinary::Kind::kMax:
          out_op.type = NnrtOpType::kMax;
          return true;
        case mojom::ElementWiseBinary::Kind::kMin:
          out_op.type = NnrtOpType::kMin;
          return true;
        case mojom::ElementWiseBinary::Kind::kPow:
          out_op.type = NnrtOpType::kPow;
          return true;
        case mojom::ElementWiseBinary::Kind::kEqual:
          out_op.type = NnrtOpType::kEqual;
          return true;
        case mojom::ElementWiseBinary::Kind::kGreater:
          out_op.type = NnrtOpType::kGreater;
          return true;
        case mojom::ElementWiseBinary::Kind::kGreaterOrEqual:
          out_op.type = NnrtOpType::kGreaterEqual;
          return true;
        case mojom::ElementWiseBinary::Kind::kLesser:
          out_op.type = NnrtOpType::kLess;
          return true;
        case mojom::ElementWiseBinary::Kind::kLesserOrEqual:
          out_op.type = NnrtOpType::kLessEqual;
          return true;
        case mojom::ElementWiseBinary::Kind::kNotEqual:
          out_op.type = NnrtOpType::kNotEqual;
          return true;
        case mojom::ElementWiseBinary::Kind::kLogicalAnd:
          out_op.type = NnrtOpType::kLogicalAnd;
          return true;
        case mojom::ElementWiseBinary::Kind::kLogicalOr:
          out_op.type = NnrtOpType::kLogicalOr;
          return true;
        default:
          error = "Unsupported ElementWiseBinary kind on OHOS NNRt";
          return false;
      }
    }

    case Tag::kElementWiseUnary: {
      const auto& un = *mojom_op.get_element_wise_unary();
      out_op.inputs = {un.input_operand_id.value()};
      out_op.outputs = {un.output_operand_id.value()};
      switch (un.kind) {
        case mojom::ElementWiseUnary::Kind::kAbs:
          out_op.type = NnrtOpType::kAbs;
          return true;
        case mojom::ElementWiseUnary::Kind::kCeil:
          out_op.type = NnrtOpType::kCeil;
          return true;
        case mojom::ElementWiseUnary::Kind::kCos:
          out_op.type = NnrtOpType::kCos;
          return true;
        case mojom::ElementWiseUnary::Kind::kErf:
          out_op.type = NnrtOpType::kErf;
          return true;
        case mojom::ElementWiseUnary::Kind::kExp:
          out_op.type = NnrtOpType::kExp;
          return true;
        case mojom::ElementWiseUnary::Kind::kFloor:
          out_op.type = NnrtOpType::kFloor;
          return true;
        case mojom::ElementWiseUnary::Kind::kIdentity:
          out_op.type = NnrtOpType::kIdentity;
          return true;
        case mojom::ElementWiseUnary::Kind::kLog:
          out_op.type = NnrtOpType::kLog;
          return true;
        case mojom::ElementWiseUnary::Kind::kLogicalNot:
          out_op.type = NnrtOpType::kLogicalNot;
          return true;
        case mojom::ElementWiseUnary::Kind::kNeg:
          out_op.type = NnrtOpType::kNeg;
          return true;
        case mojom::ElementWiseUnary::Kind::kReciprocal:
          out_op.type = NnrtOpType::kReciprocal;
          return true;
        case mojom::ElementWiseUnary::Kind::kRoundEven:
          out_op.type = NnrtOpType::kRound;
          return true;
        case mojom::ElementWiseUnary::Kind::kSin:
          out_op.type = NnrtOpType::kSin;
          return true;
        case mojom::ElementWiseUnary::Kind::kSqrt:
          out_op.type = NnrtOpType::kSqrt;
          return true;
        case mojom::ElementWiseUnary::Kind::kTan:
          out_op.type = NnrtOpType::kTan;
          return true;
        case mojom::ElementWiseUnary::Kind::kCast:
          out_op.type = NnrtOpType::kCast;
          return true;
        default:
          error = "Unsupported ElementWiseUnary kind on OHOS NNRt";
          return false;
      }
    }

    case Tag::kRelu: {
      const auto& op = *mojom_op.get_relu();
      out_op.type = NnrtOpType::kRelu;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      return true;
    }

    case Tag::kSigmoid: {
      const auto& op = *mojom_op.get_sigmoid();
      out_op.type = NnrtOpType::kSigmoid;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      return true;
    }

    case Tag::kTanh: {
      const auto& op = *mojom_op.get_tanh();
      out_op.type = NnrtOpType::kTanh;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      return true;
    }

    case Tag::kGelu: {
      const auto& op = *mojom_op.get_gelu();
      out_op.type = NnrtOpType::kGelu;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      return true;
    }

    case Tag::kHardSwish: {
      const auto& op = *mojom_op.get_hard_swish();
      out_op.type = NnrtOpType::kHardSwish;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      return true;
    }

    case Tag::kHardSigmoid: {
      const auto& op = *mojom_op.get_hard_sigmoid();
      out_op.type = NnrtOpType::kHardSigmoid;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      out_op.alpha = op.alpha;
      out_op.beta = op.beta;
      return true;
    }

    case Tag::kLeakyRelu: {
      const auto& op = *mojom_op.get_leaky_relu();
      out_op.type = NnrtOpType::kLeakyRelu;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      out_op.alpha = op.alpha;
      return true;
    }

    case Tag::kElu: {
      const auto& op = *mojom_op.get_elu();
      out_op.type = NnrtOpType::kElu;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      out_op.alpha = op.alpha;
      return true;
    }

    case Tag::kSoftplus: {
      const auto& op = *mojom_op.get_softplus();
      out_op.type = NnrtOpType::kSoftplus;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      return true;
    }

    case Tag::kLinear: {
      const auto& op = *mojom_op.get_linear();
      out_op.type = NnrtOpType::kLinear;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      out_op.alpha = op.alpha;
      out_op.beta = op.beta;
      return true;
    }

    case Tag::kPrelu: {
      const auto& op = *mojom_op.get_prelu();
      out_op.type = NnrtOpType::kPrelu;
      out_op.inputs = {op.input_operand_id.value(),
                       op.slope_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      return true;
    }

    case Tag::kClamp: {
      const auto& op = *mojom_op.get_clamp();
      out_op.type = NnrtOpType::kClamp;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      out_op.clamp_min = NumberToFloat(*op.min_value);
      out_op.clamp_max = NumberToFloat(*op.max_value);
      return true;
    }

    case Tag::kSoftmax: {
      const auto& op = *mojom_op.get_softmax();
      out_op.type = NnrtOpType::kSoftmax;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      out_op.axis = static_cast<int64_t>(op.axis);
      return true;
    }

    case Tag::kMatmul: {
      const auto& op = *mojom_op.get_matmul();
      out_op.type = NnrtOpType::kMatmul;
      out_op.inputs = {op.a_operand_id.value(), op.b_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      return true;
    }

    case Tag::kGemm: {
      const auto& op = *mojom_op.get_gemm();
      out_op.type = NnrtOpType::kGemm;
      out_op.inputs = {op.a_operand_id.value(), op.b_operand_id.value()};
      if (op.c_operand_id.has_value()) {
        out_op.inputs.push_back(op.c_operand_id->value());
      }
      out_op.outputs = {op.output_operand_id.value()};
      out_op.alpha = op.alpha;
      out_op.beta = op.beta;
      out_op.transpose_a = op.a_transpose;
      out_op.transpose_b = op.b_transpose;
      return true;
    }

    case Tag::kReshape: {
      const auto& op = *mojom_op.get_reshape();
      out_op.type = NnrtOpType::kReshape;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      return true;
    }

    case Tag::kTranspose: {
      const auto& op = *mojom_op.get_transpose();
      out_op.type = NnrtOpType::kTranspose;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      out_op.permutation.assign(op.permutation.begin(), op.permutation.end());
      return true;
    }

    case Tag::kConcat: {
      const auto& op = *mojom_op.get_concat();
      out_op.type = NnrtOpType::kConcat;
      for (const auto& id : op.input_operand_ids) {
        out_op.inputs.push_back(id.value());
      }
      out_op.outputs = {op.output_operand_id.value()};
      out_op.axis = static_cast<int64_t>(op.axis);
      return true;
    }

    case Tag::kSplit: {
      const auto& op = *mojom_op.get_split();
      out_op.type = NnrtOpType::kSplit;
      out_op.inputs = {op.input_operand_id.value()};
      for (const auto& id : op.output_operand_ids) {
        out_op.outputs.push_back(id.value());
      }
      out_op.axis = static_cast<int64_t>(op.axis);
      return true;
    }

    case Tag::kExpand: {
      const auto& op = *mojom_op.get_expand();
      out_op.type = NnrtOpType::kExpand;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      return true;
    }

    case Tag::kGather: {
      const auto& op = *mojom_op.get_gather();
      out_op.type = NnrtOpType::kGather;
      out_op.inputs = {op.input_operand_id.value(),
                       op.indices_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      out_op.axis = static_cast<int64_t>(op.axis);
      return true;
    }

    case Tag::kTile: {
      const auto& op = *mojom_op.get_tile();
      out_op.type = NnrtOpType::kTile;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      out_op.repeats.assign(op.repetitions.begin(), op.repetitions.end());
      return true;
    }

    case Tag::kWhere: {
      const auto& op = *mojom_op.get_where();
      out_op.type = NnrtOpType::kWhere;
      out_op.inputs = {op.condition_operand_id.value(),
                       op.true_value_operand_id.value(),
                       op.false_value_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      return true;
    }

    case Tag::kPad: {
      const auto& op = *mojom_op.get_pad();
      if (op.beginning_padding.size() != op.ending_padding.size()) {
        error = "Pad beginning and ending padding lengths mismatch";
        return false;
      }
      out_op.type = NnrtOpType::kPad;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      for (size_t i = 0; i < op.beginning_padding.size(); ++i) {
        out_op.padding.push_back(static_cast<int32_t>(op.beginning_padding[i]));
        out_op.padding.push_back(static_cast<int32_t>(op.ending_padding[i]));
      }
      if (op.mode->is_constant()) {
        out_op.pad_mode = 0;
        out_op.pad_value = NumberToFloat(*op.mode->get_constant()->value);
      } else if (op.mode->is_reflection()) {
        out_op.pad_mode = 1;
      } else if (op.mode->is_edge()) {
        out_op.pad_mode = 2;
      }
      return true;
    }

    case Tag::kSlice: {
      const auto& op = *mojom_op.get_slice();
      out_op.type = NnrtOpType::kSlice;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      for (const auto& range : op.ranges) {
        if (range->stride != 1) {
          error = "OHOS NNRt Slice currently requires unit stride";
          return false;
        }
        out_op.slice_starts.push_back(static_cast<int64_t>(range->start));
        out_op.slice_sizes.push_back(static_cast<int64_t>(range->size));
      }
      return true;
    }

    case Tag::kReduce: {
      const auto& op = *mojom_op.get_reduce();
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      out_op.keep_dims = op.keep_dimensions;
      out_op.axes.assign(op.axes.begin(), op.axes.end());
      switch (op.kind) {
        case mojom::Reduce::Kind::kMean:
          out_op.type = NnrtOpType::kReduceMean;
          return true;
        case mojom::Reduce::Kind::kSum:
          out_op.type = NnrtOpType::kReduceSum;
          return true;
        case mojom::Reduce::Kind::kMax:
          out_op.type = NnrtOpType::kReduceMax;
          return true;
        case mojom::Reduce::Kind::kMin:
          out_op.type = NnrtOpType::kReduceMin;
          return true;
        case mojom::Reduce::Kind::kProduct:
          out_op.type = NnrtOpType::kReduceProd;
          return true;
        case mojom::Reduce::Kind::kL2:
          out_op.type = NnrtOpType::kReduceL2;
          return true;
        default:
          error = "Unsupported Reduce kind on OHOS NNRt";
          return false;
      }
    }

    case Tag::kArgMinMax: {
      const auto& op = *mojom_op.get_arg_min_max();
      out_op.type = (op.kind == mojom::ArgMinMax::Kind::kMax)
                        ? NnrtOpType::kArgMax
                        : NnrtOpType::kArgMin;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      out_op.axis = static_cast<int64_t>(op.axis);
      out_op.keep_dims = op.keep_dimensions;
      return true;
    }

    case Tag::kConv2d: {
      const auto& op = *mojom_op.get_conv2d();
      out_op.type = (op.kind == mojom::Conv2d::Kind::kTransposed)
                        ? NnrtOpType::kConvTranspose2d
                        : NnrtOpType::kConv2d;
      out_op.inputs = {op.input_operand_id.value(),
                       op.filter_operand_id.value()};
      if (op.bias_operand_id.has_value()) {
        out_op.inputs.push_back(op.bias_operand_id->value());
      }
      out_op.outputs = {op.output_operand_id.value()};
      out_op.strides = {static_cast<int64_t>(op.strides->height),
                        static_cast<int64_t>(op.strides->width)};
      out_op.dilations = {static_cast<int64_t>(op.dilations->height),
                          static_cast<int64_t>(op.dilations->width)};
      out_op.padding = {
          static_cast<int32_t>(op.padding->beginning->height),
          static_cast<int32_t>(op.padding->ending->height),
          static_cast<int32_t>(op.padding->beginning->width),
          static_cast<int32_t>(op.padding->ending->width),
      };
      out_op.groups = static_cast<int64_t>(op.groups);
      return true;
    }

    case Tag::kPool2d: {
      const auto& op = *mojom_op.get_pool2d();
      if (op.kind == mojom::Pool2d::Kind::kAveragePool2d) {
        out_op.type = NnrtOpType::kAvgPool2d;
      } else if (op.kind == mojom::Pool2d::Kind::kMaxPool2d) {
        out_op.type = NnrtOpType::kMaxPool2d;
      } else {
        error = "Unsupported Pool2d kind on OHOS NNRt";
        return false;
      }
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      out_op.kernel_size = {static_cast<int64_t>(op.window_dimensions->height),
                            static_cast<int64_t>(op.window_dimensions->width)};
      out_op.strides = {static_cast<int64_t>(op.strides->height),
                        static_cast<int64_t>(op.strides->width)};
      out_op.dilations = {static_cast<int64_t>(op.dilations->height),
                          static_cast<int64_t>(op.dilations->width)};
      out_op.padding = {
          static_cast<int32_t>(op.padding->beginning->height),
          static_cast<int32_t>(op.padding->ending->height),
          static_cast<int32_t>(op.padding->beginning->width),
          static_cast<int32_t>(op.padding->ending->width),
      };
      return true;
    }

    case Tag::kBatchNormalization: {
      const auto& op = *mojom_op.get_batch_normalization();
      if (!op.scale_operand_id.has_value() || !op.bias_operand_id.has_value()) {
        error = "OHOS NNRt BatchNormalization requires scale and bias operands";
        return false;
      }
      out_op.type = NnrtOpType::kBatchNorm;
      out_op.inputs = {
          op.input_operand_id.value(), op.scale_operand_id->value(),
          op.bias_operand_id->value(), op.mean_operand_id.value(),
          op.variance_operand_id.value(),
      };
      out_op.outputs = {op.output_operand_id.value()};
      out_op.epsilon = op.epsilon;
      out_op.axis = static_cast<int64_t>(op.axis);
      return true;
    }

    case Tag::kLayerNormalization: {
      const auto& op = *mojom_op.get_layer_normalization();
      if (!op.scale_operand_id.has_value() || !op.bias_operand_id.has_value()) {
        error = "OHOS NNRt LayerNormalization requires scale and bias operands";
        return false;
      }
      out_op.type = NnrtOpType::kLayerNorm;
      out_op.inputs = {op.input_operand_id.value(),
                       op.scale_operand_id->value(),
                       op.bias_operand_id->value()};
      out_op.outputs = {op.output_operand_id.value()};
      out_op.epsilon = op.epsilon;
      out_op.axis =
          op.axes.empty() ? 1 : static_cast<int64_t>(op.axes.front());
      return true;
    }

    case Tag::kInstanceNormalization: {
      const auto& op = *mojom_op.get_instance_normalization();
      if (!op.scale_operand_id.has_value() || !op.bias_operand_id.has_value()) {
        error =
            "OHOS NNRt InstanceNormalization requires scale and bias operands";
        return false;
      }
      out_op.type = NnrtOpType::kInstanceNorm;
      out_op.inputs = {op.input_operand_id.value(),
                       op.scale_operand_id->value(),
                       op.bias_operand_id->value()};
      out_op.outputs = {op.output_operand_id.value()};
      out_op.epsilon = op.epsilon;
      return true;
    }

    case Tag::kResample2d: {
      const auto& op = *mojom_op.get_resample2d();
      out_op.type = NnrtOpType::kResample2d;
      out_op.inputs = {op.input_operand_id.value()};
      out_op.outputs = {op.output_operand_id.value()};
      return true;
    }

    default:
      error = "Unsupported WebNN operation on OHOS NNRt";
      return false;
  }
}

class TensorImplOhos final : public WebNNTensorImpl {
 public:
  TensorImplOhos(mojo::PendingAssociatedReceiver<mojom::WebNNTensor> receiver,
                 WebNNContextImpl& context,
                 mojom::TensorInfoPtr info)
      : WebNNTensorImpl(std::move(receiver), context, std::move(info)),
        data_(base::HeapArray<uint8_t>::WithSize(PackedByteLength())) {}

  base::span<uint8_t> data() { return data_.as_span(); }
  void WriteTensorImpl(mojo_base::BigBuffer buffer) override {
    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
    if (!static_cast<ContextImplOhos&>(*context_).execution_failed()) {
      context_->ReadDataFromBigBufferOrDataPipe(std::move(buffer), data());
    }
  }

 private:
  ~TensorImplOhos() override = default;
  void ReadTensorImpl(ReadTensorCallback callback) override {
    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
    if (static_cast<ContextImplOhos&>(*context_).execution_failed()) {
      std::move(callback).Run(mojom::ReadTensorResult::NewError(
          mojom::Error::New(mojom::Error::Code::kUnknownError,
                            "NNRt context lost after execution failure")));
      return;
    }
    std::move(callback).Run(mojom::ReadTensorResult::NewBuffer(
        context_->WriteDataToDataPipeOrBigBuffer(data())));
  }
  bool ImportTensorImpl(ScopedAccessPtr access) override { return false; }
  void ExportTensorImpl(ScopedAccessPtr access) override { NOTREACHED(); }
  base::HeapArray<uint8_t> data_;
};

class GraphImplOhos final : public WebNNGraphImpl {
 public:
  GraphImplOhos(WebNNContextImpl& context,
                ComputeResourceInfo resources,
                std::unique_ptr<NnrtCompiledGraph> graph,
                std::vector<std::string> input_names,
                std::vector<std::string> output_names)
      : WebNNGraphImpl(context, std::move(resources), {mojom::Device::kNpu}),
        graph_(std::move(graph)),
        input_names_(std::move(input_names)),
        output_names_(std::move(output_names)) {}

 private:
  ~GraphImplOhos() override = default;
  void DispatchImpl(
      base::flat_map<std::string, scoped_refptr<WebNNTensorImpl>> inputs,
      base::flat_map<std::string, scoped_refptr<WebNNTensorImpl>> outputs)
      override {
    if (static_cast<ContextImplOhos&>(*context_).execution_failed()) {
      return;
    }
    TRACE_EVENT("webnn", "OhosWebNNDispatch");
    std::vector<NnrtConstBufferView> in_views;
    in_views.reserve(input_names_.size());
    size_t total_bytes = 0;
    for (const auto& name : input_names_) {
      auto span = static_cast<TensorImplOhos*>(inputs.at(name).get())->data();
      in_views.push_back({span.data(), span.size()});
      total_bytes += span.size();
    }

    std::vector<NnrtBufferView> out_views;
    out_views.reserve(output_names_.size());
    for (const auto& name : output_names_) {
      auto span = static_cast<TensorImplOhos*>(outputs.at(name).get())->data();
      out_views.push_back({span.data(), span.size()});
      total_bytes += span.size();
    }

    std::string error;
    if (!graph_->Run(in_views, out_views, error)) {
      LOG(ERROR) << "OhosWebNN execution failed: " << error;
      // Never resolve a later read with a stale result after device failure.
      // OnLost schedules context removal; do not touch this graph afterwards.
      static_cast<ContextImplOhos&>(*context_).FailExecution(error);
      return;
    }
    TRACE_EVENT_INSTANT("webnn", "OhosWebNNExecutionCompleted", "tensor_bytes",
                        total_bytes);
  }

  std::unique_ptr<NnrtCompiledGraph> graph_;
  const std::vector<std::string> input_names_;
  const std::vector<std::string> output_names_;
};

}  // namespace

scoped_refptr<base::SingleThreadTaskRunner>
ContextImplOhos::GetNnrtTaskRunner() {
  static const base::NoDestructor<scoped_refptr<base::SingleThreadTaskRunner>>
      runner(base::ThreadPool::CreateSingleThreadTaskRunner(
          {base::MayBlock(), base::TaskPriority::USER_VISIBLE,
           base::TaskShutdownBehavior::SKIP_ON_SHUTDOWN},
          base::SingleThreadTaskRunnerThreadMode::DEDICATED));
  return *runner;
}

WebNNContextImpl::WebNNContextImplPtr ContextImplOhos::Create(
    mojo::PendingReceiver<mojom::WebNNContext> receiver,
    base::WeakPtr<WebNNContextProviderImpl> context_provider,
    mojom::CreateContextOptionsPtr options,
    std::unique_ptr<GpuTaskScheduler> gpu_task_scheduler,
    scoped_refptr<gpu::MemoryTracker> memory_tracker,
    scoped_refptr<base::SingleThreadTaskRunner> owning_task_runner,
    gpu::SharedImageManager* shared_image_manager,
    scoped_refptr<base::SingleThreadTaskRunner> main_task_runner) {
  CHECK(owning_task_runner->RunsTasksInCurrentSequence());

  std::vector<NnrtDeviceInfo> all_devices;
  std::string diag_error;
  if (ListNnrtDevices(all_devices, diag_error)) {
    std::ostringstream inventory;
    for (size_t i = 0; i < all_devices.size(); ++i) {
      if (i > 0) {
        inventory << ", ";
      }
      inventory << "[" << i << "] id=" << all_devices[i].id
                << " type=" << all_devices[i].type
                << " name=" << all_devices[i].name;
    }
    LOG(WARNING) << "OhosWebNN NNRt device inventory (" << all_devices.size()
                 << "): " << inventory.str();
  }

  std::vector<NnrtDevice> devices;
  std::string error;
  if (options->device != mojom::Device::kNpu ||
      !FindNnrtAccelerators(devices, error)) {
    LOG(ERROR) << "OhosWebNN unavailable: " << error;
    return WebNNContextImplPtr(nullptr,
                               OnTaskRunnerDeleter(owning_task_runner));
  }
  LOG(WARNING) << "OhosWebNN selected primary accelerator id="
               << devices.front().id << " name=" << devices.front().name
               << " (candidate_accelerators=" << devices.size() << ")";
  TRACE_EVENT_INSTANT("webnn", "OhosWebNNDeviceSelected", "device_id",
                      devices.front().id);
  auto deleter = OnTaskRunnerDeleter(owning_task_runner);
  return WebNNContextImplPtr(
      new ContextImplOhos(std::move(receiver), std::move(context_provider),
                          std::move(options), std::move(gpu_task_scheduler),
                          std::move(memory_tracker),
                          std::move(owning_task_runner), shared_image_manager,
                          std::move(main_task_runner), std::move(devices)),
      std::move(deleter));
}

ContextImplOhos::ContextImplOhos(
    mojo::PendingReceiver<mojom::WebNNContext> receiver,
    base::WeakPtr<WebNNContextProviderImpl> context_provider,
    mojom::CreateContextOptionsPtr options,
    std::unique_ptr<GpuTaskScheduler> gpu_task_scheduler,
    scoped_refptr<gpu::MemoryTracker> memory_tracker,
    scoped_refptr<base::SingleThreadTaskRunner> owning_task_runner,
    gpu::SharedImageManager* shared_image_manager,
    scoped_refptr<base::SingleThreadTaskRunner> main_task_runner,
    std::vector<NnrtDevice> devices)
    : WebNNContextImpl(std::move(receiver),
                       std::move(context_provider),
                       ContextBackendUma::kOhosNnrt,
                       GetProperties(),
                       std::move(options),
                       mojo::ScopedDataPipeConsumerHandle(),
                       mojo::ScopedDataPipeProducerHandle(),
                       std::move(gpu_task_scheduler),
                       std::move(memory_tracker),
                       std::move(owning_task_runner),
                       shared_image_manager,
                       std::move(main_task_runner)),
      devices_(std::move(devices)) {}

ContextImplOhos::~ContextImplOhos() = default;
void ContextImplOhos::FailExecution(const std::string& reason) {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  execution_failed_ = true;
  OnLost(reason);
}
base::WeakPtr<WebNNContextImpl> ContextImplOhos::AsWeakPtr() {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  return weak_factory_.GetWeakPtr();
}

void ContextImplOhos::CreateGraphImpl(
    mojom::GraphInfoPtr info,
    WebNNGraphImpl::ComputeResourceInfo resources,
    base::flat_map<OperandId, std::unique_ptr<WebNNConstantOperand>> constants,
    CreateGraphImplCallback callback) {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  TRACE_EVENT("webnn", "OhosWebNNCompile");

  NnrtGraphSpec spec;
  spec.operands.resize(info->operands.size());
  std::string error;

  for (size_t i = 0; i < info->operands.size(); ++i) {
    const auto& mojom_operand = *info->operands[i];
    auto& operand_spec = spec.operands[i];
    if (!ConvertDataType(mojom_operand.descriptor.data_type(),
                         operand_spec.data_type, error)) {
      std::move(callback).Run(base::unexpected(NotSupported(error)));
      return;
    }
    operand_spec.shape = mojom_operand.descriptor.shape();
    if (operand_spec.data_type == NnrtDataType::kFloat16) {
      spec.allow_fp16 = true;
    }
    if (mojom_operand.kind == mojom::Operand::Kind::kConstant) {
      auto it = constants.find(OperandId(static_cast<uint32_t>(i)));
      if (it == constants.end() || !it->second) {
        std::move(callback).Run(base::unexpected(
            NotSupported("Missing constant operand data for OHOS NNRt graph")));
        return;
      }
      base::span<const uint8_t> bytes = it->second->ByteSpan();
      operand_spec.constant_data.assign(bytes.begin(), bytes.end());
    }
  }

  std::vector<std::string> input_names;
  input_names.reserve(info->input_operands.size());
  for (const OperandId& id : info->input_operands) {
    const auto& op = *info->operands[id.value()];
    if (!op.name.has_value()) {
      std::move(callback).Run(base::unexpected(
          NotSupported("OHOS NNRt input operand missing name")));
      return;
    }
    spec.input_operands.push_back(id.value());
    input_names.push_back(*op.name);
  }

  std::vector<std::string> output_names;
  output_names.reserve(info->output_operands.size());
  for (const OperandId& id : info->output_operands) {
    const auto& op = *info->operands[id.value()];
    if (!op.name.has_value()) {
      std::move(callback).Run(base::unexpected(
          NotSupported("OHOS NNRt output operand missing name")));
      return;
    }
    spec.output_operands.push_back(id.value());
    output_names.push_back(*op.name);
  }

  spec.operations.reserve(info->operations.size());
  for (const auto& mojom_op : info->operations) {
    NnrtOpSpec op_spec;
    if (!TranslateOperation(*mojom_op, op_spec, error)) {
      LOG(ERROR) << "OhosWebNN unsupported operation: " << error;
      std::move(callback).Run(base::unexpected(NotSupported(error)));
      return;
    }
    spec.operations.push_back(std::move(op_spec));
  }

  auto graph = NnrtCompiledGraph::Create(devices_, spec, error);
  if (!graph) {
    LOG(ERROR) << "OhosWebNN build failed: " << error;
    std::move(callback).Run(base::unexpected(NotSupported(error)));
    return;
  }

  LOG(WARNING) << "OhosWebNN compiled graph (ops=" << spec.operations.size()
               << " inputs=" << spec.input_operands.size()
               << " outputs=" << spec.output_operands.size()
               << ") on accelerator id=" << graph->device().id
               << " name=" << graph->device().name;
  std::move(callback).Run(base::MakeRefCounted<GraphImplOhos>(
      *this, std::move(resources), std::move(graph), std::move(input_names),
      std::move(output_names)));
}

base::expected<scoped_refptr<WebNNTensorImpl>, mojom::ErrorPtr>
ContextImplOhos::CreateTensorImpl(
    mojo::PendingAssociatedReceiver<mojom::WebNNTensor> receiver,
    mojom::TensorInfoPtr info) {
  NnrtOperandSpec spec;
  std::string error;
  size_t bytes = 0;
  if (!ConvertDataType(info->descriptor.data_type(), spec.data_type, error)) {
    return base::unexpected(NotSupported("Unsupported OHOS tensor: " + error));
  }
  spec.shape = info->descriptor.shape();
  if (!NnrtCompiledGraph::ValidateOperand(spec, bytes, error)) {
    return base::unexpected(NotSupported("Unsupported OHOS tensor: " + error));
  }
  return base::MakeRefCounted<TensorImplOhos>(std::move(receiver), *this,
                                              std::move(info));
}

base::expected<scoped_refptr<WebNNTensorImpl>, mojom::ErrorPtr>
ContextImplOhos::CreateTensorFromSharedImageImpl(
    mojo::PendingAssociatedReceiver<mojom::WebNNTensor> receiver,
    mojom::TensorInfoPtr info,
    WebNNTensorImpl::RepresentationPtr representation) {
  return base::unexpected(
      NotSupported("OHOS WebNN WebGPU interop is not supported"));
}

std::string_view ContextImplOhos::GetBackendName() const {
  return "OHOS NNRt";
}
std::vector<mojom::WebNNExecutionProviderDetailsPtr>
ContextImplOhos::GetExecutionProvidersInfo() const {
  return {};
}

}  // namespace webnn::ohos
