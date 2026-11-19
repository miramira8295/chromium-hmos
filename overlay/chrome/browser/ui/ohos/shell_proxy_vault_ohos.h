// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license.
#ifndef CHROME_BROWSER_UI_OHOS_SHELL_PROXY_VAULT_OHOS_H_
#define CHROME_BROWSER_UI_OHOS_SHELL_PROXY_VAULT_OHOS_H_
#include <optional>
#include <string>
namespace chrome::ohos {
struct ShellProxySecret {
  std::string username;
  std::string password;
};
// Immutable, device-only AssetStoreKit records. No password enters Preferences.
std::optional<std::string> StoreShellProxySecret(const ShellProxySecret& secret);
std::optional<ShellProxySecret> LoadShellProxySecret(const std::string& reference);
void RemoveShellProxySecret(const std::string& reference);
}
#endif
