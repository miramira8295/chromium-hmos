// Test the production monitor and callback with a deterministic audio task
// queue.
#include <cassert>
#include <functional>
#include <memory>
#include <mutex>
#include <span>
#include <utility>
#include <vector>

#include "fake_ohaudio.h"

#define UNSAFE_BUFFERS(...) __VA_ARGS__
#define GUARDED_BY(lock)
#define DCHECK(condition) assert(condition)

namespace base {
using std::span;
using Lock = std::mutex;
using AutoLock = std::lock_guard<Lock>;

template <typename Signature>
struct RepeatingCallback;
template <typename... Args>
struct RepeatingCallback<void(Args...)> : std::function<void(Args...)> {
  using std::function<void(Args...)>::function;
  void Run(Args... args) const { (*this)(args...); }
  void Reset() { *this = nullptr; }
};
using RepeatingClosure = RepeatingCallback<void()>;

template <typename T>
struct NoDestructor {
  T value;
  T& operator*() { return value; }
};

struct TaskRunner {
  std::vector<RepeatingClosure> tasks;
  bool BelongsToCurrentThread() const { return true; }
  void Drain() {
    auto pending = std::move(tasks);
    for (auto& task : pending)
      task.Run();
  }
};
TaskRunner runner;

template <typename T>
struct WeakPtrFactory {
  T* owner;
  std::shared_ptr<int> token = std::make_shared<int>(0);
  auto GetWeakPtr() { return std::make_pair(std::weak_ptr<int>(token), owner); }
  void InvalidateWeakPtrs() { token.reset(); }
};

template <typename T>
RepeatingCallback<void(bool)> BindRepeating(
    void (T::*method)(bool),
    std::pair<std::weak_ptr<int>, T*> weak) {
  return [=](bool output_changed) {
    if (!weak.first.expired())
      (weak.second->*method)(output_changed);
  };
}
RepeatingCallback<void(bool)> BindPostTask(TaskRunner* runner,
                                           RepeatingCallback<void(bool)> task) {
  return [=](bool out) { runner->tasks.push_back([=] { task.Run(out); }); };
}
struct SystemMonitor {
  enum DeviceType { DEVTYPE_AUDIO };
  static SystemMonitor* Get() {
    static SystemMonitor monitor;
    return &monitor;
  }
  void ProcessDevicesChanged(DeviceType type) {
    assert(type == DEVTYPE_AUDIO);
    ++notifications;
  }
  int notifications = 0;
};
}  // namespace base

enum OH_AudioDevice_ChangeType {
  AUDIO_DEVICE_CHANGE_TYPE_CONNECT,
  AUDIO_DEVICE_CHANGE_TYPE_DISCONNECT
};
enum OH_AudioDevice_Flag { AUDIO_DEVICE_FLAG_ALL };
using DeviceChanged = int32_t (*)(OH_AudioDevice_ChangeType,
                                  OH_AudioDeviceDescriptorArray*);
OH_AudioRoutingManager manager;
DeviceChanged listener = nullptr;
bool can_register = true;
int registrations = 0;
int releases = 0;

OH_AudioCommon_Result OH_AudioManager_GetAudioRoutingManager(
    OH_AudioRoutingManager** out) {
  *out = &manager;
  return AUDIOCOMMON_RESULT_SUCCESS;
}
OH_AudioCommon_Result OH_AudioRoutingManager_ReleaseDevices(
    OH_AudioRoutingManager* owner,
    OH_AudioDeviceDescriptorArray* list) {
  assert(owner == &manager && list);
  delete list;
  ++releases;
  return AUDIOCOMMON_RESULT_SUCCESS;
}
OH_AudioCommon_Result OH_AudioRoutingManager_RegisterDeviceChangeCallback(
    OH_AudioRoutingManager* owner,
    OH_AudioDevice_Flag flags,
    DeviceChanged callback) {
  assert(owner == &manager && flags == AUDIO_DEVICE_FLAG_ALL && !listener);
  if (!can_register)
    return AUDIOCOMMON_RESULT_ERROR_SYSTEM;
  ++registrations;
  listener = callback;
  return AUDIOCOMMON_RESULT_SUCCESS;
}
OH_AudioCommon_Result OH_AudioRoutingManager_UnregisterDeviceChangeCallback(
    OH_AudioRoutingManager* owner,
    DeviceChanged callback) {
  assert(owner == &manager && callback == listener);
  listener = nullptr;
  return AUDIOCOMMON_RESULT_SUCCESS;
}

namespace media {
struct AudioManagerBase {
  int output_changes = 0;
  void NotifyAllOutputDeviceChangeListeners() { ++output_changes; }
  base::TaskRunner* GetTaskRunner() { return &base::runner; }
  void ShutdownOnAudioThread() {}
};
struct AudioManagerOhos : AudioManagerBase {
  bool monitoring_devices_ = false;
  base::WeakPtrFactory<AudioManagerOhos> weak_factory_{this};
  void StartDeviceMonitor();
  void OnDevicesChanged(bool);
  void ShutdownOnAudioThread();
};
#include "monitor_methods.inc"
}  // namespace media

OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceRole(
    OH_AudioDeviceDescriptor* device,
    OH_AudioDevice_Role* role) {
  *role = device->role;
  return AUDIOCOMMON_RESULT_SUCCESS;
}
int main() {
  OH_AudioDeviceDescriptor speaker{9, "Speaker", "Speaker",
                                   AUDIO_DEVICE_ROLE_OUTPUT};
  OH_AudioDeviceDescriptor mic{7, "Mic", "Mic", AUDIO_DEVICE_ROLE_INPUT};
  OH_AudioDeviceDescriptor* outputs[] = {&speaker};
  OH_AudioDeviceDescriptor* inputs[] = {&mic};
  media::AudioManagerOhos audio;
  auto* system = base::SystemMonitor::Get();
  can_register = false;
  audio.StartDeviceMonitor();
  assert(!listener);
  can_register = true;
  audio.StartDeviceMonitor();
  audio.StartDeviceMonitor();
  assert(registrations == 1 && listener);
  DeviceChanged in_flight = listener;
  listener(AUDIO_DEVICE_CHANGE_TYPE_CONNECT,
           new OH_AudioDeviceDescriptorArray{1, outputs});
  assert(releases == 1 && audio.output_changes == 0);
  base::runner.Drain();
  assert(audio.output_changes == 1 && system->notifications == 1);
  listener(AUDIO_DEVICE_CHANGE_TYPE_CONNECT,
           new OH_AudioDeviceDescriptorArray{1, inputs});
  base::runner.Drain();
  assert(audio.output_changes == 1 && system->notifications == 2);
  listener(AUDIO_DEVICE_CHANGE_TYPE_DISCONNECT,
           new OH_AudioDeviceDescriptorArray{});
  audio.ShutdownOnAudioThread();
  assert(!listener);
  in_flight(AUDIO_DEVICE_CHANGE_TYPE_CONNECT,
            new OH_AudioDeviceDescriptorArray{});
  base::runner.Drain();
  assert(releases == 4 && audio.output_changes == 1 &&
         system->notifications == 2);
  media::AudioManagerOhos next_manager;
  next_manager.StartDeviceMonitor();
  assert(listener && registrations == 2);
  next_manager.ShutdownOnAudioThread();
}
