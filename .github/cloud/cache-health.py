#!/usr/bin/env python3
"""Invalidate incomplete generated outputs, never sources or valid objects."""
import json
from pathlib import Path
import sys


def repair(out, report):
    out = Path(out).resolve()
    log = out / '.ninja_log'
    invalid = []
    if log.exists():
        names = {fields[3] for line in log.read_text(errors='replace').splitlines()
                 if len(fields := line.split('\t')) >= 5}
        extensions = {'.o', '.obj', '.a', '.so', '.rlib', '.rmeta', '.pcm', '.pch',
                      '.js', '.mjs', '.json', '.ts'}
        for name in sorted(names):
            path = out / name
            if (path.suffix in extensions and not path.is_symlink()
                    and path.resolve().is_relative_to(out)
                    and path.is_file() and path.stat().st_size == 0):
                invalid.append(name)
    # Write the audit before modifying rebuildable generated files.
    Path(report).write_text(json.dumps(invalid, indent=2) + '\n')
    for name in invalid:
        (out / name).unlink()
    print(f'Invalidated {len(invalid)} zero-length generated outputs', flush=True)
    return invalid


if __name__ == '__main__':
    repair(*sys.argv[1:])
