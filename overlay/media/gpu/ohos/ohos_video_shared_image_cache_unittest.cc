// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/gpu/ohos/ohos_video_shared_image_cache.h"

#include "gpu/command_buffer/common/shared_image_info.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace media {
namespace {

scoped_refptr<gpu::ClientSharedImage> MakeImage(
    gfx::Size size = gfx::Size(1920, 1080),
    viz::SharedImageFormat format = viz::MultiPlaneFormat::kNV12,
    gfx::ColorSpace color_space = gfx::ColorSpace::CreateREC709()) {
  format.SetPrefersExternalSampler();
  return gpu::ClientSharedImage::CreateForTesting(gpu::SharedImageMetadata{
      format, size, color_space, kTopLeft_GrSurfaceOrigin, kOpaque_SkAlphaType,
      gpu::SHARED_IMAGE_USAGE_DISPLAY_READ});
}

scoped_refptr<gpu::ClientSharedImage> Take(
    OhosVideoSharedImageCache& cache,
    uint32_t id,
    const gpu::ClientSharedImage& reference) {
  return cache.Take(id, reference.format(), reference.size(),
                    reference.color_space());
}

TEST(OhosVideoSharedImageCacheTest, CheckoutIsExclusive) {
  OhosVideoSharedImageCache cache;
  cache.Reset(1);
  auto image = MakeImage();
  cache.Put(1, 17, image);
  auto checked_out = Take(cache, 17, *image);
  EXPECT_EQ(checked_out, image);
  EXPECT_FALSE(Take(cache, 17, *image));
  EXPECT_EQ(cache.bytes(), 0u);
  // Production returns the image only after the GPU read-completion token.
  cache.Put(1, 17, std::move(checked_out));
  EXPECT_EQ(Take(cache, 17, *image), image);
}

TEST(OhosVideoSharedImageCacheTest, OldFramesCannotRepopulateAfterReset) {
  OhosVideoSharedImageCache cache;
  cache.Reset(1);
  auto old_image = MakeImage();
  cache.Put(1, 3, old_image);
  auto retained = Take(cache, 3, *old_image);
  cache.Reset(2);
  auto new_image = MakeImage();
  cache.Put(2, 3, new_image);  // Even if a new epoch reuses a numeric ID.
  cache.Put(1, 3, std::move(retained));
  EXPECT_EQ(Take(cache, 3, *new_image), new_image);
}

TEST(OhosVideoSharedImageCacheTest, RejectsChangedImportMetadata) {
  OhosVideoSharedImageCache cache;
  auto original = MakeImage();
  auto resized = MakeImage(gfx::Size(1280, 720));
  auto p010 = MakeImage(gfx::Size(1920, 1080), viz::MultiPlaneFormat::kP010);
  auto hdr = MakeImage(gfx::Size(1920, 1080), viz::MultiPlaneFormat::kNV12,
                       gfx::ColorSpace::CreateHDR10());
  for (const auto& changed : {resized, p010, hdr}) {
    cache.Put(0, 9, original);
    EXPECT_FALSE(Take(cache, 9, *changed));
    EXPECT_EQ(cache.size(), 0u);
    EXPECT_EQ(cache.bytes(), 0u);
  }
}

TEST(OhosVideoSharedImageCacheTest, BoundsCountAndEvictsOldestIdleImport) {
  OhosVideoSharedImageCache cache;
  auto image = MakeImage();
  for (uint32_t id = 0; id <= OhosVideoSharedImageCache::kMaxImages; ++id) {
    cache.Put(0, id, MakeImage());
  }
  EXPECT_EQ(cache.size(), OhosVideoSharedImageCache::kMaxImages);
  EXPECT_FALSE(Take(cache, 0, *image));
  EXPECT_TRUE(Take(cache, 1, *image));
}

TEST(OhosVideoSharedImageCacheTest, BoundsBytesAndDoesNotCacheOversizedImage) {
  OhosVideoSharedImageCache cache;
  auto image = MakeImage(gfx::Size(3840, 2160), viz::MultiPlaneFormat::kP010);
  const size_t frame_bytes = image->format().EstimatedSizeInBytes(image->size());
  for (uint32_t id = 0; id < OhosVideoSharedImageCache::kMaxImages; ++id) {
    cache.Put(0, id, image);
  }
  EXPECT_EQ(cache.size(), OhosVideoSharedImageCache::kMaxBytes / frame_bytes);
  EXPECT_LE(cache.bytes(), OhosVideoSharedImageCache::kMaxBytes);
  EXPECT_FALSE(Take(cache, 0, *image));
  auto oversized = MakeImage(gfx::Size(16384, 16384));
  cache.Put(0, 100, oversized);
  EXPECT_FALSE(Take(cache, 100, *oversized));
  cache.Clear();
  EXPECT_EQ(cache.size(), 0u);
  EXPECT_EQ(cache.bytes(), 0u);
}

}  // namespace
}  // namespace media
