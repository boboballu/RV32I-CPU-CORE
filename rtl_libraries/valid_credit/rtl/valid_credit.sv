//                                                                                                                                  fifo
// +-------------+        +------------------------------------------------------+       +-----+      +-----+      +-----+       +----------------------+       +-----------+
// |             |        |                                                      |       |     |      |     |      |     |       |                      |       |           |
// |             |        |                                           out.valid  +------>+     +----->+     +----->+     +------>+ in.ready   out.ready +------>+  in.valid |
// |  out.valid  +------->+ in.valid                                             |       |     |      |     |      |     |       |                      |       |           |
// |             |        |                                                      |       +-----+      +-----+      +-----+       |                      |       |           |
// |             |        |  +----------------------------------+                |       valid_ff0    valid_ff1    valid_ff2     |                      |       |           |
// |             |        |  | credit_ctr                       |                |                                               |                      |       |           |
// |             |        |  | * max_count = 7                  |                |                                               |                      |       |           |
// |             |        |  | * min_count = 0                  |                |                                               |                      |       |           |
// |             |        |  | case(in.valid, out.credit)       |                |                                               |                      |       |           |
// |             |        |  |  * 01: decrement if not 0        |                |                                               |                      |       |           |
// |             |        |  |  * 10: increment if <= max-1     |                |                                               |                      |       |           |
// |             |        |  |  * 11: decrement gt max-1        |                |      +-----+                 +-----+          |                      |       |           |
// |             |        |  +----------------------------------+                |      |     |                 |     |          |                      |       |           |
// |  out.ready  +<-------+ in.ready                                 out.credit  +<-----+     +<----------------+     +<---------+ in.credit  out.ready +<------+  in.ready |
// |             |        |                                                      |      |     |                 |     |          |                      |       |           |
// +-------------+        +------------------------------------------------------+      +-----+                 +-----+          +----------------------+       +-----------+
//                                                                                      credit_ff1              credit_ff0



