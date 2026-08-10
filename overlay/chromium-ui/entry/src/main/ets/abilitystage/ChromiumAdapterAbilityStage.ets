import { AbilityStage, Want } from '@kit.AbilityKit';

interface PwaWantParameters {
  pwaAppId?: string;
  pwaWidget?: number;
}

export default class ChromiumAdapterAbilityStage extends AbilityStage {
  onAcceptWant(want: Want): string {
    const abilityName = String(want.abilityName ?? 'EntryAbility');
    if (abilityName !== 'PWASmallAppExperience') {
      return abilityName;
    }
    const parameters = (want.parameters ?? {}) as PwaWantParameters;
    const appId = String(parameters.pwaAppId ?? '').trim();
    const widget = Number(parameters.pwaWidget ?? 0);
    const instanceId = appId || (widget > 0 ? widget.toString() : 'default');
    return `${abilityName}:${instanceId}`;
  }
}
