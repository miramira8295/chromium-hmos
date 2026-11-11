# Chromium 157 migration

## Build result

The 155 adaptation has been ported to Chromium **157.0.8103.77**, upstream
revision `7d4508cbfffd289d7015f7703bce215d3ab123bf`.

- Adapter branch: `hmos-157-adapter`.
- Built adapter commit: `23620d4463409da8033a457c3956a6c4c410f488`.
- [Native CI](https://github.com/miramira8295/chromium-hmos/actions/runs/42932045448)
  and [Adapter CI](https://github.com/miramira8295/chromium-hmos/actions/runs/42932045447)
  passed on 2026-11-11 (UTC).
- [Release](https://github.com/miramira8295/chromium-hmos/releases/tag/build-23620d44):
  unsigned `engine.har`, native debug symbols and `SHA256SUMS`.

The release tag points to the built adapter commit. No application HAP was
produced; Lumie or another downstream application must package and sign this
engine.

| Artifact identity | Value |
| --- | --- |
| HAR bytes | `146744405` |
| HAR SHA256 | `360654b8ebefc0a015f97cbdb5587badefe658877fda283bc83016788102bbe6` |
| Native Build ID | `96f825c82e0a4b7b986e8df0246c1eaa24b6dfe6` |

## Migration scope

The source adaptation is 155 commit
`60fa7e9617ebada93d9050d262a2155b11147943`. The manifest in
[`patches/migration-157/manifest.json`](../patches/migration-157/manifest.json)
records the main Chromium snapshot, nine dependency snapshots and thirteen
folded incremental patches. OHOS overlays are retained and ported to the new
interfaces. Later changes on the maintained 155 branch in this migration are
CI routing and release maintenance changes, not another native feature source.

Ports cover the existing phone, tablet and 2in1 integration; OpenGL, Ganesh
Vulkan, Graphite/Dawn, WebGPU and SharedImage paths; media decoding and HDR
metadata; and browser, authentication, sandbox, speech and WebNN interfaces.
The 157 API changes were handled without treating compilation as proof of
device behavior.

## Validation completed

- All 664 migration preflight object targets passed, followed by the full
  configured `gn_all` build and `libweb_engine.so` link through push CI.
- Engine HAR packaging passed. The packaged engine matches the native output
  byte for byte, and the V8 context snapshot matches the build output.
- Native phishing rule validation and subscription validation reported zero
  failures; site verdict state tests passed. Full subscription benchmarks ran.
- All ten snapshot application receipts match their pinned dependency heads
  and patch hashes; the migration conflict report is empty.
- Release HAR checksum matches the local CI artifact. The release includes
  matching native symbols and checksums.

## Checkout and cache isolation

154 CI is retired. Only `hmos-155-adapter` and `hmos-157-adapter` are accepted
by native build routing. Native compilation and packaging use GitHub Actions;
the migration did not invoke native builds manually.

The former `/root/chromium-154` checkout was renamed to `/root/chromium-157`.
Its source, dependency and download caches were reused. The former output,
arguments and working-tree patch are preserved under
`/root/chromium-157/retired-154/`. 157 has a fresh `out/ohos_arm64`, avoiding
mixing 154 generated files with the new compiler and dependency versions.
Subsequent 157 builds reuse that output incrementally.

`/root/chromium-155/src` and its existing output/cache were not modified by
the migration. Its native build log and `args.gn` timestamps remained at the
recorded baseline. 155 remains available for ongoing development; native
builds for the two branches use a shared serial queue and isolated directories.

## Pending device validation

157 is buildable, but is not yet declared stable. Phone and Pad regression
still needs to cover startup and process recovery, independent surfaces and
windows, GL/Ganesh/Graphite, WebGPU, SDR/P3/HDR transitions, HEVC Main10 buffer
import and zero-copy, sustained playback, fullscreen and background recovery.
Keep 155 maintained until these device checks pass.
