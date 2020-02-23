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
 
module EX_comb (
				input logic alusrcE, input logic [2:0] aluctrlE, input logic regdstE,
				input logic [1:0] forwardAE, input logic [1:0] forwardBE,
				input logic [31:0] A, input logic [31:0] B, input logic [31:0] signimmD,
				input logic [31:0] resultW, input logic [31:0] aluoutM,
				input logic [4:0] rdE, input logic [4:0] rtE,
				output logic [31:0] aluoutE, output logic [31:0] writedataE,
				output logic [4:0] writeregE
				);
	logic [31:0] srcAE, srcBE, srcBE_net0;
	
	assign writedataE = srcBE_net0;
	assign srcBE = alusrcE ? signimmD : srcBE_net0;
	assign writeregE = regdstE ? rdE : rtE;

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

	always_comb begin // alu
		case (aluctrlE)
			3'b000: aluoutE <= srcAE & srcBE;
			3'b001: aluoutE <= srcAE | srcBE;
			3'b010: aluoutE <= srcAE + srcBE;

			3'b100: aluoutE <= srcAE & (~srcBE);
			3'b101: aluoutE <= srcAE | (~srcBE);
			3'b110: aluoutE <= srcAE - srcBE;
			3'b111: aluoutE <= (srcAE < srcBE) ? 32'd1 : 32'd0;
			default: aluoutE<= 32'bx;
		endcase
	end
endmodule






