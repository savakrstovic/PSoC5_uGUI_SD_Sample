/* ======================================================
 *
 * Copyright ANDRES F. NAVAS, 2018
 * All Rights Reserved
 * 
 * Kit PSoC used:
 * CY8CKIT-050 (CY8C5868AXI-LP035)
 * 
 * Main program to Test and show how to work
 * with a SSD1963 LCD and XPT2046 Touch controllers. TFT 16Bits BUS
 * Integration with uGUI Library
 * URL: http://www.embeddedlightning.com/
 * 
 * Use of SD-Card to Log data and read Images
 * Integration with FatFs Version R0.11a port made by Hackingchips (http://www.hackingchips.com/2016/01/port-de-la-libreria-fatfs-para-micros.html)
 * URL: http://elm-chan.org/fsw/ff/00index_e.html
 *
 * Link to the 5" LCD Panel used: 
 * https://www.aliexpress.com/item/Consumer-Electronics-Shop-Free-shipping-5-TFT-LCD-SS63-Module-Display-Touch-Panel-Screen-PCB-Adapter/32603464488.html?spm=a2g0s.9042311.0.0.27424c4dwb4qzi
 * 
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF ANDRES F. NAVAS.
 *
 * ======================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project.h"
#include "uGUI_Library/ugui.h"
#include "TFT_Driver/ugui_SSD1963.h"
#include "Touch_Controller/XPT2046.h"
#include "Images/Images.h"
#include "FatFs_Library/diskio.h"
#include "FatFs_Library/ff.h"



#define MAX_OBJECTS 10
#define BuffOUT     40

char bufferOut[BuffOUT];

uint16 Px, Py, BtnPulsed;

UG_WINDOW window_1;
UG_BUTTON button_1;
UG_BUTTON button_2;
UG_BUTTON button_3;
UG_BUTTON button_4;
UG_TEXTBOX textbox_1;
UG_IMAGE image_1;
const UG_BMP logo =     // Construct the BMP structure with the Image Local data
{
    (void*)acCapture,   // Data Image (local)
    194,                // Image Width
    102,                // Image Heigth
    0,                  // BPP for HW Accelerated function doesn't matter
    BMP_RGB565          // Use RGB888 for RGB 24Bits BMP Image
};
UG_OBJECT obj_buff_wnd_1[MAX_OBJECTS];

void window_1_callback(UG_MESSAGE *msg);

int main(void)
{
    UG_COLOR colorb[4];
    
    FATFS fatFs;
    FIL fileO;
    //DIR directoryO;
    //FILINFO fileInfo;
    uint8 resultF;
    char Name[] = {'A', 'n', 'd', 'r', 'e', 's', ' ', 'N', 'a', 'v', 'a', 's', 0x00};       // Local Name if can't read the SDCard data
        
    CyGlobalIntEnable; /* Enable global interrupts. */
    colorb[0] = C_RED;
    colorb[1] = C_GREEN;
    colorb[2] = C_BLUE;
    
    BtnPulsed = 0;          // Counter of button B pulsed to Log
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    //Clock_LCD_SetDividerRegister(0,1);   // Full clock speed
    GraphicLCDIntf_Start();
    Display_Init();
    XPT2046_Start();                       // Start Touch Controller
    SPI_Start();                           // Start SPI bus.
    SPI_SS_Write(1);
    LED3_Write(0);                         // Debugging
    CyDelay(50);
    
    /* Mount sdcard. */
    resultF = f_mount(&fatFs, "", 1);
    
    if (resultF == RES_OK)
    {
        f_open(&fileO, "Name.txt", FA_READ);        // Read the Name stored in the SDCard Name.txt file
        f_gets(Name, 20, &fileO);
        f_close(&fileO);
    }
    
    
    /* Clear screen. */
    UG_FillScreen(C_BLACK);
    UG_DrawFrame(0, 0, 799, 479, C_LIGHT_GRAY);     // Draw a Frame
    CyDelay(10);
    D_BL_Write(1);          // Turn on BackLight    
    
    //Some Texts
    UG_FontSelect(&FONT_12X16);
    UG_SetBackcolor(C_BLACK);
    UG_SetForecolor(C_YELLOW);
    sprintf(bufferOut,"TFT 5\"   (%dx%d)", DISPLAY_WIDTH, DISPLAY_HEIGHT);
    UG_PutString(5, 5 , bufferOut);
    UG_FontSelect(&FONT_12X16);
    UG_SetBackcolor(C_BLACK);
    UG_SetForecolor(C_YELLOW);
    UG_PutString(5, 23, "PSoC 5LP (CY8CKIT-050)");
    UG_FontSelect(&FONT_22X36);
    UG_SetBackcolor(C_BLACK);
    UG_SetForecolor(C_WHITE);
    UG_PutString(400, 90, Name);        // Show the name from SDCard if the file exist, if not use data initializaed in the Char String 'Name' 
    
    // Create the window
    UG_WindowCreate(&window_1, obj_buff_wnd_1, MAX_OBJECTS, window_1_callback);
    // Window Title
    UG_WindowSetTitleText(&window_1, "Test Window - \xe6GUI v0.31   \x02");      //  \xhh : Special CHR the ASCII value is given by hh interpreted as a hexadecimal number (Check FONT Table)
    UG_WindowSetTitleTextFont(&window_1, &FONT_12X16);
    UG_WindowSetXStart(&window_1, 275);
    UG_WindowSetYStart(&window_1, 200);
    UG_WindowSetXEnd(&window_1, 725);       // Window 450x250
    UG_WindowSetYEnd(&window_1, 450);
    
    // Create Buttons
    UG_ButtonCreate(&window_1, &button_1, BTN_ID_0, 10, 10, 110, 60);
    UG_ButtonCreate(&window_1, &button_2, BTN_ID_1, 10, 80, 110, 130);
    UG_ButtonCreate(&window_1, &button_3, BTN_ID_2, 10, 150, 110, 200);
    UG_ButtonCreate(&window_1, &button_4, BTN_ID_3, 170, 100, 172 + logo.width, 102 + logo.height); // Button under image to have an image with touch event
    //Label Buttons
    UG_ButtonSetFont(&window_1,BTN_ID_0,&FONT_8X14);
    UG_ButtonSetForeColor(&window_1,BTN_ID_0, C_BLUE);
    UG_ButtonSetText(&window_1,BTN_ID_0,"Button \nA");
    UG_ButtonSetFont(&window_1,BTN_ID_1,&FONT_8X14);
    UG_ButtonSetForeColor(&window_1,BTN_ID_1, C_RED);
    UG_ButtonSetText(&window_1,BTN_ID_1,"Button \nB");
    UG_ButtonSetFont(&window_1,BTN_ID_2,&FONT_8X14);
    UG_ButtonSetForeColor(&window_1,BTN_ID_2, C_BLACK);
    UG_ButtonSetText(&window_1,BTN_ID_2,"Button \nC");
    
    // Create Textbox
    UG_TextboxCreate(&window_1, &textbox_1, TXB_ID_0, 120, 10, 440, 80);
    UG_TextboxSetFont(&window_1, TXB_ID_0, &FONT_16X26);
    UG_TextboxSetText(&window_1, TXB_ID_0, "This is a \n test sample window!");
    UG_TextboxSetForeColor(&window_1, TXB_ID_0, C_BLACK);
    UG_TextboxSetAlignment(&window_1, TXB_ID_0, ALIGN_CENTER);
    
    // Create Image over the button - uGUI Images only supported from Internal Flash Memory
   // UG_ImageCreate(&window_1, &image_1, IMG_ID_0, 170, 100, 170 + logo.width, 100 + logo.height); // Image doesn't support touch events so there's a button under the image
   // UG_ImageSetBMP(&window_1, IMG_ID_0, &logo);
   
    UG_WindowShow(&window_1);
    UG_Update();
    
    // Image from SDCard located over the button
    DrawExImage(window_1.xs + 173, window_1.ys + 122, window_1.xs + 174 + logo.width, window_1.ys + 122 + logo.height, "C565a.dat");   
    
    // Image from Internal Flash memory located at left side of the Test window
    HW_DrawImage(20, 200, 20 + logo.width, 200 + logo.height, logo.p, logo.width * logo.height);
    
    for(;;)
    {
    /* Some graphic primitives for testing. */      
        
        UG_DrawFrame(3, 49, 124, 156, C_RED);
        UG_FillFrame(4, 50, 123, 155, colorb[0]);
        UG_DrawFrame(126, 49, 247, 156, C_GREEN);
        UG_FillFrame(127, 50, 246, 155, colorb[1]);
        UG_DrawFrame(249, 49, 370, 156, C_BLUE);
        UG_FillFrame(250, 50, 369, 155, colorb[2]);
        
        UG_Update();
        
        CyDelay(200);
        colorb[3] = colorb[2];
        colorb[2] = colorb[1];   
        colorb[1] = colorb[0];   
        colorb[0] = colorb[3];      
            
        if(XPT2046_IRQ == 0)        // Touch IRQ
        {
            
         Py =   XPT2046_ReadPos(0x90);              /*  A2 = 0; A1 = 0; A0 = 0; */
            Py = XPT2046_ReadPos(0x90);
            XPT2046_ReadPos(0xd0);
            Px = XPT2046_ReadPos(0xd0);
            if(XPT2046_ReadXY(&PosX, &PosY))    UG_TouchUpdate(PosX, PosY, TOUCH_STATE_PRESSED);        // If touch data is valid, Update uGUI Touch
            UG_FontSelect(&FONT_12X16);
            UG_SetBackcolor(C_BLACK);
            UG_SetForecolor(C_RED);
        }
        else 
        {
            UG_TouchUpdate(-1, -1, TOUCH_STATE_RELEASED);
            UG_FontSelect(&FONT_12X16);
            UG_SetBackcolor(C_BLACK);
            UG_SetForecolor(C_GREEN);
        }
        sprintf(bufferOut,"X = %d | %d  ", Px, PosX);
        UG_PutString(350, 5 , bufferOut);
        sprintf(bufferOut,"Y = %d | %d  ", Py, PosY);
        UG_PutString(350, 23, bufferOut);     
        sprintf(bufferOut,"Z = %d   ", XPT2046_ReadZ());
        UG_PutString(600, 13, bufferOut);
    }
}

