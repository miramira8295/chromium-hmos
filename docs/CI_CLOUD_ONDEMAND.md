# 按需云构建（阿里云抢占式）设计

> 2026-11-18：本地实现已转入 [.github/cloud](../.github/cloud/README.md)，
> 用户要求开发完成后先不推送或云端验证。以该目录的代码、配置和 README 为准。
> 当前采用长期保留的数据盘，不逐轮创建/删除盘或快照。
> 下文保留首次 bootstrap 记录和早期设计；其中“一行不改”的准备脚本方案、
> 旧资源参数及 `ReleaseInstance` 示例已由当前实现替代。

## 2026-11-18 首次编译现场

用户提供的新实例已挂载 `/dev/vdb`（ext4）至 `/root/chromium-157`，32 vCPU、
约 30 GiB RAM、盘内 32 GiB swap。用户明确指定后续本轮编译使用 `NINJA_JOBS=32`。
实际系统为 Ubuntu 26.04.1；下文 Ubuntu 24.04 镜像仍是设计建议，尚未实施。
仓库位于挂载盘 `/root/chromium-157/repo`，SDK 位于
`/root/chromium-157/toolchain/harmonyos-clt/command-line-tools`。

首次接管时尚无编译进程：`args.gn` 缺失 OHOS 目标参数，默认按 Linux 生成；
快照还保留了过期的补丁应用回执，部分源码实际没有对应修改。
已备份至 `/root/chromium-157/bootstrap-backup/`，恢复仓库 OHOS ARM64 GN 配置，
恢复 `ohos_build`、`ohos_glue`、`ohos_nweb` 相对软链及 SDK 链接，
同步 `deps_code/webview`，重新应用完整 157 主树和 DEPS 适配，再同步 overlay。
GN 生成成功（42147 targets），PGO 验证通过，包含 Dock 全屏滚动容器补丁。
远端仓库原有 `ci-incremental-build.sh` 的 `arkweb/build/*` 同步改动已保留和备份。

本轮已启动：

```sh
tmux attach -t codex-j32
tail -f /root/chromium-157/bootstrap-build-j32.log
cat /root/chromium-157/bootstrap-build-j32.rc  # 完成后才生成
```

启动脚本：`/root/chromium-157/bootstrap-build-j32.sh`。
使用原有 `ci-incremental-build.sh`，`NINJA_JOBS=32 SKIP_HAP=1 SKIP_PACKAGE=1`。
当前为首次原生编译，不代表已经完成，HAR 打包和真机安装尚未执行；
GitHub CI 的按需建机/挂盘/释放流程仍未迁移。
后续快照恢复必须检查源码补丁实际存在，不能仅凭 `.git/ohos-157-snapshot` 判定健康；
运行 gclient reset/sync 后尤其需要重验，避免回执存在但补丁已丢失。

状态：设计稿，未实现。目标是把 `incremental-build.yml` 从
`self-hosted, harmonyos-chromium` 搬到按需创建的阿里云抢占式实例上，用完即释放，
而构建逻辑（`prepare-chromium-157.sh` / `ci-incremental-build.sh`）**一行不改**。

## 1. 为什么不是"每次从快照建盘"

一次性决策，先说清楚，因为后面所有步骤都依赖它。

| 形态 | 常驻成本 | 收工 | 开工 | 被 spot 回收 |
| --- | --- | --- | --- | --- |
| **M2 常驻数据盘 + 释放实例**（本设计的默认） | ¥100/月 | 1 个 API | 建实例 + 挂盘 ≈ 90 s | 盘独立于实例，安全 |
| M1 停机（StopCharging） | ¥100/月 | 1 个 API | 开机 ≈ 40 s | 重启可能因库存失败 |
| M3 每次从快照建盘 | ¥9–18/月 | 全量快照上传，数分钟 | 建盘秒级（极速可用） | 丢本次会话产物 |

