// Copyright (c) 2026
// Licensed under the Apache License, Version 2.0.

#include "ohos_nweb/src/aura_shell/ohos_aura_xcomponent_bridge.h"

#include "ohos_nweb/src/nweb_hilog.h"

namespace ohos_nweb {

OhosAuraXComponentBridge::OhosAuraXComponentBridge() = default;

OhosAuraXComponentBridge::~OhosAuraXComponentBridge() = default;

void OhosAuraXComponentBridge::OnSurfaceCreated() {
  state_.created = true;
  WVLOG_I("AuraShell XComponent surface created");
}

void OhosAuraXComponentBridge::OnSurfaceChanged(double x,
                                                double y,
                                                double width,
                                                double height,
                                                double density) {
  state_.x = x;
  state_.y = y;
  state_.width = width;
  state_.height = height;
  state_.density = density;
  WVLOG_I(
      "AuraShell XComponent resize x=%{public}f y=%{public}f "
      "width=%{public}f height=%{public}f density=%{public}f",
      x, y, width, height, density);
}

void OhosAuraXComponentBridge::OnSurfaceDestroyed() {
  state_.created = false;
  WVLOG_I("AuraShell XComponent surface destroyed");
}

void OhosAuraXComponentBridge::OnVisibilityChanged(bool visible) {
  state_.visible = visible;
  WVLOG_I("AuraShell visibility changed visible=%{public}d", visible);
}

void OhosAuraXComponentBridge::OnFocusChanged(bool focused) {
  state_.focused = focused;
  WVLOG_I("AuraShell focus changed focused=%{public}d", focused);
}

}  // namespace ohos_nweb
