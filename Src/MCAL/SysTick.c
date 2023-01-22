/***************************************************************************************
 *                                  File Description                                   *
 *  Name: SysTick.c                                                                    *
 *  Brief: System Tick Timer Driver                                                    *
 *  Author: Ahmed M. Rizk                                                              *
 *  Date: 18th of January 2023                                                         *
 *                                                                                     *
 * Details: ~Enables SysTick Timer                                                     *
 *          ~Provides User-Friendly APIS                                               *
 *          ~Enables SysTick Interrupt                                                 *
 ***************************************************************************************/

/***************************************************************************************
 *                                       Includes                                      *
 ***************************************************************************************/
#include "SysTick.h"

/***************************************************************************************
 *                             Local Macros Constant\Function                          *
 ***************************************************************************************/

/***************************************************************************************
 *                                       Local Data                                    *
 ***************************************************************************************/

/***************************************************************************************
 *                                       Global Data                                   *
 ***************************************************************************************/

/***************************************************************************************
 *                                Local Function Prototypes                            *
 ***************************************************************************************/

/***************************************************************************************
 *                                       Local Functions                               *
 ***************************************************************************************/
/***************************************************************************************
 *                                    API Implementations                              *
 ***************************************************************************************/
/*******************************************************************************
 * Syntax           : SysTick_Init(uint32 Reload_Value)
 * Description      : Load SysTick timer with a value and set clock source.
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant
 *Parameters (in)   :uint32 Reload_Value
 *Return Values     :None
 *******************************************************************************/
void SysTick_Init(uint32 Reload_Value)
{
    STCURRENT = 0x000000;
    STRELOAD = Reload_Value;
}
/*******************************************************************************
 * Syntax           : void SysTick_Start_Timer(void)
 * Description      : Start the SysTick timer counting operation and set clock source (Unconfigurable for now)
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant
 *Parameters (in)   :None
 *Return Values     :None
 *******************************************************************************/
void SysTick_Start_Timer()
{
    STCTRL->B.CLK_SRC = 1; /*Select System Clock*/
    STCTRL->B.ENABLE = 1;
}
/*******************************************************************************
 * Syntax           : void SysTick_Stop_Timer(void)
 * Description      : Stop the SysTick timer counting operation
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant
 *Parameters (in)   :None
 *Return Values     :None
 *******************************************************************************/
void SysTick_Stop_Timer()
{
    STCTRL->B.ENABLE = 0;
}
/*******************************************************************************
 * Syntax           : void SysTick_Interrupt_Enable(void)
 * Description      : Enable SysTick Expiry Interrupts
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant
 *Parameters (in)   :None
 *Return Values     :None
 *******************************************************************************/
void SysTick_Interrupt_Enable()
{
    STCTRL->B.INTEN = 1;
}
/*******************************************************************************
 * Syntax           : void SysTick_Interrupt_Disable(void)
 * Description      : Disable SysTick Expiry Interrupts
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant
 *Parameters (in)   :None
 *Return Values     :None
 *******************************************************************************/
void SysTick_Interrupt_Disable()
{
    STCTRL->B.INTEN = 0;
}
/*******************************************************************************
 * Syntax           : void SysTick_Interrupt_Disable(void)
 * Description      : Get current tick count
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant
 *Parameters (in)   :None
 *Return Values     :uint32 Tick_Count
 *******************************************************************************/
uint32 SysTick_Read_Current_Count()
{
    uint32 u32_Current_Count = STCURRENT;
    return u32_Current_Count;
}

/***************************************************************************************
 *                               End of File: SysTick.c                                *
 ***************************************************************************************/
