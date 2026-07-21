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

import { WebWindow } from '../../components/webwindow/WebWindow';
import { TabletNavigationBar } from './NavigationBar';
import { RemoteControl } from './RemoteControl';
import { UIManager } from '../../utils/UIManager';

/**
 * Tablet UI主页面（用于汽车和电视）
 */
@Entry
@Component
struct TabletIndex {
  @State url: string = 'https://www.example.com';
  @State pageTitle: string = '';
  @State isLoading: boolean = false;
  @State focusedIndex: number = 0;  // 遥控器焦点索引
  
  build() {
    Column() {
      // 大屏导航栏
      TabletNavigationBar({
        url: this.url,
        onUrlChange: (newUrl: string) => {
          this.url = newUrl;
        },
        focusedIndex: this.focusedIndex === 0 ? 0 : -1,
        onFocusChange: (index: number) => {
          this.focusedIndex = index;
        }
      })
        .height(80)
      
      // WebView（支持遥控器控制）
      WebWindow({
        url: this.url,
        width: '100%',
        height: '100%',
        onPageLoadStart: (url: string) => {
          this.isLoading = true;
        },
        onPageLoadFinish: (url: string) => {
          this.isLoading = false;
        },
        onTitleReceive: (title: string) => {
          this.pageTitle = title;
        }
      })
        .layoutWeight(1)
        .focusable(true)
        .focus(this.focusedIndex === 1)
        .onKeyEvent((event: KeyEvent) => {
          this.handleKeyEvent(event);
        })
      
      // 遥控器控制提示（可选）
      if (UIManager.isTV() || UIManager.isAuto()) {
        RemoteControl({
          onKeyPress: (key: string) => {
            this.handleRemoteKey(key);
          }
        })
          .height(60)
      }
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#1F1F1F')
  }
  
  /**
   * 处理键盘事件（遥控器/方向盘）
   */
  handleKeyEvent(event: KeyEvent): void {
    if (event.type === KeyType.Down) {
      switch (event.keyCode) {
        case KeyCode.KEY_DPAD_UP:
          // 向上移动焦点
          if (this.focusedIndex > 0) {
            this.focusedIndex--;
          }
          break;
        case KeyCode.KEY_DPAD_DOWN:
          // 向下移动焦点
          if (this.focusedIndex < 1) {
            this.focusedIndex++;
          }
          break;
        case KeyCode.KEY_DPAD_LEFT:
          // 向左
          break;
        case KeyCode.KEY_DPAD_RIGHT:
          // 向右
          break;
        case KeyCode.KEY_ENTER:
          // 确认
          break;
        case KeyCode.KEY_BACK:
          // 返回
          break;
      }
    }
  }
  
  /**
   * 处理遥控器按键
   */
  handleRemoteKey(key: string): void {
    // 处理遥控器按键逻辑
    console.log('Remote key pressed:', key);
  }
}

