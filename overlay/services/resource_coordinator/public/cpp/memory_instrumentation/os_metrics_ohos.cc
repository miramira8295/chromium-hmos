// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <vector>

#include "base/numerics/safe_conversions.h"
#include "services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h"

namespace memory_instrumentation {

bool OSMetrics::FillOSMemoryDump(base::ProcessHandle handle,
                                 const MemDumpFlagSet& flags,
                                 mojom::RawOSMemDump* dump) {
  auto info = GetMemoryInfo(handle);
  if (!info.has_value()) {
    return false;
  }

  dump->platform_private_footprint->rss_anon_bytes = info->rss_anon_bytes;
  dump->platform_private_footprint->vm_swap_bytes = info->vm_swap_bytes;
  dump->resident_set_kb =
      base::saturated_cast<uint32_t>(info->resident_set_bytes / 1024);
  return true;
}

std::vector<mojom::VmRegionPtr> OSMetrics::GetProcessMemoryMaps(
    base::ProcessHandle handle) {
  return {};
}

}  // namespace memory_instrumentation
