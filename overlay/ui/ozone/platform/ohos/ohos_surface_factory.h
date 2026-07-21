#ifndef UI_OZONE_PLATFORM_OHOS_OHOS_SURFACE_FACTORY_H_
#define UI_OZONE_PLATFORM_OHOS_OHOS_SURFACE_FACTORY_H_

#include <memory>

#include "base/files/file_path.h"
#include "ui/ozone/platform/headless/headless_surface_factory.h"

namespace ui {

class OhosSurfaceFactory : public HeadlessSurfaceFactory {
 public:
  explicit OhosSurfaceFactory(base::FilePath base_path);
  ~OhosSurfaceFactory() override;

  std::vector<gl::GLImplementationParts> GetAllowedGLImplementations() override;
  GLOzone* GetGLOzone(const gl::GLImplementationParts& implementation) override;

 private:
  std::unique_ptr<GLOzone> egl_implementation_;
};

}  // namespace ui

#endif  // UI_OZONE_PLATFORM_OHOS_OHOS_SURFACE_FACTORY_H_
