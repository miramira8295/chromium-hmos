#!/usr/bin/env python3
"""Run production mode/endpoint logic with lightweight Dict/validation fakes.
Tests retention and credential endpoint binding, not Chromium URL parsing.
"""
from pathlib import Path
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / 'overlay/chrome/browser/ui/ohos/shell_proxy_ohos.cc'
PREFIX = r'''
#include <cassert>
#include <map>
#include <optional>
#include <string>
#include <variant>
#include <utility>
namespace base {
class DictValue {
 public:
  std::map<std::string, std::variant<std::string, int, bool>> values;
  DictValue Clone() const { return *this; }
  void Set(const std::string& k, const char* v) { values[k] = std::string(v); }
  void Set(const std::string& k, std::string v) { values[k] = std::move(v); }
  void Set(const std::string& k, int v) { values[k] = v; }
  void Set(const std::string& k, bool v) { values[k] = v; }
  std::optional<int> FindInt(const std::string& k) const {
    auto i = values.find(k); if (i == values.end()) return {};
    auto p = std::get_if<int>(&i->second); return p ? std::optional(*p) : std::nullopt;
  }
};
}
std::string String(const base::DictValue& d, const std::string& k) {
  auto i = d.values.find(k); if (i == d.values.end()) return {};
  auto p = std::get_if<std::string>(&i->second); return p ? *p : std::string();
}
// Model the existing custom validator: defaults, recognized fields only,
// no credential refs accepted from an input form.
std::optional<base::DictValue> Validate(const base::DictValue&);
'''
VALIDATE = r'''
std::optional<base::DictValue> Validate(const base::DictValue& input) {
  if (String(input, "host").empty() || input.FindInt("port").value_or(0) < 1) return {};
  auto result = DefaultConfig();
  for (const auto* key : {"mode", "scheme", "host", "port", "bypassRules", "bypassPrivateAddresses"})
    result.values[key] = input.values.at(key);
  return result;
}
'''
MAIN = r'''
int main() {
  auto custom = DefaultConfig();
  custom.Set("mode", "custom"); custom.Set("scheme", "socks5");
  custom.Set("host", "proxy.example"); custom.Set("port", 11280);
  custom.Set("bypassRules", "example.com"); custom.Set("bypassPrivateAddresses", true);
  custom.Set("credentialRef", "saved-asset"); custom.Set("revision", 13);
  auto saved = custom.Clone();
  // Repeated saves, including a simulated restart/read, preserve every field
  // and the Asset reference. A hidden draft is never committed instead.
  for (const auto* mode : {"direct", "system", "direct", "system"}) {
    auto input = DefaultConfig(); input.Set("mode", mode);
    input.Set("host", "hidden-unsaved.example"); input.Set("credentialRef", "injected");
    auto next = PreserveCustomConfig(input, saved);
    assert(String(next, "mode") == mode);
    for (const auto* key : {"scheme", "host", "port", "bypassRules", "bypassPrivateAddresses", "credentialRef"})
      assert(next.values.at(key) == custom.values.at(key));
    assert(SameEndpoint(next, custom));
    saved = next.Clone();
  }
  // Enabling custom again may reuse authentication only for the saved endpoint.
  for (int change = 0; change < 3; ++change) {
    auto other = custom.Clone();
    if (change == 0) other.Set("scheme", "http");
    if (change == 1) other.Set("host", "other.example");
    if (change == 2) other.Set("port", 1080);
    assert(!SameEndpoint(saved, other));
  }
  auto direct = DefaultConfig(); direct.Set("mode", "direct");
  assert(PreserveCustomConfig(direct, DefaultConfig()).values == direct.values);
  auto broken = custom.Clone(); broken.Set("port", 0);
  assert(PreserveCustomConfig(direct, broken).values == direct.values);
  auto replacement = custom.Clone(); replacement.Set("host", "new.example");
  replacement.Set("credentialRef", "");
  assert(PreserveCustomConfig(replacement, saved).values == replacement.values);
  assert(!SameEndpoint(DefaultConfig(), DefaultConfig()));
}
'''

def function(source, signature):
    start = source.index(signature)
    return source[start:source.index('\n}', start) + 2] + '\n'

def main():
    source = SOURCE.read_text()
    code = PREFIX + function(source, 'base::DictValue DefaultConfig()') + VALIDATE
    code += function(source, 'base::DictValue PreserveCustomConfig(')
    code += function(source, 'bool SameEndpoint(') + MAIN
    with tempfile.TemporaryDirectory(prefix='proxy-mode-retention-') as folder:
        path = Path(folder)
        (path / 'test.cc').write_text(code)
        subprocess.run(['c++', '-std=c++20', '-Wall', '-Wextra', '-Werror', str(path / 'test.cc'), '-o', str(path / 'test')], check=True)
        subprocess.run([str(path / 'test')], check=True)
    print('Custom proxy retention: mode round trips, Asset reference, hidden edits, invalid saved settings and endpoint binding passed')

if __name__ == '__main__':
    main()