module valid_credit #(
    parameter type DATA_T = logic [7:0],
    parameter VALID_FFS     = 3,
    parameter CREDIT_FFS    = 2,
    //immutable params
    localparam FIFO_DEPTH   = VALID_FFS + CREDIT_FFS + 2,
    localparam CREDIT_CTR_MAX = FIFO_DEPTH,
    localparam CREDIT_CTR_SIZE = ($clog2(CREDIT_CTR_MAX+1)) // requires +1 since the counter which "CAN" from 0 to 2^n
) (
    input clk, reset_n,

    // "in" is connected module A that sends data
    valid_ready_if in,  // expects interface of type "valid_ready_if.out"

    // "out" is connected to module B that receives data
    valid_ready_if out, // expects interface of type "valid_ready_if.in"

    output logic [CREDIT_CTR_SIZE-1:0] credit_ctr
);

    // parameter checker - checks and prepares the parameters
    initial begin : parameter_checker
        $display (" rtl: valid_credit.sv : ---- parameters check ----");
        $display (" rtl: valid_credit.sv : VALID_FFS %d | CREDIT_FFS %d", VALID_FFS, CREDIT_FFS);
        $display (" rtl: valid_credit.sv : FIFO_DEPTH %d | CREDIT_CTR_MAX %d | CREDIT_CTR_SIZE %d", FIFO_DEPTH, CREDIT_CTR_MAX, CREDIT_CTR_SIZE);
    end : parameter_checker

    struct {
        logic [CREDIT_CTR_SIZE-1:0] credit_ctr[VALID_FFS-1:0];
        logic fifo_write_wire_ready_ff;
    } assertion_signals;

    // ff pipe stages for valid, valid_data dnd credit signals. Ignored if VALID_FFS or CREDIT_FFS is 0 (not used)
    logic [VALID_FFS-1:0] valid_ffs;
    DATA_T [VALID_FFS-1:0] valid_data_ffs;

    logic [CREDIT_FFS-1:0] credit_ffs;

    // in interface to valid_credit flip-flop connection
    logic in_to_ff_wire_valid;
    DATA_T in_to_ff_wire_data;
    logic ff_to_in_wire_credit;

    // out interface to valid_credit flip-flop connection
    logic fifo_to_out_wire_valid;
    DATA_T fifo_to_out_wire_data;
    logic out_to_fifo_wire_credit;

    valid_ready_if #(.DATA_T(DATA_T)) fifo_write_wire (clk, reset_n);
    valid_ready_if #(.DATA_T(DATA_T)) fifo_read_wire (clk, reset_n);

    // fifo output <-> valid_credit protocol connection
    assign fifo_to_out_wire_valid   = fifo_read_wire.valid;
    assign fifo_to_out_wire_data    = fifo_read_wire.data;
    assign out_to_fifo_wire_credit  = out.ready & fifo_read_wire.valid;
    // valid_credit <-> receiver valid_ready connection
    assign out.valid                = fifo_to_out_wire_valid;
    assign out.data                 = fifo_to_out_wire_data;
    assign fifo_read_wire.ready     = out.ready;

    // sender valid_ready <-> valid_credit connection
    assign in_to_ff_wire_valid      = in.valid & (credit_ctr <= CREDIT_CTR_MAX-1);
    assign in_to_ff_wire_data       = in.data;
    assign ff_to_in_wire_credit     = (CREDIT_FFS == 0) ? out_to_fifo_wire_credit : credit_ffs[CREDIT_FFS-1];
    assign in.ready                 = (credit_ctr <= CREDIT_CTR_MAX-1);
    // valid_ffs <-> fifo input connectiom
    assign fifo_write_wire.valid    = (VALID_FFS == 0) ? in_to_ff_wire_valid : valid_ffs[VALID_FFS-1];
    assign fifo_write_wire.data     = (VALID_FFS == 0) ? in_to_ff_wire_data : valid_data_ffs[VALID_FFS-1];

    fifo_valid_ready_wrapper #(.ROWS(FIFO_DEPTH), .DATA_T(DATA_T)) skid_fifo (
        .clk(clk), .reset_n(reset_n),

        // "in" is connected module A that sends data
        .in(fifo_write_wire),    // expects interface of type "valid_ready_if.out"
        .in_write_ptr(),

        // "out" is connected to module B that receives data
        .out(fifo_read_wire),
        .out_read_ptr()                 // expects interface of type "valid_ready_if.in"
    );

    // credit counter update logic (saturating counter which "CAN" count from 0 to 2^n (Note: not till 2^n - 1) )
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
                    end
    end : update_credit_ctr

    // valid credit pipeline generation - only generated if VALID_FFS or CREDIT_FFS are >= 1
    always_ff @(posedge clk or negedge reset_n) begin : valid_credit_ff_pipeline
        if (!reset_n) begin
            valid_ffs       <= '{default:'b0};
            valid_data_ffs  <= '{default:'b0};
            credit_ffs      <= '{default:'b0};
        end
        else begin
            // // cant really use the below code if VALID_FFS and CREDIT_FFS are less than 2
            if ( VALID_FFS >= 2 ) begin
                valid_ffs       <= {valid_ffs[VALID_FFS-2:0], in_to_ff_wire_valid};
                valid_data_ffs  <= {valid_data_ffs[VALID_FFS-2:0], in_to_ff_wire_data};
            end
            if ( CREDIT_FFS >= 2 ) begin
                credit_ffs      <= {credit_ffs[CREDIT_FFS-2:0], out_to_fifo_wire_credit};
            end
            if ( VALID_FFS == 1 ) begin
                valid_ffs <= in_to_ff_wire_valid;
                valid_data_ffs <= in_to_ff_wire_data;
            end
            if ( CREDIT_FFS == 1 ) begin
                credit_ffs <= out_to_fifo_wire_credit;
            end
        end
    end : valid_credit_ff_pipeline

    // this section covers sequential - assertion checks
    always_ff @(posedge clk or negedge reset_n) begin : assertion_checks
        if (!reset_n) begin
        end
        else begin
            // assertion check scenario:
            // - when credit_ctr saturates to CREDIT_CTR_MAX | VALID_FFS cycles later, the fifo write has to stall (not ready)
            begin : assert_credit_ctr_and_fifo_ready
                assertion_signals.fifo_write_wire_ready_ff <= fifo_write_wire.ready;
                for (int i=0; i<VALID_FFS; i++) begin : credit_history
                    if (i == 0) begin
                        assertion_signals.credit_ctr[0] <= credit_ctr;
                    end
                    else begin
                        assertion_signals.credit_ctr[i] <= assertion_signals.credit_ctr[i-1];
                    end
                end : credit_history
                // dedect negative edge in fifo_write_wire.ready
                if ( (assertion_signals.fifo_write_wire_ready_ff) & (!fifo_write_wire.ready) ) begin
                    FIFO_CTR_OVERFLOW : begin
                        assert (assertion_signals.credit_ctr[VALID_FFS-1] === CREDIT_CTR_MAX) begin
                            $display("time: %0t: assert::FIFO_CTR_OVERFLOW check : Pass", $time);
                        end
                        else begin
                            $error("time: %0t: assert::FIFO_CTR_OVERFLOW check credit_ctr: %d | fifo_write_wire %b", $time, assertion_signals.credit_ctr[VALID_FFS-1], fifo_write_wire.ready);
                        end
                    end
                end
            end : assert_credit_ctr_and_fifo_ready

        end
    end

endmodule : valid_credit