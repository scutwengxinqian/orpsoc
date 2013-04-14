onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /orpsoc_testbench/dut/wbm_d_or12_ack_i
add wave -noupdate /orpsoc_testbench/dut/wbm_d_or12_adr_o
add wave -noupdate /orpsoc_testbench/dut/wbm_d_or12_bte_o
add wave -noupdate /orpsoc_testbench/dut/wbm_d_or12_cti_o
add wave -noupdate /orpsoc_testbench/dut/wbm_d_or12_cyc_o
add wave -noupdate /orpsoc_testbench/dut/wbm_d_or12_dat_i
add wave -noupdate /orpsoc_testbench/dut/wbm_d_or12_dat_o
add wave -noupdate /orpsoc_testbench/dut/wbm_d_or12_err_i
add wave -noupdate /orpsoc_testbench/dut/wbm_d_or12_rty_i
add wave -noupdate /orpsoc_testbench/dut/wbm_d_or12_sel_o
add wave -noupdate /orpsoc_testbench/dut/wbm_d_or12_stb_o
add wave -noupdate /orpsoc_testbench/dut/wbm_d_or12_we_o
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {907527881 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 206
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
WaveRestoreZoom {0 ps} {9953531599 ps}
