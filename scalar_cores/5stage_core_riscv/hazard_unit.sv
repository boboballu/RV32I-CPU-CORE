// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// hazard_unit - takes care of * Data Forwarding logic * RAW Hazard detection
// * takes care of flush and stall in the pipeline

// inputs - jump/branch information (branchD, jumpD, br_takenD)
// memory and register control information to solve RAW hazard (memtoregE, memtoregM, regwriteE, retwriteM, regwriteW)
// source register addresses (rsD, rtD, rsE, rtE)
// reg destination addresses (writeregE, writeregM, writeregW)
// forward control signals (forwardAD, forwardBD, forwardAE, forwardBE)
// all stall and flush signals for the pipeline regs (stallF, stallD, stallE, stallM, stallW)
// and (flushF, flushD, flushE, flushM, flushW) 
`include "debug_headerfile.svh"
import dbg_pkg::*;
module hazard_unit( input logic branchD, jumpD, jalrD, br_takenD,
					input logic memtoregE, regwriteE,
					input logic memtoregM, regwriteM,
					input logic regwriteW,
					input logic [4:0] rsD, rtD,
					input logic [4:0] rsE, rtE,
					input logic [4:0] writeregE, writeregM, writeregW,
					output logic forwardAD, forwardBD,
					output logic [1:0] forwardAE, forwardBE,
					output logic stallF, stallD, stallE, stallM, stallW,
					output logic flushF, flushD, flushE, flushM, flushW
				);
	
	logic lwstall;
	logic branchstall;

	/********************************************************************************/

	// If BR_RESOLVE_D is defined, The following signals are 0
	// If BR_RESOLVE_D - instn next to Br, will stall at Decode stage until RAW is resolved
	assign stallE = 0;
	assign stallM = 0;
	assign stallW = 0;

	assign flushF = 0;
	assign flushM = 0;
	assign flushW = 0;
	/********************************************************************************/
	// *******Data Forwarding***********//
	//data forwarding:(RAW) ex-ex and mem-ex bypass

	// Intelectual Property - protected
	`pragma protect begin
	always_comb begin
		//data bypass A: 
		if ((rsE != 0) && (rsE == writeregM) && regwriteM) begin
			forwardAE = 2'b10; // ex_ex bypass -> a = aluoutM
		end
		else if ( (rsE != 0) && (rsE == writeregW) && regwriteW) begin
			forwardAE = 2'b01; // mem_ex bypass -> a = resultW
		end
		else begin
			forwardAE = 2'b00;
		end

		//data bypass A: 
		if ((rtE != 0) && (rtE == writeregM) && regwriteM) begin
			forwardBE = 2'b10; // ex_ex bypass -> b = aluoutM
		end
		else if ( (rtE != 0) && (rtE == writeregW) && regwriteW) begin
			forwardBE = 2'b01; // mem_ex bypass -> b = resultW
		end
		else begin
			forwardBE = 2'b00;
		end
	end

	//Decode stage data dependency
	always_comb begin
		forwardAD = (rsD != 0) && (rsD == writeregM) && regwriteM;
		forwardBD = (rtD != 0) && (rtD == writeregM) && regwriteM;
	end

	/********************************************************************************/
	// *******Hazard Detection***********//
	always_comb begin
		//data hazard: load RAW dependency stall (load followed by alu instn)
		lwstall = ((writeregE == rsD) || (writeregE == rtD)) && memtoregE;
		// stallF = stallD = flushE = lwstall

		// control hazard : stall during branch
		branchstall = 	( (branchD | jalrD) && regwriteE && ( (writeregE == rsD) || (writeregE == rtD) ) )
													||
					  	( (branchD | jalrD) && memtoregM && ( (writeregM == rsD) || (writeregM == rtD) ) );

		//StallF = StallD = FlushE = lwstall OR branchstall
		stallF = lwstall | branchstall;
		stallD = lwstall | branchstall;

		// moving flushD to hazard unit since it makes more sense
		// branch evaluation is not considered until branchstall is resolved
		flushD =  ((!branchstall) & br_takenD) | jumpD | (jalrD & (!branchstall)) ;
		flushE = lwstall | branchstall;


	end
	`pragma protect end
	// Intelectual Property - protection ends here
endmodule : hazard_unit