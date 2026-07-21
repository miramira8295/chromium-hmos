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
import { PCNavigationBar } from './NavigationBar';
import { BookmarkBar } from './BookmarkBar';
import { TabInfo } from './TabManager';

/**
 * PC UI主页面（用于平板和电脑）
 */
@Entry
@Component
struct PCIndex {
  @State tabs: TabInfo[] = [
    { id: 0, title: '新标签页', url: 'https://www.example.com', active: true }
  ];
  @State currentTab: number = 0;
  @State showBookmarkBar: boolean = false;
  
  build() {
    Column() {
      // PC导航栏（包含标签页）
      PCNavigationBar({
        tabs: this.tabs,
        currentTab: this.currentTab,
        onTabChange: (index: number) => {
          this.currentTab = index;
        },
        onNewTab: () => {
          this.addNewTab();
        },
        onCloseTab: (index: number) => {
          this.closeTab(index);
        }
      })
        .height(60)
      
      // 书签栏（可选）
      if (this.showBookmarkBar) {
        BookmarkBar({
          onBookmarkClick: (url: string) => {
            this.loadUrlInCurrentTab(url);
          }
        })
          .height(32)
      }
      
      // WebView（多标签页）
      Stack() {
        ForEach(this.tabs, (tab: TabInfo, index: number) => {
          WebWindow({
            url: tab.url,
            width: '100%',
            height: '100%',
            onPageLoadFinish: (url: string) => {
              // 更新标签页URL
              tab.url = url;
            },
            onTitleReceive: (title: string) => {
              // 更新标签页标题
              tab.title = title;
            }
          })
            .visibility(index === this.currentTab ? Visibility.Visible : Visibility.Hidden)
        }, (tab: TabInfo) => tab.id.toString())
      }
        .layoutWeight(1)
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#FFFFFF')
  }
  
  /**
   * 添加新标签页
   */
  addNewTab(): void {
    const newTab: TabInfo = {
      id: Date.now(),
      title: '新标签页',
      url: 'https://www.example.com',
      active: false
    };
    this.tabs.push(newTab);
    this.currentTab = this.tabs.length - 1;
  }
  
  /**
   * 关闭标签页
   */
  closeTab(index: number): void {
    if (this.tabs.length <= 1) {
      return; // 至少保留一个标签页
    }
    
    this.tabs.splice(index, 1);
    
    // 调整当前标签页索引
    if (this.currentTab >= this.tabs.length) {
      this.currentTab = this.tabs.length - 1;
    }
    
    // 激活当前标签页
    if (this.tabs[this.currentTab]) {
      this.tabs[this.currentTab].active = true;
    }
  }
  
  /**
   * 在当前标签页加载URL
   */
  loadUrlInCurrentTab(url: string): void {
    if (this.tabs[this.currentTab]) {
      this.tabs[this.currentTab].url = url;
    }
  }
}

