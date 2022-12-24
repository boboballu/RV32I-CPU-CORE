onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -divider async_fifo
add wave -noupdate /async_fifo_valid_ready_tb/clk_sender
add wave -noupdate /async_fifo_valid_ready_tb/clk_receiver
add wave -noupdate /async_fifo_valid_ready_tb/reset_n
add wave -noupdate -radix unsigned /async_fifo_valid_ready_tb/sender_A_write_ptr
add wave -noupdate -radix unsigned /async_fifo_valid_ready_tb/receiver_B_read_ptr
add wave -noupdate -divider Sender_A
add wave -noupdate /async_fifo_valid_ready_tb/sender_A/clk
add wave -noupdate /async_fifo_valid_ready_tb/sender_A/reset_n
add wave -noupdate /async_fifo_valid_ready_tb/sender_A/valid
add wave -noupdate /async_fifo_valid_ready_tb/sender_A/ready
add wave -noupdate -radix hexadecimal /async_fifo_valid_ready_tb/sender_A/data
add wave -noupdate -divider Receiver_B
add wave -noupdate /async_fifo_valid_ready_tb/receiver_B/clk
add wave -noupdate /async_fifo_valid_ready_tb/receiver_B/reset_n
add wave -noupdate /async_fifo_valid_ready_tb/receiver_B/valid
add wave -noupdate /async_fifo_valid_ready_tb/receiver_B/ready
add wave -noupdate -radix hexadecimal /async_fifo_valid_ready_tb/receiver_B/data
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {18 ps} 0} {{Cursor 2} {233 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 339
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
WaveRestoreZoom {0 ps} {101 ps}
