/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR : ABDULLAH HEIKAL 
MICRO : STM32F401CCU6
DRIVER : OS Module
Version :1.0
********************************************************************************************************
********************************************************************************************************
 */
 
 
 u8 RTOS_u8CreateTask(void(*handler)(void),u32 copy_u32periodicity,u8 Copy_u8priority,u32 fdelay);

 void scheduler (void);

 u8 RTos_DeleteTask(u8 Priority);

 u8 Rtos_Suspend (u8 Priority);

 u8 Rtos_ResumeTask (u8 priority);

 void Start_OS(void);
 
 