M2 和 M1 的成本几乎一样（算力都停了，只剩盘钱），M2 多一次挂盘但不怕抢占实例
重启失败，所以默认 M2。M3 每次省 ¥85/月，但**每次收工都要等一次快照上传**，
而且"从快照建的新盘再打快照是全量还是增量"没有定论——要实测
（`DescribeSnapshots` 看 `Size`），所以放到第二阶段再切。

切换成本很低：M3 只是 provision 的 `AttachDisk` 换成
`RunInstances --DataDisk.1.SnapshotId`，teardown 多一步 `CreateSnapshot`。

## 2. 状态机

```
 push / dispatch
      │
      ▼
 [provision] ── DescribeInstances(tag=ci=chromium-hmos) ──┐
      │                                                   │
      │  无实例                                            │ 有实例（上次崩了/回收了）
      ▼                                                   ▼
  RunInstances(spot)                              StartInstance / 复用
      │                                                   │
      └──────────────► AttachDisk(常驻盘) ◄───────────────┘
                              │
                              ▼
                    ssh 就绪（≤5 min）
                              │
                              ▼
                    [mount + swapon + sync repo]
                              │
                              ▼
                  bash scripts/ci-incremental-build.sh
                     （detached，日志轮询流回 Actions）
                              │
                              ▼
                scp HAR + symbols → ubuntu-latest
                              │
                              ▼
              gh release upload + push build-status
                              │
                              ▼
 [teardown]  if: always()  →  ReleaseInstance（盘自动变待挂载）
```

关键点：**盘是唯一有状态的东西**，生命周期独立于实例。实例是可丢弃的，
所以抢占回收、库存不足、编排失败都不会毁掉树。

## 3. 一次性资源（手工建好，写进仓库变量）

| 资源 | 取值 | 备注 |
| --- | --- | --- |
| 地域 / 可用区 | `eu-central-1` / `eu-central-1a` | 盘只能挂同 AZ 的实例，**固定住** |
| 数据盘 | 200 GiB ESSD PL0，tag `ci=chromium-hmos`、`major=157` | `DeleteWithInstance=false`；已由 bootstrap 建好 |
| 自定义镜像 | `m-…`（Ubuntu 24.04 + git/python3/rsync/tmux + `install-build-deps.sh` + rust） | bootstrap 完成后从系统盘 `CreateImage` |
| 密钥对 | `chromium-ci`，pem 存 GitHub secret `ALIYUN_SSH_KEY` | 只用于 SSH 登录，**不是** API 凭证 |
| 安全组 | 入站只开 22，源为 GitHub Actions 出口（或临时 0.0.0.0/0） | 见 §7 风险 |
| VPC / 交换机 | 默认专有网络 + 默认交换机 | `RunInstances` 需要 `VSwitchId` |
| RAM | 子账号 AK（或 OIDC 角色），仅 `ecs:*` 所需只读+生命周期权限 | 见 §6 |
| 抢占配额 | `q_ecs_enterprise_spot_c` ≥ 32 vCPU | 控制台配额页确认 |

## 4. GitHub 侧文件布局

```
.github/workflows/incremental-build.yml   # 重写：ubuntu-latest 编排
.github/cloud/provision.sh                # 找/建实例 + 挂盘 + 等 SSH
.github/cloud/ci-remote.sh                # 在云上跑：mount / repo sync / 构建
.github/cloud/run-remote.sh               # 后台启动 + 轮询日志 + 取退出码
.github/cloud/teardown.sh                 # 释放实例（失败则保留 + 打 orphan tag）
.github/cloud/reap.sh                     # 定时清理孤儿资源（独立 workflow，每 6h）
```

把逻辑放进 `.github/cloud/*.sh` 而不是 YAML 里，是因为**同一套脚本必须能手工跑**
——bootstrap 那一台、排障那一台、正式 CI 那一台，走同一条代码路径。

## 5. 关键片段

### 5.1 provision：建实例并挂盘

