// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ohos_nweb/src/aura_shell/ohos_mcp_server.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <poll.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#include <algorithm>
#include <array>
#include <cctype>
#include <charconv>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <limits>
#include <map>
#include <optional>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "base/json/json_reader.h"
#include "base/json/json_writer.h"
#include "base/values.h"
#include "chrome/browser/ui/ohos/aura_shell_runtime_bridge.h"
#include "ohos_nweb/src/nweb_hilog.h"

namespace ohos_nweb {
namespace {

constexpr uint16_t kCdpPort = 9222;
constexpr uint16_t kMcpPort = 9223;
constexpr size_t kMaxHeaderBytes = 64 * 1024;
constexpr size_t kMaxRequestBytes = 4 * 1024 * 1024;
constexpr size_t kMaxCdpResponseBytes = 8 * 1024 * 1024;
constexpr int kDefaultContentCharacters = 200000;
constexpr int kMaximumContentCharacters = 1000000;
constexpr std::string_view kMcpProtocolVersion = "2025-11-25";

struct HttpRequest {
  std::string method;
  std::string path;
  std::map<std::string, std::string> headers;
  std::string body;
};

std::string ToLower(std::string value) {
  std::ranges::transform(value, value.begin(), [](unsigned char character) {
    return static_cast<char>(std::tolower(character));
  });
  return value;
}

std::string Trim(std::string_view value) {
  size_t begin = 0;
  while (begin < value.size() &&
         std::isspace(static_cast<unsigned char>(value[begin]))) {
    ++begin;
  }
  size_t end = value.size();
  while (end > begin &&
         std::isspace(static_cast<unsigned char>(value[end - 1]))) {
    --end;
  }
  return std::string(value.substr(begin, end - begin));
}

bool SendAll(int fd, std::string_view data) {
  size_t sent = 0;
  while (sent < data.size()) {
    const ssize_t result =
        send(fd, data.data() + sent, data.size() - sent, MSG_NOSIGNAL);
    if (result <= 0) {
      return false;
    }
    sent += static_cast<size_t>(result);
  }
  return true;
}

bool ReceiveExact(int fd, void *output, size_t size) {
  auto *bytes = static_cast<uint8_t *>(output);
  size_t received = 0;
  while (received < size) {
    const ssize_t result = recv(fd, bytes + received, size - received, 0);
    if (result <= 0) {
      return false;
    }
    received += static_cast<size_t>(result);
  }
  return true;
}

std::optional<size_t> ParseSize(std::string_view value) {
  size_t result = 0;
  const auto conversion =
      std::from_chars(value.data(), value.data() + value.size(), result);
  if (conversion.ec != std::errc() ||
      conversion.ptr != value.data() + value.size()) {
    return std::nullopt;
  }
  return result;
}

bool ParseRequestHeaders(std::string_view headers, HttpRequest *request) {
  const size_t request_line_end = headers.find("\r\n");
  if (request_line_end == std::string_view::npos) {
    return false;
  }
  const std::string_view request_line = headers.substr(0, request_line_end);
  const size_t first_space = request_line.find(' ');
  const size_t second_space = request_line.find(' ', first_space + 1);
  if (first_space == std::string_view::npos ||
      second_space == std::string_view::npos) {
    return false;
  }
  request->method = std::string(request_line.substr(0, first_space));
  request->path = std::string(
      request_line.substr(first_space + 1, second_space - first_space - 1));

  size_t offset = request_line_end + 2;
  while (offset < headers.size()) {
    const size_t line_end = headers.find("\r\n", offset);
    const size_t resolved_end =
        line_end == std::string_view::npos ? headers.size() : line_end;
    const std::string_view line = headers.substr(offset, resolved_end - offset);
    if (line.empty()) {
      break;
    }
    const size_t colon = line.find(':');
    if (colon == std::string_view::npos) {
      return false;
    }
    request->headers[ToLower(Trim(line.substr(0, colon)))] =
        Trim(line.substr(colon + 1));
    if (line_end == std::string_view::npos) {
      break;
    }
    offset = line_end + 2;
  }
  return true;
}

bool ReadHttpRequest(int fd, HttpRequest *request) {
  std::string buffer;
  std::array<char, 4096> chunk = {};
  size_t header_end = std::string::npos;
  while (buffer.size() <= kMaxHeaderBytes) {
    const ssize_t size = recv(fd, chunk.data(), chunk.size(), 0);
    if (size <= 0) {
      return false;
    }
    buffer.append(chunk.data(), static_cast<size_t>(size));
    header_end = buffer.find("\r\n\r\n");
    if (header_end != std::string::npos) {
      break;
    }
  }
  if (header_end == std::string::npos ||
      !ParseRequestHeaders(std::string_view(buffer).substr(0, header_end + 2),
                           request)) {
    return false;
  }

  size_t content_length = 0;
  auto length = request->headers.find("content-length");
  if (length != request->headers.end()) {
    const std::optional<size_t> parsed = ParseSize(length->second);
    if (!parsed || *parsed > kMaxRequestBytes) {
      return false;
    }
    content_length = *parsed;
  }

  const size_t body_offset = header_end + 4;
  if (buffer.size() > body_offset) {
    request->body.assign(buffer.data() + body_offset,
                         buffer.size() - body_offset);
  }
  while (request->body.size() < content_length) {
    const size_t remaining = content_length - request->body.size();
    const ssize_t size =
        recv(fd, chunk.data(), std::min(chunk.size(), remaining), 0);
    if (size <= 0) {
      return false;
    }
    request->body.append(chunk.data(), static_cast<size_t>(size));
  }
  if (request->body.size() > content_length) {
    request->body.resize(content_length);
  }
  return true;
}

void SendHttpResponse(int fd, int status, std::string_view reason,
                      std::string_view content_type, std::string_view body,
                      std::string_view extra_headers = {}) {
  std::string response =
      "HTTP/1.1 " + std::to_string(status) + " " + std::string(reason) + "\r\n";
  if (!content_type.empty()) {
    response += "Content-Type: " + std::string(content_type) + "\r\n";
  }
  response += "Content-Length: " + std::to_string(body.size()) + "\r\n";
  response += "Connection: close\r\n";
  response += "Cache-Control: no-store\r\n";
  response += std::string(extra_headers);
  response += "\r\n";
  response += body;
  SendAll(fd, response);
}

bool IsAllowedOrigin(const HttpRequest &request) {
  auto origin = request.headers.find("origin");
  if (origin == request.headers.end()) {
    return true;
  }
  const std::string lowered = ToLower(origin->second);
  constexpr std::array<std::string_view, 4> local_origins = {
      "http://127.0.0.1", "https://127.0.0.1", "http://localhost",
      "https://localhost"};
  for (std::string_view local_origin : local_origins) {
    if (lowered == local_origin || (lowered.starts_with(local_origin) &&
                                    lowered[local_origin.size()] == ':')) {
      return true;
    }
  }
  return false;
}

int ConnectToLocalPort(uint16_t port) {
  const int fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd < 0) {
    return -1;
  }
  timeval timeout = {.tv_sec = 5, .tv_usec = 0};
  setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
  setsockopt(fd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));

