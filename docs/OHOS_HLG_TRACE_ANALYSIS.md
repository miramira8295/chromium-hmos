# HLG BeginFrameDropped 原始 trace 核验

设备为 Mate 70 Pro+，单进程，`build-010f7882`，外壳默认配置。
结论：这批 `Scheduler::BeginFrameDropped` 不能作为 HLG 持续错过有效绘制截止时间的
证据。HLG 稳定播放中的事件均可关联到无 damage 和同一帧重新投递后的替换；两次
采样的 BeginFrame 间隔分别约 120 Hz 和 60 Hz，尚不是同刷新节奏的 HDR/SDR 对照。
本轮不修改运行时调度、色彩转换或同步语义。

## 输入和复核方法

直接读取外壳的原始 Chromium JSON，核验文件 SHA-256：

| 文件 | SHA-256 |
| --- | --- |
| s_hevc10_hlg_1080p.json | b4efc7816a6b265f2711a5d83bde63b22319abbb88154755d32e330a47100aab |
| s_hevc10_sdr_1080p.json | ae7859fd7141bf873f0fb81dcb40f91ebdf0e9194c60456b8eebad56ddd150aa |

外壳采样脚本 `trace2.py` 在每个操作完成后调用 `phase(name)` 并发出 `PHASE name`。
标记是阶段结束点，不能当成开始点。例如 play-start → play-steady 之间是稳定播放，
play-steady → seek-x10 之间才是 seek 测试。

新增只读分析工具，可在原始文件目录复核：

```sh
python3 docs/tools/analyze-ohos-video-trace.py \
  /path/to/tr/s_hevc10_hlg_1080p.json \
  /path/to/tr/s_hevc10_sdr_1080p.json
```

工具将每个 dropped 事件与同线程紧随其后的 `Scheduler::SendDidNotProduceFrame`
scope 内的 `LayerTreeHostImpl::DidNotProduceFrame` 关联，读取具名原因和帧序号，
不猜测数值枚举。两份输入的 133 个 dropped 事件全部匹配，无未分类项。
再核对同序号之前的 ack 和 MISSED 重投递；这两份 trace 中每个目标线程只有一个
BeginFrame source。另统计视频丢帧、BeginFrame interval、同步调用及 flow，
`SyncToken::Wait` 的 X、s、f 分开计算，避免把一个调用及两端 flow 算成三次等待。

## 事件分类

| 指标 | HLG | SDR |
| --- | --- | --- |
| BeginFrameDropped 总数 | 119 | 14 |
| kNoDamage | 61 | 12 |
| kRecoverLatency | 58 | 2 |
| 上一行中，同帧此前已报 kNoDamage，随后 MISSED 重投递 | 56 | 2 |
| VideoFramesDropped 的 count 累计 | 2 | 3 |

HLG 的另 2 个 recover 事件未在捕获范围找到此前的 no-damage ack：1 个在 load
标记前，1 个在起播阶段。不能把它们直接对应为 VideoFramesDropped 的那 2 帧，
也不能据此认定是 GPU/fence 等待。

| 操作阶段（结束标记） | HLG no-damage / recover | 其中 recover 有上述重投递链 | SDR no-damage / recover |
| --- | --- | --- | --- |
| play-start | 3 / 3 | 2 | 0 / 0 |
| play-steady | 8 / 8 | 8 | 0 / 0 |
| seek-x10 | 31 / 27 | 27 | 11 / 2 |
| after-seek | 5 / 5 | 5 | 0 / 0 |
| to-end | 0 / 0 | 0 | 1 / 0 |
| replay | 7 / 7 | 7 | 0 / 0 |
| replay-steady | 7 / 7 | 7 | 0 / 0 |

上表不含 HLG load 标记前的 1 个 recover。两种稳定播放阶段均无 VideoFramesDropped。

