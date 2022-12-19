// assert_after_event(
//                      clk, reset_n, 
//                      event, event_start, event_end, event_cycles, 
//                      event_b, event_b_start, event_b_end, event_b_cycles
//) -> change in signal after an event occurs
//      1 -> if event(x === 1) then assert(y === 3) after 2 cycles
//      2 -> if event(x === 0->1 in 1cycle) then assert(y === 3->4 in 1cycle) after 2cycles
//      3 -> if event(x === x->2 in 1cycle) then asseet(y === x->4 in 1cycle) after 3cycles

module assert_after_event_a #(
    parameter type EVENT_A_T  = logic[3:0],
    parameter type EVENT_B_T = logic[3:0],
    parameter int event_a_cycles = 0,
    parameter int event_b_cycles = 0,
    parameter int cycles_after_event_a = 1
) (
    input logic clk, reset_n,
    input EVENT_A_T event_a,
    input EVENT_A_T event_a_start,
    input EVENT_A_T event_a_end,

    input EVENT_B_T event_b,
    input EVENT_B_T event_b_start,
    input EVENT_B_T event_b_end,

);

    bit event_a_flag = 1'b0;
    int cycles_after_event_a_counter = 0;

    EVENT_A_T [event_a_cycles-1:0] event_a_ffs;
    EVENT_B_T [event_b_cycles-1:0] event_b_ffs;

    always_ff @(posedge clk or negedge reset_n) begin
        if (!reset_n) begin
        end
        else begin
            event_a_ffs <= {event_a_ffs[event_a_cycles-2:0], event_a};
            event_b_ffs <= {event_b_ffs[event_b_cycles-2:0], event_b};
        end

        if ( (event_a === event_a_end) && (event_a_ffs[event_a_cycles-1] === event_a_start) ) begin
            $display("EVENT A occured TIME: %t | event_a_start %b | event_a_end %b", $time, event_a_start, event_a_end);
            event_a_flag = 1'b1;
        end

        if (event_a_flag === 1'b1) begin
            cycles_after_event_a_counter <= cycles_after_event_a_counter + 1;
        end

        if (cycles_after_event_a_counter === cycles_after_event_a) begin
            assert ( (event_b === event_b_end) && (event_b_ffs[event_b_cycles-1] === event_b_start) ) begin
                $display("EVENT B occured TIME: %t | event_b_start %b | event_b_end %b", $time, event_b_start, event_b_end);
            end
            else begin
                $display("EVENT B Assertion failure TIME: %t | event_b_start %b | event_b_end %b", $time, event_b_start, event_b_end);
            end
            event_a_flag = 1'b0;
            cycles_after_event_a_counter <= 0;
        end
    end

endmodule : assert_after_event_a