#!/usr/bin/env python3
"""Port all pinned 155 adaptations, reporting every conflicted repository."""
import hashlib
import importlib.util
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.dont_write_bytecode = True
spec = importlib.util.spec_from_file_location('snapshot155', ROOT / 'scripts/apply-155-snapshot.py')
snapshot = importlib.util.module_from_spec(spec)
spec.loader.exec_module(snapshot)


def main():
    src = Path(sys.argv[1]).resolve()
    if src != Path('/root/chromium-157/src'):
        raise ValueError('157 migration must never modify another engine tree')
    manifest = json.loads((ROOT / 'patches/migration-157/manifest.json').read_text())
    for entry in manifest['included_incremental_patches']:
        patch = ROOT / 'patches' / entry['patch']
        if hashlib.sha256(patch.read_bytes()).hexdigest() != entry['sha256']:
            raise ValueError(f'Shared patch changed; port it to the 157 snapshot: {patch.name}')
    def git(target, *args):
        return subprocess.check_output(['git', '-C', str(target), *args], text=True).strip()
    if git(src, 'rev-parse', 'HEAD') != manifest['target_revision']:
        raise ValueError('157 source revision mismatch')
    failures = []
    for entry in manifest['repositories']:
        target = src / entry['path']
        patch = ROOT / 'patches/migration-157' / entry['patch']
        digest = hashlib.sha256(patch.read_bytes()).hexdigest()
        if digest != entry['sha256']:
            raise ValueError(f'Patch checksum mismatch: {patch.name}')
        actual = git(target, 'rev-parse', 'HEAD')
        receipt = target / '.git/ohos-157-snapshot'
        expected = actual + ':' + digest
        if receipt.exists() and receipt.read_text().strip() == expected:
            continue
        try:
            # Unported repositories still need the 155 base; rebased patches
            # record the actual 157 DEPS revision as their source base.
            base_present = subprocess.run(
                ['git', '-C', str(target), 'cat-file', '-e',
                 entry['source_base'] + '^{commit}'], capture_output=True)
            if base_present.returncode:
                subprocess.run(['git', '-C', str(target), '-c', 'gc.auto=0', 'fetch',
                                '--depth=1', 'origin', entry['source_base']], check=True)
            snapshot.apply_snapshot(target, patch)
            receipt.write_text(expected + '\n')
        except subprocess.CalledProcessError as error:
            failures.append({'repository': entry['path'], 'target_revision': actual,
                             'returncode': error.returncode,
                             'conflicts': git(target, 'diff', '--name-only', '--diff-filter=U').splitlines()})
    report = ROOT / 'build-status/migration-157-conflicts.json'
    report.parent.mkdir(exist_ok=True)
    report.write_text(json.dumps(failures, indent=2) + '\n')
    if failures:
        raise SystemExit(f'157 adaptation has {len(failures)} repository failures; see {report}')


if __name__ == '__main__':
    main()
