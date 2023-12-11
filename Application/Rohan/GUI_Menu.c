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

#define GRID_W	( 200 )
#define GRID_H	( 159 )

void drawGrid() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			GUI_DrawRect(GRID_W*i, GRID_H * j, GRID_W * (i + 1), GRID_H * (j + 1));
		}
	}
	GUI_DrawRect(400, 0, 799, 318);
	GUI_DrawRect(400, 318, 799, 477);
}

void drawDate(char *date) {
	int curAlignment = GUI_GetTextAlign();
	GUI_SetTextAlign(GUI_TA_RIGHT | GUI_TA_BASELINE);
	GUI_DispStringAt(date,795,465);
	GUI_SetTextAlign(curAlignment);
}

void drawTableData() {
	GUI_DispStringHCenterAt("CUP1", 100, 80);
	GUI_DispStringHCenterAt("CUP2", 100, 240);
	GUI_DispStringHCenterAt("PTL", 100, 400);
	GUI_DispStringHCenterAt("OPEN", 300, 80);
	GUI_DispStringHCenterAt("OPEN", 300, 240);
	GUI_DispStringHCenterAt("OPEN", 300, 400);

	const GUI_FONT *currentFont = GUI_GetFont();
	GUI_SetFont(&GUI_Font32B_1);
	GUI_DispStringAt("Grade: ", 405, 50);
	GUI_DispStringAt("Fsize: ", 405, 100);
	GUI_DispStringAt("Target: ", 405,150);
	GUI_DispStringAt("C: ", 405, 200);
	GUI_DispStringAt("Si: ", 405, 250);
	GUI_DispStringAt("Pyro: ", 405, 370);
	GUI_DispStringAt("Cup: ", 405, 420);

	GUI_DispStringAt("CI1", 575, 50);
	GUI_DispStringAt("1 Kg. ", 575, 100);
	GUI_DispStringAt("", 575, 150);
	GUI_DispStringAt("3.00", 575, 200);
	GUI_DispStringAt("1.00", 575, 250);
	GUI_DispStringAt("R Type", 575, 370);
	GUI_DispStringAt("CE Cup", 575, 420);

	GUI_SetFont(currentFont);

}
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
  drawGrid();
  drawDate("2011-11-10");
  drawTableData();
  while(1) {
    GUI_Delay(575);
  }
}

/****** End of File *************************************************/
