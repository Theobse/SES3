/*********************************************************************
*                SEGGER MICROCONTROLLER GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 2003-2010     SEGGER Microcontroller GmbH & Co KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

----------------------------------------------------------------------
File        : DROPDOWN_Private.h
Purpose     : DROPDOWN private header file
--------------------END-OF-HEADER-------------------------------------
*/

#ifndef DROPDOWN_PRIVATE_H
#define DROPDOWN_PRIVATE_H

#include "DROPDOWN.h"
#include "WIDGET.h"
#include "GUI_ARRAY.h"

#if GUI_WINSUPPORT

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define DROPDOWN_SF_AUTOSCROLLBAR DROPDOWN_CF_AUTOSCROLLBAR

/*********************************************************************
*
*       Object definition
*
**********************************************************************
*/
typedef struct {
  WIDGET_DRAW_ITEM_FUNC * pfDrawSkin;
} DROPDOWN_SKIN_PRIVATE;

typedef struct {
  const GUI_FONT GUI_UNI_PTR * pFont;
  GUI_COLOR aBackColor[3];
  GUI_COLOR aTextColor[3];
  GUI_COLOR aColor[2];
  GUI_COLOR aScrollbarColor[3];
  DROPDOWN_SKIN_PRIVATE SkinPrivate;
  I16       TextBorderSize;
  I16       Align;
} DROPDOWN_PROPS;

typedef struct {
  WIDGET  Widget;
  I16     Sel;                        /* current selection */
  I16     ySizeEx;                    /* Drop down size */
  I16     TextHeight;
  GUI_ARRAY Handles;
  WM_SCROLL_STATE ScrollState;
  DROPDOWN_PROPS Props;
  WIDGET_SKIN const * pWidgetSkin;
  WM_HWIN hListWin;
  U8      Flags;
  U16     ItemSpacing;
  U8      ScrollbarWidth;
  char  IsPressed;
  WM_HMEM hDisabled;
  #if GUI_DEBUG_LEVEL >1
    U32 DebugId;
  #endif  
} DROPDOWN_Obj;

/*********************************************************************
*
*       Macros for internal use
*
**********************************************************************
*/
#if GUI_DEBUG_LEVEL >= GUI_DEBUG_LEVEL_CHECK_ALL
  #define DROPDOWN_INIT_ID(p) p->DebugId = DROPDOWN_ID
#else
  #define DROPDOWN_INIT_ID(p)
#endif

#if GUI_DEBUG_LEVEL >= GUI_DEBUG_LEVEL_CHECK_ALL
  DROPDOWN_Obj * DROPDOWN_LockH(DROPDOWN_Handle h);
  #define DROPDOWN_LOCK_H(h)   DROPDOWN_LockH(h)
#else
  #define DROPDOWN_LOCK_H(h)   (DROPDOWN_Obj *)GUI_LOCK_H(h)
#endif

/*********************************************************************
*
*       Private (module internal) data
*
**********************************************************************
*/

extern DROPDOWN_PROPS DROPDOWN__DefaultProps;

extern const WIDGET_SKIN DROPDOWN__SkinClassic;
extern       WIDGET_SKIN DROPDOWN__Skin;

extern WIDGET_SKIN const * DROPDOWN__pSkinDefault;

/*********************************************************************
*
*       Private functions
*
**********************************************************************
*/

void DROPDOWN__AdjustHeight(DROPDOWN_Handle hObj);
int  DROPDOWN__GetNumItems (DROPDOWN_Obj * pObj);
const char * DROPDOWN__GetpItemLocked(DROPDOWN_Handle hObj, int Index);

#endif /* GUI_WINSUPPORT */
#endif /* DROPDOWN_PRIVATE_H */
