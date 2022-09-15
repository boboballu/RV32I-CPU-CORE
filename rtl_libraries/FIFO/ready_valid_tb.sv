
module ready_valid_tb ();
    parameter DATA_WIDTH = 8;
    parameter PIPELINE_DEPTH = 3;

    // --- Signals to connect to DUT --- //
    logic clk, reset_n;
    ready_valid_if #(.DATA_WIDTH(DATA_WIDTH)) sender_A (clk, reset_n);
    ready_valid_if #(.DATA_WIDTH(DATA_WIDTH)) receiver_B (clk, reset_n);


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

    // --- Testlists --- //
    // create 2 list of tests that will be driven by individual drivers by individual run tasks
    enum bit [3:0] {PERFECT_SENDER_RECEIVER, BUSY_RECEIVER, RANDOM} test_type;
    sender_t sender_testlist[$];
    receiver_t receiver_testlist[$];
    // --- monitor / scoreboard performance counters --- //
    scoreboard_performance_counter_t scoreboard_perf_ctr;

    // ---RTL instantiation --- //
    ready_valid_skid_pipeline #(.DATA_WIDTH(DATA_WIDTH), .PIPELINE_DEPTH(PIPELINE_DEPTH) ) DUT1 (
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

    initial begin : reset_n_gen
        #5 reset_n = 0;
        #10 reset_n = 1;
    end : reset_n_gen

    initial begin : autogen_rand_testlist
        static int i=0;
        static int sv=0;
        test_type = RANDOM;
        case (test_type)
            RANDOM: begin
                $display("------ Generating random sender and receiver test sequence ------");
                for(i=0; i <= 15; ) begin
                    sv = $urandom_range(0,1);
                    sender_testlist.push_back(sender_t'{sv, $urandom_range(0,255)});
                    if (sender_testlist[sender_testlist.size()-1].valid == 1) i++;
                end
                for (i=0; i <= 15; ) begin
                    receiver_testlist.push_back(receiver_t'{$urandom_range(0,1)});
                    if (receiver_testlist[receiver_testlist.size()-1].ready == 1) i++;
                end

            end
            PERFECT_SENDER_RECEIVER: begin
                $display("------ Perfect sender and receiver test sequence ------");
                for (int i=0; i<=15; i++) begin
                    sender_testlist.push_back(sender_t'{1'b1, $urandom_range(0,255)});
                    receiver_testlist.push_back(receiver_t'{1'b1});
                end
            end
            BUSY_RECEIVER: begin
                $display("------ Busy Receiver test sequence ------");
                for (int i=0; i<=15; i++) begin
                    sender_testlist.push_back(sender_t'{1'b1, $urandom_range(0,255)});
                    receiver_testlist.push_back(receiver_t'{1'b0});
                end
            end
        endcase
        foreach(sender_testlist[i]) $display("sender : valid-> %b ; data-> %02x", sender_testlist[i].valid, sender_testlist[i].data);
        foreach(receiver_testlist[i]) $display("receiver : ready -> %b", receiver_testlist[i].ready);
    end : autogen_rand_testlist
    
    initial begin
        #15;
        forever begin
            fork
                run_sender_driver();
                run_receiver_driver();
                monitor_and_scoreboard();
            join
        end
    end

    task sender_driver(logic valid, ready, logic [DATA_WIDTH-1:0] data);
        sender_A.valid = valid;
        if (sender_A.valid && sender_A.ready) begin  // sender_A_is_ready_and_has_valid_data
            sender_A.data = data;
        end
        @(posedge clk);

    endtask : sender_driver

    task run_sender_driver();
        static int index=0;
        if (index < sender_testlist.size()) begin
            sender_driver(sender_testlist[index].valid, sender_A.ready, sender_testlist[index].data);
            casex ({sender_A.valid, sender_A.ready})
                2'b?1: begin  // sender_A_is_ready_and_has_valid_data
                    index = index + 1;
                end
                // 2'b01: begin
                //     sender_driver(sender_testlist[valid_index].valid, sender_A.ready, sender_testlist[data_index].data);
                //     valid_index = valid_index + 1;
                // end
                default:  @(posedge clk);
            endcase
        end
        else
            @(posedge clk);
    endtask : run_sender_driver

    task run_receiver_driver();
        static int index=0;
        if (index < receiver_testlist.size()) begin
            receiver_B.ready = receiver_testlist[index].ready;
            casex ({receiver_B.valid, receiver_B.ready})
                2'b1?:  index = index + 1;
                default:  @(posedge clk);
            endcase
        end
        else
            @(posedge clk);
    endtask : run_receiver_driver

    task monitor_and_scoreboard();
        @(negedge clk);
        if (sender_A.valid && sender_A.ready) begin
            scoreboard_perf_ctr.sender_count = scoreboard_perf_ctr.sender_count + 1;
            scoreboard_perf_ctr.data_transfer_assoc_array[sender_A.data] = scoreboard_perf_ctr.sender_count;
            $display("sender_A: %d : sent < %x >", scoreboard_perf_ctr.sender_count, sender_A.data);
        end
        if (receiver_B.valid && receiver_B.ready) begin
            scoreboard_perf_ctr.receiver_count = scoreboard_perf_ctr.receiver_count + 1;
            assert(scoreboard_perf_ctr.data_transfer_assoc_array[receiver_B.data] == scoreboard_perf_ctr.receiver_count);
            $display("receiver_B: %d : received < %x >", scoreboard_perf_ctr.receiver_count, receiver_B.data);
        end
    endtask : monitor_and_scoreboard

    // end the simulation printing the scoreboard statistics.
    task end_simulation();
        $display("--- END Of Simulation ---");
        $display("-- data transfer stats (Key: Data sent | value: data send index) --");
        foreach(scoreboard_perf_ctr.data_transfer_assoc_array[key]) 
            $display(" -key: %x   |   -value: %d", key, scoreboard_perf_ctr.data_transfer_assoc_array[key]);
        $display("sender counter: %d   |   receiver counter %d", scoreboard_perf_ctr.sender_count, scoreboard_perf_ctr.receiver_count);
    endtask : end_simulation

endmodule : ready_valid_tb
