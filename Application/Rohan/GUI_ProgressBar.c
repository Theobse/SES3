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
#include "DIALOG.h"
#include "WM.h"
#include "PROGBAR.h"
#include "SLIDER.h"
#include "RADIO.h"
#include "LISTBOX.h"
#include "suyashLogo.c"
#include "blueorigin.c"
#include <stdlib.h>



static const GUI_WIDGET_CREATE_INFO _aDialog[] = {
	{ WINDOW_CreateIndirect, "",       0,                0,   0, 400, 240, 0 },
	{ TEXT_CreateIndirect,   "Dialog", 0,               80,   5, 100, 20, TEXT_CF_HCENTER },
	{ BUTTON_CreateIndirect, "Close",  GUI_ID_BUTTON0,  80, 160, 100, 20 },
	{ SLIDER_CreateIndirect, "Slider1",GUI_ID_SLIDER0, 5,200,300,30 }
};


/*_cbDialog
*
* Purpose
*   Callback routine of the dialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
	int NCode, Id;
	switch (pMsg->MsgId) {
	case WM_PAINT:
		GUI_SetBkColor(0x800080);
		GUI_Clear();
		break;
	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc);    /* Id of widget */
		NCode = pMsg->Data.v;               /* Notification code */
		switch (NCode) {
		case WM_NOTIFICATION_RELEASED:      /* React only if released */
			switch (Id) {
			case GUI_ID_BUTTON0:
				GUI_EndDialog(pMsg->hWin, 0);
				break;
			}
			break;
		}
		break;
	default:
		WM_DefaultProc(pMsg);
	}
}



/*********************************************************************
*
*       main()
*/
void MainTask(void);
void MainTask(void) {
  GUI_Init();

  int xpos, ypos;
  xpos = LCD_GetXSize() / 2;
  ypos = LCD_GetYSize() / 2;
  char s1[50], s2[50];
  itoa(xpos, s1, 10);
  itoa(ypos, s2, 10);
  GUI_DispStringAt(s1, xpos, ypos);
  GUI_DispStringAt(s2, xpos, ypos + 10);
  /*
  //WM_HWIN hw = WM_CreateWindow(0, 0, 800, 480, WM_CF_SHOW, NULL, 0);
 // WM_SetDesktopColor(0xffffff);
  WM_HWIN hDlg = GUI_ExecDialogBox(_aDialog, GUI_COUNTOF(_aDialog), _cbDialog, WM_HBKWIN, 0, 0);
  SLIDER_Handle hsl1 = SLIDER_CreateEx(200, 50, 400, 20, 0, WM_CF_SHOW, 0, 0);
  SLIDER_Handle hsl2 = SLIDER_CreateEx(200, 100, 400, 20, 0, WM_CF_SHOW, 0, 0);

  //RADIO_Handle hr1 = RADIO_CreateEx(200, 50, 20, 20, 0, WM_CF_SHOW, 0, 1, 5, 50);
 // LISTBOX_Handle hlb = LISTBOX_Create()

  PROGBAR_Handle hpb = PROGBAR_Create(10, 420, 780, 40, WM_CF_SHOW);
  GUI_SetFont(&GUI_Font24_1);
  GUI_SetColor(0xffff00);
  GUI_SetTextMode(GUI_TEXTMODE_TRANS);
  GUI_DispStringAt("Progress", 370, 380);
  PROGBAR_SetBarColor(hpb, 0, 0x00ff00);

  SLIDER_Handle hSlider;
  hSlider = WM_GetDialogItem(hDlg, GUI_ID_SLIDER0);
  SLIDER_SetValue(hSlider, 60);
  int i = 0;*/
  while(1) {
    GUI_Delay(100);
	//PROGBAR_SetValue(hpb,i++);
	//SLIDER_SetValue(hsl1, i);
	//SLIDER_SetValue(hsl2, 2*i);
	//if (i > 100) i = 0;
  }
}

/****** End of File *************************************************/



