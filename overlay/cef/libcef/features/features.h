// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CEF_LIBCEF_FEATURES_FEATURES_H_
#define CEF_LIBCEF_FEATURES_FEATURES_H_

#include "build/buildflag.h"

#ifndef BUILDFLAG_INTERNAL_ENABLE_CEF
#define BUILDFLAG_INTERNAL_ENABLE_CEF() (0)
#endif

#ifndef BUILDFLAG_INTERNAL_IS_CEF_SANDBOX_BUILD
#define BUILDFLAG_INTERNAL_IS_CEF_SANDBOX_BUILD() (0)
#endif

#endif  // CEF_LIBCEF_FEATURES_FEATURES_H_
