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
 * 书签信息接口
 */
interface BookmarkInfo {
  id: number;
  title: string;
  url: string;
}
/**
 * 书签栏组件
 */
@ComponentV2
export struct BookmarkBar {
  @Param onBookmarkClick?: (url: string) => void = undefined;
  
  @Local bookmarks: BookmarkInfo[] = [
    { id: 1, title: '示例网站', url: 'https://www.example.com' }
  ];
  
  build() {
    Scroll() {
      Row() {
        ForEach(this.bookmarks, (bookmark: BookmarkInfo) => {
          Button(bookmark.title)
            .height(28)
            .fontSize(12)
            .backgroundColor('#F5F5F5')
            .borderRadius(4)
            .margin({ right: 8 })
            .onClick(() => {
              if (this.onBookmarkClick) {
                this.onBookmarkClick(bookmark.url);
              }
            })
        }, (bookmark: BookmarkInfo) => bookmark.id.toString())
      }
      .padding({ left: 8, right: 8 })
    }
    .width('100%')
    .height('100%')
    .scrollable(ScrollDirection.Horizontal)
    .backgroundColor('#F5F5F5')
  }
}

