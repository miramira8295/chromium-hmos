// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/audio/ohos/ohos_audio_output.h"

#include <ohaudio/native_audiostreambuilder.h>

#include <algorithm>
#include <cstdint>
#include <ranges>

#include "base/check.h"
#include "base/compiler_specific.h"
#include "base/containers/span.h"
#include "base/functional/bind.h"
#include "base/logging.h"
#include "base/time/time.h"
#include "media/audio/audio_manager_base.h"
#include "media/base/audio_bus.h"
#include "media/base/audio_pull_fifo.h"
#include "media/base/audio_sample_types.h"

namespace media {

namespace {

bool IsSuccess(OH_AudioStream_Result result) {
  return result == AUDIOSTREAM_SUCCESS;
}

}  // namespace

OhosAudioOutputStream::OhosAudioOutputStream(AudioManagerBase* audio_manager,
                                             const AudioParameters& params)
    : audio_manager_(audio_manager), params_(params) {
  CHECK(audio_manager_);
  CHECK(params_.IsValid());
}

OhosAudioOutputStream::~OhosAudioOutputStream() {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  DCHECK(!renderer_);
  base::AutoLock auto_lock(lock_);
  DCHECK(!callback_);
}

bool OhosAudioOutputStream::Open() {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  DCHECK(!renderer_);

  OH_AudioStreamBuilder* builder = nullptr;
  if (!IsSuccess(
          OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RENDERER))) {
    LOG(ERROR) << "OHAudio failed to create a renderer builder";
    return false;
  }

  const OH_AudioRenderer_Callbacks callbacks = {
      &OhosAudioOutputStream::OnWriteData,
      &OhosAudioOutputStream::OnStreamEvent,
      &OhosAudioOutputStream::OnInterruptEvent,
      &OhosAudioOutputStream::OnError,
  };

  const bool configured =
      IsSuccess(OH_AudioStreamBuilder_SetSamplingRate(builder,
                                                      params_.sample_rate())) &&
      IsSuccess(
          OH_AudioStreamBuilder_SetChannelCount(builder, params_.channels())) &&
      IsSuccess(OH_AudioStreamBuilder_SetSampleFormat(
          builder, AUDIOSTREAM_SAMPLE_S16LE)) &&
      IsSuccess(OH_AudioStreamBuilder_SetEncodingType(
          builder, AUDIOSTREAM_ENCODING_TYPE_RAW)) &&
      IsSuccess(OH_AudioStreamBuilder_SetLatencyMode(
          builder, AUDIOSTREAM_LATENCY_MODE_FAST)) &&
      IsSuccess(OH_AudioStreamBuilder_SetRendererInfo(
          builder, AUDIOSTREAM_USAGE_MUSIC)) &&
      IsSuccess(OH_AudioStreamBuilder_SetRendererCallback(builder, callbacks,
                                                          this)) &&
      IsSuccess(OH_AudioStreamBuilder_GenerateRenderer(builder, &renderer_));

  const OH_AudioStream_Result destroy_result =
      OH_AudioStreamBuilder_Destroy(builder);
  if (!IsSuccess(destroy_result)) {
    LOG(WARNING) << "OHAudio failed to destroy a renderer builder";
  }

  if (!configured) {
    LOG(ERROR) << "OHAudio failed to configure an output stream";
    if (renderer_) {
      OH_AudioRenderer_Release(renderer_);
      renderer_ = nullptr;
    }
    return false;
  }

  audio_bus_ = AudioBus::Create(params_);
  pull_fifo_ = std::make_unique<AudioPullFifo>(
      params_.channels(), params_.frames_per_buffer(),
      base::BindRepeating(&OhosAudioOutputStream::RefillFifo,
                          base::Unretained(this)));
  return true;
}

void OhosAudioOutputStream::Start(AudioSourceCallback* callback) {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  CHECK(callback);

  {
    base::AutoLock auto_lock(lock_);
    CHECK(!callback_);
    callback_ = callback;
  }

  if (renderer_ && IsSuccess(OH_AudioRenderer_Start(renderer_))) {
    return;
  }

  {
    base::AutoLock auto_lock(lock_);
    callback_ = nullptr;
  }
  callback->OnError(AudioSourceCallback::ErrorType::kUnknown);
}

void OhosAudioOutputStream::Stop() {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);

  AudioSourceCallback* error_callback = nullptr;
  {
    base::AutoLock auto_lock(lock_);
    if (!callback_) {
      return;
    }
    error_callback = callback_;
    callback_ = nullptr;
    pull_fifo_->Clear();
  }

  if (renderer_ && !IsSuccess(OH_AudioRenderer_Stop(renderer_))) {
    error_callback->OnError(AudioSourceCallback::ErrorType::kUnknown);
  }
}

