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

import { common } from '@kit.AbilityKit';
import { WebWindow } from '../components/webwindow/WebWindow';
import { MobileBrowserOverlay } from '../components/mobile/MobileBrowserOverlay';
import { CurrentTabCastSession } from '../components/mobile/CurrentTabCastSession';
import { PwaCapsuleOverlay } from '../components/pwa/PwaCapsuleOverlay';
import { BrowserOnboarding } from '../components/onboarding/BrowserOnboarding';
import {
  AuxiliaryWindowState,
  BrowserCommandPayload,
  BrowserRuntimeEvent,
  BrowserStateSnapshot
} from '../components/webwindow/NativeContext';
import { CHROMIUM_HOME_URL } from '../utils/DeviceType';
import { HuaweiShareAdapter } from '../utils/HuaweiShareAdapter';
import { HarmonyFilePickerAdapter, HarmonyFilePickerResult } from '../utils/HarmonyFilePickerAdapter';
import { SystemPrintAdapter } from '../utils/SystemPrintAdapter';
import { BrowserProfileState } from '../utils/profile/BrowserProfileService';

const EMPTY_BROWSER_STATE: BrowserStateSnapshot = {
  version: 1,
  mobileUi: false,
  uiFamily: '',
  ready: false,
  tabCount: 0,
  activeTabIndex: -1,
  tabs: [],
  url: CHROMIUM_HOME_URL,
  domain: '',
  title: 'Chromium',
  loading: false,
  canGoBack: false,
  canGoForward: false,
  isPwaWindow: false,
  pwaAppId: '',
  pwaStartUrl: ''
};

@Entry
@Component
struct AuraShell {
  @StorageLink('auraRoutingRevision') routingRevision: number = 0;
  @StorageLink('auraStartupConfig') startupConfigText: string = '';
  @StorageLink('auraStartUrl') startUrl: string = CHROMIUM_HOME_URL;
  @StorageLink('auraAppVisible') appVisible: boolean = true;
  @StorageLink('auraThemeFontId') themeFontId: string = '';
  @StorageLink('auraThemeFontRevision') themeFontRevision: number = 0;
  @StorageLink('auraOnboardingReady') onboardingReady: boolean = false;
  @StorageLink('auraOnboardingComplete') onboardingComplete: boolean = false;
  @StorageLink('auraProfileId') profileId: string = 'local';
  @StorageLink('auraProfileKind') profileKind: string = 'local';
  @StorageLink('auraSyncMode') syncMode: string = 'off';
  @State private browserState: BrowserStateSnapshot = EMPTY_BROWSER_STATE;
  @State private browserCommandText: string = '';
  @State private browserCommandRevision: number = 0;
  @State private auxiliaryWindows: AuxiliaryWindowState[] = [];
  @State private activeAuxiliaryWidget: number = 0;
  @State private auxiliarySheetVisible: boolean = false;
  @State private auxiliaryDismissWidget: number = 0;
  @State private auxiliaryDismissRevision: number = 0;
  @State private windowStatus: number = 0;
  @State private pwaMenuSheetVisible: boolean = false;
  private readonly currentTabCastSession: CurrentTabCastSession = new CurrentTabCastSession();

  aboutToDisappear(): void {
    this.currentTabCastSession.stop().catch((error: Error): void => {
      console.error('Failed to stop current-tab cast session:', error);
    });
  }

