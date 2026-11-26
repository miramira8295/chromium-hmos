// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/audio/ohos/audio_manager_ohos.h"

#include <ohaudio/native_audio_routing_manager.h>

#include <memory>
#include <optional>
#include <utility>

#include "base/command_line.h"
#include "base/compiler_specific.h"
#include "base/containers/span.h"
#include "base/functional/bind.h"
#include "base/functional/callback.h"
#include "base/no_destructor.h"
#include "base/strings/string_number_conversions.h"
#include "base/synchronization/lock.h"
#include "base/system/system_monitor.h"
#include "base/task/bind_post_task.h"
#include "media/audio/audio_device_description.h"
#include "media/audio/audio_device_name.h"
#include "media/audio/fake_audio_manager.h"
#include "media/audio/ohos/ohos_audio_input.h"
#include "media/audio/ohos/ohos_audio_output.h"
#include "media/audio/ohos/ohos_audio_route.h"
#include "media/base/channel_layout.h"
#include "media/base/media_switches.h"

namespace media {

namespace {

constexpr int kDefaultSampleRate = 48000;
constexpr int kDefaultFramesPerBuffer = 480;

// The OHAudio hotplug callback has no user-data argument and runs on a system
// thread. The callback only schedules work on the current manager's audio
// thread; shutdown detaches it and invalidates any already scheduled tasks.
struct DeviceChangeSubscription {
  base::Lock lock;
  base::RepeatingCallback<void(bool)> notify GUARDED_BY(lock);
};

DeviceChangeSubscription& GetDeviceChangeSubscription() {
  static base::NoDestructor<DeviceChangeSubscription> subscription;
  return *subscription;
}

int32_t OnOhosDevicesChanged(OH_AudioDevice_ChangeType,
                             OH_AudioDeviceDescriptorArray* devices) {
  bool output_changed = false;
  if (devices && devices->descriptors) {
    // SAFETY: OHAudio owns this array and supplies its count for the callback.
    auto descriptors =
        UNSAFE_BUFFERS(base::span(devices->descriptors, devices->size));
    for (auto* descriptor : descriptors) {
      OH_AudioDevice_Role role;
      if (descriptor &&
          OH_AudioDeviceDescriptor_GetDeviceRole(descriptor, &role) ==
              AUDIOCOMMON_RESULT_SUCCESS &&
          role == AUDIO_DEVICE_ROLE_OUTPUT) {
        output_changed = true;
        break;
      }
    }
  }
  OH_AudioRoutingManager* manager = nullptr;
  if (devices && OH_AudioManager_GetAudioRoutingManager(&manager) ==
                     AUDIOCOMMON_RESULT_SUCCESS) {
    OH_AudioRoutingManager_ReleaseDevices(manager, devices);
  }
  auto& subscription = GetDeviceChangeSubscription();
  base::AutoLock lock(subscription.lock);
  if (subscription.notify) {
    subscription.notify.Run(output_changed);
  }
  return 0;
}

std::optional<uint32_t> ParseDeviceId(const std::string& device_id) {
  unsigned int id;
  if (!base::StringToUint(device_id, &id) ||
      base::NumberToString(id) != device_id) {
    return std::nullopt;
  }
  return id;
}

}  // namespace

AudioManagerOhos::AudioManagerOhos(std::unique_ptr<AudioThread> audio_thread,
                                   AudioLogFactory* audio_log_factory)
    : AudioManagerBase(std::move(audio_thread), audio_log_factory) {}

AudioManagerOhos::~AudioManagerOhos() = default;

bool AudioManagerOhos::HasAudioOutputDevices() {
  return true;
}

bool AudioManagerOhos::HasAudioInputDevices() {
  return true;
}

AudioParameters AudioManagerOhos::GetInputStreamParameters(
    const std::string& device_id) {
  return AudioParameters(AudioParameters::AUDIO_PCM_LOW_LATENCY,
                         ChannelLayoutConfig::Mono(), kDefaultSampleRate,
                         kDefaultFramesPerBuffer);
}

const std::string_view AudioManagerOhos::GetName() {
  return "OHAudio";
}

AudioOutputStream* AudioManagerOhos::MakeLinearOutputStream(
    const AudioParameters& params,
    const LogCallback& log_callback) {
  return new OhosAudioOutputStream(this, params);
}

AudioOutputStream* AudioManagerOhos::MakeLowLatencyOutputStream(
    const AudioParameters& params,
    const std::string& device_id,
    const LogCallback& log_callback) {
  if (AudioDeviceDescription::IsDefaultDevice(device_id)) {
    return new OhosAudioOutputStream(this, params);
  }
  auto id = ParseDeviceId(device_id);
  return id ? new OhosAudioOutputStream(this, params, id) : nullptr;
}

AudioInputStream* AudioManagerOhos::MakeLinearInputStream(
    const AudioParameters& params,
    const std::string& device_id,
    const LogCallback& log_callback) {
  if (AudioDeviceDescription::IsDefaultDevice(device_id)) {
    return new OhosAudioInputStream(this, params);
  }
  auto id = ParseDeviceId(device_id);
  return id ? new OhosAudioInputStream(this, params, id) : nullptr;
}

AudioInputStream* AudioManagerOhos::MakeLowLatencyInputStream(
    const AudioParameters& params,
    const std::string& device_id,
    const LogCallback& log_callback) {
  return MakeLinearInputStream(params, device_id, log_callback);
}

bool AudioManagerOhos::GetAudioInputDeviceNames(
    AudioDeviceNames* device_names) {
  return GetDeviceNames(/*input=*/true, device_names);
}

bool AudioManagerOhos::GetAudioOutputDeviceNames(
    AudioDeviceNames* device_names) {
  return GetDeviceNames(/*input=*/false, device_names);
}

bool AudioManagerOhos::GetDeviceNames(bool input,
                                      AudioDeviceNames* device_names) {
  DCHECK(GetTaskRunner()->BelongsToCurrentThread());
  if (!device_names) {
    return false;
  }
  if (input && base::CommandLine::ForCurrentProcess()->HasSwitch(
                   switches::kDisableAudioInput)) {
    return true;
  }

  StartDeviceMonitor();
  device_names->emplace_back(std::string(),
                             AudioDeviceDescription::kDefaultDeviceId);
  GetSelectableOhosAudioDevices(input, device_names);
  return true;
}

void AudioManagerOhos::StartDeviceMonitor() {
  if (monitoring_devices_) {
    return;
  }
  OH_AudioRoutingManager* manager = nullptr;
  if (OH_AudioManager_GetAudioRoutingManager(&manager) !=
      AUDIOCOMMON_RESULT_SUCCESS) {
    return;
  }
  auto& subscription = GetDeviceChangeSubscription();
  {
    base::AutoLock lock(subscription.lock);
    if (subscription.notify) {
      return;
    }
    subscription.notify = base::BindPostTask(
        GetTaskRunner(),
        base::BindRepeating(&AudioManagerOhos::OnDevicesChanged,
                            weak_factory_.GetWeakPtr()));
  }
  if (OH_AudioRoutingManager_RegisterDeviceChangeCallback(
          manager, AUDIO_DEVICE_FLAG_ALL, OnOhosDevicesChanged) ==
      AUDIOCOMMON_RESULT_SUCCESS) {
    monitoring_devices_ = true;
  } else {
    base::AutoLock lock(subscription.lock);
    subscription.notify.Reset();
  }
}

void AudioManagerOhos::OnDevicesChanged(bool output_changed) {
  DCHECK(GetTaskRunner()->BelongsToCurrentThread());
  if (auto* monitor = base::SystemMonitor::Get()) {
    monitor->ProcessDevicesChanged(base::SystemMonitor::DEVTYPE_AUDIO);
  }
  if (output_changed) {
    NotifyAllOutputDeviceChangeListeners();
  }
}

void AudioManagerOhos::ShutdownOnAudioThread() {
  if (monitoring_devices_) {
    OH_AudioRoutingManager* manager = nullptr;
    if (OH_AudioManager_GetAudioRoutingManager(&manager) ==
        AUDIOCOMMON_RESULT_SUCCESS) {
      OH_AudioRoutingManager_UnregisterDeviceChangeCallback(
          manager, OnOhosDevicesChanged);
    }
    auto& subscription = GetDeviceChangeSubscription();
    base::AutoLock lock(subscription.lock);
    subscription.notify.Reset();
    monitoring_devices_ = false;
  }
  weak_factory_.InvalidateWeakPtrs();
  AudioManagerBase::ShutdownOnAudioThread();
}

AudioParameters AudioManagerOhos::GetPreferredOutputStreamParameters(
    const std::string& output_device_id,
    const AudioParameters& input_params) {
  int frames_per_buffer = GetUserBufferSize();
  if (frames_per_buffer <= 0) {
    frames_per_buffer = kDefaultFramesPerBuffer;
  }
  return AudioParameters(AudioParameters::AUDIO_PCM_LOW_LATENCY,
                         ChannelLayoutConfig::Stereo(), kDefaultSampleRate,
                         frames_per_buffer);
}

std::unique_ptr<AudioManager> CreateAudioManager(
    std::unique_ptr<AudioThread> audio_thread,
    AudioLogFactory* audio_log_factory) {
  if (base::CommandLine::ForCurrentProcess()->HasSwitch(
          switches::kDisableAudioOutput)) {
    return std::make_unique<FakeAudioManager>(std::move(audio_thread),
                                              audio_log_factory);
  }
  return std::make_unique<AudioManagerOhos>(std::move(audio_thread),
                                            audio_log_factory);
}

}  // namespace media
