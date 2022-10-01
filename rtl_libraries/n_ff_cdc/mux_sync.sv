
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