onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/clock
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/clock
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/PC
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/Regs
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/IDEXA
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/IDEXB
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/EXMEMB
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/EXMEMALUOut
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/MEMWBValue
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/IMemory
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/DMemory
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/IFIDIR
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/IDEXIR
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/EXMEMIR
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/MEMWBIR
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/IFIDrs1
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/IFIDrs2
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/MEMWBrd
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/IDEXop
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/EXMEMop
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/MEMWBop
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/Ain
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/Bin
add wave -noupdate -radix hexadecimal -radixshowbase 1 /tb/DUT/i
add wave -noupdate /tb/reset
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {33 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 209
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
WaveRestoreZoom {0 ps} {129 ps}
