// class debug_instn;
// 	string instn_type[logic [6:0]] = {
		
// 	};
// 	int rs1, rs2, rd;
// 	int imm;
// endclass : debug_instn


package dbg_pkg;
    typedef struct {
    	logic [31:0] pc;
    	string instn_type_str [logic[6:0]] = {
	    	7'b0110011:	"RTYPE",
			7'b0000011: "LW",
			7'b0100011: "SW",
			7'b0010011: "ADDI",
			7'b1100011: "BEQ",
			7'b1101111: "J",
			7'b1100111: "JALR",
			7'b0010111: "auipc",
			7'b0110111: "lui",
			default: "illegal"
    	};
    	logic [6:0] op;
    	int rs1, rs2, rd;
        
        logic [31:0] result;
        logic dmem_we;
        logic [31:0] dmem_addr; logic [31:0] dmem_wd;
        logic [31:0] dmem_rd; 
        logic alusrc;
        logic regwrite; logic memtoreg;
    }	mem_debug;
    
endpackage
