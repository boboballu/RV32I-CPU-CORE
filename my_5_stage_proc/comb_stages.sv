// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/

// 0th module in the machinary - purely combinatioal
// control signals - pcsrcD
// Datapath nets inputs - pcplus4F[Fetch], pcbranchD[Decode], jump_targetD
// Datapath nets putput - pc [flopped in pc register]
module pc_gen (
				input logic pcsrcD, jumpD,
				input logic [31:0] pcbranchD, jump_targetD,
				input logic [31:0] pcplus4F,
				output logic [31:0] pc
				);
	
	//assign pc = pcsrcD ? pcbranchD : pcplus4F;
	always_comb begin
		case ({pcsrcD, jumpD})
			2'b00: pc <= pcplus4F;
			2'b01: pc <= jump_targetD;
			2'b10: pc <= pcbranchD;
			default: pc <= pcplus4F;
		endcase
	end
endmodule : pc_gen
/********************************************************************************/

// 1st module in the machinary - purely combinational (IMEM doesnt have a clk!)
// control signals - none
// datapath nets inputs - pc
// datapath nets outputs - instnF, pcplus4F
module IF_comb (
				input logic [31:0] pc,
				output logic [31:0] instnF,
				output logic [31:0] pcplus4F
				);
	logic [31:0] IMEM [1023:0];
	initial begin
		$readmemh("./assembler/bin", RAM);
	end
	assign instnF = IMEM[pc[31:2]];
	assign pcplus4F = pc + 32'd4;
endmodule : IF_comb
/********************************************************************************/ 

// 2nd module in the machinary - reg file writes at negedge clk
// clock - clk
// control signals - regwriteW
// hazard signals - forwardAD, forwardBD
// bypass nets inputs - resultW, aluoutM
// datapath nets inputs - writeregW, instnD, pcplus4D, 
// datapath nets outputs - A, B, equalD, signimmD, pcbranchD, jump_targetD
module ID_stage (input logic clk,
				 input regwriteW,
				 input forwardAD, forwardBD,
				 input [4:0] writeregW,
				 input [31:0] resultW, aluoutM,
				 input [31:0] instnD, pcplus4D,
				 output [31:0] A, B, signimmD, pcbranchD, jump_targetD,
				 output equalD  );

	wire [31:0] A_reg, B_reg;
	regfile rf (.clk(clk),
				.we3(regwriteW),
				.ra1(instnD[25:21]), .ra2(instnD[20:16]), .wa3(writeregW),
				.wd3(resultW),
				.rd1(A_reg), .rd2(B_reg));

	assign A = forwardAD ? aluoutM : A_reg;
	assign B = forwardBD ? aluoutM : B_reg;

	assign jump_targetD = {pcplus4D[31:28], instnD[25:0], 2'b00};
	assign signimmD = {{16{instnD[15]}}, instnD[15:0]};
	assign pcbranchD = pcplus4D + (signimmD << 2);	
	assign equalD = (A-B) ? 1'b1 : 1'b0;
endmodule : ID_stage

// register file - writes during negedge of clk
module regfile(input logic clk,
				input logic we3,
				input logic [4:0] ra1, ra2, wa3,
				input logic [31:0] wd3,
				output logic [31:0] rd1, rd2);
	logic [31:0] rf[31:0];
	// three ported register file
	// read two ports combinationally
	// write third port on rising edge of clk
	// register 0 hardwired to 0
	// note: for pipelined processor, write third port
	// on falling edge of clk
	always_ff @(negedge clk) begin
		if (we3) rf[wa3] <= wd3;
	end
	assign rd1 = (ra1 != 0) ? rf[ra1] : 0;
	assign rd2 = (ra2 != 0) ? rf[ra2] : 0;
endmodule : regfile
/********************************************************************************/

// 3rd module in the machinary - purely combinational
// control signals - alusrcE, aluctrlE
// hazard signals - forwardAE, forwardBE
// datapath nets inputs - A, B, signimmE
// bypass nets inputs - resultW, aluoutM 
// datapath nets outputs - aluoutE, writedataE
/********************************************************************************/ 
module EX_comb (
				input logic alusrcE, input logic [2:0] aluctrlE,
				input logic [1:0] forwardAE, input logic [1:0] forwardBE,
				input logic [31:0] A, input logic [31:0] B, input logic [31:0] signimmE,
				input logic [31:0] resultW, input logic [31:0] aluoutM,
				output logic [31:0] aluoutE, output logic [31:0] writedataE
				);
	logic [31:0] srcAE, srcBE, srcBE_net0;
	logic alu_zero_flag; // unconnected net
	
	assign writedataE = srcBE_net0;
	assign srcBE = alusrcE ? signimmE : srcBE_net0;

	always_comb begin
		case (forwardAE)
			2'b00: srcAE <= A;	
			2'b01: srcAE <= resultW;
			2'b10: srcAE <= aluoutM;
			default: srcAE <= 32'bx;
		endcase
	end

	always_comb begin
		case (forwardBE)
			2'b00: srcBE_net0 <= B;
			2'b01: srcBE_net0 <= resultW;
			2'b10: srcBE_net0 <= aluoutM;
			default: srcBE_net0 <= 32'bx;
		endcase
	end

	alu alu0 (.sca(srcAE), .scb(srcBE), .alucontrol(aluoutM),
				.aluout(aluoutE), .zero(alu_zero_flag));	
endmodule : EX_comb

/// EX Stage - ALU  //////
module alu (input logic [31:0] srca, input logic [31:0] srcb, 
			input logic [2:0] alucontrol, 
			output logic [31:0] aluout, output logic zero);
	
	assign zero = (aluout == 32'd0) ? 1 : 0;
	always_comb begin
		case(alucontrol)
			3'b000: aluout <= srca & srcb;
			3'b001: aluout <= srca | srcb;
			3'b010: aluout <= srca + srcb;

			3'b100: aluout <= srca & (~srcb);
			3'b101: aluout <= srca | (~srcb);
			3'b110: aluout <= srca - srcb;
			3'b111: aluout <= (srca < srcb) ? 32'd1 : 32'd0;
			default: aluout<= 32'bx;
		endcase
	end
endmodule : alu
/********************************************************************************/

// 4th module in the machinary - (data cache write is clocked)
// clock - clk
// control signals - memwriteM
// hazard signals -  none
// datapath nets inputs - aluoutM, writedataM
// datapath nets outputs - readdataM, aluoutM
module MEM_stage (
				  input logic clk,
				  input logic memwriteM,
				  input logic [31:0] aluoutM, input logic [31:0] writedataM,
				  output logic [31:0] readdataM);
	
	logic [31:0] DMEM [1023:0]; // fixed size - will be changed later
	assign readdataM = DMEM[aluoutM[31:2]];
	always_ff @(posedge clk) begin
		if (memwriteM)	DMEM[aluoutM[31:2]] <= writedataM;
	end
endmodule : MEM_stage
/********************************************************************************/

// 5th module in the machinary - purely combinational
// control signals - memregW
// datapath nets inputs - readdataW, aluoutW
// datapath nets outputs - resultW
module WB_comb (input logic memregW,
				input logic [31:0] readdataW, input logic [31:0] aluoutW,
				output logic [31:0] resultW);
	assign resultW = memregW ? readdataW : aluoutW;
endmodule : WB_comb
/********************************************************************************/