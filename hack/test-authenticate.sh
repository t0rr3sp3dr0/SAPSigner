#!/bin/bash
set -eux -o 'pipefail'

DIR="$(dirname -- "$(readlink -f -- "${BASH_SOURCE[0]}")")"
SIG="$(: | DYLD_LIBRARY_PATH="${DIR}/../lib" LD_LIBRARY_PATH="${DIR}/../lib" "${1}" | base64 | tr -d '\n')"

: \
| curl \
    -H 'User-Agent: MacAppStore/1.3 (Macintosh; OS X 10.9.5) AppleWebKit/537.78.2' \
    -H "X-Apple-ActionSignature: ${SIG}" \
    -X 'POST' \
    -f \
    -o '/dev/null' \
    -w '%{response_code}\n' \
    'https://p40-buy.itunes.apple.com/WebObjects/MZFinance.woa/wa/authenticate' \
    2> '/dev/null'
