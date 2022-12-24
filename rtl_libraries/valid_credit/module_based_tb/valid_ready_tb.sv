// +---------------------------------+
// |                                 |
// | Simple flat tb implementation   |
// |                                 |
// +---------------------------------+

// [Generic TB blocks]
// * clk_gen
// * reset_n_gen
// * defaults
// * dump_vars

// [custom datatypes]
// * sender_t (sequences for sender driver)
// * receiver_t (sequences for receiver driver)
// * scoreboard_performance_counter_t (monitor perf_ctr)


//                       [sequence generator]
//                       * autogen_rand_testlist

//                           +--------+
//                           |        |
//                           |        |
//                   +------>+in   out+------>
//                           |        |
//                (DUT in)   |        |   (DUT out)
//                sender_A   |        |   receiver_B
//                           ++------++
// [task]                     ^      ^          [task]
// run_sender_driver()        |      |          run_sender_driver()
// * drives DUT_in            +      +          * drives DUT_out
//                           clk   reset_n

//                             [task]
//                             monitor_and_scoreboard()
//                             * monitors DUT_in and DUT_out
//                             * records info in scoreboard_perf_ctr

// Note : 
// The event control @e has to execute and block the current process before the trigger occurs in another process

import datatypes_globals_pkg::*;

module valid_ready_tb ();

    // [EDIT*] local parameters goes here
    parameter type DATA_T = rtl_data_t;
    parameter VALID_FFS = 2;
    parameter CREDIT_FFS = 2;
    // [EDIT] testbench test sequence size
    parameter NUM_SEQUENCE = 50;

    // --- Signals to connect to DUT --- //
    logic clk, reset_n;

    // ---RTL instantiation --- //
    valid_ready_if #(.DATA_T(DATA_T)) sender_A (clk, reset_n);
    valid_ready_if #(.DATA_T(DATA_T)) receiver_B (clk, reset_n);

    // [EDIT*] DUT instantiation goes here
     valid_credit #(.DATA_T(DATA_T), .VALID_FFS(VALID_FFS), .CREDIT_FFS(CREDIT_FFS)) DUT1 (
        .clk(clk), .reset_n(reset_n),

        // "in" is connected module A that sends data
        .in(sender_A.out),      // expects interface of type "valid_ready_if.out"
        .in_credit_ctr(),

        // "out" is connected to module B that receives data
        .out(receiver_B.in),    // expects interface of type "valid_ready_if.in"
        .out_fifo_read_ptr(), .out_fifo_write_ptr()
    );

    valid_ready_tb_elements #(.NUM_SEQUENCE(NUM_SEQUENCE)) tb_elements (
        .clk(clk), .reset_n(reset_n),
        .sender_A(sender_A.in),
        .receiver_B(receiver_B.out)
    );

    initial begin : autogen_rand_testlist
        static int i=0;
        static int sv=0;
        // get the test arg from commandline
        int arg1;
        if ( $value$plusargs("test=%d", arg1)) begin
            $cast(test_type, arg1);
            $display("Received %s", test_type.name());
        end
        else begin
            test_type = BUSY_RECEIVER;
            $display("default test picked:  %s", test_type.name());
        end
        tb_elements.generate_testlist(test_type);
    end : autogen_rand_testlist

    // --- initial / defaults / clock gen / reset gen / vcd gen  --- //
    initial begin : defaults
        clk = 1; reset_n = 1;
        sender_A.valid = 'b0; sender_A.data = 'b0;
        receiver_B.ready = 0;
        #1500 tb_elements.end_simulation(); $finish;
    end : defaults

    initial begin : dump_vars
        $dumpfile("valid_ready_tb.vcd");
        $dumpvars(0,valid_ready_tb);
    end : dump_vars

    always begin : clk_gen
        clk = #5 ~clk;
    end : clk_gen

    // reset_n should async asserted and sync deasserted (add #1 delay for deassertion to satisfy the simulator)
    initial begin : reset_n_gen
        #5 reset_n = 0;
        #16 reset_n = 1;
    end : reset_n_gen

    initial begin
        #20;
        forever begin
            fork
                tb_elements.run_sender_driver();
                tb_elements.run_receiver_driver();
                tb_elements.monitor_sender();
                tb_elements.monitor_receiver();
                begin : all_transaction_done_end
                    if ( (scoreboard_perf_ctr.sender_count == NUM_SEQUENCE) && (scoreboard_perf_ctr.receiver_count == NUM_SEQUENCE) ) begin
                        tb_elements.end_simulation();
                        $finish;
                    end
                end : all_transaction_done_end
            join
        end
    end

endmodule : valid_ready_tb
