// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_AUDIO_OHOS_OHOS_AUDIO_OUTPUT_H_
#define MEDIA_AUDIO_OHOS_OHOS_AUDIO_OUTPUT_H_

#include <ohaudio/native_audiorenderer.h>
#include <stdint.h>

#include <memory>

#include "base/memory/raw_ptr.h"
#include "base/sequence_checker.h"
#include "base/synchronization/lock.h"
#include "base/thread_annotations.h"
#include "media/audio/audio_io.h"
#include "media/base/audio_parameters.h"

namespace media {

class AudioBus;
class AudioManagerBase;
class AudioPullFifo;

class OhosAudioOutputStream final : public AudioOutputStream {
 public:
  OhosAudioOutputStream(AudioManagerBase* audio_manager,
                        const AudioParameters& params);

  OhosAudioOutputStream(const OhosAudioOutputStream&) = delete;
  OhosAudioOutputStream& operator=(const OhosAudioOutputStream&) = delete;

  ~OhosAudioOutputStream() override;

  bool Open() override;
  void Start(AudioSourceCallback* callback) override;
  void Stop() override;
  void SetVolume(double volume) override;
  void GetVolume(double* volume) override;
  void Close() override;
  void Flush() override;

 private:
  static int32_t OnWriteData(OH_AudioRenderer* renderer,
                             void* user_data,
                             void* buffer,
                             int32_t length);
  static int32_t OnStreamEvent(OH_AudioRenderer* renderer,
                               void* user_data,
                               OH_AudioStream_Event event);
  static int32_t OnInterruptEvent(OH_AudioRenderer* renderer,
                                  void* user_data,
                                  OH_AudioInterrupt_ForceType type,
                                  OH_AudioInterrupt_Hint hint);
  static int32_t OnError(OH_AudioRenderer* renderer,
                         void* user_data,
                         OH_AudioStream_Result error);

  int32_t FillBuffer(void* buffer, int32_t length);
  void RefillFifo(int frame_delay, AudioBus* destination);
  void ReportError(AudioSourceCallback::ErrorType type);

  SEQUENCE_CHECKER(sequence_checker_);

  const raw_ptr<AudioManagerBase> audio_manager_;
  const AudioParameters params_;
  OH_AudioRenderer* renderer_ = nullptr;
  std::unique_ptr<AudioBus> audio_bus_;
  std::unique_ptr<AudioPullFifo> pull_fifo_;

  base::Lock lock_;
  raw_ptr<AudioSourceCallback> callback_ GUARDED_BY(lock_) = nullptr;
  double volume_ GUARDED_BY(lock_) = 1.0;
};

}  // namespace media

#endif  // MEDIA_AUDIO_OHOS_OHOS_AUDIO_OUTPUT_H_
