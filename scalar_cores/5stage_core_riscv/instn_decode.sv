// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`include "debug_headerfile.svh"
// decodes instruction in ID stage
module instn_decode 	(
    input logic [31:0] instnD,
    
    output [6:0] opD, 
    output logic [2:0] funct3D, output logic [6:0] funct7D,
    output logic [31:0] jumpimmD, branchimmD, utypeimmD, stypeimmD, itypeimmD,
    output logic [4:0] rsD, rtD, rdD
);
    assign opD = instnD[6:0];
    // control funct signals from instnD
    assign funct3D = instnD[14:12];
    assign funct7D = instnD[31:25];

    // source and destination reg addrs
    assign rsD = instnD[19:15]; 
    assign rtD = instnD[24:20];
    assign rdD  = instnD[11:7]; // dest reg

    // all the immediate logics
    assign jumpimmD   = {{11{instnD[31]}}, instnD[31], instnD[19:12], instnD[20], instnD[30:21], 1'b0}; // riscv - for jump
    assign branchimmD = {{19{instnD[31]}}, instnD[31], instnD[7], instnD[30:25], instnD[11:8], 1'b0}; // riscv - for branch
    assign utypeimmD  = {instnD[31:12], {12'b0}}; // riscv - for lui and auipc
    // stype and itype corresponds lw sw and imm instnDs - goes through ALU
    assign stypeimmD  = {{20{instnD[31]}},instnD[31:25], instnD[11:7]}; // store
    assign itypeimmD  = {{20{instnD[31]}}, instnD[31:20]}; // load, jalr
endmodule : instn_decode