module fifo #(
    parameter ROWS  = 8,
    parameter COL_BIT_WIDTH = 32,
    //immutable params
    parameter ROW_ADDR_WIDTH = ($clog2(ROWS))
)
(
    input logic clk, reset_n,
    input logic w_req, r_req,
    input logic [COL_BIT_WIDTH-1:0] w_data, 
    output logic [COL_BIT_WIDTH-1:0] r_data,
    output logic [ROW_ADDR_WIDTH:0] head, tail,
    output logic w_stall, r_stall
);
    logic [COL_BIT_WIDTH-1:0] MEM [ROWS-1:0];
    logic full, empty;

    assign w_stall  = full;
    assign r_stall  = empty;
    assign r_data   = ( r_req & (!empty) ) ? MEM[head[ROW_ADDR_WIDTH-1:0]] : 'b0;

    always_comb begin
        if ( (head ^ tail) == 'b1000 ) begin : full_condition
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
            MEM <= '{default:'b0};
            head <= 0;
            tail <= 0;
        end
        else begin
            if (!full) begin    
                if (w_req) begin
                    MEM[tail[ROW_ADDR_WIDTH-1:0]] <= w_data;
                    tail <= tail + 1;
                end
            end
            if (!empty) begin
                if (r_req) begin
                    head <= head + 1;
                end
            end
        end 
    end
endmodule : fifo