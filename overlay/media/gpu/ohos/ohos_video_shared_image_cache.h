// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_GPU_OHOS_OHOS_VIDEO_SHARED_IMAGE_CACHE_H_
#define MEDIA_GPU_OHOS_OHOS_VIDEO_SHARED_IMAGE_CACHE_H_

#include <cstddef>
#include <cstdint>
#include <list>
#include <utility>

#include "gpu/command_buffer/client/client_shared_image.h"

namespace media {

// GPU-sequence-only cache of imports whose frame read-completion tokens have
// passed. Contains allocation references, never ConsumerSurface frame leases.
// Taking an image removes it until that frame has finished reading it again.
class OhosVideoSharedImageCache {
 public:
  static constexpr size_t kMaxImages = 8;
  static constexpr size_t kMaxBytes = 128 * 1024 * 1024;

  void Reset(uint32_t generation) {
    Clear();
    generation_ = generation;
  }

  void Clear() {
    images_.clear();
    bytes_ = 0;
  }

  uint32_t generation() const { return generation_; }
  size_t size() const { return images_.size(); }
  size_t bytes() const { return bytes_; }

  scoped_refptr<gpu::ClientSharedImage> Take(
      uint32_t buffer_id,
      viz::SharedImageFormat format,
      const gfx::Size& size,
      const gfx::ColorSpace& color_space) {
    for (auto it = images_.begin(); it != images_.end(); ++it) {
      if (it->buffer_id != buffer_id) {
        continue;
      }
      auto image = std::move(it->image);
      bytes_ -= Bytes(*image);
      images_.erase(it);
      // Color conversion is part of EGLImage import state, so a matching
      // allocation alone is insufficient, including for SDR/HDR transitions.
      if (image->format() == format && image->size() == size &&
          image->color_space() == color_space) {
        return image;
      }
      return nullptr;
    }
    return nullptr;
  }

  void Put(uint32_t generation,
           uint32_t buffer_id,
           scoped_refptr<gpu::ClientSharedImage> image) {
    if (generation != generation_) {
      return;  // A retained pre-seek frame must not repopulate the new cache.
    }
    const size_t bytes = Bytes(*image);
    if (bytes > kMaxBytes) {
      return;
    }
    // Defensive replacement; a correctly leased surface cannot return the
    // same allocation twice concurrently.
    for (auto it = images_.begin(); it != images_.end(); ++it) {
      if (it->buffer_id == buffer_id) {
        bytes_ -= Bytes(*it->image);
        images_.erase(it);
        break;
      }
    }
    while (!images_.empty() &&
           (images_.size() >= kMaxImages || bytes_ > kMaxBytes - bytes)) {
      bytes_ -= Bytes(*images_.front().image);
      images_.pop_front();
    }
    bytes_ += bytes;
    images_.push_back({buffer_id, std::move(image)});
  }

 private:
  static size_t Bytes(const gpu::ClientSharedImage& image) {
    return image.format().EstimatedSizeInBytes(image.size());
  }

  struct Entry {
    uint32_t buffer_id;
    scoped_refptr<gpu::ClientSharedImage> image;
  };
  uint32_t generation_ = 0;
  size_t bytes_ = 0;
  std::list<Entry> images_;
};

}  // namespace media
#endif  // MEDIA_GPU_OHOS_OHOS_VIDEO_SHARED_IMAGE_CACHE_H_
