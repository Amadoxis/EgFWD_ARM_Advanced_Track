/***************************************************************************************
 *                                  File Description                                   *
 *  Name: GPIO.h                                                                       *
 *  Brief: General Purpose Input/Output Driver                                         *
 *  Author: Ahmed M. Rizk                                                              *
 *  Date: 17th of January 2023                                                         *
 *                                                                                     *
 * Details: ~Declares user APIS for GPIO                                               *
 *                                                                                     *
 ****************************************************************************************/
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
/*******************************************************************************
 * Syntax           : void GPIO_Port_Init (User_Config_GPIO_Type* GPIOCfg)
 * Description      : initialize GPIO Ports according to config struct 
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant 
 *Parameters (in)   :User_Config_GPIO_Type* GPIOCfg
 *Return Values     :None
 *******************************************************************************/
void GPIO_Port_Init (User_Config_GPIO_Type* GPIOCfg);
/*******************************************************************************
 * Syntax           : void GPIO_WritePort(GPIO_Ports_Type GPIO_Port, uint8 Value )
 * Description      : Sets output value for a whole port
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant 
 *Parameters (in)   :GPIO_Ports_Type GPIO_Port, uint8 Value
 *Return Values     :None
 *******************************************************************************/
void GPIO_WritePort(GPIO_Ports_Type GPIO_Port, uint8 Value );
/*******************************************************************************
 * Syntax           : void GPIO_WritePin(GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin, GPIO_RW_Type Value )
 * Description      : Sets output value for a single pin in a selected port
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant 
 *Parameters (in)   :GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin, GPIO_RW_Type Value
 *Return Values     :None
 *******************************************************************************/
void GPIO_WritePin(GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin, GPIO_RW_Type Value );
/*******************************************************************************
 * Syntax           : void GPIO_TogglePin(GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin)
 * Description      : Toggles output value for a single pin in a selected port
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant 
 *Parameters (in)   :GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin
 *Return Values     :None
 *******************************************************************************/
void GPIO_TogglePin(GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin);
/*******************************************************************************
 * Syntax           : uint8 GPIO_ReadPort(GPIO_Ports_Type GPIO_Port)
 * Description      : Reads the input value of a while port
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant 
 *Parameters (in)   :GPIO_Ports_Type GPIO_Port
 *Return Values     :uint8 Value
 *******************************************************************************/
uint8 GPIO_ReadPort(GPIO_Ports_Type GPIO_Port);
/*******************************************************************************
 * Syntax           : uint8 GPIO_ReadPin(GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin)
 * Description      : Reads the input value for a single pin in a selected port
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant 
 *Parameters (in)   :GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin
 *Return Values     :uint8 Value
 *******************************************************************************/
uint8 GPIO_ReadPin(GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin);

#endif /*GPIO_H_*/
/***************************************************************************************
 *                               End of File: GPIO.h                                   *
 ****************************************************************************************/
