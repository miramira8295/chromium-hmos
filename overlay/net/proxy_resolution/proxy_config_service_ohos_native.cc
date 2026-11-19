// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/proxy_resolution/proxy_config_service_ohos_native.h"

#include <network/netmanager/net_connection.h>

#include <algorithm>
#include <iterator>
#include <string>
#include <utility>

#include "base/containers/span.h"
#include "base/functional/bind.h"
#include "base/location.h"
#include "base/time/time.h"
#include "net/base/proxy_server.h"
#include "net/proxy_resolution/proxy_config.h"
#include "net/traffic_annotation/network_traffic_annotation.h"

namespace net {
namespace {

template <size_t N>
std::string ReadNativeString(const char (&value)[N]) {
  return std::string(std::begin(value),
                     std::find(std::begin(value), std::end(value), '\0'));
}

ProxyConfigWithAnnotation ReadSystemProxy() {
  NetConn_HttpProxy native_proxy{};
  ProxyConfig result;
  result.set_from_system(true);
  // A failed system query must not silently bypass a configured proxy.
  // Retry on the next poll or network change.
  if (OH_NetConn_GetDefaultHttpProxy(&native_proxy) != 0) {
    result.proxy_rules().ParseFromString("http://127.0.0.1:9");
    result.proxy_rules().bypass_rules.AddRuleFromString("<-loopback>");
    return ProxyConfigWithAnnotation(result, MISSING_TRAFFIC_ANNOTATION);
  }
  const std::string host = ReadNativeString(native_proxy.host);
  // NetManager uses an empty host (or 'NONE') for an unset proxy.
  if (!host.empty() && host != "NONE") {
    const auto proxy = ProxyServer::FromSchemeHostAndPort(
        ProxyServer::SCHEME_HTTP, host, native_proxy.port);
    if (proxy.is_valid() && native_proxy.port != 0) {
      result.proxy_rules().type = ProxyConfig::ProxyRules::Type::PROXY_LIST;
      result.proxy_rules().single_proxies.SetSingleProxyServer(proxy);
      const size_t count = static_cast<size_t>(std::clamp(
          native_proxy.exclusionListSize, 0, NETCONN_MAX_EXCLUSION_SIZE));
      for (const auto& entry : base::span(native_proxy.exclusionList).first(count)) {
        result.proxy_rules().bypass_rules.AddRuleFromString(ReadNativeString(entry));
      }
    } else {
      result.proxy_rules().ParseFromString("http://127.0.0.1:9");
      result.proxy_rules().bypass_rules.AddRuleFromString("<-loopback>");
    }
  }
  return ProxyConfigWithAnnotation(result, MISSING_TRAFFIC_ANNOTATION);
}

}  // namespace

ProxyConfigServiceOHOSNative::ProxyConfigServiceOHOSNative()
    : config_(ReadSystemProxy()) {
  NetworkChangeNotifier::AddIPAddressObserver(this);
  // Proxy-only edits need not change the interface/IP. Poll as well, on the
  // owning sequence, so updates and observer destruction cannot race.
  poll_timer_.Start(FROM_HERE, base::Seconds(5),
                    base::BindRepeating(&ProxyConfigServiceOHOSNative::Refresh,
                                        base::Unretained(this)));
}

ProxyConfigServiceOHOSNative::~ProxyConfigServiceOHOSNative() {
  NetworkChangeNotifier::RemoveIPAddressObserver(this);
}

void ProxyConfigServiceOHOSNative::AddObserver(Observer* observer) {
  observers_.AddObserver(observer);
}

void ProxyConfigServiceOHOSNative::RemoveObserver(Observer* observer) {
  observers_.RemoveObserver(observer);
}

ProxyConfigService::ConfigAvailability
ProxyConfigServiceOHOSNative::GetLatestProxyConfig(
    ProxyConfigWithAnnotation* config) {
  *config = config_;
  return CONFIG_VALID;
}

void ProxyConfigServiceOHOSNative::OnIPAddressChanged(
    NetworkChangeNotifier::IPAddressChangeType) {
  Refresh();
}

void ProxyConfigServiceOHOSNative::Refresh() {
  auto updated = ReadSystemProxy();
  if (updated.value().Equals(config_.value()))
    return;
  config_ = std::move(updated);
  for (auto& observer : observers_)
    observer.OnProxyConfigChanged(config_, CONFIG_VALID);
}

}  // namespace net
