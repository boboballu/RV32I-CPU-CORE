	// takes care of all load instns
	function automatic logic [31:0] load_compute 	(	
									input logic [2:0] funct3,
									input logic memtoreg,
									input logic [31:0] pcplus4, itypeimm, readdata
									//output logic [31:0] result
							  	);
		logic [31:0] result;

		case (funct3)
			3'b000: begin // LB
						case (itypeimm[1:0])
							2'b00: result = {{24{readdata[7]}}  , readdata[7:0]  };
							2'b01: result = {{24{readdata[15]}} , readdata[15:8] };
							2'b10: result = {{24{readdata[23]}} , readdata[23:16]};
							2'b11: result = {{24{readdata[31]}} , readdata[31:24]};
							default: result = 32'bx;
						endcase
					end
			3'b100: begin // LBU
						case (itypeimm[1:0])
							2'b00: result = {{24'b0} , readdata[7:0]  };
							2'b01: result = {{24'b0} , readdata[15:8] };
							2'b10: result = {{24'b0} , readdata[23:16]};
							2'b11: result = {{24'b0} , readdata[31:24]};
							default: result = 32'bx;
						endcase
					end
			3'b001:	begin // LH
						case (itypeimm[1])
							1'b0: result = {{16{readdata[15]}} , readdata[15:0]};
							1'b1: result = {{16{readdata[15]}} , readdata[31:16]};
							default result = 32'bx;
						endcase
					end
			3'b101: begin // LHU
						case (itypeimm[1])
							1'b0: result = {{16'b0} , readdata[15:0]};
							1'b1: result = {{16'b0} , readdata[31:16]};
							default result = 32'bx;
						endcase
					end
			default: begin // LW
						result = readdata;
					end
		endcase
		
		return result;
	endfunction : load_compute

	// takes care all store instns
	function automatic logic [31:0] store_compute 	(	
								input logic [2:0] funct3,
								input logic [31:0] stypeimm, readdata, srcb_net0
								//output logic [31:0] writedata 
							);

		logic [31:0] writedata;

		case (funct3)
			3'b000: begin // SB
						case (stypeimm[1:0])
							2'b00: writedata = {readdata[31:24], readdata[23:16], readdata[15:8], srcb_net0[7:0]};
							2'b01: writedata = {readdata[31:24], readdata[23:16], srcb_net0[7:0], readdata[7:0]};
							2'b10: writedata = {readdata[31:24], srcb_net0[7:0], readdata[15:8], readdata[7:0]};
							2'b11: writedata = {srcb_net0[7:0], readdata[23:16], readdata[15:8], readdata[7:0]};
							default: writedata = 32'bx;
						endcase
					end
			3'b001: begin // SH
						case (stypeimm[1]) 
							1'b0: writedata = {readdata[31:16], srcb_net0[15:0]};
							1'b1: writedata = {srcb_net0[15:0], readdata[15:0]};
							default: writedata = 32'bx;
						endcase
					end
			default: begin // SW
						writedata = srcb_net0;
					end
		endcase

		return writedata;
	endfunction : store_compute

	//takes care of branch instns
	function automatic logic br_compute(	
								input logic branch, input logic [2:0] funct3, 
						 		input logic [31:0] srca, srcb
						 		//output logic br_taken
							);

		logic br_taken;
		if (branch) begin
			case (funct3)
				3'b000: br_taken = ( signed'(srca) == signed'(srcb) ); // BEQ
				3'b001: br_taken = ( signed'(srca) != signed'(srcb) ); // BNE
				3'b100: br_taken = ( signed'(srca) <  signed'(srcb) ); // BLT
				3'b101: br_taken = ( signed'(srca) >= signed'(srcb) ); // BGE
				3'b110: br_taken = ( srca < srcb ); 				   // BLTU
				3'b111: br_taken = ( srca >= srcb );				   // BGEU
				default: br_taken = 1'bx;
			endcase
		end
		else begin
			br_taken = 0;
		end
		return br_taken;
	endfunction : br_compute