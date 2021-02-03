onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/clk
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/reset
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/mem_req
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/mem_addr
add wave -noupdate -radix hexadecimal -childformat {{{/tb/mem_read_block[3]} -radix hexadecimal} {{/tb/mem_read_block[2]} -radix hexadecimal} {{/tb/mem_read_block[1]} -radix hexadecimal} {{/tb/mem_read_block[0]} -radix hexadecimal}} -radixshowbase 1 -expand -subitemconfig {{/tb/mem_read_block[3]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/mem_read_block[2]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/mem_read_block[1]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/mem_read_block[0]} {-height 17 -radix hexadecimal -radixshowbase 1}} /tb/mem_read_block
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/mem_we
add wave -noupdate -radix hexadecimal -childformat {{{/tb/mem_write_block[3]} -radix hexadecimal} {{/tb/mem_write_block[2]} -radix hexadecimal} {{/tb/mem_write_block[1]} -radix hexadecimal} {{/tb/mem_write_block[0]} -radix hexadecimal}} -radixshowbase 1 -expand -subitemconfig {{/tb/mem_write_block[3]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/mem_write_block[2]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/mem_write_block[1]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/mem_write_block[0]} {-height 17 -radix hexadecimal -radixshowbase 1}} /tb/mem_write_block
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/mem_miss
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/dut1/clk
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/dut1/reset
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/dut1/mem_req
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/dut1/mem_addr
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/dut1/mem_read_block
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/dut1/mem_we
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/dut1/mem_write_block
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/dut1/mem_miss
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/dut1/blk_counter_current
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/dut1/blk_counter_next
add wave -noupdate -radix hexadecimal -childformat {{{/tb/dut1/mem_read_reg[3]} -radix hexadecimal} {{/tb/dut1/mem_read_reg[2]} -radix hexadecimal} {{/tb/dut1/mem_read_reg[1]} -radix hexadecimal} {{/tb/dut1/mem_read_reg[0]} -radix hexadecimal}} -radixshowbase 1 -subitemconfig {{/tb/dut1/mem_read_reg[3]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/dut1/mem_read_reg[2]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/dut1/mem_read_reg[1]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/dut1/mem_read_reg[0]} {-height 17 -radix hexadecimal -radixshowbase 1}} /tb/dut1/mem_read_reg
add wave -noupdate /tb/Bus/dmem_req
add wave -noupdate /tb/Bus/dmem_addr
add wave -noupdate /tb/Bus/dmem_we
add wave -noupdate /tb/Bus/dmem_wd
add wave -noupdate /tb/Bus/dmem_rd
add wave -noupdate /tb/Bus/dmem_wait
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {4 ps} 0}
quietly wave cursor active 1
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
WaveRestoreZoom {0 ps} {320 ps}
