module clk_divider #(
    parameter N = 3,

    // immutable - local params
    localparam CTR_WIDTH = $clog2(N),
    localparam IS_ODD = N % 2
) (
    input logic clk, reset_n,
    output logic clk_by_N
);
    reg [CTR_WIDTH-1:0]counter_reg;
    logic clk_by_N_positive;
    logic clk_by_N_negative;

    assign clk_by_N = clk_by_N_positive & clk_by_N_negative;

    generate
        if (IS_ODD) begin : N_is_odd
            assign clk_by_N_positive = ( counter_reg <= (N/2) ) ? 1'b1 : 1'b0;
            always_ff @(negedge clk or negedge reset_n) begin
                if (!reset_n) begin
                    clk_by_N_negative <= 'b0;
                end
                else begin
                    clk_by_N_negative <= clk_by_N_positive;
                end
            end
        end : N_is_odd
        else begin : N_is_even
            assign clk_by_N_positive = ( counter_reg < (N/2) ) ? 1'b1 : 1'b0;
            assign clk_by_N_negative = clk_by_N_positive;
        end : N_is_even
    endgenerate

    always_ff @(posedge clk or negedge reset_n) begin
        if (!reset_n) begin
            counter_reg <= 'b0;
        end
        else begin
            counter_reg <= counter_reg + 1;
            if (counter_reg >= N-1) begin
                counter_reg <= 'b0;
            end
        end
    end
endmodule : clk_divider