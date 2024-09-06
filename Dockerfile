# syntax=docker.io/docker/dockerfile:1

FROM docker.io/library/ubuntu:noble AS build
WORKDIR /usr/local/src/SAPSigner
RUN apt-get update && \
    apt-get install --no-install-recommends -y clang make libcurl4-openssl-dev libsasl2-dev libunicorn-dev && \
    rm -Rf /var/lib/apt/lists/*
COPY . .
RUN make sapsigner-emu.out

FROM docker.io/library/ubuntu:noble AS run
RUN apt-get update && \
    apt-get install --no-install-recommends -y ca-certificates libcurl4t64 libsasl2-2 libunicorn2t64 && \
    rm -Rf /var/lib/apt/lists/*
COPY --from=build /usr/local/src/SAPSigner/sapsigner-emu.out /usr/local/bin/sapsigner
CMD ["sapsigner"]
