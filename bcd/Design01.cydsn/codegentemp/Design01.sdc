# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\zhaoh\Downloads\bcd0926\bcd0904\bcd\Design01.cydsn\Design01.cyprj
# Date: Fri, 04 Oct 2019 03:36:06 GMT
#set_units -time ns
create_clock -name {ADC_DelSig_1_Ext_CP_Clk(routed)} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dclk_0}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {ADC_DelSig_1_Ext_CP_Clk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 3 5} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {ADC_DelSig_1_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 9 17} [list [get_pins {ClockBlock/aclk_glb_0}]]
create_generated_clock -name {timer_clock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 25 49} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {UART_1_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 53 105} -nominal_period 2166.6666666666665 [list [get_pins {ClockBlock/dclk_glb_3}]]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/clk_sync}] -edges {1 193 385} [list [get_pins {ClockBlock/dclk_glb_4}]]
create_generated_clock -name {Clock_3} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2001 4001} -nominal_period 83333.333333333328 [list [get_pins {ClockBlock/dclk_glb_5}]]
create_generated_clock -name {Clock_4} -source [get_pins {ClockBlock/clk_sync}] -edges {1 1200001 2400001} [list [get_pins {ClockBlock/dclk_glb_6}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\zhaoh\Downloads\bcd0926\bcd0904\bcd\Design01.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\zhaoh\Downloads\bcd0926\bcd0904\bcd\Design01.cydsn\Design01.cyprj
# Date: Fri, 04 Oct 2019 03:35:53 GMT
