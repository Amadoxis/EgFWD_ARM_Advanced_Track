/***************************************************************************************
 *                                  File Description                                   *
 *  Name: GPIO.c                                                                       *
 *  Brief: General Purpose Input/Output Driver                                         *
 *  Author: Ahmed M. Rizk                                                              *
 *  Date: 17th of January 2023                                                         *
 *                                                                                     *
 * Details: ~Enables GPIO Ports                                                        *
 *          ~Configures GPIO Pins                                                      *
 *          ~Congigures GPIO Interrupts  //TODO//                                      *
 ***************************************************************************************/

/***************************************************************************************
 *                                       Includes                                      *
 ***************************************************************************************/
#include "GPIO.h"

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
/*******************************************************************************
 * Syntax           : void GPIO_Port_Init (User_Config_GPIO_Type* GPIOCfg)
 * Description      : initialize GPIO Ports according to config struct
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant
 *Parameters (in)   :User_Config_GPIO_Type* GPIOCfg
 *Return Values     :None
 *******************************************************************************/
void GPIO_Port_Init(User_Config_GPIO_Type *GPIOCfg)
{
    // GPIO_Reg *GPIO_Register;
    uint8 u8_i = 0;
    for (u8_i = 0; u8_i < 6; u8_i++)
    {
        // GPIO_APB(u8_i) = ((GPIO_Reg*) GPIO_APB(u8_i));
        /*Enable clock and Digital Function of the initialized Port*/
        if (GPIOCfg->Enabled[u8_i])
        {
            GPIO_EN(u8_i)                           /*Enable Clock*/
            GPIO_APB(u8_i)->GPIOLOCK = GPIO_UNLOCK; /*Unlock GPIO Commit Register*/
            GPIO_APB(u8_i)->GPIOCR = 0xFF;          /*Allow writing to GPIODEN, GPIOPUR, and GPIOPDN Registers*/
            GPIO_APB(u8_i)->GPIODEN = 0xFF;         /*Enable Digital I/O*/
        }
        else
        {
            continue; /*Skip Port Init if not Enabled*/
        }
        /*Configure Pin Modes*/
        if (GPIOCfg->PortPinsMode[u8_i] > Input_PullDown && GPIOCfg->PortPinsMode[u8_i] <= OUTPUT_OpenDrain)
        {
            GPIO_APB(u8_i)->GPIODIR = 0xFF; /*Set port pins to output*/

            if (GPIOCfg->PortPinsMode[u8_i] == OUTPUT_OpenDrain)
            {
                GPIO_APB(u8_i)->GPIOODR = 0xFF; /*Enable Open Drain output if configured*/
            }

            GPIO_APB(u8_i)->GPIODATA = GPIOCfg->PortInitValue[u8_i]; /*Initialize configured level values for Pins*/

            switch (GPIOCfg->PortPinsCurrent[u8_i])
            {
            case C_2MA:
                GPIO_APB(u8_i)->GPIODR2R = 0xFF;
                break;
            case C_4MA:
                GPIO_APB(u8_i)->GPIODR4R = 0xFF;
                break;
            case C_8MA:
                GPIO_APB(u8_i)->GPIODR8R = 0xFF;
                break;
            default:
                GPIO_APB(u8_i)->GPIODR8R = 0xFF;
                break;
            }
        }
        else
        {
            GPIO_APB(u8_i)->GPIODIR = 0x00;
            switch (GPIOCfg->PortPinsMode[u8_i])
            {
            case Input_PullUp:
                GPIO_APB(u8_i)->GPIOPUR = 0xFF;
                break;
            case Input_PullDown:
                GPIO_APB(u8_i)->GPIOPDR = 0xFF;
                break;

            default:
                break;
            }
        }
    }
}
/*******************************************************************************
 * Syntax           : void GPIO_WritePort(GPIO_Ports_Type GPIO_Port, uint8 Value )
 * Description      : Sets output value for a whole port
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant
 *Parameters (in)   :GPIO_Ports_Type GPIO_Port, uint8 Value
 *Return Values     :None
 *******************************************************************************/
void GPIO_WritePort(GPIO_Ports_Type GPIO_Port, uint8 Value)
{
    GPIO_APB(GPIO_Port)->GPIODATA = ((uint32)Value) & 0xFF;
}
/*******************************************************************************
 * Syntax           : void GPIO_WritePin(GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin, GPIO_RW_Type Value )
 * Description      : Sets output value for a single pin in a selected port
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant
 *Parameters (in)   :GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin, GPIO_RW_Type Value
 *Return Values     :None
 *******************************************************************************/
void GPIO_WritePin(GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin, GPIO_RW_Type Value)
{
    if (Value == HIGH)
    {
        SET_BIT(GPIO_APB(GPIO_Port)->GPIODATA, GPIO_Pin);
    }
    else
    {
        CLR_BIT(GPIO_APB(GPIO_Port)->GPIODATA, GPIO_Pin);
    }
}
/*******************************************************************************
 * Syntax           : void GPIO_TogglePin(GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin)
 * Description      : Toggles output value for a single pin in a selected port
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant 
 *Parameters (in)   :GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin
 *Return Values     :None
 *******************************************************************************/
void GPIO_TogglePin(GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin)
{
    TGL_BIT(GPIO_APB(GPIO_Port)->GPIODATA, GPIO_Pin);
}
/*******************************************************************************
 * Syntax           : uint8 GPIO_ReadPort(GPIO_Ports_Type GPIO_Port)
 * Description      : Reads the input value of a while port
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant
 *Parameters (in)   :GPIO_Ports_Type GPIO_Port
 *Return Values     :uint8 Value
 *******************************************************************************/
uint8 GPIO_ReadPort(GPIO_Ports_Type GPIO_Port)
{
    uint8 Value = 0;

    Value = (uint8)(GPIO_APB(GPIO_Port)->GPIODATA);

    return Value;
}
/*******************************************************************************
 * Syntax           : uint8 GPIO_ReadPin(GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin)
 * Description      : Reads the input value for a single pin in a selected port
 *
 *Sync\Async        : Sync
 *Reentrancy        : Reentrant
 *Parameters (in)   :GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin
 *Return Values     :uint8 Value
 *******************************************************************************/
uint8 GPIO_ReadPin(GPIO_Ports_Type GPIO_Port, GPIO_Pins_Type GPIO_Pin)
{
    uint8 Value = 0;

    Value = GET_BIT(GPIO_APB(GPIO_Port)->GPIODATA, GPIO_Pin);

    return Value;
}
/***************************************************************************************
 *                               End of File: GPIO.c                                   *
 ***************************************************************************************/
