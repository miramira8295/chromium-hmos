// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/functional/callback.h"
#include "base/no_destructor.h"
#include "content/browser/speech/tts_platform_impl.h"

namespace content {

class TtsPlatformImplOhos : public TtsPlatformImpl {
 public:
  TtsPlatformImplOhos() = default;
  TtsPlatformImplOhos(const TtsPlatformImplOhos&) = delete;
  TtsPlatformImplOhos& operator=(const TtsPlatformImplOhos&) = delete;

  bool PlatformImplSupported() override { return false; }
  bool PlatformImplInitialized() override { return false; }
  void Speak(int utterance_id,
             const std::string& utterance,
             const std::string& lang,
             const VoiceData& voice,
             const UtteranceContinuousParameters& params,
             base::OnceCallback<void(bool)> on_speak_finished) override {
    std::move(on_speak_finished).Run(false);
  }
  bool StopSpeaking() override { return false; }
  bool IsSpeaking() override { return false; }
  void GetVoices(std::vector<VoiceData>* out_voices) override {}
  void Pause() override {}
  void Resume() override {}

  static TtsPlatformImplOhos* GetInstance() {
    static base::NoDestructor<TtsPlatformImplOhos> instance;
    return instance.get();
  }
};

TtsPlatformImpl* TtsPlatformImpl::GetInstance() {
  return TtsPlatformImplOhos::GetInstance();
}

}  // namespace content
