# DevEco Studio快速启动指南

## 为什么DevEco Studio识别不到项目？

DevEco Studio需要以下配置文件才能识别HarmonyOS项目：

### ✅ 已创建的配置文件

1. **项目根目录配置**
   - ✅ `build-profile.json5` - 构建配置文件
   - ✅ `oh-package.json5` - 包配置文件
   - ✅ `app.json5` - 应用配置文件
   - ✅ `local.properties` - 本地SDK路径配置（需要修改）
   - ✅ `.gitignore` - Git忽略文件

2. **模块配置**
   - ✅ `entry/src/main/module.json` - 模块配置
   - ✅ `entry/src/main/resources/base/profile/main_pages.json` - 页面配置
   - ✅ `entry/src/main/resources/base/element/string.json` - 字符串资源
   - ✅ `entry/src/main/resources/base/element/color.json` - 颜色资源
   - ✅ `entry/src/main/resources/base/element/app.json5` - 应用配置

3. **Ability和Application**
   - ✅ `entry/src/main/ets/ability/EntryAbility.ets` - 主Ability
   - ✅ `entry/src/main/ets/Application/AbilityStage.ets` - Application类

## 在DevEco Studio中打开项目

### 步骤1: 配置SDK路径

1. 打开 `local.properties` 文件
2. 修改 `sdk.dir` 为你的HarmonyOS SDK路径，例如：
   ```
   sdk.dir=C\:\\Users\\YourName\\AppData\\Local\\Huawei\\Sdk
   ```
   或者
   ```
   sdk.dir=D\:\\HarmonyOS\\Sdk
   ```

### 步骤2: 打开项目

**方法1: 直接打开**
1. 打开DevEco Studio
2. 选择 `File` → `Open`
3. 选择 `chromium_src/ohos_nweb_hap` 目录
4. 点击 `OK`
5. 等待项目同步完成

**方法2: 导入项目**
1. 打开DevEco Studio
2. 选择 `File` → `New` → `Import Project`
3. 选择 `chromium_src/ohos_nweb_hap` 目录
4. 点击 `Next`
5. 选择SDK版本（建议5.0.5.165或更高）
6. 点击 `Finish`

### 步骤3: 同步项目

1. 如果项目没有自动同步，点击 `File` → `Sync Project with Gradle Files`
2. 或者点击工具栏的同步按钮
3. 等待同步完成

### 步骤4: 添加应用图标（可选）

1. 准备应用图标文件（512x512 PNG格式）
2. 命名为 `app_icon.png`
3. 复制到 `entry/src/main/resources/base/media/` 目录
4. 如果没有图标，项目会使用默认图标

## 验证项目配置

### 检查项目结构

在DevEco Studio的项目视图中，应该能看到：

```
ohos_nweb_hap
├── entry
│   ├── src
│   │   ├── main
│   │   │   ├── ets
│   │   │   ├── module.json
│   │   │   └── resources
│   ├── build-profile.json5
│   └── oh-package.json5
├── build-profile.json5
├── oh-package.json5
└── app.json5
```

### 检查配置是否正确

1. **module.json**: 检查Ability路径是否正确
2. **main_pages.json**: 检查页面路径是否正确
3. **string.json**: 检查字符串资源是否完整

## 常见问题解决

### Q1: 项目打开后显示"Project structure is invalid"

**解决方案**:
1. 检查 `build-profile.json5` 是否存在
2. 检查 `entry/src/main/module.json` 是否存在
3. 检查 `entry/src/main/resources/base/profile/main_pages.json` 是否存在
4. 重新同步项目：`File` → `Sync Project with Gradle Files`

### Q2: 找不到Ability或页面

**解决方案**:
1. 检查 `module.json` 中的 `srcEntry` 路径是否正确
2. 检查 `main_pages.json` 中的页面路径是否正确
3. 确保文件扩展名为 `.ets`

### Q3: 资源文件找不到

**解决方案**:
1. 检查资源文件是否在 `entry/src/main/resources/base/` 目录下
2. 检查资源引用路径是否正确（如 `$string:app_name`）
3. 确保 `string.json`、`color.json` 等文件格式正确

### Q4: SDK路径错误

**解决方案**:
1. 打开 `local.properties`
2. 修改 `sdk.dir` 为正确的SDK路径
3. 路径中的反斜杠需要转义：`C:\\Users\\...`
4. 重新同步项目

### Q5: 编译错误：找不到原生库

**解决方案**:
1. 确保已编译生成 `libweb_engine.so` 和 `libnweb_render.so`
2. 在 `module.json` 中配置原生库路径
3. 或者先注释掉XComponent相关代码，先让项目能编译通过

## 项目结构说明

```
ohos_nweb_hap/
├── build-profile.json5          # 构建配置（必需）
├── oh-package.json5              # 包配置（必需）
├── app.json5                     # 应用配置（必需）
├── local.properties              # SDK路径（需要配置）
├── .gitignore                    # Git忽略文件
├── README.md                     # 项目说明
└── entry/                        # 入口模块
    ├── build-profile.json5       # 模块构建配置
    ├── oh-package.json5          # 模块包配置
    └── src/main/
        ├── ets/                  # ArkTS源代码
        ├── module.json           # 模块配置（必需）
        └── resources/            # 资源文件
            └── base/
                ├── element/       # 元素资源
                ├── media/         # 媒体资源
                └── profile/       # 配置文件
```

## 下一步

1. ✅ 项目已配置完成，可以在DevEco Studio中打开
2. ⏳ 添加应用图标（可选）
3. ⏳ 配置原生库路径
4. ⏳ 测试编译和运行

## 参考

- [HarmonyOS应用开发文档](https://developer.harmonyos.com/)
- [DevEco Studio使用指南](https://developer.harmonyos.com/cn/develop/deveco-studio)

