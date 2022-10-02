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

// ------ CUSTOM DATATYPES ------ //
//  --- Testbench datastructure types --- //

// the modules have datatype of the payload of ready-valid protocol parameterized (DATA_T)
// But for simulation, logic type is not adviced to be used (not adviced to be used in assoc array / queues etc)
// So, create a datatype for RTL with logic and another datatype for tb with bit
typedef logic [7:0] rtl_data_t;
typedef bit   [7:0] tb_data_t;

// The sequence generator generates a queue of sequences of the below struct datatypes
// used by driver
typedef struct {
    bit valid;
    tb_data_t data;
} sender_t;

typedef struct {
    bit ready;
} receiver_t;

// Used by monitor
typedef struct {
    int sender_count = 0;
    int receiver_count = 0;
    // Note: Donot use logic datatype in associatve array. It blows up memory and breaks the simulator
    int data_transfer_assoc_array[tb_data_t] = '{8'b0: 1};
} scoreboard_performance_counter_t;

// --- Testlists --- //
// create 2 queue of tests that will be driven by individual drivers by individual run tasks
// used by driver and generate_testlist
typedef enum bit [3:0] {PERFECT_SENDER_RECEIVER, BUSY_RECEIVER, RANDOM} test_type_t;

// testbench variables //
test_type_t test_type;
sender_t sender_testlist[$];
receiver_t receiver_testlist[$];

// --- monitor / scoreboard performance counters --- //
scoreboard_performance_counter_t scoreboard_perf_ctr;

module ready_valid_tb ();

    parameter type DATA_T = rtl_data_t;
    parameter PIPELINE_DEPTH = 3;
    parameter NUM_SEQUENCE = 16;

    // --- Signals to connect to DUT --- //
    logic clk, reset_n;

    // ---RTL instantiation --- //
    ready_valid_if #(.DATA_T(DATA_T)) sender_A (clk, reset_n);
    ready_valid_if #(.DATA_T(DATA_T)) receiver_B (clk, reset_n);

    ready_valid_hb_pipeline #(.DATA_T(DATA_T), .PIPELINE_DEPTH(PIPELINE_DEPTH) ) DUT1 (
        .clk(clk), .reset_n(reset_n),

        // "in" is connected module A that sends data
        .in(sender_A.out),      // expects interface of type "ready_valid_if.out"

        // "out" is connected to module B that receives data
        .out(receiver_B.in)     // expects interface of type "ready_valid_if.in"
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
        generate_testlist(test_type);
    end : autogen_rand_testlist

    // --- initial / defaults / clock gen / reset gen / vcd gen  --- //
    initial begin : defaults
        clk = 1; reset_n = 1;
        sender_A.valid = 'b0; sender_A.data = 'b0;
        receiver_B.ready = 0;
        #500 end_simulation(); $finish;
    end : defaults

    initial begin : dump_vars
        $dumpfile("ready_valid_tb.vcd");
        $dumpvars(0,ready_valid_tb);
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
                run_sender_driver();
                run_receiver_driver();
                monitor_sender();
                monitor_receiver();
                begin : all_transaction_done_end
                    if ( (scoreboard_perf_ctr.sender_count == NUM_SEQUENCE) && (scoreboard_perf_ctr.receiver_count == NUM_SEQUENCE) ) begin
                        end_simulation();
                        $finish;
                    end
                end : all_transaction_done_end
            join
        end
    end

    `include "ready_valid_tb_elements.sv"

endmodule : ready_valid_tb
