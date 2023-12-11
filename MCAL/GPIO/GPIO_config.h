/*
 * AUTHOR     : Mohamed Sherif
 * MICRO      : STM32F401CCU6
 * LAYER      : MCAL
 * DRIVER     : GPIO_Driver
 * File       : Configuration File
 * Version    : 1.0
 * Created on : Aug 9, 2023
 */

#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

#define GPIOA_PORT	0
#define GPIOB_PORT	1
#define GPIOC_PORT	2

#define MODE_INPUT   	(0b00)
#define MODE_OUTPUT  	(0b01)
#define MODE_ALTF    	(0b10)
#define MODE_ANALOGE 	(0b11)

#define PUSH_PULL	0
#define OPEN_DRAIN	1

#define LOW_SPEED			(0b00)
#define MEDIUM_SPEED 		(0b01)
#define HIGH_SPEED			(0b10)
#define VERY_HIGH_SPEED		(0b11)

#define NO_PULL			(0b00)
#define PULL_UP			(0b01)
#define PULL_DOWN		(0b10)

#endif /* GPIO_CONFIG_H_ */
