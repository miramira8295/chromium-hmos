// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <set>
#include <string>
#include <utility>

#include "base/check.h"
#include "base/values.h"
#include "content/common/font_list.h"
#include "skia/ext/font_utils.h"
#include "third_party/skia/include/core/SkFontMgr.h"
#include "third_party/skia/include/core/SkString.h"

namespace content {

base::ListValue GetFontList_SlowBlocking() {
  DCHECK(GetFontListTaskRunner()->RunsTasksInCurrentSequence());

  std::set<std::string> sorted_families;
  sk_sp<SkFontMgr> font_manager = skia::DefaultFontMgr();
  if (font_manager) {
    const int family_count = font_manager->countFamilies();
    for (int index = 0; index < family_count; ++index) {
      SkString family_name;
      font_manager->getFamilyName(index, &family_name);
      if (!family_name.isEmpty()) {
        sorted_families.insert(family_name.c_str());
      }
    }
  }

  base::ListValue font_list;
  for (const std::string& family : sorted_families) {
    base::ListValue font_item;
    font_item.Append(family);
    font_item.Append(family);
    font_list.Append(std::move(font_item));
  }
  return font_list;
}

}  // namespace content
