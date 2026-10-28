"""Link and execute a V8 probe using existing host mksnapshot dependencies."""
import hashlib
import json
from pathlib import Path
import shlex
import subprocess

source = Path('/root/chromium-155/src')
build = source / 'out/ohos_arm64'
output = Path('validation/host-v8').resolve()
output.mkdir(parents=True, exist_ok=True)
ninja = source / 'third_party/ninja/ninja'
target = 'clang_x64_v8_arm64/mksnapshot'
probe = Path('scripts/tests/v8-module-cache-runtime.cc').resolve()
report = {'status': 'preparing', 'tests_executed': False,
          'limitation': 'Host V8 API probe; not Blink gtests, cache clearing, or device acceptance.'}


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def ninja_tool(*arguments):
    return subprocess.check_output([str(ninja), '-C', str(build), '-t', *arguments],
                                   text=True, errors='replace', timeout=240)


def query(name):
    lines = ninja_tool('query', name).splitlines()
    rule = next(line.split(':', 1)[1].strip() for line in lines if line.startswith('  input:'))
    inputs = []
    for line in lines[2:]:
        if not line.startswith('    '):
            break
        inputs.append(line.strip().lstrip('| ').strip())
    return rule, inputs


def compile_entry(rule, target_name):
    entries = json.loads(ninja_tool('compdb', '-x', rule))
    matches = [entry for entry in entries
               if (Path(entry['directory']) / entry['output']).resolve() == (build / target_name).resolve()]
    if len(matches) != 1:
        raise RuntimeError(f'Expected one compilation-database entry for {target_name}; got {len(matches)}')
    return matches[0]


def stage(args, name, timeout=180):
    if any(arg.startswith('@') for arg in args):
        raise RuntimeError('Unexpanded response file')
    with (output / f'{name}.log').open('w') as log:
        result = subprocess.run(args, cwd=build, stdout=log, stderr=subprocess.STDOUT, timeout=timeout)
    report[f'{name}_exit'] = result.returncode
    if result.returncode:
        raise RuntimeError(f'{name} failed ({result.returncode}); see {name}.log')


original = build / target
original_digest = digest(original)
main_object = None
main_digest = None
try:
    key = digest(build / 'build.ninja') + original_digest
    cache = Path('/tmp/lumie-host-v8-toolchain-' + hashlib.sha256(key.encode()).hexdigest()[:16] + '.json')
    if cache.exists():
        metadata = json.loads(cache.read_text())
        main_object, compiler, linker = (metadata[name] for name in ['main_object', 'compiler', 'linker'])
    else:
        link_rule, inputs = query(target)
        main_object = next(name for name in inputs if name.endswith('/mksnapshot.o'))
        compile_rule, _ = query(main_object)
        compiler = compile_entry(compile_rule, main_object)
        linker = compile_entry(link_rule, target)
        cache.write_text(json.dumps({'main_object': main_object, 'compiler': compiler, 'linker': linker}))
    main_digest = digest(build / main_object)
    (output / 'toolchain.json').write_text(json.dumps({'main_object': main_object,
        'compiler': compiler, 'linker': linker}))
    args = shlex.split(compiler['command'])
    report['architecture_flags'] = [arg for arg in args
        if arg.startswith(('-DV8_TARGET_ARCH', '-DV8_HOST_ARCH', '-DUSE_SIMULATOR'))]
    filtered = []
    index = 0
    while index < len(args):
        arg = args[index]
        if arg in ('-o', '-MF', '-MT', '-MQ', '-MJ'):
            index += 2
            continue
        if arg in ('-MMD', '-MD', '-MP') or arg.startswith('-fcrash-diagnostics-dir='):
            index += 1
            continue
        filtered.append(str(probe) if arg == compiler['file'] else arg)
        index += 1
    if str(probe) not in filtered:
        raise RuntimeError('Could not replace the mksnapshot source')
    stage(filtered + ['-o', str(output / 'probe.o'), '-Wno-unsafe-buffer-usage',
                      '-fcrash-diagnostics-dir=' + str(output / 'crashes')], 'compile')
    args = shlex.split(linker['command'])
    # Invoke the actual linker, bypassing the strip/output wrapper so no
    # original executable, symbols file, or response file can be overwritten.
    delimiter = args.index('--')
    args = args[delimiter + 1:]
    # Some ninja versions preserve quotes around expanded response contents.
    # Expand that object list before comparing normalized input paths.
    expanded = []
    for arg in args:
        if any(character.isspace() for character in arg) and main_object in arg:
            expanded.extend(shlex.split(arg))
        else:
            expanded.append(arg)
    args = expanded
    output_index = args.index('-o') + 1
    args[output_index] = str(output / 'probe')
    replacements = 0
    for index, arg in enumerate(args):
        if not arg.startswith('-') and (build / arg).resolve() == (build / main_object).resolve():
            args[index] = str(output / 'probe.o')
            replacements += 1
    if replacements != 1:
        report['main_object'] = main_object
        report['matching_link_args'] = [arg[:4000] for arg in args if 'mksnapshot.o' in arg]
        raise RuntimeError(f'Expected one main-object replacement; got {replacements}')
    stage(args, 'link')
    report['probe_sha256'] = digest(output / 'probe')
    report['probe_source_sha256'] = digest(probe)
    icu = next((path for path in [build / 'icudtl.dat', source / 'third_party/icu/common/icudtl.dat']
                if path.exists()), None)
    report['tests_executed'] = True
    stage([str(output / 'probe')] + ([str(icu)] if icu else []), 'run', 90)
    lines = (output / 'run.log').read_text(errors='replace').splitlines()
    observations = [json.loads(line) for line in lines if line.startswith('{')]
    report['observations'] = observations
    cases = [item for item in observations if 'case' in item]
    if len(cases) != 4 or not all(item['passed'] for item in cases):
        raise RuntimeError('Expected four passing V8 runtime cases')
    report['status'] = 'passed'
except Exception as error:
    report['status'] = 'error'
    report['error'] = str(error)
    raise
finally:
    report['original_mksnapshot_unchanged'] = digest(original) == original_digest
    report['original_main_object_unchanged'] = main_object is None or digest(build / main_object) == main_digest
    (output / 'result.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report, indent=2))
