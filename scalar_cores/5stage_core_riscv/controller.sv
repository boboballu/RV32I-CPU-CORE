// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
module controller	(   
                    input logic [6:0] opD, input logic  [2:0] funct3D, input logic [6:0] funct7D,
                    
                    output logic branchD, jumpD, jalrD,
                    output logic memtoregD, memwriteD,
                    output logic alusrcD,
                    output logic regwriteD,
                    output logic [2:0] alucontrolD, output logic alu_subD,
                    output logic auipcD, luiD
);

    logic [1:0] aluop;

    maindec maindec (	.opD(opD), 
                        .regwriteD(regwriteD), .alusrcD(alusrcD),
                        .branchD(branchD), 
                        .memwriteD(memwriteD), .memtoregD(memtoregD),
                        .jumpD(jumpD), .jalrD(jalrD), .auipcD(auipcD), .luiD(luiD),
                        .aluop(aluop)
    );
    aludec ad(	        .funct3D(funct3D), .funct7D(funct7D), 
                        .aluop(aluop), 
                        .alucontrolD(alucontrolD),
                        .alu_subD(alu_subD)
    );

endmodule : controller

module maindec	(	input logic [6:0] opD,
                    output logic regwriteD, alusrcD,
                    output logic branchD,
                    output logic memwriteD, memtoregD,
                    output logic jumpD, jalrD, auipcD, luiD,
                    output logic [1:0] aluop
);

    logic [8:0] controls;
    assign {regwriteD, alusrcD, branchD, memwriteD, 
            memtoregD, jumpD, jalrD, auipcD, luiD} = controls;

    always_comb begin
        case(opD)
            7'b0110011: begin controls <= 9'b100000000;   aluop <= 2'b10; end // RTYPE
            7'b0000011: begin controls <= 9'b110010000;   aluop <= 2'b00; end // LW
            7'b0100011: begin controls <= 9'b010100000;   aluop <= 2'b00; end // SW
            7'b0010011: begin controls <= 9'b110000000;   aluop <= 2'b00; end // Immediate
            7'b1100011: begin controls <= 9'b001000000;   aluop <= 2'b01; end // Branch
            7'b1101111: begin controls <= 9'b100001000;   aluop <= 2'b00; end // JAL - Jump
            7'b1100111: begin controls <= 9'b100000100;	  aluop <= 2'b00; end // JALR
            7'b0010111: begin controls <= 9'b100000010;   aluop <= 2'b00; end // auipc
            7'b0110111: begin controls <= 9'b100000001;   aluop <= 2'b00; end // lui
            default   : begin controls <= 9'b000000000;   aluop <= 2'b00; end // illegal op - nop
        endcase
    end
endmodule : maindec

module aludec(	
                input logic [1:0] aluop,
                input logic [2:0] funct3D, input logic [6:0] funct7D,
                output logic [2:0] alucontrolD, output logic alu_subD
);

    always_comb begin
        case(aluop)
            2'b00: 	 begin alucontrolD <= 3'b000; alu_subD <= 1'b0; end       // add (for lw/sw/immediate/J)
            2'b01: 	 begin alucontrolD <= 3'b000; alu_subD <= 1'b1; end       // sub (for branch)
            default: begin alucontrolD <= funct3D; alu_subD = funct7D[5]; end   // R-type 
        endcase
    end
endmodule : aludec