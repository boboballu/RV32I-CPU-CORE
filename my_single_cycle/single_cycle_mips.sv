module mips(input logic clk, reset,
			output logic [31:0] pc,
			input logic [31:0] instr,
			output logic memwrite,
			output logic [31:0] aluout, writedata,
			input logic [31:0] readdata);
	
	logic memtoreg, alusrc, regdst;
	logic regwrite, jump, pcsrc, zero;
	logic [2:0] alucontrol;
	
	controller c(instr[31:26], instr[5:0], zero, memtoreg, memwrite, pcsrc, alusrc, regdst, regwrite, jump, alucontrol);
	datapath dp(clk, reset, memtoreg, pcsrc, alusrc, regdst, regwrite, jump, alucontrol, zero, pc, instr, aluout, writedata, readdata);
	
	// debug
	string alu_function[logic] = {6'b100000:"add", 
	6'b100010:"sub",
	6'b100100:"and",
	6'b100101:"or",
	6'b101010:"slt"
	};

	integer cycle=0;
	always@(negedge (clk&(!reset))) begin
		case (instr[31:26]) // opcode
			6'b000000 : begin 
						$display("time | PC | opcode : instr[31:26] | funct : instr[5:0] |  srcA : value | srcB : value | dest : value");
						$display("|%d  | %d | %s  :  %b\t   | %s  :  %b | %d  :   | %d  :   | %d  :  ", cycle, pc, "R type", instr[31:26], alu_function[instr[31:26]], instr[5:0], instr[25:21], instr[20:16], instr[15:11]);
						end
			6'b100011 : begin 
						$display("time | PC |  opcode : instr[31:26] | funct : instr[5:0] |  srcA : value |   imm value  | dest : value");
						$display("|%d  | %d |%s  :  %b\t   | %s  :  %b | %d  :   | %d  :   | %d  :  ", cycle, pc,  "LW", instr[31:26], alu_function[instr[31:26]], instr[5:0], instr[25:21], instr[15:0], instr[20:16]);
						end
			6'b101011 : begin 
						$display("time | PC |  opcode : instr[31:26] | funct : instr[5:0] |  srcA : value |   imm value  | srcB : value");
						$display("|%d  | %d | %s  :  %b\t   | %s  :  %b | %d  :   | %d  :   | %d  :  ", cycle, pc,  "SW", instr[31:26], alu_function[instr[31:26]], instr[5:0], instr[25:21], instr[15:0], instr[20:16]);
						end
			6'b000100 : begin
						$display("time | PC |  opcode : instr[31:26] | funct : instr[5:0] |  srcA : value | srcB : value | target ");
						$display("|%d  | %d | %s  :  %b\t   | %s  :  %b | %d  :   | %d  :   | %d  :  ", cycle, pc,  "BREQ", instr[31:26], alu_function[instr[31:26]], instr[5:0], instr[25:21], instr[20:16], instr[15:0]);
						end
			6'b001000 : begin
						$display("time | PC |  opcode : instr[31:26] | funct : instr[5:0] |  srcA : value |   imm value  | dest : value");
						$display("|%d  | %d | %s  :  %b\t   | %s  :  %b | %d  :   | %d  :   | %d  :  ", cycle, pc,  "ADDI", instr[31:26], alu_function[instr[31:26]], instr[5:0], instr[25:21], instr[15:0], instr[20:16]);
						end
			6'b101010 : begin
						$display("time | PC |  opcode : instr[31:26] | funct : instr[5:0] |  target ");
						$display("|%d  | %d | %s  :  %b\t   | %s  :  %b | %d :  ", cycle, pc,  "j", instr[31:26], alu_function[instr[31:26]], instr[5:0], instr[25:0]);
						end
		endcase
		$display();
		cycle = cycle + 1;
	end
endmodule

module controller(input logic [5:0] op, funct,
				input logic zero,
				output logic memtoreg, memwrite,
				output logic pcsrc, alusrc,
				output logic regdst, regwrite,
				output logic jump,
				output logic [2:0] alucontrol);

	logic [1:0] aluop;
	logic branch;

	maindec md(op, memtoreg, memwrite, branch, alusrc, regdst, regwrite, jump, aluop);
	aludec ad(funct, aluop, alucontrol);
	assign pcsrc = branch & zero;

