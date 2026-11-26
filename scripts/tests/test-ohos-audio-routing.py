#!/usr/bin/env python3
"""Run the OHOS per-stream device selection against a fake native runtime."""
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]
FIXTURES = ROOT / 'scripts/tests/ohos-audio'
BACKEND = ROOT / 'overlay/media/audio/ohos'


class AudioRoutingTest(unittest.TestCase):
    def run_with_platform(self, *flags):
        with tempfile.TemporaryDirectory() as directory:
            tmp = Path(directory)
            def header(path, contents):
                file = tmp / path
                file.parent.mkdir(parents=True, exist_ok=True)
                file.write_text(contents)

            for name in ['native_audio_routing_manager', 'native_audio_manager', 'native_audio_device_base',
                         'native_audio_device_enhance_manager', 'native_audiocapturer', 'native_audiorenderer',
                         'native_audiostream_base']:
                header(f'ohaudio/{name}.h', '#include "fake_ohaudio.h"\n')
            header('base/compiler_specific.h', '#define UNSAFE_BUFFERS(...) __VA_ARGS__\n')
            header('base/containers/span.h', '#include <span>\nnamespace base { using std::span; }\n')
            header('base/strings/string_number_conversions.h',
                   '#include <string>\nnamespace base { inline auto NumberToString(unsigned x) { return std::to_string(x); } }\n')
            header('media/audio/audio_device_name.h', '''
#pragma once
#include <list>
#include <string>
namespace media {
struct AudioDeviceName { std::string device_name; std::string unique_id; };
using AudioDeviceNames = std::list<AudioDeviceName>;
}
''')
            exe = tmp / 'route_test'
            link = ['-Wl,-export_dynamic'] if sys.platform == 'darwin' else ['-rdynamic', '-ldl']
            subprocess.run([os.getenv('CXX', 'c++'), '-std=c++20', '-I', str(tmp),
                            '-I', str(FIXTURES), '-I', str(ROOT / 'overlay'), *flags,
                            str(BACKEND / 'ohos_audio_route.cc'), str(FIXTURES / 'route_test.cc'),
                            *link, '-o', str(exe)], check=True)
            subprocess.run([str(exe)], check=True, timeout=10)

    def test_selectable_routes_and_runtime_rejections(self):
        self.run_with_platform()

    def test_device_change_callback_shutdown_and_retry(self):
        # Compile the manager methods themselves. Other Chromium audio machinery
        # is replaced by a queued runner so a callback can straddle shutdown.
        source = (BACKEND / 'audio_manager_ohos.cc').read_text()
        subscription = source[source.index('struct DeviceChangeSubscription {'):
                              source.index('std::optional<uint32_t> ParseDeviceId')]
        methods = source[source.index('void AudioManagerOhos::StartDeviceMonitor()'):
                         source.index('AudioParameters AudioManagerOhos::GetPreferredOutputStreamParameters')]
        with tempfile.TemporaryDirectory() as directory:
            folder = Path(directory)
            (folder / 'monitor_methods.inc').write_text(subscription + methods)
            exe = folder / 'monitor_test'
            subprocess.run([os.getenv('CXX', 'c++'), '-std=c++20', '-I', str(folder),
                            str(FIXTURES / 'monitor_test.cc'), '-o', str(exe)], check=True)
            subprocess.run([str(exe)], check=True, timeout=10)

    def test_old_runtime_lacks_enhanced_symbols(self):
        self.run_with_platform('-DWITHOUT_ENHANCED_ROUTING')


if __name__ == '__main__':
    unittest.main()
