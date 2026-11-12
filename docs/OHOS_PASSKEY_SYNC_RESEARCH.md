# 通行密钥跨设备同步：Chromium 157 研究与集成方案

研究日期：2026-11-12。目标分支：`hmos-157-adapter`；检查基线：
`38e47436`，Chromium `157.0.8103.77`，上游提交
`7d4508cbfffd289d7015f7703bce215d3ab123bf`。

本轮完成源码、平台文档和标准研究，未实现同步后端，未操作手机或运行设备测试。
用户要求优先集成到 157；155 不作为首轮落地目标。第一阶段范围建议为同一用户的
两台 HarmonyOS 设备中的 Lumie，跨 Apple/Google 凭据生态另行评估。

## 结论和建议

技术上可做，但不是打开 Chromium Sync 开关或同步现有 JSON 文件。
建议先用一个有明确退出条件的验证阶段确认系统凭据提供方：它可以减少我们自行
实现私钥托管、恢复和同步的工作，但目前公开证据不足以证明能满足真正的 Passkey Sync。
若系统路径无法满足权限、任意网站 origin 和跨设备独立登录三项条件，转入独立的
Lumie 加密凭据库方案。不能把扫码登录作为同步完成的替代验收。

| 能力 | 判定方式 | 当前证据 |
| --- | --- | --- |
| 本机通行密钥 | 在创建凭据的设备上完成签名 | 当前 HUKS 后端已有实现，157 已纳入编译；本轮未复测 |
| 跨设备扫码认证（CDA / hybrid） | 另一台设备借助原设备完成认证，原设备仍参与 | 鸿蒙 FIDO2 文档明确提供此能力；当前自建 HUKS 后端不因此自动成为系统扫码认证器 |
| 通行密钥同步 | 同步后原设备关机，目标设备仍能用同一 credential ID 对应私钥认证 | 当前后端没有实现；系统 FIDO2 是否支持，仍须确认 |
| 凭据跨提供方迁移 | 从一种凭据管理器迁入另一种 | FIDO Credential Exchange 是可研究的后续方向，不等于持续同步，也不等于能导出现有 HUKS 密钥 |

## 157 代码现状

| 位置 | 已核对事实 | 集成含义 |
| --- | --- | --- |
| `overlay/device/fido/ohos/huks_signing_key.cc` | P-256 密钥在 HUKS 内生成；仅导出公钥；签名以会话 challenge 绑定系统 AuthToken | 现有凭据是设备绑定凭据，不能复制到另一台设备使用 |
| `overlay/device/fido/ohos/credential_store.{h,cc}` | Profile 文件仅保存 credential ID、RP ID、用户信息和创建时间 | 同步此文件不会同步私钥；新同步模型不能直接沿用当前同 RP/用户替换后销毁旧密钥的行为 |
| `overlay/device/fido/ohos/authenticator.cc` | `MakeAuthenticatorData()` 固定 `BE=false, BS=false`，签名计数为 0 | 不得把已有凭据改成 `BE=true`；可同步凭据必须从新注册开始 |
| `patches/migration-157/chromium.patch` | 在 `AuthenticatorCommonImpl` 和 `FidoDiscoveryFactory` 接入 OHOS 后端；无痕不注册本机平台认证器 | 后续后端选择、能力查询和生命周期处理从这些位置接入 |
| `config/args.plan_kirin_pc.gn` | `enable_arkweb = false` | ArkWeb 中保留的系统 FIDO2 实现不是当前运行路径 |
| `docs/SHELL_CONTRACT.md` 的密码云同步契约 | `getPasswordsForSync` / `applyPasswords` 明确排除通行密钥，含普通密码明文的运行时传输 | 不能在这个桥接中追加私钥字段来实现同步 |
| `config/native-checks-157.txt` | 已列入 OHOS authenticator、credential store、HUKS、user auth 等对象 | 新增原生实现时应扩充 157 preflight 目标，最终仍需全量链接和 HAR 验证 |

WebAuthn 的备份资格 BE 在注册时确定，此后不得改变；BS 表示当前备份状态，可以变化。
因此已有本机凭据的迁移方式是：先使用旧凭据登录网站，再由网站发起一次新的可同步
凭据注册。用户确认新凭据可用后，才考虑在网站和本地分别移除旧凭据。[S1]

## 系统 FIDO2 路径：优先验证，但尚不能认定为同步方案

