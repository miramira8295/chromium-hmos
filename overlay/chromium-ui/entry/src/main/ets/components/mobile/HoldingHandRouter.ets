import motion from '@ohos.multimodalAwareness.motion';

export enum GripSide {
  LEFT = 'left',
  RIGHT = 'right'
}

export class HoldingHandRouter {
  private started: boolean = false;
  private onStableSide: (side: GripSide) => void = (_side: GripSide): void => {};

  private readonly holdingHandChanged = (status: motion.HoldingHandStatus): void => {
    if (status === motion.HoldingHandStatus.LEFT_HAND_HELD) {
      this.onStableSide(GripSide.LEFT);
    } else if (status === motion.HoldingHandStatus.RIGHT_HAND_HELD) {
      this.onStableSide(GripSide.RIGHT);
    }
  };

  start(onStableSide: (side: GripSide) => void): void {
    this.onStableSide = onStableSide;
    if (this.started) {
      return;
    }

    if (!canIUse('SystemCapability.MultimodalAwareness.Motion')) {
      return;
    }

    try {
      motion.on('holdingHandChanged', this.holdingHandChanged);
      this.started = true;
    } catch (error) {
      console.warn('Holding-hand awareness is unavailable:', error);
    }
  }

  stop(): void {
    if (!this.started) {
      return;
    }

    try {
      motion.off('holdingHandChanged', this.holdingHandChanged);
    } catch (error) {
    }
    this.started = false;
    this.onStableSide = (_side: GripSide): void => {};
  }
}
