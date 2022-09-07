// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// the top module used for test and verification //
`define RTL_TOP_TEST
`include "defs_params_common.svh"
import dbg_pkg::*;

module top(    input logic clk, reset,
            output logic [31:0] writedata, dataadr,
            output logic [31:0] readdata, pc, instr,
            output logic memwrite
);

    logic Iwait, Dwait;
    logic dmem_req, imem_req;
    logic [3:0] dmem_mask;

    riscv_32i riscv_32i (
            .clk(clk), .reset(reset),

            // instruction mem interface signals
            .imem_pc_addr(pc),
            .imem_req(imem_req),
            .imem_instn(instr),
            .imem_wait(Iwait),

            // data mem interface signals
            .dmem_we(memwrite),
            .dmem_addr(dataadr), .dmem_wd(writedata),
            .dmem_mask(dmem_mask),
            .dmem_req(dmem_req),
            .dmem_rd(readdata),
            .dmem_wait(Dwait)
    );

    mem_bus Bus();
    unified_L1_cache #(.RAM_SIZE(`L1_SIZE)) L1_cache (.Bus(Bus));
    imem imem(.imem_addr(pc), .imem_instn(instr), .imem_req(imem_req), .imem_wait(Iwait), .Bus(Bus));
    dmem dmem(    .clk(clk), .dmem_we(memwrite), .dmem_addr(dataadr),
                .dmem_wd(writedata), .dmem_mask(dmem_mask), .dmem_req(dmem_req),
                .dmem_rd(readdata), .dmem_wait(Dwait), .Bus(Bus)
    );
endmodule : top
