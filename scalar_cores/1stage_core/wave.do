onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/clk
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/reset
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/imem_pc_addr
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/imem_req
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/imem_instn
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/imem_wait
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/dmem_we
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/dmem_addr
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/dmem_wd
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/dmem_mask
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/dmem_req
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/dmem_rd
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/riscv_32i/dmem_wait
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/clock
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/reset
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/req
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/we
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/addr
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/byte_mask
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/write_word
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/miss
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/read_word
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/mem_req
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/mem_addr
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/mem_we
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/mem_read_block
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/mem_write_block
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/mem_miss
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/addr_tag
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/addr_index
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/addr_offset
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/assoc_match_index
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/assoc_lru_index
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/assoc_mru_index
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/mem_read_addr
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/mem_write_addr
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache/mem_done
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache_mem_glue/clock
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache_mem_glue/reset
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache_mem_glue/mem_req
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache_mem_glue/mem_addr
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache_mem_glue/mem_we
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache_mem_glue/mem_read_block
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache_mem_glue/mem_write_block
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache_mem_glue/mem_miss
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache_mem_glue/ram_req
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache_mem_glue/ram_addr
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache_mem_glue/ram_we
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache_mem_glue/ram_read_word
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache_mem_glue/ram_write_word
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache_mem_glue/ram_miss
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache_mem_glue/block_counter
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /testbench/dut/dcache_mem_glue/prev_ram_words
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {0 ps} 0}
quietly wave cursor active 0
configure wave -namecolwidth 150
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
WaveRestoreZoom {0 ps} {988 ps}
