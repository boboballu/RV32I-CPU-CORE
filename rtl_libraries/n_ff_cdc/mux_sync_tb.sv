// or browse Examples

module mux_sync_tb ();
    localparam DATA_WIDTH = 8, M = 2;
    logic clk, reset;
    logic sready;
    logic [DATA_WIDTH-1:0] Din;
    logic [DATA_WIDTH-1:0] Dout;
    
 initial begin : vcd
     $dumpfile("mux_sync_tb.vcd");
     $dumpvars(0,mux_sync_tb);
 end : vcd
    
    initial begin : time0_delta0
        clk = 0;
        reset = 0;
        Din = 0;
    end : time0_delta0
    
    always begin : clk_gen
        clk = #5 ~clk; 
    end : clk_gen
    
    always begin
        @(posedge clk); @(posedge clk);
        @(posedge clk); @(posedge clk);
        Din = $urandom_range(20);
    end
    
    always begin
        @(posedge clk);
        #2 sready = $random;
    end
    
    initial begin
    	#10 reset = 1;
    	#100 $finish;
    end
    
    // connect DUT to tb
    mux_sync #(.DATA_WIDTH(DATA_WIDTH), .M(M)) DUT (clk, reset, sready, Din, Dout);

endmodule : mux_sync_tb