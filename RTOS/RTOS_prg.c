/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR : ABDULLAH HEIKAL 
MICRO : STM32F401CCU6
DRIVER : OS Module
Version :1.0
********************************************************************************************************
********************************************************************************************************
 */
 
 #include "../LIB/STD_TYPES.h"
 #include "../MCAL/STK/STK_interface.h"
 #include "RTOS_INTERFACE.h"
 #include "RTOS_CFG.h"
 #include "RTOS_PRV.h"
 



Task SystemTasks[MAX_NUMBER_TASKS] = {0}; // 20 task      50 
u8  Timing [MAX_NUMBER_TASKS];
Task Empty = {0};



 u8 RTOS_u8CreateTask(void(*handler)(void),u32 copy_u32periodicity,u8 Copy_u8priority,u32 fdelay)
 {
	 u8 Local_ErrorState = 0 ;
	 if (Copy_u8priority < MAX_NUMBER_TASKS )
	 {
		 // verify priority within limit 
		 if (SystemTasks[Copy_u8priority].TaskHandler == 0 )
		 {
			 SystemTasks[Copy_u8priority].TaskHandler = handler            ;
			 SystemTasks[Copy_u8priority].periodicity = copy_u32periodicity ;
			 Timing     [Copy_u8priority]             = fdelay ;
			 SystemTasks[Copy_u8priority].Tstate      = Running ;
			 
		 }
		 else
		 {
			 Local_ErrorState = 2 ; 
			 
		 }
		 
		 
	 }
	 else 
	 {
		 Local_ErrorState = 1 ;
		 
	 }
	 
	 return Local_ErrorState;

	 
 }


void scheduler (void)  // callback function systk
{
	u8 Local_Counter = 0 ;
	for ( Local_Counter = 0 ; Local_Counter < MAX_NUMBER_TASKS ;  Local_Counter ++)
	{
		/*IS there is a task ? */
		if (SystemTasks[Local_Counter].TaskHandler != 0 )
		{
			if (SystemTasks[Local_Counter].Tstate == Running)  // 1 -- 0
			{
			 if (Timing[Local_Counter]==0)
			   {
				SystemTasks[Local_Counter].TaskHandler();
				Timing[Local_Counter] = SystemTasks[Local_Counter].periodicity ;    //10 => 9 => 8 - 7 -6- 5 -4 3 -2-1
				
			   }
			   else 
		 	   {
				Timing[Local_Counter] -- ; 
			   }
				
			 }
		
			
		}

		
	}
	
}


u8 RTos_DeleteTask(u8 Priority)   // RTos_DeleteTask (0)    u8 x = RTos_DeleteTask (0)
{
	u8 Local_ErrorState = 0 ;
	if (SystemTasks[Priority].TaskHandler != 0 )
	{
		SystemTasks[Priority] = Empty;
	}
	else 
	{
		Local_ErrorState = 1 ;  // there_is no task  
		
	}
	return Local_ErrorState ; 
	
}



u8 Rtos_Suspend (u8 Priority)
{
		u8 Local_ErrorState = 0 ;
	if (SystemTasks[Priority].TaskHandler != 0 )
	{
		SystemTasks[Priority].Tstate = Suspend;
	}
	else 
	{
		Local_ErrorState = 1 ; 
		
	}
	return Local_ErrorState ; 
	
}



u8 Rtos_ResumeTask (u8 priority)
{
	u8 Local_ErrorState = 0 ;
	if (SystemTasks[priority].TaskHandler != 0 )
	{
		SystemTasks[priority].Tstate = Running ;
	}
	else 
	{
		Local_ErrorState = 1 ; 
		
	}
	return Local_ErrorState ; 
	
}

void Start_OS(void)
{
	STK_vSetIntervalPeriodic(TICK_TIME, scheduler);
}
