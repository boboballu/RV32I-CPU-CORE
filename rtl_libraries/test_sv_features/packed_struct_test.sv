typedef struct packed {
    logic [1:0] s1;
    logic [1:0] s2;
} pd_t;
module packed_struct_test ();
    pd_t pd1, pd2;
    logic clk = 1;

    always begin : clk_gen
        clk = #5 ~clk;
    end : clk_gen

    assign pd1 = {2'b01, 2'b0};
    always_ff @(posedge clk) begin
        pd2 <= pd1;
    end
endmodule : packed_struct_test
