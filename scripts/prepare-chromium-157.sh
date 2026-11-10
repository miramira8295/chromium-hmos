#!/usr/bin/env bash
# Preparation and native compilation are exclusively push-CI operations.
set -euo pipefail
[[ "${GITHUB_ACTIONS:-}" == true && "${GITHUB_REF_NAME:-}" == hmos-157-adapter ]] || exit 1
readonly repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
readonly root=/root/chromium-157
readonly src="$root/src"
readonly old=/root/chromium-154
readonly revision="${CHROMIUM_REVISION:?}"
[[ "${CHROMIUM_SRC:-}" == "$src" && "$revision" == 7d4508cbfffd289d7015f7703bce215d3ab123bf ]] || exit 1
mkdir -p "$repo_root/build-status"
exec > >(tee -a "$repo_root/build-status/preparation-157.log") 2>&1
# The global workflow concurrency lock excludes concurrent native builds.
# Never read from or mutate the independent 155 checkout/cache.
if [[ ! -d "$root" ]]; then
  [[ -d "$old/src/.git" ]] || { echo 'Missing retired 154 seed'; exit 1; }
  mv "$old" "$root"
fi
if [[ ! -f "$root/.retired-154-saved" ]]; then
  mkdir -p "$root/retired-154" "$root/sdk-links"
  git -C "$src" diff --binary HEAD > "$root/retired-154/native-working-tree.patch"
  git -C "$src" status --porcelain > "$root/retired-154/status.txt"
  cp "$root/.gclient" "$root/retired-154/gclient"
  cp "$src/out/ohos_arm64/args.gn" "$root/retired-154/args.gn"
  rsync -a "$src/ohos_sdk/" "$root/sdk-links/"
  if [[ -d "$src/out" ]]; then mv "$src/out" "$root/retired-154/out"; fi
  mkdir -p "$root/depot_tools"
  rsync -a "$src/third_party/depot_tools/" "$root/depot_tools/"
  touch "$root/.retired-154-saved"
fi
export PATH="$root/depot_tools:$PATH"
export DEPOT_TOOLS_UPDATE=0 DEPOT_TOOLS_METRICS=0
if [[ ! -f "$root/.deps-$revision" ]]; then
  git -C "$src" remote set-url origin https://github.com/chromium/chromium.git
  git -C "$src" -c gc.auto=0 fetch --depth=1 origin "$revision"
  git -C "$src" reset --hard "$revision"
  tools_revision=$(python3 - "$src/DEPS" <<'PY'
import re, sys
from pathlib import Path
s = Path(sys.argv[1]).read_text(); s = s[s.index("'src/third_party/depot_tools':"):]
print(re.search(r'[0-9a-f]{40}', s).group())
PY
  )
  git -C "$root/depot_tools" -c gc.auto=0 fetch --depth=1 origin "$tools_revision"
  git -C "$root/depot_tools" reset --hard "$tools_revision"
  sed -i 's#https://chromium.googlesource.com/chromium/src.git#https://github.com/chromium/chromium.git#' "$root/.gclient"
  (cd "$root" && gclient sync --nohooks --noprehooks --no-history --shallow --jobs=8 --reset --force -D --revision "src@$revision")
  touch "$root/.deps-$revision"
fi
mkdir -p "$src/ohos_sdk"
rsync -a "$root/sdk-links/" "$src/ohos_sdk/"
python3 "$repo_root/scripts/apply-157-snapshot.py" "$src"
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
