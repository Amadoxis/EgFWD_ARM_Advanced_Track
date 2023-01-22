/***************************************************************************************
 *                                  File Description                                   *
 *  Name: MCU_Hw.h                                                                     *
 *  Brief: TivaC Hardware Header File                                                  *
 *  Author: Ahmed M. Rizk                                                              *
 *  Date: 14th of January 2023                                                         *
 *                                                                                     *
 * Details: ~Contains Registers and their Struct/Union bit field representations       *
 *                                                                                     *
 ****************************************************************************************/
#ifndef MCU_HW_H_
#define MCU_HW_H_

/***************************************************************************************
 *                                       Includes                                      *
****************************************************************************************/
#include "Platform_Types.h"
#include "BIT_MATH.h"
/***************************************************************************************
 *                          Global Data Types and Structures                           *
****************************************************************************************/
typedef union {
    vuint32        R;
    struct{
        vuint32 MEMA   :1; /*Memory Management Fault Active*/
        vuint32 BUSA   :1; /*Bus Fault Active*/
        vuint32        :1;
        vuint32 USGA   :1; /*Usage Fault Active*/
        vuint32        :3; 
        vuint32 SVCA   :1; /*SVC Cal Active*/
        vuint32 MON    :1; /*Debug Monitor Active*/
        vuint32        :1;
        vuint32 PNDSV  :1; /*PendSV Active*/
        vuint32 TICK   :1; /*SysTick Active*/
        vuint32 USAGEP :1; /*Usage Fault Pending*/
        vuint32 MEMP   :1; /*Memeory Management Fault Pending*/
        vuint32 BUSP   :1; /*Bus Fault Pending*/
        vuint32 SVC    :1; /*SVC Call Pending*/
        vuint32 MEM    :1; /*Memeory Management Fault Enable*/
        vuint32 BUS    :1; /*Bus Fault Enable*/
        vuint32 USAGE  :1; /*Usage Fault Enable*/
        vuint32        :13;
    }B;
}SYSHNDCTRL_Tag;

typedef struct{
    vuint32          : 5;
    vuint32 MEM      : 3;
    vuint32          : 5;
    vuint32 BUS      : 3;
    vuint32          : 5;
    vuint32 USAGE    : 3;
    vuint32          : 8;
    vuint32          :29;
    vuint32 SVC      : 3;
    vuint32          : 5;
    vuint32 DEBUG    : 3;
    vuint32          :13;
    vuint32 PENDSV   : 3;
    vuint32          : 5;
    vuint32 TICK     : 3;
}SYSPRI_BF;

typedef struct{
    vuint32 _Reserved_1_[255]; /*gap between 0x000 and 0x400*/
    vuint32 GPIODATA; /*Data Register*/
    vuint32 GPIODIR;  /*Direction Register*/
    vuint32 GPIOIS;
    vuint32 GPIOIBE;
    vuint32 GPIOIEV;
    vuint32 GPIOIM;
    vuint32 GPIORIS;
    vuint32 GPIOMIS;
    vuint32 GPIOICR;
    vuint32 GPIOAFSEL;
    vuint32 _Reserved_2_[55]; /*gap between 0x420 and 0x500*/
    vuint32 GPIODR2R; /*2 mA output*/
    vuint32 GPIODR4R; /*4 mA output*/
    vuint32 GPIODR8R; /*8 mA output*/
    vuint32 GPIOODR;
    vuint32 GPIOPUR;
    vuint32 GPIOPDR;
    vuint32 GPIOSLR;
    vuint32 GPIODEN;  /*GPIO Digital Input Enable*/
    vuint32 GPIOLOCK; /*GPIO Lock*/
    vuint32 GPIOCR;   /*GPIO Commit*/
    vuint32 GPIOAMSEL;
    vuint32 GPIOPCTL;
    vuint32 GPIOADCCTL;
    vuint32 GPIODMACTL;
    }GPIO_Reg;

typedef union{
    vuint32 R;
    struct{
        vuint32 ENABLE  : 1;
        vuint32 INTEN   : 1;
        vuint32 CLK_SRC : 1;
        vuint32         :13;
        vuint32 COUNT   : 1;
        vuint32         :15;
    }B;

}STCTRL_Tag;
/***************************************************************************************
 *                              Global Constant Macros                                 *
****************************************************************************************/
#define SYS_CLC 16000000UL /*Sytem Clock*/
/************************************Base Addresses************************************/
#define Cortex_M4_Core_Peripherals_Base_Address 0xE000E000UL
#define System_Control_Base_Address             0x400FE000UL
#define GPIO_Base_APB                           0x40004000UL
// #define GPIOA_Base_APB                          0x40004000UL
// #define GPIOB_Base_APB                          0x40005000UL
// #define GPIOC_Base_APB                          0x40006000UL
// #define GPIOD_Base_APB                          0x40007000UL
// #define GPIOE_Base_APB                          0x40024000UL
// #define GPIOF_Base_APB                          0x40025000UL

