import { AbilityConstant, Configuration, ConfigurationConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { http } from '@kit.NetworkKit';
import display from '@ohos.display';
import { CHROMIUM_HOME_URL, DeviceRouting, DeviceRoutingPolicy, WindowPolicy, WindowStateSnapshot } from '../utils/DeviceType';
import { UIManager } from '../utils/UIManager';
import {
  CrossDeviceEntryAdapter,
  CrossDeviceSessionSnapshot
} from '../utils/crossdevice/CrossDeviceEntryAdapter';

const DOMAIN = 0x0000;
const AURA_SURFACE_READY_KEY = 'auraSurfaceReady';
const AURA_APP_VISIBLE_KEY = 'auraAppVisible';
const AURA_THEME_FONT_ID_KEY = 'auraThemeFontId';
const AURA_THEME_FONT_REVISION_KEY = 'auraThemeFontRevision';
const CDP_PAGE_LIST_URL = 'http://127.0.0.1:9222/json/list';

interface CdpPageTarget {
  type?: string;
  url?: string;
  title?: string;
}

export default class EntryAbility extends UIAbility {
  private startupWant: Want | null = null;
  private mainWindow: window.Window | null = null;
  private lastRoutingSignature: string = '';
  private lastThemeFontId: string = '';
  private lastFoldStatus: number = -1;
  private routingRefreshTimer: number = -1;

  private readonly foldStatusChanged = (foldStatus: display.FoldStatus): void => {
    this.lastFoldStatus = Number(foldStatus);
    this.refreshRouting('foldStatusChange', this.lastFoldStatus);
    this.scheduleRoutingRefresh('foldStatusSettled', 180);
  };

  private readonly windowRotationChanged = (info: window.RotationChangeInfo): void => {
    if (info.type === window.RotationChangeType.WINDOW_DID_ROTATE) {
      this.scheduleRoutingRefresh('rotationDidChange', 80);
    }
  };

  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    this.startupWant = want;
    const initialThemeFontId = this.context.config.fontId ?? '';
    this.lastThemeFontId = initialThemeFontId;
    AppStorage.setOrCreate(AURA_APP_VISIBLE_KEY, true);
    AppStorage.setOrCreate(AURA_THEME_FONT_ID_KEY, initialThemeFontId);
    AppStorage.setOrCreate(AURA_THEME_FONT_REVISION_KEY, 0);
    AppStorage.setOrCreate('auraPwaWindowActive', false);
    hilog.info(DOMAIN, 'AuraShell', 'Initial theme font configuration: %{public}s', initialThemeFontId);
    try {
      this.context.getApplicationContext().setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_NOT_SET);
    } catch (err) {
      hilog.error(DOMAIN, 'AuraShell', 'Failed to set colorMode. Cause: %{public}s', JSON.stringify(err));
    }
  }

  onDestroy(): void {
    AppStorage.setOrCreate(AURA_APP_VISIBLE_KEY, false);
    this.unregisterRuntimeObservers();
  }

  onForeground(): void {
    AppStorage.setOrCreate(AURA_APP_VISIBLE_KEY, true);
  }

  onBackground(): void {
    AppStorage.setOrCreate(AURA_APP_VISIBLE_KEY, false);
  }

  onConfigurationUpdate(newConfig: Configuration): void {
    const fontId = newConfig.fontId ?? '';
    if (fontId === this.lastThemeFontId) {
      return;
    }

    this.lastThemeFontId = fontId;
    AppStorage.setOrCreate(AURA_THEME_FONT_ID_KEY, fontId);
    const revision = Number(AppStorage.get(AURA_THEME_FONT_REVISION_KEY) ?? 0);
    AppStorage.setOrCreate(AURA_THEME_FONT_REVISION_KEY, revision + 1);
    hilog.info(DOMAIN, 'AuraShell', 'Theme font configuration changed: %{public}s', fontId);
  }

  async onContinue(wantParam: Record<string, Object>): Promise<AbilityConstant.OnContinueResult> {
    const snapshot = await this.captureContinuationSnapshot();
    CrossDeviceEntryAdapter.writeContinuation(wantParam, snapshot);
    hilog.info(DOMAIN, 'AuraShell', 'Prepared cross-device continuation for %{public}s', snapshot.url);
    return AbilityConstant.OnContinueResult.AGREE;
  }

  onNewWant(want: Want, _launchParam: AbilityConstant.LaunchParam): void {
    this.startupWant = want;
    const startUrl = CrossDeviceEntryAdapter.resolveLaunchUrl(want);
    AppStorage.setOrCreate('auraStartUrl', startUrl);
    if (this.mainWindow) {
      this.refreshRouting('newWant');
    }
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    const uiPath = UIManager.loadUI();
    const startUrl = CrossDeviceEntryAdapter.resolveLaunchUrl(this.startupWant ?? undefined);

    AppStorage.setOrCreate('auraStartUrl', startUrl);
    AppStorage.setOrCreate('auraRoutingRevision', 0);
    AppStorage.setOrCreate('auraRouting', '');
    AppStorage.setOrCreate('auraStartupConfig', UIManager.serializeAuraStartupConfig(startUrl));
    AppStorage.setOrCreate(AURA_SURFACE_READY_KEY, false);

    windowStage.loadContent(uiPath, (err) => {
      if (err && err.code) {
        hilog.error(DOMAIN, 'AuraShell', 'Failed to load UI content: %{public}s', JSON.stringify(err));
        return;
      }
      hilog.info(DOMAIN, 'AuraShell', 'Loaded UI content: %{public}s', uiPath);
    });

    windowStage.getMainWindow().then((win: window.Window) => {
      this.mainWindow = win;
      this.lastFoldStatus = DeviceRoutingPolicy.getFoldStatus();
      this.configureChromiumOwnedFrame(win);
      this.refreshRouting('initial', this.lastFoldStatus);
      this.registerRuntimeObservers(win);
    }).catch((error: Error) => {
      hilog.error(DOMAIN, 'AuraShell', 'Failed to get main window: %{public}s', JSON.stringify(error));
    });
  }

  onWindowStageDestroy(): void {
    AppStorage.setOrCreate(AURA_SURFACE_READY_KEY, false);
    this.unregisterRuntimeObservers();
  }

  private registerRuntimeObservers(win: window.Window): void {
    try {
      win.on('windowSizeChange', (_size: window.Size) => {
        this.refreshRouting('windowSizeChange', this.lastFoldStatus);
        this.scheduleRoutingRefresh('windowSizeSettled', 120);
      });
    } catch (error) {
      hilog.warn(DOMAIN, 'AuraShell', 'Window size observer is unavailable: %{public}s', JSON.stringify(error));
    }

    try {
      win.on('windowStatusChange', (_status: window.WindowStatusType) => {
        this.refreshRouting('windowStatusChange');
      });
    } catch (statusChangeError) {
      try {
        win.on('windowStatusDidChange', (_status: window.WindowStatusType) => {
          this.refreshRouting('windowStatusDidChange');
        });
      } catch (statusDidChangeError) {
        hilog.warn(DOMAIN, 'AuraShell', 'Window status observers are unavailable: %{public}s / %{public}s',
          JSON.stringify(statusChangeError), JSON.stringify(statusDidChangeError));
      }
    }

    try {
      win.on('freeWindowModeChange', (_enabled: boolean) => {
        this.refreshRouting('freeWindowModeChange');
      });
    } catch (error) {
      hilog.info(DOMAIN, 'AuraShell', 'Free-window observer is unavailable: %{public}s', JSON.stringify(error));
    }

    try {
      win.on('rotationChange', this.windowRotationChanged);
    } catch (error) {
      hilog.info(DOMAIN, 'AuraShell', 'Rotation observer is unavailable: %{public}s', JSON.stringify(error));
    }

    if (DeviceRoutingPolicy.isFoldable()) {
      try {
        display.on('foldStatusChange', this.foldStatusChanged);
      } catch (error) {
        hilog.error(DOMAIN, 'AuraShell', 'Failed to register fold listener: %{public}s', JSON.stringify(error));
      }
    }
  }

  private configureChromiumOwnedFrame(win: window.Window): void {
    try {
      win.setWindowDecorVisible(false);
    } catch (error) {
      hilog.warn(DOMAIN, 'AuraShell', 'Window decor control is unavailable: %{public}s', JSON.stringify(error));
    }

    win.setPreferredOrientation(window.Orientation.AUTO_ROTATION_UNSPECIFIED).catch((error: Error) => {
      hilog.warn(DOMAIN, 'AuraShell', 'Preferred orientation control is unavailable: %{public}s',
        JSON.stringify(error));
    });
  }

  private unregisterRuntimeObservers(): void {
    if (this.mainWindow) {
      try {
        this.mainWindow.off('windowSizeChange');
      } catch (error) {
      }
      try {
        this.mainWindow.off('windowStatusChange');
      } catch (error) {
      }
      try {
        this.mainWindow.off('windowStatusDidChange');
      } catch (error) {
      }
      try {
        this.mainWindow.off('freeWindowModeChange');
      } catch (error) {
      }
      try {
        this.mainWindow.off('rotationChange', this.windowRotationChanged);
      } catch (error) {
      }
    }

    try {
      display.off('foldStatusChange', this.foldStatusChanged);
    } catch (error) {
    }

    if (this.routingRefreshTimer >= 0) {
      clearTimeout(this.routingRefreshTimer);
      this.routingRefreshTimer = -1;
    }

    this.mainWindow = null;
  }

  private scheduleRoutingRefresh(reason: string, delayMs: number): void {
    if (this.routingRefreshTimer >= 0) {
      clearTimeout(this.routingRefreshTimer);
    }
    this.routingRefreshTimer = setTimeout(() => {
      this.routingRefreshTimer = -1;
      const foldStatus = DeviceRoutingPolicy.getFoldStatus();
      this.lastFoldStatus = foldStatus;
      this.refreshRouting(reason, foldStatus);
    }, delayMs);
  }

  private refreshRouting(reason: string, foldStatusOverride?: number): void {
    if (!this.mainWindow) {
      return;
    }

    if (reason !== 'initial' && !this.isSurfaceReady()) {
      hilog.info(DOMAIN, 'AuraShell', 'Skip routing refresh before first surface frame: %{public}s', reason);
      return;
    }

    const windowState = this.captureWindowState(this.mainWindow);
    const foldStatus = foldStatusOverride ?? this.lastFoldStatus;
    const routing = UIManager.getRouting(windowState, foldStatus);
    const startUrl = (AppStorage.get('auraStartUrl') as string) || CHROMIUM_HOME_URL;
    const routingSignature = DeviceRoutingPolicy.buildRoutingSignature(routing);

    this.applyWindowPolicy(this.mainWindow, routing);
    AppStorage.setOrCreate('auraRouting', JSON.stringify(routing));
    AppStorage.setOrCreate('auraStartupConfig',
      UIManager.serializeAuraStartupConfig(startUrl, windowState, foldStatus));

    if (routingSignature !== this.lastRoutingSignature) {
      this.lastRoutingSignature = routingSignature;
      const currentRevision = Number(AppStorage.get('auraRoutingRevision') ?? 0);
      AppStorage.setOrCreate('auraRoutingRevision', currentRevision + 1);
    }

    hilog.info(DOMAIN, 'AuraShell', 'Routing refreshed from %{public}s: %{public}s', reason, routingSignature);
  }

  private isSurfaceReady(): boolean {
    return Boolean(AppStorage.get(AURA_SURFACE_READY_KEY) ?? false);
  }

  private captureWindowState(win: window.Window): WindowStateSnapshot {
    let inFreeWindowMode = false;
    let windowStatus = 0;

    try {
      inFreeWindowMode = !!win.isInFreeWindowMode();
    } catch (error) {
    }

    try {
      windowStatus = Number(win.getWindowStatus());
    } catch (error) {
    }

    return {
      inFreeWindowMode,
      windowStatus
    };
  }

  private applyWindowPolicy(win: window.Window, routing: DeviceRouting): void {
    try {
      // Chromium owns browser chrome, but HarmonyOS remains the sole owner of
      // desktop caption controls. Fullscreen/mobile states have no caption.
      const pwaWindowActive = Boolean(AppStorage.get('auraPwaWindowActive') ?? false);
      win.setWindowDecorVisible(
        routing.windowPolicy === WindowPolicy.WINDOWED && !pwaWindowActive);
    } catch (error) {
      hilog.warn(DOMAIN, 'AuraShell', 'Window decor update is unavailable: %{public}s', JSON.stringify(error));
    }

    if (routing.windowPolicy === WindowPolicy.FULLSCREEN) {
      win.setWindowLayoutFullScreen(true).catch(() => {
      });
      try {
        win.setSpecificSystemBarEnabled('status', false);
        win.setSpecificSystemBarEnabled('navigationIndicator', false);
      } catch (error) {
      }
    } else {
      win.setWindowLayoutFullScreen(false).catch(() => {
      });
      try {
        win.setSpecificSystemBarEnabled('status', true);
        win.setSpecificSystemBarEnabled('navigationIndicator', true);
      } catch (error) {
      }
    }
  }

  private async captureContinuationSnapshot(): Promise<CrossDeviceSessionSnapshot> {
    const fallbackUrl = (AppStorage.get('auraStartUrl') as string) || CHROMIUM_HOME_URL;
    const request = http.createHttp();
    try {
      const response = await request.request(CDP_PAGE_LIST_URL, {
        method: http.RequestMethod.GET,
        expectDataType: http.HttpDataType.STRING,
        usingCache: false,
        connectTimeout: 1500,
        readTimeout: 1500
      });
      if (Number(response.responseCode) === 200 && typeof response.result === 'string') {
        const targets = JSON.parse(response.result) as CdpPageTarget[];
        for (const target of targets) {
          if (target.type === 'page' && target.url) {
            return {
              url: target.url,
              title: target.title ?? '',
              capturedAt: Date.now()
            };
          }
        }
      }
    } catch (error) {
      hilog.warn(DOMAIN, 'AuraShell', 'CDP snapshot unavailable during continuation: %{public}s',
        JSON.stringify(error));
    } finally {
      request.destroy();
    }
    return {
      url: fallbackUrl,
      title: '',
      capturedAt: Date.now()
    };
  }
}
