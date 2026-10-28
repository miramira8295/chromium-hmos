"""Read-only inspection before choosing an isolated native test build."""
import json
from pathlib import Path
import shutil
import subprocess

source = Path('/root/chromium-155/src')
out = source / 'out/ohos_arm64'
def run(args):
    result = subprocess.run(args, cwd=source, text=True, capture_output=True)
    return {'exit': result.returncode, 'output': result.stdout[-12000:],
            'error': result.stderr[-2000:]}

listing = subprocess.check_output([str(source/'third_party/ninja/ninja'), '-C',
                                  str(out), '-t', 'targets', 'all'], text=True)
targets = [line for line in listing.splitlines()
           if 'blink_unittests' in line or 'script_streamer_test' in line]
configs = {}
for name in ['third_party/blink/renderer/core/BUILD.gn', 'third_party/blink/renderer/BUILD.gn']:
    lines = (source/name).read_text().splitlines()
    selected = set()
    for i, line in enumerate(lines):
        if 'script_streamer_test.cc' in line or 'blink_unittests' in line:
            selected.update(range(max(0, i-5), min(len(lines), i+6)))
    configs[name] = '\n'.join(f'{i+1}: {lines[i]}' for i in sorted(selected))
usage = shutil.disk_usage(source)
print(json.dumps({'free_bytes': usage.free, 'targets': targets,
    'args': (out/'args.gn').read_text(),
    'test_binary_exists': (out/'blink_unittests').exists(),
    'test_build_config': configs,
    'test_source_exists': (source/'third_party/blink/renderer/bindings/core/v8/script_streamer_test.cc').exists(),
}, indent=2))
