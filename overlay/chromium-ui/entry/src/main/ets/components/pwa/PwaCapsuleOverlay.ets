import { common } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BrowserCommandPayload, BrowserStateSnapshot } from '../webwindow/NativeContext';

@Component
export struct PwaCapsuleOverlay {
  @Prop browserState: BrowserStateSnapshot;
  @Prop windowStatus: number = 0;
  onCommand: (command: BrowserCommandPayload) => void = (_command: BrowserCommandPayload): void => {};

  build() {
    Row() {
      Row() {
        this.CapsuleButton($r('app.media.chromium_back'), '\u8fd4\u56de',
          (): void => this.onCommand({ command: 'back' }), this.browserState.canGoBack)
        this.CapsuleButton($r('app.media.chromium_home'), '\u56de\u5230\u5c0f\u7a0b\u5e8f\u4e3b\u9875',
          (): void => this.onCommand({
            command: 'pwaHome',
            url: this.browserState.pwaStartUrl || this.browserState.url
          }))
      }
      .height(44)
      .padding({ left: 4, right: 4 })
      .borderRadius(22)
      .backgroundColor($r('app.color.surface_floating'))
      .shadow({ radius: 12, color: $r('app.color.shadow'), offsetY: 3 })

      Blank()

      Row() {
        this.CapsuleButton($r('app.media.chromium_more'), '\u66f4\u591a',
          (): void => this.onCommand({ command: 'pwaMenu' }))
        if (this.windowStatus === window.WindowStatusType.FLOATING) {
          this.CapsuleButton($r('app.media.chromium_maximize'), '\u6700\u5927\u5316',
            (): void => this.runWindowAction('maximize'))
          this.CapsuleButton($r('app.media.chromium_minimize'), '\u6700\u5c0f\u5316',
            (): void => this.runWindowAction('minimize'))
        }
        this.CapsuleButton($r('app.media.chromium_close'), '\u5173\u95ed\u5c0f\u7a0b\u5e8f',
          (): void => this.onCommand({ command: 'pwaClose' }))
      }
      .height(44)
      .padding({ left: 4, right: 4 })
      .borderRadius(22)
      .backgroundColor($r('app.color.surface_floating'))
      .shadow({ radius: 12, color: $r('app.color.shadow'), offsetY: 3 })
    }
    .width('100%')
    .height(60)
    .padding({ left: 12, right: 12, top: 8, bottom: 8 })
  }

  @Builder
  private CapsuleButton(icon: Resource, label: string, action: () => void, enabled: boolean = true) {
    Button({ type: ButtonType.Circle, stateEffect: true }) {
      Image(icon)
        .width(20)
        .height(20)
        .fillColor($r('app.color.icon_primary'))
    }
    .width(36)
    .height(36)
    .backgroundColor(Color.Transparent)
    .enabled(enabled)
    .opacity(enabled ? 1 : 0.42)
    .accessibilityText(label)
    .onClick(action)
  }

  private runWindowAction(action: 'maximize' | 'minimize'): void {
    const context = this.getUIContext().getHostContext() as common.Context | undefined;
    if (!context) {
      return;
    }
    window.getLastWindow(context).then((win: window.Window): void => {
      const operation = action === 'maximize' ? win.maximize() : win.minimize();
      operation.catch((error: Error): void => {
        console.error(`PWA window ${action} failed:`, error);
      });
    }).catch((error: Error): void => {
      console.error('Failed to get the PWA host window:', error);
    });
  }
}
