/*
 * AUTHOR     : Mohamed Sherif
 * MICRO      : STM32F401CCU6
 * LAYER      : MCAL
 * DRIVER     : EXTI_Driver
 * File       : Private File
 * Version    : 1.0
 * Created on : Aug 14, 2023
 */

#ifndef EXTI_EXTI_PRIVATE_H_
#define EXTI_EXTI_PRIVATE_H_

/**
 * @def EXTI_Base_Adderss
 * @brief Base address of the EXTI peripheral.
 */
#define EXTI_BASE_ADDRESS 0x40013C00

#define EXTI_CONFIG_MASK1 0xFFFFFFF0 UL
#define EXTI_CONFIG_MASK2 0xFFFFFF0F UL
#define EXTI_CONFIG_MASK3 0xFFFFF0FF UL
#define EXTI_CONFIG_MASK4 0xFFFF0FFF UL

typedef struct{
	volatile u32 IMR	;
	volatile u32 EMR	;
	volatile u32 RTSR	;
	volatile u32 FTSR	;
	volatile u32 SWIER	;
	volatile u32 PR		;
}EXTI_t;

/**
 * @def EXTI
 * @brief Pointer to the EXTI peripheral base address.
 */
#define EXTI ((volatile EXTI_t*)EXTI_BASE_ADDRESS)




/**
 * @def SYSCFG_EXTICR1_BaseAdress
 * @brief Base address of the SYSCFG_EXTICR register.
 */
#define SYSCFG_BASE_ADDRESS 0x40013800

/*
#define SYSCFG_EXTICR1 (*(volatile u32*)SYSCFG_BASE_ADDRESS + 0x08)
#define SYSCFG_EXTICR2 (*(volatile u32*)SYSCFG_BASE_ADDRESS + 0x0C)
#define SYSCFG_EXTICR3 (*(volatile u32*)SYSCFG_BASE_ADDRESS + 0x10)
#define SYSCFG_EXTICR4 (*(volatile u32*)SYSCFG_BASE_ADDRESS + 0x14)
*/

#define SYSCFG_EXTICR1 0
#define SYSCFG_EXTICR2 1
#define SYSCFG_EXTICR3 2
#define SYSCFG_EXTICR4 3

typedef struct{
	volatile u32 EXTICR1;
	volatile u32 EXTICR2;
	volatile u32 EXTICR3;
	volatile u32 EXTICR4;
}SYSCFG_t;

#define SYSCFG ((volatile SYSCFG_t*)SYSCFG_BASE_ADDRESS)

#endif /* EXTI_EXTI_PRIVATE_H_ */
