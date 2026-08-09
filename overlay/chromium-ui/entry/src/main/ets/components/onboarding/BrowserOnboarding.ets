import { common } from '@kit.AbilityKit';
import {
  BrowserProfileService,
  BrowserProfileState
} from '../../utils/profile/BrowserProfileService';

@Component
export struct BrowserOnboarding {
  onComplete: (state: BrowserProfileState) => void = (_state: BrowserProfileState): void => {};

  @State private busy: boolean = false;
  @State private errorText: string = '';

  build() {
    Scroll() {
      Column({ space: 24 }) {
        Image($r('app.media.startIcon'))
          .width(88)
          .height(88)
          .objectFit(ImageFit.Contain)
          .accessibilityText('Chromium HarmonyOS Adapter')

        Column({ space: 8 }) {
          Text('Chromium HarmonyOS Adapter')
            .fontSize(36)
            .fontWeight(FontWeight.Bold)
            .fontColor($r('app.color.text_primary'))
          Text('选择浏览器资料的保存方式')
            .fontSize(17)
            .fontColor($r('app.color.text_secondary'))
        }
        .alignItems(HorizontalAlign.Center)

        Column({ space: 12 }) {
          Button('使用本机 Profile')
            .width('100%')
            .height(52)
            .fontSize(17)
            .fontColor($r('app.color.on_accent'))
            .backgroundColor($r('app.color.accent_primary'))
            .borderRadius(8)
            .enabled(!this.busy)
            .onClick((): void => this.completeLocalProfile())

          Button('使用华为账号')
            .width('100%')
            .height(52)
            .fontSize(17)
            .fontColor($r('app.color.text_primary'))
            .backgroundColor($r('app.color.surface_secondary'))
            .borderRadius(8)
            .enabled(!this.busy)
            .onClick((): void => this.beginHuaweiAccountLink())
        }
        .width('100%')

        if (this.busy) {
          LoadingProgress()
            .width(32)
            .height(32)
            .color($r('app.color.accent_primary'))
        }

        if (this.errorText.length > 0) {
          Text(this.errorText)
            .width('100%')
            .fontSize(14)
            .fontColor($r('app.color.text_secondary'))
            .textAlign(TextAlign.Center)
        }

        Text('本机模式不会上传浏览数据。华为账号跨设备同步会在账号服务端、云空间和端到端加密配置完成后开放。')
          .width('100%')
          .fontSize(13)
          .lineHeight(20)
          .fontColor($r('app.color.text_secondary'))
          .textAlign(TextAlign.Center)
      }
      .width('100%')
      .constraintSize({ maxWidth: 520 })
      .padding({ left: 28, right: 28, top: 56, bottom: 40 })
    }
    .width('100%')
    .height('100%')
    .align(Alignment.Center)
    .backgroundColor($r('app.color.browser_canvas'))
  }

  private completeLocalProfile(): void {
    const context = this.getUIContext().getHostContext() as common.Context | undefined;
    if (!context || this.busy) {
      return;
    }
    this.busy = true;
    this.errorText = '';
    BrowserProfileService.completeLocalOnboarding(context)
      .then((state: BrowserProfileState): void => {
        this.busy = false;
        this.onComplete(state);
      })
      .catch((error: Error): void => {
        this.busy = false;
        this.errorText = `无法创建本机 Profile：${error.message}`;
      });
  }

  private beginHuaweiAccountLink(): void {
    const context = this.getUIContext().getHostContext() as common.Context | undefined;
    if (!context || this.busy) {
      return;
    }
    this.busy = true;
    this.errorText = '';
    BrowserProfileService.requestHuaweiAuthorizationCode(context)
      .then((_authorizationCode: string): void => {
        this.busy = false;
        AlertDialog.show({
          title: '还差账号服务端',
          message: '华为账号授权已经返回。为避免把临时授权码当作身份或明文保存凭证，当前开源构建不会创建假的云端 Profile；配置账号服务端后即可完成绑定。',
          confirm: {
            value: '继续使用本机',
            action: (): void => this.completeLocalProfile()
          }
        });
      })
      .catch((error: Error): void => {
        this.busy = false;
        this.errorText = `华为账号暂时无法连接：${error.message}`;
      });
  }
}
