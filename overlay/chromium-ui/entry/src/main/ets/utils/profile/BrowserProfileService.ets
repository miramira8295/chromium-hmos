import { common } from '@kit.AbilityKit';
import { preferences } from '@kit.ArkData';
import { authentication } from '@kit.AccountKit';
import { util } from '@kit.ArkTS';

const PREFERENCES_NAME: string = 'chromium_hmos_browser_profile';
const ONBOARDING_COMPLETE_KEY: string = 'onboardingComplete';
const PROFILE_ID_KEY: string = 'profileId';
const PROFILE_KIND_KEY: string = 'profileKind';
const SYNC_MODE_KEY: string = 'syncMode';

export enum BrowserProfileKind {
  LOCAL = 'local',
  HUAWEI = 'huawei'
}

export enum BrowserSyncMode {
  OFF = 'off',
  NEARBY = 'nearby',
  CLOUD = 'cloud'
}

export interface BrowserProfileState {
  onboardingComplete: boolean;
  profileId: string;
  profileKind: BrowserProfileKind;
  syncMode: BrowserSyncMode;
}

export class BrowserProfileService {
  static async load(context: common.Context): Promise<BrowserProfileState> {
    const store = await preferences.getPreferences(context, PREFERENCES_NAME);
    const onboardingComplete = Boolean(await store.get(ONBOARDING_COMPLETE_KEY, false));
    const profileId = String(await store.get(PROFILE_ID_KEY, 'local'));
    const storedKind = String(await store.get(PROFILE_KIND_KEY, BrowserProfileKind.LOCAL));
    const storedSyncMode = String(await store.get(SYNC_MODE_KEY, BrowserSyncMode.OFF));
    return {
      onboardingComplete,
      profileId: BrowserProfileService.sanitizeProfileId(profileId),
      profileKind: storedKind === BrowserProfileKind.HUAWEI ?
        BrowserProfileKind.HUAWEI : BrowserProfileKind.LOCAL,
      syncMode: BrowserProfileService.parseSyncMode(storedSyncMode)
    };
  }

  static async completeLocalOnboarding(context: common.Context): Promise<BrowserProfileState> {
    const state: BrowserProfileState = {
      onboardingComplete: true,
      profileId: 'local',
      profileKind: BrowserProfileKind.LOCAL,
      syncMode: BrowserSyncMode.OFF
    };
    await BrowserProfileService.persist(context, state);
    return state;
  }

  static async persistVerifiedHuaweiProfile(
    context: common.Context,
    stableAccountId: string,
    syncMode: BrowserSyncMode
  ): Promise<BrowserProfileState> {
    const profileId = BrowserProfileService.sanitizeProfileId(stableAccountId);
    if (!profileId || profileId === 'local') {
      throw new Error('The verified Huawei account identifier is invalid');
    }
    const state: BrowserProfileState = {
      onboardingComplete: true,
      profileId,
      profileKind: BrowserProfileKind.HUAWEI,
      syncMode
    };
    await BrowserProfileService.persist(context, state);
    return state;
  }

  static async requestHuaweiAuthorizationCode(context: common.Context): Promise<string> {
    const loginRequest = new authentication.HuaweiIDProvider().createLoginWithHuaweiIDRequest();
    loginRequest.forceLogin = true;
    loginRequest.state = util.generateRandomUUID();
    const controller = new authentication.AuthenticationController(context);
    const response = await controller.executeRequest(loginRequest) as authentication.LoginWithHuaweiIDResponse;
    if (response.state && response.state !== loginRequest.state) {
      throw new Error('Huawei account response state did not match the request');
    }
    const authorizationCode = response.data?.authorizationCode ?? '';
    if (!authorizationCode) {
      throw new Error('Huawei account authorization did not return a code');
    }
    return authorizationCode;
  }

  private static async persist(context: common.Context, state: BrowserProfileState): Promise<void> {
    const store = await preferences.getPreferences(context, PREFERENCES_NAME);
    await store.put(ONBOARDING_COMPLETE_KEY, state.onboardingComplete);
    await store.put(PROFILE_ID_KEY, state.profileId);
    await store.put(PROFILE_KIND_KEY, state.profileKind);
    await store.put(SYNC_MODE_KEY, state.syncMode);
    await store.flush();
  }

  private static parseSyncMode(value: string): BrowserSyncMode {
    if (value === BrowserSyncMode.NEARBY) {
      return BrowserSyncMode.NEARBY;
    }
    if (value === BrowserSyncMode.CLOUD) {
      return BrowserSyncMode.CLOUD;
    }
    return BrowserSyncMode.OFF;
  }

  private static sanitizeProfileId(value: string): string {
    const sanitized = value.trim().replace(/[^a-zA-Z0-9._-]/g, '_').substring(0, 96);
    return sanitized.length > 0 ? sanitized : 'local';
  }
}
