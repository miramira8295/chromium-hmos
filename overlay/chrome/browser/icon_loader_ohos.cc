// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <utility>

#include "base/functional/bind.h"
#include "base/task/thread_pool.h"
#include "chrome/browser/icon_loader.h"

IconLoader::IconGroup IconLoader::GroupForFilepath(
    const base::FilePath& file_path) {
  return file_path.Extension();
}

scoped_refptr<base::TaskRunner> IconLoader::GetReadIconTaskRunner() {
  return base::ThreadPool::CreateSequencedTaskRunner(traits());
}

void IconLoader::ReadIcon() {
  target_task_runner_->PostTask(
      FROM_HERE,
      base::BindOnce(std::move(callback_), gfx::Image(), std::move(group_)));
  delete this;
}
