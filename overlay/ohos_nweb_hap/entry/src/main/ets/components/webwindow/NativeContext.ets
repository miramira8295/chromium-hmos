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
 * 窗口状态枚举
 */
export enum WindowStatus {
  CREATED = 0,
  SHOWN = 1,
  HIDDEN = 2,
  DESTROYED = 3,
  FOCUSED = 4,
  UNFOCUSED = 5
}

/**
 * 手势动作枚举
 */
export enum PanAction {
  START = 0,
  UPDATE = 1,
  END = 2,
  CANCEL = 3
}

/**
 * 窗口矩形结构
 */
export interface WindowRect {
  x: number;
  y: number;
  width: number;
  height: number;
}

/**
 * 手势事件结构
 */
export interface PanEvent {
  action: PanAction;
  x: number;
  y: number;
  deltaX: number;
  deltaY: number;
  velocityX: number;
  velocityY: number;
  timestamp: number;
}

/**
 * 原生上下文类
 * 封装与NWeb C++ API的交互
 */
export class NativeContext {
  private xComponentId: string;
  private nativeContext: any = null;
  
  constructor(xComponentId: string) {
    this.xComponentId = xComponentId;
  }
  
  /**
   * 初始化原生上下文
   * @param context XComponent的nativeContext
   */
  init(context: any): void {
    this.nativeContext = context;
    if (this.nativeContext) {
      // 通知窗口创建
      this.OnWindowStatusChange(WindowStatus.CREATED);
    }
  }
  
  /**
   * 窗口状态变化
   * @param status 窗口状态
   */
  OnWindowStatusChange(status: WindowStatus): void {
    if (!this.nativeContext) {
      console.error('NativeContext is not initialized');
      return;
    }
    
    try {
      // 调用原生方法 OnWindowStatusChange
      // 注意：实际调用方式需要根据XComponent的nativeContext API调整
      if (this.nativeContext.OnWindowStatusChange) {
        this.nativeContext.OnWindowStatusChange(this.xComponentId, status);
      } else {
        console.warn('OnWindowStatusChange method not found in nativeContext');
      }
    } catch (error) {
      console.error('Failed to call OnWindowStatusChange:', error);
    }
  }
  
  /**
   * 窗口矩形变化
   * @param rect 窗口矩形
   */
  OnWindowRectChange(rect: WindowRect): void {
    if (!this.nativeContext) {
      console.error('NativeContext is not initialized');
      return;
    }
    
    // 参数验证
    if (rect.width <= 0 || rect.height <= 0) {
      console.warn('Invalid window rect:', rect);
      return;
    }
    
    try {
      // 调用原生方法 OnWindowRectChange
      if (this.nativeContext.OnWindowRectChange) {
        this.nativeContext.OnWindowRectChange(
          this.xComponentId,
          rect.x,
          rect.y,
          rect.width,
          rect.height
        );
      } else {
        console.warn('OnWindowRectChange method not found in nativeContext');
      }
    } catch (error) {
      console.error('Failed to call OnWindowRectChange:', error);
    }
  }
  
  /**
   * 手势事件
   * @param event 手势事件
   */
  OnPanEvent(event: PanEvent): void {
    if (!this.nativeContext) {
      console.error('NativeContext is not initialized');
      return;
    }
    
    try {
      // 调用原生方法 OnPanEvent
      if (this.nativeContext.OnPanEvent) {
        this.nativeContext.OnPanEvent(
          this.xComponentId,
          event.action,
          event.x,
          event.y,
          event.deltaX,
          event.deltaY,
          event.velocityX,
          event.velocityY,
          event.timestamp
        );
      } else {
        console.warn('OnPanEvent method not found in nativeContext');
      }
    } catch (error) {
      console.error('Failed to call OnPanEvent:', error);
    }
  }
  
  /**
   * 加载URL
   * @param url URL地址
   */
  Load(url: string): void {
    if (!this.nativeContext) {
      console.error('NativeContext is not initialized');
      return;
    }
    
    if (!url || url.trim() === '') {
      console.warn('Invalid URL:', url);
      return;
    }
    
    try {
      // 调用原生方法 Load
      if (this.nativeContext.Load) {
        this.nativeContext.Load(this.xComponentId, url);
      } else {
        console.warn('Load method not found in nativeContext');
      }
    } catch (error) {
      console.error('Failed to call Load:', error);
    }
  }
  
  /**
   * 销毁原生上下文
   */
  destroy(): void {
    if (this.nativeContext) {
      // 通知窗口销毁
      this.OnWindowStatusChange(WindowStatus.DESTROYED);
      this.nativeContext = null;
    }
  }
  
  /**
   * 检查原生上下文是否已初始化
   * @returns boolean
   */
  isInitialized(): boolean {
    return this.nativeContext !== null;
  }
}