void OhosAudioOutputStream::SetVolume(double volume) {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  if (volume < 0.0 || volume > 1.0) {
    return;
  }
  base::AutoLock auto_lock(lock_);
  volume_ = volume;
}

void OhosAudioOutputStream::GetVolume(double* volume) {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  CHECK(volume);
  base::AutoLock auto_lock(lock_);
  *volume = volume_;
}

void OhosAudioOutputStream::Close() {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  Stop();
  if (renderer_) {
    if (!IsSuccess(OH_AudioRenderer_Release(renderer_))) {
      LOG(WARNING) << "OHAudio failed to release an output stream";
    }
    renderer_ = nullptr;
  }
  audio_bus_.reset();
  pull_fifo_.reset();

  // ReleaseOutputStream() deletes this object.
  audio_manager_->ReleaseOutputStream(this);
}

void OhosAudioOutputStream::Flush() {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
  if (renderer_ && !IsSuccess(OH_AudioRenderer_Flush(renderer_))) {
    LOG(WARNING) << "OHAudio failed to flush an output stream";
  }
}

// static
int32_t OhosAudioOutputStream::OnWriteData(OH_AudioRenderer* renderer,
                                           void* user_data,
                                           void* buffer,
                                           int32_t length) {
  return static_cast<OhosAudioOutputStream*>(user_data)->FillBuffer(buffer,
                                                                    length);
}

// static
int32_t OhosAudioOutputStream::OnStreamEvent(OH_AudioRenderer* renderer,
                                             void* user_data,
                                             OH_AudioStream_Event event) {
  if (event == AUDIOSTREAM_EVENT_ROUTING_CHANGED) {
    static_cast<OhosAudioOutputStream*>(user_data)->ReportError(
        AudioSourceCallback::ErrorType::kDeviceChange);
  }
  return AUDIOSTREAM_SUCCESS;
}

// static
int32_t OhosAudioOutputStream::OnInterruptEvent(
    OH_AudioRenderer* renderer,
    void* user_data,
    OH_AudioInterrupt_ForceType type,
    OH_AudioInterrupt_Hint hint) {
  return AUDIOSTREAM_SUCCESS;
}

// static
int32_t OhosAudioOutputStream::OnError(OH_AudioRenderer* renderer,
                                       void* user_data,
                                       OH_AudioStream_Result error) {
  static_cast<OhosAudioOutputStream*>(user_data)->ReportError(
      AudioSourceCallback::ErrorType::kUnknown);
  return AUDIOSTREAM_SUCCESS;
}

int32_t OhosAudioOutputStream::FillBuffer(void* buffer, int32_t length) {
  if (!buffer || length <= 0 ||
      length % static_cast<int32_t>(sizeof(int16_t)) != 0) {
    return AUDIOSTREAM_ERROR_INVALID_PARAM;
  }

  const size_t sample_count = length / sizeof(int16_t);
  auto samples =
      UNSAFE_BUFFERS(base::span(static_cast<int16_t*>(buffer), sample_count));

  base::AutoLock auto_lock(lock_);
  if (!callback_ || !audio_bus_ || !pull_fifo_ ||
      sample_count % params_.channels() != 0) {
    std::ranges::fill(samples, 0);
    return AUDIOSTREAM_SUCCESS;
  }

  while (!samples.empty()) {
    const size_t frames_to_pull =
        std::min(samples.size() / params_.channels(),
                 static_cast<size_t>(audio_bus_->frames()));
    if (frames_to_pull == 0) {
      std::ranges::fill(samples, 0);
      break;
    }

    pull_fifo_->Consume(audio_bus_.get(), frames_to_pull);
    audio_bus_->Scale(volume_);

    const size_t samples_to_write = frames_to_pull * params_.channels();
    audio_bus_->ToInterleavedPartial<SignedInt16SampleTypeTraits>(
        0u, samples.take_first(samples_to_write));
  }

  return AUDIOSTREAM_SUCCESS;
}

void OhosAudioOutputStream::RefillFifo(int frame_delay, AudioBus* destination) {
  lock_.AssertAcquired();
  CHECK(callback_);

  const int frames_filled = callback_->OnMoreData(
      base::TimeDelta(), base::TimeTicks::Now(), {}, destination);
  if (frames_filled <= 0) {
    destination->Zero();
    return;
  }

  if (frames_filled < destination->frames()) {
    destination->ZeroFramesPartial(frames_filled,
                                   destination->frames() - frames_filled);
  }
}

void OhosAudioOutputStream::ReportError(AudioSourceCallback::ErrorType type) {
  base::AutoLock auto_lock(lock_);
  if (callback_) {
    callback_->OnError(type);
  }
}

}  // namespace media