  sockaddr_in address = {};
  address.sin_family = AF_INET;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  if (connect(fd, reinterpret_cast<sockaddr *>(&address), sizeof(address)) !=
      0) {
    close(fd);
    return -1;
  }
  return fd;
}

std::optional<std::string> ReadHttpResponseBody(int fd, std::string *error) {
  std::string buffer;
  std::array<char, 4096> chunk = {};
  size_t header_end = std::string::npos;
  while (buffer.size() <= kMaxHeaderBytes) {
    const ssize_t size = recv(fd, chunk.data(), chunk.size(), 0);
    if (size <= 0) {
      *error = "CDP closed its HTTP response";
      return std::nullopt;
    }
    buffer.append(chunk.data(), static_cast<size_t>(size));
    header_end = buffer.find("\r\n\r\n");
    if (header_end != std::string::npos) {
      break;
    }
  }
  if (header_end == std::string::npos ||
      !std::string_view(buffer).starts_with("HTTP/1.1 200")) {
    *error = "CDP returned an invalid HTTP response";
    return std::nullopt;
  }

  HttpRequest response_headers;
  std::string synthetic = "GET / HTTP/1.1\r\n";
  synthetic.append(buffer.data() + buffer.find("\r\n") + 2,
                   header_end - buffer.find("\r\n"));
  if (!ParseRequestHeaders(synthetic, &response_headers)) {
    *error = "CDP returned invalid HTTP headers";
    return std::nullopt;
  }
  auto length = response_headers.headers.find("content-length");
  if (length == response_headers.headers.end()) {
    *error = "CDP HTTP response has no content length";
    return std::nullopt;
  }
  const std::optional<size_t> content_length = ParseSize(length->second);
  if (!content_length || *content_length > kMaxCdpResponseBytes) {
    *error = "CDP HTTP response is too large";
    return std::nullopt;
  }

  std::string body;
  const size_t body_offset = header_end + 4;
  if (buffer.size() > body_offset) {
    body.assign(buffer.data() + body_offset, buffer.size() - body_offset);
  }
  while (body.size() < *content_length) {
    const size_t remaining = *content_length - body.size();
    const ssize_t size =
        recv(fd, chunk.data(), std::min(chunk.size(), remaining), 0);
    if (size <= 0) {
      *error = "CDP HTTP body ended early";
      return std::nullopt;
    }
    body.append(chunk.data(), static_cast<size_t>(size));
  }
  body.resize(*content_length);
  return body;
}

