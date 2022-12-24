onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -divider sender_A
add wave -noupdate /valid_ready_tb/sender_A/clk
add wave -noupdate /valid_ready_tb/sender_A/reset_n
add wave -noupdate /valid_ready_tb/sender_A/valid
add wave -noupdate /valid_ready_tb/sender_A/ready
add wave -noupdate -radix hexadecimal -radixshowbase 1 /valid_ready_tb/sender_A/data
add wave -noupdate -divider receiver_B
add wave -noupdate /valid_ready_tb/receiver_B/clk
add wave -noupdate /valid_ready_tb/receiver_B/reset_n
add wave -noupdate /valid_ready_tb/receiver_B/valid
add wave -noupdate /valid_ready_tb/receiver_B/ready
add wave -noupdate -radix hexadecimal -radixshowbase 1 /valid_ready_tb/receiver_B/data
add wave -noupdate -divider {FIFO DUT}
add wave -noupdate -radix hexadecimal -childformat {{{/valid_ready_tb/DUT1/fifo_inst/MEM[3]} -radix hexadecimal} {{/valid_ready_tb/DUT1/fifo_inst/MEM[2]} -radix hexadecimal} {{/valid_ready_tb/DUT1/fifo_inst/MEM[1]} -radix hexadecimal} {{/valid_ready_tb/DUT1/fifo_inst/MEM[0]} -radix hexadecimal}} -radixshowbase 1 -subitemconfig {{/valid_ready_tb/DUT1/fifo_inst/MEM[3]} {-radix hexadecimal -radixshowbase 1} {/valid_ready_tb/DUT1/fifo_inst/MEM[2]} {-radix hexadecimal -radixshowbase 1} {/valid_ready_tb/DUT1/fifo_inst/MEM[1]} {-radix hexadecimal -radixshowbase 1} {/valid_ready_tb/DUT1/fifo_inst/MEM[0]} {-radix hexadecimal -radixshowbase 1}} /valid_ready_tb/DUT1/fifo_inst/MEM
add wave -noupdate -radix unsigned -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/write_ptr
add wave -noupdate -radix unsigned -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/read_ptr
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {73 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 368
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
