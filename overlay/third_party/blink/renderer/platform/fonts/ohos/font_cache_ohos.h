// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_FONTS_OHOS_FONT_CACHE_OHOS_H_
#define THIRD_PARTY_BLINK_RENDERER_PLATFORM_FONTS_OHOS_FONT_CACHE_OHOS_H_

#include "third_party/blink/renderer/platform/platform_export.h"

namespace blink {

// Runs on the renderer main thread after the HarmonyOS theme font changes.
PLATFORM_EXPORT void ReloadOhosThemeFontCache();

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_PLATFORM_FONTS_OHOS_FONT_CACHE_OHOS_H_
