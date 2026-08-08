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

## Open media

The public configuration disables proprietary codecs. Sites using open codecs
can work through Chromium's media pipeline. Enabling AAC, H.264, or other
patent-encumbered formats for distribution is a separate licensing decision,
not merely a compiler fix.
