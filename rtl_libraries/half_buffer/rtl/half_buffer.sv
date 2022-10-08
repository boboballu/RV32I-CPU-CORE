// half buffer state machine
//
//                           valid_in=0
//                          +-------+
//                          |       |
//                          |       v
//                     +----+-------+---+
//                     |                |
//                     | valid_out = 0  |
//              +----->+ ready_in = 1   +------+
//              |      |                |      |
//              |      |     EMPTY      |      |
//              |      |                |      |
//              |      +----------------+      |
//              |                              | valid_in=1
// ready_out=1  |                              |
//              |                              |
//              |                              |
//              |      +----------------+      |
//              |      |                |      |
//              |      | valid_out = 1  |      |
//              +------+ reafy_in = 0   +<-----+
//                     |                |
//                     |     FULL       |
//                     |                |
//                     +----+-------+---+
//                          ^       |
//                          |       |
//                          +-------+
//                           ready_out=0

module half_buffer #(
    type DATA_T = logic [7:0]
) (
    input logic clk, reset_n,
    
    input logic valid_in, input DATA_T data_in,
    output logic ready_in,

    output logic valid_out, output DATA_T data_out,
    input logic ready_out
);

    // state_present is reg
    // state_next is wire
    enum logic[0:0] {EMPTY=1'b0, FULL=1'b1} state_present, state_next;

    always_comb begin
        casex(state_present)
            EMPTY: begin
                valid_out  = 1'b0;
                ready_in = 1'b1;
                if (valid_in == 1'b1)
                    state_next = FULL;
                else
                    state_next = EMPTY;
            end
            FULL: begin
                valid_out = 1'b1;
                ready_in = 1'b0;
                if (ready_out == 1'b1)
                    state_next = EMPTY;
                else
                    state_next = FULL;
            end
            default: state_next = EMPTY;
        endcase
    end

    always_ff @(posedge clk or negedge reset_n) begin
        if (!reset_n) begin
            state_present <= EMPTY;
            data_out <= '{default:'b0};
        end
        else begin
            state_present <= state_next;
            if ( (state_present == EMPTY ) && (valid_in) ) begin
                data_out <= data_in;
            end
        end
    end
endmodule : half_buffer

module hb_valid_ready_wrapper #(
    type DATA_T = logic [7:0]
)
(
    // general signals
    input logic clk, reset_n,
    // "in" is connected module A that sends data

    valid_ready_if in,      // expects interface of type "valid_ready_if.out"

    valid_ready_if out      // expects interface of type "valid_ready_if.in"
);

    logic w_stall, r_stall;
    half_buffer #(.DATA_T(DATA_T)) hb (
        .clk(clk), .reset_n(reset_n),
        .valid_in(in.valid), .ready_in(in.ready),
        .data_in(in.data),
        .valid_out(out.valid), .ready_out(out.ready),
        .data_out(out.data)
    );

endmodule : hb_valid_ready_wrapper