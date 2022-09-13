module fifo #(
    parameter ROWS  = 8,
    parameter COL_BIT_WIDTH = 32,
    //immutable - local params
    localparam ROW_ADDR_WIDTH = ($clog2(ROWS))
)
(
    input logic clk, reset_n,
    input logic w_req, r_req,
    input logic [COL_BIT_WIDTH-1:0] w_data,
    output logic [COL_BIT_WIDTH-1:0] r_data,
    output logic [ROW_ADDR_WIDTH:0] write_ptr, read_ptr,
    output logic w_stall, r_stall
);
    logic [COL_BIT_WIDTH-1:0] MEM [ROWS-1:0];
    logic full, empty;
    logic [ROW_ADDR_WIDTH:0] head, tail;

    assign {read_ptr, write_ptr} = {head, tail};
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
        end

        else begin
            full = 0;
            empty = 0;
        end
    end

    always_ff @(posedge clk or negedge reset_n) begin
        if (!reset_n) begin
            MEM <= #1 '{default:'b0};
            head <= #1 0;
            tail <= #1 0;
        end
        else begin
            if (!full) begin
                if (w_req) begin
                    MEM[tail[ROW_ADDR_WIDTH-1:0]] <= #1 w_data;
                    tail <= #1 tail + 1;
                end
            end
            if (!empty) begin
                if (r_req) begin
                    head <= #1 head + 1;
                end
            end
        end
    end
endmodule : fifo


module fifo_ready_valid_wrapper #(
    parameter ROWS  = 8,
    parameter COL_BIT_WIDTH = 32,

    //immutable - local params
    localparam ROW_ADDR_WIDTH = ($clog2(ROWS))
)

(
    // general signals
    input logic clk, reset_n,

    // Sender module (module A for simplicity) signals
    input logic A_valid, 
    input logic [COL_BIT_WIDTH-1:0] A_data,
    output logic A_ready, 
    output logic [ROW_ADDR_WIDTH:0] A_write_ptr, 

    // Receiver module (Module B for simplicity) signals
    output logic B_valid,
    output logic [COL_BIT_WIDTH-1:0] B_data,
    input logic B_ready,
    output logic [ROW_ADDR_WIDTH:0] B_read_ptr
);

    logic w_stall, r_stall;
    fifo #(.ROWS(ROWS), .COL_BIT_WIDTH(COL_BIT_WIDTH)) fifo_inst (
        .clk(clk), .reset_n(reset_n),
        .w_req(A_valid), .r_req(B_ready),
        .w_data(A_data), .r_data(B_data),
        .write_ptr(A_write_ptr), .read_ptr(B_read_ptr),
        .w_stall(w_stall), .r_stall(r_stall)
    );

    assign A_ready = !w_stall;
    assign B_valid = !r_stall;
endmodule : fifo_ready_valid_wrapper