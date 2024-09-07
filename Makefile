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

sapsigner-pfw.out: ./CommerceKit.xcframework/* ./CommerceKit.xcframework/macos-arm64_x86_64/* ./CommerceKit.xcframework/macos-arm64_x86_64/CommerceKit.framework/* ./CommerceKit.xcframework/macos-arm64_x86_64/CommerceKit.framework/Headers/* ./CommerceKit.xcframework/macos-arm64_x86_64/CommerceKit.framework/Modules/* ./Package.swift ./Sources/SAPSignerBin/* ./Sources/SAPSignerLib/* ./Sources/SAPSignerLib/include/*
	swift build -c release --arch arm64 --arch x86_64
	ln -fs ./.build/apple/Products/Release/sapsigner $@

sapsigner-alt.out: ./Sources/SAPSignerAlt/**
	$(CC) -L ./Sources/SAPSignerAlt -O2 -Wall -Wextra -Wpedantic -lcurl -lmescal -lsasl2 -o $@ ./Sources/SAPSignerAlt/*.c

sapsigner-emu.out: ./Sources/SAPSignerEmu/**
	$(CC) -I ./include -L ./lib -O2 -Wall -Wextra -Wpedantic -Wno-dollar-in-identifier-extension -lcurl -lsasl2 -lunicorn -rpath . -o $@ ./Sources/SAPSignerEmu/*.c
