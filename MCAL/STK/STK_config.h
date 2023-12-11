/*
 * AUTHOR     : Mohamed Sherif
 * MICRO      : STM32F401CCU6
 * LAYER      : MCAL
 * DRIVER     : STK_Driver
 * File       : Configuration File
 * Version    : 1.0
 * Created on : Aug 15, 2023
 */

#ifndef MCAL_STK_STK_CONFIG_H_
#define MCAL_STK_STK_CONFIG_H_

/*
 * STK_AHB_OVER_8
 * STK_AHB
 */
#define STK_CLOCK_SOURCE STK_AHB_OVER_8

/*
 * INTERRUPT_DISABLE
 * INTERRUPT_ENABLE
 */
#define STK_TICK_INTERRUPT INTERRUPT_DISABLE

#endif /* MCAL_STK_STK_CONFIG_H_ */
