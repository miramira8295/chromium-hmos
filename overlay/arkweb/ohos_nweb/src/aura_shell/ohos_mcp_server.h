// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef OHOS_NWEB_SRC_AURA_SHELL_OHOS_MCP_SERVER_H_
#define OHOS_NWEB_SRC_AURA_SHELL_OHOS_MCP_SERVER_H_

#include <atomic>
#include <thread>

namespace ohos_nweb {

class OhosMcpServer {
public:
  OhosMcpServer();
  OhosMcpServer(const OhosMcpServer &) = delete;
  OhosMcpServer &operator=(const OhosMcpServer &) = delete;
  ~OhosMcpServer();

  void Start();
  void Stop();

private:
  void Run();
  void HandleClient(int client_fd);

  std::atomic<bool> stop_requested_{false};
  std::atomic<int> listen_fd_{-1};
  std::thread server_thread_;
};

} // namespace ohos_nweb

#endif // OHOS_NWEB_SRC_AURA_SHELL_OHOS_MCP_SERVER_H_
