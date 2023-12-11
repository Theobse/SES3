/*
 * AUTHOR     : Mohamed Sherif
 * MICRO      : STM32F401CCU6
 * LAYER      : MCAL
 * DRIVER     : RCC_Driver
 * File       : Private File
 * Version    : 1.0
 * Created on : Aug 7, 2023
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

typedef struct{
	volatile u32 CR;
	volatile u32 PLLCFGR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 AHB1RST;
	volatile u32 AHB2RST;
	volatile u32 Reserved1[2];
	volatile u32 APB1RST;
	volatile u32 APB2RST;
	volatile u32 Reserved2[2];
	volatile u32 AHB1ENR;
	volatile u32 AHB2ENR;
	volatile u32 Reserved3[2];
	volatile u32 APB1ENR;
	volatile u32 APB2ENR;
	volatile u32 Reserved4[2];
	volatile u32 AHB1LPENR;
	volatile u32 AHB2LPENR;
	volatile u32 Reserved5[2];
	volatile u32 APB1LPENR;
	volatile u32 APB2LPENR;
	volatile u32 Reserved6[2];
	volatile u32 BDCR;
	volatile u32 CSR;
	volatile u32 Reserved7[2];
	volatile u32 SSCGR;
	volatile u32 PLLI2SCFGR;
	volatile u32 Reserved15;
	volatile u32 DCKCFGR;
}RCC_t;

#define RCC_BASE_ADDRESS 0x40023800

#define RCC	((RCC_t *)RCC_BASE_ADDRESS)

#define RCC_HSI	0
#define RCC_HSE	1
#define RCC_PLL	2

#define	RCC_HSE_BYPASS	1
#define	RCC_HSE_CRYSTAL	2

#define PLL_HSI 0
#define PLL_HSE 1

#define PLLCFGR_RESET_VALUE 0xF0FC8000

#endif
