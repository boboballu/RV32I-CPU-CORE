// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define RTL_BTB
`include "defs_params_common.svh"
import dbg_pkg::*;

// This file contains the BTB

module BTB #(parameter TAG_SIZE = 20,
             parameter INDEX_SIZE = 10)
(    
            input logic clk, reset,
            
            input logic [31:0] pcF, pcD,
            input logic BTBWriteD,
            input logic [31:0] branchimmD, input logic [2:0] funct3D,
            
            output logic BTBHit,
            output logic [31:0] branchimmF//, output logic [2:0] funct3F
);

    // 4 byte instn, so 2 lsb bits discarded
    // TAG_SIZE + INDEX_SIZE = 30

    typedef struct packed {
        logic [TAG_SIZE-1:0] tag;
        logic [2:0] funct3;
        logic [31:0] branchimm;
    } BTB_ENTRY_t;

    BTB_ENTRY_t [(2 ** INDEX_SIZE)-1:0] BTB;
    
    // BTB: tag and index computation from pcF
    logic [TAG_SIZE-1:0] tag;
    logic [INDEX_SIZE-1:0] index;

    logic [TAG_SIZE-1:0] tag_W;
    logic [INDEX_SIZE-1:0] index_W;
    
    assign index        = pcF[(INDEX_SIZE+1):2];
    assign tag          = pcF[(TAG_SIZE+INDEX_SIZE+1):(INDEX_SIZE+2)];

    assign index_W      = pcD[(INDEX_SIZE+1):2];
    assign tag_W        = pcD[(TAG_SIZE+INDEX_SIZE+1):(INDEX_SIZE+2)];

    // BTB READ in fetch
    // 1) Index BTB with index
    // 2) check for tag match
    // 3) If match, set BTBHit, and pass the branchimmF and funct3F

    assign BTBHit       = (BTB[index].tag == tag);
    assign branchimmF   = BTB[index].branchimm;
    //assign funct3F      = BTB[index].funct3;

    // BTB write in Decode if BTB miss at fetch
    // 1) If BTBWriteD
    // 2) index DTB, write the entry with tag_W, funct3D and branchimmD
    
    always_ff @(posedge clk or negedge reset) begin
        if (!reset) begin
            BTB <= '{default:'1};
        end
        else begin
            if (BTBWriteD) begin
                BTB[index_W].tag        <= tag_W;
                BTB[index_W].funct3     <= funct3D;
                BTB[index_W].branchimm  <= branchimmD; 
            end
        end
    end
endmodule : BTB