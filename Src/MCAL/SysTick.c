/***************************************************************************************
 *                                  File Description                                   *
 *  Name: SysTick.c                                                                    *
 *  Brief: Nested Vector Interrupt Controller Driver                                   *
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
 *                                Local Function Prototypes                            *
 ***************************************************************************************/



/***************************************************************************************
 *                                       Local Functions                               *
 ***************************************************************************************/
/***************************************************************************************
 *                                    API Implementations                              *
 ***************************************************************************************/
void SysTick_Init_Delay_ms(uint32 Delay){
    uint32 u32_Result;
    u32_Result= ((Delay*SYS_CLC)/1000);
    STCURRENT=0x000000;
    STRELOAD=u32_Result;
}
void SysTick_Start_Timer(){
    STCTRL->B.ENABLE=1;
}
void SysTick_Stop_Timer(){
    STCTRL->B.ENABLE=0;
}
void SysTick_Interrupt_Enable(){
    STCTRL->B.INTEN=1;
}
void SysTick_Interrupt_Disable(){
    STCTRL->B.INTEN=0;
}
uint32 SysTick_Read_Current_Count(){
    uint32 u32_Current_Count = STCURRENT;
    return STCURRENT;
}

/***************************************************************************************
 *                               End of File: SysTick.c                                *
 ***************************************************************************************/
