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
 * NWeb HAP包导出文件
 * 导出WebWindow组件和相关工具类
 */

// 导出WebWindow组件
export { WebWindow, WebWindowOptions } from './components/webwindow/WebWindow';

// 导出NativeContext相关类型
export { 
  NativeContext, 
  WindowStatus, 
  WindowRect, 
  PanEvent, 
  PanAction 
} from './components/webwindow/NativeContext';

// 导出工具类
export { DeviceTypeDetector, DeviceType, UIProfile } from './utils/DeviceType';
export { UIManager } from './utils/UIManager';

