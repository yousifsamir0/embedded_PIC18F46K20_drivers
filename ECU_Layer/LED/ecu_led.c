#include "ecu_led.h"


/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType ecu_led_initialize(led_t * led){
    Std_ReturnType ret = E_OK;
    if (led == NULL)
    {
        ret= E_NOT_OK;
    }
    else{
        pin_config_t _pin_config = {
            .port_index = led->port_index,
            .pin_index = led->pin_index,
            .direction = OUTPUT_DIRECTION,
        };
        ret = gpio_pin_initialize(&_pin_config);
        ret = gpio_pin_write_logic(&_pin_config,led->initial_state);
    }
    
    return ret;
}
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType ecu_led_turn_on(led_t * led){
    Std_ReturnType ret = E_OK;
    if (led == NULL)
    {
        ret= E_NOT_OK;
    }
    else{
        pin_config_t _pin_config = {
            .port_index = led->port_index,
            .pin_index = led->pin_index,
            .direction = OUTPUT_DIRECTION,
        };
        ret = gpio_pin_write_logic(&_pin_config,HIGH);
    }
    
    return ret;
}
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType ecu_led_turn_off(led_t * led){
    Std_ReturnType ret = E_OK;
    if (led == NULL)
    {
        ret= E_NOT_OK;
    }
    else{
        pin_config_t _pin_config = {
            .port_index = led->port_index,
            .pin_index = led->pin_index,
            .direction = OUTPUT_DIRECTION,
        };
        ret = gpio_pin_write_logic(&_pin_config,LOW);
    }
    
    return ret;
}
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType ecu_led_toggle(led_t * led){
    Std_ReturnType ret = E_OK;
    if (led == NULL)
    {
        ret= E_NOT_OK;
    }
    else{
        pin_config_t _pin_config = {
            .port_index = led->port_index,
            .pin_index = led->pin_index,
            .direction = OUTPUT_DIRECTION,
        };
        ret = gpio_pin_toggle_logic(&_pin_config);        
    }
    
    return ret;
}