// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/feature_list.h"
#include "chrome/browser/ui/views/chrome_views_delegate.h"
#include "chrome/browser/ui/views/chrome_views_delegate_ohos_utils.h"
#include "chrome/browser/ui/views/native_widget_factory.h"
#include "ui/base/ui_base_features.h"
#include "ui/ozone/public/ozone_platform.h"
#include "ui/views/widget/widget_delegate.h"

namespace {

NativeWidgetType GetNativeWidgetTypeForInitParams(
    const views::Widget::InitParams& params) {
  if (params.z_order &&
      params.z_order.value() == ui::ZOrderLevel::kSecuritySurface) {
    return NativeWidgetType::kDesktopNativeWidgetAura;
  }

  const bool default_desktop_bubble =
      (params.type == views::Widget::InitParams::TYPE_BUBBLE ||
       params.type == views::Widget::InitParams::TYPE_POPUP) &&
      base::FeatureList::IsEnabled(features::kOzoneBubblesUsePlatformWidgets) &&
      ui::OzonePlatform::GetInstance()
          ->GetPlatformRuntimeProperties()
          .supports_subwindows_as_accelerated_widgets;

  if (!params.child &&
      params.use_accelerated_widget_override.value_or(default_desktop_bubble)) {
    return NativeWidgetType::kDesktopNativeWidgetAura;
  }

  if (params.delegate && params.delegate->use_desktop_widget_override()) {
    return NativeWidgetType::kDesktopNativeWidgetAura;
  }

  // HarmonyOS embeds Chromium in one XComponent surface. Secondary widgets
  // such as menus, tooltips, and bubbles must therefore stay in the owner's
  // Aura compositor instead of creating another platform window with no
  // native surface to bind to.
  return chrome::ohos::ShouldEmbedSecondaryWidget(params)
             ? NativeWidgetType::kNativeWidgetAura
             : NativeWidgetType::kDesktopNativeWidgetAura;
}

}  // namespace

views::NativeWidget* ChromeViewsDelegate::CreateNativeWidget(
    views::Widget::InitParams* params,
    views::internal::NativeWidgetDelegate* delegate) {
  return ::CreateNativeWidget(GetNativeWidgetTypeForInitParams(*params), params,
                              delegate);
}
