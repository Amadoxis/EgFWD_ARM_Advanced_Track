#ifndef INTCTRL_TYPES_H_
#define INTCTRL_TYPES_H_

/***************************************************************************************
 *                                       Includes                                      *
****************************************************************************************/
#include "Platform_Types.h"
/***************************************************************************************
 *                              Global Constant Macros                                 *
****************************************************************************************/
#define XXX 0x0U
#define XXY 0x5U
#define XYY 0x6U
#define YYY 0x7U

/***************************************************************************************
 *                                Global Function Macros                               *
****************************************************************************************/

/***************************************************************************************
 *                          Global Data Types and Structures                           *
****************************************************************************************/
/*************Interrupt Vectors Enum*************/
typedef enum{
Reset_IRQ=1,
NMI_IRQ,
Hard_Fault_IRQ,
Memory_Management_IRQ,
Bus_Fault_IRQ,
Usage_Fault_IRQ,
SVCall_IRQ=11,
Debug_Monitor_IRQ,
PendSV_IRQ=14,
SysTick_IRQ,
GPIOA_IRQ,
GPIOB_IRQ,
GPIOC_IRQ,
GPIOD_IRQ,
GPIOE_IRQ,
UART0_IRQ,
UART1_IRQ
}IntVectors_Type;

/*************Interrupt Configs*************/
typedef struct{
        uint8 Enabled           [155];
        uint8 Group_Priority    [155];
        uint8 Sub_Group_Priority[155];
}User_Config_IRQ_Type;

#endif /*INTCTRL_TYPES_H_ */
