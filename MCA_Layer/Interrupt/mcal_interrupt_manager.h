/* 
 * File:   mcal_interrupt_manager.h
 * Author: Joe
 *
 * Created on February 26, 2024, 9:25 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

/* section: Includes */
#include "mcal_interrupt_config.h"

/*section: macro declaration*/

/* section: macro function declarations */

/* section: data types declaration*/

/*section: functions declaration*/
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);

void ADC_ISR(void);
void TIMER0_ISR(void);
void TIMER1_ISR(void);
void TIMER2_ISR(void);
void TIMER3_ISR(void);
void USART_RX_ISR(void);

#endif	/* MCAL_INTERRUPT_MANAGER_H */

