onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/clock
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/reset
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/req
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/we
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/addr
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/byte_mask
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/write_word
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/miss
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/read_word
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/mem_req
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/cache/mem_done
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/cache/mem_addr
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/mem_read_addr
add wave -noupdate -height 25 -radix hexadecimal -childformat {{{/tb/cache/mem_read_block[7]} -radix hexadecimal} {{/tb/cache/mem_read_block[6]} -radix hexadecimal} {{/tb/cache/mem_read_block[5]} -radix hexadecimal} {{/tb/cache/mem_read_block[4]} -radix hexadecimal} {{/tb/cache/mem_read_block[3]} -radix hexadecimal} {{/tb/cache/mem_read_block[2]} -radix hexadecimal} {{/tb/cache/mem_read_block[1]} -radix hexadecimal} {{/tb/cache/mem_read_block[0]} -radix hexadecimal}} -radixshowbase 1 -subitemconfig {{/tb/cache/mem_read_block[7]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/cache/mem_read_block[6]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/cache/mem_read_block[5]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/cache/mem_read_block[4]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/cache/mem_read_block[3]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/cache/mem_read_block[2]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/cache/mem_read_block[1]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/cache/mem_read_block[0]} {-height 17 -radix hexadecimal -radixshowbase 1}} /tb/cache/mem_read_block
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/mem_we
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/mem_write_addr
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/mem_write_block
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/mem_miss
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/addr_tag
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/addr_index
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/addr_offset
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/cache
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/assoc_match_index
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/assoc_lru_index
add wave -noupdate -height 25 -radix hexadecimal -radixshowbase 1 /tb/cache/assoc_mru_index
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {41 ps} 0}
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
WaveRestoreZoom {0 ps} {106 ps}
