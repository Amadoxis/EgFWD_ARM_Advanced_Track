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
void IntCtrl_Init(User_Config_IRQ_Type* S_UserConfig);

#endif /*INTCTRL_H_*/
