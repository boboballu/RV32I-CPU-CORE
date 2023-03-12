module reset_sync(
    input logic clk, async_reset_n,
    output logic sync_reset_n
);
    logic [1:0] ffs;
    assign sync_reset_n = ffs[1];
    always_ff @(posedge clk or negedge async_reset_n) begin
        if (!async_reset_n) begin
            ffs <= 2'b0;
        end
        else begin
            {ffs[1], ffs[0]} <= {ffs[0], 1'b1};
        end
    end
endmodule : reset_sync