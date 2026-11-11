# Build Notes

## Prerequisites

- A complete Chromium checkout with `depot_tools` and all DEPS synchronized.
- Linux or WSL for Chromium native compilation. On Apple silicon macOS, use an
  x86_64 container as described in
  [docs/BUILDING_MACOS_CONTAINER.md](docs/BUILDING_MACOS_CONTAINER.md).
- A compatible HarmonyOS SDK/NDK and Rust toolchain supplied by the developer.
- DevEco Studio/Hvigor for the ArkUI HAP shell.

## Isolated CI source trees

This branch pins Chromium **157.0.8103.77** at
`7d4508cbfffd289d7015f7703bce215d3ab123bf`. Native compilation, HAR packaging
and CI checks passed on 2026-11-11; see the
[migration record](docs/CHROMIUM_157_MIGRATION.md). Device regression remains
pending, and 155 remains maintained until 157 passes it.

| Adapter branch | Native source | Native output |
| --- | --- | --- |
| `hmos-155-adapter` | `/root/chromium-155/src` | its existing `out/ohos_arm64` |
| `hmos-157-adapter` | `/root/chromium-157/src` | its new `out/ohos_arm64` |

154 CI is retired. Native compilation runs through push-triggered GitHub
Actions. Push changes to the corresponding adapter branch;
`select-ci-engine.py` rejects other refs. Both branches share a serial native
build queue, while 157 preparation rejects any source path except its own.
Do not invoke the native build manually on the runner.

## Chromium 157 preparation

`scripts/prepare-chromium-157.sh` repurposes `/root/chromium-154` by renaming
it to `/root/chromium-157`, preserving source, dependency and download caches.
The previous outputs, native diff and arguments are archived under
`/root/chromium-157/retired-154/`. A fresh 157 output directory avoids carrying
154 generated files across compiler and dependency changes. Repeated 157 CI
runs reuse their completed objects. The separate 155 tree is never a source
or destination of this migration.

The job synchronizes the pinned 157 DEPS, restores its saved SDK links and
verifies `patches/migration-157/manifest.json` before applying all snapshots.
The manifest also hashes shared incremental patches already folded into the
157 snapshot: changing one requires porting it into 157, rather than silently
ignoring it or replaying a patch based on an older release. Overlay sources
are synchronized by content. Unchanged inputs retain timestamps on retries.

155 preparation continues using `patches/migration-155/`. Its existing tree
and arguments are preserved; only a fresh bootstrap may seed independent
source files from 157. `scripts/apply-adapter.sh` and `patches/deps/series`
remain historical 154 tooling.

## Native build

CI generates `out/ohos_arm64` and validates V8 PGO/context snapshots, compiles
critical OHOS graphics, video, certificate and browser objects first, and
then builds `gn_all`. Compiler diagnostics are retained in `build-status/`.
Native rule validation and engine HAR packaging follow a successful build.

The build uses Chromium branding and includes the V8 JIT compilers
(Sparkplug, Maglev and TurboFan). At launch the runner probes whether the
process may map executable memory: where it may -- tablets and 2in1, and a
phone running a debug-signed package -- JIT is on; where it may not -- a
released phone package -- or when the startup configuration asks for it, V8
runs with `--jitless` and JavaScript is interpreted (about five times slower
on a simple loop on a phone). `aboutInfo.jitEnabled` reports the current
launch.

WebAssembly needs the DrumBrake interpreter when V8 is JITless, so the build
carries it (`v8_enable_drumbrake = true`, with its bounds checks): a JITless
launch still runs WebAssembly, interpreted, through `--wasm-jitless`.
It also enables the Chromium AAC/H.264 build switches used by the validated
test package. Those switches do not grant codec patent or distribution rights;
distributors remain responsible for the licenses required in their markets.

Each bootstrap copies `config/args.plan_kirin_pc.gn` only when the output
has no arguments file. Subsequent builds retain that tree's arguments; the
profile helper synchronizes the repository's V8 PGO and context snapshot
choices. 157 preparation removes the build argument removed upstream; all other
persistent arguments remain in that engine’s own output directory.

## HAP

The ArkUI project is under `chromium-ui`. Configure signing locally in DevEco
Studio. Do not commit generated signing blocks or `.cer`, `.p12`, or `.p7b`
files. The native build must be staged into the ArkUI project before running
`devecocli build --product default --build-mode release`.

This publication is a source snapshot, not a promise that every third-party
machine has the same private SDK build used for the original test package.
