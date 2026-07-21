/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import { NativeContext, WindowStatus, WindowRect, PanEvent, PanAction } from './NativeContext';
import window from '@ohos.window';

/**
 * WebWindow组件属性接口
 */
export interface WebWindowOptions {
  url?: string;
  width?: number | string;
  height?: number | string;
  onPageLoadStart?: (url: string) => void;
  onPageLoadFinish?: (url: string) => void;
  onTitleReceive?: (title: string) => void;
  onError?: (error: Error) => void;
}

/**
 * WebWindow组件
 * 基于XComponent封装的WebView组件
 */
@Component
export struct WebWindow {
  // 组件属性
  @Param url: string = '';
  @Param width: number | string = '100%';
  @Param height: number | string = '100%';
  
  // 回调函数
  @Param onPageLoadStart?: (url: string) => void;
  @Param onPageLoadFinish?: (url: string) => void;
  @Param onTitleReceive?: (title: string) => void;
  @Param onError?: (error: Error) => void;
  
  // 内部状态
  @State currentUrl: string = '';
  @State pageTitle: string = '';
  @State isLoading: boolean = false;
  
  // XComponent控制器
  xComponentController: XComponentController = new XComponentController();
  
  // 原生上下文
  private nativeContext: NativeContext | null = null;
  
  // 组件ID（用于标识XComponent）
  private readonly componentId: string = 'webview_' + Date.now().toString();
  
  // 手势状态
  private panStartX: number = 0;
  private panStartY: number = 0;
  private panLastX: number = 0;
  private panLastY: number = 0;
  private panStartTime: number = 0;
  
  aboutToAppear() {
    this.currentUrl = this.url;
    this.initWindowListeners();
  }
  
  aboutToDisappear() {
    this.destroyNativeContext();
    this.removeWindowListeners();
  }
  
  build() {
    Column() {
      XComponent({
        id: this.componentId,
        type: XComponentType.SURFACE,
        libraryname: 'libweb_engine'  // 原生库名称，对应libweb_engine.so
      })
        .controller(this.xComponentController)
        .width(this.width)
        .height(this.height)
        .onLoad(() => {
          this.initNativeContext();
        })
        .onDestroy(() => {
          this.destroyNativeContext();
        })
        .gesture(
          // 平移手势
          PanGesture({ fingers: 1, direction: PanDirection.All })
            .onActionStart((event: GestureEvent) => {
              this.onPanStart(event);
            })
            .onActionUpdate((event: GestureEvent) => {
              this.onPanUpdate(event);
            })
            .onActionEnd((event: GestureEvent) => {
              this.onPanEnd(event);
            })
            .onActionCancel(() => {
              this.onPanCancel();
            })
        )
    }
    .width('100%')
    .height('100%')
  }
  
  /**
   * 初始化原生上下文
   */
  private initNativeContext(): void {
    try {
      // 获取XComponent的nativeContext
      const context = this.xComponentController.getXComponentContext();
      if (context) {
        this.nativeContext = new NativeContext(this.componentId);
        this.nativeContext.init(context);
        
        // 通知窗口显示
        this.nativeContext.OnWindowStatusChange(WindowStatus.SHOWN);
        
        // 如果URL已设置，加载页面
        if (this.currentUrl && this.currentUrl.trim() !== '') {
          this.loadUrl(this.currentUrl);
        }
      } else {
        console.error('Failed to get XComponent context');
        if (this.onError) {
          this.onError(new Error('Failed to initialize native context'));
        }
      }
    } catch (error) {
      console.error('Failed to initialize native context:', error);
      if (this.onError) {
        this.onError(error as Error);
      }
    }
  }
  
  /**
   * 销毁原生上下文
   */
  private destroyNativeContext(): void {
    if (this.nativeContext) {
      this.nativeContext.destroy();
      this.nativeContext = null;
    }
  }
  
  /**
   * 初始化窗口监听器
   */
  private initWindowListeners(): void {
    try {
      // 监听窗口状态变化
      window.getLastWindow(getContext(this)).then((win: window.Window) => {
        win.on('windowStatusChange', (status: window.WindowStatus) => {
          this.onWindowStatusChange(status);
        });
        
        win.on('windowSizeChange', (size: window.Size) => {
          this.onWindowSizeChange(size);
        });
      }).catch((error: Error) => {
        console.error('Failed to get window:', error);
      });
    } catch (error) {
      console.error('Failed to init window listeners:', error);
    }
  }
  
  /**
   * 移除窗口监听器
   */
  private removeWindowListeners(): void {
    // 窗口监听器会在窗口销毁时自动移除
  }
  
  /**
   * 窗口状态变化处理
   */
  private onWindowStatusChange(status: window.WindowStatus): void {
    if (!this.nativeContext) {
      return;
    }
    
    let windowStatus: WindowStatus;
    switch (status) {
      case window.WindowStatus.SHOWN:
        windowStatus = WindowStatus.SHOWN;
        break;
      case window.WindowStatus.HIDDEN:
        windowStatus = WindowStatus.HIDDEN;
        break;
      default:
        return;
    }
    
    this.nativeContext.OnWindowStatusChange(windowStatus);
  }
  
