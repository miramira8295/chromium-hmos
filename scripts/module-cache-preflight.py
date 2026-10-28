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

targets = run([str(source/'third_party/ninja/ninja'), '-C', str(out),
               '-t', 'targets', 'all'])
targets['output'] = '\n'.join(line for line in targets['output'].splitlines()
                              if 'blink_unittests' in line or 'script_streamer_test' in line)
# Capture matching lines from the entire target listing, not only its tail.
listing = subprocess.check_output([str(source/'third_party/ninja/ninja'), '-C',
                                  str(out), '-t', 'targets', 'all'], text=True)
targets['output'] = '\n'.join(line for line in listing.splitlines()
                              if 'blink_unittests' in line or 'script_streamer_test' in line)
usage = shutil.disk_usage(source)
print(json.dumps({'free_bytes': usage.free, 'targets': targets,
    'args': (out/'args.gn').read_text(),
    'test_binary_exists': (out/'blink_unittests').exists(),
    'test_build_config': run(['rg', '-n', '-C', '5', 'script_streamer_test.cc|blink_unittests',
        'third_party/blink/renderer/core/BUILD.gn', 'third_party/blink/renderer/BUILD.gn']),
    'test_source_exists': (source/'third_party/blink/renderer/bindings/core/v8/script_streamer_test.cc').exists(),
}, indent=2))
