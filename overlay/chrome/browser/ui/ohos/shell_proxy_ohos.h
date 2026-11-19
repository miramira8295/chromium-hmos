// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license.
#ifndef CHROME_BROWSER_UI_OHOS_SHELL_PROXY_OHOS_H_
#define CHROME_BROWSER_UI_OHOS_SHELL_PROXY_OHOS_H_
#include "base/values.h"
#include "services/network/public/mojom/network_context.mojom-forward.h"
class Profile;
class PrefRegistrySimple;
namespace chrome::ohos {
struct ShellCommandContext;
void RegisterShellProxyPrefs(PrefRegistrySimple* registry);
// Called BEFORE ProxyConfigMonitor constructs its preference tracker.
void InitializeShellProxy(Profile* profile);
void ConfigureShellProxyNetworkContext(Profile* profile, network::mojom::NetworkContextParams* params);
bool ShellProxyProtectsTraffic(Profile* profile);
namespace settings_internal {
void GetProxySettings(const ShellCommandContext&, const base::DictValue&);
void GetProxyCredentials(const ShellCommandContext&, const base::DictValue&);
void ApplyProxySettings(const ShellCommandContext&, const base::DictValue&);
void TestProxySettings(const ShellCommandContext&, const base::DictValue&);
void CancelProxyTest(const ShellCommandContext&, const base::DictValue&);
}
}
#endif
