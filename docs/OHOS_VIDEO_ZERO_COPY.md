# OHOS Surface 视频零拷贝（实验）

本路径去掉 **8 位硬解输出 → Chromium 视频帧** 之间的逐帧 CPU
`CopyOutput()`／`NV12Copy`。解码器写入 ConsumerSurface 的 NativeBuffer，
GPU 进程直接导入 EGLImage／SharedImage，renderer 只接收 mailbox。
压缩码流输入仍会复制；视频合成、Canvas/WebGL 操作仍可能产生 GPU 采样或 GPU 拷贝。
不能把这里的“零拷贝”理解成整条媒体管线没有任何数据搬运。

状态：`build-0e19c42c` 已通过内核／HAR 构建和 Adapter CI，待外壳设备验证。
性能收益尚未测量；此前 renderer isolation 的验证结果不能替代本项验证。

## 启用与回退

默认关闭。外壳启动 Chromium 时，在已有 `--enable-features` 列表中追加：

```text
--enable-features=OhosZeroCopyVideo
```

已有其他 feature 时用逗号合并，不能用第二个同名 switch 覆盖原列表。
该 feature 通过 Chromium 的 feature 配置传给 GPU 进程；无需增加外壳接口。
删除该 feature 或加入 `--disable-features=OhosZeroCopyVideo` 后完全重启可回到默认 Buffer 模式。

首版范围：

- 已被硬解能力表接受的 H.264 和 HEVC Main；8 位 NV12。
- Skia GL 合成，EGL 支持 `EGL_OHOS_image_native_buffer` 和 native fence。
  ANGLE Vulkan 只有同时具备这些 EGL 能力才可进入；仍需独立验证。
- HEVC Main10、HDR 和不支持的 GPU 后端保持旧 Buffer 路径。
- 不提供直接 WebGPU／overlay scanout 导入，也不改变 VP9／AV1 软件解码。

GPU 能力检查或 Surface 初始化失败时，在**消耗压缩数据之前**回退 Buffer 模式。
进入 Surface 模式后遇到不支持的实际 NativeBuffer 格式、导入失败或帧到达超时，
明确上报解码失败，不尝试重放已经消费的码流。

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
- ConsumerSurface 和其借用的 NativeWindow 一起销毁；不单独销毁借用窗口。

主要代码：`overlay/media/gpu/ohos/ohos_video_decoder.*`、
`ohos_video_surface.*`、`ohos_video_frame_converter.*`、
`overlay/ui/ozone/platform/ohos/ohos_native_pixmap.*`。
上游接线在 `patches/ohos-video-zero-copy.patch`，已注册增量构建脚本。

## 外壳验证

使用 `docs/test-pages/video-zero-copy.html`，或通过 `scripts/serve-test-pages.sh` 提供页面。
页面默认静音，选择本地文件或输入测试资源 URL 后手动播放；不自带远程视频请求。

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
7. HEVC Main10/HDR 验证旧路径仍可用；去掉开关重启后再做基础播放回归。

日志筛选：`OHOS video zero-copy`、`OHOS native pixmap`、`OhosVideoDecoder error`、
`SharedImage`、`EGLImage`、GPU context lost／进程退出。

| 日志 | 含义 |
| --- | --- |
| `first SharedImage frame ...; CPU output copies=0` | 该 decoder 已交付第一张 Surface-backed SharedImage 帧，未走 CPU 输出拷贝 |
| `OHOS native pixmap: imported ...` | 当前 GPU 进程至少成功做过一次 NativeBuffer EGL 导入；此日志也可能来自其他 pixmap，不能单独证明视频零拷贝 |
| `GPU import/fences unavailable; buffer mode` | 启用请求未满足 GPU 条件，使用旧路径 |
| `profile/HDR ineligible; buffer mode` | 当前视频不在首版支持范围 |
| `surface initialization failed; buffer mode` | 初始化失败，已在消费输入前回退 |
| `surface SharedImage conversion failed` / `surface frame arrival timed out` | 运行中失败，需附前后日志排查 |

“首张 SharedImage 帧”证明到达转换出口；还需画面和 EGL 导入日志一起确认实际显示。
仅看到播放正常或命令行开关，不能认定启用了本路径。

性能对比使用同一真机、同一视频、同一亮度／窗口大小、稳定温度，关开各播放至少 60 秒，
记录帧率、丢帧、CPU/GPU 使用率、功耗及进程内存。模拟器只验证功能，不用其功耗推算真机收益。
测试页帧回调是显示节奏指标，不是解码 CPU 耗时或 GPU 带宽计数器。

## 2026-10-08 交付记录

- 内核提交：`0e19c42cf8c8b9e227f7032db2eb89c6a46b624a`。
- [增量构建 37740779258](https://github.com/miramira8295/chromium-hmos/actions/runs/37740779258)：成功，HAR 和未剥离符号均已上传。
- [Adapter CI 37740779085](https://github.com/miramira8295/chromium-hmos/actions/runs/37740779085)：成功，包含公开树、脚本、memfd 契约和固定 Chromium 版本适配检查。
- [engine.har](https://github.com/miramira8295/chromium-hmos/releases/download/build-0e19c42c/engine.har)（136445801 字节），SHA-256：`c46013af179fd7164e5ae63e51d9e94a2e671c8bb1728594e8c4658460843277`。
- 上游接线基于 runner 快照 `37736920489`，已核验快照 SHA-256、补丁首次／重复应用及最终文件一致性。
- 测试页脚本已通过 `node --check`；页面操作和设备生命周期验证仍待外壳执行。
- 本轮没有真机功能或性能结论，默认开关保持关闭。
