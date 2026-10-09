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

## System audio decoders (AC-3, DTS)

Chromium has no AC-3 or DTS decoder. On OHOS they are decoded by the
system's AVCodecKit audio decoders (`media/gpu/ohos/ohos_audio_decoder.*`),
hosted in the GPU process's media service and reached from the renderer
through `MojoAudioDecoder`, as video reaches `OhosVideoDecoder`. The
`audio_decoder` mojo media service is on for OHOS; FFmpeg is still tried
first, so every other audio format decodes in the renderer as before.

Support is whatever the device has: the GPU process asks AVCodecKit
(`OH_AVCodec_GetCapability`) and the renderer answers `canPlayType`, MSE and
MediaCapabilities from that, the way Windows and Mac answer for AC-3.
Never offered: E-AC-3, which the system has no decoder for; DTS:X and DTS
Express, which are not reported (only core DTS is); AC-4 and TrueHD, which
Chromium does not demux on OHOS.
The AC-3 and DTS MIME constants are resolved at run time (API 22 and 23),
so older systems load the engine and report neither.

Clear streams only. Encrypted audio waits for the WisePlay CDM, which will
hand the same decoder a key session.

As with AAC and H.264, enabling these formats is a technical capability, not
a licence.
