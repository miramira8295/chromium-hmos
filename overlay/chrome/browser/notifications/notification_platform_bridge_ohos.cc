// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <memory>

#include "chrome/browser/notifications/notification_platform_bridge.h"
#include "chrome/browser/notifications/stub_notification_platform_bridge.h"

std::unique_ptr<NotificationPlatformBridge>
NotificationPlatformBridge::Create() {
  return std::make_unique<StubNotificationPlatformBridge>();
}

bool NotificationPlatformBridge::CanHandleType(
    NotificationHandler::Type notification_type) {
  return true;
}
