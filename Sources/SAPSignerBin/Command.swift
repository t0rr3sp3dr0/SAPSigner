//
//  Command.swift
//
//
//  Created by Pedro Tôrres on 2024-05-24.
//

import Foundation

import ArgumentParser

import SAPSignerLib

@main
struct Command: ParsableCommand {
    static var configuration = CommandConfiguration(commandName: "sapsigner")
    
    @Option(name: .shortAndLong, help: "The input file path")
    var input: String = "-"
    
    @Option(name: .shortAndLong, help: "The output file path")
    var output: String = "-"
    
    mutating func run() throws {
        let iData: Data
        if input == "-" {
            iData = FileHandle.standardInput.readDataToEndOfFile()
        } else {
            iData = try Data(contentsOf: URL(fileURLWithPath: input))
        }
        
        let oData = try SAPSigner.sign(iData)
        if output == "-" {
            FileHandle.standardOutput.write(oData)
        } else {
            try oData.write(to: URL(fileURLWithPath: output))
        }
    }
}
