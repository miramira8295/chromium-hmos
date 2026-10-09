# OHOS Surface 视频零拷贝

本路径去掉 **8／10 位硬解输出 → Chromium 视频帧** 之间的逐帧 CPU
`CopyOutput()` 像素拷贝。解码器写入 ConsumerSurface 的 NativeBuffer，
GPU 进程直接导入 EGLImage／SharedImage，renderer 只接收 mailbox。
压缩码流输入仍会复制；视频合成、Canvas/WebGL 操作仍可能产生 GPU 采样或 GPU 拷贝。
不能把这里的“零拷贝”理解成整条媒体管线没有任何数据搬运。

状态：`build-010f7882` 已通过 Mate 70 Pro+ 单进程、默认配置的 H.264、HEVC Main／
Main10 SDR/PQ/HLG 零拷贝与导入复用功能验收（具体片源和范围见文末）。HLG 1080p
单轮丢帧 14/123，单列为性能待复测项。Pad 多进程、4K PQ/HLG 及 VP9／AV1 硬解
尚未由本轮覆盖，功耗／CPU 对照收益也尚未测量。

## 启用与回退

视频零拷贝和 SharedImage／EGLImage 导入复用默认开启，外壳正常启动即可，
无需 TESTSWITCH 或额外的 `enable-features` 参数。之前显式开启的参数可以移除；
如曾设置 `disable-features=OhosZeroCopyVideo`，需移除该项才能使用默认路径。
出现回归时回退内核版本。能力检查和初始化失败时的自动兼容回退继续保留。
文末旧版本交付记录中的“默认关闭”仅描述当时版本。

当前范围：

- 已被硬解能力表接受的 H.264、HEVC Main／Main10、VP9 Profile 0／2、AV1 Main；
  实际输出支持 8 位 NV12 和 10 位 P010。4:2:2／4:4:4 档次不加入硬解候选，
  本项不宣称保留 12 位输出。带 alpha 的视频交回软件解码器。
- HDR10／HLG 允许进入 Surface 路径，携带色域、传递函数、范围及 Chromium 已知的 HDR 元数据。
- Skia GL 合成，EGL 支持 `EGL_OHOS_image_native_buffer` 和 native fence。
  ANGLE Vulkan 只有同时具备这些 EGL 能力才可进入；仍需独立验证。
- 不支持的 GPU 后端在消费输入前保持旧 Buffer 路径。
- 不提供直接 WebGPU／overlay scanout 导入；VP9／AV1 无硬解能力时继续使用 Chromium 软件解码器。

GPU 能力检查或 Surface 初始化失败时，在**消耗压缩数据之前**回退 Buffer 模式。
进入 Surface 模式后遇到不支持的实际 NativeBuffer 格式、Main10／VP9 Profile 2 实际输出非 P010、导入失败或帧到达超时，
明确上报解码失败，不尝试重放已经消费的码流。

## 动态硬解选择与 HEVC 能力声明

VP9／AV1 与 H.264／HEVC 一样，从 AVCodecKit 查询硬件实现、profile 和尺寸范围。
`HARDWARE` 查询之后仍检查 `OH_AVCapability_IsHardware()`，不把系统软件解码器当硬解。
API 23 新增的 VP9／AV1 MIME 导出变量在运行时从定义它们的 `libnative_media_codecbase.so` 中 `dlsym` 读取，
取不到再查 `RTLD_DEFAULT`。引擎以 RTLD_LOCAL 方式作为模块加载，其依赖库不一定在 `RTLD_DEFAULT` 的全局查找范围内，
只查全局会在有硬解的设备上误报 `MIME unavailable` 而全部走软解。API 20～22 缺少符号时不产生加载依赖，
也不虚构硬解支持。空 profile 列表不会为 VP9／AV1／HEVC 猜测默认档次。
硬解查询本身不受 `OhosZeroCopyVideo` 开关控制；该开关只控制 Surface 输出。

系统不支持、档次／尺寸不匹配或硬解初始化失败时，由 Chromium 解码器选择器继续尝试软件实现。
保留 Chromium 自身的选择策略（包括部分低分辨率视频的软解优先策略）。VP9 使用 libvpx，AV1 使用 dav1d；
解码中途失败不承诺无缝回退。VP9 包和 AV1 OBU 不执行 H.264／HEVC 的 Annex B 转换。
兼容 Buffer 路径也读取原生格式：NV12／P010 按实际字节宽度复制，保留 P010 样本、输出色彩和已知 HDR 元数据，
无法确认高位深格式或遇到其他原生格式时明确失败，不按 8 位伪造输出。