std::optional<std::string> FetchCdpPageList(std::string *error) {
  const int fd = ConnectToLocalPort(kCdpPort);
  if (fd < 0) {
    *error = "Chromium CDP is not ready";
    return std::nullopt;
  }
  const std::string request =
      "GET /json/list HTTP/1.1\r\nHost: 127.0.0.1:9222\r\n"
      "Connection: close\r\n\r\n";
  if (!SendAll(fd, request)) {
    close(fd);
    *error = "Failed to request the CDP page list";
    return std::nullopt;
  }
  std::optional<std::string> body = ReadHttpResponseBody(fd, error);
  close(fd);
  return body;
}

std::optional<std::string> FindCdpWebSocketPath(std::string_view page_list,
                                                std::string_view target_id,
                                                std::string *error) {
  std::optional<base::Value> parsed =
      base::JSONReader::Read(page_list, base::JSON_PARSE_RFC);
  if (!parsed || !parsed->is_list()) {
    *error = "CDP returned an invalid page list";
    return std::nullopt;
  }
  for (const base::Value &target : parsed->GetList()) {
    const base::DictValue *item = target.GetIfDict();
    const std::string *type = item ? item->FindString("type") : nullptr;
    if (!type || *type != "page") {
      continue;
    }
    const std::string *id = item->FindString("id");
    if (!target_id.empty() && (!id || *id != target_id)) {
      continue;
    }
    const std::string *websocket = item->FindString("webSocketDebuggerUrl");
    if (!websocket) {
      continue;
    }
    const size_t path = websocket->find("/devtools/");
    if (path != std::string::npos) {
      return websocket->substr(path);
    }
  }
  *error = "No matching Chromium page target was found";
  return std::nullopt;
}

bool SendWebSocketFrame(int fd, std::string_view payload, uint8_t opcode = 1) {
  std::vector<uint8_t> frame;
  frame.push_back(static_cast<uint8_t>(0x80 | opcode));
  if (payload.size() < 126) {
    frame.push_back(static_cast<uint8_t>(0x80 | payload.size()));
  } else if (payload.size() <= std::numeric_limits<uint16_t>::max()) {
    frame.push_back(0x80 | 126);
    frame.push_back(static_cast<uint8_t>((payload.size() >> 8) & 0xff));
    frame.push_back(static_cast<uint8_t>(payload.size() & 0xff));
  } else {
    frame.push_back(0x80 | 127);
    for (int shift = 56; shift >= 0; shift -= 8) {
      frame.push_back(static_cast<uint8_t>((payload.size() >> shift) & 0xff));
    }
  }
  const uint32_t seed = static_cast<uint32_t>(
      std::chrono::steady_clock::now().time_since_epoch().count());
  const std::array<uint8_t, 4> mask = {
      static_cast<uint8_t>(seed), static_cast<uint8_t>(seed >> 8),
      static_cast<uint8_t>(seed >> 16), static_cast<uint8_t>(seed >> 24)};
  frame.insert(frame.end(), mask.begin(), mask.end());
  for (size_t index = 0; index < payload.size(); ++index) {
    frame.push_back(static_cast<uint8_t>(payload[index]) ^ mask[index % 4]);
  }
  return SendAll(fd,
                 std::string_view(reinterpret_cast<const char *>(frame.data()),
                                  frame.size()));
}

