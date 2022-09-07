/*** Memory interface ***/
interface mem_bus;
    logic clk, reset;
    // instruction mem interface signals
    logic imem_req;
    logic [31:0] imem_addr, imem_instn;
    logic imem_wait;

    // data mem interface signals
    logic dmem_wait;
    logic [31:0] dmem_addr, dmem_rd, dmem_wd;
    logic dmem_we;
    logic dmem_req;
    logic [3:0] dmem_mask;

endinterface : mem_bus

/*** cimulation ready typical memory model with 1 cycle memory_read latency ***/
module memory_model (
    mem_bus Bus
);
    assign Bus.dmem_rd    = (!Bus.dmem_we) ? Bus.dmem_addr : 'h0;

endmodule : memory_model


module cache_mem_glue_logic # (
        parameter BLOCKS = 4
    )
    (
    input logic clk, reset,
    input logic mem_req,
    input logic [31:0] mem_addr,
    output logic [BLOCKS-1:0] [31:0] mem_read_block,
    input logic mem_we,
    input logic [BLOCKS-1:0] [31:0] mem_write_block,
    output logic mem_miss,
    mem_bus Bus
    );

    logic [31:0] blk_counter_current, blk_counter_next;
    logic [BLOCKS-1:0] [31:0] mem_read_reg;

    assign Bus.dmem_addr = mem_addr + (blk_counter_current << 2);
    assign mem_read_block = mem_read_reg;
    assign Bus.dmem_we = mem_we;
    
    always@(posedge Bus.clk or negedge Bus.reset) begin
        if (!Bus.reset) begin
            blk_counter_current <= 0;
            mem_read_reg <= 0;
        end
        else begin
            blk_counter_current <= blk_counter_next;
            if (mem_req) begin
                if (!Bus.dmem_wait) begin
                    if (mem_we) begin
                        Bus.dmem_wd <= mem_write_block[blk_counter_current];
                    end
                    else begin
                        mem_read_reg[blk_counter_current] <= Bus.dmem_rd;
                    end
                end
            end
        end
    end

    always_comb begin
        mem_miss = 1;
        blk_counter_next = blk_counter_current;
        case (blk_counter_current)  
            0 : begin
                if (mem_req) begin
                    if (!Bus.dmem_wait) begin
                        blk_counter_next = blk_counter_current + 1;
                    end
                end
                else begin
                    mem_miss = 0;
                end
            end
            (BLOCKS-1) : begin
                if (mem_req) begin
                    if (!Bus.dmem_wait) begin
                        blk_counter_next = 0;
                        mem_miss = 0;
                    end
                end
            end
            default : begin
                if (mem_req) begin
                    if (!Bus.dmem_wait) begin
                        blk_counter_next = blk_counter_current + 1;
                    end
                end
            end
        endcase
    end    
endmodule : cache_mem_glue_logic

module tb ();

    localparam BLOCKS = 4;

    logic clk, reset;

    logic mem_req;
    logic [31:0] mem_addr;
    logic [BLOCKS-1:0] [31:0] mem_read_block;
    logic mem_we;
    logic [BLOCKS-1:0] [31:0] mem_write_block; 
    logic mem_miss;

    mem_bus Bus();

    cache_mem_glue_logic dut1 (
        .clk(clk), .reset(reset),
        
        .mem_req(mem_req),
        
        .mem_addr(mem_addr),
        .mem_read_block(mem_read_block),
        .mem_we(mem_we),
        .mem_write_block(mem_write_block),
        .mem_miss(mem_miss),
        .Bus(Bus)
    );

    memory_model mem1 (Bus);

    assign Bus.clk = clk;
    assign Bus.reset = reset;
    /********************************************************************************/
    // reset generator
    initial begin : reset_gen
        reset <= 0; # 22; reset <= 1;
    end : reset_gen
    // generate clock to sequence tests
    always begin : clock_gen
        clk <= 1; # 5; clk <= 0; # 5;
    end : clock_gen

    /********************************************************************************/
    // Driver
    initial begin : Driver
        mem_addr = 0;
        mem_req = 0;
        mem_write_block = '{default:'0};
        mem_we = 0;
        # 30; 
        mem_req = 1;
        mem_addr = 'h40;
    end : Driver

endmodule : tb