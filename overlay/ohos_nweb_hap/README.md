# NWeb HAP包项目

## 项目说明

这是Chromium移植到鸿蒙的ArkUI组件封装项目，提供WebView组件和多设备UI适配。

## 项目结构

```
ohos_nweb_hap/
├── entry/                          # 入口模块
│   ├── src/main/
│   │   ├── ets/                    # ArkTS源代码
│   │   │   ├── ability/            # Ability类
│   │   │   ├── Application/        # Application类
│   │   │   ├── components/         # 组件
│   │   │   ├── pages/              # 页面
│   │   │   └── utils/              # 工具类
│   │   ├── resources/              # 资源文件
│   │   └── module.json             # 模块配置
├── build-profile.json5             # 构建配置
├── oh-package.json5                # 包配置
└── app.json5                       # 应用配置
```

## 在DevEco Studio中打开项目

### 方法1: 直接打开项目目录

1. 打开DevEco Studio
2. 选择 `File` → `Open`
3. 选择 `chromium_src/ohos_nweb_hap` 目录
4. 点击 `OK`

### 方法2: 导入项目

1. 打开DevEco Studio
2. 选择 `File` → `New` → `Import Project`
3. 选择 `chromium_src/ohos_nweb_hap` 目录
4. 点击 `Next` 并完成导入

## 配置要求

### SDK版本
- **compileSdkVersion**: 5.0.5.165
- **targetAPIVersion**: 50005017
- **compatible**: 50001013

### 设备支持
- phone（手机）
- tablet（平板）
- tv（电视）
- car（汽车）
- desktop（桌面）

## 依赖说明

### 原生库依赖
- `libweb_engine.so` - Chromium Web引擎
- `libnweb_render.so` - Render进程库

### 权限要求
- `ohos.permission.INTERNET` - 网络访问
- `ohos.permission.GET_NETWORK_INFO` - 网络信息
- `ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER` - 扩展设备驱动

## 构建说明

### 使用DevEco Studio构建
1. 在DevEco Studio中打开项目
2. 点击 `Build` → `Build Hap(s)/App(s)` → `Build Hap(s)`
3. 构建产物在 `entry/build/default/outputs/default/` 目录

### 使用命令行构建
```bash
# 在项目根目录执行
hvigorw assembleHap
```

## 运行说明

### 在模拟器/真机上运行
1. 连接设备或启动模拟器
2. 点击 `Run` → `Run 'entry'`
3. 选择目标设备
4. 点击 `OK`

## 注意事项

1. **SDK路径配置**: 确保 `local.properties` 中配置了正确的SDK路径
2. **原生库**: 需要先编译生成 `libweb_engine.so` 和 `libnweb_render.so`
3. **资源文件**: 需要添加应用图标等资源文件
4. **XComponent库名**: 确保 `libweb_engine.so` 在设备的libs目录中

## 常见问题

### Q: DevEco Studio无法识别项目
A: 确保以下文件存在：
- `build-profile.json5`
- `oh-package.json5`
- `entry/src/main/module.json`
- `entry/src/main/resources/base/profile/main_pages.json`

### Q: 编译错误：找不到原生库
A: 确保 `libweb_engine.so` 已编译并放置在正确位置

### Q: 运行时错误：XComponent无法加载
A: 检查：
1. `libraryname` 是否正确（应为 `libweb_engine`）
2. 原生库是否在设备的libs目录中
3. 权限是否已配置

## 开发指南

### 添加新页面
1. 在 `entry/src/main/ets/pages/` 下创建页面文件
2. 在 `entry/src/main/resources/base/profile/main_pages.json` 中添加页面路径

### 添加新组件
1. 在 `entry/src/main/ets/components/` 下创建组件文件
2. 在需要使用的地方导入组件

### 修改UI适配
1. Phone UI: `entry/src/main/ets/pages/phone/`
2. Tablet UI: `entry/src/main/ets/pages/tablet/`
3. PC UI: `entry/src/main/ets/pages/pc/`

## 参考文档

- [HarmonyOS应用开发文档](https://developer.harmonyos.com/)
- [ArkUI开发指南](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/arkui-overview-0000001504769581)
- [XComponent使用指南](https://developer.harmonyos.com/cn/docs/documentation/doc-references/ts-basic-components-xcomponent-0000001477981205)

