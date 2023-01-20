/***************************************************************************************
 *                                  File Description                                   *
 *  Name: IntCtrl.c                                                                    *
 *  Brief: Nested Vector Interrupt Controller Driver                                   *
 *  Author: Ahmed M. Rizk                                                              *
 *  Date: 14th of January 2023                                                         *
 *                                                                                     *
 * Details: ~Enables Interrupt Gates for Peripherals                                   *
 *           ~Configures Interrupt Priorities                                          *
 *                                                                                     *
 ****************************************************************************************/

/***************************************************************************************
 *                                       Includes                                      *
 ****************************************************************************************/
#include "IntCtrl.h"
/***************************************************************************************
 *                             Local Macros Constant\Function                          *
 ****************************************************************************************/

/***************************************************************************************
 *                                       Local Data                                    *
 ****************************************************************************************/
void (* PF_CallBack[154])(void);
/***************************************************************************************
 *                                       Global Data                                   *
 ****************************************************************************************/

/***************************************************************************************
 *                                Local Function Prototypes                            *
 ****************************************************************************************/
void IntCtrl_ConfigPriority(IntVectors_Type E_IntNum, uint8 u8_InteruptPriority);
void IntCtrl_EnableIRQ(IntVectors_Type E_IntNum);
void IntCtrl_DisableIRQ(IntVectors_Type E_IntNum);
/***************************************************************************************
 *                                       Local Functions                               *
 ****************************************************************************************/
void IntCtrl_ConfigPriority(IntVectors_Type E_IntNum, uint8 u8_InteruptPriority){
    if(E_IntNum>SysTick_IRQ){
        uint8 u8_InterruptNum=E_IntNum;
        u8_InterruptNum-=16;
        if(u8_InterruptNum%4==0){
            PRI(u8_InterruptNum)|=((uint32)u8_InteruptPriority<<5);
        }
        else if(u8_InterruptNum%4==1){
            PRI(u8_InterruptNum)|=((uint32)u8_InteruptPriority<<13);
        }
        else if(u8_InterruptNum%4==2){
            PRI(u8_InterruptNum)|=((uint32)u8_InteruptPriority<<21);            
        }
        else{
            PRI(u8_InterruptNum)|=((uint32)u8_InteruptPriority<<29);
        }

    }
    else{
        switch (E_IntNum)
        {
        case Memory_Management_IRQ:
            SYSPRI->MEM = u8_InteruptPriority;
            break;
        case Bus_Fault_IRQ:
            SYSPRI->BUS = u8_InteruptPriority;
            break;
        case Usage_Fault_IRQ:
            SYSPRI->USAGE |= u8_InteruptPriority;
            break;
        case SVCall_IRQ:
            SYSPRI->SVC = u8_InteruptPriority;
            break;
        case Debug_Monitor_IRQ:
            SYSPRI->DEBUG = u8_InteruptPriority;
            break;
        case PendSV_IRQ:
            SYSPRI->PENDSV = u8_InteruptPriority;
            break;
        case SysTick_IRQ:
            SYSPRI->TICK = u8_InteruptPriority;
            break;
        default:
            break;
        }
    }
}
void IntCtrl_EnableIRQ(IntVectors_Type E_IntNum){
    if(E_IntNum>SysTick_IRQ){
        uint8 u8_InterruptNum=E_IntNum;
        u8_InterruptNum-=16UL;
        SET_BIT(EN(u8_InterruptNum), u8_InterruptNum%32UL);
    }
    else{
        switch (E_IntNum)
        {
        case Memory_Management_IRQ:
            SYSHNDCTRL->B.MEM=1;
            break;
        case Bus_Fault_IRQ:
            SYSHNDCTRL->B.BUS=1;
            break;
        case Usage_Fault_IRQ:
            SYSHNDCTRL->B.USAGE=1;
            break;
        case SVCall_IRQ:
            break;
        case Debug_Monitor_IRQ:
            break;
        case PendSV_IRQ:
            break;
        case SysTick_IRQ:
            break;
        default:
            break;
        }
    }
}
void IntCtrl_DisableIRQ(IntVectors_Type E_IntNum){
        if(E_IntNum>SysTick_IRQ){
        uint8 u8_InterruptNum=E_IntNum;
        u8_InterruptNum-=16UL;
        SET_BIT(DIS(u8_InterruptNum), u8_InterruptNum%32UL);
    }
    else{
        switch (E_IntNum)
        {
        case Memory_Management_IRQ:
            SYSHNDCTRL->B.MEM=0;
            break;
        case Bus_Fault_IRQ:
            SYSHNDCTRL->B.BUS=0;
            break;
        case Usage_Fault_IRQ:
            SYSHNDCTRL->B.USAGE=0;
            break;
        case SVCall_IRQ:
            break;
        case Debug_Monitor_IRQ:
            break;
        case PendSV_IRQ:
            break;
        case SysTick_IRQ:
            break;
        default:
            break;
        }
    }
}
/***************************************************************************************
 *                                    API Implementations                              *
 ****************************************************************************************/
/***********************************************************
 * Syntax:
 * Description:
 *
 *
 *
 *************************************************************/
void IntCtrl_Init(User_Config_IRQ_Type *S_UserConfig){
    uint8 u8_i;
    uint8 u8_IRQ_Priority = 0, u8_Group_Priority, u8_Sub_Group_Priority;
    /*Configure Grouping/Subgrouping Systems in APPINT register in SCB*/
    APINT = (0x05FA << 16) | (Int_Priority << 8);
    for (u8_i=1; u8_i <= 154; u8_i++)
    {
        u8_Group_Priority=S_UserConfig->Group_Priority[u8_i];
        u8_Sub_Group_Priority=S_UserConfig->Sub_Group_Priority[u8_i];
        /*Assign Grouping/Subgrouping priority in NVIC PRIx NVIC and SCB_SYSPRIx Registers*/
#if   Int_Priority == XXX
        u8_IRQ_Priority = ((u8_Group_Priority) & 0x7);
#elif Int_Priority == XXY
        u8_IRQ_Priority = (((u8_Group_Priority) & 0x03) << 1UL) | ((u8_Sub_Group_Priority) & 0x01);
#elif Int_Priority == XYY
        u8_IRQ_Priority = (((u8_Group_Priority) & 0x01) << 2UL) | ((u8_Sub_Group_Priority) & 0x03);
#elif Int_Priority == YYY
        u8_IRQ_Priority = ((u8_Sub_Group_Priority) & 0x07);
#endif
        IntCtrl_ConfigPriority(u8_i, u8_IRQ_Priority);
        /*Enable/Disable based on user configuration in NVIC_ENx and SCB_Sys Registers*/
        if(S_UserConfig->Enabled[u8_i]){
            IntCtrl_EnableIRQ(u8_i);
        }
    }
}

void IntCtrl_Set_CallBack(void(*PF_CallBackAddress)(void), IntVectors_Type IRQ_Vector){
    PF_CallBack[IRQ_Vector]=PF_CallBackAddress;
}

void SysTick_Handler(){
    if(PF_CallBack[SysTick_IRQ]!=NULL){
    (*PF_CallBack[SysTick_IRQ])();
    }
}

/***************************************************************************************
 *                               End of File: IntCtrl.c                                *
 ****************************************************************************************/
