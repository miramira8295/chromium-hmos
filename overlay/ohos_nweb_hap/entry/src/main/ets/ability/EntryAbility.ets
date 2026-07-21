/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { UIManager } from '../utils/UIManager';
import { WindowStatus } from '../components/webwindow/NativeContext';

/**
 * EntryAbility - 主入口Ability
 * 根据设备类型加载对应的UI
 */
export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // 设置窗口全屏
    windowStage.getMainWindow().then((win: window.Window) => {
      win.setWindowLayoutFullScreen(true).catch((error: Error) => {
        console.error('Failed to set window fullscreen:', error);
      });
      
      // 监听窗口状态变化
      win.on('windowStatusChange', (status: window.WindowStatus) => {
        this.onWindowStatusChange(status);
      });
      
      win.on('windowSizeChange', (size: window.Size) => {
        this.onWindowSizeChange(size);
      });
    }).catch((error: Error) => {
      console.error('Failed to get main window:', error);
    });
    
    // 根据设备类型加载对应UI
    const uiPath = UIManager.loadUI();
    windowStage.loadContent(uiPath, (err, data) => {
      if (err) {
        console.error('Failed to load content:', err);
        return;
      }
      console.info('Content loaded successfully:', data);
    });
  }
  
  onWindowStageDestroy() {
    // 清理资源
  }
  
  onForeground() {
    // 应用进入前台
  }
  
  onBackground() {
    // 应用进入后台
  }
  
  /**
   * 窗口状态变化处理
   */
  private onWindowStatusChange(status: window.WindowStatus): void {
    console.info('Window status changed:', status);
    // 可以在这里通知WebWindow组件窗口状态变化
  }
  
  /**
   * 窗口大小变化处理
   */
  private onWindowSizeChange(size: window.Size): void {
    console.info('Window size changed:', size);
    // 可以在这里通知WebWindow组件窗口大小变化
  }
}

