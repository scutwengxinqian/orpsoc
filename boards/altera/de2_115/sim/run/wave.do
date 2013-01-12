onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /orpsoc_testbench/dut/jtag_tap0/tck_pad_i
add wave -noupdate /orpsoc_testbench/dut/jtag_tap0/tdi_pad_i
add wave -noupdate /orpsoc_testbench/dut/jtag_tap0/tdo_pad_o
add wave -noupdate /orpsoc_testbench/dut/jtag_tap0/tms_pad_i
add wave -noupdate /orpsoc_testbench/dut/jtag_tap0/trstn_pad_i
add wave -noupdate /orpsoc_testbench/dut/jtag_tap0/tdo_mux_out
add wave -noupdate /orpsoc_testbench/dut/dbg_if0/module_id_reg
add wave -noupdate /orpsoc_testbench/dut/dbg_if0/rst_i
add wave -noupdate /orpsoc_testbench/dut/test_logic_reset
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {54736657 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 1
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ps
update
WaveRestoreZoom {0 ps} {187568928 ps}
