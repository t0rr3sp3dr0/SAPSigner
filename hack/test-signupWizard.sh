#!/bin/bash
set -eux -o 'pipefail'

SAPSIGNER="${1}"
function sapsigner {
	local SRC="$(readlink -f -- "${BASH_SOURCE[0]}")"
	local DIR="$(dirname -- "${SRC}")"

	DYLD_LIBRARY_PATH="${DIR}/../lib" LD_LIBRARY_PATH="${DIR}/../lib" "${SAPSIGNER}" "${@:+"${@}"}"
}

SIG="$(
	:           \
	| sapsigner \
		-p  \
	| base64    \
	;
)"

:                                                                                                     \
| curl                                                                                                \
	-H 'User-Agent: iTunes/12.6.2 (Macintosh; OS X 10.9.5) AppleWebKit/537.78.2'                  \
	-H "X-Apple-ActionSignature: ${SIG}"                                                          \
	-X 'GET'                                                                                      \
	-f                                                                                            \
	-o '/dev/null'                                                                                \
	-w '%header{X-Apple-ActionSignature}\n'                                                       \
	'https://p49-buy.itunes.apple.com/WebObjects/MZFinance.woa/wa/signupWizard?guid=000000000000' \
	2> '/dev/null'                                                                                \
| grep                                                                                                \
	-E                                                                                            \
	'^([0-9A-Za-z+/]{4})*([0-9A-Za-z+/]{4}|[0-9A-Za-z+/]{3}=|[0-9A-Za-z+/]{2}==)$'                \
;
