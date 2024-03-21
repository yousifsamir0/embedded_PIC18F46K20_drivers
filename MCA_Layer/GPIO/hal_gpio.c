
#include "hal_gpio.h"


uint8_t volatile  * GPIO_TRIS_REGISTERS[] = {&TRISA,&TRISB, &TRISC,&TRISD,&TRISE};
uint8_t volatile  * GPIO_LAT_REGISTERS[]  = {&LATA,&LATB, &LATC,&LATD,&LATE};
uint8_t volatile  * GPIO_PORT_REGISTERS[]  = {&PORTA,&PORTB, &PORTC,&PORTD,&PORTE};
/* PORT manipulation Implementation */
Std_ReturnType gpio_port_initialize(port_index_t port_index, uint8_t port_direction){
    
    Std_ReturnType Ret = E_OK;
    if (port_index>4)
        Ret = E_NOT_OK;
    else{
        *GPIO_TRIS_REGISTERS[port_index] = port_direction;
        *GPIO_LAT_REGISTERS[port_index]  = 0x0;
    }
    return Ret;
}
Std_ReturnType gpio_port_get_direction(port_index_t port_index, uint8_t *port_direction){
    Std_ReturnType Ret = E_OK;
    if (port_index>4 || port_direction == NULL)
        Ret = E_NOT_OK;
    else{
        *port_direction = *(GPIO_TRIS_REGISTERS[port_index]);
    }
    return Ret;
}
Std_ReturnType gpio_port_write_logic(port_index_t port_index, uint8_t port_logic){
    Std_ReturnType Ret = E_OK;
    if (port_index>4)
        Ret = E_NOT_OK;
    else{
        *GPIO_LAT_REGISTERS[port_index] = port_logic;
    }
    return Ret;
}
Std_ReturnType gpio_port_read_logic(port_index_t port_index, uint8_t *port_logic){
    Std_ReturnType Ret = E_OK;
    if (port_index>4 || port_logic == NULL)
        Ret = E_NOT_OK;
    else{
        *port_logic = *GPIO_PORT_REGISTERS[port_index];
    }
    return Ret;
}
Std_ReturnType gpio_port_toggle_logic(port_index_t port_index){
    Std_ReturnType Ret = E_OK;
    if (port_index>4)
        Ret = E_NOT_OK;
    else{
        *GPIO_LAT_REGISTERS[port_index] ^= 0xff;
    }
    return Ret;
}

/* PIN manipulation Implementation */
Std_ReturnType gpio_pin_initialize(pin_config_t *pin_config){
    Std_ReturnType Ret = E_OK;
    if (pin_config==NULL)
        Ret = E_NOT_OK;
    else{
        if (pin_config->direction == INPUT_DIRECTION)
        {
            SET_BIT(*GPIO_TRIS_REGISTERS[pin_config->port_index],pin_config->pin_index);
        }
        else if (pin_config->direction == OUTPUT_DIRECTION)
        {
            CLEAR_BIT(*GPIO_TRIS_REGISTERS[pin_config->port_index],pin_config->pin_index);
        }
        else{
            Ret=E_NOT_OK;
        }
    }
    return Ret;
}
Std_ReturnType gpio_pin_get_direction(pin_config_t *pin_config, uint8_t *direction){
   Std_ReturnType Ret = E_OK;
    if (pin_config==NULL ||direction==NULL )
        Ret = E_NOT_OK;
    else{
        *direction = READ_BIT(*GPIO_TRIS_REGISTERS[pin_config->port_index],pin_config->pin_index);
    }
    return Ret;
}
Std_ReturnType gpio_pin_write_logic(pin_config_t *pin_config, uint8_t logic){
    Std_ReturnType Ret = E_OK;
    if (pin_config==NULL)
        Ret = E_NOT_OK;
    else{
        if (logic == HIGH)
        {
            SET_BIT(*GPIO_LAT_REGISTERS[pin_config->port_index],pin_config->pin_index);
        }
        else if (logic == LOW)
        {
            CLEAR_BIT(*GPIO_LAT_REGISTERS[pin_config->port_index],pin_config->pin_index);
        }
        else{
            Ret=E_NOT_OK;
        }
    }
    return Ret;
}
Std_ReturnType gpio_pin_read_logic(pin_config_t *pin_config, uint8_t *logic){
    Std_ReturnType Ret = E_OK;
    if (pin_config==NULL ||logic==NULL )
        Ret = E_NOT_OK;
    else{
        *logic = READ_BIT(*GPIO_PORT_REGISTERS[pin_config->port_index],pin_config->pin_index);
    }
    return Ret;
}
Std_ReturnType gpio_pin_toggle_logic(pin_config_t *pin_config){

    Std_ReturnType Ret = E_OK;
    if (pin_config==NULL)
        Ret = E_NOT_OK;
    else{
        TOGGLE_BIT(*GPIO_LAT_REGISTERS[pin_config->port_index],pin_config->pin_index);
    }
    return Ret;

}