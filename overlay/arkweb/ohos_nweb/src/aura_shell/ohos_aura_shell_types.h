// Copyright (c) 2026
// Licensed under the Apache License, Version 2.0.

#ifndef OHOS_NWEB_SRC_AURA_SHELL_OHOS_AURA_SHELL_TYPES_H_
#define OHOS_NWEB_SRC_AURA_SHELL_OHOS_AURA_SHELL_TYPES_H_

#include <cstdint>
#include <string>

namespace ohos_nweb {

inline constexpr char kChromiumHomeUrl[] = "chrome://newtab/";
inline constexpr char kDefaultUiProfile[] = "phone";
inline constexpr char kDefaultUiFamily[] = "mobile_phone";

struct AuraStartupConfig {
  std::string start_url = kChromiumHomeUrl;
  std::string ui_profile = kDefaultUiProfile;
  std::string ui_family = kDefaultUiFamily;
  std::string window_mode = "fullscreen";
  std::string device_class = "phone";
  std::string market_name;
  std::string product_model;
  bool is_foldable = false;
  int fold_status = -1;
  std::string user_data_dir;
  std::string print_output_dir;
  std::string resources_dir;
  std::string application_locale = "en-US";
  std::string color_scheme = "light";
  double display_width = 1920.0;
  double display_height = 1080.0;
  double display_density = 1.0;
  int icu_data_fd = -1;
  int64_t icu_data_offset = 0;
  int64_t icu_data_length = 0;
  bool jitless = true;
  bool fullscreen_requested = true;
};

struct AuraSurfaceState {
  bool created = false;
  bool visible = false;
  bool focused = false;
  double x = 0.0;
  double y = 0.0;
  double width = 0.0;
  double height = 0.0;
  double density = 1.0;
};

}  // namespace ohos_nweb

#endif  // OHOS_NWEB_SRC_AURA_SHELL_OHOS_AURA_SHELL_TYPES_H_