源码依据：固定 Chromium
[`Scheduler::OnBeginFrameDerivedImpl`](https://github.com/chromium/chromium/blob/743f26418a267dd97c3c1c71d786038ae68cfc8f/cc/scheduler/scheduler.cc#L477)
在不需要新帧时发出同名 dropped 事件并报 kNoDamage；有 pending 参数被新帧替换时
也发出该事件，但报 kRecoverLatency。取消 pending 帧同样可能报 kNoDamage。
因此该事件不是统一的“合成超时”计数。

HLG 稳定阶段的一个具体样本（Compositor tid 63217、source 1）：

| trace ts（µs） | 事件 |
| --- | --- |
| 364416366148 | NORMAL BeginFrame，sequence 344578 |
| 364416366192 | 344578 的 ack 为 kNoDamage |
| 364416366486 | 停止请求 BeginFrame |
| 364416366696 | 主线程发来的 SendCommitRequestToImplThreadIfNeeded 任务 |
| 364416366788 | 重新订阅后，344578 以 MISSED 再次到达 |
| 364416374593 | 新的 NORMAL BeginFrame，sequence 344579 |
| 364416374633 | pending 的 344578 被替换，报 kRecoverLatency |
| 364416374883 | 开始处理 344579 |

这是 idle／重新订阅附近的调度事件链，不能把同一个序号的两次报告解释为丢了两帧
视频。为什么 HLG 下更常出现重新订阅，需要控制刷新节奏后继续比较，不能宣称所有
额外事件都由 HDR 或全部由刷新率引起。

## 刷新节奏与同步

| 稳定阶段 | HLG interval 中位数 / BeginFrame 调用数 | SDR interval 中位数 / 调用数 |
| --- | --- | --- |
| play-steady（约 3 秒） | 8317 µs / 332 | 16632 µs / 180 |
| replay-steady（约 3 秒） | 8315 µs / 335 | 16629 µs / 181 |

interval 是 BeginFrame 参数，不等于逐次实测显示间隔或视频帧率。
`ohos_vsync_provider.cc` 向系统申请范围 60–120 Hz、期望值 120 Hz，并周期性查询
系统返回的 period；这里没有 HLG 专用分支。仅这些样本无法确定系统为何选择不同节奏。

HLG 的两段稳定播放分别只有 5/8 个 `SyncToken::Wait` X scope，单次最长 18/25 µs；
匹配其 s→f flow 的最长延迟分别为 316/374 µs。SDR 对应为 1/0 个 X scope，首段
最长 26 µs、flow 439 µs。没有这些事件位于 renderer 的 Compositor 线程。
全程 HLG/SDR 分别是 159/81 个 X scope，各自另有相同数量的 s、f 事件。

这些 flow 反映记录到的提交／调度关系，不是全部 GPU NativeFence 的完成时间，
也不是 GPU 硬件执行计时。当前记录不支持“稳定播放的 dropped 数量来自长时间
SharedImage 同步阻塞”的归因；不能反过来宣称所有 GPU 等待已排除。

## 本轮边界及下一步

- 原 14/123 未复现；本轮视频丢帧为 HLG 起播 2 帧，SDR seek 2 帧、播完 1 帧。
  外壳另报告两种格式各 2 次起播均无丢帧，RS 进入 Unirender 前后间隔不超过 25 ms。
  这支持“切换不必然丢帧”，不能证明所有负载下切换永远不会丢帧。
- 一个根 render pass 不排除该 pass 内部的 Skia F16 saveLayer、色彩转换和 RS
  离屏处理；需要内部绘制／资源事件才能确认物理渲染目标与分配行为。
- 后续优先在系统允许的同刷新节奏下对比 SDR/PQ/HLG，并重新核验 trace 中的 interval。
  比较有效绘制、真实视频丢帧、重新订阅次数及 CPU/GPU 耗时，不能直接比较混合原因的
  BeginFrameDropped 总数。不为这次采样差异直接硬编码限制 60 Hz，避免影响滚动。
- 若要继续优化功耗，可另做内容驱动的 VSync 请求策略；若出现可见丢帧，再针对
  VideoFramesDropped 时刻追踪解码供应、合成提交和 GPU/RS 时间线。本次保留已验收
  SharedImage/EGLImage 复用与 fence 协议。
