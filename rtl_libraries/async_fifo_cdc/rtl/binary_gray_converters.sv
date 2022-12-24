//                BINARY TO GRAY
// in_bin3 +---+----------------------------+ out_gray3
//             |
//             |      +-------+
//             +------+       |
//                    | =A^B  +-------------+ out_gray2
//                    |  XOR  |
// in_bin2 +---+------+       |
//             |      +-------+
//             |
//             |      +-------+
//             +------+       |
//                    | =A^B  +-------------+ out_gray1
//                    |  XOR  |
// in_bin1 +---+------+       |
//             |      +-------+
//             |
//             |      +-------+
//             +------+       |
//                    | =A^B  +-------------+ out_gray0
//                    |  XOR  |
// in_bin0 +----------+       |
//                    +-------+

module bin2gray #(
    parameter BIT_WIDTH = 8
)
(
    input logic [BIT_WIDTH-1:0] in_bin,
    output logic [BIT_WIDTH-1:0] out_gray
);
    always_comb begin
        out_gray[BIT_WIDTH-1] = in_bin[BIT_WIDTH-1];
        for (int i=BIT_WIDTH-2; i>=0; i--) begin
            out_gray[i] = in_bin[i] ^ in_bin[i+1];
        end
    end
endmodule : bin2gray


//              GRAY To BINARY
// in_gray3 +-+------------------------------------------+ out_bin3
//            |
//            |  +-------+
//            +--+       |
//               | =A^B  +-+-----------------------------+ out_bin2
//               |  XOR  | |
// in_gray2 +----+       | |
//               +-------+ |
//                         | +-------+
//                         +-+       |
//                           | =A^B  +-+-----------------+ out_bin1
//                           |  XOR  | |
// in_gray1 +----------------+       | |
//                           +-------+ |
//                                     | +-------+
//                                     +-+       |
//                                       | =A^B  +-------- out_bin0
//                                       |  XOR  |
// in_gray0 +----------------------------+       |
//                                       +-------+

module gray2bin #(
    parameter BIT_WIDTH = 8
)
(
    input logic [BIT_WIDTH-1:0] in_gray,
    output logic [BIT_WIDTH-1:0] out_bin
);
    always_comb begin
        out_bin[BIT_WIDTH-1] = in_gray[BIT_WIDTH-1];
        for (int i=BIT_WIDTH-2; i>=0; i--) begin
            out_bin[i] = in_gray[i] ^ out_bin[i+1];
        end
    end
endmodule : gray2bin