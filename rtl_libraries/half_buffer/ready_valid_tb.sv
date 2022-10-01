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
module ready_valid_tb ();
    parameter DATA_WIDTH = 8;
    parameter PIPELINE_DEPTH = 3;
    parameter NUM_SEQUENCE = 16;

    //  --- Testbench datastructure types --- //
    typedef struct {
        bit valid;
        bit [DATA_WIDTH-1:0] data;
    } sender_t;

    typedef struct {
        bit ready;
    } receiver_t;

    typedef struct {
        int sender_count = 0;
        int receiver_count = 0;
        int data_transfer_assoc_array[bit[DATA_WIDTH-1:0]] = '{8'b0: 1};
    } scoreboard_performance_counter_t;

    // --- Signals to connect to DUT --- //
    logic clk, reset_n;

    // --- Testlists --- //
    // create 2 list of tests that will be driven by individual drivers by individual run tasks
    enum bit [3:0] {PERFECT_SENDER_RECEIVER, BUSY_RECEIVER, RANDOM} test_type;
    sender_t sender_testlist[$];
    receiver_t receiver_testlist[$];
    // --- monitor / scoreboard performance counters --- //
    scoreboard_performance_counter_t scoreboard_perf_ctr;

    // ---RTL instantiation --- //
    ready_valid_if #(.DATA_WIDTH(DATA_WIDTH)) sender_A (clk, reset_n);
    ready_valid_if #(.DATA_WIDTH(DATA_WIDTH)) receiver_B (clk, reset_n);

    ready_valid_hb_pipeline #(.DATA_WIDTH(DATA_WIDTH), .PIPELINE_DEPTH(PIPELINE_DEPTH) ) DUT1 (
        .clk(clk), .reset_n(reset_n),
        
        // "in" is connected module A that sends data
        .in(sender_A.out),      // expects interface of type "ready_valid_if.out"
        
        // "out" is connected to module B that receives data
        .out(receiver_B.in)     // expects interface of type "ready_valid_if.in"
    );

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
        case (test_type)
            RANDOM: begin
                $display("------ Generating random sender and receiver test sequence ------");
                for(i=0; i < NUM_SEQUENCE; ) begin
                    sv = $urandom_range(0,1);
                    sender_testlist.push_back(sender_t'{sv, $urandom_range(0,255)});
                    if (sender_testlist[sender_testlist.size()-1].valid == 1) i++;
                end
                for (i=0; i < NUM_SEQUENCE; ) begin
                    receiver_testlist.push_back(receiver_t'{$urandom_range(0,1)});
                    if (receiver_testlist[receiver_testlist.size()-1].ready == 1) i++;
                end

            end
            PERFECT_SENDER_RECEIVER: begin
                $display("------ Perfect sender and receiver test sequence ------");
                for (int i=0; i < NUM_SEQUENCE; i++) begin
                    sender_testlist.push_back(sender_t'{1'b1, $urandom_range(0,255)});
                    receiver_testlist.push_back(receiver_t'{1'b1});
                end
            end
            BUSY_RECEIVER: begin
                $display("------ Busy Receiver test sequence ------");
                for (int i=0; i < NUM_SEQUENCE; i++) begin
                    sender_testlist.push_back(sender_t'{1'b1, $urandom_range(0,255)});
                end
                for (int i=0; i < NUM_SEQUENCE + (NUM_SEQUENCE)/2; i++) begin
                    if (i < (NUM_SEQUENCE)/2) receiver_testlist.push_back(receiver_t'{1'b0});
                    else     receiver_testlist.push_back(receiver_t'{1'b1});
                end
            end
        endcase
        foreach(sender_testlist[i]) $display("sender : valid-> %b ; data-> %02x", sender_testlist[i].valid, sender_testlist[i].data);
        foreach(receiver_testlist[i]) $display("receiver : ready -> %b", receiver_testlist[i].ready);
        $display ("------ Done ------");
    end : autogen_rand_testlist
    
    initial begin
        #20;
        forever begin
            fork
                run_sender_driver();
                run_receiver_driver();
                monitor_and_scoreboard();
            join
        end
    end

    // never have (if else / case) conditions depending on the signals that are driven by the driver
    // drives sender_A.valid and sender_A.data; Depends on sender_A.ready
    task run_sender_driver();
        static enum bit [1:0] {SENDER_STALL, RECEIVER_STALL, TRANSACT} transaction_tracker;
        static int index=0;
        @(posedge clk);
        if (reset_n == 1'b0) return;
        if (index < sender_testlist.size()) begin
                casex ({sender_testlist[index].valid, sender_A.ready})
                    2'b01: begin // sender_A_has_no_valid_data
                        sender_A.valid = sender_testlist[index].valid;
                        transaction_tracker = SENDER_STALL;
                        index = index + 1;
                    end
                    2'b11: begin // sender_A_has_valid_data_and_receiver_is_ready
                        sender_A.valid = sender_testlist[index].valid;
                        sender_A.data = sender_testlist[index].data;
                        transaction_tracker = TRANSACT;
                        index = index + 1;
                    end
                    default: begin 
                        transaction_tracker = RECEIVER_STALL;
                        /* do nothing */ 
                    end
                endcase
        end
        //@(posedge clk);
    endtask : run_sender_driver

    // never have (if else / case) conditions depending on the signals that are driven by the driver
    // drives receiver_B.ready; Depends on receiver_B.valid and receiver_B.data
    task run_receiver_driver();
        static enum bit [1:0] {SENDER_STALL, RECEIVER_STALL, TRANSACT} transaction_tracker;
        static int index=0;
        @(posedge clk);
        if (reset_n == 1'b0) return;
        if (index < receiver_testlist.size()) begin
            receiver_B.ready = receiver_testlist[index].ready;
            casex ({receiver_B.valid, receiver_testlist[index].ready})
                2'b11: begin
                    transaction_tracker = TRANSACT;
                    index = index + 1;
                end
                2'b10: begin
                    transaction_tracker = RECEIVER_STALL;
                    index = index + 1;
                end
                default: begin
                    transaction_tracker = SENDER_STALL;
                    /* do nothing */ 
                end
            endcase
        end
        //@(posedge clk);
    endtask : run_receiver_driver

    task monitor_and_scoreboard();
        @(posedge clk);
        if (reset_n == 1'b0) return;
        if ( (sender_A.valid && sender_A.ready) && (scoreboard_perf_ctr.sender_count <= 15) ) begin
            scoreboard_perf_ctr.data_transfer_assoc_array[scoreboard_perf_ctr.sender_count] = sender_A.data;
            $display("time: %0t: sender_A: %d : sent < %x >", $time(), scoreboard_perf_ctr.sender_count, sender_A.data);
            scoreboard_perf_ctr.sender_count = scoreboard_perf_ctr.sender_count + 1;
        end
        if ( (receiver_B.valid && receiver_B.ready) && (scoreboard_perf_ctr.receiver_count <= 15) ) begin
            assert(scoreboard_perf_ctr.data_transfer_assoc_array[scoreboard_perf_ctr.receiver_count] == receiver_B.data);
            $display("time: %0t: receiver_B: %d : received < %x >", $time(), scoreboard_perf_ctr.receiver_count, receiver_B.data);
            scoreboard_perf_ctr.receiver_count = scoreboard_perf_ctr.receiver_count + 1;
        end
    endtask : monitor_and_scoreboard

    // end the simulation printing the scoreboard statistics.
    task end_simulation();
        $display("--- END Of Simulation ---");
        $display("-- data transfer stats (Key: data send index | value: Data sent) --");
        foreach(scoreboard_perf_ctr.data_transfer_assoc_array[key]) begin
            $display(" -key: %d   |   -value: %x", key, scoreboard_perf_ctr.data_transfer_assoc_array[key]);
        end
        $display("sender counter: %d   |   receiver counter: %d", scoreboard_perf_ctr.sender_count, scoreboard_perf_ctr.receiver_count);
    endtask : end_simulation

endmodule : ready_valid_tb
