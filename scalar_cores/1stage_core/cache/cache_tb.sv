// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/

import cache_types::*;

typedef struct packed {
    int rd, rd_miss;
    int wr, wr_miss;
    int wb, mem_tr;
}cache_metric_counter_t;

cache_metric_counter_t mc = '{default:0};
int fp;

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

    memory_model memory (
        .clock(clock), .reset(reset),

        .mem_req(mem_req),
        .mem_read_addr(mem_read_addr), 
        .mem_read_block(mem_read_block),

        .mem_we(mem_we),
        .mem_write_addr(mem_write_addr),
        .mem_write_block(mem_write_block),

        .mem_miss(mem_miss)
    );

    // get trace_file from commandline + args 
    string tf;
	initial begin : trace_file
		if ( !$value$plusargs("TF=%s", tf)) begin
	        $display("FATAL: +TF plusarg not found on command line");
	        $fatal;
	    end
        $display("%m found +TF=%s", tf);
        fp = $fopen(tf,"r");
    end : trace_file

    // reset generator
    initial begin : reset_block
        // defaults
        req = 0; we = 0; addr = 0; byte_mask = 0; 
        write_word = 0;
        reset = 0;
        # 22; reset = 1; #8;  // 30ns done here
    end : reset_block

	// generate clock to sequence tests
	always begin : clock_block
		clock = 1; # 5; clock = 0; # 5;
	end : clock_block

    // driving all the tests
    initial begin : drive
        #30; // after reset
        // cpu_model("r", 'h800, 'b1111, 0);
        // cpu_model("w", 'h100, 'b0011, 32'hdeadbeef);
        // cpu_model("r", 'h800, 'b1111, 0);
        // cpu_model("w", 'h100, 'b1100, 32'hdeadbeef);
        // cpu_model("r", 'h200, 'b1111, 0);
        // cpu_model("r", 'h300, 'b1111, 0);
        // cpu_model("r", 'h400, 'b1111, 0);
        // cpu_model("r", 'h500, 'b1111, 0);
        while (1) begin
            trace_driver();
        end
    end : drive

    // metric calculation
    always @(we, req) begin : metric_calculator
        @(negedge clock);
        if (req) begin
            if (we) begin
                mc.wr++;
                if (miss) begin
                    mc.wr_miss++;
                    mc.mem_tr++;
                    if (mem_we) begin
                        mc.wb++;
                        mc.mem_tr++;
                    end
                end
            end
            else begin
                mc.rd++;
                if (miss) begin 
                    mc.rd_miss++;
                    mc.mem_tr++;
                    if (mem_we) begin
                        mc.wb++;
                        mc.mem_tr++;
                    end
                end
            end
        end
    end : metric_calculator

    task trace_driver ();
        string dvr_we; int dvr_addr;
        int status;
        if (!$feof(fp)) begin
            status = $fscanf(fp, "%s %h", dvr_we, dvr_addr);
            if ( status != 2 ) begin
                $display ("ERROR reading file : %d %c %h", status , dvr_we[0], dvr_addr);
                $stop;
            end
            cpu_model(dvr_we[0], dvr_addr, 'b1111, $urandom_range(((2**32)-1), 0));
        end
        else begin
            #50;
            $display ("trace file -> EOF");
            $display(); $display();
            $display ("Simulation results");
            $display ("a. number of L1 reads: %d", mc.rd);
            $display ("b. number of L1 read misses: %d", mc.rd_miss);
            $display ("c. number of L1 writes: %d", mc.wr);
            $display ("d. number of L1 write misses: %d", mc.wr_miss);
            $display ("e. L1 miss rate:\t%0.4f", (real'(mc.rd_miss+mc.wr_miss)/real'(mc.rd+mc.wr)));
            $display ("f. number of writebacks from L1 memory: %d", mc.wb);
            $display ("g. total memory traffic: %d", mc.mem_tr);
            $display(); $display();
            $finish;
        end
    endtask : trace_driver

    task cpu_model (
        input byte trace_rw_char, input logic[31:0] trace_addr, 
        input logic [3:0] trace_word_mask,
        input logic[31:0] trace_write_word
        );

        @(posedge clock);
        // if (miss == 1'b1) begin
        //     wait (miss == 0);
        // end

        req = 1;
        case (trace_rw_char)
            "r": we = 0;
            "w": we = 1;
        endcase
        addr = trace_addr;
        byte_mask = trace_word_mask;
        write_word = trace_write_word; //$urandom_range(((2**32)-1), 0);
        
        @(posedge clock);        
        wait (miss == 0);
        @(posedge clock);
        req = 0; 
    endtask : cpu_model 
    
endmodule : tb


module memory_model (
    input logic clock, reset,

    input logic mem_req,
    input logic [31:0] mem_read_addr,
	output logic [BLOCKS-1:0] [31:0] mem_read_block,

    input logic mem_we,
    input logic [31:0] mem_write_addr,
    input logic [BLOCKS-1:0] [31:0] mem_write_block,
    
    output logic mem_miss
);
//assign mem_miss = 0;
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

endmodule : memory_model


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
    logic [1:0] counter;

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