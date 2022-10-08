module valid_credit #(
    parameter DATA_WIDTH    = 8,
    parameter VALID_FFS     = 3,
    parameter CREDIT_FFS     = 2,

    //immutable params
    localparam FIFO_DEPTH   = VALID_FFS + CREDIT_FFS + 2,
    localparam CREDIT_CTR_MAX = FIFO_DEPTH,
    localparam CREDIT_CTR_SIZE = ($clog2(FIFO_DEPTH))
) (
    input clk, reset_n,

    // "in" is connected module A that sends data
    ready_valid_if in,  // expects interface of type "ready_valid_if.out"

    // "out" is connected to module B that receives data
    ready_valid_if out  // expects interface of type "ready_valid_if.in"
);

    struct {
        logic [CREDIT_CTR_SIZE-1:0] credit_ctr[1:0];
    } assertion_signals;

    logic [VALID_FFS-1:0] valid_ffs;
    logic [DATA_WIDTH-1:0] valid_data_ffs [VALID_FFS-1:0];

    logic [CREDIT_FFS-1:0] credit_ffs;
    logic [CREDIT_CTR_SIZE-1:0] credit_ctr;

    // in interface to valid_credit flip-flop connection
    logic in_to_ff_wire_valid;
    logic [DATA_WIDTH-1:0] in_to_ff_wire_data;
    logic ff_to_in_wire_credit;

    // out interface to valid_credit flip-flop connection
    logic fifo_to_out_wire_valid;
    logic [DATA_WIDTH-1:0] fifo_to_out_wire_data;
    logic out_to_fifo_wire_credit;

    ready_valid_if #(.DATA_WIDTH(DATA_WIDTH)) fifo_write_wire (clk, reset_n);
    ready_valid_if #(.DATA_WIDTH(DATA_WIDTH)) fifo_read_wire (clk, reset_n);

    // fifo output <-> valid_credit protocol connection
    assign fifo_to_out_wire_valid   = fifo_read_wire.valid;
    assign fifo_to_out_wire_data    = fifo_read_wire.data;
    assign out_to_fifo_wire_credit  = out.ready & fifo_read_wire.valid;;
    // valid_credit <-> receiver valid_ready connection
    assign out.valid                = fifo_to_out_wire_valid;
    assign out.data                 = fifo_to_out_wire_data;
    assign fifo_read_wire.ready     = out.ready;


    // sender valid_ready <-> valid_credit connection
    assign in_to_ff_wire_valid      = in.valid & (credit_ctr <= CREDIT_CTR_MAX-1);
    assign in_to_ff_wire_data       = in.data;
    assign ff_to_in_wire_credit     = credit_ffs[CREDIT_FFS-1];
    assign in.ready                 = (credit_ctr <= CREDIT_CTR_MAX-1);
    // valid_ffs <-> fifo input connectiom
    assign fifo_write_wire.valid    = valid_ffs[VALID_FFS-1];
    assign fifo_write_wire.data     = valid_data_ffs[VALID_FFS-1];



    fifo_ready_valid_wrapper #(.ROWS(FIFO_DEPTH), .COL_BIT_WIDTH(DATA_WIDTH)) skid_fifo (
        .clk(clk), .reset_n(reset_n),

        // "in" is connected module A that sends data
        .in(fifo_write_wire),    // expects interface of type "ready_valid_if.out"
        .in_write_ptr(),

        // "out" is connected to module B that receives data
        .out(fifo_read_wire),
        .out_read_ptr()                 // expects interface of type "ready_valid_if.in"
    );


    always_ff @(posedge clk or negedge reset_n) begin : update_credit_ctr
        if (!reset_n) begin
            credit_ctr <= '{default:'b0};
        end
        else begin
            casex({in.valid, ff_to_in_wire_credit})
                2'b01: begin
                    if (credit_ctr != 0) begin
                        credit_ctr <= credit_ctr - 1;
                    end
                    else begin
                        credit_ctr <= 0;
                    end
                end
                2'b10: begin
                    if (credit_ctr <= CREDIT_CTR_MAX-1) begin
                        credit_ctr <= credit_ctr + 1;
                    end
                end
                2'b11: begin
                    if (credit_ctr > CREDIT_CTR_MAX-1) begin
                        credit_ctr <= credit_ctr - 1;
                    end
                end
                default: credit_ctr <= credit_ctr;
            endcase
            assertion_signals.credit_ctr[0] <= credit_ctr;
            assertion_signals.credit_ctr[1] <= assertion_signals.credit_ctr[0];
            
            if (assertion_signals.credit_ctr[1] === CREDIT_CTR_MAX)
            FIFO_CTR_OVERFLOW : assert( (assertion_signals.credit_ctr[1] === CREDIT_CTR_MAX) ^ (fifo_write_wire.ready === 1'b0) == 1'b0 )
                                else $error("credit_ctr_2cb: %d | fifo_write_wire %b", assertion_signals.credit_ctr[1], fifo_write_wire.ready);
        end
    end : update_credit_ctr

    always_ff @(posedge clk or negedge reset_n) begin : valid_credit_ff_pipeline
        if (!reset_n) begin

            valid_ffs       <= '{default:'b0};
            valid_data_ffs  <= '{default:'b0};
            credit_ffs      <= '{default:'b0};
        end
        else begin
            for(int i=0; i<VALID_FFS; i++) begin
                if (i == 0) begin
                    valid_ffs[0]        <= in_to_ff_wire_valid;
                    valid_data_ffs[0]   <= in_to_ff_wire_data;
                end
                else begin
                    valid_ffs[i]        <= valid_ffs[i-1];
                    valid_data_ffs[i]   <= valid_data_ffs[i-1];
                end
            end

            for (int i=0; i <= CREDIT_FFS-1; i++) begin
                if (i == 0) begin
                    credit_ffs[0] <= out_to_fifo_wire_credit;
                end
                else begin
                    credit_ffs[i] <= credit_ffs[i-1];
                end
            end
        end
    end : valid_credit_ff_pipeline

endmodule : valid_credit