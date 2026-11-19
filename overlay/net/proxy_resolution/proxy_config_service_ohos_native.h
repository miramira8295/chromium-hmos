// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_PROXY_RESOLUTION_PROXY_CONFIG_SERVICE_OHOS_NATIVE_H_
#define NET_PROXY_RESOLUTION_PROXY_CONFIG_SERVICE_OHOS_NATIVE_H_

#include "base/observer_list.h"
#include "base/timer/timer.h"
#include "net/base/network_change_notifier.h"
#include "net/proxy_resolution/proxy_config_service.h"
#include "net/proxy_resolution/proxy_config_with_annotation.h"

namespace net {

// Chrome-shell system proxy source. It uses public NetManager APIs and does
// not depend on the NWeb embedder/adapter singleton being initialized.
class NET_EXPORT ProxyConfigServiceOHOSNative
    : public ProxyConfigService,
      public NetworkChangeNotifier::IPAddressObserver {
 public:
  ProxyConfigServiceOHOSNative();
  ~ProxyConfigServiceOHOSNative() override;
  void AddObserver(Observer* observer) override;
  void RemoveObserver(Observer* observer) override;
  ConfigAvailability GetLatestProxyConfig(
      ProxyConfigWithAnnotation* config) override;
  void OnIPAddressChanged(
      NetworkChangeNotifier::IPAddressChangeType change_type) override;

 private:
  void Refresh();
  ProxyConfigWithAnnotation config_;
  base::ObserverList<Observer>::Unchecked observers_;
  base::RepeatingTimer poll_timer_;
};

}  // namespace net
#endif
