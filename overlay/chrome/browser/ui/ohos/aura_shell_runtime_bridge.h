// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_OHOS_AURA_SHELL_RUNTIME_BRIDGE_H_
#define CHROME_BROWSER_UI_OHOS_AURA_SHELL_RUNTIME_BRIDGE_H_

#include <string>

#include "base/functional/callback_forward.h"

namespace content {
class WebContents;
}

namespace chrome::ohos {

using AuraShellBrowserStateCallback =
    base::RepeatingCallback<void(const std::string& state_json)>;

// Called on the Chromium UI thread as the browser main loop starts and stops.
void NotifyAuraShellBrowserStarted();
void NotifyAuraShellBrowserStopped();

// These entry points are safe to call from the ArkUI/N-API thread. Requests
// made during startup are held until Chromium's UI thread is ready.
bool NavigateAuraShellBrowser(const std::string& url);
bool ExecuteAuraShellBrowserCommand(const std::string& command_json);
void SetAuraShellBrowserStateCallback(AuraShellBrowserStateCallback callback);
void UpdateAuraShellUiFamily(const std::string& ui_family);
void UpdateAuraShellColorScheme(const std::string& color_scheme);
void UpdateAuraShellPrintOutputDirectory(const std::string& output_directory);
bool IsAuraShellMobilePhoneUi();
bool IsAuraShellDesktopUi();
bool RequestAuraShellSystemPrint(content::WebContents* contents);
bool RequestAuraShellSystemShare(content::WebContents* contents);
bool RequestAuraShellSystemCast(content::WebContents* contents);
void NotifyAuraShellWebAppInstalled(const std::string& app_id,
                                    const std::string& title,
                                    const std::string& start_url);
void SetAuraShellBrowserVisible(bool visible);
void SetAuraShellBrowserFocused(bool focused);
void NotifyAuraShellThemeFontChanged(const std::string& font_id);
void ShutdownAuraShellBrowser();

}  // namespace chrome::ohos

#endif  // CHROME_BROWSER_UI_OHOS_AURA_SHELL_RUNTIME_BRIDGE_H_
