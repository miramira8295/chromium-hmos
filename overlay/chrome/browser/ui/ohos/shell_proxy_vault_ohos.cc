// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license.
#include "chrome/browser/ui/ohos/shell_proxy_vault_ohos.h"
#include <asset/asset_api.h>
#include <algorithm>
#include <iterator>
#include "base/json/json_reader.h"
#include "base/json/json_writer.h"
#include "base/strings/string_util.h"
#include "base/uuid.h"
#include "base/values.h"
namespace chrome::ohos {
namespace {
constexpr char kPrefix[] = "lumie.proxy.v1.";
Asset_Attr BlobAttr(uint32_t tag, const std::string& text) {
  Asset_Attr attr{};
  attr.tag = tag;
  attr.value.blob.size = static_cast<uint32_t>(text.size());
  attr.value.blob.data = reinterpret_cast<uint8_t*>(const_cast<char*>(text.data()));
  return attr;
}
Asset_Attr NumberAttr(uint32_t tag, uint32_t number) {
  Asset_Attr attr{};
  attr.tag = tag;
  attr.value.u32 = number;
  return attr;
}
bool ValidRef(const std::string& ref) {
  return base::StartsWith(ref, kPrefix) &&
         base::Uuid::ParseLowercase(ref.substr(sizeof(kPrefix) - 1)).is_valid();
}
}
std::optional<std::string> StoreShellProxySecret(const ShellProxySecret& secret) {
  base::DictValue value;
  value.Set("username", secret.username);
  value.Set("password", secret.password);
  std::string bytes;
  if (!base::JSONWriter::Write(value, &bytes) || bytes.size() > 1024) return std::nullopt;
  const std::string ref = std::string(kPrefix) + base::Uuid::GenerateRandomV4().AsLowercaseString();
  Asset_Attr attrs[] = {
      BlobAttr(ASSET_TAG_ALIAS, ref), BlobAttr(ASSET_TAG_SECRET, bytes),
      NumberAttr(ASSET_TAG_ACCESSIBILITY, ASSET_ACCESSIBILITY_DEVICE_UNLOCKED),
      NumberAttr(ASSET_TAG_SYNC_TYPE, ASSET_SYNC_TYPE_NEVER),
      NumberAttr(ASSET_TAG_CONFLICT_RESOLUTION, ASSET_CONFLICT_THROW_ERROR)};
  const int result = OH_Asset_Add(attrs, std::size(attrs));
  std::fill(bytes.begin(), bytes.end(), '\0');
  return result == ASSET_SUCCESS ? std::optional(ref) : std::nullopt;
}
std::optional<ShellProxySecret> LoadShellProxySecret(const std::string& ref) {
  if (!ValidRef(ref)) return std::nullopt;
  Asset_Attr query[] = {BlobAttr(ASSET_TAG_ALIAS, ref), NumberAttr(ASSET_TAG_RETURN_TYPE, ASSET_RETURN_ALL)};
  Asset_ResultSet results{};
  if (OH_Asset_Query(query, std::size(query), &results) != ASSET_SUCCESS) return std::nullopt;
  std::optional<ShellProxySecret> secret;
  if (results.count == 1) {
    const auto& result = results.results[0];
    for (uint32_t i = 0; i < result.count; ++i) {
      auto& attr = result.attrs[i];
      if (attr.tag != ASSET_TAG_SECRET) continue;
      const auto& blob = attr.value.blob;
      const auto dict = base::JSONReader::ReadDict(
          std::string_view(reinterpret_cast<const char*>(blob.data), blob.size),
          base::JSON_PARSE_RFC);
      if (dict && dict->FindString("username") && dict->FindString("password")) {
        secret = ShellProxySecret{*dict->FindString("username"), *dict->FindString("password")};
      }
      std::fill_n(blob.data, blob.size, 0);
    }
  }
  OH_Asset_FreeResultSet(&results);
  return secret;
}
void RemoveShellProxySecret(const std::string& ref) {
  if (!ValidRef(ref)) return;
  auto query = BlobAttr(ASSET_TAG_ALIAS, ref);
  OH_Asset_Remove(&query, 1);
}
}