bool ReceiveWebSocketFrame(int fd, uint8_t *opcode, std::string *payload,
                           std::string *error) {
  std::array<uint8_t, 2> header = {};
  if (!ReceiveExact(fd, header.data(), header.size())) {
    *error = "CDP WebSocket closed";
    return false;
  }
  *opcode = header[0] & 0x0f;
  uint64_t size = header[1] & 0x7f;
  if (size == 126) {
    std::array<uint8_t, 2> extended = {};
    if (!ReceiveExact(fd, extended.data(), extended.size())) {
      return false;
    }
    size = (static_cast<uint64_t>(extended[0]) << 8) | extended[1];
  } else if (size == 127) {
    std::array<uint8_t, 8> extended = {};
    if (!ReceiveExact(fd, extended.data(), extended.size())) {
      return false;
    }
    size = 0;
    for (uint8_t value : extended) {
      size = (size << 8) | value;
    }
  }
  if (size > kMaxCdpResponseBytes) {
    *error = "CDP WebSocket response is too large";
    return false;
  }
  std::array<uint8_t, 4> mask = {};
  const bool masked = (header[1] & 0x80) != 0;
  if (masked && !ReceiveExact(fd, mask.data(), mask.size())) {
    return false;
  }
  payload->resize(static_cast<size_t>(size));
  if (size && !ReceiveExact(fd, payload->data(), payload->size())) {
    return false;
  }
  if (masked) {
    for (size_t index = 0; index < payload->size(); ++index) {
      (*payload)[index] = static_cast<char>(
          static_cast<uint8_t>((*payload)[index]) ^ mask[index % 4]);
    }
  }
  return true;
}

std::optional<std::string> EvaluateWithCdp(std::string_view websocket_path,
                                           std::string_view expression,
                                           std::string *error) {
  const int fd = ConnectToLocalPort(kCdpPort);
  if (fd < 0) {
    *error = "Chromium CDP is not ready";
    return std::nullopt;
  }
  const std::string handshake =
      "GET " + std::string(websocket_path) +
      " HTTP/1.1\r\nHost: 127.0.0.1:9222\r\nUpgrade: websocket\r\n"
      "Connection: Upgrade\r\nSec-WebSocket-Key: "
      "dGhlIHNhbXBsZSBub25jZQ==\r\nSec-WebSocket-Version: 13\r\n\r\n";
  if (!SendAll(fd, handshake)) {
    close(fd);
    *error = "Failed to open the CDP WebSocket";
    return std::nullopt;
  }
  std::string response;
  std::array<char, 1024> chunk = {};
  while (response.size() <= kMaxHeaderBytes &&
         response.find("\r\n\r\n") == std::string::npos) {
    const ssize_t size = recv(fd, chunk.data(), chunk.size(), 0);
    if (size <= 0) {
      close(fd);
      *error = "CDP rejected the WebSocket handshake";
      return std::nullopt;
    }
    response.append(chunk.data(), static_cast<size_t>(size));
  }
  if (!std::string_view(response).starts_with("HTTP/1.1 101")) {
    close(fd);
    *error = "CDP rejected the WebSocket handshake";
    return std::nullopt;
  }

  base::DictValue params;
  params.Set("expression", expression);
  params.Set("awaitPromise", true);
  params.Set("returnByValue", true);
  base::DictValue command;
  command.Set("id", 1);
  command.Set("method", "Runtime.evaluate");
  command.Set("params", std::move(params));
  std::string command_json;
  base::JSONWriter::Write(command, &command_json);
  if (!SendWebSocketFrame(fd, command_json)) {
    close(fd);
    *error = "Failed to send the CDP command";
    return std::nullopt;
  }

  std::string fragments;
  while (true) {
    uint8_t opcode = 0;
    std::string payload;
    if (!ReceiveWebSocketFrame(fd, &opcode, &payload, error)) {
      close(fd);
      return std::nullopt;
    }
    if (opcode == 8) {
      close(fd);
      *error = "CDP closed before returning page content";
      return std::nullopt;
    }
    if (opcode == 9) {
      SendWebSocketFrame(fd, payload, 10);
      continue;
    }
    if (opcode == 1 || opcode == 2) {
      fragments = std::move(payload);
    } else if (opcode == 0) {
      fragments += payload;
    } else {
      continue;
    }

    std::optional<base::DictValue> message =
        base::JSONReader::ReadDict(fragments, base::JSON_PARSE_RFC);
    if (!message || message->FindInt("id").value_or(0) != 1) {
      continue;
    }
    SendWebSocketFrame(fd, {}, 8);
    close(fd);
    const base::DictValue *result = message->FindDict("result");
    if (!result || result->Find("exceptionDetails")) {
      *error = "Chromium could not evaluate the page content request";
      return std::nullopt;
    }
    const base::DictValue *remote_object = result->FindDict("result");
    const std::string *value =
        remote_object ? remote_object->FindString("value") : nullptr;
    if (!value) {
      *error = "Chromium returned no page content";
      return std::nullopt;
    }
    return *value;
  }
}

