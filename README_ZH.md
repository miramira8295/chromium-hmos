# Chromium HarmonyOS 适配层

本分支公开本地 Chromium 150 HarmonyOS 测试 HAP 所使用的适配代码。它是独立、
非官方项目，不代表 Google、Chromium、华为或 OpenHarmony 官方立场。

## 基线

- Chromium：`150.0.7871.114`
- 上游提交：`f405107495a07cb1bfcf687d4af8d91117098db6`
- 目标系统：`ohos`，产品界面统一表述为 HarmonyOS
- 目标架构：`arm64`
- 单一产品：`plan_kirin_pc`
- V8：JITless；保留 WebAssembly，使用解释器执行
- 大屏：Chromium Aura/Views；手机：ArkUI 浏览器栏加 Chromium 内容层
- 公开身份：Chromium HarmonyOS Adapter，包名为
  `com.caidingding233.chromium`；商业品牌与 AppGallery 签名留在独立下游

## 仓库内容

- `patches/chromium-150-harmonyos.patch`：对 Chromium 上游已跟踪文件的完整修改。
- `overlay/`：新增的 HarmonyOS、ArkWeb、Ozone、Aura shell 与 ArkUI 源码。
- `external/deps_code/webview/`：适配层需要的 WebView 接口源码。
- `config/args.plan_kirin_pc.gn`：本次原生构建使用的 GN 参数。
- `scripts/apply-adapter.sh`：把适配快照应用到指定 Chromium 基线。
- `.github/workflows/upstream-stable.yml`：每 6 小时检查官方 Chromium Stable，
  补丁兼容时可触发带授权 SDK 的自托管 HAP 构建。
- `licenses/`：许可证正文与目标构建生成的第三方许可清单。
- `SOURCE_MANIFEST.sha256`：除清单自身外，所有公开常规文件的 SHA-256 校验值。

本分支不发布 HAP、原生编译产物、HarmonyOS SDK、签名证书、Profile、设备 UDID、
私钥或本机签名配置。开发者需要自行安装 HarmonyOS SDK，并在本机配置自己的签名。

## 应用适配

先准备完整 Chromium checkout，并切换到上述固定提交、同步 DEPS，然后执行：

```bash
./scripts/apply-adapter.sh /path/to/chromium/src
cp config/args.plan_kirin_pc.gn /path/to/chromium/src/out/plan_kirin_pc/args.gn
```

继续构建前请阅读 [BUILDING.md](BUILDING.md)。许可证及对应源码说明见
[OPEN_SOURCE_NOTICES.md](OPEN_SOURCE_NOTICES.md) 与 [SOURCE_OFFER.md](SOURCE_OFFER.md)。
DRM/编解码边界见 [docs/DRM_AND_MEDIA.md](docs/DRM_AND_MEDIA.md)，账号与同步信任模型见
[docs/HARMONYOS_SYNC.md](docs/HARMONYOS_SYNC.md)。
