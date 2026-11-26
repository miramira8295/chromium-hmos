// Exercise the production route implementation against public OHAudio calls.
#include <dlfcn.h>

#include <cassert>
#include <vector>

#include "fake_ohaudio.h"
#include "media/audio/ohos/ohos_audio_route.h"

namespace {
OH_AudioRoutingManager routing;
OH_AudioDeviceEnhanceManager enhance;
OH_AudioCapturer mic;
OH_AudioRenderer renderer;
OH_AudioDeviceDescriptor headset_mic{17, "USB Microphone", "USB",
                                     AUDIO_DEVICE_ROLE_INPUT};
OH_AudioDeviceDescriptor speaker{9, "Speaker", "Built-in",
                                 AUDIO_DEVICE_ROLE_OUTPUT};
OH_AudioDeviceDescriptor headset_sink{18, "", "USB Headset",
                                      AUDIO_DEVICE_ROLE_OUTPUT};
std::vector<OH_AudioDeviceDescriptor*> microphones{&headset_mic};
std::vector<OH_AudioDeviceDescriptor*> outputs{&speaker, &headset_sink};
bool supported = true;
bool refuse_selection = false;
bool malformed_array = false;
int outstanding_arrays = 0;
unsigned chosen_input = 0;
unsigned chosen_output = 0;
}  // namespace

extern "C" {
OH_AudioCommon_Result OH_AudioManager_GetAudioRoutingManager(
    OH_AudioRoutingManager** out) {
  *out = &routing;
  return AUDIOCOMMON_RESULT_SUCCESS;
}
OH_AudioCommon_Result OH_AudioRoutingManager_GetAvailableDevices(
    OH_AudioRoutingManager* manager,
    OH_AudioDevice_Usage usage,
    OH_AudioDeviceDescriptorArray** out) {
  assert(manager == &routing);
  assert(usage == AUDIO_DEVICE_USAGE_CALL_INPUT ||
         usage == AUDIO_DEVICE_USAGE_MEDIA_OUTPUT);
  auto& devices =
      usage == AUDIO_DEVICE_USAGE_CALL_INPUT ? microphones : outputs;
  *out = new OH_AudioDeviceDescriptorArray{
      static_cast<uint32_t>(devices.size()),
      malformed_array ? nullptr : devices.data()};
  ++outstanding_arrays;
  return AUDIOCOMMON_RESULT_SUCCESS;
}
OH_AudioCommon_Result OH_AudioRoutingManager_ReleaseDevices(
    OH_AudioRoutingManager* manager,
    OH_AudioDeviceDescriptorArray* array) {
  assert(manager == &routing && outstanding_arrays > 0);
  delete array;
  --outstanding_arrays;
  return AUDIOCOMMON_RESULT_SUCCESS;
}
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceId(
    OH_AudioDeviceDescriptor* desc,
    uint32_t* out) {
  *out = desc->id;
  return AUDIOCOMMON_RESULT_SUCCESS;
}
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceRole(
    OH_AudioDeviceDescriptor* desc,
    OH_AudioDevice_Role* out) {
  *out = desc->role;
  return AUDIOCOMMON_RESULT_SUCCESS;
}
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceDisplayName(
    OH_AudioDeviceDescriptor* desc,
    char** out) {
  *out = const_cast<char*>(desc->display_name);
  return AUDIOCOMMON_RESULT_SUCCESS;
}
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceName(
    OH_AudioDeviceDescriptor* desc,
    char** out) {
  *out = const_cast<char*>(desc->name);
  return AUDIOCOMMON_RESULT_SUCCESS;
}
#ifndef WITHOUT_ENHANCED_ROUTING
OH_AudioCommon_Result OH_AudioManager_GetAudioDeviceEnhanceManager(
    OH_AudioDeviceEnhanceManager** out) {
  *out = &enhance;
  return AUDIOCOMMON_RESULT_SUCCESS;
}
OH_AudioCommon_Result OH_AudioDeviceEnhanceManager_IsEnhancedRoutingSupported(
    OH_AudioDeviceEnhanceManager* manager,
    bool* out) {
  assert(manager == &enhance);
  *out = supported;
  return AUDIOCOMMON_RESULT_SUCCESS;
}
OH_AudioCommon_Result
OH_AudioDeviceEnhanceManager_SelectInputDeviceForAudioCapturer(
    OH_AudioDeviceEnhanceManager* manager,
    OH_AudioCapturer* capturer,
    OH_AudioDeviceDescriptor* desc) {
  assert(manager == &enhance && capturer == &mic && outstanding_arrays > 0);
  if (refuse_selection) {
    return AUDIOCOMMON_RESULT_ERROR_SYSTEM;
  }
  chosen_input = desc->id;
  return AUDIOCOMMON_RESULT_SUCCESS;
}
OH_AudioCommon_Result
OH_AudioDeviceEnhanceManager_SelectOutputDeviceForAudioRenderer(
    OH_AudioDeviceEnhanceManager* manager,
    OH_AudioRenderer* stream,
    OH_AudioDeviceDescriptor* desc) {
  assert(manager == &enhance && stream == &renderer && outstanding_arrays > 0);
  if (refuse_selection) {
    return AUDIOCOMMON_RESULT_ERROR_SYSTEM;
  }
  chosen_output = desc->id;
  return AUDIOCOMMON_RESULT_SUCCESS;
}
#endif
}  // extern "C"

