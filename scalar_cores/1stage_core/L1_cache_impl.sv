module L1_cache 
#(
    sets        = 1024,
    block_size  = 2,
    assoc       = 2
)
(
    input logic clk, 

    input logic imem_req,
    input logic [31:0] imem_addr,
    output logic [((block_size*32)-1):0] imem_block_data,

    input logic dmem_req, dmem_we,
    output logic [((block_size*32)-1):0] dmem_block_data
);

    genvar i;
    generate (i=0; i<block_size; i++) begin
        assign imem_block_data[( (32 * (i+1) )-1 ):(32*i)] = imem_req ? MEM[imem_addr[31:2] + 4*i] : 'b0;
    end

