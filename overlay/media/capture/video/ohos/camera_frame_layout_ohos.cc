// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/capture/video/ohos/camera_frame_layout_ohos.h"

#include <cstring>
#include <utility>

namespace media {

bool IsCrCbFormat(int32_t format) {
  return format == NATIVEBUFFER_PIXEL_FMT_YCRCB_420_SP ||
         format == NATIVEBUFFER_PIXEL_FMT_YCRCB_420_P;
}

// Whether `plane` holds `width` x `height` samples inside `mapped_size`
// bytes, and where. Some CameraKit YUV_420_SP buffers report chroma rowStride
// and columnStride in the opposite fields; that is accepted, and reported
// through `corrected_stride`, only when the reported values cannot describe
// one row and the swapped values can.
std::optional<PlaneLayout> ValidatePlane(size_t mapped_size,
                                         const OH_NativeBuffer_Plane& plane,
                                         int width,
                                         int height,
                                         bool* corrected_stride) {
  if (width <= 0 || height <= 0 || plane.rowStride == 0 ||
      plane.columnStride == 0) {
    return std::nullopt;
  }
  PlaneLayout layout = {plane.offset, plane.rowStride, plane.columnStride};
  const size_t row_bytes =
      (static_cast<size_t>(width) - 1) * layout.column_stride + 1;
  if (layout.row_stride < row_bytes) {
    const size_t swapped_row_bytes =
        (static_cast<size_t>(width) - 1) * layout.row_stride + 1;
    if (layout.column_stride < swapped_row_bytes) {
      return std::nullopt;
    }
    std::swap(layout.row_stride, layout.column_stride);
    *corrected_stride = true;
  }
  size_t last_byte = layout.offset;
  const size_t last_row = static_cast<size_t>(height) - 1;
  const size_t last_column = static_cast<size_t>(width) - 1;
  if (last_byte >= mapped_size ||
      (last_row &&
       layout.row_stride > (mapped_size - 1 - last_byte) / last_row)) {
    return std::nullopt;
  }
  last_byte += last_row * layout.row_stride;
  if (last_column &&
      layout.column_stride > (mapped_size - 1 - last_byte) / last_column) {
    return std::nullopt;
  }
  return layout;
}

// The same for an interleaved chroma plane: `height` rows of `width` bytes,
// two samples to a pair.
std::optional<PlaneLayout> ValidateInterleavedPlane(
    size_t mapped_size,
    const OH_NativeBuffer_Plane& plane,
    int width,
    int height,
    bool* corrected_stride) {
  size_t row_stride = plane.rowStride;
  if (row_stride < static_cast<size_t>(width) &&
      plane.columnStride >= static_cast<uint32_t>(width)) {
    row_stride = plane.columnStride;
    *corrected_stride = true;
  }
  if (width <= 0 || height <= 0 || row_stride < static_cast<size_t>(width) ||
      plane.offset >= mapped_size ||
      mapped_size - plane.offset < static_cast<size_t>(width)) {
    return std::nullopt;
  }
  const size_t last_row = static_cast<size_t>(height) - 1;
  if (last_row &&
      row_stride > (mapped_size - plane.offset - width) / last_row) {
    return std::nullopt;
  }
  return PlaneLayout{plane.offset, row_stride, 2};
}

bool CopyPlane(const uint8_t* mapped,
               size_t mapped_size,
               const OH_NativeBuffer_Plane& plane,
               int width,
               int height,
               uint8_t* destination,
               bool* corrected_stride) {
  const std::optional<PlaneLayout> layout =
      ValidatePlane(mapped_size, plane, width, height, corrected_stride);
  if (!mapped || !destination || !layout) {
    return false;
  }
  const uint8_t* source = mapped + layout->offset;
  for (int row = 0; row < height; ++row) {
    const uint8_t* source_row = source + row * layout->row_stride;
    uint8_t* destination_row = destination + row * width;
    if (layout->column_stride == 1) {
      std::memcpy(destination_row, source_row, width);
      continue;
    }
    for (int column = 0; column < width; ++column) {
      destination_row[column] = source_row[column * layout->column_stride];
    }
  }
  return true;
}

bool CopyInterleavedPlane(const uint8_t* mapped,
                          size_t mapped_size,
                          const OH_NativeBuffer_Plane& plane,
                          int width,
                          int height,
                          uint8_t* destination,
                          bool* corrected_stride) {
  const std::optional<PlaneLayout> layout = ValidateInterleavedPlane(
      mapped_size, plane, width, height, corrected_stride);
  if (!mapped || !destination || !layout) {
    return false;
  }
  for (int row = 0; row < height; ++row) {
    std::memcpy(destination + static_cast<size_t>(row) * width,
                mapped + layout->offset + static_cast<size_t>(row) *
                                              layout->row_stride,
                width);
  }
  return true;
}

std::optional<YuvLayout> ResolveYuvLayout(size_t mapped_size,
                                          const OH_NativeBuffer_Planes& planes,
                                          const OH_NativeBuffer_Config& config,
                                          bool* corrected_stride) {
  const int width = config.width;
  const int height = config.height;
  std::optional<PlaneLayout> y =
      ValidatePlane(mapped_size, planes.planes[0], width, height,
                    corrected_stride);
  if (!y || y->column_stride != 1) {
    return std::nullopt;
  }
  const bool cr_first = IsCrCbFormat(config.format);
  if (planes.planeCount >= 3) {
    // Which chroma plane is U and which is V follows from the offsets, not
    // the array index: see CaptureDelegateOhos::ProcessFrame().
    const uint32_t first_plane =
        planes.planes[1].offset <= planes.planes[2].offset ? 1u : 2u;
    const uint32_t second_plane = first_plane == 1u ? 2u : 1u;
    std::optional<PlaneLayout> u = ValidatePlane(
        mapped_size, planes.planes[cr_first ? second_plane : first_plane],
        width / 2, height / 2, corrected_stride);
    std::optional<PlaneLayout> v = ValidatePlane(
        mapped_size, planes.planes[cr_first ? first_plane : second_plane],
        width / 2, height / 2, corrected_stride);
    if (!u || !v || u->column_stride != v->column_stride ||
        u->column_stride > 2) {
      return std::nullopt;
    }
    return YuvLayout{*y, *u, *v};
  }
  OH_NativeBuffer_Plane chroma_plane = planes.planes[1];
  if (planes.planeCount < 2) {
    const uint32_t stride = config.stride > 0 ? config.stride : width;
    chroma_plane = {.offset = static_cast<uint64_t>(stride) * height,
                    .rowStride = stride,
                    .columnStride = 1};
  }
  std::optional<PlaneLayout> chroma = ValidateInterleavedPlane(
      mapped_size, chroma_plane, width, height / 2, corrected_stride);
  if (!chroma) {
    return std::nullopt;
  }
  PlaneLayout first = *chroma;
  PlaneLayout second = *chroma;
  second.offset += 1;
  return cr_first ? YuvLayout{*y, second, first} : YuvLayout{*y, first, second};
}

libyuv::RotationMode RotationModeFor(int degrees) {
  switch (degrees) {
    case 90:
      return libyuv::kRotate90;
    case 180:
      return libyuv::kRotate180;
    case 270:
      return libyuv::kRotate270;
    default:
      return libyuv::kRotate0;
  }
}

}  // namespace media
