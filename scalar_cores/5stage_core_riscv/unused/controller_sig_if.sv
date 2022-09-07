// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
interface controller_if ();
    // logic [31:0] instr;
    // logic [6:0] op; logic  [2:0] funct3; logic [6:0] funct7;
    // logic br_taken; 
    logic branch, jump, jalr;
    logic memtoreg, memwrite;
    logic pcsrc, alusrc;
    logic regwrite;
    logic [2:0] alucontrol; logic alu_sub;
    logic auipc, lui;

    // assign op       = instr[6:0];
    // assign funct3 = instr[14:12];
    // assign funct7 = instr[31:25];

    
    // controller
    // input : 6' op - to identify instn
    // input : 3' funct3 - as mentioned in risv isa
    // input : 7' funct7 - as mentioned in riscv isa
    // input : br_taken(from alu for beq)
    modport ctrlr   (    
                    //input instr, 
                    input br_taken,
                    output branch, jump, jalr, 
                    memtoreg, memwrite, pcsrc, alusrc, regwrite,
                    alucontrol, alu_sub, auipc, lui
    );
    
    // control pipeline_reg input and output
    modport reg_in     (
                    input branch, jump, jalr, 
                    memtoreg, memwrite, pcsrc, alusrc, regwrite,
                    alucontrol, alu_sub, auipc, lui
    );
    modport reg_out (
                    output branch, jump, jalr, 
                    memtoreg, memwrite, pcsrc, alusrc, regwrite,
                    alucontrol, alu_sub, auipc, lui
    );

    // datapath stages [EX, MEM, WB] - control path pass through

endinterface : controller_if

// ctrl_reg implements control signal pipeline registers
module ctrl_reg ( 
                    input logic clk, 
                    input logic clear, en,   
                    controller_if.reg_in   reg_in,
                    controller_if.reg_out reg_out
);
    
    always_ff @(posedge clk) begin
        if (clear) begin
            {reg_out.branch, reg_out.jump, reg_out.jalr, 
            reg_out.memtoreg, reg_out.memwrite, reg_out.pcsrc, reg_out.alusrc, reg_out.regwrite,
            reg_out.alucontrol, reg_out.alu_sub, reg_out.auipc, reg_out.lui}
            ='b0;
        end
        else if(!en) begin
            {reg_out.branch, reg_out.jump, reg_out.jalr, 
            reg_out.memtoreg, reg_out.memwrite, reg_out.pcsrc, reg_out.alusrc, reg_out.regwrite,
            reg_out.alucontrol, reg_out.alu_sub, reg_out.auipc, reg_out.lui}
            =
            {reg_in.branch, reg_in.jump, reg_in.jalr, 
            reg_in.memtoreg, reg_in.memwrite, reg_in.pcsrc, reg_in.alusrc, reg_in.regwrite,
            reg_in.alucontrol, reg_in.alu_sub, reg_in.auipc, reg_in.lui}
            ;
        end
    end
endmodule : ctrl_reg