  build() {
    Stack({ alignContent: Alignment.Bottom }) {
      if (!this.onboardingReady) {
        LoadingProgress()
          .width(40)
          .height(40)
          .color($r('app.color.accent_primary'))
          .align(Alignment.Center)
      } else if (!this.onboardingComplete) {
        BrowserOnboarding({
          onComplete: (state: BrowserProfileState): void => {
            this.profileId = state.profileId;
            this.profileKind = state.profileKind;
            this.syncMode = state.syncMode;
            this.onboardingComplete = state.onboardingComplete;
          }
        })
      } else {
        WebWindow({
        url: this.startUrl,
        profileId: this.profileId,
        startupConfigText: this.startupConfigText,
        routingRevision: this.routingRevision,
        appVisible: this.appVisible,
        themeFontId: this.themeFontId,
        themeFontRevision: this.themeFontRevision,
        browserCommandText: this.browserCommandText,
        browserCommandRevision: this.browserCommandRevision,
        auxiliaryDismissWidget: this.auxiliaryDismissWidget,
        auxiliaryDismissRevision: this.auxiliaryDismissRevision,
        onBrowserState: (state: BrowserStateSnapshot): void => {
          this.browserState = state;
          this.currentTabCastSession.update(state);
        },
        onRuntimeEvent: (event: BrowserRuntimeEvent): void => {
          this.handleRuntimeEvent(event);
        },
        onWindowStatus: (status: number): void => {
          this.windowStatus = status;
        },
        onAuxiliaryWindowState: (state: AuxiliaryWindowState): void => {
          this.handleAuxiliaryWindowState(state);
        }
        })
          .width('100%')
          .height('100%')
        if (this.isMobilePhoneUi()) {
          MobileBrowserOverlay({
            browserState: this.browserState,
            onCommand: (command: BrowserCommandPayload): void => {
              this.executeBrowserCommand(command);
            }
          })
        }
        if (this.browserState.isPwaWindow) {
          PwaCapsuleOverlay({
            browserState: this.browserState,
            windowStatus: this.windowStatus,
            onCommand: (command: BrowserCommandPayload): void => {
              this.executeBrowserCommand(command);
            }
          })
            .align(Alignment.Top)
            .bindSheet($$this.pwaMenuSheetVisible, this.PwaMenuSheet, {
              height: SheetSize.FIT_CONTENT,
              showClose: false
            })
        }
      }
    }
    .width('100%')
    .height('100%')
    .backgroundColor($r('app.color.browser_canvas'))
    .bindSheet($$this.auxiliarySheetVisible, this.AuxiliaryWindowSheet, {
      height: SheetSize.LARGE,
      showClose: false,
      onWillDismiss: (action: DismissSheetAction): void => {
        this.requestAuxiliaryWindowDismiss(this.activeAuxiliaryWidget);
        if (this.auxiliaryWindows.length <= 1) {
          action.dismiss();
        }
      }
    })
  }

  @Builder
  private AuxiliaryWindowSheet() {
    Column() {
      Row() {
        Text('NaviLoom')
          .fontSize(18)
          .fontWeight(FontWeight.Medium)
          .fontColor($r('app.color.text_primary'))
        Blank()
        Button({ type: ButtonType.Circle }) {
          Image($r('app.media.chromium_close'))
            .width(20)
            .height(20)
            .fillColor($r('app.color.icon_primary'))
        }
        .width(40)
        .height(40)
        .backgroundColor(Color.Transparent)
        .onClick(() => {
          this.requestAuxiliaryWindowDismiss(this.activeAuxiliaryWidget);
        })
      }
      .width('100%')
      .height(48)

      if (this.auxiliaryWindows.length > 1) {
        Scroll() {
          Row({ space: 8 }) {
            ForEach(this.auxiliaryWindows, (state: AuxiliaryWindowState, index: number) => {
              Button(`窗口 ${index + 1}`)
                .height(36)
                .fontSize(14)
                .fontColor(state.widget === this.activeAuxiliaryWidget ?
                  $r('app.color.on_accent') : $r('app.color.text_secondary'))
                .backgroundColor(state.widget === this.activeAuxiliaryWidget ?
                  $r('app.color.accent_primary') : $r('app.color.surface_secondary'))
                .borderRadius(8)
                .onClick(() => {
                  this.activeAuxiliaryWidget = state.widget;
                })
            }, (state: AuxiliaryWindowState): string => state.widget.toString())
          }
        }
        .scrollable(ScrollDirection.Horizontal)
        .scrollBar(BarState.Off)
        .width('100%')
        .height(44)
      }

      Stack() {
        ForEach(this.auxiliaryWindows, (state: AuxiliaryWindowState) => {
          XComponent({
            id: state.componentId,
            type: XComponentType.SURFACE,
            libraryname: 'web_engine'
          })
            .id(state.componentId)
            .width('100%')
            .height('100%')
            .focusable(state.widget === this.activeAuxiliaryWidget)
            .defaultFocus(state.widget === this.activeAuxiliaryWidget)
            .visibility(state.widget === this.activeAuxiliaryWidget ?
              Visibility.Visible : Visibility.Hidden)
            .zIndex(state.widget === this.activeAuxiliaryWidget ? 1 : 0)
        }, (state: AuxiliaryWindowState): string => state.componentId)
      }
      .width('100%')
      .layoutWeight(1)
      .backgroundColor($r('app.color.surface_primary'))
    }
    .width('100%')
    .height('100%')
    .padding({ left: 12, right: 12, bottom: 12 })
    .backgroundColor($r('app.color.surface_primary'))
  }

