// Code your testbench here
// or browse Examples
module tb ();
  parameter DATA_WIDTH = 4;
  
  logic [DATA_WIDTH-1:0] in;
  logic [DATA_WIDTH-1:0] out;
  logic found;
  
  first_1_finder #(.DATA_WIDTH(DATA_WIDTH)) DUT0 (
    .in(in), .out(out), .found(found) );
  
  
  initial begin
    // Required to dump signals to EPWave
    $dumpfile("dump.vcd");
    $dumpvars(0);
  end
  
  initial begin
  	in = 4'b1100;
    #5;
    $display ("in : %b  | out : %b  | found : %b", in, out, found);
    $finish;
  end
endmodule : tb

// Code your design here
module wrapper (
  input logic [3:0] in,
  output logic [3:0] out,
  output logic found
);
  first_1_finder #(.DATA_WIDTH(4)) DUT0 (.in(in), .out(out), .found(found));
endmodule
  
module first_1_finder
#(
  parameter DATA_WIDTH=8
) 
(
  input logic [DATA_WIDTH-1:0] in,
  output logic [DATA_WIDTH-1:0] out,
  output logic found
);
  
  always_comb begin
    found = 0;
    out = 0;
    for (int i=0; i<DATA_WIDTH; i++) begin : loop_1
      if (found == 'b0) begin
        if (in[i] == 'b1) begin
          out = i;
          found = 'b1;
        end
      end
    end : loop_1
  end
endmodule : first_1_finder