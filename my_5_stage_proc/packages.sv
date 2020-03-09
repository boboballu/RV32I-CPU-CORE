package dbg_pkg;
    typedef struct {
        logic dmem_we;
        logic dmem_addr; logic dmem_wd;
        logic dmem_rd; 
        logic regwriteM; logic memtoregM;
    }	mem_debug;
endpackage