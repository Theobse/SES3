/*
 * AUTHOR     : Mohamed Sherif
 * MICRO      : STM32F401CCU6
 * LAYER      : MCAL
 * DRIVER     : RCC_Driver
 * File       : Interface File
 * Version    : 1.0
 * Created on : Aug 7, 2023
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/*
 * Buses Macros
 */
#define  AHB1_BUS	0
#define  AHB2_BUS	1
#define  APB1_BUS	2
#define  APB2_BUS	3

/*
 * RCC clock control register (RCC_CR) Bits
 */
#define HSION		0
#define HSIRDY		1


#define HSEON		16
#define HSERDY		17
#define HSEBYP		18




#define PLLON		24
#define PLLRDY		25



/*
 * RCC clock configuration register (RCC_CFGR) Bits
 */
#define SW0		0
#define SW1		1



/*
 * RCC PLL configuration register (RCC_PLLCFGR) Bits
 */
#define PLLM0		0
#define PLLM1		1
#define PLLM2		2
#define PLLM3		3
#define PLLM4		4
#define PLLM5		5
#define PLLN0		6	// Accessed half word or word only
#define PLLP0		16
#define PLLP1		17
#define PLLSRC		22
#define PLLQ0		24
#define PLLQ1		26
#define PLLQ2		27
#define PLLQ3		28

/*
 *	RCC AHB1 peripheral clock enable register (RCC_AHB1ENR) Bits
 */
#define GPIOAEN		0
#define GPIOBEN		1
#define GPIOCEN		2
#define GPIODEN		3
#define GPIOEEN		4
#define GPIOHEN		7
#define CRCEN		12
#define DMA1EN		21
#define DMA2EN		22

/*
 * NAME: RCC_vInit
 * PARAM: void
 * RETURN VALUE: void
 * DESCRIPTION: initialize the Clock
 */
void RCC_vInit(void);

/*
 * NAME: RCC_vEnPeriphral
 * PARAM: Copy_u8BusName, Copy_u8PeripheralNum
 * RETURN VALUE: void
 * DESCRIPTION: enable the peripheral
 */
void RCC_vEnPeriphral(u8 Copy_u8BusName, u8 Copy_u8PeripheralNum);

/*
 * NAME: RCC_vDisablePeriphral
 * PARAM: Copy_u8BusName, Copy_u8PeripheralNum
 * RETURN VALUE: void
 * DESCRIPTION: disable the peripheral
 */
void RCC_vDisablePeriphral(u8 Copy_u8BusName, u8 Copy_u8PeripheralNum);

#endif
