/* 
 * File:   hal_gpio.h
 * Author: Joe
 *
 * Created on February 4, 2024, 12:45 AM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H


/* section: Includes */

#include "../mcal_std_types.h"
#include "../device_config.h"

/* section: Macros declarations */

#define BIT_MASK            STD_ONE

#define LOW                 STD_ZERO
#define HIGH                STD_ONE

#define INPUT_DIRECTION     STD_ONE
#define OUTPUT_DIRECTION    STD_ZERO


/* section: macro function declarations */
#define SET_BIT(reg,bit_pos)    (reg |= (BIT_MASK<<bit_pos))
#define CLEAR_BIT(reg,bit_pos)  (reg &= ~(BIT_MASK<<bit_pos))
#define TOGGLE_BIT(reg,bit_pos) (reg ^= (BIT_MASK<<bit_pos))
#define READ_BIT(reg,bit_pos)   ((reg>>bit_pos) & BIT_MASK )

/* section: data types declaration*/
typedef enum {
    PORTA_INDEX=0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX,
}port_index_t;
typedef enum{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;
typedef struct {
    uint8_t port_index  :3;
    uint8_t pin_index   :3;
    uint8_t direction   :1;
}pin_config_t;

/*section: functions declaration*/
Std_ReturnType gpio_port_initialize(port_index_t port_index, uint8_t port_direction);
Std_ReturnType gpio_port_get_direction(port_index_t port_index, uint8_t *port_direction);
Std_ReturnType gpio_port_write_logic(port_index_t port_index, uint8_t port_logic);
Std_ReturnType gpio_port_read_logic(port_index_t port_index, uint8_t *port_logic);
Std_ReturnType gpio_port_toggle_logic(port_index_t port_index);


Std_ReturnType gpio_pin_initialize(pin_config_t *pin_config);
Std_ReturnType gpio_pin_get_direction(pin_config_t *pin_config, uint8_t *direction);
Std_ReturnType gpio_pin_write_logic(pin_config_t *pin_config, uint8_t logic);
Std_ReturnType gpio_pin_read_logic(pin_config_t *pin_config, uint8_t *logic);
Std_ReturnType gpio_pin_toggle_logic(pin_config_t *pin_config);

#endif	/* HAL_GPIO_H */

