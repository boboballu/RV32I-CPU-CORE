// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define TB_TESTBENCH
`include "defs_params_common.svh"
import dbg_pkg::*;

module testbench();
    logic clk;
    logic reset;
    logic [31:0] writedata, dataadr;
    logic [31:0] readdata, pc, instr;
    logic memwrite;

    // mem check variables filled from command line args
    integer D_cache_address, D_cache_data;

    // debug variable
    `ifdef MEM_DEBUG
    mem_debug dbg;
    assign dbg.funct3             = dut.riscv_32i.c_bus.instr[14:12];
    assign dbg.alu_sub_funct7     = dut.riscv_32i.c_bus.instr[30];
    assign dbg.pc                  = dut.pc;
    assign dbg.op                  = dut.riscv_32i.c_bus.instr[6:0];
    assign dbg.rs1                  = dut.riscv_32i.c_bus.instr[19:15];
    assign dbg.rs2               = dut.riscv_32i.c_bus.instr[24:20];
    assign dbg.rd                = dut.riscv_32i.c_bus.instr[11:7];

    assign dbg.result            = dut.riscv_32i.datapath.result;

    assign dbg.dmem_we       = dut.riscv_32i.c_bus.memwrite;
    assign dbg.dmem_addr     = dut.riscv_32i.dmem_addr;
    assign dbg.dmem_wd       = dut.riscv_32i.dmem_wd;
    assign dbg.dmem_rd       = dut.riscv_32i.dmem_rd;

    assign dbg.alusrc       = dut.riscv_32i.c_bus.alusrc;
    assign dbg.regwrite     = dut.riscv_32i.c_bus.regwrite;
    assign dbg.memtoreg     = dut.riscv_32i.c_bus.memtoreg;
    `endif

    // instantiate device to be tested
    top dut (.clk(clk), .reset(reset),
            .writedata(writedata), .dataadr(dataadr),
            .readdata(readdata), .pc(pc), .instr(instr),
            .memwrite(memwrite)
    );

    // debug variable
    `ifdef MEM_DEBUG
    // initialize the associative arrays for mem_debug
    initial begin
        dbg.instn_type_str     = initialize_instn_type_str();
        dbg.instn_str         = initialize_instn_str();
    end
    `endif
    
    // dump var for gtkwave
    `ifdef DUMP_VCD
     initial begin
        $dumpfile("dumpwave.vcd")
        $dumpvars(0, testbench);
    end
    `endif

    // initialize test
    initial begin
        #EXE_TIME
        // console trailer
        $display (); $display ();
        $stop;
    end

/********************************************************************************/
    // reset generator
    initial begin
        reset <= 0; # 22; reset <= 1;
        $display (); $display ();
        $display ("==> Console [0x%08x] print - writes to the addr treated as a console print msg <==", CONSOLE_ADDR);
        $display (); $display ();
    end
    // generate clock to sequence tests
    always begin
        clk <= 1; # 5; clk <= 0; # 5;
    end

/********************************************************************************/
// check results
`ifdef MEM_DEBUG
    always @(negedge clk) begin
        if (reset) begin
            if ((dbg.instn_type_str[dbg.op] != "INVALID") && (dbg.instn_type_str[dbg.op] != "J"))
            begin
                $write ("%t; pc: %x; op: %s; instr: %s; rd :%d; rs1: %d; rs2: %d; ", $time, dbg.pc, dbg.instn_type_str[dbg.op], dbg.instn_str[dbg.op][dbg.funct3][dbg.alu_sub_funct7], dbg.rd, dbg.rs1, dbg.rs2);
                $write (" | srca: %d; srcb: %d; res: %d\n", dut.riscv_32i.datapath.srca, dut.riscv_32i.datapath.srcb, dbg.result);
            end
        end
        if (dbg.instn_type_str[dbg.op] == "LW") begin
            $display("%t load-> addr: %d; regwrite %b; result :%08x", $time, dataadr, dbg.regwrite, dbg.result);
        end

        if (memwrite) begin
            $display ("%t: dataadr: %d  writedata: %x", $time, dataadr, signed'(writedata));
            if (dataadr===D_cache_address) begin
                if (writedata===D_cache_data) begin
                    $display("Simulation succeeded");
                end
                else begin
                    $display("Simulation stops when sw at mem[%d] encountered", D_cache_address);
                end
            end
        end
        if (memwrite) begin
            if (dataadr == CONSOLE_ADDR) begin
                $write("%c", writedata);
            end
            else if (dataadr == HALT_ADDR) begin
                $display("\nHALT");
                $stop;
            end
        end
    end

`else
/********************************************************************************/
    always @(reset, memwrite, dataadr) begin
        if (memwrite) begin
            //$display("here : %d", dataadr);
            if (dataadr == CONSOLE_ADDR) begin
                $write(CONSOLE_FORMAT, writedata);
            end
            else if (dataadr == HALT_ADDR) begin
                $display("\n");
                $stop;
            end
        end
    end
`endif

/********************************************************************************/

int fp;
int imem_trace_pc, imem_trace_instn;
int imem_trace_status;
int imem_trace_reg[32];
initial begin : imem_trace
    fp = $fopen("imem_reg.dump", "r");
    
    // if (!$feof(fp)) begin
    //     imem_trace_status = $fscanf(fp, "%s %h %s %h", filler1, imem_trace_pc, filler2, imem_trace_instn);
    //     if ( imem_trace_status != 4 ) begin
    //         $display ("ERROR reading file : %d %s %h %s %h", imem_trace_status, filler1, imem_trace_pc, filler2, imem_trace_instn);
    //         $display ("!!! Make sure the trace_file doesn't end with a NEWLINE !!!");
    //         $stop;
    //     end
    //     compare_imem_trace (imem_trace_pc, imem_trace_instn);
    // end
end : imem_trace

always @ (posedge clk) begin : imem_comparison
    if ( ( (!dut.riscv_32i.imem_wait) & (!dut.riscv_32i.dmem_wait) ) & reset ) begin //(!dut.riscv_32i.dmem_wait) )
        if (!$feof(fp)) begin
            imem_trace_status = $fscanf(fp, "%h,%h,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
            imem_trace_pc, imem_trace_instn,
            imem_trace_reg[0], imem_trace_reg[1], imem_trace_reg[2], imem_trace_reg[3],
            imem_trace_reg[4], imem_trace_reg[5], imem_trace_reg[6], imem_trace_reg[7],
            imem_trace_reg[8], imem_trace_reg[9], imem_trace_reg[10], imem_trace_reg[11],
            imem_trace_reg[12], imem_trace_reg[13], imem_trace_reg[14], imem_trace_reg[15],
            imem_trace_reg[16], imem_trace_reg[17], imem_trace_reg[18], imem_trace_reg[19],
            imem_trace_reg[20], imem_trace_reg[21], imem_trace_reg[22], imem_trace_reg[23],
            imem_trace_reg[24], imem_trace_reg[25], imem_trace_reg[26], imem_trace_reg[27],
            imem_trace_reg[28], imem_trace_reg[29], imem_trace_reg[30], imem_trace_reg[31]
            );
            if ( imem_trace_status != 34 ) begin
                $display ("ERROR reading file : %d %h %h", imem_trace_status, imem_trace_pc, imem_trace_instn);
                $display ("!!! Make sure the trace_file doesn't end with a NEWLINE !!!");
                $stop;
            end
            if (imem_trace_pc != dut.riscv_32i.imem_pc_addr) begin
                $display ("PC address mismatch; rtlPC: %h tracePC: %h", dut.riscv_32i.imem_pc_addr, imem_trace_pc);
                $stop;
            end
            if (imem_trace_instn != dut.riscv_32i.imem_instn) begin
                $display ("Instn mismatch; rtlInstn: %h traceInstn: %h", dut.riscv_32i.imem_instn, imem_trace_instn);
                $stop;
            end

            #4;
            for (int i=1; i<32; i++) begin
                if (imem_trace_reg[i] != dut.riscv_32i.datapath.rf.rf[i]) begin
                    $display ("reg[%0d] mismatch; rtlReg: %0d traceReg: %0d", i, dut.riscv_32i.datapath.rf.rf[i], imem_trace_reg[i]);
                    $stop;
                end
            end
        end
    end
end : imem_comparison

endmodule : testbench