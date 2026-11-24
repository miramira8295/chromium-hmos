#!/usr/bin/env python3
"""Apply the rebased HarmonyOS patches to the pinned Chromium 158 checkout."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
PATCHES = ROOT / "patches/migration-158"


def apply(src):
    if src != Path("/root/chromium-158/src"):
        raise ValueError("158 migration requires its own source tree")
    manifest = json.loads((PATCHES / "manifest.json").read_text())
    pin = json.loads((ROOT / "config/engines/158.json").read_text())
    if manifest["target_revision"] != pin["revision"]:
        raise ValueError("Patch manifest does not match the engine revision")
    pending = []
    for entry in manifest["repositories"]:
        target = src / entry["path"]
        git = ["git", "-C", str(target)]
        revision = subprocess.check_output(git + ["rev-parse", "HEAD"], text=True).strip()
        if revision != entry["source_base"]:
            raise ValueError(f"Dependency revision mismatch in {target}: {revision}")
        patch = PATCHES / entry["patch"]
        if hashlib.sha256(patch.read_bytes()).hexdigest() != entry["sha256"]:
            raise ValueError(f"Patch checksum mismatch: {patch}")
        # The overlay can replace working-tree files. The index still records
        # the exact native snapshot that was applied before that copy.
        already_applied = subprocess.run(
            git + ["apply", "--cached", "--reverse", "--check", str(patch)],
            capture_output=True)
        if already_applied.returncode == 0:
            continue
        subprocess.run(git + ["apply", "--index", "--check", str(patch)], check=True)
        pending.append((git, patch))
    for git, patch in pending:
        subprocess.run(git + ["apply", "--index", "--whitespace=nowarn", str(patch)], check=True)


if __name__ == "__main__":
    apply(Path(sys.argv[1]).resolve())
