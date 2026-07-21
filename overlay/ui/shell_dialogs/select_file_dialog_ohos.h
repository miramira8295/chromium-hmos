// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_SHELL_DIALOGS_SELECT_FILE_DIALOG_OHOS_H_
#define UI_SHELL_DIALOGS_SELECT_FILE_DIALOG_OHOS_H_

#include <string>
#include <vector>

#include "base/functional/callback_forward.h"
#include "ui/shell_dialogs/select_file_dialog.h"
#include "ui/shell_dialogs/shell_dialogs_export.h"

namespace ui {

struct SHELL_DIALOGS_EXPORT OhosSelectFileDialogRequest {
  int request_id = 0;
  SelectFileDialog::Type type = SelectFileDialog::SELECT_NONE;
  std::string title;
  std::string default_name;
  std::vector<std::string> suffix_filters;
  int file_type_index = 0;
};

using OhosSelectFileDialogRequestCallback =
    base::RepeatingCallback<void(const OhosSelectFileDialogRequest& request)>;

// The Chromium embedder supplies the ArkUI request bridge while the browser
// process is running.
SHELL_DIALOGS_EXPORT void SetOhosSelectFileDialogRequestCallback(
    OhosSelectFileDialogRequestCallback callback);

// Completes a request with file:// URIs returned by HarmonyOS DocumentPicker.
SHELL_DIALOGS_EXPORT bool CompleteOhosSelectFileDialog(
    int request_id,
    const std::vector<std::string>& selected_uris,
    int file_type_index,
    bool canceled);

SHELL_DIALOGS_EXPORT void CancelAllOhosSelectFileDialogs();

}  // namespace ui

#endif  // UI_SHELL_DIALOGS_SELECT_FILE_DIALOG_OHOS_H_
