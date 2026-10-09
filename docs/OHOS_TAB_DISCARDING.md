# OHOS 标签页淘汰

HarmonyOS 内存不足时会直接杀掉浏览器进程；手机单进程，所有标签页一起丢。
系统只把内存等级告诉应用（`onMemoryLevel`），Chromium 自己收不到。本机制在
引擎内完成，外壳无需接入。

## 策略

`OhosTabDiscardingPolicy`（`chrome/browser/performance_manager/policies/`）
挂在 Chromium 的 Performance Manager 上，复用其丢弃资格判断和丢弃机制。

| 触发 | 手机（单进程） | 平板 / PC（多进程） |
| --- | --- | --- |
| 同时保持加载的标签页（含当前） | 5 | 10 |
| 后台多久未看即丢弃 | 30 分钟 | 60 分钟 |
| 恢复上次会话时后台预加载 | 0 个 | 3 个 |
| 系统内存 LOW（1）/ BACKGROUND_LOW（5） | 内存压力 MODERATE，丢弃 1 个最久未看的 | 同左 |
| 系统内存 CRITICAL（2）/ BACKGROUND_CRITICAL（6） | 内存压力 CRITICAL，丢弃所有允许丢弃的后台标签 | 同左 |
| 系统内存 MODERATE（0） | 只发内存压力 MODERATE（页面清缓存、GC），不丢弃 | 同左 |

总是先丢最久没看的。以下标签不丢弃（Chromium 规则）：当前标签、可见的、正在
或 1 分钟内发过声、画中画、录音录像录屏、连着蓝牙或 USB、填过表单或编辑过内容、
PDF、开着开发者工具；按数量或时间淘汰时，另外保护有通知权限、后台在改标题或
图标的标签。所以加载数可能暂时超过上限。

标签切换后等 5 秒再检查，来回切换不会立刻触发丢弃；每分钟检查一次超时。
同一内存事件 10 秒内只丢弃一轮；转给 Chromium 的内存压力 10 秒后撤回，因为
系统不通知内存恢复。

## 丢弃之后

就地丢弃（`kWebContentsDiscard`，与 Android 相同）：WebContents 保留，标签
`id`、标题、图标、前进后退记录都不变，渲染内容释放。切回该标签时自动重新加载，
滚动位置一般会恢复；未提交的表单内容、页面里的 JS 状态会丢失。

外壳状态快照里每个标签多了 `discarded`（未加载）。外壳可以把它画成灰色，或在
切换时显示加载中；不处理也能正常工作。

## 内存等级来源

引擎 HAR 的 `MemoryLevelService` 在应用上下文上注册 `environment` 回调，
把 `onMemoryLevel` 经系统服务通道转给 C++（事件 `memorylevel.level`）。不需要
外壳的 AbilityStage 转发。

## 验证

日志过滤 `OHOS tab discard` 与 hilog 标签 `MemoryLevel`：

```text
OHOS tab discard: keeping 5 tabs loaded, hidden ones for 30 min
OHOS tab discard: 6 loaded, limit 5, 4 discardable
OHOS tab discard: 1 tab(s) over the loaded tab limit, discarded
OHOS tab discard: system memory level 2
OHOS tab discard: 3 tab(s) memory critical, discarded
```

1. 手机依次打开 7 个普通网页，停在最后一个。5 秒后应丢弃最早的 2 个；切回它们
   时重新加载，标题和后退记录正常。
2. 在某个标签播放音频或填写表单后切走，它不应被丢弃。
3. 模拟内存等级：`hdc shell aa send-memory-level -p <pid> -l 2`（1 为 LOW）。
   CRITICAL 应丢弃所有允许丢弃的后台标签，当前标签不受影响。
4. 杀掉应用后恢复上次会话：手机只加载当前标签，其余标签 `discarded` 为 true，
   点开才加载。
5. `chrome://discards` 可以查看每个标签能否丢弃以及原因，也能手动丢弃。

单进程模式下丢弃不会结束渲染进程（Chromium 在单进程下从不关它），释放的是该
页面在进程内的内存。实际节省多少需真机测量。
