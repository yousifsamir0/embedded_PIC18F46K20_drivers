
/* 
 * File:   hal_timer1.c
 * Author: Joe
 *
 * Created on March 10, 2024, 2:11 PM
 */

#include "hal_timer1.h"

#if (INTERRUPT_FEATURE)
static void (* timer1_interrupt_handler)(void)=NULL;
static volatile uint16_t timer1_reg_preload;
#endif

void TIMER1_ISR(void){
    TIMER1_INTERRUPT_CLEAR_FLAG();
    
    TMR1L = (uint8_t)(timer1_reg_preload); 
    TMR1H = (uint8_t)(timer1_reg_preload>>8);
    
    if (timer1_interrupt_handler){
        timer1_interrupt_handler();
    }   
}



static inline void set_rw_mode(uint8_t);
static inline void set_clock_source(timer1_t *timer1_config);


Std_ReturnType timer1_init(timer1_t *timer1_config){
    if (NULL == timer1_config){
        return E_NOT_OK;
    }
    else{
        
        /*disable TIMER1*/
        TIMER1_MODULE_OFF();
        /*set pre-scale value*/
        TIMER1_SET_PRESCALE(timer1_config->prescale);
        /*set read/write 8/16 bit mode*/
        set_rw_mode(timer1_config->RW_8bit_mode_enable);
        /*set pre-loaded value*/
        timer1_write_reg(timer1_config->preloaded_value);
        /*set clock source external/internal*/
        set_clock_source(timer1_config);
        
        /*configure interrupt*/
#if (INTERRUPT_FEATURE)
        INTERRUPT_GLOBAL_ENABLE();
        INTERRUPT_PERIFERALS_ENABLE();
        TIMER1_INTERRUPT_ENABLE();
        TIMER1_INTERRUPT_CLEAR_FLAG();
        timer1_interrupt_handler = timer1_config->interrupt_handler;
        timer1_reg_preload = timer1_config->preloaded_value;
#if (INTERRUPT_PRIORITY_LEVELS)
        INTERRUPT_PRIORITY_ENABLE();
        TIMER1_HIGH_PRIOTIRY_SET();     
//        TIMER1_LOW_PRIOTIRY_SET();
#endif
#endif
        
        /*enable TIMER1*/
        TIMER1_MODULE_ON();

        return E_OK;
    }
    
}
Std_ReturnType timer1_deinit(timer1_t *timer1_config){
    
}
Std_ReturnType timer1_read_reg(uint16_t *timer_value){
    if (NULL == timer_value)
    {
        return E_NOT_OK;
    }
    else{
        
        *timer_value = (uint8_t)TMR1L;
        *timer_value += (uint8_t)(TMR1H<<8);
        return E_OK;
    }
}
Std_ReturnType timer1_write_reg(uint16_t data){
    
    TMR1L = (uint8_t)(data);
    TMR1H = (uint8_t)(data>>8);
    return E_OK;
}

static inline void set_rw_mode(uint8_t mode){
    if (mode){
        TIMER1_RW_8BIT_REG();
    }else{
        TIMER1_RW_16BIT_REG();
    }
}
static inline void set_clock_source(timer1_t *timer1_config){
    if (TIMER1_EXTERNAL_CLOCK_SOURCE == timer1_config->clock_source){
        TIMER1_SET_EXTERNAL_CLOCK_SOURCE();
        
        if (TIMER1_EXTERNAL_CLOCK_SYNC == timer1_config->external_sync){
            TIMER1_SET_EXTERNAL_CLOCK_SYNC();
        }
        else{
            TIMER1_SET_EXTERNAL_CLOCK_ASYNC();
        }
        TRISCbits.RC0 = INPUT_DIRECTION;
        TRISCbits.RC1 = INPUT_DIRECTION;
        
    }
    else{
        TIMER1_SET_INTERNAL_FOSC_DIV_4();
    }
}