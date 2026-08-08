# HarmonyOS profile and sync architecture

NaviLoom maps each verified account identity to an isolated Chromium user data
directory. The legacy local profile remains at `chromium-profile`; verified
account profiles use `chromium-profiles/<stable-id>`.

The first-run ArkUI flow supports a fully local profile today. Account Kit is
used only to obtain a short-lived authorization code. The code and ID token are
never persisted. A production account broker must exchange the code, validate
the response, and return a stable UnionID/OpenID-derived profile identifier.

Nearby browser-state synchronization should use ArkData distributed storage or
an application-level encrypted transport. Service Collaboration Kit can power
appropriate cross-device collaboration experiences, but it is not treated as
a generic bookmark/password database. Cloud synchronization should use a
developer-owned Cloud Foundation Kit backend with explicit conflict handling.

Passwords are excluded until the implementation has all of these properties:

- encryption keys are protected by Asset Store/HUKS;
- records are end-to-end encrypted before nearby or cloud transport;
- the server cannot read plaintext credentials;
- deletion, sign-out, key rotation, and device revocation are tested.

Bookmarks, history, extensions, and themes also need schema/version conflict
tests before their switches may be shown as available. The current onboarding
labels unavailable services honestly instead of storing transient credentials
or pretending synchronization succeeded.
