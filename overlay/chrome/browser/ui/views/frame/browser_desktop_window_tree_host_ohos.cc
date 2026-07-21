// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/views/frame/browser_desktop_window_tree_host.h"
#include "ui/views/widget/desktop_aura/desktop_native_widget_aura.h"
#include "ui/views/widget/desktop_aura/desktop_window_tree_host_platform.h"

namespace {

class BrowserDesktopWindowTreeHostOhos
    : public views::DesktopWindowTreeHostPlatform,
      public BrowserDesktopWindowTreeHost {
 public:
  BrowserDesktopWindowTreeHostOhos(
      views::internal::NativeWidgetDelegate* native_widget_delegate,
      views::DesktopNativeWidgetAura* desktop_native_widget_aura)
      : DesktopWindowTreeHostPlatform(native_widget_delegate,
                                      desktop_native_widget_aura) {}

  BrowserDesktopWindowTreeHostOhos(const BrowserDesktopWindowTreeHostOhos&) =
      delete;
  BrowserDesktopWindowTreeHostOhos& operator=(
      const BrowserDesktopWindowTreeHostOhos&) = delete;

  views::DesktopWindowTreeHost* AsDesktopWindowTreeHost() override {
    return this;
  }

  bool UsesNativeSystemMenu() const override { return false; }
};

}  // namespace

BrowserDesktopWindowTreeHost*
BrowserDesktopWindowTreeHost::CreateBrowserDesktopWindowTreeHost(
    views::internal::NativeWidgetDelegate* native_widget_delegate,
    views::DesktopNativeWidgetAura* desktop_native_widget_aura,
    BrowserView* browser_view,
    BrowserWidget* browser_widget) {
  return new BrowserDesktopWindowTreeHostOhos(native_widget_delegate,
                                              desktop_native_widget_aura);
}
