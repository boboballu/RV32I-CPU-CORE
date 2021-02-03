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
add wave -noupdate -height 25 -radix hexadecimal -childformat {{{/tb/cache/mem_read_block[3]} -radix hexadecimal} {{/tb/cache/mem_read_block[2]} -radix hexadecimal} {{/tb/cache/mem_read_block[1]} -radix hexadecimal} {{/tb/cache/mem_read_block[0]} -radix hexadecimal}} -radixshowbase 1 -expand -subitemconfig {{/tb/cache/mem_read_block[3]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/cache/mem_read_block[2]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/cache/mem_read_block[1]} {-height 17 -radix hexadecimal -radixshowbase 1} {/tb/cache/mem_read_block[0]} {-height 17 -radix hexadecimal -radixshowbase 1}} /tb/cache/mem_read_block
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
add wave -noupdate /tb/rcglue/clock
add wave -noupdate /tb/rcglue/reset
add wave -noupdate /tb/rcglue/mem_req
add wave -noupdate /tb/rcglue/mem_addr
add wave -noupdate /tb/rcglue/mem_we
add wave -noupdate /tb/rcglue/mem_read_block
add wave -noupdate /tb/rcglue/mem_write_block
add wave -noupdate /tb/rcglue/mem_miss
add wave -noupdate /tb/rcglue/ram_req
add wave -noupdate /tb/rcglue/ram_addr
add wave -noupdate /tb/rcglue/ram_we
add wave -noupdate /tb/rcglue/ram_read_word
add wave -noupdate /tb/rcglue/ram_write_word
add wave -noupdate /tb/rcglue/ram_miss
add wave -noupdate /tb/rcglue/block_counter
add wave -noupdate /tb/rcglue/prev_ram_words
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {74 ps} 0}
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
