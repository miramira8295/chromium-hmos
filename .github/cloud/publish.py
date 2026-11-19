#!/usr/bin/env python3
"""Publish only locally recovered and checksum-verified cloud build results."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
import tarfile
import tempfile

ROOT = Path(__file__).resolve().parents[2]


def call(*args, **kwargs):
    return subprocess.run(args, cwd=ROOT, check=True, text=True, **kwargs)


def release():
    artifacts = ROOT / 'cloud-artifacts'
    manifest = json.loads((artifacts / 'manifest.json').read_text())
    state = json.loads((ROOT / 'build-status/cloud-state.json').read_text())
    assert state.get('artifacts_verified') is True
    assert manifest['commit'] == os.environ['GITHUB_SHA']
    sums = []
    files = []
    for entry in manifest['files']:
        assert Path(entry['name']).name == entry['name']
        path = artifacts / entry['name']
        with path.open('rb') as stream:
            digest = hashlib.file_digest(stream, 'sha256').hexdigest()
        assert digest == entry['sha256'] and path.stat().st_size == entry['bytes']
        sums.append(digest + '  ' + path.name)
        files.append(str(path))
    (artifacts / 'SHA256SUMS').write_text('\n'.join(sums) + '\n')
    tag = 'build-' + manifest['commit'][:8]
    notes = ROOT / 'build-status/release-notes.md'
    notes.write_text('```json\n' + json.dumps(manifest['build'], indent=2) + '\n```\n')
    exists = subprocess.run(['gh', 'release', 'view', tag], cwd=ROOT,
                            capture_output=True, text=True).returncode == 0
    if not exists:
        call('gh', 'release', 'create', tag, '--target', manifest['commit'], '--prerelease',
             '--notes-file', str(notes), '--title', 'Chromium cloud build · ' + manifest['commit'][:8])
    call('gh', 'release', 'upload', tag, *files, str(artifacts / 'manifest.json'),
         str(artifacts / 'SHA256SUMS'), '--clobber')


def status():
    folder = ROOT / 'build-status'
    folder.mkdir(exist_ok=True)
    archive = folder / 'cloud/diagnostics.tar.gz'
    if archive.exists():
        # Read specific diagnostic files, rather than extract arbitrary paths.
        with tarfile.open(archive) as tar:
            for name in ('latest.json', 'errors.txt'):
                try:
                    member = tar.getmember('status/' + name)
                except KeyError:
                    continue
                if member.isfile() and member.size < 8 * 1024 * 1024:
                    (folder / name).write_bytes(tar.extractfile(member).read())
    summary = folder / 'latest.json'
    if summary.exists():
        result = json.loads(summary.read_text())
    else:
        result = {'status': 'failed', 'reason': 'Cloud preparation or diagnostics retrieval failed'}
    result['pipeline_status'] = os.environ.get('CLOUD_JOB_STATUS', 'unknown')
    summary.write_text(json.dumps(result, indent=2) + '\n')
    if os.environ.get('GITHUB_STEP_SUMMARY'):
        with open(os.environ['GITHUB_STEP_SUMMARY'], 'a') as output:
            output.write('### Cloud native build\n\n```json\n' + json.dumps(result, indent=2) + '\n```\n')
    # An isolated index creates an orphan build-results commit without changing
    # the controller's checkout (cleanup still needs its scripts/config).
    with tempfile.TemporaryDirectory(prefix='cloud-status-') as temp:
        env = dict(os.environ, GIT_INDEX_FILE=str(Path(temp) / 'index'),
                   GIT_AUTHOR_NAME='chromium-hmos runner', GIT_COMMITTER_NAME='chromium-hmos runner',
                   GIT_AUTHOR_EMAIL='runner@localhost', GIT_COMMITTER_EMAIL='runner@localhost')
        call('git', 'read-tree', '--empty', env=env)
        for path in sorted(folder.rglob('*')):
            if not path.is_file() or path.is_symlink():
                continue
            blob = call('git', 'hash-object', '-w', str(path), capture_output=True).stdout.strip()
            call('git', 'update-index', '--add', '--cacheinfo',
                 '100644,' + blob + ',' + path.relative_to(ROOT).as_posix(), env=env)
        tree = call('git', 'write-tree', capture_output=True, env=env).stdout.strip()
        commit = call('git', 'commit-tree', tree, '-m', 'cloud build ' + os.environ['GITHUB_SHA'][:8],
                      capture_output=True, env=env).stdout.strip()
        call('git', 'push', '--force', 'origin', commit + ':refs/heads/build-results')


if __name__ == '__main__':
    {'release': release, 'status': status}[sys.argv[1]]()
