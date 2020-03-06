onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/id_comb/clk
add wave -noupdate /testcase1/dut/mips/imem_instn
add wave -noupdate /testcase1/dut/mips/instnD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/id_comb/regwriteW
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/id_comb/instnD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/id_comb/pcplus4D
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/id_comb/forwardAD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/id_comb/forwardBD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/id_comb/writeregW
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/id_comb/resultW
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/id_comb/aluoutM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/id_comb/a
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/id_comb/b
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/id_comb/signimmD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/id_comb/pcbranchD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/id_comb/jump_targetD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/id_comb/equalD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/id_comb/A_reg
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/id_comb/B_reg
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/mem_comb/memwriteM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/mem_comb/aluoutM_in
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/mem_comb/writedataM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/mem_comb/dmem_rd
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/mem_comb/dmem_addr
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/mem_comb/dmem_wd
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/mem_comb/dmem_we
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/mem_comb/readdataM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/mem_comb/aluoutM_out
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/branchD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/memtoregE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/regwriteE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/memtoregM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/regwriteM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/regwriteW
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/rsD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/rtD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/rsE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/rtE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/writeregE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/writeregM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/writeregW
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/stallF
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/stallD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/forwardAD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/forwardBD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/flushE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/forwardAE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/forwardBE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/lwstall
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testcase1/dut/mips/hazard_unit1/branchstall
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {244 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 331
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
configure wave -timelineunits ns
update
WaveRestoreZoom {201 ns} {306 ns}
