/***************************************************************************************
 *                                  File Description                                   *
 *  Name: GPIO_Types.h                                                                 *
 *  Brief: General Purpose Input/Output Driver                                         *
 *  Author: Ahmed M. Rizk                                                              *
 *  Date: 17th of January 2023                                                         *
 *                                                                                     *
 * Details: ~Prebuild configs constant Macros                                          *
 *          ~Config Struct                                                             *
 *          ~Enum definitions                                                          *
 *                                                                                     *
 ****************************************************************************************/
#ifndef GPIO_TYPES_H_
#define GPIO_TYPES_H_

/***************************************************************************************
 *                                       Includes                                      *
****************************************************************************************/
#include "Platform_Types.h"
/***************************************************************************************
 *                              Global Constant Macros                                 *
****************************************************************************************/
#define GPIO_PORTS_NUMBER 6

#ifdef HIGH
#undef HIGH
#endif

#ifdef LOW
#undef LOW
#endif

#define ClR_MASK    0x00000000FF
#define GPIO_UNLOCK 0x4C4F434BUL

/***************************************************************************************
 *                                Global Function Macros                               *
****************************************************************************************/

/***************************************************************************************
 *                          Global Data Types and Structures                           *
****************************************************************************************/
/*************Interrupt Vectors Enum*************/
typedef enum{
GPIOA,
GPIOB,
GPIOC,
GPIOD,
GPIOE,
GPIOF
}GPIO_Ports_Type;

typedef enum{
PIN_0,
PIN_1,
PIN_2,
PIN_3,
PIN_4,
PIN_5,
PIN_6,
PIN_7
}GPIO_Pins_Type;

typedef enum{
Input_Floating,
Input_PullUp,
Input_PullDown,
OUTPUT_Push_Pull,
OUTPUT_OpenDrain
}GPIO_Pins_Modes_Type;

typedef enum{
C_2MA,
C_4MA,
C_8MA
}GPIO_Pins_Currents_Type;

typedef enum{
    APB,
    AHB
}GPIO_Bus_Type;

typedef enum{
    LOW,
    HIGH
}GPIO_RW_Type;

/*************GPIO Configs*************/
typedef struct{
    vuint8 Enabled[GPIO_PORTS_NUMBER];
    vuint8 PortPinsMode[GPIO_PORTS_NUMBER];
    vuint8 PortInitValue[GPIO_PORTS_NUMBER];
    vuint8 PortPinsCurrent[GPIO_PORTS_NUMBER];
}User_Config_GPIO_Type;

#endif /*GPIO_TYPES_H_ */
/***************************************************************************************
 *                               End of File: GPIO_Types.h                             *
 ****************************************************************************************/
