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
/***************************************************************************************
 *                              Global Constant Macros                                 *
****************************************************************************************/
#define Cortex_M4_Core_Peripherals_Base_Address 0xE000E000UL
/************************************SysTick************************************/
#define STCTRL     *((vuint32*) (Cortex_M4_Core_Peripherals_Base_Address+0x010UL))
#define STRELOAD   *((vuint32*) (Cortex_M4_Core_Peripherals_Base_Address+0x014UL))
#define STCURRENT  *((vuint32*) (Cortex_M4_Core_Peripherals_Base_Address+0x018UL))

/************************************NVIC************************************/
#define EN(x)  *((vuint32*) (Cortex_M4_Core_Peripherals_Base_Address+0x100+((x/32)*32)))
#define DIS(x) *((vuint32*) (Cortex_M4_Core_Peripherals_Base_Address+0x180+((x/32)*32)))
#define PRI(x) *((vuint32*) (Cortex_M4_Core_Peripherals_Base_Address+0x400+((x/4)*4)))
/*************************************SCB*************************************/
#define APINT      *((vuint32*)        (Cortex_M4_Core_Peripherals_Base_Address+0xD0CUL))
#define SYSPRI      ((SYSPRI_BF*)      (Cortex_M4_Core_Peripherals_Base_Address+0xD18UL))
#define SYSHNDCTRL  ((SYSHNDCTRL_Tag*) (Cortex_M4_Core_Peripherals_Base_Address+0xD24UL))

#endif /*MCU_HW_H_*/
