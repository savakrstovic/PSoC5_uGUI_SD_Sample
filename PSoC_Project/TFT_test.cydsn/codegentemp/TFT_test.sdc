# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\GitHub\PSoC5_uGUI_SD_Sample\PSoC_Project\TFT_test.cydsn\TFT_test.cyprj
# Date: Mon, 16 Sep 2019 06:51:17 GMT
#set_units -time ns
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 15.151515151515152 -waveform {0 7.57575757575758} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 15.151515151515152 -waveform {0 7.57575757575758} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {Clock_LCD} -source [get_pins {ClockBlock/clk_sync}] -edges {1 3 5} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {SPI_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 17 35} [list [get_pins {ClockBlock/dclk_glb_1}]]


# Component constraints for D:\GitHub\PSoC5_uGUI_SD_Sample\PSoC_Project\TFT_test.cydsn\TopDesign\TopDesign.cysch
# Project: D:\GitHub\PSoC5_uGUI_SD_Sample\PSoC_Project\TFT_test.cydsn\TFT_test.cyprj
# Date: Mon, 16 Sep 2019 06:51:10 GMT
# GraphicLCDIntf
# False paths present for both 8 and 16 bits Graphic LCD Interface configurations 
expr {(16) == 8 ?
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd8:Lsb\/p_out_0}] -to [get_pins {\GraphicLCDIntf:LsbReg\/status_0}]] : \
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd16:Lsb\/p_out_0}] -to [get_pins {\GraphicLCDIntf:LsbReg\/status_0}]]} 
   
expr {(16) == 8 ?
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd8:Lsb\/p_out_1}] -to [get_pins {\GraphicLCDIntf:LsbReg\/status_1}]] : \
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd16:Lsb\/p_out_1}] -to [get_pins {\GraphicLCDIntf:LsbReg\/status_1}]]} 
   
expr {(16) == 8 ?
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd8:Lsb\/p_out_2}] -to [get_pins {\GraphicLCDIntf:LsbReg\/status_2}]] : \
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd16:Lsb\/p_out_2}] -to [get_pins {\GraphicLCDIntf:LsbReg\/status_2}]]} 
   
expr {(16) == 8 ?
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd8:Lsb\/p_out_3}] -to [get_pins {\GraphicLCDIntf:LsbReg\/status_3}]] : \
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd16:Lsb\/p_out_3}] -to [get_pins {\GraphicLCDIntf:LsbReg\/status_3}]]} 
   
expr {(16) == 8 ?
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd8:Lsb\/p_out_4}] -to [get_pins {\GraphicLCDIntf:LsbReg\/status_4}]] : \
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd16:Lsb\/p_out_4}] -to [get_pins {\GraphicLCDIntf:LsbReg\/status_4}]]} 
   
expr {(16) == 8 ?
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd8:Lsb\/p_out_5}] -to [get_pins {\GraphicLCDIntf:LsbReg\/status_5}]] : \
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd16:Lsb\/p_out_5}] -to [get_pins {\GraphicLCDIntf:LsbReg\/status_5}]]} 
   
expr {(16) == 8 ?
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd8:Lsb\/p_out_6}] -to [get_pins {\GraphicLCDIntf:LsbReg\/status_6}]] : \
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd16:Lsb\/p_out_6}] -to [get_pins {\GraphicLCDIntf:LsbReg\/status_6}]]} 
 
expr {(16) == 8 ?
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd8:Lsb\/p_out_7}] -to [get_pins {\GraphicLCDIntf:LsbReg\/status_7}]] : \
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd16:Lsb\/p_out_7}] -to [get_pins {\GraphicLCDIntf:LsbReg\/status_7}]]} 
   
# False paths present only for 16 bits Graphic LCD Interface configuration
expr {(16) == 16 ?
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd16:Msb\/p_out_0}] -to [get_pins {\GraphicLCDIntf:GraphLcd16:MsbReg\/status_0}]] : {}}
   
expr {(16) == 16 ?
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd16:Msb\/p_out_1}] -to [get_pins {\GraphicLCDIntf:GraphLcd16:MsbReg\/status_1}]] : {}}
   
expr {(16) == 16 ?
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd16:Msb\/p_out_2}] -to [get_pins {\GraphicLCDIntf:GraphLcd16:MsbReg\/status_2}]] : {}}

expr {(16) == 16 ?
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd16:Msb\/p_out_3}] -to [get_pins {\GraphicLCDIntf:GraphLcd16:MsbReg\/status_3}]] : {}}
   
expr {(16) == 16 ?
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd16:Msb\/p_out_4}] -to [get_pins {\GraphicLCDIntf:GraphLcd16:MsbReg\/status_4}]] : {}}
   
expr {(16) == 16 ?
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd16:Msb\/p_out_5}] -to [get_pins {\GraphicLCDIntf:GraphLcd16:MsbReg\/status_5}]] : {}}
   
expr {(16) == 16 ?
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd16:Msb\/p_out_6}] -to [get_pins {\GraphicLCDIntf:GraphLcd16:MsbReg\/status_6}]] : {}}
   
expr {(16) == 16 ?
   [set_false_path -from [get_pins {\GraphicLCDIntf:GraphLcd16:Msb\/p_out_7}] -to [get_pins {\GraphicLCDIntf:GraphLcd16:MsbReg\/status_7}]] : {}}

