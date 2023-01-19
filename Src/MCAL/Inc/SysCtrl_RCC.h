#ifndef SysCtrl_RCC_H_
#define SysCtrl_RCC_H_

/***************************************************************************************
 *                                       Includes                                      *
****************************************************************************************/
#include "Platform_Types.h"
#include "BIT_MATH.h"
#include "Mcu_Hw.h"
/***************************************************************************************
 *                              Global Function Macros                                 *
****************************************************************************************/
/***************************Clock Enable Macros***************************/
/*@*@*@*@*@*@*GPIO*@*@*@*@*@*@*/
#define GPIO_EN(X)    SET_BIT(RCGCGPIO,X);
//#define GPIO_EN(X)    SET_BIT(RCGC2,X); /*Legacy Used In Simulation*/

/***************************Reset Macros***************************/
/*@*@*@*@*@*@*GPIO*@*@*@*@*@*@*/
#define GPIO_RESET(X) SET_BIT(SRGPIO,X);
//#define GPIO_RESET(X) SET_BIT(SRCR2,X); /*Legacy Used In Simulation*/


#endif /*SysCtrl_RCC_H_*/


