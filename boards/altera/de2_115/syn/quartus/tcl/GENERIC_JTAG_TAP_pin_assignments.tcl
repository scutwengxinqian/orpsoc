# use GPIO, locates at lower right conner of the IDE port.
set_location_assignment PIN_AE24 -to tck_pad_i ; # GPIO[27]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to tck_pad_i

set_location_assignment PIN_AF26 -to tms_pad_i ; # GPIO[29]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to tms_pad_i

set_location_assignment PIN_AG23 -to tdi_pad_i ; # GPIO[31]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to tdi_pad_i

set_location_assignment PIN_AH26 -to tdo_pad_o ; # GPIO[33]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to tdo_pad_o

set_location_assignment PIN_AG26 -to trstn_pad_i ; # GPIO[35]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to trstn_pad_i

