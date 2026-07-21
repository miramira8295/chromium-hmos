// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <memory>
#include <utility>

#include "services/on_device_model/on_device_model_service.h"

namespace on_device_model {

// static
bool OnDeviceModelService::PreSandboxInit() {
  return true;
}

// static
bool OnDeviceModelService::Shutdown() {
  return true;
}

OnDeviceModelService::OnDeviceModelService(
    mojo::PendingReceiver<mojom::OnDeviceModelService> receiver)
    : receiver_(this, std::move(receiver)) {}

OnDeviceModelService::~OnDeviceModelService() = default;

// static
std::unique_ptr<mojom::OnDeviceModelService> OnDeviceModelService::Create(
    mojo::PendingReceiver<mojom::OnDeviceModelService> receiver) {
  return std::make_unique<OnDeviceModelService>(std::move(receiver));
}

void OnDeviceModelService::LoadModel(
    mojom::LoadModelParamsPtr params,
    mojo::PendingReceiver<mojom::OnDeviceModel> model,
    LoadModelCallback callback) {
  std::move(callback).Run(mojom::LoadModelResult::kFailedToLoadLibrary);
}

void OnDeviceModelService::LoadTextSafetyModel(
    on_device_model::mojom::TextSafetyModelParamsPtr params,
    mojo::PendingReceiver<mojom::TextSafetyModel> model) {}

void OnDeviceModelService::GetEstimatedPerformanceClass(
    GetEstimatedPerformanceClassCallback callback) {
  std::move(callback).Run(mojom::PerformanceClass::kFailedToLoadLibrary);
}

void OnDeviceModelService::DeleteModel(
    base::WeakPtr<mojom::OnDeviceModel> model) {}

}  // namespace on_device_model
