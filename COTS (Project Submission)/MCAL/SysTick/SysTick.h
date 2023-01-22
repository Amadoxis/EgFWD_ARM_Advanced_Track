/***************************************************************************************
 *                                  File Description                                   *
 *  Name: SysTick.h                                                                    *
 *  Brief: System Tick Timer Driver                                                    *
 *  Author: Ahmed M. Rizk                                                              *
 *  Date: 18th of January 2023                                                         *
 *                                                                                     *
 * Details: ~Declares user APIS for SysTick                                            *
 *                                                                                     *
 ****************************************************************************************/
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
/*******************************************************************************
 * Syntax           : SysTick_Init(uint32 Reload_Value)
 * Description      : Load SysTick timer with a value and set clock source.
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant 
 *Parameters (in)   :uint32 Reload_Value
 *Return Values     :None
 *******************************************************************************/
void SysTick_Init(uint32 Reload_Value);
/*******************************************************************************
 * Syntax           : void SysTick_Start_Timer(void)
 * Description      : Start the SysTick timer counting operation and set clock source (Unconfigurable for now)
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant 
 *Parameters (in)   :None
 *Return Values     :None
 *******************************************************************************/
void SysTick_Start_Timer(void);
/*******************************************************************************
 * Syntax           : void SysTick_Stop_Timer(void)
 * Description      : Stop the SysTick timer counting operation
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant 
 *Parameters (in)   :None
 *Return Values     :None
 *******************************************************************************/
void SysTick_Stop_Timer(void);
/*******************************************************************************
 * Syntax           : void SysTick_Interrupt_Enable(void)
 * Description      : Enable SysTick Expiry Interrupts
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant 
 *Parameters (in)   :None
 *Return Values     :None
 *******************************************************************************/
void SysTick_Interrupt_Enable(void);
/*******************************************************************************
 * Syntax           : void SysTick_Interrupt_Disable(void)
 * Description      : Disable SysTick Expiry Interrupts
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant 
 *Parameters (in)   :None
 *Return Values     :None
 *******************************************************************************/
void SysTick_Interrupt_Disable(void);
/*******************************************************************************
 * Syntax           : void SysTick_Interrupt_Disable(void)
 * Description      : Get current tick count
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant 
 *Parameters (in)   :None
 *Return Values     :uint32 Tick_Count
 *******************************************************************************/
uint32 SysTick_Read_Current_Count(void);


#endif /*SYSTICK_H_*/

/***************************************************************************************
 *                               End of File: SysTick.h                                *
 ***************************************************************************************/