Online Authentication Kit 从 HarmonyOS 6.0.0 / API 20 提供通行密钥服务。
文档列出注册、本机认证和跨设备扫码认证；C 接口为
`libfido2_ndk.z.so` 中的 `HMS_FIDO2_getClientCapability`、
`HMS_FIDO2_getPlatformAuthenticator`、`HMS_FIDO2_register` 和
`HMS_FIDO2_authenticate`。注册/认证要求在非 UI 线程执行。[S2][S3]

**接入条件：** C API 需要受限权限 `ohos.permission.ACCESS_FIDO2_ONLINEAUTH`。
开发准备文档还要求应用与网址域名关联。因此必须确认第三方浏览器能否在获授权后
代表任意经过 Chromium 验证的网站 origin 发起操作，不能假设传入 `origin` 就获得权限。
当前 engine 的权限声明未包含该项。申请主体、应用签名和商业发行包需由下游确认。[S4]

ArkTS API 没有与 C API 相同的任意 origin 参数；它的应用关联域名场景不能未经验证
直接替代浏览器路径，也不应通过伪造域名关联绕过 C API 的接入要求。

官方密码保险箱帮助页分别介绍账号密码的多设备同步和通行密钥的扫码登录。
这不足以证明第三方应用创建的通行密钥会同步，也不能据此断言所有系统版本均不支持；
需要平台说明及后续双设备证据。[S5]

### 仓库已有参考代码的复用边界

`overlay/arkweb/chromium_ext/device/fido/ohos/` 已有动态装载、参数转换、认证器与测试代码，
适合复用结构和测试用例，但不宜整体直接启用：

- `ohos_webauthn_api.cpp` 在库加载成功后就设置 available，必需符号缺失仅警告；
  157 实现应检查完整函数集及实际能力，并区分无权限、库缺失与设备不支持。
- 其 UVPAA 实现将任意一个为 true 的 capability 当作可用，需要改成检查对应能力。
- 其注册/认证会输出 options 和 credential 内容；新实现仅记录错误类别和耗时。
- 使用 `request.extra->common.origin` 等 ArkWeb 扩展，迁移时必须从 157 的受信任
  browser 请求上下文传递数据，不能从 RP ID 反推 origin。
- `Cancel()` 只设置等待取消标志，未展示取消系统提示的原生调用。必须验证页面关闭、
  导航、超时和并发请求下的提示生命周期，过期结果不得写回新页面。
- 须核对实际 SDK ABI、内存释放函数、错误映射、clientDataJSON 与跨源字段；
  不能关闭 origin/RP ID 校验来适应旧代码。

### 系统路径的三个通过条件

1. 商业应用身份可获得所需权限，且第三方浏览器的任意合法网站 origin 场景获支持。
2. A 创建的凭据在 B 上可用，网站服务端确认 credential ID 相同且签名可用，A 全程关机；
   B 的认证不需要扫码或重新注册。记录系统版本、提供方、账号、BE/BS 和设置条件。
3. 已确认密钥恢复、删除、账号切换和访问验证语义，能够与 Lumie 的 Profile 行为一致。
   系统账户级存储未必提供浏览器 Profile 级隔离，需要明确产品行为。

三个条件通过后，157 首选接入系统提供方；仅通过本地/扫码认证时，应作为单独能力交付，
Passkey Sync 仍保留未完成状态。本轮按用户要求不执行这些设备操作。

## Asset Store 能做什么

已通过 `devecocli docs` 核对 `@ohos.security.asset` 和同步开发指南：

- `TRUSTED_DEVICE` 支持可信设备克隆等备份恢复场景，需接入应用备份恢复。
- 当前中文 API 文档将 `THIS_DEVICE`、`TRUSTED_ACCOUNT` 同步类型标为预埋、暂不支持。
  搜索摘要可能只展示枚举说明，不能据此承诺账号云同步。
- `querySyncResult()` 是结果查询，不是实时云同步触发接口。
- `WrapType.TRUSTED_ACCOUNT` 枚举的存在不足以证明普通应用有完整、可调用的跨设备
  密钥封装协议；本轮读取的公共 ArkTS API 没有列出配套导入导出方法。

Asset Store 可作为本地敏感材料保护候选，不能据此省略云端密钥分发、恢复和冲突设计。
其授权查询与 HUKS 硬件内签名的安全边界不同：查询成功后明文可能进入应用内存。
若采用该路径，需要单独评估手机单进程模式下网页漏洞对密钥材料的风险。[S6][S7]

## Chromium 157 上游可复用能力

已直接读取固定上游提交中的以下文件，避免以 main 的行为代替 157：

