/*
 * Copyright (c) 2026 The Chromium Authors
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

// The system's memory level, for Chromium's tab discarding.
//
// HarmonyOS reports memory pressure only to ArkTS, through onMemoryLevel.
// This forwards every report to C++ as the event
//   level { level: AbilityConstant.MemoryLevel }
// (see chrome/browser/performance_manager/policies/
// ohos_tab_discarding_policy.cc). It has no methods.
//
// The level belongs to the application, not to a window, so the callback is
// registered once however many windows -- and so bridges -- there are. Every
// bridge reaches the same C++ dispatcher, so the newest one is used to send.

import { AbilityConstant, Configuration, EnvironmentCallback, common } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { SystemServiceEmitter, SystemServiceHandler } from './SystemServiceBridge';

const DOMAIN: number = 0x0000;
const TAG: string = 'MemoryLevel';

let emitLevel: SystemServiceEmitter | null = null;
let watching: boolean = false;

class MemoryLevelWatcher extends EnvironmentCallback {
  onConfigurationUpdated(_config: Configuration): void {
  }

  onMemoryLevel(level: AbilityConstant.MemoryLevel): void {
    hilog.info(DOMAIN, TAG, 'system memory level %{public}d', level);
    if (emitLevel === null) {
      return;
    }
    const data: Record<string, Object> = { 'level': level as number };
    emitLevel('level', data);
  }
}

export class MemoryLevelService implements SystemServiceHandler {
  constructor(context: common.UIAbilityContext, emit: SystemServiceEmitter) {
    emitLevel = emit;
    if (watching) {
      return;
    }
    try {
      context.getApplicationContext().on('environment', new MemoryLevelWatcher());
      watching = true;
    } catch (error) {
      hilog.warn(DOMAIN, TAG, 'cannot watch the memory level: %{public}s', String(error));
    }
  }

  async handle(method: string, _args: Record<string, Object>): Promise<Object | undefined> {
    throw new Error(`memorylevel has no method ${method}`);
  }
}
