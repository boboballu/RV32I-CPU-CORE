// Code your design here
// Author: Tarun Govind Kesavamurthi
// CDC Synchrolizers

// m-flip-flop synchronizer
module m_ff_sync #(
  parameter M = 2,
  parameter DATA_WIDTH = 1
  ) 
  (input logic clk, reset_n,
   input logic [DATA_WIDTH-1:0] Din, output logic [DATA_WIDTH-1:0] Dout
  );
  logic [DATA_WIDTH-1:0] DFF [M-1:0];
  assign Dout = DFF[M-1];
  always_ff @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
      DFF <= '{default:1'b0};
    end
    else begin
      DFF[0] <= Din;
      for (int i=1; i<M; i++) begin
        DFF[i] <= DFF[i-1];
      end
    end
  end
  
  // Fire assertion if Din is not stable for m+1 destiation cycles
  property p_stability;
    disable iff (!reset_n)
    @(posedge clk) !$stable(Din) |=> $stable(Din)[*M];
  endproperty : p_stability

  A_p_stability: assert property (p_stability);
  
endmodule : m_ff_sync

// mux synchronizer
module mux_sync #(DATA_WIDTH = 8, M = 2)
  (input logic clk, reset_n,
   input logic sready,
   input logic [DATA_WIDTH-1:0] Din, 
   output logic [DATA_WIDTH-1:0] Dout
  );
  
  logic dready;
  logic [DATA_WIDTH-1:0] DFF;
  assign Dout = DFF;
  
  m_ff_syncr #(.M(M)) ff_sync0 (clk, reset_n, sready, dready);
  
  always_ff @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
      DFF <= '{default:'b0};
    end
    else begin
      if (dready) begin
        DFF <= Din;
      end
    end
  end
  
  property p_data_stable;
    disable iff (reset_n) 
    @(posedge clk) (dready) |=> ($stable (Din) || (!dready)); 
  endproperty
  
  A_p_data_stable: assert property (p_data_stable);

endmodule : mux_sync
      