`build-0e19c42c` 和 `build-47c09559` 的 runner 构建实际上关闭了 HEVC 解析／解封装，
所以仅有后端 Main／Main10 实现还不能使网页接受 `hvc1`／`hev1`。
本轮 `patches/ohos-hevc-capability.patch` 在 `proprietary_codecs=true` 时为 OHOS 启用
HEVC 解析和平台解码，并开启 optional HEVC capability：网页支持声明取决于 GPU 查询所得的真实 profile。
未新增 HEVC 软件解码器，也未开启 DRM。补丁基于已校验 SHA-256 的 runner 快照 `37748799880` 生成，
已检查首次应用、重复应用识别及应用后文件一致性。

外壳可筛选以下日志（能力查询会随 GPU 进程重启而重新发生）：

- `OHOS video capability: ... MIME unavailable`：旧系统缺少 MIME 符号。
- `OHOS video capability: ... no hardware decoder`：没有硬解实现，保留软件路径。
- `OHOS video capability: ... hardware decoder, usable profiles=...`：系统能力查询结果。
- `OHOS video decoder: selected hardware ... profile=... output=surface/buffer`：实际创建并启动的硬解实现。
- `hardware initialization failed; trying next decoder`：初始化失败，交回 Chromium 选择器。
- `first buffer frame format=...`：Buffer 输出的实际格式；不能当作零拷贝证据。

## 10 位格式与 HDR

AVCodec 的 `AV_PIXEL_FORMAT_NV12` 表示 UV 排列，并不充分说明输出只有 8 位。
OpenHarmony HCodec 的格式表同时把 `GRAPHIC_PIXEL_FMT_YCBCR_420_SP` 和
`GRAPHIC_PIXEL_FMT_YCBCR_P010` 映射到此枚举；解析流后更新原生分配格式。
因此保留兼容的 AVCodec 配置，以取得缓冲区后的 `OH_NativeBuffer_GetConfig()` 为准：

| 实际原生格式 | SharedImage | VideoFrame |
| --- | --- | --- |
| `NATIVEBUFFER_PIXEL_FMT_YCBCR_420_SP` | NV12，external sampler | `PIXEL_FORMAT_NV12` |
| `NATIVEBUFFER_PIXEL_FMT_YCBCR_P010` | P010，external sampler | `PIXEL_FORMAT_P010LE` |
| NV21、YCrCb P010、未知格式 | 明确报错，避免错误解释 UV 顺序或位深 | 不输出伪造帧 |

Main10 必须实际取得 P010 才算本项通过；不能用“播放成功”或视频文件名证明位深。
不以 stride 猜位深，也不映射／重排／截断 P010 的像素。

色彩标记优先使用 NativeBuffer 的已知色彩空间，其次使用解码器报告的完整色彩空间，
再回退码流配置；支持 BT.2020 PQ／HLG 的 full／limited range。
输出仍为 HDR 时，把配置中的 HDRMetadata 传到 VideoFrame；系统输出已变为 SDR 时不携带旧 HDRMetadata。
本次不新增解码器 HDR→SDR 转换请求，不改系统屏幕 HDR 开关。
这覆盖解码输出的 10 位与色彩传递，不等于显示面板、XComponent、合成目标已完成全链路 10 位 HDR 验收。
HDR10+／Dolby Vision／HDR Vivid 的专有动态元数据不新增解析支持。

