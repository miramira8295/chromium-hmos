#!/usr/bin/env python3
import os
from pathlib import Path
import subprocess
import sys
import unittest
ROOT = Path(__file__).resolve().parents[2]

class IsolationTest(unittest.TestCase):
    def test_snapshot_rejects_other_trees_before_git(self):
        for path in ['/root/chromium-155/src', '/root/chromium-154/src', '/tmp/src']:
            r = subprocess.run([sys.executable, str(ROOT/'scripts/apply-157-snapshot.py'), path], capture_output=True, text=True)
            self.assertNotEqual(r.returncode, 0)
            self.assertIn('must never modify another engine', r.stderr)

    def test_preparation_rejects_other_branches_and_paths(self):
        for branch, path in [('hmos-155-adapter', '/root/chromium-155/src'), ('hmos-154-adapter', '/root/chromium-154/src'), ('hmos-157-adapter', '/root/chromium-155/src')]:
            env = dict(os.environ, GITHUB_ACTIONS='true', GITHUB_REF_NAME=branch, CHROMIUM_SRC=path, CHROMIUM_REVISION='7d4508cbfffd289d7015f7703bce215d3ab123bf')
            r = subprocess.run(['bash', str(ROOT/'scripts/prepare-chromium-157.sh')], env=env, capture_output=True)
            self.assertNotEqual(r.returncode, 0)

if __name__ == '__main__': unittest.main()
