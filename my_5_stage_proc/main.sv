module mips(input logic clk, reset,
			output logic [31:0] pc_imem,
			input logic [31:0] imem_instn,
			output logic dmem_we,
			output logic [31:0] dmem_addr, dmem_wd,
			input logic [31:0] dmem_rd);

	// Datapath of the processor

	// pc_if stage
	pc_gen pc_gen1 (.pcsrcD(), .jumpD(),
					.pcbranchD(), .jump_targetD(),
					.pcplus4(), .pc());
	pc_if pc_if_ff (.clk(clk), 
					.en(), .clear(), 
					.pc(),
					.pcF());

	// if_id stage 
	IF_comb IF_comb1 (	.pc()
						.imem_instn(imem_instn),
						.pc_imem(pc_imem),
						.instnF(),
						.pcplus4F());
	if_id if_id_ff (	.clk(clk),
						.en(), .clear(),
						.rd(), .pcplus4F(),
						.instnD(), .pcplus4D());

endmodule : mips