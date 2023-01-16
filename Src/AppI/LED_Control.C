#include "IntCtrl.h"
void IntCtrl_Config(void);

int main(){
	IntCtrl_Config();
    while(1){
			
        
    }
		return 0;
}
void IntCtrl_Config(void){
    User_Config_IRQ_Type Interrupts_Cfg;
    Interrupts_Cfg.Enabled[Bus_Fault_IRQ] = 1;
    Interrupts_Cfg.Group_Priority[Bus_Fault_IRQ] = 0;
    Interrupts_Cfg.Sub_Group_Priority[Bus_Fault_IRQ] = 3;

    Interrupts_Cfg.Enabled[Usage_Fault_IRQ] = 1;
    Interrupts_Cfg.Group_Priority[Usage_Fault_IRQ] = 0;
    Interrupts_Cfg.Sub_Group_Priority[Usage_Fault_IRQ] = 5;


    Interrupts_Cfg.Enabled[GPIOA_IRQ] = 1;
    Interrupts_Cfg.Group_Priority[GPIOA_IRQ] = 0;
    Interrupts_Cfg.Sub_Group_Priority[GPIOA_IRQ] = 2;

    Interrupts_Cfg.Enabled[GPIOB_IRQ] = 1;
    Interrupts_Cfg.Group_Priority[GPIOB_IRQ] = 0;
    Interrupts_Cfg.Sub_Group_Priority[GPIOB_IRQ] = 2;

    Interrupts_Cfg.Enabled[GPIOC_IRQ] = 1;
    Interrupts_Cfg.Group_Priority[GPIOC_IRQ] = 0;
    Interrupts_Cfg.Sub_Group_Priority[GPIOC_IRQ] = 2;

    Interrupts_Cfg.Enabled[GPIOD_IRQ] = 1;
    Interrupts_Cfg.Group_Priority[GPIOD_IRQ] = 0;
    Interrupts_Cfg.Sub_Group_Priority[GPIOD_IRQ] = 2;

    Interrupts_Cfg.Enabled[GPIOE_IRQ] = 1;
    Interrupts_Cfg.Group_Priority[GPIOE_IRQ] = 0;
    Interrupts_Cfg.Sub_Group_Priority[GPIOE_IRQ] = 2;
    IntCtrl_Init(&Interrupts_Cfg);
}
