// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_GPU_OHOS_OHOS_AUDIO_DECODER_H_
#define MEDIA_GPU_OHOS_OHOS_AUDIO_DECODER_H_

#include <multimedia/player_framework/native_avcodec_base.h>
#include <stdint.h>

#include <atomic>
#include <memory>
#include <optional>

#include "base/containers/circular_deque.h"
#include "base/memory/raw_ptr.h"
#include "base/memory/raw_ptr_exclusion.h"
#include "base/memory/scoped_refptr.h"
#include "base/memory/weak_ptr.h"
#include "base/sequence_checker.h"
#include "base/task/sequenced_task_runner.h"
#include "media/base/audio_decoder.h"
#include "media/base/audio_decoder_config.h"
#include "media/base/audio_timestamp_helper.h"
#include "media/base/callback_registry.h"
#include "media/base/cdm_context.h"
#include "media/base/channel_layout.h"
#include "media/base/decoder_buffer.h"
#include "media/base/media_log.h"
#include "media/base/sample_format.h"
#include "media/gpu/media_gpu_export.h"

namespace media {

// Decodes the audio Chromium has no decoder for -- AC-3 and DTS -- with the
// system's AVCodecKit audio codecs. Hosted in the GPU process's media service
// and reached from the renderer through MojoAudioDecoder, the same way video
// reaches OhosVideoDecoder. Also decrypts and decodes AAC encrypted for a
// DRM Kit CDM (OhosCdm), which only the system decoder can decrypt.
class MEDIA_GPU_EXPORT OhosAudioDecoder final : public AudioDecoder {
 public:
  OhosAudioDecoder(scoped_refptr<base::SequencedTaskRunner> task_runner,
                   std::unique_ptr<MediaLog> media_log);
  OhosAudioDecoder(const OhosAudioDecoder&) = delete;
  OhosAudioDecoder& operator=(const OhosAudioDecoder&) = delete;
  ~OhosAudioDecoder() override;

  // AudioDecoder implementation.
  AudioDecoderType GetDecoderType() const override;
  void Initialize(const AudioDecoderConfig& config,
                  CdmContext* cdm_context,
                  InitCB init_cb,
                  const OutputCB& output_cb,
                  const WaitingCB& waiting_cb) override;
  void Decode(scoped_refptr<DecoderBuffer> buffer, DecodeCB decode_cb) override;
  void Reset(base::OnceClosure closure) override;
  bool NeedsBitstreamConversion() const override;
  bool IsPlatformDecoder() const override;

 private:
  struct CallbackRelay;

  struct PendingDecode {
    PendingDecode(scoped_refptr<DecoderBuffer> buffer, DecodeCB decode_cb);
    PendingDecode(PendingDecode&&);
    PendingDecode& operator=(PendingDecode&&);
    ~PendingDecode();

    scoped_refptr<DecoderBuffer> buffer;
    DecodeCB decode_cb;
  };

  struct CodecDeleter {
    void operator()(OH_AVCodec* codec) const;
  };

  // A buffer AVCodecKit lent us through a callback.
  struct CodecBuffer {
    uint32_t index;
    // Owned by the codec; valid until the index is pushed or freed, or the
    // codec is flushed, which invalidates every outstanding index.
    RAW_PTR_EXCLUSION OH_AVBuffer* buffer;
  };

  // What the codec says it produces; read from its output description.
  struct OutputFormat {
    SampleFormat sample_format;
    ChannelLayout channel_layout;
    int channels;
    int sample_rate;
  };

  enum class State {
    kUninitialized,
    kDecoding,
    // An end-of-stream buffer is in the codec; its decode callback runs once
    // the matching end-of-stream output comes back.
    kDraining,
    kError,
  };

  // AVCodecKit invokes these on its own threads. They only post to
  // `task_runner_`; `user_data` is the CallbackRelay of the codec instance.
  static void OnCodecErrorThunk(OH_AVCodec* codec,
                                int32_t error_code,
                                void* user_data);
  static void OnStreamChangedThunk(OH_AVCodec* codec,
                                   OH_AVFormat* format,
                                   void* user_data);
  static void OnNeedInputBufferThunk(OH_AVCodec* codec,
                                     uint32_t index,
                                     OH_AVBuffer* buffer,
                                     void* user_data);
  static void OnNewOutputBufferThunk(OH_AVCodec* codec,
                                     uint32_t index,
                                     OH_AVBuffer* buffer,
                                     void* user_data);

  void OnCodecError(uint32_t generation, int32_t error_code);
  void OnStreamChanged(uint32_t generation);
  void OnNeedInputBuffer(uint32_t generation, CodecBuffer input);
  void OnNewOutputBuffer(uint32_t generation, CodecBuffer output);

  bool CreateCodec(const char* mime);
  void DestroyCodec();
  // Drops every index the codec handed out and starts it again: after end of
  // stream (it takes no input in that state) and on Reset().
  bool FlushAndRestartCodec();
  void PumpInput();
  void OnCdmEvent(CdmContext::Event event);
  bool QueueInput(const CodecBuffer& input, const DecoderBuffer& buffer);
  bool UpdateOutputFormat();
  void DeliverOutput(const OH_AVCodecBufferAttr& attr, OH_AVBuffer* buffer);
  void EnterErrorState(const char* reason);
  void AbortPendingDecodes(DecoderStatus status);

  const scoped_refptr<base::SequencedTaskRunner> task_runner_;
  const std::unique_ptr<MediaLog> media_log_;

  State state_ = State::kUninitialized;
  AudioDecoderConfig config_;
  OutputCB output_cb_;
  WaitingCB waiting_cb_;

  // For encrypted streams: the CDM whose DRM Kit session decrypts them. The
  // media service keeps it alive for as long as this decoder.
  raw_ptr<CdmContext> cdm_context_ = nullptr;
  std::unique_ptr<CallbackRegistration> cdm_event_registration_;
  // Encrypted input is held while the CDM has no usable key.
  bool waiting_for_key_ = false;

  // Identifies the codec instance and flush epoch. Every callback carries the
  // value current when AVCodecKit invoked it, so tasks that refer to a
  // destroyed codec or to indices a flush invalidated are dropped.
  uint32_t generation_ = 0;
  // Declared before `codec_` so it outlives it: the codec's threads use the
  // relay until OH_AudioCodec_Destroy() returns.
  std::unique_ptr<CallbackRelay> relay_;
  std::unique_ptr<OH_AVCodec, CodecDeleter> codec_;

  base::circular_deque<CodecBuffer> free_inputs_;
  base::circular_deque<PendingDecode> pending_decodes_;
  DecodeCB eos_decode_cb_;
  std::optional<OutputFormat> output_format_;
  // Output timestamps run on from the first input after a start or reset, by
  // the frames delivered, as Android's MediaCodecAudioDecoder does: a codec's
  // own presentation times need not survive a flush.
  std::unique_ptr<AudioTimestampHelper> timestamp_helper_;
  // The rate `timestamp_helper_` counts frames at.
  int timestamp_sample_rate_ = 0;
  bool logged_first_output_ = false;

  SEQUENCE_CHECKER(sequence_checker_);
  base::WeakPtrFactory<OhosAudioDecoder> weak_factory_{this};
};

}  // namespace media

#endif  // MEDIA_GPU_OHOS_OHOS_AUDIO_DECODER_H_
