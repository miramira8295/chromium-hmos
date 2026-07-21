// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/extensions/api/image_writer_private/removable_storage_provider.h"

namespace extensions {

scoped_refptr<StorageDeviceList>
RemovableStorageProvider::PopulateDeviceList() {
  return base::MakeRefCounted<StorageDeviceList>();
}

}  // namespace extensions
