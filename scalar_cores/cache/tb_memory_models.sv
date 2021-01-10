// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`include "defs_params_common.svh"
import cache_types::*;

/*** cimulation ready typical memory model with 1 cycle memory_read latency ***/
module memory_model (
    input logic clock, reset,

    input logic mem_req,
    `ifdef dual_ported_L2
    input logic [31:0] mem_read_addr,
    input logic [31:0] mem_write_addr,
    `endif
    `ifdef single_ported_L2
    input logic [31:0] mem_addr,
    `endif
    input logic mem_we,
    output logic [BLOCKS-1:0] [31:0] mem_read_block,
    input logic [BLOCKS-1:0] [31:0] mem_write_block,
    
    output logic mem_miss
);
//assign mem_miss = 0;

// mem writes assoc array
logic [BLOCKS-1:0] [31:0] mem_write_assoc_array [logic[31:0]];

`ifdef single_ported_L2
logic [31:0] mem_read_addr, mem_write_addr;
assign mem_read_addr    = (!mem_we) ? mem_addr : 'h0;
assign mem_write_addr   = (mem_we)  ? mem_addr : 'h0;
`endif

always @(mem_read_addr, mem_req) begin : randomization
   if (mem_req) begin
        mem_miss = 1;
        @(posedge clock);
        mem_miss = 0;
        for (int i=0; i<BLOCKS; i++) begin
            mem_read_block[i] = mem_read_addr;//$urandom_range ((2**32)-1, 0);
        end
    end
    else begin 
        mem_miss = 0;
        mem_read_block = '{default:0};
    end
end : randomization

// mem_writes populated in assoc array
always @(posedge clock) begin : mem_writes
    if (mem_we & mem_req) begin
        mem_write_assoc_array[mem_addr] = mem_write_block;
        // $display("writeback addresses: %08x", mem_addr);
    end
end : mem_writes

endmodule : memory_model

/** ideal meory model with multi cycle memory access latency - not used with trace files **/
module memory (
    input logic clock, reset,

    input logic mem_req,

    `ifdef single_ported_L2
    input logic [31:0] mem_addr,
    `endif
    `ifdef dual_ported_L2
    input logic [31:0] mem_read_addr,
    input logic [31:0] mem_write_addr,
    `endif
    input logic mem_we,
	output logic [BLOCKS-1:0] [31:0] mem_read_block,
    input logic [BLOCKS-1:0] [31:0] mem_write_block,
    
    output logic mem_miss
);

    parameter RAM_SIZE = 1024*16;

    // internal computed address
    logic [31:0] bank_read_addr, bank_write_addr;
    bit [(RAM_SIZE/4)-1:0][31:0] MEM; // 7 words of memory
    logic [1:0] counter;

    `ifdef single_ported_L2
    logic [31:0] mem_read_addr, mem_write_addr;
    assign mem_read_addr    = (!mem_we) ? mem_addr : 'h0;
    assign mem_write_addr   = (mem_we)  ? mem_addr : 'h0;
    `endif

    assign bank_read_addr   = {mem_read_addr[31:4], 2'b0};
    assign bank_write_addr  = {mem_write_addr[31:4], 2'b0};
    assign mem_miss         = mem_req & ( (counter!=3) ); 

    //assign mem_read_block   = mem_req  ? {MEM[bank_read_addr+3], MEM[bank_read_addr+2], MEM[bank_read_addr+1], MEM[bank_read_addr]} : 'b0;
    always_comb begin
        if (mem_req) begin
            for (int i=0; i<BLOCKS; i++) begin
                mem_read_block[i] = MEM[bank_read_addr+i];
            end
        end
        else begin
            mem_read_block = '{default:'0};
        end
    end

    // reset the MEM to a known state
    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin
            for (int i=0; i<(RAM_SIZE/4); i++) begin
                MEM[i] <= i<<2;
            end
            counter <= 0;
        end
    end

    always_ff @(posedge clock) begin
        if (mem_req) begin
            counter <= counter+1'b1;
            if (counter == 3) begin
                if (mem_we) begin
                    for (int i=0; i<BLOCKS; i++) begin
                        MEM[bank_write_addr+i]    <= mem_write_block[i];
                    end
                end                     
            end
        end
        else begin
            counter <= 0;
        end
    end
endmodule : memory