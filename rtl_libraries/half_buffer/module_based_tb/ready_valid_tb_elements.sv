import datatypes_globals_pkg::*;
module ready_valid_tb_elements #(
    parameter NUM_SEQUENCE = 16
)(
    // generic signals
    input logic clk, reset_n,

    // "in" is connected module A that sends data
    ready_valid_if sender_A,  // expects interface of type "ready_valid_if.out"

    // "out" is connected to module B that receives data
    ready_valid_if receiver_B  // expects interface of type "ready_valid_if.in"
);
    task generate_testlist(test_type_t test_type);
        static int i=0;
        static int sv=0;
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
    endtask : generate_testlist

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

    task monitor_sender();
        @(posedge clk);
        if (reset_n == 1'b0) return;
        if ( (sender_A.valid && sender_A.ready) && (scoreboard_perf_ctr.sender_count <= 15) ) begin
            scoreboard_perf_ctr.data_transfer_assoc_array[scoreboard_perf_ctr.sender_count] = sender_A.data;
            $display("time: %0t: sender_A: %d : sent < %x >", $time(), scoreboard_perf_ctr.sender_count, sender_A.data);
            scoreboard_perf_ctr.sender_count = scoreboard_perf_ctr.sender_count + 1;
        end
    endtask : monitor_sender

    task monitor_receiver();
        @(posedge clk);
        if (reset_n == 1'b0) return;
        if ( (receiver_B.valid && receiver_B.ready) && (scoreboard_perf_ctr.receiver_count <= 15) ) begin
            assert(scoreboard_perf_ctr.data_transfer_assoc_array[scoreboard_perf_ctr.receiver_count] == receiver_B.data);
            $display("time: %0t: receiver_B: %d : received < %x >", $time(), scoreboard_perf_ctr.receiver_count, receiver_B.data);
            scoreboard_perf_ctr.receiver_count = scoreboard_perf_ctr.receiver_count + 1;
        end
    endtask : monitor_receiver

    // end the simulation printing the scoreboard statistics.
    task end_simulation();
        $display("--- END Of Simulation ---");
        $display("-- data transfer stats (Key: data send index | value: Data sent) --");
        foreach(scoreboard_perf_ctr.data_transfer_assoc_array[key]) begin
            $display(" -key: %d   |   -value: %x", key, scoreboard_perf_ctr.data_transfer_assoc_array[key]);
        end
        $display("sender counter: %d   |   receiver counter: %d", scoreboard_perf_ctr.sender_count, scoreboard_perf_ctr.receiver_count);
    endtask : end_simulation

endmodule : ready_valid_tb_elements