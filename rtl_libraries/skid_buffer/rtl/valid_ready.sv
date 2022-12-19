// this module is the ready-valid flow control protocol wrapper.
//                                skid buffer
//
//                 Interface Definition
//        +-------------------+------------------+
// +----> | valid             |            valid +----->
//        |          [IN]     |   [OUT]          |
// +----> | data              |            data  +----->
//        |                   |                  |
//        |(receiver modport) |  (sender modport)|
//        |                   |                  |
// <------+ ready             |            ready +<----+
//        |                   |                  |
//        +-------------------+------------------+
//
// sender                                                               receiver
// +---------+   [IN]+-------------------+------------------+[OUT]    +---------+
// |out.valid+-----> | sender_valid      |   receiver_valid +-------> | in.valid|
// |         |       |                   |                  |         |         |
// |out.data +-----> | sender_data       |   receiver_data  +-------> | in.data |
// |         |       |                   |                  |         |         |
// |         |       |                   |                  |         |         |
// |         |       |                   |                  |         |         |
// |out.ready| <-----+ sender_ready      |   receiver_ready | <-------+ in.ready|
// |         |       |                   |                  |         |         |
// +---------+       +-------------------+------------------+         +---------+
//
//                     <----------- Skid buffer Pipeline --------------->
// sender                                                                       receiver
//  ┌─────────┐       0                    valid                        15      ┌─────────┐
//  │out.valid├──────►┌─────────────────────────────────────────────────┬──────►│in.valid │
//  │         │       └─────────────────────────────────────────────────┘       │         │
//  │         │       0                    data                         15      │         │
//  │out.data ├──────►┌─────────────────────────────────────────────────┬──────►│in.data  │
//  │         │       └─────────────────────────────────────────────────┘       │         │
//  │         │       15                   ready                        0       │         │
//  │out.ready│◄──────┬─────────────────────────────────────────────────┐◄──────┤in.ready │
//  └─────────┘       └─────────────────────────────────────────────────┘       └─────────┘

module valid_ready_skid_pipeline
#(
    parameter PIPELINE_DEPTH = 3,
    parameter type DATA_T = logic [7:0]
    
    //immutable params
)
(
    // generic signals
    input logic clk, reset_n,
    
    // "in" is connected to module A that sends data
    valid_ready_if in,  // expects interface of type "valid_ready_if.out"
    
    // "out" is connected to module B that receives data
    valid_ready_if out  // expects interface of type "valid_ready_if.in"
);
    // Skid pipeline internals
    valid_ready_if #(.DATA_T(DATA_T)) SB_wire[PIPELINE_DEPTH-1:0](clk, reset_n);
    valid_ready_if #(.DATA_T(DATA_T)) in_wire(clk, reset_n);

    assign in_wire.valid = in.valid;
    assign in_wire.data = in.data;
    assign in.ready = in_wire.ready;

// (sender - Module A | receiver - Module B)
//   Module A               SB0                SB1                SB2                  Module B
// +---------+        [IN]+--------+        +--------+         +--------+[OUT]      +----------+
// |         |            |        | Valid0 |        | Valid1  |        |  Valid2   |          |
// |out.valid+----------> |        +------> |        +-------> |        +---------> |in.valid  |
// |         |            |        |        |        |         |        |           |          |
// |out.data +----------> |        +------> |        +-------> |        +---------> |in.data   |
// |         |            |        | data0  |        | data1   |        |  data2    |          |
// |         |            |        |        |        |         |        |           |          |
// |         |            |        |        |        |         |        |           |          |
// |out.ready<------------+        | <------+        | <-------+        | <---------+in.ready  |
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
            // put the initial [0]th skid buffer in for loop itself; this helps to keep track of all
            // generated gen_skid_fifo_[0 to PIPELINE_DEPTH-1]
            for (genvar i=0; i<=PIPELINE_DEPTH-1; i++) begin : gen_skid_fifo
                if (i == 0) begin
                    // At module A
                    fifo_valid_ready_wrapper #(.ROWS(2), .DATA_T(DATA_T)) skid_fifo (
                        .clk(clk), .reset_n(reset_n),                        
                        
                        // "in" is connected module A that sends data
                        .in(in_wire),           // expects interface of type "valid_ready_if.out"
                        .in_write_ptr(), 
                        
                        // "out" is connected to module B that receives data
                        .out(SB_wire[i]),
                        .out_read_ptr()         // expects interface of type "valid_ready_if.in"
                    );
                end
                else begin
                    fifo_valid_ready_wrapper #(.ROWS(2), .DATA_T(DATA_T)) skid_fifo (
                        .clk(clk), .reset_n(reset_n),
                        
                        // "in" is connected module A that sends data
                        .in(SB_wire[i-1]),      // expects interface of type "valid_ready_if.out"
                        .in_write_ptr(), 
                        
                        // "out" is connected to module B that receives data
                        .out(SB_wire[i]),       // expects interface of type "valid_ready_if.in"
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

endmodule : valid_ready_skid_pipeline