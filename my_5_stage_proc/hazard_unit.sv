// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
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
	//data forwarding:(RAW) ex-ex and mem-ex bypass
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

	always_comb begin
		//data hazard: load RAW dependency stall (load followed by alu instn)
		lwstall = ((rsD == rtE) || (rtD == rtE)) && memtoregE;
		// stallF = stallD = flushE = lwstall

		// control hazard : stall during branch
		branchstall = 	( branchD && regwriteE && ( (writeregE == rsD) || (writeregE == rtD) ) )
													||
					  	( branchD && memtoregM && ( (writeregM == rsD) || (writeregM == rtD) ) );

		//StallF = StallD = FlushE = lwstall OR branchstall
		stallF = lwstall | branchstall;
		stallD = lwstall | branchstall;
		flushE = lwstall | branchstall;
	end

	//Decode stage data dependency
	always_comb begin
		forwardAD = (rsD != 0) && (rsD == writeregM) && regwriteM;
		forwardBD = (rtD != 0) && (rtD == writeregM) && regwriteM;
	end

endmodule : hazard_unit