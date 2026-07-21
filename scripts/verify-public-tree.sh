#!/usr/bin/env bash

set -euo pipefail

readonly project_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "${project_root}"

untracked_files="$(git ls-files --others --exclude-standard)"
if [[ -n "${untracked_files}" ]]; then
  echo "Stage or remove untracked publication files before verification:" >&2
  echo "${untracked_files}" >&2
  exit 1
fi

forbidden_files="$(git ls-files | \
  grep -Ei '\.(app|cer|hap|jks|key|keystore|p12|p7b|pem|pfx|so)$' || true)"
if [[ -n "${forbidden_files}" ]]; then
  echo "Forbidden files:" >&2
  echo "${forbidden_files}" >&2
  exit 1
fi

if git grep --cached -n -I -E \
  '("(storePassword|keyPassword|certpath|storeFile)"[[:space:]]*:|^[[:space:]]*-----BEGIN (RSA |EC |OPENSSH )?PRIVATE KEY-----|1467004196342472257|2850086000361765380|6918725825249001652)' \
  -- . ':(exclude)scripts/verify-public-tree.sh'; then
  echo "Possible signing material or identity found." >&2
  exit 1
fi

absolute_symlinks="$(git ls-files -s | while read -r mode object stage path; do
  if [[ "${mode}" == "120000" ]]; then
    target="$(git show ":${path}")"
    if [[ "${target}" == /* ]]; then
      echo "${path} -> ${target}"
    fi
  fi
done)"
if [[ -n "${absolute_symlinks}" ]]; then
  echo "Absolute local symlinks are forbidden:" >&2
  echo "${absolute_symlinks}" >&2
  exit 1
fi

large_files="$(git ls-tree -r -l "$(git write-tree)" | \
  awk '$4 != "-" && $4 > 99614720 {print $5}')"
if [[ -n "${large_files}" ]]; then
  echo "A file exceeds the public-tree size limit." >&2
  echo "${large_files}" >&2
  exit 1
fi

echo "Public-tree checks passed."