std::optional<std::string> ReadPageContent(const base::DictValue *arguments,
                                           std::string *error) {
  std::string target_id;
  bool include_text = true;
  bool include_html = true;
  int max_characters = kDefaultContentCharacters;
  if (arguments) {
    if (const std::string *value = arguments->FindString("targetId")) {
      target_id = *value;
    }
    include_text = arguments->FindBool("includeText").value_or(true);
    include_html = arguments->FindBool("includeHtml").value_or(true);
    max_characters = std::clamp(
        arguments->FindInt("maxChars").value_or(kDefaultContentCharacters), 1,
        kMaximumContentCharacters);
  }

  std::optional<std::string> page_list = FetchCdpPageList(error);
  if (!page_list) {
    return std::nullopt;
  }
  std::optional<std::string> websocket =
      FindCdpWebSocketPath(*page_list, target_id, error);
  if (!websocket) {
    return std::nullopt;
  }

  const std::string expression =
      "(() => { const limit = " + std::to_string(max_characters) +
      "; const text = " + (include_text ? "true" : "false") +
      " ? (document.body?.innerText || '') : ''; const html = " +
      (include_html ? "true" : "false") +
      " ? (document.documentElement?.outerHTML || '') : ''; return "
      "JSON.stringify({url: location.href, title: document.title, "
      "text: text.slice(0, limit), html: html.slice(0, limit), "
      "selection: (globalThis.getSelection?.().toString() || '').slice(0, "
      "limit)}); })()";
  return EvaluateWithCdp(*websocket, expression, error);
}

base::DictValue MakeTool(std::string_view name, std::string_view title,
                         std::string_view description,
                         base::DictValue input_schema) {
  base::DictValue tool;
  tool.Set("name", name);
  tool.Set("title", title);
  tool.Set("description", description);
  tool.Set("inputSchema", std::move(input_schema));
  return tool;
}

base::DictValue EmptyObjectSchema() {
  base::DictValue schema;
  schema.Set("type", "object");
  schema.Set("properties", base::DictValue());
  schema.Set("additionalProperties", false);
  return schema;
}

