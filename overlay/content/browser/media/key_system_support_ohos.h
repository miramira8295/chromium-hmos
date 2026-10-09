// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_BROWSER_MEDIA_KEY_SYSTEM_SUPPORT_OHOS_H_
#define CONTENT_BROWSER_MEDIA_KEY_SYSTEM_SUPPORT_OHOS_H_

#include <string>

#include "content/common/content_export.h"
#include "content/public/common/cdm_info.h"
#include "media/base/cdm_capability.h"

namespace content {

// What DRM Kit can do for `key_system` at `robustness`: the codecs, schemes
// and session types OhosCdm and the AVCodecKit decoders support with it, or
// why there are none. Asks DRM Kit off the calling sequence and answers on
// it.
CONTENT_EXPORT void GetOhosCdmCapability(const std::string& key_system,
                                         CdmInfo::Robustness robustness,
                                         media::CdmCapabilityCB cdm_capability_cb);

}  // namespace content

#endif  // CONTENT_BROWSER_MEDIA_KEY_SYSTEM_SUPPORT_OHOS_H_
