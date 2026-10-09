// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_GPU_OHOS_OHOS_CENC_INFO_H_
#define MEDIA_GPU_OHOS_OHOS_CENC_INFO_H_

#include <stddef.h>

#include "media/gpu/media_gpu_export.h"

struct OH_AVBuffer;

namespace media {

class DecryptConfig;

// Tells an AVCodecKit decoder how to decrypt the sample in `buffer`, a codec
// input buffer holding `sample_size` bytes, before it decodes it: the CENC
// parameters of `config`, or none -- the sample is clear -- when `config` is
// null. Returns false if DRM Kit cannot express them, e.g. more than 64
// subsamples.
MEDIA_GPU_EXPORT bool AttachOhosCencInfo(const DecryptConfig* config,
                                         size_t sample_size,
                                         OH_AVBuffer* buffer);

}  // namespace media

#endif  // MEDIA_GPU_OHOS_OHOS_CENC_INFO_H_