base::ListValue BuildTools() {
  base::ListValue tools;
  tools.Append(MakeTool("browser.list_pages", "List browser pages",
                        "List Chromium page targets available to the agent.",
                        EmptyObjectSchema()));

  base::DictValue content_properties;
  content_properties.Set(
      "targetId", base::DictValue()
                      .Set("type", "string")
                      .Set("description", "Optional CDP page target id."));
  content_properties.Set(
      "includeText",
      base::DictValue().Set("type", "boolean").Set("default", true));
  content_properties.Set(
      "includeHtml",
      base::DictValue().Set("type", "boolean").Set("default", true));
  content_properties.Set("maxChars",
                         base::DictValue()
                             .Set("type", "integer")
                             .Set("minimum", 1)
                             .Set("maximum", kMaximumContentCharacters)
                             .Set("default", kDefaultContentCharacters));
  base::DictValue content_schema;
  content_schema.Set("type", "object");
  content_schema.Set("properties", std::move(content_properties));
  content_schema.Set("additionalProperties", false);
  tools.Append(MakeTool(
      "browser.get_content", "Read browser content",
      "Read the current Chromium page URL, title, visible text, HTML, and "
      "selection.",
      std::move(content_schema)));

  base::DictValue navigate_properties;
  navigate_properties.Set(
      "url",
      base::DictValue()
          .Set("type", "string")
          .Set("description", "The HTTP, HTTPS, or Chromium URL to open."));
  base::DictValue navigate_schema;
  navigate_schema.Set("type", "object");
  navigate_schema.Set("properties", std::move(navigate_properties));
  navigate_schema.Set("required", base::ListValue().Append("url"));
  navigate_schema.Set("additionalProperties", false);
  tools.Append(MakeTool("browser.navigate", "Navigate browser",
                        "Navigate the active Chromium tab to a URL.",
                        std::move(navigate_schema)));
  return tools;
}

base::DictValue MakeToolResult(std::string text, bool is_error) {
  base::DictValue text_content;
  text_content.Set("type", "text");
  text_content.Set("text", text);
  base::ListValue content;
  content.Append(std::move(text_content));
  base::DictValue result;
  result.Set("content", std::move(content));
  result.Set("isError", is_error);
  if (!is_error) {
    std::optional<base::Value> structured =
        base::JSONReader::Read(text, base::JSON_PARSE_RFC);
    if (structured) {
      if (structured->is_dict()) {
        result.Set("structuredContent", std::move(*structured).TakeDict());
      } else if (structured->is_list()) {
        base::DictValue wrapper;
        wrapper.Set("pages", std::move(*structured).TakeList());
        result.Set("structuredContent", std::move(wrapper));
      }
    }
  }
  return result;
}

base::DictValue MakeError(int code, std::string_view message) {
  base::DictValue error;
  error.Set("code", code);
  error.Set("message", message);
  return error;
}

std::string SerializeResponse(const base::Value *id,
                              std::optional<base::DictValue> result,
                              std::optional<base::DictValue> error) {
  base::DictValue response;
  response.Set("jsonrpc", "2.0");
  if (id) {
    response.Set("id", id->Clone());
  } else {
    response.Set("id", base::Value());
  }
  if (result) {
    response.Set("result", std::move(*result));
  } else if (error) {
    response.Set("error", std::move(*error));
  }
  std::string serialized;
  base::JSONWriter::Write(response, &serialized);
  return serialized;
}

