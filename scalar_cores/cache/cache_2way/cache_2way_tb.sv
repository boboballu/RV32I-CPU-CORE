import cache_types::*;

module tb ();

    logic clock, reset;
    
    logic req, we;
	logic [31:0] addr;
	logic [3:0] byte_mask;
	logic [31:0] write_block;
    logic miss;
	logic [31:0] read_block;
    
    logic mem_req;
    logic [31:0] mem_read_addr;
    logic [1:0] [31:0] mem_read_block;

    logic mem_we;
    logic [31:0] mem_write_addr;
    logic [1:0] [31:0] mem_write_block;
    logic mem_miss;

    cache_module cache(
        .clock(clock), .reset(reset),
	
        .req(req), .we(we),
        .addr(addr),
        .byte_mask(byte_mask), 
        .write_block(write_block),
        .miss(miss), 
        .read_block(read_block),

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
        write_block = 0;
        reset = 0;
        # 22; reset = 1; #8;  // 30ns done here

        // cache read - miss
        #1 req = 1; we = 0; byte_mask = 'b1111; 
        addr = 'h80; #10; // 41ns done here
        
        // cache write miss
        #50;
        req = 1; we = 1; addr = 'h10; byte_mask = 'b0011; write_block = 32'hdeadbeef;
        
        // cache read - hit
        #50;
        req = 1; we = 0; byte_mask = 'b1111; addr = 'h80;

        // cache write - hit
        #50
        req = 1; we = 1; addr = 'h10; byte_mask = 'b1100; write_block = 32'hdeadbeef;

        // cache read - miss; no writeback 'h80 evicted - no writeback
        #50;
        req = 1; we = 0; byte_mask = 'b1111; addr = 'h20;

        // cache read - miss; writeback '10 evicted - writeback
        #50;
        req = 1; we = 0; byte_mask = 'b1111; addr = 'h30;

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
	output logic [1:0] [31:0] mem_read_block,

    input logic mem_we,
    input logic [31:0] mem_write_addr,
    input logic [1:0] [31:0] mem_write_block,
    
    output logic mem_miss
);

    parameter RAM_SIZE = 1024;

    // internal computed address
    logic [31:0] bank_read_addr, bank_write_addr;
    bit [(RAM_SIZE/4)-1:0][31:0] MEM; // 7 words of memory
    logic [0:0] counter;

    assign bank_read_addr   = {mem_read_addr[31:3], 1'b0};
    assign bank_write_addr  = {mem_write_addr[31:3], 1'b0};
    assign mem_read_block   = mem_req  ? {MEM[bank_read_addr+1], MEM[bank_read_addr]} : 'b0;
    assign mem_miss         = mem_req & ( !(counter!=1) ); 

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
                    MEM[bank_write_addr]    <= mem_write_block[0];
                    MEM[bank_write_addr+1]  <= mem_write_block[1];
                end                     
            end
        end
    end
endmodule : memory