# Corresponding Source

This branch provides the source mapping for the test HAP with SHA-256:

`37968cb1082f8082dac6760e513a8a67b70a5ffacae5e0c75b830fd5633d05d6`

The corresponding source consists of:

1. Chromium revision `f405107495a07cb1bfcf687d4af8d91117098db6` and the
   third-party revisions pinned by its DEPS file.
2. `patches/chromium-150-harmonyos.patch`.
3. The complete `overlay/` and `external/` trees in this branch.
4. `config/args.plan_kirin_pc.gn` and the build instructions in `BUILDING.md`.
5. `SOURCE_MANIFEST.sha256`, which verifies every published regular file other
   than the manifest itself.

For at least three years from 2026-07-21, recipients of that binary may request
an electronic copy of these materials through this repository's GitHub issues.
The source is provided without charge. System SDKs and standard toolchain
components are not included; obtain them from their respective vendors.
