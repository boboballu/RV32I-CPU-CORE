module test();

    logic clk_sender, clk_receiver;
    int sender_ct = 0, receiver_ct = 0;

    initial begin
        clk_sender = 1;
        clk_receiver = 1;
    end

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

    task t1();
        @(posedge clk_sender);
        sender_ct++;
        $display("Time %0t | sender_ct %d", $time, sender_ct);
    endtask

    task t2();
        @(posedge clk_receiver);
        receiver_ct++;
        $display("Time %0t | receiver_ct %d", $time, receiver_ct);
    endtask

    initial begin
        forever begin
            fork
                t1();
                t2();
            join_any
            begin
                if (sender_ct == 20) begin
                    $finish;
                end
            end
        end
    end
endmodule