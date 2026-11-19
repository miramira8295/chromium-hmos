#!/usr/bin/env bash
# Runs in a systemd control group. No cloud/GitHub credentials reach this host.
set -euo pipefail
bootstrap="$1"
exec > >(tee -a "$bootstrap/build.log") 2>&1
task=''
repo=''
status=''
finish() {
  local rc=$?
  trap - EXIT
  set +eu
  if [[ -d "$task" ]]; then
    mkdir -p "$status"
    if [[ -d "$repo/build-status" ]]; then
      cp -a "$repo/build-status/." "$status/"
    fi
    if [[ -f "$root/ci-build.log" ]]; then
      cp "$root/ci-build.log" "$status/native-build.log"
    fi
    if [[ ! -f "$status/latest.json" ]]; then
      printf '{"status":"failed","exit_code":%s}\n' "$rc" > "$status/latest.json"
    fi
    sync -f "$task"
  fi
  printf 'Remote task exited %s\n' "$rc"
  printf '%s\n' "$rc" > "$bootstrap/exit-code.tmp"
  mv "$bootstrap/exit-code.tmp" "$bootstrap/exit-code"
  exit "$rc"
}
trap finish EXIT

# Parse the controller's JSON using shell quoting, not shell interpolation.
request_exports="$(python3 - "$bootstrap/request.json" <<'PY'
import json,re,shlex,sys
c=json.load(open(sys.argv[1]))
assert re.fullmatch(r'[0-9a-f]{40}', c['sha'])
assert re.fullmatch(r'\d+-\d+', c['run_key'])
assert c['branch'] == f'hmos-{int(c["major"])}-adapter'
values={
 'GITHUB_SHA':c['sha'], 'GITHUB_REF_NAME':c['branch'], 'GITHUB_ACTIONS':'true',
 'CLOUD_RUN_KEY':c['run_key'], 'CLOUD_DISK_UUID':c['disk_uuid'],
 'CHROMIUM_MAJOR':str(int(c['major'])), 'NINJA_JOBS':str(int(c['jobs'])),
 'CLOUD_PACKAGE':'true' if c['package'] else 'false',
 'CRASH_BUILD_ID':c['crash_build_id'], 'CRASH_ADDRESSES':c['crash_addresses']}
for key,value in values.items(): print('export '+key+'='+shlex.quote(value))
PY
)"
eval "$request_exports"
root="/root/chromium-$CHROMIUM_MAJOR"
task="$root/ci/cloud/$CLOUD_RUN_KEY"
repo="$task/repo"
status="$task/status"

mkdir -p "$root"
if mountpoint -q "$root"; then
  [[ "$(findmnt -n -o UUID --target "$root")" == "$CLOUD_DISK_UUID" ]] || {
    echo 'Wrong filesystem mounted at build root'; exit 1;
  }
else
  mapfile -t devices < <(blkid -t "UUID=$CLOUD_DISK_UUID" -o device)
  [[ ${#devices[@]} == 1 ]] || { echo 'Expected exactly one retained filesystem'; exit 1; }
  mount "${devices[0]}" "$root"
fi
[[ -d "$root/src/.git" && -f "$root/src/out/ohos_arm64/args.gn" ]] || {
  echo 'Retained disk does not contain a prepared build tree'; exit 1;
}
mkdir -p "$root/ci" "$task" "$status"
exec 9>"$root/ci/build.lock"
flock -n 9 || { echo 'A manual or CI build already owns the data disk'; exit 75; }

# Move the log onto the retained disk before building, while keeping a stable
# bootstrap path for the controller. Re-open stdout after replacing the link.
cp "$bootstrap/build.log" "$task/build.log"
rm "$bootstrap/build.log"
ln -s "$task/build.log" "$bootstrap/build.log"
exec >> "$task/build.log" 2>&1
cp "$bootstrap/request.json" "$task/request.json"
printf 'Preparing commit %s with -j%s\n' "$GITHUB_SHA" "$NINJA_JOBS"
if [[ -f "$root/.swap" ]] && ! swapon --noheadings --raw --show=NAME | grep -Fxq "$root/.swap"; then
  swapon "$root/.swap"
fi
export PATH="/root/.cargo/bin:$root/toolchain/harmonyos-clt/command-line-tools/tool/node/bin:$root/depot_tools:$PATH"
export DEPOT_TOOLS_UPDATE=0 DEPOT_TOOLS_METRICS=0
export DEVECO_CLT_HOME="$root/toolchain/harmonyos-clt/command-line-tools"
export JAVA_HOME
JAVA_HOME="$(dirname "$(dirname "$(readlink -f "$(command -v javac)")")")"
export SKIP_HAP=1
if [[ "$CLOUD_PACKAGE" == false ]]; then export SKIP_PACKAGE=1; fi

# An isolated task checkout preserves any manual changes in the old repo/.
git clone --no-checkout "$bootstrap/repo.bundle" "$repo"
git -C "$repo" checkout --detach "$GITHUB_SHA"
cd "$repo"
mkdir -p build-status
if [[ -f "$root/ci-build.log" ]]; then
  cp "$root/ci-build.log" build-status/previous-native-build.log
fi
engine_exports="$(python3 scripts/select-ci-engine.py | sed 's/^/export /')"
eval "$engine_exports"
bash "scripts/prepare-chromium-$CHROMIUM_MAJOR.sh"
python3 .github/cloud/cache-health.py "$CHROMIUM_SRC/out/ohos_arm64" build-status/invalid-cache-outputs.json
bash scripts/symbolize-previous-native-build.sh
bash scripts/ci-incremental-build.sh
bash scripts/test-url-protection-native.sh

mkdir -p "$task/artifacts"
python3 - "$repo" "$task/artifacts" "$CHROMIUM_SRC" "$CLOUD_PACKAGE" <<'PY'
import hashlib,json,os,shutil,subprocess,sys
from pathlib import Path
repo,artifacts,src=map(Path,sys.argv[1:4]); packaged=sys.argv[4]=='true'
status=json.loads((repo/'build-status/latest.json').read_text())
assert status['status']=='ok'
sources=[]
if packaged:
    marker=repo/'build-status/har-path.txt'
    if not marker.is_file(): raise RuntimeError('HAR requested but packaging produced none')
    har=Path(marker.read_text().strip()).resolve()
    assert har.is_relative_to(repo) and har.is_file() and har.suffix=='.har'
    sources.append(har)
symbols=src/'out/ohos_arm64/exe.unstripped/libweb_engine.so'
if symbols.is_file():
    target=artifacts/'libweb_engine.unstripped.so.gz'
    with target.open('wb') as output:
        subprocess.run(['gzip','-1','-c',str(symbols)],stdout=output,check=True)
for source in sources: shutil.copy2(source,artifacts/source.name)
files=[]
for p in sorted(artifacts.iterdir()):
    if p.is_file():
        with p.open('rb') as stream: digest=hashlib.file_digest(stream,'sha256').hexdigest()
        files.append({'name':p.name,'bytes':p.stat().st_size,'sha256':digest})
manifest={'commit':os.environ['GITHUB_SHA'],'build':status,'files':files}
(artifacts/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
PY
