// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/

/* Change this config if the L2 supports 2 ports for read and write at the same time. */
//`define dual_ported_L2
`define single_ported_L2

/* is the cache is fully associative, change the define to FA */
`define SA      // FA, SA are the possible options