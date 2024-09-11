#!/bin/bash
set -ex

DIR="$(dirname -- "$(readlink -f -- "${BASH_SOURCE[0]}")")"

DAT='<?xml version="1.0" encoding="UTF-8"?><!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd"><plist version="1.0"><dict></dict></plist>'
SIG="$(echo -n "${DAT}" | DYLD_LIBRARY_PATH="${DIR}/../lib" LD_LIBRARY_PATH="${DIR}/../lib" "${1}" | base64 | tr -d '\n')"

curl \
    -H 'User-Agent: MacAppStore/1.3 (Macintosh; OS X 10.9.5) AppleWebKit/537.78.2' \
    -H "X-Apple-ActionSignature: ${SIG}" \
    -X 'POST' \
    -d "${DAT}" \
    -f \
    -i \
    -o '/dev/null' \
    -w '%{response_code}\n' \
    'https://buy.itunes.apple.com/WebObjects/MZFinance.woa/wa/authenticate' \
    2> '/dev/null'
