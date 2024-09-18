#!/bin/bash
set -eux -o 'pipefail'

SAPSIGNER="${1}"
function sapsigner {
	local SRC="$(readlink -f -- "${BASH_SOURCE[0]}")"
	local DIR="$(dirname -- "${SRC}")"

	DYLD_LIBRARY_PATH="${DIR}/../lib" LD_LIBRARY_PATH="${DIR}/../lib" "${SAPSIGNER}" "${@:+"${@}"}"
}

DAT="$(
	cat <<- EOF
		<?xml version="1.0" encoding="UTF-8"?>
		<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
		<plist version="1.0">
		    <dict>
		        <key>appleId</key>
		        <string>***</string>
		        <key>attempt</key>
		        <string>2</string>
		        <key>guid</key>
		        <string>***</string>
		        <key>password</key>
		        <string>***</string>
		        <key>rmp</key>
		        <string>0</string>
		        <key>why</key>
		        <string>signIn</string>
		    </dict>
		</plist>
	EOF
)"

SIG="$(
	:                \
	| echo           \
		-n       \
		"${DAT}" \
	| sapsigner      \
	| base64         \
	;
)"

:                                                                                      \
| curl                                                                                 \
	-H 'User-Agent: MacAppStore/1.3 (Macintosh; OS X 10.9.5) AppleWebKit/537.78.2' \
	-H "X-Apple-ActionSignature: ${SIG}"                                           \
	-X 'POST'                                                                      \
	-d "${DAT}"                                                                    \
	-f                                                                             \
	-o '/dev/null'                                                                 \
	-w '%{response_code}\n'                                                        \
	'https://p40-buy.itunes.apple.com/WebObjects/MZFinance.woa/wa/authenticate'    \
	2> '/dev/null'                                                                 \
;
