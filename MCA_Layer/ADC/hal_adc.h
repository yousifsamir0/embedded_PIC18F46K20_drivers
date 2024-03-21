/* 
 * File:   hal_adc.h
 * Author: Joe
 *
 * Created on March 4, 2024, 9:35 AM
 */

#ifndef HAL_ADC_H
#define	HAL_ADC_H

/* section: Includes */
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_interrupt.h"

/* section: Macros declarations */
#define ADC_CONVERTION_GO            (STD_ONE)
#define ADC_CONVERTION_DONE             (STD_ZERO)
#define ADC_IS_DONE                     (ADCON0bits.GO_DONE==STD_ZERO)
#define ADC_EXTERNAL_VREF               (STD_ONE)
#define ADC_INTERNAL_VREF               (STD_ZERO)

/* section: macro function declarations */


#define ADC_MODULE_ENABLE()                     (ADCON0bits.ADON = STD_ONE)
#define ADC_MODULE_DISABLE()                    (ADCON0bits.ADON = STD_ZERO)

#define ADC_CONVERTION_START()                  (ADCON0bits.GO_DONE = ADC_CONVERTION_GO)

#define ADC_SET_EXTERNAL_VREF()                 do {\
                                                ADCON1bits.VCFG1=STD_ONE;\
                                                ADCON1bits.VCFG0=STD_ONE;\
                                                }while(0)
                                                
#define ADC_SET_INTERNAL_VREF()                 do {\
                                                ADCON1bits.VCFG1=STD_ZERO;\
                                                ADCON1bits.VCFG0=STD_ZERO;\
                                                }while(0)
                                                
#define ADC_SET_RIGHT_JUSTIFIED_FORMAT()        (ADCON2bits.ADFM = STD_ONE)
#define ADC_SET_LEFT_JUSTIFIED_FORMAT()         (ADCON2bits.ADFM = STD_ZERO)

#define ADC_SET_ACQUISITION_TIME(_T)            (ADCON2bits.ACQT=_T)
#define ADC_SET_CONVERTION_CLOCK(_C)            (ADCON2bits.ADCS=_C)

#define ADC_CHANNEL_SELECT(_CH)                 (ADCON0bits.CHS = _CH)


/* section: data types declaration*/
typedef enum {
    ADC_AN0=0,
    ADC_AN1,
    ADC_AN2,
    ADC_AN3,
    ADC_AN4,
    ADC_AN5,
    ADC_AN6,
    ADC_AN7,
    ADC_AN8,
    ADC_AN9,
    ADC_AN10,
    ADC_AN11,
    ADC_AN12,
}adc_channel_select_t;
typedef enum{
    ADC_0_TAD=0,
    ADC_2_TAD,
    ADC_4_TAD,
    ADC_6_TAD,
    ADC_8_TAD,
    ADC_12_TAD,
    ADC_16_TAD,
    ADC_20_TAD,
}adc_acquisition_time_t;
typedef enum{
    ADC_FOSC_DIV_2=0,
    ADC_FOSC_DIV_8,
    ADC_FOSC_DIV_32,
    ADC_FRC,
    ADC_FOSC_DIV_4,
    ADC_FOSC_DIV_16,
    ADC_FOSC_DIV_64,
}adc_convertion_clock_t;

typedef struct{
#if (INTERRUPT_FEATURE)
    void (* callback_handler)(void);
#if (INTERRUPT_PRIORITY_LEVELS)
    uint8_t priority;
#endif
#endif
    adc_channel_select_t    default_channel;
    adc_acquisition_time_t  acquisition_time;
    adc_convertion_clock_t  convertion_clock;
    uint8_t                 voltage_ref;
}adc_config_t;

/*section: functions declaration*/
Std_ReturnType adc_init(adc_config_t *adc_config);
Std_ReturnType adc_select_channel(adc_channel_select_t channel);
Std_ReturnType adc_start_conversion();
Std_ReturnType adc_get_conversion_result(uint16_t * result);
Std_ReturnType adc_get_conversion_blocking(adc_config_t *adc_config,uint16_t *result);
Std_ReturnType adc_start_conversion_interrupt(adc_config_t *adc_config,uint16_t *result);


#endif	/* HAL_ADC_H */

