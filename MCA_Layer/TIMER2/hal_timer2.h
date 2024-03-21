/* 
 * File:   hal_timer2.h
 * Author: Joe
 *
 * Created on March 10, 2024, 4:22 PM
 */

#ifndef HAL_TIMER2_H
#define	HAL_TIMER2_H

/*  section: Includes */
#include "../device_config.h"
#include "../mcal_std_types.h"
#include "../Interrupt/mcal_internal_interrupt.h"
#include "../GPIO/hal_gpio.h"

/* section : MACROS*/


/* section : function like MACROS*/

#define TIMER2_MODULE_ENABLE()                  (T2CONbits.TMR2ON = STD_ONE)
#define TIMER2_MODULE_DISABLE()                  (T2CONbits.TMR2ON = STD_ZERO)

#define TIMER2_SET_PRESCALE_VALUE(_PRE)             (T2CONbits.T2CKPS = _PRE)
#define TIMER2_SET_POSTSCALE_VALUE(_POST)           (T2CONbits.T2OUTPS = _POST)


/* section : data types declaration*/
typedef enum{
    TIMER2_POSTSCALE_1_1=0,
    TIMER2_POSTSCALE_1_2,
    TIMER2_POSTSCALE_1_3,
    TIMER2_POSTSCALE_1_4,
    TIMER2_POSTSCALE_1_5,
    TIMER2_POSTSCALE_1_6,
    TIMER2_POSTSCALE_1_7,
    TIMER2_POSTSCALE_1_8,
    TIMER2_POSTSCALE_1_9,
    TIMER2_POSTSCALE_1_10,
    TIMER2_POSTSCALE_1_11,
    TIMER2_POSTSCALE_1_12,
    TIMER2_POSTSCALE_1_13,
    TIMER2_POSTSCALE_1_14,
    TIMER2_POSTSCALE_1_15,
    TIMER2_POSTSCALE_1_16,
}timer2_clock_postscale_t;
typedef enum{
    TIMER2_PRESCALE_1_1=0,
    TIMER2_PRESCALE_1_4,
    TIMER2_PRESCALE_1_16=3,
}timer2_clock_prescale_t;

typedef struct{
    void (*interrupt_handler)(void);
    timer2_clock_prescale_t prescaler_value;
    timer2_clock_postscale_t postscaler_value;
    uint8_t preloaded_value;
}timer2_t;
/* section : interface declaration*/
Std_ReturnType timer2_init(timer2_t *timer2_config);
Std_ReturnType timer2_deinit(timer2_t *timer2_config);
Std_ReturnType timer2_read_reg(uint8_t *timer_value);
Std_ReturnType timer2_write_reg(uint8_t data);


#endif	/* HAL_TIMER2_H */

