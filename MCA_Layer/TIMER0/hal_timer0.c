/* 
 * File:   hal_timer0.c
 * Author: Joe
 *
 * Created on March 5, 2024, 3:20 PM
 */
#include "hal_timer0.h"

#if (INTERRUPT_FEATURE)
static void (* timer0_interrupt_handler)(void)=NULL;
static volatile uint16_t timer0_reg_preload;
#endif

static inline void timer0_set_bit_mode(timer0_t *timer0_config);
static inline void timer0_set_clock_source(timer0_t *timer0_config);
static inline void timer0_set_clock_prescaler(timer0_t *timer0_config);



void TIMER0_ISR(void){
    TIMER0_INTERRUPT_CLEAR_FLAG();
    
    TMR0L = (uint8_t)(timer0_reg_preload); 
    TMR0H = (uint8_t)(timer0_reg_preload>>8);
    
    if (timer0_interrupt_handler){
        timer0_interrupt_handler();
    }   
}

Std_ReturnType timer0_init(timer0_t *timer0_config){
    Std_ReturnType ret = E_OK;
    if (NULL==timer0_config){
        return E_NOT_OK;
    }
    else{
        TIMER0_DISABLE();
        
#if (INTERRUPT_FEATURE)
        INTERRUPT_GLOBAL_ENABLE();
        INTERRUPT_PERIFERALS_ENABLE();
        TIMER0_INTERRUPT_ENABLE();
        TIMER0_INTERRUPT_CLEAR_FLAG();
        timer0_interrupt_handler = timer0_config->interrupt_handler;
        timer0_reg_preload = timer0_config->preloaded_value;
#if (INTERRUPT_PRIORITY_LEVELS)
        INTERRUPT_PRIORITY_ENABLE();
        TIMER0_HIGH_PRIOTIRY_SET();     
//        TIMER0_LOW_PRIOTIRY_SET();
#endif
#endif
        
        timer0_set_bit_mode(timer0_config);
        timer0_set_clock_source(timer0_config);
        timer0_set_clock_prescaler(timer0_config);
        ret |= timer0_write_register(timer0_config->preloaded_value);
        
        TIMER0_ENABLE();
        return ret;
    }
}
Std_ReturnType timer0_de_init(timer0_t *timer0_config){
        Std_ReturnType ret = E_OK;
    if (NULL==timer0_config){
        return E_NOT_OK;
    }
    else{
        
        
        return ret;
    }
}
Std_ReturnType timer0_write_register(uint16_t data){
    Std_ReturnType ret = E_OK;
    TMR0L = (uint8_t)(data); 
    TMR0H = (uint8_t)(data>>8);
    return ret;
}
Std_ReturnType timer0_read_register(uint16_t *timer_value){

    if (NULL==timer_value){
        return E_NOT_OK;
    }
    else{
        
        *timer_value =  (uint16_t)TMR0L;
        *timer_value += (uint16_t)(TMR0H<<8) & (0xff00); 

        return E_OK;
    }
}



static inline void timer0_set_bit_mode(timer0_t *timer0_config){
    if (timer0_config->bits_mode == TIMER0_8_BIT_MODE){
        TIMER0_SET_8_BIT_MODE();
    }
    else{
        TIMER0_SET_16_BIT_MODE();
    }
}
static inline void timer0_set_clock_source(timer0_t *timer0_config){
    if (timer0_config->clock_source == TIMER0_CLOCK_SOURCE_EXTERNAL){
        TIMER0_SET_CLOCK_SOURCE_EXTERNAL();
        TRISAbits.RA4 = INPUT_DIRECTION;
        if (timer0_config->clock_edge == TIMER0_EXT_CLOCK_FALLING_EDGE){
            TIMER0_SET_EXT_CLOCK_FALLING_EDGE();
        }
        else{
            TIMER0_SET_EXT_CLOCK_RISING_EDGE();
        }
    }
    else{
        TIMER0_SET_CLOCK_SOURCE_INTERNAL();
    }
}
static inline void timer0_set_clock_prescaler(timer0_t *timer0_config){
    if (timer0_config->prescaler == STD_ZERO){
        TIMER0_PRESCALE_ENABLE();
        TIMER0_SET_PRESCALE_VALUE(timer0_config->prescale_value);
    }
    else{
        TIMER0_PRESCALE_DISABLE();
    }
}


