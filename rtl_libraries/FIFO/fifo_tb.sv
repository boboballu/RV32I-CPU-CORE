// Write_module and read_module functional models
// write_fm and read_fm contains:
// * the sequence vars
// * drivers for the respective modules
// * the sequence itself which can be loaded from the class constructor
// * run task which works like a sequence generator, driving the sequence passed

module fifo_tb ();
    parameter COL_BIT_WIDTH = 32;
    parameter ROWS          = 8;
    parameter ROW_ADDR_WIDTH = ($clog2(ROWS));

    typedef struct {
        bit w;
        bit r;
        bit [COL_BIT_WIDTH-1:0] w_data;
    } testcase_t;

    //int w_i=0, r_i=0;

    testcase_t testcase_list[$] = '{
        '{1'b1, 1'b0, 'd14},
        '{1'b1, 1'b0, 'd18},
        '{1'b1, 1'b0, 'd16},
        '{1'b0, 1'b1, 'd10},
        '{1'b1, 1'b1, 'd8},
        '{1'b1, 1'b0, 'd20},
        '{1'b1, 1'b0, 'd21},
        '{1'b1, 1'b0, 'd22},
        '{1'b1, 1'b0, 'd23},
        '{1'b1, 1'b0, 'd24},
        '{1'b1, 1'b0, 'd25},
        '{1'b0, 1'b1, 'd0},
        '{1'b0, 1'b1, 'd0},
        '{1'b0, 1'b1, 'd0},
        '{1'b0, 1'b1, 'd0},
        '{1'b0, 1'b1, 'd0},
        '{1'b0, 1'b1, 'd0},
        '{1'b0, 1'b1, 'd0},
        '{1'b1, 1'b1, 'd9}
    };

    logic clk, reset_n;
    logic w_req, r_req;
    logic [COL_BIT_WIDTH-1:0] w_data, r_data;
    logic [ROW_ADDR_WIDTH:0] head, tail;
    logic w_stall, r_stall;

    fifo #( .ROWS(ROWS), .COL_BIT_WIDTH(COL_BIT_WIDTH) ) DUT
    (
        .clk(clk), .reset_n(reset_n),
        .w_req(w_req), .r_req(r_req),
        .w_data(w_data), .r_data(r_data),
        .write_ptr(tail), .read_ptr(head),
        .w_stall(w_stall), .r_stall(r_stall)
    );

    ready_valid_skid_pipeline #(.DATA_WIDTH(8), .PIPELINE_DEPTH(1) ) DUT1 (
        .clk(clk), .reset_n(reset_n),

        // Driver module (module A for simplicity) signals
        .A_valid(A_valid),
        .A_data(A_data),
        .A_ready(A_ready),
        .A_write_ptr(),

        // Receiver module (Module B for simplicity) signals
        .B_valid(B_valid),
        .B_data(B_data),
        .B_ready(B_ready),
        .B_read_ptr()
    );

    initial begin : defaults
        clk = 1; reset_n = 1;

        w_req = 0; r_req = 0;
        w_data = 0;

        #300 $finish;
    end : defaults

    initial begin : dump_vars
        $dumpfile("fifo_tb.vcd");
        $dumpvars(0,fifo_tb);
    end : dump_vars

    always begin : clk_gen
        clk = #5 ~clk;
    end : clk_gen

    initial begin : reset_n_gen
        #5 reset_n = #1 0;
        #10 reset_n = #1 1;
    end : reset_n_gen

    initial begin : start_driver_threads
        #15;
        forever begin
            fork
                w_run_driver();
                r_run_driver();
            join
        end
    end : start_driver_threads

    task w_driver(
        input logic req,
        input logic [COL_BIT_WIDTH-1:0] data
    );
        @(posedge clk);
        w_req = req;
        if ( w_req ) begin
            if (!w_stall) begin
                w_data = #1 data;
            end
            else begin
                w_data = #1 'b0;
            end
        end
        else begin
            w_data = #1 'b0;
        end
    endtask : w_driver

    task w_run_driver();
        static int w_i=0;
        if (w_i < testcase_list.size()) begin
            w_driver(testcase_list[w_i].w, testcase_list[w_i].w_data);
            if (!w_stall)
                w_i = w_i + 1;
            else
                @(posedge clk);
        end
        else
            @(posedge clk);
    endtask : w_run_driver

    task r_run_driver();
        static int r_i=0;
        if (r_i < testcase_list.size()) begin
            r_req = testcase_list[r_i].r;
            if (!r_stall)
                r_i = r_i + 1;
            @(posedge clk);
        end
        else
            @(posedge clk);
    endtask : r_run_driver

endmodule : fifo_tb
