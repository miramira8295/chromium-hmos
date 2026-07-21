// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/base_paths.h"
#include "base/files/file_path.h"
#include "base/path_service.h"
#include "chrome/browser/first_run/first_run_internal.h"
#include "chrome/installer/util/initial_preferences.h"

namespace first_run::internal {

base::FilePath InitialPrefsPath() {
  base::FilePath executable_dir;
  if (!base::PathService::Get(base::DIR_EXE, &executable_dir)) {
    return base::FilePath();
  }
  return installer::InitialPreferences::Path(executable_dir);
}

void DoPostImportPlatformSpecificTasks() {}

bool ShowPostInstallEULAIfNeeded(installer::InitialPreferences* install_prefs) {
  return true;
}

}  // namespace first_run::internal
