// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`include "debug_headerfile.sv"
import dbg_pkg::*;
/********************************************************************************/
module riscv_32i(input logic clk, reset,
			output logic [31:0] pc_imem,
			input logic [31:0] imem_instn,
			output logic dmem_we,
			output logic [31:0] dmem_addr, dmem_wd,
			input logic [31:0] dmem_rd
			`ifdef mem_debug 
			, output mem_debug debug
			`endif			
			);

/********************************************************************************/
	// Datapath of the processor - stagewise datapath nets
	logic [31:0] pc_genF_in;  // pc_gen_comb to to pc_gen_IF ff
	logic [31:0] pc_genF_out; // pc_gen_if ff to if_comb
	logic [31:0] pcD, pcE, pcM, pcW; // pc in all the ff stages
	logic [31:0] instnF, pcplus4F;  // if comb to if_id ff
	logic [31:0] instnD, pcplus4D;  // if_id ff to id_comb
	logic [31:0] aD, bD, signimmD, pcbranchD, jump_targetD; // id_comb to id_ex ff
	logic equalD_ctrl; // id_comb to controller
	logic [31:0] pcplus4E;
	logic [31:0] aE, bE, signimmE; // id_ex ff to ex_comb 
	logic [31:0] aluoutE, writedataE; // ex_comb to ex_mem ff
	logic [31:0] aluoutM, writedataM; // ex_mem ff to mem_comb
	logic [31:0] readdataM, aluoutM_out; // mem_comb to mem_wb ff
	logic [31:0] readdataW, aluoutW; // mem_wb ff to wv_comb
	logic [31:0] resultW; // wb_comb to other stage comb modules
	
/********************************************************************************/
	// control path nets
	logic [6:0] opD; 
	logic [2:0] funct3D; 
	logic [6:0] funct7D;// op and funct - inputs to the controller
	
	// interconnect nets
	logic branchD, pcsrcD, jumpD, regwriteD, memtoregD, memwriteD, alusrcD, alu_subD; logic [2:0] alucontrolD;
	logic jumpE, regwriteE, memtoregE, memwriteE, alusrcE, alu_subE; logic [2:0] alucontrolE;
	logic regwriteM, memtoregM, memwriteM;
	logic regwriteW, memtoregW;

	`ifdef BR_RESOLVE_M
	logic [31:0] pcbranchE, pcbranchM;
	logic branchE, branchM;
	logic zeroE, zeroM;
	logic pcsrcM;
	`endif
/********************************************************************************/
	// hazard datapath nets
	logic [4:0] rsD, rtD, rdD; // reg source & dest addresses - for hazard datapath
	logic [4:0] rsE, rtE, rdE;
	logic [4:0] writeregE, writeregM, writeregW;

/********************************************************************************/
	// hazaard control nets
	// forward nets:
	logic forwardAD, forwardBD;
	logic [1:0] forwardAE, forwardBE;
	// stall nets
	logic stallF, stallD, stallE, stallM, stallW;
	logic flushF, flushD, flushE, flushM, flushW;
/********************************************************************************/
	// controller: op, funct assignment
	assign opD = instnD[6:0];
	assign funct3D = instnD[14:12];
	assign funct7D = instnD[31:25];
/********************************************************************************/	
	// hazard: Datapath
	assign writeregE = rdE;
	// rsD, rtD and rtD
	assign rsD = instnD[19:15];
	assign rtD = instnD[24:20];
	assign rdD = instnD[11:7];

	`ifdef BR_RESOLVE_M
	assign pcsrcM = branchM & zeroM;
	`endif
/********************************************************************************/
	// debugging at mem stage
	`ifdef mem_debug
	assign debug.dmem_we = dmem_we;
	assign debug.dmem_addr = dmem_addr;
	assign debug.dmem_wd = dmem_wd;
	assign debug.dmem_rd = dmem_rd;
	assign debug.regwriteM = regwriteM;
	assign debug.memtoregM = memtoregM;
	`endif 
