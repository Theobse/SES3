/*
 * AUTHOR     : Mohamed Sherif
 * MICRO      : STM32F401CCU6
 * LAYER      : MCAL
 * DRIVER     : NVIC_Driver
 * File       : Program File
 * Version    : 1.0
 * Created on : Aug 13, 2023
 */

/*******************************************   Includes    ***********************************************/

#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_TYPES.h"

#include "NVIC_config.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"

/*******************************************   Global Variables    ***********************************************/

u32 Global_u32GroupMode;

/*******************************************   APIs    ***********************************************/

void NVIC_vEnableInterrupt (u8 Copy_u8IntNum) {
	u8 L_u8Register				= Copy_u8IntNum / REGISTER_BITS	;
	u8 L_u8BitNum				= Copy_u8IntNum % REGISTER_BITS	;
	NVIC->ISER[L_u8Register]	= 1 << L_u8BitNum				;
}

/******************************************************************************************************/

void NVIC_vDisableInterrupt(u8 Copy_u8IntNum){
	u8 L_u8Register				= Copy_u8IntNum / REGISTER_BITS	;
	u8 L_u8BitNum				= Copy_u8IntNum % REGISTER_BITS	;
	NVIC->ICER[L_u8Register]	= 1 << L_u8BitNum				;
}

/******************************************************************************************************/

void NVIC_vSetPendingFlag(u8 Copy_u8IntNum){
	u8 L_u8Register				= Copy_u8IntNum / REGISTER_BITS	;
	u8 L_u8BitNum				= Copy_u8IntNum % REGISTER_BITS	;
	NVIC->ISPR[L_u8Register]	= 1 << L_u8BitNum				;
}

/******************************************************************************************************/

void NVIC_vClearPendingFlag(u8 Copy_u8IntNum){
	u8 L_u8Register				= Copy_u8IntNum / REGISTER_BITS	;
	u8 L_u8BitNum				= Copy_u8IntNum % REGISTER_BITS	;
	NVIC->ICPR[L_u8Register]	= 1 << L_u8BitNum				;
}

/******************************************************************************************************/

u8 NVIC_vReadInterruptStatus (u8 Copy_u8IntNum) {
	u8 L_u8Register	= Copy_u8IntNum / REGISTER_BITS					;
	u8 L_u8BitNum	= Copy_u8IntNum % REGISTER_BITS					;
	u8 L_u8Status	= NVIC->IABR[L_u8Register] & (1 << L_u8BitNum)	;
	return L_u8Status;
}

/******************************************************************************************************/

void NVIC_vSetGroupMode (Group_mode COPY_GROUPMODE) {
	Global_u32GroupMode = COPY_GROUPMODE;
	AIRCR = VECTKEY | (Global_u32GroupMode << 8);
}

/******************************************************************************************************/

void NVIC_vSetInterruptPriority (u8 Copy_u8IntNum, u8 Copy_GroupNum, u8 Copy_SubGroupNum) {
	u8 L_u8Register	= Copy_u8IntNum / 4			;
	u8 L_u8BitNum	= (Copy_u8IntNum % 4) * 8	;
	switch(Global_u32GroupMode) {
		case  NVIC_G16_SG0	: NVIC->IPR[L_u8Register] |= (Copy_GroupNum << (L_u8BitNum + 4)) 										  ;	break;
		case  NVIC_G8_SG2	: NVIC->IPR[L_u8Register] |= (Copy_GroupNum << (L_u8BitNum + 5) | (Copy_SubGroupNum << (L_u8BitNum + 4))) ; break;
		case  NVIC_G4_SG4	: NVIC->IPR[L_u8Register] |= (Copy_GroupNum << (L_u8BitNum + 6) | (Copy_SubGroupNum << (L_u8BitNum + 4))) ; break;
		case  NVIC_G2_SG8	: NVIC->IPR[L_u8Register] |= (Copy_GroupNum << (L_u8BitNum + 7) | (Copy_SubGroupNum << (L_u8BitNum + 4))) ; break;
		case  NVIC_G0_SG16	: NVIC->IPR[L_u8Register] |= 									  (Copy_SubGroupNum << (L_u8BitNum + 4))  ; break;
		default				: /* Wrong Configuration */ 																				break;
	}
}

/******************************************************************************************************/