```bash
# 复用上次没释放干净的实例（上一轮 teardown 失败、或 spot 回收后重建）
existing=$(aliyun ecs DescribeInstances --RegionId "$REGION" \
  --Tag.1.Key ci --Tag.1.Value chromium-hmos --Status Running \
  --query 'Instances.Instance[0].InstanceId' --output cols=InstanceId rows=1 | tail -1)

if [[ -n "$existing" ]]; then
  INSTANCE_ID=$existing
else
  INSTANCE_ID=$(aliyun ecs RunInstances --RegionId "$REGION" --ZoneId "$ZONE" \
    --ImageId "$IMAGE_ID" --InstanceType "$INSTANCE_TYPE" \
    --InstanceChargeType PostPaid --SpotStrategy SpotAsPriceGo --SpotDuration 1 \
    --SecurityGroupId "$SG_ID" --VSwitchId "$VSWITCH_ID" \
    --KeyPairName chromium-ci --InstanceName "chromium-ci-$GITHUB_RUN_ID" \
    --InternetChargeType PayByTraffic --InternetMaxBandwidthOut 100 \
    --Tag.1.Key ci --Tag.1.Value chromium-hmos \
    --Tag.2.Key run --Tag.2.Value "$GITHUB_RUN_ID" \
    --query 'InstanceIdSets.InstanceIdSet[0]' --output cols=InstanceId rows=1 | tail -1)
fi

# 盘是否已经挂着（复用时可能还在）
attached=$(aliyun ecs DescribeDisks --RegionId "$REGION" \
  --Tag.1.Key ci --Tag.1.Value chromium-hmos \
  --query 'Disks.Disk[0].Status' --output cols=Status rows=1 | tail -1)
[[ "$attached" == In_use ]] || \
  aliyun ecs AttachDisk --InstanceId "$INSTANCE_ID" --DiskId "$DISK_ID" \
    --DeleteWithInstance false

# 等 SSH（实例刚建时 sshd 还没起来）
for _ in $(seq 1 60); do $SSH true 2>/dev/null && break; sleep 5; done
```

### 5.2 远端：复用现有脚本，不复制构建逻辑

```bash
# .github/cloud/ci-remote.sh（在云上执行）
set -euo pipefail
mountpoint -q /root/chromium-157 || mount /dev/vdb /root/chromium-157   # 带重试
[[ -d /root/chromium-157/src/out/ohos_arm64 ]] || { echo 'cold tree'; exit 3; }
swapon /root/chromium-157/.swap 2>/dev/null || true

git -C /root/chromium-hmos fetch --depth=1 origin "$SHA"
git -C /root/chromium-hmos checkout -f "$SHA"

export GITHUB_ACTIONS=true GITHUB_REF_NAME=hmos-157-adapter
export CHROMIUM_SRC=/root/chromium-157/src CHROMIUM_MAJOR=157
export CHROMIUM_VERSION=$VERSION CHROMIUM_REVISION=$REVISION
export NINJA_JOBS=12 SKIP_HAP=1

bash /root/chromium-hmos/scripts/prepare-chromium-157.sh   # sentinel 在，等于增量同步
bash /root/chromium-hmos/scripts/ci-incremental-build.sh
```

`prepare-chromium-157.sh` 依赖的三个 sentinel（`.retired-154-saved`、
`.deps-<rev>`、`.hooks-<rev>`）随盘携带，所以云上这台和现在那台走的是**同一段代码**。

### 5.3 轮询日志（SSH 掉线不留孤儿）

```bash
$SSH "setsid bash -c 'bash /root/ci-remote.sh >/root/ci.log 2>&1; echo \$? >/root/ci.rc' </dev/null &"

lines=0
while :; do
  out=$($SSH "tail -n +$((lines+1)) /root/ci.log; test -f /root/ci.rc && cat /root/ci.rc" 2>/dev/null || true)
  # 打印新增日志；最后一行是 rc 时结束
  ...
  sleep 15
done
```

