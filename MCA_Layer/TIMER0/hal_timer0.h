/* 
 * File:   hal_timer0.h
 * Author: Joe
 *
 * Created on March 5, 2024, 3:20 PM
 */

#ifndef HAL_TIMER0_H
#define	HAL_TIMER0_H
/*  section: Includes */
#include "../device_config.h"
#include "../mcal_std_types.h"
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_interrupt.h"


/* section : MACROS*/

#define TIMER0_8_BIT_MODE                       (STD_ONE)
#define TIMER0_16_BIT_MODE                      (STD_ZERO)

#define TIMER0_CLOCK_SOURCE_EXTERNAL            (STD_ONE)
#define TIMER0_CLOCK_SOURCE_INTERNAL            (STD_ZERO)

#define TIMER0_EXT_CLOCK_FALLING_EDGE           (STD_ONE)
#define TIMER0_EXT_CLOCK_RISING_EDGE            (STD_ZERO)

#define TIMER0_PRESCALER_OFF                    (STD_ONE)
#define TIMER0_PRESCALER_ON                     (STD_ZERO)





/* section : function like MACROS*/
#define TIMER0_ENABLE()                             (T0CONbits.TMR0ON=STD_ONE)
#define TIMER0_DISABLE()                            (T0CONbits.TMR0ON=STD_ZERO)

#define TIMER0_SET_8_BIT_MODE()                     (T0CONbits.T08BIT=TIMER0_8_BIT_MODE)
#define TIMER0_SET_16_BIT_MODE()                    (T0CONbits.T08BIT=TIMER0_16_BIT_MODE)

#define TIMER0_SET_CLOCK_SOURCE_EXTERNAL()          (T0CONbits.T0CS=TIMER0_CLOCK_SOURCE_EXTERNAL)
#define TIMER0_SET_CLOCK_SOURCE_INTERNAL()          (T0CONbits.T0CS=TIMER0_CLOCK_SOURCE_INTERNAL)

#define TIMER0_SET_EXT_CLOCK_FALLING_EDGE()         (T0CONbits.T0SE= TIMER0_EXT_CLOCK_FALLING_EDGE)
#define TIMER0_SET_EXT_CLOCK_RISING_EDGE()          (T0CONbits.T0SE= TIMER0_EXT_CLOCK_RISING_EDGE)

#define TIMER0_PRESCALE_DISABLE()                   (T0CONbits.PSA =STD_ONE )
#define TIMER0_PRESCALE_ENABLE()                    (T0CONbits.PSA =STD_ZERO)

#define TIMER0_SET_PRESCALE_VALUE(_P)               (T0CONbits.T0PS = _P)

/* section : data types declaration*/
typedef enum{
    TIMER0_1_2=0,
    TIMER0_1_4,
    TIMER0_1_8,
    TIMER0_1_16,
    TIMER0_1_32,
    TIMER0_1_64,
    TIMER0_1_128,
    TIMER0_1_256,
}timer0_prescale_t;

typedef struct{
    timer0_prescale_t prescale_value;
    void(* interrupt_handler)(void);
    uint16_t preloaded_value;
    uint8_t bits_mode           :1;
    uint8_t clock_source        :1;
    uint8_t prescaler           :1;
    uint8_t clock_edge          :1;
}timer0_t;
/* section : interface declaration*/

Std_ReturnType timer0_init(timer0_t *timer0_config);
Std_ReturnType timer0_de_init(timer0_t *timer0_config);
Std_ReturnType timer0_write_register(uint16_t data);
Std_ReturnType timer0_read_register(uint16_t *timer_value);


#endif	/* HAL_TIMER0_H */

