onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -divider sender_A
add wave -noupdate -radixshowbase 1 /valid_ready_tb/sender_A/clk
add wave -noupdate -radixshowbase 1 /valid_ready_tb/sender_A/reset_n
add wave -noupdate -radixshowbase 1 /valid_ready_tb/sender_A/valid
add wave -noupdate -radixshowbase 1 /valid_ready_tb/sender_A/ready
add wave -noupdate -radix hexadecimal -radixshowbase 1 /valid_ready_tb/sender_A/data
add wave -noupdate /valid_ready_tb/run_sender_driver/index
add wave -noupdate /valid_ready_tb/run_sender_driver/transaction_tracker
add wave -noupdate -divider receiver_B
add wave -noupdate -radixshowbase 1 /valid_ready_tb/receiver_B/clk
add wave -noupdate -radixshowbase 1 /valid_ready_tb/receiver_B/reset_n
add wave -noupdate -radixshowbase 1 /valid_ready_tb/receiver_B/valid
add wave -noupdate -radixshowbase 1 /valid_ready_tb/receiver_B/ready
add wave -noupdate -radix hexadecimal -radixshowbase 1 /valid_ready_tb/receiver_B/data
add wave -noupdate /valid_ready_tb/run_receiver_driver/index
add wave -noupdate /valid_ready_tb/run_receiver_driver/transaction_tracker
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {467 ps} 0}
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
WaveRestoreZoom {408 ps} {502 ps}
