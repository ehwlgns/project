`timescale 1ns/1ps

module tb();

reg clk;
reg reset;

counter cnt(
    .clk(clk),
    .reset(reset)
);

initial begin
    clk = 1'b0;
    reset = 1'b0;

    #100
    reset = 1'b1;
end
initial begin
	$dumpfile("test_out.vcd");
	$dumpvars;
	#1000
	$finish;

end

always #5 clk <= ~clk;

endmodule

