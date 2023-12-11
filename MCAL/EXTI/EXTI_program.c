/*
 * AUTHOR     : Mohamed Sherif
 * MICRO      : STM32F401CCU6
 * LAYER      : MCAL
 * DRIVER     : EXTI_Driver
 * File       : Program File
 * Version    : 1.0
 * Created on : Aug 14, 2023
 */

/********************************************* Includes *********************************************************/

#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_TYPES.h"

#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"

/******************************************************************************************************/

static void (*EXTI0_callback)(void) = NULL;
static void (*EXTI1_callback)(void) = NULL;

/****************************************** APIs ************************************************************/

void EXTI_vEnableInterrupt(EXTI_LINE_t Copy_tLineNum){
	SET_BIT(EXTI->IMR, Copy_tLineNum);
}

/******************************************************************************************************/

void EXTI_vDisableInterrupt(EXTI_LINE_t Copy_tLineNum){
	CLEAR_BIT(EXTI->IMR, Copy_tLineNum);
}

/******************************************************************************************************/

void EXTI_vEnableEvent(EXTI_LINE_t Copy_tLineNum){
	SET_BIT(EXTI->EMR, Copy_tLineNum);
}

/******************************************************************************************************/

void EXTI_vDisableEvent(EXTI_LINE_t Copy_tLineNum){
	CLEAR_BIT(EXTI->EMR, Copy_tLineNum);
}

/******************************************************************************************************/

void EXTI_vSoftwareInterrupt(EXTI_LINE_t Copy_tLineNum){
	SET_BIT(EXTI->SWIER, Copy_tLineNum);
}

/******************************************************************************************************/

void EXTI_vSetTriggerSource(EXTI_LINE_t Copy_tLineNum, EXTI_TRIGGER_MODE_t Copy_tTriggerMode){
	switch(Copy_tTriggerMode){
		case EXTI_RISING_EDGE	: SET_BIT(EXTI->RTSR, Copy_tLineNum); 										break;
		case EXTI_FALLING_EDGE	: SET_BIT(EXTI->FTSR, Copy_tLineNum); 										break;
		case EXTI_ON_CHANGE		: SET_BIT(EXTI->RTSR, Copy_tLineNum); SET_BIT(EXTI->FTSR, Copy_tLineNum); 	break;
		default					: /* Do nothing */ 															break;
	}
}

/******************************************************************************************************/

void EXTI_vSetConfiguration(EXTI_LINE_t Copy_tLineNum, EXTI_PORT_t Copy_tGpioPortNum){
	u8 L_u8Register	= Copy_tLineNum / 4	;
	u8 L_u8BitNum	= Copy_tLineNum % 4	;
	switch(L_u8Register){
		case SYSCFG_EXTICR1: SYSCFG->EXTICR1 &= ~(0b111 << (L_u8BitNum * 4)) ; SYSCFG->EXTICR1 |= (Copy_tGpioPortNum << (L_u8BitNum * 4)) ;	break;
		case SYSCFG_EXTICR2: SYSCFG->EXTICR2 &= ~(0b111 << (L_u8BitNum * 4)) ; SYSCFG->EXTICR2 |= (Copy_tGpioPortNum << (L_u8BitNum * 4)) ;	break;
		case SYSCFG_EXTICR3: SYSCFG->EXTICR3 &= ~(0b111 << (L_u8BitNum * 4)) ; SYSCFG->EXTICR3 |= (Copy_tGpioPortNum << (L_u8BitNum * 4)) ;	break;
		case SYSCFG_EXTICR4: SYSCFG->EXTICR4 &= ~(0b111 << (L_u8BitNum * 4)) ; SYSCFG->EXTICR4 |= (Copy_tGpioPortNum << (L_u8BitNum * 4)) ;	break;
		default		: /* Do nothing */																										break;
	}
}

/******************************************************************************************************/

void EXTI0_vCallBack(void (*ptr)(void)){
	EXTI0_callback = ptr;
}

/******************************************************************************************************/

void EXTI1_vCallBack(void (*ptr)(void)){
	EXTI1_callback = ptr;
}

/******************************************************************************************************/

void EXTI1_IRQHandler(void) {
	if(EXTI1_callback != NULL){
		EXTI1_callback();
	}
}

/******************************************************************************************************/
