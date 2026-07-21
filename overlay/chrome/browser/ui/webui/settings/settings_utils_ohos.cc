// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/logging.h"
#include "chrome/browser/ui/webui/settings/settings_utils.h"

namespace settings_utils {

void ShowNetworkProxySettings(content::WebContents* web_contents) {
  LOG(WARNING) << "HarmonyOS system proxy settings are not available through "
                  "the native Chromium bridge yet";
}

}  // namespace settings_utils