- `chrome/browser/webauthn/passkey_model_factory.cc` 创建 Profile 对应的 `PasskeySyncBridge`。
- `components/webauthn/core/browser/passkey_sync_bridge.h` 实现 `WEBAUTHN_CREDENTIAL`
  数据类型，包含创建、更新和同步接口。
- `components/sync/protocol/webauthn_credential_specifics.proto` 包含凭据标识、RP/user、
  加密私钥、密钥版本及新旧凭据遮蔽关系；可参考其替换、冲突和恢复语义。
- `chrome/browser/webauthn/enclave_manager.cc` 依赖 Gaia 身份、OAuth、Trusted Vault
  和恢复服务；Google Password Manager 的云认证器不是一个独立的本地同步库。[S8]

可复用 WebAuthn 请求验证、认证器发现、凭据选择模型以及经过评估的数据结构。
不将华为账号冒充 Gaia 身份，不假设切换 Sync 服务地址即可获得 GPM 能力。
Google / iCloud 已存凭据也不会因为增加 OHOS 后端而自动进入 Lumie。

## 独立 Lumie 加密凭据库：系统路径不满足时的方案

这是设计候选，尚未实现；需要在进入正式开发前完成具体协议和密钥生命周期评审。

### 凭据与保护模型

- 增加独立的 `synced` 提供方，与原有 `device-bound` HUKS 后端并存；旧凭据继续使用
  旧签名路径。新凭据从创建时明确 BE，BS 仅在具有真实可恢复备份后更新。
- 同步材料需要包含可恢复的私钥、credential ID、RP ID、user handle 及已支持扩展的
  必需秘密。先限定 ES256 和明确支持的 WebAuthn 功能，不虚报 PRF/largeBlob 等能力。
- 本地凭据密文由受系统身份验证保护的密钥解封。可评估导入 HUKS 后执行签名，或在
  受限生命周期中软件签名；两者均需保留可同步的加密副本，不能称为原有的私钥永不出设备。
- 外壳只传输版本化密文和状态；明文私钥、账户解密密钥不进入通用 JSON 桥、日志、
  调试导出或网页进程。当前手机单进程边界是必须解决或明确接受的集成风险。

### 同步与设备加入

建议复用账号身份和云端传输设施，但新建凭据密文协议，不复用普通密码的明文桥接。
账号登录只证明云端身份，不能单独赋予解密能力。

- 随机账户密钥与设备授权分离；新设备需经既有可信设备批准，或以独立高熵恢复材料加入。
  扫码配对在这里用于授权新设备，不应混同每次登录依赖旧设备的 CDA。
- 使用成熟库的 AEAD，加密内容和认证附加数据绑定账户域、schema、记录 ID、版本等；
  nonce 不复用，密文修改或跨账户重放应被拒绝。不能用账户 ID 或普通短 PIN 直接派生密钥。
- 同步实体用随机标识；敏感 RP/user 元数据也需保护。删除使用 tombstone，设备加入、
  密钥轮换和批量应用需要事务或可恢复日志；不能只靠客户端时间戳解决回滚和删除复活。
- 同 RP/user 并发注册须保留必要的旧凭据及冲突关系，避免网站未收到新公钥就失去旧凭据。
- 恢复不应仅依赖存放在这个同一凭据库中的账号通行密钥，否则会形成循环依赖。

### 撤销的真实边界

撤销设备可停止它获取后续密文和新密钥，密钥轮换可以保护后续更新；
**无法收回设备已经解密或复制的既有 RP 私钥**。若怀疑设备失陷，需要在相应网站
移除旧凭据并注册新凭据。远程删库、退出账号、删除本地记录均不等于网站端撤销。
离线设备也无法被保证即时清除。这一限制必须体现在恢复与撤销产品文案和验收中。

## 157 优先集成顺序

| 阶段 | 交付与接入位置 | 通过条件 |
| --- | --- | --- |
| 0：研究（本轮） | 本文、路线图、现有同步文档入口 | 明确旧凭据边界、系统权限、同步证据缺口；已完成静态研究 |
| 1：提供方可行性验证 | 先核实 FIDO2 受限权限/浏览器接入；后续经用户允许再做双设备实验 | 系统路径三个条件有结果；失败时选独立加密凭据库，避免无限等待 |
| 2：157 原生接入 | `overlay/device/fido/ohos/` 新提供方；`AuthenticatorCommonImpl` / discovery；必要时 browser 层 Profile 服务 | 默认关闭的实验开关；现有凭据可用；完整符号、权限和能力检测；取消/失败不静默降级成另一种凭据 |
| 3：同步或系统状态接入 | 系统托管时读真实能力；自有路径新增密文同步契约、恢复/设备管理，分别修改 engine 与下游 Lumie | 不通过普通密码授权导出私钥；账号/Profile 隔离、冲突、删除、恢复测试通过 |
| 4：构建与发布验证 | 更新 `config/native-checks-157.txt`，157 patch/manifest 和 CI；下游签名集成 | 原生测试、全量链接、HAR 打包通过；随后在明确授权下做设备验收，才启用正式功能 |

