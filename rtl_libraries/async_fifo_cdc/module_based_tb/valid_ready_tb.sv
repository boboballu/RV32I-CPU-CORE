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
    parameter ROWS = 4;
    parameter ROW_ADDR_WIDTH = ($clog2(ROWS));
    parameter M_FF_SYNC_WIDTH = 2;
    // [EDIT] testbench test sequence size
    parameter NUM_SEQUENCE = 50;

    // --- Signals to connect to DUT --- //
    logic clk_sender, clk_receiver, async_reset_n, sender_reset_n, receiver_reset_n;

    // fifo read and write pointers
    logic [ROW_ADDR_WIDTH-1:0] sender_A_write_ptr, receiver_B_read_ptr;

    // reset_sync instantiation
    // reset_sync sender_reset_A (.clk(clk_sender), .async_reset_n(async_reset_n), .sync_reset_n(sender_reset_n));
    // reset_sync sender_reset_B (.clk(clk_receiver), .async_reset_n(async_reset_n), .sync_reset_n(receiver_reset_n));


    // ---RTL instantiation --- //
    valid_ready_if #(.DATA_T(DATA_T)) sender_A (clk_sender, sender_reset_n);
    valid_ready_if #(.DATA_T(DATA_T)) receiver_B (clk_receiver, receiver_reset_n);


    async_fifo_reset_gen #(.M_FF_SYNC_WIDTH(M_FF_SYNC_WIDTH)) async_fifo_reset_gen (.clk_sender(clk_sender), .clk_receiver(clk_receiver), .async_reset_n(async_reset_n), .sender_reset_n(sender_reset_n), .receiver_reset_n(receiver_reset_n));

    // [EDIT*] DUT instantiation goes here
    async_fifo_valid_ready_wrapper #(.DATA_T(DATA_T), .ROWS(ROWS), .M_FF_SYNC_WIDTH(M_FF_SYNC_WIDTH) ) DUT1 (
        .clk_sender(clk_sender), .clk_receiver(clk_receiver), .sender_reset_n(sender_reset_n), .receiver_reset_n(receiver_reset_n),

        // "in" is connected module A that sends data
        .in(sender_A.out),      // expects interface of type "valid_ready_if.out"
        .in_write_ptr(sender_A_write_ptr),

        // "out" is connected to module B that receives data
        .out(receiver_B.in),    // expects interface of type "valid_ready_if.in"
        .out_read_ptr(receiver_B_read_ptr)
    );

    // // [EDIT*] DUT instantiation goes here
    // async_fifo_valid_ready_wrapper_w_reset_gen #(.DATA_T(DATA_T), .ROWS(ROWS), .M_FF_SYNC_WIDTH(M_FF_SYNC_WIDTH) ) DUT1 (
    //     .clk_sender(clk_sender), .clk_receiver(clk_receiver), .async_reset_n(async_reset_n),

    //     // "in" is connected module A that sends data
    //     .in(sender_A.out),      // expects interface of type "valid_ready_if.out"
    //     .in_write_ptr(sender_A_write_ptr),

    //     // "out" is connected to module B that receives data
    //     .out(receiver_B.in),    // expects interface of type "valid_ready_if.in"
    //     .out_read_ptr(receiver_B_read_ptr)
    // );



    valid_ready_tb_elements #(.NUM_SEQUENCE(NUM_SEQUENCE)) tb_elements (
        .clk_sender(clk_sender), .clk_receiver(clk_receiver), .sender_reset_n(sender_reset_n), .receiver_reset_n(receiver_reset_n),
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
        clk_sender = 1; clk_receiver = 1; async_reset_n = 1;
        sender_A.valid = 'b0; sender_A.data = 'b0;
        receiver_B.ready = 0;
        #2500 tb_elements.end_simulation(); $finish;
    end : defaults

    initial begin : dump_vars
        $dumpfile("valid_ready_tb.vcd");
        $dumpvars(0,valid_ready_tb);
    end : dump_vars

    initial begin : clk_sender_gen
        forever begin
            clk_sender = #5 ~clk_sender;
        end
    end : clk_sender_gen

    initial begin : clk_receiver_gen
        #5;
        forever begin
            clk_receiver = #10 ~clk_receiver;
        end
    end : clk_receiver_gen

    // async_reset_n should async asserted and sync deasserted (add #1 delay for deassertion to satisfy the simulator)
    initial begin : async_reset_n_gen
        #5 async_reset_n = 0;
        #16 async_reset_n = 1;
    end : async_reset_n_gen


    initial begin
        #20;
        forever begin
            tb_elements.run_sender_driver();
        end
    end
    initial begin
        #20;
        forever begin
            tb_elements.run_receiver_driver();
        end
    end
    initial begin
        #20;
        forever begin
            tb_elements.monitor_sender();
        end
    end
    initial begin
        #20;
        forever begin
            tb_elements.monitor_receiver();
        end
    end

    // issue wuth fork-join : (All) waits for the longest thread to finish and joins
    // fork-join_any : waits for the earliest thread to finish and the rest is dropped
    // initial begin
    //     #20;
    //     forever begin
    //         fork
    //             tb_elements.run_sender_driver();
    //             tb_elements.monitor_sender();
    //         join
    //     end
    // end

    // initial begin
    //     #20;
    //     forever begin
    //         fork
    //             tb_elements.run_receiver_driver();
    //             tb_elements.monitor_receiver();
    //         join
    //     end
    // end

    always@(scoreboard_perf_ctr.sender_count or scoreboard_perf_ctr.receiver_count) begin : all_transaction_done_end
        if ( (scoreboard_perf_ctr.sender_count == NUM_SEQUENCE) && (scoreboard_perf_ctr.receiver_count == NUM_SEQUENCE) ) begin
            tb_elements.end_simulation();
            $finish;
        end
    end : all_transaction_done_end


    // issue wuth fork-join : (All) waits for the longest thread to finish and joins
    // fork-join_any : waits for the earliest thread to finish and the rest is dropped
    // initial begin
    //     #20;
    //     forever begin
    //         fork
    //             tb_elements.run_sender_driver();
    //             tb_elements.run_receiver_driver();
    //             tb_elements.monitor_sender();
    //             tb_elements.monitor_receiver();
    //         join_any
    //         begin : all_transaction_done_end
    //             if ( (scoreboard_perf_ctr.sender_count == NUM_SEQUENCE) && (scoreboard_perf_ctr.receiver_count == NUM_SEQUENCE) ) begin
    //                 tb_elements.end_simulation();
    //                 $finish;
    //             end
    //         end : all_transaction_done_end
    //     end
    // end

endmodule : valid_ready_tb
