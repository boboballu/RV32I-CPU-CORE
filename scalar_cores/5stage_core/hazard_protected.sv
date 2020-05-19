// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`include "debug_headerfile.sv"
import dbg_pkg::*;
module hazard_unit( input logic branchD, jumpD,
					input logic memtoregE, regwriteE,
					input logic memtoregM, regwriteM,
					input logic regwriteW,
					input logic [4:0] rsD, rtD,
					input logic [4:0] rsE, rtE,
					input logic [4:0] writeregE, writeregM, writeregW,
					output logic stallF,
					output logic stallD, forwardAD, forwardBD,
					output logic flushE, output logic [1:0] forwardAE, forwardBE	);
	
	logic lwstall;
	logic branchstall;
	
	/********************************************************************************/
	// *******Data Forwarding***********//
	//data forwarding:(RAW) ex-ex and mem-ex bypass
	
	// Intelectual Property - protected
	`pragma protect begin_protected
`pragma protect version = 1
`pragma protect encrypt_agent = "ModelSim" , encrypt_agent_info = "10.5b"
`pragma protect key_keyowner = "Mentor Graphics Corporation" , key_keyname = "MGC-VERIF-SIM-RSA-2"
`pragma protect key_method = "rsa"
`pragma protect encoding = ( enctype = "base64" , line_length = 64 , bytes = 256 )
`pragma protect key_block
kuyLDkDXPyoAYKLjk10tWsLC2vf7PFknVR4wYROlLNh91JxuLKZg04wY5ZuQ6/jG
or4fDnFp2ybxbF94SqbFcwnLUJkNBz7Zuvb460Y9HAdN1pR5+Eh3glDnEO8Ahz4x
vhgR4HM5WLnK5PEzO90q6EgcrJbhD0P3M/QQPbzDrkoUmswt8divO4HPLhQpe9uL
3rzHU9Ah63JN38s7Y5nMA6ESemncD+7y+T5T0/WGWYh3mv3gEABMvjKQIAcSTyTy
AJrZ7N3fZdndXuTgQ/HV5e1PrTfOOXGVvsAVq/SQ7qgHegjA/DfXrX4oAuzvzQ5V
1qvr2s2DyVfwA2PXadsSUw==
`pragma protect data_method = "aes128-cbc"
`pragma protect encoding = ( enctype = "base64" , line_length = 64 , bytes = 1664 )
`pragma protect data_block
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
`pragma protect end_protected
	// Intelectual Property - protection ends here
endmodule : hazard_unit