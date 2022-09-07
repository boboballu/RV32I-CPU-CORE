// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// master (golden) testbench, checking all the features (uses adHoc testing)
// master testbench updated (15/7/2020)- mimics terminal by dumping writes to the address 'd65532
`define TB_TESTBENCH
`include "defs_params_common.svh"
import dbg_pkg::*;

module testbench();
    logic clk;
    logic reset;
    logic [31:0] writedata, dataadr;
    logic [31:0] readdata, pc, instr;
    logic memwrite;
    int instn_cycle = 1;

    // instantiate device to be tested
    top dut (.clk(clk), .reset(reset), 

            .writedata(writedata), .dataadr(dataadr),
            .readdata(readdata), .pc(pc), .instr(instr), 
            .memwrite(memwrite)
    );
    
    // initialize test
    initial begin
        # EXE_TIME;
        // terminal footer
        $display (); $display ();
        $stop;
    end

/********************************************************************************/
    // reset generation / terminal header
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
`ifdef WB_DEBUG
        // debug at writeback stage
    string instn_type;// [4] = {"reg-reg", "load", "store", "branch"};
    logic memaccessW;
    logic jumpM, jalrM;
    logic jumpW, jalrW;
    always@ (posedge clk or negedge reset) begin
        if (!reset) begin
            memaccessW         <= 'b0;
            {jumpW, jumpM}     <= 'b0;
        end
        else begin
            memaccessW     <= dut.memaccessM;
            jumpM         <= dut.riscv_32i.jumpE;
            jumpW        <= jumpM;
        end
    end
    always@ (negedge clk) begin    
        if (reset) begin
            if (dut.riscv_32i.regwriteW) begin
                if (dut.riscv_32i.memtoregW)
                    instn_type = "load";
                else if (jumpW)
                    instn_type = "jump";
                else if (jalrW)
                    instn_type = "jalr";
                else
                    instn_type = "reg-reg";
            end
            else begin
                if (memaccessW)
                    instn_type = "store";
                if (dut.riscv_32i.branchW)
                    instn_type = "branch";
                else
                    instn_type = "bbl";
            end
            
            instn_cycle++;
        end
    end

    always @ (dut.riscv_32i.pcW) begin
        $display ("instn_cycle: %d; PC: %x; %s; data: %d", 
                        instn_cycle, dut.riscv_32i.pcW, instn_type, dut.riscv_32i.resultW
                );
    end

`endif
/********************************************************************************/
`ifdef MEM_DEBUG
    always @(negedge clk) begin
        if (reset) begin
            if (memwrite) begin
                $display ("instn_cycle : %d pc %x store : dataadr: %d writedata: %x", instn_cycle, dut.riscv_32i.pcM, dataadr, $signed(writedata));
                // D_cache_address and D_cache_data not used for testing anymore
                if (dataadr === D_cache_address & $signed(writedata) === D_cache_data) begin
                    $display("Simulation succeeded");
                    $stop;
                end
            end
            else if (dut.riscv_32i.regwriteM) begin
                if (dut.riscv_32i.memtoregM) begin
                    $display ("instn_cycle : %d pc %x load : dataadr: %d readdata: %x", instn_cycle, dut.riscv_32i.pcM, dataadr, $signed(readdata));
                end
                else begin
                    if (dut.riscv_32i.dmem_addr === 32'bx) begin
                        $display ("instn_cycle : %d pc %x nop/squashed instn-taken branch: data: %d", instn_cycle, dut.riscv_32i.pcM, dataadr);
                    end
                    else begin
                        $display ("instn_cycle : %d pc %x ALU/Addi : data: %d", instn_cycle, dut.riscv_32i.pcM, dataadr);
                    end
                end        
            end

            else begin
                if (dataadr === 0)
                    $display ("instn_cycle : %d pc %x bubble/branch : data: %d", instn_cycle, dut.riscv_32i.pcM, dataadr);
                else 
                    $display ("instn_cycle : %d pc %x branch : data: %d", instn_cycle, dut.riscv_32i.pcM, dataadr);
            end
            instn_cycle++;
        end
        if (memwrite) begin
            if (dataadr == CONSOLE_ADDR) begin
                $write("%d", writedata);
            end
            else if (dataadr == HALT_ADDR) begin
                $display("\nHALT");
                $stop;
            end
        end
    end

`else
/********************************************************************************/
    // normal console print
    always @(reset, memwrite, dataadr) begin
        if (memwrite) begin
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
endmodule : testbench

/********************************************************************************/
