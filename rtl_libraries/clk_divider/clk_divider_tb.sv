module clk_divider_tb ();
    parameter CLK_BY_N = 3;
    // --- Signals to connect to DUT --- //
    logic clk, reset_n;
    logic clk_by_N;
    // --- initial / defaults / clock gen / reset gen / vcd gen  --- //
    initial begin : defaults
        clk = 1; reset_n = 1;
        #500 $finish;
    end : defaults

    initial begin : dump_vars
        $dumpfile("clk_divider_tb.vcd");
        $dumpvars(0,clk_divider_tb);
    end : dump_vars

    always begin : clk_gen
        clk = #5 ~clk;
    end : clk_gen

    // reset_n should async asserted and sync deasserted (add #1 delay for deassertion to satisfy the simulator)
    initial begin : reset_n_gen
        #5 reset_n = 0;
        #16 reset_n = 1;
    end : reset_n_gen

    // --- DUT instantiation --- //
    clk_divider #(.N(CLK_BY_N)) DUT1 (.clk(clk), .reset_n(reset_n), .clk_by_N(clk_by_N));

endmodule : clk_divider_tb
