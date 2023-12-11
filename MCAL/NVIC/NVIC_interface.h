/*
 * AUTHOR     : Mohamed Sherif
 * MICRO      : STM32F401CCU6
 * LAYER      : MCAL
 * DRIVER     : NVIC_Driver
 * File       : Interface File
 * Version    : 1.0
 * Created on : Aug 13, 2023
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

typedef enum {
	 NVIC_G16_SG0	= 3	,  /* 16 Group,  0 Sub-Group  */
	 NVIC_G8_SG2		,  /*  8 Group,  2 Sub-Group  */
	 NVIC_G4_SG4		,  /*  4 Group,  4 Sub-Group  */
	 NVIC_G2_SG8		,  /*  2 Group,  8 Sub-Group  */
	 NVIC_G0_SG16          /*  0 Group, 16 Sub-Group  */
}Group_mode;

/*
 * NAME: NVIC_vEnableInterrupt
 * PARAM: Copy_u8IntNum
 * RETURN VALUE: void
 * DESCRIPTION: Enable interrupt for specific number of bit
 */
void NVIC_vEnableInterrupt (u8 Copy_u8IntNum);

/******************************************************************************************************/

/*
 * NAME: NVIC_vDisableInterrupt
 * PARAM: Copy_u8IntNum
 * RETURN VALUE: void
 * DESCRIPTION: Disable interrupt for specific number of bit
 */
void NVIC_vDisableInterrupt (u8 Copy_u8IntNum);

/******************************************************************************************************/

/*
 * NAME: NVIC_vSetPendingFlag
 * PARAM: Copy_u8IntNum
 * RETURN VALUE: void
 * DESCRIPTION: Set Pending Flag for specific number of bit
 */
void NVIC_vSetPendingFlag (u8 Copy_u8IntNum);

/******************************************************************************************************/

/*
 * NAME: NVIC_vClearPendingFlag
 * PARAM: Copy_u8IntNum
 * RETURN VALUE: void
 * DESCRIPTION: Clear Pending Flag for specific number of bit
 */
void NVIC_vClearPendingFlag (u8 Copy_u8IntNum);

/******************************************************************************************************/

/*
 * NAME: NVIC_vReadInterruptStatus
 * PARAM: Copy_u8IntNum
 * RETURN VALUE: u8
 * DESCRIPTION: Read the status of the corresponding interrupt {
 * 														0: Interrupt not active
 * 														1: Interrupt active
 * 													}
 */
u8 NVIC_vReadInterruptStatus (u8 Copy_u8IntNum);

/******************************************************************************************************/

/*
 * NAME: NVIC_vSetGroupMode
 * PARAM: COPY_GROUPMODE
 * RETURN VALUE: void
 * DESCRIPTION: Set Group Mode
 * 								Priority grouping {														Choices
 * 												0b0xx : 16 Group,  0 Sub-Group    -->  Group_mode->NVIC_G16_SG0
 * 												0b100 :  8 Group,  2 Sub-Group    -->  Group_mode->NVIC_G8_SG2
 * 												0b101 :  4 Group,  4 Sub-Group    -->  Group_mode->NVIC_G4_SG4
 * 												0b110 :  2 Group,  8 Sub-Group    -->  Group_mode->NVIC_G2_SG8
 * 												0b111 :  0 Group, 16 Sub-Group    -->  Group_mode->NVIC_G0_SG16
 * 											}
 */
void NVIC_vSetGroupMode (Group_mode COPY_GROUPMODE);

/******************************************************************************************************/

/*
 * NAME: NVIC_vSetInterruptPriority
 * PARAM: Copy_u8IntNum, Copy_GroupNum, Copy_SubGroupNum
 * RETURN VALUE: void
 * DESCRIPTION: Set Priority to an interrupt (Place it in a Group and Sub-Group)
 * 											Groups & Sub-Groups Ranges {
 * 																16 	Group		, 	0 	Sub-Group
 * 																8 	Group		,	2 	Sub-Group
 * 																4 	Group		,	4 	Sub-Group
 * 																2 	Group		,	8 	Sub-Group
 * 																0 	Group		,	16	Sub-Group
 * 															}
 */
void NVIC_vSetInterruptPriority (u8 Copy_u8IntNum, u8 Copy_GroupNum, u8 Copy_SubGroupNum);

/******************************************************************************************************/

#endif /* NVIC_INTERFACE_H_ */
