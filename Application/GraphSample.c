#include "DIALOG.h"
#include "stdlib.h"
#include "math.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0        (GUI_ID_USER + 0x00)
#define ID_GRAPH_0         (GUI_ID_USER + 0x01)
#define ID_GRAPH_1         (GUI_ID_USER + 0x02)

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "Window",          ID_WINDOW_0,   0, 0, 480, 272, 0, 0x0, 0 },
  { GRAPH_CreateIndirect, "Graph",            ID_GRAPH_0,   25, 86, 200, 100, 0, 0x0, 0 },
  { GRAPH_CreateIndirect, "Graph",            ID_GRAPH_1,  255, 86, 200, 100, 0, 0x0, 0 },
};

static GUI_POINT _aPoints[200];
static GRAPH_DATA_Handle _hDataXY;
static GRAPH_DATA_Handle _hDataYT0;
static GRAPH_DATA_Handle _hDataYT1;

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Window'
    //
    hItem = pMsg->hWin;
   // WINDOW_SetBkColor(hItem, GUI_MAKE_COLOR(0x00353644));
	WINDOW_SetBkColor(hItem, GUI_BLACK);
    //
    // Graph YT
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_GRAPH_0);
    _hDataYT0 = GRAPH_DATA_YT_Create(GUI_RED, 200, NULL, 0);
    _hDataYT1 = GRAPH_DATA_YT_Create(GUI_ORANGE, 200, NULL, 0);
    GRAPH_AttachData(hItem, _hDataYT0);
    GRAPH_AttachData(hItem, _hDataYT1);
    GRAPH_SetGridVis(hItem, 1);
    //
    // Graph XY
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_GRAPH_1);
    _hDataXY = GRAPH_DATA_XY_Create(GUI_GREEN, 200, _aPoints, GUI_COUNTOF(_aPoints));
    GRAPH_DATA_XY_SetLineStyle(_hDataXY, GUI_LS_SOLID);
    GRAPH_AttachData(hItem, _hDataXY);
    GRAPH_SetGridVis(hItem, 1);
    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       _ChangeDataXY
*/
static void _ChangeDataXY(void) {
  static int Index;
  WM_HWIN hItem;

  //
  // Fill the array which holds the value to be displayed
  //
  _aPoints[Index].x = Index;
  //_aPoints[Index++].y = rand() % 30 + 50;
  _aPoints[Index++].y = sqrt(Index);
  if (Index == GUI_COUNTOF(_aPoints)) {
    Index = 0;
  }
  //
  // Get the GRAPH handle
  //
  hItem = WM_GetFirstChild(WM_HBKWIN);
  hItem = WM_GetDialogItem(hItem, ID_GRAPH_1);
  //
  // Detach data handle and delete it
  //
  GRAPH_DetachData(hItem, _hDataXY);
  GRAPH_DATA_XY_Delete(_hDataXY);
  //
  // Create a new one and attach it
  //
  _hDataXY = GRAPH_DATA_XY_Create(GUI_GREEN, 200, _aPoints, GUI_COUNTOF(_aPoints));
  GRAPH_AttachData(hItem, _hDataXY);
}

/*********************************************************************
*
*       _ChangeDataYT
*/
static void _ChangeDataYT(GRAPH_DATA_Handle hData, int Offset) {
  //
  // Add a value to the given handle
  //
  GRAPH_DATA_YT_AddValue(hData, (I16)rand() % 30 + Offset);
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
void MainTask(void) {
  int i;

  GUI_Init();
  //
  // Create dialog containing the GRAPH widgets
  //
  GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  while (1) {
    //
    // Change data to be displayed
    //
    for (i = 0; i < GUI_COUNTOF(_aPoints); i++) {
      _ChangeDataXY();
      _ChangeDataYT(_hDataYT0, 60);
    }
    GUI_Delay(100);
    _ChangeDataYT(_hDataYT1, 20);
  }
}
