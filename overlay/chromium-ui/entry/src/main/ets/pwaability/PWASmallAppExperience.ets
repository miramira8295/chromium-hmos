import { AbilityConstant, Configuration, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

const DOMAIN = 0x0000;

interface PwaWantParameters {
  pwaWidget?: number;
  pwaAppId?: string;
  pwaTitle?: string;
  pwaStartUrl?: string;
  pwaProfileId?: string;
  pwaStartupConfig?: string;
}

class PwaStorageValues {
  pwaWidget: number = 0;
  pwaAppId: string = '';
  pwaTitle: string = 'Chromium';
  pwaStartUrl: string = 'chrome://newtab/';
  pwaProfileId: string = 'local';
  pwaStartupConfig: string = '';
  pwaAppVisible: boolean = true;
  pwaThemeFontId: string = '';
  pwaThemeFontRevision: number = 0;
}

export default class PWASmallAppExperience extends UIAbility {
  private mainWindow: window.Window | null = null;
  private storage: LocalStorage = new LocalStorage(new PwaStorageValues());
  private immersiveRetryTimers: number[] = [];

  private readonly windowStatusChanged = (_status: window.WindowStatusType): void => {
    if (this.mainWindow) {
      this.scheduleImmersiveWindowConfiguration(this.mainWindow, [ 60, 220 ]);
    }
  };

  onCreate(want: Want, _launchParam: AbilityConstant.LaunchParam): void {
    this.writeWant(want);
    this.storage.setOrCreate('pwaThemeFontId', this.context.config.fontId ?? '');
  }

  onNewWant(want: Want, _launchParam: AbilityConstant.LaunchParam): void {
    this.writeWant(want);
  }

  onForeground(): void {
    this.storage.setOrCreate('pwaAppVisible', true);
  }

  onBackground(): void {
    this.storage.setOrCreate('pwaAppVisible', false);
  }

  onConfigurationUpdate(newConfig: Configuration): void {
    const nextFontId = newConfig.fontId ?? '';
    const currentFontId = String(this.storage.get('pwaThemeFontId') ?? '');
    if (nextFontId !== currentFontId) {
      this.storage.setOrCreate('pwaThemeFontId', nextFontId);
      const revision = Number(this.storage.get('pwaThemeFontRevision') ?? 0);
      this.storage.setOrCreate('pwaThemeFontRevision', revision + 1);
    }
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/PWASmallAppExperience', this.storage, (error) => {
      if (error && error.code) {
        hilog.error(DOMAIN, 'ChromiumPWA', 'Failed to load PWA window: %{public}s',
          JSON.stringify(error));
        return;
      }
      windowStage.getMainWindow().then((win: window.Window): void => {
        this.mainWindow = win;
        this.registerWindowObservers(win);
        this.scheduleImmersiveWindowConfiguration(win, [ 0, 80, 240, 600 ]);
      }).catch((windowError: Error): void => {
        hilog.error(DOMAIN, 'ChromiumPWA', 'Failed to get PWA main window: %{public}s',
          JSON.stringify(windowError));
      });
    });
  }

  onWindowStageDestroy(): void {
    this.storage.setOrCreate('pwaAppVisible', false);
    this.clearImmersiveRetryTimers();
    if (this.mainWindow) {
      try {
        this.mainWindow.off('windowStatusChange', this.windowStatusChanged);
      } catch (error) {
      }
      try {
        this.mainWindow.off('windowStatusDidChange', this.windowStatusChanged);
      } catch (error) {
      }
    }
    this.mainWindow = null;
  }

  private writeWant(want: Want): void {
    const parameters = (want.parameters ?? {}) as PwaWantParameters;
    this.storage.setOrCreate('pwaWidget', Number(parameters.pwaWidget ?? 0));
    this.storage.setOrCreate('pwaAppId', String(parameters.pwaAppId ?? ''));
    this.storage.setOrCreate('pwaTitle', String(parameters.pwaTitle ?? 'Chromium'));
    this.storage.setOrCreate('pwaStartUrl',
      String(parameters.pwaStartUrl ?? 'chrome://newtab/'));
    this.storage.setOrCreate('pwaProfileId', String(parameters.pwaProfileId ?? 'local'));
    this.storage.setOrCreate('pwaStartupConfig', String(parameters.pwaStartupConfig ?? ''));
  }

  private registerWindowObservers(win: window.Window): void {
    try {
      win.on('windowStatusChange', this.windowStatusChanged);
    } catch (statusChangeError) {
      try {
        win.on('windowStatusDidChange', this.windowStatusChanged);
      } catch (statusDidChangeError) {
        hilog.info(DOMAIN, 'ChromiumPWA', 'PWA window status observer unavailable: %{public}s / %{public}s',
          JSON.stringify(statusChangeError), JSON.stringify(statusDidChangeError));
      }
    }
  }

  private scheduleImmersiveWindowConfiguration(win: window.Window, delays: number[]): void {
    this.clearImmersiveRetryTimers();
    delays.forEach((delay: number, index: number): void => {
      this.immersiveRetryTimers.push(setTimeout((): void => {
        if (this.mainWindow !== win) {
          return;
        }
        this.configureImmersiveWindow(win, index === delays.length - 1);
      }, delay));
    });
  }

  private clearImmersiveRetryTimers(): void {
    this.immersiveRetryTimers.forEach((timer: number): void => clearTimeout(timer));
    this.immersiveRetryTimers = [];
  }

  private configureImmersiveWindow(win: window.Window, reportFailure: boolean): void {
    try {
      win.setWindowDecorVisible(false);
    } catch (error) {
      if (reportFailure) {
        hilog.warn(DOMAIN, 'ChromiumPWA', 'PWA decor control unavailable after retry: %{public}s',
          JSON.stringify(error));
      }
    }
    try {
      win.setWindowTitleButtonVisible(false, false, false);
    } catch (error) {
      if (reportFailure) {
        hilog.info(DOMAIN, 'ChromiumPWA', 'PWA title button control unavailable: %{public}s',
          JSON.stringify(error));
      }
    }
    try {
      win.setSpecificSystemBarEnabled('status', false);
    } catch (error) {
    }
    try {
      win.setSpecificSystemBarEnabled('navigationIndicator', false);
    } catch (error) {
    }
    win.setWindowLayoutFullScreen(true).catch((): void => {
    });
    const title = String(this.storage.get('pwaTitle') ?? 'Chromium');
    win.setWindowTitle(title).catch((): void => {
    });
  }
}
