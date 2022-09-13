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
// | A_valid +-----> | sender_valid      |   receiver_valid +-------> | A_valid |
// |         |       |                   |                  |         |         |
// | A_data  +-----> | sender_data       |   receiver_data  +-------> | A_data  |
// |         |       |                   |                  |         |         |
// |         |       |                   |                  |         |         |
// |         |       |                   |                  |         |         |
// | A_ready | <-----+ sender_ready      |   receiver_ready | <-------+ A_ready |
// |         |       |                   |                  |         |         |
// +---------+       +-------------------+------------------+         +---------+
//
//                     <----------- Skid buffer Pipeline --------------->
//  ┌─────────┐       0                    valid                        15      ┌─────────┐
//  │  A_valid├──────►┌─────────────────────────────────────────────────┬──────►│B_valid  │
//  │         │       └─────────────────────────────────────────────────┘       │         │
//  │         │       0                    data                         15      │         │
//  │  A_data ├──────►┌─────────────────────────────────────────────────┬──────►│B_data   │
//  │         │       └─────────────────────────────────────────────────┘       │         │
//  │         │       15                   ready                        0       │         │
//  │  A_ready│◄──────┬─────────────────────────────────────────────────┐◄──────┤B_ready  │
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

    // Sender module (module A for simplicity) signals
    input logic A_valid,
    input logic [DATA_WIDTH-1:0] A_data,
    output logic A_ready,

    // Receiver module (Module B for simplicity) signals
    output logic B_valid,
    output logic [DATA_WIDTH-1:0] B_data,
    input logic B_ready
);
    // Skid pipeline internals
    logic [PIPELINE_DEPTH-1:0] valid, ready;
    logic [DATA_WIDTH-1:0] data [PIPELINE_DEPTH-1:0];

// (sender - Module A | receiver - Module B)
//   Module A               SB0                SB1                SB2                  Module B
// +---------+            +--------+        +--------+         +--------+           +----------+
// |         |            |        | Valid0 |        | Valid1  |        |  Valid2   |          |
// | A_valid +----------> |        +------> |        +-------> |        +---------> | B_valid  |
// |         |            |        |        |        |         |        |           |          |
// | A_data  +----------> |        +------> |        +-------> |        +---------> | B_data   |
// |         |            |        | data0  |        | data1   |        |  data2    |          |
// |         |            |        |        |        |         |        |           |          |
// |         |            |        |        |        |         |        |           |          |
// | A_ready <------------+        | <------+        | <-------+        | <---------+ B_ready  |
// |         |            |        | ready2 |        | ready1  |        |  ready0   |          |
// +---------+            +--------+        +--------+         +--------+           +----------+
// Direct wire connection                                                         SB2 to B_* wires are
// from A to SB0                                                                  assigned static assigned

    generate
        // if the pipeline depth is 0; ie, to skid buffers in-between
        if (PIPELINE_DEPTH == 0) begin : zero_pipeline_depth
            assign B_valid = A_valid;
            assign B_data = A_data;
            assign A_ready = B_ready;
        end : zero_pipeline_depth

        else begin : nonzero_pipeline_depth
            genvar i;
            for (i=0; i<=PIPELINE_DEPTH-1; i++) begin : gen_skid_fifo
                if (i == 0) begin
                    // At module A
                    fifo_ready_valid_wrapper #(.ROWS(2), .COL_BIT_WIDTH(DATA_WIDTH)) skid_fifo (
                        .clk(clk), .reset_n(reset_n),
                        
                        // Driver module (module A for simplicity) signals
                        .A_valid(A_valid), 
                        .A_data(A_data),
                        .A_ready(A_ready), 
                        .A_write_ptr(), 

                        // Receiver module (Module B for simplicity) signals
                        .B_valid(valid[i]),
                        .B_data(data[i]),
                        .B_ready(ready[PIPELINE_DEPTH-i-1]),
                        .B_read_ptr()
                    );
                end
                else begin
                    fifo_ready_valid_wrapper #(.ROWS(2), .COL_BIT_WIDTH(DATA_WIDTH)) skid_fifo (
                        .clk(clk), .reset_n(reset_n),
                    
                        // Driver module (module A for simplicity) signals
                        .A_valid(valid[i-1]), 
                        .A_data(data[i-1]),
                        .A_ready(ready[PIPELINE_DEPTH-i]), 
                        .A_write_ptr(), 

                        // Receiver module (Module B for simplicity) signals
                        .B_valid(valid[i]),
                        .B_data(data[i]),
                        .B_ready(ready[PIPELINE_DEPTH-i-1]),
                        .B_read_ptr()
                    );
                end
            end : gen_skid_fifo
            // At module B
            assign B_valid = valid[PIPELINE_DEPTH-1];
            assign B_data = data[PIPELINE_DEPTH-1];
            assign ready[0] = B_ready;
        end : nonzero_pipeline_depth

    endgenerate

endmodule