接口依据：DevEco CLI 的 `native_avformat.h`、`native_buffer.h` 文档，以及
[OpenHarmony HCodec 格式表](https://github.com/eclipse-oniro-mirrors/multimedia_av_codec/blob/OpenHarmony-5.1.0-Release/services/engine/codec/video/hcodec/type_converter.cpp)
和 [HDecoder 输出格式更新](https://github.com/eclipse-oniro-mirrors/multimedia_av_codec/blob/OpenHarmony-5.1.0-Release/services/engine/codec/video/hcodec/hdecoder.cpp)。
系统版本可能采用厂商实现，最终仍以设备实际输出和日志为准。

## 同步与生命周期

- 解码器只向 Surface 提交一个尚未 Acquire 的输出，按消费 FIFO 配对 PTS；
  不使用仅适用于 `UpdateSurfaceImage` 的时间戳 API。Surface 输出 `size=0` 仍是有效帧。
- NativeBuffer 不映射、不导出 dma-buf，不向缓冲区写身份标记。
- acquire fence 进入 SharedImage 的 external write fence；所有 GPU 读操作先等待它。
- VideoFrame 设置 `read_lock_fences_enabled`；释放时等待 Chromium 的 GPU 完成 token，
  再在媒体序列归还 NativeWindowBuffer。提前丢弃的帧也携带原 producer fence 归还。
- 每个解码 epoch 最多持有 4 个已取得的 Surface 帧，满额后暂停提交输出，释放后恢复。
  对 Chromium 的 `CanReadWithoutStalling()` 保守返回 false：系统实际队列可能更小，
  避免 preroll 为凑满帧而等待一个已经耗尽的固定缓冲池。
- seek/reset 与 EOS 后重启使用新 codec 和新 ConsumerSurface；旧帧独立持有旧队列。
  EOS 等待已提交帧的转换和输出回调完成，但不会等待显示方释放最后一帧。
- 解码器销毁前将旧 Surface 标记为退役。平台销毁 producer 时会清空队列缓存；
  旧帧等 GPU 使用完成后直接释放 Acquire 引用和额外持有引用、关闭 producer fence，
  不再向已清空的旧队列调用 ReleaseBuffer。活动队列仍按原方式携带 fence 归还，失败仍报错。
- ConsumerSurface 和其借用的 NativeWindow 一起销毁；不单独销毁借用窗口。

主要代码：`overlay/media/gpu/ohos/ohos_video_decoder.*`、
`ohos_video_surface.*`、`ohos_video_frame_converter.*`、
`overlay/ui/ozone/platform/ohos/ohos_native_pixmap.*`。
上游接线在 `patches/ohos-video-zero-copy.patch`，已注册增量构建脚本。

## 外壳验证

使用 `docs/test-pages/video-zero-copy.html`，或通过 `scripts/serve-test-pages.sh` 提供页面。
页面默认静音，选择本地文件或输入测试资源 URL 后手动播放；不自带远程视频请求。
脚本现使用支持 HTTP 单段 Range 的服务器，返回 `206`／`Content-Range`，支持开放末尾与 suffix range，
超界返回 `416`；多段 Range 回到完整响应。可用
`python3 scripts/serve-test-pages.py --directory /测试素材目录 --port 8080`
单独提供素材（不操作设备）。此前 `python3 -m http.server` 不支持 Range，不能用它的 URL seek 结果判断内核。

先在默认 ANGLE GLES 下做开关关闭／开启对照：

1. H.264 1080p30、1080p60、2160p30/60，HEVC Main 1080p／2160p；
   检查首帧、连续播放、颜色（含 BT.601／BT.709、full／limited range）、裁切和音画同步。
   全程静音也应正常推进；音画同步需另用有声测试片人工验证。
2. 暂停恢复、逐次 seek、页面内连续 seek、临近结尾、EOS 后重播、循环播放。
   不应停在最后一帧、出现上一时间线的帧或报 surface arrival timeout。
3. 点击 Canvas 和 WebGL 取帧，核对画面；同源视频应无导入失败或安全异常。
   跨域视频需服务端允许 CORS，CORS 错误不能归因于 GPU 导入。
4. 保留一帧后继续播放／seek，再绘制保留帧；该图应保持不变。释放后播放应能继续。
5. 全屏、切后台再回来、切换视频、关闭标签页；反复 20 次。
   观察 GPU 进程存活、FD 数和内存是否持续增长，留意 native buffer release 错误。
6. `ohos-isolate-renderers` 开启时重复短流程；测试硬解与独立 renderer 的 mailbox 传递。
7. HEVC Main10 分别使用 **10 位 SDR、HDR10/PQ、HLG** 测试片，1080p／4K 均覆盖。
   用 `ffprobe -v error -select_streams v:0 -show_entries stream=codec_name,profile,pix_fmt,color_range,color_space,color_transfer,color_primaries -of json 文件名` 核实输入格式。
   检查首帧日志必须含 `format=PIXEL_FORMAT_P010LE`，
   HDR 视频的 `color_space` 应包含 PQ 或 HLG、BT2020 及正确范围。
   HLG 可能没有静态 HDRMetadata，`hdr_metadata=0` 本身不是失败。
   比较灰阶渐变、暗部、高光、肤色与已知正确参考；测试页的 8 位 Canvas 读回不能证明面板有 10 位输出。
8. 8 位 → 10 位 → 8 位切换、HDR → SDR 切换并重复 seek／重播；不应残留旧格式或 HDR 元数据。
   去掉开关重启后再做原 Buffer 路径的基础播放回归。
9. 当前无 VP9／AV1 硬解的系统：能力日志应显示无硬解，原有 VP9／AV1（含 10 位）软解应保持正常。
   若后续设备报告硬解，分别测试 VP9 Profile 0／2、AV1 Main 8／10 位的 Buffer 与 Surface 模式；
   结合实际解码器日志与首帧格式确认选择结果，不以 `canPlayType()` 单独认定硬解。
10. HEVC 用完整 RFC 6381 codec 字符串测试 `canPlayType()`／MSE，再实际播放 Main 和 Main10；
    可用于 profile 探测的完整示例为 `hvc1.1.6.L153.B0`、`hvc1.2.4.L153.B0`、`hev1.2.4.L153.B0`，
    实际 MSE／MediaCapabilities 配置需使用与素材匹配的 level 等字段。
    `hvc1.1.6`、`hvc1.2.4`、`hev1.2.4` 缺少 tier／level，Chromium 解析器要求至少四段，
    这些缩写即使在支持 HEVC 的构建上也会返回空，不能用作 HEVC 能力验收。
    硬件能力查询为空时返回不支持是正确结果。有能力时应能看到视频画面和所选硬解日志。
    H.264 重复 seek、清空视频、重播及保留帧，确认旧队列的 `41210000`／`surface release failed` 不再刷屏。

日志筛选：`OHOS video zero-copy`、`OHOS native pixmap`、`OhosVideoDecoder error`、
`SharedImage`、`EGLImage`、GPU context lost／进程退出。

| 日志 | 含义 |
| --- | --- |
| `first SharedImage frame ...; CPU output copies=0` | 该 decoder 已交付第一张 Surface-backed SharedImage 帧，未走 CPU 输出拷贝 |
| `OHOS native pixmap: imported ...` | 当前 GPU 进程至少成功做过一次 NativeBuffer EGL 导入；此日志也可能来自其他 pixmap，不能单独证明视频零拷贝 |
| `GPU import/fences unavailable; buffer mode` | 启用请求未满足 GPU 条件，使用旧路径 |
| `profile ineligible; buffer mode` | 当前视频不在支持的 codec/profile 范围 |
| `surface initialization failed; buffer mode` | 初始化失败，已在消费输入前回退 |
| `... requires P010 but received ...` | 平台没有交付预期高位深缓冲区，明确失败，不能算 10 位零拷贝通过 |
| `surface SharedImage conversion failed` / `surface frame arrival timed out` | 运行中失败，需附前后日志排查 |

“首张 SharedImage 帧”日志现在包含实际帧格式、色彩空间、是否有 HDRMetadata，每次重新初始化记录一次。
它证明到达转换出口；还需画面和 EGL 导入日志一起确认实际显示。
仅看到播放正常或命令行开关，不能认定启用了本路径。

性能对比使用同一真机、同一视频、同一亮度／窗口大小、稳定温度，关开各播放至少 60 秒，
记录帧率、丢帧、CPU/GPU 使用率、功耗及进程内存。模拟器只验证功能，不用其功耗推算真机收益。
测试页帧回调是显示节奏指标，不是解码 CPU 耗时或 GPU 带宽计数器。

4K（3840×2160）P010 的未压缩像素约 24.9 MB／帧；一次完整 CPU 拷贝的读＋写，
在 60 fps 下理论上约 2.99 GB/s。此数字仅说明可避免的完整 P010 拷贝规模，
不代表已测得的整机带宽差值或功耗降幅。CPU 拷贝减少有望改善发热、续航和带宽受限时的掉帧，
不会增加视频分辨率或保证帧率翻倍。

## 2026-10-08 Main10／P010 交付记录

- 内核提交：`47c09559b2fa2decfbdeeb3c5549842fca21b60f`，产物标签：`build-47c09559`。
- [增量构建 37745445847](https://github.com/miramira8295/chromium-hmos/actions/runs/37745445847)：成功，HAR 和未剥离符号均已上传。
- [Adapter CI 37745445835](https://github.com/miramira8295/chromium-hmos/actions/runs/37745445835)：成功。
- [engine.har](https://github.com/miramira8295/chromium-hmos/releases/download/build-47c09559/engine.har)（136454453 字节），发布资产 SHA-256：`cc0ad405f45c42ce1b4cb4c92195b90bb99b7b2ed3c0c619860256ec594b7bb7`。
- 继续使用 `--enable-features=OhosZeroCopyVideo`；默认关闭，外壳无需新增接口。
- 本轮完成 10 位输出格式和色彩／HDR 元数据传递，待外壳按上述矩阵验证实际 P010 输出、画面及生命周期。
- 尚无设备功能、功耗或性能实测结论；屏幕端全链路 10 位 HDR 需另行验证。

## 2026-10-08 首版（8 位）交付记录

- 内核提交：`0e19c42cf8c8b9e227f7032db2eb89c6a46b624a`。
- [增量构建 37740779258](https://github.com/miramira8295/chromium-hmos/actions/runs/37740779258)：成功，HAR 和未剥离符号均已上传。
- [Adapter CI 37740779085](https://github.com/miramira8295/chromium-hmos/actions/runs/37740779085)：成功，包含公开树、脚本、memfd 契约和固定 Chromium 版本适配检查。
- [engine.har](https://github.com/miramira8295/chromium-hmos/releases/download/build-0e19c42c/engine.har)（136445801 字节），SHA-256：`c46013af179fd7164e5ae63e51d9e94a2e671c8bb1728594e8c4658460843277`。
- 上游接线基于 runner 快照 `37736920489`，已核验快照 SHA-256、补丁首次／重复应用及最终文件一致性。
- 测试页脚本已通过 `node --check`；交付时设备验证待外壳执行，后续反馈见下节。
- 默认开关保持关闭；无功耗／CPU 开关对照实测结论。

## Mate 70 Pro+ 外壳验收反馈（build-0e19c42c）

维护者转来的真机结果：H.264 High 1080p30、1080p60、2160p30 均出现
`first SharedImage frame ...; CPU output copies=0`，无 Buffer 回退，画面颜色正常，未观察到丢帧。
暂停恢复、连续 seek、EOS 重播／循环、Canvas／WebGL 取帧和保留帧通过；
全屏 ×10、前后台切换 ×10、关闭重开 ×100 未发生黑屏、花屏、卡住、进程退出或内存持续增长。

反馈同时指出旧帧归还报 `41210000 / cache not find the buffer`、HEVC 网页能力为空、
测试服务器 URL seek 回到 0 秒。本轮分别处理 Surface 退役、HEVC 构建开关和 HTTP Range；
修复后的回归、HEVC／VP9／AV1 新路径仍待外壳验收。上述结果只覆盖该旧版 H.264，不是 10 位或新增编码格式的验收。

## Mate 70 Pro+ 回归反馈（build-47c09559）

手机单进程、开启 `OhosZeroCopyVideo`，维护者已校验 HAR SHA-256。
H.264 1080p30／2160p30 保持零拷贝；首帧为 `PIXEL_FORMAT_NV12`、BT709 limited，
播放、暂停恢复、seek、重播、Canvas 取帧和保留帧通过，未观察到丢帧。
4K 快速脚本曾未等待 EOS／Canvas 可用，不能据此判定回归；此前放慢操作已通过。

Main10 SDR／PQ／HLG（1080p、4K，均为 yuv420p10le）仍被网页 HEVC 能力判断挡住，
只有音轨、`videoWidth=0`，没有进入解码器。系统已有 HEVC 解码能力，不能据此认定设备无硬解。
该版仍出现旧 Surface 归还错误（1080p 一轮 68 条，4K 一轮 32 条）。
本轮修复针对这两个已确认问题；P010、PQ／HLG 色彩和格式切换仍待新构建补测。

## 构建开关核验（32ccb220 之后）

`32ccb220` 的 VP9／AV1 动态硬解、HEVC 前端开关、Surface 退役和 Range 服务已进入
后续 `3a1baca8` 构建。runner 源码快照 `37772039250` 已逐文件校验哈希：
`ENABLE_PLATFORM_HEVC`、`ENABLE_HEVC_PARSER_AND_HW_DECODER` 和
`PLATFORM_HAS_OPTIONAL_HEVC_DECODE_SUPPORT` 均为 1；
`ENABLE_LIBVPX`、`ENABLE_DAV1D_DECODER` 和 `ENABLE_AV1_DECODER` 仍为 1。
这证明功能已编入，不等同于 HEVC／Main10／VP9／AV1 真机路径验收。

`3a1baca8` 已收到标签页截图和外链冷启动的共享内存导入崩溃反馈，不能作为稳定验收包；
修复进展见 [渲染隔离记录](OHOS_RENDERER_ISOLATION.md)。媒体复测应使用后续修复构建。

## 切换标签后屏幕停在 HDR 亮度（2026-10-08）

现象：手机播放 YouTube HDR（PQ）视频后切到别的标签页，屏幕一直保持 HDR 亮度，
普通网页的白底显示成灰色。日志里窗口在播放时被标成 `Rec. 2020 PQ, HDR10`，
切换后再没有改回 sRGB；同一标签页内从视频页跳到别的页面则能正常改回。

原因在 viz：`SurfaceAggregator` 汇总一帧时，会对"被引用但不显示"的 surface 也做 prewalk，
并把它们的 `content_color_usage` 一并取最大值。被隐藏的标签页不再出新帧，浏览器仍引用它最后那个 HDR 帧，
于是整帧输出一直选 PQ，`ohos_surface_factory.cc` 也就一直没收到改回 sRGB 的 Resize。
真机上已排除可见页面（刷新、滚动无效）和后台标签页内容（清掉视频、跳转空白页无效）。

修复放在 `patches/ohos-video-zero-copy.patch`：不显示的 surface 照常 prewalk（复制请求等仍需要），
但不参与输出色彩空间的选择。

## SharedImage / EGLImage 导入复用

导入复用随默认零拷贝路径生效，不设独立测试开关。它减少同一解码 NativeBuffer
循环使用时的 SharedImage 创建；Ozone backing 已有的每 context 纹理缓存
随之保留 EGLImage。视频位深和 HDR 输出规则不变。

生命周期约束：

- 缓存使用 NativeBuffer 的唯一序列号，限于同一解码代次，并核对尺寸、格式和色彩空间。
- 缓存导入使用独立 native wrapper，只持有底层 allocation；原始 pixmap 单独持有本帧
  ConsumerSurface lease。不能把带队列 lease 的 pixmap 放进长期缓存。
- VideoFrame 被释放后，还要等待 GPU read-completion token 和本次外部更新 token。
  两者完成后才归还队列 lease，并允许该 SharedImage 再次复用。
- 每次复用都通过 `BackingWasExternallyUpdated` 更新本帧 acquire fence，提供新的
  verified SyncToken 给读取者；不能重复使用初次创建时的 token 来表示新帧就绪。
- seek、EOS 后重启、配置变化和销毁解码器时清空该代次缓存；之后归还的旧代次帧不能
  填回新缓存。GPU stub 销毁时也清空缓存。
- 最多缓存 8 个空闲导入，估算像素内存最多 128 MiB；超限淘汰最早归还的空闲项。
  10 秒没有新的可缓存归还时清空空闲项。活跃/保留帧不计入这个空闲预算，不会被强制释放。
- 独立 wrapper 创建失败时，该帧继续使用原来不缓存的导入路径。

外壳正常启动即可验证。需要查看复用计数时，可选加日志参数：

```text
--vmodule=ohos_video_frame_converter=1
```

该参数只控制诊断日志，不控制功能。修改参数后完全重启应用；不要带上一轮软解上传
回收测试的 `--disable-accelerated-video-decode`。性能对照使用复用实现之前的构建，
并确认两版实际都走零拷贝、使用相同媒体和运行条件。

首次命中应出现 `OHOS video zero-copy: SharedImage reuse active`。
每 300 帧、解码代次结束和空闲清理前，在 VLOG(1) 输出：

```text
OHOS video SharedImage cache: generation=... created=... reused=... uncached=... idle=... estimated_bytes=...
```

`created/reused/uncached` 是当前解码代次内累计计数。持续播放、尺寸和颜色不变时，
`reused` 应持续增长，`created` 通常应明显少于总帧数。
队列缓冲数量、预算淘汰和长暂停可能带来额外创建，不能要求始终只创建某个固定数量。
`created` 统计 SharedImage 创建，不是驱动内部 EGLImage 调用次数；EGLImage 的实际
复用取决于 Ozone context 纹理缓存，需结合 trace 验证。应保持 CPU output copies=0。

设备回归沿用前述矩阵：H.264 1080p60/4K、HEVC Main10 的 SDR/PQ/HLG；重点覆盖
持续播放、连续 seek、8/10 位切换、暂停超过 10 秒再恢复、Canvas/WebGL 保留旧帧后
继续播放、关闭页面，以及 Pad 多进程。旧帧不能变成新帧画面，不能出现队列卡死、花屏、
新的 surface release 错误或持续内存增长。HDR 网页亮度待办仍暂缓。

`aura_shell_smoke_tests` 增加 `OhosVideoSharedImageCacheTest.*` 和
`OhosNativePixmapTest.CachedImportDoesNotHoldFrameLease`，覆盖元数据不匹配、旧代次
迟归还、独占取出、数量/字节预算，以及独立导入引用不占用原始帧 lease。
这些测试不替代真机 GPU fence、EGL 驱动和功耗验收。

### 2026-10-09 首帧转换失败回归

外壳在 Mate 70 Pro+ 单进程、默认启动配置下报告：`build-2115d651` 的 H.264、
HEVC Main／Main10（SDR、PQ、HLG）首帧均在转换阶段失败，H.264 仅靠后续软解才能播放。
对照 `build-500ebea0` 的 H.264 NV12 和 `build-a00494a1` 的 Main10 P010 均能零拷贝播放。

代码确认：复用实现只在 `DestroyCodec()` 递增代次时重置转换器缓存，遗漏了
`CreateCodec()` 的下一次递增。例如首次初始化缓存停在代次 1，解码输出已是代次 2，
`Convert()` 在导入前直接拒绝首帧。seek 和 EOS 重建也有同样问题；此处尚未执行
SharedImage 导入、缓存复用或 acquire fence 更新。

修复将创建、销毁和 Buffer flush 的代次切换统一到 `AdvanceGeneration()`，在同一
GPU task runner 上先投递缓存 Reset，再投递该代次的 Convert，保留旧帧不可归还到
新代次缓存的约束。零拷贝和复用仍默认开启，无需外壳测试开关。

转换失败现在会在普通 ERROR 日志中区分 stub 不可用、代次不匹配、pixmap 缺失、
可见区域越界、GL context 失败、格式不支持、SharedImage 创建失败和 VideoFrame
包装失败，并附上相关代次、尺寸及导入／同步状态。独立 wrapper 不可用时会记录
一次降级到不缓存导入的日志。

修复时的设备复测要求：先确认 H.264 NV12、HEVC Main NV12、Main10 P010 都出现
`first SharedImage frame ... CPU output copies=0`，持续播放后出现
`SharedImage reuse active`；再覆盖 seek、播完重播、SDR/PQ/HLG 切换及保留旧帧。
首帧成功只验证代次修复，不能替代实际复用后的画面与同步验收。

### build-010f7882 手机验收及 HLG 性能待复测

以下为外壳回传结果，非内核开发环境执行：Mate 70 Pro+、单进程、默认启动配置，
没有测试开关；HAR SHA-256 `55771290a5f62450c1e0a94035ecff8382bd9799847b847a03a4ae4d336a0763` 已校验。
所有片源均完成播放、暂停恢复、seek ×10、播完重播、Canvas/WebGL 取帧，以及保留帧
12 秒后重新绘制且画面不变。

| 片源 | 丢帧／总帧（外壳记录） | 首帧格式／色彩 | reuse active 日志次数 | 转换失败 |
| --- | --- | --- | --- | --- |
| H.264 1080p30 | 0/123 | NV12 BT709 | 23 | 0 |
| H.264 1080p60 | 0/240 | NV12 BT709 | 21 | 0 |
| H.264 2160p30 | 0/122 | NV12 BT709 | 21 | 0 |
| HEVC Main 1080p | 0/122 | NV12 BT709 | 22 | 0 |
| HEVC Main10 SDR 1080p | 0/123 | P010 BT709 | 23 | 0 |
| HEVC Main10 PQ 1080p | 0/122 | P010 BT2020/PQ，hdr_metadata=1 | 23 | 0 |
| HEVC Main10 HLG 1080p | 14/123 | P010 BT2020/HLG | 23 | 0 |
| HEVC Main10 SDR 2160p | 0/123 | P010 BT709 | 19 | 0 |

零拷贝首帧确认 `CPU output copies=0`。全程无 `buffer mode`、`arrival timed out`、
`requires P010`、`context lost` 或崩溃。`SharedImage reuse active` 每代次首次复用
只打一次，因此表中次数不是复用帧数，也不能用于计算缓存命中率。

同页按 SDR → PQ → HLG → H.264 → PQ 等顺序切换共 8 次，每次再 seek，均有画面且
继续播放；首帧格式和色彩正确。只有 PQ 的 hdr_metadata=1，切回 SDR/8 位后为 0，
没有旧 HDR 元数据残留。HLG 日志为 white 203 nits、peak 1000 nits、gamma 1.2。

HLG 代码检查（基于固定 Chromium `743f26418a267dd97c3c1c71d786038ae68cfc8f`）：

- OHOS 转换器的 P010 导入、复用和 fence 流程不区分 PQ/HLG，Surface 路径没有新增
  HLG 专用 CPU 像素转换。`OhosVideoColorSpace()` 保留 HLG 标记。
- `ohos_screen.cc` 的 HDR 输出空间统一为 PQ，因此 HLG 到最终输出存在色彩转换。
  上游 `SkiaRenderer::DrawTextureQuad()` 对 PQ 和 HLG 的 HDR 视频都会选择 tone-map
  路径，调用 `ToneMapUtil::AddGlobalToneMapFilterToPaint()`，不能据此宣称只有 HLG
  多一次渲染 pass，或认定丢帧由 HLG shader 引起。
- 上游 `ui/gfx/color_space.cc` 会在未指定参数时显示上述 HLG 默认值；1000 nits 是
  色彩转换的默认峰值参数，不代表测得手机面板峰值，也不是异常或旧 PQ 元数据残留。
- 当前只有一次短样本，尚不能区分首播 shader 编译、解码供应、GPU/fence 等待、
  调度、设备温度和 seek／Canvas/WebGL 操作造成的开销。保持现有色彩和复用逻辑。

复测无需功能开关：使用同源且分辨率、帧率和编码设置尽量一致的 Main10 SDR/PQ/HLG
长片，固定亮度和窗口大小；分别记录冷启动首播及同进程第二遍，每组至少 3 次。
纯播放阶段不执行 seek／取帧，先记录前 5 秒，再统计其后至少 60 秒的
`getVideoPlaybackQuality()` 总帧／丢帧增量（每秒采样），把 seek、取帧测试另记。
若热身后 HLG 仍稳定丢帧，再采集同时间段 media/viz/gpu trace 和系统 GPU 数据，
区分解码输出迟到、GPU 队列／fence 等待与合成耗时，不能把 CPU 提交耗时当 GPU 执行时间。

## 待办：HDR 播放时网页也跟着变亮（已记录，暂缓）

现象：播放 HDR 视频时，网页上视频以外的部分（白底、文字）也比平时亮。

原因：HDR 输出用的是绝对亮度的 PQ。`ohos_screen.cc` 的 HDR 输出写死为 `CreateHDR10()`，
`ohos_surface_factory.cc` 把整个窗口标成 Rec. 2020 PQ / HDR10，SDR 白固定在 203 尼特；
面板进入 HDR 模式后，这通常比用户平时的 SDR 亮度高。

Chromium 在安卓上的做法依赖安卓专用接口，未随 Ozone 移植过来：
扩展范围 sRGB（SDR 白 = 1.0、HDR 高光超出 1.0）加 `ASurfaceTransaction_setExtendedRangeBrightness`
（`ui/gfx/android/android_surface_control_compat.cc`），由屏幕当前余量设
`SetHDRMaxLuminanceRelative`（`ui/android/display_android_manager.cc`）；视频另可提到独立 SurfaceControl 图层。

计划：按安卓思路改为相对亮度。先在真机确认 RenderService 是否接受超过 1.0 的扩展范围缓冲区
（OHOS 线性 / 扩展色彩空间），以及 `external_window.h` 的 `SET_SDR_WHITE_POINT_BRIGHTNESS`、
`SET_HDR_WHITE_POINT_BRIGHTNESS`（API 12，取值 0～1，含义文档未写明）的实际效果；
再改 HDR 输出、设置白点、按系统可得的屏幕余量设置相对 HDR 亮度。
退路：设置项"HDR 视频"关闭时色调映射为 SDR。长期：视频走独立系统图层（直出），工作量以周计。
