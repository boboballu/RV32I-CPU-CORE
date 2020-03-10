package dbg_pkg;
    typedef struct {
        logic dmem_we;
        logic [31:0] dmem_addr; logic [31:0] dmem_wd;
        logic [31:0] dmem_rd; 
        logic regwriteM; logic memtoregM;
    }	mem_debug;
endpackage