  /**
   * 窗口大小变化处理
   */
  private onWindowSizeChange(size: window.Size): void {
    if (!this.nativeContext) {
      return;
    }
    
    const rect: WindowRect = {
      x: 0,
      y: 0,
      width: size.width,
      height: size.height
    };
    
    this.nativeContext.OnWindowRectChange(rect);
  }
  
  /**
   * 手势开始处理
   */
  private onPanStart(event: GestureEvent): void {
    if (!this.nativeContext) {
      return;
    }
    
    this.panStartX = event.offsetX;
    this.panStartY = event.offsetY;
    this.panLastX = event.offsetX;
    this.panLastY = event.offsetY;
    this.panStartTime = Date.now();
    
    const panEvent: PanEvent = {
      action: PanAction.START,
      x: event.offsetX,
      y: event.offsetY,
      deltaX: 0,
      deltaY: 0,
      velocityX: 0,
      velocityY: 0,
      timestamp: this.panStartTime
    };
    
    this.nativeContext.OnPanEvent(panEvent);
  }
  
  /**
   * 手势更新处理
   */
  private onPanUpdate(event: GestureEvent): void {
    if (!this.nativeContext) {
      return;
    }
    
    const deltaX = event.offsetX - this.panLastX;
    const deltaY = event.offsetY - this.panLastY;
    const deltaTime = Date.now() - this.panStartTime;
    
    // 计算速度（像素/秒）
    const velocityX = deltaTime > 0 ? (deltaX / deltaTime) * 1000 : 0;
    const velocityY = deltaTime > 0 ? (deltaY / deltaTime) * 1000 : 0;
    
    this.panLastX = event.offsetX;
    this.panLastY = event.offsetY;
    
    const panEvent: PanEvent = {
      action: PanAction.UPDATE,
      x: event.offsetX,
      y: event.offsetY,
      deltaX: deltaX,
      deltaY: deltaY,
      velocityX: velocityX,
      velocityY: velocityY,
      timestamp: Date.now()
    };
    
    this.nativeContext.OnPanEvent(panEvent);
  }
  
  /**
   * 手势结束处理
   */
  private onPanEnd(event: GestureEvent): void {
    if (!this.nativeContext) {
      return;
    }
    
    const deltaX = event.offsetX - this.panLastX;
    const deltaY = event.offsetY - this.panLastY;
    const deltaTime = Date.now() - this.panStartTime;
    
    // 计算最终速度
    const velocityX = deltaTime > 0 ? (deltaX / deltaTime) * 1000 : 0;
    const velocityY = deltaTime > 0 ? (deltaY / deltaTime) * 1000 : 0;
    
    const panEvent: PanEvent = {
      action: PanAction.END,
      x: event.offsetX,
      y: event.offsetY,
      deltaX: deltaX,
      deltaY: deltaY,
      velocityX: velocityX,
      velocityY: velocityY,
      timestamp: Date.now()
    };
    
    this.nativeContext.OnPanEvent(panEvent);
    
    // 重置手势状态
    this.panStartX = 0;
    this.panStartY = 0;
    this.panLastX = 0;
    this.panLastY = 0;
    this.panStartTime = 0;
  }
  
  /**
   * 手势取消处理
   */
  private onPanCancel(): void {
    if (!this.nativeContext) {
      return;
    }
    
    const panEvent: PanEvent = {
      action: PanAction.CANCEL,
      x: this.panLastX,
      y: this.panLastY,
      deltaX: 0,
      deltaY: 0,
      velocityX: 0,
      velocityY: 0,
      timestamp: Date.now()
    };
    
    this.nativeContext.OnPanEvent(panEvent);
    
    // 重置手势状态
    this.panStartX = 0;
    this.panStartY = 0;
    this.panLastX = 0;
    this.panLastY = 0;
    this.panStartTime = 0;
  }
  
  /**
   * 加载URL
   * @param url URL地址
   */
  loadUrl(url: string): void {
    if (!url || url.trim() === '') {
      console.warn('Invalid URL:', url);
      return;
    }
    
    this.currentUrl = url;
    this.isLoading = true;
    
    if (this.onPageLoadStart) {
      this.onPageLoadStart(url);
    }
    
    if (this.nativeContext) {
      this.nativeContext.Load(url);
    } else {
      console.warn('NativeContext is not initialized, URL will be loaded after initialization');
    }
  }
  
  /**
   * 重新加载
   */
  reload(): void {
    if (this.currentUrl) {
      this.loadUrl(this.currentUrl);
    }
  }
  
  /**
   * 获取当前URL
   * @returns string
   */
  getUrl(): string {
    return this.currentUrl;
  }
  
  /**
   * 获取页面标题
   * @returns string
   */
  getTitle(): string {
    return this.pageTitle;
  }
}