endmodule

module maindec(	input logic [5:0] op,
				output logic memtoreg, memwrite,
				output logic branch, alusrc,
				output logic regdst, regwrite,
				output logic jump,
				output logic [1:0] aluop);

	logic [8:0] controls;
	assign {regwrite, regdst, alusrc, branch, memwrite, memtoreg, jump, aluop} = controls;
	always_comb begin
		case(op)
			6'b000000: controls <= 9'b110000010; // RTYPE
			6'b100011: controls <= 9'b101001000; // LW
			6'b101011: controls <= 9'b001010000; // SW
			6'b000100: controls <= 9'b000100001; // BEQ
			6'b001000: controls <= 9'b101000000; // ADDI
			6'b000010: controls <= 9'b000000100; // J
			default: controls <= 9'bxxxxxxxxx; // illegal op
		endcase
	end
endmodule

module aludec(	input logic [5:0] funct,
				input logic [1:0] aluop,
				output logic [2:0] alucontrol);
	always_comb
	case(aluop)
		2'b00: alucontrol <= 3'b010; // add (for lw/sw/addi)
		2'b01: alucontrol <= 3'b110; // sub (for beq)
		default: case(funct) // R-type instructions
					6'b100000: alucontrol <= 3'b010; // add
					6'b100010: alucontrol <= 3'b110; // sub
					6'b100100: alucontrol <= 3'b000; // and
					6'b100101: alucontrol <= 3'b001; // or
					6'b101010: alucontrol <= 3'b111; // slt
					default: alucontrol <= 3'bxxx; // ???
				endcase
	endcase
endmodule

module datapath(input logic clk, reset,
				input logic memtoreg, pcsrc,
				input logic alusrc, regdst,
				input logic regwrite, jump,
				input logic [2:0] alucontrol,
				output logic zero,
				output logic [31:0] pc,
				input logic [31:0] instr,
				output logic [31:0] aluout, writedata,
				input logic [31:0] readdata);
	
	logic [4:0] writereg;
	logic [31:0] pcnext, pcnextbr, pcplus4, pcbranch;
	logic [31:0] signimm, signimmsh;
	logic [31:0] srca, srcb;
	logic [31:0] result;
	// next PC logic
	assign pcplus4 = pc + 32'd4;
	assign signimmsh = signimm << 2; // signextended immediate left shifted by 2;  
	always_ff @(posedge clk, posedge reset) begin
		if (reset) begin
			pc <= 0;
		end
		else begin
			case( {pcsrc, jump} )
				2'b00: pc <= pcplus4;
				2'b01: pc <= {pcplus4[31:28], instr[25:0], 2'b00};  // jump
				2'b10: pc <= pcplus4 + signimmsh;  // branch
				default pc <= pcplus4;
			endcase
		end
	end
	// register file logic
	regfile rf(clk, regwrite, instr[25:21], instr[20:16], writereg, result, srca, writedata);
	assign signimm = {{16{instr[15]}}, instr[15:0]};
	assign writereg = regdst ? instr[15:11] : instr[20:16]; // regfile write address
	assign result = memtoreg ? readdata : aluout; // regfile write data
	// ALU logic
	assign srcb = alusrc ? signimm : writedata; // srcb mux
	alu alu(srca, srcb, alucontrol, aluout, zero);
endmodule

/// Generic blocks /////

/// ALU  //////
module alu (input logic [31:0] srca, 
				input logic [31:0] srcb, 
				input logic [2:0] alucontrol, 
				output logic [31:0] aluout, 
				output logic zero);
	
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
	always_ff @(posedge clk) begin
		if (we3) rf[wa3] <= wd3;
	end
	assign rd1 = (ra1 != 0) ? rf[ra1] : 0;
	assign rd2 = (ra2 != 0) ? rf[ra2] : 0;
endmodule