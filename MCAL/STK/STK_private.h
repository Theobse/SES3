/*
 * AUTHOR     : Mohamed Sherif
 * MICRO      : STM32F401CCU6
 * LAYER      : MCAL
 * DRIVER     : STK_Driver
 * File       : Private File
 * Version    : 1.0
 * Created on : Aug 15, 2023
 */

#ifndef MCAL_STK_STK_PRIVATE_H_
#define MCAL_STK_STK_PRIVATE_H_

#define STK_BASE_ADDRESS 0xE000E010

typedef struct{
	volatile u32 CTRL	;
	volatile u32 LOAD	;
	volatile u32 VAL	;
	volatile u32 CALIB	;
}STK_t;

#define STK ((volatile STK_t*)STK_BASE_ADDRESS)

/*
 * 0: AHB/8
 * 1: Processor clock (AHB)
 */
#define STK_AHB_DIV_8 	0
#define STK_AHB			1

#define INTERRUPT_DISABLE	0
#define INTERRUPT_ENABLE	1

/*
 * SysTick control and status register (STK_CTRL) Bits
 */
#define ENABLE 		0
#define TICKINT 	1
#define CLKSOURCE 	2
#define COUNTFLAG 	16

#endif /* MCAL_STK_STK_PRIVATE_H_ */