  @Builder
  private PwaMenuSheet() {
    Column({ space: 8 }) {
      Text(this.browserState.title || 'Chromium')
        .width('100%')
        .maxLines(1)
        .textOverflow({ overflow: TextOverflow.Ellipsis })
        .fontSize(18)
        .fontWeight(FontWeight.Medium)
        .fontColor($r('app.color.text_primary'))
        .margin({ bottom: 4 })
      this.PwaMenuButton('\u534e\u4e3a\u5206\u4eab', $r('app.media.chromium_share'), (): void => {
        this.pwaMenuSheetVisible = false;
        this.executeBrowserCommand({ command: 'share' });
      })
      this.PwaMenuButton('\u7cfb\u7edf\u6253\u5370', $r('app.media.chromium_print'), (): void => {
        this.pwaMenuSheetVisible = false;
        this.executeBrowserCommand({ command: 'print' });
      })
      this.PwaMenuButton('\u5237\u65b0', $r('app.media.chromium_reload'), (): void => {
        this.pwaMenuSheetVisible = false;
        this.executeBrowserCommand({ command: 'reload' });
      })
    }
    .width('100%')
    .padding({ left: 20, right: 20, top: 20, bottom: 24 })
    .backgroundColor($r('app.color.surface_primary'))
  }

  @Builder
  private PwaMenuButton(label: string, icon: Resource, action: () => void) {
    Button({ type: ButtonType.Normal, stateEffect: true }) {
      Row({ space: 12 }) {
        Image(icon)
          .width(22)
          .height(22)
          .fillColor($r('app.color.icon_primary'))
        Text(label)
          .fontSize(16)
          .fontColor($r('app.color.text_primary'))
        Blank()
      }
      .width('100%')
    }
    .width('100%')
    .height(48)
    .padding({ left: 12, right: 12 })
    .borderRadius(8)
    .backgroundColor($r('app.color.surface_secondary'))
    .onClick(action)
  }

  private executeBrowserCommand(command: BrowserCommandPayload): void {
    this.browserCommandText = JSON.stringify(command);
    this.browserCommandRevision += 1;
  }

