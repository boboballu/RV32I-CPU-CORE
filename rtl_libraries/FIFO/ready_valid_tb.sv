
module ready_valid_tb ();
    parameter DATA_WIDTH = 8;
    parameter PIPELINE_DEPTH = 3;

    typedef struct {
        bit valid;
        bit [DATA_WIDTH-1:0] data;
    } sender_t;

    typedef struct {
        bit ready;
    } receiver_t;

    logic clk, reset_n;
    
    logic A_valid, A_ready;
    logic [DATA_WIDTH-1:0] A_data;

    logic B_valid, B_ready;
    logic [DATA_WIDTH-1:0] B_data;

    // create 2 list of tests that will be driven by individual drivers by individual run tasks
    sender_t sender_testlist[$];
    receiver_t receiver_testlist[$];
    enum bit [3:0] {PERFECT_SENDER_RECEIVER, BUSY_RECEIVER, RANDOM} test_type;

    ready_valid_skid_pipeline #(.DATA_WIDTH(DATA_WIDTH), .PIPELINE_DEPTH(PIPELINE_DEPTH) ) DUT1 (
        .clk(clk), .reset_n(reset_n),

        // Driver module (module A for simplicity) signals
        .A_valid(A_valid),
        .A_data(A_data),
        .A_ready(A_ready),

        // Receiver module (Module B for simplicity) signals
        .B_valid(B_valid),
        .B_data(B_data),
        .B_ready(B_ready)
    );

    initial begin : defaults
        clk = 1; reset_n = 1;
        {A_valid, A_data} = {'b0, 'b0};
        B_ready = 0;
        #300 $finish;
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
        test_type = BUSY_RECEIVER;
        case (test_type)
            RANDOM: begin
                $display("------ Generating random sender and receiver test sequences ------");
                for (int i=0; i<=15; i++) begin
                    sender_testlist.push_back(sender_t'{$urandom_range(0,1), $urandom_range(0,255)});
                    receiver_testlist.push_back(receiver_t'{$urandom_range(0,1)});
                end
            end
            PERFECT_SENDER_RECEIVER: begin
                for (int i=0; i<=15; i++) begin
                    sender_testlist.push_back(sender_t'{1'b1, $urandom_range(0,255)});
                    receiver_testlist.push_back(receiver_t'{1'b1});
                end
            end
            BUSY_RECEIVER: begin
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
            join
        end
    end

    task sender_driver(logic valid, ready, logic [DATA_WIDTH-1:0] data);
        @(posedge clk);
        A_valid = #1 valid;
        if (A_valid && A_ready) begin
            A_data = #1 data;
        end
    endtask : sender_driver

    task run_sender_driver();
        static int index=0;
        if (index < sender_testlist.size()) begin
            sender_driver(sender_testlist[index].valid, A_ready, sender_testlist[index].data);
            casex ({A_valid, A_ready})
                2'b?1:  index = index + 1;
                default:  @(posedge clk);
            endcase
        end
        else
            @(posedge clk);
    endtask : run_sender_driver

    task run_receiver_driver();
        static int index=0;
        if (index < receiver_testlist.size()) begin
            B_ready = #1 receiver_testlist[index].ready;
            casex ({B_valid, B_ready})
                2'b1?:  index = index + 1;
                default:  @(posedge clk);
            endcase
        end
        else
            @(posedge clk);
    endtask : run_receiver_driver

endmodule : ready_valid_tb