void window_1_callback(UG_MESSAGE *msg)
{
    FATFS fatFs;
    FIL fileO;
    uint8 resultF;
    
    if(msg->type == MSG_TYPE_OBJECT)
    {
        if(msg->id == OBJ_TYPE_BUTTON)
        {
            if(msg->event == OBJ_EVENT_PRESSED)
            {
                switch(msg->sub_id)
                {
                    case BTN_ID_0:
                    {
                        LED4_Write(0);
                        UG_ButtonHide(&window_1,BTN_ID_1);
                        break;
                    }
                    case BTN_ID_1:
                    {
                        UG_TextboxSetText(&window_1, TXB_ID_0, "Button B \nPressed!");
                        /* Mount sdcard. */
                        resultF = f_mount(&fatFs, "", 1);
                        if (resultF == RES_OK)
                        {
                            BtnPulsed++;
                            f_open(&fileO, "Log.txt", FA_OPEN_ALWAYS | FA_WRITE | FA_READ);        // Open Always  LOG.TXT file
                            f_lseek(&fileO, f_size(&fileO));                                       // Go to EOF to append data
                            sprintf(bufferOut,"Button B pressed %d times since reset\r\n", BtnPulsed);         
                            f_puts(bufferOut, &fileO);                                             // Write data string to file
                            f_close(&fileO);
                        }
                        break;
                    }
                    case BTN_ID_2:
                    {
                        LED4_Write(1);
                        UG_ButtonShow(&window_1,BTN_ID_1);
                        break;
                    }
                    case BTN_ID_3:
                    {
                        UG_TextboxSetText(&window_1, TXB_ID_0, "Image \nPressed!");
                        LED4_Write(!LED4_Read());
                        /* Mount sdcard. */
                        resultF = f_mount(&fatFs, "", 1);
                        if (resultF == RES_OK)
                        {
                            BtnPulsed++;
                            f_open(&fileO, "Log.txt", FA_OPEN_ALWAYS | FA_WRITE | FA_READ);        // Open Always  LOG.TXT file
                            f_lseek(&fileO, f_size(&fileO));                                       // Go to EOF to append data
                            f_puts("The image was Pressed!\r\n", &fileO);                          // Write data string to file
                            f_close(&fileO);
                        }
                        break;
                    }
                }
            }
            if(msg->event == OBJ_EVENT_RELEASED)
            {
                if(msg->sub_id == BTN_ID_1)
                {
                        UG_TextboxSetText(&window_1, TXB_ID_0, "This is a \n test sample window!");
                }
                if(msg->sub_id == BTN_ID_3)
                {
                        UG_TextboxSetText(&window_1, TXB_ID_0, "This is a \n test sample window!");
                }
            }
        }
        //CyDelay(5);
    }
}

/* [] END OF FILE */
