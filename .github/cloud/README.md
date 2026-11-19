# 阿里云按需 Chromium 构建

2026-11-19 用户授权推送并开始首次云端联调。
本地检查已通过；实际 OIDC、RAM、实例生命周期和产物结果以联调记录为准。

## 配置

资源标识集中在 [config.json](config.json)：

- 地域 `eu-central-1`。
- 启动模板 `lt-gw8eis82pr9mv0e4sqjt`，固定版本 `3`。
- 抢占式实例显式设置 `SpotDuration=1`，创建后提供一小时保护期；超过后仍可能回收。
- 长期数据盘 `d-gw8hklmz2vbu7gozleno`，文件系统 UUID
  `7e5aa3ce-605e-432a-b833-89516c643543`。
- OIDC Audience `sts.aliyuncs.com`，角色和身份提供商 ARN 也在配置文件内。
- 当前数据盘仅用于 Chromium 157，编译并行数 32。

ARN、资源 ID、UUID 均不是凭证。SSH 私钥只能存于 GitHub Actions Secret
`ALIYUN_SSH_KEY`，不得提交到仓库。此 Secret 已由用户配置，2026-11-19 已确认仓库中存在。
RAM 角色绑定 [ram-policy.json](ram-policy.json)，用户已确认授权。
身份提供商信任策略允许本仓库分支，后续升级无需修改这层信任。
角色信任策略完整示例为 [trust-policy.json](trust-policy.json)。注意信任策略的
`Action` 是 `sts:AssumeRole`，而运行时调用的 STS API 名称是 `AssumeRoleWithOIDC`。

首次联调记录：已补齐 STS 请求的 Timestamp/SignatureNonce。运行
`44444232779` 返回 `AuthenticationFail.NoPermission`。用户核对后确认控制台的
Action 已是正确的 `sts:AssumeRole`，此前将运行失败归因于 Action 的判断过早。
通过 GitHub OIDC 设置 API 查到本仓库 `use_immutable_subject=true`，主体前缀实际为
`repo:miramira8295@300834246/chromium-hmos@1372926316`，旧的无 ID 条件无法匹配。
需按 trust-policy.json 更新 `oidc:sub`，保留分支通配符。
同时已用实际安装的官方 SDK 核对并修正 STS 凭证客户端的初始化方式。
用户更新不可变主体条件后，运行 `44445363387` 已取得 STS 凭证，
成功读取数据盘、模板和镜像，但 `RunInstances` 返回 `Forbidden.RAM`。
运行 `44446176328` 的详细诊断为 `ecs:RunInstances / ImplicitDeny /
ResourceGroupLevelIdentityBasedPolicy`。此字段不足以单独证明控制台授权范围填错，
用户确认已经按账号级别授权。

运行 `44447416534` 使用 `preflight_only=true`，对模板、模板加显式参数、
不使用模板三种请求执行 `DryRun=true`，均返回相同权限拒绝，没有创建资源。
下一步通过 `ram:DecodeDiagnosticMessage` 解码服务返回的诊断密文；
[ram-policy.json](ram-policy.json) 已增加这项只读权限，需更新控制台默认策略版本。
用户补充解码权限后，运行 `44447853593` 成功取得诊断明文：拒绝的资源实际是
`acs:ecs:eu-central-1:1349864334375917:disk/*`，操作是 `ecs:RunInstances`。
该次鉴权只提供 `acs:MFAPresent` 和 `acs:ResourceGroupId` 条件，
未提供实例的请求标签和计费条件，`MatchedPolicies=[]`。
因此旧策略把实例条件套在全部关联资源上，导致创建系统盘的子鉴权无法匹配。
修复需为关联资源单独授权；实例创建条件继续仅作用于 `instance/*`。
预检入口是现有 Incremental build 的 `preflight_only` 输入，不执行编译和实例清理。
截至本记录，所有创建请求均被拒绝，没有 CI 实例产生，正式运行的清理任务成功。

后续进展：修正关联资源授权后，预检 `44448517904` 的三种请求全部返回
`DryRunOperation`。正式运行 `44448609956` 创建实例并成功挂载数据盘，
完成源码准备后因 systemd 服务没有 HOME、Rust 初始化失败而退出。
该运行清理成功，实例已释放，保留盘未删除；失败没有发布 HAR。
启动服务改用显式 `User=root` 和 `SetLoginEnvironment=yes`，由 systemd
按用户数据库提供 HOME/LOGNAME/SHELL，避免与交互 SSH 会话的环境不一致。

