// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/platform_util.h"

namespace platform_util {

void ShowItemInFolder(Profile* profile, const base::FilePath& full_path) {}

namespace internal {

void PlatformOpenVerifiedItem(const base::FilePath& path, OpenItemType type) {}

}  // namespace internal

void OpenExternal(const GURL& url) {}

}  // namespace platform_util
