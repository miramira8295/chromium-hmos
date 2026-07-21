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

import { DeviceTypeDetector, DeviceType } from './DeviceType';

/**
 * UI管理器
 * 根据设备类型加载对应的UI组件
 */
export class UIManager {
  /**
   * 加载主UI组件
   * @returns string UI组件路径
   */
  static loadUI(): string {
    const deviceType = DeviceTypeDetector.getDeviceType();
    
    switch (deviceType) {
      case DeviceType.PHONE:
        return 'pages/phone/Index';
      case DeviceType.TABLET:
        return 'pages/tablet/Index';
      case DeviceType.PC:
        return 'pages/pc/Index';
      default:
        return 'pages/phone/Index';
    }
  }
  
  /**
   * 获取设备类型
   * @returns DeviceType
   */
  static getDeviceType(): DeviceType {
    return DeviceTypeDetector.getDeviceType();
  }
  
  /**
   * 判断是否应该使用手机UI
   * @returns boolean
   */
  static shouldUsePhoneUI(): boolean {
    return DeviceTypeDetector.isPhone();
  }
  
  /**
   * 判断是否应该使用Tablet UI（汽车/电视）
   * @returns boolean
   */
  static shouldUseTabletUI(): boolean {
    return DeviceTypeDetector.isTablet();
  }
  
  /**
   * 判断是否应该使用PC UI（平板/电脑）
   * @returns boolean
   */
  static shouldUsePCUI(): boolean {
    return DeviceTypeDetector.isPC();
  }
  
  /**
   * 判断是否为电视设备
   * @returns boolean
   */
  static isTV(): boolean {
    return DeviceTypeDetector.isTV();
  }
  
  /**
   * 判断是否为汽车设备
   * @returns boolean
   */
  static isAuto(): boolean {
    return DeviceTypeDetector.isAuto();
  }
}

