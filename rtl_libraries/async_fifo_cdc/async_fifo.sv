//                               PARAMETERIZABLE ASYNC FIFO DESIGN

//                                        +---------------+
//                       w_data +-------->+               +---------> r_data
//                                        +---------------+
//                  clk_sender  +-------->+               +<--------+ clk_receiver
//                                        +---------------+
//                                        |               |
//                                        +---------------+
//                                        |       .       |
//               +--------+        tail   |       .       |   head          +--------+
//   w_req +---->+ write  +<-------+------+       .       +------+--------->+ read   +<----+ r_req
//               | stall  |        |      |      fifo     |      |          | stall  |
//               |        +<---+   |      |       .       |      |       +->+        |
// w_stall <-----+        |    |   |      +---------------+      |       |  |        +-----> r_stall
//               +--------+    |   |                             |    ++ |  +--------+
//                             |   +-------------------------------------+
//                             | ++                              |    ++
//                             +---------------------------------+   m_ff_sync
//                               ++                                  (clk_receiver)
//                            m_ff_sync
//                            (clk_sender)

// head and tail are counters keeping track of the free entry in the fifo
// write_stall and read_stall modules raises full and empty condition
// head corresponds to read pointer's location
// tail corresponds to write pointer's location
// full condition   -> head ^ tail == (MSB == 'b1) and (rest other bits 1'b0);
// empty condition  -> head ^ tail == 0;

module async_fifo #(
    parameter ROWS  = 8,
    parameter COL_BIT_WIDTH = 32,
    parameter M_FF_SYNC_WIDTH = 2,
    //immutable - local params
    localparam ROW_ADDR_WIDTH = ($clog2(ROWS)),
    localparam POINTER_WIDTH = ROW_ADDR_WIDTH + 1
)
(
    input logic clk_sender, clk_receiver, reset_n,
    input logic w_req, r_req,
    input logic [COL_BIT_WIDTH-1:0] w_data,
    output logic [COL_BIT_WIDTH-1:0] r_data,
    output logic [POINTER_WIDTH-1:0] write_ptr, read_ptr,
    output logic w_stall, r_stall
);
    logic [COL_BIT_WIDTH-1:0] MEM [ROWS-1:0];
    logic full, empty;
    logic [POINTER_WIDTH-1:0] head, tail;

    // head and tail pointer sync wires across clock domain
    logic [POINTER_WIDTH-1:0] head_gray, tail_gray;
    logic [POINTER_WIDTH-1:0] head_gray_synced, tail_gray_synced;
    logic [POINTER_WIDTH-1:0] head_bin_synced, tail_bin_synced;

    // share head and tail pointers from sender and receiver to compute full and empty conditions.
    // share gray code between sender and receiver
    bin2gray #(.BIT_WIDTH(POINTER_WIDTH)) head_gray_at_receiver (.in_bin(head), .out_gray(head_gray));
    bin2gray #(.BIT_WIDTH(POINTER_WIDTH)) tail_gray_at_sender   (.in_bin(tail), .out_gray(tail_gray));

    m_ff_sync #(.M(M_FF_SYNC_WIDTH), .DATA_WIDTH(POINTER_WIDTH)) head_gray_receiver2sender (.clk(clk_sender),   .reset_n(reset_n), .Din(head_gray), .Dout(head_gray_synced) );
    m_ff_sync #(.M(M_FF_SYNC_WIDTH), .DATA_WIDTH(POINTER_WIDTH)) tail_gray_sender2receiver (.clk(clk_receiver), .reset_n(reset_n), .Din(tail_gray), .Dout(tail_gray_synced) );

    gray2bin #(.BIT_WIDTH(POINTER_WIDTH)) head_bin_at_sender    (.in_gray(head_gray_synced), .out_bin(head_bin_synced));
    gray2bin #(.BIT_WIDTH(POINTER_WIDTH)) tail_bin_at_receiver  (.in_gray(tail_gray_synced), .out_bin(tail_bin_synced));

    assign {read_ptr, write_ptr} = {head, tail};
    assign w_stall  = full;
    assign r_stall  = empty;
    assign r_data   = ( r_req & (!empty) ) ? MEM[head[ROW_ADDR_WIDTH-1:0]] : 'b0;

    always_comb begin : sender_side_full
        if ( (head_bin_synced ^ tail) == { 1'b1, {(ROW_ADDR_WIDTH-1){1'b0}} } ) begin : full_condition
            full = 1;
        end : full_condition
        else begin
            full = 0;
        end
    end : sender_side_full

    always_comb begin : receiver_side_empty
        if ( (head ^ tail_bin_synced) == 'b0 ) begin : empty_condition
            empty = 1;
        end : empty_condition
        else begin
            empty = 0;
        end
    end : receiver_side_empty

    always_ff @(posedge clk_sender or negedge reset_n) begin : sender_side
        if (!reset_n) begin
            MEM <= '{default:'b0};
            tail <= 0;
        end
        else begin
            if (!full) begin
                if (w_req) begin
                    MEM[tail[ROW_ADDR_WIDTH-1:0]] <= w_data;
                    tail <= tail + 1;
                end
            end
        end
    end : sender_side

    always_ff @(posedge clk_receiver or negedge reset_n) begin : receiver_side
        if (!reset_n) begin
            head <= 0;
        end
        else begin
            if (!empty) begin
                if (r_req) begin
                    head <= head + 1;
                end
            end
        end
    end : receiver_side
endmodule : async_fifo

module async_fifo_ready_valid_wrapper #(
    parameter ROWS  = 8,
    parameter COL_BIT_WIDTH = 32,
    parameter M_FF_SYNC_WIDTH = 2,

    //immutable - local params
    localparam ROW_ADDR_WIDTH = ($clog2(ROWS)),
    localparam POINTER_WIDTH = ROW_ADDR_WIDTH + 1
)

(
    // general signals
    input logic clk_sender, clk_receiver, reset_n,
    // "in" is connected module A that sends data
    
    ready_valid_if in,      // expects interface of type "ready_valid_if.out"
    output logic [POINTER_WIDTH-1:0] in_write_ptr, 
    // "out" is connected to module B that receives data
    
    ready_valid_if out,     // expects interface of type "ready_valid_if.in"
    output logic [POINTER_WIDTH-1:0] out_read_ptr
);

    logic w_stall, r_stall;
    async_fifo #(.ROWS(ROWS), .COL_BIT_WIDTH(COL_BIT_WIDTH), .M_FF_SYNC_WIDTH(M_FF_SYNC_WIDTH)) fifo_inst (
        .clk_sender(clk_sender), .clk_receiver(clk_receiver), .reset_n(reset_n),
        .w_req(in.valid), .r_req(out.ready),
        .w_data(in.data), .r_data(out.data),
        .write_ptr(in_write_ptr), .read_ptr(out_read_ptr),
        .w_stall(w_stall), .r_stall(r_stall)
    );

    assign in.ready = !w_stall;
    assign out.valid = !r_stall;

endmodule : async_fifo_ready_valid_wrapper