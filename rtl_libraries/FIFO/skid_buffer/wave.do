onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /ready_valid_tb/clk
add wave -noupdate /ready_valid_tb/reset_n
add wave -noupdate /ready_valid_tb/A_valid
add wave -noupdate /ready_valid_tb/A_ready
add wave -noupdate -radix decimal /ready_valid_tb/A_data
add wave -noupdate /ready_valid_tb/B_valid
add wave -noupdate /ready_valid_tb/B_ready
add wave -noupdate -radix decimal /ready_valid_tb/B_data
add wave -noupdate -divider {Zeroth skid buffer}
add wave -noupdate /ready_valid_tb/DUT1/A_valid
add wave -noupdate -radix decimal /ready_valid_tb/DUT1/A_data
add wave -noupdate /ready_valid_tb/DUT1/A_ready
add wave -noupdate /ready_valid_tb/DUT1/B_valid
add wave -noupdate -radix decimal -childformat {{{/ready_valid_tb/DUT1/B_data[7]} -radix decimal} {{/ready_valid_tb/DUT1/B_data[6]} -radix decimal} {{/ready_valid_tb/DUT1/B_data[5]} -radix decimal} {{/ready_valid_tb/DUT1/B_data[4]} -radix decimal} {{/ready_valid_tb/DUT1/B_data[3]} -radix decimal} {{/ready_valid_tb/DUT1/B_data[2]} -radix decimal} {{/ready_valid_tb/DUT1/B_data[1]} -radix decimal} {{/ready_valid_tb/DUT1/B_data[0]} -radix decimal}} -subitemconfig {{/ready_valid_tb/DUT1/B_data[7]} {-radix decimal} {/ready_valid_tb/DUT1/B_data[6]} {-radix decimal} {/ready_valid_tb/DUT1/B_data[5]} {-radix decimal} {/ready_valid_tb/DUT1/B_data[4]} {-radix decimal} {/ready_valid_tb/DUT1/B_data[3]} {-radix decimal} {/ready_valid_tb/DUT1/B_data[2]} {-radix decimal} {/ready_valid_tb/DUT1/B_data[1]} {-radix decimal} {/ready_valid_tb/DUT1/B_data[0]} {-radix decimal}} /ready_valid_tb/DUT1/B_data
add wave -noupdate /ready_valid_tb/DUT1/B_ready
add wave -noupdate /ready_valid_tb/DUT1/valid
add wave -noupdate /ready_valid_tb/DUT1/ready
add wave -noupdate -radix decimal -childformat {{{/ready_valid_tb/DUT1/data[2]} -radix decimal} {{/ready_valid_tb/DUT1/data[1]} -radix decimal} {{/ready_valid_tb/DUT1/data[0]} -radix decimal}} -subitemconfig {{/ready_valid_tb/DUT1/data[2]} {-radix decimal} {/ready_valid_tb/DUT1/data[1]} {-radix decimal} {/ready_valid_tb/DUT1/data[0]} {-radix decimal}} /ready_valid_tb/DUT1/data
add wave -noupdate -divider {FIFO of zeroth buffer}
add wave -noupdate {/ready_valid_tb/DUT1/nonzero_pipeline_depth/gen_skid_fifo[0]/genblk1/skid_fifo/A_valid}
add wave -noupdate {/ready_valid_tb/DUT1/nonzero_pipeline_depth/gen_skid_fifo[0]/genblk1/skid_fifo/A_data}
add wave -noupdate {/ready_valid_tb/DUT1/nonzero_pipeline_depth/gen_skid_fifo[0]/genblk1/skid_fifo/A_ready}
add wave -noupdate {/ready_valid_tb/DUT1/nonzero_pipeline_depth/gen_skid_fifo[0]/genblk1/skid_fifo/A_write_ptr}
add wave -noupdate {/ready_valid_tb/DUT1/nonzero_pipeline_depth/gen_skid_fifo[0]/genblk1/skid_fifo/B_valid}
add wave -noupdate {/ready_valid_tb/DUT1/nonzero_pipeline_depth/gen_skid_fifo[0]/genblk1/skid_fifo/B_data}
add wave -noupdate {/ready_valid_tb/DUT1/nonzero_pipeline_depth/gen_skid_fifo[0]/genblk1/skid_fifo/B_ready}
add wave -noupdate {/ready_valid_tb/DUT1/nonzero_pipeline_depth/gen_skid_fifo[0]/genblk1/skid_fifo/B_read_ptr}
add wave -noupdate {/ready_valid_tb/DUT1/nonzero_pipeline_depth/gen_skid_fifo[0]/genblk1/skid_fifo/w_stall}
add wave -noupdate {/ready_valid_tb/DUT1/nonzero_pipeline_depth/gen_skid_fifo[0]/genblk1/skid_fifo/r_stall}
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {13 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 413
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
WaveRestoreZoom {0 ps} {84 ps}
