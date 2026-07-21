// Copyright (c) 2026
// Licensed under the Apache License, Version 2.0.

#ifndef OHOS_NWEB_SRC_AURA_SHELL_OHOS_AURA_XCOMPONENT_BRIDGE_H_
#define OHOS_NWEB_SRC_AURA_SHELL_OHOS_AURA_XCOMPONENT_BRIDGE_H_

#include "ohos_nweb/src/aura_shell/ohos_aura_shell_types.h"

namespace ohos_nweb {

class OhosAuraXComponentBridge {
 public:
  OhosAuraXComponentBridge();
  OhosAuraXComponentBridge(const OhosAuraXComponentBridge&) = delete;
  OhosAuraXComponentBridge& operator=(const OhosAuraXComponentBridge&) = delete;
  ~OhosAuraXComponentBridge();

  void OnSurfaceCreated();
  void OnSurfaceChanged(double x,
                        double y,
                        double width,
                        double height,
                        double density);
  void OnSurfaceDestroyed();
  void OnVisibilityChanged(bool visible);
  void OnFocusChanged(bool focused);

  const AuraSurfaceState& state() const { return state_; }

 private:
  AuraSurfaceState state_;
};

}  // namespace ohos_nweb

#endif  // OHOS_NWEB_SRC_AURA_SHELL_OHOS_AURA_XCOMPONENT_BRIDGE_H_
