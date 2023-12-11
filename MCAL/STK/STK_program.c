/*
 * AUTHOR     : Mohamed Sherif
 * MICRO      : STM32F401CCU6
 * LAYER      : MCAL
 * DRIVER     : STK_Driver
 * File       : Program File
 * Version    : 1.0
 * Created on : Aug 15, 2023
 */

/********************************************* Includes *********************************************************/

#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_TYPES.h"

#include "STK_private.h"
#include "STK_interface.h"
#include "STK_config.h"

/********************************************** Global Declaration ********************************************************/

void (* STK_G_Callback) (void) = NULL;

/********************************************** APIs ********************************************************/

void STK_vInit(void){

#if STK_CLOCK_SOURCE == STK_AHB_OVER_8

	CLEAR_BIT(STK->CTRL, CLKSOURCE);

#elif STK_CLOCK_SOURCE == STK_AHB

	SET_BIT(STK->CTRL, CLKSOURCE);

#endif

}

/******************************************************************************************************/

void STK_vSetInterrupt(void){
	SET_BIT(STK->CTRL, TICKINT);
}

/******************************************************************************************************/

void STK_vClearInterrupt(void){
	CLEAR_BIT(STK->CTRL, TICKINT);
}

/******************************************************************************************************/

void STK_vSetReloadValue(u32 Copy_u32ReloadValue){
	STK->LOAD = Copy_u32ReloadValue;
	STK->VAL = 0;
	SET_BIT(STK->CTRL, ENABLE);
}

/******************************************************************************************************/

u32 STK_u32GetElapsedTime(void){
	return STK->LOAD - STK->VAL;
}

/******************************************************************************************************/

u32 STK_u32GetRemainingTime(void){
	return STK->VAL;
}

/******************************************************************************************************/

u8 STK_u8GetCountFlag(void){
	return GET_BIT(STK->CTRL, COUNTFLAG);
}

/******************************************************************************************************/

void STK_vDelayMs(u32 Copy_u32Ms){
	STK_vInit();
	CLEAR_BIT(STK->CTRL, TICKINT);
	STK->LOAD = (u32)(Copy_u32Ms * 2000); /*STK_Frq = 2 MHZ , 0.5 Micro second*/
	STK->VAL = 0;
	SET_BIT(STK->CTRL, ENABLE);
	while(GET_BIT(STK->CTRL, COUNTFLAG) == 0);
	CLEAR_BIT(STK->CTRL, ENABLE);
}

/******************************************************************************************************/

void STK_vDelayUs(u32 Copy_u32Us){
	STK_vInit();
	CLEAR_BIT(STK->CTRL, TICKINT);
	STK->LOAD = (u32)(Copy_u32Us * 2); /*STK_Frq = 2 MHZ , 0.5 Micro second*/
	STK->VAL = 0;
	SET_BIT(STK->CTRL, ENABLE);
	while(GET_BIT(STK->CTRL, COUNTFLAG) == 0);
	CLEAR_BIT(STK->CTRL, ENABLE);
}

/******************************************************************************************************/

void STK_vCallBack(void (*ptr)(void)){
	STK_G_Callback = ptr;
}

/******************************************************************************************************/

void SysTick_Handler(void){
	if(STK_G_Callback != NULL){
		STK_G_Callback();
	}
}

/******************************************************************************************************/

void STK_vSetIntervalPeriodic(u32 Copy_u32Ticks, void (*ptr)(void)){
	STK_vCallBack(ptr);
	STK_vSetReloadValue(Copy_u32Ticks);
}

/******************************************************************************************************/
