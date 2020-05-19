onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pc_if_ff/clk
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pc_if_ff/en
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pc_if_ff/clear
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pc_if_ff/pc
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/mips/pc_if_ff/pcF
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {116 ps} 0}
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
WaveRestoreZoom {27 ps} {143 ps}
