# DRM and media policy

## Widevine

`enable_widevine=true` does not provide a Widevine CDM. Upstream Chromium only
registers the library CDM on its supported desktop and ChromeOS platforms, and
Google distributes production Widevine access under a separate agreement.
This adapter therefore keeps `enable_widevine=false` until all of the following
are available:

1. a licensed HarmonyOS arm64 CDM and any required OEMCrypto implementation;
2. an approved packaging and provisioning path that does not redistribute the
   Chrome CDM;
3. an OHOS CDM registration implementation and on-device EME tests;
4. permission to ship the audio/video codecs required by the target service.

The project will not copy a CDM from Chrome, bypass DRM, or report Apple Music
playback based only on a GN flag. Apple Music must be validated on a physical
device after both EME and the required codecs are present.

## Codec configuration

The tested configuration enables Chromium's AAC/H.264 build switches so the
HarmonyOS media path can be exercised on physical devices. This is only a
technical capability flag. It does not grant patent, content, or distribution
rights, and downstream distributors must make their own licensing decision.
Open codecs continue to use Chromium's normal media pipeline.
