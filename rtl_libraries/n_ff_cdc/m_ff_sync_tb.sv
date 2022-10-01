//tb for m_ff_syncr
// req ack protocol


interface req_ack_if #(DATA_WIDTH = 8) (input clk, reset_n);

logic req, ack;
logic [DATA_WIDTH-1:0] data;

modport out(
    output req, data,
    input ack
);

modport in(
    input out, data,
    output ack
);

endinterface : req_ack_if


module ready_valid2req_ack #(
    parameter M = 2,
    parameter BIT_WIDTH = 8
)
(
    input logic clk, reset_n,
    ready_valid_if in,      // expects interface of type "ready_valid_if.out"
    req_ack_if out          // expects interface of type "req_ack_if.out"
);

    //
endmodule : ready_valid2req_ack

module m_ff_sync_tb ();
    localparam DATA_WIDTH = 8, M = 2;
    logic clk1, reset_n;
    logic clk2;
    logic [DATA_WIDTH-1:0] Din, Dout;
    
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
    m_ff_sync #(.M(2), .DATA_WIDTH(DATA_WIDTH)) DUT (clk2, reset_n, Din, Dout);
endmodule : m_ff_sync_tb

