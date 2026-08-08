// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/ohos/aura_shell_runtime_bridge.h"

#include <algorithm>
#include <optional>
#include <set>
#include <string_view>
#include <utility>
#include <variant>

#include "base/command_line.h"
#include "base/containers/span.h"
#include "base/files/file_path.h"
#include "base/files/file_util.h"
#include "base/functional/bind.h"
#include "base/functional/callback.h"
#include "base/json/json_reader.h"
#include "base/json/json_writer.h"
#include "base/location.h"
#include "base/logging.h"
#include "base/memory/ref_counted_memory.h"
#include "base/memory/scoped_refptr.h"
#include "base/no_destructor.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/synchronization/lock.h"
#include "base/task/single_thread_task_runner.h"
#include "base/task/thread_pool.h"
#include "base/time/time.h"
#include "base/values.h"
#include "chrome/browser/lifetime/application_lifetime.h"
#include "chrome/browser/printing/print_view_manager.h"
#include "chrome/browser/ui/browser.h"
#include "chrome/browser/ui/browser_window/public/browser_window_interface.h"
#include "chrome/browser/ui/browser_window/public/global_browser_collection.h"
#include "chrome/browser/ui/tabs/tab_enums.h"
#include "chrome/browser/ui/tabs/tab_strip_model.h"
#include "chrome/browser/ui/views/frame/browser_view.h"
#include "chrome/browser/ui/views/frame/toolbar_button_provider.h"
#include "chrome/browser/ui/views/toolbar/app_menu_control.h"
#include "chrome/browser/web_applications/web_app_provider.h"
#include "chrome/browser/web_applications/web_app_registrar.h"
#include "chrome/browser/web_applications/web_app_tab_helper.h"
#include "components/embedder_support/user_agent_utils.h"
#include "components/printing/browser/print_to_pdf/pdf_print_result.h"
#include "components/printing/browser/print_to_pdf/pdf_print_utils.h"
#include "content/public/browser/navigation_controller.h"
#include "content/public/browser/page_navigator.h"
#include "content/public/browser/render_frame_host.h"
#include "content/public/browser/render_process_host.h"
#include "content/public/browser/web_contents.h"
#include "content/public/common/content_switches.h"
#include "content/public/common/referrer.h"
#include "content/public/renderer/render_thread.h"
#include "skia/ext/font_utils.h"
#include "ui/base/base_window.h"
#include "ui/base/page_transition_types.h"
#include "ui/base/pointer/touch_ui_controller.h"
#include "ui/base/resource/resource_bundle.h"
#include "ui/base/window_open_disposition.h"
#include "ui/native_theme/native_theme.h"
#include "ui/shell_dialogs/select_file_dialog_ohos.h"
#include "url/gurl.h"

