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

import deviceInfo from '@ohos.deviceInfo';

/**
 * 设备类型枚举
 */
export enum DeviceType {
  PHONE = 'phone',      // 手机
  TABLET = 'tablet',    // 汽车和电视
  PC = 'pc'            // 平板和电脑
}

/**
 * UI Profile类型
 */
export enum UIProfile {
  PHONE = 'phone',
  LEANBACK = 'leanback',  // 电视
  AUTO = 'auto',          // 汽车
  PC = 'pc'              // 平板和电脑
}

/**
 * 设备类型检测工具类
 */
export class DeviceTypeDetector {
  /**
   * 获取设备类型
   * @returns DeviceType 设备类型
   */
  static getDeviceType(): DeviceType {
    try {
      // HarmonyOS deviceInfo API - deviceType返回字符串
      const deviceTypeStr = deviceInfo.deviceType;
      
      // 根据设备类型字符串判断
      if (deviceTypeStr === 'phone') {
        return DeviceType.PHONE;
      } else if (deviceTypeStr === 'tv' || deviceTypeStr === 'car') {
        return DeviceType.TABLET;
      } else if (deviceTypeStr === 'tablet' || deviceTypeStr === 'desktop') {
        return DeviceType.PC;
      } else {
        // 默认返回手机类型
        return DeviceType.PHONE;
      }
    } catch (error) {
      console.error('Failed to get device type:', error);
      return DeviceType.PHONE;
    }
  }
  
  /**
   * 获取UI Profile
   * @returns UIProfile UI配置类型
   */
  static getUIProfile(): UIProfile {
    const deviceType = this.getDeviceType();
    
    switch (deviceType) {
      case DeviceType.PHONE:
        return UIProfile.PHONE;
      case DeviceType.TABLET:
        // 根据具体设备类型返回leanback或auto
        try {
          const deviceTypeStr = deviceInfo.deviceType;
          if (deviceTypeStr === 'tv') {
            return UIProfile.LEANBACK;
          } else if (deviceTypeStr === 'car') {
            return UIProfile.AUTO;
          }
          return UIProfile.LEANBACK;
        } catch (error) {
          return UIProfile.LEANBACK;
        }
      case DeviceType.PC:
        return UIProfile.PC;
      default:
        return UIProfile.PHONE;
    }
  }
  
  /**
   * 判断是否为手机设备
   * @returns boolean
   */
  static isPhone(): boolean {
    return this.getDeviceType() === DeviceType.PHONE;
  }
  
  /**
   * 判断是否为Tablet设备（汽车/电视）
   * @returns boolean
   */
  static isTablet(): boolean {
    return this.getDeviceType() === DeviceType.TABLET;
  }
  
  /**
   * 判断是否为PC设备（平板/电脑）
   * @returns boolean
   */
  static isPC(): boolean {
    return this.getDeviceType() === DeviceType.PC;
  }
  
  /**
   * 判断是否为电视设备
   * @returns boolean
   */
  static isTV(): boolean {
    try {
      return deviceInfo.deviceType === 'tv';
    } catch (error) {
      return false;
    }
  }
  
  /**
   * 判断是否为汽车设备
   * @returns boolean
   */
  static isAuto(): boolean {
    try {
      return deviceInfo.deviceType === 'car';
    } catch (error) {
      return false;
    }
  }
}

