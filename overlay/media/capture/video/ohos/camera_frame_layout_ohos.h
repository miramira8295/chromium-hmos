// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_CAPTURE_VIDEO_OHOS_CAMERA_FRAME_LAYOUT_OHOS_H_
#define MEDIA_CAPTURE_VIDEO_OHOS_CAMERA_FRAME_LAYOUT_OHOS_H_

#include <stddef.h>
#include <stdint.h>

#include <optional>

#include <native_buffer/native_buffer.h>

#include "third_party/libyuv/include/libyuv/rotate.h"

// Reading CameraKit's YUV 4:2:0 frames where they are mapped: which plane is
// which, where each one's samples are, and whether they fit in the buffer.

namespace media {

bool IsCrCbFormat(int32_t format);

// Where one plane's samples are in the mapped buffer.
struct PlaneLayout {
  size_t offset = 0;
  size_t row_stride = 0;
  size_t column_stride = 0;
};

// Whether `plane` holds `width` x `height` samples inside `mapped_size`
// bytes, and where. Swapped CameraKit strides are corrected and reported
// through `corrected_stride`.
std::optional<PlaneLayout> ValidatePlane(size_t mapped_size,
                                         const OH_NativeBuffer_Plane& plane,
                                         int width,
                                         int height,
                                         bool* corrected_stride);

// The same for an interleaved chroma plane: `height` rows of `width` bytes.
std::optional<PlaneLayout> ValidateInterleavedPlane(
    size_t mapped_size,
    const OH_NativeBuffer_Plane& plane,
    int width,
    int height,
    bool* corrected_stride);

// Copies a plane ValidatePlane() accepts into `width` x `height` bytes.
bool CopyPlane(const uint8_t* mapped,
               size_t mapped_size,
               const OH_NativeBuffer_Plane& plane,
               int width,
               int height,
               uint8_t* destination,
               bool* corrected_stride);

// Copies an interleaved plane ValidateInterleavedPlane() accepts.
bool CopyInterleavedPlane(const uint8_t* mapped,
                          size_t mapped_size,
                          const OH_NativeBuffer_Plane& plane,
                          int width,
                          int height,
                          uint8_t* destination,
                          bool* corrected_stride);

// A frame's three components in the mapped buffer, as libyuv's
// Android420ToI420Rotate() reads them: U and V the same distance apart within
// a row, whether planar (1) or interleaved (2).
struct YuvLayout {
  PlaneLayout y;
  PlaneLayout u;
  PlaneLayout v;
};

// The layout of a frame with `planes` and `config`, or nullopt if it is not
// one Android420ToI420Rotate() can read in place.
std::optional<YuvLayout> ResolveYuvLayout(size_t mapped_size,
                                          const OH_NativeBuffer_Planes& planes,
                                          const OH_NativeBuffer_Config& config,
                                          bool* corrected_stride);

libyuv::RotationMode RotationModeFor(int degrees);

}  // namespace media

#endif  // MEDIA_CAPTURE_VIDEO_OHOS_CAMERA_FRAME_LAYOUT_OHOS_H_
