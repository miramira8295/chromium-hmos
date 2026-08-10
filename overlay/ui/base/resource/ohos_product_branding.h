// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_BASE_RESOURCE_OHOS_PRODUCT_BRANDING_H_
#define UI_BASE_RESOURCE_OHOS_PRODUCT_BRANDING_H_

#include <string>

#include "base/component_export.h"

namespace ui {

// Rebrands Chromium's localized product strings without changing protocol
// names such as chrome:// or platform names such as ChromeOS.
COMPONENT_EXPORT(UI_BASE)
std::u16string ApplyOhosProductBranding(std::u16string localized_string);

}  // namespace ui

#endif  // UI_BASE_RESOURCE_OHOS_PRODUCT_BRANDING_H_
