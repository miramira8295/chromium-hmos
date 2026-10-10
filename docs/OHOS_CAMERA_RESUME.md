# OHOS 摄像头前后台恢复

2026-10-10，外壳报告 build-8ed09f21 在 Mate 70 Pro+ 上：摄像头预览时回桌面
约 2 秒，再返回，10 秒内没有新帧，MediaStreamTrack 仍为 live；不录像也能复现。
前后摄像头 720p/1080p、软件横竖屏和 20 次开关已完成短测，前台录像 5 分钟
没有冻结。约 15 fps、CPU 平均 339%、RSS 449–543 MiB 没有旧版对照，不作为
优化收益证明。Pad 仅测模拟器；物理旋转、色彩及无痕截图竞态仍待补验。

## 原因与处理

CameraKit 文档《相机启动恢复实践》说明，退后台时系统安全策略会强制断流，
回前台需要重新初始化设备、预览输出和会话。原 OHOS 桥只改变浏览器窗口可见性，
没有通知 Chromium 的 VideoCaptureManager 释放/重建设备。

新流程复用 Chromium 管理摄像头设备和客户端的原有通道：

1. 外壳原有 OnVisibilityChanged 通知进入浏览器桥，汇总应用/各窗口可见性。
   有一个窗口仍可见就保持前台；焦点变化不作为相机暂停信号。
2. UI 线程按可见性变化顺序向浏览器 IO 线程发送状态。IO 线程释放摄像头设备，
   保留控制器和客户端；屏幕/标签捕获不在此释放范围。
3. 前台恢复时重新启动原控制器的设备，重建 CameraKit 及 ConsumerSurface。
   原有采集池直接转换继续使用，不增加新的测试开关或外壳协议。
4. 后台到达的新摄像头请求暂不启动；回前台后启动。轨道已停止、控制器已删除时，
   不会因为回前台重新打开摄像头。
5. 前台返回早于上一次设备启动取消完成时，在取消回调结束后重新检查恢复请求。
   恢复逻辑同时检查后台/锁屏状态，避免晚到任务在后台重新打开相机。

标准设备启动失败仍沿 Chromium 错误通道上报。此修改不承诺后台持续录像，也
不改变相机权限策略。系统强制回收与 shell 通知的实际时序仍需真机复测。

## 外壳复测

使用默认启动配置，保留原来的 MediaStreamTrack 和 video.srcObject，返回前台
时不要重新调用 getUserMedia，否则无法验证内核是否自动恢复。

- 前/后摄像头 720p、1080p，各执行预览 → 回桌面 2 秒 → 返回，重复 20 次。
  记录每次返回到首个新视频帧的延迟及 track live/muted/ended；应恢复连续新帧，
  不能只看旧画面仍在。预览与 MediaRecorder 录制分别测试。
- 快速前后台切换；权限弹窗返回；摄像头正在启动时退后台再返回。
- 后台停止轨道或关闭摄像头标签，再返回；确认摄像头不会自行重开。
- 锁屏/解锁、前后镜头切换、连续录像。检查录制文件时间戳、声音、方向和颜色。
- Pad 多窗口：隐藏一个窗口但另一个仍可见；全部隐藏再恢复。另测采集进程模式。

关键日志：

```text
OHOS camera lifecycle: background; releasing devices
OHOS camera lifecycle: foreground; restoring devices
OHOS camera: session started ... rotation=...
OHOS camera: first frame delivered (pool conversion)
```

如果会话启动但没有首帧，继续定位原生出帧/采集路径；如果首帧交付正常但网页
仍不呈现，继续检查 renderer/VideoFrame 提交。回退旧转换路径会显示
`first frame delivered (copy fallback)`，并保留原有布局回退原因日志。

## 验证范围

补丁为 content_unittests 添加 VideoCaptureManagerTest.Ohos* 用例，覆盖：
保留客户端的前后台恢复、重复通知、后台停止后不复活、后台新请求延迟到前台，
以及恢复遇到未完成的启动取消。

这些测试需要支持 OHOS 的 Chromium 测试构建；默认 runner 构建内核与 HAR，
不执行 content_unittests。源码/补丁检查与 runner 编译结果不能替代设备验收。
