// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
/*** cimulation ready typical memory model with 1 cycle memory_read latency ***/
module ram_cache_glue 
#(
    parameter BLOCKS = 4
)(
    input logic clock, reset,

    // cache side
    input logic mem_req,
    input logic [31:0] mem_addr,
    input logic mem_we,
    output logic [BLOCKS-1:0] [31:0] mem_read_block,
    input logic [BLOCKS-1:0] [31:0] mem_write_block,
    output logic mem_miss,

    //ram side
    output logic ram_req,
    output logic [31:0] ram_addr,
    output logic ram_we,
    input logic [31:0] ram_read_word,
    output logic [31:0] ram_write_word,
    input logic ram_miss
);

    parameter BLOCK_BIT_SIZE = ($clog2(BLOCKS));

    logic [($clog2(BLOCKS) - 1):0] block_counter;
    logic [BLOCKS-2:0] [31:0] prev_ram_words;

    assign ram_req = mem_req;
    assign ram_we = mem_we;
    assign mem_miss = ram_miss | ( block_counter != (BLOCKS-1) );
    assign mem_read_block = ( mem_req & (!mem_we) & (!mem_miss) ) ? {ram_read_word, prev_ram_words} : '{default:0};
    assign ram_addr = { mem_addr[31:(BLOCK_BIT_SIZE+2)], block_counter , 2'b00 };

    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin
            block_counter <= 0;
            prev_ram_words <= '{default:0};
        end
        else begin
            if (mem_req) begin
                if (!ram_miss) begin
                    if ( (!ram_we) & ( block_counter != (BLOCKS-1) ) ) begin
                        prev_ram_words[block_counter] <= ram_read_word;
                    end 
                    block_counter <= block_counter + 1;
                end
            end
            else begin
                block_counter <= 0;
            end 
        end
    end

    always_comb begin
        if (mem_req) begin
            if (mem_we) begin
                ram_write_word = mem_write_block[block_counter];
            end
            else begin
                ram_write_word = 0;
            end
        end
        else begin
            ram_write_word = 0;
        end
    end
endmodule : ram_cache_glue

module ram_memory_model (
    input logic clock, reset,
    input logic ram_req,
    input logic [31:0] ram_addr,
    input logic ram_we,
    output logic [31:0] ram_read_word,
    input logic [31:0] ram_write_word,
    output logic ram_miss
);
    assign ram_miss = 0;
    assign ram_read_word = ( ram_req & (!ram_we) ) ? ram_addr : 0;
endmodule : ram_memory_model