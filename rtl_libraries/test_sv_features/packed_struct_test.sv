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

// module bin2gray #(
//     parameter BIT_WIDTH = 8
// )
// (
//     input logic [BIT_WIDTH-1:0] in_bin,
//     output logic [BIT_WIDTH-1:0] out_gray
// );
//     always_comb begin
//         out_gray[BIT_WIDTH-1] = in_bin[BIT_WIDTH-1];
//         for (int i=BIT_WIDTH-2; i>=0; i--) begin
//             out_gray[i] = in_bin[i] ^ in_bin[i+1];
//         end
//     end
// endmodule : bin2gray

module async_fifo_depth_addr();
    parameter FIFO_DEPTH = 5;
    parameter n = $clog2(FIFO_DEPTH);

    initial begin
        for ( int i = ( (2^(n-1)) - (FIFO_DEPTH/2) ) ; i <  ( (2^(n-1)) + (FIFO_DEPTH/2)  + 1); i++) begin
            $display("%d in gray : %d", i, bin2gray(int'(i)));
        end
    end
    function bin2gray(int in_bin);
        automatic int out_gray=0;
        out_gray[] = in_bin[];
        for (int i=31-2; i>=0; i--) begin
            out_gray[i] = in_bin[i] ^ in_bin[i+1];
        end
        return out_gray;
    endfunction : bin2gray
endmodule : async_fifo_depth_addr