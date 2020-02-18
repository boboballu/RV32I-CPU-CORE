module pipelined_cpu(
                    input  clk
                    );

	/********************* opcodes**********************************
	R type : opcode 	 Rd  		Rs1 		Rs2	 	 funvtion
				[31:26]  [25:21]	[20:16]     [15:11]  [11:0]

	I type : opcode 		Rd 			Rs1 		immediate
				[21:26]		[25:21] 	[20:16] 	[15:0]
	****************************************************************/ 

	/******************* Mnemonic op codes ***************************/
	parameter NOP = 6'd0;
	/***** R type instructions Register - Register ********/
	parameter ADD  = 6'd1;  parameter SUB  = 6'd2;  parameter AND = 6'd3;  parameter OR  = 6'd4;
	parameter NOR = 6'd5;   parameter XOR = 6'd6;   parameter SLA = 6'd7;  parameter SLL = 6'd8;
	parameter SRA = 6'd9;   parameter SRL = 6'd10; 
	/***** I type instructions ********/
	parameter ADDI = 6'd32;   parameter SUBI = 6'd33; 
	/***** I type instructions  - load and store********/	
	parameter LD = 6'd34; parameter ST = 6'd35;
	/***** I type instructions  - branches********/	
	parameter BEZ = 6'd36; parameter BNE = 6'd37; parameter JMP = 6'd38;
  	/****************************************************************/ 

	/******************* Core cpu parameters ***********************
	** Register File      : 32 general purpose registers(32-bit)
	** Instruction Memory : size 1024; 
	** Instruction Size   : 32 bit;
	****************************************************************/ 
	parameter OPCODE_SIZE = 6; parameter DATA_MEMORY_SIZE = 10; parameter INSTRUCTION_MEMORY_SIZE = 10;

	reg [31:0] DMEM [2 ** DATA_MEMORY_SIZE -1 : 0];	    // Data Memory // [0:1023] regs of 32 bits
	

	// IF stage : PC -> I$ -> IF_ID_stage
	module IF_ID (
					input clk, 
					input pc_mux_ctrl, input [31:0] pc_jmp,
					output reg [9:0] NPC, output reg [31:0] IR
					);
		
		reg [9:0]  PC;
		wire [9:0] pc_adder;  wire [9:0] pc_mux;
		
		reg [31:0] IMEM [2**INSTRUCTION_MEMORY_SIZE  -1 : 0] ;
		
		assign pc_adder = PC + 10'b1;
		assign pc_mux = pc_mux_ctrl ? pc_jmp : pc_adder;

		always@(posedge clk) begin
			PC <= pc_mux;  // change PC if there is a valid branch or jump
		end
		always@(posedge clk) begin
			NPC <= pc_adder;
			IR <= IMEM[PC]; // Instruction Reg
		end
	endmodule

	// ID stage : IR & NPC_IN  -->  NPC_OUT, A, B, IMM, RD, opcode
	module ID_EX(
				input clk,
				input [31:0] reg_wr_data, input [4:0] reg_wr_addr, input reg_wr_en,
				input [31:0] ir, input [9:0] npc_in,

				output reg [9:0] NPC_OUT,	
				output reg signed [31:0] A, output reg signed [31:0] B,
				output reg signed [15:0] IMM,
				output reg [4:0] RD,
				output reg [5:0] OPCODE
				);

		reg [31:0] REGFILE[31:0];	    // General Purpose Registers // [0:31] regs of each 32 bits

// interconnect for src1 src2 dest 		opcode           &   immediate signals 
		wire [4:0] rs1, rs2, rd;  wire [5:0] opcode;  wire signed [15:0] imm;

		assign rd = ir[25:21];
		assign opcode = ir[31:26];
		assign rs1 = ir[20:16];
		assign rs2 = ir[15:11];
		assign imm = ir[15:0];

		always@(posedge clk) begin
			if(reg_wr_en) begin
				REGFILE[reg_wr_addr] <= reg_wr_data;
			end
		end
		always@(negedge clk) begin  // register file read
			NPC_OUT <= npc_in;
			A <= REGFILE[rs1];
			B <= (opcode >= 6'd32) ? 32'd0 : REGFILE[rs2];
			IMM <= {{16{imm[15]}}, {imm[15:0]}};  // sign extension
			RD <= rd;
			OPCODE <= opcode;

		end
	endmodule
