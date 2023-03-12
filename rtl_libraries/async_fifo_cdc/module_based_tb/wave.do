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
add wave -noupdate -divider fifo
add wave -noupdate -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/w_req
add wave -noupdate -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/r_req
add wave -noupdate -radix hexadecimal -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/w_data
add wave -noupdate -radix hexadecimal -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/r_data
add wave -noupdate -radix unsigned -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/write_ptr
add wave -noupdate -radix unsigned -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/read_ptr
add wave -noupdate -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/w_stall
add wave -noupdate -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/r_stall
add wave -noupdate -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/MEM
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/POINTER_WIDTH
add wave -noupdate /valid_ready_tb/async_reset_n
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/sender_reset_n
add wave -noupdate -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/clk_sender
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/wp
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/wp_gray
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/receiver_reset_n
add wave -noupdate -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/clk_receiver
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/rp
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/rp_gray
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/rp_gray_synced
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/wp_gray_synced
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/rp_bin_synced
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/wp_bin_synced
add wave -noupdate -radix unsigned -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/write_ptr_abs
add wave -noupdate -radix unsigned -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/read_ptr_abs
add wave -noupdate -radix unsigned -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/write_ptr_norm
add wave -noupdate -radix unsigned -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/read_ptr_norm
add wave -noupdate -radix unsigned -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/write_occupancy_ctr
add wave -noupdate -radix unsigned -radixshowbase 1 /valid_ready_tb/DUT1/fifo_inst/read_occupancy_ctr
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/rp_wire
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/wp_wire
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/rp_gray_wire
add wave -noupdate /valid_ready_tb/DUT1/fifo_inst/wp_gray_wire
add wave -noupdate -divider sender_A_reset_sync
add wave -noupdate /valid_ready_tb/sender_reset_A/clk
add wave -noupdate /valid_ready_tb/sender_reset_A/async_reset_n
add wave -noupdate /valid_ready_tb/sender_reset_A/sync_reset_n
add wave -noupdate /valid_ready_tb/sender_reset_A/ffs
add wave -noupdate -divider reset_test
add wave -noupdate /valid_ready_tb/async_fifo_reset_gen_test/clk_sender
add wave -noupdate /valid_ready_tb/async_fifo_reset_gen_test/clk_receiver
add wave -noupdate /valid_ready_tb/async_fifo_reset_gen_test/async_reset_n
add wave -noupdate /valid_ready_tb/async_fifo_reset_gen_test/sender_reset_n
add wave -noupdate /valid_ready_tb/async_fifo_reset_gen_test/receiver_reset_n
add wave -noupdate /valid_ready_tb/async_fifo_reset_gen_test/receiver_reset_synced
add wave -noupdate /valid_ready_tb/async_fifo_reset_gen_test/receiver_reset_loopback
add wave -noupdate /valid_ready_tb/async_fifo_reset_gen_test/sender_reset_from_receiver
add wave -noupdate /valid_ready_tb/async_fifo_reset_gen_test/sender_reset_flop
add wave -noupdate /valid_ready_tb/async_fifo_reset_gen_test/receiver_reset_flop
add wave -noupdate /valid_ready_tb/async_fifo_reset_gen_test/sender_reset_synced
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {36 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 372
configure wave -valuecolwidth 81
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
WaveRestoreZoom {18 ps} {105 ps}
