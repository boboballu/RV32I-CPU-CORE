onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/clk
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/reset
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/writedata
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/dataadr
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/readdata
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/pc
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/instr
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/memwrite
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/id_comb/rf/clk
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/id_comb/rf/we3
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/id_comb/rf/ra1
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/id_comb/rf/ra2
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/id_comb/rf/wa3
add wave -noupdate -radix decimal -radixshowbase 1 /testbench/dut/riscv_32i/id_comb/rf/wd3
add wave -noupdate -radix decimal -radixshowbase 1 /testbench/dut/riscv_32i/id_comb/rf/rd1
add wave -noupdate -radix decimal -radixshowbase 1 /testbench/dut/riscv_32i/id_comb/rf/rd2
add wave -noupdate -radix decimal -radixshowbase 1 /testbench/dut/riscv_32i/id_comb/aluoutM
add wave -noupdate -radix decimal -radixshowbase 1 /testbench/dut/riscv_32i/id_comb/a
add wave -noupdate -radix decimal -radixshowbase 1 /testbench/dut/riscv_32i/id_comb/b
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {38 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 279
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
WaveRestoreZoom {69 ps} {162 ps}