std::optional<std::string> HandleMcpRequest(const HttpRequest &request,
                                            int *http_status) {
  std::optional<base::DictValue> message =
      base::JSONReader::ReadDict(request.body, base::JSON_PARSE_RFC);
  if (!message) {
    *http_status = 400;
    return SerializeResponse(nullptr, std::nullopt,
                             MakeError(-32700, "Parse error"));
  }
  const base::Value *id = message->Find("id");
  const std::string *method = message->FindString("method");
  const std::string *jsonrpc = message->FindString("jsonrpc");
  if (!jsonrpc || *jsonrpc != "2.0" || !method) {
    *http_status = 400;
    return SerializeResponse(id, std::nullopt,
                             MakeError(-32600, "Invalid Request"));
  }
  if (!id && method->starts_with("notifications/")) {
    *http_status = 202;
    return std::nullopt;
  }

  if (*method == "initialize") {
    std::string protocol(kMcpProtocolVersion);
    if (const base::DictValue *params = message->FindDict("params")) {
      const std::string *requested_value =
          params->FindString("protocolVersion");
      const std::string requested =
          requested_value ? *requested_value : std::string();
      if (requested == "2025-06-18" || requested == "2025-11-25") {
        protocol = requested;
      }
    }
    base::DictValue tools_capability;
    tools_capability.Set("listChanged", false);
    base::DictValue capabilities;
    capabilities.Set("tools", std::move(tools_capability));
    base::DictValue server_info;
    server_info.Set("name", "chromium-harmonyos-browser");
    server_info.Set("title", "Chromium for HarmonyOS");
    server_info.Set("version", "150.0.7871.114");
    base::DictValue result;
    result.Set("protocolVersion", protocol);
    result.Set("capabilities", std::move(capabilities));
    result.Set("serverInfo", std::move(server_info));
    result.Set("instructions",
               "Use browser.get_content to read the active Chromium page. "
               "All access stays on the local HarmonyOS device.");
    return SerializeResponse(id, std::move(result), std::nullopt);
  }

  if (*method == "ping") {
    return SerializeResponse(id, base::DictValue(), std::nullopt);
  }
  if (*method == "tools/list") {
    base::DictValue result;
    result.Set("tools", BuildTools());
    return SerializeResponse(id, std::move(result), std::nullopt);
  }
  if (*method != "tools/call") {
    return SerializeResponse(id, std::nullopt,
                             MakeError(-32601, "Method not found"));
  }

  const base::DictValue *params = message->FindDict("params");
  const std::string *name = params ? params->FindString("name") : nullptr;
  const base::DictValue *arguments =
      params ? params->FindDict("arguments") : nullptr;
  if (!name) {
    return SerializeResponse(id, std::nullopt,
                             MakeError(-32602, "Tool name is required"));
  }

  std::string error;
  if (*name == "browser.list_pages") {
    std::optional<std::string> pages = FetchCdpPageList(&error);
    return SerializeResponse(id, MakeToolResult(pages.value_or(error), !pages),
                             std::nullopt);
  }
  if (*name == "browser.get_content") {
    std::optional<std::string> content = ReadPageContent(arguments, &error);
    return SerializeResponse(
        id, MakeToolResult(content.value_or(error), !content), std::nullopt);
  }
  if (*name == "browser.navigate") {
    const std::string *url_value =
        arguments ? arguments->FindString("url") : nullptr;
    const std::string url = url_value ? *url_value : std::string();
    const bool accepted = chrome::ohos::NavigateAuraShellBrowser(url);
    base::DictValue navigation;
    navigation.Set("accepted", accepted);
    navigation.Set("url", url);
    std::string navigation_json;
    base::JSONWriter::Write(navigation, &navigation_json);
    return SerializeResponse(
        id,
        MakeToolResult(accepted ? navigation_json : "Invalid navigation URL",
                       !accepted),
        std::nullopt);
  }
  return SerializeResponse(id, std::nullopt,
                           MakeError(-32602, "Unknown browser tool"));
}

std::string BuildServerCard() {
  base::DictValue server_info;
  server_info.Set("name", "chromium-harmonyos-browser");
  server_info.Set("title", "Chromium for HarmonyOS");
  server_info.Set("version", "150.0.7871.114");
  base::DictValue transport;
  transport.Set("type", "streamable-http");
  transport.Set("endpoint", "http://127.0.0.1:9223/mcp");
  base::DictValue tools;
  tools.Set("listChanged", false);
  base::DictValue capabilities;
  capabilities.Set("tools", std::move(tools));
  base::DictValue card;
  card.Set("$schema", "https://static.modelcontextprotocol.io/schemas/"
                      "mcp-server-card/v1.json");
  card.Set("version", "1.0");
  card.Set("protocolVersion", kMcpProtocolVersion);
  card.Set("serverInfo", std::move(server_info));
  card.Set("description",
           "Local access to the active Chromium browsing context on "
           "HarmonyOS.");
  card.Set("transport", std::move(transport));
  card.Set("capabilities", std::move(capabilities));
  std::string serialized;
  base::JSONWriter::Write(card, &serialized);
  return serialized;
}

} // namespace

