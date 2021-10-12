exe ?= ./execute.hex

all: rtl tb vsim

rtl:
	vlog core.sv

tb:
	vlog core_tb.sv

vsim:
	vsim -do "do wave.do" +EXEC=$(exe) tb

clean:
	rm -f vsim.wlf
# rm -f wlft*
