all: clean build
.PHONY: all

build:
	swift build -c release --arch arm64 --arch x86_64
.PHONY: all

clean:
	rm -Rfv ./.build ./.swiftpm ./a.out
.PHONY: clean

a.out: ./Sources/SAPSignerAlt/*
	$(CC) -L ./Sources/SAPSignerAlt -O2 -Wall -Wextra -Wpedantic -lcurl -lmescal -lsasl2 -o $@ ./Sources/SAPSignerAlt/*.c
