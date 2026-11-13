#!/usr/bin/env python3
"""Compile the production BFCache condition with navigation/service doubles.

Exercises asynchronous callbacks, cancellation, policy races and synchronous
owner destruction under sanitizers. This is not a Chromium browser test: the
157 native build validates APIs; real BFCache/rendering needs engine regression.
"""
import os
from pathlib import Path
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[2]
source = (ROOT / 'overlay/chrome/browser/ohos/url_protection/navigation_throttle.cc').read_text()
condition = source[source.index('class BackForwardCacheCheck :'):source.index('struct OneNavigationBypass :')]
factory = source[source.index('std::unique_ptr<content::CommitDeferringCondition>\nMaybeCreateBackForwardCacheCheck'):source.index('void NavigationThrottle::MaybeCreateAndAdd')]
# Cross-file integration contracts supplement (not replace) the executable tests.
assert 'ProtectCurrentDocument' not in source
assert 'GetBackForwardCache().Flush()' in source
assert 'CancelAllPrerendering()' in source
patch = (ROOT / 'patches/migration-157/chromium.patch').read_text()
assert '+      chrome::ohos::url_protection::MaybeCreateBackForwardCacheCheck(' in patch

prelude = r'''
#include <cassert>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#define VLOG(level) std::clog
using GURL = std::string;
namespace base {
inline int now = 0;
struct TimeDelta { int value = 0; int InMilliseconds() const { return value; } };
TimeDelta Milliseconds(int n) { return {n}; }
struct TimeTicks { int value = 0; static TimeTicks Now() { return {now}; } };
TimeTicks operator+(TimeTicks a, TimeDelta b) { return {a.value+b.value}; }
TimeTicks operator-(TimeTicks a, TimeDelta b) { return {a.value-b.value}; }
TimeDelta operator-(TimeTicks a, TimeTicks b) { return {a.value-b.value}; }
template<class T> struct WeakPtr {
  T* pointer = nullptr; std::weak_ptr<int> generation; int expected = 0;
  explicit operator bool() const {
    auto g = generation.lock(); return g && *g == expected;
  }
  T* operator->() const { assert(bool(*this)); return pointer; }
};
template<class T> struct WeakPtrFactory {
  T* pointer; std::shared_ptr<int> generation = std::make_shared<int>(0);
  void InvalidateWeakPtrs() { ++*generation; }
  WeakPtr<T> GetWeakPtr() { return {pointer, generation, *generation}; }
};
struct OnceClosure {
  std::function<void()> f;
  OnceClosure() = default;
  OnceClosure(std::function<void()> fn) : f(std::move(fn)) {}
  OnceClosure(OnceClosure&&) = default;
  OnceClosure& operator=(OnceClosure&&) = default;
  explicit operator bool() const { return bool(f); }
  void Reset() { f = {}; }
  void Run() { auto fn = std::move(f); f = {}; assert(fn); fn(); }
};
struct CallbackListSubscription {
  std::shared_ptr<bool> alive;
  CallbackListSubscription() = default;
  explicit CallbackListSubscription(std::shared_ptr<bool> a) : alive(a) {}
  CallbackListSubscription(CallbackListSubscription&&) = default;
  CallbackListSubscription& operator=(CallbackListSubscription&&) = default;
  ~CallbackListSubscription() { if (alive) *alive = false; }
};
template<class T> T* Unretained(T* p) { return p; }
template<class T> auto BindRepeating(void (T::*method)(), T* p) {
  return [=] { (p->*method)(); };
}
template<class T, class R> auto BindOnce(void (T::*method)(int, R), WeakPtr<T> p, int n) {
  return [=](R result) { if (p) (p.pointer->*method)(n, std::move(result)); };
}
}
namespace content {
struct RenderFrameHost { int id; };
struct WebContents {
  int removed = 0; void* GetBrowserContext() { return nullptr; }
  void RemoveUserData(const char*) { ++removed; }
};
struct NavigationHandle {
  WebContents contents;
  RenderFrameHost target{2}, current{3};
  bool primary = true, cached = true;
  GURL url = "https://example.test/b";
  WebContents* GetWebContents() { return &contents; }
  const GURL& GetURL() const { return url; }
  int GetNavigationId() { return 7; }
  RenderFrameHost* GetRenderFrameHost() { return &target; }
  bool IsInPrimaryMainFrame() { return primary; }
  bool IsServedFromBackForwardCache() { return cached; }
};
class CommitDeferringCondition {
 public:
  enum class Result { kProceed, kDefer, kCancelled };
  explicit CommitDeferringCondition(NavigationHandle& h) : handle(h) {}
  virtual ~CommitDeferringCondition() = default;
  virtual Result WillCommitNavigation(base::OnceClosure) = 0;
  virtual const char* TraceEventName() const = 0;
  NavigationHandle& GetNavigationHandle() const { return handle; }
 private:
  NavigationHandle& handle;
};
struct BackForwardCache {
  enum class DisabledSource { kEmbedder };
  struct DisabledReason { DisabledReason(DisabledSource, int, const char*, const char*, const char*) {} };
  static inline RenderFrameHost* evicted = nullptr;
  static inline std::function<void()> destroy;
  static void DisableForRenderFrameHost(RenderFrameHost* frame, DisabledReason) {
    evicted = frame;
    assert(destroy);
    destroy();  // Real Chromium destroys the condition synchronously here.
  }
};
}
struct Profile { static Profile* FromBrowserContext(void*) { return nullptr; } };
namespace chrome::ohos::url_protection {
constexpr char kBypassKey[] = "bypass";
enum class Verdict { kUnknown, kNoMatch, kPhishing };
struct Result {
  Verdict verdict; std::string source, reason; GURL url;
  bool dangerous() const { return verdict == Verdict::kPhishing; }
};
bool IsPublicHttpUrl(const GURL& url) { return url.starts_with("https://"); }
struct Service {
  static inline Service* instance;
  bool enabled_ = true, site_enabled = true;
  int revision_ = 1, cancelled = 0, next = 0;
  std::vector<int> budgets;
  using Callback = std::function<void(Result)>;
  struct Request { Callback callback; GURL url; };
  std::map<std::string, Request> pending;
  std::vector<std::function<void()>> posted;
  std::vector<std::pair<std::shared_ptr<bool>, std::function<void()>>> observers;
  base::WeakPtrFactory<Service> weak{this};
  Service() { instance = this; }
  static Service* Get(Profile*) { return instance; }
  auto GetWeakPtr() { return weak.GetWeakPtr(); }
  bool enabled() const { return enabled_; }
  bool IsSiteEnabled(const GURL&) const { return site_enabled; }
  int revision() const { return revision_; }
  auto Observe(std::function<void()> fn) {
    auto flag = std::make_shared<bool>(true); observers.emplace_back(flag, std::move(fn));
    return base::CallbackListSubscription(flag);
  }
  void Policy() {
    ++revision_;
    auto snapshot = observers;
    for (auto& [flag, fn] : snapshot) if (*flag) fn();
  }
  std::string Check(const GURL& url, base::TimeDelta timeout, Callback callback) {
    budgets.push_back(timeout.value);
    auto id = std::to_string(++next);
    pending.emplace(id, Request{std::move(callback), url});
    return id;
  }
  void Complete(std::string id, Verdict verdict) {
    auto req = std::move(pending.at(id)); pending.erase(id);
    posted.push_back([req = std::move(req), verdict] {
      req.callback({verdict, {}, {}, req.url});
    });
  }
  void Cancel(const std::string& id) {
    ++cancelled;
    if (pending.contains(id)) Complete(id, Verdict::kUnknown);
  }
  void Run() {
    auto tasks = std::move(posted); posted.clear();
    for (auto& task : tasks) task();
  }
};
struct TabProtection {
  static inline int reports = 0, begins = 0;
  static inline bool checking = false;
  static inline Verdict verdict = Verdict::kUnknown;
  static void CreateForWebContents(content::WebContents*) {}
  static TabProtection* FromWebContents(content::WebContents*) { static TabProtection tab; return &tab; }
  void Begin(content::NavigationHandle*) { ++begins; }
  void Report(content::NavigationHandle*, const Result& result, bool pending) {
    ++reports; checking = pending; verdict = result.verdict;
  }
};
'''
tests = r'''
} // namespace chrome::ohos::url_protection
using namespace chrome::ohos::url_protection;
using Decision = content::CommitDeferringCondition::Result;
base::OnceClosure Closure(std::function<void()> fn) { return base::OnceClosure(std::move(fn)); }
int main() {
  for (int mode = 0; mode < 2; ++mode) {
    Service s; content::NavigationHandle h;
    if (mode == 0) h.primary = false; else h.cached = false;
    assert(!MaybeCreateBackForwardCacheCheck(h));
  }
  for (int mode = 0; mode < 3; ++mode) {
    Service s; content::NavigationHandle h;
    if (mode == 0) s.enabled_ = false;
    if (mode == 1) s.site_enabled = false;
    if (mode == 2) h.url = "chrome://newtab";
    auto c = MaybeCreateBackForwardCacheCheck(h);
    assert(c && c->WillCommitNavigation(Closure([] { assert(false); })) == Decision::kProceed);
    assert(s.pending.empty() && h.contents.removed == 1);
  }
  // Allowed/timeout results resume exactly once; resume may destroy the owner.
  for (auto verdict : {Verdict::kNoMatch, Verdict::kUnknown}) {
    Service s; content::NavigationHandle h; int resumed = 0;
    auto c = MaybeCreateBackForwardCacheCheck(h);
    assert(c->WillCommitNavigation(Closure([&] { ++resumed; c.reset(); })) == Decision::kDefer);
    assert(resumed == 0 && TabProtection::checking);
    s.Complete("1", verdict); s.Run(); s.Run();
    assert(resumed == 1 && !c && !TabProtection::checking);
  }
  // Risk must evict B, never C, and must never call resume after synchronous deletion.
  {
    Service s; content::NavigationHandle h;
    auto c = MaybeCreateBackForwardCacheCheck(h);
    content::BackForwardCache::destroy = [&] { c.reset(); };
    c->WillCommitNavigation(Closure([] { assert(false); }));
    s.Complete("1", Verdict::kPhishing); s.Run();
    assert(!c && content::BackForwardCache::evicted == &h.target);
    assert(TabProtection::verdict == Verdict::kPhishing);
  }
  // Destruction rejects both pending cancellation callbacks and already-posted results.
  for (bool posted : {false, true}) {
    Service s; content::NavigationHandle h;
    auto c = MaybeCreateBackForwardCacheCheck(h);
    c->WillCommitNavigation(Closure([] { assert(false); }));
    if (posted) s.Complete("1", Verdict::kPhishing);
    c.reset(); const int reports = TabProtection::reports;
    s.Run(); assert(reports == TabProtection::reports && s.cancelled == 1);
  }
  // Disable while a risky result is queued: cancel old result and resume only once.
  {
    Service s; content::NavigationHandle h; int resumed = 0;
    auto c = MaybeCreateBackForwardCacheCheck(h);
    c->WillCommitNavigation(Closure([&] { ++resumed; }));
    s.Complete("1", Verdict::kPhishing);
    s.enabled_ = false; s.Policy(); s.Run(); s.Policy();
    assert(resumed == 1 && !TabProtection::checking);
  }
  // Policy changed before condition execution: no premature resume/check.
  {
    Service s; content::NavigationHandle h;
    auto c = MaybeCreateBackForwardCacheCheck(h);
    s.enabled_ = false; s.Policy();
    assert(s.pending.empty());
    assert(c->WillCommitNavigation(Closure([] { assert(false); })) == Decision::kProceed);
  }
  // If not evicted by an earlier observer, restart within the ORIGINAL budget.
  {
    Service s; content::NavigationHandle h; int resumed = 0;
    base::now = 100;
    auto c = MaybeCreateBackForwardCacheCheck(h);
    c->WillCommitNavigation(Closure([&] { ++resumed; }));
    s.Complete("1", Verdict::kPhishing);
    base::now = 1100; s.Policy(); s.Run();
    assert(resumed == 0 && (s.budgets == std::vector<int>{1500, 500}));
    base::now = 1700; s.Policy(); s.Run();
    assert(resumed == 0 && s.budgets.back() == -100);
    s.Complete("3", Verdict::kUnknown); s.Run();
    assert(resumed == 1);
  }
  // Model the earlier TabProtection policy observer evicting the restore.
  // The removed condition observer must not run in the same notification pass.
  {
    Service s; content::NavigationHandle h;
    std::unique_ptr<content::CommitDeferringCondition> c;
    auto subscription = s.Observe([&] { c.reset(); });
    c = MaybeCreateBackForwardCacheCheck(h);
    c->WillCommitNavigation(Closure([] { assert(false); }));
    s.Policy(); s.Run();
    assert(!c && s.cancelled == 1 && s.budgets.size() == 1);
  }
  std::cout << "PASS BFCache production condition: policy, budget, risk target, cancellation and owner destruction\n";
}
'''
with tempfile.TemporaryDirectory(prefix='bfcache-protection-') as tmp:
    unit = Path(tmp) / 'test.cc'; binary = Path(tmp) / 'test'
    unit.write_text(prelude + condition + factory + tests)
    subprocess.run([os.environ.get('CXX', 'c++'), '-std=c++20', '-Wall', '-Wextra', '-Werror',
                    '-fsanitize=address,undefined', str(unit), '-o', str(binary)], check=True)
    subprocess.run([str(binary)], check=True)
