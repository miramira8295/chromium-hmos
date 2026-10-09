/*
 * Copyright (c) 2026 The Chromium Authors
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

// The system font size (Settings > Display > Font size), so that web text
// follows it the way the shell's own text does.
//
// Chromium asks once with the method
//   get -> { scale: number }
// and is then sent every change as the event
//   scale { scale: number }
// (see OhosSystemFontScaleWatcher in aura_shell_runtime_bridge.cc, which
// turns it into page zoom). The scale is Configuration.fontSizeScale: 1 is
// the standard size.
//
// Like the memory level, the font size belongs to the application, so the
// callback is registered once however many windows there are.

import { AbilityConstant, Configuration, EnvironmentCallback, common } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { SystemServiceEmitter, SystemServiceHandler } from './SystemServiceBridge';

const DOMAIN: number = 0x0000;
const TAG: string = 'FontScale';

let emitScale: SystemServiceEmitter | null = null;
let currentScale: number = 1;
let watching: boolean = false;

function validScale(scale: number | undefined): number | undefined {
  return typeof scale === 'number' && isFinite(scale) && scale > 0 ? scale : undefined;
}

class FontScaleWatcher extends EnvironmentCallback {
  onConfigurationUpdated(config: Configuration): void {
    const scale = validScale(config.fontSizeScale);
    if (scale === undefined || scale === currentScale) {
      return;
    }
    currentScale = scale;
    hilog.info(DOMAIN, TAG, 'system font scale %{public}f', scale);
    if (emitScale !== null) {
      const data: Record<string, Object> = { 'scale': scale };
      emitScale('scale', data);
    }
  }

  onMemoryLevel(_level: AbilityConstant.MemoryLevel): void {
  }
}

export class FontScaleService implements SystemServiceHandler {
  constructor(context: common.UIAbilityContext, emit: SystemServiceEmitter) {
    emitScale = emit;
    if (watching) {
      return;
    }
    currentScale = validScale(context.config.fontSizeScale) ?? 1;
    try {
      context.getApplicationContext().on('environment', new FontScaleWatcher());
      watching = true;
    } catch (error) {
      hilog.warn(DOMAIN, TAG, 'cannot watch the font scale: %{public}s', String(error));
    }
  }

  async handle(method: string, _args: Record<string, Object>): Promise<Object | undefined> {
    if (method !== 'get') {
      throw new Error(`fontscale has no method ${method}`);
    }
    const result: Record<string, Object> = { 'scale': currentScale };
    return result;
  }
}
