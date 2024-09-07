// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SAPSigner",
    products: [
        .executable(name: "sapsigner", targets: ["SAPSignerBin"]),
        .library(name: "SAPSigner", type: .dynamic, targets: ["SAPSignerLib"]),
    ],
    dependencies: [
        .package(url: "https://github.com/apple/swift-argument-parser.git", from: "1.2.0"),
    ],
    targets: [
        .executableTarget(
            name: "SAPSignerBin",
            dependencies: [
                .product(name: "ArgumentParser", package: "swift-argument-parser"),
                .target(name: "SAPSignerLib"),
            ]
        ),
        .target(
            name: "SAPSignerLib",
            dependencies: [
                .target(name: "CommerceKit"),
            ]
        ),
        .binaryTarget(
            name: "CommerceKit",
            path: "CommerceKit.xcframework"
        )
    ]
)
