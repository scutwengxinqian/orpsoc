//////////////////////////////////////////////////////////////////////
////                                                              ////
////  $Id: wb_flash.v,v 1.1 2008-06-04 06:10:35 hharte Exp $          ////
////  wb_flash.v - Wishbone FLASH interface for the StrataFLASH   ////
////               on the Xilinx Spartan3E Starter Kit            ////
////                                                              ////
////  This file is part of the wb_flash Project                   ////
////  http://www.opencores.org/projects/wb_flash/                 ////
////                                                              ////
////  Author:                                                     ////
////      - Howard M. Harte (hharte@opencores.org)                ////
////                                                              ////
//////////////////////////////////////////////////////////////////////
////                                                              ////
//// Copyright (C) 2008 Howard M. Harte                           ////
////                                                              ////
//// This source file may be used and distributed without         ////
//// restriction provided that this copyright statement is not    ////
//// removed from the file and that any derivative work contains  ////
//// the original copyright notice and the associated disclaimer. ////
////                                                              ////
//// This source file is free software; you can redistribute it   ////
//// and/or modify it under the terms of the GNU Lesser General   ////
//// Public License as published by the Free Software Foundation; ////
//// either version 2.1 of the License, or (at your option) any   ////
//// later version.                                               ////
////                                                              ////
//// This source is distributed in the hope that it will be       ////
//// useful, but WITHOUT ANY WARRANTY; without even the implied   ////
//// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR      ////
//// PURPOSE.  See the GNU Lesser General Public License for more ////
//// details.                                                     ////
////                                                              ////
//// You should have received a copy of the GNU Lesser General    ////
//// Public License along with this source; if not, download it   ////
//// from http://www.opencores.org/lgpl.shtml                     ////
////                                                              ////
//////////////////////////////////////////////////////////////////////

// xqweng
// change data width to 8 bits.

module wb_flash(
    // Parallel FLASH Interface
    clk_i, nrst_i, 
    // wishbone
    wb_adr_i, wb_dat_o, wb_dat_i, wb_we_i,
    wb_stb_i, wb_cyc_i, wb_ack_o, wb_err_o, wb_rty_o,
    wb_bte_i, wb_cti_i,
    // flash
    flash_adr_o, flash_dat_o, flash_dat_i,
    flash_oe, flash_ce, flash_we
);

    //
    // Default address and data bus width
    //
    parameter aw = 23;   // number of address-bits
    parameter dw = 8;   // number of data-bits
    parameter ws = 4'hf; // number of wait-states

    //
    // FLASH interface
    //
    input   clk_i;
    input   nrst_i;
    input   [aw-1:0] wb_adr_i;
    output  [dw-1:0] wb_dat_o;
    input   [dw-1:0] wb_dat_i;
    input   wb_we_i;
    input   wb_stb_i;
    input   wb_cyc_i;
    output reg wb_ack_o;
    output  wb_err_o;
    output  wb_rty_o;
    input [2:0] wb_cti_i;
    input [1:0] wb_bte_i;

    output  [aw-1:0] flash_adr_o;
    output  [7:0] flash_dat_o;
    input   [7:0] flash_dat_i;
    output  flash_oe;
    output  flash_ce;
    output  flash_we;
    reg [3:0] waitstate;

    // Wishbone read/write accesses
    wire wb_acc = wb_cyc_i & wb_stb_i;    // WISHBONE access
    wire wb_wr  = wb_acc & wb_we_i;       // WISHBONE write access
    wire wb_rd  = wb_acc & !wb_we_i;      // WISHBONE read access

    always @(posedge clk_i or negedge nrst_i)
        if(~nrst_i)
        begin
            waitstate <= 4'b0;
                wb_ack_o <= 1'b0;
        end
        else begin
                if(waitstate == 4'b0) begin
                    wb_ack_o <= 1'b0;
                    if(wb_acc) begin
                        waitstate <= waitstate + 1;
                    end
                end
                else begin
                    waitstate <= waitstate + 1;
                    if(waitstate == ws)
                        wb_ack_o <= 1'b1;
                end
         end

    assign flash_ce = !wb_acc;
    assign flash_we = !wb_wr;
    assign flash_oe = !wb_rd;

    assign flash_adr_o = wb_adr_i;
    assign flash_dat_o = wb_dat_i;
    assign wb_dat_o = flash_dat_i;

    assign wb_err_o = 1'b0;
    assign wb_rty_o = 1'b0;

endmodule