// #define GPIOA_Base_AHB                          0x40058000UL
// #define GPIOB_Base_AHB                          0x40059000UL
// #define GPIOC_Base_AHB                          0x4005A000UL
// #define GPIOD_Base_AHB                          0x4005B000UL
// #define GPIOE_Base_AHB                          0x4005C000UL
// #define GPIOF_Base_AHB                          0x4005D000UL

/************************************SysTick Timer ************************************/
#define STCTRL      ((STCTRL_Tag*) (Cortex_M4_Core_Peripherals_Base_Address+0x010UL))
#define STRELOAD   *((vuint32*)    (Cortex_M4_Core_Peripherals_Base_Address+0x014UL))
#define STCURRENT  *((vuint32*)    (Cortex_M4_Core_Peripherals_Base_Address+0x018UL))

/************************************NVIC************************************/
#define EN(x)      *((vuint32*) (Cortex_M4_Core_Peripherals_Base_Address+0x100UL+((x/32UL)*32UL)))
#define DIS(x)     *((vuint32*) (Cortex_M4_Core_Peripherals_Base_Address+0x180UL+((x/32UL)*32UL)))
#define PRI(x)     *((vuint32*) (Cortex_M4_Core_Peripherals_Base_Address+0x400UL+((x/4UL)*4UL)))

/*************************************SCB*************************************/
#define APINT      *((vuint32*)        (Cortex_M4_Core_Peripherals_Base_Address+0xD0CUL))
#define SYSPRI      ((SYSPRI_BF*)      (Cortex_M4_Core_Peripherals_Base_Address+0xD18UL))
#define SYSHNDCTRL  ((SYSHNDCTRL_Tag*) (Cortex_M4_Core_Peripherals_Base_Address+0xD24UL))

/*************************************System Control*************************************/
#define RCC        *((vuint32*) (System_Control_Base_Address+0x060UL))
#define GPIOHBCTL  *((vuint32*) (System_Control_Base_Address+0x06CUL))
#define RCC2       *((vuint32*) (System_Control_Base_Address+0x070UL))
#define SRGPIO     *((vuint32*) (System_Control_Base_Address+0x508UL))
#define RCGCGPIO   *((vuint32*) (System_Control_Base_Address+0x608UL))


/*************************************GPIO*************************************/
/*@*@*@*@*@*@*@*@* APB *@*@*@*@*@*@*@*@*@*/
#define GPIO_APB(X)  ((GPIO_Reg*)(X<4?((0x40004000UL)+((X)*0x1000UL)):((0x40024000UL)+((X-4)*0x1000UL))))


// #define GPIOA_APB ((GPIO_Reg*) (GPIOA_Base_APB));
// #define GPIOB_APB ((GPIO_Reg*) (GPIOB_Base_APB));
// #define GPIOC_APB ((GPIO_Reg*) (GPIOC_Base_APB));
// #define GPIOD_APB ((GPIO_Reg*) (GPIOD_Base_APB));
// #define GPIOF_APB ((GPIO_Reg*) (GPIOE_Base_APB));
// #define GPIOE_APB ((GPIO_Reg*) (GPIOF_Base_APB));

/*@*@*@*@*@*@*@*@* AHB *@*@*@*@*@*@*@*@*@*/
// #define GPIOA_AHB ((GPIO_Reg*) (GPIOA_Base_AHB));
// #define GPIOB_AHB ((GPIO_Reg*) (GPIOB_Base_AHB));
// #define GPIOC_AHB ((GPIO_Reg*) (GPIOC_Base_AHB));
// #define GPIOD_AHB ((GPIO_Reg*) (GPIOD_Base_AHB));
// #define GPIOF_AHB ((GPIO_Reg*) (GPIOE_Base_AHB));
// #define GPIOE_AHB ((GPIO_Reg*) (GPIOF_Base_AHB));
#endif /*MCU_HW_H_*/

/***************************************************************************************
 *                               End of File: Mcu_Hw.h                                 *
 ****************************************************************************************/