构建跑在 `setsid` 里，**编排端进程死了构建还在跑**，下次 `provision` 会复用同一台机器。

### 5.4 teardown：释放，失败则保留现场

```bash
# .github/cloud/teardown.sh —— if: always()
rc=0
$SSH "pkill -f ci-remote.sh || true; pkill -f 'ninja' || true; sync" || rc=$?

# 先取回产物，再释放（产物取不到就不要销毁机器）
bash .github/cloud/fetch-artifacts.sh || { tag_orphan; exit 1; }

aliyun ecs ReleaseInstance --InstanceId "$INSTANCE_ID" --Force true || { tag_orphan; exit 1; }
```

盘设了 `DeleteWithInstance=false`，实例释放后自动变"待挂载"，下一轮 `AttachDisk` 接上。

### 5.5 产物走编排端，不走云上

HAR 147 MB + symbols 138 MB 由 `scp` 拉回 `ubuntu-latest`，再 `gh release upload`。
好处：出网流量不进 CDT 配额、发布逻辑留在 Actions 里可控、云上机器完全不需要
GitHub 凭证（仓库是公开的）。

## 6. 认证

两条路，先跑通再收紧：

- **AK（第一步）**：RAM 子账号，只授 `ecs:DescribeInstances/DescribeDisks/RunInstances/
  AttachDisk/ReleaseInstance/StartInstance`；AK 放 `secrets.ALIYUN_ACCESS_KEY_ID/SECRET`。
- **OIDC（收紧）**：RAM 身份提供商指向 `token.actions.githubusercontent.com`，
  trust policy 限定 `repo:miramira8295/chromium-hmos:ref:refs/heads/hmos-157-adapter`，
  job 里 `curl $ACTIONS_ID_TOKEN_REQUEST_URL&audience=aliyun` 换 STS 临时凭证。
  没有长期密钥。

pem 只解决 SSH 登录（`RunInstances --KeyPairName`），跟 API 认证无关。

## 7. 失败矩阵

| 失败点 | 现象 | 处理 |
| --- | --- | --- |
| 抢占无库存 | `OperationDenied.NoStock` | 同 AZ 内换规格（u1 → c7/g7）重试；再不行退按量 |
| 盘挂不上 | `mount` 失败 | provision 先 `mountpoint` 校验，fail fast，**不释放**，打 orphan |
| 编译失败 | rc≠0 | 仍走 teardown 释放（盘保留，**下次从失败点续编**） |
| 编排端被杀 | 实例还在跑 | 实例内 `shutdown -h +480` 硬上限 + reaper |
| 被 spot 回收 | SSH 断、实例消失 | 重跑 workflow；盘还在，续编 |
| SSH 暴露面 | 22 对公网开 | 安全组限 GitHub Actions 出口；`PermitRootLogin prohibit-password`；机器寿命分钟级 |

## 8. 成本（法兰克福，spot ¥0.87/h）

| 项 | 月成本 |
| --- | --- |
| 数据盘 200 GiB PL0 | ~¥100 |
| 自定义镜像（~40 GiB 快照） | ~¥5 |
| 算力（20 h/月） | ~¥17 |
| 出网（<200 GB CDT 免费额度） | ¥0 |
| **合计** | **≈ ¥125/月** |

单次构建 3 分钟 ≈ ¥0.04；全量 5 小时 ≈ ¥4.4。

## 9. 待定

1. 手动停止抢占式实例是否支持 `StopCharging`（决定 §1 里 M1 能否用）。
2. 从快照建的新盘再打快照是否全量（决定 M3 何时切换）。
3. 安全组能否收窄到 GitHub Actions 出口段（`api.github.com/meta` 的 `actions`）。
4. 155 树是否一并迁移（目前 155 只有 ci 提交，建议不迁）。
5. `inspect-runtime.yml` 复用同一套 provision/teardown，只是中间换成快照脚本。