运行 `44449167561` 验证登录环境修复后，命中保留盘旧 SDK 的真实编译错误：
API 22 / Native 6.0.2.130 缺少 `native_avplaybackstate.h` 和 VP9/AV1 profile 定义。
该运行同样完成失败清理。运行 `44449707131` 在实例就绪后暂时冻结构建服务，
将本机已安装的官方 SDK 26.0.0.105 的完整目标 sysroot 上传到保留盘，
保留 Linux 主机工具；目标库已核对为 OHOS ELF（非 macOS 主机库）。
原 sysroot 备份为 native/sysroot-api22-6.0.2.130-backup，当前链接指向
`/root/chromium-157/toolchain/target-sdk-26.0.0.105/sysroot`。
更新保留了 1612 个内容一致文件的时间戳，883 个新增/修改文件标记为更新；
来源、SHA256 和备份路径写在盘内 `toolchain/target-sdk-receipt.json`。
恢复服务后，之前失败的两个媒体对象已编译通过；完整编译和 HAR 发布仍待验证。

运行 `44453038887` 使用模板 3 和显式一小时保护期，实时进度上传已实测
按 550、600、650 等间隔 50 的步数写入 `build-results`。之后主编译遇到
Mojo typemap JSON 解析失败，以及 host toolchain 的生成声明缺失。
旧缓存检查只检查 Ninja 日志中部分扩展名的零字节文件，漏掉了生成头文件、
无扩展名的 `__type_mappings` 和尚未写入 Ninja 日志的中断输出。
现补充 OHOS/host `gen/` 已知格式检查：Mojo/Protobuf 空生成源码、
无法解析的 typemap JSON 和截断的 Mojo module pickle；pickle 仅分析操作码，
不反序列化执行。完成/失败诊断保留原始 native 日志，下一轮同时保留上轮日志。
此处记录的是待云端回归验证的修复，不能据此认为所有源码编译错误均已解决。

回归运行 `44455399891` 的缓存审计实际发现并移除 48 个损坏生成文件，
包括 model_broker 的 Mojo 头文件、多个 typemap 和 disk_cache_proto.pb.h/cc，
与上一轮的错误吻合。重新生成后，host toolchain 的 on_device_features、
memory_program_cache、tflite_op_resolver、optimization_guide_features、
language_detection_model 五个此前失败的 C++ 目标均已成功编译。
主编译在约 850/35740 步时没有新 FAILED；完整链接及 HAR 仍在进行。
对应 Adapter CI `44455399955` 已通过（云端生命周期/进度/缓存测试共 33 项）。

该运行在约 21549/35740 步收到用户确认的抢占回收通知，已先停止构建服务，
并对保留盘执行 sync。旧实例的回收锁阻止 CI 主动清理，首次替代请求
`44463574565` 因盘仍被占用在创建前退出，没有重复付费实例。
新建流程现可只读等待同仓库上一轮 CI 实例释放该盘（最长十分钟）；
仍拒绝占用磁盘的手动/其他仓库实例，超时也不创建或强制拆盘。

启动模板必须指定密钥对、交换机、实例规格和仅包含系统盘的镜像，
不能携带数据盘快照，也不需要绑定 ECS RAM 实例角色。
实例与长期盘需要在同一可用区；创建时显式使用数据盘的 ZoneId。

## 执行过程

沿用 `Incremental build`，157 使用 GitHub 托管调度机；155 保留原有独立 runner。
全局 workflow concurrency 锁保持原样。

1. 从 GitHub OIDC 获取临时 STS 凭证，只留在调度端，每 50 分钟按需刷新。
2. 查询模板、镜像及固定盘。盘未脱离手动实例时，在创建新实例之前失败退出。
3. 使用固定模板版本创建一台 SpotAsPriceGo 抢占式实例，不自动退回普通按量实例。
   创建请求包含本仓库、本轮 run ID/attempt 的标签和幂等 ClientToken。
4. 保存实例 ID，挂载长期盘时显式设置 `DeleteWithInstance=false`，并查询核实。
5. 通过本轮独立 known_hosts 建立 SSH，上传包含指定提交历史的 Git bundle。
   实例不接收 GitHub token、云 API 凭证或 SSH 私钥。
6. systemd 服务按 UUID 挂盘至 `/root/chromium-157`，取得与手动构建共用的
   `ci/build.lock`，从 bundle 创建独立任务仓库，保留旧的手动 repo/。
