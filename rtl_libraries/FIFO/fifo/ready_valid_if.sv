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

interface ready_valid_if #(DATA_WIDTH = 8) (input clk, reset_n);

logic valid, ready;
logic [DATA_WIDTH-1:0] data;

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
endinterface