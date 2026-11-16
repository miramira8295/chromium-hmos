#!/usr/bin/env python3
"""Exercise the production font preference update; verify the OHOS IPC route.

Compiles the bridge's actual update method and browser preference helper with
platform stubs. This checks propagation and zoom independence, not Blink layout.
"""
import json
import hashlib
import os
from pathlib import Path
import re
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[2]
patch_path = ROOT / 'patches/migration-157/chromium.patch'
patch = patch_path.read_text()
bridge = (ROOT / 'overlay/chrome/browser/ui/ohos/aura_shell_runtime_bridge.cc').read_text()


def section(path):
    match = re.search(r'^diff --git a/' + re.escape(path) +
                      r' b/.*?(?=^diff --git |\Z)', patch, re.M | re.S)
    assert match, path
    return '\n'.join(line[1:] for line in match[0].splitlines()
                     if line[:1] in (' ', '+') and not line.startswith('+++'))


def function(source, signature):
    start = source.index(signature)
    opening = source.index('{', start)
    depth, end = 1, opening + 1
    while depth:
        depth += (source[end] == '{') - (source[end] == '}')
        end += 1
    return source[start:end]


client = section('chrome/browser/chrome_content_browser_client.cc')
assert client.count('ApplyOhosSystemFontWebPreferences(web_prefs);') == 2
assert 'SetOhosSystemFontScale' not in patch + bridge
assert 'GetEffectiveDefaultZoomLevel' not in patch
assert 'ChromeZoomLevelPrefs' not in bridge[bridge.index('class OhosSystemFontScaleWatcher'):bridge.index('// Watches every profile')]
assert '!base::FeatureList::IsEnabled(kOhosFollowSystemFontSize)' in bridge
assert 'float scale_ = 1.0f;' in bridge
manifest = json.loads((ROOT / 'patches/migration-157/manifest.json').read_text())
assert manifest['repositories'][0]['sha256'] == hashlib.sha256(patch_path.read_bytes()).hexdigest()
assert manifest['repositories'][0]['bytes'] == len(patch_path.read_bytes())

# Check all three C++ IPC boundaries plus the renderer setter have an OHOS
# guard. Do not widen the neighbouring Android-only settings or WebView quirks.
for path, line in (
    ('third_party/blink/public/common/web_preferences/web_preferences.h', '  float font_scale_factor = 1.0f;'),
    ('third_party/blink/public/common/web_preferences/web_preferences_mojom_traits.h', '  static float font_scale_factor('),
    ('third_party/blink/common/web_preferences/web_preferences_mojom_traits.cc', '  out->font_scale_factor = data.font_scale_factor();'),
    ('third_party/blink/renderer/core/exported/web_view_impl.cc', '  settings->SetAccessibilityFontScaleFactor(prefs.font_scale_factor);'),
):
    source = section(path)
    guard = '#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_OHOS)\n'
    assert guard + line in source, path
    assert '#endif\n#if BUILDFLAG(IS_ANDROID)' in source or '#endif\n\n#if BUILDFLAG(IS_ANDROID)' in source, path
assert '[EnableIf=is_android|is_ohos]\n  float font_scale_factor;' in section(
    'third_party/blink/public/mojom/webpreferences/web_preferences.mojom')

