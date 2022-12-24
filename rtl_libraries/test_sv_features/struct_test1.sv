// Code your design here
// Code your design here
module test();

  // the struct has to be packed for synthesis
  typedef struct packed {
    logic [3:0] a, b;
  } test_t;
 
  test_t t1 = '{'d2,'d3};
  logic [$bits(t1)-1:0] test_t_packed_signal;
  initial begin
    test_t_packed_signal = t1;
    // The below will fail since struct cannot be accessed as a logic which %h
    // modifier looks for
    // $display("struct var t1 contents: %h", t1);

    // So, we use $bits to determine total number of bits in t1 and created
    // a new logic (wire) test_t_packed_signal

    $display ("number of $bits in t1 %d", $bits(t1));
    $display ("t1 as a packed logic signal %08x", test_t_packed_signal);
  end
endmodule
