// ------ CUSTOM DATATYPES ------ //
//  --- Testbench datastructure types --- //
package tb_rtl_datatypes_pkg;
    // the modules have datatype of the payload of ready-valid protocol parameterized (DATA_T)
    // But for simulation, logic type is not adviced to be used (not adviced to be used in assoc array / queues etc)
    // So, create a datatype for RTL with logic and another datatype for tb with bit
    typedef logic [7:0] rtl_data_t;
    typedef bit   [7:0] tb_data_t;

    // The sequence generator generates a queue of sequences of the below struct datatypes
    // used by driver
    typedef struct {
        bit valid;
        tb_data_t data;
    } sender_t;

    typedef struct {
        bit ready;
    } receiver_t;

    // Used by monitor
    typedef struct {
        int sender_count = 0;
        int receiver_count = 0;
        // Note: Donot use logic datatype in associatve array. It blows up memory and breaks the simulator
        int data_transfer_assoc_array[tb_data_t] = '{8'b0: 1};
    } scoreboard_performance_counter_t;

    // --- Testlists --- //
    // create 2 queue of tests that will be driven by individual drivers by individual run tasks
    // used by driver and generate_testlist
    typedef enum bit [3:0] {PERFECT_SENDER_RECEIVER, BUSY_RECEIVER, RANDOM} test_type_t;

    test_type_t test_type;
    sender_t sender_testlist[$];
    receiver_t receiver_testlist[$];

    // --- monitor / scoreboard performance counters --- //
    scoreboard_performance_counter_t scoreboard_perf_ctr;
endpackage : tb_rtl_datatypes_pkg