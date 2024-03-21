/* 
 * File:   hal_timer2.c
 * Author: Joe
 *
 * Created on March 10, 2024, 4:22 PM
 */

#include "hal_timer2.h"


#if (INTERRUPT_FEATURE)
static void (* timer2_interrupt_handler)(void)=NULL;
static volatile uint8_t timer2_reg_preload;
#endif

void TIMER2_ISR(void){
    TIMER2_INTERRUPT_CLEAR_FLAG();
    
    TMR2 = (uint8_t)(timer2_reg_preload); 

    if (timer2_interrupt_handler){
        timer2_interrupt_handler();
    }   
}


Std_ReturnType timer2_init(timer2_t *timer2_config){
    if (NULL == timer2_config){
        return E_NOT_OK;
    }
    else{
        
        /*disable TIMER1*/
        TIMER2_MODULE_DISABLE();
        /*set pre-scale value*/
        TIMER2_SET_PRESCALE_VALUE(timer2_config->prescaler_value);
        /*set post-scale value*/
        TIMER2_SET_POSTSCALE_VALUE(timer2_config->postscaler_value);
        /*set pre-loaded value*/
        TMR2 =(timer2_config->preloaded_value);
        
        /*configure interrupt*/
#if (INTERRUPT_FEATURE)
        INTERRUPT_GLOBAL_ENABLE();
        INTERRUPT_PERIFERALS_ENABLE();
        TIMER2_INTERRUPT_ENABLE();
        TIMER2_INTERRUPT_CLEAR_FLAG();
        timer2_interrupt_handler = timer2_config->interrupt_handler;
        timer2_reg_preload = timer2_config->preloaded_value;
#if (INTERRUPT_PRIORITY_LEVELS)
        INTERRUPT_PRIORITY_ENABLE();
        TIMER2_HIGH_PRIOTIRY_SET();     
//        TIMER2_LOW_PRIOTIRY_SET();
#endif
#endif
        
        /*enable TIMER1*/
        TIMER2_MODULE_ENABLE();
        return E_OK;
    }
    
}
Std_ReturnType timer2_deinit(timer2_t *timer2_config);
Std_ReturnType timer2_read_reg(uint8_t *timer_value){
    if (timer_value == NULL)
    {
        return E_NOT_OK;
    }
    *timer_value = TMR2;
    return E_OK;
}
Std_ReturnType timer2_write_reg(uint8_t data){
    TMR2= data;
    return E_OK;
}
