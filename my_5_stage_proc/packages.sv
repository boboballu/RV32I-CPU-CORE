// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// This package is included in all the files
// Serves only for debugging purposes - Debug done in mem stage
package dbg_pkg;
    typedef struct {
        logic dmem_we;
        logic [31:0] dmem_addr; logic [31:0] dmem_wd;
        logic [31:0] dmem_rd; 
        logic regwriteM; logic memtoregM;
    }	mem_debug;
endpackage