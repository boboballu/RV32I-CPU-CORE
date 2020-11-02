// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define MAIN
`include "debug_headerfile.svh"
import dbg_pkg::*;

/********************************************************************************/
module riscv_32i(	input logic clk, reset,

					// Instruction mem interface signals
					output logic [31:0] imem_pc_addr,
					output logic imem_req,
					input logic [31:0] imem_instn,
					input logic imem_wait,

					// data mem interface signals
					output logic dmem_we,
					output logic [31:0] dmem_addr, dmem_wd,
					output logic [3:0]  dmem_mask,
					output logic dmem_req,
					input logic [31:0] dmem_rd,
					input logic  dmem_wait
);

// imem_req is always 1 as of now
//assign imem_req = 1;

/********************************************************************************/
	// Datapath of the processor - stagewise datapath nets
	logic [31:0] pc_genF_in;  // pc_gen_comb to to pc_gen_IF ff
	logic [31:0] pc_genF_out; // pc_gen_if ff to if_comb
	logic [31:0] pcD, pcE, pcM, pcW; // pc in all the ff stages
	logic [31:0] instnF, pcplus4F;  // if comb to if_id ff
	logic [31:0] instnD, pcplus4D;  // if_id ff to id_comb
	logic [31:0] jumpimmD, branchimmD, utypeimmD, itypeimmD, stypeimmD; // all imm's
	logic [31:0] aD, bD, signimmD; // id_comb to id_ex ff
	logic [31:0] pcplus4E;
	logic [31:0] aE, bE, signimmE; // id_ex ff to ex_comb
	logic [31:0] utypeimmE, branchimmE;
	logic [31:0] aluoutE, writedataE; // ex_comb to ex_mem ff
	logic [31:0] aluoutM, writedataM, branchimmM; // ex_mem ff to mem_comb
	logic [31:0] readdataM, aluoutM_out; // mem_comb to mem_wb ff
	logic [31:0] readdataW, aluoutW, branchimmW; // mem_wb ff to wv_comb
	logic [31:0] resultW; // wb_comb to other stage comb modules

/********************************************************************************/
	// control path nets
	logic [6:0] opD;
	logic [2:0] funct3D, funct3E, funct3M, funct3W;
	logic [6:0] funct7D;// op and funct - inputs to the controller

	// control path interconnect nets
	logic jalrD, auipcD, luiD;
	logic branchD, br_takenD, jumpD, regwriteD, memtoregD, memwriteD, alusrcD, alu_subD; logic [2:0] alucontrolD;
	logic branchE, br_takenE, jumpE, jalrE, auipcE, luiE, regwriteE, memtoregE, memwriteE, alusrcE, alu_subE; logic [2:0] alucontrolE;
	logic branchM, br_takenM, regwriteM, memtoregM, memwriteM;
	logic branchW, br_takenW, regwriteW, memtoregW;
	logic br_actual;
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
 	//assign br_takenD = 0; // static predictor -> predicted not taken
	// branch predictor and BTB interface
	logic [31:0] branchimmF;
	logic BTBHitF, BpredF;
	logic BTBHitD, BpredD;
/********************************************************************************/
	// Datapath: connecting stage_comb to stage_ff
	// stage 1: pc_if stage
	`ifndef BPRED
	assign BTBHitF = 1'b0;
	assign BTBHitD = 1'b0;
	assign BpredF  = 1'b0;
	assign BpredD  = 1'b0;
	assign branchimmF = 32'b0;
	`endif

	pc_gen pc_gen_comb (
						.branchD(branchD),
						.br_takenD(br_takenD), .jumpD(jumpD), .jalrD(jalrD),
						.BTBHitF(BTBHitF), .BpredF(BpredF),
						.BTBHitD(BTBHitD), .BpredD(BpredD),
						.branchimmF(branchimmF), .branchimmD(branchimmD), .jumpimmD(jumpimmD), .itypeimmD(itypeimmD),
						.pcF(pc_genF_out), .pcplus4F(pcplus4F), .pcD(pcD), .pcplus4D(pcplus4D),
						.srcaD(aD),

						.pc(pc_genF_in)
	);

	pc_if pc_if_ff 	(	.clk(clk), .reset(reset),
						.en(stallF), .clear(flushF),

						.pc(pc_genF_in),

						.pcF(pc_genF_out)
	);

	// stage 2: if_id stage
	IF_comb If_comb (	.pc(pc_genF_out),
						.imem_instn(imem_instn),

						.imem_pc_addr(imem_pc_addr),
						.instnF(instnF),
						.pcplus4F(pcplus4F)
	);

	if_id if_id_ff  (	.clk(clk), .reset(reset),
						.en(stallD), .clear((flushD)),

						.rd(instnF), .pcF(pc_genF_out) ,.pcplus4F(pcplus4F),
						.BTBHitF(BTBHitF), .BpredF(BpredF),

						.instnD(instnD), .pcD(pcD), .pcplus4D(pcplus4D),
						.BTBHitD(BTBHitD), .BpredD(BpredD)
	);

	// stage 3: id_ex stage
	instn_decode id_D (
						.instnD(instnD),

						.opD(opD),
						.funct3D(funct3D), .funct7D(funct7D),
						.jumpimmD(jumpimmD), .branchimmD(branchimmD), .utypeimmD(utypeimmD), .stypeimmD(stypeimmD), .itypeimmD(itypeimmD),
						.rsD(rsD), .rtD(rtD), .rdD(rdD)
	);

	ID_comb id_comb (	.clk(clk), .reset(reset),

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

	id_ex id_ex_ff	(	.clk(clk), .reset(reset),
						.en(stallE), .clear((flushE)),

						.jumpD(jumpD), .jalrD(jalrD), .pcD(pcD), .pcplus4D(pcplus4D),
						.regwriteD(regwriteD), .memtoregD(memtoregD), .memwriteD(memwriteD), .alusrcD(alusrcD),
						.alucontrolD(alucontrolD), .alu_subD(alu_subD), .funct3D(funct3D),
						.auipcD(auipcD), .luiD(luiD),
						.a(aD), .b(bD), .signimmD(signimmD), .rsD(rsD), .rtD(rtD), .rdD(rdD), .utypeimmD(utypeimmD),
						.branchD(branchD), .br_takenD(br_takenD), .branchimmD(branchimmD),

						.jumpE(jumpE), .jalrE(jalrE), .pcE(pcE), .pcplus4E(pcplus4E),
						.regwriteE(regwriteE), .memtoregE(memtoregE), .memwriteE(memwriteE), .alusrcE(alusrcE),
						.alucontrolE(alucontrolE), .alu_subE(alu_subE), .funct3E(funct3E),
						.auipcE(auipcE), .luiE(luiE),
						.aE(aE), .bE(bE), .signimmE(signimmE), .rsE(rsE), .rtE(rtE), .rdE(rdE), .utypeimmE(utypeimmE),
						.branchE(branchE), .br_takenE(br_takenE), .branchimmE(branchimmE)
	);

	// stage 4: ex_mem stage
	EX_comb ex_comb (	.jumpE(jumpE),.jalrE(jalrE), .auipcE(auipcE), .luiE(luiE), .pcE(pcE), .pcplus4E(pcplus4E),
						.alusrcE(alusrcE), .alucontrolE(alucontrolE), .alu_subE(alu_subE),
						.forwardAE(forwardAE), .forwardBE(forwardBE),
						.a(aE), .b(bE), .signimmE(signimmE), .utypeimmE(utypeimmE),
						.resultW(resultW), .aluoutM(aluoutM),

						.aluoutE(aluoutE), .writedataE(writedataE)
	);

	ex_mem ex_mem_ff(	.clk(clk), .reset(reset),
						.en(stallM), .clear(flushM),

						.funct3E(funct3E), .pcE(pcE),
						.regwriteE(regwriteE), .memtoregE(memtoregE), .memwriteE(memwriteE),
						.aluoutE(aluoutE), .writedataE(writedataE), .writeregE(writeregE),
						.branchE(branchE), .br_takenE(br_takenE), .branchimmE(branchimmE),

						.funct3M(funct3M), .pcM(pcM),
						.regwriteM(regwriteM), .memtoregM(memtoregM), .memwriteM(memwriteM),
						.aluoutM(aluoutM), .writedataM(writedataM), .writeregM(writeregM),
						.branchM(branchM), .br_takenM(br_takenM), .branchimmM(branchimmM)
	);

	// stage 5: mem_wb stage
	MEM_comb mem_comb
					(	.funct3M(funct3M),
						.memwriteM(memwriteM),
						.aluoutM_in(aluoutM), .writedataM(writedataM),
						.dmem_rd(dmem_rd),

						.dmem_addr(dmem_addr), .dmem_wd(dmem_wd),
						.dmem_mask(dmem_mask),
						.dmem_we(dmem_we),
						.readdataM(readdataM), .aluoutM_out(aluoutM_out)
	);

	mem_wb mem_wb_ff(	.clk(clk), .reset(reset),
						.en(stallW), .clear(flushW),

						.funct3M(funct3M), .pcM(pcM),
						.regwriteM(regwriteM), .memtoregM(memtoregM),
						.aluoutM(aluoutM_out), .readdataM(readdataM), .writeregM(writeregM),
						.branchM(branchM), .br_takenM(br_takenM), .branchimmM(branchimmM),

						.funct3W(funct3W), .pcW(pcW),
						.regwriteW(regwriteW), .memtoregW(memtoregW),
						.aluoutW(aluoutW), .readdataW(readdataW), .writeregW(writeregW),
						.branchW(branchW), .br_takenW(br_takenW), .branchimmW(branchimmW)
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
						.srca(aD), .srcb(bD),

						.br_takenD(br_takenD)
	);

/********************************************************************************/

	// hazard unit:
	hazard_unit hazard_unit1
					( 	.imem_wait(imem_wait), .dmem_wait(dmem_wait),
						.branchD(branchD), .BTBHitD(BTBHitD), .BpredD(BpredD), .br_takenD(br_takenD),
						.jumpD(jumpD), .jalrD(jalrD),
						.memtoregE(memtoregE), .regwriteE(regwriteE),
						.memtoregM(memtoregM), .regwriteM(regwriteM),
						.regwriteW(regwriteW),
						.rsD(rsD), .rtD(rtD),
						.rsE(rsE), .rtE(rtE),
						.writeregE(writeregE), .writeregM(writeregM), .writeregW(writeregW),
						.memwriteM(memwriteM),

						.forwardAD(forwardAD), .forwardBD(forwardBD),
						.forwardAE(forwardAE), .forwardBE(forwardBE),
						.stallF(stallF), .stallD(stallD), .stallE(stallE), .stallM(stallM), .stallW(stallW),
						.flushF(flushF), .flushD(flushD), .flushE(flushE), .flushM(flushM), .flushW(flushW),
						.imem_req(imem_req), .dmem_req(dmem_req)
	);


/********************************************************************************/
	`ifdef BPRED
	// BTB
	BTB #(.INDEX_SIZE(`BTB_INDEX_SIZE), .TAG_SIZE(`BTB_TAG_SIZE)) BTB
	(
		.clk(clk), .reset(reset),

		.pcF(pc_genF_out), .pcD(pcD),
		.BTBWriteD( ( (!BTBHitD) & branchD ) ),
		.branchimmD(branchimmD), .funct3D(funct3D),

		.BTBHit(BTBHitF),
		.branchimmF(branchimmF)//, .funct3F()
	);

	// Branch predictor
	Bpred #(.INDEX_SIZE(`BPRED_INDEX_SIZE)) Bpred
	(
		.clk(clk), .reset(reset),

		.pcF(pc_genF_out), .pcD(pcD),
		.br_takenD(br_takenD), .BpredWriteD(branchD),

		.BpredF(BpredF)
	);
	`endif 

/********************************************************************************/

endmodule : riscv_32i
