#!/usr/bin/env bash
# Preparation and native compilation are exclusively push-CI operations.
set -euo pipefail
major="${1:?engine milestone required}"
[[ "$major" == 157 || "$major" == 158 ]] || exit 1
[[ "${GITHUB_REF_NAME:-}" == "hmos-$major-adapter" ]] || exit 1
[[ "$major" == 158 || "${GITHUB_ACTIONS:-}" == true ]] || exit 1
repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
readonly repo_root
readonly root="/root/chromium-$major"
readonly src="$root/src"
readonly revision="${CHROMIUM_REVISION:?}"
[[ "${CHROMIUM_SRC:-}" == "$src" && "$revision" == "$(python3 -c 'import json,sys; print(json.load(open(sys.argv[1]))["revision"])' "$repo_root/config/engines/$major.json")" ]] || exit 1
mkdir -p "$repo_root/build-status"
exec > >(tee -a "$repo_root/build-status/preparation-$major.log") 2>&1
# The retained disk is provisioned separately. Daily CI must never move out/
# into a retired-engine directory, reset a source tree, or run gclient sync
# behind an existing snapshot receipt. New engine revisions require explicit
# bootstrap on a suitable retained disk.
mountpoint -q "$root" || { echo 'Build data disk is not mounted'; exit 1; }
[[ -d "$src/.git" && -f "$root/.gclient" ]] || { echo 'Prepared Chromium tree is missing'; exit 1; }
[[ "$(git -C "$src" rev-parse HEAD)" == "$revision" ]] || {
  echo 'Source revision differs from the pin; bootstrap this engine explicitly'; exit 1;
}
[[ -x "$root/depot_tools/gclient" ]] || { echo 'Persistent depot_tools are missing'; exit 1; }
export PATH="$root/depot_tools:$PATH"
export DEPOT_TOOLS_UPDATE=0 DEPOT_TOOLS_METRICS=0
mkdir -p "$src/ohos_sdk"
if [[ -d "$root/sdk-links" ]]; then
  rsync -a "$root/sdk-links/" "$src/ohos_sdk/"
fi
[[ -d "$src/ohos_sdk/native/sysroot" ]] || { echo 'HarmonyOS native SDK is missing'; exit 1; }
python3 "$repo_root/scripts/apply-$major-snapshot.py" "$src"
rsync -a --checksum --no-times "$repo_root/overlay/" "$src/"
mkdir -p "$root/deps_code/webview"
rsync -a --checksum --no-times "$repo_root/external/deps_code/webview/" "$root/deps_code/webview/"
if [[ ! -f "$root/.hooks-$revision" ]]; then
  (cd "$root" && gclient runhooks)
  touch "$root/.hooks-$revision"
fi
mkdir -p "$src/out/ohos_arm64"
if [[ ! -f "$src/out/ohos_arm64/args.gn" ]]; then
  cp "$repo_root/config/args.plan_kirin_pc.gn" "$src/out/ohos_arm64/args.gn"
fi
# Chromium 157 removed this build argument; provisioning is no longer gated
# by it. Retain all other persistent 157 build choices, including the PGO path.
python3 - "$src/out/ohos_arm64/args.gn" <<'PY'
from pathlib import Path
import re, sys
path = Path(sys.argv[1])
before = path.read_text()
after = re.sub(r'^\s*enterprise_client_certificates\s*=.*\n', '', before, flags=re.M)
if after != before:
    path.write_text(after)
PY
