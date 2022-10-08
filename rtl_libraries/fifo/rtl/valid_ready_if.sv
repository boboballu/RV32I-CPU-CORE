//                 Interface Definition
//        +-------------------+------------------+
// +----> | valid             |            valid +----->
//        |                   |                  |
// +----> | data              |            data  +----->
//        |                   |                  |
//        |(receiver modport) |  (sender modport)|
//        |                   |                  |
// <------+ ready             |            ready +<----+
//        |                   |                  |
//        +-------------------+------------------+

interface valid_ready_if #( type DATA_T = logic [7:0] ) (input clk, reset_n);

logic valid, ready;
DATA_T data;

modport sender(
    output valid, data,
    input ready
);

modport receiver(
    input valid, data,
    output ready
);

modport out(
    output valid, data,
    input ready
);

modport in(
    input valid, data,
    output ready
);

modport monitor(
    input valid, data,
    input ready
);
endinterface : valid_ready_if