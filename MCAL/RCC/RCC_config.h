/*
 * AUTHOR     : Mohamed Sherif
 * MICRO      : STM32F401CCU6
 * LAYER      : MCAL
 * DRIVER     : RCC_Driver
 * File       : Configuration File
 * Version    : 1.0
 * Created on : Aug 7, 2023
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*
 * RCC_SYSCLK
 *  1- RCC_HSI
 *  2- RCC_HSE
 *  3- RCC_PLL
 */
#define RCC_SYSCLK  RCC_HSI

/*
 * RCC_HSE_MODE
 * 	1- RCC_HSE_BYPASS
 * 	2- RCC_HSE_CYRSTAL
 */
#define RCC_HSE_MODE  RCC_HSE_BYPASS

/*
 * PLL Source
 * 	1-PLL_HSE
 * 	2-PLL_HSI
 */
#define PLL_SRC		PLL_HSE

/*
 * • f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
 * • f(PLL general clock output) = f(VCO clock) / PLLP
 * • f(USB OTG FS, SDIO, RNG clock output) = f(VCO clock) / PLLQ
 *
 * Ranges:-
 * 			PLLQ = {2..15}
 * 			PLLP = {
 * 					00: PLLP = 2
 * 					01: PLLP = 4
 * 					10: PLLP = 6
 * 					11: PLLP = 8
 * 				}
 * 			PLLN = {2..432}
 * 			PLLM = {2..63}
 *
 * 	NOTES:-
 * 			A. Set PLLM to to 1/16, set PLLN to 336, and PLLP to 1/4.
 *				fPLL_IN = 16MHz * (1/16) = 1MHz
 *				fVCO_OUT = fPLL_IN * (336) = 336MHz
 *				fPLL_OUT = fVCO_OUT * (1/4) = 84MHz
 *
 *			B. Set PLLM to to 1/16, set PLLN to 168, and PLLP to 1/2.
 *				fPLL_IN = 16MHz * (1/16) = 1MHz
 *				fVCO_OUT = fPLL_IN * (168) = 168MHz
 *				fPLL_OUT = fVCO_OUT * (1/2) = 84MHz
 *
 *			C. Set PLLM to to 1/8, set PLLN to 168, and PLLP to 1/4.
 *				fPLL_IN = 16MHz *(1/8) = 2MHz
 *				fVCO_OUT = fPLL_IN * (168) = 336MHz
 *				fPLL_OUT = fVCO_OUT * (1/4) = 84MHz
 *
 *			D. Set PLLM to to 1/8, set PLLN to 84, and PLLP to 1/2.
 *				fPLL_IN = 16MHz *(1/8) = 2MHz
 *				fVCO_OUT = fPLL_IN * (84) = 168MHz
 *				fPLL_OUT = fVCO_OUT * (1/2) = 84MHz
 */
#define PLLQ_VALUE 8
#define PLLP_VALUE 0b00
#define PLLN_VALUE 250
#define PLLM_VALUE 30



#endif
