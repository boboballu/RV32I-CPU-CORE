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
add wave -noupdate -divider DUT
add wave -noupdate -radix unsigned -radixshowbase 1 /valid_ready_tb/DUT1/credit_ctr
add wave -noupdate /valid_ready_tb/DUT1/fifo_write_wire/valid
add wave -noupdate /valid_ready_tb/DUT1/fifo_write_wire/ready
add wave -noupdate -radix hexadecimal -radixshowbase 1 /valid_ready_tb/DUT1/fifo_write_wire/data
add wave -noupdate -childformat {{/valid_ready_tb/DUT1/assertion_signals.credit_ctr -radix unsigned -childformat {{{/valid_ready_tb/DUT1/assertion_signals.credit_ctr[0]} -radix unsigned}}}} -expand -subitemconfig {/valid_ready_tb/DUT1/assertion_signals.credit_ctr {-height 17 -radix unsigned -childformat {{{/valid_ready_tb/DUT1/assertion_signals.credit_ctr[0]} -radix unsigned}} -expand} {/valid_ready_tb/DUT1/assertion_signals.credit_ctr[0]} {-height 17 -radix unsigned}} /valid_ready_tb/DUT1/assertion_signals
add wave -noupdate /valid_ready_tb/DUT1/skid_fifo/fifo_inst/write_ptr
add wave -noupdate /valid_ready_tb/DUT1/skid_fifo/fifo_inst/read_ptr
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {94 ps} 0}
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
WaveRestoreZoom {511 ps} {605 ps}
