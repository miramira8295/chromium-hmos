// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/ozone/platform/ohos/ohos_native_pixmap.h"

#include <utility>

#include <native_buffer/native_buffer.h>
#include <native_window/external_window.h>

#include "base/functional/bind.h"
#include "base/functional/callback_helpers.h"
#include "base/memory_coordinator/memory_consumer_registry.h"
#include "base/memory_coordinator/test_memory_consumer_registry.h"
#include "base/test/task_environment.h"
#include "base/time/time.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "ui/gfx/native_pixmap.h"

namespace ui {
namespace {

TEST(OhosNativePixmapTest, CachedImportDoesNotHoldFrameLease) {
  OH_NativeBuffer_Config config = {};
  config.width = 1920;
  config.height = 1080;
  config.format = NATIVEBUFFER_PIXEL_FMT_YCBCR_420_SP;
  config.usage = NATIVEBUFFER_USAGE_HW_TEXTURE;
  auto* buffer = OH_NativeBuffer_Alloc(&config);
  ASSERT_NE(buffer, nullptr);
  auto* window =
      OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer(buffer);
  OH_NativeBuffer_Unreference(buffer);
  ASSERT_NE(window, nullptr);
  bool released = false;
  gfx::ColorSpace color_space = gfx::ColorSpace::CreateREC709();
  using OwnedWindowBuffer =
      std::unique_ptr<OHNativeWindowBuffer,
                      decltype(&OH_NativeWindow_DestroyNativeWindowBuffer)>;
  auto frame_pixmap = CreateOhosVideoNativePixmap(
      window, &color_space,
      base::BindOnce([](OwnedWindowBuffer, bool* released) { *released = true; },
                     OwnedWindowBuffer(
                         window, &OH_NativeWindow_DestroyNativeWindowBuffer),
                     base::Unretained(&released)));
  ASSERT_TRUE(frame_pixmap);
  const auto id = GetOhosVideoNativePixmapId(*frame_pixmap);
  ASSERT_TRUE(id.has_value());
  auto cached_import = CloneOhosVideoNativePixmapForImport(*frame_pixmap);
  ASSERT_TRUE(cached_import);
  EXPECT_EQ(GetOhosVideoNativePixmapId(*cached_import), id);
  frame_pixmap.reset();
  EXPECT_TRUE(released);  // A live cache must not keep the queue slot occupied.
  // Its own wrapper must still be valid after the original is destroyed.
  auto another_import = CloneOhosVideoNativePixmapForImport(*cached_import);
  ASSERT_TRUE(another_import);
  EXPECT_EQ(GetOhosVideoNativePixmapId(*another_import), id);
}

// Exercises the real allocator/registry without creating a GL context. Keep
// the scenarios in one environment because the process-wide registry, like
// its async memory consumer registration, deliberately lives until exit.
TEST(OhosNativePixmapTest, IdleRetirementAndReimport) {
  base::test::TaskEnvironment tasks(
      base::test::TaskEnvironment::TimeSource::MOCK_TIME,
      base::test::TaskEnvironment::ThreadPoolExecutionMode::QUEUED);
  base::ScopedMemoryConsumerRegistry<base::TestMemoryConsumerRegistry> pressure;
  const gfx::Size size(1920, 1080);
  const auto format = viz::MultiPlaneFormat::kNV12;

  auto active = CreateOhosNativePixmap(size, format);
  ASSERT_TRUE(active);
  auto idle = CreateOhosNativePixmap(size, format);
  ASSERT_TRUE(idle);
  auto idle_handle = idle->ExportHandle();
  idle.reset();
  tasks.RunUntilIdle();  // Finish the async memory consumer registration.
  ASSERT_GE(pressure.Get().size(), 1u);

  // Pressure must not shorten the handle handoff grace period.
  tasks.FastForwardBy(base::Seconds(9));
  pressure.Get().NotifyReleaseMemory();
  tasks.RunUntilIdle();
  auto reimported =
      CreateOhosNativePixmapFromHandle(size, format, std::move(idle_handle));
  ASSERT_TRUE(reimported);
  auto reimport_handle = reimported->ExportHandle();

  // The already queued purge must not evict a buffer re-acquired before its
  // old deadline. Hold it past that deadline, then start a fresh grace period.
  tasks.FastForwardBy(base::Seconds(2));
  auto second_user = CreateOhosNativePixmapFromHandle(
      size, format, std::move(reimport_handle));
  ASSERT_TRUE(second_user);
  auto expired_handle = second_user->ExportHandle();
  reimported.reset();
  tasks.FastForwardBy(base::Seconds(10));
  // A second live pixmap still owns this entry even after the first is gone.
  EXPECT_NE(GetOhosNativeBuffer(*second_user), nullptr);
  second_user.reset();

  // No allocation or memory-pressure event drives this cleanup. The delayed
  // task alone must retire the idle entry at its new deadline.
  tasks.FastForwardBy(base::Seconds(10));
  EXPECT_FALSE(CreateOhosNativePixmapFromHandle(
      size, format, std::move(expired_handle)));
  EXPECT_NE(GetOhosNativeBuffer(*active), nullptr);

  // Staggered retirement: the first task must arrange another wakeup for the
  // later buffer, rather than keeping it forever or evicting it too early.
  auto later = CreateOhosNativePixmap(size, format);
  ASSERT_TRUE(later);
  auto active_handle = active->ExportHandle();
  active.reset();
  tasks.FastForwardBy(base::Seconds(3));
  auto later_handle = later->ExportHandle();
  later.reset();
  tasks.FastForwardBy(base::Seconds(7));
  EXPECT_FALSE(CreateOhosNativePixmapFromHandle(
      size, format, std::move(active_handle)));
  auto within_grace = CreateOhosNativePixmapFromHandle(
      size, format, std::move(later_handle));
  ASSERT_TRUE(within_grace);
  auto final_handle = within_grace->ExportHandle();
  within_grace.reset();
  tasks.FastForwardBy(base::Seconds(10));
  EXPECT_FALSE(CreateOhosNativePixmapFromHandle(
      size, format, std::move(final_handle)));

  // Empty registries do not keep a periodic task (and the process) awake.
  const auto now = base::TimeTicks::Now();
  tasks.FastForwardUntilNoTasksRemain();
  EXPECT_EQ(base::TimeTicks::Now(), now);
}

}  // namespace
}  // namespace ui
