/* 
 * File:   mcal_external_interrupt.h
 * Author: Joe
 *
 * Created on February 26, 2024, 9:24 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* section: Includes */
#include "mcal_interrupt_config.h"
#include "../GPIO/hal_gpio.h"

/*section: macro declaration*/
#define INT0_INTERRUPT_IS_ENABLE                (INTCONbits.INT0IE)
#define INT0_INTERRUPT_FLAG                     (INTCONbits.INT0IF)

#define INT1_INTERRUPT_IS_ENABLE                (INTCON3bits.INT1IE)
#define INT1_INTERRUPT_FLAG                     (INTCON3bits.INT1IF)

#define INT2_INTERRUPT_IS_ENABLE                (INTCON3bits.INT2IE)
#define INT2_INTERRUPT_FLAG                     (INTCON3bits.INT2IF)

/* section: macro function declarations */
/* INTx interrupt interface  */
#if (INTERRUPT_EXTERNAL_INTx_ENABLE)
    #define INT0_INTERRUPT_ENABLE()             (INTCONbits.INT0IE = STD_ONE)
    #define INT0_INTERRUPT_DISABLE()            (INTCONbits.INT0IE = STD_ZERO)
    #define INT0_CLEAR_INTERRUPT_FLAG()         (INTCONbits.INT0IF = STD_ZERO)
    #define INT0_FALLING_EDGE_SET()             (INTCON2bits.INTEDG0 = STD_ZERO)
    #define INT0_RISING_EDGE_SET()              (INTCON2bits.INTEDG0 = STD_ONE)

    #define INT1_INTERRUPT_ENABLE()             (INTCON3bits.INT1IE = STD_ONE)
    #define INT1_INTERRUPT_DISABLE()            (INTCON3bits.INT1IE = STD_ZERO)
    #define INT1_CLEAR_INTERRUPT_FLAG()         (INTCON3bits.INT1IF = STD_ZERO)
    #define INT1_FALLING_EDGE_SET()             (INTCON2bits.INTEDG1 = STD_ZERO)
    #define INT1_RISING_EDGE_SET()              (INTCON2bits.INTEDG1 = STD_ONE)

    #define INT2_INTERRUPT_ENABLE()             (INTCON3bits.INT2IE = STD_ONE)
    #define INT2_INTERRUPT_DISABLE()            (INTCON3bits.INT2IE = STD_ZERO)
    #define INT2_CLEAR_INTERRUPT_FLAG()         (INTCON3bits.INT2IF = STD_ZERO)
    #define INT2_FALLING_EDGE_SET()             (INTCON2bits.INTEDG2 = STD_ZERO)
    #define INT2_RISING_EDGE_SET()              (INTCON2bits.INTEDG2 = STD_ONE)

    #if (INTERRUPT_PRIORITY_LEVELS)
        #define INT1_HIGH_PRIOTIRY_SET()            (INTCON3bits.INT1IP=STD_ONE)
        #define INT1_LOW_PRIOTIRY_SET()             (INTCON3bits.INT1IP=STD_ZERO)        
        #define INT2_HIGH_PRIOTIRY_SET()            (INTCON3bits.INT2IP=STD_ONE)
        #define INT2_LOW_PRIOTIRY_SET()             (INTCON3bits.INT2IP=STD_ZERO)
    #endif
#endif 
/* RBx interrupt interface  */
#if (INTERRUPT_EXTERNAL_RBx_ENABLE)
    #define RBx_INTERRUPT_ENABLE()             (INTCONbits.RBIE = STD_ONE)
    #define RBx_INTERRUPT_DISABLE()            (INTCONbits.RBIE = STD_ZERO)
    #define RBx_CLEAR_INTERRUPT_FLAG()         (INTCONbits.RBIF = STD_ZERO)

    #if (INTERRUPT_PRIORITY_LEVELS)
        #define RBx_HIGH_PRIOTIRY_SET()            (INTCON2bits.RBIP=STD_ONE)
        #define RBx_LOW_PRIOTIRY_SET()             (INTCON2bits.RBIP=STD_ZERO)        
    #endif
#endif
/* section: data types declaration*/
typedef struct {
    void (* ext_interrupt_handler)(void);
    uint8_t     priority;
    uint8_t     i_edge;
    uint8_t     INTx_index;
}ext_INTx_config_t;
typedef struct {
    void (* ext_interrupt_handler)(void);
    uint8_t     priority;
    uint8_t     i_edge;
    uint8_t     INTx_index;
}ext_RBx_config_t;
/*section: functions declaration*/

Std_ReturnType Interrupt_INTx_Init(ext_INTx_config_t * intx_config);
Std_ReturnType Interrupt_INTx_DeInit(ext_INTx_config_t * intx_config);

Std_ReturnType Interrupt_RBx_Init(ext_RBx_config_t * intx_config);
Std_ReturnType Interrupt_RBx_DeInit(ext_RBx_config_t * intx_config);


#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

