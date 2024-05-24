all: clean build
.PHONY: all

build:
	swift build -c release --arch arm64 --arch x86_64
.PHONY: all

clean:
	rm -Rfv ./.build ./.swiftpm
.PHONY: clean
