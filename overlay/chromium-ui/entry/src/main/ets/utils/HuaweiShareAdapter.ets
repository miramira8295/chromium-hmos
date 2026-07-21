import { common } from '@kit.AbilityKit';
import { systemShare } from '@kit.ShareKit';

export class HuaweiShareAdapter {
  static async sharePage(
    context: common.UIAbilityContext,
    url: string,
    title: string
  ): Promise<void> {
    if (!url || url.trim().length === 0) {
      return;
    }
    if (!canIUse('SystemCapability.Collaboration.SystemShare')) {
      throw new Error('System Share is not supported on this device');
    }

    const displayTitle = title && title.trim().length > 0 ? title : url;
    const record: systemShare.SharedRecord = {
      utd: 'general.hyperlink',
      content: url,
      uri: url,
      title: displayTitle,
      label: displayTitle,
      description: url
    };
    const data = new systemShare.SharedData(record);
    const controller = new systemShare.ShareController(data);
    await controller.show(context, {
      selectionMode: systemShare.SelectionMode.SINGLE,
      previewMode: systemShare.SharePreviewMode.DETAIL
    });
  }
}
