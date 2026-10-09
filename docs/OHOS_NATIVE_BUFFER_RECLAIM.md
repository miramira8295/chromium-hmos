# NativeBuffer 闲置回收

## 行为

分配器管理的 NativeBuffer 在最后一个 `OhosNativePixmap` 释放后进入 10 秒宽限期，
用于容纳仍在跨进程传递的 dma-buf 句柄。原来只在下一次分配时清理到期项；现在会自动
安排延迟任务，不再依赖后续播放、分配或页面操作。

- 只释放使用者数量为零、并且连续闲置满 10 秒的项。
- 宽限期内重新导入会保护该缓冲，下一次最后使用者释放时重新计时。
- 多个闲置缓冲共用一个延迟清理任务，按最近的到期时间再次调度；清空后停止调度。
- 注册 Chromium 的异步 MemoryConsumer，收到释放内存请求时也只清理已到期项。
  内存压力不会缩短句柄交接宽限期，也不会释放仍在使用的项。
- 在注册表锁内移除到期项，在 ThreadPool 上、锁外销毁原生句柄并关闭注册表持有的 FD。

这不是可任意淘汰的图像缓存，因此没有设置会挤掉宽限期内缓冲的容量上限。
硬解 ConsumerSurface 帧不经过此注册表，仍按原有 GPU fence 和 Surface 生命周期归还。

10 秒从最后一个 pixmap 释放时开始计算，不是从点击暂停时计算；Chromium 帧池或页面
仍持有的帧不会被提前释放。任务调度繁忙时回收可能晚于 10 秒。注册表释放引用也不等同于
驱动立即释放物理内存：外部 FD、GPU 或系统组件仍可能持有其他引用。

## 自动测试

`aura_shell_smoke_tests` 新增 `OhosNativePixmapTest.IdleRetirementAndReimport`，
使用真实 NativeBuffer 分配和 Chromium mock time，不创建 GL context，覆盖：

- 没有后续分配时自动到期回收；
- 内存释放请求不能挤掉宽限期内的缓冲；
- 到期前重新导入、多个使用者、最后一次释放后重新计时；
- 不同时间释放的缓冲分别到期；
- 清空后没有持续定时唤醒。

测试需在具有 NativeBuffer 分配能力的 OHOS 环境执行：

```sh
./aura_shell_smoke_tests --gtest_filter=OhosNativePixmapTest.*
```

## 外壳验收

启动参数增加 `--vmodule=ohos_native_pixmap=1` 可观察按批次输出的回收日志：

```text
OHOS native pixmap: reclaimed N idle buffers, B bytes
```

1. 播放确认走 NativeBuffer 上传的软解视频，或运行 WebGPU 页面；只播放硬解
   零拷贝视频不足以覆盖本次修改。
2. 关闭视频/页面，让相关帧池和 GPU 资源释放，之后不打开新页面、不创建新视频。
   观察最后一批闲置项是否自动回收，结合 GPU/进程内存曲线记录结果。
3. 连续播放、暂停恢复、seek、反复关闭重开，以及 Canvas/WebGL 保留视频帧时，
   确认没有新增 `handle for a buffer from elsewhere`、花屏或崩溃。
4. Pad 多进程模式重点覆盖关闭后快速重开，检查跨进程句柄交接没有退步。
5. 如外壳可以注入内存压力，分别在资源仍活跃、释放不到 10 秒和闲置到期后触发；
   活跃资源和宽限期内资源不能被清理。

代码审查/编译不能代替上述设备验收；设备结果由外壳补充。
