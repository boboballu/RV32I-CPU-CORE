onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -divider sender_A
add wave -noupdate -radixshowbase 1 /ready_valid_tb/sender_A/clk
add wave -noupdate -radixshowbase 1 /ready_valid_tb/sender_A/reset_n
add wave -noupdate -radixshowbase 1 /ready_valid_tb/sender_A/valid
add wave -noupdate -radixshowbase 1 /ready_valid_tb/sender_A/ready
add wave -noupdate -radix hexadecimal -radixshowbase 1 /ready_valid_tb/sender_A/data
add wave -noupdate /ready_valid_tb/run_sender_driver/index
add wave -noupdate /ready_valid_tb/run_sender_driver/transaction_tracker
add wave -noupdate -divider receiver_B
add wave -noupdate -radixshowbase 1 /ready_valid_tb/receiver_B/clk
add wave -noupdate -radixshowbase 1 /ready_valid_tb/receiver_B/reset_n
add wave -noupdate -radixshowbase 1 /ready_valid_tb/receiver_B/valid
add wave -noupdate -radixshowbase 1 /ready_valid_tb/receiver_B/ready
add wave -noupdate -radix hexadecimal -radixshowbase 1 /ready_valid_tb/receiver_B/data
add wave -noupdate /ready_valid_tb/run_receiver_driver/index
add wave -noupdate /ready_valid_tb/run_receiver_driver/transaction_tracker
add wave -noupdate -divider DUT1
add wave -noupdate /ready_valid_tb/DUT1/credit_ctr
add wave -noupdate /ready_valid_tb/DUT1/skid_fifo/in_write_ptr
add wave -noupdate /ready_valid_tb/DUT1/skid_fifo/out_read_ptr
add wave -noupdate /ready_valid_tb/DUT1/ff_to_in_wire_credit
add wave -noupdate /ready_valid_tb/DUT1/fifo_write_wire/ready
add wave -noupdate /ready_valid_tb/DUT1/skid_fifo/fifo_inst/full
add wave -noupdate /ready_valid_tb/DUT1/skid_fifo/fifo_inst/empty
add wave -noupdate /ready_valid_tb/DUT1/in_to_ff_wire_valid
add wave -noupdate -expand -subitemconfig {/ready_valid_tb/DUT1/assertion_signals.credit_ctr -expand} /ready_valid_tb/DUT1/assertion_signals
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {160 ps} 0}
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
WaveRestoreZoom {39 ps} {134 ps}
