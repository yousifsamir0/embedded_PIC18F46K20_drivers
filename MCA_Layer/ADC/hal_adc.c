/* 
 * File:   hal_adc.c
 * Author: Joe
 *
 * Created on March 4, 2024, 9:35 AM
 */
#include "hal_adc.h"

#if (INTERRUPT_FEATURE)
static void (* adc_call_back_handler)(void)=NULL;
static volatile uint16_t *interrupt_result=NULL;
#endif

static inline void adc_set_vref(uint8_t vref);
static inline void adc_port_configure(adc_channel_select_t channel);


void ADC_ISR(void){
    ADC_INTERRUPT_CLEAR_FLAG();
    if(interrupt_result)
        adc_get_conversion_result(interrupt_result);
    
    if (adc_call_back_handler){
        adc_call_back_handler();
    }
    interrupt_result=NULL;
    
}


Std_ReturnType adc_init(adc_config_t *adc_config){
    Std_ReturnType ret = E_OK;
    if (NULL==adc_config){
        return E_NOT_OK;
    }
    else{
        ADC_MODULE_DISABLE();
        
        ADC_SET_ACQUISITION_TIME(adc_config->acquisition_time);
        ADC_SET_CONVERTION_CLOCK(adc_config->convertion_clock);
        adc_set_vref(adc_config->voltage_ref);
        adc_port_configure(adc_config->default_channel);
        ret |= adc_select_channel(adc_config->default_channel);
        ADC_SET_RIGHT_JUSTIFIED_FORMAT();
        
#if (INTERRUPT_FEATURE)
        INTERRUPT_GLOBAL_ENABLE();
        INTERRUPT_PERIFERALS_ENABLE();
        ADC_INTERRUPT_ENABLE();
        ADC_INTERRUPT_CLEAR_FLAG();
#if (INTERRUPT_PRIORITY_LEVELS)
        INTERRUPT_PRIORITY_ENABLE();
        if (adc_config->priority == HIGH_PRIORITY)
            ADC_HIGH_PRIOTIRY_SET();
        else
            ADC_LOW_PRIOTIRY_SET();
#endif
#endif
        ADC_MODULE_ENABLE();
    }
    return ret;
}
Std_ReturnType adc_select_channel(adc_channel_select_t channel){

    Std_ReturnType ret = E_OK;
    if (channel > 7){
        return E_NOT_OK;
    }
    else{
        ADC_CHANNEL_SELECT(channel);
        adc_port_configure(channel);
    }
    return ret;
}
Std_ReturnType adc_start_conversion(){
    ADC_CONVERTION_START();
    return E_OK;
}
Std_ReturnType adc_get_conversion_result(uint16_t *result){
    Std_ReturnType ret = E_OK;
    if ( NULL==result){
        return E_NOT_OK;
    }
    else{
        if (ADC_IS_DONE)
            *result = (uint16_t)((uint16_t)ADRESL + (uint16_t)(ADRESH<<8) );
        else
            ret = E_NOT_OK;
    }
    return ret;
}
Std_ReturnType adc_get_conversion_blocking(adc_config_t *adc_config,uint16_t *result){
    Std_ReturnType ret = E_OK;
    if (NULL==adc_config || NULL==result){
        return E_NOT_OK;
    }
    else{
        ret |= adc_select_channel(adc_config->default_channel);
        ret |= adc_start_conversion();
        while(!ADC_IS_DONE);
        ret |= adc_get_conversion_result(result);
    }
    return ret;
}
#if (INTERRUPT_FEATURE)
Std_ReturnType adc_start_conversion_interrupt(adc_config_t *adc_config,uint16_t *result){
    Std_ReturnType ret = E_OK;
    if (NULL==adc_config || NULL==result){
        return E_NOT_OK;
    }
    else{
        adc_call_back_handler = adc_config->callback_handler;
        interrupt_result = result;
        ret |= adc_select_channel(adc_config->default_channel);
        ret |= adc_start_conversion();
    }
    return ret;
}
#endif

static inline void adc_set_vref(uint8_t vref){
        if (vref == ADC_EXTERNAL_VREF)
        {
            ADC_SET_EXTERNAL_VREF();
        }
        else{
            ADC_SET_INTERNAL_VREF();
        }
}
static inline void adc_port_configure(adc_channel_select_t channel){
    if (channel==ADC_AN0){
        TRISAbits.RA0 = STD_ONE;
        ANSELbits.ANS0=STD_ONE;
    }
    else if (channel==ADC_AN1){
        TRISAbits.RA1 = STD_ONE;
        ANSELbits.ANS1=STD_ONE;
    }
    else if (channel==ADC_AN2){
        TRISAbits.RA2 = STD_ONE;
        ANSELbits.ANS2=STD_ONE;
    }
    else if (channel==ADC_AN3){
        TRISAbits.RA3 = STD_ONE;
        ANSELbits.ANS3=STD_ONE;
    }
    else if (channel==ADC_AN4){
        TRISAbits.RA5 = STD_ONE;
        ANSELbits.ANS4=STD_ONE;
    }
    else if (channel==ADC_AN5){
        TRISEbits.RE0 = STD_ONE;
        ANSELbits.ANS5=STD_ONE;
    }
    else if (channel==ADC_AN6){
        TRISEbits.RE1 = STD_ONE;
        ANSELbits.ANS6=STD_ONE;
    }
    else if (channel==ADC_AN7){
        TRISEbits.RE2 = STD_ONE;
        ANSELbits.ANS7=STD_ONE;
    }
    else if (channel==ADC_AN8){
        TRISBbits.RB2 = STD_ONE;
        ANSELHbits.ANS8=STD_ONE;
    }
    else if (channel==ADC_AN9){
        TRISBbits.RB3 = STD_ONE;
        ANSELHbits.ANS9=STD_ONE;
    }
    else if (channel==ADC_AN10){
        TRISBbits.RB1 = STD_ONE;
        ANSELHbits.ANS10=STD_ONE;
    }
    else if (channel==ADC_AN11){
        TRISBbits.RB4 = STD_ONE;
        ANSELHbits.ANS11=STD_ONE;
    }
    else if (channel==ADC_AN12){
        TRISBbits.RB0 = STD_ONE;
        ANSELHbits.ANS12=STD_ONE;
    }
}