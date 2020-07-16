interface datapath_if ();
    logic [31:0] srca, srcb;
    logic [4:0] rs, rt, rd;
    logic [31:0] signimm, branchimm, jumpimm, stypeimm, itypeimm, utypeimm;
    logic [4:0] writereg;
    logic [31:0] aluout;
    logic [31:0] writedata, readdata;

    //// datapath pipeline_reg input and output
    modport reg_in (    input srca, srcb,
                        rs, rt, rd,
                        signimm, branchimm, jumpimm, stypeimm, itypeimm, utypeimm,
                        writereg,
                        aluout,
                        writedata, readdata
    );
    modport reg_out (   output srca, srcb,
                        rs, rt, rd,
                        signimm, branchimm, jumpimm, stypeimm, itypeimm, utypeimm,
                        writereg,
                        aluout,
                        writedata, readdata
    );

    // datapath stages [EX, MEM, WB] - data pass through
endinterface : datapath

// dp_reg implements datapath signal pipeline registers
module dp_reg ( input logic clk,
                input clear, en,
                datapath.reg_in reg_in,
                datapath.reg_out reg_out
);
    always_ff @(posedge clk) begin
        if (clear) begin
            {reg_out.srca, reg_out.srcb,
            reg_out.rs, reg_out.rt, reg_out.rd,
            reg_out.signimm, reg_out.branchimm, reg_out.jumpimm, reg_out.stypeimm, reg_out.itypeimm, reg_out.utypeimm,
            reg_out.writereg,
            reg_out.aluout,
            reg_out.writedata, reg_out.readdata}
            = 'b0;
        end
        else if(!en) begin
            {reg_out.srca, reg_out.srcb,
            reg_out.rs, reg_out.rt, reg_out.rd,
            reg_out.signimm, reg_out.branchimm, reg_out.jumpimm, reg_out.stypeimm, reg_out.itypeimm, reg_out.utypeimm,
            reg_out.writereg,
            reg_out.aluout,
            reg_out.writedata, reg_out.readdata}
            =
            {reg_in.srca, reg_in.srcb,
            reg_in.rs, reg_in.rt, reg_in.rd,
            reg_in.signimm, reg_in.branchimm, reg_in.jumpimm, reg_in.stypeimm, reg_in.itypeimm, reg_in.utypeimm,
            reg_in.writereg,
            reg_in.aluout,
            reg_in.writedata, reg_in.readdata};
        end
    end
endmodule : dp_reg