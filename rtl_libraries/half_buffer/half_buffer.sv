module half_buffer #(
    parameter DATA_WIDTH = 8
) (
    input logic clk, reset_n,
    
    input logic valid_in, input logic [DATA_WIDTH-1:0] data_in,
    output logic ready_in,

    output logic valid_out, logic [DATA_WIDTH-1:0] data_out,
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

module hb_ready_valid_wrapper #(
    parameter DATA_WIDTH = 8
)
(
    // general signals
    input logic clk, reset_n,
    // "in" is connected module A that sends data

    ready_valid_if in,      // expects interface of type "ready_valid_if.out"

    ready_valid_if out      // expects interface of type "ready_valid_if.in"
);

    logic w_stall, r_stall;
    half_buffer #(.DATA_WIDTH(DATA_WIDTH)) hb (
        .clk(clk), .reset_n(reset_n),
        .valid_in(in.valid), .ready_in(in.ready),
        .data_in(in.data),
        .valid_out(out.valid), .ready_out(out.ready),
        .data_out(out.data)
    );

endmodule : hb_ready_valid_wrapper