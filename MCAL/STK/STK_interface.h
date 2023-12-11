/*
 * AUTHOR     : Mohamed Sherif
 * MICRO      : STM32F401CCU6
 * LAYER      : MCAL
 * DRIVER     : STK_Driver
 * File       : Interface File
 * Version    : 1.0
 * Created on : Aug 15, 2023
 */

#ifndef MCAL_STK_STK_INTERFACE_H_
#define MCAL_STK_STK_INTERFACE_H_

/****************************************** Prototypes ************************************************************/

/*
 * NAME: STK_vInit
 * PARAM: void
 * RETURN VALUE: void
 * DESCRIPTION: initialize the System Timer
 */
void STK_vInit(void);

/******************************************************************************************************/

/*
 * NAME: STK_vSetInterrupt
 * PARAM: void
 * RETURN VALUE: void
 * DESCRIPTION: Enables interrupt
 */
void STK_vSetInterrupt(void);

/******************************************************************************************************/

/*
 * NAME: STK_vClearInterrupt
 * PARAM: void
 * RETURN VALUE: void
 * DESCRIPTION: Disables interrupt
 */
void STK_vClearInterrupt(void);

/******************************************************************************************************/

/*
 * NAME: STK_vSetReloadValue
 * PARAM: u32 Copy_u32ReloadValue
 * RETURN VALUE: void
 * DESCRIPTION: Set load register with passed value and start count down
 */
void STK_vSetReloadValue(u32 Copy_u32ReloadValue);

/******************************************************************************************************/

/*
 * NAME: STK_u32GetElapsedTime
 * PARAM: void
 * RETURN VALUE: (u32) elapsed time
 * DESCRIPTION: get elapsed time
 */
u32 STK_u32GetElapsedTime(void);

/******************************************************************************************************/

/*
 * NAME: STK_u32GetRemainingTime
 * PARAM: void
 * RETURN VALUE: (u32) remaining time
 * DESCRIPTION: get remaining time
 */
u32 STK_u32GetRemainingTime(void);

/******************************************************************************************************/

/*
 * NAME: STK_u8GetCountFlag
 * PARAM: void
 * RETURN VALUE: (u8) count flag --> 1 or 0
 * DESCRIPTION: get count flag
 */
u8 STK_u8GetCountFlag(void);

/******************************************************************************************************/

/*
 * NAME: STK_vDelayMs
 * PARAM: u32 Copy_u32Ms
 * RETURN VALUE: void
 * DESCRIPTION: set delay by milli seconds
 */
void STK_vDelayMs(u32 Copy_u32Ms);

/******************************************************************************************************/

/*
 * NAME: STK_vDelayUs
 * PARAM: u32 Copy_u32Us
 * RETURN VALUE: void
 * DESCRIPTION: set delay by micro seconds
 */
void STK_vDelayUs(u32 Copy_u32Us);

/******************************************************************************************************/

/*
 * NAME: STK_vCallBack
 * PARAM: void (*ptr)(void)
 * RETURN VALUE: void
 * DESCRIPTION: callback function
 */
void STK_vCallBack(void (*ptr)(void));

/******************************************************************************************************/

/*
 * NAME: STK_vSetIntervalPeriodic
 * PARAM: u32 Copy_u32Ticks, void (*ptr)(void)
 * RETURN VALUE: void
 * DESCRIPTION: sets interval periodic interrupts to executes the isr
 */
void STK_vSetIntervalPeriodic(u32 Copy_u32Ticks, void (*ptr)(void));

/******************************************************************************************************/

#endif /* MCAL_STK_STK_INTERFACE_H_ */
