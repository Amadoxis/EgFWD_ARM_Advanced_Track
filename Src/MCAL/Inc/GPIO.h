#ifndef GPIO_H_
#define GPIO_H_

/***************************************************************************************
 *                                       Includes                                      *
****************************************************************************************/
#include "GPIO_Types.h"
#include "GPIO_Cfg.h"
#include "Mcu_Hw.h"
#include "SysCtrl_RCC.h"
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
void GPIO_Port_Init (User_Config_GPIO_Type* GPIOCfg);
void GPIO_WritePort(GPIO_Ports_Type GPIO_Port, uint8 Value );
void GPIO_WritePin(GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin, GPIO_RW_Type Value );
void GPIO_TogglePin(GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin);
uint8 GPIO_ReadPort(GPIO_Ports_Type GPIO_Port);
uint8 GPIO_ReadPin(GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin);

#endif /*GPIO_H_*/
