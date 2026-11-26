// Minimal host declarations for the OHAudio ABI exercised by the route tests.
#pragma once

#include <cstdint>

struct OH_AudioRoutingManager {};
struct OH_AudioDeviceEnhanceManager {};
struct OH_AudioCapturer {};
struct OH_AudioRenderer {};

enum OH_AudioCommon_Result {
  AUDIOCOMMON_RESULT_SUCCESS = 0,
  AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM = 6800101,
  AUDIOCOMMON_RESULT_ERROR_SYSTEM = 6800301
};
enum OH_AudioDevice_Usage {
  AUDIO_DEVICE_USAGE_MEDIA_OUTPUT = 1,
  AUDIO_DEVICE_USAGE_MEDIA_INPUT = 2,
  AUDIO_DEVICE_USAGE_CALL_OUTPUT = 4,
  AUDIO_DEVICE_USAGE_CALL_INPUT = 8
};
enum OH_AudioDevice_Role {
  AUDIO_DEVICE_ROLE_INPUT = 1,
  AUDIO_DEVICE_ROLE_OUTPUT = 2
};
struct OH_AudioDeviceDescriptor {
  unsigned id;
  const char* display_name;
  const char* name;
  OH_AudioDevice_Role role;
};
struct OH_AudioDeviceDescriptorArray {
  uint32_t size;
  OH_AudioDeviceDescriptor** descriptors;
};

extern "C" {
OH_AudioCommon_Result OH_AudioManager_GetAudioRoutingManager(
    OH_AudioRoutingManager**);
OH_AudioCommon_Result OH_AudioRoutingManager_GetAvailableDevices(
    OH_AudioRoutingManager*,
    OH_AudioDevice_Usage,
    OH_AudioDeviceDescriptorArray**);
OH_AudioCommon_Result OH_AudioRoutingManager_ReleaseDevices(
    OH_AudioRoutingManager*,
    OH_AudioDeviceDescriptorArray*);
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceId(
    OH_AudioDeviceDescriptor*,
    uint32_t*);
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceRole(
    OH_AudioDeviceDescriptor*,
    OH_AudioDevice_Role*);
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceDisplayName(
    OH_AudioDeviceDescriptor*,
    char**);
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceName(
    OH_AudioDeviceDescriptor*,
    char**);
OH_AudioCommon_Result OH_AudioManager_GetAudioDeviceEnhanceManager(
    OH_AudioDeviceEnhanceManager**);
OH_AudioCommon_Result OH_AudioDeviceEnhanceManager_IsEnhancedRoutingSupported(
    OH_AudioDeviceEnhanceManager*,
    bool*);
OH_AudioCommon_Result
OH_AudioDeviceEnhanceManager_SelectInputDeviceForAudioCapturer(
    OH_AudioDeviceEnhanceManager*,
    OH_AudioCapturer*,
    OH_AudioDeviceDescriptor*);
OH_AudioCommon_Result
OH_AudioDeviceEnhanceManager_SelectOutputDeviceForAudioRenderer(
    OH_AudioDeviceEnhanceManager*,
    OH_AudioRenderer*,
    OH_AudioDeviceDescriptor*);
}
