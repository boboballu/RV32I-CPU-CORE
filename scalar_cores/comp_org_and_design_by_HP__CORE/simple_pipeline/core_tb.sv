module tb ();

    // Parameters
    parameter LD = 7'b000_0011, SD = 7'b010_0011, BEQ = 7'b110_0011, NOP = 32'h0000_0013, ALUop = 7'b011_0011;

    // local vars
    string EXEC;

    // local signals
    logic clock;
    logic reset;

    // DUT instanciation
    RISCVCPU DUT (.clock(clock));

    // adding an external reset for DUT registers
    // since this is a behaviour model from comp org and design - hennessey & patterson book, the DUT doesn't have reset
    // Hence I have added a reset section in this testbench to manually reset the registers
    always @ (posedge clock or negedge reset) begin : DUT_external_reset
        if (!reset) begin
            {DUT.PC, DUT.IDEXA, DUT.IDEXB, DUT.EXMEMB, DUT.EXMEMALUOut, DUT.MEMWBValue} <= 'h0;
            {DUT.IFIDIR, DUT.IDEXIR, DUT.EXMEMIR, DUT.MEMWBIR} <= 'h0;                               // pipeline registers
        end
    end : DUT_external_reset

    // reset generator - resets all the flipflops in the DUT
    initial begin : reset_gen
        reset = 0;
        #15 reset = 1;
    end : reset_gen

    // clock generator
    initial begin : clock_gen
        clock = 1;
        forever begin
            clock = #5 ~clock;
        end
    end : clock_gen
    
    // Instruction memory and Data memory initializer
    initial begin
        // initialize data memory
        for (int i=0; i<32; i++) begin
            DUT.DMemory[i] = i;
        end

        // initialize instruction memory
        if ( !$value$plusargs("EXEC=%s", EXEC)) begin
	        $display("FATAL: +EXEC plusarg not found on command line");
	        $fatal;
	    end
	    $display("%m found +EXEC=%s", EXEC);
        
        // more reading on $readmem methods
        // https://athena.ecs.csus.edu/~changw/class_docs/VerilogManual/memory.html
        $readmemh(EXEC, DUT.IMemory);
    end

    // lesson here - dont clear these lines
    // initial begin
    //     #5 clock=1;
    //     #5;
    //     forever begin
    //         clock = #5 ~clock;
    //     end

    //     // the below code wont work since the forever loop and the below code is in the same thread
    //     // dont delete these lines. Let this be a lesson learnt
    //     // #100; 
    //     // $display ("store value at 'h32: %d", DUT.DMemory[32]);
    //     // $finish;
    // end

    // stop simulation
    initial begin
        #300; 
        $display ("store value at 'h32: %d", DUT.DMemory[32]);
        $finish;
    end
endmodule : tb