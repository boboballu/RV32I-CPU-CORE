// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
module controller    (   
                        input logic [6:0] op,
                        input logic  [2:0] funct3; input logic [6:0] funct7;
                        input logic br_taken,
                        controller_if.ctrlr c_bus 
);

    logic [1:0] aluop;

    maindec maindec (    .c_bus(c_bus),
                        .aluop(aluop)
    );
    aludec aludec     (    .c_bus(c_bus),
                        .aluop(aluop)
    );
    assign c_bus.pcsrc = c_bus.branch & br_taken;

endmodule
 
module maindec        (    controller_if c_bus,
                        output logic [1:0] aluop
    );

    logic [8:0] controls;
    assign {c_bus.regwrite, c_bus.alusrc, c_bus.branch, c_bus.memwrite, 
            c_bus.memtoreg, c_bus.jump, c_bus.jalr, c_bus.auipc, c_bus.lui} = controls;
    
    always_comb begin
        case(op)
            7'b0110011: begin controls <= 9'b100000000;   aluop <= 2'b10; end // RTYPE
            7'b0000011: begin controls <= 9'b110010000;   aluop <= 2'b00; end // LW
            7'b0100011: begin controls <= 9'b010100000;   aluop <= 2'b00; end // SW
            7'b0010011: begin controls <= 9'b110000000;   aluop <= 2'b00; end // ADDI
            7'b1100011: begin controls <= 9'b001000000;   aluop <= 2'b01; end // BEQ
            7'b1101111: begin controls <= 9'b100001000;   aluop <= 2'b00; end // J
            7'b1100111: begin controls <= 9'b100001100;      aluop <= 2'b00; end // JALR
            7'b0010111: begin controls <= 9'b100000010;   aluop <= 2'b00; end // auipc
            7'b0110111: begin controls <= 9'b100000001;   aluop <= 2'b00; end // lui
            default   : begin controls <= 9'b000000000;   aluop <= 2'b00; end // illegal op - nop
        endcase
    end
endmodule

module aludec(    
                controller_if c_bus,
                input logic [1:0] aluop
);

    always_comb
    case(aluop)
        2'b00:      begin c_bus.alucontrol <= 3'b000; c_bus.alu_sub <= 1'b0; end       // add (for lw/sw/addi/J)
        2'b01:      begin c_bus.alucontrol <= 3'b000; c_bus.alu_sub <= 1'b1; end       // sub (for beq)
        default: begin c_bus.alucontrol <= funct3; c_bus.alu_sub = funct7[5]; end   // R-type 
    endcase
endmodule