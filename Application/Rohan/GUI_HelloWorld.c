/*********************************************************************
*                SEGGER MICROCONTROLLER GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 2003-2012     SEGGER Microcontroller GmbH & Co KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

----------------------------------------------------------------------
File    : GUI_HelloWorld.c
Purpose : emWin and embOS demo application
--------  END-OF-HEADER  ---------------------------------------------
*/

#include "GUI.h"
#include "suyashLogo.c"
#include "blueorigin.c"
/*********************************************************************
*
*       main()
*/
void MainTask(void);
void MainTask(void) {
  GUI_Init();
  GUI_SetFont(&GUI_Font24B_1);
  GUI_SetColor(0xffff66);
  //GUI_SetTextMode(GUI_TEXTMODE_XOR);
  GUI_RECT Rect = { 10,100,790,400 };
  GUI_RECT* rect = &Rect;
  GUI_DrawRectEx(rect);
  GUI_JPEG_Draw(acblueorigin, sizeof(acblueorigin), 250, 150);
  GUI_DispStringHCenterAt("Suyash Solutions\n",400,350);
  GUI_DispStringHCenterAt("Version 230317", 400, 405);
  GUI_DispStringHCenterAt("Rohan Pandit",400,430);
  while(1) {
    GUI_Delay(500);
  }
}

/****** End of File *************************************************/
