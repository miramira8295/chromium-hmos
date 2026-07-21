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
 * 手机导航栏组件
 */
@Component
export struct PhoneNavigationBar {
  @Param url: string;
  @Param onUrlChange?: (url: string) => void;
  @Param onBack?: () => void;
  @Param onForward?: () => void;
  @Param onRefresh?: () => void;
  
  @State inputUrl: string = '';
  @State canGoBack: boolean = false;
  @State canGoForward: boolean = false;
  
  aboutToAppear() {
    this.inputUrl = this.url;
  }
  
  build() {
    Row() {
      // 返回按钮
      Button('←')
        .type(ButtonType.Circle)
        .width(40)
        .height(40)
        .fontSize(20)
        .fontColor('#333333')
        .backgroundColor('#F5F5F5')
        .enabled(this.canGoBack)
        .onClick(() => {
          if (this.onBack) {
            this.onBack();
          }
        })
      
      // 地址栏
      TextInput({ placeholder: '输入网址或搜索' })
        .layoutWeight(1)
        .height(36)
        .backgroundColor('#F5F5F5')
        .borderRadius(18)
        .padding({ left: 12, right: 12 })
        .fontSize(14)
        .onChange((value: string) => {
          this.inputUrl = value;
        })
        .onSubmit(() => {
          if (this.inputUrl && this.inputUrl.trim() !== '') {
            let finalUrl = this.inputUrl.trim();
            // 如果不是URL格式，添加https://
            if (!finalUrl.startsWith('http://') && !finalUrl.startsWith('https://')) {
              finalUrl = 'https://' + finalUrl;
            }
            if (this.onUrlChange) {
              this.onUrlChange(finalUrl);
            }
          }
        })
      
      // 刷新按钮
      Button('↻')
        .type(ButtonType.Circle)
        .width(40)
        .height(40)
        .fontSize(20)
        .fontColor('#333333')
        .backgroundColor('#F5F5F5')
        .onClick(() => {
          if (this.onRefresh) {
            this.onRefresh();
          }
        })
    }
    .width('100%')
    .height('100%')
    .padding({ left: 8, right: 8 })
    .backgroundColor('#F5F5F5')
    .justifyContent(FlexAlign.SpaceBetween)
    .alignItems(VerticalAlign.Center)
  }
}

