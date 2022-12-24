module test();
    logic signed [31:0] in = '0;
    logic signed [31:0] Out; 
    initial begin
        in = 2;
        $display("number %d and its 2's complement %d", in, Out);
    end

    always_comb begin
        Out = '0;
        // systemverilog rule : ** Error: loop_test1.sv(15): Range must be bounded by constant expressions.
        for(int i=0; i<32; i++) begin
            if(i==0)
                Out[i] = in[i];
            else
                Out[i]= (|in[i-1:0]) ? ~in[i] : in[i];
        end
    end
endmodule
