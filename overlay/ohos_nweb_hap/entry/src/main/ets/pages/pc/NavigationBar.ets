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

import { TabInfo } from './TabManager';

/**
 * PC导航栏组件（包含标签页管理）
 */
@Component
export struct PCNavigationBar {
  @Param tabs: TabInfo[];
  @Param currentTab: number;
  @Param onTabChange?: (index: number) => void;
  @Param onNewTab?: () => void;
  @Param onCloseTab?: (index: number) => void;
  
  @State inputUrl: string = '';
  
  aboutToAppear() {
    if (this.tabs[this.currentTab]) {
      this.inputUrl = this.tabs[this.currentTab].url;
    }
  }
  
  build() {
    Column() {
      // 标签页栏
      Row() {
        ForEach(this.tabs, (tab: TabInfo, index: number) => {
          Row() {
            Text(tab.title)
              .fontSize(14)
              .maxLines(1)
              .textOverflow({ overflow: TextOverflow.Ellipsis })
              .layoutWeight(1)
            
            Button('×')
              .type(ButtonType.Circle)
              .width(20)
              .height(20)
              .fontSize(16)
              .fontColor('#666666')
              .backgroundColor(Color.Transparent)
              .onClick(() => {
                if (this.onCloseTab) {
                  this.onCloseTab(index);
                }
              })
          }
          .width(200)
          .height(36)
          .padding({ left: 12, right: 8 })
          .backgroundColor(tab.active ? '#FFFFFF' : '#E0E0E0')
          .borderRadius({ topLeft: 8, topRight: 8 })
          .onClick(() => {
            if (this.onTabChange) {
              this.onTabChange(index);
            }
          })
        }, (tab: TabInfo) => tab.id.toString())
        
        // 新建标签页按钮
        Button('+')
          .type(ButtonType.Circle)
          .width(36)
          .height(36)
          .fontSize(20)
          .fontColor('#333333')
          .backgroundColor('#E0E0E0')
          .onClick(() => {
            if (this.onNewTab) {
              this.onNewTab();
            }
          })
      }
      .width('100%')
      .height(36)
      .backgroundColor('#F5F5F5')
      
      // 地址栏和工具栏
      Row() {
        // 地址栏
        TextInput({ placeholder: '输入网址或搜索' })
          .layoutWeight(1)
          .height(36)
          .backgroundColor('#FFFFFF')
          .borderRadius(4)
          .padding({ left: 12, right: 12 })
          .fontSize(14)
          .onChange((value: string) => {
            this.inputUrl = value;
          })
          .onSubmit(() => {
            if (this.inputUrl && this.inputUrl.trim() !== '') {
              let finalUrl = this.inputUrl.trim();
              if (!finalUrl.startsWith('http://') && !finalUrl.startsWith('https://')) {
                finalUrl = 'https://' + finalUrl;
              }
              // 在当前标签页加载URL
              if (this.tabs[this.currentTab]) {
                this.tabs[this.currentTab].url = finalUrl;
              }
            }
          })
        
        // 工具栏按钮
        Button('刷新')
          .height(36)
          .onClick(() => {
            // 刷新当前标签页
          })
        
        Button('书签')
          .height(36)
          .onClick(() => {
            // 显示书签
          })
        
        Button('菜单')
          .height(36)
          .onClick(() => {
            // 显示菜单
          })
      }
      .width('100%')
      .height(36)
      .padding({ left: 8, right: 8 })
      .backgroundColor('#FFFFFF')
    }
    .width('100%')
    .height('100%')
  }
}