7. 校验源码版本、SDK 和适配，修复 Ninja 记录中零字节的可重建产物，
   执行现有 `ci-incremental-build.sh`，`NINJA_JOBS=32 SKIP_HAP=1`。
   原生构建脚本继续校验 HAR 内引擎 build ID 和 V8 snapshot。
8. 调度端回传日志，回收诊断、HAR 和符号文件，逐文件核对大小、SHA-256 和提交号。
   验证后沿用 `build-<commit>` prerelease，状态写入 build-results 分支。
9. 独立 `cloud-cleanup` job 使用新的 OIDC 凭证发现本轮标签的实例：
   停止服务及实例，卸载长期盘，确认没有其他数据盘，再删除实例。

任务文件保存在长期盘 `ci/cloud/<run-id>-<attempt>/`，包含日志、任务仓库、
诊断和产物。失败或抢占后再次运行可复用 out/，不自动清空源码和缓存。
任务目录暂不自动清理，应按保留周期处理已经发布/不再需要的旧任务文件。

## 超时与失败

- SSH 短暂失败重连；连续失败会报告中断，不重复启动编译或偷偷创建第二台机器。
- 本轮原生任务最多 5 小时，systemd 限制为 5 小时 5 分钟，整个构建 job 为 330 分钟。
- 取消、构建失败或取回产物失败都会进入独立清理 job。
- 控制端丢失时，创建请求中的 8 小时 AutoReleaseTime 作为实例释放的最终上限。
  长期盘必须已经查询确认 `DeleteWithInstance=false` 才开始使用。
- 清理仅操作与仓库、run ID、attempt 标签全部一致的实例；没有 `DeleteDisk` 权限。
- 磁盘删除标记异常、实例存在操作锁、无法停止/卸盘或仍有其他数据盘时，
  清理失败并保留现场，不强制删除实例。
- systemd 的 control-group 包含 Ninja 创建的独立子进程组，清理不依赖 pkill ninja。
- 准备脚本不再执行旧 154 迁移或把 out/ 移到 retired-154，
  也不在日常 CI 中重置主树/运行 gclient sync。
- 源码 revision 不匹配时要求显式 bootstrap，不允许悄悄重建另一版本的树。
- snapshot 回执增加 Git index tree 指纹，防止 gclient/reset 后旧回执错误地跳过适配。

## 首次联调

首次联调步骤：

1. 将现有 SSH 密钥配置为仓库 Actions Secret `ALIYUN_SSH_KEY`，确认与模板密钥对匹配。
2. 结束手动构建并同步/安全卸载数据盘，在控制台将盘从手动实例脱离。
   暂停进程仍持有盘，不能直接转挂；这些动作尚未执行。
3. 取消占用同一 concurrency group 的旧 self-hosted 排队任务（若存在）。
4. 推送完成的实现，触发原有工作流。首次检查 OIDC、RAM 和模板实际返回结构，
   这些云端契约尚未实测。
5. 验证成功、编译失败和取消三种路径，以及实例确实释放、固定盘保持 Available。

`package=false` 只编译，不要求 HAR；`publish_artifacts=false` 不创建 prerelease，
产物仍作为 workflow artifact 保存。HAP 签名和手机安装继续留在本机。

编译进度每完成 50 个 Ninja 步骤上传到 `build-results` 分支的
`build-status/progress.json`，阶段开始和结束也会更新。字段包含步数、总数、
百分比、目标、源码提交和运行链接；预检和主编译使用各自的计数。
GitHub 写权限只留在调度机，上传失败保留最新快照供下轮轮询重试，
不影响 ECS 上的编译。最终状态发布同时保留这份进度文件。
运行 `44449707131` 启动时尚无实时上传逻辑，本轮由本机临时旁路进程读取
SSH 日志补充上传，不重启 Ninja；后续运行由 GitHub 调度机直接完成。

## 本地检查

```sh
python3 scripts/tests/test-cloud-ci.py
python3 scripts/tests/test-157-isolation.py
python3 scripts/tests/test-155-snapshot.py
python3 scripts/tests/test-ci-engine-selection.py
shellcheck .github/cloud/remote.sh scripts/prepare-chromium-157.sh
actionlint .github/workflows/incremental-build.yml .github/workflows/adapter-ci.yml
```

生命周期测试使用内存中的 ECS 替身和临时 Git/文件目录，不访问阿里云、不创建资源。
本地测试不能替代实际 OIDC、RAM、ECS 创建和产物回收验证。
