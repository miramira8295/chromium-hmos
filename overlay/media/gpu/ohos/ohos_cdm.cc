// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/gpu/ohos/ohos_cdm.h"

#include <multimedia/drm_framework/native_drm_err.h>
#include <multimedia/drm_framework/native_mediakeysession.h>
#include <multimedia/drm_framework/native_mediakeysystem.h>

#include <algorithm>
#include <array>
#include <utility>

#include "base/compiler_specific.h"
#include "base/containers/flat_map.h"
#include "base/containers/span.h"
#include "base/functional/bind.h"
#include "base/location.h"
#include "base/logging.h"
#include "base/memory/ref_counted.h"
#include "base/no_destructor.h"
#include "base/numerics/byte_conversions.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/string_util.h"
#include "base/synchronization/lock.h"
#include "base/thread_annotations.h"
#include "base/time/time.h"
#include "url/gurl.h"

namespace media {

namespace {

// DRM Kit's buffer sizes for requests it writes (native_drm_common.h gives
// none for these two; ArkWeb uses the same values).
constexpr int32_t kMaxProvisionRequestLength = 12288;
constexpr int32_t kMaxProvisionUrlLength = 2048;
// Large enough for any offline media key ID DRM Kit hands back.
constexpr int32_t kMaxMediaKeyIdLength = 128;

// The MIME type DRM Kit is told the init data comes from. 'cenc' init data
// is PSSH boxes from an MP4 container; MediaDrmBridge says the same to
// MediaDrm.
constexpr char kCencInitDataMimeType[] = "video/mp4";

// DRM Kit's configuration name for a server certificate (ArkWeb's
// SERVER_CERTIFICATE).
constexpr char kServerCertificateConfig[] = "serviceCertificate";

// The PSSH system ID WisePlay licenses are requested with.
constexpr std::array<uint8_t, 16> kWisePlaySystemId = {
    0x3d, 0x5e, 0x6d, 0x35, 0x9b, 0x9a, 0x41, 0xe8,
    0xb8, 0x43, 0xdd, 0x3c, 0x6e, 0x72, 0xc4, 0x2c};

const char* CertificateStatusName(DRM_CertificateStatus status) {
  switch (status) {
    case CERT_STATUS_PROVISIONED:
      return "provisioned";
    case CERT_STATUS_NOT_PROVISIONED:
      return "not provisioned";
    case CERT_STATUS_EXPIRED:
      return "expired";
    case CERT_STATUS_INVALID:
      return "invalid";
    case CERT_STATUS_UNAVAILABLE:
      return "unavailable";
  }
  return "unknown";
}

CdmMessageType ToCdmMessageType(DRM_MediaKeyRequestType type) {
  switch (type) {
    case MEDIA_KEY_REQUEST_TYPE_RENEWAL:
    case MEDIA_KEY_REQUEST_TYPE_UPDATE:
      return CdmMessageType::LICENSE_RENEWAL;
    case MEDIA_KEY_REQUEST_TYPE_RELEASE:
      return CdmMessageType::LICENSE_RELEASE;
    case MEDIA_KEY_REQUEST_TYPE_UNKNOWN:
    case MEDIA_KEY_REQUEST_TYPE_INITIAL:
    case MEDIA_KEY_REQUEST_TYPE_NONE:
      return CdmMessageType::LICENSE_REQUEST;
  }
  return CdmMessageType::LICENSE_REQUEST;
}

// DRM Kit names key statuses as strings (ArkWeb's KeyStatusMap).
CdmKeyInformation::KeyStatus ToKeyStatus(std::string_view status) {
  if (status == "USABLE") {
    return CdmKeyInformation::USABLE;
  }
  if (status == "EXPIRED") {
    return CdmKeyInformation::EXPIRED;
  }
  if (status == "OUTPUT_NOT_ALLOWED") {
    return CdmKeyInformation::OUTPUT_RESTRICTED;
  }
  if (status == "PENDING") {
    return CdmKeyInformation::KEY_STATUS_PENDING;
  }
  if (status == "USABLE_IN_FUTURE") {
    return CdmKeyInformation::USABLE_IN_FUTURE;
  }
  return CdmKeyInformation::INTERNAL_ERROR;
}

// The PSSH boxes DRM Kit is given. It takes at most MAX_INIT_DATA_LEN bytes,
// and init data carrying boxes for every DRM a stream supports can be
// longer; then only WisePlay's boxes are passed on. Empty if they do not fit
// either.
std::vector<uint8_t> InitDataForDrmKit(base::span<const uint8_t> init_data) {
  if (init_data.size() <= MAX_INIT_DATA_LEN) {
    return std::vector<uint8_t>(init_data.begin(), init_data.end());
  }
  std::vector<uint8_t> result;
  // A full box header: size, 'pssh', version and flags, system ID.
  constexpr size_t kHeaderSize = 4 + 4 + 4 + 16;
  while (init_data.size() >= kHeaderSize) {
    const uint32_t box_size =
        base::U32FromBigEndian(init_data.first<4u>());
    if (box_size < kHeaderSize || box_size > init_data.size()) {
      break;
    }
    const auto box = init_data.first(box_size);
    const auto type = box.subspan(4u, 4u);
    const auto system_id = box.subspan(12u, 16u);
    if (std::ranges::equal(type, base::byte_span_from_cstring("pssh")) &&
        std::ranges::equal(system_id, kWisePlaySystemId)) {
      result.insert(result.end(), box.begin(), box.end());
    }
    init_data = init_data.subspan(box_size);
  }
  if (result.size() > MAX_INIT_DATA_LEN) {
    result.clear();
  }
  return result;
}

}  // namespace

namespace {

// Routes DRM Kit's callbacks, which carry only the key system or session
// pointer, to the CDM that owns that pointer.
struct DrmEventRelay : public base::RefCountedThreadSafe<DrmEventRelay> {
  DrmEventRelay(scoped_refptr<base::SequencedTaskRunner> task_runner,
                base::WeakPtr<OhosCdm> cdm)
      : task_runner(std::move(task_runner)), cdm(std::move(cdm)) {}

