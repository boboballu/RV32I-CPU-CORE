import cache_types::*;

module tb ();

    logic clock, reset;
    
    logic req, we;
	logic [31:0] addr;
	logic [3:0] byte_mask;
	logic [31:0] write_word;
    logic miss;
	logic [31:0] read_word;
    
    logic mem_req;
    logic [31:0] mem_read_addr;
    logic [BLOCKS-1:0] [31:0] mem_read_block;

    logic mem_we;
    logic [31:0] mem_write_addr;
    logic [BLOCKS-1:0] [31:0] mem_write_block;
    logic mem_miss;

    cache_module cache(
        .clock(clock), .reset(reset),
	
        .req(req), .we(we),
        .addr(addr),
        .byte_mask(byte_mask), 
        .write_word(write_word),
        .miss(miss), 
        .read_word(read_word),

        .mem_req(mem_req), 
        .mem_read_addr(mem_read_addr),
        .mem_read_block(mem_read_block),
        
        .mem_we(mem_we),
        .mem_write_addr(mem_write_addr),
        .mem_write_block(mem_write_block),
        
        .mem_miss(mem_miss)
    );

    memory memory (
        .clock(clock), .reset(reset),

        .mem_req(mem_req),
        .mem_read_addr(mem_read_addr), 
        .mem_read_block(mem_read_block),

        .mem_we(mem_we),
        .mem_write_addr(mem_write_addr),
        .mem_write_block(mem_write_block),

        .mem_miss(mem_miss)
    );

    // reset generator
    initial begin
        // defaults
        req = 0; we = 0; addr = 0; byte_mask = 0; 
        write_word = 0;
        reset = 0;
        # 22; reset = 1; #8;  // 30ns done here

        // cache read - miss
        #1 req = 1; we = 0; byte_mask = 'b1111; addr = 'h800; #10; // 41ns done here
        
        // cache write miss
        #50;
        req = 1; we = 1; addr = 'h100; byte_mask = 'b0011; write_word = 32'hdeadbeef;
        
        // cache read - hit
        #50;
        req = 1; we = 0; byte_mask = 'b1111; addr = 'h800;

        // cache write - hit
        #50
        req = 1; we = 1; addr = 'h100; byte_mask = 'b1100; write_word = 32'hdeadbeef;

        // cache read - miss; no writeback 'h80 evicted - no writeback
        #50;
        req = 1; we = 0; byte_mask = 'b1111; addr = 'h200;

        // cache read - miss; writeback '10 evicted - writeback
        #50;
        req = 1; we = 0; byte_mask = 'b1111; addr = 'h300;

        // cache read - miss; writeback '10 evicted - writeback
        #50;
        req = 1; we = 0; byte_mask = 'b1111; addr = 'h400;

        // cache read - miss; writeback '10 evicted - writeback
        #50;
        req = 1; we = 0; byte_mask = 'b1111; addr = 'h500;

    end
	// generate clock to sequence tests
	always begin
		clock = 1; # 5; clock = 0; # 5;
	end

endmodule : tb

module memory (
    input logic clock, reset,

    input logic mem_req,
    input logic [31:0] mem_read_addr,
	output logic [BLOCKS-1:0] [31:0] mem_read_block,

    input logic mem_we,
    input logic [31:0] mem_write_addr,
    input logic [BLOCKS-1:0] [31:0] mem_write_block,
    
    output logic mem_miss
);

    parameter RAM_SIZE = 1024*16;

    // internal computed address
    logic [31:0] bank_read_addr, bank_write_addr;
    bit [(RAM_SIZE/4)-1:0][31:0] MEM; // 7 words of memory
    logic [0:0] counter;

    assign bank_read_addr   = {mem_read_addr[31:4], 2'b0};
    assign bank_write_addr  = {mem_write_addr[31:4], 2'b0};
    assign mem_miss         = mem_req & ( !(counter!=1) ); 


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
            if (counter == 1) begin
                if (mem_we) begin
                    for (int i=0; i<BLOCKS; i++) begin
                        MEM[bank_write_addr+i]    <= mem_write_block[i];
                    end
                end                     
            end
        end
    end
endmodule : memory