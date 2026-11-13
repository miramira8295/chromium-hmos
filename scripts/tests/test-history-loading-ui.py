#!/usr/bin/env python3
"""Exercise the production loading observer; Chromium supplies restore identity."""
import os
from pathlib import Path
import subprocess
import tempfile

root = Path(__file__).resolve().parents[2]
source = (root / 'overlay/chrome/browser/ui/ohos/aura_shell_runtime_bridge.cc').read_text()
observer = source[source.index('class ShellLoadingUiState'):source.index('bool ShouldShowShellLoading')]
assert 'tab.Set("loading", ShouldShowShellLoading(contents));' in source
assert 'const bool show_loading = ShouldShowShellLoading(active);' in source
assert 'show_loading ? active->GetLoadProgress() : 1.0' in source
harness = r'''
#include <cassert>
#include <cstdint>
#include <optional>
#define WEB_CONTENTS_USER_DATA_KEY_DECL()
#define WEB_CONTENTS_USER_DATA_KEY_IMPL(T)
int updates = 0;
void RequestBrowserStateUpdate() { ++updates; }
namespace content {
struct NavigationHandle {
  int64_t id; bool cached = false, primary = true, committed = false;
  bool IsInPrimaryMainFrame() { return primary; }
  bool IsServedFromBackForwardCache() { return cached; }
  bool HasCommitted() { return committed; }
  int64_t GetNavigationId() { return id; }
};
struct WebContents { bool ui = false; bool ShouldShowLoadingUI() { return ui; } };
struct WebContentsObserver {
  explicit WebContentsObserver(WebContents* c) : contents(c) {}
  virtual ~WebContentsObserver() = default;
  WebContents* web_contents() const { return contents; }
  virtual void DidStartNavigation(NavigationHandle*) {}
  virtual void DidFinishNavigation(NavigationHandle*) {}
  virtual void DidStopLoading() {}
  WebContents* contents;
};
template<class T> class WebContentsUserData {
 public:
  explicit WebContentsUserData(WebContents&) {}
  static T Make(WebContents* contents) { return T(contents); }
};
}
OBSERVER
int main() {
  content::WebContents contents;
  auto state = content::WebContentsUserData<ShellLoadingUiState>::Make(&contents);
  assert(!state.ShouldShow());
  contents.ui = true;
  content::NavigationHandle network{1};
  state.DidStartNavigation(&network);
  assert(state.ShouldShow());  // Reload, network history and first visits.
  content::NavigationHandle restore{2, true};
  state.DidStartNavigation(&restore);
  assert(!state.ShouldShow());
  content::NavigationHandle subframe{3, false, false};
  state.DidStartNavigation(&subframe);
  state.DidFinishNavigation(&subframe);
  assert(!state.ShouldShow());
  network.committed = true;
  state.DidFinishNavigation(&network);  // Late result from the previous request.
  assert(!state.ShouldShow());
  restore.committed = true;
  state.DidFinishNavigation(&restore);
  assert(!state.ShouldShow());  // No one-frame spinner just after restore commit.
  contents.ui = false;
  state.DidStopLoading();
  assert(!state.ShouldShow());
  contents.ui = true;
  state.DidStartNavigation(&network);
  assert(state.ShouldShow());
  // Eviction/security rejection aborts the restore and restarts a normal load.
  restore.committed = false;
  state.DidStartNavigation(&restore);
  state.DidFinishNavigation(&restore);
  state.DidStartNavigation(&network);
  assert(state.ShouldShow());
  // A newer restore survives the older restore's cancellation callback.
  content::NavigationHandle newer{4, true};
  state.DidStartNavigation(&restore);
  state.DidStartNavigation(&newer);
  state.DidFinishNavigation(&restore);
  assert(!state.ShouldShow());
  // A new navigation (including Navigation API intercept) clears suppression.
  content::NavigationHandle intercepted{5};
  state.DidStartNavigation(&intercepted);
  assert(state.ShouldShow());
  // Chromium can report loading without requesting UI for same-document work.
  contents.ui = false;
  assert(!state.ShouldShow());
  // Defensive: a restore that committed without BFCache cannot retain the gate.
  contents.ui = true;
  state.DidStartNavigation(&newer);
  newer.cached = false; newer.committed = true;
  state.DidFinishNavigation(&newer);
  assert(state.ShouldShow());
  assert(updates > 0);
}
'''.replace('OBSERVER', observer)
with tempfile.TemporaryDirectory(prefix='history-loading-') as tmp:
    code = Path(tmp) / 'test.cc'; binary = Path(tmp) / 'test'
    code.write_text(harness)
    subprocess.run([os.environ.get('CXX', 'c++'), '-std=c++20', '-Wall', '-Wextra', '-Werror',
                    '-fsanitize=address,undefined', str(code), '-o', str(binary)], check=True)
    subprocess.run([str(binary)], check=True)
print('PASS history loading UI: restore, commit, cancellation, eviction fallback and overlapping navigation')
