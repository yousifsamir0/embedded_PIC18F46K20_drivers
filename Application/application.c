/* 
 * File:   application.c
 * Author: Joe
 *
 * Created on February 4, 2024, 12:36 AM
 */

#include "../ECU_Layer/LED/ecu_led.h"
#include "../MCA_Layer/Interrupt/mcal_external_interrupt.h"
#include "../MCA_Layer/EEPROM/hal_eeprom.h"
#include "../MCA_Layer/ADC/hal_adc.h"
#include "../MCA_Layer/TIMER0/hal_timer0.h"

void start_init(void);
void APP_INT0_ISR(void);
void ADC_callback(void);
void APP_TIMER0_ISR(void);

uint16_t temp_res_an0;
uint16_t temp_res_an1;
uint16_t temp_res_an2;

adc_config_t adc_config1 = {
  .callback_handler=  ADC_callback,
  .acquisition_time=ADC_12_TAD,
  .convertion_clock= ADC_FOSC_DIV_4,
  .default_channel= ADC_AN0,
  .voltage_ref=ADC_INTERNAL_VREF
};
adc_config_t adc_config2 = {
  .callback_handler=  ADC_callback,
  .acquisition_time=ADC_12_TAD,
  .convertion_clock= ADC_FOSC_DIV_4,
  .default_channel= ADC_AN2,
  .voltage_ref=ADC_INTERNAL_VREF
};
adc_config_t adc_config3 = {
  .callback_handler=  ADC_callback,
  .acquisition_time=ADC_12_TAD,
  .convertion_clock= ADC_FOSC_DIV_4,
  .default_channel= ADC_AN3,
  .voltage_ref=ADC_INTERNAL_VREF
};


ext_INTx_config_t int0 = {
.ext_interrupt_handler = APP_INT0_ISR,
.priority = HIGH_PRIORITY,
.i_edge = INTERRUPT_RISING_EDGE,
.INTx_index = 0
};

led_t led_1 = {
  .port_index = PORTA_INDEX,
  .pin_index = PIN1,
  .initial_state=LED_OFF,
};
led_t led_2 = {
  .port_index = PORTB_INDEX,
  .pin_index = PIN1,
  .initial_state=LED_OFF,
};
led_t led_3 = {
  .port_index = PORTC_INDEX,
  .pin_index = PIN1,
  .initial_state=LED_OFF,
};
led_t led_4 = {
  .port_index = PORTD_INDEX,
  .pin_index = PIN1,
  .initial_state=LED_OFF,
};
led_t *leds_array[] = {&led_1,&led_2,&led_3,&led_4};

timer0_t timer0 = {
  .interrupt_handler=  APP_TIMER0_ISR,
  .bits_mode = TIMER0_16_BIT_MODE,
  .clock_source=TIMER0_CLOCK_SOURCE_INTERNAL,
  .prescaler = TIMER0_PRESCALER_ON,
  .prescale_value = TIMER0_1_2,
  .preloaded_value = 32767
};
uint16_t timer0_reg;

int main() {
    
    
    start_init();   
    while(1){
//        timer0_read_register(&timer0_reg);
        

    }
    
    return (EXIT_SUCCESS);
}

void start_init(void){
    timer0_init(&timer0);
    adc_init(&adc_config1);
    adc_init(&adc_config2);
    adc_init(&adc_config3);
    for (uint8_t i=0;i<4;++i)
    {
        ecu_led_initialize((leds_array[i]));
    }
}

void APP_INT0_ISR(void){
    
}
void ADC_callback (void){
    ecu_led_toggle(&led_1);
}
void APP_TIMER0_ISR(void){
//    timer0_read_register(&timer0_reg);
    timer0_reg++;
}