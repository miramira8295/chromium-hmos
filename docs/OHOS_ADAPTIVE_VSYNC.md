# OHOS 动态帧率与 VSync 策略

本轮默认启用内容驱动的 NativeVSync 帧率请求，无需外壳测试开关。真机效果待验收。
背景见 [HLG trace 分析](OHOS_HLG_TRACE_ANALYSIS.md)：原策略始终请求 120 Hz，
HLG 和 SDR 实测分别约 120/60 Hz；多数 `BeginFrameDropped` 是 no-damage 与
MISSED 重投配对，不能直接当作视频掉帧或 SharedImage 同步阻塞。

## 策略

使用 Chromium `FrameIntervalDecider` 对实际参与合成的 Surface 进行判断，
沿 Display → Skia GPU → VSyncProvider 把请求传给
`OH_NativeVSync_SetExpectedFrameRateRange`。手机单进程与 Pad 多进程走相同链路。

GL 与 Vulkan 两条后端都接入：GL 由 `OhosNativeViewGLSurfaceEGL` 持有
`OhosVSyncProvider`；Vulkan 由 ozone 在创建 `VulkanImplementationOhos` 时传入
同一 provider 工厂，`VulkanSurface` 持有它，`SkiaOutputDeviceVulkan` 转发帧率请求。
此前 Vulkan 用固定 60 Hz 假设驱动 BeginFrame，也不提交帧率请求。
Vulkan 的呈现反馈按 GL 的做法对齐到下一个 VSync，并带 `kVSync`/`kHWClock`，
否则 viz 会因时间早于绘制而丢弃反馈，BeginFrame 无法跟随实际周期。

| 场景 | 期望请求 |
| --- | --- |
| 输入、混合动画、无法确定内容节奏 | 120 Hz |
| 只有同帧率视频更新，30 / 29.97 / 60 / 59.94 fps | 60 Hz |
| 只有 24 / 23.976 fps 视频更新 | 72 Hz |
| 只有 25 fps 视频更新 | 75 Hz |
| 只有 50 fps 视频更新 | 100 Hz |
| 500 ms 没有查询绘制 VSync 参数 | 取消期望请求 `{0,0,0}` |

活跃请求范围暂限 60–120 Hz。整数 NativeVSync API 对分数帧率四舍五入，
匹配器边界容差 50 μs，避免 1000/1001 帧率或微秒取整误选额外倍频。
72/75/100 Hz 只是期望值，不声称屏幕具备这些模式；系统可能因屏幕能力、
其他窗口、HDR、功耗或温控选择不同频率。

升频在包含输入或其他动画的新合成帧被聚合后立即提交，不等待降频计时；
降频沿用调度器的防抖，最近一次原有高频决策过去超过 500 ms 才允许降低。
没有原有决策的首次匹配可立即采用视频频率。
超过 250 ms 未更新的 Surface 不阻止纯视频匹配。
完全闲置会停止连续请求 VSync 并取消期望帧率；恢复绘制时重新提交最近内容偏好，
后续聚合输入帧可将其提升至 120 Hz。

实际 BeginFrame 周期仍来自 `OH_NativeVSync_GetPeriod`，不使用视频请求值覆盖
测得的周期。请求变化后 1 秒内每次回调复查实际周期，稳定后每秒复查一次。
现有 DVSync 与 2 ms BeginFrame 相位偏移保持原策略。
原生请求返回参数错误（40001000）时视为本机不支持，尝试恢复旧的 `{60,120,120}`
请求并停止该实例的动态请求；其他错误视为暂时失败，1 秒后的下一帧重试，
日志前 3 次及之后每 100 次输出一条。

NativeVSync 回调不再直接持有 provider 裸指针：每次请求帧时给一个引用计数的
回调目标加引用，回调释放；provider 析构先断开目标，晚到的回调不会访问已释放对象。

SDR、PQ、HLG 使用相同决策；本轮不改变 HDR 色调映射、亮度、像素格式、
SharedImage/EGLImage 缓存或 fence。预期收益是纯视频场景减少不必要的调度唤醒，
实际 GPU 工作量与功耗收益需实测，不能按刷新率下降比例推算。

## 外壳验证

默认启动配置，不加测试开关。与 `build-010f7882` 对照，保持系统刷新率设置、
亮度、温度和电源状态一致；优先在 Mate 70 Pro+，再覆盖 Pad 多进程与渲染沙箱。
Vulkan 后端（若当前配置启用）需另测一遍第 1、3、4 项，确认日志同样出现
`requested rate=`，且 BeginFrame 间隔随实际周期变化，而非固定 16.7 ms。

1. 同帧率的 Main10 SDR/PQ/HLG 各稳定播放 15 秒，先测 1080p30，再测 60 fps。
   视频控件消失后，确认都有 `requested rate=60`，并分别记录实际 interval。
   若系统仍给 HDR 120 Hz，应记录实际结果，不算伪造为 60 Hz，也不能据此认定策略未请求。
2. 如有素材，测 24/23.976/25/29.97/50/59.94 fps，确认请求与上表一致，
   30/29.97 不应误请求 90 Hz，60/59.94 不应误请求 120 Hz。
3. 播放时滚动页面、拖动进度条、运行持续 CSS 动画，确认及时请求 120 Hz；
   停止输入且只剩视频更新后再次降频。短暂控件变化不应造成频繁升降频。
4. 暂停且等控件消失、打开静态空白页、切后台，观察闲置请求释放；恢复播放、
   返回前台、切换标签、全屏和转屏后有画面且刷新恢复正常。页面自己的持续动画
   会阻止闲置，不能仅凭视频暂停要求出现 `rate=0`。
5. 复测 seek ×10、播完重播、SDR/PQ/HLG/8 位切换、Canvas/WebGL 取帧和保留帧。
   仍应走 SharedImage 零拷贝，无颜色异常、转换失败或崩溃。

日志（仅策略变化和显著实际周期变化时输出）：

```text
OHOS VSync: requested rate=60 range=60..120 (content policy)
OHOS VSync: actual interval=16.6667 ms
OHOS VSync: requested rate=120 range=60..120 (content policy)
OHOS VSync: requested rate=0 range=0..0 (idle, request released)
```

Chromium trace 开启 `viz,cc,gpu,media`；需要决策输入时加
`disabled-by-default-cc.debug`。关注 `FrameIntervalDeciderResult`、
`FrameIntervalMatcherInputs`、`OhosVSyncRateRequest`、`OhosVSyncActualInterval`，
以及实际 BeginFrame 间隔与 `VideoFramesDropped`。配合 hitrace 的 graphic/sched/freq
观察系统选择。不要只比较 `Scheduler::BeginFrameDropped` 总数。

## 自动检查

补丁加入 `FrameIntervalDeciderTest.Ohos*` 三个用例，使用真实 InputBoost/OnlyVideo
匹配器，覆盖整数/分数视频帧率、防抖、输入及混合内容升频、过期 Surface。
它们属于上游 `viz_unittests`；本仓库默认原生 runner 只构建内核和 HAR，
不会运行这些用例。可在具备上游测试构建环境时执行：

```sh
viz_unittests --gtest_filter='FrameIntervalDeciderTest.Ohos*'
```

本地可检查固定 Chromium 版本上的补丁正向/反向应用、脚本语法与公开树检查；
编译以原生 runner 为准，设备行为由外壳验收。
