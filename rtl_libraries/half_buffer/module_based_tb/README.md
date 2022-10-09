valid_ready_tb is a generic tb that can be used for all the interface tests that use valid_ready protocol.

Look for in the module_baded_tb directory:
 - grep "\[EDIT" *
  - [EDIT*] -> Mandatory Edits
  - [EDIT]  -> Optional Edits

view wlf file in Modelsim:
 - vsim -view vsim.wlf
To capture all the signals recursively in wlf
 - <in modelsim shell> log * -r

Examine . Change a signal in Modelsim:
 - Eg:
  - VSIM> examine -time 675 sim:/lock/curr_state_r \
    \# code_2
  - VSIM> examine -binary /sttran/count_v \
    \# 00000000000000000000000000000011
  - VSIM> change sttran/count_v 12 \

make help on how to run