#!/usr/bin/env python3
"""Compile Blink's patched eligibility method with minimal layout inputs.

Checks policy boundaries on OHOS and other platforms. Real layout and gesture
coverage lives in docs/test-pages/browser-controls-scrollers.html.
"""
import os
from pathlib import Path
import re
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[2]
patch = (ROOT / 'patches/migration-157/chromium.patch').read_text()
name = 'third_party/blink/renderer/core/page/scrolling/root_scroller_controller.cc'
section = re.search(r'^diff --git a/' + re.escape(name) +
                    r' .*?(?=^diff --git |\Z)', patch, re.M | re.S)[0]
source = '\n'.join(line[1:] for line in section.splitlines()
                   if line[:1] in (' ', '+') and not line.startswith('+++'))
start = source.index('bool RootScrollerController::IsValidImplicit(')
opening = source.index('{', start)
depth, end = 1, opening + 1
while depth:
    depth += (source[end] == '{') - (source[end] == '}')
    end += 1
method = source[start:end]

stubs = r'''
#include <cassert>
#define BUILDFLAG(flag) TEST_OHOS
#define DCHECK(condition) assert(condition)
enum class EPosition { kStatic, kAbsolute, kFixed };
struct ComputedStyle {
  bool opacity = false, visible = true, overflow_y = true;
  EPosition position = EPosition::kFixed;
  bool HasOpacity() const { return opacity; }
  bool VisibleToHitTesting() const { return visible; }
  bool ScrollsOverflowY() const { return overflow_y; }
  EPosition GetPosition() const { return position; }
};
struct PaintLayerScrollableArea {
  bool overflow = true, vertical = true;
  bool ScrollsOverflow() const { return overflow; }
  bool HasVerticalOverflow() const { return vertical; }
};
struct LayoutBox {
  bool view = false, clip = false, mask = false, css_clip = false, path = false;
  LayoutBox* containing = nullptr;
  ComputedStyle style;
  PaintLayerScrollableArea area;
  LayoutBox* ContainingBlock() const { return containing; }
  const ComputedStyle& Style() const { return style; }
  PaintLayerScrollableArea* GetScrollableArea() { return &area; }
  bool ShouldClipOverflowAlongEitherAxis() const { return clip; }
  bool HasMask() const { return mask; }
  bool HasCSSClip() const { return css_clip; }
  bool HasClipPath() const { return path; }
};
struct LayoutView {};
template<class T> bool IsA(LayoutBox* box) { return box->view; }
struct Element {
  LayoutBox* box;
  bool valid = true, frame = false, has_area = true;
  LayoutBox* GetLayoutObject() const { return box; }
  bool IsFrameOwnerElement() const { return frame; }
};
PaintLayerScrollableArea* GetScrollableArea(const Element& e) {
  return e.has_area ? &e.box->area : nullptr;
}
struct BrowserControls {
  int height = 95;
  int TotalHeight() const { return height; }
};
struct Page {
  BrowserControls controls;
  BrowserControls& GetBrowserControls() { return controls; }
};
struct Document {
  Page page;
  Page* GetPage() { return &page; }
};
struct RootScrollerController {
  Document* document_;
  bool IsValidRootScroller(const Element& e) const { return e.valid; }
  bool IsValidImplicit(const Element&) const;
};
'''
cases = r'''
int main() {
  LayoutBox root, box, transformed;
  root.view = true;
  box.containing = &root;
  Element candidate{&box};
  Document document;
  RootScrollerController controller{&document};
  auto valid = [&] { return controller.IsValidImplicit(candidate); };
  // Root overflow + full viewport-fixed vertical scroller: OHOS exception.
  assert(valid() == bool(TEST_OHOS));
  // Existing rejection checks must still win over the new exception.
  candidate.valid = false; assert(!valid()); candidate.valid = true;
  candidate.has_area = false; assert(!valid()); candidate.has_area = true;
  box.style.opacity = true; assert(!valid()); box.style.opacity = false;
  box.style.visible = false; assert(!valid()); box.style.visible = true;
  box.area.overflow = false; assert(!valid()); box.area.overflow = true;
  box.area.vertical = false; assert(!valid()); box.area.vertical = true;
  candidate.frame = true; assert(!valid()); candidate.frame = false;
  box.style.position = EPosition::kAbsolute; assert(!valid());
  box.style.position = EPosition::kStatic; assert(!valid());
  box.style.position = EPosition::kFixed;
  document.page.controls.height = 0; assert(!valid());
  document.page.controls.height = 95;
  // A transformed ancestor establishes a different fixed containing block.
  transformed.containing = &root;
  box.containing = &transformed; assert(!valid());
  // Without document scrolling, upstream ordinary-container behavior survives.
  root.area.vertical = false; assert(valid());
  transformed.clip = true; assert(!valid()); transformed.clip = false;
  transformed.mask = true; assert(!valid()); transformed.mask = false;
  transformed.css_clip = true; assert(!valid()); transformed.css_clip = false;
  transformed.path = true; assert(!valid()); transformed.path = false;
  box.containing = &root;
  candidate.frame = true; assert(valid()); candidate.frame = false;
  box.style.position = EPosition::kStatic; assert(valid());
  root.area.vertical = true;
  root.style.overflow_y = false; assert(valid());
  root.style.overflow_y = true; assert(!valid());
}
'''
with tempfile.TemporaryDirectory() as folder:
    path = Path(folder)
    (path / 'test.cc').write_text(stubs + method + cases)
    for ohos in (0, 1):
        subprocess.run([os.environ.get('CXX', 'c++'), '-std=c++20', '-Wall',
                        '-Wextra', '-Werror', f'-DTEST_OHOS={ohos}',
                        str(path / 'test.cc'), '-o', str(path / 'test')], check=True)
        subprocess.run([str(path / 'test')], check=True)
print('PASS: actual Blink eligibility method, OHOS-only exception and existing rejection boundaries')
