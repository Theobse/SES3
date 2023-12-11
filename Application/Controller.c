#include "Controller.h"

WM_HWIN aHandles[100];


void showhideWindow(int index,int n) {
	for (int i = 0; i < n;i++) {
		if (i == index)
			WM_ShowWindow(aHandles[i]);
		else
			WM_HideWindow(aHandles[i]);
	}
}

void MainTask(void) {
	GUI_Init();

	WM_SetCreateFlags(WM_CF_MEMDEV);
	WM_EnableMemdev(WM_HBKWIN);


	aHandles[PG_SETTINGS] = CreateSettingsWindow();
	aHandles[PG_OFFSETS] = CreateOffsetsWindow(); 
	aHandles[PG_CHECKPOINT] = CreateCheckPointWindow();
	aHandles[PG_CUP1CP] = CreateCup1CPWindow();
	aHandles[PG_CUP2CP] = CreateCup2CPWindow();
	aHandles[PG_RESULTRULES] = CreateResultRulesWindow();
	aHandles[PG_LIMITS] = CreateLimitsWindow();
	aHandles[PG_NODULARITY] = CreateNodularityWindow();
	aHandles[PG_ABOUT] = CreateAboutWindow();
	aHandles[PG_LOG] = CreateLogWindow();
	aHandles[PG_CALIB] = CreateCalibrationWindow();
	showhideWindow(PG_SETTINGS, PAGES);

	while (1) {
		GUI_Delay(1000);

	}
}