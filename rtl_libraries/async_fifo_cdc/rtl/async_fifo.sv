//                               PARAMETERIZABLE ASYNC FIFO DESIGN

//                                        +---------------+
//                       w_data +-------->+               +---------> r_data
//                                        +---------------+
//                  clk_sender  +-------->+               +<--------+ clk_receiver
//                                        +---------------+
//                                        |               |
//                                        +---------------+
//                                        |       .       |
//               +--------+          wp   |       .       |     rp          +--------+
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

// rp and wp are counters keeping track of the free entry in the fifo
// write_stall and read_stall modules raises full and empty condition
// rp corresponds to read pointer's location
// wp corresponds to write pointer's location
// full condition   -> rp ^ wp == (MSB == 2'b11) and (rest other bits 1'b0);
// empty condition  -> rp ^ wp == 0;

`include "bingray_generic_functions.svh"

module async_fifo #(
    parameter ROWS  = 8,
    parameter type DATA_T = logic [7:0],
    parameter M_FF_SYNC_WIDTH = 2,
    //--- immutable --- local params ---
    localparam ROW_ADDR_WIDTH = ($clog2(ROWS)),
    localparam POINTER_WIDTH = ROW_ADDR_WIDTH + 1,
    // fifo MEM address range (MIRROR limits gets mapped)
    localparam MEM_ADDR_LOW = ( (2**ROW_ADDR_WIDTH) - ROWS ) / 2,
    localparam MEM_ADDR_HIGH = MEM_ADDR_LOW + ROWS - 1,
    localparam MIRROR_MEM_ADDR_LOW = (2**ROW_ADDR_WIDTH) + ( (2**ROW_ADDR_WIDTH) - ROWS ) / 2,
    localparam MIRROR_MEM_ADDR_HIGH = MIRROR_MEM_ADDR_LOW + ROWS - 1
)
(
    input logic clk_sender, clk_receiver, sender_reset_n, receiver_reset_n,
    input logic w_req, r_req,
    input DATA_T w_data,
    output DATA_T r_data,
    // ----- output all possible pointer information ----
    // [1] The absolute pointer used by wp and rp counters
    output logic [POINTER_WIDTH-1:0] write_ptr_abs, read_ptr_abs,
    // [2] The absolute pointer without the wrap-arround MSB which is used to compute empty and full conditions
    output logic [ROW_ADDR_WIDTH-1:0] write_ptr, read_ptr,
    // [3] Pointer normalized to zero (starts from zero). This will be same as [2] for pow of 2 ROW sizes
    output logic [ROW_ADDR_WIDTH-1:0] write_ptr_norm, read_ptr_norm,
    // [4] Occupancy counter at sender and receiver side
    output logic [POINTER_WIDTH-1:0] write_occupancy_ctr, read_occupancy_ctr,
    output logic w_stall, r_stall
);
    DATA_T MEM [MEM_ADDR_HIGH:MEM_ADDR_LOW];
    logic full, empty;
    logic [POINTER_WIDTH-1:0] rp, wp;
    logic [POINTER_WIDTH-1:0] rp_wire, wp_wire;


    // rp and wp pointer sync wires across clock domain
    logic [POINTER_WIDTH-1:0] rp_gray, wp_gray;
    logic [POINTER_WIDTH-1:0] rp_gray_wire, wp_gray_wire;
    logic [POINTER_WIDTH-1:0] rp_gray_synced, wp_gray_synced;
    logic [POINTER_WIDTH-1:0] rp_bin_synced, wp_bin_synced;

    // share rp and wp pointers from sender and receiver to compute full and empty conditions.
    // share gray code between sender and receiver
    bin2gray #(.BIT_WIDTH(POINTER_WIDTH)) rp_gray_at_receiver (.in_bin(rp_wire), .out_gray(rp_gray_wire));
    bin2gray #(.BIT_WIDTH(POINTER_WIDTH)) wp_gray_at_sender   (.in_bin(wp_wire), .out_gray(wp_gray_wire));

    m_ff_sync #(.M(M_FF_SYNC_WIDTH), .DATA_WIDTH(POINTER_WIDTH)) rp_gray_receiver2sender (.clk(clk_sender),   .reset_n(1'b1), .Din(rp_gray), .Dout(rp_gray_synced) );
    m_ff_sync #(.M(M_FF_SYNC_WIDTH), .DATA_WIDTH(POINTER_WIDTH)) wp_gray_sender2receiver (.clk(clk_receiver), .reset_n(1'b1), .Din(wp_gray), .Dout(wp_gray_synced) );

    gray2bin #(.BIT_WIDTH(POINTER_WIDTH)) rp_bin_at_sender    (.in_gray(rp_gray_synced), .out_bin(rp_bin_synced));
    gray2bin #(.BIT_WIDTH(POINTER_WIDTH)) wp_bin_at_receiver  (.in_gray(wp_gray_synced), .out_bin(wp_bin_synced));

    assign {read_ptr_abs, write_ptr_abs}                = {rp, wp};
    assign read_ptr                                     = rp[POINTER_WIDTH-1] ? (MIRROR_MEM_ADDR_LOW - rp) : rp[ROW_ADDR_WIDTH-1:0];
    assign write_ptr                                    = wp[POINTER_WIDTH-1] ? (MIRROR_MEM_ADDR_LOW - wp) : wp[ROW_ADDR_WIDTH-1:0];
    assign read_ptr_norm                                = rp[POINTER_WIDTH-1] ? (read_ptr - MIRROR_MEM_ADDR_LOW)  : (read_ptr - MEM_ADDR_LOW);
    assign write_ptr_norm                               = wp[POINTER_WIDTH-1] ? (write_ptr - MIRROR_MEM_ADDR_LOW)  : (write_ptr - MEM_ADDR_LOW);

    // should fix the occupancy counter implementation
    assign write_occupancy_ctr                          = wp[POINTER_WIDTH-1] ^ rp_bin_synced[POINTER_WIDTH-1] ? wp - rp_bin_synced - ( (2**ROW_ADDR_WIDTH) - ROWS ) : wp - rp_bin_synced;
    assign read_occupancy_ctr                           = wp_bin_synced[POINTER_WIDTH-1] ^ rp[POINTER_WIDTH-1] ? wp_bin_synced - rp - ( (2**ROW_ADDR_WIDTH) - ROWS ) : wp_bin_synced - rp;

    assign w_stall  = full;
    assign r_stall  = empty;
    assign r_data   = ( r_req & (!empty) ) ? MEM[rp[ROW_ADDR_WIDTH-1:0]] : 'b0;

    initial begin : param_checker
        if (ROWS == 1) begin
            $display("rtl: async_fifo.sv: ROWS %d async fifo - unknown functionality; 1 not supported", ROWS);
            $finish();
        end
        // check if ROWS is power of 2
        else if (ROWS && ( (ROWS & (ROWS - 1)) == 0 ) ) begin
            $display("rtl: async_fifo.sv : ROWS = %d async_fifo - received a power of 2 size", ROWS);
        end
       
        // check if ROWS is even
        else if (ROWS % 2 == 0) begin
            $display("rtl: async_fifo.sv : ROWS %d async_fifo - received a even size", ROWS);
        end
        else begin
            $display("ROW size %d is odd | module doesnot support odd ROW sizes", ROWS);
            $finish();
        end
        $display("rtl: async_fifo.sv: MEM_ADDR_LOW = %d and MEM_ADDR_HIGH = %d", MEM_ADDR_LOW, MEM_ADDR_HIGH);
        $display("rtl: async_fifo.sv: MIRROR_MEM_ADDR_LOW = %d and MIRROR_MEM_ADDR_HIGH = %d", MIRROR_MEM_ADDR_LOW, MIRROR_MEM_ADDR_HIGH);
    end : param_checker


if (1) begin : sender_side_logic

    always_comb begin : sender_side_full
        // default condition
        full = 1'b0;
        if ( (rp_gray_synced ^ wp_gray) == { 2'b11, {(POINTER_WIDTH-2){1'b0}} } ) begin : full_condition
            full = 1'b1;
        end : full_condition
        else begin
            full = 1'b0;
        end
    end : sender_side_full

    always_comb begin : wp_counter
        // default condition
        wp_wire = wp + 1;
        if (wp == MEM_ADDR_HIGH) begin
            wp_wire = MIRROR_MEM_ADDR_LOW;
        end
        else if (wp == MIRROR_MEM_ADDR_HIGH) begin
            wp_wire = MEM_ADDR_LOW;
        end
        else begin
            wp_wire = wp + 1;
        end
    end : wp_counter
    
    always_ff @(posedge clk_sender or negedge sender_reset_n) begin : sender_side
        if (!sender_reset_n) begin
            MEM <= '{default:'b0};
            wp <= MEM_ADDR_LOW;
            wp_gray <= bin2gray_fun(MEM_ADDR_LOW);
        end
        else begin
            if (!full) begin
                if (w_req) begin
                    MEM[wp[ROW_ADDR_WIDTH-1:0]] <= w_data;
                    wp <= wp_wire;
                    wp_gray <= wp_gray_wire;
                end
            end
        end
    end : sender_side

end : sender_side_logic


if (1) begin : receiver_side_logic
    
    always_comb begin : receiver_side_empty
        // default condition
        empty = 1'b0;
        if ( rp_gray == wp_gray_synced ) begin : empty_condition
            empty = 1'b1;
        end : empty_condition
        else begin
            empty = 1'b0;
        end
    end : receiver_side_empty

    always_comb begin : rp_counter
        // default condition
        rp_wire = rp + 1;
        if (rp == MEM_ADDR_HIGH) begin
            rp_wire = MIRROR_MEM_ADDR_LOW;
        end
        else if (rp == MIRROR_MEM_ADDR_HIGH) begin
            rp_wire = MEM_ADDR_LOW;
        end
        else begin
            rp_wire = rp + 1;
        end
    end : rp_counter
    
    always_ff @(posedge clk_receiver or negedge receiver_reset_n) begin : receiver_side
        if (!receiver_reset_n) begin
            rp <= MEM_ADDR_LOW;
            rp_gray <= bin2gray_fun(MEM_ADDR_LOW);
        end
        else begin
            if (!empty) begin
                if (r_req) begin
                    rp <= rp_wire;
                    rp_gray <= rp_gray_wire;
                end
            end
        end
    end : receiver_side

end : receiver_side_logic

endmodule : async_fifo

module async_fifo_valid_ready_wrapper #(
    parameter ROWS  = 8,
    parameter type DATA_T = logic [7:0],
    parameter M_FF_SYNC_WIDTH = 2,

    //immutable - local params
    localparam ROW_ADDR_WIDTH = ($clog2(ROWS)),
    localparam POINTER_WIDTH = ROW_ADDR_WIDTH + 1
)

(
    // general signals
    input logic clk_sender, clk_receiver, sender_reset_n, receiver_reset_n,
    // "in" is connected module A that sends data
    
    valid_ready_if in,      // expects interface of type "valid_ready_if.out"
    output logic [ROW_ADDR_WIDTH-1:0] in_write_ptr, 
    // "out" is connected to module B that receives data
    
    valid_ready_if out,     // expects interface of type "valid_ready_if.in"
    output logic [ROW_ADDR_WIDTH-1:0] out_read_ptr
);

    logic w_stall, r_stall;
    
    async_fifo #(.ROWS(ROWS), .DATA_T(DATA_T), .M_FF_SYNC_WIDTH(M_FF_SYNC_WIDTH)) fifo_inst (
        .clk_sender(clk_sender), .clk_receiver(clk_receiver), .sender_reset_n(sender_reset_n), .receiver_reset_n(receiver_reset_n),
        .w_req(in.valid), .r_req(out.ready),
        .w_data(in.data), .r_data(out.data),
        .write_ptr(in_write_ptr), .read_ptr(out_read_ptr),
        .w_stall(w_stall), .r_stall(r_stall)
    );

    assign in.ready = !w_stall;
    assign out.valid = !r_stall;

endmodule : async_fifo_valid_ready_wrapper


module async_fifo_reset_gen #(
    parameter M_FF_SYNC_WIDTH = 2
    ) (
    input logic clk_sender, clk_receiver, async_reset_n, 
    output logic sender_reset_n, receiver_reset_n
    );

    logic sender_reset_flop, receiver_reset_flop;
    logic sender_reset_synced, receiver_reset_synced;
    logic receiver_reset_loopback;
    logic sender_reset_from_receiver; // at the time of this signal assert, the ff syncs will have stable value.

    assign receiver_reset_n = receiver_reset_synced & receiver_reset_loopback;
    assign sender_reset_n   = sender_reset_synced & sender_reset_flop;

    reset_sync sender_reset_A (.clk(clk_sender), .async_reset_n(async_reset_n), .sync_reset_n(sender_reset_synced));
    reset_sync receiver_reset_B (.clk(clk_receiver), .async_reset_n(async_reset_n), .sync_reset_n(receiver_reset_synced));

    m_ff_sync #(.M(M_FF_SYNC_WIDTH), .DATA_WIDTH(1)) receiver2sender_reset (.clk(clk_sender), .reset_n(receiver_reset_synced), .Din(async_reset_n), .Dout(sender_reset_from_receiver) );
    m_ff_sync #(.M(M_FF_SYNC_WIDTH), .DATA_WIDTH(1)) sender2receiver_reset_loopback (.clk(clk_receiver),   .reset_n(sender_reset_synced), .Din(sender_reset_flop), .Dout(receiver_reset_loopback) );

    always_ff@(posedge clk_sender or negedge sender_reset_synced) begin
        if (!sender_reset_synced)
            sender_reset_flop <= 1'b0;
        else
            sender_reset_flop <= sender_reset_from_receiver;
    end

    always_ff@(posedge clk_receiver or negedge receiver_reset_synced) begin
        if (!receiver_reset_synced)
            receiver_reset_flop <= 1'b0;
        else
            receiver_reset_flop <= receiver_reset_synced;
    end

endmodule : async_fifo_reset_gen

module async_fifo_valid_ready_wrapper_w_reset_gen #(
    parameter ROWS  = 8,
    parameter type DATA_T = logic [7:0],
    parameter M_FF_SYNC_WIDTH = 2,

    //immutable - local params
    localparam ROW_ADDR_WIDTH = ($clog2(ROWS)),
    localparam POINTER_WIDTH = ROW_ADDR_WIDTH + 1
) (
    // general signals
    input logic clk_sender, clk_receiver, async_reset_n,
    // "in" is connected module A that sends data
    
    valid_ready_if in,      // expects interface of type "valid_ready_if.out"
    output logic [ROW_ADDR_WIDTH-1:0] in_write_ptr, 
    // "out" is connected to module B that receives data
    
    valid_ready_if out,     // expects interface of type "valid_ready_if.in"
    output logic [ROW_ADDR_WIDTH-1:0] out_read_ptr
);

    async_fifo_reset_gen #(.M_FF_SYNC_WIDTH(M_FF_SYNC_WIDTH)) async_fifo_reset_gen (.clk_sender(clk_sender), .clk_receiver(clk_receiver), .async_reset_n(async_reset_n), .sender_reset_n(sender_reset_n), .receiver_reset_n(receiver_reset_n));

    async_fifo_valid_ready_wrapper #(.DATA_T(DATA_T), .ROWS(ROWS), .M_FF_SYNC_WIDTH(M_FF_SYNC_WIDTH) ) async_fifo_valid_ready_wrapper (
        .clk_sender(clk_sender), .clk_receiver(clk_receiver), .sender_reset_n(sender_reset_n), .receiver_reset_n(receiver_reset_n),

        // "in" is connected module A that sends data
        .in(sender_A.out),      // expects interface of type "valid_ready_if.out"
        .in_write_ptr(sender_A_write_ptr),

        // "out" is connected to module B that receives data
        .out(receiver_B.in),    // expects interface of type "valid_ready_if.in"
        .out_read_ptr(receiver_B_read_ptr)
    );


endmodule : async_fifo_valid_ready_wrapper_w_reset_gen