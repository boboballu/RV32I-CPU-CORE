// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
import dbg_pkg::*;
`include "debug_headerfile.svh"

/********************************************************************************/
module riscv_32i(	input logic clk, reset,
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
	logic [31:0] pcD, pcE;// pcM, pcW; // pc in all the ff stages
	logic [31:0] instnF, pcplus4F;  // if comb to if_id ff
	logic [31:0] instnD, pcplus4D;  // if_id ff to id_comb
	logic [31:0] jumpimmD, branchimmD, utypeimmD, itypeimmD, stypeimmD; // all imm's
	logic [31:0] aD, bD, signimmD; // id_comb to id_ex ff
	logic [31:0] pcplus4E;
	logic [31:0] aE, bE, signimmE; // id_ex ff to ex_comb
	logic [31:0] utypeimmE;
	logic [31:0] aluoutE, writedataE; // ex_comb to ex_mem ff
	logic [31:0] aluoutM, writedataM; // ex_mem ff to mem_comb
	logic [31:0] readdataM, aluoutM_out; // mem_comb to mem_wb ff
	logic [31:0] readdataW, aluoutW; // mem_wb ff to wv_comb
	logic [31:0] resultW; // wb_comb to other stage comb modules
	
/********************************************************************************/
	// control path nets
	logic [6:0] opD; 
	logic [2:0] funct3D, funct3E, funct3M;
	logic [6:0] funct7D;// op and funct - inputs to the controller
	
	// control path interconnect nets
	logic jalrD, auipcD, luiD;
	logic branchD, br_takenD, jumpD, regwriteD, memtoregD, memwriteD, alusrcD, alu_subD; logic [2:0] alucontrolD;
	logic jumpE, auipcE, luiE, regwriteE, memtoregE, memwriteE, alusrcE, alu_subE; logic [2:0] alucontrolE;
	logic regwriteM, memtoregM, memwriteM;
	logic regwriteW, memtoregW;

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
	// hazard: Datapath
	assign writeregE = rdE;
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
	// Datapath: connecting stage_comb to stage_ff		
	// stage 1: pc_if stage
	pc_gen pc_gen_comb (
						.br_takenD(br_takenD), .jumpD(jumpD), .jalrD(jalrD),
						.branchimmD(branchimmD), .jumpimmD(jumpimmD), .itypeimmD(itypeimmD),
						.pcD(pcD), .pcplus4F(pcplus4F), 
						.srcaD(aD),
						.pc(pc_genF_in)	
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
	instn_decode id_D (
						.instnD(instnD),
						.opD(opD),
						.funct3D(funct3D), .funct7D(funct7D),
						.jumpimmD(jumpimmD), .branchimmD(branchimmD), .utypeimmD(utypeimmD), .stypeimmD(stypeimmD), .itypeimmD(itypeimmD),
						.rsD(rsD), .rtD(rtD), .rdD(rdD)
	);

	ID_comb id_comb (	.clk(clk),
						.regwriteW(regwriteW),
						.rsD(rsD), .rtD(rtD),
						.jumpimmD(jumpimmD), .branchimmD(branchimmD), .stypeimmD(stypeimmD), .itypeimmD(itypeimmD),
						.pc(pcD),
						.forwardAD(forwardAD), .forwardBD(forwardBD),
						.memwriteD(memwriteD),
						.writeregW(writeregW),
						.resultW(resultW), .aluoutM(aluoutM),
						.a(aD), .b(bD), .signimmD(signimmD)
	);
	
	id_ex id_ex_ff	(	.clk(clk), 
						.en(stallE), .clear((flushE | reset)),
						.jumpD(jumpD), .jalrD(jalrD), .pcD(pcD), .pcplus4D(pcplus4D),
						.regwriteD(regwriteD), .memtoregD(memtoregD), .memwriteD(memwriteD), .alusrcD(alusrcD),
						.alucontrolD(alucontrolD), .alu_subD(alu_subD), .funct3D(funct3D),
						.auipcD(auipcD), .luiD(luiD),
						.a(aD), .b(bD), .signimmD(signimmD), .rsD(rsD), .rtD(rtD), .rdD(rdD), .utypeimmD(utypeimmD),
						.jumpE(jumpE), .jalrE(jalrE), .pcE(pcE), .pcplus4E(pcplus4E),
						.regwriteE(regwriteE), .memtoregE(memtoregE), .memwriteE(memwriteE), .alusrcE(alusrcE),
						.alucontrolE(alucontrolE), .alu_subE(alu_subE), .funct3E(funct3E),
						.auipcE(auipcE), .luiE(luiE),
						.aE(aE), .bE(bE), .signimmE(signimmE), .rsE(rsE), .rtE(rtE), .rdE(rdE), .utypeimmE(utypeimmE)
	); 

	// stage 4: ex_mem stage
	EX_comb ex_comb (	.jumpE(jumpE),.jalrE(jalrE), .auipcE(auipcE), .luiE(luiE), .pcE(pcE), .pcplus4E(pcplus4E),
						.alusrcE(alusrcE), .alucontrolE(alucontrolE), .alu_subE(alu_subE),
						.forwardAE(forwardAE), .forwardBE(forwardBE),
						.a(aE), .b(bE), .signimmE(signimmE), .utypeimmE(utypeimmE),
						.resultW(resultW), .aluoutM(aluoutM),
						.aluoutE(aluoutE), .writedataE(writedataE)	
	);
	
	ex_mem ex_mem_ff(	.clk(clk),
						.en(stallM), .clear(flushM | reset),
						.funct3E(funct3E),
						.regwriteE(regwriteE), .memtoregE(memtoregE), .memwriteE(memwriteE),
						.aluoutE(aluoutE), .writedataE(writedataE), .writeregE(writeregE),
						.regwriteM(regwriteM), .memtoregM(memtoregM), .memwriteM(memwriteM),
						.funct3M(funct3M),
						.aluoutM(aluoutM), .writedataM(writedataM),
						.writeregM(writeregM)
	);

	// stage 5: mem_wb stage
	MEM_comb mem_comb 
					(	.funct3M(funct3M),
						.memwriteM(memwriteM),
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
						//.equalD(equalD_ctrl),
						.branchD(branchD), .jumpD(jumpD), .jalrD(jalrD),
						.regwriteD(regwriteD),
						.memtoregD(memtoregD), .memwriteD(memwriteD),
						/*.br_takenD(br_takenD),*/ .alusrcD(alusrcD),
						.alucontrolD(alucontrolD),
						.alu_subD(alu_subD),
						.auipcD(auipcD), .luiD(luiD)
	);

	// branch compute:
	branch_compute branch_compute (
						.branchD(branchD), .funct3D(funct3D),
						.jumpimmD(jumpimmD), .branchimmD(branchimmD), .itypeimmD(itypeimmD),
						.srca(aD), .srcb(bD),
						.br_takenD(br_takenD)
	);
	
/********************************************************************************/
	
	// hazard unit:
	hazard_unit hazard_unit1
					( 	.branchD(branchD), .jumpD(jumpD), .jalrD(jalrD), .br_takenD(br_takenD),
						.memtoregE(memtoregE), .regwriteE(regwriteE),
						.memtoregM(memtoregM), .regwriteM(regwriteM),
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
