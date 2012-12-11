module led(
	    wb_clk,
	    wb_rst,
	    
	    wb_adr_i,
	    wb_dat_i,
	    wb_we_i,
	    wb_cyc_i,
	    wb_stb_i,
	    wb_cti_i,
	    wb_bte_i,

	    wb_ack_o,
	    wb_dat_o,
	    wb_err_o,
	    wb_rty_o,

	    led_o);

input wb_clk;
input wb_rst;
   
input [31:0] wb_adr_i;
input [7:0] wb_dat_i;
input wb_we_i;
input wb_cyc_i;
input wb_stb_i;
input [2:0] wb_cti_i;
input [1:0] wb_bte_i;

output reg wb_ack_o;
output [7:0] wb_dat_o;
output wb_err_o;
output wb_rty_o;

output reg [7:0] led_o;

always @(posedge wb_clk)
if(wb_rst)
	led_o <= 8'b0;
else if(wb_cyc_i & wb_stb_i & wb_we_i)
// ignore address checking
	led_o <= wb_dat_i;

assign wb_dat_o = led_o;

always @(posedge wb_clk)
if(wb_rst)
	wb_ack_o <= 1'b0;
else if(wb_ack_o)
	wb_ack_o <= 1'b0;
else if (wb_cyc_i & wb_stb_i)
	wb_ack_o <= 1'b1;

assign wb_err_o = 1'b0;
assign wb_rty_o = 1'b0;

endmodule // led

