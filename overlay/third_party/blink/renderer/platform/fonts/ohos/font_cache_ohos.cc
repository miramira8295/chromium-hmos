// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/platform/fonts/ohos/font_cache_ohos.h"

#include <string>

#include "skia/ext/font_utils.h"
#include "third_party/blink/renderer/platform/font_family_names.h"
#include "third_party/blink/renderer/platform/fonts/font_cache.h"
#include "third_party/blink/renderer/platform/fonts/font_description.h"
#include "third_party/blink/renderer/platform/fonts/font_platform_data.h"
#include "third_party/blink/renderer/platform/fonts/simple_font_data.h"
#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/skia/include/core/SkFontMgr.h"
#include "third_party/skia/include/core/SkString.h"
#include "third_party/skia/include/core/SkTypeface.h"

namespace blink {

namespace {

AtomicString DefaultFontFamily() {
  sk_sp<SkTypeface> typeface =
      skia::DefaultFontMgr()->legacyMakeTypeface(nullptr, SkFontStyle());
  if (typeface) {
    SkString family_name;
    typeface->getFamilyName(&family_name);
    if (!family_name.isEmpty()) {
      return ToAtomicString(family_name);
    }
  }
  return font_family_names::kSans;
}

AtomicString& MutableSystemFontFamily() {
  DEFINE_THREAD_SAFE_STATIC_LOCAL(AtomicString, system_font_family,
                                  (DefaultFontFamily()));
  return system_font_family;
}

}  // namespace

// static
const AtomicString& FontCache::SystemFontFamily() {
  return MutableSystemFontFamily();
}

// static
void FontCache::SetSystemFontFamily(const AtomicString& family_name) {
  if (!family_name.empty()) {
    MutableSystemFontFamily() = family_name;
  }
}

void ReloadOhosThemeFontCache() {
  MutableSystemFontFamily() = DefaultFontFamily();
  FontCache::Get().Invalidate();
}

const SimpleFontData* FontCache::PlatformFallbackFontForCharacter(
    const FontDescription& font_description,
    UChar32 character,
    const SimpleFontData*,
    FontFallbackPriority fallback_priority) {
  sk_sp<SkFontMgr> font_manager = skia::DefaultFontMgr();
  std::string family_name = font_description.Family().FamilyName().Utf8();
  Bcp47Vector locales =
      GetBcp47LocaleForRequest(font_description, fallback_priority);
  sk_sp<SkTypeface> typeface = font_manager->matchFamilyStyleCharacter(
      family_name.empty() ? nullptr : family_name.c_str(),
      font_description.SkiaFontStyle(), locales.data(), locales.size(),
      character);
  if (!typeface) {
    typeface = font_manager->matchFamilyStyleCharacter(
        nullptr, font_description.SkiaFontStyle(), locales.data(),
        locales.size(), character);
  }
  if (!typeface) {
    return GetLastResortFallbackFont(font_description);
  }

  SkString fallback_family_name;
  typeface->getFamilyName(&fallback_family_name);
  bool synthetic_bold = font_description.Weight() >= kBoldThreshold &&
                        !typeface->isBold() &&
                        font_description.SyntheticBoldAllowed();
  bool synthetic_italic = font_description.Style() > kNormalSlopeValue &&
                          !typeface->isItalic() &&
                          font_description.SyntheticItalicAllowed();

  const auto* platform_data = MakeGarbageCollected<FontPlatformData>(
      std::move(typeface), fallback_family_name.c_str(),
      font_description.EffectiveFontSize(), synthetic_bold, synthetic_italic,
      font_description.TextRendering(), ResolvedFontFeatures(),
      font_description.Orientation());
  return FontDataFromFontPlatformData(platform_data);
}

}  // namespace blink
