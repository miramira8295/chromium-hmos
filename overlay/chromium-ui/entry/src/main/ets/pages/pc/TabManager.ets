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

/**
 * 标签页信息接口
 */
export interface TabInfo {
  id: number;
  title: string;
  url: string;
  active: boolean;
}

/**
 * 标签页管理器
 */
export class TabManager {
  private tabs: TabInfo[] = [];
  private currentTabIndex: number = 0;
  
  /**
   * 添加新标签页
   */
  addTab(url: string = 'https://www.example.com'): TabInfo {
    const newTab: TabInfo = {
      id: Date.now(),
      title: '新标签页',
      url: url,
      active: false
    };
    
    // 取消所有标签页的激活状态
    this.tabs.forEach(tab => tab.active = false);
    
    this.tabs.push(newTab);
    this.currentTabIndex = this.tabs.length - 1;
    newTab.active = true;
    
    return newTab;
  }
  
  /**
   * 关闭标签页
   */
  closeTab(index: number): boolean {
    if (this.tabs.length <= 1) {
      return false; // 至少保留一个标签页
    }
    
    this.tabs.splice(index, 1);
    
    // 调整当前标签页索引
    if (this.currentTabIndex >= this.tabs.length) {
      this.currentTabIndex = this.tabs.length - 1;
    }
    
    // 激活当前标签页
    if (this.tabs[this.currentTabIndex]) {
      this.tabs[this.currentTabIndex].active = true;
    }
    
    return true;
  }
  
  /**
   * 切换标签页
   */
  switchTab(index: number): void {
    if (index < 0 || index >= this.tabs.length) {
      return;
    }
    
    // 取消所有标签页的激活状态
    this.tabs.forEach(tab => tab.active = false);
    
    // 激活指定标签页
    this.tabs[index].active = true;
    this.currentTabIndex = index;
  }
  
  /**
   * 获取所有标签页
   */
  getTabs(): TabInfo[] {
    return this.tabs;
  }
  
  /**
   * 获取当前标签页
   */
  getCurrentTab(): TabInfo | null {
    if (this.currentTabIndex >= 0 && this.currentTabIndex < this.tabs.length) {
      return this.tabs[this.currentTabIndex];
    }
    return null;
  }
  
  /**
   * 获取当前标签页索引
   */
  getCurrentTabIndex(): number {
    return this.currentTabIndex;
  }
  
  /**
   * 更新标签页信息
   */
  updateTab(index: number, title?: string, url?: string): void {
    if (index < 0 || index >= this.tabs.length) {
      return;
    }
    
    const tab = this.tabs[index];
    if (title !== undefined) {
      tab.title = title;
    }
    if (url !== undefined) {
      tab.url = url;
    }
  }
}

