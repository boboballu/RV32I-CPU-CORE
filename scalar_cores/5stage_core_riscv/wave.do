onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /testbench/dut/riscv_32i/Dwait
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/clk
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/reset
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pc_imem
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/imem_instn
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/dmem_we
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/dmem_addr
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/dmem_wd
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/dmem_rd
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pc_genF_in
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pc_genF_out
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pcD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pcE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pcM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pcW
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/instnF
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pcplus4F
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/instnD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pcplus4D
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/jumpimmD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/branchimmD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/utypeimmD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/itypeimmD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/stypeimmD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/aD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/bD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/signimmD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/pcplus4E
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/aE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/bE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/signimmE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/aluoutE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/writedataE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/aluoutM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/writedataM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/readdataM
add wave -noupdate -radix decimal -radixshowbase 1 /testbench/dut/riscv_32i/aluoutM_out
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/readdataW
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/aluoutW
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/resultW
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/opD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/funct3D
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/funct7D
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/jalrD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/auipcD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/luiD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/branchD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/br_takenD
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
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/alusrcE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/alu_subE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/alucontrolE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/regwriteM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/memtoregM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/memwriteM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/regwriteW
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/memtoregW
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
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/stallF
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/stallD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/stallE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/stallM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/stallW
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/flushF
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/flushD
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/flushE
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/flushM
add wave -noupdate -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/flushW
add wave -noupdate /testbench/dut/riscv_32i/BTBHitF
add wave -noupdate /testbench/dut/riscv_32i/BpredF
add wave -noupdate /testbench/dut/riscv_32i/BTBHitD
add wave -noupdate /testbench/dut/riscv_32i/BpredD
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {13 ps} 0}
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
WaveRestoreZoom {10 ps} {107 ps}
