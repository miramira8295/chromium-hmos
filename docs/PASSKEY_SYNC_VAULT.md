# Optional shell passkey vault (protocol 1)

The OHOS authenticator can delegate synchronized ES256 credentials to the
trusted application shell's `passkeyvault` system service. `aboutInfo` advertises
`passkeySyncApiVersion: 1`. The engine's existing HUKS credentials remain local;
there is no export or migration of their private keys.

## Boundary

This is a browser-process system service, not a JavaScript/page API. Chromium
continues to validate secure context, origin, RP ID and WebAuthn request policy.
The existing discovery excludes off-the-record profiles. The shell implementation
accepts only the ordinary `Default` profile, an explicitly enrolled vault, a
signed-in account and the trusted app signing identity. Account changes cancel
pending operations before detaching the old store.

`make`, `get`, and `list` carry `profile`, `rp`, and `ids` (lowercase hex credential
IDs). `make` and `get` also carry a unique `requestId` and base64 `clientDataHash`.
Registration adds base64 `userId`, `userName`, `displayName`, and `localExcluded`.
The native implementation checks the local exclusion list first, but the vault
must obtain user verification before exposing an exclusion result.

`list` returns metadata (`id`, `rp`, `userId`, `userName`, `displayName`). Successful
registration/assertion returns `handled: true`, `id`, `userId`, base64
`authenticatorData`, and a DER ECDSA `signature`. No private key or root is returned
to C++. Native code verifies RP hash, UP/UV/BE flags, credential ID, assertion
allow-list and response bounds before constructing Chromium responses. BE is set
for vault credentials; BS is asserted only after a successful cloud backup of
that credential. Counters are zero. `cancel` carries the matching request ID.

An explicit `handled: false` or absent service falls back to HUKS. Authentication,
corruption and transport failures never silently create a different local key.
An old shell without the service and an unenrolled new shell keep their original
behavior. Registration/assertion bridge calls are bounded to 90 seconds.

## Lumie storage and recovery

The application implements this protocol under `shell/passkeys/`. A 256-bit
random recovery key protects immutable credential events with AES-256-GCM (fresh
96-bit nonce, 128-bit tag). AAD binds protocol, account hash, vault ID and event
ID. The cloud database stores only opaque IDs, encrypted private records and
separately encrypted metadata. The metadata key is derived with domain separation
from the root; possessing it permits account listing but not credential signing.

The local root is an Asset Store secret with `AUTH_TYPE=ANY`,
`REQUIRE_PASSWORD_SET=true`, `DEVICE_UNLOCKED` and `SYNC_TYPE=NEVER`. Each use
obtains a fresh Asset Store challenge, performs system user authentication and
presents its token to Asset Store. Root buffers and imported crypto key objects
are cleared on completion. JavaScript strings and framework-managed buffers are
subject to runtime garbage collection; this design does not claim hardware-only
private-key execution. The local metadata key is device-unlocked, without a user
prompt, so encrypted indexes can refresh in the background.

Recovery codes encode 256 random bits plus a checksum, not a user-chosen password.
A new device must download and authenticate the vault header before saving any
root locally. Existing local HUKS credentials are not uploaded. Permanent,
authenticated deletion events prevent honest offline clients from resurrecting
removed credentials. An unavailable or malicious cloud can still withhold data;
this protocol does not claim a globally trusted freshness/availability service.

The first implementation uses recovery-code enrollment, not QR device approval.
It does not provide device revocation/root rotation: an already authorized device
or a copied recovery code can decrypt ciphertext it has obtained. Revocation
requires a separate key-rotation and credential re-registration design, not
merely deleting a device label.

## Validation

Lumie `scripts/tests/passkey-vault.test.mjs` executes production record, protocol,
crypto-adapter and service code with independent Node cryptography and simulated
cloud/device boundaries. It covers two-device recovery/signing, tampering,
wrong accounts/keys, metadata separation, tombstones, exclusion, cancellation and
account switching. `scripts/tests/test-passkey-store.py` continues to verify the
existing HUKS store's fault handling. These tests do not substitute for SDK/native
compilation, real Asset Store authentication or two-device cloud testing.
