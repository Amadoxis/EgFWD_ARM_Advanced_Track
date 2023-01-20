#ifndef SYSTICK_H_
#define SYSTICK_H_

/***************************************************************************************
 *                                       Includes                                      *
****************************************************************************************/
#include "Mcu_Hw.h"
/***************************************************************************************
 *                              Global Constant Macros                                 *
****************************************************************************************/
#define MAX_TIMER_COUNT 0x00FFFFFF
#define MAX_TIMER_TIME_ms   (((float)MAX_TIMER_COUNT/SYS_CLC)*1000)
/***************************************************************************************
 *                          Global Data Types and Structures                           *
****************************************************************************************/

/***************************************************************************************
 *                                Global Data Prototypes                               *
****************************************************************************************/

/***************************************************************************************
 *                                     API Prototypes                                  *
****************************************************************************************/
void SysTick_Init(uint32 Reload_Value);
void SysTick_Start_Timer(void);
void SysTick_Stop_Timer(void);
void SysTick_Interrupt_Enable(void);
void SysTick_Interrupt_Disable(void);
uint32 SysTick_Read_Current_Count(void);


#endif /*SYSTICK_H_*/