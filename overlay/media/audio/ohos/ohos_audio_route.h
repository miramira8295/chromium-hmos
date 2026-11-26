// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_AUDIO_OHOS_OHOS_AUDIO_ROUTE_H_
#define MEDIA_AUDIO_OHOS_OHOS_AUDIO_ROUTE_H_

#include <ohaudio/native_audiostream_base.h>
#include <stdint.h>

#include "media/audio/audio_device_name.h"

namespace media {

// Appends endpoints that can be selected for an individual stream. The caller
// supplies Chromium's default entry, which always follows system routing.
bool GetSelectableOhosAudioDevices(bool input, AudioDeviceNames* names);
bool SelectOhosAudioInput(uint32_t id, OH_AudioCapturer* capturer);
bool SelectOhosAudioOutput(uint32_t id, OH_AudioRenderer* renderer);

}  // namespace media

#endif  // MEDIA_AUDIO_OHOS_OHOS_AUDIO_ROUTE_H_
