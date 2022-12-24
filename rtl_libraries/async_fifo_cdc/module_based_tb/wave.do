onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -divider sender_A
add wave -noupdate -radixshowbase 1 /valid_ready_tb/sender_A/clk
add wave -noupdate -radixshowbase 1 /valid_ready_tb/sender_A/reset_n
add wave -noupdate -radixshowbase 1 /valid_ready_tb/sender_A/valid
add wave -noupdate -radixshowbase 1 /valid_ready_tb/sender_A/ready
add wave -noupdate -radix hexadecimal -radixshowbase 1 /valid_ready_tb/sender_A/data
add wave -noupdate /valid_ready_tb/tb_elements/run_sender_driver/index
add wave -noupdate /valid_ready_tb/tb_elements/run_sender_driver/transaction_tracker
add wave -noupdate -divider receiver_B
add wave -noupdate -radixshowbase 1 /valid_ready_tb/receiver_B/clk
add wave -noupdate -radixshowbase 1 /valid_ready_tb/receiver_B/reset_n
add wave -noupdate -radixshowbase 1 /valid_ready_tb/receiver_B/valid
add wave -noupdate -radixshowbase 1 /valid_ready_tb/receiver_B/ready
add wave -noupdate -radix hexadecimal -radixshowbase 1 /valid_ready_tb/receiver_B/data
add wave -noupdate /valid_ready_tb/tb_elements/run_receiver_driver/index
add wave -noupdate /valid_ready_tb/tb_elements/run_receiver_driver/transaction_tracker
add wave -noupdate -divider fifo_inst
add wave -noupdate -radix hexadecimal -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/MEM
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/tail
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/tail_gray
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/head
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/head_gray
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/head_bin_synced
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/head_gray_synced
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/tail_gray_synced
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/tail_bin_synced
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {629 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 275
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
WaveRestoreZoom {561 ps} {655 ps}
