// this module is the ready-valid flow control protocol wrapper.
//                                skid buffer
//
//                 Interface Definition
//        +-------------------+------------------+
// +----> | valid             |            valid +----->
//        |                   |                  |
// +----> | data              |            data  +----->
//        |                   |                  |
//        |(receiver modport) |  (sender modport)|
//        |                   |                  |
// <------+ ready             |            ready +<----+
//        |                   |                  |
//        +-------------------+------------------+
//
// +---------+       +-------------------+------------------+         +---------+
// |in.valid +-----> | sender_valid      |   receiver_valid +-------> | in.valid|
// |         |       |                   |                  |         |         |
// |in.data  +-----> | sender_data       |   receiver_data  +-------> | in.data |
// |         |       |                   |                  |         |         |
// |         |       |                   |                  |         |         |
// |         |       |                   |                  |         |         |
// |in.ready | <-----+ sender_ready      |   receiver_ready | <-------+ in.ready|
// |         |       |                   |                  |         |         |
// +---------+       +-------------------+------------------+         +---------+
//
//                     <----------- Skid buffer Pipeline --------------->
//  ┌─────────┐       0                    valid                        15      ┌─────────┐
//  │in.valid ├──────►┌─────────────────────────────────────────────────┬──────►│out.valid│
//  │         │       └─────────────────────────────────────────────────┘       │         │
//  │         │       0                    data                         15      │         │
//  │in.data  ├──────►┌─────────────────────────────────────────────────┬──────►│out.data │
//  │         │       └─────────────────────────────────────────────────┘       │         │
//  │         │       15                   ready                        0       │         │
//  │ in.ready│◄──────┬─────────────────────────────────────────────────┐◄──────┤out.ready│
//  └─────────┘       └─────────────────────────────────────────────────┘       └─────────┘

module ready_valid_skid_pipeline
#(
    parameter DATA_WIDTH = 8,
    parameter PIPELINE_DEPTH = 3

    //immutable params
)
(
    // generic signals
    input logic clk, reset_n,
    
    // "in" is connected module A that sends data
    ready_valid_if in,  // expects interface of type "ready_valid_if.out"
    
    // "out" is connected to module B that receives data
    ready_valid_if out  // expects interface of type "ready_valid_if.in"
);
    // Skid pipeline internals
    // logic [PIPELINE_DEPTH-1:0] valid, ready;
    // logic [DATA_WIDTH-1:0] data [PIPELINE_DEPTH-1:0];
    ready_valid_if #(.DATA_WIDTH(DATA_WIDTH)) SB_wire[PIPELINE_DEPTH-1:0](clk, reset_n);
    ready_valid_if #(.DATA_WIDTH(DATA_WIDTH)) in_wire(clk, reset_n);

    assign in_wire.valid = in.valid;
    assign in_wire.data = in.data;
    assign in.ready = in_wire.ready;

// (sender - Module A | receiver - Module B)
//   Module A               SB0                SB1                SB2                  Module B
// +---------+            +--------+        +--------+         +--------+           +----------+
// |         |            |        | Valid0 |        | Valid1  |        |  Valid2   |          |
// |in.valid +----------> |        +------> |        +-------> |        +---------> | out.valid|
// |         |            |        |        |        |         |        |           |          |
// |in.data  +----------> |        +------> |        +-------> |        +---------> | out.data |
// |         |            |        | data0  |        | data1   |        |  data2    |          |
// |         |            |        |        |        |         |        |           |          |
// |         |            |        |        |        |         |        |           |          |
// |in.ready <------------+        | <------+        | <-------+        | <---------+ out.ready|
// |         |            |        | ready2 |        | ready1  |        |  ready0   |          |
// +---------+            +--------+        +--------+         +--------+           +----------+
// Direct wire connection                                                         SB2 to B_* wires are
// from A to SB0                                                                  assigned static assigned

    generate
        // if the pipeline depth is 0; ie, to skid buffers in-between
        if (PIPELINE_DEPTH == 0) begin : zero_pipeline_depth
            assign out.valid = in.valid;
            assign out.data = in.data;
            assign in.ready = out.ready;
        end : zero_pipeline_depth

        else begin : nonzero_pipeline_depth
            // genvar i; // genvar should only be used in "for" loops; cannot be initialized
            for (genvar i=0; i<=PIPELINE_DEPTH-1; i++) begin : gen_skid_fifo
                if (i == 0) begin
                    // At module A
                    fifo_ready_valid_wrapper #(.ROWS(2), .COL_BIT_WIDTH(DATA_WIDTH)) skid_fifo (
                        .clk(clk), .reset_n(reset_n),                        
                        
                        // "in" is connected module A that sends data
                        .in(in_wire),           // expects interface of type "ready_valid_if.out"
                        .in_write_ptr(), 
                        
                        // "out" is connected to module B that receives data
                        .out(SB_wire[i]),
                        .out_read_ptr()         // expects interface of type "ready_valid_if.in"
                    );
                end
                else begin
                    fifo_ready_valid_wrapper #(.ROWS(2), .COL_BIT_WIDTH(DATA_WIDTH)) skid_fifo (
                        .clk(clk), .reset_n(reset_n),
                        
                        // "in" is connected module A that sends data
                        .in(SB_wire[i-1]),      // expects interface of type "ready_valid_if.out"
                        .in_write_ptr(), 
                        
                        // "out" is connected to module B that receives data
                        .out(SB_wire[i]),       // expects interface of type "ready_valid_if.in"
                        .out_read_ptr()
                    );
                end
            end : gen_skid_fifo
            // At module B
            assign out.valid = SB_wire[PIPELINE_DEPTH-1].valid;
            assign out.data = SB_wire[PIPELINE_DEPTH-1].data;
            assign SB_wire[PIPELINE_DEPTH-1].ready = out.ready;
        end : nonzero_pipeline_depth

    endgenerate

endmodule