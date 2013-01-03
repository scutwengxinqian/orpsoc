# template
# set_location_assignment PIN_xx -to yy
# set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to yy

# Supply voltage for 88E1111 is 2.5V/1.0V, but I/0s are 3.3V tolerant.

# MII interface
# Transmit
set_location_assignment PIN_B17 -to eth0_tx_clk
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_tx_clk
set_location_assignment PIN_B19 -to eth0_tx_data[3]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_tx_data[3]
set_location_assignment PIN_A19 -to eth0_tx_data[2]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_tx_data[2]
set_location_assignment PIN_D19 -to eth0_tx_data[1]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_tx_data[1]
set_location_assignment PIN_C18 -to eth0_tx_data[0]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_tx_data[0]
set_location_assignment PIN_A18 -to eth0_tx_en
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_tx_en
set_location_assignment PIN_B18 -to eth0_tx_er
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_tx_er
set_location_assignment PIN_E15 -to eth0_col
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_col
set_location_assignment PIN_D15 -to eth0_crs
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_crs

# Receive
set_location_assignment PIN_A15 -to eth0_rx_clk
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_rx_clk
set_location_assignment PIN_C15 -to eth0_rx_data[3]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_rx_data[3]
set_location_assignment PIN_D17 -to eth0_rx_data[2]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_rx_data[2]
set_location_assignment PIN_D16 -to eth0_rx_data[1]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_rx_data[1]
set_location_assignment PIN_C16 -to eth0_rx_data[0]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_rx_data[0]
set_location_assignment PIN_C17 -to eth0_dv
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_dv
set_location_assignment PIN_D18 -to eth0_rx_er
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_rx_er

# Management interface
set_location_assignment PIN_C20 -to eth0_mdc_pad_o
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_mdc_pad_o
set_location_assignment PIN_B21 -to eth0_md_pad_io
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_md_pad_io

# reset
set_location_assignment PIN_D22 -to eth0_rst_n_o
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to eth0_rst_n_o

