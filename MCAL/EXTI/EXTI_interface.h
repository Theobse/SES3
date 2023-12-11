/*
 * AUTHOR     : Mohamed Sherif
 * MICRO      : STM32F401CCU6
 * LAYER      : MCAL
 * DRIVER     : EXTI_Driver
 * File       : Interface File
 * Version    : 1.0
 * Created on : Aug 14, 2023
 */

#ifndef EXTI_EXTI_INTERFACE_H_
#define EXTI_EXTI_INTERFACE_H_

/**
 * @enum EXTI_LINE_t
 * @brief Enumeration representing different EXTI lines.
 */
typedef enum{
	EXTI_LINE_0 = 0	,
	EXTI_LINE_1		,
	EXTI_LINE_2		,
	EXTI_LINE_3		,
	EXTI_LINE_4		,
	EXTI_LINE_5		,
	EXTI_LINE_6		,
	EXTI_LINE_7		,
	EXTI_LINE_8		,
	EXTI_LINE_9		,
	EXTI_LINE_10	,
	EXTI_LINE_11	,
	EXTI_LINE_12	,
	EXTI_LINE_13	,
	EXTI_LINE_14	,
	EXTI_LINE_15
}EXTI_LINE_t;

/******************************************************************************************************/

/**
 * @enum EXTI_TriggerMode_t
 * @brief Enumeration representing different trigger modes for EXTI lines.
 */
typedef enum{
	EXTI_RISING_EDGE = 0,
	EXTI_FALLING_EDGE	,
	EXTI_ON_CHANGE
}EXTI_TRIGGER_MODE_t;

/******************************************************************************************************/

/**
 * @enum EXTI_Port_t
 * @brief Enumeration representing different GPIO ports for EXTI configuration.
 */
typedef enum{
	EXTI_PORTA = 0	,
	EXTI_PORTB		,
	EXTI_PORTC
}EXTI_PORT_t;

/**************************************************** Prototypes **************************************************/

/*
 * NAME: EXTI_vEnableInterrupt
 * PARAM: Copy_tLineNum
 * RETURN VALUE: void
 * DESCRIPTION: Enable interrupt for specific line
 */
void EXTI_vEnableInterrupt(EXTI_LINE_t Copy_tLineNum);

/******************************************************************************************************/

/*
 * NAME: EXTI_vDisableInterrupt
 * PARAM: Copy_tLineNum
 * RETURN VALUE: void
 * DESCRIPTION: Disable interrupt for specific line
 */
void EXTI_vDisableInterrupt(EXTI_LINE_t Copy_tLineNum);

/******************************************************************************************************/

/*
 * NAME: EXTI_vEnableEvent
 * PARAM: Copy_tLineNum
 * RETURN VALUE: void
 * DESCRIPTION: Enable Event for specific line
 */
void EXTI_vEnableEvent(EXTI_LINE_t Copy_tLineNum);

/******************************************************************************************************/

/*
 * NAME: EXTI_vDisableEvent
 * PARAM: Copy_tLineNum
 * RETURN VALUE: void
 * DESCRIPTION: Disable Event for specific line
 */
void EXTI_vDisableEvent(EXTI_LINE_t Copy_tLineNum);

/******************************************************************************************************/

/*
 * NAME: EXTI_vSoftwareInterrupt
 * PARAM: Copy_tLineNum
 * RETURN VALUE: void
 * DESCRIPTION:
 */
void EXTI_vSoftwareInterrupt(EXTI_LINE_t Copy_tLineNum);

/******************************************************************************************************/

/*
 * NAME: EXTI_vSetTriggerSource
 * PARAM: Copy_tLineNum, Copy_tTriggerMode
 * RETURN VALUE: void
 * DESCRIPTION: Set Trigger Source {
 * 								EXTI_RISING_EDGE
 * 								EXTI_FALLING_EDGE
 * 								EXTI_ON_CHANGE
 * 							}
 */
void EXTI_vSetTriggerSource(EXTI_LINE_t Copy_tLineNum, EXTI_TRIGGER_MODE_t Copy_tTriggerMode);

/******************************************************************************************************/

/*
 * NAME: EXTI_vSetConfiguration
 * PARAM: Copy_tLineNum,
 * 						Copy_u8GpioPortNum {
 * 											EXTI_PORTA
 * 											EXTI_PORTB
 * 											EXTI_PORTC
 * 										}
 * RETURN VALUE: void
 * DESCRIPTION: select the source input for the external interrupt.
 */
void EXTI_vSetConfiguration(EXTI_LINE_t Copy_tLineNum, EXTI_PORT_t Copy_tGpioPortNum);

/******************************************************************************************************/

/*
 * NAME: EXTI0_vCallBack
 * PARAM: (*ptr)(void)
 * RETURN VALUE: void
 * DESCRIPTION:
 */
void EXTI0_vCallBack(void (*ptr)(void));

/******************************************************************************************************/

/*
 * NAME: EXTI1_vCallBack
 * PARAM: (*ptr)(void)
 * RETURN VALUE: void
 * DESCRIPTION:
 */
void EXTI1_vCallBack(void (*ptr)(void));

/******************************************************************************************************/

#endif /* EXTI_EXTI_INTERFACE_H_ */
