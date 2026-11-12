// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
#include <array>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include "services/webnn/ohos/nnrt_add_model.h"

int main() {
  std::string error;
  std::vector<webnn::ohos::NnrtDeviceInfo> all_devices;
  if (webnn::ohos::ListNnrtDevices(all_devices, error)) {
    std::cout << "NNRt device inventory (" << all_devices.size() << "):\n";
    for (size_t i = 0; i < all_devices.size(); ++i) {
      std::cout << "  [" << i << "] id=" << all_devices[i].id
                << " type=" << all_devices[i].type
                << " name=" << all_devices[i].name << '\n';
    }
  } else {
    std::cerr << "ListNnrtDevices failed: " << error << '\n';
    return 1;
  }

  std::vector<webnn::ohos::NnrtDevice> accelerators;
  if (!webnn::ohos::FindNnrtAccelerators(accelerators, error)) {
    std::cerr << error << '\n';
    return 1;
  }
  std::cout << "Selected primary NNRt accelerator id="
            << accelerators.front().id << " name=" << accelerators.front().name
            << " (candidate accelerators=" << accelerators.size() << ")\n";

  // 1. Test NnrtAddModel (2D [1, 4] with automatic format/4D promotion).
  auto model =
      webnn::ohos::NnrtAddModel::Create(accelerators.front(), {1, 4}, error);
  if (!model) {
    std::cerr << "NnrtAddModel::Create failed: " << error << '\n';
    return 2;
  }
  const float lhs[] = {1, -2, 0.25f, 1024};
  const float rhs[] = {3, 0.5f, -0.125f, -512};
  float output[4]{};
  const float expected_add[] = {4, -1.5f, 0.125f, 512};
  for (int run = 0; run < 10; ++run) {
    if (!model->Run(lhs, sizeof(lhs), rhs, sizeof(rhs), output, sizeof(output),
                    error)) {
      std::cerr << error << '\n';
      return 3;
    }
    for (size_t i = 0; i < 4; ++i) {
      if (!std::isfinite(output[i]) ||
          std::abs(output[i] - expected_add[i]) > 0.0001f) {
        std::cerr << "Incorrect Add output at " << i << ": " << output[i]
                  << '\n';
        return 4;
      }
    }
  }

  // 2. Test NnrtCompiledGraph multi-op DAG: y = Relu(x * 2 + rhs)
  webnn::ohos::NnrtGraphSpec spec;
  spec.operands.resize(5);
  spec.operands[0] = {webnn::ohos::NnrtDataType::kFloat32, {1, 4}, {}};
  spec.operands[1] = {webnn::ohos::NnrtDataType::kFloat32, {1, 4}, {}};
  const std::array<float, 4> scale_vals{2.0f, 2.0f, 2.0f, 2.0f};
  spec.operands[2].data_type = webnn::ohos::NnrtDataType::kFloat32;
  spec.operands[2].shape = {1, 4};
  spec.operands[2].constant_data.resize(sizeof(scale_vals));
  std::memcpy(spec.operands[2].constant_data.data(), scale_vals.data(),
              sizeof(scale_vals));
  spec.operands[3] = {webnn::ohos::NnrtDataType::kFloat32, {1, 4}, {}};
  spec.operands[4] = {webnn::ohos::NnrtDataType::kFloat32, {1, 4}, {}};

  spec.input_operands = {0, 1};
  spec.output_operands = {4};
  spec.operations.resize(3);
  spec.operations[0].type = webnn::ohos::NnrtOpType::kMul;
  spec.operations[0].inputs = {0, 2};
  spec.operations[0].outputs = {3};
  spec.operations[1].type = webnn::ohos::NnrtOpType::kAdd;
  spec.operations[1].inputs = {3, 1};
  spec.operations[1].outputs = {4};
  // Overwrite with Relu into a 6th operand
  spec.operands.push_back({webnn::ohos::NnrtDataType::kFloat32, {1, 4}, {}});
  spec.output_operands = {5};
  spec.operations[2].type = webnn::ohos::NnrtOpType::kRelu;
  spec.operations[2].inputs = {4};
  spec.operations[2].outputs = {5};

  auto graph = webnn::ohos::NnrtCompiledGraph::Create(accelerators, spec, error);
  if (!graph) {
    std::cerr << "NnrtCompiledGraph::Create failed: " << error << '\n';
    return 5;
  }
  const float expected_dag[] = {5.0f, 0.0f, 0.375f, 1536.0f};
  float dag_out[4]{};
  if (!graph->Run({{lhs, sizeof(lhs)}, {rhs, sizeof(rhs)}},
                  {{dag_out, sizeof(dag_out)}}, error)) {
    std::cerr << "NnrtCompiledGraph::Run failed: " << error << '\n';
    return 6;
  }
  for (size_t i = 0; i < 4; ++i) {
    if (!std::isfinite(dag_out[i]) ||
        std::abs(dag_out[i] - expected_dag[i]) > 0.0001f) {
      std::cerr << "Incorrect DAG output at " << i << ": " << dag_out[i]
                << '\n';
      return 7;
    }
  }

  std::cout << "PASS: 10 NNRt Add dispatches + multi-op DAG (Mul+Add+Relu) on "
            << graph->device().name << " (id=" << graph->device().id
            << "); CPU fallback disabled\n";
}
