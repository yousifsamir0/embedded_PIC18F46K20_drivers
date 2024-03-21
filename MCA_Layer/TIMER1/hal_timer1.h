/* 
 * File:   hal_timer1.h
 * Author: Joe
 *
 * Created on March 10, 2024, 2:11 PM
 */

#ifndef HAL_TIMER1_H
#define	HAL_TIMER1_H

/*  section: Includes */
#include "../device_config.h"
#include "../mcal_std_types.h"
#include "../Interrupt/mcal_internal_interrupt.h"
#include "../GPIO/hal_gpio.h"

/* section : MACROS*/
#define TIMER1_EXTERNAL_CLOCK_SOURCE                    (STD_ONE)
#define TIMER1_INTERNAL_FOSC_DIV_4                      (STD_ZERO)

#define TIMER1_EXTERNAL_CLOCK_SYNC                      (STD_ZERO)
#define TIMER1_EXTERNAL_CLOCK_ASYNC                     (STD_ONE)

#define TIMER1_OSCILLATOR_ENABLE                        (STD_ONE)
#define TIMER1_OSCILLATOR_DISABLE                       (STD_ZERO)

#define TIMER1_MAIN_CLOCK_SOURCE                        (STD_ONE)
#define TIMER1_NOT_MAIN_CLOCK_SOURCE                    (STD_ZERO)






/* section : function like MACROS*/

#define TIMER1_MODULE_ON()                          (T1CONbits.TMR1ON = STD_ONE)
#define TIMER1_MODULE_OFF()                         (T1CONbits.TMR1ON = STD_ONE)

#define TIMER1_SET_EXTERNAL_CLOCK_SOURCE()          (T1CONbits.TMR1CS = TIMER1_EXTERNAL_CLOCK_SOURCE)
#define TIMER1_SET_INTERNAL_FOSC_DIV_4()            (T1CONbits.TMR1CS = TIMER1_INTERNAL_FOSC_DIV_4)

#define TIMER1_SET_EXTERNAL_CLOCK_SYNC()            (T1CONbits.T1SYNC = TIMER1_EXTERNAL_CLOCK_SYNC)
#define TIMER1_SET_EXTERNAL_CLOCK_ASYNC()           (T1CONbits.T1SYNC = TIMER1_EXTERNAL_CLOCK_ASYNC)

#define TIMER1_OSCILLATOR_START()                   (T1CONbits.T1OSCEN = TIMER1_OSCILLATOR_ENABLE)
#define TIMER1_OSCILLATOR_STOP()                    (T1CONbits.T1OSCEN = TIMER1_OSCILLATOR_DISABLE)

#define TIMER1_SET_PRESCALE(_P)                     (T1CONbits.T1CKPS = _P)

#define TIMER1_SYSTEM_CLOCK_STATUS()                (T1CONbits.T1RUN)

#define TIMER1_RW_8BIT_REG()                        (T1CONbits.RD16= STD_ZERO)
#define TIMER1_RW_16BIT_REG()                       (T1CONbits.RD16= STD_ONE)


/* section : data types declaration*/
typedef enum{
    TIMER1_DIV_1=0,
    TIMER1_DIV_2,
    TIMER1_DIV_4,
    TIMER1_DIV_8,
}timer1_prescale_value_t;

typedef struct {
    void (*interrupt_handler)(void);
    timer1_prescale_value_t prescale;
    uint16_t preloaded_value;
    uint8_t RW_8bit_mode_enable :1;
    uint8_t clock_source:1;
    uint8_t external_sync:1;
}timer1_t;

/* section : interface declaration*/
Std_ReturnType timer1_init(timer1_t *timer1_config);
Std_ReturnType timer1_deinit(timer1_t *timer1_config);
Std_ReturnType timer1_read_reg(uint16_t *timer_value);
Std_ReturnType timer1_write_reg(uint16_t data);

#endif	/* HAL_TIMER1_H */