namespace chrome::ohos {
namespace {

constexpr int kMaxBrowserLookupAttempts = 50;
constexpr base::TimeDelta kBrowserLookupDelay = base::Milliseconds(100);
constexpr base::TimeDelta kThemeFontRendererRestartDelay =
    base::Milliseconds(250);
constexpr base::TimeDelta kBrowserStatePollInterval = base::Milliseconds(200);

struct RuntimeBridgeState {
  base::Lock lock;
  scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner GUARDED_BY(lock);
  std::optional<GURL> pending_url GUARDED_BY(lock);
  std::optional<std::string> pending_theme_font_id GUARDED_BY(lock);
  std::string ui_family GUARDED_BY(lock) = "mobile_phone";
  std::string color_scheme GUARDED_BY(lock) = "light";
  std::string print_output_directory GUARDED_BY(lock);
  AuraShellBrowserStateCallback browser_state_callback GUARDED_BY(lock);
  std::string last_browser_state_json GUARDED_BY(lock);
  uint64_t browser_generation GUARDED_BY(lock) = 0;
  bool app_visible GUARDED_BY(lock) = true;
  bool app_focused GUARDED_BY(lock) = true;
  bool pending_shutdown GUARDED_BY(lock) = false;
};

RuntimeBridgeState& GetState() {
  static base::NoDestructor<RuntimeBridgeState> state;
  return *state;
}

BrowserWindowInterface* GetActiveBrowser() {
  GlobalBrowserCollection* browsers = GlobalBrowserCollection::GetInstance();
  return browsers ? browsers->GetLastActiveBrowser() : nullptr;
}

void DispatchRuntimeEvent(base::DictValue event) {
  event.Set("version", 1);
  std::string event_json;
  if (!base::JSONWriter::Write(event, &event_json)) {
    return;
  }

  AuraShellBrowserStateCallback callback;
  {
    RuntimeBridgeState& state = GetState();
    base::AutoLock lock(state.lock);
    callback = state.browser_state_callback;
  }
  if (callback) {
    callback.Run(event_json);
  }
}

void DispatchPrintFailure(std::string reason) {
  base::DictValue event;
  event.Set("event", "systemPrintFailed");
  event.Set("reason", std::move(reason));
  DispatchRuntimeEvent(std::move(event));
}

const char* FilePickerTypeName(ui::SelectFileDialog::Type type) {
  switch (type) {
    case ui::SelectFileDialog::SELECT_FOLDER:
    case ui::SelectFileDialog::SELECT_UPLOAD_FOLDER:
    case ui::SelectFileDialog::SELECT_EXISTING_FOLDER:
      return "folder";
    case ui::SelectFileDialog::SELECT_SAVEAS_FILE:
      return "save";
    case ui::SelectFileDialog::SELECT_OPEN_MULTI_FILE:
      return "openMultiple";
    case ui::SelectFileDialog::SELECT_OPEN_FILE:
      return "open";
    case ui::SelectFileDialog::SELECT_NONE:
      return "none";
  }
}

void DispatchFilePickerRequest(const ui::OhosSelectFileDialogRequest& request) {
  base::DictValue event;
  event.Set("event", "filePickerRequested");
  event.Set("requestId", request.request_id);
  event.Set("pickerType", FilePickerTypeName(request.type));
  event.Set("title", request.title);
  event.Set("defaultName", request.default_name);
  event.Set("fileTypeIndex", request.file_type_index);
  base::ListValue filters;
  for (const std::string& filter : request.suffix_filters) {
    filters.Append(filter);
  }
  event.Set("suffixFilters", std::move(filters));
  DispatchRuntimeEvent(std::move(event));
}

bool WritePdfFile(const base::FilePath& path,
                  scoped_refptr<base::RefCountedMemory> data) {
  return data && data->size() > 0 && base::CreateDirectory(path.DirName()) &&
         base::WriteFile(
             path, base::span<const uint8_t>(data->front(), data->size()));
}

void OnPdfFileWritten(base::FilePath path,
                      std::string title,
                      std::string url,
                      bool written) {
  if (!written) {
    DispatchPrintFailure("writePdfFailed");
    return;
  }
  base::DictValue event;
  event.Set("event", "systemPrintReady");
  event.Set("filePath", path.value());
  event.Set("title", std::move(title));
  event.Set("url", std::move(url));
  DispatchRuntimeEvent(std::move(event));
}

void OnPdfGenerated(base::FilePath path,
                    std::string title,
                    std::string url,
                    print_to_pdf::PdfPrintResult result,
                    scoped_refptr<base::RefCountedMemory> data) {
  if (result != print_to_pdf::PdfPrintResult::kPrintSuccess || !data) {
    DispatchPrintFailure(print_to_pdf::PdfPrintResultToString(result));
    return;
  }
  base::ThreadPool::PostTaskAndReplyWithResult(
      FROM_HERE, {base::MayBlock(), base::TaskPriority::USER_VISIBLE},
      base::BindOnce(&WritePdfFile, path, std::move(data)),
      base::BindOnce(&OnPdfFileWritten, std::move(path), std::move(title),
                     std::move(url)));
}

bool IsMobileUiFamily(std::string_view ui_family) {
  return ui_family == "mobile_phone";
}

blink::UserAgentOverride BuildOhosUserAgentOverride(bool mobile) {
  blink::UserAgentOverride ua_override;
  ua_override.ua_string_override =
      embedder_support::GetUserAgentForOhos(mobile);
  ua_override.ua_metadata_override =
      embedder_support::GetUserAgentMetadataForOhos(mobile);
  return ua_override;
}

bool ApplyUserAgentToWebContents(content::WebContents* contents,
                                 bool mobile,
                                 bool reload) {
  if (!contents) {
    return false;
  }
  const blink::UserAgentOverride desired = BuildOhosUserAgentOverride(mobile);
  if (contents->GetUserAgentOverride() == desired) {
    return false;
  }

  contents->SetUserAgentOverride(desired, /*override_in_new_tabs=*/true);
  if (reload && contents->GetController().GetLastCommittedEntry()) {
    contents->GetController().Reload(content::ReloadType::NORMAL,
                                     /*check_for_repost=*/false);
  }
  return true;
}

void ApplyUserAgentToAllTabs(bool mobile, bool reload) {
  GlobalBrowserCollection* browsers = GlobalBrowserCollection::GetInstance();
  if (!browsers) {
    return;
  }
  browsers->ForEach([mobile, reload](BrowserWindowInterface* browser) {
    TabStripModel* tabs = browser->GetTabStripModel();
    if (!tabs) {
      return true;
    }
    for (int index = 0; index < tabs->count(); ++index) {
      ApplyUserAgentToWebContents(tabs->GetWebContentsAt(index), mobile,
                                  reload);
    }
    return true;
  });
}

std::string BuildBrowserStateJson(std::string_view ui_family) {
  base::DictValue state;
  state.Set("version", 1);
  state.Set("mobileUi", IsMobileUiFamily(ui_family));
  state.Set("uiFamily", std::string(ui_family));
  state.Set("ready", false);
  state.Set("tabCount", 0);
  state.Set("activeTabIndex", -1);
  state.Set("tabs", base::ListValue());
  state.Set("url", "");
  state.Set("domain", "");
  state.Set("title", "");
  state.Set("loading", false);
  state.Set("canGoBack", false);
  state.Set("canGoForward", false);
  state.Set("isPwaWindow", false);
  state.Set("pwaAppId", "");
  state.Set("pwaStartUrl", "");

  BrowserWindowInterface* browser = GetActiveBrowser();
  TabStripModel* tabs = browser ? browser->GetTabStripModel() : nullptr;
  if (!tabs) {
    state.Set("ready", false);
    std::string json;
    base::JSONWriter::Write(state, &json);
    return json;
  }

  state.Set("ready", true);
  const bool is_pwa_window =
      browser->GetType() == BrowserWindowInterface::Type::TYPE_APP ||
      browser->GetType() == BrowserWindowInterface::Type::TYPE_APP_POPUP;
  state.Set("isPwaWindow", is_pwa_window);
  state.Set("tabCount", tabs->count());
  state.Set("activeTabIndex", tabs->active_index());
  base::ListValue tab_values;
  for (int index = 0; index < tabs->count(); ++index) {
    content::WebContents* contents = tabs->GetWebContentsAt(index);
    base::DictValue tab;
    tab.Set("index", index);
    tab.Set("active", index == tabs->active_index());
    tab.Set("url", "");
    tab.Set("title", "");
    tab.Set("loading", false);
    if (contents) {
      const GURL url = contents->GetVisibleURL();
      tab.Set("url", url.spec());
      tab.Set("title", base::UTF16ToUTF8(contents->GetTitle()));
      tab.Set("loading", contents->IsLoading());
    }
    tab_values.Append(std::move(tab));
  }
  state.Set("tabs", std::move(tab_values));

  content::WebContents* active = tabs->GetActiveWebContents();
  if (active) {
    const GURL url = active->GetVisibleURL();
    state.Set("url", url.spec());
    state.Set("domain", url.host().empty() ? url.spec() : url.host());
    state.Set("title", base::UTF16ToUTF8(active->GetTitle()));
    state.Set("loading", active->IsLoading());
    state.Set("canGoBack", active->GetController().CanGoBack());
    state.Set("canGoForward", active->GetController().CanGoForward());
    if (is_pwa_window) {
      state.Set("pwaStartUrl", url.spec());
      if (const webapps::AppId* app_id =
              web_app::WebAppTabHelper::GetAppId(active)) {
        state.Set("pwaAppId", *app_id);
        if (web_app::WebAppProvider* provider =
                web_app::WebAppProvider::GetForWebApps(browser->GetProfile())) {
          state.Set(
              "pwaStartUrl",
              provider->registrar_unsafe().GetAppStartUrl(*app_id).spec());
        }
      }
    }
  }

  std::string json;
  base::JSONWriter::Write(state, &json);
  return json;
}

void PollBrowserStateOnUiThread(uint64_t generation) {
  std::string ui_family;
  {
    RuntimeBridgeState& state = GetState();
    base::AutoLock lock(state.lock);
    if (!state.ui_task_runner || state.browser_generation != generation) {
      return;
    }
    ui_family = state.ui_family;
  }

  const bool mobile = IsMobileUiFamily(ui_family);
  ApplyUserAgentToAllTabs(mobile, /*reload=*/false);
  const std::string state_json = BuildBrowserStateJson(ui_family);

  AuraShellBrowserStateCallback callback;
  scoped_refptr<base::SingleThreadTaskRunner> task_runner;
  {
    RuntimeBridgeState& state = GetState();
    base::AutoLock lock(state.lock);
    if (!state.ui_task_runner || state.browser_generation != generation) {
      return;
    }
    if (state_json != state.last_browser_state_json) {
      state.last_browser_state_json = state_json;
      callback = state.browser_state_callback;
    }
    task_runner = state.ui_task_runner;
  }
  if (callback) {
    callback.Run(state_json);
  }
  task_runner->PostDelayedTask(
      FROM_HERE, base::BindOnce(&PollBrowserStateOnUiThread, generation),
      kBrowserStatePollInterval);
}

void NavigateOnUiThread(GURL url, int attempt) {
  GlobalBrowserCollection* browsers = GlobalBrowserCollection::GetInstance();
  BrowserWindowInterface* browser =
      browsers ? browsers->GetLastActiveBrowser() : nullptr;
  if (!browser) {
    if (attempt >= kMaxBrowserLookupAttempts) {
      LOG(ERROR) << "OHOS Aura shell could not find a Chromium browser window";
      return;
    }
    base::SingleThreadTaskRunner::GetCurrentDefault()->PostDelayedTask(
        FROM_HERE,
        base::BindOnce(&NavigateOnUiThread, std::move(url), attempt + 1),
        kBrowserLookupDelay);
    return;
  }

  content::OpenURLParams params(
      url, content::Referrer(), WindowOpenDisposition::CURRENT_TAB,
      ui::PAGE_TRANSITION_TYPED, /*is_renderer_initiated=*/false);
  browser->OpenURL(params, {});
}

void ShutdownOnUiThread() {
  chrome::ExitIgnoreUnloadHandlers();
}

void ApplyWindowStateOnUiThread(int attempt) {
  GlobalBrowserCollection* browsers = GlobalBrowserCollection::GetInstance();
  BrowserWindowInterface* browser =
      browsers ? browsers->GetLastActiveBrowser() : nullptr;
  if (!browser || !browser->GetWindow()) {
    if (attempt >= kMaxBrowserLookupAttempts) {
      LOG(ERROR) << "OHOS Aura shell could not apply browser window state";
      return;
    }
    base::SingleThreadTaskRunner::GetCurrentDefault()->PostDelayedTask(
        FROM_HERE, base::BindOnce(&ApplyWindowStateOnUiThread, attempt + 1),
        kBrowserLookupDelay);
    return;
  }

  bool visible = true;
  bool focused = true;
  {
    RuntimeBridgeState& state = GetState();
    base::AutoLock lock(state.lock);
    visible = state.app_visible;
    focused = state.app_focused;
  }

  ui::BaseWindow* window = browser->GetWindow();
  if (!visible) {
    window->Deactivate();
    window->Hide();
    return;
  }

  window->ShowInactive();
  if (focused) {
    window->Activate();
  } else {
    window->Deactivate();
  }

  if (BrowserView* browser_view = BrowserView::GetBrowserViewForBrowser(
          browser->GetBrowserForMigrationOnly())) {
    browser_view->InvalidateLayout();
    browser_view->SchedulePaint();
  }
}

void ApplyUiFamilyOnUiThread(std::string ui_family) {
  const bool mobile = IsMobileUiFamily(ui_family);
  const bool use_touch_ui = ui_family != "aura_pc";
  ui::TouchUiController* controller = ui::TouchUiController::Get();
  if (controller->touch_ui() == use_touch_ui) {
    controller->OnTabletModeToggled(!use_touch_ui);
  }
  controller->OnTabletModeToggled(use_touch_ui);

  ApplyUserAgentToAllTabs(mobile, /*reload=*/true);

  if (GlobalBrowserCollection* browsers =
          GlobalBrowserCollection::GetInstance()) {
    browsers->ForEach([](BrowserWindowInterface* browser) {
      if (BrowserView* browser_view = BrowserView::GetBrowserViewForBrowser(
              browser->GetBrowserForMigrationOnly())) {
        browser_view->OnOhosUiFamilyChanged();
      }
      return true;
    });
  }

  LOG(INFO) << "OHOS Aura shell applied UI family " << ui_family
            << " touch_ui=" << use_touch_ui;
}

void ApplyColorSchemeOnUiThread(std::string color_scheme) {
  const ui::NativeTheme::PreferredColorScheme preferred_scheme =
      color_scheme == "dark" ? ui::NativeTheme::PreferredColorScheme::kDark
                             : ui::NativeTheme::PreferredColorScheme::kLight;

  ui::NativeTheme* native_theme = ui::NativeTheme::GetInstanceForNativeUi();
  if (native_theme &&
      native_theme->preferred_color_scheme() != preferred_scheme) {
    native_theme->set_preferred_color_scheme(preferred_scheme);
    native_theme->NotifyOnNativeThemeUpdated();
  }

  ui::NativeTheme* web_theme = ui::NativeTheme::GetInstanceForWeb();
  if (web_theme && web_theme != native_theme &&
      web_theme->preferred_color_scheme() != preferred_scheme) {
    web_theme->set_preferred_color_scheme(preferred_scheme);
    web_theme->NotifyOnNativeThemeUpdated();
  }

  if (GlobalBrowserCollection* browsers =
          GlobalBrowserCollection::GetInstance()) {
    browsers->ForEach([](BrowserWindowInterface* browser) {
      TabStripModel* tabs = browser->GetTabStripModel();
      if (tabs) {
        for (int index = 0; index < tabs->count(); ++index) {
          if (content::WebContents* contents = tabs->GetWebContentsAt(index)) {
            contents->NotifyPreferencesChanged();
          }
        }
      }
      if (BrowserView* browser_view = BrowserView::GetBrowserViewForBrowser(
              browser->GetBrowserForMigrationOnly())) {
        browser_view->InvalidateLayout();
        browser_view->SchedulePaint();
      }
      return true;
    });
  }

  LOG(INFO) << "OHOS Aura shell applied color scheme " << color_scheme;
}

void ExecuteBrowserCommandOnUiThread(base::DictValue command) {
  const std::string* name = command.FindString("command");
  if (!name || *name == "requestState") {
    return;
  }

  if (*name == "filePickerResult") {
    const std::optional<int> request_id = command.FindInt("requestId");
    const base::ListValue* path_values = command.FindList("paths");
    std::vector<std::string> paths;
    if (path_values) {
      for (const base::Value& path : *path_values) {
        if (path.is_string()) {
          paths.push_back(path.GetString());
        }
      }
    }
    if (request_id) {
      ui::CompleteOhosSelectFileDialog(
          *request_id, paths, command.FindInt("fileTypeIndex").value_or(0),
          command.FindBool("canceled").value_or(paths.empty()));
    }
    return;
  }

  BrowserWindowInterface* browser = GetActiveBrowser();
  TabStripModel* tabs = browser ? browser->GetTabStripModel() : nullptr;
  if (!browser || !tabs) {
    LOG(ERROR) << "OHOS Aura shell command has no active browser: " << *name;
    return;
  }

  content::WebContents* active = tabs->GetActiveWebContents();
  if (*name == "back" && active && active->GetController().CanGoBack()) {
    active->GetController().GoBack();
  } else if (*name == "forward" && active &&
             active->GetController().CanGoForward()) {
    active->GetController().GoForward();
  } else if (*name == "reload" && active) {
    active->GetController().Reload(content::ReloadType::NORMAL,
                                   /*check_for_repost=*/false);
  } else if (*name == "stop" && active) {
    active->Stop();
  } else if (*name == "home") {
    NavigateOnUiThread(GURL("chrome://newtab/"), 0);
  } else if (*name == "pwaHome") {
    const std::string* url = command.FindString("url");
    if (url && GURL(*url).is_valid()) {
      NavigateOnUiThread(GURL(*url), 0);
    }
  } else if (*name == "navigate") {
    const std::string* url = command.FindString("url");
    if (url && GURL(*url).is_valid()) {
      NavigateOnUiThread(GURL(*url), 0);
    }
  } else if (*name == "newTab") {
    content::OpenURLParams params(GURL("chrome://newtab/"), content::Referrer(),
                                  WindowOpenDisposition::NEW_FOREGROUND_TAB,
                                  ui::PAGE_TRANSITION_TYPED,
                                  /*is_renderer_initiated=*/false);
    browser->OpenURL(params, {});
  } else if (*name == "activateTab") {
    const std::optional<int> index = command.FindInt("index");
    if (index && tabs->ContainsIndex(*index)) {
      tabs->ActivateTabAt(*index);
    }
  } else if (*name == "closeTab") {
    const int index = command.FindInt("index").value_or(tabs->active_index());
    if (tabs->ContainsIndex(index) && tabs->count() > 1) {
      tabs->CloseWebContentsAt(index, TabCloseTypes::CLOSE_USER_GESTURE);
    } else if (active) {
      NavigateOnUiThread(GURL("chrome://newtab/"), 0);
    }
  } else if (*name == "print" && active) {
    RequestAuraShellSystemPrint(active);
  } else if (*name == "share" && active) {
    RequestAuraShellSystemShare(active);
  } else if (*name == "pwaMenu") {
    BrowserView* browser_view = BrowserView::GetBrowserViewForBrowser(
        browser->GetBrowserForMigrationOnly());
    AppMenuControl* menu =
        browser_view && browser_view->toolbar_button_provider()
            ? browser_view->toolbar_button_provider()->GetAppMenuControl()
            : nullptr;
    if (menu && menu->IsDrawn()) {
      menu->ShowMenu();
    } else {
      base::DictValue event;
      event.Set("event", "pwaMenuFallback");
      DispatchRuntimeEvent(std::move(event));
    }
  } else if (*name == "pwaClose" &&
             (browser->GetType() == BrowserWindowInterface::Type::TYPE_APP ||
              browser->GetType() ==
                  BrowserWindowInterface::Type::TYPE_APP_POPUP)) {
    browser->GetWindow()->Close();
  }
}

void ReloadAllTabsAfterThemeFontChange() {
  GlobalBrowserCollection* browsers = GlobalBrowserCollection::GetInstance();
  if (!browsers) {
    return;
  }
  browsers->ForEach([](BrowserWindowInterface* browser) {
    TabStripModel* tabs = browser->GetTabStripModel();
    if (tabs) {
      for (int index = 0; index < tabs->count(); ++index) {
        if (content::WebContents* contents = tabs->GetWebContentsAt(index)) {
          contents->GetController().Reload(content::ReloadType::NORMAL,
                                           /*check_for_repost=*/false);
        }
      }
    }
    if (BrowserView* browser_view = BrowserView::GetBrowserViewForBrowser(
            browser->GetBrowserForMigrationOnly())) {
      browser_view->InvalidateLayout();
      browser_view->SchedulePaint();
    }
    return true;
  });
}

void ReloadThemeFontsOnUiThread(std::string font_id) {
  const bool font_manager_reloaded = skia::ReloadOhosFontManager(font_id);
  ui::ResourceBundle::GetSharedInstance().ReloadFonts();

  const bool single_process = base::CommandLine::ForCurrentProcess()->HasSwitch(
      switches::kSingleProcess);
  bool renderer_cache_refresh_posted = false;
  if (single_process) {
    renderer_cache_refresh_posted =
        content::ReloadOhosThemeFontsForInProcessRenderer();
  } else {
    std::set<content::RenderProcessHost*> renderer_processes;
    if (GlobalBrowserCollection* browsers =
            GlobalBrowserCollection::GetInstance()) {
      browsers->ForEach([&renderer_processes](BrowserWindowInterface* browser) {
        TabStripModel* tabs = browser->GetTabStripModel();
        if (!tabs) {
          return true;
        }
        for (int index = 0; index < tabs->count(); ++index) {
          content::WebContents* contents = tabs->GetWebContentsAt(index);
          if (contents && contents->GetPrimaryMainFrame()) {
            renderer_processes.insert(
                contents->GetPrimaryMainFrame()->GetProcess());
          }
        }
        return true;
      });
    }
    for (content::RenderProcessHost* process : renderer_processes) {
      if (process && !process->ShutdownRequested()) {
        process->Shutdown(/*exit_code=*/0);
      }
    }
  }

  base::SingleThreadTaskRunner::GetCurrentDefault()->PostDelayedTask(
      FROM_HERE, base::BindOnce(&ReloadAllTabsAfterThemeFontChange),
      kThemeFontRendererRestartDelay);
  LOG(INFO) << "OHOS theme font refreshed fontId=" << font_id
            << " managerReloaded=" << font_manager_reloaded
            << " singleProcess=" << single_process
            << " rendererRefreshPosted=" << renderer_cache_refresh_posted;
}

}  // namespace

void NotifyAuraShellBrowserStarted() {
  ui::SetOhosSelectFileDialogRequestCallback(
      base::BindRepeating(&DispatchFilePickerRequest));
  RuntimeBridgeState& state = GetState();
  std::optional<GURL> pending_url;
  std::optional<std::string> pending_theme_font_id;
  bool pending_shutdown = false;
  std::string ui_family;
  std::string color_scheme;
  scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner;
  uint64_t browser_generation = 0;
  {
    base::AutoLock lock(state.lock);
    state.ui_task_runner = base::SingleThreadTaskRunner::GetCurrentDefault();
    browser_generation = ++state.browser_generation;
    state.last_browser_state_json.clear();
    ui_task_runner = state.ui_task_runner;
    pending_url = std::move(state.pending_url);
    pending_theme_font_id = std::move(state.pending_theme_font_id);
    ui_family = state.ui_family;
    color_scheme = state.color_scheme;
    pending_shutdown = state.pending_shutdown;
    state.pending_shutdown = false;
  }

  ApplyUiFamilyOnUiThread(std::move(ui_family));
  ApplyColorSchemeOnUiThread(std::move(color_scheme));
  ui_task_runner->PostTask(
      FROM_HERE,
      base::BindOnce(&PollBrowserStateOnUiThread, browser_generation));
  ui_task_runner->PostTask(FROM_HERE,
                           base::BindOnce(&ApplyWindowStateOnUiThread, 0));
  if (pending_url) {
    ui_task_runner->PostTask(
        FROM_HERE,
        base::BindOnce(&NavigateOnUiThread, std::move(*pending_url), 0));
  }
  if (pending_theme_font_id) {
    ui_task_runner->PostTask(FROM_HERE,
                             base::BindOnce(&ReloadThemeFontsOnUiThread,
                                            std::move(*pending_theme_font_id)));
  }
  if (pending_shutdown) {
    ui_task_runner->PostTask(FROM_HERE, base::BindOnce(&ShutdownOnUiThread));
  }
}

void NotifyAuraShellBrowserStopped() {
  ui::SetOhosSelectFileDialogRequestCallback({});
  ui::CancelAllOhosSelectFileDialogs();
  RuntimeBridgeState& state = GetState();
  base::AutoLock lock(state.lock);
  state.ui_task_runner.reset();
  ++state.browser_generation;
  state.last_browser_state_json.clear();
}

bool NavigateAuraShellBrowser(const std::string& url) {
  GURL target(url);
  if (!target.is_valid()) {
    LOG(ERROR) << "OHOS Aura shell rejected invalid URL: " << url;
    return false;
  }

  scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner;
  {
    RuntimeBridgeState& state = GetState();
    base::AutoLock lock(state.lock);
    ui_task_runner = state.ui_task_runner;
    if (!ui_task_runner) {
      state.pending_url = std::move(target);
      return true;
    }
  }

  ui_task_runner->PostTask(
      FROM_HERE, base::BindOnce(&NavigateOnUiThread, std::move(target), 0));
  return true;
}

bool ExecuteAuraShellBrowserCommand(const std::string& command_json) {
  std::optional<base::DictValue> command =
      base::JSONReader::ReadDict(command_json, base::JSON_PARSE_RFC);
  const std::string* name = command ? command->FindString("command") : nullptr;
  static constexpr std::string_view kSupportedCommands[] = {
      "back",        "forward",  "reload",       "stop",
      "home",        "pwaHome",  "navigate",     "newTab",
      "activateTab", "closeTab", "print",        "share",
      "pwaMenu",     "pwaClose", "requestState", "filePickerResult",
  };
  if (!name || std::ranges::find(kSupportedCommands, *name) ==
                   std::ranges::end(kSupportedCommands)) {
    LOG(ERROR) << "OHOS Aura shell rejected browser command JSON";
    return false;
  }

  scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner;
  {
    RuntimeBridgeState& state = GetState();
    base::AutoLock lock(state.lock);
    ui_task_runner = state.ui_task_runner;
  }
  if (!ui_task_runner) {
    return false;
  }
  ui_task_runner->PostTask(
      FROM_HERE,
      base::BindOnce(&ExecuteBrowserCommandOnUiThread, std::move(*command)));
  return true;
}

void SetAuraShellBrowserStateCallback(AuraShellBrowserStateCallback callback) {
  RuntimeBridgeState& state = GetState();
  base::AutoLock lock(state.lock);
  state.browser_state_callback = std::move(callback);
  state.last_browser_state_json.clear();
}

void UpdateAuraShellUiFamily(const std::string& ui_family) {
  const std::string resolved_family =
      ui_family.empty() ? "mobile_phone" : ui_family;
  scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner;
  {
    RuntimeBridgeState& state = GetState();
    base::AutoLock lock(state.lock);
    if (state.ui_family == resolved_family) {
      return;
    }
    state.ui_family = resolved_family;
    ui_task_runner = state.ui_task_runner;
  }

  if (ui_task_runner) {
    ui_task_runner->PostTask(
        FROM_HERE, base::BindOnce(&ApplyUiFamilyOnUiThread, resolved_family));
  }
}

void UpdateAuraShellColorScheme(const std::string& color_scheme) {
  const std::string resolved_scheme = color_scheme == "dark" ? "dark" : "light";
  scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner;
  {
    RuntimeBridgeState& state = GetState();
    base::AutoLock lock(state.lock);
    if (state.color_scheme == resolved_scheme) {
      return;
    }
    state.color_scheme = resolved_scheme;
    ui_task_runner = state.ui_task_runner;
  }

  if (ui_task_runner) {
    ui_task_runner->PostTask(
        FROM_HERE,
        base::BindOnce(&ApplyColorSchemeOnUiThread, resolved_scheme));
  }
}

void UpdateAuraShellPrintOutputDirectory(const std::string& output_directory) {
  RuntimeBridgeState& state = GetState();
  base::AutoLock lock(state.lock);
  state.print_output_directory = output_directory;
}

bool RequestAuraShellSystemPrint(content::WebContents* contents) {
  if (!contents) {
    BrowserWindowInterface* browser = GetActiveBrowser();
    TabStripModel* tabs = browser ? browser->GetTabStripModel() : nullptr;
    contents = tabs ? tabs->GetActiveWebContents() : nullptr;
  }
  if (!contents || !contents->GetPrimaryMainFrame()) {
    DispatchPrintFailure("noActiveDocument");
    return true;
  }

  std::string output_directory;
  {
    RuntimeBridgeState& state = GetState();
    base::AutoLock lock(state.lock);
    output_directory = state.print_output_directory;
  }
  if (output_directory.empty()) {
    DispatchPrintFailure("printOutputDirectoryUnavailable");
    return true;
  }

  auto params_or_error = print_to_pdf::GetPrintPagesParams(
      contents->GetLastCommittedURL(), std::nullopt, std::nullopt, std::nullopt,
      std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt,
      std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt,
      std::nullopt, std::nullopt);
  if (std::holds_alternative<std::string>(params_or_error)) {
    DispatchPrintFailure(std::get<std::string>(std::move(params_or_error)));
    return true;
  }

  printing::PrintViewManager* manager =
      printing::PrintViewManager::FromWebContents(contents);
  if (!manager) {
    printing::PrintViewManager::CreateForWebContents(contents);
    manager = printing::PrintViewManager::FromWebContents(contents);
  }
  if (!manager) {
    DispatchPrintFailure("printManagerUnavailable");
    return true;
  }

  const base::FilePath path =
      base::FilePath(output_directory)
          .AppendASCII("chromium-print-" +
                       base::NumberToString(
                           base::Time::Now().InMillisecondsSinceUnixEpoch()) +
                       ".pdf");
  manager->PrintToPdf(contents->GetPrimaryMainFrame(), "",
                      std::get<printing::mojom::PrintPagesParamsPtr>(
                          std::move(params_or_error)),
                      base::BindOnce(&OnPdfGenerated, path,
                                     base::UTF16ToUTF8(contents->GetTitle()),
                                     contents->GetLastCommittedURL().spec()));
  return true;
}

bool RequestAuraShellSystemShare(content::WebContents* contents) {
  if (!contents) {
    BrowserWindowInterface* browser = GetActiveBrowser();
    TabStripModel* tabs = browser ? browser->GetTabStripModel() : nullptr;
    contents = tabs ? tabs->GetActiveWebContents() : nullptr;
  }
  if (!contents || !contents->GetLastCommittedURL().is_valid()) {
    return false;
  }
  base::DictValue event;
  event.Set("event", "shareRequested");
  event.Set("url", contents->GetLastCommittedURL().spec());
  event.Set("title", base::UTF16ToUTF8(contents->GetTitle()));
  DispatchRuntimeEvent(std::move(event));
  return true;
}

bool RequestAuraShellSystemCast(content::WebContents* contents) {
  if (!contents) {
    BrowserWindowInterface* browser = GetActiveBrowser();
    TabStripModel* tabs = browser ? browser->GetTabStripModel() : nullptr;
    contents = tabs ? tabs->GetActiveWebContents() : nullptr;
  }
  if (!contents) {
    return false;
  }
  base::DictValue event;
  event.Set("event", "castRequested");
  event.Set("url", contents->GetLastCommittedURL().spec());
  event.Set("title", base::UTF16ToUTF8(contents->GetTitle()));
  DispatchRuntimeEvent(std::move(event));
  return true;
}

void NotifyAuraShellWebAppInstalled(const std::string& app_id,
                                    const std::string& title,
                                    const std::string& start_url) {
  base::DictValue event;
  event.Set("event", "pwaInstalled");
  event.Set("appId", app_id);
  event.Set("title", title);
  event.Set("url", start_url);
  event.Set("pwaStartUrl", start_url);
  DispatchRuntimeEvent(std::move(event));
}

bool IsAuraShellMobilePhoneUi() {
  RuntimeBridgeState& state = GetState();
  base::AutoLock lock(state.lock);
  return state.ui_family == "mobile_phone";
}

bool IsAuraShellDesktopUi() {
  RuntimeBridgeState& state = GetState();
  base::AutoLock lock(state.lock);
  return state.ui_family == "aura_pc";
}

void SetAuraShellBrowserVisible(bool visible) {
  scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner;
  {
    RuntimeBridgeState& state = GetState();
    base::AutoLock lock(state.lock);
    if (state.app_visible == visible && (visible || !state.app_focused)) {
      return;
    }
    state.app_visible = visible;
    if (!visible) {
      state.app_focused = false;
    }
    ui_task_runner = state.ui_task_runner;
  }
  if (ui_task_runner) {
    ui_task_runner->PostTask(FROM_HERE,
                             base::BindOnce(&ApplyWindowStateOnUiThread, 0));
  }
}

void SetAuraShellBrowserFocused(bool focused) {
  scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner;
  {
    RuntimeBridgeState& state = GetState();
    base::AutoLock lock(state.lock);
    if (state.app_focused == focused && !focused) {
      return;
    }
    state.app_focused = focused;
    ui_task_runner = state.ui_task_runner;
  }
  if (ui_task_runner) {
    ui_task_runner->PostTask(FROM_HERE,
                             base::BindOnce(&ApplyWindowStateOnUiThread, 0));
  }
}

void NotifyAuraShellThemeFontChanged(const std::string& font_id) {
  scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner;
  {
    RuntimeBridgeState& state = GetState();
    base::AutoLock lock(state.lock);
    ui_task_runner = state.ui_task_runner;
    if (!ui_task_runner) {
      state.pending_theme_font_id = font_id;
      return;
    }
  }
  ui_task_runner->PostTask(
      FROM_HERE, base::BindOnce(&ReloadThemeFontsOnUiThread, font_id));
}

void ShutdownAuraShellBrowser() {
  scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner;
  {
    RuntimeBridgeState& state = GetState();
    base::AutoLock lock(state.lock);
    ui_task_runner = state.ui_task_runner;
    if (!ui_task_runner) {
      state.pending_shutdown = true;
      return;
    }
  }

  ui_task_runner->PostTask(FROM_HERE, base::BindOnce(&ShutdownOnUiThread));
}

}  // namespace chrome::ohos
