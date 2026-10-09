// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_PERFORMANCE_MANAGER_POLICIES_OHOS_TAB_DISCARDING_POLICY_H_
#define CHROME_BROWSER_PERFORMANCE_MANAGER_POLICIES_OHOS_TAB_DISCARDING_POLICY_H_

#include <stddef.h>

#include <memory>
#include <string>
#include <vector>

#include "base/time/time.h"
#include "base/timer/timer.h"
#include "base/values.h"
#include "components/performance_manager/public/graph/graph.h"
#include "components/performance_manager/public/graph/page_node.h"

namespace ohos_system_service {
class EventSubscription;
}  // namespace ohos_system_service

namespace performance_manager::policies {

// Keeps the number of loaded tabs down on HarmonyOS, where running out of
// memory gets the whole browser killed -- on a phone every tab lives in one
// process -- and where the platform tells only the app, never Chromium, that
// memory is short.
//
// Three triggers, all discarding background tabs Chromium's own eligibility
// rules allow (never the active tab, one playing or capturing media, one
// with a form being filled in, ...), least recently seen first:
//  - more tabs loaded than the device keeps: the oldest go;
//  - a tab not looked at for long enough goes;
//  - HarmonyOS reports memory LOW (one goes) or CRITICAL (all that may go),
//    which is also passed on as memory pressure so pages drop their caches.
// A discarded tab keeps its title, icon and history, and loads again when it
// is activated.
class OhosTabDiscardingPolicy : public GraphOwned, public PageNodeObserver {
 public:
  struct Limits {
    // Tabs kept loaded, the active one included.
    size_t max_loaded_tabs = 0;
    // A background tab unseen for this long is discarded.
    base::TimeDelta max_hidden_time;
    // Restored background tabs loaded at startup. The rest wait to be opened.
    size_t max_restored_background_loads = 0;
  };

  // The phone runs single-process, so it is told apart from tablets and PCs
  // by that.
  static Limits LimitsForThisDevice();

  explicit OhosTabDiscardingPolicy(Limits limits);
  OhosTabDiscardingPolicy(const OhosTabDiscardingPolicy&) = delete;
  OhosTabDiscardingPolicy& operator=(const OhosTabDiscardingPolicy&) = delete;
  ~OhosTabDiscardingPolicy() override;

  // GraphOwned:
  void OnPassedToGraph(Graph* graph) override;
  void OnTakenFromGraph(Graph* graph) override;

  // PageNodeObserver:
  void OnPageNodeAdded(const PageNode* page_node) override;
  void OnTypeChanged(const PageNode* page_node, PageType previous_type) override;
  void OnIsVisibleChanged(const PageNode* page_node) override;
  void OnMainFrameDocumentChanged(const PageNode* page_node) override;

 private:
  void ScheduleEnforce();
  void Enforce();
  void OnSystemServiceEvent(const std::string& event,
                            const base::DictValue& data);
  void OnMemoryLevel(int level);
  void ReleaseMemoryPressure();

  // Tabs with a page in them, visible or not.
  std::vector<const PageNode*> LoadedTabs() const;
  // Of `tabs`, the hidden ones that may be discarded for `reason`, least
  // recently visible first.
  std::vector<const PageNode*> DiscardableOldestFirst(
      const std::vector<const PageNode*>& tabs,
      bool urgent) const;
  void Discard(const std::vector<const PageNode*>& pages,
               bool urgent,
               const char* why);

  const Limits limits_;
  // Folds the burst of changes one tab switch makes into one pass.
  base::OneShotTimer enforce_timer_;
  // Finds tabs that have gone unseen too long without anything changing.
  base::RepeatingTimer hidden_check_timer_;
  // HarmonyOS never reports that memory is fine again, so pressure passed on
  // to Chromium is withdrawn after a while instead.
  base::OneShotTimer pressure_release_timer_;
  base::TimeTicks last_memory_discard_;
  std::unique_ptr<ohos_system_service::EventSubscription> memory_events_;
};

}  // namespace performance_manager::policies

#endif  // CHROME_BROWSER_PERFORMANCE_MANAGER_POLICIES_OHOS_TAB_DISCARDING_POLICY_H_
