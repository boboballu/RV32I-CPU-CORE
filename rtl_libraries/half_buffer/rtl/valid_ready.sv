module valid_ready_hb_pipeline #(
    type DATA_T = logic [7:0],
    parameter PIPELINE_DEPTH = 1
) (
    // generic signals
    input logic clk, reset_n,
    
    // "in" is connected module A that sends data
    valid_ready_if in,  // expects interface of type "valid_ready_if.out"
    
    // "out" is connected to module B that receives data
    valid_ready_if out  // expects interface of type "valid_ready_if.in"
);

    valid_ready_if #(.DATA_T(DATA_T)) B_wire[PIPELINE_DEPTH-1:0](clk, reset_n);
    valid_ready_if #(.DATA_T(DATA_T)) in_wire(clk, reset_n);

    assign in_wire.valid = in.valid;
    assign in_wire.data = in.data;
    assign in.ready = in_wire.ready;

    generate
         // if the pipeline depth is 0; ie, to skid buffers in-between
        if (PIPELINE_DEPTH == 0) begin : zero_pipeline_depth
            assign out.valid = in.valid;
            assign out.data = in.data;
            assign in.ready = out.ready;
        end : zero_pipeline_depth

        else begin : nonzero_pipeline_depth
            // genvar i; // genvar should only be used in "for" loops; cannot be initialized
            for (genvar i=0; i<=PIPELINE_DEPTH-1; i++) begin : gen_hb_fifo
                if (i == 0) begin
                    // At module A
                    hb_valid_ready_wrapper #(.DATA_T(DATA_T)) hb_fifo (
                        .clk(clk), .reset_n(reset_n),                        
                        
                        // "in" is connected module A that sends data
                        .in(in_wire),           // expects interface of type "valid_ready_if.out"
                        
                        // "out" is connected to module B that receives data
                        .out(B_wire[i])         // expects interface of type "valid_ready_if.in"
                    );
                end
                else begin
                    hb_valid_ready_wrapper #(.DATA_T(DATA_T)) hb_fifo (
                        .clk(clk), .reset_n(reset_n),
                        
                        // "in" is connected module A that sends data
                        .in(B_wire[i-1]),      // expects interface of type "valid_ready_if.out"
                        
                        // "out" is connected to module B that receives data
                        .out(B_wire[i])        // expects interface of type "valid_ready_if.in"
                    );
                end
            end : gen_hb_fifo
            // At module B
            assign out.valid = B_wire[PIPELINE_DEPTH-1].valid;
            assign out.data = B_wire[PIPELINE_DEPTH-1].data;
            assign B_wire[PIPELINE_DEPTH-1].ready = out.ready;
        end : nonzero_pipeline_depth

    endgenerate
endmodule : valid_ready_hb_pipeline