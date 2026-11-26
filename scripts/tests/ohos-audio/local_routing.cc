// API-26 functions exported only by the RTLD_LOCAL native library fixture.
#include "fake_ohaudio.h"

extern "C" {
OH_AudioCommon_Result OH_AudioManager_GetAudioDeviceEnhanceManager(
    OH_AudioDeviceEnhanceManager** out) {
  static OH_AudioDeviceEnhanceManager manager;
  *out = &manager;
  return AUDIOCOMMON_RESULT_SUCCESS;
}

OH_AudioCommon_Result OH_AudioDeviceEnhanceManager_IsEnhancedRoutingSupported(
    OH_AudioDeviceEnhanceManager* manager,
    bool* out) {
  *out = true;
  return AUDIOCOMMON_RESULT_SUCCESS;
}

OH_AudioCommon_Result
OH_AudioDeviceEnhanceManager_SelectInputDeviceForAudioCapturer(
    OH_AudioDeviceEnhanceManager* manager,
    OH_AudioCapturer* capturer,
    OH_AudioDeviceDescriptor* desc) {
  return capturer && desc && desc->id == 17
             ? AUDIOCOMMON_RESULT_SUCCESS
             : AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM;
}

OH_AudioCommon_Result
OH_AudioDeviceEnhanceManager_SelectOutputDeviceForAudioRenderer(
    OH_AudioDeviceEnhanceManager* manager,
    OH_AudioRenderer* renderer,
    OH_AudioDeviceDescriptor* desc) {
  return renderer && desc && desc->id == 18
             ? AUDIOCOMMON_RESULT_SUCCESS
             : AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM;
}
}  // extern "C"
