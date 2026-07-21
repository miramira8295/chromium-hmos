// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_VIEWS_CHROME_VIEWS_DELEGATE_OHOS_UTILS_H_
#define CHROME_BROWSER_UI_VIEWS_CHROME_VIEWS_DELEGATE_OHOS_UTILS_H_

#include "ui/views/widget/widget.h"

namespace chrome::ohos {

inline bool ShouldEmbedSecondaryWidget(
    const views::Widget::InitParams& params) {
  return params.parent || params.context;
}

}  // namespace chrome::ohos

#endif  // CHROME_BROWSER_UI_VIEWS_CHROME_VIEWS_DELEGATE_OHOS_UTILS_H_
