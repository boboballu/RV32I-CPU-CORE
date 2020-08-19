// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// branch compute - connects to the controller in the decode stage
// identifies the branch instruction and computes taken/not taken
`include "debug_headerfile.svh"
module branch_compute ( input logic branchD, input logic [2:0] funct3D,
                        input logic [31:0] srca, srcb,
                        
                        output logic br_takenD
);

    always_comb begin
        if (branchD) begin
            case (funct3D)
                3'b000: br_takenD   = ( signed'(srca) == signed'(srcb) ); // BEQ
                3'b001: br_takenD   = ( signed'(srca) != signed'(srcb) ); // BNE
                3'b100: br_takenD   = ( signed'(srca) <  signed'(srcb) ); // BLT
                3'b101: br_takenD   = ( signed'(srca) >= signed'(srcb) ); // BGE
                3'b110: br_takenD   = ( srca < srcb ); 				   // BLTU
                3'b111: br_takenD   = ( srca >= srcb );				   // BGEU
                default: br_takenD  = 1'b0;
            endcase
        end
        else begin
            br_takenD = 0;
        end
    end
endmodule : branch_compute
