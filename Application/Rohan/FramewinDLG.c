/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.12                          *
*        Compiled Jun 29 2011, 15:28:47                              *
*        (c) 2011 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/

#define ID_FRAMEWIN_0 (GUI_ID_USER + 0x00)
#define ID_SLIDER_0 (GUI_ID_USER + 0x01)
#define ID_BUTTON_0 (GUI_ID_USER + 0x02)

// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "App", ID_FRAMEWIN_0, 0, 0, 799, 479, 0, 0, 0 },
  { SLIDER_CreateIndirect, "Slider", ID_SLIDER_0, 86, 143, 239, 20, 0, 0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 170, 211, 80, 20, 0, 0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem,hDlg;
  int Id, NCode;
  // USER START (Optionally insert additional variables)
  // USER END
  hDlg = pMsg->hWin;
  switch (pMsg->MsgId) {
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_SLIDER_0: // Notifications sent by 'Slider'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_0: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
		  hItem = WM_GetDialogItem(hDlg, ID_SLIDER_0);
		  int val = SLIDER_GetValue(hItem);
		  if (val >= 100) val = -5;
		  SLIDER_SetValue(hItem, val + 5);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateFramewin
*/
WM_HWIN CreateFramewin(void);
WM_HWIN CreateFramewin(void) {
  WM_HWIN hWin,hItem;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), &_cbDialog, WM_HBKWIN, 0, 0);
  hItem = WM_GetDialogItem(hWin, ID_SLIDER_0);
  SLIDER_SetFocusColor(hItem,GUI_GREEN);

  hItem = WM_GetDialogItem(hWin, ID_BUTTON_0);
  BUTTON_SetText(hItem, "Increase");
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

void MainTask(void);
void MainTask(void) {
	GUI_Init();
	CreateFramewin();
	while (1) {
		GUI_Delay(200);
	}
}

/*************************** End of file ****************************/
