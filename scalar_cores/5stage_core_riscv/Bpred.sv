// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define BPRED
`include "debug_headerfile.svh"
import dbg_pkg::*;

// A bimodal branch predictor

module Bpred #(parameter INDEX_SIZE = 10)
(
    input logic clk, reset,

    input logic [31:0] pcF, pcD,
    input logic br_takenD, BpredWriteD,
    
    output BpredF
);
    // BIMODAL TABLE definition
    logic [1:0] BIMODAL_TABLE [(2**INDEX_SIZE)-1:0];

    // Compute index from pcF
    logic [INDEX_SIZE-1:0] index, index_W;

    assign index   = pcF[INDEX_SIZE-1:0];
    assign index_W = pcD[INDEX_SIZE-1:0]; 
    
    // Reading the prediction
    assign BpredF = BIMODAL_TABLE[index][1]; // MSB of the table entry gives the prediction

    // writing to / updating the predictor
    always_ff @ (posedge clk or negedge reset) begin
        if (!reset) begin
            BIMODAL_TABLE <= '{default:2};
        end
        else begin
            if (BpredWriteD) begin
                if (br_takenD) begin
                    if (BIMODAL_TABLE[index_W] != 2'b11) begin
                        BIMODAL_TABLE[index_W]  <= BIMODAL_TABLE[index_W]+1;
                    end
                end
                else begin
                    if (BIMODAL_TABLE[index_W] != 2'b00) begin
                        BIMODAL_TABLE[index_W]  <= BIMODAL_TABLE[index_W]-1;
                    end
                end
            end
        end
    end

endmodule : Bpred