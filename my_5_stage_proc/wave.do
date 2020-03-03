onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pc_gen_comb/pcsrcD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pc_gen_comb/jumpD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pc_gen_comb/pcbranchD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pc_gen_comb/jump_targetD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pc_gen_comb/pcplus4F
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pc_gen_comb/pc
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/clk
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/reset
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/writedata
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/dataadr
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/memwrite
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/pc
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/instr
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/readdata
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/imem/a
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/imem/rd
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pc_if_ff/clk
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pc_if_ff/en
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pc_if_ff/clear
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pc_if_ff/pc
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pc_if_ff/pcF
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/dmem/clk
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/dmem/we
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/dmem/a
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/dmem/wd
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/dmem/rd
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {51 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 289
configure wave -valuecolwidth 100
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
WaveRestoreZoom {0 ps} {112 ps}
