/* 
 * File:   hal_timer3.h
 * Author: Joe
 *
 * Created on March 10, 2024, 5:32 PM
 */
#include "hal_timer3.h"

#if (INTERRUPT_FEATURE)
static void (* timer3_interrupt_handler)(void)=NULL;
static volatile uint16_t timer3_reg_preload;
#endif

void TIMER3_ISR(void){
    TIMER3_INTERRUPT_CLEAR_FLAG();
    
    TMR3L = (uint8_t)(timer3_reg_preload); 
    TMR3H = (uint8_t)(timer3_reg_preload>>8);
    
    if (timer3_interrupt_handler){
        timer3_interrupt_handler();
    }   
}



static inline void set_rw_mode(uint8_t);
static inline void set_clock_source(timer3_t *timer3_config);


Std_ReturnType timer3_init(timer3_t *timer3_config){
    if (NULL == timer3_config){
        return E_NOT_OK;
    }
    else{
        
        /*disable TIMER3*/
        TIMER3_MODULE_OFF();
        /*set pre-scale value*/
        TIMER3_SET_PRESCALE(timer3_config->prescale);
        /*set read/write 8/16 bit mode*/
        set_rw_mode(timer3_config->RW_8bit_mode_enable);
        /*set pre-loaded value*/
        timer3_write_reg(timer3_config->preloaded_value);
        /*set clock source external/internal*/
        set_clock_source(timer3_config);
        
        /*configure interrupt*/
#if (INTERRUPT_FEATURE)
        INTERRUPT_GLOBAL_ENABLE();
        INTERRUPT_PERIFERALS_ENABLE();
        TIMER3_INTERRUPT_ENABLE();
        TIMER3_INTERRUPT_CLEAR_FLAG();
        timer3_interrupt_handler = timer3_config->interrupt_handler;
        timer3_reg_preload = timer3_config->preloaded_value;
#if (INTERRUPT_PRIORITY_LEVELS)
        INTERRUPT_PRIORITY_ENABLE();
        TIMER3_HIGH_PRIOTIRY_SET();     
//        TIMER3_LOW_PRIOTIRY_SET();
#endif
#endif
        
        /*enable TIMER3*/
        TIMER3_MODULE_ON();

        return E_OK;
    }
    
}
Std_ReturnType timer3_deinit(timer3_t *timer3_config){
    
}
Std_ReturnType timer3_read_reg(uint16_t *timer_value){
    if (NULL == timer_value)
    {
        return E_NOT_OK;
    }
    else{
        
        *timer_value = TMR3L;
        *timer_value += (TMR3H<<8);
        return E_OK;
    }
}
Std_ReturnType timer3_write_reg(uint16_t data){
    
    TMR3L = (uint8_t)(data);
    TMR3H = (uint8_t)(data>>8);
    return E_OK;
}

static inline void set_rw_mode(uint8_t mode){
    if (mode){
        TIMER3_RW_8BIT_REG();
    }else{
        TIMER3_RW_16BIT_REG();
    }
}
static inline void set_clock_source(timer3_t *timer3_config){
    if (TIMER3_EXTERNAL_CLOCK_SOURCE == timer3_config->clock_source){
        TIMER3_SET_EXTERNAL_CLOCK_SOURCE();
        
        if (TIMER3_EXTERNAL_CLOCK_SYNC == timer3_config->external_sync){
            TIMER3_SET_EXTERNAL_CLOCK_SYNC();
        }
        else{
            TIMER3_SET_EXTERNAL_CLOCK_ASYNC();
        }
        TRISCbits.RC0 = INPUT_DIRECTION;
        TRISCbits.RC1 = INPUT_DIRECTION;
        
    }
    else{
        TIMER3_SET_INTERNAL_FOSC_DIV_4();
    }
}