仅研究阶段不修改运行时代码、签名权限或构建开关。尚无依据给出“几个补丁即可完成”
或承诺排期；主要工作量取决于系统提供方是否真实支持同步，以及是否需要自建恢复体系。

## 验收矩阵

| 场景 | 必须验证的结果 |
| --- | --- |
| A 注册、B 同步后登录，A 关机 | RP 服务端校验签名成功；同一 credential ID；无扫码、无重新注册 |
| 已有 HUKS 凭据 | 继续可用、BE/BS 不变；B 不展示无私钥的复制记录 |
| 备份尚未完成 / 下载失败 | 状态准确，不宣称已同步；本地成功与备份失败分开报告 |
| 用户验证取消、页面导航、超时、多标签并发 | 不签名、不泄漏密钥；过期回调不能作用于新请求；无悬挂系统提示 |
| RP/origin、跨源 iframe、无痕、账号切换 | 保持 Chromium WebAuthn 校验和已定义的 Profile 策略；不跨账户取凭据 |
| 并发创建/改名/删除、离线重连、旧备份重放 | 冲突可解释、删除不复活；失败不破坏原有可用凭据 |
| 锁屏清除、卸载重装、全部设备丢失 | 按设计恢复或明确无法恢复；账号登录不能绕过解密授权 |
| 设备撤销与密钥轮换 | 被撤销设备不能拿到后续材料；明确既有已复制私钥仍需 RP 端撤销 |
| 崩溃、磁盘写失败、服务端故障 | 原子保存/恢复，无明文落盘和日志，内核与云端状态可重试收敛 |

静态阶段可准备转换/错误映射、持久化故障注入、冲突与加密协议测试。
`scripts/tests/test-passkey-store.py` 仅覆盖当前存储的部分 I/O 边界，不能作为同步、
系统权限、硬件签名或跨设备验收的证据。设备测试留待后续用户授权。

## 来源与证据等级

- [S1 WebAuthn Level 3：Credential Backup State](https://www.w3.org/TR/webauthn-3/#sctn-credential-backup)。规范约束。
- [S2 鸿蒙通行密钥概述](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/onlineauthentication-passkey-intro)。使用 `devecocli docs read` 读取对应指南。
- [S3 鸿蒙 FIDO2 C API](https://developer.huawei.com/consumer/cn/doc/harmonyos-references/passkey)。本轮核对 API 20 起始版本、非 UI 线程和权限声明。
- [S4 Online Authentication Kit 开发准备](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/onlineauthentication-passwordless-auth-preparation)。本轮核对受限权限和域名关联。
- [S5 华为密码保险箱帮助（HarmonyOS 6.0 / 6.1）](https://consumer.huawei.com/cn/support/content/zh-cn16090774/)。产品说明，不能代替第三方 API 授权与同步验证。
- [S6 Asset Store API](https://developer.huawei.com/consumer/cn/doc/harmonyos-references/js-apis-asset)；[S7 同步/备份恢复指南](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/asset-js-sync)。以本轮 `devecocli docs` 全文中的限制为依据，后续随 SDK 更新重新核实。
- [S8 Chromium 157 PasskeySyncBridge](https://chromium.googlesource.com/chromium/src/+/7d4508cbfffd289d7015f7703bce215d3ab123bf/components/webauthn/core/browser/passkey_sync_bridge.h)、[凭据 proto](https://chromium.googlesource.com/chromium/src/+/7d4508cbfffd289d7015f7703bce215d3ab123bf/components/sync/protocol/webauthn_credential_specifics.proto)、[EnclaveManager](https://chromium.googlesource.com/chromium/src/+/7d4508cbfffd289d7015f7703bce215d3ab123bf/chrome/browser/webauthn/enclave_manager.cc)。通过 Chromium GitHub 镜像读取固定提交的原文。
- [FIDO Passkeys](https://fidoalliance.org/passkeys/)；[Credential Exchange](https://fidoalliance.org/specifications-credential-exchange-specifications/)。用于区分跨设备认证、同步和提供方迁移。

仓库源码证据为上述检查基线；平台文档和上游源码阅读不构成实际运行证据。
