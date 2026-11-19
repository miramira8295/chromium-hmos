#!/usr/bin/env python3
"""Compile the migrated picker policy for phone and desktop build flags."""
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]


class FileChooserWindowSizeTest(unittest.TestCase):
    def test_phone_picker_and_desktop_occlusion_policy(self):
        patch = (ROOT / 'patches/migration-157/chromium.patch').read_text()
        section = patch.split('diff --git a/chrome/browser/file_select_helper.cc ', 1)[1]
        section = section.split('\ndiff --git ', 1)[0]
        migrated = '\n'.join(line[1:] for line in section.splitlines()
                             if line.startswith((' ', '+')) and not line.startswith('+++'))
        policy = re.search(r'gfx::Size GetMinFileChooserWindowSize\(\) \{.*?'
                           r'return kMinFileChooserWindowSize;', migrated, re.S).group() + '\n}'
        compiler = shutil.which('clang++') or shutil.which('g++')
        self.assertIsNotNone(compiler)
        with tempfile.TemporaryDirectory() as temp:
            source = Path(temp) / 'policy.cc'
            source.write_text('''#include <cassert>
#define BUILDFLAG(flag) flag
namespace gfx {
struct Size {
  int width = 0, height = 0;
  constexpr Size() = default;
  constexpr Size(int w, int h) : width(w), height(h) {}
};
}
namespace features { constexpr int kFileChooserMinWindowSize = 1; }
namespace base {
struct FeatureList {
  static inline bool enabled = true;
  static bool IsEnabled(int) { return enabled; }
};
}
constexpr gfx::Size kMinFileChooserWindowSize(400, 300);
''' + policy + '''
bool allowed(int width, int height) {
  auto minimum = GetMinFileChooserWindowSize();
  return width >= minimum.width && height >= minimum.height;
}
int main() {
  // Portrait phone and landscape phone below one desktop minimum dimension.
  assert(allowed(360, 780) == bool(IS_OHOS));
  assert(allowed(780, 280) == bool(IS_OHOS));
  assert(allowed(800, 1200));
  assert(allowed(400, 300));
  base::FeatureList::enabled = false;
  assert(allowed(360, 280));
}
''')
            for ohos in (0, 1):
                binary = str(Path(temp) / f'policy-{ohos}')
                subprocess.run([compiler, '-std=c++17', '-Wall', '-Wextra', '-Werror',
                                f'-DIS_OHOS={ohos}', str(source), '-o', binary], check=True)
                subprocess.run([binary], check=True)


if __name__ == '__main__':
    unittest.main()
