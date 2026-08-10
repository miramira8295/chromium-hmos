// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/base/resource/ohos_product_branding.h"

#include <string_view>

namespace ui {
namespace {

bool IsAsciiIdentifierCharacter(char16_t character) {
  return (character >= u'a' && character <= u'z') ||
         (character >= u'A' && character <= u'Z') ||
         (character >= u'0' && character <= u'9') || character == u'_';
}

void ReplaceStandaloneProductName(std::u16string* value,
                                  std::u16string_view source,
                                  std::u16string_view replacement) {
  size_t offset = 0;
  while ((offset = value->find(source, offset)) != std::u16string::npos) {
    const size_t end = offset + source.size();
    const bool starts_at_boundary =
        offset == 0 || !IsAsciiIdentifierCharacter((*value)[offset - 1]);
    const bool ends_at_boundary =
        end == value->size() || !IsAsciiIdentifierCharacter((*value)[end]);
    if (!starts_at_boundary || !ends_at_boundary) {
      offset = end;
      continue;
    }
    value->replace(offset, source.size(), replacement);
    offset += replacement.size();
  }
}

}  // namespace

std::u16string ApplyOhosProductBranding(std::u16string localized_string) {
  ReplaceStandaloneProductName(&localized_string, u"Google Chrome", u"Chromium");
  ReplaceStandaloneProductName(&localized_string, u"Chrome", u"Chromium");
  return localized_string;
}

}  // namespace ui
