// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license.
#include "chrome/browser/ui/ohos/shell_proxy_ohos.h"

#include <algorithm>
#include <fcntl.h>
#include <sys/file.h>
#include <memory>
#include <optional>
#include <set>
#include <string>
#include <utility>
#include "base/command_line.h"
#include "base/files/file_util.h"
#include "base/files/scoped_file.h"
#include "base/files/important_file_writer.h"
#include "base/json/json_reader.h"
#include "base/json/json_writer.h"
#include "base/task/thread_pool.h"
#include "base/threading/thread_restrictions.h"
#include "base/functional/bind.h"
#include "base/memory/weak_ptr.h"
#include "base/strings/string_split.h"
#include "base/strings/string_util.h"
#include "base/strings/string_number_conversions.h"
#include "base/supports_user_data.h"
#include "base/time/time.h"
#include "chrome/browser/browser_process.h"
#include "chrome/browser/net/system_network_context_manager.h"
#include "chrome/browser/profiles/profile.h"
#include "chrome/browser/profiles/profile_observer.h"
#include "chrome/browser/ui/browser_window/public/browser_window_interface.h"
#include "chrome/browser/ui/ohos/shell_proxy_vault_ohos.h"
#include "chrome/browser/ui/ohos/shell_services_ohos.h"
#include "chrome/browser/ui/ohos/shell_settings_ohos_internal.h"
#include "components/prefs/pref_registry_simple.h"
#include "components/prefs/pref_change_registrar.h"
#include "components/prefs/pref_service.h"
#include "components/proxy_config/proxy_config_dictionary.h"
#include "components/proxy_config/proxy_config_pref_names.h"
#include "content/public/browser/network_service_instance.h"
#include "mojo/public/cpp/bindings/remote.h"
#include "net/base/host_port_pair.h"
#include "net/base/load_flags.h"
#include "net/base/net_errors.h"
#include "net/base/network_change_notifier.h"
#include "net/http/http_response_headers.h"
#include "net/proxy_resolution/proxy_config.h"
#include "net/proxy_resolution/proxy_config_with_annotation.h"
#include "net/traffic_annotation/network_traffic_annotation.h"
#include "services/network/public/cpp/resource_request.h"
#include "services/network/public/cpp/simple_url_loader.h"
#include "services/network/public/mojom/network_context.mojom.h"
#include "services/network/public/mojom/url_loader_factory.mojom.h"
#include "url/gurl.h"

namespace net {
// Match the platform proxy-setting getter helper used by Chromium on Linux.
// Its existing thread-restriction exception permits the bounded startup read
// before any Profile NetworkContext can issue requests.
class ScopedAllowBlockingForSettingGetter : public base::ScopedAllowBlocking {};
}  // namespace net

