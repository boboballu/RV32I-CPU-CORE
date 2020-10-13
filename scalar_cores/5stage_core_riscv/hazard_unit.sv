// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// hazard_unit - takes care of * Data Forwarding logic * RAW Hazard detection
// * takes care of flush and stall in the pipeline
`define HAZARD_UNIT
`include "debug_headerfile.svh"
import dbg_pkg::*;

// inputs - jump/branch information (branchD, jumpD, br_takenD)
// memory and register control information to solve RAW hazard (memtoregE, memtoregM, regwriteE, retwriteM, regwriteW)
// source register addresses (rsD, rtD, rsE, rtE)
// reg destination addresses (writeregE, writeregM, writeregW)
// forward control signals (forwardAD, forwardBD, forwardAE, forwardBE)
// all stall and flush signals for the pipeline regs (stallF, stallD, stallE, stallM, stallW)
// and (flushF, flushD, flushE, flushM, flushW)
module hazard_unit(
					input logic imem_wait, dmem_wait,
					input logic branchD, BTBHitD, BpredD, br_takenD,
					input logic jumpD, jalrD,
					input logic memtoregE, regwriteE,
					input logic memtoregM, regwriteM,
					input logic regwriteW,
					input logic [4:0] rsD, rtD,
					input logic [4:0] rsE, rtE,
					input logic [4:0] writeregE, writeregM, writeregW,
					input logic memwriteM,

					output logic forwardAD, forwardBD,
					output logic [1:0] forwardAE, forwardBE,
					output logic stallF, stallD, stallE, stallM, stallW,
					output logic flushF, flushD, flushE, flushM, flushW,
					output logic imem_req, dmem_req
);

	logic lwstall;
	logic branchstall;
	logic memstall;

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
		// memstall:
		// dmem request - dmem request is high only if the instn is ld or sw
		dmem_req 	= (memtoregM | memwriteM);
		memstall 	= (dmem_wait & dmem_req) | imem_wait;

		//data hazard: load RAW dependency stall (load followed by alu instn)
		lwstall = ((writeregE == rsD) || (writeregE == rtD)) && memtoregE;
		// stallF = stallD = flushE = lwstall

		// control hazard : stall during branch

		branchstall = 	( (branchD | jalrD) && regwriteE && ( (writeregE == rsD) || (writeregE == rtD) ) )
													||
					  	( (branchD | jalrD) && memtoregM && ( (writeregM == rsD) || (writeregM == rtD) ) );

		// note: A pipeline reg cant stall and flush at the sametime
		//StallF = StallD = FlushE = lwstall OR branchstall

		// If BR_RESOLVE_D is defined, The following signals are 0
		// If BR_RESOLVE_D - instn next to Br, will stall at Decode stage until RAW is resolved
		// if memstall, stall F, D, E, M and flush W
		stallF = lwstall | branchstall | memstall;
		stallD = lwstall | branchstall | memstall;
		stallE = memstall;
		stallM = memstall;
		stallW = memstall;
		// moving flushD to hazard unit since it makes more sense
		// branch evaluation is not considered until branchstall is resolved
		flushF = 0;
		//flushD =  ( ((!branchstall) & br_takenD) | jumpD | (jalrD & (!branchstall)) ) & (!memstall);
		flushD =  ( ((!branchstall) & ((!BTBHitD) & br_takenD | BTBHitD & (BpredD != br_takenD) ) )
					| jumpD
					| (jalrD & (!branchstall))
					) & (!memstall);
		flushE =  ( lwstall | branchstall ) & (!memstall);
		flushM = 0;
		flushW = 0;

		// Imem request - is same as stallF; Since if fetch is stalled, we r not supposed to request a new instn
		imem_req = !stallF;
		// imem_req = 1;
	end
	`pragma protect end
	// Intelectual Property - protection ends here
endmodule : hazard_unit
