"""Inspect test linking/running dependencies without mutating the shared build."""
import json
from pathlib import Path
import subprocess

source = Path('/root/chromium-155/src')
out = source / 'out/ohos_arm64'
ninja = source / 'third_party/ninja/ninja'


def command(*arguments):
    result = subprocess.run([str(ninja), '-C', str(out), '-t', *arguments],
                            capture_output=True, text=True, errors='replace', timeout=180)
    return result


query = command('query', 'blink_unittests')
inputs = []
reading = False
for line in query.stdout.splitlines():
    if line.startswith('  input:'):
        reading = True
    elif line.startswith('  outputs:'):
        reading = False
    elif reading and line.startswith('    '):
        value = line.strip().lstrip('| ').strip()
        if value:
            inputs.append(value)
missing = [value for value in inputs if not (out / value).exists()]
runner = out / 'bin/run_blink_unittests'
configs = {}
for relative in ['third_party/blink/renderer/controller/BUILD.gn',
                 'build/toolchain/ohos/BUILD.gn', 'testing/test.gni']:
    path = source / relative
    if not path.exists():
        continue
    lines = path.read_text().splitlines()
    selected = set()
    for index, line in enumerate(lines):
        if any(token in line for token in ['blink_unittests', 'test_launcher',
                                            'run_ohos', 'target_os == "ohos"']):
            selected.update(range(max(0, index - 4), min(len(lines), index + 12)))
    configs[relative] = '\n'.join(f'{index + 1}: {lines[index]}' for index in sorted(selected))
commands = command('commands', 'blink_unittests')
lines = commands.stdout.splitlines()
result = {'test_binary_exists': (out / 'blink_unittests').exists(),
          'runner_exists': runner.exists(),
          'runner': runner.read_text()[:16000] if runner.exists() else None,
          'query_exit': query.returncode, 'query': query.stdout[:30000],
          'direct_input_count': len(inputs), 'missing_direct_input_count': len(missing),
          'missing_direct_inputs': missing[:200],
          'dependency_command_count': len(lines),
          'command_query_exit': commands.returncode,
          'last_commands': [line[:4000] for line in lines[-6:]],
          'available_output_dirs': [path.name for path in (source / 'out').iterdir()
                                    if path.is_dir()],
          'host_v8_candidates': [str(path.relative_to(out))
                                 for pattern in ['mksnapshot', '*/mksnapshot', '*/d8', '*/cctest']
                                 for path in out.glob(pattern) if path.is_file()],
          'test_build_config': configs}
print(json.dumps(result, indent=2))
