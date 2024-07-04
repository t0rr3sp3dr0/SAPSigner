all: clean build
.PHONY: all

build: sapsigner-pfw.out
.PHONY: build

clean:
	rm -Rfv ./*.out ./.build ./.swiftpm ./Package.resolved ./include ./lib
.PHONY: clean

docker:
	docker build -t t0rr3sp3dr0/sapsigner .
.PHONY: docker

UNAME_MACHINE ?= $(shell uname -m)
UNAME_SYSNAME ?= $(shell uname -s)
ifeq ($(UNAME_SYSNAME) $(UNAME_MACHINE),Linux x86_64)
	UNICORN_BLOB := sha256:f45a8a230a4a63c46fc1d9a63e4d3a8ea33e6448051200bb202c23081efc96f2
else ifeq ($(UNAME_SYSNAME) $(UNAME_MACHINE),Darwin x86_64)
	UNICORN_BLOB := sha256:e092a3f6f7fbaa3483b3fa2b892da569adb0e3773aed3135aafe3eb9de132210
else ifeq ($(UNAME_SYSNAME) $(UNAME_MACHINE),Darwin arm64)
	UNICORN_BLOB := sha256:19357aa9fc753df6791bf5a1764dbb2fdfeed8cdcc3a6b5c8174a052558cd8e2
endif

include/unicorn/unicorn.h lib/libunicorn.a:
	[ -z '$(UNICORN_BLOB)' ] || curl --compressed -Lfv -H 'Accept: application/vnd.oci.image.index.v1+json' -H 'Authorization: Bearer QQ==' 'https://ghcr.io/v2/homebrew/core/unicorn/blobs/$(UNICORN_BLOB)' | tar --strip-components 2 -vx ./unicorn/2.0.1.post1/{include,lib}

sapsigner-pfw.out: ./CommerceKit.xcframework/* ./CommerceKit.xcframework/macos-arm64_x86_64/* ./CommerceKit.xcframework/macos-arm64_x86_64/CommerceKit.framework/* ./CommerceKit.xcframework/macos-arm64_x86_64/CommerceKit.framework/Headers/* ./CommerceKit.xcframework/macos-arm64_x86_64/CommerceKit.framework/Modules/* ./Package.swift ./Sources/SAPSignerBin/* ./Sources/SAPSignerLib/* ./Sources/SAPSignerLib/include/*
	swift build -c release --arch arm64 --arch x86_64
	ln -fs ./.build/apple/Products/Release/sapsigner $@

sapsigner-alt.out: ./Sources/SAPSignerAlt/*
	$(CC) -L ./Sources/SAPSignerAlt -O2 -Wall -Wextra -Wpedantic -lcurl -lmescal -lsasl2 -o $@ ./Sources/SAPSignerAlt/*.c

sapsigner-emu.out: ./Sources/SAPSignerEmu/* ./include/unicorn/unicorn.h ./lib/libunicorn.a
	$(CC) -I ./include -L ./lib -O2 -Wall -Wextra -Wpedantic -lcurl -lsasl2 -lunicorn -rpath . -o $@ ./Sources/SAPSignerEmu/*.c
