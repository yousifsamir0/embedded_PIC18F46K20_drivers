/* 
 * File:   mcal_interrupt_config.h
 * Author: Joe
 *
 * Created on February 26, 2024, 9:22 PM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H

/* section: Includes */
#include "../mcal_std_types.h"
#include "../device_config.h"

/*section: macro declaration*/

/*configurations */
#define INTERRUPT_FEATURE                   1   // enable(1)/disable(0) interrupt interface 
#define INTERRUPT_PRIORITY_LEVELS           0   // enable(1)/disable(0) interrupt priority levels
#define INTERRUPT_EXTERNAL_INTx_ENABLE      1   // enable(1)/disable(0) external INTx interrupt interface
#define INTERRUPT_EXTERNAL_RBx_ENABLE       1   // enable(1)/disable(0) external RBx  interrupt interface
#define INTERRUPT_INTERNAL_ENABLE           1   // enable(1)/disable(0) external interrupt interface
/*----------------------------------------------------------------------------------*/

#define INTERRUPT_ENABLE                STD_ONE

#define HIGH_PRIORITY                   STD_ONE
#define LOW_PRIORITY                    STD_ZERO

#define INTERRUPT_RISING_EDGE           STD_ONE
#define INTERRUPT_FALLING_EDGE          STD_ZERO

/* section: macro function declarations */

#if (INTERRUPT_FEATURE)



    #if (INTERRUPT_PRIORITY_LEVELS)
        /* priority levels interrupts */
        #define INTERRUPT_PRIORITY_ENABLE()             (RCONbits.IPEN = STD_ONE)
        #define INTERRUPT_PRIORITY_DISABLE()            (RCONbits.IPEN = STD_ZERO)

        #define INTERRUPT_GLOBAL_HIGH_ENABLE()          (INTCONbits.GIEH = STD_ONE)
        #define INTERRUPT_GLOBAL_HIGH_DISABLE()         (INTCONbits.GIEH = STD_ZERO)
        #define INTERRUPT_GLOBAL_LOW_ENABLE()           (INTCONbits.GIEL = STD_ONE)
        #define INTERRUPT_GLOBAL_LOW_DISABLE()          (INTCONbits.GIEL = STD_ZERO)
    #endif
        /* non priority interrupts */
        #define INTERRUPT_GLOBAL_ENABLE()               (INTCONbits.GIE = STD_ONE)
        #define INTERRUPT_GLOBAL_DISABLE()              (INTCONbits.GIE = STD_ZERO)
        #define INTERRUPT_PERIFERALS_ENABLE()           (INTCONbits.PEIE = STD_ONE)
        #define INTERRUPT_PERIFERALS_DISABLE()          (INTCONbits.PEIE = STD_ZERO)
#endif








/* section: data types declaration*/

/*section: functions declaration*/


#endif	/* MCAL_INTERRUPT_CONFIG_H */

