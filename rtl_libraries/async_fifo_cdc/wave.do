onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /async_fifo_ready_valid_tb/clk_sender
add wave -noupdate /async_fifo_ready_valid_tb/clk_receiver
add wave -noupdate /async_fifo_ready_valid_tb/reset_n
add wave -noupdate /async_fifo_ready_valid_tb/test_type
add wave -noupdate /async_fifo_ready_valid_tb/sender_A_write_ptr
add wave -noupdate /async_fifo_ready_valid_tb/receiver_B_read_ptr
add wave -noupdate -divider Sender_A
add wave -noupdate /async_fifo_ready_valid_tb/sender_A/clk
add wave -noupdate /async_fifo_ready_valid_tb/sender_A/valid
add wave -noupdate /async_fifo_ready_valid_tb/sender_A/ready
add wave -noupdate -radix hexadecimal /async_fifo_ready_valid_tb/sender_A/data
add wave -noupdate -divider Receiver_B
add wave -noupdate /async_fifo_ready_valid_tb/receiver_B/clk
add wave -noupdate /async_fifo_ready_valid_tb/receiver_B/valid
add wave -noupdate /async_fifo_ready_valid_tb/receiver_B/ready
add wave -noupdate -radix hexadecimal /async_fifo_ready_valid_tb/receiver_B/data
add wave -noupdate -divider async_fifo
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/in_write_ptr
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/out_read_ptr
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/w_stall
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/r_stall
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/in/valid
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/in/ready
add wave -noupdate -radix hexadecimal /async_fifo_ready_valid_tb/DUT1/in/data
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/out/valid
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/out/ready
add wave -noupdate -radix hexadecimal /async_fifo_ready_valid_tb/DUT1/out/data
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/fifo_inst/full
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/fifo_inst/empty
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/fifo_inst/head
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/fifo_inst/tail
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/fifo_inst/head_gray
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/fifo_inst/tail_gray
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/fifo_inst/head_gray_synced
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/fifo_inst/tail_gray_synced
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/fifo_inst/head_bin
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/fifo_inst/tail_bin
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/fifo_inst/head_bin_synced
add wave -noupdate /async_fifo_ready_valid_tb/DUT1/fifo_inst/tail_bin_synced
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {150 ps} 0} {{Cursor 2} {233 ps} 0}
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
WaveRestoreZoom {79 ps} {180 ps}
