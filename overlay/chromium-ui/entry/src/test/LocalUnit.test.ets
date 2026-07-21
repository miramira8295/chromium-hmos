import { describe, it, expect } from '@ohos/hypium';
import {
  CHROMIUM_HOME_URL,
  DeviceIdentity,
  DeviceRoutingPolicy,
  UIFamily,
  UIProfile
} from '../main/ets/utils/DeviceType';
import { CrossDeviceEntryAdapter } from '../main/ets/utils/crossdevice/CrossDeviceEntryAdapter';

function identity(overrides: Partial<DeviceIdentity>): DeviceIdentity {
  return {
    deviceType: 'phone',
    marketName: '',
    productModel: '',
    isFoldable: false,
    foldStatus: -1,
    ...overrides
  };
}

export default function localUnitTest() {
  describe('chromiumAuraRouting', () => {
    it('usesChromiumHomeWhenLaunchUrlIsEmpty', 0, () => {
      expect(CrossDeviceEntryAdapter.resolveLaunchUrl()).assertEqual(CHROMIUM_HOME_URL);
    });

    it('routesPhoneToMobileChromiumUi', 0, () => {
      const routing = DeviceRoutingPolicy.resolveFromIdentity(identity({ deviceType: 'phone' }));
      expect(routing.uiProfile).assertEqual(UIProfile.PHONE);
      expect(routing.uiFamily).assertEqual(UIFamily.MOBILE_PHONE);
    });

    it('routesMatePadToAuraTabletUi', 0, () => {
      const routing = DeviceRoutingPolicy.resolveFromIdentity(identity({
        deviceType: 'tablet',
        marketName: 'HUAWEI MatePad Pro'
      }));
      expect(routing.uiProfile).assertEqual(UIProfile.TABLET);
      expect(routing.uiFamily).assertEqual(UIFamily.AURA_TABLET);
    });

    it('routesMateBookToAuraPcUi', 0, () => {
      const routing = DeviceRoutingPolicy.resolveFromIdentity(identity({
        deviceType: '2in1',
        marketName: 'HUAWEI MateBook'
      }));
      expect(routing.uiProfile).assertEqual(UIProfile.PC);
      expect(routing.uiFamily).assertEqual(UIFamily.AURA_PC);
    });

    it('routesLargeSurfacesToMobileLargeUi', 0, () => {
      const carRouting = DeviceRoutingPolicy.resolveFromIdentity(identity({ deviceType: 'car' }));
      expect(carRouting.uiFamily).assertEqual(UIFamily.MOBILE_LARGE);

      const expandedFoldRouting = DeviceRoutingPolicy.resolveFromIdentity(identity({
        deviceType: 'tablet',
        isFoldable: true,
        foldStatus: 999
      }));
      expect(expandedFoldRouting.uiFamily).assertEqual(UIFamily.MOBILE_LARGE);
    });

    it('routesFoldedFoldableToMobilePhoneUi', 0, () => {
      const routing = DeviceRoutingPolicy.resolveFromIdentity(identity({
        deviceType: 'phone',
        isFoldable: true,
        foldStatus: 2
      }));
      expect(routing.uiProfile).assertEqual(UIProfile.PHONE);
      expect(routing.uiFamily).assertEqual(UIFamily.MOBILE_PHONE);
    });
  });
}
