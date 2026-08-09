#!/usr/bin/env python3

import argparse
from pathlib import Path

from PIL import Image, ImageOps


def write_assets(project: Path, foreground_path: Path) -> None:
    foreground = Image.open(foreground_path).convert("RGBA")
    foreground = ImageOps.contain(
        foreground, (1024, 1024), Image.Resampling.LANCZOS)
    canvas = Image.new("RGBA", (1024, 1024), (0, 0, 0, 0))
    canvas.alpha_composite(
        foreground,
        ((1024 - foreground.width) // 2, (1024 - foreground.height) // 2),
    )
    background = Image.new("RGBA", (1024, 1024), "#F6F8FC")
    start_icon = Image.alpha_composite(background, canvas).resize(
        (144, 144), Image.Resampling.LANCZOS)

    app_media = project / "AppScope/resources/base/media"
    entry_media = project / "entry/src/main/resources/base/media"
    for media_dir in (app_media, entry_media):
        media_dir.mkdir(parents=True, exist_ok=True)
        canvas.save(media_dir / "chromium_hmos_foreground.png", optimize=True)
        background.save(media_dir / "chromium_hmos_background.png", optimize=True)
    start_icon.save(entry_media / "chromium_hmos_start_icon.png", optimize=True)


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Generate deterministic Chromium HarmonyOS Adapter icon assets.")
    parser.add_argument("--project", type=Path, required=True)
    parser.add_argument("--foreground", type=Path, required=True)
    args = parser.parse_args()
    write_assets(args.project.resolve(), args.foreground.resolve())


if __name__ == "__main__":
    main()
