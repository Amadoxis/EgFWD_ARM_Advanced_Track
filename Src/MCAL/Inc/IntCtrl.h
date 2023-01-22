/***************************************************************************************
 *                                  File Description                                   *
 *  Name: IntCtrl.h                                                                    *
 *  Brief: Nested Vector Interrupt Controller Driver                                   *
 *  Author: Ahmed M. Rizk                                                              *
 *  Date: 14th of January 2023                                                         *
 *                                                                                     *
 * Details: ~Declares user APIS for NVIC                                               *
 *                                                                                     *
 ****************************************************************************************/
#ifndef INTCTRL_H_
#define INTCTRL_H_

/***************************************************************************************
 *                                       Includes                                      *
****************************************************************************************/
#include "IntCtrl_Types.h"
#include "IntCtrl_Cfg.h"
#include "Mcu_Hw.h"
/***************************************************************************************
 *                              Global Constant Macros                                 *
****************************************************************************************/

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
 * Syntax           : void IntCtrl_Init(User_Config_IRQ_Type *S_UserConfig)
 * Description      : initialize NVIC\SCB 
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant 
 *Parameters (in)   :User_Config_IRQ_Type *S_UserConfig)
 *Return Values     :None
 *******************************************************************************/
void IntCtrl_Init(User_Config_IRQ_Type* S_UserConfig);
/*******************************************************************************
 * Syntax           : IntCtrl_Set_CallBack(void(*PF_CallBackAddress)(void), IntVectors_Type IRQ_Vector)
 * Description      : Set IRQ call back PFs
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant 
 *Parameters (in)   :*PF_CallBackAddress)(void)  / IntVectors_Type IRQ_Vector
 *Return Values     :None
 *******************************************************************************/
void IntCtrl_Set_CallBack(void(*PF_CallBackAddress)(void), IntVectors_Type IRQ_Vector);

#endif /*INTCTRL_H_*/
/***************************************************************************************
 *                               End of File: IntCtrl.c                                *
 ****************************************************************************************/
