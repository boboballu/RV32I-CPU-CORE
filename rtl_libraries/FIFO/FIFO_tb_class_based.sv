
// Write_module and read_module functional models
// write_fm and read_fm contains: 
// * the sequence vars
// * drivers for the respective modules
// * the sequence itself which can be loaded from the class constructor
// * run task which works like a sequence generator, driving the sequence passed

class write_fm #(parameter BIT_WIDTH);
    bit trace_w_req; // puts a write request and writes the w_data if high
    bit [BIT_WIDTH-1:0] trace_data;
    
    // typedef struct {
    //     bit w; // puts a write request and writes the w_data if high
    //     bit [BIT_WIDTH-1:0] data;
    // } trace_t;

    // trace_t trace_sequence[$] = '{
    //     '{1'b1, 'd14},
    //     '{1'b1, 'd18},
    //     '{1'b1, 'd16},
    //     '{1'b0, 'd10},
    //     '{1'b1, 'd8},
    //     '{1'b1, 'd9}
    // };

    function new (bit w, bit [BIT_WIDTH-1:0] data);
        this.trace_w_req = w;
        this.trace_data = data;
    endfunction : new

    static function create(bit w, bit [BIT_WIDTH-1:0] data);
        create = new(w, data);
    endfunction : creates
    
    task driver(
        input logic clk,
        input logic w_stall,
        output logic w_req,
        output logic [BIT_WIDTH-1:0] w_data
        );

        w_req = this.trace_w_req;
        if ( w_req ) begin
            if (!w_stall) begin
                w_data = this.trace_data;
            end
            else begin
                w_data = 'b0;
            end
        end
        else begin
            w_data = 'b0;
        end

        @(posedge clk);
    endtask : driver

    task run(
        input logic clk,
        input logic w_stall,
        output logic w_req,
        output logic [BIT_WIDTH-1:0] w_data
        );
        
        static int w_i=0;
        if (w_i < trace_sequence.size()) begin
            if (!w_stall)
                this.trace_w_req    = trace_sequence[w_i].w; 
                this.trace_data     = trace_sequence[w_i].data
                this.driver(.clk(clk), .w_stall(w_stall), .w_req(w_req), w_data(w_data));
                w_i = w_i + 1;
            else
                @(posedge clk);
        end
        else
            @(posedge clk);
    endtask : run
endclass : write_fm

class read_fm #(parameter BIT_WIDTH);
    bit trace_r_req;
    
    // typedef struct {
    //     bit r;
    // } trace_t;
    
    // trace_t trace_sequence[$] = '{
    //     '{1'b1},
    //     '{1'b1},
    //     '{1'b1},
    //     '{1'b0},
    //     '{1'b1},
    //     '{1'b1}
    // };

    function new (bit r);
        this.trace_r_req = r;
    endfunction : new

    task r_driver (
        input logic clk,
        output logic r_req
        );
        r_req = this.trace_r_req;
    endtask : r_driver

    task run (input logic clk, 
        output logic r_req);

        static int r_i;
        if (r_i < read_sequence_list.size()) begin
            r_req = read_sequence_list[r_i].r;
            if (!r_stall)
                r_i = r_i + 1;
            @(posedge clk);
        end
        else
            @(posedge clk);
    end
endclass : read_fm

typedef struct {
    bit w; 
    bit r;
    bit [COL_BIT_WIDTH-1:0] w_data;
} testcase_t;

int w_i=0, r_i=0;

testcase_t testcase_list[$] = '{
    '{1'b1, 1'b0, 'd14},
    '{1'b1, 1'b0, 'd18},
    '{1'b1, 1'b0, 'd16},
    '{1'b0, 1'b1, 'd10},
    '{1'b1, 1'b1, 'd8},
    '{1'b1, 1'b1, 'd9}   
};


// task w_driver(
//     input logic req,
//     input logic [COL_BIT_WIDTH-1:0] data
//     );

//     @(posedge clk);
//     w_req = req;
//     if ( w_req ) begin
//         if (!w_stall) begin
//             w_data = data;
//         end
//         else begin
//             w_data = 'b0;
//         end
//     end
//     else begin
//         w_data = 'b0;
//     end
// endtask : w_driver

write_fm write_testcase_list = '{
    write_fm::create(1, 14),
    write_fm::create(1, 18),
    write_fm::create(1, 16),
    write_fm::create(0, 10),
    write_fm::create(1, 8),
    write_fm::create(1, 9)
};

read_fm read_testcase_list = '{
    read_fm::create1(1),
    read_fm::create1(1),
    read_fm::create1(1),
    read_fm::create1(0),
    read_fm::create1(1),
    read_fm::create1(1)
};

module fifo_tb ();
    parameter COL_BIT_WIDTH = 32;
    parameter ROWS          = 8;
    parameter ROW_ADDR_WIDTH = ($clog2(ROWS));

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
        .head(head), .tail(tail),
        .w_stall(w_stall), .r_stall(r_stall)
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
        #5 reset_n = 0;
        #10 reset_n = 1;
    end : reset_n_gen

    initial begin
        #15; 
        forever begin
            if (reset_n) begin
                fork
                    begin
                        if (w_i < testcase_list.size()) begin
                            w_driver(testcase_list[w_i].w, testcase_list[w_i].w_data);
                            if (!w_stall)
                                w_i = w_i + 1;
                            else
                                @(posedge clk);
                        end
                        else
                            @(posedge clk);
                    end

                    begin
                        if (r_i < testcase_list.size()) begin
                            r_req = testcase_list[r_i].r;
                            if (!r_stall)
                                r_i = r_i + 1;
                            @(posedge clk);
                        end
                        else
                            @(posedge clk);
                    end
                join
            end
            else begin
                @(posedge clk);
            end
        end
    end
                   

    
    // task r_receiver(
    //     input logic req;
    // ); 
    //     r_req = req
    //     if( r_req ) begin
    //         if (!r_stall) begin

endmodule : fifo_tb 