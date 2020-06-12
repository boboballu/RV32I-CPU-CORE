onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/clk
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/reset
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pc_imem
add wave -noupdate -radix hexadecimal -childformat {{{/testbench/dut/riscv_32i/imem_instn[31]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[30]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[29]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[28]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[27]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[26]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[25]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[24]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[23]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[22]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[21]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[20]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[19]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[18]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[17]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[16]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[15]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[14]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[13]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[12]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[11]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[10]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[9]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[8]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[7]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[6]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[5]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[4]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[3]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[2]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[1]} -radix hexadecimal} {{/testbench/dut/riscv_32i/imem_instn[0]} -radix hexadecimal}} -radixshowbase 1 -subitemconfig {{/testbench/dut/riscv_32i/imem_instn[31]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[30]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[29]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[28]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[27]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[26]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[25]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[24]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[23]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[22]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[21]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[20]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[19]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[18]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[17]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[16]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[15]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[14]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[13]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[12]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[11]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[10]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[9]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[8]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[7]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[6]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[5]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[4]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[3]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[2]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[1]} {-radix hexadecimal -radixshowbase 1} {/testbench/dut/riscv_32i/imem_instn[0]} {-radix hexadecimal -radixshowbase 1}} /testbench/dut/riscv_32i/imem_instn
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pcplus4F
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/stallF
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/flushF
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/dmem_we
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/dmem_addr
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/dmem_wd
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/dmem_rd
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/debug
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pc_genF_in
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pc_genF_out
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/instnF
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/instnD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pcplus4D
add wave -noupdate -radix decimal -radixshowbase 1 /testbench/dut/riscv_32i/aD
add wave -noupdate -radix decimal -radixshowbase 1 /testbench/dut/riscv_32i/bD
add wave -noupdate -radix decimal -radixshowbase 1 /testbench/dut/riscv_32i/signimmD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pcbranchD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/jump_targetD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/equalD_ctrl
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pcplus4E
add wave -noupdate -radix decimal -radixshowbase 1 /testbench/dut/riscv_32i/aE
add wave -noupdate -radix decimal -radixshowbase 1 /testbench/dut/riscv_32i/bE
add wave -noupdate -radix decimal -radixshowbase 1 /testbench/dut/riscv_32i/signimmE
add wave -noupdate -radix decimal -radixshowbase 1 /testbench/dut/riscv_32i/resultW
add wave -noupdate -radix decimal -radixshowbase 1 /testbench/dut/riscv_32i/aluoutM_out
add wave -noupdate -radix decimal -radixshowbase 1 /testbench/dut/riscv_32i/aluoutE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/alusrcE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/writedataE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/aluoutM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/writedataM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/readdataM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/readdataW
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/aluoutW
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/opD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/funct3D
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/funct7D
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/branchD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pcsrcD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/jumpD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/regwriteD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/memtoregD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/memwriteD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/alusrcD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/alu_subD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/alucontrolD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/jumpE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/regwriteE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/memtoregE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/memwriteE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/alu_subE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/alucontrolE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/regwriteM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/memtoregM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/memwriteM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/regwriteW
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/memtoregW
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pcbranchE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pcbranchM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/branchE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/branchM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/zeroE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/zeroM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pcsrcM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/rsD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/rtD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/rdD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/rsE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/rtE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/rdE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/writeregE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/writeregM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/writeregW
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/forwardAD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/forwardBD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/forwardAE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/forwardBE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/stallD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/stallE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/stallM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/stallW
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/flushD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/flushE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/flushM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/flushW
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {52 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 225
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
WaveRestoreZoom {0 ps} {105 ps}
