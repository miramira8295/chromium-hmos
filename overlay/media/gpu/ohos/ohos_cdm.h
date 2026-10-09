// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_GPU_OHOS_OHOS_CDM_H_
#define MEDIA_GPU_OHOS_OHOS_CDM_H_

#include <multimedia/drm_framework/native_drm_common.h>
#include <multimedia/drm_framework/native_drm_err.h>
#include <stdint.h>

#include <atomic>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "base/functional/callback.h"
#include "base/memory/raw_ptr_exclusion.h"
#include "base/memory/scoped_refptr.h"
#include "base/memory/weak_ptr.h"
#include "base/task/sequenced_task_runner.h"
#include "media/base/callback_registry.h"
#include "media/base/cdm_config.h"
#include "media/base/cdm_context.h"
#include "media/base/cdm_key_information.h"
#include "media/base/cdm_promise_adapter.h"
#include "media/base/content_decryption_module.h"
#include "media/base/provision_fetcher.h"
#include "media/gpu/media_gpu_export.h"

namespace media {

// The EME key systems DRM Kit serves, and the PSSH system ID of each.
inline constexpr char kOhosWisePlayKeySystem[] = "com.wiseplay.drm";

// An EME CDM backed by HarmonyOS DRM Kit, modeled on Android's
// MediaDrmBridge. It lives in the GPU process's media service next to the
// AVCodecKit decoders, which decrypt and decode in one step: they take the
// DRM Kit session from GetOhosMediaKeySession() and per-sample CENC data from
// each DecoderBuffer, so there is no Decryptor.
//
// DRM Kit decrypts with one MediaKeySession per decoder, so every EME session
// of this CDM shares one DRM Kit session, as ArkWeb does for WisePlay and as
// MediaDrmBridge shares one MediaCrypto. Temporary sessions only for now.
class MEDIA_GPU_EXPORT OhosCdm final : public ContentDecryptionModule,
                                       public CdmContext {
 public:
  using CreatedCB =
      base::OnceCallback<void(scoped_refptr<OhosCdm> cdm,
                              const std::string& error_message)>;

  // Whether DRM Kit on this device serves `key_system`.
  static bool IsKeySystemSupported(const std::string& key_system);

  // Creates the DRM Kit key system and, once the device certificate is in
  // place -- downloading one through `create_fetcher_cb` if needed -- its
  // session. Runs `created_cb` on the calling sequence.
  static void Create(const CdmConfig& cdm_config,
                     CreateFetcherCB create_fetcher_cb,
                     const SessionMessageCB& session_message_cb,
                     const SessionClosedCB& session_closed_cb,
                     const SessionKeysChangeCB& session_keys_change_cb,
                     const SessionExpirationUpdateCB& session_expiration_cb,
                     CreatedCB created_cb);

  OhosCdm(const OhosCdm&) = delete;
  OhosCdm& operator=(const OhosCdm&) = delete;

  // ContentDecryptionModule implementation.
  void SetServerCertificate(const std::vector<uint8_t>& certificate,
                            std::unique_ptr<SimpleCdmPromise> promise) override;
  void CreateSessionAndGenerateRequest(
      CdmSessionType session_type,
      EmeInitDataType init_data_type,
      const std::vector<uint8_t>& init_data,
      std::unique_ptr<NewSessionCdmPromise> promise) override;
  void LoadSession(CdmSessionType session_type,
                   const std::string& session_id,
                   std::unique_ptr<NewSessionCdmPromise> promise) override;
  void UpdateSession(const std::string& session_id,
                     const std::vector<uint8_t>& response,
                     std::unique_ptr<SimpleCdmPromise> promise) override;
  void CloseSession(const std::string& session_id,
                    std::unique_ptr<SimpleCdmPromise> promise) override;
  void RemoveSession(const std::string& session_id,
                     std::unique_ptr<SimpleCdmPromise> promise) override;
  CdmContext* GetCdmContext() override;
  void DeleteOnCorrectThread() const override;

  // CdmContext implementation.
  std::unique_ptr<CallbackRegistration> RegisterEventCB(
      EventCB event_cb) override;
  ::MediaKeySession* GetOhosMediaKeySession() override;
  bool OhosHasUsableKey() override;

 private:
  // DeleteOnCorrectThread() may hand the CDM to DeleteSoon().
  friend class base::DeleteHelper<OhosCdm>;

  OhosCdm(const CdmConfig& cdm_config,
          CreateFetcherCB create_fetcher_cb,
          const SessionMessageCB& session_message_cb,
          const SessionClosedCB& session_closed_cb,
          const SessionKeysChangeCB& session_keys_change_cb,
          const SessionExpirationUpdateCB& session_expiration_cb);
  ~OhosCdm() override;

  // DRM Kit calls these on its own threads with no user data; they find the
  // CDM through the key system or session pointer and post to it.
  static Drm_ErrCode OnSystemEventThunk(MediaKeySystem* system,
                                        DRM_EventType event,
                                        uint8_t* info,
                                        int32_t info_len,
                                        char* extra);
  static Drm_ErrCode OnSessionEventThunk(MediaKeySession* session,
                                         DRM_EventType event,
                                         uint8_t* info,
                                         int32_t info_len,
                                         char* extra);
  static Drm_ErrCode OnKeysChangeThunk(MediaKeySession* session,
                                       DRM_KeysInfo* keys_info,
                                       bool new_keys_available);

  // Creation, in order.
  void Initialize(CreatedCB created_cb);
  void Provision(CreatedCB created_cb);
  void OnProvisionResponse(CreatedCB created_cb,
                           bool success,
                           const std::string& response);
  void CreateDrmSession(CreatedCB created_cb);

  void OnSessionEvent(DRM_EventType event, std::vector<uint8_t> info);
  void OnKeysChange(CdmKeysInfo keys_info, bool new_keys_available);
  void ReportKeysIfSilent(const std::string& session_id, uint64_t update);
  // Asks DRM Kit for a license request and sends it to the page as
  // `session_id`'s message; false if DRM Kit has none.
  bool SendKeyRequest(const std::string& session_id,
                      const std::vector<uint8_t>& init_data);

  // The EME session that DRM Kit's session events and key changes belong
  // to: the one last updated, else the newest.
  std::optional<std::string> CurrentSessionId() const;
  void NotifyUsableKey();
  void DestroyDrmObjects();

  const scoped_refptr<base::SequencedTaskRunner> task_runner_;
  const CdmConfig cdm_config_;
  const CreateFetcherCB create_fetcher_cb_;
  const SessionMessageCB session_message_cb_;
  const SessionClosedCB session_closed_cb_;
  const SessionKeysChangeCB session_keys_change_cb_;
  const SessionExpirationUpdateCB session_expiration_cb_;

  // Owned; destroyed in DestroyDrmObjects(). DRM Kit structs are opaque.
  RAW_PTR_EXCLUSION MediaKeySystem* system_ = nullptr;
  RAW_PTR_EXCLUSION MediaKeySession* session_ = nullptr;

  std::unique_ptr<ProvisionFetcher> provision_fetcher_;
  bool provisioning_ = false;

  // Open EME sessions, each with the number it was created with.
  std::map<std::string, uint64_t> session_order_;
  uint64_t next_session_number_ = 1;
  std::optional<std::string> last_updated_session_;
  // Counts UpdateSession() calls; a key change from DRM Kit records the count
  // it followed, so an update that DRM Kit reports no keys for is noticed.
  uint64_t update_count_ = 0;
  uint64_t keys_reported_for_update_ = 0;
  // Read by decoders on the media thread, written here; atomic in case a
  // decoder ever asks from another sequence.
  std::atomic<bool> has_usable_key_{false};

  CdmPromiseAdapter cdm_promise_adapter_;
  CallbackRegistry<EventCB::RunType> event_callbacks_;

  base::WeakPtrFactory<OhosCdm> weak_factory_{this};
};

}  // namespace media

#endif  // MEDIA_GPU_OHOS_OHOS_CDM_H_
