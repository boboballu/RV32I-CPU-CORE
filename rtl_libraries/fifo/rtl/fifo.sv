//                                      PRRAMETRIZABLE FIFO DESIGN

//                                        +---------------+
//                       w_data +-------->+               +---------> r_data
//                                        +---------------+
//                                        |               |
//                                        +---------------+
//                                        |               |
//                                        +---------------+
//                                        |       .       |
//               +--------+        tail   |       .       |   head          +--------+
//   w_req +---->+ write  +<-------+------+       .       +------+--------->+ read   +<----+ r_req
//               | stall  |        |      |      fifo     |      |          | stall  |
//               |        +<---+   |      |       .       |      |    +---->+        |
// w_stall <-----+        |    |   |      +---------------+      |    |     |        +-----> r_stall
//               +--------+    |   |                             |    |     +--------+
//                             |   +----------------------------------+
//                             |                                 |
//                             +---------------------------------+

// head and tail are counters keeping track of the free entry in the fifo
// write_stall and read_stall modules raises full and empty condition
// head corresponds to read pointer's location
// tail corresponds to write pointer's location
// full condition   -> head ^ tail == (MSB == 'b1) and (rest other bits 1'b0);
// empty condition  -> head ^ tail == 0;


module fifo #(
    parameter ROWS  = 8,
    parameter type DATA_T = logic [7:0],
    
    //immutable - local params
    localparam ROW_ADDR_WIDTH = ($clog2(ROWS))
)
(
    input logic clk, reset_n,
    input logic w_req, r_req,
    input DATA_T w_data,
    output DATA_T r_data,
    output logic [ROW_ADDR_WIDTH-1:0] write_ptr, read_ptr,
    output logic w_stall, r_stall
);
    DATA_T MEM [ROWS-1:0];
    logic full, empty;
    logic [ROW_ADDR_WIDTH:0] head, tail;

    assign {read_ptr, write_ptr} = {head[ROW_ADDR_WIDTH-1:0], tail[ROW_ADDR_WIDTH-1:0]};
    assign w_stall  = full;
    assign r_stall  = empty;
    assign r_data   = ( r_req & (!empty) ) ? MEM[head[ROW_ADDR_WIDTH-1:0]] : 'b0;

    always_comb begin
        if ( (head ^ tail) == { 1'b1, {(ROW_ADDR_WIDTH){1'b0}} } ) begin : full_condition
            full = 1;
            empty = 0;
        end : full_condition

        else if ( (head ^ tail) == 'b0 ) begin : empty_condition
            full = 0;
            empty = 1;
        end : empty_condition

        else begin
            full = 0;
            empty = 0;
        end
    end

    always_ff @(posedge clk or negedge reset_n) begin
        if (!reset_n) begin
            MEM <= '{default:'b0};
            head <= 0;
            tail <= 0;
        end
        else begin
            if (!full) begin
                if (w_req) begin
                    MEM[tail[ROW_ADDR_WIDTH-1:0]] <= w_data;
                    if (tail[ROW_ADDR_WIDTH-1:0] == ROWS-1) begin
                        tail <= { {~tail[ROW_ADDR_WIDTH]}, {(ROW_ADDR_WIDTH){1'b0}} };
                    end
                    else begin
                        tail <= tail + 1;
                    end
                end
            end
            if (!empty) begin
                if (r_req) begin
                    if (head[ROW_ADDR_WIDTH-1:0] == ROWS-1) begin
                        head <= { {~head[ROW_ADDR_WIDTH]}, {(ROW_ADDR_WIDTH){1'b0}} };
                    end
                    else begin
                        head <= head + 1;
                    end
                end
            end
        end
    end
endmodule : fifo


module fifo_valid_ready_wrapper #(
    parameter ROWS  = 8,
    parameter type DATA_T = logic [7:0],

    //immutable - local params
    localparam ROW_ADDR_WIDTH = ($clog2(ROWS))
)

(
    // general signals
    input logic clk, reset_n,
    // "in" is connected module A that sends data
    
    valid_ready_if in,      // expects interface of type "valid_ready_if.out"
    output logic [ROW_ADDR_WIDTH-1:0] in_write_ptr, 
    // "out" is connected to module B that receives data
    
    valid_ready_if out,     // expects interface of type "valid_ready_if.in"
    output logic [ROW_ADDR_WIDTH-1:0] out_read_ptr
);

    logic w_stall, r_stall;
    fifo #(.ROWS(ROWS), .DATA_T(DATA_T)) fifo_inst (
        .clk(clk), .reset_n(reset_n),
        .w_req(in.valid), .r_req(out.ready),
        .w_data(in.data), .r_data(out.data),
        .write_ptr(in_write_ptr), .read_ptr(out_read_ptr),
        .w_stall(w_stall), .r_stall(r_stall)
    );

    assign in.ready = !w_stall;
    assign out.valid = !r_stall;

endmodule : fifo_valid_ready_wrapper