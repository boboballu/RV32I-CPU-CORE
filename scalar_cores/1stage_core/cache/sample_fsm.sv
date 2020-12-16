
module wb_wa_fsm (
    input logic clock, reset, 
    input logic mem_we, mem_miss,
    input logic [31:0] mem_write_addr, mem_read_addr,
    output logic [31:0] mem_addr,
    output logic mem_ctl_we
    );

    parameter s0 = 2'b00, s1 = 2'b01, s2 = 2'b10, s3 = 2'b11;

    logic [1:0] p_state; // reg
    logic [1:0] n_state; // wire
    always_ff @ (posedge clock or negedge reset) begin
        if (!reset) p_state <= s0;
        else        p_state <= n_state;
    end

    always_comb begin
        case (p_state)
            s0: begin
                mem_addr = mem_read_addr;
                mem_ctl_we = 0;
                n_state = s0;
                if (mem_we) begin
                    mem_addr = mem_write_addr;
                    mem_ctl_we = 1;
                    n_state = s1;
                end
            end

            s1: begin
                mem_addr = mem_write_addr;
                mem_ctl_we = 1;
                n_state = s1;
                if (!mem_miss) begin
                    mem_addr = mem_write_addr;
                    mem_ctl_we = 1;
                    n_state = s2;
                end
            end

            s2: begin
                // 1 cycle gap for read after write
                mem_addr = mem_write_addr;
                mem_ctl_we = 1;
                n_state = s0;
            end
        endcase
    end

endmodule : wb_wa_fsm