namespace chrome::ohos {
namespace {
constexpr char kDesired[] = "ohos.proxy.desired";
constexpr char kRetired[] = "ohos.proxy.retired_credentials";
const char kStateKey = 0;
constexpr char kTestUrl[] = "https://example.com/";
constexpr net::NetworkTrafficAnnotationTag kProxyAnnotation =
    net::DefineNetworkTrafficAnnotation("ohos_shell_proxy", R"(
      semantics {
        sender: "Lumie proxy settings"
        description: "Routes browser profile traffic through the user-selected proxy. A user-requested isolated test fetches only the headers of the IANA example page."
        trigger: "User saves a custom proxy and restarts, or explicitly tests a draft."
        data: "Requested URLs and, when configured, proxy authentication. No browser cookies in tests."
        destination: OTHER
        destination_other: "The user-selected proxy server; example.com for tests."
      }
      policy {
        cookies_allowed: NO
        setting: "Settings > Privacy and security > Proxy. Defaults to system settings."
        policy_exception_justification: "Respects Chromium proxy policy precedence."
      })");

std::string String(const base::DictValue& dict, std::string_view key) {
  const auto* value = dict.FindString(key);
  return value ? *value : std::string();
}
base::DictValue DefaultConfig() {
  base::DictValue config;
  config.Set("version", 1);
  config.Set("revision", 0);
  config.Set("mode", "system");
  config.Set("scheme", "http");
  config.Set("host", "");
  config.Set("port", 8080);
  config.Set("bypassRules", "");
  config.Set("bypassPrivateAddresses", false);
  config.Set("credentialRef", "");
  return config;
}

// Deliberately accept only explicit host/domain exceptions in the editor.
// No '*' / <local> / <-loopback> / reverse bypass or hidden DIRECT escape.
bool ValidBypassHost(std::string rule) {
  if (base::StartsWith(rule, "*.")) rule.erase(0, 2);
  if (rule.empty() || rule.find_first_not_of(
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-") != std::string::npos)
    return false;
  if (rule == "." || rule.front() == '.' || rule.back() == '.' || rule.find("..") != std::string::npos)
    return false;
  const GURL url("http://" + rule + "/");
  return url.is_valid() && url.has_host();
}
std::optional<base::DictValue> Validate(const base::DictValue& input) {
  auto config = DefaultConfig();
  const auto mode = String(input, "mode");
  if (input.FindInt("version") != 1 ||
      (mode != "system" && mode != "direct" && mode != "custom")) return std::nullopt;
  config.Set("mode", mode);
  if (mode != "custom") return config;
  const auto scheme = String(input, "scheme");
  auto host = String(input, "host");
  const auto port = input.FindInt("port");
  if ((scheme != "http" && scheme != "https" && scheme != "socks5") ||
      !port || *port < 1 || *port > 65535 || host.empty() || host.size() > 253 ||
      host.find_first_of("/\\@?#;=, \t\r\n") != std::string::npos)
    return std::nullopt;
  if (host.find(':') != std::string::npos && host.front() != '[') host = "[" + host + "]";
  const GURL canonical("http://" + host + ":" + base::NumberToString(*port) + "/");
  if (!canonical.is_valid() || !canonical.has_host() || canonical.has_username() ||
      canonical.has_password() || canonical.EffectiveIntPort() != *port) return std::nullopt;
  // A non-IPv6 address with an embedded port is never accepted as a host.
  if (canonical.host() != base::ToLowerASCII(host) && host.find(':') != std::string::npos && host.front() != '[')
    return std::nullopt;
  const auto bypass = String(input, "bypassRules");
  if (bypass.size() > 4096) return std::nullopt;
  std::string normalized;
  for (const auto& rule : base::SplitString(bypass, "\n", base::TRIM_WHITESPACE, base::SPLIT_WANT_NONEMPTY)) {
    if (!ValidBypassHost(rule)) return std::nullopt;
    if (!normalized.empty()) normalized += "\n";
    normalized += base::ToLowerASCII(rule);
  }
  config.Set("scheme", scheme);
  config.Set("host", canonical.HostNoBrackets());
  config.Set("port", *port);
  config.Set("bypassRules", normalized);
  config.Set("bypassPrivateAddresses", input.FindBool("bypassPrivateAddresses").value_or(false));
  return config;
}
std::string Server(const base::DictValue& config) {
  return String(config, "scheme") + "://" +
      net::HostPortPair(String(config, "host"), config.FindInt("port").value_or(0)).ToString();
}
std::string Bypass(const base::DictValue& config) {
  std::string rules = String(config, "bypassRules");
  std::replace(rules.begin(), rules.end(), '\n', ';');
  if (config.FindBool("bypassPrivateAddresses").value_or(false))
    rules += ";10.0.0.0/8;172.16.0.0/12;192.168.0.0/16;169.254.0.0/16;fc00::/7;fe80::/10";
  return rules;
}
net::ProxyConfigWithAnnotation NetworkConfig(const base::DictValue& config, bool test = false) {
  net::ProxyConfig result;
  result.proxy_rules().ParseFromString(Server(config));
  result.proxy_rules().bypass_rules.ParseFromString(test ? "<-loopback>" : Bypass(config));
  return net::ProxyConfigWithAnnotation(result, kProxyAnnotation);
}
net::ProxyConfigWithAnnotation BlockedConfig() {
  auto config = DefaultConfig();
  config.Set("scheme", "http"); config.Set("host", "127.0.0.1"); config.Set("port", 9);
  return NetworkConfig(config, true);
}
base::FilePath SharedConfigPath(Profile* profile) {
  // Phone private browsing uses files/chromium-profiles/incognito/Default,
  // whereas normal browsing uses files/chromium-profile/Default.
  auto user_data = profile->GetOriginalProfile()->GetPath().DirName();
  auto files = user_data.BaseName().value() == "chromium-profile"
      ? user_data.DirName()
      : user_data.DirName().BaseName().value() == "chromium-profiles"
          ? user_data.DirName().DirName() : user_data;
  return files.AppendASCII("lumie-proxy.json");
}
base::DictValue Desired(Profile* profile) {
  // Must finish before the profile creates any network context. An unreadable
  // existing file is an error, never a reason to reset to system/direct.
  net::ScopedAllowBlockingForSettingGetter allow;
  const auto path = SharedConfigPath(profile);
  if (!base::PathExists(path)) return DefaultConfig();
  std::string bytes;
  if (!base::ReadFileToStringWithMaxSize(path, &bytes, 65536)) return base::DictValue();
  auto saved = base::JSONReader::ReadDict(bytes, base::JSON_PARSE_RFC);
  return saved ? std::move(*saved) : base::DictValue();
}
// All phone processes use the same lock file. The UI-side revision check is
// only an early error; the authoritative check and commit happen under flock.
int CommitConfig(base::FilePath path, int expected_revision, std::string bytes) {
  base::ScopedFD lock(open(path.AddExtensionASCII("lock").value().c_str(),
                           O_CREAT | O_RDWR | O_CLOEXEC, 0600));
  if (!lock.is_valid() || flock(lock.get(), LOCK_EX) != 0) return 2;
  int current_revision = 0;
  if (base::PathExists(path)) {
    std::string current;
    if (base::ReadFileToStringWithMaxSize(path, &current, 65536)) {
      auto saved = base::JSONReader::ReadDict(current, base::JSON_PARSE_RFC);
      if (saved) current_revision = std::max(0, saved->FindInt("revision").value_or(0));
    }
  }
  if (current_revision != expected_revision) return 1;
  return base::ImportantFileWriter::WriteFileAtomically(path, bytes) ? 0 : 2;
}
std::string Source(Profile* profile) {
  const auto* pref = profile->GetPrefs()->FindPreference(proxy_config::prefs::kProxy);
  if (pref && pref->IsManaged()) return "policy";
  if (pref && pref->IsExtensionControlled()) return "extension";
  const auto* cmd = base::CommandLine::ForCurrentProcess();
  for (const auto* flag : {"proxy-server", "no-proxy-server", "proxy-pac-url", "proxy-auto-detect"})
    if (cmd->HasSwitch(flag)) return "commandLine";
  if (pref && !pref->IsUserModifiable()) return "policy";
  return "user";
}
bool Controlled(Profile* profile) { return Source(profile) != "user"; }

class ProxyTest : public net::NetworkChangeNotifier::NetworkChangeObserver {
 public:
  ProxyTest(ShellCommandContext context, int request_id)
      : context_(context), request_id_(request_id),
        browser_(context.browser ? context.browser->GetWeakPtr() : base::WeakPtr<BrowserWindowInterface>()) {
    net::NetworkChangeNotifier::AddNetworkChangeObserver(this);
  }
  ~ProxyTest() override { net::NetworkChangeNotifier::RemoveNetworkChangeObserver(this); }
  void OnNetworkChanged(net::NetworkChangeNotifier::ConnectionType) override {
    if (!finished_) { Finish("networkChanged", 0); return; }
    base::DictValue event;
    event.Set("event", "proxyTestInvalidated");
    if (browser_) ReplyToShell(context_,std::move(event));
  }
  void Start(const base::DictValue& config, const std::optional<ShellProxySecret>& secret) {
    auto params = g_browser_process->system_network_context_manager()->CreateDefaultNetworkContextParams();
    params->http_cache_enabled = false;
    params->initial_proxy_config = NetworkConfig(config, true);
    params->shell_proxy_protection = true;
    if (secret) {
      params->shell_proxy_scheme = String(config, "scheme");
      params->shell_proxy_host = String(config, "host");
      params->shell_proxy_port = config.FindInt("port").value();
      params->shell_proxy_username = secret->username;
      params->shell_proxy_password = secret->password;
    }
    content::CreateNetworkContextInNetworkService(network_.BindNewPipeAndPassReceiver(), std::move(params));
    network_.set_disconnect_handler(base::BindOnce(&ProxyTest::Finish, weak_.GetWeakPtr(), "networkServiceUnavailable", 0));
    auto factory_params = network::mojom::URLLoaderFactoryParams::New();
    factory_params->process_id = network::OriginatingProcessId::browser();
    network_->CreateURLLoaderFactory(factory_.BindNewPipeAndPassReceiver(), std::move(factory_params));
    auto request = std::make_unique<network::ResourceRequest>();
    request->url = GURL(kTestUrl);
    request->credentials_mode = network::mojom::CredentialsMode::kOmit;
    // Proxy credentials remain available; cookies and origin credentials do not.
    request->load_flags = net::LOAD_DISABLE_CACHE;
    request->redirect_mode = network::mojom::RedirectMode::kError;
    loader_ = network::SimpleURLLoader::Create(std::move(request), kProxyAnnotation);
    loader_->SetTimeoutDuration(base::Seconds(15));
    started_ = base::TimeTicks::Now();
    loader_->DownloadHeadersOnly(factory_.get(), base::BindOnce(&ProxyTest::Complete, weak_.GetWeakPtr()));
  }
  void Cancel() { Finish("cancelled", 0); }
  gfx::AcceleratedWidget widget() const { return context_.widget; }
 private:
  void Complete(scoped_refptr<net::HttpResponseHeaders> headers) {
    const int error = loader_->NetError();
    std::string status = "targetFailed";
    const int response = headers ? headers->response_code() : 0;
    if (error == net::OK && response >= 200 && response < 300) status = "passed";
    else if (error == net::ERR_INVALID_AUTH_CREDENTIALS || error == net::ERR_PROXY_AUTH_REQUESTED || response == 407) status = "authenticationFailed";
    else if (net::IsCertificateError(error) || error == net::ERR_PROXY_CERTIFICATE_INVALID) status = "certificateFailed";
    else if (error == net::ERR_TIMED_OUT) status = "timeout";
    else if (error == net::ERR_SOCKS_CONNECTION_FAILED || error == net::ERR_PROXY_AUTH_UNSUPPORTED) status = "handshakeFailed";
    else if (error == net::ERR_PROXY_CONNECTION_FAILED || error == net::ERR_NAME_NOT_RESOLVED || error == net::ERR_CONNECTION_REFUSED) status = "unreachable";
    Finish(status, response);
  }
  void Finish(const std::string& status, int response) {
    if (finished_) return;
    finished_ = true;
    base::DictValue event;
    event.Set("event", "proxyTestResult"); event.Set("requestId", request_id_);
    event.Set("status", status); event.Set("httpStatus", response);
    event.Set("elapsedMs", (base::TimeTicks::Now() - started_).InMillisecondsF());
    event.Set("testUrl", kTestUrl);
    if (browser_) ReplyToShell(context_, std::move(event));
    loader_.reset(); factory_.reset(); network_.reset();
  }
  ShellCommandContext context_;
  int request_id_;
  base::WeakPtr<BrowserWindowInterface> browser_;
  bool finished_ = false;
  base::TimeTicks started_;
  mojo::Remote<network::mojom::NetworkContext> network_;
  mojo::Remote<network::mojom::URLLoaderFactory> factory_;
  std::unique_ptr<network::SimpleURLLoader> loader_;
  base::WeakPtrFactory<ProxyTest> weak_{this};
};

void Broadcast(Profile* profile);
class ProxyState : public base::SupportsUserData::Data, public ProfileObserver {
 public:
  explicit ProxyState(Profile* profile) : profile_(profile) { profile_->AddObserver(this); }
  ~ProxyState() override { if (profile_) profile_->RemoveObserver(this); }
  void Watch() {
    registrar_.Init(profile_->GetPrefs());
    registrar_.Add(proxy_config::prefs::kProxy, base::BindRepeating(
        [](base::WeakPtr<ProxyState> state) {
          if (state && state->profile_) Broadcast(state->profile_);
        }, weak.GetWeakPtr()));
  }
  void OnProfileWillBeDestroyed(Profile* profile) override {
    registrar_.RemoveAll(); test.reset(); weak.InvalidateWeakPtrs();
    profile->RemoveObserver(this); profile_ = nullptr;
  }
  raw_ptr<Profile> profile_;
  PrefChangeRegistrar registrar_;
  base::DictValue effective;
  std::optional<ShellProxySecret> effective_secret;
  std::set<std::string> cleaned_refs;
  bool invalid = false;
  bool saving = false;
  std::unique_ptr<ProxyTest> test;
  base::WeakPtrFactory<ProxyState> weak{this};
};
ProxyState* State(Profile* profile) {
  InitializeShellProxy(profile);
  return static_cast<ProxyState*>(profile->GetOriginalProfile()->GetUserData(&kStateKey));
}
base::DictValue PublicConfig(const base::DictValue& config) {
  // A damaged file must still leave the settings editor usable. The snapshot
  // reports blocked separately; defaults here are an editable recovery draft,
  // never the network configuration.
  auto result = Validate(config) ? config.Clone() : DefaultConfig();
  result.Set("revision", std::max(0, config.FindInt("revision").value_or(0)));
  result.Set("hasCredentials", !String(config, "credentialRef").empty());
  result.Remove("credentialRef");
  result.Remove("_retired");
  return result;
}
base::DictValue Snapshot(Profile* profile) {
  auto* state = State(profile);
  const auto desired = Desired(profile);
  auto result = base::DictValue();
  result.Set("desired", PublicConfig(desired));
  result.Set("effective", PublicConfig(state->effective));
  result.Set("revision", std::max(0, desired.FindInt("revision").value_or(0)));
  result.Set("effectiveRevision", std::max(0, state->effective.FindInt("revision").value_or(0)));
  result.Set("restartRequired", desired != state->effective);
  auto source = Source(profile);
  if (source == "user" && String(state->effective, "mode") == "system") source = "system";
  result.Set("source", source);
  result.Set("controlled", Controlled(profile));
  result.Set("status", state->invalid ? "blocked" : "ready");
  result.Set("effectiveBlocked", state->invalid);
  result.Set("proxyApiVersion", 1);
  result.Set("httpAuth", true); result.Set("socks5Auth", true);
  result.Set("testUrl", kTestUrl);
  return result;
}
void Reply(const ShellCommandContext& context, const base::DictValue& command,
           const char* event_name, const std::string& status) {
  auto event = Snapshot(settings_internal::SettingsProfile(context));
  event.Set("event", event_name); event.Set("requestId", ReadRequestId(command));
  if (!status.empty()) event.Set("status", status);
  ReplyToShell(context, std::move(event));
}
void Broadcast(Profile* profile) {
  auto event = Snapshot(profile);
  event.Set("event", "proxySettingsChanged");
  BroadcastToShell(profile, event.Clone());
  for (auto* otr : profile->GetAllOffTheRecordProfiles()) BroadcastToShell(otr, event.Clone());
}
bool SameEndpoint(const base::DictValue& a, const base::DictValue& b) {
  return String(a,"mode") == "custom" && String(b,"mode") == "custom" &&
      String(a,"scheme") == String(b,"scheme") && String(a,"host") == String(b,"host") &&
      a.FindInt("port") == b.FindInt("port");
}
std::optional<ShellProxySecret> ReadSecret(const base::DictValue& command) {
  ShellProxySecret secret{String(command,"proxyUsername"), String(command,"proxyPassword")};
  if (secret.username.empty() || secret.password.empty() || secret.username.size() > 255 ||
      secret.password.size() > 255 || !base::IsStringUTF8(secret.username) || !base::IsStringUTF8(secret.password)) return std::nullopt;
  return secret;
}
}

void RegisterShellProxyPrefs(PrefRegistrySimple* registry) {
  registry->RegisterDictionaryPref(kDesired);
  registry->RegisterListPref(kRetired);
}
void InitializeShellProxy(Profile* profile) {
  profile = profile->GetOriginalProfile();
  if (profile->GetUserData(&kStateKey)) return;
  auto state = std::make_unique<ProxyState>(profile);
  state->effective = Desired(profile);
  state->invalid = !Validate(state->effective).has_value();
  const auto credential_ref = String(state->effective, "credentialRef");
  if (!state->invalid && String(state->effective, "mode") == "custom" && !credential_ref.empty()) {
    state->effective_secret = LoadShellProxySecret(credential_ref);
    state->invalid = !state->effective_secret.has_value();
  }
  const auto config = state->effective.Clone();
  const bool invalid = state->invalid;
  profile->SetUserData(&kStateKey, std::move(state));
  auto* prefs = profile->GetPrefs();
  if (invalid) {
    prefs->SetDict(proxy_config::prefs::kProxy,
                  ProxyConfigDictionary::CreateFixedServers("http://127.0.0.1:9", "<-loopback>"));
  } else if (String(config,"mode") == "system") {
    prefs->ClearPref(proxy_config::prefs::kProxy);
  } else if (String(config,"mode") == "direct") {
    prefs->SetDict(proxy_config::prefs::kProxy, ProxyConfigDictionary::CreateDirect());
  } else {
    prefs->SetDict(proxy_config::prefs::kProxy,
                  ProxyConfigDictionary::CreateFixedServers(Server(config), Bypass(config)));
  }
  State(profile)->Watch();
  // References retired by a committed save can be removed after restart.
  if (const auto* retired = config.FindList("_retired")) {
    for (const auto& ref : *retired) {
      if (ref.is_string() && ref.GetString() != String(config,"credentialRef")) {
        RemoveShellProxySecret(ref.GetString());
        State(profile)->cleaned_refs.insert(ref.GetString());
      }
    }
  }
}
bool ShellProxyProtectsTraffic(Profile* profile) {
  auto* state = State(profile);
  return state->invalid || String(state->effective,"mode") == "custom";
}
void ConfigureShellProxyNetworkContext(Profile* profile, network::mojom::NetworkContextParams* params) {
  auto* state = State(profile);
  params->shell_proxy_protection = ShellProxyProtectsTraffic(profile);
  if (Controlled(profile)) return;
  const auto& config = state->effective;
  if (state->invalid) {
    params->initial_proxy_config = BlockedConfig();
    params->proxy_config_client_receiver.reset();
    return;
  }
  const auto ref = String(config,"credentialRef");
  if (String(config,"mode") != "custom" || ref.empty()) return;
  // Freeze the effective secret with the effective configuration. A second
  // phone process may retire the disk asset after its own restart; existing
  // profiles must still be able to recreate their network contexts.
  const auto& secret = state->effective_secret;
  if (!secret) {
    // Device locked / secure store unavailable: never start unauthenticated or
    // direct. A restart after unlocking is required, and the UI reports blocked.
    state->invalid = true;
    params->initial_proxy_config = BlockedConfig();
    params->proxy_config_client_receiver.reset();
    return;
  }
  params->shell_proxy_scheme = String(config,"scheme");
  params->shell_proxy_host = String(config,"host");
  params->shell_proxy_port = config.FindInt("port").value_or(0);
  params->shell_proxy_username = secret->username;
  params->shell_proxy_password = secret->password;
}
namespace settings_internal {
void GetProxySettings(const ShellCommandContext& context, const base::DictValue& command) {
  if (!SettingsProfile(context)) return;
  Reply(context, command, "proxySettings", "");
}
void ApplyProxySettings(const ShellCommandContext& context, const base::DictValue& command) {
  auto* profile = SettingsProfile(context);
  if (!profile) return;
  auto* state = State(profile);
  const auto saved = Desired(profile);
  std::string error;
  const auto* input = command.FindDict("proxyConfig");
  auto config = input ? Validate(*input) : std::nullopt;
  if (Controlled(profile)) error = "controlled";
  else if (state->saving) error = "busy";
  else if (command.FindInt("expectedRevision") != std::max(0, saved.FindInt("revision").value_or(0))) error = "conflict";
  else if (!config) error = "invalidConfig";
  if (!error.empty()) { Reply(context, command, "proxyApplyResult", error); return; }
  std::string new_ref;
  const auto action = String(command,"credentialAction");
  if (String(*config,"mode") == "custom") {
    if (action == "keep") {
      if (!SameEndpoint(saved, *config)) { Reply(context,command,"proxyApplyResult","credentialsRequired"); return; }
      config->Set("credentialRef", String(saved,"credentialRef"));
    } else if (action == "replace") {
      const auto secret = ReadSecret(command);
      if (!secret) { Reply(context,command,"proxyApplyResult","invalidCredentials"); return; }
      const auto ref = StoreShellProxySecret(*secret);
      if (!ref) { Reply(context,command,"proxyApplyResult","secureStorageFailed"); return; }
      new_ref = *ref;
      config->Set("credentialRef", new_ref);
    } else if (action != "remove") { Reply(context,command,"proxyApplyResult","invalidCredentials"); return; }
  }
  const int revision = std::max(0, saved.FindInt("revision").value_or(0));
  if (revision >= 2147483646) { RemoveShellProxySecret(new_ref); Reply(context,command,"proxyApplyResult","revisionExhausted"); return; }
  config->Set("revision", revision + 1);
  state->saving = true;
  const auto old_ref = String(saved,"credentialRef");
  base::ListValue retired;
  std::set<std::string> retired_refs;
  if (const auto* previous = saved.FindList("_retired")) {
    for (const auto& ref : *previous) {
      if (ref.is_string() && !state->cleaned_refs.contains(ref.GetString()))
        retired_refs.insert(ref.GetString());
    }
  }
  // Preserve intermediate saves too, so replacing a draft several times
  // before restart cannot orphan secure assets.
  retired_refs.insert(String(state->effective,"credentialRef"));
  retired_refs.insert(old_ref);
  retired_refs.erase("");
  retired_refs.erase(String(*config,"credentialRef"));
  for (const auto& ref : retired_refs) retired.Append(ref);
  config->Set("_retired",std::move(retired));
  std::string bytes;
  if (!base::JSONWriter::Write(*config, &bytes) || bytes.size() > 65536) {
    state->saving = false; RemoveShellProxySecret(new_ref);
    Reply(context,command,"proxyApplyResult","storageFailed"); return;
  }
  base::ThreadPool::PostTaskAndReplyWithResult(
      FROM_HERE, {base::MayBlock(), base::TaskPriority::USER_BLOCKING,
                  base::TaskShutdownBehavior::BLOCK_SHUTDOWN},
      base::BindOnce(&CommitConfig, SharedConfigPath(profile), revision, std::move(bytes)),
      base::BindOnce([](base::WeakPtr<ProxyState> state,
                        ShellCommandContext context, int id,
                        base::WeakPtr<BrowserWindowInterface> browser,
                        std::string new_ref, int result) {
        if (result != 0) RemoveShellProxySecret(new_ref);
        if (!state) return;
        state->saving = false;
        base::DictValue request; request.Set("requestId",id);
        if (browser) Reply(context,request,"proxyApplyResult", result == 0 ? "savedRestartRequired" :
                          result == 1 ? "conflict" : "storageFailed");
        if (result == 0) Broadcast(state->profile_);
      },state->weak.GetWeakPtr(),context,ReadRequestId(command),
        context.browser ? context.browser->GetWeakPtr() : base::WeakPtr<BrowserWindowInterface>(),new_ref));
}
void TestProxySettings(const ShellCommandContext& context, const base::DictValue& command) {
  auto* profile = SettingsProfile(context);
  if (!profile) return;
  auto* state = State(profile);
  const auto* input = command.FindDict("proxyConfig");
  auto config = input ? Validate(*input) : std::nullopt;
  if (Controlled(profile) || !config || String(*config,"mode") != "custom") {
    Reply(context,command,"proxyTestResult", Controlled(profile) ? "controlled" : "invalidConfig"); return;
  }
  std::optional<ShellProxySecret> secret;
  const auto action = String(command,"credentialAction");
  if (action == "keep") {
    const auto saved = Desired(profile);
    if (!SameEndpoint(saved,*config)) { Reply(context,command,"proxyTestResult","credentialsRequired"); return; }
    const auto ref = String(saved,"credentialRef");
    if (!ref.empty()) {
      secret = LoadShellProxySecret(ref);
      if (!secret) { Reply(context,command,"proxyTestResult","secureStorageFailed"); return; }
    }
  } else if (action == "replace") {
    secret = ReadSecret(command);
    if (!secret) { Reply(context,command,"proxyTestResult","invalidCredentials"); return; }
  } else if (action != "remove") { Reply(context,command,"proxyTestResult","invalidCredentials"); return; }
  if (state->test) state->test->Cancel();
  state->test = std::make_unique<ProxyTest>(context, ReadRequestId(command));
  state->test->Start(*config, secret);
}
void CancelProxyTest(const ShellCommandContext& context, const base::DictValue&) {
  if (auto* profile = SettingsProfile(context)) {
    auto* state = State(profile);
    if (state->test && state->test->widget() == context.widget) {
      state->test->Cancel(); state->test.reset();
    }
  }
}
}
}
