/*
 * AUTHOR     : Mohamed Sherif
 * MICRO      : STM32F401CCU6
 * LAYER      : MCAL
 * DRIVER     : GPIO_Driver
 * File       : Interface File
 * Version    : 1.0
 * Created on : Aug 9, 2023
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*
 * GPIO port configuration lock register (GPIOx_LCKR) Bits
 */
#define LCKK 16

/********************************************* Prototypes *********************************************************/

/*
 * NAME: GPIO_vSetPinMode
 * PARAM: Copy_u8Port, Copy_u8Pin, Copy_u8PinMode
 * RETURN VALUE: void
 * DESCRIPTION: Set Pin Mode {
 * 					00: Input (reset state)          -->  1- MODE_INPUT
 *					01: General purpose output mode  -->  2- MODE_OUTPUT
 *					10: Alternate function mode      -->  3- MODE_ALTF
 *					11: Analog mode                  -->  4- MODE_ANALOGE
 * 				}
 */
void GPIO_vSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinMode);

/******************************************************************************************************/

/*
 * NAME: GPIO_u8GetPinValue
 * PARAM: Copy_u8Port, Copy_u8Pin
 * RETURN VALUE: u8 PinVal
 * DESCRIPTION: Get Pin Value
 */
u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

/******************************************************************************************************/

/*
 * NAME: GPIO_vSetPinOutValue
 * PARAM: Copy_u8Port, Copy_u8Pin, Copy_u8PinOutVal{
 * 												1: BIT_SET
 * 												0: BIT_RESET
 * 											}
 * RETURN VALUE: void
 * DESCRIPTION: Write new value on the Pin
 */
void GPIO_vSetPinOutValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutVal);

/******************************************************************************************************/

/*
 * NAME: GPIO_vSetPinOutType
 * PARAM: Copy_u8Port, Copy_u8Pin, Copy_u8PinOutType
 * RETURN VALUE: void
 * DESCRIPTION: Set Pin Type {
 * 					0: Output push-pull (reset state)  --> 1- PUSH_PULL
 *					1: Output open-drain               --> 2- OPEN_DRAIN
 * 				}
 */
void GPIO_vSetPinOutType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutType);

/******************************************************************************************************/

/*
 * NAME: GPIO_vSetPinOutSpeed
 * PARAM: Copy_u8Port, Copy_u8Pin, Copy_u8PinOutSpeed
 * RETURN VALUE: void
 * DESCRIPTION: Set Pin's exchanging state Speed {
 * 								00: Low speed          --> 1- LOW_SPEED
 *								01: Medium speed       --> 2- MEDIUM_SPEED
 *								10: High speed         --> 3- HIGH_SPEED
 *								11: Very high speed    --> 4- VERY_HIGH_SPEED
 * 							}
 */
void GPIO_vSetPinOutSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutSpeed);

/******************************************************************************************************/

/*
 * NAME: GPIO_vSetPullType
 * PARAM: Copy_u8Port, Copy_u8Pin, Copy_u8PullType
 * RETURN VALUE: void
 * DESCRIPTION: Set Pin Pull Type {
 * 								00: No pull-up, pull-down       --> 1- NO_PULL
 *								01: Pull-up       				--> 2- PULL_UP
 *								10: Pull-down       			--> 3- PULL_DOWN
 * 							}
 */
void GPIO_vSetPullType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PullType);

/******************************************************************************************************/

/*
 * NAME: GPIO_vSetPinLock
 * PARAM: Copy_u8Port, Copy_u32RegisterValue
 * RETURN VALUE: void
 * DESCRIPTION: Set Lock to Port Pins
 * NOTE: Only word access (32-bit long) is allowed during this write sequence.
 */
void GPIO_vSetPinLock(u8 Copy_u8Port, u32 Copy_u32RegisterValue);

/******************************************************************************************************/

/*
 * NAME: GPIO_vSetPinAltFunction
 * PARAM: Copy_u8Port, Copy_u8Pin, Copy_u8AltFunction
 * RETURN VALUE: void
 * DESCRIPTION: Set Lock to Port Pins
 * NOTE: Only word access (32-bit long) is allowed during this write sequence.
 */
void GPIO_vSetPinAltFunction(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8AltFunction);

/******************************************************************************************************/

/*
 * NAME: GPIO_vTogglePin
 * PARAM: Copy_u8Port, Copy_u8Pin
 * RETURN VALUE: void
 * DESCRIPTION: Toggles given pin
 */
void GPIO_vTogglePin(u8 Copy_u8Port, u8 Copy_u8Pin);

/******************************************************************************************************/

#endif /* GPIO_INTERFACE_H_ */