/********************************************************************************/
	// Datapath: cinnecting stage_comb to stage_ff		
	// stage 1: pc_if stage
	pc_gen pc_gen_comb 
					(	`ifdef BR_RESOLVE_D
						.pcsrcD(pcsrcD),
						`endif
						`ifdef BR_RESOLVE_M
						.pcsrcD(pcsrcM),
						`endif
						.jumpD(jumpD),
						`ifdef BR_RESOLVE_D
						.pcbranchD(pcbranchD),
						`endif
						`ifdef BR_RESOLVE_M
						.pcbranchD(pcbranchM),
						`endif
						.jump_targetD(jump_targetD),
						.pcplus4F(pcplus4F), .pc(pc_genF_in)	
					);
	
	pc_if pc_if_ff 	(	.clk(clk), 
						.en(stallF), .clear(flushF | reset), 
						.pc(pc_genF_in),
						.pcF(pc_genF_out)	
					);

	// stage 2: if_id stage 
	IF_comb If_comb (	.pc(pc_genF_out),
						.imem_instn(imem_instn),
						.pc_imem(pc_imem),
						.instnF(instnF),
						.pcplus4F(pcplus4F)	
					);
	
	if_id if_id_ff  (	.clk(clk),
						.en(stallD), .clear((flushD | reset)),
						.rd(instnF), .pcF(pc_genF_out) ,.pcplus4F(pcplus4F),
						.instnD(instnD), .pcD(pcD), .pcplus4D(pcplus4D)	
					);

	// stage 3: id_ex stage
	ID_comb id_comb (	.clk(clk),
						.regwriteW(regwriteW),
						.instnD(instnD), .pc(pcD), .pcplus4D(pcplus4D),
						.forwardAD(forwardAD), .forwardBD(forwardBD),
						.memwriteD(memwriteD),
						.writeregW(writeregW),
						.resultW(resultW), .aluoutM(aluoutM),
						.a(aD), .b(bD), .signimmD(signimmD), .pcbranchD(pcbranchD), .jump_targetD(jump_targetD),
						.equalD(equalD_ctrl)
					);
	
	id_ex id_ex_ff	(	.clk(clk), 
						.en(stallE), .clear((flushE | reset)),
						.jumpD(jumpD), .pcplus4D(pcplus4D),
						.regwriteD(regwriteD), .memtoregD(memtoregD), .memwriteD(memwriteD), .alusrcD(alusrcD),
						.alucontrolD(alucontrolD), .alu_subD(alu_subD),
						.a(aD), .b(bD), .signimmD(signimmD), .rsD(rsD), .rtD(rtD), .rdD(rdD),
						.jumpE(jumpE), .pcplus4E(pcplus4E),
						.regwriteE(regwriteE), .memtoregE(memtoregE), .memwriteE(memwriteE), .alusrcE(alusrcE),
						.alucontrolE(alucontrolE), .alu_subE(alu_subE),
						.aE(aE), .bE(bE), .signimmE(signimmE), .rsE(rsE), .rtE(rtE), .rdE(rdE)
						`ifdef BR_RESOLVE_M
						, .pcbranchD(pcbranchD),
						  .pcbranchE(pcbranchE),
						  .branchD(branchD),
						  .branchE(branchE)
						`endif
					); 

	// stage 4: ex_mem stage
	EX_comb ex_comb (	.jumpE(jumpE), .pcplus4E(pcplus4E),
						.alusrcE(alusrcE), .alucontrolE(alucontrolE), .alu_subE(alu_subE),
						.forwardAE(forwardAE), .forwardBE(forwardBE),
						.a(aE), .b(bE), .signimmE(signimmE),
						.resultW(resultW), .aluoutM(aluoutM),
						.aluoutE(aluoutE), .writedataE(writedataE)	
						`ifdef BR_RESOLVE_M
						, .zeroE(zeroE)
						`endif
					);
	
	ex_mem ex_mem_ff(	.clk(clk),
						.en(stallM), .clear(flushM | reset),
						.regwriteE(regwriteE), .memtoregE(memtoregE), .memwriteE(memwriteE),
						.aluoutE(aluoutE), .writedataE(writedataE), .writeregE(writeregE),
						.regwriteM(regwriteM), .memtoregM(memtoregM), .memwriteM(memwriteM),
						.aluoutM(aluoutM), .writedataM(writedataM),
						.writeregM(writeregM)
						`ifdef BR_RESOLVE_M
						, .pcbranchE(pcbranchE),
						  .pcbranchM(pcbranchM),
						  .branchE(branchE), .zeroE(zeroE),
						  .branchM(branchM), .zeroM(zeroM)
						`endif
					);

	// stage 5: mem_wb stage
	MEM_comb mem_comb 
					(	.memwriteM(memwriteM),
						.aluoutM_in(aluoutM), .writedataM(writedataM),
						.dmem_rd(dmem_rd), .dmem_addr(dmem_addr), .dmem_wd(dmem_wd), .dmem_we(dmem_we), 
						.readdataM(readdataM), 
						.aluoutM_out(aluoutM_out)	
					);

	mem_wb mem_wb_ff(	.clk(clk), 
						.en(stallW), .clear(flushW | reset),
						.regwriteM(regwriteM), .memtoregM(memtoregM),
						.aluoutM(aluoutM_out), .readdataM(readdataM), .writeregM(writeregM),
						.regwriteW(regwriteW), .memtoregW(memtoregW),
						.aluoutW(aluoutW), .readdataW(readdataW),
						.writeregW(writeregW) 
					);

	WB_comb wb_comb (	.memtoregW(memtoregW),
						.readdataW(readdataW), .aluoutW(aluoutW),
						.resultW(resultW)
					);
/********************************************************************************/
	
	// controller:
	controller ctrl (	.opD(opD), .funct3D(funct3D), .funct7D(funct7D),
						.equalD(equalD_ctrl),
						.branchD(branchD), .pcsrcD(pcsrcD), .jumpD(jumpD),
						.regwriteD(regwriteD),
						.memtoregD(memtoregD), .memwriteD(memwriteD),
						.alusrcD(alusrcD),
						.alucontrolD(alucontrolD),
						.alu_subD(alu_subD)
					);
/********************************************************************************/
	
	// hazard unit:
	hazard_unit hazard_unit1
					( 	.branchD(branchD), .jumpD(jumpD), .pcsrcD(pcsrcD),
						.memtoregE(memtoregE), .regwriteE(regwriteE),
						.memtoregM(memtoregM), .regwriteM(regwriteM),
						`ifdef BR_RESOLVE_M
						.pcsrcM(pcsrcM),
						`endif
						.regwriteW(regwriteW),
						.rsD(rsD), .rtD(rtD),
						.rsE(rsE), .rtE(rtE),
						.writeregE(writeregE), .writeregM(writeregM), .writeregW(writeregW),
						.forwardAD(forwardAD), .forwardBD(forwardBD),
						.forwardAE(forwardAE), .forwardBE(forwardBE),
						.stallF(stallF), .stallD(stallD), .stallE(stallE), .stallM(stallM), .stallW(stallW),
						.flushF(flushF), .flushD(flushD), .flushE(flushE), .flushM(flushM), .flushW(flushW)
					);

endmodule : riscv_32i
