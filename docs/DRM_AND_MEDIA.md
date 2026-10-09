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

These are clear streams. Encrypted AC-3 or DTS is not offered: WisePlay
(below) decrypts only AAC audio.

As with AAC and H.264, enabling these formats is a technical capability, not
a licence.

## WisePlay (EME `com.wiseplay.drm`)

HarmonyOS ships WisePlay in DRM Kit. The engine exposes it to pages through
standard EME, the way Chrome on Android exposes MediaDrm's platform key
systems:

- **CDM.** `OhosCdm` (`media/gpu/ohos/ohos_cdm.*`) runs in the GPU process's
  media service (the `cdm` mojo media service is on for OHOS) and maps EME
  onto `OH_MediaKeySystem_*` and `OH_MediaKeySession_*`. All EME sessions of
  one `MediaKeys` share one DRM Kit session, because decoders decrypt with a
  single session, as ArkWeb does for WisePlay.
- **Decryption.** There is no `Decryptor`. `OhosVideoDecoder` (H.264, HEVC)
  and `OhosAudioDecoder` (AAC) call `OH_*_SetDecryptionConfig` with that
  session and attach each sample's key ID, IV, subsamples and `cbcs` pattern
  as `OH_AVCencInfo` (`ohos_cenc_info.*`). Encrypted samples wait
  (`WaitingReason::kNoDecryptionKey`) until a license is in. Clear AAC still
  decodes in the renderer; only encrypted AAC reaches the system decoder.
- **Registration.** The browser registers the key system without capabilities;
  the first page that asks makes `CdmRegistryImpl` query DRM Kit
  (`content/browser/media/key_system_support_ohos.cc`): `IsSupported`, MP4
  video and audio, and whether there is a hardware HEVC decoder. On a device
  without WisePlay, `requestMediaKeySystemAccess` fails.
- **Device certificate.** When DRM Kit has none, `OhosCdm` downloads it
  before creating its session, through the browser's `ProvisionFetcher`
  (no cookies), and only then resolves `createMediaKeys()`.

Limits for now:

| What | Status |
| --- | --- |
| Security level | Software (`CONTENT_PROTECTION_LEVEL_SW_CRYPTO`) only. Hardware levels need DRM Kit's secure video path, which renders past the GPU and so past the zero-copy compositor. Robustness `""`, `SW_SECURE_CRYPTO` and `SW_SECURE_DECODE` are accepted. |
| Session types | `temporary` only; `persistent-license`, `load()` and `remove()` are rejected. |
| Init data | `cenc` (PSSH boxes). Longer than DRM Kit's 2048 bytes, only WisePlay's boxes (system ID `3d5e6d35-9b9a-41e8-b843-dd3c6e72c42c`) are passed. |
| Codecs | H.264, HEVC and AAC in MP4, `cenc` and `cbcs`. DRM Kit decrypts nothing else. |
| Distinctive identifier | Not offered: the protected media identifier permission does not exist on this platform yet. Pages that ask for it `optional` (Shaka's and dash.js's default) play; `required` fails. |
| Incognito | Not offered, as Android does for its platform key systems. |

Logs: filter `OHOS CDM`, `OHOS key system` and `decrypting`.
