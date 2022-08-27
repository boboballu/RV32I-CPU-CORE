// Code your testbench here
// or browse Examples

module tb ();
  localparam DATA_WIDTH = 8, M = 2;
  logic clk, reset;
  logic sready;
  logic [DATA_WIDTH-1:0] Din;
  logic [DATA_WIDTH-1:0] Dout;
  
//  initial begin : vcd
//    $dumpfile("dump.vcd");
//    $dumpvars(0,tb);
//  end : vcd
  
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
  mux_syncr #(.DATA_WIDTH(DATA_WIDTH), .M(M)) DUT (clk, reset, sready, Din, Dout);
  
endmodule : tb

/*
//tb for m_ff_syncr
module tb ();
  logic clk=0, reset;
  logic Din, Dout;
  
  initial begin : vcd
    $dumpfile("dump.vcd");
    $dumpvars(0,tb); 
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
    @(posedge clk);
    #2 Din = $random;
  end
  
  initial begin
  #10 reset = 1;
  #100 $finish;
  end
  
  // connect DUT to tb
  m_ff_syncr #(.M(2)) DUT (clk, reset, Din, Dout);
endmodule : tb_m_ff_syncr
*/