  const scoped_refptr<base::SequencedTaskRunner> task_runner;
  // Only dereferenced on `task_runner`.
  const base::WeakPtr<OhosCdm> cdm;

 private:
  friend class base::RefCountedThreadSafe<DrmEventRelay>;
  ~DrmEventRelay() = default;
};

class RelayRegistry {
 public:
  static RelayRegistry& Get() {
    static base::NoDestructor<RelayRegistry> registry;
    return *registry;
  }

  void Add(const void* drm_object, scoped_refptr<DrmEventRelay> relay) {
    base::AutoLock lock(lock_);
    relays_[drm_object] = std::move(relay);
  }

  void Remove(const void* drm_object) {
    base::AutoLock lock(lock_);
    relays_.erase(drm_object);
  }

  scoped_refptr<DrmEventRelay> Find(const void* drm_object) {
    base::AutoLock lock(lock_);
    auto it = relays_.find(drm_object);
    return it == relays_.end() ? nullptr : it->second;
  }

 private:
  base::Lock lock_;
  base::flat_map<const void*, scoped_refptr<DrmEventRelay>> relays_
      GUARDED_BY(lock_);
};

}  // namespace

// static
bool OhosCdm::IsKeySystemSupported(const std::string& key_system) {
  return key_system == kOhosWisePlayKeySystem &&
         OH_MediaKeySystem_IsSupported(key_system.c_str());
}

// static
void OhosCdm::Create(const CdmConfig& cdm_config,
                     CreateFetcherCB create_fetcher_cb,
                     const SessionMessageCB& session_message_cb,
                     const SessionClosedCB& session_closed_cb,
                     const SessionKeysChangeCB& session_keys_change_cb,
                     const SessionExpirationUpdateCB& session_expiration_cb,
                     CreatedCB created_cb) {
  if (cdm_config.use_hw_secure_codecs) {
    // Hardware security needs DRM Kit's secure video path, which renders
    // past the GPU; this CDM only does software crypto so far.
    std::move(created_cb).Run(nullptr, "Hardware secure codecs unsupported");
    return;
  }
  if (!IsKeySystemSupported(cdm_config.key_system)) {
    std::move(created_cb).Run(nullptr, "Key system unsupported");
    return;
  }
  scoped_refptr<OhosCdm> cdm = base::AdoptRef(new OhosCdm(
      cdm_config, std::move(create_fetcher_cb), session_message_cb,
      session_closed_cb, session_keys_change_cb, session_expiration_cb));
  cdm->Initialize(std::move(created_cb));
}

OhosCdm::OhosCdm(const CdmConfig& cdm_config,
                 CreateFetcherCB create_fetcher_cb,
                 const SessionMessageCB& session_message_cb,
                 const SessionClosedCB& session_closed_cb,
                 const SessionKeysChangeCB& session_keys_change_cb,
                 const SessionExpirationUpdateCB& session_expiration_cb)
    : task_runner_(base::SequencedTaskRunner::GetCurrentDefault()),
      cdm_config_(cdm_config),
      create_fetcher_cb_(std::move(create_fetcher_cb)),
      session_message_cb_(session_message_cb),
      session_closed_cb_(session_closed_cb),
      session_keys_change_cb_(session_keys_change_cb),
      session_expiration_cb_(session_expiration_cb) {}

OhosCdm::~OhosCdm() {
  DCHECK(task_runner_->RunsTasksInCurrentSequence());
  cdm_promise_adapter_.Clear(CdmPromiseAdapter::ClearReason::kDestruction);
  DestroyDrmObjects();
}

void OhosCdm::DeleteOnCorrectThread() const {
  if (!task_runner_->RunsTasksInCurrentSequence()) {
    // When DeleteSoon returns false, |this| leaks, which is okay.
    task_runner_->DeleteSoon(FROM_HERE, this);
  } else {
    delete this;
  }
}

void OhosCdm::Initialize(CreatedCB created_cb) {
  Drm_ErrCode result =
      OH_MediaKeySystem_Create(cdm_config_.key_system.c_str(), &system_);
  if (result != DRM_ERR_OK || !system_) {
    LOG(ERROR) << "OHOS CDM: OH_MediaKeySystem_Create failed: " << result;
    system_ = nullptr;
    std::move(created_cb).Run(nullptr, "Could not create the key system");
    return;
  }
  RelayRegistry::Get().Add(system_, base::MakeRefCounted<DrmEventRelay>(
                                        task_runner_,
                                        weak_factory_.GetWeakPtr()));
  OH_MediaKeySystem_SetCallback(system_, &OhosCdm::OnSystemEventThunk);

  DRM_CertificateStatus status = CERT_STATUS_UNAVAILABLE;
  result = OH_MediaKeySystem_GetCertificateStatus(system_, &status);
  LOG(WARNING) << "OHOS CDM: " << cdm_config_.key_system << " certificate "
               << (result == DRM_ERR_OK ? CertificateStatusName(status)
                                        : "status unknown");
  if (result == DRM_ERR_OK && status != CERT_STATUS_PROVISIONED) {
    Provision(std::move(created_cb));
    return;
  }
  CreateDrmSession(std::move(created_cb));
}

void OhosCdm::Provision(CreatedCB created_cb) {
  if (provisioning_) {
    // Only DRM Kit's own provision-required event gets here twice, and it
    // has no one waiting.
    return;
  }
  std::vector<uint8_t> request(kMaxProvisionRequestLength);
  int32_t request_length = kMaxProvisionRequestLength;
  std::array<char, kMaxProvisionUrlLength> url = {};
  Drm_ErrCode result = OH_MediaKeySystem_GenerateKeySystemRequest(
      system_, request.data(), &request_length, url.data(),
      static_cast<int32_t>(url.size() - 1));
  if (result != DRM_ERR_OK || request_length <= 0 ||
      request_length > kMaxProvisionRequestLength) {
    LOG(ERROR) << "OHOS CDM: no certificate request: " << result;
    if (created_cb) {
      std::move(created_cb).Run(nullptr, "Device certificate unavailable");
    }
    return;
  }
  const GURL default_url(std::string(url.data()));
  provision_fetcher_ = create_fetcher_cb_ ? create_fetcher_cb_.Run() : nullptr;
  if (!provision_fetcher_ || !default_url.is_valid()) {
    LOG(ERROR) << "OHOS CDM: cannot download a device certificate";
    if (created_cb) {
      std::move(created_cb).Run(nullptr, "Device certificate unavailable");
    }
    return;
  }
  provisioning_ = true;
  LOG(WARNING) << "OHOS CDM: downloading a device certificate from "
               << default_url.host();
  // Hold a reference: until `created_cb` runs, nothing else owns this CDM.
  provision_fetcher_->Retrieve(
      default_url,
      std::string(request.begin(), request.begin() + request_length),
      base::BindOnce(&OhosCdm::OnProvisionResponse, base::WrapRefCounted(this),
                     std::move(created_cb)));
}

void OhosCdm::OnProvisionResponse(CreatedCB created_cb,
                                  bool success,
                                  const std::string& response) {
  provisioning_ = false;
  provision_fetcher_.reset();
  Drm_ErrCode result = DRM_ERR_UNKNOWN;
  if (success && !response.empty()) {
    std::vector<uint8_t> bytes(response.begin(), response.end());
    result = OH_MediaKeySystem_ProcessKeySystemResponse(
        system_, bytes.data(), static_cast<int32_t>(bytes.size()));
  }
  LOG(WARNING) << "OHOS CDM: device certificate "
               << (result == DRM_ERR_OK ? "installed" : "download failed")
               << (success ? "" : " (no response)");
  if (!created_cb) {
    return;
  }
  if (result != DRM_ERR_OK) {
    std::move(created_cb).Run(nullptr, "Device certificate unavailable");
    return;
  }
  CreateDrmSession(std::move(created_cb));
}

void OhosCdm::CreateDrmSession(CreatedCB created_cb) {
  DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_SW_CRYPTO;
  Drm_ErrCode result =
      OH_MediaKeySystem_CreateMediaKeySession(system_, &level, &session_);
  if (result != DRM_ERR_OK || !session_) {
    LOG(ERROR) << "OHOS CDM: OH_MediaKeySystem_CreateMediaKeySession failed: "
               << result;
    session_ = nullptr;
    std::move(created_cb).Run(nullptr, "Could not create a DRM session");
    return;
  }
  RelayRegistry::Get().Add(session_, base::MakeRefCounted<DrmEventRelay>(
                                         task_runner_,
                                         weak_factory_.GetWeakPtr()));
  OH_MediaKeySession_Callback callback = {&OhosCdm::OnSessionEventThunk,
                                          &OhosCdm::OnKeysChangeThunk};
  OH_MediaKeySession_SetCallback(session_, &callback);
  LOG(WARNING) << "OHOS CDM: " << cdm_config_.key_system
               << " ready, protection level " << level;
  std::move(created_cb).Run(this, std::string());
}

void OhosCdm::DestroyDrmObjects() {
  // Unregister first so that no callback reaches a destroyed object.
  if (session_) {
    RelayRegistry::Get().Remove(session_);
    OH_MediaKeySession_Destroy(session_);
    session_ = nullptr;
  }
  if (system_) {
    RelayRegistry::Get().Remove(system_);
    OH_MediaKeySystem_Destroy(system_);
    system_ = nullptr;
  }
}

void OhosCdm::SetServerCertificate(const std::vector<uint8_t>& certificate,
                                   std::unique_ptr<SimpleCdmPromise> promise) {
  if (certificate.empty()) {
    promise->reject(CdmPromise::Exception::TYPE_ERROR, 0,
                    "Empty server certificate");
    return;
  }
  std::vector<uint8_t> bytes = certificate;
  if (!system_ || OH_MediaKeySystem_SetConfigurationByteArray(
                      system_, kServerCertificateConfig, bytes.data(),
                      static_cast<int32_t>(bytes.size())) != DRM_ERR_OK) {
    promise->reject(CdmPromise::Exception::NOT_SUPPORTED_ERROR, 0,
                    "Server certificate not accepted");
    return;
  }
  promise->resolve();
}

void OhosCdm::CreateSessionAndGenerateRequest(
    CdmSessionType session_type,
    EmeInitDataType init_data_type,
    const std::vector<uint8_t>& init_data,
    std::unique_ptr<NewSessionCdmPromise> promise) {
  DCHECK(task_runner_->RunsTasksInCurrentSequence());
  const uint32_t promise_id =
      cdm_promise_adapter_.SavePromise(std::move(promise), __func__);
  if (session_type != CdmSessionType::kTemporary) {
    cdm_promise_adapter_.RejectPromise(
        promise_id, CdmPromise::Exception::NOT_SUPPORTED_ERROR, 0,
        "Only temporary sessions are supported");
    return;
  }
  if (init_data_type != EmeInitDataType::CENC) {
    cdm_promise_adapter_.RejectPromise(
        promise_id, CdmPromise::Exception::NOT_SUPPORTED_ERROR, 0,
        "Only 'cenc' init data is supported");
    return;
  }
  if (!session_) {
    cdm_promise_adapter_.RejectPromise(
        promise_id, CdmPromise::Exception::INVALID_STATE_ERROR, 0,
        "The CDM has no DRM session");
    return;
  }
  const std::vector<uint8_t> drm_init_data = InitDataForDrmKit(init_data);
  if (drm_init_data.empty()) {
    cdm_promise_adapter_.RejectPromise(
        promise_id, CdmPromise::Exception::TYPE_ERROR, 0,
        "Init data has no usable PSSH box");
    return;
  }

  const std::string session_id = base::NumberToString(next_session_number_);
  session_order_[session_id] = next_session_number_++;
  // The promise resolves before the message is sent, as EME expects.
  cdm_promise_adapter_.ResolvePromise(promise_id, session_id);
  if (!SendKeyRequest(session_id, drm_init_data)) {
    // generateRequest() already resolved; the page sees a session that
    // never gets a message, so close it.
    session_order_.erase(session_id);
    session_closed_cb_.Run(session_id, CdmSessionClosedReason::kInternalError);
  }
}

bool OhosCdm::SendKeyRequest(const std::string& session_id,
                             const std::vector<uint8_t>& init_data) {
  // Both structs hold fixed arrays of several KB; keep them off the stack.
  auto info = std::make_unique<DRM_MediaKeyRequestInfo>();
  info->type = MEDIA_KEY_TYPE_ONLINE;
  info->initDataLen = static_cast<int32_t>(init_data.size());
  base::span(info->initData).copy_prefix_from(init_data);
  base::span(info->mimeType)
      .copy_prefix_from(base::span_from_cstring(kCencInitDataMimeType));
  info->optionsCount = 0;
  auto request = std::make_unique<DRM_MediaKeyRequest>();
  Drm_ErrCode result =
      OH_MediaKeySession_GenerateMediaKeyRequest(session_, info.get(),
                                                 request.get());
  if (result != DRM_ERR_OK || request->dataLen <= 0 ||
      request->dataLen > MAX_MEDIA_KEY_REQUEST_DATA_LEN) {
    LOG(ERROR) << "OHOS CDM: no license request for session " << session_id
               << ": " << result;
    return false;
  }
  const auto data = base::span(request->data)
                        .first(static_cast<size_t>(request->dataLen));
  session_message_cb_.Run(session_id, ToCdmMessageType(request->type),
                          std::vector<uint8_t>(data.begin(), data.end()));
  return true;
}

void OhosCdm::LoadSession(CdmSessionType session_type,
                          const std::string& session_id,
                          std::unique_ptr<NewSessionCdmPromise> promise) {
  promise->reject(CdmPromise::Exception::NOT_SUPPORTED_ERROR, 0,
                  "Persistent licenses are not supported");
}

void OhosCdm::UpdateSession(const std::string& session_id,
                            const std::vector<uint8_t>& response,
                            std::unique_ptr<SimpleCdmPromise> promise) {
  DCHECK(task_runner_->RunsTasksInCurrentSequence());
  if (!session_order_.contains(session_id) || !session_) {
    promise->reject(CdmPromise::Exception::INVALID_STATE_ERROR, 0,
                    "Session does not exist");
    return;
  }
  if (response.empty()) {
    promise->reject(CdmPromise::Exception::TYPE_ERROR, 0, "Empty response");
    return;
  }
  last_updated_session_ = session_id;
  const uint64_t update = ++update_count_;
  std::vector<uint8_t> bytes = response;
  std::array<uint8_t, kMaxMediaKeyIdLength> media_key_id = {};
  int32_t media_key_id_length = kMaxMediaKeyIdLength;
  Drm_ErrCode result = OH_MediaKeySession_ProcessMediaKeyResponse(
      session_, bytes.data(), static_cast<int32_t>(bytes.size()),
      media_key_id.data(), &media_key_id_length);
  if (result != DRM_ERR_OK) {
    LOG(ERROR) << "OHOS CDM: license rejected for session " << session_id
               << ": " << result;
    promise->reject(CdmPromise::Exception::NOT_SUPPORTED_ERROR, 0,
                    "License not accepted");
    return;
  }
  LOG(WARNING) << "OHOS CDM: license accepted for session " << session_id;
  promise->resolve();
  // DRM Kit reports the keys from its own thread, usually before the call
  // above returns; this runs after that report if there is one.
  task_runner_->PostTask(
      FROM_HERE, base::BindOnce(&OhosCdm::ReportKeysIfSilent,
                                weak_factory_.GetWeakPtr(), session_id, update));
}

void OhosCdm::ReportKeysIfSilent(const std::string& session_id,
                                 uint64_t update) {
  if (keys_reported_for_update_ >= update ||
      !session_order_.contains(session_id)) {
    return;
  }
  // The license went in, so its keys are usable, but DRM Kit has not said
  // which they are. Report that keys were added; decoders waiting for one go
  // ahead.
  session_keys_change_cb_.Run(session_id, /*has_additional_usable_key=*/true,
                              CdmKeysInfo());
  NotifyUsableKey();
}

void OhosCdm::CloseSession(const std::string& session_id,
                           std::unique_ptr<SimpleCdmPromise> promise) {
  if (!session_order_.erase(session_id)) {
    promise->reject(CdmPromise::Exception::INVALID_STATE_ERROR, 0,
                    "Session does not exist");
    return;
  }
  if (last_updated_session_ == session_id) {
    last_updated_session_.reset();
  }
  if (session_order_.empty() && session_) {
    // The last session's keys go with it. Every session shares the one DRM
    // Kit session, so keys are only dropped once none is left.
    OH_MediaKeySession_ClearMediaKeys(session_);
    has_usable_key_ = false;
  }
  promise->resolve();
  session_closed_cb_.Run(session_id, CdmSessionClosedReason::kClose);
}

void OhosCdm::RemoveSession(const std::string& session_id,
                            std::unique_ptr<SimpleCdmPromise> promise) {
  // As MediaDrmBridge: only persistent licenses can be removed, and there
  // are none yet.
  promise->reject(CdmPromise::Exception::NOT_SUPPORTED_ERROR, 0,
                  "Removing temporary sessions is not supported");
}

CdmContext* OhosCdm::GetCdmContext() {
  return this;
}

std::unique_ptr<CallbackRegistration> OhosCdm::RegisterEventCB(
    EventCB event_cb) {
  return event_callbacks_.Register(std::move(event_cb));
}

::MediaKeySession* OhosCdm::GetOhosMediaKeySession() {
  return session_;
}

bool OhosCdm::OhosHasUsableKey() {
  return has_usable_key_;
}

// static
Drm_ErrCode OhosCdm::OnSystemEventThunk(MediaKeySystem* system,
                                        DRM_EventType event,
                                        uint8_t* info,
                                        int32_t info_len,
                                        char* extra) {
  scoped_refptr<DrmEventRelay> relay = RelayRegistry::Get().Find(system);
  if (relay && event == EVENT_PROVISION_REQUIRED) {
    relay->task_runner->PostTask(
        FROM_HERE,
        base::BindOnce(&OhosCdm::Provision, relay->cdm, CreatedCB()));
  }
  return DRM_ERR_OK;
}

// static
Drm_ErrCode OhosCdm::OnSessionEventThunk(MediaKeySession* session,
                                         DRM_EventType event,
                                         uint8_t* info,
                                         int32_t info_len,
                                         char* extra) {
  scoped_refptr<DrmEventRelay> relay = RelayRegistry::Get().Find(session);
  if (!relay) {
    return DRM_ERR_OK;
  }
  std::vector<uint8_t> bytes;
  if (info && info_len > 0) {
    // SAFETY: DRM Kit passes `info_len` bytes at `info` for this call.
    auto data =
        UNSAFE_BUFFERS(base::span(info, static_cast<size_t>(info_len)));
    bytes.assign(data.begin(), data.end());
  }
  relay->task_runner->PostTask(
      FROM_HERE, base::BindOnce(&OhosCdm::OnSessionEvent, relay->cdm, event,
                                std::move(bytes)));
  return DRM_ERR_OK;
}

// static
Drm_ErrCode OhosCdm::OnKeysChangeThunk(MediaKeySession* session,
                                       DRM_KeysInfo* keys_info,
                                       bool new_keys_available) {
  scoped_refptr<DrmEventRelay> relay = RelayRegistry::Get().Find(session);
  if (!relay || !keys_info) {
    return DRM_ERR_OK;
  }
  // `keys_info` is only valid for this call.
  CdmKeysInfo keys;
  const uint32_t count = std::min<uint32_t>(keys_info->keysInfoCount,
                                            MAX_KEY_INFO_COUNT);
  for (uint32_t i = 0; i < count; ++i) {
    const auto status_chars = base::span(keys_info->statusValue[i]);
    const size_t status_length = static_cast<size_t>(
        std::ranges::find(status_chars, '\0') - status_chars.begin());
    keys.push_back(std::make_unique<CdmKeyInformation>(
        base::span<const uint8_t>(keys_info->keyId[i]),
        ToKeyStatus(std::string_view(status_chars.data(), status_length)),
        /*system_code=*/0));
  }
  relay->task_runner->PostTask(
      FROM_HERE, base::BindOnce(&OhosCdm::OnKeysChange, relay->cdm,
                                std::move(keys), new_keys_available));
  return DRM_ERR_OK;
}

std::optional<std::string> OhosCdm::CurrentSessionId() const {
  if (last_updated_session_) {
    return last_updated_session_;
  }
  if (session_order_.empty()) {
    return std::nullopt;
  }
  return std::ranges::max_element(session_order_, {},
                                  [](const auto& entry) {
                                    return entry.second;
                                  })
      ->first;
}

void OhosCdm::OnSessionEvent(DRM_EventType event, std::vector<uint8_t> info) {
  const std::optional<std::string> session_id = CurrentSessionId();
  switch (event) {
    case EVENT_KEY_REQUIRED:
      // License renewal: DRM Kit wants another request sent.
      if (session_id) {
        SendKeyRequest(*session_id, info);
      }
      return;
    case EVENT_EXPIRATION_UPDATE: {
      if (!session_id) {
        return;
      }
      // Milliseconds since the epoch as text, sometimes followed by "ms".
      std::string text(info.begin(), info.end());
      text = std::string(base::TrimString(text, std::string_view("\0", 1),
                                          base::TRIM_TRAILING));
      if (base::EndsWith(text, "ms")) {
        text.resize(text.size() - 2);
      }
      int64_t milliseconds = 0;
      if (!base::StringToInt64(text, &milliseconds) || milliseconds < 0) {
        return;
      }
      session_expiration_cb_.Run(
          *session_id, milliseconds
                           ? base::Time::FromMillisecondsSinceUnixEpoch(
                                 milliseconds)
                           : base::Time());
      return;
    }
    case EVENT_KEY_EXPIRED:
      LOG(WARNING) << "OHOS CDM: a key expired";
      return;
    default:
      return;
  }
}

void OhosCdm::OnKeysChange(CdmKeysInfo keys_info, bool new_keys_available) {
  const std::optional<std::string> session_id = CurrentSessionId();
  if (!session_id) {
    return;
  }
  keys_reported_for_update_ = update_count_;
  const bool any_usable =
      std::ranges::any_of(keys_info, [](const auto& key) {
        return key->status == CdmKeyInformation::USABLE;
      });
  LOG(WARNING) << "OHOS CDM: session " << *session_id << " has "
               << keys_info.size() << " key(s)"
               << (any_usable ? ", usable" : "");
  session_keys_change_cb_.Run(*session_id,
                              new_keys_available || any_usable,
                              std::move(keys_info));
  if (new_keys_available || any_usable) {
    NotifyUsableKey();
  }
}

void OhosCdm::NotifyUsableKey() {
  has_usable_key_ = true;
  event_callbacks_.Notify(Event::kHasAdditionalUsableKey);
}

}  // namespace media
