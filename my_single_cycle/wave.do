onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /testbench/clk
add wave -noupdate /testbench/reset
add wave -noupdate /testbench/writedata
add wave -noupdate /testbench/dataadr
add wave -noupdate /testbench/memwrite
add wave -noupdate /testbench/dut/clk
add wave -noupdate /testbench/dut/reset
add wave -noupdate /testbench/dut/writedata
add wave -noupdate /testbench/dut/dataadr
add wave -noupdate /testbench/dut/memwrite
add wave -noupdate /testbench/dut/pc
add wave -noupdate -radix hexadecimal /testbench/dut/instr
add wave -noupdate /testbench/dut/readdata
add wave -noupdate /testbench/dut/mips/dp/alu/srca
add wave -noupdate /testbench/dut/mips/dp/alu/srcb
add wave -noupdate /testbench/dut/mips/dp/alu/alucontrol
add wave -noupdate /testbench/dut/mips/dp/alu/aluout
add wave -noupdate /testbench/dut/mips/dp/alu/zero
add wave -noupdate /testbench/dut/dmem/clk
add wave -noupdate /testbench/dut/dmem/we
add wave -noupdate -radix decimal /testbench/dut/dmem/a
add wave -noupdate -radix hexadecimal /testbench/dut/dmem/wd
add wave -noupdate /testbench/dut/dmem/rd
add wave -noupdate -radix binary /testbench/dut/mips/dp/alu/alucontrol
add wave -noupdate -radix decimal /testbench/dut/mips/dp/alu/aluout
add wave -noupdate -radix decimal /testbench/dut/mips/dp/alu/srca
add wave -noupdate -radix decimal /testbench/dut/mips/dp/alu/srcb
add wave -noupdate -radix hexadecimal /testbench/dut/mips/dp/alu/zero
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {91 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 345
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
WaveRestoreZoom {75 ps} {116 ps}
