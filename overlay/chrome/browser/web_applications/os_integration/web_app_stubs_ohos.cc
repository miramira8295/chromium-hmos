// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <utility>

#include "base/functional/bind.h"
#include "base/task/task_runner.h"
#include "chrome/browser/web_applications/os_integration/web_app_file_handler_registration.h"
#include "chrome/browser/web_applications/os_integration/web_app_run_on_os_login.h"
#include "chrome/browser/web_applications/os_integration/web_app_shortcut.h"

namespace web_app {

bool ShouldRegisterFileHandlersWithOs() {
  return false;
}

bool FileHandlingIconsSupportedByOs() {
  return false;
}

void RegisterFileHandlersWithOs(const webapps::AppId& app_id,
                                const std::string& app_name,
                                const base::FilePath& profile_path,
                                const apps::FileHandlers& file_handlers,
                                ResultCallback callback) {
  std::move(callback).Run(Result::kError);
}

void UnregisterFileHandlersWithOs(const webapps::AppId& app_id,
                                  const base::FilePath& profile_path,
                                  ResultCallback callback) {
  std::move(callback).Run(Result::kError);
}

namespace internals {

void RegisterRunOnOsLogin(const ShortcutInfo& shortcut_info,
                          ResultCallback callback) {
  std::move(callback).Run(Result::kError);
}

Result UnregisterRunOnOsLogin(const std::string& app_id,
                              const base::FilePath& profile_path,
                              const std::u16string& shortcut_title) {
  return Result::kError;
}

void CreatePlatformShortcuts(const base::FilePath& shortcut_data_path,
                             const ShortcutLocations& creation_locations,
                             ShortcutCreationReason creation_reason,
                             const ShortcutInfo& shortcut_info,
                             CreateShortcutsCallback callback) {
  std::move(callback).Run(false);
}

ShortcutLocations GetAppExistingShortCutLocationImpl(
    const ShortcutInfo& shortcut_info) {
  return {};
}

void DeletePlatformShortcuts(const base::FilePath& shortcut_data_path,
                             const ShortcutInfo& shortcut_info,
                             scoped_refptr<base::TaskRunner> result_runner,
                             DeleteShortcutsCallback callback) {
  result_runner->PostTask(FROM_HERE,
                          base::BindOnce(std::move(callback), false));
}

void UpdatePlatformShortcuts(
    const base::FilePath& shortcut_data_path,
    const std::u16string& old_app_title,
    std::optional<ShortcutLocations> user_specified_locations,
    ResultCallback callback,
    const ShortcutInfo& shortcut_info) {
  std::move(callback).Run(Result::kError);
}

void DeleteAllShortcutsForProfile(const base::FilePath& profile_path) {}

}  // namespace internals
}  // namespace web_app