OhosMcpServer::OhosMcpServer() = default;

OhosMcpServer::~OhosMcpServer() { Stop(); }

void OhosMcpServer::Start() {
  if (server_thread_.joinable()) {
    return;
  }
  stop_requested_.store(false);
  server_thread_ = std::thread(&OhosMcpServer::Run, this);
}

void OhosMcpServer::Stop() {
  stop_requested_.store(true);
  const int fd = listen_fd_.exchange(-1);
  if (fd >= 0) {
    shutdown(fd, SHUT_RDWR);
    close(fd);
  }
  if (server_thread_.joinable() &&
      server_thread_.get_id() != std::this_thread::get_id()) {
    server_thread_.join();
  }
}

void OhosMcpServer::Run() {
  const int fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd < 0) {
    WVLOG_E("AuraShell MCP failed to create its local socket");
    return;
  }
  int reuse_address = 1;
  setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse_address,
             sizeof(reuse_address));
  sockaddr_in address = {};
  address.sin_family = AF_INET;
  address.sin_port = htons(kMcpPort);
  address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  if (bind(fd, reinterpret_cast<sockaddr *>(&address), sizeof(address)) != 0 ||
      listen(fd, 4) != 0) {
    WVLOG_E("AuraShell MCP failed to bind 127.0.0.1:%{public}u", kMcpPort);
    close(fd);
    return;
  }
  listen_fd_.store(fd);
  WVLOG_I("AuraShell MCP listening on 127.0.0.1:%{public}u/mcp", kMcpPort);

  while (!stop_requested_.load()) {
    pollfd descriptor = {.fd = fd, .events = POLLIN, .revents = 0};
    const int poll_result = poll(&descriptor, 1, 250);
    if (poll_result <= 0 || !(descriptor.revents & POLLIN)) {
      continue;
    }
    const int client_fd = accept(fd, nullptr, nullptr);
    if (client_fd < 0) {
      continue;
    }
    timeval timeout = {.tv_sec = 5, .tv_usec = 0};
    setsockopt(client_fd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    setsockopt(client_fd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));
    HandleClient(client_fd);
    close(client_fd);
  }
  if (listen_fd_.exchange(-1) == fd) {
    close(fd);
  }
}

void OhosMcpServer::HandleClient(int client_fd) {
  HttpRequest request;
  if (!ReadHttpRequest(client_fd, &request)) {
    SendHttpResponse(client_fd, 400, "Bad Request", "text/plain",
                     "Bad Request");
    return;
  }
  if (!IsAllowedOrigin(request)) {
    SendHttpResponse(client_fd, 403, "Forbidden", "text/plain", "Forbidden");
    return;
  }
  if (request.method == "OPTIONS") {
    SendHttpResponse(client_fd, 204, "No Content", "", "",
                     "Access-Control-Allow-Origin: http://127.0.0.1\r\n"
                     "Access-Control-Allow-Methods: POST, OPTIONS\r\n"
                     "Access-Control-Allow-Headers: Content-Type, Accept, "
                     "MCP-Protocol-Version\r\n");
    return;
  }
  if (request.method == "GET" && request.path == "/health") {
    SendHttpResponse(client_fd, 200, "OK", "application/json",
                     "{\"status\":\"ok\",\"cdpPort\":9222,"
                     "\"mcpPort\":9223}");
    return;
  }
  if (request.method == "GET" &&
      request.path == "/.well-known/mcp/server-card.json") {
    SendHttpResponse(client_fd, 200, "OK", "application/json",
                     BuildServerCard());
    return;
  }
  if (request.method != "POST" || request.path != "/mcp") {
    SendHttpResponse(client_fd, 404, "Not Found", "text/plain", "Not Found");
    return;
  }

  int status = 200;
  std::optional<std::string> response = HandleMcpRequest(request, &status);
  if (!response) {
    SendHttpResponse(client_fd, status, "Accepted", "", "");
    return;
  }
  SendHttpResponse(client_fd, status, status == 200 ? "OK" : "Bad Request",
                   "application/json", *response);
}

} // namespace ohos_nweb
