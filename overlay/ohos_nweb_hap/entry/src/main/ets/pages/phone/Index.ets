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
import { PhoneNavigationBar } from './NavigationBar';
import { PhoneToolBar } from './ToolBar';

/**
 * 手机UI主页面
 */
@Entry
@Component
struct PhoneIndex {
  @State url: string = 'https://www.example.com';
  @State pageTitle: string = '';
  @State isLoading: boolean = false;
  
  build() {
    Column() {
      // 导航栏（简化版）
      PhoneNavigationBar({
        url: this.url,
        onUrlChange: (newUrl: string) => {
          this.url = newUrl;
        },
        onBack: () => {
          // 返回上一页
        },
        onForward: () => {
          // 前进
        },
        onRefresh: () => {
          // 刷新
        }
      })
        .height(56)
      
      // WebView
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
      
      // 工具栏（可选）
      PhoneToolBar({
        onMenuClick: () => {
          // 显示菜单
        },
        onBookmarkClick: () => {
          // 显示书签
        },
        onSettingsClick: () => {
          // 显示设置
        }
      })
        .height(48)
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#FFFFFF')
  }
}

