// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "services/device/usb/ohos/usb_device_handle_ohos.h"

#include <utility>

#include "base/functional/bind.h"
#include "base/task/sequenced_task_runner.h"
#include "base/time/time.h"
#include "services/device/usb/ohos/usb_bridge_ohos.h"
#include "services/device/usb/usb_device.h"
#include "services/device/usb/usb_service.h"

namespace device {

// static
scoped_refptr<UsbDeviceHandleOhos> UsbDeviceHandleOhos::Create(
    scoped_refptr<UsbDevice> device,
    int file_descriptor,
    int pipe_id) {
  if (file_descriptor < 0 || pipe_id <= 0) {
    return nullptr;
  }
  return base::WrapRefCounted(new UsbDeviceHandleOhos(
      std::move(device), base::ScopedFD(file_descriptor), pipe_id));
}

UsbDeviceHandleOhos::UsbDeviceHandleOhos(scoped_refptr<UsbDevice> device,
                                         base::ScopedFD file_descriptor,
                                         int pipe_id)
    : UsbDeviceHandleUsbfs(std::move(device),
                           std::move(file_descriptor),
                           base::ScopedFD(),
                           std::string(),
                           UsbService::CreateBlockingTaskRunner()),
      pipe_id_(pipe_id) {}

UsbDeviceHandleOhos::~UsbDeviceHandleOhos() = default;

void UsbDeviceHandleOhos::FinishClose() {
  ReleaseFileDescriptor(base::BindOnce(&UsbDeviceHandleOhos::ClosePipe, this));
}

void UsbDeviceHandleOhos::ClosePipe(base::OnceClosure on_closed) {
  base::DictValue command;
  command.Set("method", "close");
  command.Set("pipeId", pipe_id_);
  SendUsbCommandOhos(
      std::move(command),
      base::BindOnce(&UsbDeviceHandleOhos::OnPipeClosed, this, std::move(on_closed)));
}

void UsbDeviceHandleOhos::OnPipeClosed(base::OnceClosure on_closed,
                                      base::DictValue response) {
  if (response.FindBool("ok").value_or(false)) {
    std::move(on_closed).Run();
    return;
  }
  // The kernel may still own transfer buffers while the pipe is open.
  task_runner()->PostDelayedTask(
      FROM_HERE, base::BindOnce(&UsbDeviceHandleOhos::ClosePipe, this,
                                std::move(on_closed)), base::Seconds(5));
}

}  // namespace device
