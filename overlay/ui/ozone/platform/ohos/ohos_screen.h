#ifndef UI_OZONE_PLATFORM_OHOS_OHOS_SCREEN_H_
#define UI_OZONE_PLATFORM_OHOS_OHOS_SCREEN_H_

#include <vector>

#include "base/memory/weak_ptr.h"
#include "ui/display/display_list.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/size.h"
#include "ui/ozone/public/platform_screen.h"

namespace ui {

class OhosScreen : public PlatformScreen {
 public:
  OhosScreen();
  ~OhosScreen() override;

  const std::vector<display::Display>& GetAllDisplays() const override;
  display::Display GetPrimaryDisplay() const override;
  display::Display GetDisplayForAcceleratedWidget(
      gfx::AcceleratedWidget widget) const override;
  gfx::Point GetCursorScreenPoint() const override;
  gfx::AcceleratedWidget GetAcceleratedWidgetAtScreenPoint(
      const gfx::Point& point) const override;
  display::Display GetDisplayNearestPoint(
      const gfx::Point& point) const override;
  display::Display GetDisplayMatching(
      const gfx::Rect& match_rect) const override;
  void AddObserver(display::DisplayObserver* observer) override;
  void RemoveObserver(display::DisplayObserver* observer) override;

 private:
  display::Display GetPrimaryDisplayWithSurfaceWorkArea() const;
  void OnDisplayMetricsChanged(gfx::Size pixel_size, float density);

  display::DisplayList display_list_;
  base::WeakPtrFactory<OhosScreen> weak_factory_{this};
};

}  // namespace ui

#endif  // UI_OZONE_PLATFORM_OHOS_OHOS_SCREEN_H_
