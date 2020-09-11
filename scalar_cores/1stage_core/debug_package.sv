// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define DEBUG_PACKAGE
`include "debug_headerfile.svh"
package dbg_pkg;

`ifdef MEM_DEBUG

	typedef struct {

		logic [31:0] pc;

		// 1D associaative array : [op]
		string instn_type_str [logic[6:0]] = '{
			7'b0110011:	"RTYPE",
			7'b0000011: "LW",
			7'b0100011: "SW",
			7'b0010011: "Imm",
			7'b1100011: "BRANCH",
			7'b1101111: "J",
			7'b1100111: "JALR",
			7'b0010111: "auipc",
			7'b0110111: "lui",
			default: "INVALID"
		};

		// 3D associative array : [op][funct3][alu_sub_funct7]
		string instn_str [logic[6:0]][logic[2:0]][logic] = '{
			// RTYPE INSTNS
			7'b0110011: '{
											3'b000: '{1'b0:"ADD", 1'b1:"SUB"},
											3'b001: '{default:"SLL"},
											3'b010: '{default:"SLT"},
											3'b011: '{default:"SLTU"},
											3'b100: '{default:"XOR"},
											3'b101: '{1'b0:"SRL", 1'b1:"SRA"},
											3'b110: '{default:"OR"},
											3'b111: '{default: "AND"},
											default: '{default: "INVALID_RTYPE"}
									},

			// LOAD INSTNS
			7'b0000011: '{
											3'b000: '{default: "LB"},
											3'b001: '{default: "LH"},
											3'b010: '{default: "LW"},
											3'b100: '{default: "LBU"},
											3'b101: '{default: "LHU"},
											default: '{default: "INVALID_LW"}
									},

			// STORE INSTNS
			7'b0100011: '{
											3'b000: '{default: "SB"},
											3'b001: '{default: "SH"},
											3'b010: '{default: "SW"},
											default: '{default: "INVALID_SW"}
									},

			// IMMEDIATE INSTNS
			7'b0010011: '{
											3'b000: '{default:"ADDI"},
											3'b001: '{default:"SLLI"},
											3'b010: '{default:"SLTI"},
											3'b011: '{default:"SLTIU"},
											3'b100: '{default:"XORI"},
											3'b101: '{1'b0:"SRLI", 1'b1:"SRAI"},
											3'b110: '{default:"ORI"},
											3'b111: '{default:"ANDI"},
											default: '{default:"INVALID_IMM"}
									},

			// BRANCH INSTNS
			7'b1100011: '{
											3'b000: '{default: "BEQ"},
											3'b001: '{default: "BNE"},
											3'b100: '{default: "BLT"},
											3'b101: '{default: "BGE"},
											3'b110: '{default: "BLTU"},
											3'b111: '{default: "BGEU"},
											default: '{default: "INVALID_BRANCH"}
									},

			// J INSTN
			7'b1101111: '{ default: '{default:"J"}},

			// JALR INSTN
			7'b1100111: '{ default: '{default:"JALR"}},

			// auipc INSTN
			7'b0010111: '{default: '{default:"auipc"}},

			// lui INSTN
			7'b0110111: '{default: '{default:"lui"}},

			// Default invalid instn
			default: '{default:'{default:"INVALID"}}
		};


		logic [6:0] op;
		logic [2:0] funct3;
		logic alu_sub_funct7;
		logic [4:0] rs1, rs2, rd;

		logic [31:0] result;
		logic dmem_we;
		logic [31:0] dmem_addr; logic [31:0] dmem_wd;
		logic [31:0] dmem_rd;
		logic alusrc;
		logic regwrite; logic memtoreg;

	} mem_debug;

`endif

endpackage
