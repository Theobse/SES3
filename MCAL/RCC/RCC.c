/*
 * AUTHOR     : Mohamed Sherif
 * MICRO      : STM32F401CCU6
 * LAYER      : MCAL
 * DRIVER     : RCC_Driver
 * File       : Program File
 * Version    : 1.0
 * Created on : Aug 7, 2023
 */

/********************************************* Includes *********************************************************/

#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_TYPES.h"

#include "RCC_config.h"
#include "RCC_interface.h"
#include "RCC_private.h"

/********************************************** APIs ********************************************************/

void RCC_vInit(void) {

	RCC->CR = 0;

	/****************************** HSI ****************************************/
#if RCC_SYSCLK == RCC_HSI

	SET_BIT(RCC->CR, HSION); // Enable HSI CLK
	while(GET_BIT(RCC->CR, HSIRDY) == 0); // Wait until HSI be ready
	/*
	 * Adjust System clock switch (SW)
	 * 	00: HSI oscillator selected as system clock
	 */
	CLEAR_BIT(RCC->CFGR, SW0);
	CLEAR_BIT(RCC->CFGR, SW1);

	/****************************** HSE ****************************************/
#elif RCC_SYSCLK == RCC_HSE

	/****************************** HSE_BYPASS *********************************/
	#if RCC_HSE_MODE == RCC_HSE_BYPASS

	/*
	 *  HSE clock bypass
	 *  	1: HSE oscillator bypassed with an external clock
	 */
	SET_BIT(RCC->CR, HSEBYP);

	/****************************** HSE_CRYSTAL ********************************/
	#elif RCC_HSE_MODE == RCC_HSE_CYRSTAL

	/*
	 *  HSE clock bypass
	 *  	0: HSE oscillator not bypassed
	 */
	CLEAR_BIT(RCC->RCC_CR, HSEBYP);

	#endif

	SET_BIT(RCC->CR, HSEON); // Enable HSE CLK
	while(GET_BIT(RCC->CR, HSERDY) == 0); // Wait until HSE be ready
	/*
	 * Adjust System clock switch (SW)
	 * 	01: HSE oscillator selected as system clock
	 */
	SET_BIT(RCC->CFGR, SW0);
	CLEAR_BIT(RCC->CFGR, SW1);

	/****************************** PLL ****************************************/
#elif RCC_SYSCLK == RCC_PLL

	/****************************** PLL_HSE ************************************/
	#if PLL_SRC == PLL_HSE

		#if RCC_HSE_MODE == RCC_HSE_BYPASS

		/*
		 *  HSE clock bypass
		 *  	1: HSE oscillator bypassed with an external clock
		 */
		SET_BIT(RCC->CR, HSEBYP);

		/****************************** HSE_CRYSTAL ********************************/
		#elif RCC_HSE_MODE == RCC_HSE_CYRSTAL

		/*
		 *  HSE clock bypass
		 *  	0: HSE oscillator not bypassed
		 */
		CLEAR_BIT(RCC->RCC_CR, HSEBYP);

		#endif

	SET_BIT(RCC->CR, HSEON); // Enable HSE CLK
	while(GET_BIT(RCC->CR, HSERDY) == 0); // Wait until HSE be ready
	/*
	 * Main PLL(PLL) and audio PLL (PLLI2S) entry clock source
	 * 	1: HSE oscillator clock selected as PLL and PLLI2S clock entry
	 */
	SET_BIT(RCC->CFGR, PLLSRC);

	/****************************** PLL_HSI ************************************/
	#elif PLL_SRC == PLL_HSI

	SET_BIT(RCC->CR, HSION); // Enable HSI CLK
	while(GET_BIT(RCC->CR, HSIRDY) == 0); // Wait until HSI be ready
	/*
	 * Main PLL(PLL) and audio PLL (PLLI2S) entry clock source
	 * 	0: HSI clock selected as PLL and PLLI2S clock entry
	 */
	CLEAR_BIT(RCC->CFGR, PLLSRC);

	#endif

	/****************************** PLL_CONFIGs *********************************/
	//MODIFY_REG(RCC->PLLCFGR, ( (PLLN_VALUE << PLLN0) | (PLLM_VALUE << PLLM0) | (PLLP_VALUE << PLLP0) | (PLLQ_VALUE << PLLQ0) ), ~( (PLLN_VALUE << PLLN0) | (PLLM_VALUE << PLLM0) | (PLLP_VALUE << PLLP0) | (PLLQ_VALUE << PLLQ0) ));
	RCC->PLLCFGR &= PLLCFGR_RESET_VALUE;
	RCC->PLLCFGR |= (
			(PLLN_VALUE << PLLN0) |
			(PLLM_VALUE << PLLM0) |
			(PLLP_VALUE << PLLP0) |
			(PLLQ_VALUE << PLLQ0)
			);

	/****************************** EN_PLL ***************************************/
	SET_BIT(RCC->CR, PLLON); // Enable PLL CLK
	while(GET_BIT(RCC->CR, PLLRDY) == 0); // Wait until PLL be ready
	/*
	 * Adjust System clock switch (SW)
	 * 	10: PLL selected as system clock
	 */
	CLEAR_BIT(RCC->CFGR, SW0);
	SET_BIT(RCC->CFGR, SW1);

#else

	#error "Wrong Clock Source mode"

#endif

}

/******************************************************************************************************/

void RCC_vEnPeriphral(u8 Copy_u8BusName, u8 Copy_u8PeripheralNum) {

	switch(Copy_u8BusName) {
		case AHB1_BUS:
			SET_BIT(RCC->AHB1ENR, Copy_u8PeripheralNum);
			break;
		case AHB2_BUS:
			SET_BIT(RCC->AHB2ENR, Copy_u8PeripheralNum);
			break;
		case APB1_BUS:
			SET_BIT(RCC->APB1ENR, Copy_u8PeripheralNum);
			break;
		case APB2_BUS:
			SET_BIT(RCC->APB2ENR, Copy_u8PeripheralNum);
			break;
		default:
			break;
	}

}

/******************************************************************************************************/

void RCC_vDisablePeriphral(u8 Copy_u8BusName, u8 Copy_u8PeripheralNum) {

	switch(Copy_u8BusName) {
		case AHB1_BUS:
			CLEAR_BIT(RCC->AHB1ENR, Copy_u8PeripheralNum);
			break;
		case AHB2_BUS:
			CLEAR_BIT(RCC->AHB2ENR, Copy_u8PeripheralNum);
			break;
		case APB1_BUS:
			CLEAR_BIT(RCC->APB1ENR, Copy_u8PeripheralNum);
			break;
		case APB2_BUS:
			CLEAR_BIT(RCC->APB2ENR, Copy_u8PeripheralNum);
			break;
		default:
			break;
	}

}

/******************************************************************************************************/
