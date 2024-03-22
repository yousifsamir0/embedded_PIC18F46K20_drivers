/* 
 * File:   mcal_internal_interrupt.h
 * Author: Joe
 *
 * Created on February 26, 2024, 9:24 PM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H
/* section: Includes */
#include "mcal_interrupt_config.h"

/*section: macro declaration*/
#define ADC_INTERRUPT_IS_OCCUREED           (PIR1bits.ADIF==STD_ONE)
#define ADC_INTERRUPT_IS_ENABLE             (PIE1bits.ADIE==STD_ONE)

#define TIMER0_INTERRUPT_IS_OCCUREED           (INTCONbits.T0IF==STD_ONE)
#define TIMER0_INTERRUPT_IS_ENABLE             (INTCONbits.T0IE==STD_ONE)

#define TIMER1_INTERRUPT_IS_OCCUREED           (PIR1bits.TMR1IF==STD_ONE)
#define TIMER1_INTERRUPT_IS_ENABLE             (PIE1bits.TMR1IE==STD_ONE)

#define TIMER2_INTERRUPT_IS_OCCUREED           (PIR1bits.TMR2IF==STD_ONE)
#define TIMER2_INTERRUPT_IS_ENABLE             (PIE1bits.TMR2IE==STD_ONE)

#define TIMER3_INTERRUPT_IS_OCCUREED           (PIR2bits.TMR3IF==STD_ONE)
#define TIMER3_INTERRUPT_IS_ENABLE             (PIE2bits.TMR3IE==STD_ONE)

#define USART_RX_INTERRUPT_IS_OCCUREED           (PIR1bits.RCIF==STD_ONE)
#define USART_RX_INTERRUPT_IS_ENABLE             (PIE1bits.RCIE==STD_ONE)

/* section: macro function declarations */
#define ADC_INTERRUPT_ENABLE()              (PIE1bits.ADIE=STD_ONE)
#define ADC_INTERRUPT_DISABLE()             (PIE1bits.ADIE=STD_ZERO)
#define ADC_INTERRUPT_CLEAR_FLAG()          (PIR1bits.ADIF=STD_ZERO)

#define TIMER0_INTERRUPT_ENABLE()              (INTCONbits.T0IE=STD_ONE)
#define TIMER0_INTERRUPT_DISABLE()             (INTCONbits.T0IE=STD_ZERO)
#define TIMER0_INTERRUPT_CLEAR_FLAG()          (INTCONbits.T0IF=STD_ZERO)

#define TIMER1_INTERRUPT_ENABLE()              (PIE1bits.TMR1IE=STD_ONE)
#define TIMER1_INTERRUPT_DISABLE()             (PIE1bits.TMR1IE=STD_ZERO)
#define TIMER1_INTERRUPT_CLEAR_FLAG()          (PIR1bits.TMR1IF=STD_ZERO)

#define TIMER2_INTERRUPT_ENABLE()              (PIE1bits.TMR2IE=STD_ONE)
#define TIMER2_INTERRUPT_DISABLE()             (PIE1bits.TMR2IE=STD_ZERO)
#define TIMER2_INTERRUPT_CLEAR_FLAG()          (PIR1bits.TMR2IF=STD_ZERO)

#define TIMER3_INTERRUPT_ENABLE()              (PIE2bits.TMR3IE=STD_ONE)
#define TIMER3_INTERRUPT_DISABLE()             (PIE2bits.TMR3IE=STD_ZERO)
#define TIMER3_INTERRUPT_CLEAR_FLAG()          (PIR2bits.TMR3IF=STD_ZERO)

#define USART_RX_INTERRUPT_ENABLE()              (PIE1bits.RCIE = STD_ONE)
#define USART_RX_INTERRUPT_DISABLE()             (PIE1bits.RCIE = STD_ZERO)


#if (INTERRUPT_PRIORITY_LEVELS)
    #define ADC_HIGH_PRIOTIRY_SET()            (IPR1bits.ADIP=STD_ONE)
    #define ADC_LOW_PRIOTIRY_SET()             (IPR1bits.ADIP=STD_ZERO)  

    #define TIMER0_HIGH_PRIOTIRY_SET()            (INTCON2bits.TMR0IP=STD_ONE)
    #define TIMER0_LOW_PRIOTIRY_SET()             (INTCON2bits.TMR0IP=STD_ZERO)

    #define TIMER1_HIGH_PRIOTIRY_SET()            (IPR1bits.TMR1IP=STD_ONE)
    #define TIMER1_LOW_PRIOTIRY_SET()             (IPR1bits.TMR1IP=STD_ZERO)

    #define TIMER2_HIGH_PRIOTIRY_SET()            (IPR1bits.TMR2IP=STD_ONE)
    #define TIMER2_LOW_PRIOTIRY_SET()             (IPR1bits.TMR2IP=STD_ZERO)

    #define TIMER3_HIGH_PRIOTIRY_SET()            (IPR2bits.TMR3IP=STD_ONE)
    #define TIMER3_LOW_PRIOTIRY_SET()             (IPR2bits.TMR3IP=STD_ZERO)

    #define USART_RX_HIGH_PRIOTIRY_SET()            (IPR1bits.RCIP=STD_ONE)
    #define USART_RX_LOW_PRIOTIRY_SET()             (IPR1bits.RCIP=STD_ZERO)



#endif
/* section: data types declaration*/

/*section: functions declaration*/
#endif	/* MCAL_INTERNAL_INTERRUPT_H */