int main() {
  using namespace media;
  AudioDeviceNames visible;
#ifdef TEST_LOCAL_LIBRARY
  const char* symbol = "OH_AudioManager_GetAudioDeviceEnhanceManager";
  void* library = dlopen("libohaudio.so", RTLD_NOW | RTLD_LOCAL);
  assert(library && dlsym(library, symbol) && !dlsym(RTLD_DEFAULT, symbol));
  assert(GetSelectableOhosAudioDevices(true, &visible));
  assert(visible.size() == 1 && visible.front().unique_id == "17");
  assert(SelectOhosAudioInput(17, &mic));
  assert(SelectOhosAudioOutput(18, &renderer));
  assert(!SelectOhosAudioOutput(9, &renderer));
  assert(!dlsym(RTLD_DEFAULT, symbol) && outstanding_arrays == 0);
  dlclose(library);
  return 0;
#endif
  visible.emplace_back("Default", "default");
  supported = false;
  assert(!GetSelectableOhosAudioDevices(true, &visible));
  assert(visible.size() == 1 && visible.front().unique_id == "default");
  assert(!SelectOhosAudioInput(17, &mic));
  assert(!SelectOhosAudioOutput(18, &renderer));
#ifndef WITHOUT_ENHANCED_ROUTING
  supported = true;
  microphones = {nullptr, &headset_mic, &headset_mic};
  assert(GetSelectableOhosAudioDevices(true, &visible));
  assert(visible.size() == 2 && visible.back().unique_id == "17");
  assert(visible.back().device_name == "USB Microphone");
  visible.clear();
  assert(GetSelectableOhosAudioDevices(false, &visible));
  assert(visible.size() == 2 && visible.back().unique_id == "18");
  assert(visible.back().device_name == "USB Headset");
  assert(SelectOhosAudioInput(17, &mic) && chosen_input == 17);
  assert(SelectOhosAudioOutput(18, &renderer) && chosen_output == 18);
  assert(!SelectOhosAudioInput(18, &mic));
  refuse_selection = true;
  assert(!SelectOhosAudioOutput(9, &renderer));
  assert(chosen_output == 18);
  refuse_selection = false;
  // The USB device was unplugged between enumeration and opening a stream.
  microphones.clear();
  outputs = {&speaker};
  visible.clear();
  assert(GetSelectableOhosAudioDevices(false, &visible));
  assert(visible.size() == 1 && visible.front().unique_id == "9");
  assert(!SelectOhosAudioOutput(18, &renderer));
  assert(!SelectOhosAudioInput(17, &mic));
  microphones = {&headset_mic};
  assert(SelectOhosAudioInput(17, &mic));
  malformed_array = true;
  visible.clear();
  assert(!GetSelectableOhosAudioDevices(true, &visible) && visible.empty());
  assert(!SelectOhosAudioInput(17, &mic));
#endif
  assert(outstanding_arrays == 0);
}
