#!/usr/bin/env python3
"""Invalidate incomplete generated outputs, never sources or valid objects."""
import json
from pathlib import Path
import pickletools
import sys


def generated_format(path):
    if path.name in ('snapshot_blob.bin', 'v8_context_snapshot.bin'):
        return 'snapshot'
    if path.name.endswith('_type_mappings'):
        return 'typemap'
    if path.name.endswith('.mojom-module'):
        return 'module'
    if path.name.endswith(('.pb.h', '.pb.cc')) or (
            '.mojom' in path.name and path.suffix in ('.h', '.cc')):
        return 'source'
    return None


def repair(out, report):
    out = Path(out).resolve()
    log = out / '.ninja_log'
    invalid = []
    names = set()
    if log.exists():
        names = {fields[3] for line in log.read_text(errors='replace').splitlines()
                 if len(fields := line.split('\t')) >= 5}
    snapshots = []
    for directory in [out, *(path for path in out.iterdir() if path.is_dir() and not path.is_symlink())]:
        for filename in ('snapshot_blob.bin', 'v8_context_snapshot.bin'):
            path = directory / filename
            if path.is_file() and not path.is_symlink():
                name = str(path.relative_to(out))
                names.add(name)
                snapshots.append({'path': name, 'bytes': path.stat().st_size})
    Path(report).with_name('v8-snapshot-inputs.json').write_text(json.dumps(snapshots, indent=2) + '\n')
    # Interrupted actions may never reach .ninja_log. Cover the generated
    # trees of both the OHOS target and host toolchains, using known formats
    # that cannot legitimately be empty. Empty stamps/ordinary sources stay.
    for gen in [out / 'gen', *out.glob('*/gen')]:
        if gen.is_symlink() or not gen.is_dir():
            continue
        names.update(str(path.relative_to(out)) for path in gen.rglob('*')
                     if generated_format(path))
    extensions = {'.o', '.obj', '.a', '.so', '.rlib', '.rmeta', '.pcm', '.pch',
                  '.js', '.mjs', '.json', '.ts'}
    for name in sorted(names):
        path = out / name
        if (path.is_symlink() or not path.resolve().is_relative_to(out) or not path.is_file()):
            continue
        kind = generated_format(path)
        if path.stat().st_size == 0 and (kind or path.suffix in extensions):
            invalid.append(name)
        elif kind == 'typemap':
            try:
                content = '\n'.join(line for line in path.read_text().splitlines()
                                    if not line.lstrip().startswith('//'))
                if not isinstance(json.loads(content), dict):
                    invalid.append(name)
            except (ValueError, UnicodeError):
                invalid.append(name)
        elif kind == 'module':
            try:
                # Inspect pickle opcodes without unpickling/executing objects.
                list(pickletools.genops(path.read_bytes()))
            except ValueError:
                invalid.append(name)
    # Write the audit before modifying rebuildable generated files.
    Path(report).write_text(json.dumps(invalid, indent=2) + '\n')
    for name in invalid:
        (out / name).unlink()
    print(f'Invalidated {len(invalid)} incomplete generated outputs', flush=True)
    return invalid


if __name__ == '__main__':
    repair(*sys.argv[1:])
