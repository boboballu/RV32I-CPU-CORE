onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/clk
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/reset
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/pc
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/aluout
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/writedata
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/readdata
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/result
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/rs1
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/rs2
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/rd
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/pcplus4
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/signimm
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/branchimm
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/jumpimm
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/stypeimm
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/itypeimm
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/utypeimm
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/srca
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/srcb
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/srcb_net0
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/funct3
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/datapath/funct7
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/c_bus/instr
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/c_bus/op
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/c_bus/funct3
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/c_bus/funct7
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/c_bus/br_taken
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/c_bus/branch
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/c_bus/jump
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/c_bus/jalr
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/c_bus/memtoreg
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/c_bus/memwrite
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/c_bus/pcsrc
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/c_bus/alusrc
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/c_bus/regwrite
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/c_bus/alucontrol
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/c_bus/alu_sub
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/c_bus/auipc
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/c_bus/lui
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {288 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 252
configure wave -valuecolwidth 82
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ps
update
WaveRestoreZoom {0 ps} {105 ps}
