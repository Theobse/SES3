
#include <math.h>
#include "GraphXY1.H"
#include "./Controller.h"
/*********************************************************************
*
*       Externals
*
**********************************************************************
*/

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0     (GUI_ID_USER + 0x00)
#define ID_GRAPH_0      (GUI_ID_USER + 0x01)
#define ID_BUTTON_0     (GUI_ID_USER + 0x05)
#define MESSAGE_STARTSTOP  (WM_USER + 0x00)
#define E 2.718
#define Y_OFFSET 9900
/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

static int Value = 300;
static GUI_POINT _aPoints1[900],_aPoints2[900],_aPoints3[900],_aPoints4[900];
static GRAPH_DATA_Handle _hDataXY1,_hDataXY2,_hDataXY3,_hDataXY4;
/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
	{ WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 800, 480, 0, 0x0, 0 },
	{ GRAPH_CreateIndirect, "Graph", ID_GRAPH_0, 10, 10, 790, 430, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Back", ID_BUTTON_0, 340, 430, 120, 40, 0, 0, 0 }
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
static void _UserDraw(WM_HWIN hWin, int Stage) {
	if (Stage == GRAPH_DRAW_LAST) {
		char acText[] = "Temperature (deg C)";
		GUI_RECT Rect, RectInvalid;
		int FontSizeY;
		GUI_SetFont(&GUI_Font24_ASCII);
		FontSizeY = GUI_GetFontSizeY();
		WM_GetInsideRect(&Rect);
		WM_GetInvalidRect(hWin, &RectInvalid);
		Rect.x1 = Rect.x0 + FontSizeY;
		GUI_SetColor(GUI_BLUE);
		GUI_DispStringInRectEx(acText, &Rect, GUI_TA_HCENTER, strlen(acText), GUI_ROTATE_CCW);
		GUI_DispStringHCenterAt("Time (s)", 400, 420);
	}
}

static void fillGraphData(int n) {
	int i;
	if (n > 900)	return;
	for (i = 0; i < n; i++) {
		_aPoints1[i].x = _aPoints2[i].x = _aPoints3[i].x = _aPoints4[i].x = i;
		_aPoints1[i].y = (CIC[i]-Y_OFFSET)*0.129;
		_aPoints2[i].y = CICE[i] * 0.28;
		_aPoints3[i].y = SGC[i] * 0.28;
		_aPoints4[i].y = SGCE[i] * 0.28;

	}
	int j = i;
	for (i = n; i < 900; i++) {
		_aPoints1[i].x = _aPoints2[i].x = _aPoints3[i].x = _aPoints4[i].x = j;
		_aPoints1[i].y = _aPoints1[j-1].y;
		_aPoints2[i].y = _aPoints2[j-1].y;
		_aPoints3[i].y = _aPoints3[j-1].y;
		_aPoints4[i].y = _aPoints4[j-1].y;
	}
}
/*********************************************************************
*
*       _cbGraph
*/
static void _cbGraph(WM_MESSAGE * pMsg) {
	GUI_PID_STATE * pState;
	static int Pressed;
	WM_HWIN hWin;

	switch (pMsg->MsgId) {
	case WM_TOUCH:
		pState = (GUI_PID_STATE *)pMsg->Data.p;
		if (pState) {
			if (pState->Pressed) {
				Pressed = 1;
			}
			else {
				if (Pressed) {
					Pressed = 0;
					//
					// If released send start stop message to the parent
					//
					hWin = WM_GetParent(pMsg->hWin);
					WM_SendMessageNoPara(hWin, MESSAGE_STARTSTOP);
				}
			}
		}
		break;
	default:
		GRAPH_Callback(pMsg);
		break;
	}
}

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
	WM_HWIN hItem;
	int Id, NCode;
	int NumItems;
	static GRAPH_DATA_Handle hDataSin, hDataCos;
	
	static int Angle;
	static int Stop;
	static WM_HTIMER hTimer;

	switch (pMsg->MsgId) {

	case WM_NOTIFY_PARENT :
		Id = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
	case ID_BUTTON_0: // Notifications sent by 'Back'
		switch (NCode) {
		case WM_NOTIFICATION_CLICKED:
			// USER START (Optionally insert code for reacting on notification message)
			// USER END
			break;
		case WM_NOTIFICATION_RELEASED:
			// USER START (Optionally insert code for reacting on notification message)
			showhideWindow(PG_SETTINGS, PAGES);
			// USER END
			break;
			// USER START (Optionally insert additional code for further notification handling)
			// USER END
		}
		break;
		// USER START (Optionally insert additional code for further Ids)
		// USER END
	
	case WM_INIT_DIALOG:
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
		BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);
		//
		// Initialization of 'Graph'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_GRAPH_0);
		//
		// Set a callback, it manages touch on the graph, if it gets touched it stops, another touch and it starts
		//
		WM_SetCallback(hItem, _cbGraph);
		//
		// Make the grid visible
		//
		GRAPH_SetGridVis(hItem, 1);
		//
		// Get x size, used as max num items
		//
		NumItems = WM_GetWindowSizeX(hItem);
		//
		// Create two data items, one for sin, one for cos
		//
		//hTimer = WM_CreateTimer(pMsg->hWin, 0, 10, 0);
		GRAPH_SCALE_Handle hScaleY, hScaleX;
		hScaleY = GRAPH_SCALE_Create(70, GUI_TA_RIGHT, GRAPH_SCALE_CF_VERTICAL, 50);
		GRAPH_SCALE_SetOff(hScaleY, -990);
		GRAPH_SCALE_SetFont(hScaleY, GUI_FONT_24_ASCII);
		GRAPH_SCALE_SetTextColor(hScaleY, GUI_DARKCYAN);
		GRAPH_AttachScale(hItem, hScaleY);

		hScaleX = GRAPH_SCALE_Create(400, GUI_TA_CENTER, GRAPH_SCALE_CF_HORIZONTAL, 25);
		//GRAPH_SCALE_SetTickDist(hScaleX, );
		GRAPH_SCALE_SetFactor(hScaleX, 0.4);
		GRAPH_SCALE_SetFont(hScaleX, GUI_FONT_16_ASCII);
		GRAPH_SCALE_SetTextColor(hScaleX, GUI_DARKCYAN);
		GRAPH_AttachScale(hItem, hScaleX);
		GRAPH_SetBorder(hItem, 70, 0, 0, 30);
		GRAPH_SetUserDraw(hItem, _UserDraw);
		
		_hDataXY1 = GRAPH_DATA_XY_Create(GUI_GREEN, 900, _aPoints1, GUI_COUNTOF(_aPoints1));
		_hDataXY2 = GRAPH_DATA_XY_Create(GUI_RED, 900, _aPoints2, GUI_COUNTOF(_aPoints2));
		_hDataXY3 = GRAPH_DATA_XY_Create(GUI_YELLOW, 900, _aPoints3, GUI_COUNTOF(_aPoints3));
		_hDataXY4 = GRAPH_DATA_XY_Create(GUI_DARKCYAN, 900, _aPoints4, GUI_COUNTOF(_aPoints4));
		GRAPH_DATA_XY_SetLineStyle(_hDataXY1, GUI_LS_SOLID);
		GRAPH_DATA_XY_SetLineStyle(_hDataXY2, GUI_LS_SOLID);
		GRAPH_DATA_XY_SetLineStyle(_hDataXY3, GUI_LS_SOLID);
		GRAPH_DATA_XY_SetLineStyle(_hDataXY4, GUI_LS_SOLID);
		GRAPH_AttachData(hItem, _hDataXY1);
		GRAPH_AttachData(hItem, _hDataXY2);
		GRAPH_AttachData(hItem, _hDataXY3);
		GRAPH_AttachData(hItem, _hDataXY4);
		GRAPH_SetGridVis(hItem, 1);
		
		break;
	case WM_TIMER:
		//
		// Depending on Stop, restart the graph
		//
		if (Stop == 0) {
			WM_RestartTimer(hTimer, 0);
		}
		
		/*
		if (Value >= 200) Angle = 0;
		if (Value <= 0) Angle = 1;
		if (Angle) Value++; 
		else	   Value--;

		GRAPH_DATA_YT_AddValue(hDataSin,Value);
		*/
		Angle++;
		hItem = WM_GetDialogItem(pMsg->hWin, ID_GRAPH_0);
		GRAPH_DetachData(hItem, _hDataXY1);
		GRAPH_DetachData(hItem, _hDataXY2);
		GRAPH_DetachData(hItem, _hDataXY3);
		GRAPH_DetachData(hItem, _hDataXY4);
		GRAPH_DATA_XY_Delete(_hDataXY1);
		GRAPH_DATA_XY_Delete(_hDataXY2);
		GRAPH_DATA_XY_Delete(_hDataXY3);
		GRAPH_DATA_XY_Delete(_hDataXY4);
		//
		// Create a new one and attach it
		//
		
		fillGraphData(Angle);
		_hDataXY1 = GRAPH_DATA_XY_Create(GUI_GREEN, 900, _aPoints1, GUI_COUNTOF(_aPoints1));
		_hDataXY2 = GRAPH_DATA_XY_Create(GUI_RED, 900, _aPoints2, GUI_COUNTOF(_aPoints2));
		_hDataXY3 = GRAPH_DATA_XY_Create(GUI_YELLOW, 900, _aPoints3, GUI_COUNTOF(_aPoints3));
		_hDataXY4 = GRAPH_DATA_XY_Create(GUI_DARKCYAN, 900, _aPoints4, GUI_COUNTOF(_aPoints4));

		GRAPH_AttachData(hItem, _hDataXY1);
		GRAPH_AttachData(hItem, _hDataXY2);
		GRAPH_AttachData(hItem, _hDataXY3);
		GRAPH_AttachData(hItem, _hDataXY4);
		break;
	case MESSAGE_STARTSTOP:
		//
		// Start stop message send by the GRAPH
		//
		Stop ^= 1;
		if (Stop == 0) {
			WM_RestartTimer(hTimer, 0);
		}
		break;
	case WM_PAINT :
		hTimer = WM_CreateTimer(pMsg->hWin, 0, 10, 0);
		break;
	default:
		WM_DefaultProc(pMsg);
		break;
	}
}

/*********************************************************************
*
*       _cbBk
*/
static void _cbBk(WM_MESSAGE * pMsg) {
	switch (pMsg->MsgId) {
	case WM_PAINT:
		GUI_SetBkColor(GUI_BLACK);
		GUI_Clear();
		break;
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
*       MainTask
*/
WM_HWIN CreateLogWindow(void) {

	return GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
}