  private handleRuntimeEvent(event: BrowserRuntimeEvent): void {
    if (event.event === 'pwaMenuFallback') {
      this.pwaMenuSheetVisible = true;
      return;
    }
    if (event.event === 'pwaInstalled' && this.isDesktopAuraUi()) {
      AlertDialog.show({
        title: '\u5b89\u88c5\u5b8c\u6210',
        message: '\u606d\u559c\u60a8\uff0c\u60a8\u5df2\u7ecf\u5c06\u5b83\u4f5c\u4e3a\u5c0f\u7a0b\u5e8f\u5b89\u88c5\u5230\u672c\u673a\u4e86\u3002\u60a8\u53ef\u4ee5\u6dfb\u52a0\u670d\u52a1\u5361\u7247\uff0c\u5728\u684c\u9762\u663e\u793a\u5c0f\u7a0b\u5e8f\uff01',
        confirm: {
          value: '\u5b8c\u6210',
          action: (): void => {
          }
        }
      });
      return;
    }

    const context = this.getUIContext().getHostContext() as common.UIAbilityContext | undefined;
    if (!context) {
      if (event.event === 'filePickerRequested') {
        this.completeFilePicker({
          requestId: event.requestId ?? 0,
          paths: [],
          fileTypeIndex: event.fileTypeIndex ?? 0,
          canceled: true
        });
      }
      return;
    }
    if (event.event === 'systemPrintReady' && event.filePath) {
      SystemPrintAdapter.printPdf(context, event.filePath).catch((error: Error): void => {
        console.error('System print failed:', error);
      });
    } else if (event.event === 'shareRequested' && event.url) {
      HuaweiShareAdapter.sharePage(context, event.url, event.title ?? event.url)
        .catch((error: Error): void => {
          console.error('Huawei Share failed:', error);
        });
    } else if (event.event === 'castRequested') {
      this.currentTabCastSession.openPicker(context, this.browserState)
        .catch((error: Error): void => {
          console.error('HarmonyOS cast picker failed:', error);
        });
    } else if (event.event === 'filePickerRequested') {
      HarmonyFilePickerAdapter.show(context, event)
        .then((result: HarmonyFilePickerResult): void => {
          this.completeFilePicker(result);
        })
        .catch((error: Error): void => {
          console.error('HarmonyOS file picker failed:', error);
          this.completeFilePicker({
            requestId: event.requestId ?? 0,
            paths: [],
            fileTypeIndex: event.fileTypeIndex ?? 0,
            canceled: true
          });
        });
    } else if (event.event === 'systemPrintFailed') {
      console.error(`Chromium PDF generation failed: ${event.reason ?? 'unknown'}`);
    }
  }

  private completeFilePicker(result: HarmonyFilePickerResult): void {
    this.executeBrowserCommand({
      command: 'filePickerResult',
      requestId: result.requestId,
      paths: result.paths,
      fileTypeIndex: result.fileTypeIndex,
      canceled: result.canceled
    });
  }

  private handleAuxiliaryWindowState(state: AuxiliaryWindowState): void {
    if (!this.isFullscreenWindow()) {
      return;
    }

    const remaining = this.auxiliaryWindows.filter(
      (item: AuxiliaryWindowState): boolean => item.widget !== state.widget
    );
    if (state.visible && !state.destroyed) {
      remaining.push(state);
      remaining.sort((left: AuxiliaryWindowState, right: AuxiliaryWindowState): number =>
        left.stackingOrder - right.stackingOrder);
      this.activeAuxiliaryWidget = state.widget;
    } else if (this.activeAuxiliaryWidget === state.widget) {
      this.activeAuxiliaryWidget = remaining.length > 0 ? remaining[remaining.length - 1].widget : 0;
    }

    this.auxiliaryWindows = remaining;
    this.auxiliarySheetVisible = remaining.length > 0;
  }

  private requestAuxiliaryWindowDismiss(widget: number): void {
    if (widget <= 0) {
      return;
    }
    this.auxiliaryDismissWidget = widget;
    this.auxiliaryDismissRevision += 1;
  }

  private isMobilePhoneUi(): boolean {
    if (!this.startupConfigText || this.startupConfigText.trim().length === 0) {
      return this.browserState.uiFamily === 'mobile_phone';
    }

    try {
      const startupConfig = JSON.parse(this.startupConfigText) as Record<string, Object>;
      return String(startupConfig['uiFamily'] ?? '') === 'mobile_phone';
    } catch (error) {
      return this.browserState.uiFamily === 'mobile_phone';
    }
  }

  private isDesktopAuraUi(): boolean {
    if (!this.startupConfigText || this.startupConfigText.trim().length === 0) {
      return this.browserState.uiFamily === 'aura_pc';
    }
    try {
      const startupConfig = JSON.parse(this.startupConfigText) as Record<string, Object>;
      return String(startupConfig['uiFamily'] ?? '') === 'aura_pc';
    } catch (error) {
      return this.browserState.uiFamily === 'aura_pc';
    }
  }

  private isFullscreenWindow(): boolean {
    if (!this.startupConfigText || this.startupConfigText.trim().length === 0) {
      return this.isMobilePhoneUi();
    }
    try {
      const startupConfig = JSON.parse(this.startupConfigText) as Record<string, Object>;
      return String(startupConfig['windowMode'] ?? '') === 'fullscreen';
    } catch (error) {
      return this.isMobilePhoneUi();
    }
  }
}
