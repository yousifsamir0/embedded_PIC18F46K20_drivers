/* 
 * File:   ecu_led.h
 * Author: Joe
 *
 * Created on February 6, 2024, 2:30 AM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H
/* Section: Includes */
#include "../../MCA_Layer/GPIO/hal_gpio.h"

/* Section: Macro define */
#define LED_ON     HIGH
#define LED_OFF     LOW
/* Section: Macro functions define */
/* Section: data types declaration */
typedef struct{
    uint8_t port_index      :3;
    uint8_t pin_index       :3;
    uint8_t initial_state   :1;
    uint8_t reserved        :1;
}led_t;
/* Section: functions declaration */
Std_ReturnType ecu_led_initialize(led_t * led);
Std_ReturnType ecu_led_turn_on(led_t * led);
Std_ReturnType ecu_led_turn_off(led_t * led);
Std_ReturnType ecu_led_toggle(led_t * led);

#endif	/* ECU_LED_H */

