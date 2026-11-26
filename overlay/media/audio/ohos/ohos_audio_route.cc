// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/audio/ohos/ohos_audio_route.h"

#include <dlfcn.h>
#include <ohaudio/native_audio_routing_manager.h>

#include <algorithm>
#include <utility>

#include "base/compiler_specific.h"
#include "base/containers/span.h"
#include "base/strings/string_number_conversions.h"

// The builder SDK predates API 26. Resolve the public per-stream routing
// functions at runtime so older systems still have the normal default route.
struct OH_AudioDeviceEnhanceManager;

namespace media {
namespace {

void* ResolveAudioSymbol(const char* name) {
  // The engine is loaded with RTLD_LOCAL. Its dependencies need not be
  // visible through RTLD_DEFAULT on the device.
  static void* const library = dlopen("libohaudio.so", RTLD_NOW | RTLD_LOCAL);
  void* symbol = library ? dlsym(library, name) : nullptr;
  return symbol ? symbol : dlsym(RTLD_DEFAULT, name);
}

struct EnhancedRouting {
  using Result = OH_AudioCommon_Result;
  using Manager = OH_AudioDeviceEnhanceManager;
  using GetManager = Result (*)(Manager**);
  using IsSupported = Result (*)(Manager*, bool*);
  using SelectInput = Result (*)(Manager*,
                                 OH_AudioCapturer*,
                                 OH_AudioDeviceDescriptor*);
  using SelectOutput = Result (*)(Manager*,
                                  OH_AudioRenderer*,
                                  OH_AudioDeviceDescriptor*);

  GetManager get = reinterpret_cast<GetManager>(
      ResolveAudioSymbol("OH_AudioManager_GetAudioDeviceEnhanceManager"));
  IsSupported supported = reinterpret_cast<IsSupported>(ResolveAudioSymbol(
      "OH_AudioDeviceEnhanceManager_IsEnhancedRoutingSupported"));
  SelectInput input = reinterpret_cast<SelectInput>(ResolveAudioSymbol(
      "OH_AudioDeviceEnhanceManager_SelectInputDeviceForAudioCapturer"));
  SelectOutput output = reinterpret_cast<SelectOutput>(ResolveAudioSymbol(
      "OH_AudioDeviceEnhanceManager_SelectOutputDeviceForAudioRenderer"));

  Manager* ForDirection(bool is_input) const {
    Manager* manager = nullptr;
    bool enabled = false;
    if (!get || !supported || (is_input ? !input : !output) ||
        get(&manager) != AUDIOCOMMON_RESULT_SUCCESS || !manager ||
        supported(manager, &enabled) != AUDIOCOMMON_RESULT_SUCCESS ||
        !enabled) {
      return nullptr;
    }
    return manager;
  }
};

const EnhancedRouting& RoutingApi() {
  static const EnhancedRouting api;
  return api;
}

class AvailableDevices {
 public:
  AvailableDevices() = default;
  AvailableDevices(const AvailableDevices&) = delete;
  AvailableDevices& operator=(const AvailableDevices&) = delete;

  ~AvailableDevices() {
    if (devices_) {
      OH_AudioRoutingManager_ReleaseDevices(manager_, devices_);
    }
  }

  bool Load(bool input) {
    // Match VOICE_COMMUNICATION recording and MUSIC playback used by the
    // streams. The OS can return different routes for a different usage.
    const auto usage =
        input ? AUDIO_DEVICE_USAGE_CALL_INPUT : AUDIO_DEVICE_USAGE_MEDIA_OUTPUT;
    return OH_AudioManager_GetAudioRoutingManager(&manager_) ==
               AUDIOCOMMON_RESULT_SUCCESS &&
           manager_ &&
           OH_AudioRoutingManager_GetAvailableDevices(
               manager_, usage, &devices_) == AUDIOCOMMON_RESULT_SUCCESS &&
           devices_ && (devices_->size == 0 || devices_->descriptors);
  }

  base::span<OH_AudioDeviceDescriptor*> entries() const {
    // SAFETY: The routing manager owns exactly size entries until
    // ReleaseDevices.
    return UNSAFE_BUFFERS(base::span(devices_->descriptors, devices_->size));
  }

  OH_AudioDeviceDescriptor* Find(uint32_t id) const {
    for (auto* device : entries()) {
      uint32_t candidate = 0;
      if (device &&
          OH_AudioDeviceDescriptor_GetDeviceId(device, &candidate) ==
              AUDIOCOMMON_RESULT_SUCCESS &&
          candidate == id) {
        return device;
      }
    }
    return nullptr;
  }

 private:
  OH_AudioRoutingManager* manager_ = nullptr;
  OH_AudioDeviceDescriptorArray* devices_ = nullptr;
};

}  // namespace

bool GetSelectableOhosAudioDevices(bool input, AudioDeviceNames* names) {
  if (!names || !RoutingApi().ForDirection(input)) {
    return false;
  }
  AvailableDevices available;
  if (!available.Load(input)) {
    return false;
  }
  for (auto* device : available.entries()) {
    uint32_t id = 0;
    if (!device || OH_AudioDeviceDescriptor_GetDeviceId(device, &id) !=
                       AUDIOCOMMON_RESULT_SUCCESS) {
      continue;
    }
    std::string unique_id = base::NumberToString(id);
    if (std::any_of(names->begin(), names->end(), [&](const auto& entry) {
          return entry.unique_id == unique_id;
        })) {
      continue;
    }
    char* label = nullptr;
    if (OH_AudioDeviceDescriptor_GetDeviceDisplayName(device, &label) !=
            AUDIOCOMMON_RESULT_SUCCESS ||
        !label || !*label) {
      label = nullptr;
      if (OH_AudioDeviceDescriptor_GetDeviceName(device, &label) !=
          AUDIOCOMMON_RESULT_SUCCESS) {
        label = nullptr;
      }
    }
    names->emplace_back(label ? label : "", std::move(unique_id));
  }
  return true;
}

bool SelectOhosAudioInput(uint32_t id, OH_AudioCapturer* capturer) {
  auto* manager = RoutingApi().ForDirection(true);
  AvailableDevices available;
  if (!manager || !capturer || !available.Load(true)) {
    return false;
  }
  auto* device = available.Find(id);
  return device && RoutingApi().input(manager, capturer, device) ==
                       AUDIOCOMMON_RESULT_SUCCESS;
}

bool SelectOhosAudioOutput(uint32_t id, OH_AudioRenderer* renderer) {
  auto* manager = RoutingApi().ForDirection(false);
  AvailableDevices available;
  if (!manager || !renderer || !available.Load(false)) {
    return false;
  }
  auto* device = available.Find(id);
  return device && RoutingApi().output(manager, renderer, device) ==
                       AUDIOCOMMON_RESULT_SUCCESS;
}

}  // namespace media
