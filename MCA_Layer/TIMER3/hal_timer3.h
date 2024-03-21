/* 
 * File:   hal_timer3.h
 * Author: Joe
 *
 * Created on March 10, 2024, 5:32 PM
 */

#ifndef HAL_TIMER3_H
#define	HAL_TIMER3_H

/*  section: Includes */
#include "../device_config.h"
#include "../mcal_std_types.h"
#include "../Interrupt/mcal_internal_interrupt.h"
#include "../GPIO/hal_gpio.h"

/* section : MACROS*/
#define TIMER3_EXTERNAL_CLOCK_SOURCE                    (STD_ONE)
#define TIMER3_INTERNAL_FOSC_DIV_4                      (STD_ZERO)

#define TIMER3_EXTERNAL_CLOCK_SYNC                      (STD_ZERO)
#define TIMER3_EXTERNAL_CLOCK_ASYNC                     (STD_ONE)

/* section : function like MACROS*/

#define TIMER3_MODULE_ON()                           (T1CONbits.TMR1ON = STD_ONE)
#define TIMER3_MODULE_OFF()                          (T1CONbits.TMR1ON = STD_ONE)

#define TIMER3_SET_EXTERNAL_CLOCK_SOURCE()           (T1CONbits.TMR1CS = TIMER3_EXTERNAL_CLOCK_SOURCE)
#define TIMER3_SET_INTERNAL_FOSC_DIV_4()             (T1CONbits.TMR1CS = TIMER3_INTERNAL_FOSC_DIV_4)

#define TIMER3_SET_EXTERNAL_CLOCK_SYNC()             (T1CONbits.T1SYNC = TIMER3_EXTERNAL_CLOCK_SYNC)
#define TIMER3_SET_EXTERNAL_CLOCK_ASYNC()            (T1CONbits.T1SYNC = TIMER3_EXTERNAL_CLOCK_ASYNC)

#define TIMER3_SET_PRESCALE(_P)                      (T1CONbits.T1CKPS = _P)


#define TIMER3_RW_8BIT_REG()                         (T1CONbits.RD16= STD_ZERO)
#define TIMER3_RW_16BIT_REG()                        (T1CONbits.RD16= STD_ONE)


/* section : data types declaration*/
typedef enum{
    TIMER3_DIV_1=0,
    TIMER3_DIV_2,
    TIMER3_DIV_4,
    TIMER3_DIV_8,
}timer3_prescale_value_t;

typedef struct {
    void (*interrupt_handler)(void);
    timer3_prescale_value_t prescale;
    uint16_t preloaded_value;
    uint8_t RW_8bit_mode_enable :1;
    uint8_t clock_source:1;
    uint8_t external_sync:1;
}timer3_t;

/* section : interface declaration*/
Std_ReturnType timer3_init(timer3_t *timer3_config);
Std_ReturnType timer3_deinit(timer3_t *timer3_config);
Std_ReturnType timer3_read_reg(uint16_t *timer_value);
Std_ReturnType timer3_write_reg(uint16_t data);
#endif	/* HAL_TIMER3_H */

