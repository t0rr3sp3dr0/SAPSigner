all: clean build
.PHONY: all

build:
	swift build -c release --arch arm64 --arch x86_64
.PHONY: all

clean:
	rm -Rfv ./.build ./.swiftpm ./a.out
.PHONY: clean

a.out: ./Sources/SAPSignerAlt/*
	$(CC) -lcurl -lsasl2 -L ./Sources/SAPSignerAlt -lmescal -o $@ ./Sources/SAPSignerAlt/main.c
