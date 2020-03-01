// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
module mips(input logic clk, reset,
			output logic [31:0] pc_imem,
			input logic [31:0] imem_instn,
			output logic dmem_we,
			output logic [31:0] dmem_addr, dmem_wd,
			input logic [31:0] dmem_rd 	);

/********************************************************************************/
	// Datapath of the processor - stagewise datapath nets
	logic [31:0] pc_genF_in;  // pc_gen_comb to to pc_gen_IF ff
	logic [31:0] pc_genF_out; // pc_gen_if ff to if_comb
	logic [31:0] instnF, pcplus4F;  // if comb to if_id ff
	logic [31:0] instnD, pcplus4D;  // if_id ff to id_comb
	logic [31:0] aD, bD, signimmD, pcbranchD, jump_targetD; // id_comb to id_ex ff
	logic equalD_ctrl; // id_comb to controller
	logic [31:0] aE, bE, signimmE; // id_ex ff to ex_comb 
	logic [31:0] aluoutE, writedataE; // ex_comb to ex_mem ff
	logic [31:0] aluoutM, writedataM; // ex_mem ff to mem_comb
	logic [31:0] readdataM, aluoutM_out; // mem_comb to mem_wb ff
	logic [31:0] readdataW, aluoutW; // mem_wb ff to wv_comb
	logic [31:0] resultW; // wb_comb to other stage comb modules
	
/********************************************************************************/
	// control path nets
	logic [5:0] op, funct; // op and funct - inputs to the controller
	// interconnect nets
	logic pcsrcD, jumpD, regwriteD, memtoregD, memwriteD, regdstD, alusrcD; logic [2:0] alucontrolD;
	logic regwriteE, memtoregE, memwriteE, regdstE, alusrcE; logic [2:0] alucontrolE;
	logic regwriteM, memtoregM, memwriteM;
	logic regwriteW, memtoregW;
	//logic [15:0] immD - immidiate value, sign extended in ID_comb stage
/********************************************************************************/
	// hazard datapath nets
	// 	logic [4:0] rsD, rtD, rdD; // reg source & dest addresses - for hazard datapath
	logic [4:0] rsE, rtE, rdE;
	logic [4:0] writeregE, writeregM, writeregW;
/********************************************************************************/
	// controller: op, funct assignment
	assign op = instnD[31:26];
	assign funct = instnD[5:0];
	// hazard: Datapath
	assign writeregE = regdstE ? rdE : rtE;
	// Datapath: cinnecting stage_comb to stage_ff		
	// stage 1: pc_if stage
	pc_gen pc_gen_comb 
					(	.pcsrcD(pcsrcD), .jumpD(jumpD),
						.pcbranchD(pcbranchD), .jump_targetD(jump_targetD),
						.pcplus4(pcplus4F), .pc(pc_genF_in)	);
	
	pc_if pc_if_ff 	(	.clk(clk), 
						.en(), .clear(), 
						.pc(pc_genF_in),
						.pcF(pc_genF_out)	);

	// stage 2: if_id stage 
	IF_comb If_comb (	.pc(pc_genF_out),
						.imem_instn(imem_instn),
						.pc_imem(pc_imem),
						.instnF(instnF),
						.pcplus4F(pcplus4F)	);
	
	if_id if_id_ff  (	.clk(clk),
						.en(), .clear(),
						.rd(instnF), .pcplus4F(pcplus4F),
						.instnD(instnD), .pcplus4D(pcplus4D)	);

	// stage 3: id_ex stage
	
	ID_comb id_comb (	.clk(clk),
						.regwriteW(regwriteW),
						.instnD(instnD), .pcplus4D(pcplus4D),
						.forwardAD(), .forwardBD(),
						.writeregW(writeregW),
						.resultW(resultW), .aluoutM(aluoutM),
						.a(aD), .b(bD), .signimmD(signimmD), .pcbranchD(pcbranchD), .jump_targetD(jump_targetD),
						.equalD(equalD_ctrl));
	
	id_ex id_ex_ff	(	.clk(clk), 
						.en(), .clear(),
						.regwriteD(regwriteD), .memtoregD(regwriteD), .memwriteD(memwriteD), .regdstD(regdstD), .alusrcD(alusrcD),
						.alucontrolD(alucontrolD), 
						.a(aD), .b(bD), .signimmD(signimmD), .rsD(rsD), .rtD(rtD), .rdD(rdD),
						.regwriteE(regwriteE), .memtoregE(memtoregE), .memwriteE(memwriteE), .regdstE(regdstE), .alusrcE(alusrcE),
						.alucontrolE(alucontrolE),
						.aE(aE), .bE(bE), .signimmE(signimmE), .rsE(rsE), .rtE(rtE), .rdE(rdE)	); 

	// stage 4: ex_mem stage
	EX_comb ex_comb (	.alusrcE(alusrcE), .alucontrolE(alucontrolE),
						.forwardAE(), .forwardBE(),
						.a(aE), .b(bE), .signimmE(signimmE),
						.resultW(resultW), .aluoutM(aluoutM),
						.aluoutE(aluoutE), .writedataE(writedataE)	);
	
	ex_mem ex_mem_ff(	.clk(clk),
						.en(), .clear(),
						.regwriteE(regwriteE), .memtoregE(memtoregE), .memwriteE(memwriteE),
						.aluoutE(aluoutE), .writedataE(writedataE), 
						.writeregE(writeregE), 
						.regwriteM(regwriteM), .memtoregM(memtoregM), .memwriteM(memwriteM),
						.aluoutM(aluoutM), .writedataM(writedataM),
						.writeregM(writeregM)	);

	// stage 5: mem_wb stage
	MEM_comb mem_comb 
					(	.memwriteM(memwriteM),
						.aluoutM_in(aluoutM), .writedataM(writedataM),
						.dmem_rd(dmem_rd), .dmem_addr(dmem_addr), .dmem_wd(dmem_wd), .dmem_we(), 
						.readdataM(readdataM), 
						.aluoutM_out(aluoutM_out)	);

	mem_wb mem_wb_ff(	.clk(clk), 
						.en(), .clear(),
						.regwriteM(regwriteM), .memtoregM(memtoregM),
						.aluoutM(aluoutM_out), .readdataM(readdataM), .writeregM(writeregM),
						.regwriteW(regwriteW), .memtoregW(memtoregW),
						.aluoutW(aluoutW), .readdataW(readdataW),
						.writeregW(writeregW)	);	

	WB_comb wb_comb (	.memregW(),
						.readdataW(readdataW), .aluoutW(aluoutW),
						.resultW(resultW)	);

/********************************************************************************/
	// controller:
	controller ctrl(	.op(op), .funct(funct),
						.equalD(equalD_ctrl),
						.pcsrcD(pcsrcD), .jumpD(jumpD),
						.regwriteD(regwriteD),
						.memtoregD(regwriteD), .memwriteD(memwriteD),
						.regdstD(regdstD),
						.alusrcD(alusrcD),
						.alucontrolD(alucontrolD)  );

endmodule : mips
