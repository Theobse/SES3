#pragma once
#include "DIALOG.h"
#include "./Screens/SettingsWindowDLG.h"
#include "./Screens/CheckPointWindowDLG.h"
#include "./Screens/OffsetsWindowDLG.h"
#include "./Screens/Cup1CPWindowDLG.h"
#include "./Screens/Cup2CPWindowDLG.h"
#include "./Screens/ResultRulesWindowDLG.h"
#include "./Screens/LimitsWindowDLG.h"
#include "./Screens/NodularityWindowDLG.h"


#define PAGES ( 11 )
#define PG_SETTINGS ( 0 )
#define PG_OFFSETS	( 1 )
#define PG_CHECKPOINT ( 2 )
#define PG_CUP1CP	( 3 )
#define PG_CUP2CP	( 4 )
#define PG_RESULTRULES	( 5 )
#define PG_LIMITS	( 6 )
#define PG_NODULARITY	( 7 )
#define PG_ABOUT	( 8 )
#define PG_LOG		( 9 )
#define PG_CALIB	( 10 )

void showhideWindow( int index, int n);
