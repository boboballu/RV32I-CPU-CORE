onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/clk
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/reset
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pc
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/instr
add wave -noupdate -height 25 -radix decimal -radixshowbase 1 /testbench/dut/mips/dp/alu/srca
add wave -noupdate -height 25 -radix decimal -radixshowbase 1 /testbench/dut/mips/dp/alu/srcb
add wave -noupdate -height 25 -radix decimal -radixshowbase 1 /testbench/dut/mips/aluout
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/alusrc
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/regdst
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/memtoreg
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/regwrite
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/memwrite
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/writedata
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/readdata
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/jump
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pcsrc
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/zero
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/alucontrol
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/alu_sub
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {14 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 235
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
WaveRestoreZoom {0 ps} {70 ps}
