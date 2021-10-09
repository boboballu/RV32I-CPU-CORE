onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal -radixshowbase 1 /fifo_tb/clk
add wave -noupdate -radix hexadecimal -radixshowbase 1 /fifo_tb/reset_n
add wave -noupdate -radix hexadecimal -radixshowbase 1 /fifo_tb/w_req
add wave -noupdate -radix hexadecimal -radixshowbase 1 /fifo_tb/r_req
add wave -noupdate -radix decimal -radixshowbase 1 /fifo_tb/w_data
add wave -noupdate -radix decimal -radixshowbase 1 /fifo_tb/r_data
add wave -noupdate -radix hexadecimal -radixshowbase 1 /fifo_tb/head
add wave -noupdate -radix hexadecimal -radixshowbase 1 /fifo_tb/tail
add wave -noupdate -radix hexadecimal -radixshowbase 1 /fifo_tb/w_stall
add wave -noupdate -radix hexadecimal -radixshowbase 1 /fifo_tb/r_stall
add wave -noupdate -divider w_run_driver
add wave -noupdate /fifo_tb/w_run_driver/w_i
add wave -noupdate -divider r_run_driver
add wave -noupdate /fifo_tb/r_run_driver/r_i
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {163 ps} 0}
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
configure wave -timelineunits ns
update
WaveRestoreZoom {12 ps} {107 ps}
