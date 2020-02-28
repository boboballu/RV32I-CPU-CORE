// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// 0th module in the machinary - purely combinatioal
// control signals - pcsrcD
// Datapath nets inputs - pcplus4F[Fetch], pcbranchD[Decode] 
// Datapath nets putput - pc [flopped in pc register]
module pc_gen (
				input logic pcsrcD,
				input logic [31:0] pcbranchD,
				input logic [31:0] pcplus4F,
				output logic [31:0] pc
				);
	
	assign pc = pcsrcD ? pcbranchD : pcplus4F;
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

// 3rd module in the machinary - purely combinational
// control signals - alusrcE, aluctrlE, regdstE
// hazard signals - forwardAE, forwardBE
// datapath nets inputs - A, B, signimmD
// bypass nets inputs - resultW, aluoutM 
// datapath nets outputs - aluoutE, writedataE
// inputs to hazard unit from EX - rsE, rtE, writeregE

/********************************************************************************/ 
module EX_comb (
				input logic alusrcE, input logic [2:0] aluctrlE, input logic regdstE,
				input logic [1:0] forwardAE, input logic [1:0] forwardBE,
				input logic [31:0] A, input logic [31:0] B, input logic [31:0] signimmD,
				input logic [31:0] resultW, input logic [31:0] aluoutM,
				output logic [31:0] aluoutE, output logic [31:0] writedataE
				);
	logic [31:0] srcAE, srcBE, srcBE_net0;
	logic alu_zero_flag; // unconnected net
	
	assign writedataE = srcBE_net0;
	assign srcBE = alusrcE ? signimmD : srcBE_net0;

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
endmodule

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
endmodule
/********************************************************************************/ 

// 4th module in the machinary - (data cache write is clocked)
// clock - clk
// control signals - memwriteM
// hazard signals -  none
// datapath nets inputs - aluoutM, writedataM
// datapath nets outputs - readdataM
module mem_stage (
				  input logic clk,
				  input logic memwriteM,
				  input logic [31:0] aluoutM, input logic [31:0] writedataM,
				  output logic [31:0] readdataM);
	
	logic [31:0] DMEM [1023:0]; // fixed size - will be changed later
	assign readdataM = DMEM[aluoutM[31:2]];
	always_ff @(posedge clk) begin
		if (memwriteM)	DMEM[aluoutM[31:2]] <= writedataM;
	end
endmodule
/********************************************************************************/ 

// 5th module in the machinary - purely combinational
// control signals - memregW
// datapath nets inputs - readdataW, aluoutW
// datapath nets outputs - resultW
module wb_comb (input logic memregW,
				input logic [31:0] readdataW, input logic [31:0] aluoutW,
				output logic [31:0] resultW);
	assign resultW = memregW ? readdataW : aluoutW;
endmodule		
/********************************************************************************/ 