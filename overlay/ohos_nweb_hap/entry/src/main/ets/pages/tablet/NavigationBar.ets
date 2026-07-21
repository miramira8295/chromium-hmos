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
 * Tablet导航栏组件（大屏适配）
 */
@Component
export struct TabletNavigationBar {
  @Param url: string;
  @Param onUrlChange?: (url: string) => void;
  @Param focusedIndex: number = -1;
  @Param onFocusChange?: (index: number) => void;
  
  @State inputUrl: string = '';
  
  aboutToAppear() {
    this.inputUrl = this.url;
  }
  
  build() {
    Row() {
      // 大屏地址栏
      TextInput({ placeholder: '输入网址' })
        .layoutWeight(1)
        .height(60)
        .fontSize(24)
        .backgroundColor('#2F2F2F')
        .borderRadius(8)
        .padding({ left: 16, right: 16 })
        .focusable(true)
        .focus(this.focusedIndex === 0)
        .onChange((value: string) => {
          this.inputUrl = value;
        })
        .onSubmit(() => {
          if (this.inputUrl && this.inputUrl.trim() !== '') {
            let finalUrl = this.inputUrl.trim();
            if (!finalUrl.startsWith('http://') && !finalUrl.startsWith('https://')) {
              finalUrl = 'https://' + finalUrl;
            }
            if (this.onUrlChange) {
              this.onUrlChange(finalUrl);
            }
          }
        })
        .onKeyEvent((event: KeyEvent) => {
          if (event.type === KeyType.Down && event.keyCode === KeyCode.KEY_TAB) {
            if (this.onFocusChange) {
              this.onFocusChange(1);
            }
          }
        })
      
      // 大按钮
      Button('返回')
        .width(120)
        .height(60)
        .fontSize(20)
        .backgroundColor('#3F3F3F')
        .focusable(true)
        .focus(this.focusedIndex === 1)
        .onClick(() => {
          // 返回
        })
      
      Button('前进')
        .width(120)
        .height(60)
        .fontSize(20)
        .backgroundColor('#3F3F3F')
        .focusable(true)
        .focus(this.focusedIndex === 2)
        .onClick(() => {
          // 前进
        })
    }
    .width('100%')
    .height('100%')
    .padding(16)
    .backgroundColor('#1F1F1F')
    .justifyContent(FlexAlign.SpaceBetween)
  }
}

