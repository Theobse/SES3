/*
 * AUTHOR     : Mohamed Sherif
 * MICRO      : STM32F401CCU6
 * LAYER      : MCAL
 * DRIVER     : NVIC_Driver
 * File       : Private File
 * Version    : 1.0
 * Created on : Aug 13, 2023
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

typedef struct{
	volatile u32 ISER		[8]		;
	volatile u32 Reserved1	[24]	;
	volatile u32 ICER		[8]		;
	volatile u32 Reserved2	[24]	;
	volatile u32 ISPR		[8]		;
	volatile u32 Reserved3	[24]	;
	volatile u32 ICPR		[8]		;
	volatile u32 Reserved4	[24]	;
	volatile u32 IABR		[8]		;
	volatile u32 Reserved5	[56]	;
	volatile u8  IPR		[240]	;	// 60 * 4
	volatile u32 Reserved6	[580]	;
	volatile u32 STIR				;
}NVIC_t;

#define NVIC_BASE_ADDRESS				0xE000E100

#define NVIC							((volatile NVIC_t *)NVIC_BASE_ADDRESS)

#define AIRCR_BASE_ADDRESS				0xE000ED0C

#define AIRCR							(*(volatile u32 *)(AIRCR_BASE_ADDRESS))

#define REGISTER_BITS					32

#define VECTKEY							0x05FA0000

#endif /* NVIC_PRIVATE_H_ */
