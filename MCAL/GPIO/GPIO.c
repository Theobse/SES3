/*
 * AUTHOR     : Mohamed Sherif
 * MICRO      : STM32F401CCU6
 * LAYER      : MCAL
 * DRIVER     : GPIO_Driver
 * File       : Program File
 * Version    : 1.0
 * Created on : Aug 9, 2023
 */

/********************************************* Includes *********************************************************/

#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_TYPES.h"

#include "GPIO_config.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"

/********************************************** APIs ********************************************************/

void GPIO_vSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinMode){
	switch(Copy_u8Port){
		case GPIOA_PORT: GPIOA->MODER &= ~(0b11 << (2*Copy_u8Pin)); GPIOA->MODER |= (u32) (Copy_u8PinMode << (2*Copy_u8Pin)); 	break;
		case GPIOB_PORT: GPIOB->MODER &= ~(0b11 << (2*Copy_u8Pin)); GPIOB->MODER |= (u32) (Copy_u8PinMode << (2*Copy_u8Pin)); 	break;
		case GPIOC_PORT: GPIOC->MODER &= ~(0b11 << (2*Copy_u8Pin)); GPIOC->MODER |= (u32) (Copy_u8PinMode << (2*Copy_u8Pin)); 	break;
		default: /* Do Nothing */ 																								break;
	}
}

/******************************************************************************************************/

u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin){
	u8 u8PinVal = 0;
	switch(Copy_u8Port){
		case GPIOA_PORT: u8PinVal = GET_BIT(GPIOA->IDR, Copy_u8Pin); 	break;
		case GPIOB_PORT: u8PinVal = GET_BIT(GPIOB->IDR, Copy_u8Pin); 	break;
		case GPIOC_PORT: u8PinVal = GET_BIT(GPIOC->IDR, Copy_u8Pin); 	break;
		default: /* Do Nothing */										break;
	}
	return u8PinVal;
}

/******************************************************************************************************/

void GPIO_vSetPinOutValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutVal){
	if(Copy_u8PinOutVal == BIT_SET){
		switch(Copy_u8Port){
			case GPIOA_PORT: SET_BIT(GPIOA->ODR, Copy_u8Pin); 	break;
			case GPIOB_PORT: SET_BIT(GPIOB->ODR, Copy_u8Pin); 	break;
			case GPIOC_PORT: SET_BIT(GPIOC->ODR, Copy_u8Pin); 	break;
			default: /* Do Nothing */							break;
		}
	}
	else if(Copy_u8PinOutVal == BIT_RESET){
		switch(Copy_u8Port){
			case GPIOA_PORT: CLEAR_BIT(GPIOA->ODR, Copy_u8Pin); 	break;
			case GPIOB_PORT: CLEAR_BIT(GPIOB->ODR, Copy_u8Pin); 	break;
			case GPIOC_PORT: CLEAR_BIT(GPIOC->ODR, Copy_u8Pin); 	break;
			default: /* Do Nothing */								break;
		}
	}
	else{
		/* Do Nothing */
	}
}

/******************************************************************************************************/

void GPIO_vSetPinOutType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutType){
	switch(Copy_u8Port){
		case GPIOA_PORT: GPIOA->OTYPER &= ~(1 << Copy_u8Pin); GPIOA->OTYPER |= (u32) (Copy_u8PinOutType << Copy_u8Pin); 	break;
		case GPIOB_PORT: GPIOB->OTYPER &= ~(1 << Copy_u8Pin); GPIOB->OTYPER |= (u32) (Copy_u8PinOutType << Copy_u8Pin); 	break;
		case GPIOC_PORT: GPIOC->OTYPER &= ~(1 << Copy_u8Pin); GPIOC->OTYPER |= (u32) (Copy_u8PinOutType << Copy_u8Pin); 	break;
		default: /* Do Nothing */ 																							break;
	}
}

/******************************************************************************************************/

void GPIO_vSetPinOutSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutSpeed){
	switch(Copy_u8Port){
		case GPIOA_PORT: GPIOA->OSPEEDR &= ~(0b11 << (2*Copy_u8Pin)); GPIOA->OSPEEDR |= (u32) (Copy_u8PinOutSpeed << (2*Copy_u8Pin)); 	break;
		case GPIOB_PORT: GPIOB->OSPEEDR &= ~(0b11 << (2*Copy_u8Pin)); GPIOB->OSPEEDR |= (u32) (Copy_u8PinOutSpeed << (2*Copy_u8Pin)); 	break;
		case GPIOC_PORT: GPIOC->OSPEEDR &= ~(0b11 << (2*Copy_u8Pin)); GPIOC->OSPEEDR |= (u32) (Copy_u8PinOutSpeed << (2*Copy_u8Pin)); 	break;
		default: /* Do Nothing */ 																										break;
	}
}

