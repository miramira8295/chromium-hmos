// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/performance_manager/policies/ohos_tab_discarding_policy.h"

#include <algorithm>
#include <optional>
#include <utility>

#include "base/command_line.h"
#include "base/functional/bind.h"
#include "base/logging.h"
#include "base/memory/memory_pressure_level.h"
#include "base/memory/memory_pressure_listener.h"
#include "base/memory/weak_ptr.h"
#include "chrome/browser/performance_manager/policies/discard_eligibility_policy.h"
#include "chrome/browser/performance_manager/policies/page_discarding_helper.h"
#include "components/ohos_system_service/system_service_ohos.h"
#include "components/performance_manager/public/decorators/page_live_state_decorator.h"
#include "content/public/browser/navigation_controller.h"
#include "content/public/browser/web_contents.h"
#include "content/public/common/content_switches.h"

namespace performance_manager::policies {

namespace {

using DiscardReason = DiscardEligibilityPolicy::DiscardReason;

// AbilityConstant.MemoryLevel. The BACKGROUND_* levels (API 24) come while
// the app is in the background; UI_HIDDEN and BACKGROUND_MODERATE say
// nothing about memory being short and are ignored.
enum MemoryLevel {
  kMemoryLevelModerate = 0,
  kMemoryLevelLow = 1,
  kMemoryLevelCritical = 2,
  kMemoryLevelBackgroundLow = 5,
  kMemoryLevelBackgroundCritical = 6,
};

// Phone: one process for every tab, so its limit is the browser's.
constexpr OhosTabDiscardingPolicy::Limits kPhoneLimits = {
    .max_loaded_tabs = 5,
    .max_hidden_time = base::Minutes(30),
    .max_restored_background_loads = 0,
};
constexpr OhosTabDiscardingPolicy::Limits kTabletLimits = {
    .max_loaded_tabs = 10,
    .max_hidden_time = base::Minutes(60),
    .max_restored_background_loads = 3,
};

// After a switch, the tab left behind is hidden before the next one is
// shown. Waiting folds that into one pass, and keeps a quick look at another
// tab and back from costing anything.
constexpr base::TimeDelta kEnforceDelay = base::Seconds(5);
constexpr base::TimeDelta kHiddenCheckPeriod = base::Minutes(1);
// HarmonyOS may report the same level several times in a row; one report's
// worth of discarding is enough until memory has had time to come back.
constexpr base::TimeDelta kMemoryDiscardInterval = base::Seconds(10);
// How long pressure passed on to Chromium stands without another report.
constexpr base::TimeDelta kPressureHoldTime = base::Seconds(10);

constexpr char kMemoryLevelService[] = "memorylevel";

}  // namespace

// static
OhosTabDiscardingPolicy::Limits OhosTabDiscardingPolicy::LimitsForThisDevice() {
  return base::CommandLine::ForCurrentProcess()->HasSwitch(
             switches::kSingleProcess)
             ? kPhoneLimits
             : kTabletLimits;
}

OhosTabDiscardingPolicy::OhosTabDiscardingPolicy(Limits limits)
    : limits_(limits) {}

OhosTabDiscardingPolicy::~OhosTabDiscardingPolicy() = default;

void OhosTabDiscardingPolicy::OnPassedToGraph(Graph* graph) {
  graph->AddPageNodeObserver(this);
  hidden_check_timer_.Start(FROM_HERE, kHiddenCheckPeriod, this,
                            &OhosTabDiscardingPolicy::Enforce);
  memory_events_ = ohos_system_service::SubscribeToEvents(
      kMemoryLevelService,
      base::BindRepeating(&OhosTabDiscardingPolicy::OnSystemServiceEvent,
                          base::Unretained(this)));
  LOG(WARNING) << "OHOS tab discard: keeping " << limits_.max_loaded_tabs
            << " tabs loaded, hidden ones for "
            << limits_.max_hidden_time.InMinutes() << " min";
}

void OhosTabDiscardingPolicy::OnTakenFromGraph(Graph* graph) {
  memory_events_.reset();
  pressure_release_timer_.Stop();
  hidden_check_timer_.Stop();
  enforce_timer_.Stop();
  graph->RemovePageNodeObserver(this);
}

void OhosTabDiscardingPolicy::OnPageNodeAdded(const PageNode* page_node) {
  ScheduleEnforce();
}

void OhosTabDiscardingPolicy::OnTypeChanged(const PageNode* page_node,
                                            PageType previous_type) {
  ScheduleEnforce();
}

void OhosTabDiscardingPolicy::OnIsVisibleChanged(const PageNode* page_node) {
  ScheduleEnforce();
}

void OhosTabDiscardingPolicy::OnMainFrameDocumentChanged(
    const PageNode* page_node) {
  // A discarded or restored tab loading again is one more tab loaded.
  ScheduleEnforce();
}

void OhosTabDiscardingPolicy::ScheduleEnforce() {
  if (!enforce_timer_.IsRunning()) {
    enforce_timer_.Start(FROM_HERE, kEnforceDelay, this,
                         &OhosTabDiscardingPolicy::Enforce);
  }
}

void OhosTabDiscardingPolicy::Enforce() {
  enforce_timer_.Stop();
  const std::vector<const PageNode*> loaded = LoadedTabs();
  const std::vector<const PageNode*> candidates =
      DiscardableOldestFirst(loaded, /*urgent=*/false);

  const base::TimeTicks now = base::TimeTicks::Now();
  const size_t over_limit = loaded.size() > limits_.max_loaded_tabs
                                ? loaded.size() - limits_.max_loaded_tabs
                                : 0;
  std::vector<const PageNode*> victims;
  for (const PageNode* page : candidates) {
    if (victims.size() < over_limit ||
        now - page->GetLastVisibilityChangeTime() >= limits_.max_hidden_time) {
      victims.push_back(page);
    }
  }
  if (victims.empty()) {
    return;
  }
  LOG(WARNING) << "OHOS tab discard: " << loaded.size() << " loaded, limit "
            << limits_.max_loaded_tabs << ", " << candidates.size()
            << " discardable";
  Discard(victims, /*urgent=*/false,
          over_limit ? "over the loaded tab limit" : "hidden too long");
}

void OhosTabDiscardingPolicy::OnSystemServiceEvent(
    const std::string& event,
    const base::DictValue& data) {
  if (event != "level") {
    return;
  }
  const std::optional<int> level = data.FindInt("level");
  if (!level) {
    LOG(WARNING) << "OHOS tab discard: memory level event without a level";
    return;
  }
  OnMemoryLevel(*level);
}

void OhosTabDiscardingPolicy::OnMemoryLevel(int level) {
  base::MemoryPressureLevel pressure;
  bool discard_all = false;
  switch (level) {
    case kMemoryLevelModerate:
      pressure = base::MEMORY_PRESSURE_LEVEL_MODERATE;
      break;
    case kMemoryLevelLow:
    case kMemoryLevelBackgroundLow:
      pressure = base::MEMORY_PRESSURE_LEVEL_MODERATE;
      break;
    case kMemoryLevelCritical:
    case kMemoryLevelBackgroundCritical:
      pressure = base::MEMORY_PRESSURE_LEVEL_CRITICAL;
      discard_all = true;
      break;
    default:
      LOG(INFO) << "OHOS tab discard: memory level " << level << " ignored";
      return;
  }
  LOG(WARNING) << "OHOS tab discard: system memory level " << level;

  // Pages drop caches and collect garbage on this, the cheap part, first.
  base::MemoryPressureListener::NotifyMemoryPressure(pressure);
  pressure_release_timer_.Start(
      FROM_HERE, kPressureHoldTime, this,
      &OhosTabDiscardingPolicy::ReleaseMemoryPressure);

  if (level == kMemoryLevelModerate) {
    return;
  }
  const base::TimeTicks now = base::TimeTicks::Now();
  if (!last_memory_discard_.is_null() &&
      now - last_memory_discard_ < kMemoryDiscardInterval) {
    return;
  }
  last_memory_discard_ = now;

  std::vector<const PageNode*> victims =
      DiscardableOldestFirst(LoadedTabs(), /*urgent=*/true);
  if (!discard_all && victims.size() > 1) {
    victims.resize(1);
  }
  Discard(victims, /*urgent=*/true,
          discard_all ? "memory critical" : "memory low");
}

void OhosTabDiscardingPolicy::ReleaseMemoryPressure() {
  base::MemoryPressureListener::NotifyMemoryPressure(
      base::MEMORY_PRESSURE_LEVEL_NONE);
}

std::vector<const PageNode*> OhosTabDiscardingPolicy::LoadedTabs() const {
  std::vector<const PageNode*> loaded;
  for (const PageNode* page : GetOwningGraph()->GetAllPageNodes()) {
    if (page->GetType() != PageType::kTab ||
        !page->GetPrimaryMainFrameNode()) {
      // No main frame: discarded or crashed.
      continue;
    }
    const auto* live_state = PageLiveStateDecorator::Data::FromPageNode(page);
    if (live_state && live_state->IsDiscarded()) {
      continue;
    }
    // A restored tab not opened since can have a main frame too -- its empty
    // first document -- but no page. Counted, thirty restored tabs read as
    // thirty loaded on a phone, and twenty-five were discarded at startup for
    // nothing.
    const base::WeakPtr<content::WebContents> contents =
        page->GetWebContents();
    if (!contents || contents->GetController().NeedsReload() ||
        page->GetMainFrameUrl().is_empty()) {
      continue;
    }
    loaded.push_back(page);
  }
  return loaded;
}

std::vector<const PageNode*> OhosTabDiscardingPolicy::DiscardableOldestFirst(
    const std::vector<const PageNode*>& tabs,
    bool urgent) const {
  const auto* eligibility =
      DiscardEligibilityPolicy::GetFromGraph(GetOwningGraph());
  if (!eligibility) {
    return {};
  }
  std::vector<const PageNode*> discardable;
  for (const PageNode* page : tabs) {
    // Recent visibility is not a protection here: the oldest go first, so a
    // tab just left is the last one picked, and only when it is over the
    // limit.
    if (!page->IsVisible() &&
        eligibility->CanDiscard(
            page, urgent ? DiscardReason::URGENT : DiscardReason::PROACTIVE,
            /*ignore_recent_visibility=*/true) == CanDiscardResult::kEligible) {
      discardable.push_back(page);
    }
  }
  std::sort(discardable.begin(), discardable.end(),
            [](const PageNode* a, const PageNode* b) {
              return a->GetLastVisibilityChangeTime() <
                     b->GetLastVisibilityChangeTime();
            });
  return discardable;
}

void OhosTabDiscardingPolicy::Discard(const std::vector<const PageNode*>& pages,
                                      bool urgent,
                                      const char* why) {
  if (pages.empty()) {
    LOG(WARNING) << "OHOS tab discard: nothing may be discarded (" << why << ")";
    return;
  }
  auto* helper = PageDiscardingHelper::GetFromGraph(GetOwningGraph());
  if (!helper) {
    LOG(ERROR) << "OHOS tab discard: no PageDiscardingHelper";
    return;
  }
  const bool discarded = helper->ImmediatelyDiscardMultiplePages(
      pages, urgent ? DiscardReason::URGENT : DiscardReason::PROACTIVE,
      /*ignore_recent_visibility=*/true);
  // The URL is left out: it is the user's browsing.
  LOG(WARNING) << "OHOS tab discard: " << pages.size() << " tab(s) " << why
               << (discarded ? ", discarded" : ", discard failed");
}

}  // namespace performance_manager::policies
