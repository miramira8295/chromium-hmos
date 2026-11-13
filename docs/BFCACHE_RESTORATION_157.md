# 157 历史导航恢复与闪白诊断

## 已确认的问题与改动

返回指令本来调用 `NavigationController::GoBack()`。网址防护原先在每次主文档提交后调用 `DisableForRenderFrameHost`，导致启用防护时所有页面都不能进入 BFCache。历史导航于是需要重新加载文档，即使资源可由 HTTP 缓存提供。

157 改为在 `ChromeContentBrowserClient::CreateCommitDeferringConditionsForNavigation` 注册恢复检查。网络导航仍由原有 throttle 检查；BFCache 恢复在 Chromium 最后一个 BFCache condition 解冻目标 renderer 前检查，安全结果到达后才继续。恢复检查保持既有 1500 ms 预算以及 unknown/超时放行语义，正常命中不会重新请求页面文档，但配置了云检查时可能请求信誉服务。

命中风险时只淘汰待恢复页面的 RFH。Chromium 同步取消该恢复、异步重新执行同一条历史导航，由原有 throttle 和风险页处理。不会把当前 C 当作缓存中的 B 淘汰，也不自行重发 POST。策略变更继续 Flush BFCache、取消 prerender；检查回调使用 weak pointer 与策略 revision，取消或关闭标签后不能继续恢复。单次绕过授权不会继承到 BFCache 恢复。

内置规则的不可变快照完成替换时也递增策略 revision 并通知观察者，清理旧检测结果与 BFCache；下载进度或临时 loading 状态不重复触发失效。

此修改只进入 157 分支。`patches/migration-155` 与历史增量补丁保持原样；不能单独将“移除全局禁用”移植到缺少恢复检查注册的旧版本。

## 本地验证

```sh
python3 scripts/tests/test-bfcache-protection.py
python3 scripts/tests/test-startup-handoff-retry.py
python3 scripts/tests/test-157-isolation.py
python3 scripts/tests/test-155-snapshot.py
```

恢复检查测试直接编译生产 condition 和 factory，使用服务/导航替身注入允许、超时、风险、取消、已排队结果、策略切换以及同步销毁，启用 ASan/UBSan。它不模拟 Chromium 的缓存实现，因此不能证明目标引擎实际命中缓存或没有闪白。原生 API、链接与 HAR 打包由 157 CI 检查，设备验收仍需单独执行。

## 回退场景与观测

测试页：`docs/test-pages/history-navigation/index.html`，可由现有 `scripts/serve-test-pages.py` 提供。A/B/C 链接分别触发跨文档导航，页面包含不同纯色背景、文档实例 ID、初始化次数、输入和滚动标记。不要在验收时启用 DevTools 的禁用缓存选项。

- A → B → C → 返回 B → 返回 A → 前进 B。`pageshow.persisted=true` 是恢复证据；B 的实例 ID/初始化次数应不变，输入与滚动位置应保留。
- 同文档 hash/History API 返回要单独观察，不能用它证明跨文档 BFCache 有效。
- 防护开启、关闭、站点例外分别验证；已知危险规则、检查超时、快速连续返回、检查途中切换规则或关闭标签应无越权恢复、崩溃或挂起。
- 在 C 更新规则将 B 标为危险，然后返回 B：缓存应被策略变更清空，显示原有拦截结果。检查途中收到云端危险结果时，B 不能先恢复执行。
- POST 历史、跨站跳转、有 iframe 的页面和不符合 BFCache 条件的网站需覆盖。未命中不一定是回归，记录原因。

本次任务不操作手机，也不声称已完成设备验收。

可显式启用 native verbose 日志：

```text
--enable-logging --vmodule=aura_shell_runtime_bridge=1,navigation_throttle=1
```

`OHOS navigation` 记录导航 ID、history/reload/same_document、提交/错误、BFCache 标志以及开始到结束的时间，不输出 URL。`OHOS BFCache protection` 记录恢复安全检查时间。历史导航提交后另外记录 `visual_state` 与 `presentation` 的回调耗时。后两项只在开启 verbose 时触发探测和一次 redraw；文档变化、隐藏或销毁使回调失效。

这些时间是提交后的观测节点，不是“首个有效内容帧”的测量，也不直接证明没有白帧。若 `bfcache=1` 仍闪白，下一步对照 compositor/surface 生命周期与帧录制；不要用固定延迟或白色遮罩推断问题已修复。

缓存未恢复的具体原因可在测试页查看 `PerformanceNavigationTiming.notRestoredReasons`，或记录 CDP `Page.backForwardCacheNotUsed`。跨源细节可能被隐藏。`notRestoredReasons=null` 不是缓存命中的证据，应结合 `pageshow.persisted`、native 命中标志和文档请求记录判断。

## 上游依据

以上生命周期结论核对自固定的 Chromium revision `7d4508cbfffd289d7015f7703bce215d3ab123bf`：

- `content/browser/renderer_host/commit_deferring_condition_runner.cc`：embedder conditions 先运行，BFCache condition 最后运行。
- `content/browser/renderer_host/navigation_request.cc`：在恢复的 response 阶段选择缓存 RFH，再运行 commit conditions。
- `content/browser/renderer_host/render_frame_host_impl.cc`：禁用缓存触发 eviction；正在恢复的导航同步销毁、随后异步重启。
- `content/browser/back_forward_cache/back_forward_cache_commit_deferring_condition.cc`：最后准备恢复并禁止进一步 eviction。

## 手机回访：恢复后的进度条

2026-11-13 在 Mate 70 Pro+、`e32ef676` 上用本地 HTTP 测试页执行两轮 A → B → C → B：两轮均 `pageshow.persisted=true`、B 的文档实例和初始化次数不变，返回期间服务器没有收到请求；CDP 未报告缓存不恢复。观测到回退约 66 / 111 ms（包括 CDP 与状态轮询开销，不是绘制耗时）。该结论只适用于受控测试页，不能代替用户网站的检查。

外壳此前把 `WebContents::IsLoading()` 直接用作顶栏进度与控件展开的依据。Chromium 157 的跨文档 BFCache 恢复本身也会进入 loading；只换成 `ShouldShowLoadingUI()` 仍不足以排除这种恢复。新增按标签保存的导航观察状态，只对已确认的 BFCache 恢复抑制加载 UI，覆盖提交到停止加载之间的最后一次更新。缓存淘汰后的正常导航、刷新和新页面仍正常显示进度；同文档是否显示 UI 则遵循 Chromium 判定。此改动不延迟导航，也不改变安全检查。

生产观察器回归测试：`python3 scripts/tests/test-history-loading-ui.py`，覆盖恢复提交、取消、缓存失效后网络加载、旧回调及连续导航。