/******************************************************************************************************/

void GPIO_vSetPullType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PullType){
	switch(Copy_u8Port){
		case GPIOA_PORT: GPIOA->PUPDR &= ~(0b11 << (2*Copy_u8Pin)); GPIOA->PUPDR |= (u32) (Copy_u8PullType << (2*Copy_u8Pin)); 	break;
		case GPIOB_PORT: GPIOB->PUPDR &= ~(0b11 << (2*Copy_u8Pin)); GPIOB->PUPDR |= (u32) (Copy_u8PullType << (2*Copy_u8Pin)); 	break;
		case GPIOC_PORT: GPIOC->PUPDR &= ~(0b11 << (2*Copy_u8Pin)); GPIOC->PUPDR |= (u32) (Copy_u8PullType << (2*Copy_u8Pin)); 	break;
		default: /* Do Nothing */ 																								break;
	}
}

/******************************************************************************************************/

void GPIO_vSetPinLock(u8 Copy_u8Port, u32 Copy_u32RegisterValue){
	GPIOA->LCKR = 0;
	switch(Copy_u8Port){
		case GPIOA_PORT:
			GPIOA->LCKR |= Copy_u32RegisterValue;
			while(GET_BIT(GPIOA->LCKR, LCKK) == 1);
			break;
		case GPIOB_PORT:
			GPIOB->LCKR |= Copy_u32RegisterValue;
			while(GET_BIT(GPIOB->LCKR, LCKK) == 1);
			break;
		case GPIOC_PORT:
			GPIOC->LCKR |= Copy_u32RegisterValue;
			while(GET_BIT(GPIOC->LCKR, LCKK) == 1);
			break;
		default:
			break;
	}
}

/******************************************************************************************************/

void GPIO_vSetPinAltFunction(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8AltFunction) {
	if (Copy_u8Pin <= 7) {
		switch (Copy_u8Port) {
		case GPIOA_PORT:
			GPIOA->AFRL &= ~(0 << 4 * Copy_u8Pin);
			GPIOA->AFRL |= (Copy_u8AltFunction << 4 * Copy_u8Pin);
			break;
		case GPIOB_PORT:
			GPIOB->AFRL &= ~(0 << 4 * Copy_u8Pin);
			GPIOB->AFRL |= (Copy_u8AltFunction << 4 * Copy_u8Pin);
			break;
		case GPIOC_PORT:
			GPIOC->AFRL &= ~(0 << 4 * Copy_u8Pin);
			GPIOC->AFRL |= (Copy_u8AltFunction << 4 * Copy_u8Pin);
			break;
		default:
			break;
		}
	}
	else {
		Copy_u8Pin %= 8; // Example: if pin = 8 --> 8 % 8 = 0 ; ... ; if pin = 15 --> 15 % 8 = 7
		switch (Copy_u8Port) {
		case GPIOA_PORT:
			GPIOA->AFRH &= ~(0 << 4 * Copy_u8Pin);
			GPIOA->AFRH |= (Copy_u8AltFunction << 4 * Copy_u8Pin);
			break;
		case GPIOB_PORT:
			GPIOB->AFRH &= ~(0 << 4 * Copy_u8Pin);
			GPIOB->AFRH |= (Copy_u8AltFunction << 4 * Copy_u8Pin);
			break;
		case GPIOC_PORT:
			GPIOC->AFRH &= ~(0 << 4 * Copy_u8Pin);
			GPIOC->AFRH |= (Copy_u8AltFunction << 4 * Copy_u8Pin);
			break;
		default:
			break;
		}
	}
}

/******************************************************************************************************/

void GPIO_vTogglePin(u8 Copy_u8Port, u8 Copy_u8Pin){
	switch(Copy_u8Port){
		case GPIOA_PORT: GPIOA->ODR ^= (1 << Copy_u8Pin); 	break;
		case GPIOB_PORT: GPIOB->ODR ^= (1 << Copy_u8Pin); 	break;
		case GPIOC_PORT: GPIOC->ODR ^= (1 << Copy_u8Pin); 	break;
		default: /* Do Nothing */							break;
	}
}

/******************************************************************************************************/