unit = r'''
#include <algorithm>
#include <cassert>
#include <cmath>
#include <limits>
#include <optional>
#include <sstream>
#include <vector>
#define DCHECK_CURRENTLY_ON(...) ((void)0)
#define LOG(...) std::ostringstream()
struct WebPreferences {
  float font_scale_factor = 1.0f;
  bool text_size_adjust_enabled = false;
};
float system_scale = 1.0f;
namespace chrome::ohos {
float GetAuraShellSystemFontScale() { return system_scale; }
}
FONT_PREFS
struct WebContents {
  WebPreferences prefs;
  int updates = 0;
  double page_zoom = 1.25;
  bool fullscreen = false;
  void OnWebPreferencesChanged() {
    ++updates;
    ApplyOhosSystemFontWebPreferences(&prefs);
  }
};
struct TabStripModel {
  std::vector<WebContents*> tabs;
  int count() const { return static_cast<int>(tabs.size()); }
  WebContents* GetWebContentsAt(int index) { return tabs[index]; }
};
struct BrowserWindowInterface {
  TabStripModel* tabs;
  TabStripModel* GetTabStripModel() { return tabs; }
};
struct GlobalBrowserCollection {
  static GlobalBrowserCollection* instance;
  static GlobalBrowserCollection* GetInstance() { return instance; }
  std::vector<BrowserWindowInterface*> windows;
  template<class F> void ForEach(F f) {
    for (auto* window : windows) { if (!f(window)) break; }
  }
};
GlobalBrowserCollection* GlobalBrowserCollection::instance = nullptr;
struct Watcher {
  // Alias the stub getter to the production method's stored scale.
  float& scale_ = system_scale;
  APPLY
};
int main() {
  Watcher watcher;
  // Startup reply before any window: retain the scale for future pages.
  watcher.Apply(1.45);
  assert(system_scale == 1.45f);
  WebContents foreground, background, incognito, app;
  foreground.fullscreen = true;
  incognito.page_zoom = 1.75;
  app.page_zoom = 0.9;
  TabStripModel normal{{&foreground, nullptr, &background}};
  TabStripModel private_tabs{{&incognito}}, app_tabs{{&app}};
  BrowserWindowInterface normal_window{&normal}, private_window{&private_tabs},
      app_window{&app_tabs}, empty_window{nullptr};
  GlobalBrowserCollection browsers{{&normal_window, &private_window, &app_window, &empty_window}};
  GlobalBrowserCollection::instance = &browsers;
  watcher.Apply(1.6);
  for (auto* page : {&foreground, &background, &incognito, &app}) {
    assert(page->updates == 1);
    assert(page->prefs.font_scale_factor == 1.6f);
    assert(page->prefs.text_size_adjust_enabled);
  }
  assert(foreground.page_zoom == 1.25 && background.page_zoom == 1.25);
  assert(incognito.page_zoom == 1.75 && app.page_zoom == 0.9);
  assert(foreground.fullscreen);
  // Duplicate, unavailable and invalid service replies cannot perturb pages.
  for (auto value : {std::optional<double>{}, std::optional<double>{1.6},
      std::optional<double>{0}, std::optional<double>{-1},
      std::optional<double>{std::numeric_limits<double>::infinity()},
      std::optional<double>{std::numeric_limits<double>::quiet_NaN()}}) {
    watcher.Apply(value);
  }
  assert(foreground.updates == 1 && system_scale == 1.6f);
  watcher.Apply(9.0);
  assert(system_scale == 2.0f);
  watcher.Apply(0.1);
  assert(system_scale == 0.8f);
  watcher.Apply(1.0);
  assert(system_scale == 1.0f && foreground.prefs.font_scale_factor == 1.0f);
  assert(foreground.page_zoom == 1.25 && incognito.page_zoom == 1.75);
  // Newly created and recomputed pages read the current font preference.
  WebPreferences next;
  assert(ApplyOhosSystemFontWebPreferences(&next));
  assert(!ApplyOhosSystemFontWebPreferences(&next));
  watcher.Apply(1.45);
  assert(ApplyOhosSystemFontWebPreferences(&next));
  assert(next.font_scale_factor == 1.45f);
  assert(!ApplyOhosSystemFontWebPreferences(&next));
}
'''
# The actual Blink document policy must avoid both inheritance mistakes and
# double scaling on pages opting into meta text-scale.
frame = section('third_party/blink/renderer/core/frame/local_frame.cc')
page = section('third_party/blink/renderer/core/page/page.cc')
view = section('third_party/blink/renderer/core/exported/web_view_impl.cc')
assert 'SetScaleAllFontsIfNoMetaTextScaleTag(true)' in view
assert 'SetTextZoomFactor(OhosTextZoomFactor(document, text_zoom_factor_))' in frame
assert 'text_zoom_factor = OhosTextZoomFactor(GetDocument(), text_zoom_factor)' in frame
assert 'local_frame->SetTextZoomFactor(' in page
policy = r"""
struct Settings {
  bool all = true;
  float factor = 1.45f;
  bool GetScaleAllFontsIfNoMetaTextScaleTag() const { return all; }
  float GetAccessibilityFontScaleFactor() const { return factor; }
};
struct Document {
  Settings* settings;
  bool meta = false;
  const Settings* GetSettings() const { return settings; }
  bool TextScaleMetaTagPresent() const { return meta; }
};
TEXT_POLICY
void CheckDocumentTextPolicy() {
  Settings settings;
  Document ordinary{&settings}, adapted{&settings, true}, detached{nullptr};
  assert(OhosTextZoomFactor(nullptr, 1.2f) == 1.2f);
  assert(OhosTextZoomFactor(&detached, 1.2f) == 1.2f);
  // A meta parent passes 1, an ordinary parent passes its scale. Each child
  // resolves its own opt-in; neither inherits the wrong parent's decision.
  for (float inherited : {1.0f, 1.45f, 2.0f}) {
    assert(OhosTextZoomFactor(&ordinary, inherited) == 1.45f);
    assert(OhosTextZoomFactor(&adapted, inherited) == 1.0f);
  }
  ordinary.meta = true;
  assert(OhosTextZoomFactor(&ordinary, 1.45f) == 1.0f);
  ordinary.meta = false;
  assert(OhosTextZoomFactor(&ordinary, 1.0f) == 1.45f);
  settings.factor = 1.6f;
  assert(OhosTextZoomFactor(&ordinary, 1.45f) == 1.6f);
  assert(OhosTextZoomFactor(&adapted, 1.45f) == 1.0f);
  settings.factor = 1.0f;
  assert(OhosTextZoomFactor(&ordinary, 1.45f) == 1.0f);
  settings.all = false;
  assert(OhosTextZoomFactor(&ordinary, 1.2f) == 1.2f);
}
"""
policy = policy.replace('TEXT_POLICY', function(frame, 'float OhosTextZoomFactor('))
unit = unit.replace('int main() {', policy + '\nint main() {\n  CheckDocumentTextPolicy();')
unit = unit.replace('FONT_PREFS', function(client, 'bool ApplyOhosSystemFontWebPreferences('))
unit = unit.replace('APPLY', function(bridge, 'void Apply(std::optional<double> scale)'))
with tempfile.TemporaryDirectory(prefix='font-scale-test-') as directory:
    path = Path(directory)
    (path / 'test.cc').write_text(unit)
    subprocess.run([os.environ.get('CXX', 'c++'), '-std=c++20', '-Wall', '-Wextra', '-Werror',
                    str(path / 'test.cc'), '-o', str(path / 'test')], check=True)
    subprocess.run([str(path / 'test')], check=True)
print('PASS: system font propagation, all tab windows, invalid replies, zoom independence and OHOS IPC wiring')
