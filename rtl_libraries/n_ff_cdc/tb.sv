// Code your testbench here
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


//tb for m_ff_syncr
module m_ff_sync_tb ();
  logic clk1, reset_n;
  logic clk2;
  logic Din, Dout;
  
  initial begin : vcd
    $dumpfile("m_ff_sync_tb.vcd");
    $dumpvars(0,m_ff_sync_tb); 
  end : vcd
    
  initial begin : time0_delta0
    clk1 = 1;
    clk2 = 1;
    reset_n = 0;
    Din = 0;
  end : time0_delta0

  initial begin : reset_n_gen
    #5 reset_n = 0;
    #16 reset_n = 1;
  end : reset_n_gen
  
  always begin : clk1_gen
    clk1 = #5 ~clk1; 
  end : clk1_gen

  always begin : clk2_gen
    clk2 = #10 ~clk2; 
  end : clk2_gen

  always begin
    @(posedge clk1);
    Din = $random;
  end
  
  initial begin
  #100 $finish;
  end
  
  // connect DUT to tb
  m_ff_sync #(.M(2)) DUT (clk2, reset_n, Din, Dout);
endmodule : m_ff_sync_tb

