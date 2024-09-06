all: clean build
.PHONY: all

build:
	swift build -c release --arch arm64 --arch x86_64
.PHONY: all

clean:
	rm -Rfv ./.build ./.swiftpm ./*.out ./include ./lib
.PHONY: clean

docker:
	docker build -t t0rr3sp3dr0/sapsigner .
.PHONY: clean

sapsigner-alt.out: ./Sources/SAPSignerAlt/*
	$(CC) -L ./Sources/SAPSignerAlt -O2 -Wall -Wextra -Wpedantic -lcurl -lmescal -lsasl2 -o $@ ./Sources/SAPSignerAlt/*.c

sapsigner-emu.out: ./Sources/SAPSignerEmu/*
	$(CC) -I ./include -L ./lib -O2 -Wall -Wextra -Wpedantic -Wno-dollar-in-identifier-extension -lcurl -lsasl2 -lunicorn -rpath . -o $@ ./Sources/SAPSignerEmu/*.c
