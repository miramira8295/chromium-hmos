#ifndef UI_OZONE_PLATFORM_OHOS_OZONE_PLATFORM_OHOS_H_
#define UI_OZONE_PLATFORM_OHOS_OZONE_PLATFORM_OHOS_H_

namespace gfx {
class ClientNativePixmapFactory;
}

namespace ui {

class OzonePlatform;

OzonePlatform* CreateOzonePlatformOhos();
gfx::ClientNativePixmapFactory* CreateClientNativePixmapFactoryOhos();

}  // namespace ui

#endif  // UI_OZONE_PLATFORM_OHOS_OZONE_PLATFORM_OHOS_H_
