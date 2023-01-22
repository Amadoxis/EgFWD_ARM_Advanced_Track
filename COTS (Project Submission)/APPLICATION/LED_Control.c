/***************************************************************************************
 *                                  File Description                                   *
 *  Name: LED_Control.c                                                                *
 *  Brief: System Tick Timer Driver                                                    *
 *  Author: Ahmed M. Rizk                                                              *
 *  Date: 14th of January 2023                                                         *
 *                                                                                     *
 * Details: ~LED Control Application                                                   *
 *          ~Delay Function                                                            *
 *          ~Initializes Hardware                                                 *
 ***************************************************************************************/
/***************************************************************************************
 *                                       Includes                                      *
 ***************************************************************************************/
#include "IntCtrl.h"
#include "GPIO.h"
#include "SysTick.h"
/***************************************************************************************
 *                                   User Input Macros                                 *
 ***************************************************************************************/
#define LED_ON_DELAY_ms 2000
#define LED_OFF_DELAY_ms 2000
/***************************************************************************************
 *                                       Local Data                                    *
 ***************************************************************************************/
vuint32 u32_SysTick_OverFlow_Counter = 0UL;
/***************************************************************************************
 *                                Local Function Prototypes                            *
 ***************************************************************************************/
void IntCtrl_Config(void);
void GPIO_Config(void);
void SysTick_Config(void);
void SysTick_Expired(void);
void Delay_ms(uint32);

/***************************************************************************************
 *                                       Main Function                                 *
 ***************************************************************************************/
int main()
{
  IntCtrl_Config();
  GPIO_Config();
  SysTick_Config();
  Delay_ms(1500);
  while (1)
  {
    GPIO_WritePin(GPIOA, PIN_0, HIGH); /*LED ON*/
    Delay_ms(LED_ON_DELAY_ms);
    GPIO_WritePin(GPIOA, PIN_0, LOW); /*LED OFF*/
    Delay_ms(LED_OFF_DELAY_ms);
  }
  return 0;
}

/***************************************************************************************
 *                                       Local Functions                               *
 ***************************************************************************************/
void IntCtrl_Config(void)
{
  User_Config_IRQ_Type Interrupts_Cfg;

  Interrupts_Cfg.Enabled[Bus_Fault_IRQ] = 1;
  Interrupts_Cfg.Group_Priority[Bus_Fault_IRQ] = 3;
  Interrupts_Cfg.Sub_Group_Priority[Bus_Fault_IRQ] = 3;

  Interrupts_Cfg.Enabled[Usage_Fault_IRQ] = 1;
  Interrupts_Cfg.Group_Priority[Usage_Fault_IRQ] = 3;
  Interrupts_Cfg.Sub_Group_Priority[Usage_Fault_IRQ] = 5;

  Interrupts_Cfg.Enabled[GPIOA_IRQ] = 1;
  Interrupts_Cfg.Group_Priority[GPIOA_IRQ] = 3;
  Interrupts_Cfg.Sub_Group_Priority[GPIOA_IRQ] = 3;

  Interrupts_Cfg.Enabled[GPIOB_IRQ] = 1;
  Interrupts_Cfg.Group_Priority[GPIOB_IRQ] = 3;
  Interrupts_Cfg.Sub_Group_Priority[GPIOB_IRQ] = 7;

  Interrupts_Cfg.Enabled[GPIOC_IRQ] = 1;
  Interrupts_Cfg.Group_Priority[GPIOC_IRQ] = 3;
  Interrupts_Cfg.Sub_Group_Priority[GPIOC_IRQ] = 6;

  Interrupts_Cfg.Enabled[GPIOD_IRQ] = 1;
  Interrupts_Cfg.Group_Priority[GPIOD_IRQ] = 3;
  Interrupts_Cfg.Sub_Group_Priority[GPIOD_IRQ] = 4;

  Interrupts_Cfg.Enabled[GPIOE_IRQ] = 1;
  Interrupts_Cfg.Group_Priority[GPIOE_IRQ] = 3;
  Interrupts_Cfg.Sub_Group_Priority[GPIOE_IRQ] = 5;
  IntCtrl_Init(&Interrupts_Cfg);
}
void GPIO_Config(void)
{
  User_Config_GPIO_Type GPIOCfg;

  /*Init Port A*/
  GPIOCfg.Enabled[GPIOA] = 1;
  GPIOCfg.PortPinsMode[GPIOA] = OUTPUT_Push_Pull;
  GPIOCfg.PortPinsCurrent[GPIOA] = C_8MA;
  GPIOCfg.PortInitValue[GPIOA] = 0x01;

  GPIOCfg.Enabled[GPIOC] = 1;
  GPIOCfg.PortPinsMode[GPIOC] = Input_PullUp;

  GPIOCfg.Enabled[GPIOF] = 1;
  GPIOCfg.PortPinsMode[GPIOF] = OUTPUT_Push_Pull;
  GPIOCfg.PortPinsCurrent[GPIOF] = C_8MA;
  GPIOCfg.PortInitValue[GPIOF] = 0xFF;

  GPIO_Port_Init(&GPIOCfg);
}

void SysTick_Config(void)
{
  SysTick_Interrupt_Enable();
  IntCtrl_Set_CallBack(SysTick_Expired, SysTick_IRQ);
}

void SysTick_Expired()
{
  if (u32_SysTick_OverFlow_Counter != 0)
  {
    u32_SysTick_OverFlow_Counter--;
    if (u32_SysTick_OverFlow_Counter == 0)
    {
      SysTick_Stop_Timer();
    }
  }
}

void Delay_ms(uint32 u32_Delay)
{
  float32 f32_ReloadValue;
  if (u32_Delay < MAX_TIMER_TIME_ms)
  { /*Check whether delay is bigger than one timer overflow*/
    f32_ReloadValue = ((((float)u32_Delay / 1000) * SYS_CLC) - 1);
    u32_SysTick_OverFlow_Counter = 1;
    SysTick_Init((uint32)f32_ReloadValue);
    SysTick_Start_Timer();
    while (u32_SysTick_OverFlow_Counter != 0)
    {
    } /*wait till overflow counter is zero*/
  }
  else
  {
    u32_SysTick_OverFlow_Counter = ((((float)u32_Delay / 1000) * SYS_CLC) / MAX_TIMER_COUNT);
    u32_Delay -= (u32_SysTick_OverFlow_Counter * MAX_TIMER_TIME_ms);
    f32_ReloadValue = ((((float)u32_Delay / 1000) * SYS_CLC) - 1);
    SysTick_Init(MAX_TIMER_COUNT);
    SysTick_Start_Timer();
    while (u32_SysTick_OverFlow_Counter != 0)
    {
    } /*wait till overflow counter is zero*/
    u32_SysTick_OverFlow_Counter = 1;
    SysTick_Init((uint32)f32_ReloadValue);
    SysTick_Start_Timer();
    while (u32_SysTick_OverFlow_Counter != 0)
    {
    } /*wait till overflow counter is zero*/
  }
}

/***************************************************************************************
 *                               End of File: LED_Control.c                            *
 ***************************************************************************************/